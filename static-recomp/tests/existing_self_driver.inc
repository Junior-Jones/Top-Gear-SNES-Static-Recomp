/* Unmodified Driver/road/traffic/input policy extracted from the existing
   tests/test_time_trial_journey.c for short Career/Rally/Trial smoke runs. */
#define P1_PLACE_OFFSET 0x011Au
#define P1_LAP_OFFSET 0x011Eu
#define P1_SPEED_OFFSET 0x1E5Au
#define COURSE_LENGTH_OFFSET 0x0200u
#define P1_COURSE_POS_OFFSET 0x0202u
#define COURSE_WORD_OFFSET 0x1F06u
#define P1_GEAR_LO_OFFSET 0x1F7Au
#define P1_GEAR_HI_OFFSET 0x1F7Cu
#define P1_CAR_OFFSET 0x1F8Fu

#define TG_BTN_START UINT16_C(0x1000)
#define TG_BTN_B UINT16_C(0x8000)
#define TG_BTN_DOWN UINT16_C(0x0400)
#define TG_BTN_UP UINT16_C(0x0800)
#define TG_BTN_LEFT UINT16_C(0x0200)
#define TG_BTN_RIGHT UINT16_C(0x0100)
#define TG_BTN_A UINT16_C(0x0080)
#define TG_BTN_X UINT16_C(0x0040)
#define TG_BTN_R UINT16_C(0x0010)

typedef struct Driver {
    int steer;
    int avoid_direction;
    unsigned avoid_frames;
    unsigned missing_road_frames;
    unsigned traffic_frames;
    unsigned boost_frames;
    unsigned boost_count;
    unsigned boost_used_lap[8];
    unsigned lap_straight_frames;
    unsigned prior_lap;
    uint32_t race_frame;
    unsigned stopped_frames;
    unsigned pit_seek_frames;
    unsigned shift_count;
    unsigned shift_hold,shift_release,shift_gear;
    uint16_t shift_button;
    int shift_speed[2];
} Driver;

static uint16_t read_le16(const uint8_t *data, unsigned offset) {
    return (uint16_t)(data[offset] | ((uint16_t)data[offset + 1u] << 8u));
}

static int road_center(const uint8_t *frame, int *samples,
                       unsigned row_first,unsigned row_last) {
    unsigned x,y; int64_t weighted_x=0,total=0; int count=0;
    for(y=row_first;y<=row_last;y+=2u){
        int weight=1+(int)(y-row_first)/10;
        for(x=0u;x<238u;++x){
            size_t o=((size_t)y*256u+x)*2u;
            uint16_t c=(uint16_t)(frame[o]|((uint16_t)frame[o+1u]<<8u));
            int r=c&31u,g=(c>>5u)&31u,b=(c>>10u)&31u;
            int low=r<g?(r<b?r:b):(g<b?g:b);
            int high=r>g?(r>b?r:b):(g>b?g:b);
            if(r>=5&&r<=14&&g>=5&&g<=15&&b>=5&&b<=15&&high-low<=4){
                weighted_x+=(int64_t)x*weight; total+=weight; ++count;
            }
        }
    }
    *samples=count;
    return total?(int)(weighted_x/total):-1;
}

static int traffic_ahead(TopGearRecomp *core, int *traffic_x) {
    uint8_t oam[544]; unsigned index,found=0u; int x_total=0;
    *traffic_x=124;
    if(!topgear_recomp_v07_read_oam(core,0u,oam,sizeof(oam)))return -1;
    for(index=0u;index<128u;++index){
        unsigned high=oam[512u+index/4u],shift=(index%4u)*2u;
        int x=(int)oam[index*4u]+(int)(((high>>shift)&1u)*256u);
        int y=(int)oam[index*4u+1u];
        int half_width=((high>>(shift+1u))&1u)?8:4;
        int center;
        if(index>=3u&&index<=14u)continue;
        if(x>=256)x-=512;
        center=x+half_width;
        if(y>=34&&y<=70&&center>=92&&center<=156){x_total+=center;++found;}
    }
    if(found)*traffic_x=x_total/(int)found;
    return found!=0u;
}

