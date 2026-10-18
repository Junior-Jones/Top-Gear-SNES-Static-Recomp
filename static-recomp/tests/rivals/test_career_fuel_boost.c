#include "topgear_internal.h"
#include "topgear_v22_interrupt_dispatch.h"
#include "v22_reentry/topgear_v22_reentry_shards.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "career_fuel_driver.inc"
static TopGearRecomp *c;
static void put(unsigned a,unsigned v){c->wram[a]=(uint8_t)v;c->wram[a+1]=(uint8_t)(v>>8);}
#define CHECK(v) do{if(!(v)){printf("FAIL line=%u %s pc=%02X:%04X error=%s\n",__LINE__,#v,c->cpu.pbr,c->cpu.pc,c->last_error);return 1;}}while(0)
static int run(unsigned bank,unsigned start,unsigned end,int interrupt){unsigned n;c->cpu.pbr=(uint8_t)bank;c->cpu.pc=(uint16_t)start;c->cpu.dbr=0;c->cpu.d=0;c->cpu.p=TG_P_I;c->cpu.e=0;for(n=0;n<500&&c->cpu.pc!=end;n++)if(!(interrupt?tg_v22_interrupt_semantic_step(c):tg_v22_reentry_semantic_step(c)))return 0;return c->cpu.pc==end;}
int main(int argc,char**argv){Driver d={0};FILE*f;unsigned n,id,accepted=0;uint8_t rom[524288];char error[256];if(argc!=2)return 2;f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);if(!topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)))return 2;memset(c->wram,0,sizeof(c->wram));c->v23_event_mode=0;c->rivals.ready=1;put(0x200,10000);put(0x1ed7,1000);put(0x1e5a,9000);put(0x1e6c,3);put(0x1f7e,TG_BTN_A);put(0x206,18);for(id=1;id<20;id++){put(0x212+id*18,id);put(0x219+id*18,8000);put(0x21c+id*18,3000);}d.race_frame=600;
for(n=0;n<4000&&(read_le16(c->wram,0x1e6c)||d.boost_count<3);n++){
 unsigned before=read_le16(c->wram,0x1e6c);uint16_t input=driver_input(c,&d,c->wram,c->mode1_frame,0);put(0x14,input&TG_BTN_A);CHECK(run(5,0xd353,0xd37c,0));if(!(before&0x8000)&&(read_le16(c->wram,0x1e6c)&0x8000))accepted++;
 CHECK(run(0,0xb9ed,0xba50,1));
}
CHECK(n<4000);CHECK(d.boost_count==3&&accepted==3&&!read_le16(c->wram,0x1e6c));printf("PASS native boost requests=%u accepted=%u remaining=%u frames=%u no_race_started=1\n",d.boost_count,accepted,read_le16(c->wram,0x1e6c),n);topgear_recomp_destroy(c);return 0;}
