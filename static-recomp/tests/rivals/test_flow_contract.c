#include "topgear_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rally_flow_driver.inc"
static TopGearRecomp *c;
static void put(unsigned a,unsigned v){c->wram[a]=(uint8_t)v;c->wram[a+1]=(uint8_t)(v>>8);}
static void car(unsigned id,int gap,int lat){unsigned off=id*18;put(0x219+off,(read_le16(c->wram,0x1ed7)+10000+gap)%10000);put(0x214+off,(unsigned)lat);}
static void setup(void){unsigned id;memset(c->wram,0,sizeof(c->wram));memset(&c->rivals,0,sizeof(c->rivals));c->rivals.ready=1;put(0x200,10000);put(0x1ed7,1000);put(0x1e5a,9000);put(0x1e6c,3);put(0x1f78,0x4000);put(0x206,18);put(0x1e5c,6000);c->rivals.rival[0].speed=c->rivals.rival[1].speed=6000;for(id=0;id<20;id++){put(0x212+id*18,id);put(0x21c+id*18,3000);car(id,-3000,0);}}
#define CHECK(v) do{if(!(v)){printf("FAIL line=%u %s\n",__LINE__,#v);return 1;}}while(0)
int main(void){Driver d;int x;unsigned id,n,cases=0;uint8_t ram[131072];c=calloc(1,sizeof(*c));c->rom=calloc(524288,1);
for(id=1;id<20;id++){setup();memset(&d,0,sizeof(d));car(id,1100,0);memcpy(ram,c->wram,sizeof(ram));CHECK(passing_plan(c,&d,&x)&&d.pass_id==(int)id&&driver_abs(d.pass_target)>=4300);CHECK(!memcmp(ram,c->wram,sizeof(ram)));CHECK(!d.emergency_brake);cases++;}
setup();memset(&d,0,sizeof(d));put(0x17b,(unsigned)-3000);put(0x17d,3000);car(2,50,0);for(n=0;n<120;n++)CHECK(!(driver_input(c,&d,c->wram,c->mode1_frame,0)&0x4000));CHECK(!d.pass_id&&!d.emergency_frames);cases++;
setup();memset(&d,0,sizeof(d));car(2,700,0);CHECK(passing_plan(c,&d,&x));{int target=d.pass_target;put(0x1e8a,(unsigned)target);for(n=0;n<120;n++){car(4,200+(n&1)*300,0);passing_plan(c,&d,&x);CHECK(d.pass_id==2&&d.pass_target==target);}car(2,-400,0);for(n=0;n<24;n++)passing_plan(c,&d,&x);CHECK(!d.pass_id&&d.pass_target==target&&d.completed_passes==1);}cases++;
setup();memset(&d,0,sizeof(d));d.race_frame=600;/* Short clear straight: bend starts only beyond new horizon. */c->wram[0x4c00+(((1000+1408)>>4)&0xfffeu)]=40;for(n=0;n<8;n++)driver_input(c,&d,c->wram,c->mode1_frame,0);CHECK(d.boost_count==1);cases++;
setup();memset(&d,0,sizeof(d));d.race_frame=600;car(4,700,0);put(0x17b,(unsigned)-3000);put(0x17d,3000);for(n=0;n<60;n++)driver_input(c,&d,c->wram,c->mode1_frame,0);CHECK(!d.boost_count&&!d.emergency_frames);cases++;
setup();memset(&d,0,sizeof(d));d.race_frame=600;c->wram[0x4c00+(((1000+512)>>4)&0xfffeu)]=40;for(n=0;n<60;n++)driver_input(c,&d,c->wram,c->mode1_frame,0);CHECK(!d.boost_count);cases++;
setup();memset(&d,0,sizeof(d));put(0x1e5a,12000);put(0x1e8a,6000);c->wram[0x4c08+((1000>>4)&0xfffeu)]=32;CHECK(driver_input(c,&d,c->wram,c->mode1_frame,0)&0x4000);CHECK(d.corner_braking_frames==1);cases++;
printf("PASS flow cases=%u all_19_cars=1 early_passing=1 committed_lane=1 stay_in_lane_after_pass=1 no_traffic_brake=1 short_straight_boost=1 blocked_boost=1 corner_only_brake=1 observe_only=1\n",cases);free(c->rom);free(c);return 0;}
