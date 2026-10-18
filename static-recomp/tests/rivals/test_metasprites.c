#include "topgear_internal.h"
#include <stdio.h>
#include <string.h>
static TopGearRecomp *c;static char error[256];
static unsigned w(unsigned a){return c->wram[a]|(c->wram[a+1]<<8);}
static void put(unsigned a,unsigned v){c->wram[a]=(uint8_t)v;c->wram[a+1]=(uint8_t)(v>>8);}
#define CHECK(v) do{if(!(v)){fprintf(stderr,"FAIL line=%d case=%u %s (%s)\n",__LINE__,cases,#v,error);return 1;}}while(0)
int main(int argc,char **argv){uint8_t rom[524288],native[256*224*2];FILE *f;unsigned car,view,style,cases=0;
 if(argc!=3)return 2;f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));CHECK(topgear_recomp_snapshot_load(c,argv[2],error,sizeof(error)));
 put(0x1f04,1);put(0x1b76,0);put(0xf7,256);put(0xf9,65520);put(0x1b88,128);put(0x1b8a,80);
 put(0xcc,0xf0a);put(0xd8,0x112a);put(0x1c08,0);put(0x1d56,0);put(0x1b9c,0);
 for(car=0;car<4;car++)for(view=0;view<2;view++)for(style=0;style<0x50;style+=2){
  unsigned n,owner=view?w(0xd8):w(0xcc),stop=view?0x9007u:0x8c5bu,start=view?0x8e33u:0x8a87u;TopGearV22VideoInfo info;
  memset(c->oam,0,544);for(n=0;n<128;n++)c->oam[n*4+1]=240;
  memcpy(c->wram+owner,c->oam,544);put(0x1b92,0);put(0x1b94,512);put(0x1b96,0);put(0x1b86,style);
  c->rivals.disabled=1;c->cpu.pbr=1;c->cpu.pc=(uint16_t)start;c->cpu.dbr=1;c->cpu.d=0;c->cpu.p=0;c->cpu.e=0;
  for(n=0;n<12000&&c->cpu.pc!=stop;n++)CHECK(tg_v22_semantic_static_step_any(c));CHECK(c->cpu.pc==stop);
  memcpy(c->oam,c->wram+owner,544);memcpy(c->vram+0x4000,rom+0x20000+car*3936,3936);memcpy(c->cgram+256,rom+0x412da+car*32,32);
  CHECK(topgear_recomp_v22_render_current_frame(c,&info));memcpy(native,c->mode1_frame,sizeof(native));
  memset(c->oam,0,544);for(n=0;n<128;n++)c->oam[n*4+1]=240;
  memset(&c->rivals,0,sizeof(c->rivals));c->rivals.ready=1;c->rivals.cars[2]=(uint8_t)car;c->rivals.draw_id=2;
  memcpy(c->rivals.tiles[car],rom+0x20000+car*3936,3936);memcpy(c->rivals.palettes[car],c->cgram+256,32);
  c->rivals.pending[0].owner=(uint16_t)owner;put(0x1b92,0);put(0x1b86,0x200u+style);c->cpu.pc=(uint16_t)start;
  tg_rivals_before(c,0x10000u|start);tg_rivals_latch(c,(uint16_t)owner);
  CHECK(topgear_recomp_v22_render_current_frame(c,&info));
  if(memcmp(native,c->mode1_frame,sizeof(native))){fprintf(stderr,"car=%u view=%u style=%04X native_objects=%u private_objects=%u\n",car,view,style,w(0x1b92)/4,c->rivals.visible.count);CHECK(0);}
  cases++;
 }
 printf("PASS native_metasprite_equivalence=%u all_40_main_styles=1 car_banks=4 human_views=2\n",cases);topgear_recomp_destroy(c);return 0;
}
