#include "topgear_internal.h"
#include "v22_reentry/topgear_v22_reentry_shards.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rally_pit_guard_driver.inc"
static TopGearRecomp *c;
static void put(unsigned a,unsigned v){c->wram[a]=(uint8_t)v;c->wram[a+1]=(uint8_t)(v>>8);}
static void car(unsigned id,int gap,int lat){unsigned off=id*18;put(0x219+off,(read_le16(c->wram,0x1ed7)+10000+gap)%10000);put(0x214+off,(unsigned)lat);}
static void setup(void){unsigned id;memset(c->wram,0,sizeof(c->wram));memset(&c->rivals,0,sizeof(c->rivals));c->rivals.ready=1;put(0x200,10000);put(0x1ed7,1000);put(0x1e5a,9000);put(0x1e6c,3);put(0x1f78,0x4000);put(0x206,18);put(0x1e5c,6000);c->rivals.rival[0].speed=c->rivals.rival[1].speed=6000;for(id=0;id<20;id++){put(0x212+id*18,id);put(0x21c+id*18,3000);car(id,-3000,0);}}
static int native_entry(unsigned obj,int lateral){
 TopGearRecomp *t=malloc(sizeof(*t));unsigned n;int result;
 memcpy(t,c,sizeof(*t));t->cpu.pbr=5;t->cpu.pc=0xd742;t->cpu.dbr=0;t->cpu.d=0;t->cpu.p=TG_P_I;t->cpu.e=0;t->cpu.s=0x1b00;t->cpu.x=0x100;t->cpu.a=(uint16_t)obj;
 t->wram[0x6500]=(uint8_t)obj;t->wram[0x6501]=(uint8_t)(obj>>8);t->wram[0x1e8a]=(uint8_t)lateral;t->wram[0x1e8b]=(uint8_t)(lateral>>8);t->wram[0x1e86]=t->wram[0x1e87]=0;
 for(n=0;n<150&&t->cpu.pc!=0xd790&&t->cpu.pc!=0xd7d4;n++)if(!tg_v22_reentry_semantic_step(t))break;
 result=n<150&&!t->failed?(read_le16(t->wram,0x1e86)>=0x8000u):-1;free(t);return result;
}
#define CHECK(v) do{if(!(v)){printf("FAIL line=%u %s\n",__LINE__,#v);return 1;}}while(0)
int main(void){Driver d;int x;unsigned id,n,cases=0;uint8_t ram[131072];c=calloc(1,sizeof(*c));c->rom=calloc(524288,1);
for(id=1;id<20;id++){setup();memset(&d,0,sizeof(d));car(id,1100,0);memcpy(ram,c->wram,sizeof(ram));CHECK(passing_plan(c,&d,&x)&&d.pass_id==(int)id&&driver_abs(d.pass_target)>=4300);CHECK(!memcmp(ram,c->wram,sizeof(ram)));CHECK(!d.emergency_brake);cases++;}
setup();memset(&d,0,sizeof(d));put(0x17b,(unsigned)-3000);put(0x17d,3000);car(2,50,0);for(n=0;n<120;n++)CHECK(!(driver_input(c,&d,c->wram,c->mode1_frame,0)&0x4000));CHECK(!d.pass_id&&!d.emergency_frames);cases++;
setup();memset(&d,0,sizeof(d));car(2,700,0);CHECK(passing_plan(c,&d,&x));{int target=d.pass_target;put(0x1e8a,(unsigned)target);for(n=0;n<120;n++){car(4,200+(n&1)*300,0);passing_plan(c,&d,&x);CHECK(d.pass_id==2&&d.pass_target==target);}car(2,-400,0);for(n=0;n<24;n++)passing_plan(c,&d,&x);CHECK(!d.pass_id&&d.pass_target==target&&d.completed_passes==1);}cases++;
setup();memset(&d,0,sizeof(d));d.race_frame=600;/* Short clear straight: bend starts only beyond new horizon. */c->wram[0x4c00+(((1000+1408)>>4)&0xfffeu)]=40;for(n=0;n<8;n++)driver_input(c,&d,c->wram,c->mode1_frame,0);CHECK(d.boost_count==1);cases++;
setup();memset(&d,0,sizeof(d));d.race_frame=600;car(4,700,0);put(0x17b,(unsigned)-3000);put(0x17d,3000);for(n=0;n<60;n++)driver_input(c,&d,c->wram,c->mode1_frame,0);CHECK(!d.boost_count&&!d.emergency_frames);cases++;
setup();memset(&d,0,sizeof(d));d.race_frame=600;c->wram[0x4c00+(((1000+512)>>4)&0xfffeu)]=40;for(n=0;n<60;n++)driver_input(c,&d,c->wram,c->mode1_frame,0);CHECK(!d.boost_count);cases++;
setup();memset(&d,0,sizeof(d));put(0x1e5a,12000);put(0x1e8a,6000);c->wram[0x4c08+((1000>>4)&0xfffeu)]=32;CHECK(driver_input(c,&d,c->wram,c->mode1_frame,0)&0x4000);CHECK(d.corner_braking_frames==1);cases++;
/* Full tank: exclude both left/right entrance boundaries and move out of
   a previously held passing line. Include track wrap and rear grace window. */
for(id=0;id<2;id++){
 int left,right,edge=7680,safe=(id?-1:1)*(edge-2048);unsigned marker=id?0x753c:0x743c;
 setup();memset(&d,0,sizeof(d));put(0x1e62,43007);put(0x1e56,6);put(0x6400+1504/16,marker);passing_limits(c,&left,&right);
 CHECK(id?left==safe:right==safe);CHECK(native_entry(marker,id?-9000:9000)==1);CHECK(native_entry(marker,safe)==0);cases++;
 put(0x1e8a,(unsigned)(id?-9000:9000));d.pass_target=id?-9000:9000;
 {unsigned input=driver_input(c,&d,c->wram,c->mode1_frame,0);CHECK(!d.pit_intent&&d.pit_guard_frames==1);CHECK(id?d.pass_target>=safe:d.pass_target<=safe);CHECK(input&(id?TG_BTN_RIGHT:TG_BTN_LEFT));CHECK(!(input&0x4000));}cases++;
 setup();memset(&d,0,sizeof(d));put(0x1e62,0x6000);put(0x1e56,6);put(0x6400+1504/16,marker);
 {unsigned input=driver_input(c,&d,c->wram,c->mode1_frame,0);CHECK(d.pit_intent&&input&(id?TG_BTN_LEFT:TG_BTN_RIGHT));}cases++;
 setup();memset(&d,0,sizeof(d));put(0x1e62,0x6000);put(0x1e56,6);put(0x1e76,5);put(0x6400+1504/16,marker);driver_input(c,&d,c->wram,c->mode1_frame,0);CHECK(!d.pit_intent);cases++;
 setup();memset(&d,0,sizeof(d));put(0x1ed7,9800);put(0x6400+320/16,marker);passing_limits(c,&left,&right);CHECK(id?left==safe:right==safe);cases++;
 setup();memset(&d,0,sizeof(d));put(0x1ed7,1700);put(0x6400+1504/16,marker);passing_limits(c,&left,&right);CHECK(id?left==safe:right==safe);cases++;
}
printf("PASS pit guard cases=%u left_right=1 full_tank_avoid=1 low_fuel_intentional_entry=1 final_lap_policy=1 wrap=1 exit_grace=1 no_traffic_brake=1 no_game_state_writes=1\n",cases);free(c->rom);free(c);return 0;}
