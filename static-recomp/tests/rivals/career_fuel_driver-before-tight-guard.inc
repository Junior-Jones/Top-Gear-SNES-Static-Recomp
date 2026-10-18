/* P1-only Career fuel-budget controller with pit entrance protection.
   Reads native Rally vehicle telemetry and produces normal P1 controller inputs.
   Separate from both earlier recorded drivers. */
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
    unsigned pass_age, pass_cooldown, return_hold, boost_safe_frames, boost_denied;
    unsigned blocked_frames, replans, corner_braking_frames, boost_active_frames;
    unsigned pit_guard_frames, pit_intent;
    uint64_t fuel_burn, fuel_distance;
    unsigned fuel_tracking, fuel_previous, fuel_previous_pos, fuel_rate_q16;
    int fuel_previous_lap;
    unsigned fuel_remaining_distance, fuel_required, fuel_low, fuel_shortfall;
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
/* Native pit objects ($74xx/$75xx) trigger entry by lateral position alone.
   The low byte *128 is the full-coordinate boundary, not a lane count.
   Exclude the entry side early enough to move out of an existing passing line.
   Intentional pit steering bypasses this passing-only restriction below. */
static int pit_exclusion(TopGearRecomp *core,int *left,int *right){
 unsigned length=read_le16(core->wram,0x200),pos=read_le16(core->wram,0x1ed7),n;int active=0;
 if(!length||read_le16(core->wram,0x1e86))return 0;
 pos%=length;
 for(n=0;n<=4480u;n+=32u){
  unsigned p=((pos&~31u)+length-384u+n)%length;
  unsigned obj=read_le16(core->wram,0x6400u+((p>>4)&0xfffeu)),edge=(obj&255u)*128u;
  if((obj&0xfe00u)!=0x7400u)continue;
  if(obj&0x100u){int safe=-(int)edge+2048;if(safe>*left)*left=safe;}
  else{int safe=(int)edge-2048;if(safe<*right)*right=safe;}
  active=1;
 }
 if(*left>*right){*left=0;*right=0;}
 return active;
}
static void passing_limits(TopGearRecomp *core,int *left,int *right){
 unsigned pos=read_le16(core->wram,0x1ed7),idx=(pos>>4)&0xfffeu;
 unsigned map=read_le16(core->wram,0x5800u+idx)&32767u;
 unsigned type=core->rom[0x1b3fu+map]|core->rom[0x1b40u+map]<<8;
 int lo=type<256u?(int)(int16_t)read_le16(core->wram,0x17bu+type):0;
 int hi=type<256u?(int)(int16_t)read_le16(core->wram,0x17du+type):0;
 if(lo<0&&hi>0&&hi-lo>=5000&&hi-lo<40000){*left=lo+1500;*right=hi-1500;}
 else{*left=-6500;*right=6500;}
 (void)pit_exclusion(core,left,right);
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
  if(gap>=0&&gap<1400&&driver_abs(lat-lateral)<4300&&(speed>=v-256||gap<180)&&gap<nearest){nearest=gap;front=(int)count-1;}
 }
 if(d->pass_cooldown)d->pass_cooldown--;
 if(d->pass_id){
  d->pass_age++;
  if(tracked_gap< -180||tracked_gap>1400){
   if(++d->pass_clear_frames>=24&&d->pass_age>=90){
    /* Keep the current line; there is no merge back to centre to delay. */
    if(tracked_gap< -180)d->completed_passes++;
    d->pass_id=0;d->pass_clear_frames=0;d->pass_cooldown=0;
   }
  }else d->pass_clear_frames=0;
 }
 if(front>=0){traffic=1;d->traffic_frames++;*traffic_x=124+(cars[front].lateral-lateral)/256;}
 /* Commit to a line; reconsider only a sustained obstruction in that line.
    Never apply traffic braking. Keep the passing lane after clearing a car. */
 if(front>=0&&d->pass_id&&nearest<450&&driver_abs(cars[front].lateral-d->pass_target)<4300){d->blocked_frames++;}else d->blocked_frames=0;
 if(front>=0&&(!d->pass_id||(d->pass_age>=120&&d->blocked_frames>=24))){
  int candidates[9]={d->pass_target,lateral,-5000,0,5000,left,right,cars[front].lateral-5400,cars[front].lateral+5400};
  int best_target=d->pass_target,best_score=100000000,best_blocked=1;
  for(k=0;k<9;k++){
   int target=candidates[k],blocked=0,score;unsigned j;
   if(target<left)target=left;if(target>right)target=right;
   score=driver_abs(target-lateral)/3+driver_abs(target)/12;
   if(d->pass_id&&((target<0)!=(d->pass_target<0)))score+=4000;
   for(j=0;j<count;j++){
    DriverTraffic *t=&cars[j];
    if(t->gap>= -180&&t->gap<1200&&driver_abs(t->lateral-target)<4300){blocked=1;score+=100000+1200-t->gap;}
    if(t->gap>= -220&&t->gap<100&&t->id!=cars[front].id){int lo=lateral<target?lateral:target,hi=lateral>target?lateral:target;if(t->lateral>lo-2200&&t->lateral<hi+2200){blocked=1;score+=200000;}}
   }
   if(score<best_score){best_score=score;best_target=target;best_blocked=blocked;}
  }
  if(!best_blocked){
   if(d->pass_id)d->replans++;
   if(driver_abs(best_target-d->pass_target)>1500)d->lane_changes++;
   d->pass_id=cars[front].id;d->pass_target=best_target;d->pass_clear_frames=0;d->pass_age=0;d->blocked_frames=0;
  }
 }
 if(d->pass_target<left)d->pass_target=left;if(d->pass_target>right)d->pass_target=right;
 d->avoid_frames=d->pass_id?1u:0u;return traffic;
}

