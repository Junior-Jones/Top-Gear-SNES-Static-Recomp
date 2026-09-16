#include "topgear_internal.h"
extern int tg_v22_reentry_group_017A_step(struct TopGearRecomp *);
extern int tg_v22_interrupt_semantic_step(struct TopGearRecomp *);
extern int tg_v22_reentry_group_0021_step(struct TopGearRecomp *);

#include <stdio.h>
#include <string.h>

#define TG_BTN_B     UINT16_C(0x8000)
#define TG_BTN_UP    UINT16_C(0x0800)
#define TG_BTN_DOWN  UINT16_C(0x0400)
#define TG_BTN_LEFT  UINT16_C(0x0200)
#define TG_BTN_RIGHT UINT16_C(0x0100)
#define TG_BTN_A     UINT16_C(0x0080)
#define TG_BTN_L     UINT16_C(0x0020)
#define TG_BTN_R     UINT16_C(0x0010)

static void put16(TopGearRecomp *c,unsigned a,uint16_t v){
    c->wram[a]=(uint8_t)v;
    c->wram[a+1u]=(uint8_t)(v>>8u);
}

static void set_name(TopGearRecomp *c,const char *name){
    unsigned n;
    for(n=0u;n<8u;n++)c->wram[0x1F86u+n]=(uint8_t)(name[n]?name[n]:' ');
}

static void install_three_lap_run(TopGearRecomp *c){
    static const uint32_t lap[3]={60u,60u,60u};
    static const uint32_t s1[3]={10u,15u,20u};
    static const uint32_t s2[3]={20u,10u,25u};
    static const uint32_t s3[3]={30u,35u,15u};
    unsigned n;
    memset(c->mod_time_trial_completed_laps,0,sizeof(c->mod_time_trial_completed_laps));
    memset(c->mod_time_trial_completed_s1,0,sizeof(c->mod_time_trial_completed_s1));
    memset(c->mod_time_trial_completed_s2,0,sizeof(c->mod_time_trial_completed_s2));
    memset(c->mod_time_trial_completed_s3,0,sizeof(c->mod_time_trial_completed_s3));
    for(n=0u;n<3u;n++){
        c->mod_time_trial_completed_laps[n]=lap[n];
        c->mod_time_trial_completed_s1[n]=s1[n];
        c->mod_time_trial_completed_s2[n]=s2[n];
        c->mod_time_trial_completed_s3[n]=s3[n];
    }
    c->mod_time_trial_lap_count=3u;
    c->mod_time_trial_required_laps=3u;
}

typedef struct ProviderFixture {
    TopGearTimeTrialRun runs[2];
    unsigned calls;
    unsigned last_track;
    int last_car;
    unsigned last_rank;
} ProviderFixture;

static int fixture_provider(void *user,unsigned track,int car_filter,unsigned rank,
                            TopGearTimeTrialRun *out){
    ProviderFixture *f=(ProviderFixture*)user;
    f->calls++;
    f->last_track=track;
    f->last_car=car_filter;
    f->last_rank=rank;
    if(!out||track!=5u||car_filter!=-1||rank>=2u)return 0;
    *out=f->runs[rank];
    return 1;
}

