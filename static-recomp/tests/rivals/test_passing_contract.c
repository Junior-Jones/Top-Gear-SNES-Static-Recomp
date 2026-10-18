#include "topgear_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rally_passing_driver.inc"
static TopGearRecomp *c;
static void put(unsigned a,unsigned v){c->wram[a]=(uint8_t)v;c->wram[a+1]=(uint8_t)(v>>8);}
static void car(unsigned id,int gap,int lateral){unsigned off=id*18;put(0x219+off,(read_le16(c->wram,0x1ed7)+10000+gap)%10000);put(0x214+off,(unsigned)lateral);}
static void setup(void){unsigned id;memset(c->wram,0,sizeof(c->wram));memset(&c->rivals,0,sizeof(c->rivals));c->rivals.ready=1;put(0x200,10000);put(0x1ed7,1000);put(0x1e5a,9000);put(0x206,18);put(0x1e5c,6000);c->rivals.rival[0].speed=c->rivals.rival[1].speed=6000;for(id=0;id<20;id++){put(0x212+id*18,id);put(0x21c+id*18,3000);car(id,-3000,0);}}
#define CHECK(v) do{if(!(v)){printf("FAIL line=%u %s\n",__LINE__,#v);return 1;}}while(0)
int main(void){Driver d;int x;unsigned id,n,cases=0;uint8_t ram[131072];c=calloc(1,sizeof(*c));if(!c)return 2;c->rom=calloc(524288,1);if(!c->rom)return 2;
 setup();memset(&d,0,sizeof(d));CHECK(!passing_plan(c,&d,&x)&&!d.pass_id);cases++;
 for(id=1;id<20;id++){setup();memset(&d,0,sizeof(d));car(id,350,0);memcpy(ram,c->wram,sizeof(ram));CHECK(passing_plan(c,&d,&x)&&d.pass_id==(int)id&&driver_abs(d.pass_target)>=4000);CHECK(!memcmp(ram,c->wram,sizeof(ram)));cases++;}
 setup();memset(&d,0,sizeof(d));car(2,350,0);car(4,-100,-5000);CHECK(passing_plan(c,&d,&x)&&d.pass_target>0);cases++;
 setup();memset(&d,0,sizeof(d));car(2,350,0);car(4,-100,5000);CHECK(passing_plan(c,&d,&x)&&d.pass_target<0);cases++;
 setup();memset(&d,0,sizeof(d));car(2,100,0);car(4,-100,-5000);car(5,-100,5000);CHECK(passing_plan(c,&d,&x)&&!d.pass_id&&d.emergency_brake);cases++;
 setup();memset(&d,0,sizeof(d));put(0x1ed7,9900);for(id=1;id<20;id++)car(id,-3000,0);car(3,300,0);CHECK(passing_plan(c,&d,&x)&&d.pass_id==3);cases++;
 setup();memset(&d,0,sizeof(d));car(2,350,0);CHECK(passing_plan(c,&d,&x));{int target=d.pass_target;put(0x1e8a,(unsigned)target);car(2,100,0);for(n=0;n<30;n++)passing_plan(c,&d,&x);CHECK(d.pass_id==2&&d.pass_target==target&&!d.completed_passes);car(2,-250,0);for(n=0;n<24;n++)passing_plan(c,&d,&x);CHECK(!d.pass_id&&d.completed_passes==1);}cases++;
 setup();memset(&d,0,sizeof(d));memset(c->oam,60,sizeof(c->oam));CHECK(!passing_plan(c,&d,&x));cases++;
 setup();memset(&d,0,sizeof(d));put(0x17b,(unsigned)-3000);put(0x17d,3000);car(2,100,0);CHECK(passing_plan(c,&d,&x)&&!d.pass_id&&d.emergency_brake);cases++;
 printf("PASS passing cases=%u all_19_opponent_IDs=1 private_rivals=1 scenery_ignored=1 rear_traffic=1 blocked_lanes_brake=1 wrap=1 hold_until_clear=1 observe_only=1\n",cases);free(c->rom);free(c);return 0;}
