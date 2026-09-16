#include "topgear_internal.h"
#include "../../frontend/windows/topgear_app_core.c"
#define main old_audio_main
#include "test_menu_insert_audio.c"
#undef main
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d %s\n",__LINE__,#x);return 1;}}while(0)
int main(int argc,char **argv){
 TopGearApp *app=0;TopGearRecomp *expected=(TopGearRecomp*)calloc(1,sizeof(*expected));uint8_t *rom=0,record[96],reloaded[96];size_t bytes;char error[256];unsigned next,last=255;
 if(argc!=3)return 2;CHECK(load_file(argv[1],&rom,&bytes));CHECK(topgear_app_create(&app,rom,bytes,error,sizeof(error)));
 CHECK(topgear_app_player_settings_load(app,argv[2]));app->core->mod_music_mode=1u;
 for(unsigned n=0;n<19;n++){unsigned song=tg_mod_music_pick_song(app->core);CHECK(song!=last);last=song;CHECK(topgear_app_player_settings_save(app,argv[2]));}
 CHECK(topgear_recomp_music_state_export(app->core,record,96));CHECK(topgear_recomp_music_state_import(expected,record,96));expected->mod_music_mode=1u;next=tg_mod_music_pick_song(expected);
 topgear_app_destroy(app);app=0;
 CHECK(topgear_app_create(&app,rom,bytes,error,sizeof(error)));CHECK(topgear_app_player_settings_load(app,argv[2]));
 CHECK(topgear_recomp_music_state_export(app->core,reloaded,96));CHECK(!memcmp(record,reloaded,96));app->core->mod_music_mode=1u;CHECK(tg_mod_music_pick_song(app->core)==next&&next!=last);
 CHECK(topgear_recomp_music_state_export(app->core,record,96));CHECK(topgear_app_reset(app,error,sizeof(error)));CHECK(topgear_recomp_music_state_export(app->core,reloaded,96));CHECK(!memcmp(record,reloaded,96));
 CHECK(topgear_app_player_settings_save(app,argv[2]));topgear_app_destroy(app);free(expected);free(rom);puts("PASS: music-state.dat async write during non-menu state, close during save, restart resumes remaining playlist, Reset preserves history");return 0;
}
