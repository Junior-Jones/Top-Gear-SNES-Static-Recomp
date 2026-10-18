#define main career_contract_main
#include "../test_career_v2.c"
#undef main
#include "existing_self_driver.inc"
#include <windows.h>
static unsigned word(unsigned a){return c->wram[a]|c->wram[a+1]<<8;}
static int advance_driver(Driver *d){TopGearRecompFrameResult result;
 if(!topgear_recomp_advance_headless(c,driver_input(c,d,c->wram,c->mode1_frame,word(0x1f7a)|word(0x1f7c)),0,1,&result))return 0;
 topgear_recomp_audio_clear(c);return 1;
}

static unsigned mismatch_logs;
static int trace(void *user,const TopGearHookEvent *e){TgRival *r=&c->rivals.shadow;int fail=0;(void)user;if(e->type!=TOPGEAR_HOOK_EVENT_INSTRUCTION_BEFORE||mismatch_logs>=12)return 0;
 if(e->address==0x5f002)fail=r->speed!=word(0x1e5c)||r->fuel!=word(0x1e64)||r->gear!=word(0x1e74)||r->rpm!=word(0x1e60);
 if(e->address==0x5f395)fail=r->steering!=word(0x1e80)||r->upper!=word(0x1ec4)||r->lower!=word(0x1ec6)||r->passing_side!=(c->wram[0x1ec8]!=0);
 if(fail){mismatch_logs++;printf("SHADOW_DETAIL pc=%06X speed=%u/%u fuel=%u/%u gear=%u/%u rpm=%u/%u steer=%u/%u upper=%u/%u lower=%u/%u pass=%u/%u CPUfinish=%04X finishers=%u pit=%04X car=%u ready=%u\n",e->address,r->speed,word(0x1e5c),r->fuel,word(0x1e64),r->gear,word(0x1e74),r->rpm,word(0x1e60),r->steering,word(0x1e80),r->upper,word(0x1ec4),r->lower,word(0x1ec6),r->passing_side,c->wram[0x1ec8],word(0x1f02),word(0x1eb0),word(0x1e88),word(0x1fac),c->rivals.ready);fflush(stdout);}return 0;
}