int main(void){
    TopGearRecomp c;
    TopGearTimeTrialRun run = {0},queried;
    ProviderFixture provider;
    uint16_t sel;
    int ok=1;
    memset(&c,0,sizeof(c));

    /* Execute the generated pit-exit ROL itself: both input and incoming
       carry must survive. Losing the input leaves a refuelled car at zero
       speed forever. Include all operand/carry combinations. */
    {
        unsigned value, carry;
        for(value=0u;value<65536u;value++)for(carry=0u;carry<2u;carry++){
            uint16_t expected=(uint16_t)((value<<1u)|carry);
            c.cpu.pc=0xBD38u;c.cpu.pbr=0u;c.cpu.e=0u;
            c.cpu.p=(uint8_t)carry;c.cpu.a=(uint16_t)value;
            if(!tg_v22_interrupt_semantic_step(&c)||c.cpu.a!=expected||
               ((c.cpu.p&TG_P_C)!=0u)!=(value>=0x8000u)||
               ((c.cpu.p&TG_P_Z)!=0u)!=(expected==0u)||
               ((c.cpu.p&TG_P_N)!=0u)!=((expected&0x8000u)!=0u)){
                fprintf(stderr,"generated pit ROL failed: %04X carry %u\n",value,carry);
                return 1;
            }
        }
        memset(&c,0,sizeof(c));
    }
    c.cpu.pc=0x8783u;c.cpu.p=TG_P_C;c.mod_time_trial_active=1u;
    c.mod_time_trial_required_laps=3u;c.mod_time_trial_lap_count=1u;
    put16(&c,0x1E62u,100u);
    put16(&c,0x1F00u,0xFFFFu);
    if(!tg_v22_reentry_group_0021_step(&c)||c.cpu.pc!=0x878Au)return 1;
    c.cpu.pc=0x8783u;c.mod_time_trial_lap_count=3u;
    if(!tg_v22_reentry_group_0021_step(&c)||c.cpu.pc!=0x8790u)return 1;
    c.cpu.pc=0x8783u;c.mod_time_trial_active=0u;
    if(!tg_v22_reentry_group_0021_step(&c)||c.cpu.pc!=0x8790u)return 1;
    memset(&c,0,sizeof(c));

    /* Natural first-lap geometry begins close to the finish-line wrap.  It
       must not invent S1/S2 before that wrap and lap capture remains live-run
       state only; there is no core-owned historical leaderboard anymore. */
    c.mod_time_trial_selected_course=0u;
    if(!tg_mod_time_trial_start(&c)){fprintf(stderr,"first-lap start failed\n");ok=0;}
    put16(&c,0x0200u,300u);put16(&c,0x1ED7u,280u);put16(&c,0x1EAEu,10u);
    tg_mod_time_trial_frame(&c);
    if((c.mod_time_trial_sector_mask&3u)!=0u){fprintf(stderr,"grid position fabricated first-lap sectors\n");ok=0;}
    put16(&c,0x1ED7u,10u);put16(&c,0x1EAEu,20u);tg_mod_time_trial_frame(&c);
    put16(&c,0x0202u,290u);put16(&c,0x1EAEu,30u);tg_mod_time_trial_frame(&c);
    if(c.mod_time_trial_sector_mask&3u){fprintf(stderr,"camera movement advanced stationary-player sectors\n");ok=0;}
    put16(&c,0x1ED7u,110u);put16(&c,0x1EAEu,40u);tg_mod_time_trial_frame(&c);
    put16(&c,0x1ED7u,210u);put16(&c,0x1EAEu,60u);tg_mod_time_trial_frame(&c);
    put16(&c,0x1EAEu,80u);tg_mod_time_trial_note_lap(&c,1u);
    if(c.mod_time_trial_completed_laps[0]!=60u||
       c.mod_time_trial_completed_s1[0]!=20u||
       c.mod_time_trial_completed_s2[0]!=20u||
       c.mod_time_trial_completed_s3[0]!=20u){
        fprintf(stderr,"natural first-lap wrap/sector capture failed\n");ok=0;
    }

    /* The lap-count update can happen while the course word is still high.
       Preserve completed values and wait for the new lap's low position. */
    put16(&c,0x1ED7u,290u);tg_mod_time_trial_frame(&c);
    if(c.mod_time_trial_sector_mask&3u){fprintf(stderr,"old high position fabricated new-lap sectors\n");ok=0;}
    put16(&c,0x1ED7u,10u);tg_mod_time_trial_frame(&c);
    put16(&c,0x1ED7u,110u);put16(&c,0x1EAEu,100u);tg_mod_time_trial_frame(&c);
    put16(&c,0x1ED7u,210u);put16(&c,0x1EAEu,120u);tg_mod_time_trial_frame(&c);
    put16(&c,0x1EAEu,140u);tg_mod_time_trial_note_lap(&c,2u);
    if(c.mod_time_trial_completed_laps[1]!=60u||c.mod_time_trial_completed_s1[1]!=20u||
       c.mod_time_trial_completed_s2[1]!=20u||c.mod_time_trial_completed_s3[1]!=20u){
        fprintf(stderr,"new-lap arming lost valid sectors\n");ok=0;
    }

    /* Exercise the real generated finish-line instruction, independent of
       whether the native HUD update runs before results. */
    memset(&c,0,sizeof(c));c.mod_time_trial_active=1u;c.mod_time_trial_required_laps=3u;
    c.mod_time_trial_lap_count=2u;c.mod_time_trial_lap_start_tick=120u;
    c.mod_time_trial_sector1_tick=140u;c.mod_time_trial_sector2_tick=160u;c.mod_time_trial_sector_mask=3u;
    put16(&c,0x1E76u,2u);put16(&c,0x1EAEu,180u);
    c.cpu.pbr=5u;c.cpu.pc=0xE823u;c.cpu.dbr=0u;c.cpu.p=0u;
    if(!tg_v22_reentry_group_017A_step(&c)||c.cpu.pc!=0xE826u||
       c.mod_time_trial_lap_count!=3u||c.mod_time_trial_completed_laps[2]!=60u||
       c.mod_time_trial_completed_s3[2]!=20u){fprintf(stderr,"canonical final-lap hook failed\n");ok=0;}
    tg_mod_time_trial_note_lap(&c,65535u);
    if(c.mod_time_trial_lap_count!=3u){fprintf(stderr,"invalid lap counter accepted\n");ok=0;}

    /* Start installs canonical course, but required-lap authority is captured
       from the game's live $1E56 value after race construction. */
    memset(&c,0,sizeof(c));c.mod_time_trial_selected_course=31u;
    if(!tg_mod_time_trial_start(&c)||!c.mod_time_trial_active||c.wram[0x1F06u]!=31u||c.wram[0x1F08u]!=31u){
        fprintf(stderr,"Time Trial start did not install canonical course\n");ok=0;
    }
    if(c.mod_time_trial_required_laps!=0u){fprintf(stderr,"required laps were guessed before game-owned capture\n");ok=0;}
    put16(&c,0x1E56u,8u);tg_mod_time_trial_frame(&c);
    if(c.mod_time_trial_required_laps!=0u){fprintf(stderr,"stale previous-track laps captured\n");ok=0;}
    tg_mod_time_trial_capture_required_laps(&c,4u);
    if(c.mod_time_trial_required_laps!=4u){fprintf(stderr,"game-owned required laps were not captured\n");ok=0;}
    if(!tg_mod_time_trial_skip_career_points(&c)){fprintf(stderr,"Time Trial must skip Career points\n");ok=0;}

    /* Completed race becomes one core-to-host handoff only.  Best sectors are
       independent minima and deliberately come from different laps here. */
    memset(&c,0,sizeof(c));
    c.mod_time_trial_selected_course=0u;c.mod_time_trial_active=1u;
    install_three_lap_run(&c);set_name(&c,"TODD    ");
    put16(&c,0x1F8Fu,2u); /* RAZOR */
    put16(&c,0x1F7Au,0x0010u);put16(&c,0x1F7Cu,0x0020u); /* MANUAL */
    if(!tg_mod_time_trial_post_results(&c)||
       !topgear_recomp_time_trial_completed_run_pending(&c)||
       !topgear_recomp_time_trial_completed_run(&c,&run)){
        fprintf(stderr,"completed-run handoff was not produced\n");ok=0;
    }else{
        if(memcmp(run.name,"TODD    ",8u)!=0||run.course!=0u||run.car_id!=2u||run.gearbox!=1u||
           run.required_laps!=3u||run.completed_laps!=3u||run.total_time_ticks!=180u||
           run.best_sector1_ticks!=10u||run.best_sector2_ticks!=10u||run.best_sector3_ticks!=15u||
           run.lap_time_ticks[0]!=60u||run.lap_sector1_ticks[0]!=10u||
           run.lap_sector2_ticks[1]!=10u||run.lap_sector3_ticks[2]!=15u||
           run.lap_time_ticks[3]!=0u){
            fprintf(stderr,"completed-run metadata/per-lap/best-sector handoff is wrong\n");ok=0;
        }
    }
    if(c.mod_menu_remodel_return_page!=10u||!c.mod_menu_remodel_return_pending){
        fprintf(stderr,"completed run did not schedule RESULTS page\n");ok=0;
    }

    /* The RESULTS page cannot be dismissed before the host acknowledges that
       Data/time-trial.dat was saved.  After commit, RESULTS -> LEADERBOARD ->
       Time Trial with COUNTRY selected. */
    if(!tg_mod_menu_remodel_main_menu_enter(&c)||c.mod_menu_remodel_page!=10u){
        fprintf(stderr,"post-race RESULTS page did not open\n");ok=0;
    }
    sel=UINT16_C(0xFFFF);
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_A,&sel)!=1||c.mod_menu_remodel_page!=10u){
        fprintf(stderr,"pending Data save did not lock RESULTS page\n");ok=0;
    }
    if(!topgear_recomp_time_trial_commit_completed_run(&c)||topgear_recomp_time_trial_completed_run_pending(&c)){
        fprintf(stderr,"host commit acknowledgement failed\n");ok=0;
    }
    sel=UINT16_C(0xFFFF);
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_A,&sel)!=2||c.mod_menu_remodel_page!=11u){
        fprintf(stderr,"RESULTS -> post-race LEADERBOARD failed\n");ok=0;
    }
    sel=UINT16_C(0xFFFF);
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_A,&sel)!=2||c.mod_menu_remodel_page!=3u||c.mod_menu_remodel_selection!=1u||sel!=1u){
        fprintf(stderr,"post-race LEADERBOARD -> COUNTRY failed\n");ok=0;
    }

    /* The redesigned RESULTS footer uses two centered rows. Verify spatial
       navigation and every destination without relying on renderer copies. */
    c.mod_menu_remodel_active=1u;c.mod_menu_remodel_page=10u;c.mod_menu_remodel_selection=0u;
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_RIGHT,&sel)!=2||c.mod_menu_remodel_selection!=4u||
       tg_mod_menu_remodel_handle_input(&c,TG_BTN_LEFT,&sel)!=2||c.mod_menu_remodel_selection!=0u||
       tg_mod_menu_remodel_handle_input(&c,TG_BTN_UP,&sel)!=2||c.mod_menu_remodel_selection!=1u||
       tg_mod_menu_remodel_handle_input(&c,TG_BTN_RIGHT,&sel)!=2||c.mod_menu_remodel_selection!=2u||
       tg_mod_menu_remodel_handle_input(&c,TG_BTN_RIGHT,&sel)!=2||c.mod_menu_remodel_selection!=3u||
       tg_mod_menu_remodel_handle_input(&c,UINT16_C(0x0400),&sel)!=2||c.mod_menu_remodel_selection!=4u){
        fprintf(stderr,"RESULTS two-row navigation failed\n");ok=0;
    }
    c.mod_menu_remodel_selection=2u;c.mod_time_trial_country=3u;
    c.mod_insert_audio_main_menu_active=1u;c.mod_insert_audio_sfx_state=0u;
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_A,&sel)!=2||c.mod_menu_remodel_page!=4u||c.mod_menu_remodel_selection!=0u||
       c.mod_insert_audio_sfx_state!=7u||c.mod_insert_audio_sfx_command!=8u){
        fprintf(stderr,"RESULTS Tracks action failed\n");ok=0;
    }
    c.mod_insert_audio_sfx_state=0u;
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_DOWN,&sel)!=2||c.mod_menu_remodel_selection!=1u||
       c.mod_insert_audio_sfx_state!=1u){
        fprintf(stderr,"TRACKS country navigation sound failed\n");ok=0;
    }
    c.mod_menu_remodel_page=10u;c.mod_menu_remodel_selection=3u;put16(&c,0x1F8Fu,2u);
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_A,&sel)!=2||c.mod_menu_remodel_page!=16u||c.mod_menu_remodel_selection!=2u||
       tg_mod_menu_remodel_handle_input(&c,TG_BTN_UP,&sel)!=2||c.mod_menu_remodel_selection!=1u||
       tg_mod_menu_remodel_handle_input(&c,TG_BTN_A,&sel)!=2||c.mod_menu_remodel_page!=10u||c.mod_menu_remodel_selection!=3u||c.wram[0x1F8Fu]!=1u){
        fprintf(stderr,"RESULTS Cars/current-highlight/selection action failed\n");ok=0;
    }
    c.mod_menu_remodel_selection=4u;
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_A,&sel)!=2||c.mod_menu_remodel_page!=0u||c.mod_menu_remodel_selection!=2u){
        fprintf(stderr,"RESULTS Main Menu action failed\n");ok=0;
    }

    /* Historical reads are host callbacks.  The core neither stores nor ranks
       the supplied history. */
    memset(&provider,0,sizeof(provider));
    provider.runs[0]=run;provider.runs[0].course=5u;provider.runs[0].car_id=0u;
    provider.runs[1]=run;provider.runs[1].course=5u;provider.runs[1].car_id=3u;
    topgear_recomp_time_trial_set_leaderboard_provider(&c,fixture_provider,&provider);
    memset(&queried,0,sizeof(queried));
    if(!topgear_recomp_time_trial_query_leaderboard(&c,5u,-1,1u,&queried)||
       provider.calls!=1u||provider.last_track!=5u||provider.last_car!=-1||provider.last_rank!=1u||
       queried.car_id!=3u){
        fprintf(stderr,"host leaderboard callback/query contract failed\n");ok=0;
    }
    if(topgear_recomp_time_trial_query_leaderboard(&c,5u,2,0u,&queried)!=0||provider.calls!=2u){
        fprintf(stderr,"core leaderboard query bypassed provider contract\n");ok=0;
    }

    /* LEADERBOARD browser: Overall uses only horizontal Left/Right across
       OVERALL-CAR-BACK; CAR opens a per-car view and L/R cycles the car. */
    c.mod_menu_remodel_active=1u;c.mod_menu_remodel_page=8u;c.mod_menu_remodel_selection=0u;
    sel=0u;
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_UP,&sel)!=1||c.mod_menu_remodel_selection!=0u){
        fprintf(stderr,"Overall incorrectly accepted vertical navigation\n");ok=0;
    }
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_LEFT,&sel)!=2||c.mod_menu_remodel_selection!=2u){
        fprintf(stderr,"Overall Left wrap failed\n");ok=0;
    }
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_RIGHT,&sel)!=2||c.mod_menu_remodel_selection!=0u){
        fprintf(stderr,"Overall Right wrap failed\n");ok=0;
    }
    c.mod_menu_remodel_selection=1u;put16(&c,0x1F8Fu,1u);sel=1u;
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_A,&sel)!=2||c.mod_menu_remodel_page!=9u||c.mod_time_trial_leaderboard_car!=1u){
        fprintf(stderr,"Overall CAR action failed\n");ok=0;
    }
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_R,&sel)!=1||c.mod_time_trial_leaderboard_car!=2u||
       tg_mod_menu_remodel_handle_input(&c,TG_BTN_L,&sel)!=1||c.mod_time_trial_leaderboard_car!=1u){
        fprintf(stderr,"per-car L/R cycling failed\n");ok=0;
    }
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_B,&sel)!=2||c.mod_menu_remodel_page!=8u||c.mod_menu_remodel_selection!=1u){
        fprintf(stderr,"per-car B-back failed\n");ok=0;
    }

    /* Post-race Overall ignores any browser car filter and offers FINISH
       only, with no phantom selection change from Left/Right/L/R. */
    provider.calls=0u;c.mod_menu_remodel_page=11u;c.mod_menu_remodel_selection=0u;
    c.mod_menu_remodel_dirty=1u;c.mod_time_trial_times_course=5u;c.mod_time_trial_leaderboard_car=3u;
    tg_mod_menu_remodel_draw_if_dirty(&c);
    if(provider.calls!=5u||provider.last_track!=5u||provider.last_car!=-1){
        fprintf(stderr,"post-race Overall leaked the browser car filter\n");ok=0;
    }
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_RIGHT,&sel)!=1||
       tg_mod_menu_remodel_handle_input(&c,TG_BTN_R,&sel)!=1||c.mod_menu_remodel_selection!=0u){
        fprintf(stderr,"post-race FINISH accepted browser navigation\n");ok=0;
    }
    if(tg_mod_menu_remodel_handle_input(&c,TG_BTN_B,&sel)!=2||c.mod_menu_remodel_page!=10u||c.mod_menu_remodel_selection!=0u){
        fprintf(stderr,"post-race Leaderboard B-back to RESULTS failed\n");ok=0;
    }
    /* One invalid lap cannot be marked as a complete, saveable run. */
    (void)tg_mod_time_trial_start(&c);install_three_lap_run(&c);
    c.mod_time_trial_completed_s1[2]=0u;
    (void)tg_mod_time_trial_post_results(&c);
    if(c.mod_time_trial_completed_run_valid||c.mod_time_trial_completed_run_pending){
        fprintf(stderr,"invalid partial timing was marked saveable\n");ok=0;
    }
    if(!ok)return 1;
    puts("time trial PASS: game-owned lap count, completed-run handoff, best sectors, save gate, five-choice RESULTS routes, car picker, LEADERBOARD and browser navigation");
    return 0;
}
