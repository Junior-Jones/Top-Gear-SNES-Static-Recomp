#include "topgear_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static TopGearRecomp *c;static char error[256];
#define CHECK(v) do{if(!(v)){fprintf(stderr,"FAIL line=%d %s (%s)\n",__LINE__,#v,error);return 1;}}while(0)
int main(int argc,char **argv){uint8_t rom[524288],oam[544],native[256*224*2],memory[65536+512];FILE *f;unsigned car,flip,n,cases=0,total=0;TopGearV22VideoInfo info;
 if(argc!=3)return 2;f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
 CHECK(topgear_recomp_snapshot_load(c,argv[2],error,sizeof(error)));
 memcpy(memory,c->vram,65536);memcpy(memory+65536,c->cgram,512);memcpy(oam,c->oam,544);
 c->rivals.disabled=1;CHECK(topgear_recomp_v22_render_current_frame(c,&info));memcpy(native,c->mode1_frame,sizeof(native));
 c->rivals.disabled=0;c->rivals.ready=1;CHECK(topgear_recomp_v22_render_current_frame(c,&info));CHECK(!memcmp(native,c->mode1_frame,sizeof(native)));
 CHECK(!memcmp(memory,c->vram,65536));CHECK(!memcmp(memory+65536,c->cgram,512));CHECK(!memcmp(oam,c->oam,544));
 for(car=0;car<4;car++)for(flip=0;flip<4;flip++){
  unsigned count=0;memcpy(c->oam,oam,544);memcpy(c->vram+0x4000,rom+0x20000+car*3936,3936);memcpy(c->cgram+256,rom+0x412da+car*32,32);
  memcpy(c->rivals.tiles[car],rom+0x20000+car*3936,3936);memcpy(c->rivals.palettes[car],c->cgram+256,32);
  for(n=0;n<128;n++){unsigned at=c->oam[n*4+3],tile=c->oam[n*4+2];if(!(at&15u)&&tile<123u&&c->oam[n*4+1]<108u)c->oam[n*4+3]^=(uint8_t)(flip<<6);}
  c->rivals.visible.count=0;CHECK(topgear_recomp_v22_render_current_frame(c,&info));memcpy(native,c->mode1_frame,sizeof(native));
  for(n=0;n<128;n++){
   unsigned at=c->oam[n*4+3],tile=c->oam[n*4+2],pair=(c->oam[512+n/4]>>((n&3)*2))&3u;TgExtendedObject *o;
   if((at&15u)||tile>=123u||c->oam[n*4+1]>=108u)continue;
   o=&c->rivals.visible.objects[count++];memset(o,0,sizeof(*o));o->x=(int16_t)(c->oam[n*4]|((pair&1u)<<8));if(o->x>=256)o->x-=512;
   o->y=c->oam[n*4+1];o->tile=(uint16_t)tile;o->bank=(uint8_t)car;o->palette=(uint8_t)car;o->size=(uint8_t)((pair&2u)?16:8);o->priority=(uint8_t)((at>>4)&3u);o->hflip=(uint8_t)((at>>6)&1u);o->vflip=(uint8_t)((at>>7)&1u);o->order=n*2048u+2047u;
   c->oam[n*4+1]=240;
  }
  CHECK(count>0);c->rivals.visible.count=(uint16_t)count;CHECK(topgear_recomp_v22_render_current_frame(c,&info));CHECK(!memcmp(native,c->mode1_frame,sizeof(native)));total+=count;cases++;
 }
 printf("PASS empty_device_native_pixels_and_memory=1 car_banks=4 flip_combinations=4 cases=%u object_comparisons=%u full_frame_pixels=%u\n",cases,total,cases*256u*224u);
 topgear_recomp_destroy(c);return 0;
}
