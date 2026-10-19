#define main menu_regression_main
#include "test_menu_flicker.c"
#undef main

#define REQUIRE(x) do{if(!(x)){fprintf(stderr,"FAIL line=%u: %s page=%u selection=%u error=%s\n",__LINE__,#x,core->mod_menu_remodel_page,core->mod_menu_remodel_selection,error);return 1;}}while(0)
static int load_menu_snapshot(const char *path){
    if(!topgear_recomp_snapshot_load(core,path,error,sizeof(error)))return 0;
    previous_page=older_page=desired_page=255u;target_seen=0;
    /* Snapshot restore is not a displayed transition. Establish its complete
       source frame before testing subsequent natural navigation. */
    return frames(3,0,1);
}
static int button(uint16_t b){return frames(6,b,1)&&frames(24,0,1);}
static int choose(unsigned row){unsigned guard=0;while(core->mod_menu_remodel_selection!=row&&guard++<20)if(!button(0x0400))return 0;return core->mod_menu_remodel_selection==row;}
static int directions(unsigned count){unsigned n;for(n=0;n<count;n++)if(!button(0x0400))return 0;for(n=0;n<count;n++)if(!button(0x0800))return 0;return button(0x0100)&&button(0x0200);}
static int no_race(void){return core->mod_menu_remodel_active&&!core->mod_time_trial_active;}

