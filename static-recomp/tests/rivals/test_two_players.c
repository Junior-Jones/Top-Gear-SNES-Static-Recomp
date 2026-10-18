#define main career_contract_main
#include "../test_career_v2.c"
#undef main
#include "existing_self_driver.inc"
#include <windows.h>
static unsigned word(unsigned a){return c->wram[a]|c->wram[a+1]<<8;}
static unsigned ordinary_position(unsigned id){unsigned off;for(off=0;off<360;off+=18)if(off!=word(0x204)&&off!=word(0x206)&&(word(0x212+off)&31u)==id)return word(0x219+off);return 65535;}
int main(int argc,char **argv){
 uint8_t rom[524288];FILE *f;unsigned mode,n;TopGearRecompFrameResult result;
 if(argc!=4)return 2;dir=argv[3];f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
 for(mode=0;mode<2;mode++){
  Driver driver={0};unsigned p1,p2,lit=0,pos2,pos3;LARGE_INTEGER frequency,begin,end;double seconds=0;QueryPerformanceFrequency(&frequency);
  CHECK(topgear_recomp_snapshot_load(c,argv[2],error,sizeof(error)));
  CHECK(!c->mod_time_trial_active&&c->mod_menu_remodel_active&&c->mod_menu_remodel_page==0);
  topgear_recomp_set_center_screen_enabled(c,0);topgear_recomp_set_bottom_screen_enabled(c,0);
  if(mode)CHECK(press(0x0400));CHECK(press(0x0080));CHECK(press(0x0100)&&word(0x1f04));p1=word(0x1f8f);p2=word(0x1fac);
  CHECK(press(0x0400)&&press(0x0400));if(!mode)CHECK(press(0x0400));
  CHECK(press(0x0080)&&frames(1900,0));CHECK(c->hdma_enable_mask==0x7f&&!c->mod_time_trial_active);
  CHECK(!c->rivals.ready&&word(0x1f8f)==p1&&word(0x1fac)==p2);CHECK(c->mod_bottom_screen_off&&!tg_mod_bottom_screen_off(c));
  pos2=ordinary_position(2);pos3=ordinary_position(3);CHECK(pos2!=65535&&pos3!=65535);
  for(n=0;n<600;n++){
   QueryPerformanceCounter(&begin);
   CHECK(topgear_recomp_advance_headless(c,driver_input(c,&driver,c->wram,c->mode1_frame,word(0x1f7a)|word(0x1f7c)),0x40,1,&result));topgear_recomp_audio_clear(c);
   QueryPerformanceCounter(&end);seconds+=(double)(end.QuadPart-begin.QuadPart)/frequency.QuadPart;
   CHECK(!c->mod_time_trial_active&&!tg_mod_bottom_screen_off(c));CHECK(!c->rivals.ready&&!c->rivals.visible.count&&!c->rivals.rival[0].updates&&!c->rivals.rival[1].updates);
  }
  CHECK(ordinary_position(2)!=pos2&&ordinary_position(3)!=pos3);
  for(n=108*256;n<224*256;n++)if(c->mode1_frame[2*n]||c->mode1_frame[2*n+1])lit++;
  CHECK(lit>1000&&shot(mode?"rally-two-players":"career-two-players"));
  printf("PERFORMANCE %s headless_frames=600 seconds=%.6f throughput_fps=%.2f (not window presentation FPS)\n",mode?"Rally":"Career",seconds,600/seconds);
  printf("PASS %s native menu two-player start, no added CPU drivers, human cars=%u/%u unchanged, Bottom Off overridden, lower_lit=%u, both restored ordinary slots moving, private_updates=0/0 private_objects=0\n",mode?"Rally":"Career",p1,p2,lit);fflush(stdout);
 }
 topgear_recomp_destroy(c);return 0;
}
