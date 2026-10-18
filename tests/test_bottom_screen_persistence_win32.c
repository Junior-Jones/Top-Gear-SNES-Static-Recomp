#include "topgear_app_core.h"
#include "topgear_frontend_settings_win32.h"
#include <stdio.h>
#include <string.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d: %s (%s)\n",__LINE__,#x,error);return 1;}}while(0)
static void discard(TopGearApp *a,void *u){(void)u;(void)topgear_app_audio_discard(a);}
int main(int argc,char **argv){
    TopGearApp *app=NULL;TopGearAppFrameResult frame;TopGearFrontendSettingsWin32 cfg,loaded;
    uint8_t rom[524288],record[96];char error[256]={0},path[2048],snap[2048];wchar_t ini[2048];FILE *f;
    if(argc!=3)return 2;
    snprintf(path,sizeof(path),"%s/player-settings.dat",argv[2]);snprintf(snap,sizeof(snap),"%s/old-on.snap",argv[2]);
    swprintf(ini,2048,L"%hs/settings.ini",argv[2]);
    f=fopen(argv[1],"rb");CHECK(f&&fread(rom,1,sizeof(rom),f)==sizeof(rom));fclose(f);
    CHECK(topgear_app_create(&app,rom,sizeof(rom),error,sizeof(error)));
    CHECK(topgear_app_advance_streamed(app,0,1560,discard,NULL,&frame));
    CHECK(topgear_app_advance_streamed(app,0x1000,120,discard,NULL,&frame));
    CHECK(topgear_app_advance_streamed(app,0,220,discard,NULL,&frame));
    topgear_app_set_bottom_screen_enabled(app,1);
    CHECK(topgear_app_snapshot_save(app,snap,error,sizeof(error)));
    topgear_app_set_bottom_screen_enabled(app,0);
    topgear_app_set_extra_cpu_drivers_enabled(app,0);
    CHECK(topgear_app_player_settings_save(app,path));
    CHECK(topgear_app_snapshot_load(app,snap,error,sizeof(error)));
    CHECK(!topgear_app_bottom_screen_enabled(app));
    CHECK(topgear_app_reset(app,error,sizeof(error))&&!topgear_app_bottom_screen_enabled(app));
    CHECK(!topgear_app_extra_cpu_drivers_enabled(app));
    /* Still outside the menu: persist an edit despite the normal export gate. */
    topgear_app_set_bottom_screen_enabled(app,1);CHECK(topgear_app_player_settings_save(app,path));
    topgear_app_set_bottom_screen_enabled(app,0);CHECK(topgear_app_player_settings_save(app,path));
    topgear_app_destroy(app);app=NULL;
    f=fopen(path,"rb");CHECK(f&&fread(record,1,96,f)==96);fclose(f);CHECK(record[4]==8&&(record[95]&16));
    CHECK(topgear_app_create(&app,rom,sizeof(rom),error,sizeof(error)));
    CHECK(topgear_app_player_settings_load(app,path)&&!topgear_app_bottom_screen_enabled(app));
    CHECK(!topgear_app_extra_cpu_drivers_enabled(app));
    topgear_app_destroy(app);app=NULL;
    topgear_frontend_settings_win32_defaults(&cfg);CHECK(cfg.bottom_screen_enabled&&!cfg.bottom_screen_saved);
    cfg.bottom_screen_enabled=0;cfg.bottom_screen_saved=1;
    CHECK(topgear_frontend_settings_win32_save(&cfg,ini));
    topgear_frontend_settings_win32_load(&loaded,ini);CHECK(!loaded.bottom_screen_enabled&&loaded.bottom_screen_saved);
    cfg.bottom_screen_enabled=1;CHECK(topgear_frontend_settings_win32_save(&cfg,ini));
    topgear_frontend_settings_win32_load(&loaded,ini);CHECK(loaded.bottom_screen_enabled&&loaded.bottom_screen_saved);
    CHECK(topgear_app_create(&app,rom,sizeof(rom),error,sizeof(error)));
    CHECK(!topgear_app_center_screen_enabled(app));
    CHECK(topgear_app_snapshot_save(app,snap,error,sizeof(error)));
    topgear_app_set_bottom_screen_enabled(app,0);
    topgear_app_set_center_screen_enabled(app,1);
    CHECK(topgear_app_center_screen_enabled(app));
    CHECK(topgear_app_snapshot_load(app,snap,error,sizeof(error))&&topgear_app_center_screen_enabled(app));
    CHECK(topgear_app_reset(app,error,sizeof(error))&&topgear_app_center_screen_enabled(app));
    CHECK(topgear_app_player_settings_save(app,path));topgear_app_destroy(app);app=NULL;
    CHECK(topgear_app_create(&app,rom,sizeof(rom),error,sizeof(error)));
    CHECK(topgear_app_player_settings_load(app,path)&&topgear_app_center_screen_enabled(app));
    topgear_app_set_bottom_screen_enabled(app,1);CHECK(!topgear_app_center_screen_enabled(app));
    topgear_app_set_center_screen_enabled(app,1);CHECK(!topgear_app_center_screen_enabled(app));
    topgear_app_destroy(app);app=NULL;
    puts("PASS Center Screen: default Off, snapshot/reset/exit/cold restart persistence and Bottom Screen dependency");
    puts("PASS Bottom Screen: old On snapshot cannot overwrite Off; reset, outside-menu/exit save, cold restart, and INI Off/On round-trip");return 0;
}
