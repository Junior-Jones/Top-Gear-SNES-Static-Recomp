/* Experimental test-only passing driver, derived from rally_self_driver.inc.
   Reads native Rally vehicle telemetry and produces normal P1 controller inputs.
   Keep separate from the baseline: Rain Forest regressed in the recorded run. */
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
    int pass_target, pass_id, emergency_brake;
    int last_lateral, lateral_velocity, lateral_initialized;
    unsigned pass_clear_frames, lane_changes, completed_passes, emergency_frames;
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

/* Observe race vehicles, including private-rendered rivals, rather than
   guessing that every sprite in a screen-space band is a car. Inputs only:
   this helper never changes a car's position, speed, fuel or race state. */
typedef struct DriverTraffic {int id,gap,lateral,speed;} DriverTraffic;
static int driver_abs(int v){return v<0?-v:v;}
static void passing_limits(TopGearRecomp *core,int *left,int *right){
 unsigned pos=read_le16(core->wram,0x1ed7),idx=(pos>>4)&0xfffeu;
 unsigned map=read_le16(core->wram,0x5800u+idx)&32767u;
 unsigned type=core->rom[0x1b3fu+map]|core->rom[0x1b40u+map]<<8;
 int lo=type<256u?(int)(int16_t)read_le16(core->wram,0x17bu+type):0;
 int hi=type<256u?(int)(int16_t)read_le16(core->wram,0x17du+type):0;
 if(lo<0&&hi>0&&hi-lo>=5000&&hi-lo<40000){*left=lo+1500;*right=hi-1500;}
 else{*left=-6500;*right=6500;}
}
static int passing_plan(TopGearRecomp *core,Driver *d,int *traffic_x){
 DriverTraffic cars[19];unsigned off,count=0,k;int length=read_le16(core->wram,0x200),position=read_le16(core->wram,0x1ed7);
 int lateral=(int)(int16_t)read_le16(core->wram,0x1e8a),speed=(int)(int16_t)read_le16(core->wram,0x1e5a);
 int front=-1,nearest=100000,tracked_gap=100000,left,right,traffic=0;
 *traffic_x=124;d->emergency_brake=0;
 if(!core->rivals.ready||!length||(int16_t)read_le16(core->wram,0x1e76)<0)return 0;
 passing_limits(core,&left,&right);
 for(off=0;off<360;off+=18){
  int gap,lat,v,id;
  if(off==read_le16(core->wram,0x204))continue;
  id=off==read_le16(core->wram,0x206)?1:read_le16(core->wram,0x212+off)&31;
  if(id<1||id>=20)continue;
  gap=(int)read_le16(core->wram,0x219+off)-position;
  if(gap< -length/2)gap+=length;else if(gap>length/2)gap-=length;
  lat=(int)(int16_t)read_le16(core->wram,0x214+off);
  v=id==1?(int)(int16_t)read_le16(core->wram,0x1e5c):id<4?(int)(int16_t)core->rivals.rival[id-2].speed:2*(int)read_le16(core->wram,0x21c+off);
  cars[count].id=id;cars[count].gap=gap;cars[count].lateral=lat;cars[count].speed=v;count++;
  if(d->pass_id==id)tracked_gap=gap;
  if(gap>=0&&gap<700&&driver_abs(lat-lateral)<2400&&(speed>=v-256||gap<180)&&gap<nearest){nearest=gap;front=(int)count-1;}
 }
 if(d->pass_id){
  if(tracked_gap< -180||tracked_gap>1400){
   if(++d->pass_clear_frames>=24){if(tracked_gap< -180)d->completed_passes++;d->pass_id=0;d->pass_target=0;d->pass_clear_frames=0;}
  }else d->pass_clear_frames=0;
 }
 if(front>=0){
  int candidates[3]={-5000,0,5000},best_target=d->pass_target,best_score=100000000,best_blocked=1;
  traffic=1;d->traffic_frames++;*traffic_x=124+(cars[front].lateral-lateral)/256;
  for(k=0;k<3;k++){
   int target=candidates[k],blocked=0,score;unsigned j;
   if(target<left)target=left;if(target>right)target=right;
   score=driver_abs(target-lateral)/4+driver_abs(target)/8;
   if(d->pass_id&&driver_abs(target-d->pass_target)>1500)score+=3000;
   for(j=0;j<count;j++){
    DriverTraffic *t=&cars[j];
    if(t->gap>= -200&&t->gap<750&&driver_abs(t->lateral-target)<2500){blocked=1;score+=100000+750-t->gap;}
    /* Do not merge across a nearby overtaking car behind either shoulder. */
    if(t->gap>= -280&&t->gap<120&&t->id!=cars[front].id){int lo=lateral<target?lateral:target,hi=lateral>target?lateral:target;if(t->lateral>lo-1800&&t->lateral<hi+1800){blocked=1;score+=200000;}}
   }
   if(score<best_score){best_score=score;best_target=target;best_blocked=blocked;}
  }
  if(!best_blocked){
   if(!d->pass_id||driver_abs(best_target-d->pass_target)>1500)d->lane_changes++;
   d->pass_id=cars[front].id;d->pass_target=best_target;d->pass_clear_frames=0;
  }else if(nearest<190&&speed>cars[front].speed+256){d->emergency_brake=1;d->emergency_frames++;}
 }
 if(d->pass_target<left)d->pass_target=left;if(d->pass_target>right)d->pass_target=right;
 d->avoid_frames=d->pass_id?1u:0u;return traffic;
}

