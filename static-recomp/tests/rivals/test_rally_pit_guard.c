#define main career_contract_main
#include "../test_career_v2.c"
#undef main
#include "rally_pit_guard_driver.inc"
#include <windows.h>
static unsigned word(unsigned a){return c->wram[a]|c->wram[a+1]<<8;}
static const char *tracks[]={"Las Vegas","Los Angeles","New York","San Francisco","Rio","Machu Picchu","Chichen Itza","Rain Forest","Tokyo","Hiroshima","Yokohama","Kyoto","Munich","Cologne","Black Forest","Frankfurt","Stockholm","Copenhagen","Helsinki","Oslo","Paris","Nice","Bordeaux","Monaco","Pisa","Rome","Sicily","Florence","London","Sheffield","Loch Ness","Stonehenge"};
static const char *cars[]={"Red Cannibal","White Sidewinder","Purple Razor","Blue Weasel"};
static void save(const char *label){char path[1024];snprintf(path,sizeof(path),"%s/%s.scsnap",dir,label);if(!topgear_recomp_snapshot_save(c,path,error,sizeof(error))){fprintf(stderr,"snapshot failed: %s\n",error);exit(1);}}
int main(int argc,char **argv){
 uint8_t rom[524288],profile[96],last_order[20];unsigned last_points[20]={0},have_standings=0;FILE *f,*csv;unsigned race,n,k,id,rank,wait,schedule[8],disqualified=0;char path[1024],label[80];
 if(argc!=3)return 2;dir=argv[2];f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
 /* Cold boot: no saved machine state or schedule loaded. Real process start
    timing chooses only a normal menu waiting interval, never the game seed. */
 CHECK(frames(1560,0)&&frames(120,0x1000)&&frames(220,0));
 {unsigned delay=37u+(unsigned)(GetTickCount64()%179u);printf("BOOT cold_reset=1 snapshots_loaded=0 menu_wait_frames=%u\n",delay);CHECK(frames(delay,0));}

 CHECK(c->mod_menu_remodel_active&&c->mod_menu_remodel_page==0&&!c->mod_time_trial_active&&!c->mod_rally_active);
 topgear_recomp_set_center_screen_enabled(c,0);topgear_recomp_set_bottom_screen_enabled(c,1);
 /* Select white through the public pre-race player-settings interface, so the
    native race initialization installs white-car physics/graphics normally. */
 CHECK(topgear_recomp_player_settings_export(c,profile,sizeof(profile)));
 profile[40]=1;profile[41]=0;profile[94]=0;
 {uint32_t hash=2166136261u;for(n=16;n<96;n++)hash=(hash^profile[n])*16777619u;for(n=0;n<4;n++)profile[12+n]=(uint8_t)(hash>>(n*8));}
 CHECK(topgear_recomp_player_settings_import(c,profile,sizeof(profile)));CHECK(tg_mod_menu_remodel_main_menu_enter(c));
 printf("PROFILE P1car=%u players=%u shared_car=%u pending=%u\n",word(0x1f8f),word(0x1f04),c->mod_setup_shared[0][24],c->mod_setup_import_pending);
 CHECK(press(0x0400)&&press(0x0080)&&c->mod_menu_remodel_page==2);CHECK(word(0x1f8f)==1&&!word(0x1f04));
 CHECK(press(0x0400)&&press(0x0400)&&press(0x0080));
 CHECK(c->mod_rally_schedule_valid);
 {const unsigned prior[8]={0,4,8,15,16,20,25,28};unsigned changed=0;for(n=0;n<8;n++)changed+=c->mod_rally_schedule[n]!=prior[n];CHECK(changed>0);printf("NEW_SCHEDULE changed_tracks=%u of=8 no_manual_seed_or_track_edits=1\n",changed);}
 for(n=0;n<8;n++){schedule[n]=c->mod_rally_schedule[n];printf("SCHEDULE race=%u course=%u name=%s cutoff=%u\n",n+1,schedule[n],tracks[schedule[n]],tg_mod_rally_cutoff(n));}
 for(wait=0;wait<3500&&c->hdma_enable_mask!=0x7f;wait++)CHECK(frames(1,0));CHECK(wait<3500);
 snprintf(path,sizeof(path),"%s/results.csv",dir);csv=fopen(path,"wb");CHECK(csv);
 fprintf(csv,"race,course,track,cutoff,id,name,car,crossed,finish_place,classified_place,points,standing,disqualified\n");
 for(race=0;race<8;race++){
  Driver driver={0};unsigned places[20]={0},classified[20]={0},crossed[20]={0},assigned[4]={1,0,2,3},count,cutoff=tg_mod_rally_cutoff(race),previous_pit=0,pit_entries=0,unintended_entries=0;LARGE_INTEGER freq,start,end;
  CHECK(c->mod_rally_active&&!c->mod_time_trial_active&&!word(0x1f04)&&word(0x1f8f)==1&&word(0x1f06)==schedule[race]&&c->mod_rally_race_index==race);
  printf("START race=%u course=%u name=%s laps=%u length=%u pit=%u cutoff=%u P1car=White-Sidewinder\n",race+1,schedule[race],tracks[schedule[race]],word(0x1e56),word(0x200),word(0x1ef0),cutoff);fflush(stdout);
  snprintf(label,sizeof(label),"race-%u-start",race+1);save(label);
  QueryPerformanceFrequency(&freq);QueryPerformanceCounter(&start);
  for(n=0;n<60000&&word(0x1eb0)<10;n++){
   TopGearRecompFrameResult result;unsigned before_fuel=word(0x1e62);
   CHECK(topgear_recomp_advance_headless(c,driver_input(c,&driver,c->wram,c->mode1_frame,word(0x1f7a)|word(0x1f7c)),0,1,&result));topgear_recomp_audio_clear(c);
   {unsigned phase=word(0x1e86);if(!previous_pit&&phase>=0x8000u){
     pit_entries++;if(!driver.pit_intent)unintended_entries++;
     printf("P1_PIT_ENTRY race=%u frame=%u fuel=%u intent=%u lateral=%d position=%u phase=%04X\n",race+1,n,before_fuel,driver.pit_intent,(int)(int16_t)word(0x1e8a),word(0x1ed7),phase);fflush(stdout);
   }previous_pit=phase;}
   CHECK(!c->mod_time_trial_active);
   if(word(0x1eb0)<10){CHECK(c->mod_rally_active&&!word(0x1f04)&&word(0x1f8f)==1);}
   if(c->rivals.ready){CHECK(word(0x1ee8)==16);for(k=0;k<4;k++)CHECK(c->rivals.cars[k]==assigned[k]);}
   if(n==2000){snprintf(label,sizeof(label),"race-%u-driving-white",race+1);CHECK(shot(label));}
   if(n%2000==0){printf("PROGRESS race=%u frame=%u P1lap=%d fuel=%u speed=%u finishers=%u CPUfuel=%u/%u/%u stops=%u/%u\n",race+1,n,(int)(int16_t)word(0x1e76),word(0x1e62),word(0x1e5a),word(0x1eb0),word(0x1e64),c->rivals.rival[0].fuel,c->rivals.rival[1].fuel,c->rivals.rival[0].pit_stops,c->rivals.rival[1].pit_stops);fflush(stdout);}
  }
  printf("PASSING race=%u traffic_frames=%u lane_changes=%u completed_passes=%u emergency_braking_frames=%u\n",race+1,driver.traffic_frames,driver.lane_changes,driver.completed_passes,driver.emergency_frames);
  printf("CONTROLLER race=%u boosts=%u return_wait=%u boost_denied_frames=%u\n",race+1,driver.boost_count,driver.return_hold,driver.boost_denied);
  printf("FLOW race=%u replans=%u corner_braking=%u boost_active_frames=%u nitros_remaining=%u\n",race+1,driver.replans,driver.corner_braking_frames,driver.boost_active_frames,word(0x1e6c)&3u);
  printf("PIT_GUARD race=%u approach_frames=%u P1_entries=%u unintended_entries=%u CPU_stops=%u/%u\n",race+1,driver.pit_guard_frames,pit_entries,unintended_entries,c->rivals.rival[0].pit_stops,c->rivals.rival[1].pit_stops);
  CHECK(driver.emergency_frames==0);
  CHECK(n<60000);QueryPerformanceCounter(&end);printf("TIMING race=%u frames=%u headless_fps=%.2f\n",race+1,n,(double)n*freq.QuadPart/(end.QuadPart-start.QuadPart));
  count=word(0x1eb0);for(k=0;k<count&&k<20;k++){id=c->wram[0x1f12+k];CHECK(id<20&&!crossed[id]);crossed[id]=1;places[id]=k+1;classified[id]=k+1;}
  printf("DIAGNOSTICS race=%u shadow_checks=%u shadow_failures=%u overflow=%u\n",race+1,c->rivals.shadow_checks,c->rivals.shadow_failures,c->rivals.overflow);fflush(stdout);
  snprintf(label,sizeof(label),"race-%u-end",race+1);save(label);
  /* Snapshot/ranks still describe the race here. The failure path later clears 1F00. */
  if(!classified[0]&&word(0x1e7a)<20)classified[0]=word(0x1e7a)+1;
  if(!classified[1]&&word(0x1e7c)<20)classified[1]=word(0x1e7c)+1;
  CHECK(frames(600,0));
  disqualified=(c->mod_continue_screen==5);
  snprintf(label,sizeof(label),"race-%u-%s",race+1,disqualified?"disqualified":"race-results");CHECK(shot(label));save(label);
  if(!disqualified){
   CHECK(!c->mod_continue_screen&&press(0x0080)&&frames(300,0));
   snprintf(label,sizeof(label),"race-%u-standings",race+1);CHECK(shot(label));save(label);
   {unsigned seen=0;for(rank=0;rank<20;rank++){id=c->wram[0x1f62+rank];CHECK(id<20&&!(seen&(1u<<id)));seen|=1u<<id;last_order[rank]=(uint8_t)id;}}
   for(id=0;id<20;id++)last_points[id]=c->wram[0x1f4e+id];have_standings=1;
  }
  for(id=0;id<20;id++){
   unsigned standing=0;const char *name=id==0?"P1":tg_rivals_name(id);const char *car=id<4?cars[assigned[id]]:"Ordinary";
   if(have_standings)for(rank=0;rank<20;rank++)if(last_order[rank]==id)standing=rank+1;
   fprintf(csv,"%u,%u,%s,%u,%u,%.8s,%s,%u,%u,%u,%u,%u,%u\n",race+1,schedule[race],tracks[schedule[race]],cutoff,id,name,car,crossed[id],places[id],classified[id],last_points[id],standing,disqualified);
   if(id<4)printf("RESULT race=%u driver=%.8s car=%s finish=%u classified=%u crossed=%u points=%u standing=%u disqualified=%u\n",race+1,name,car,places[id],classified[id],crossed[id],last_points[id],standing,disqualified);
  }
  fflush(csv);fflush(stdout);
  if(disqualified){printf("STOP disqualified_at_race=%u P1classified=%u required_top=%u retries=0\n",race+1,classified[0],cutoff);fflush(stdout);break;}
  CHECK(press(0x0080));
  for(wait=0;wait<4000;wait++){if(race==7?(c->mod_menu_remodel_active&&c->mod_menu_remodel_page==0):c->mod_rally_active&&c->mod_rally_race_index==race+1&&word(0x1f06)==schedule[race+1]&&c->hdma_enable_mask==0x7f)break;CHECK(frames(1,0));}
  CHECK(wait<4000);if(race==7)puts("COMPLETED eight Rally races");
 }
 fclose(csv);topgear_recomp_destroy(c);puts("PASS Rally white-car natural journey; no retries or CPU/fuel/results overrides");return 0;
}
