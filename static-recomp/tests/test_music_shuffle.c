#include "topgear_internal.h"
#include "topgear_player_settings_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#x);return 1;}}while(0)
int main(int argc,char **argv){
 TopGearRecomp *a=(TopGearRecomp*)calloc(1,sizeof(*a)),*b=(TopGearRecomp*)calloc(1,sizeof(*b));uint8_t record[96],cache[96],copy[96];unsigned previous=255u;
 CHECK(a&&b);if(argc!=2)return 2;
 topgear_recomp_music_state_seed(a,1234567u);a->mod_music_mode=1u;
 for(unsigned mode=0;mode<2;mode++){
  a->mod_time_trial_active=(uint8_t)mode;previous=255u;
  for(unsigned cycle=0;cycle<100;cycle++){
   unsigned mask=0u;
   for(unsigned n=0;n<11;n++){
    unsigned song=tg_mod_music_pick_song(a);CHECK(song<11u&&song!=previous&&!(mask&(1u<<song)));mask|=1u<<song;previous=song;
    CHECK(topgear_recomp_music_state_export(a,record,sizeof(record)));
    if((cycle==0u||cycle==99u)&&n==5u){CHECK(topgear_settings_write_record(argv[1],record,sizeof(record)));CHECK(topgear_music_state_load_file(b,argv[1],cache));}
    else CHECK(topgear_recomp_music_state_import(b,record,sizeof(record)));b->mod_time_trial_active=(uint8_t)mode;b->mod_music_mode=1u;
    CHECK(topgear_recomp_music_state_export(b,copy,sizeof(copy)));CHECK(!memcmp(record,copy,96));
    CHECK(topgear_recomp_music_state_import(b,record,96));
    if(n==5){unsigned expected=tg_mod_music_pick_song(b);CHECK(topgear_recomp_music_state_import(b,record,96));CHECK(tg_mod_music_pick_song(b)==expected);}
   }
   CHECK(mask==2047u);
  }
 }
 a->mod_time_trial_active=0u;a->mod_rally_active=1u;
 for(unsigned rally=0;rally<100;rally++){
  unsigned mask=0;tg_mod_music_rally_playlist(a);
  for(unsigned race=0;race<8;race++){a->mod_rally_race_index=(uint8_t)race;unsigned song=tg_mod_music_pick_song(a);CHECK(song<11u&&!(mask&(1u<<song)));mask|=1u<<song;CHECK(tg_mod_music_pick_song(a)==song);}
 }
 CHECK(topgear_recomp_music_state_export(a,record,96));memcpy(copy,record,96);copy[20]^=1u;CHECK(!topgear_recomp_music_state_import(b,copy,96));CHECK(!topgear_recomp_music_state_import(b,record,95));
 a->mod_rally_active=0u;a->mod_music_mode=0u;a->mod_music_sequence=0u;
 for(unsigned n=0;n<33;n++)CHECK(tg_mod_music_pick_song(a)==n%11u);
 a->mod_music_mode=2u;
 CHECK(topgear_recomp_music_state_export(a,record,96));
 for(unsigned course=0;course<32;course++){
  a->wram[0x1F06]=course;CHECK(tg_mod_music_pick_song(a)==(course&3u));
  CHECK(tg_mod_music_race_prepare(a));CHECK(a->mod_music_engine==0&&a->mod_music_native_selector==5u-(course&3u));
 }
 CHECK(topgear_recomp_music_state_export(a,copy,96)&&!memcmp(record,copy,96));
 a->mod_music_title=2u;a->mod_music_engine=2u;a->mod_menu_remodel_return_pending=1u;a->mod_menu_remodel_return_page=10u;
 tg_mod_music_menu_enter(a);CHECK(a->mod_music_engine==0u);
 a->mod_menu_remodel_active=1u;a->mod_menu_remodel_page=10u;CHECK(tg_mod_music_input(a,0x10u)==0u&&a->mod_music_engine==0u);
 free(a);free(b);puts("PASS: 2,200 Career/TT draws, 100 unique eight-song Rally playlists, durable state reloads, corrupt-file rejection, Complete order, no sequel title on results");return 0;
}