#ifndef TG_MENU_ALL_PAGES_HELPERS_ONLY
int main(int argc,char **argv){
    uint8_t rom[524288];FILE *f;unsigned country,track,n,base,title,combinations=0;
    char root[1024],tt[1024],countries[1024],tracks[1024],results[1024];
    if(argc!=3&&argc!=4)return 2;output=argv[2];
    if(argc==4&&strcmp(argv[3],"--results-only"))return 2;
    f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
    reference=(TopGearRecomp*)malloc(sizeof(*reference));
    REQUIRE(reference&&topgear_recomp_create(&core,rom,sizeof(rom),error,sizeof(error)));
    REQUIRE(frames(1560,0,0)&&frames(120,0x1000,0)&&frames(220,0,0));
    snprintf(root,sizeof(root),"%s/all-pages-root.snap",output);
    snprintf(tt,sizeof(tt),"%s/tt-main.snap",output);
    snprintf(countries,sizeof(countries),"%s/tt-countries.snap",output);
    snprintf(tracks,sizeof(tracks),"%s/tt-tracks.snap",output);
    snprintf(results,sizeof(results),"%s/tt-results-fixture.snap",output);
    REQUIRE(topgear_recomp_snapshot_save(core,root,error,sizeof(error)));
    REQUIRE(choose(2)&&button(0x0080)&&core->mod_menu_remodel_page==3);
    REQUIRE(topgear_recomp_snapshot_save(core,tt,error,sizeof(error)));
    if(argc==4)goto results_fixture;
    REQUIRE(choose(1)&&button(0x0080)&&core->mod_menu_remodel_page==4&&directions(8));
    REQUIRE(topgear_recomp_snapshot_save(core,countries,error,sizeof(error)));
    for(country=0;country<8;country++){
        REQUIRE(load_menu_snapshot(countries));
        REQUIRE(choose(country)&&button(0x0080)&&core->mod_menu_remodel_page==5&&directions(4));
        REQUIRE(topgear_recomp_snapshot_save(core,tracks,error,sizeof(error)));
        for(track=0;track<4;track++){
            REQUIRE(load_menu_snapshot(tracks));
            REQUIRE(choose(track)&&button(0x0080)&&core->mod_menu_remodel_page==3);
            REQUIRE(core->mod_time_trial_selected_course==country*4+track&&no_race());
            combinations++;
        }
    }
    printf("PASS Time Trial track selection: all %u country/track combinations, no race started\n",combinations);fflush(stdout);
    REQUIRE(load_menu_snapshot(tt));
    REQUIRE(choose(2)&&button(0x0080)&&core->mod_menu_remodel_page==6&&directions(8));
    REQUIRE(topgear_recomp_snapshot_save(core,countries,error,sizeof(error)));
    combinations=0;
    for(country=0;country<8;country++){
        REQUIRE(load_menu_snapshot(countries));
        REQUIRE(choose(country)&&button(0x0080)&&core->mod_menu_remodel_page==7&&directions(4));
        REQUIRE(topgear_recomp_snapshot_save(core,tracks,error,sizeof(error)));
        for(track=0;track<4;track++){
            REQUIRE(load_menu_snapshot(tracks));
            REQUIRE(choose(track)&&button(0x0080)&&core->mod_menu_remodel_page==8);
            REQUIRE(core->mod_time_trial_times_course==country*4+track);
            REQUIRE(button(0x0800)&&button(0x0400)&&core->mod_menu_remodel_selection==0);
            REQUIRE(button(0x0100)&&core->mod_menu_remodel_selection==1);
            REQUIRE(button(0x0080)&&core->mod_menu_remodel_page==9);
            base=core->mod_time_trial_leaderboard_car;
            title=core->mod_music_title;
            for(n=0;n<4;n++){REQUIRE(button(0x0010));REQUIRE(core->mod_time_trial_leaderboard_car==((base+n+1)&3));}
            REQUIRE(button(0x0020)&&button(0x0100)&&button(0x0200)&&button(0x0800)&&button(0x0400));
            REQUIRE(core->mod_music_title==title);
            REQUIRE(button(0x0080)&&core->mod_menu_remodel_page==8);
            REQUIRE(button(0x0100)&&core->mod_menu_remodel_selection==2);
            REQUIRE(button(0x0080)&&core->mod_menu_remodel_page==7&&button(0x8000)&&core->mod_menu_remodel_page==6&&no_race());
            combinations++;
        }
    }
    printf("PASS Time Trial leaderboards: all %u tracks, all four car filters, footer and Back/Finish paths\n",combinations);fflush(stdout);
results_fixture:
    /* Post-race menus are explicit display fixtures, not a Time Trial race. */
    REQUIRE(load_menu_snapshot(tt));
    core->mod_menu_remodel_page=10;core->mod_menu_remodel_selection=0;
    core->mod_menu_remodel_reserved=0;core->mod_menu_remodel_dirty=1;
    core->mod_time_trial_times_course=31;
    core->mod_time_trial_completed_run_valid=1;core->mod_time_trial_completed_run_pending=1;
    memset(&core->mod_time_trial_completed_run,0,sizeof(core->mod_time_trial_completed_run));
    core->mod_time_trial_completed_run.required_laps=8;core->mod_time_trial_completed_run.completed_laps=8;
    for(n=0;n<8;n++)core->mod_time_trial_completed_run.lap_time_ticks[n]=180;
    tg_mod_menu_remodel_replace_layout(core);REQUIRE(frames(30,0,0));
    REQUIRE(button(0x0800)&&button(0x0400)&&button(0x0200)&&button(0x0100)&&button(0x0080)&&button(0x8000));
    REQUIRE(core->mod_menu_remodel_page==10&&core->mod_time_trial_completed_run_pending);
    REQUIRE(topgear_recomp_time_trial_commit_completed_run(core));
    REQUIRE(topgear_recomp_snapshot_save(core,results,error,sizeof(error)));
    for(n=0;n<8;n++)REQUIRE(button(n%4==0?0x0400:n%4==1?0x0800:n%4==2?0x0100:0x0200));
    capture("tt-results-navigation");
    REQUIRE(load_menu_snapshot(results));
    REQUIRE(button(0x0080)&&core->mod_menu_remodel_page==11&&directions(2));
    REQUIRE(button(0x8000)&&core->mod_menu_remodel_page==10);
    REQUIRE(button(0x0080)&&core->mod_menu_remodel_page==11&&button(0x0080)&&core->mod_menu_remodel_page==3);
    REQUIRE(load_menu_snapshot(results));
    REQUIRE(button(0x0400)&&button(0x0100)&&core->mod_menu_remodel_selection==2&&button(0x0080)&&core->mod_menu_remodel_page==4);
    REQUIRE(button(0x8000)&&core->mod_menu_remodel_page==3);
    for(track=0;track<4;track++){
        REQUIRE(load_menu_snapshot(results));
        REQUIRE(button(0x0400)&&button(0x0100)&&button(0x0100)&&core->mod_menu_remodel_selection==3&&button(0x0080)&&core->mod_menu_remodel_page==16&&directions(4));
        REQUIRE(choose(track)&&button(0x0080)&&core->mod_menu_remodel_page==10&&core->mod_menu_remodel_selection==3);
        REQUIRE((core->wram[0x1F8F]&3)==track&&no_race());
    }
    REQUIRE(load_menu_snapshot(results));
    REQUIRE(button(0x0100)&&core->mod_menu_remodel_selection==4&&button(0x0080)&&core->mod_menu_remodel_page==0&&no_race());
    printf("PASS post-race display fixtures: results, save guard, leaderboard, tracks, all four cars and Main Menu; Retry not activated\n");fflush(stdout);
    for(n=0;n<17;n++)if(page_checks[n])printf("page=%u frames=%u mismatching_frames=%u\n",n,page_checks[n],page_bad[n]);
    printf("%s extended menus: %u completed frames; mismatching_frames=%u; no Time Trial race started\n",bad_frames?"FAIL":"PASS",checked,bad_frames);
    topgear_recomp_destroy(core);free(reference);return bad_frames?1:0;
}

#endif