static uint16_t driver_input(TopGearRecomp *core, Driver *d,
                             const uint8_t *wram, const uint8_t *frame,
                             int manual) {
    unsigned local=(unsigned)(core->mod_time_trial_selected_course&3u);
    unsigned row_first=local==2u?55u:40u;
    unsigned row_last=local==2u?90u:70u;
    int low_threshold=local==2u?108:119;
    int high_threshold=local==2u?148:137;
    int samples=0,center=road_center(frame,&samples,row_first,row_last),traffic_x=124;
    int traffic=0,seeking_pit=0; unsigned lap=wram[P1_LAP_OFFSET];
    int raw_speed=(int)(int16_t)read_le16(wram,P1_SPEED_OFFSET);
    uint16_t mask=TG_BTN_X;
    if(center>=0&&samples>=24){
        if(center<low_threshold)d->steer=-1; else if(center>high_threshold)d->steer=1; else d->steer=0;
        d->missing_road_frames=0u;
    }else{
        ++d->missing_road_frames;
        if((d->missing_road_frames%120u)==0u)d->steer=-d->steer;
        if(!d->steer)d->steer=((d->missing_road_frames/120u)&1u)?1:-1;
    }
    /* Reuse the mature eight-race driver policy: OAM traffic avoidance is
       reliable for local track slots 0/1, while slots 2/3 can expose scenery
       sprites in the same OAM region and must not be treated as traffic. */
    if(local<2u)traffic=traffic_ahead(core,&traffic_x);
    if(traffic>0){
        ++d->traffic_frames;
        if(!d->avoid_frames){d->avoid_direction=traffic_x<124?1:-1;d->avoid_frames=18u;}
        else if(d->avoid_frames<8u)d->avoid_frames=8u;
    }
    if(d->avoid_frames){
        if(center>=0&&center<108)d->steer=-1;
        else if(center>148)d->steer=1;
        else d->steer=d->avoid_direction;
        --d->avoid_frames;
    }
    /* Read native roadside objects, never invent a pit location. D760-D7C0
       identifies type $74, with bit $100 selecting the left entrance.
       Approach on real steering controls before fuel becomes critical. */
    {
        unsigned fuel=read_le16(wram,0x1E62u),length=read_le16(wram,0x0200u);
        unsigned pit=read_le16(wram,0x1E86u),position=read_le16(wram,0x1ED7u),p;
        if(!pit&&length&&((fuel<0x7000u&&core->mod_time_trial_lap_count+1u<core->mod_time_trial_required_laps)||fuel<0x3000u)){
            position%=length;
            for(p=0u;p<length;p+=32u){
                unsigned obj=read_le16(wram,0x6400u+p/16u);
                if((obj&0xFE00u)==0x7400u&&(p+length-position)%length<4096u){
                    d->steer=(obj&0x100u)?-1:1;d->avoid_frames=0u;
                    d->pit_seek_frames++;seeking_pit=1;break;
                }
            }
        }
    }
    /* Use the engine's lateral coordinate as steering authority. Several
       courses have coloured road surfaces, so grey pixel sampling alone
       can aim at roadside signs and pin the car against them. OAM traffic
       can request a modest lane offset, well inside roadside obstacles. */
    if(!seeking_pit&&!read_le16(wram,0x1E86u)){
        int lateral=(int)(int16_t)read_le16(wram,0x1E8Au);
        int target=d->avoid_frames?d->avoid_direction*4000:0;
        d->steer=lateral<target-1000?1:lateral>target+1000?-1:0;
    }
    if(d->steer<0)mask=(uint16_t)(mask|TG_BTN_LEFT);
    if(d->steer>0)mask=(uint16_t)(mask|TG_BTN_RIGHT);
    if(lap!=d->prior_lap){d->prior_lap=lap;d->lap_straight_frames=0u;}
    if(local==0u||local==2u||local==3u){
        static const unsigned short_windows[3]={1488u,2378u,2995u};
        static const unsigned slot2_windows[3]={1500u,4500u,7500u};
        const unsigned *windows=local==2u?slot2_windows:short_windows;
        if(!d->boost_frames&&d->boost_count<3u&&
           d->race_frame>=windows[d->boost_count]&&traffic<=0){
            d->boost_used_lap[d->boost_count]=lap+1u;
            ++d->boost_count;d->boost_frames=12u;
        }
    }else if(d->boost_count<3u&&lap<3u){
        if(center>=118&&center<=132&&samples>=500&&traffic<=0&&!d->avoid_frames)
            ++d->lap_straight_frames;
        else d->lap_straight_frames=0u;
        if(!d->boost_frames&&!d->boost_used_lap[lap]&&d->race_frame>=480u&&
           d->lap_straight_frames>=12u){
            d->boost_used_lap[lap]=lap+1u;
            ++d->boost_count;d->boost_frames=12u;
        }
    }
    if(d->boost_frames){mask=(uint16_t)(mask|TG_BTN_A);--d->boost_frames;}
    /* Read the native five-gear index and per-car speed thresholds
       ($05:D391-D3AB). Operate real controls with a held pulse and release;
       a single video-frame tap can fall between game input polls. */
    if(manual){
        unsigned gear=read_le16(wram,0x1E72u),index=read_le16(wram,0x1EE8u)+gear*2u;
        uint16_t lower=0u,upper=65535u;
        (void)tg_bus_read16(core,0x0099DBu+index,&lower);
        (void)tg_bus_read16(core,0x009A15u+index,&upper);
        if(d->shift_hold){
            if(gear!=d->shift_gear){d->shift_hold=0u;d->shift_release=12u;}
            else {mask|=d->shift_button;if(!--d->shift_hold)d->shift_release=12u;}
        }else if(d->shift_release)d->shift_release--;
        else if((gear<4u&&raw_speed>=upper)||(gear>0u&&raw_speed>=0&&raw_speed<lower)){
            d->shift_button=(gear<4u&&raw_speed>=upper)?TG_BTN_R:UINT16_C(0x0020);
            d->shift_gear=gear;d->shift_hold=12u;mask|=d->shift_button;
            if(d->shift_count<2u)d->shift_speed[d->shift_count]=raw_speed;
            ++d->shift_count;
        }
    }
    if(raw_speed==0&&d->race_frame>600u)d->stopped_frames++;else d->stopped_frames=0u;
    /* Bordeaux's bend after the right pit can throw Razor into the signs
       before steering recovers. Brake when lateral drift builds, using the
       configured native brake control. Other track policies are unchanged. */
    if(core->mod_time_trial_selected_course==22u&&!seeking_pit&&!read_le16(wram,0x1E86u)&&raw_speed>0x1400){
        int lateral=(int)(int16_t)read_le16(wram,0x1E8Au);
        if(lateral < -3000 || lateral > 3000)
            mask=(uint16_t)((mask&~(TG_BTN_X|TG_BTN_A))|read_le16(wram,0x1F78u));
    }
    /* Accelerator is an EARLY EXIT request during refuelling. Release it
       for every entry/refuel phase; full fuel advances natively to FFF9. */
    if(read_le16(wram,0x1E86u)>=0xFFFAu)mask=0u;
    ++d->race_frame;
    return mask;
}
