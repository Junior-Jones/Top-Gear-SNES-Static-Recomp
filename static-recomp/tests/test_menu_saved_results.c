#define TG_MENU_ALL_PAGES_HELPERS_ONLY
#include "test_menu_all_pages.c"
#include "topgear_time_trial_store.h"

int main(int argc,char **argv){
    uint8_t rom[524288],blob[TOPGEAR_TT_STORE_FILE_SIZE];FILE *f;
    TopGearTimeTrialStore *store;TopGearTimeTrialRun completed,last,ranked;
    unsigned n,rank,found=0;char result[1024];
    if(argc!=5)return 2;output=argv[4];
    f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
    f=fopen(argv[3],"rb");if(!f||fread(blob,1,sizeof(blob),f)!=sizeof(blob))return 2;fclose(f);
    reference=(TopGearRecomp*)malloc(sizeof(*reference));store=(TopGearTimeTrialStore*)malloc(sizeof(*store));
    REQUIRE(reference&&store&&topgear_recomp_create(&core,rom,sizeof(rom),error,sizeof(error)));
    topgear_time_trial_store_init(store);
    REQUIRE(topgear_time_trial_store_import(store,blob,sizeof(blob),error,sizeof(error)));
    REQUIRE(topgear_recomp_snapshot_load(core,argv[2],error,sizeof(error)));
    topgear_recomp_time_trial_set_leaderboard_provider(core,topgear_time_trial_store_provider,store);
    REQUIRE(topgear_recomp_time_trial_completed_run(core,&completed));
    REQUIRE(topgear_time_trial_store_last_run(store,&last));
    REQUIRE(completed.course==last.course&&completed.car_id==last.car_id&&completed.total_time_ticks==last.total_time_ticks);
    REQUIRE(!memcmp(completed.lap_time_ticks,last.lap_time_ticks,sizeof(last.lap_time_ticks)));
    REQUIRE(topgear_recomp_time_trial_commit_completed_run(core));
    for(n=0;n<1200&&(!core->mod_menu_remodel_active||core->mod_menu_remodel_page!=10);n++)REQUIRE(frames(1,0,0));
    REQUIRE(n<1200&&frames(90,0,1));capture("natural-results-fixed");
    /* All five real post-race choices are explored; Retry was already used
       to finish the second natural race by the controller journey. */
    snprintf(result,sizeof(result),"%s/natural-results.snap",output);
    REQUIRE(topgear_recomp_snapshot_save(core,result,error,sizeof(error)));
    REQUIRE(directions(5));
    REQUIRE(load_menu_snapshot(result)&&button(0x0080)&&core->mod_menu_remodel_page==11&&frames(90,0,1));
    capture("natural-leaderboard-fixed");
    for(rank=0;rank<5;rank++)if(topgear_recomp_time_trial_query_leaderboard(core,completed.course,-1,rank,&ranked)&&ranked.total_time_ticks==last.total_time_ticks)found=1;
    REQUIRE(found&&directions(2)&&button(0x8000)&&core->mod_menu_remodel_page==10);
    REQUIRE(button(0x0080)&&button(0x0080)&&core->mod_menu_remodel_page==3);
    REQUIRE(load_menu_snapshot(result)&&button(0x0400)&&button(0x0100)&&button(0x0080)&&core->mod_menu_remodel_page==4);
    REQUIRE(button(0x8000)&&core->mod_menu_remodel_page==3);
    REQUIRE(load_menu_snapshot(result)&&button(0x0400)&&button(0x0100)&&button(0x0100)&&button(0x0080)&&core->mod_menu_remodel_page==16);
    REQUIRE(directions(4)&&choose(1)&&button(0x0080)&&core->mod_menu_remodel_page==10);
    REQUIRE(load_menu_snapshot(result)&&button(0x0100)&&button(0x0080)&&core->mod_menu_remodel_page==0);
    REQUIRE(!core->mod_time_trial_active);
    printf("%s natural saved results course=%u: completed race equals physical last run; live leaderboard contains it; all footer routes; checked_frames=%u mismatching_frames=%u\n",bad_frames?"FAIL":"PASS",last.course,checked,bad_frames);
    free(store);free(reference);topgear_recomp_destroy(core);return bad_frames?1:0;
}
