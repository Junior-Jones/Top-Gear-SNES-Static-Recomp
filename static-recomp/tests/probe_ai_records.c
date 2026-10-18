/* Read-only gameplay probe. Saves writer sites, WRAM and OAM observations. */
#include "topgear_internal.h"
#include <stdio.h>
#include <string.h>
static TopGearRecomp *c;
static struct {unsigned pc,field,count;} sites[1024];
static unsigned used;
static int trace(void *user,const TopGearHookEvent *e){unsigned n,a=e->address&0xffffu,pc; (void)user;
 if(e->type!=TOPGEAR_HOOK_EVENT_BUS_WRITE||a<0x212u||a>=0x37au)return 0;
 pc=((unsigned)c->cpu.pbr<<16)|c->cpu.pc;
 for(n=0;n<used;n++)if(sites[n].pc==pc&&sites[n].field==(a-0x212u)%18u){sites[n].count++;return 0;}
 if(used<1024){sites[used].pc=pc;sites[used].field=(a-0x212u)%18u;sites[used++].count=1;}
 return 0;
}
int main(int argc,char **argv){uint8_t rom[524288];FILE *f;char error[256];TopGearRecompFrameResult result;unsigned n,pals[8]={0};
 if(argc!=4)return 2;
 f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
 if(!topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error))||!topgear_recomp_snapshot_load(c,argv[2],error,sizeof(error)))return 1;
 if(!topgear_recomp_set_hook(c,TOPGEAR_HOOK_MASK_BUS,trace,NULL))return 1;
 for(n=0;n<180;n++){if(!topgear_recomp_advance_headless(c,0x0040,0,1,&result))return 1;topgear_recomp_audio_clear(c);}
 topgear_recomp_clear_hook(c);
 f=fopen(argv[3],"w");if(!f)return 2;fprintf(f,"pc,record_byte,writes\n");for(n=0;n<used;n++)fprintf(f,"%06X,%u,%u\n",sites[n].pc,sites[n].field,sites[n].count);fclose(f);
 for(n=0;n<128;n++)if(c->oam[n*4+1]<224)pals[(c->oam[n*4+3]>>1)&7]++;
 printf("Observed %u car-record writer/byte sites over 180 unforced race frames. Visible OAM palette counts:",used);
 for(n=0;n<8;n++)printf(" %u:%u",n,pals[n]);puts("");
 {
  const unsigned offsets[4]={0x20000,0x20f60,0x21ec0,0x22e20};
  const char *names[4]={"Cannibal","Sidewinder","Razor","Weasel"};
  unsigned view,car;
  printf("RAM P1 car=%u P2/CPU car=%u\n",c->wram[0x1f8f],c->wram[0x1fac]);
  for(view=0;view<2;view++){
   printf("OBJ palette %u:",view);
   for(n=0;n<16;n++){unsigned a=(128u+view*16u+n)*2u;printf(" %04X",c->cgram[a]|(c->cgram[a+1]<<8));}
   puts("");
  }
  for(view=0;view<2;view++)for(car=0;car<4;car++)
   if(!memcmp(c->vram+(view?0x5000:0x4000),rom+offsets[car],3936))
    printf("Exact VRAM bank match: %s slot=%04X car=%s\n",view?"CPU/P2":"P1",view?0x5000:0x4000,names[car]);
 }
 topgear_recomp_destroy(c);return 0;
}