/* Budget fuel from observed P1 consumption per distance. Pits/refills and
   reverse movement never enter the measurement. Need both LOW fuel (<= $3000,
   about 29% of a full tank) and insufficient predicted fuel to finish.
   Estimate includes 10% consumption margin plus 512 fuel units reserve. */
static int driver_fuel_plan(TopGearRecomp *core,Driver *d){
 const uint8_t *ram=core->wram;unsigned fuel=read_le16(ram,0x1e62),pos=read_le16(ram,0x1ed7);
 unsigned length=read_le16(ram,0x200),laps=read_le16(ram,0x1e56),pit=read_le16(ram,0x1e86);
 int lap=(int16_t)read_le16(ram,0x1e76);int64_t delta=0;uint64_t need;
 d->fuel_low=fuel<=0x3000u;d->fuel_required=0;d->fuel_remaining_distance=0;d->fuel_shortfall=0;
 if(!length||lap<0||pos>=length){d->fuel_tracking=0;return 0;}
 if(d->fuel_tracking&&!pit&&fuel<=d->fuel_previous){
  delta=(int64_t)(lap-d->fuel_previous_lap)*length+(int64_t)pos-d->fuel_previous_pos;
  if(delta>=0&&delta<(int64_t)length/4){d->fuel_distance+=(unsigned)delta;d->fuel_burn+=d->fuel_previous-fuel;}
 }
 d->fuel_tracking=!pit;d->fuel_previous=fuel;d->fuel_previous_pos=pos;d->fuel_previous_lap=lap;
 d->fuel_rate_q16=d->fuel_distance>=1024u&&d->fuel_burn?(unsigned)((d->fuel_burn*65536u+d->fuel_distance-1)/d->fuel_distance):16384u;
 if((unsigned)lap>=laps)return 0;
 d->fuel_remaining_distance=(laps-(unsigned)lap)*length-pos;
 need=((uint64_t)d->fuel_remaining_distance*d->fuel_rate_q16*110u+6553599u)/6553600u+512u;
 d->fuel_required=(unsigned)(need>0xffffffffu?0xffffffffu:need);
 d->fuel_shortfall=d->fuel_required>fuel;
 return d->fuel_low&&d->fuel_shortfall&&!pit;
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
    int traffic=0,seeking_pit=0,needs_fuel=driver_fuel_plan(core,d); unsigned lap=wram[P1_LAP_OFFSET];
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
    d->pit_intent=0;
    {int left=-32767,right=32767;if(pit_exclusion(core,&left,&right))d->pit_guard_frames++;}
    /* Read native roadside objects, never invent a pit location. D760-D7C0
       identifies type $74, with bit $100 selecting the left entrance.
       Approach on real steering controls before fuel becomes critical. */
    {
        unsigned fuel=read_le16(wram,0x1E62u),length=read_le16(wram,0x0200u);
        unsigned pit=read_le16(wram,0x1E86u),position=read_le16(wram,0x1ED7u),p;
        if(!pit&&length&&needs_fuel){
            position%=length;
            for(p=0u;p<length;p+=32u){
                unsigned obj=read_le16(wram,0x6400u+p/16u);
                if((obj&0xFE00u)==0x7400u&&(p+length-position)%length<4096u){
                    d->steer=(obj&0x100u)?-1:1;d->avoid_frames=0u;d->pass_id=0;d->pass_target=0;
                    d->pit_seek_frames++;d->pit_intent=1;seeking_pit=1;break;
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
        int target=d->pass_target,predicted;
        if(!d->lateral_initialized){d->last_lateral=lateral;d->lateral_initialized=1;}
        d->lateral_velocity=(3*d->lateral_velocity+lateral-d->last_lateral)/4;d->last_lateral=lateral;
        predicted=lateral+4*d->lateral_velocity;
        d->steer=predicted<target-800?1:predicted>target+800?-1:0;
    }
    if(d->steer<0)mask=(uint16_t)(mask|TG_BTN_LEFT);
    if(d->steer>0)mask=(uint16_t)(mask|TG_BTN_RIGHT);
    if(lap!=d->prior_lap){d->prior_lap=lap;d->lap_straight_frames=0u;}
    /* Inspect upcoming native curvature and all nineteen physical vehicles.
       No time-based track windows and no sprite/road-colour classification.
       At boost speed require the lane plus the steering sweep to remain clear. */
    {
        unsigned length=read_le16(wram,0x200),pos=read_le16(wram,0x1ed7),ahead,off;
        int lateral=(int16_t)read_le16(wram,0x1e8a),safe=length>0&&raw_speed>0x1600&&!seeking_pit&&!read_le16(wram,0x1e86)&&!d->emergency_brake;
        for(ahead=0;safe&&ahead<=896; ahead+=64){
            unsigned idx=(((pos+ahead)%length)>>4)&0xfffeu;
            int bend=(int8_t)wram[0x4c00+idx],steer_bend=(int8_t)wram[0x4c08+idx];
            if(driver_abs(bend)>6||driver_abs(steer_bend)>6)safe=0;
        }
        for(off=0;safe&&off<360;off+=18){
            int gap,lat;if(off==read_le16(wram,0x204))continue;
            gap=(int)read_le16(wram,0x219+off)-(int)pos;
            if(gap< -(int)length/2)gap+=length;else if(gap>(int)length/2)gap-=length;
            lat=(int16_t)read_le16(wram,0x214+off);
            if(gap> -160&&gap<1100&&driver_abs(lat-lateral)<4300)safe=0;
        }
        if(driver_abs(lateral-d->pass_target)>1700||driver_abs(d->lateral_velocity)>240)safe=0;
        if(safe)d->boost_safe_frames++;else {d->boost_safe_frames=0;d->boost_denied++;}
        if(!d->boost_frames&&d->boost_count<3&&d->race_frame>480&&d->boost_safe_frames>=8&&
           read_le16(wram,0x1e6c)>0&&!(read_le16(wram,0x1e6c)&0x8000u)){
            d->boost_used_lap[d->boost_count]=lap+1;++d->boost_count;d->boost_frames=12;d->boost_safe_frames=0;
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
    /* Brake only for a sharp corner when speed and outward displacement
       threaten the road edge. Traffic never issues a brake input. */
    {
        unsigned pos=read_le16(wram,0x1ed7),idx=(pos>>4)&0xfffeu;
        int bend=(int8_t)wram[0x4c08+idx],left,right;
        int lateral=(int16_t)read_le16(wram,0x1e8a);
        passing_limits(core,&left,&right);
        if(!seeking_pit&&!read_le16(wram,0x1e86)&&driver_abs(bend)>=24&&raw_speed>10000&&
           ((bend>0&&lateral>right-2000)||(bend<0&&lateral<left+2000))){
            mask=(uint16_t)((mask&~(TG_BTN_X|TG_BTN_A))|read_le16(wram,0x1f78));d->corner_braking_frames++;
        }
        if(read_le16(wram,0x1e6c)&0x8000u)d->boost_active_frames++;
    }
    if(read_le16(wram,0x1E86u)>=0xFFFAu)mask=0u;
    ++d->race_frame;
    return mask;
}
