#define main career_contract_main
#include "../test_career_v2.c"
#undef main
#include "career_fuel_driver.inc"
static unsigned word(unsigned a){return c->wram[a]|((unsigned)c->wram[a+1]<<8);}
static uint32_t output[256*224];
static int image_out(const char *name){char path[2048];FILE *f;unsigned n;
 if(!topgear_recomp_frame_bgra(c,output,256*224))return 0;
 snprintf(path,sizeof(path),"%s/%s.ppm",dir,name);f=fopen(path,"wb");if(!f)return 0;
 fprintf(f,"P6\n256 224\n255\n");for(n=0;n<256*224;n++){uint8_t rgb[3]={(uint8_t)(output[n]>>16),(uint8_t)(output[n]>>8),(uint8_t)output[n]};fwrite(rgb,1,3,f);}return fclose(f)==0;
}
static unsigned lower_pixels(void){unsigned n,lit=0;for(n=108*256;n<224*256;n++)lit+=c->mode1_frame[n*2]||c->mode1_frame[n*2+1];return lit;}
static int centered(void){unsigned x,y;
 if(!topgear_recomp_frame_bgra(c,output,256*224)||lower_pixels())return 0;
 for(y=0;y<224;y++)for(x=0;x<256;x++){
  uint32_t expected=0xff000000u;
  if(y>=60&&y<164){unsigned a=((y-56)*256+x)*2,v=c->mode1_frame[a]|c->mode1_frame[a+1]<<8,r=v&31,g=v>>5&31,b=v>>10&31;expected|=((r<<3|r>>2)<<16)|((g<<3|g>>2)<<8)|(b<<3|b>>2);}
  if(output[y*256+x]!=expected)return 0;
 }
 return 1;
}
int main(int argc,char **argv){uint8_t rom[524288],record[96];FILE *f;unsigned mode,n;char root[2048],name[80],path[2048];
 if(argc!=3)return 2;dir=argv[2];f=fopen(argv[1],"rb");CHECK(f&&fread(rom,1,sizeof(rom),f)==sizeof(rom));fclose(f);
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
 CHECK(topgear_recomp_bottom_screen_enabled(c)&&!topgear_recomp_center_screen_enabled(c));
 CHECK(frames(1560,0)&&frames(120,0x1000)&&frames(220,0));
 snprintf(root,sizeof(root),"%s/root.snap",dir);CHECK(topgear_recomp_snapshot_save(c,root,error,sizeof(error)));
 for(mode=0;mode<3;mode++){
  const char *label=mode==0?"career":mode==1?"rally":"trial";Driver driver={0};unsigned lit;
  CHECK(topgear_recomp_snapshot_load(c,root,error,sizeof(error)));
  topgear_recomp_set_bottom_screen_enabled(c,1);topgear_recomp_set_center_screen_enabled(c,1);
  CHECK(!topgear_recomp_center_screen_enabled(c));
  for(n=0;n<mode;n++)CHECK(press(0x0400));CHECK(press(0x0080));
  CHECK(press(0x0400)&&press(0x0400));if(mode!=1)CHECK(press(0x0400));CHECK(press(0x0080)&&frames(1900,0));
  CHECK(c->hdma_enable_mask==0x7f&&!!c->mod_rally_active==(mode==1)&&!!c->mod_time_trial_active==(mode==2)&&!word(0x1f04));
  for(n=0;n<600;n++){TopGearRecompFrameResult result;CHECK(topgear_recomp_advance_headless(c,driver_input(c,&driver,c->wram,c->mode1_frame,word(0x1f7a)|word(0x1f7c)),0,1,&result));topgear_recomp_audio_clear(c);}
  CHECK(c->hdma_enable_mask==0x7f&&c->mod_time_trial_font_valid);
  if(mode==2)CHECK(!c->rivals.ready&&!c->rivals.rival[0].updates&&!c->rivals.rival[1].updates);
  else CHECK(c->mod_career_panel);
  lit=lower_pixels();CHECK(lit>100);snprintf(name,sizeof(name),"%s-bottom-on-stats",label);CHECK(image_out(name));
  printf("PASS %s Bottom On: stats visible, lit_pixels=%u font_valid=%u career_panel=%u Trial=%u Rally=%u lap_count=%u sector_mask=%u\n",label,lit,c->mod_time_trial_font_valid,c->mod_career_panel,c->mod_time_trial_active,c->mod_rally_active,c->mod_time_trial_lap_count,c->mod_time_trial_sector_mask);fflush(stdout);
  topgear_recomp_set_bottom_screen_enabled(c,0);CHECK(!topgear_recomp_center_screen_enabled(c)&&frames(2,0)&&!lower_pixels());
  snprintf(name,sizeof(name),"%s-bottom-off-black",label);CHECK(image_out(name));
  topgear_recomp_set_center_screen_enabled(c,1);CHECK(topgear_recomp_center_screen_enabled(c)&&frames(2,0)&&tg_mod_center_screen_race(c)&&centered());
  snprintf(name,sizeof(name),"%s-center-on-black-margins",label);CHECK(image_out(name));
  CHECK(topgear_recomp_profile_record(c,record,96)&&(record[95]&48u)==48u);
  CHECK(topgear_recomp_player_settings_import(c,record,96)&&topgear_recomp_center_screen_enabled(c));
  topgear_recomp_set_bottom_screen_enabled(c,1);CHECK(!topgear_recomp_center_screen_enabled(c)&&frames(2,0)&&lower_pixels()>100);
  snprintf(name,sizeof(name),"%s-bottom-on-stats-restored",label);CHECK(image_out(name));
  snprintf(path,sizeof(path),"%s/%s-final.snap",dir,label);CHECK(topgear_recomp_snapshot_save(c,path,error,sizeof(error)));
  printf("PASS %s: Bottom Off black; Center On allowed only with Bottom Off; both margins black; profile round-trip; turning Bottom On disables Center and restores stats\n",label);fflush(stdout);
 }
 topgear_recomp_destroy(c);return 0;
}
