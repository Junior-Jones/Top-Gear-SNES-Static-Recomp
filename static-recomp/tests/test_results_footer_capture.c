#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "topgear_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* UI fixture only: boot real assets, install an eight-lap completed-run
   fixture, then exercise production menu input/rendering and snapshot state.
   This is not evidence of a naturally completed race. */
static int advance(TopGearRecomp *c,unsigned count,uint16_t buttons){
    unsigned n;TopGearRecompFrameResult result;int16_t samples[4096];
    for(n=0u;n<count;n++){
        if(!topgear_recomp_advance(c,buttons,0u,1u,&result))return 0;
        while(topgear_recomp_audio_read(c,samples,2048u)){}
    }
    return 1;
}
static int picture(TopGearRecomp *c,const char *prefix,unsigned page){
    char path[1024];unsigned n;FILE *f;
    (void)snprintf(path,sizeof(path),"%s-%u.ppm",prefix,page);
    f=fopen(path,"wb");if(!f)return 0;
    fprintf(f,"P6\n256 224\n255\n");
    for(n=0u;n<256u*224u;n++){
        unsigned v=(unsigned)c->mode1_frame[n*2u]|((unsigned)c->mode1_frame[n*2u+1u]<<8u);
        fputc((int)((v&31u)*255u/31u),f);
        fputc((int)(((v>>5u)&31u)*255u/31u),f);
        fputc((int)(((v>>10u)&31u)*255u/31u),f);
    }
    return fclose(f)==0;
}
static int history(void *user,unsigned track,int car,unsigned rank,TopGearTimeTrialRun *out){
    if(track!=31u||car!=-1||rank>=5u||!out)return 0;
    *out=*(TopGearTimeTrialRun*)user;
    out->total_time_ticks+=rank*60u;
    return 1;
}
int main(int argc,char **argv){
    uint8_t *rom;FILE *f;TopGearRecomp *c=NULL;char error[256],snapshot[1024];
    unsigned page,n;int ok=1;
    if(argc!=3)return 2;
    rom=(uint8_t*)malloc(524288u);if(!rom)return 2;
    f=fopen(argv[1],"rb");if(!f){free(rom);return 2;}
    ok=fread(rom,1u,524288u,f)==524288u;fclose(f);
    if(!ok||!topgear_recomp_create(&c,rom,524288u,error,sizeof(error))){free(rom);return 2;}
    free(rom);
    ok=advance(c,1560u,0u)&&advance(c,120u,TOPGEAR_INPUT_START)&&advance(c,300u,0u);
    if(!ok)goto done;
    c->mod_setup_time_trial[0]=0x5Au;c->mod_setup_shared[1][0]=0xA5u;
    (void)snprintf(snapshot,sizeof(snapshot),"%s.snap",argv[2]);
    if(!topgear_recomp_snapshot_save(c,snapshot,error,sizeof(error))){ok=0;goto done;}
    c->mod_setup_time_trial[0]=0u;c->mod_setup_shared[1][0]=0u;
    if(!topgear_recomp_snapshot_load(c,snapshot,error,sizeof(error))||
       c->mod_setup_time_trial[0]!=0x5Au||c->mod_setup_shared[1][0]!=0xA5u){ok=0;goto done;}
    /* Every selectable remodel row, with real selector updates and 90
       neutral frames after each input. Page setup is a UI fixture. */
    for(page=0u;page<=12u;page++){
        unsigned country, countries=(page==5u||page==7u)?8u:1u;
        unsigned count=page==1u?4u:page==2u?3u:page==4u||page==6u?8u:
            page==8u?3u:page==9u||page==11u?1u:page==12u?5u:page==10u?2u:4u;
        if(page==10u||page==11u)continue; /* populated below */
        for(country=0u;country<countries;country++){
            if(!topgear_recomp_snapshot_load(c,snapshot,error,sizeof(error))){ok=0;goto done;}
            c->mod_menu_remodel_return_pending=1u;c->mod_menu_remodel_return_page=(uint8_t)page;
            c->mod_menu_remodel_return_selection=0u;c->mod_time_trial_country=(uint8_t)country;
            (void)tg_mod_menu_remodel_main_menu_enter(c);
            for(n=0u;n<count;n++){
                unsigned selection;
                if(!advance(c,12u,page==8u?TOPGEAR_INPUT_RIGHT:TOPGEAR_INPUT_DOWN)||!advance(c,90u,0u)){ok=0;goto done;}
                selection=c->mod_menu_remodel_selection;
                if(!picture(c,argv[2],1000u+page*100u+country*10u+selection)){ok=0;goto done;}
            }
        }
    }
    /* Natural Rally Start -> generated preview -> neutral timeout -> race. */
    if(!topgear_recomp_snapshot_load(c,snapshot,error,sizeof(error))){ok=0;goto done;}
    if(!advance(c,12u,TOPGEAR_INPUT_DOWN)||!advance(c,90u,0u)||
       !advance(c,12u,TOPGEAR_INPUT_A)||!advance(c,90u,0u)||
       !advance(c,12u,TOPGEAR_INPUT_DOWN)||!advance(c,90u,0u)||
       !advance(c,12u,TOPGEAR_INPUT_DOWN)||!advance(c,90u,0u)||
       !advance(c,12u,TOPGEAR_INPUT_A)||!advance(c,90u,0u)||
       c->mod_menu_remodel_page!=13u||!picture(c,argv[2],13u)){ok=0;goto done;}
    {
        uint8_t schedule[8];memcpy(schedule,c->mod_rally_schedule,8u);
        if(!advance(c,1836u,0u)||c->mod_menu_remodel_active||
           memcmp(schedule,c->mod_rally_schedule,8u)||c->mod_rally_generation_count!=1u||
           c->wram[0x1F06u]!=schedule[0]||!picture(c,argv[2],14u)){ok=0;goto done;}
    }
    /* Empty leaderboard slots are presentation placeholders only. No host
       record is supplied and no zero-time result is inserted. */
    if(!topgear_recomp_snapshot_load(c,snapshot,error,sizeof(error))){ok=0;goto done;}
    c->mod_time_trial_times_course=0u;c->mod_menu_remodel_return_pending=1u;
    c->mod_menu_remodel_return_page=11u;c->mod_menu_remodel_return_selection=0u;
    (void)tg_mod_menu_remodel_main_menu_enter(c);
    if(!advance(c,90u,0u)||!picture(c,argv[2],107u)){ok=0;goto done;}
    for(page=10u;page<=11u;page++){
        TopGearTimeTrialRun *r=&c->mod_time_trial_completed_run;
        if(!topgear_recomp_snapshot_load(c,snapshot,error,sizeof(error))){ok=0;break;}
        memset(r,0,sizeof(*r));memcpy(r->name,"PLAYER 1",8u);
        r->car_id=1u;r->gearbox=1u;r->course=31u;r->required_laps=8u;r->completed_laps=8u;
        r->valid_flags=TOPGEAR_TIME_TRIAL_RUN_VALID|TOPGEAR_TIME_TRIAL_RUN_COMPLETE;
        r->total_time_ticks=4800u;r->best_sector1_ticks=180u;r->best_sector2_ticks=200u;r->best_sector3_ticks=220u;
        for(n=0u;n<8u;n++){
            r->lap_time_ticks[n]=600u;r->lap_sector1_ticks[n]=180u;
            r->lap_sector2_ticks[n]=200u;r->lap_sector3_ticks[n]=220u;
        }
        c->mod_time_trial_completed_run_valid=1u;c->mod_time_trial_completed_run_pending=0u;
        c->mod_time_trial_times_course=31u;c->mod_menu_remodel_return_pending=1u;
        c->mod_time_trial_leaderboard_provider=history;
        c->mod_time_trial_leaderboard_user=r;
        c->mod_menu_remodel_return_page=10u;c->mod_menu_remodel_return_selection=0u;
        (void)tg_mod_menu_remodel_main_menu_enter(c);
        if(page==10u){
            static const uint16_t buttons[4]={TOPGEAR_INPUT_UP,TOPGEAR_INPUT_RIGHT,TOPGEAR_INPUT_RIGHT,TOPGEAR_INPUT_DOWN};
            /* Move away and back so this direct-entry fixture exercises the
               native selector redraw path before capturing LEADERBOARD. */
            if(!advance(c,12u,TOPGEAR_INPUT_RIGHT)||!advance(c,90u,0u)||
               !advance(c,12u,TOPGEAR_INPUT_LEFT)||!advance(c,90u,0u)||
               c->mod_menu_remodel_selection!=0u||!picture(c,argv[2],100u)){ok=0;break;}
            for(n=0u;n<4u;n++)if(!advance(c,12u,buttons[n])||!advance(c,90u,0u)||
                c->mod_menu_remodel_selection!=n+1u||!picture(c,argv[2],101u+n)){ok=0;break;}
            if(!ok)break;
            /* Capture the two destination screens as well: CARS must open
               with the live car selected, and TRACKS with the current country. */
            c->wram[0x1F8Fu]=1u;c->wram[0x1F90u]=0u;
            c->mod_menu_remodel_selection=3u;c->mod_menu_remodel_dirty=1u;
            tg_mod_menu_remodel_draw_if_dirty(c);
            if(!advance(c,12u,TOPGEAR_INPUT_A)||!advance(c,90u,0u)||
               c->mod_menu_remodel_page!=16u||c->mod_menu_remodel_selection!=1u||
               !picture(c,argv[2],105u)||
               !advance(c,12u,TOPGEAR_INPUT_DOWN)||!advance(c,90u,0u)||
               c->mod_menu_remodel_selection!=2u||!picture(c,argv[2],108u)||
               !advance(c,12u,TOPGEAR_INPUT_DOWN)||!advance(c,90u,0u)||
               c->mod_menu_remodel_selection!=3u||!picture(c,argv[2],109u)||
               !advance(c,12u,TOPGEAR_INPUT_DOWN)||!advance(c,90u,0u)||
               c->mod_menu_remodel_selection!=0u||!picture(c,argv[2],110u)||
               !advance(c,12u,TOPGEAR_INPUT_B)||
               !advance(c,90u,0u)){ok=0;break;}
            c->mod_menu_remodel_selection=2u;c->mod_menu_remodel_dirty=1u;
            tg_mod_menu_remodel_draw_if_dirty(c);
            if(!advance(c,12u,TOPGEAR_INPUT_A)||!advance(c,90u,0u)||
               c->mod_menu_remodel_page!=4u||c->mod_menu_remodel_selection!=7u||
               !picture(c,argv[2],106u)){ok=0;break;}
            c->mod_menu_remodel_page=10u;c->mod_menu_remodel_selection=1u;
            c->mod_menu_remodel_dirty=1u;tg_mod_menu_remodel_draw_if_dirty(c);
        }else if(!advance(c,12u,TOPGEAR_INPUT_A)||!advance(c,90u,0u)||
                 c->mod_menu_remodel_selection!=0u||!picture(c,argv[2],page)){ok=0;break;}
        /* Slow-run formatting must remain truthful past 10 minutes and
           99.9-second sectors; keep this separate from natural evidence. */
        r->total_time_ticks=144000u;r->best_sector1_ticks=7200u;
        r->best_sector2_ticks=6000u;r->best_sector3_ticks=4800u;
        for(n=0u;n<8u;n++){
            r->lap_time_ticks[n]=18000u;r->lap_sector1_ticks[n]=7200u;
            r->lap_sector2_ticks[n]=6000u;r->lap_sector3_ticks[n]=4800u;
        }
        c->mod_menu_remodel_dirty=1u;tg_mod_menu_remodel_draw_if_dirty(c);
        if(!advance(c,90u,0u)||!picture(c,argv[2],page+20u)){ok=0;break;}
        if(!advance(c,12u,TOPGEAR_INPUT_A)||!advance(c,240u,0u)||
           (page==10u?(!c->mod_time_trial_active||c->mod_menu_remodel_active||c->wram[0x1F06u]!=31u):
                        (c->mod_time_trial_active||!c->mod_menu_remodel_active||c->mod_menu_remodel_page!=3u))||c->wram[0x1F04u]!=0u){ok=0;break;}
    }
done:
    topgear_recomp_destroy(c);
    if(ok)puts("PASS: zero-time empty leaderboard placeholders, five highlighted RESULTS choices, Top 5 footer, controller-driven retry and setup-bank snapshot round trip (synthetic results fixture)");
    return ok?0:1;
}