int main(int argc,char **argv){
 uint8_t rom[524288];FILE *f,*csv;unsigned race,n,wait,id,rank,retries=0;char name[128],path[1024];
 const char *tracks[]={"Las Vegas","Los Angeles","New York","San Francisco"};
 if(argc!=4&&argc!=5)return 2;dir=argv[3];f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
 CHECK(topgear_recomp_snapshot_load(c,argv[2],error,sizeof(error)));
 if(argc==4){
 CHECK(c->mod_menu_remodel_active&&c->mod_menu_remodel_page==0&&!c->mod_rally_active&&!c->mod_time_trial_active);
 topgear_recomp_set_center_screen_enabled(c,0);topgear_recomp_set_bottom_screen_enabled(c,1);
 CHECK(press(0x0080)&&press(0x0400)&&press(0x0400)&&press(0x0400)&&press(0x0080));
 for(wait=0;wait<3000&&c->hdma_enable_mask!=0x7f;wait++)CHECK(frames(1,0));CHECK(wait<3000);
 CHECK(!word(0x1f04)&&!word(0x1f06));
 }else{CHECK(!c->mod_rally_active&&!c->mod_time_trial_active&&!word(0x1f04)&&word(0x1f06)==3);retries=1;}
 snprintf(path,sizeof(path),"%s/results.csv",dir);csv=fopen(path,argc==5?"ab":"wb");CHECK(csv);if(argc==4)fprintf(csv,"track,attempt,id,name,race_place,crossed_before_race_end,points,standing\n");
 CHECK(topgear_recomp_set_hook(c,TOPGEAR_HOOK_MASK_INSTRUCTION,trace,NULL));
 for(race=argc==5?word(0x1f06):0;race<4;){
  Driver driver={0};unsigned crossed[20]={0},places[20]={0},finisher_count;LARGE_INTEGER freq,start,end;
  CHECK(!c->mod_time_trial_active&&!c->mod_rally_active&&!word(0x1f04)&&word(0x1f06)==race);
  printf("START track=%u name=%s P1car=%u skill=%u laps=%u length=%u pit=%u points=%u/%u/%u/%u retries=%u\n",race+1,tracks[race],word(0x1f8f),word(0x1f10),word(0x1e56),word(0x200),word(0x1ef0),c->wram[0x1f4e],c->wram[0x1f4f],c->wram[0x1f50],c->wram[0x1f51],retries);fflush(stdout);
  snprintf(path,sizeof(path),"%s/track-%u-attempt-%u-start.scsnap",dir,race+1,retries+1);CHECK(topgear_recomp_snapshot_save(c,path,error,sizeof(error)));
  QueryPerformanceFrequency(&freq);QueryPerformanceCounter(&start);
  for(n=0;n<60000&&word(0x1eb0)<10;n++){
   CHECK(advance_driver(&driver));CHECK(!c->mod_time_trial_active&&!c->mod_rally_active&&!word(0x1f04));
   if(n%2000==0){printf("PROGRESS track=%u frame=%u P1lap=%d place=%d speed=%u fuel=%u finishers=%u CPUcars=%u/%u/%u CPUlaps=%d/%d/%d CPUfuel=%u/%u/%u stops=%u/%u\n",race+1,n,(int)(int16_t)word(0x1e76),(int)(int16_t)word(0x1f00),word(0x1e5a),word(0x1e62),word(0x1eb0),c->rivals.cars[1],c->rivals.cars[2],c->rivals.cars[3],(int)(int16_t)word(0x1e78),c->rivals.rival[0].lap,c->rivals.rival[1].lap,word(0x1e64),c->rivals.rival[0].fuel,c->rivals.rival[1].fuel,c->rivals.rival[0].pit_stops,c->rivals.rival[1].pit_stops);fflush(stdout);}
  }
  CHECK(n<60000);QueryPerformanceCounter(&end);printf("TIMING track=%u frames=%u headless_fps=%.2f\n",race+1,n,(double)n*freq.QuadPart/(end.QuadPart-start.QuadPart));
  finisher_count=word(0x1eb0);for(id=0;id<finisher_count&&id<20;id++){unsigned finisher=c->wram[0x1f12+id];CHECK(finisher<20&&!crossed[finisher]);crossed[finisher]=1;places[finisher]=id+1;}
  printf("DIAGNOSTICS track=%u shadow_checks=%u shadow_failures=%u overflow=%u\n",race+1,c->rivals.shadow_checks,c->rivals.shadow_failures,c->rivals.overflow);
  snprintf(path,sizeof(path),"%s/track-%u-race-end.scsnap",dir,race+1);CHECK(topgear_recomp_snapshot_save(c,path,error,sizeof(error)));
  CHECK(!c->rivals.overflow);
  CHECK(frames(600,0));
  if(c->mod_continue_screen==2){
   printf("RETRY track=%u P1 did not qualify, remaining=%u\n",race+1,c->mod_continues_remaining);fflush(stdout);
   snprintf(name,sizeof(name),"track-%u-failed-attempt-%u",race+1,retries+1);CHECK(shot(name));
   CHECK(retries<3&&c->mod_continues_remaining&&press(0x0080));retries++;
   for(wait=0;wait<3000&&c->hdma_enable_mask!=0x7f;wait++)CHECK(frames(1,0));CHECK(wait<3000);continue;
  }
  CHECK(!c->mod_continue_screen);
  snprintf(name,sizeof(name),"track-%u-race-results",race+1);CHECK(shot(name));
  CHECK(press(0x0080)&&frames(300,0));snprintf(name,sizeof(name),"track-%u-standings",race+1);CHECK(shot(name));
  {unsigned seen=0;for(rank=0;rank<20;rank++){unsigned driver_id=c->wram[0x1f62+rank];CHECK(driver_id<20&&!(seen&(1u<<driver_id)));seen|=1u<<driver_id;}}
  for(id=0;id<20;id++){
   unsigned place=places[id],standing=20;const char *label=id==0?"P1":tg_rivals_name(id);
   for(rank=0;rank<20;rank++){if(c->wram[0x1f62+rank]==id)standing=rank+1;}
   fprintf(csv,"%u,%u,%u,%.8s,%u,%u,%u,%u\n",race+1,retries+1,id,label,place,crossed[id],c->wram[0x1f4e+id],standing);
   if(id<4)printf("RESULT track=%u driver=%.8s place=%u crossed=%u cumulative_points=%u standing=%u\n",race+1,label,place,crossed[id],c->wram[0x1f4e+id],standing);
  }
  fflush(csv);fflush(stdout);
  snprintf(path,sizeof(path),"%s/track-%u-standings.scsnap",dir,race+1);CHECK(topgear_recomp_snapshot_save(c,path,error,sizeof(error)));
  race++;if(race==4)break;
  CHECK(press(0x0080));for(wait=0;wait<4000&&!(word(0x1f06)==race&&c->hdma_enable_mask==0x7f);wait++)CHECK(frames(1,0));CHECK(wait<4000);
 }
 fclose(csv);topgear_recomp_destroy(c);puts("PASS natural first-four-track Career journey; P1 self-driving; CPU states/fuel/results unmodified");return 0;
}
