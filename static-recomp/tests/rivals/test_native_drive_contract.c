#include "topgear_internal.h"
#include "v22_reentry/topgear_v22_reentry_shards.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static unsigned w(TopGearRecomp*c,unsigned a){return c->wram[a]|c->wram[a+1]<<8;}
static void put(TopGearRecomp*c,unsigned a,unsigned v){c->wram[a]=(uint8_t)v;c->wram[a+1]=(uint8_t)(v>>8);}
#define CHECK(v) do{if(!(v)){printf("FAIL line=%u %s error=%s\n",__LINE__,#v,c->last_error);return 1;}}while(0)
int main(int argc,char**argv){TopGearRecomp*c,*ref;TgRival r;uint8_t rom[524288];char error[256];FILE*f;unsigned car,fuel,n,cases=0;const unsigned fuels[]={43007,11000,0};if(argc!=3)return 2;f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);if(!topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)))return 2;ref=malloc(sizeof(*ref));
for(car=0;car<4;car++)for(fuel=0;fuel<3;fuel++){
 CHECK(topgear_recomp_snapshot_load(c,argv[2],error,sizeof(error)));
 memset(&r,0,sizeof(r));r.id=2;r.car=(uint8_t)car;r.speed=8000;r.fuel=(uint16_t)fuels[fuel];r.gear=3;r.position=(uint32_t)w(c,0x1eda)<<8;r.lap=(int16_t)w(c,0x1e78);r.lateral=1000;r.upper=6144;r.lower=(uint16_t)-6144;
 /* Independently set up and step the native path in the ordinary CPU slot. */
 memcpy(ref,c,sizeof(*ref));ref->v23_event_mode=0;ref->hook_callback=NULL;ref->cpu.pbr=5;ref->cpu.pc=0xed92;ref->cpu.dbr=0;ref->cpu.d=0;ref->cpu.p=TG_P_I;ref->cpu.e=0;ref->cpu.s=0x1b00;
 put(ref,0x53,0);put(ref,0x1fac,car);put(ref,0x1e5c,r.speed);put(ref,0x1e64,r.fuel);put(ref,0x1e74,r.gear);put(ref,0x1e60,0);put(ref,0x1e78,(unsigned)r.lap);put(ref,0x1ed9,r.position&65535u);ref->wram[0x1edb]=(uint8_t)(r.position>>16);put(ref,0x59,r.position>>8);put(ref,0x1e8c,r.lateral);put(ref,0x1ec4,r.upper);put(ref,0x1ec6,r.lower);ref->wram[0x1ec8]=0;put(ref,0x1e80,0);put(ref,0x1eee,0);put(ref,0x1e84,0);put(ref,0x1ebe,0);put(ref,0x1e88,0);put(ref,0x1ef6,0);put(ref,0x1f02,65535);put(ref,0x1ee0,3);put(ref,0x1efe,ref->rom[0x17db+car]|ref->rom[0x17dc+car]<<8);put(ref,0x1ef2,w(ref,0x1ef2)&~1u);
 for(n=0;n<12000&&!(ref->cpu.pbr==5&&ref->cpu.pc==0xe3b9);n++){if(ref->cpu.pbr==5&&ref->cpu.pc==0xee05)ref->cpu.y=(uint16_t)(ref->cpu.y+car*16);CHECK(tg_v22_reentry_semantic_step(ref));}
 CHECK(n<12000);CHECK(tg_rivals_native_drive(c,&r,w(c,0x206)));
 CHECK(r.speed==w(ref,0x1e5c)&&r.fuel==w(ref,0x1e64)&&r.gear==w(ref,0x1e74)&&r.rpm==w(ref,0x1e60));
 CHECK(r.position==((uint32_t)ref->wram[0x1ed9]|(uint32_t)w(ref,0x1eda)<<8));CHECK(r.lateral==w(ref,0x1e8c)&&r.steering==w(ref,0x1e80));CHECK(r.upper==w(ref,0x1ec4)&&r.lower==w(ref,0x1ec6));
 CHECK(!c->failed);cases++;
}
printf("PASS native driving cases=%u all_four_cars=1 full_low_empty_fuel=1 speed_fuel_gear_rpm_position_lateral_steering_bounds_match=1\n",cases);free(ref);topgear_recomp_destroy(c);return 0;}
