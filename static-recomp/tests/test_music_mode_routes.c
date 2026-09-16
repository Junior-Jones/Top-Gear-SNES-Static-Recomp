#define main old_audio_main
#include "test_menu_insert_audio.c"
#undef main
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d %s: %s\n",__LINE__,#x,topgear_recomp_last_error(c));return 1;}}while(0)
static int frames(TopGearRecomp*c,uint16_t input,unsigned count){TopGearRecompFrameResult result;int16_t pcm[4096];for(unsigned n=0;n<count;n++){if(!topgear_recomp_advance_headless(c,input,0,1,&result))return 0;while(topgear_recomp_audio_read(c,pcm,2048)){} }return 1;}
static int press(TopGearRecomp*c,uint16_t input){return frames(c,input,15)&&frames(c,0,45);}
static int wait_draw(TopGearRecomp*c,unsigned mode,unsigned count){for(unsigned f=0;f<5000;f++){if(!frames(c,0,1))return 0;if(c->mod_music_race&&c->mod_music_positions[mode]==count)return 1;}return 0;}
static int mapped(TopGearRecomp*c){unsigned song=c->mod_music_selected_song;return song<11u&&c->mod_music_engine==(song<4u?0u:song<7u?1u:2u)&& (song>=4u||c->mod_music_native_selector==5u-song);}
int main(int argc,char**argv){
 TopGearRecomp*c=0;uint8_t *rom=0,record[96];size_t size;char error[256],snapshot[1024];unsigned first,second;
 if(argc!=3)return 2;CHECK(load_file(argv[1],&rom,&size));CHECK(topgear_recomp_create(&c,rom,size,error,sizeof(error)));
 CHECK(frames(c,0,1560)&&frames(c,TOPGEAR_INPUT_START,120)&&frames(c,0,220));
 snprintf(snapshot,sizeof(snapshot),"%s/root.snap",argv[2]);CHECK(topgear_recomp_snapshot_save(c,snapshot,error,sizeof(error)));
 for(unsigned mode=0;mode<3;mode++){
  CHECK(topgear_recomp_snapshot_load(c,snapshot,error,sizeof(error)));c->mod_music_mode=1u;
  for(unsigned n=0;n<mode;n++)CHECK(press(c,TOPGEAR_INPUT_DOWN));CHECK(press(c,TOPGEAR_INPUT_A));
  for(unsigned n=0;n<(mode==1u?2u:3u);n++)CHECK(press(c,TOPGEAR_INPUT_DOWN));CHECK(press(c,TOPGEAR_INPUT_A));
  CHECK(wait_draw(c,mode,1u)&&mapped(c));CHECK(c->mod_music_positions[mode]==1u);
  if(mode==1u){unsigned mask=0;for(unsigned n=0;n<8;n++){unsigned song=c->mod_music_bags[1][n];CHECK(!(mask&(1u<<song)));mask|=1u<<song;}}
  printf("PASS %s Start selects gameplay song %u engine %u\n",mode==0?"Career":mode==1?"Rally":"Time Trial",c->mod_music_selected_song,c->mod_music_engine);
 }
 first=c->mod_music_selected_song;CHECK(topgear_recomp_music_state_export(c,record,96));
 /* Synthetic completed-results fixture, preserving the real first run's music history. */
 CHECK(topgear_recomp_snapshot_load(c,snapshot,error,sizeof(error)));CHECK(topgear_recomp_music_state_import(c,record,96));
 c->mod_menu_remodel_return_pending=1u;c->mod_menu_remodel_return_page=10u;c->mod_menu_remodel_return_selection=1u;c->mod_time_trial_times_course=0u;
 CHECK(tg_mod_insert_audio_main_menu_enter(c));CHECK(tg_mod_menu_remodel_main_menu_enter(c));CHECK(frames(c,0,60));CHECK(press(c,TOPGEAR_INPUT_A));CHECK(wait_draw(c,2u,2u)&&mapped(c));
 second=c->mod_music_selected_song;CHECK(second!=first&&c->mod_music_positions[2]==2u);CHECK(topgear_recomp_music_state_export(c,record,96));
 CHECK(topgear_recomp_snapshot_load(c,snapshot,error,sizeof(error)));CHECK(topgear_recomp_music_state_import(c,record,96));
 c->mod_menu_remodel_return_pending=1u;c->mod_menu_remodel_return_page=3u;c->mod_menu_remodel_return_selection=3u;c->mod_time_trial_selected_course=1u;
 CHECK(tg_mod_menu_remodel_main_menu_enter(c));CHECK(frames(c,0,60));CHECK(press(c,TOPGEAR_INPUT_A));CHECK(wait_draw(c,2u,3u)&&mapped(c));
 CHECK(c->mod_music_positions[2]==3u&&c->mod_music_selected_song!=first&&c->mod_music_selected_song!=second&&c->wram[0x1F06]==1u);
 puts("PASS Time Trial results Retry and new-course Start draw fresh gameplay songs from the remaining bag (synthetic results fixture)");
 topgear_recomp_destroy(c);free(rom);return 0;
}
