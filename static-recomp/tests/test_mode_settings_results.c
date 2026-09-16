#if defined(_MSC_VER) && !defined(_CRT_SECURE_NO_WARNINGS)
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "topgear_internal.h"
#include "topgear_player_settings_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void put16(TopGearRecomp *c,unsigned a,unsigned v){
    c->wram[a]=(uint8_t)v;c->wram[a+1u]=(uint8_t)(v>>8u);
}
static void setup(TopGearRecomp *c,unsigned p,unsigned seed){
    unsigned a=p?0x1F93u:0x1F76u,n;
    for(n=0u;n<24u;n++)c->wram[a+n]=(uint8_t)(seed+n);
    put16(c,a+25u,seed&3u);
}
static int matches(TopGearRecomp *c,unsigned p,unsigned seed){
    unsigned a=p?0x1F93u:0x1F76u,n;
    for(n=0u;n<24u;n++)if(c->wram[a+n]!=(uint8_t)(seed+n))return 0;
    return c->wram[a+25u]==(seed&3u)&&c->wram[a+26u]==0u;
}
static int press(TopGearRecomp *c,uint16_t b){
    uint16_t s=0u;return tg_mod_menu_remodel_handle_input(c,b,&s);
}
#define CHECK(e) do{if(!(e)){fprintf(stderr,"line %d: %s\n",__LINE__,#e);ok=0;}}while(0)
int main(void){
    TopGearRecomp *c=(TopGearRecomp*)calloc(1u,sizeof(*c));
    unsigned page,n;int ok=1;
    if(!c)return 1;
    c->rom=(uint8_t*)calloc(524288u,1u);
    if(!c->rom){free(c);return 1;}
    setup(c,0u,1u);setup(c,1u,2u);
    c->bg_scroll[1]=16u;c->bg1_vofs=16u;
    CHECK(tg_mod_menu_remodel_main_menu_enter(c));
    CHECK(c->bg_scroll[1]==0u&&c->bg1_vofs==0u);
    CHECK(c->wram[0x1FB0u]==255u);
    /* Independent TT defaults are seeded once. Shared changes stay shared. */
    setup(c,0u,3u);setup(c,1u,4u);
    put16(c,0x1F04u,1u);put16(c,0x1F06u,12u);put16(c,0x1F08u,13u);
    CHECK(press(c,0x0400u)==2&&press(c,0x0400u)==2&&press(c,0x0080u)==2);
    CHECK(c->mod_menu_remodel_page==3u&&c->wram[0x1F04u]==0u);
    CHECK(matches(c,0u,1u));setup(c,0u,5u);
    put16(c,0x1F06u,31u);put16(c,0x1F08u,31u);
    CHECK(press(c,0x8000u)==2);
    CHECK(matches(c,0u,3u)&&matches(c,1u,4u)&&c->wram[0x1F04u]==1u);
    CHECK(c->wram[0x1F06u]==12u&&c->wram[0x1F08u]==13u);
    CHECK(press(c,0x0800u)==2&&press(c,0x0080u)==2); /* Rally */
    CHECK(c->mod_menu_remodel_page==2u&&matches(c,0u,3u));setup(c,1u,6u);
    CHECK(press(c,0x8000u)==2&&press(c,0x0800u)==2&&press(c,0x0080u)==2);
    CHECK(c->mod_menu_remodel_page==1u&&matches(c,1u,6u));
    CHECK(press(c,0x8000u)==2&&press(c,0x0400u)==2&&press(c,0x0400u)==2&&press(c,0x0080u)==2);
    CHECK(matches(c,0u,5u)&&c->wram[0x1F04u]==0u);
    /* Finishing original TT player setup must not restore stale bank data. */
    CHECK(press(c,0x0080u)==0);setup(c,0u,7u);
    CHECK(tg_mod_menu_remodel_main_menu_enter(c)&&matches(c,0u,7u));
    CHECK(press(c,0x8000u)==2&&matches(c,0u,3u)&&matches(c,1u,6u));
    CHECK(press(c,0x0080u)==2&&matches(c,0u,7u));

    for(page=10u;page<=11u;page++){
        c->mod_time_trial_active=0u;
        c->mod_menu_remodel_active=1u;c->mod_menu_remodel_page=(uint8_t)page;
        c->mod_menu_remodel_selection=0u;c->mod_menu_remodel_dirty=1u;
        c->mod_time_trial_times_course=31u;c->mod_time_trial_selected_course=0u;
        c->mod_time_trial_completed_run_valid=1u;c->mod_time_trial_completed_run_pending=1u;
        memset(&c->mod_time_trial_completed_run,0,sizeof(c->mod_time_trial_completed_run));
        c->mod_time_trial_completed_run.required_laps=8u;
        c->mod_time_trial_completed_run.completed_laps=8u;
        for(n=0u;n<8u;n++)c->mod_time_trial_completed_run.lap_time_ticks[n]=180u;
        /* Navigation, A and B cannot discard a pending host save. */
        CHECK(press(c,0x0100u)==1&&press(c,0x0080u)==1&&press(c,0x8000u)==1);
        CHECK(c->mod_menu_remodel_page==page&&c->mod_time_trial_completed_run_pending);
        CHECK(topgear_recomp_time_trial_commit_completed_run(c));
        tg_mod_menu_remodel_draw_if_dirty(c);
        if(page==11u){
            CHECK(tg_mod_menu_remodel_selector_coord(c,0u,0u)==0x1808u);
            CHECK(press(c,0x0100u)==1&&c->mod_menu_remodel_selection==0u);
            CHECK(press(c,0x0080u)==2&&c->mod_menu_remodel_page==3u);
            CHECK(!c->mod_time_trial_active);continue;
        }
        CHECK(tg_mod_menu_remodel_selector_coord(c,0u,0u)==0x1803u);
        CHECK(tg_mod_menu_remodel_selector_coord(c,1u,0u)==0x1503u);
        CHECK(tg_mod_menu_remodel_selector_width(c,0u,0u)==6u);
        CHECK(tg_mod_menu_remodel_selector_width(c,1u,0u)==3u);
        /* Both centered small-font rows are below the eight-lap table. */
        CHECK(c->vram[(21u*32u+5u)*2u]!=0u&&c->vram[(24u*32u+4u)*2u]!=0u);
        CHECK(press(c,0x0800u)==2&&c->mod_menu_remodel_selection==1u);
        CHECK(press(c,0x0080u)==0);
        CHECK(c->mod_time_trial_active&&!c->mod_menu_remodel_active);
        CHECK(c->mod_time_trial_selected_course==31u&&c->wram[0x1F06u]==31u);
        CHECK(c->wram[0x1F04u]==0u&&matches(c,0u,7u));
        CHECK(!c->mod_time_trial_completed_run_pending&&c->mod_time_trial_lap_count==0u);
    }
    {
        uint8_t blob[TOPGEAR_PLAYER_SETTINGS_SIZE],again[TOPGEAR_PLAYER_SETTINGS_SIZE];
        c->mod_menu_remodel_active=1u;c->mod_menu_remodel_page=3u;
        CHECK(topgear_recomp_player_settings_export(c,blob,sizeof(blob)));
        CHECK(!topgear_recomp_player_settings_import(c,blob,sizeof(blob)-1u));
        blob[20]^=1u;CHECK(!topgear_recomp_player_settings_import(c,blob,sizeof(blob)));blob[20]^=1u;
        CHECK(topgear_recomp_player_settings_import(c,blob,sizeof(blob)));
        c->mod_menu_remodel_return_pending=0u;
        memset(c->wram,0,sizeof(c->wram));
        CHECK(tg_mod_menu_remodel_main_menu_enter(c));
        CHECK(matches(c,0u,3u)&&matches(c,1u,6u)&&c->wram[0x1F04u]==1u);
        CHECK(topgear_recomp_player_settings_export(c,again,sizeof(again)));
        CHECK(!memcmp(blob,again,sizeof(blob)));
        {
            uint8_t cache[TOPGEAR_PLAYER_SETTINGS_SIZE]={0},old[TOPGEAR_PLAYER_SETTINGS_SIZE];
            FILE *file;
            (void)remove("mode-settings-test.dat");
            CHECK(topgear_player_settings_load_file(c,"mode-settings-test.dat",cache));
            CHECK(topgear_player_settings_save_file(c,"mode-settings-test.dat",cache));
            CHECK(!memcmp(cache,blob,sizeof(cache)));
            memset(c->wram,0,sizeof(c->wram));
            CHECK(topgear_player_settings_load_file(c,"mode-settings-test.dat",cache));
            CHECK(tg_mod_menu_remodel_main_menu_enter(c)&&matches(c,0u,3u)&&matches(c,1u,6u));
            memset(cache,0,sizeof(cache));memcpy(old,cache,sizeof(old));
            CHECK(!topgear_player_settings_save_file(c,"mode-settings-missing-dir/settings.dat",cache));
            CHECK(!memcmp(cache,old,sizeof(old)));
            file=fopen("mode-settings-bad.dat","wb");CHECK(file!=NULL);
            if(file){blob[0]='X';CHECK(fwrite(blob,1u,sizeof(blob),file)==sizeof(blob));CHECK(fclose(file)==0);blob[0]='T';}
            CHECK(!topgear_player_settings_load_file(c,"mode-settings-bad.dat",cache));
            CHECK(matches(c,0u,3u)&&matches(c,1u,6u));
            CHECK(topgear_player_settings_load_file(c,"mode-settings-test.dat",cache));
            (void)remove("mode-settings-test.dat");(void)remove("mode-settings-bad.dat");
        }
    }
    {
        uint8_t legacy[TOPGEAR_PLAYER_SETTINGS_SIZE];uint32_t hash=2166136261u;
        c->mod_setup_import_pending=0u;c->mod_menu_remodel_active=1u;
        CHECK(topgear_recomp_player_settings_export(c,legacy,sizeof(legacy)));
        legacy[4]=1u;legacy[95]=0u;
        for(n=16u;n<sizeof(legacy);n++)hash=(hash^legacy[n])*16777619u;
        for(n=0u;n<4u;n++)legacy[12u+n]=(uint8_t)(hash>>(8u*n));
        CHECK(topgear_recomp_player_settings_import(c,legacy,sizeof(legacy)));
        put16(c,0x1FB0u,0u);CHECK(tg_mod_menu_remodel_main_menu_enter(c));
        CHECK(c->wram[0x1FB0u]==255u);
        CHECK(topgear_recomp_player_settings_export(c,legacy,sizeof(legacy)));
        CHECK(legacy[4]==5u&&legacy[95]==1u);
        legacy[4]=2u;CHECK(topgear_recomp_player_settings_import(c,legacy,sizeof(legacy)));
        CHECK(!c->mod_audio_mute);
        c->mod_setup_import_pending=0u;c->mod_audio_mute=1u;
        CHECK(topgear_recomp_player_settings_export(c,legacy,sizeof(legacy)));
        CHECK(legacy[4]==5u&&legacy[95]==3u);
        c->mod_audio_mute=0u;CHECK(topgear_recomp_player_settings_import(c,legacy,sizeof(legacy)));
        CHECK(c->mod_audio_mute);
        c->mod_setup_import_pending=0u;c->mod_music_mode=1u;
        CHECK(topgear_recomp_player_settings_export(c,legacy,sizeof(legacy)));
        CHECK(legacy[4]==5u&&legacy[95]==7u);
        c->mod_music_mode=0u;
        CHECK(topgear_recomp_player_settings_import(c,legacy,sizeof(legacy)));
        CHECK(c->mod_music_mode==1u);
        legacy[4]=4u;CHECK(topgear_recomp_player_settings_import(c,legacy,sizeof(legacy))&&c->mod_music_mode==1u);
        c->mod_setup_import_pending=0u;c->mod_music_mode=2u;
        CHECK(topgear_recomp_player_settings_export(c,legacy,sizeof(legacy))&&legacy[95]==11u);
        c->mod_music_mode=0;CHECK(topgear_recomp_player_settings_import(c,legacy,sizeof(legacy))&&c->mod_music_mode==2u);
        legacy[95]=15;hash=2166136261u;
        for(n=16;n<sizeof(legacy);n++)hash=(hash^legacy[n])*16777619u;
        for(n=0;n<4;n++)legacy[12+n]=(uint8_t)(hash>>(8*n));
        CHECK(!topgear_recomp_player_settings_import(c,legacy,sizeof(legacy)));
        c->mod_music_mode=0u;c->mod_audio_mute=0u;
    }
    /* Settings must never activate the one-player TT bank. */
    c->mod_setup_import_pending=0u;
    c->mod_menu_remodel_active=1u;c->mod_menu_remodel_page=0u;
    c->mod_menu_remodel_selection=3u;
    CHECK(press(c,0x0080u)==2&&c->mod_menu_remodel_page==12u);
    put16(c,0x1FB0u,0xFFFFu);
    /* A and directions must take the native wait-for-release path. */
    CHECK(press(c,0x0080u)==2&&c->wram[0x1FB0u]==0u);
    CHECK(press(c,0x0100u)==2&&c->wram[0x1FB0u]==255u);
    CHECK(press(c,0x8000u)==2&&c->mod_menu_remodel_selection==3u);
    c->mod_menu_remodel_page=2u;c->mod_menu_remodel_selection=2u;
    CHECK(press(c,0x0080u)==2&&c->mod_menu_remodel_page==13u);
    CHECK(c->mod_rally_generation_count==1u&&c->mod_menu_remodel_active);
    CHECK(tg_mod_menu_remodel_selector_coord(c,0u,0u)==0x1F03u);
    for(n=0u;n<8u;n++)CHECK(c->mod_rally_schedule[n]/4u==n);
    for(n=0u;n<1535u;n++)CHECK(press(c,0u)==1);
    /* Input polls alone do not advance the five-second frame deadline. */
    c->mod_rally_preview_deadline=(uint32_t)topgear_recomp_v27_frame_count(c);
    CHECK(press(c,0u)==3&&!c->mod_menu_remodel_active);
    CHECK(c->wram[0x5Au]==4u&&c->wram[0x1F06u]==c->mod_rally_schedule[0]);
    CHECK(c->mod_rally_generation_count==1u);
    {
        unsigned seen=0u;
        c->mod_time_trial_active=0u;c->mod_rally_active=0u;c->mod_music_mode=1u;
        c->mod_music_sequence=7u;
        for(n=0;n<11u;n++){
            unsigned song=tg_mod_music_pick_song(c);
            CHECK(song<11u&&!(seen&(1u<<song)));seen|=1u<<song;
        }
        CHECK(seen==2047u&&c->mod_music_sequence==7u);
    }
    free(c->rom);free(c);
    if(ok)puts("PASS: separate TT setup, shared Career/Rally P1/P2/count/course, setup returns, five-choice results menu, Overall FINISH, save gate and settings serialization");
    return ok?0:1;
}
