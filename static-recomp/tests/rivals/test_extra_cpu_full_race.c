/* Isolated, cold-process settings and complete single-race regression.
   Only P1 controller inputs drive the race. CPU code/state/fuel are untouched. */
#define main career_contract_main
#include "../test_career_v2.c"
#undef main
#include "career_fuel_driver.inc"
#include "topgear_player_settings_file.h"
#include "topgear_frontend_settings_win32.h"
#include <windows.h>
static unsigned word(unsigned a){return c->wram[a]|((unsigned)c->wram[a+1]<<8);}
static const char *tracks[]={"Las Vegas","Los Angeles","New York","San Francisco","Rio","Machu Picchu","Chichen Itza","Rain Forest","Tokyo","Hiroshima","Yokohama","Kyoto","Munich","Cologne","Black Forest","Frankfurt","Stockholm","Copenhagen","Helsinki","Oslo","Paris","Nice","Bordeaux","Monaco","Pisa","Rome","Sicily","Florence","London","Sheffield","Loch Ness","Stonehenge"};
static char profile_path[2048];static wchar_t ini_path[2048];static int wanted;
static uint8_t cache[96];static TopGearFrontendSettingsWin32 settings;
static void checksum(uint8_t *b){unsigned n;uint32_t h=2166136261u;for(n=16;n<96;n++)h=(h^b[n])*16777619u;for(n=0;n<4;n++)b[12+n]=(uint8_t)(h>>(8*n));}
static int boot(void){return frames(1560,0)&&frames(120,0x1000)&&frames(220,0)&&c->mod_menu_remodel_active&&c->mod_menu_remodel_page==0&&!c->mod_time_trial_active;}
static int settings_menu(void){unsigned n;if(!press(0x0400)||!press(0x0400)||!press(0x0400)||!press(0x0080))return 0;for(n=0;n<6;n++)if(!press(0x0400))return 0;return c->mod_menu_remodel_selection==6;}
static int save_options(void){uint8_t b[96];
 if(!topgear_recomp_profile_record(c,b,96)||!!(b[95]&64)==!!wanted)return 0;
 if(!topgear_player_settings_write_bytes(profile_path,b))return 0;
 settings.extra_cpu_drivers_enabled=topgear_recomp_extra_cpu_drivers_enabled(c);
 settings.bottom_screen_enabled=topgear_recomp_bottom_screen_enabled(c);
 settings.center_screen_enabled=topgear_recomp_center_screen_enabled(c);
 settings.show_fps_counter=0;
 return topgear_frontend_settings_win32_save(&settings,ini_path);
}
static int load_options(void){
 if(!topgear_player_settings_load_file(c,profile_path,cache)||topgear_recomp_extra_cpu_drivers_enabled(c)!=wanted)return 0;
 topgear_frontend_settings_win32_load(&settings,ini_path);
 if(!settings.extra_cpu_drivers_saved||settings.extra_cpu_drivers_enabled!=wanted||settings.show_fps_counter)return 0;
 topgear_recomp_set_bottom_screen_enabled(c,settings.bottom_screen_enabled);
 topgear_recomp_set_center_screen_enabled(c,settings.center_screen_enabled);
 topgear_recomp_set_extra_cpu_drivers_enabled(c,settings.extra_cpu_drivers_enabled);
 return 1;
}
int main(int argc,char **argv){
 uint8_t rom[524288],b[96];FILE *f;unsigned mode,n,wait,k,course,lap_count,pit_entries=0,previous_pit=0;
 unsigned places[20]={0},finish_count,initial_fuel[2],assigned[4]={1,0,2,3};
 char result_path[2048],snapshot[2048];Driver driver={0};LARGE_INTEGER freq,begin,end;double elapsed;
 if(argc!=6)return 2;dir=argv[2];mode=(unsigned)atoi(argv[3]);wanted=atoi(argv[4]);
 if(mode>1||wanted<0||wanted>1)return 2;
 snprintf(profile_path,sizeof(profile_path),"%s/player-settings.dat",dir);swprintf(ini_path,2048,L"%hs/settings.ini",dir);
 f=fopen(argv[1],"rb");CHECK(f&&fread(rom,1,sizeof(rom),f)==sizeof(rom));fclose(f);
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
 if(!strcmp(argv[5],"defaults")){
  CHECK(topgear_recomp_bottom_screen_enabled(c)&&!topgear_recomp_center_screen_enabled(c)&&topgear_recomp_extra_cpu_drivers_enabled(c));
  CHECK(boot());
  CHECK(topgear_recomp_bottom_screen_enabled(c)&&!topgear_recomp_center_screen_enabled(c));
  CHECK(settings_menu()&&shot("fresh-defaults-bottom-off-center-off"));
  topgear_frontend_settings_win32_defaults(&settings);CHECK(save_options());
  puts("PASS fresh core, cold boot, visible Settings, profile and INI: Bottom On, Center Off, Extra CPUs On, FPS Off");
  topgear_recomp_destroy(c);return 0;
 }
 if(!strcmp(argv[5],"prepare")){
  CHECK(boot());CHECK(topgear_recomp_player_settings_export(c,b,96));
  b[40]=1;b[41]=0;b[94]=0;b[95]=1;checksum(b);
  CHECK(topgear_recomp_player_settings_import(c,b,96));CHECK(tg_mod_menu_remodel_main_menu_enter(c));
  topgear_recomp_set_bottom_screen_enabled(c,0);topgear_recomp_set_center_screen_enabled(c,0);
  CHECK(settings_menu());
  /* Exercise a real menu edit even for the default On case. */
  CHECK(press(0x0200)&&!topgear_recomp_extra_cpu_drivers_enabled(c));
  if(wanted)CHECK(press(0x0100)&&topgear_recomp_extra_cpu_drivers_enabled(c));
  CHECK(topgear_recomp_extra_cpu_drivers_enabled(c)==wanted);
  topgear_frontend_settings_win32_defaults(&settings);CHECK(save_options()&&shot("saved-setting-before-exit"));
  printf("PREPARE PASS mode=%s ExtraCPUDrivers=%d menu_edit=1 durable_profile_and_INI=1 process=%lu FPS_counter=Off\n",mode?"Rally":"Career",wanted,GetCurrentProcessId());
  topgear_recomp_destroy(c);return 0;
 }
 CHECK(load_options());CHECK(boot());
 CHECK(topgear_recomp_extra_cpu_drivers_enabled(c)==wanted&&word(0x1f8f)==1&&!word(0x1f04));
 if(!strcmp(argv[5],"check")){
  CHECK(settings_menu()&&topgear_recomp_extra_cpu_drivers_enabled(c)==wanted&&shot("saved-setting-after-race-restart"));
  printf("RESTART PASS mode=%s ExtraCPUDrivers=%d profile=%d INI=%d visible_settings_menu=1 process=%lu FPS_counter=Off\n",mode?"Rally":"Career",wanted,topgear_recomp_extra_cpu_drivers_enabled(c),settings.extra_cpu_drivers_enabled,GetCurrentProcessId());
  topgear_recomp_destroy(c);return 0;
 }
 CHECK(!strcmp(argv[5],"race"));
 printf("COLD_START PASS mode=%s ExtraCPUDrivers=%d profile_and_INI_agree=1 P1=White snapshots_loaded=0 process=%lu\n",mode?"Rally":"Career",wanted,GetCurrentProcessId());fflush(stdout);
 /* Normal waiting time changes the native Rally seed on each cold start. */
 CHECK(frames(37u+(unsigned)(GetTickCount64()%179u),0));
 if(mode)CHECK(press(0x0400));CHECK(press(0x0080));
 CHECK(press(0x0400)&&press(0x0400));if(!mode)CHECK(press(0x0400));CHECK(press(0x0080));
 for(wait=0;wait<3500&&c->hdma_enable_mask!=0x7f;wait++)CHECK(frames(1,0));CHECK(wait<3500);
 CHECK(!c->mod_time_trial_active&&!!c->mod_rally_active==!!mode&&!word(0x1f04)&&word(0x1f8f)==1);
 course=word(0x1f06);CHECK(course<32);lap_count=word(0x1e56);initial_fuel[0]=word(0x1e62);initial_fuel[1]=word(0x1e64);
 printf("START mode=%s extra=%d track=%s course=%u laps=%u pit_track=%u P1_fuel=%u JONES_fuel=%u natural_full_tanks=1\n",mode?"Rally":"Career",wanted,tracks[course],course,lap_count,word(0x1ef0),initial_fuel[0],initial_fuel[1]);fflush(stdout);
 CHECK(shot("race-start"));QueryPerformanceFrequency(&freq);QueryPerformanceCounter(&begin);
 for(n=0;n<60000&&word(0x1eb0)<10;n++){
  TopGearRecompFrameResult result;
  CHECK(topgear_recomp_advance_headless(c,driver_input(c,&driver,c->wram,c->mode1_frame,word(0x1f7a)|word(0x1f7c)),0,1,&result));topgear_recomp_audio_clear(c);
  CHECK(!c->mod_time_trial_active&&!word(0x1f04)&&topgear_recomp_extra_cpu_drivers_enabled(c)==wanted);
  {unsigned phase=word(0x1e86);if(!previous_pit&&phase>=0x8000u)pit_entries++;previous_pit=phase;}
  if(!wanted)CHECK(!c->rivals.rival[0].updates&&!c->rivals.rival[1].updates&&!c->rivals.rival[0].pit_stops&&!c->rivals.rival[1].pit_stops);
  if(n==2000)CHECK(shot("race-driving"));
  if(n%2000==0){printf("PROGRESS %s extra=%d frame=%u P1lap=%d fuel=%u finishers=%u private_updates=%u/%u\n",mode?"Rally":"Career",wanted,n,(int)(int16_t)word(0x1e76),word(0x1e62),word(0x1eb0),c->rivals.rival[0].updates,c->rivals.rival[1].updates);fflush(stdout);}
 }
 QueryPerformanceCounter(&end);elapsed=(double)(end.QuadPart-begin.QuadPart)/freq.QuadPart;CHECK(n<60000);
 finish_count=word(0x1eb0);CHECK(finish_count>=10&&!c->rivals.overflow);
 for(k=0;k<finish_count&&k<20;k++){unsigned id=c->wram[0x1f12+k];CHECK(id<20&&!places[id]);places[id]=k+1;}
 if(wanted){unsigned used=1u<<1;CHECK(c->rivals.rival[0].updates&&c->rivals.rival[1].updates);
  for(k=1;k<4;k++){assigned[k]=c->rivals.cars[k];CHECK(!(used&(1u<<assigned[k])));used|=1u<<assigned[k];}CHECK(used==15);
 }
 else {assigned[1]=word(0x1fac)&3u;assigned[2]=assigned[3]=255u;}
 printf("END mode=%s extra=%d track=%s natural_finishers=%u frames=%u headless_throughput_FPS=%.2f P1_place=%u JONES=%u SENNA=%u MANSELL=%u P1_pits=%u CPU_extra_pits=%u/%u shadow_failures=%u overflow=%u\n",mode?"Rally":"Career",wanted,tracks[course],finish_count,n,n/elapsed,places[0],places[1],places[2],places[3],pit_entries,c->rivals.rival[0].pit_stops,c->rivals.rival[1].pit_stops,c->rivals.shadow_failures,c->rivals.overflow);fflush(stdout);
 snprintf(snapshot,sizeof(snapshot),"%s/race-end.scsnap",dir);CHECK(topgear_recomp_snapshot_save(c,snapshot,error,sizeof(error))&&shot("race-end"));
 snprintf(result_path,sizeof(result_path),"%s/results.json",dir);f=fopen(result_path,"wb");CHECK(f);
 fprintf(f,"{\n\"mode\":\"%s\",\"extra_cpu_drivers\":%d,\"track\":\"%s\",\"course\":%u,\"laps\":%u,\"native_race_completed\":true,\"finishers\":%u,\"frames\":%u,\"headless_throughput_fps\":%.2f,\"p1_pit_entries\":%u,\"p1_fuel_at_end\":%u,\"shadow_failures\":%u,\"overflow\":%u,\"extra_updates\":[%u,%u],\"extra_pits\":[%u,%u],\"car_types_p1_jones_senna_mansell\":[%u,%u,%u,%u],\"finish_places\":[",mode?"Rally":"Career",wanted,tracks[course],course,lap_count,finish_count,n,n/elapsed,pit_entries,word(0x1e62),c->rivals.shadow_failures,c->rivals.overflow,c->rivals.rival[0].updates,c->rivals.rival[1].updates,c->rivals.rival[0].pit_stops,c->rivals.rival[1].pit_stops,assigned[0],assigned[1],assigned[2],assigned[3]);
 for(k=0;k<20;k++)fprintf(f,"%s%u",k?",":"",places[k]);fprintf(f,"]\n}\n");CHECK(!fclose(f));
 CHECK(frames(600,0)&&shot("race-results"));CHECK(save_options());
 printf("RACE_SAVE PASS mode=%s ExtraCPUDrivers=%d durable_profile_and_INI=1 native_result_screen=%u retries=0\n",mode?"Rally":"Career",wanted,c->mod_continue_screen);fflush(stdout);
 topgear_recomp_destroy(c);return 0;
}
