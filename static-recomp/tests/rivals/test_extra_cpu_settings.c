#define main career_contract_main
#include "../test_career_v2.c"
#undef main
#include "topgear_player_settings_file.h"
#include <windows.h>
static unsigned word(unsigned a){return c->wram[a]|c->wram[a+1]<<8;}
static unsigned ordinary(unsigned id){unsigned off;for(off=0;off<360;off+=18)if(off!=word(0x204)&&off!=word(0x206)&&(word(0x212+off)&31u)==id)return off;return 360;}
static void checksum(uint8_t *b){unsigned n;uint32_t h=2166136261u;for(n=16;n<96;n++)h=(h^b[n])*16777619u;for(n=0;n<4;n++)b[12+n]=(uint8_t)(h>>(8*n));}
static int sound_press(uint16_t button){
 uint64_t navigation=c->mod_insert_audio_navigation_change_count,keyon=c->mod_insert_audio_cue_keyon_count;
 return press(button)&&c->mod_insert_audio_navigation_change_count>navigation&&c->mod_insert_audio_cue_keyon_count>keyon;
}
int main(int argc,char **argv){
 uint8_t rom[524288],b[96],cache[96];FILE *f;unsigned n,mode,players,on;char path[2048],label[80];
 TopGearPlayerProfile profile;
 if(argc!=4&&argc!=5)return 2;dir=argv[3];f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
 CHECK(topgear_recomp_extra_cpu_drivers_enabled(c));
 CHECK(topgear_recomp_snapshot_load(c,argv[2],error,sizeof(error)));
 CHECK(c->mod_menu_remodel_active&&c->mod_menu_remodel_page==0&&!c->mod_time_trial_active);
 CHECK(press(0x0400)&&press(0x0400)&&press(0x0400)&&press(0x0080));
 for(n=0;n<5;n++)CHECK(press(0x0400));
 topgear_recomp_set_bottom_screen_enabled(c,0);topgear_recomp_set_center_screen_enabled(c,0);
 CHECK(c->mod_menu_remodel_selection==5);
 CHECK(sound_press(0x0200)&&topgear_recomp_center_screen_enabled(c));
 CHECK(sound_press(0x0100)&&!topgear_recomp_center_screen_enabled(c));
 CHECK(press(0x0400));
 CHECK(c->mod_menu_remodel_selection==6&&shot("settings-extra-cpu-on"));
 topgear_recomp_set_bottom_screen_enabled(c,0);
 CHECK(press(0x0080)&&!topgear_recomp_extra_cpu_drivers_enabled(c)&&shot("settings-extra-cpu-off"));
 CHECK(sound_press(0x0200)&&topgear_recomp_extra_cpu_drivers_enabled(c));
 CHECK(sound_press(0x0100)&&!topgear_recomp_extra_cpu_drivers_enabled(c));
 puts("PASS Center Screen and Extra CPUs: both Left and Right request navigation audio and key on the audio cue");
 CHECK(topgear_recomp_player_settings_export(c,b,96)&&b[4]==8&&(b[95]&64));
 snprintf(path,sizeof(path),"%s/player-settings.dat",dir);
 CHECK(topgear_player_settings_write_bytes(path,b));
 /* Launcher Profile must accept the new record and preserve option bits. */
 CHECK(topgear_player_profile_file_read(path,0,&profile));
 profile.car=1;CHECK(topgear_player_profile_file_write(path,0,&profile));
 CHECK(press(0x0400)&&c->mod_menu_remodel_selection==7&&shot("settings-back-inside-border")&&press(0x0080)&&c->mod_menu_remodel_page==0);
 tg_rivals_reset(c);CHECK(!topgear_recomp_extra_cpu_drivers_enabled(c));
 topgear_recomp_destroy(c);c=NULL;
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
 CHECK(topgear_player_settings_load_file(c,path,cache)&&!topgear_recomp_extra_cpu_drivers_enabled(c));
 CHECK(topgear_recomp_profile_record(c,b,96)&&b[4]==8&&(b[95]&64));
 b[4]=7;b[95]&=63;checksum(b);
 CHECK(topgear_recomp_player_settings_import(c,b,96)&&topgear_recomp_extra_cpu_drivers_enabled(c));
 puts("PASS menu A/Left/Right, Back, profile v8, disk save/cold restart, launcher Profile edit, race reset, legacy v7 default On");fflush(stdout);
 if(argc==5){topgear_recomp_destroy(c);return 0;}
 for(mode=0;mode<2;mode++)for(players=0;players<2;players++)for(on=0;on<2;on++){
  unsigned off2,off3,pos2,pos3;LARGE_INTEGER frequency,begin,end;double seconds;
  CHECK(topgear_recomp_snapshot_load(c,argv[2],error,sizeof(error)));
  CHECK(topgear_recomp_profile_record(c,b,96));b[40]=1;b[41]=0;b[94]=(uint8_t)players;b[95]=1;checksum(b);
  CHECK(topgear_recomp_player_settings_import(c,b,96));tg_mod_menu_remodel_main_menu_enter(c);
  topgear_recomp_set_extra_cpu_drivers_enabled(c,on);
  if(mode)CHECK(press(0x0400));CHECK(press(0x0080)&&word(0x1f04)==players);
  CHECK(press(0x0400)&&press(0x0400));if(!mode)CHECK(press(0x0400));
  CHECK(press(0x0080)&&frames(1900,0));
  CHECK(c->hdma_enable_mask==0x7f&&!c->mod_time_trial_active&&!!c->mod_rally_active==!!mode);
  CHECK(topgear_recomp_extra_cpu_drivers_enabled(c)==(int)on);
  off2=ordinary(2);off3=ordinary(3);CHECK(off2<360&&off3<360);
  pos2=word(0x219+off2);pos3=word(0x219+off3);
  QueryPerformanceFrequency(&frequency);QueryPerformanceCounter(&begin);
  CHECK(frames(180,0x0040));QueryPerformanceCounter(&end);seconds=(double)(end.QuadPart-begin.QuadPart)/frequency.QuadPart;
  if(on&&!players){
   unsigned used=1u<<1;CHECK(c->rivals.ready&&c->rivals.rival[0].updates&&c->rivals.rival[1].updates);
   CHECK(tg_rivals_promoted(c,ordinary(2))&&tg_rivals_promoted(c,ordinary(3)));
   for(n=1;n<4;n++){CHECK(!(used&(1u<<c->rivals.cars[n])));used|=1u<<c->rivals.cars[n];}CHECK(used==15);
  }else{
   CHECK(!c->rivals.rival[0].updates&&!c->rivals.rival[1].updates);
   CHECK(!tg_rivals_promoted(c,ordinary(2))&&!tg_rivals_promoted(c,ordinary(3)));
   CHECK(word(0x219+ordinary(2))!=pos2&&word(0x219+ordinary(3))!=pos3);
   if(!players)CHECK(c->rivals.ready&&c->rivals.palettes[20][8]&&c->rivals.palettes[21][8]);
  }
  snprintf(label,sizeof(label),"%s-%up-extra-%s",mode?"rally":"career",players+1,on?"on":"off");CHECK(shot(label));
  printf("PASS %s private_updates=%u/%u original_cpu_car=%u FPS headless_throughput=%.2f (not display FPS)\n",label,c->rivals.rival[0].updates,c->rivals.rival[1].updates,word(0x1fac),180/seconds);fflush(stdout);
 }
 topgear_recomp_destroy(c);puts("PASS all settings and Career/Rally start checks; no Trial races");return 0;
}
