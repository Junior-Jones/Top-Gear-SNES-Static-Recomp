#include "topgear_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "existing_self_driver.inc"
static TopGearRecomp *c;static char error[256];
static unsigned w(unsigned a){return c->wram[a]|(c->wram[a+1]<<8);}
#define CHECK(v) do{if(!(v)){fprintf(stderr,"FAIL line=%d %s (%s)\n",__LINE__,#v,error);return 1;}}while(0)
static int advance(uint16_t input){TopGearRecompFrameResult r;int ok=topgear_recomp_advance_headless(c,input,0,1,&r);topgear_recomp_audio_clear(c);return ok;}
int main(int argc,char **argv){uint8_t rom[524288],ram[131072],frame[256*224*2],profile[96],again[96];TgRivals saved;uint16_t inputs[120];FILE *f;Driver d={0};unsigned n,pass;
 if(argc!=4)return 2;f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));CHECK(topgear_recomp_snapshot_load(c,argv[2],error,sizeof(error)));
 for(n=0;n<360;n++)CHECK(advance(driver_input(c,&d,c->wram,c->mode1_frame,0)));
 CHECK(c->rivals.ready);CHECK(topgear_recomp_profile_record(c,profile,sizeof(profile)));
 for(pass=0;pass<2;pass++){
  if(pass){TgRival *a=&c->rivals.rival[0],*b=&c->rivals.rival[1];a->fuel=12000;a->pit_phase=-6;a->gate=1;a->pit_elapsed=128;a->speed=0;
   b->fuel=40000;b->pit_phase=-7;b->gate=1;b->pit_elapsed=128;b->speed=0;}
  CHECK(topgear_recomp_snapshot_save(c,argv[3],error,sizeof(error)));
  for(n=0;n<120;n++){inputs[n]=driver_input(c,&d,c->wram,c->mode1_frame,0);CHECK(advance(inputs[n]));}
  saved=c->rivals;memcpy(ram,c->wram,sizeof(ram));memcpy(frame,c->mode1_frame,sizeof(frame));
  CHECK(topgear_recomp_snapshot_load(c,argv[3],error,sizeof(error)));
  for(n=0;n<120;n++)CHECK(advance(inputs[n]));
  CHECK(!memcmp(&saved,&c->rivals,sizeof(saved)));CHECK(!memcmp(ram,c->wram,sizeof(ram)));CHECK(!memcmp(frame,c->mode1_frame,sizeof(frame)));
  if(pass){CHECK(c->rivals.rival[0].refill_updates>0);CHECK(c->rivals.rival[0].fuel!=c->rivals.rival[1].fuel);}
 }
 CHECK(topgear_recomp_profile_record(c,again,sizeof(again)));CHECK(!memcmp(profile,again,sizeof(profile)));
 {unsigned human=profile[66]|(profile[67]<<8);tg_rivals_menu_enter(c);CHECK(w(0x1fac)==human);CHECK(topgear_recomp_profile_record(c,again,sizeof(again)));CHECK(!memcmp(profile,again,sizeof(profile)));}
 printf("PASS replay_normal=120 replay_independent_mid_pit=120 exact_private_state_WRAM_pixels=1 profile_preserved=1 human_P2_car_restored=1\n");
 topgear_recomp_destroy(c);return 0;
}