static uint16_t driver_input(TopGearRecomp *core, Driver *d,
                             const uint8_t *wram, const uint8_t *frame,
                             int manual) {
    unsigned local=(unsigned)(read_le16(wram,COURSE_WORD_OFFSET)&3u);
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
    traffic=passing_plan(core,d,&traffic_x);
    /* Read native roadside objects, never invent a pit location. D760-D7C0
       identifies type $74, with bit $100 selecting the left entrance.
       Approach on real steering controls before fuel becomes critical. */
    {
        unsigned fuel=read_le16(wram,0x1E62u),length=read_le16(wram,0x0200u);
        unsigned pit=read_le16(wram,0x1E86u),position=read_le16(wram,0x1ED7u),p;
        if(!pit&&length&&((fuel<0x7000u&&(int)(int16_t)read_le16(wram,0x1E76u)+1<(int)read_le16(wram,0x1E56u))||fuel<0x3000u)){
            position%=length;
            for(p=0u;p<length;p+=32u){
                unsigned obj=read_le16(wram,0x6400u+p/16u);
                if((obj&0xFE00u)==0x7400u&&(p+length-position)%length<4096u){
                    d->steer=(obj&0x100u)?-1:1;d->avoid_frames=0u;d->pass_id=0;d->pass_target=0;
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
        int target=d->pass_id?d->pass_target:0,predicted;
        if(!d->lateral_initialized){d->last_lateral=lateral;d->lateral_initialized=1;}
        d->lateral_velocity=(3*d->lateral_velocity+lateral-d->last_lateral)/4;d->last_lateral=lateral;
        predicted=lateral+4*d->lateral_velocity;
        d->steer=predicted<target-800?1:predicted>target+800?-1:0;
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
    if(read_le16(wram,COURSE_WORD_OFFSET)==22u&&!seeking_pit&&!read_le16(wram,0x1E86u)&&raw_speed>0x1400){
        int lateral=(int)(int16_t)read_le16(wram,0x1E8Au);
        if(lateral < -3000 || lateral > 3000)
            mask=(uint16_t)((mask&~(TG_BTN_X|TG_BTN_A))|read_le16(wram,0x1F78u));
    }
    /* Accelerator is an EARLY EXIT request during refuelling. Release it
       for every entry/refuel phase; full fuel advances natively to FFF9. */
    if(d->emergency_brake&&!seeking_pit&&!read_le16(wram,0x1E86u))mask=(uint16_t)((mask&~(TG_BTN_X|TG_BTN_A))|read_le16(wram,0x1F78u));
    if(read_le16(wram,0x1E86u)>=0xFFFAu)mask=0u;
    ++d->race_frame;
    return mask;
}
