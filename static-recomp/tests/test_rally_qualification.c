#include "topgear_internal.h"

#include <stdio.h>
#include <string.h>

extern int tg_v22_group_03E1(TopGearRecomp *core);
extern int tg_v22_group_03E4(TopGearRecomp *core);
extern int tg_v22_reentry_group_03E1_step(TopGearRecomp *core);
extern int tg_v22_reentry_group_03E4_step(TopGearRecomp *core);

static void init_core(TopGearRecomp *core, unsigned race_index, int two_players) {
    unsigned n;
    memset(core, 0, sizeof(*core));
    core->mod_rally_active = 1u;
    core->mod_rally_schedule_valid = 1u;
    core->mod_rally_race_index = (uint8_t)race_index;
    core->mod_rally_qualification_pending = 1u;
    core->wram[0x1F04u] = two_players ? 1u : 0u;
    core->wram[0x1F05u] = 0u;
    for (n = 0u; n < 20u; ++n)
        core->wram[0x1F12u + n] = (uint8_t)(2u + (n % 18u));
}

static void put_racer(TopGearRecomp *core, unsigned place_one_based, uint8_t racer_id) {
    if (place_one_based >= 1u && place_one_based <= 20u)
        core->wram[0x1F12u + place_one_based - 1u] = racer_id;
}

int main(void) {
    TopGearRecomp core;
    unsigned race;
    int ok = 1;

    for (race = 0u; race < 7u; ++race) {
        unsigned cutoff = 8u - race;

        init_core(&core, race, 0);
        put_racer(&core, cutoff, 0u);
        if (!tg_mod_rally_qualification_passes(&core)) {
            fprintf(stderr, "race %u one-player exact cutoff %u should pass\n", race + 1u, cutoff);
            ok = 0;
        }

        init_core(&core, race, 0);
        put_racer(&core, cutoff + 1u, 0u);
        put_racer(&core, 1u, 1u); /* CPU COMPUTER must not count in one-player. */
        if (tg_mod_rally_qualification_passes(&core)) {
            fprintf(stderr, "race %u one-player place %u should fail even with CPU ID1 first\n",
                    race + 1u, cutoff + 1u);
            ok = 0;
        }

        init_core(&core, race, 1);
        put_racer(&core, cutoff > 1u ? cutoff - 1u : 1u, 0u);
        put_racer(&core, cutoff, 1u);
        if (!tg_mod_rally_qualification_passes(&core)) {
            fprintf(stderr, "race %u two-player both inside cutoff %u should pass\n",
                    race + 1u, cutoff);
            ok = 0;
        }

        init_core(&core, race, 1);
        put_racer(&core, 1u, 0u);
        put_racer(&core, cutoff + 1u, 1u);
        if (tg_mod_rally_qualification_passes(&core)) {
            fprintf(stderr, "race %u two-player P2 outside cutoff should fail\n", race + 1u);
            ok = 0;
        }

        init_core(&core, race, 1);
        put_racer(&core, cutoff + 1u, 0u);
        put_racer(&core, 1u, 1u);
        if (tg_mod_rally_qualification_passes(&core)) {
            fprintf(stderr, "race %u two-player P1 outside cutoff should fail\n", race + 1u);
            ok = 0;
        }
    }


    for(race=0;race<20;race++){init_core(&core,7,0);put_racer(&core,race+1,0);if(!tg_mod_rally_qualification_passes(&core))ok=0;init_core(&core,7,1);put_racer(&core,20,0);put_racer(&core,race+1,1);if(!tg_mod_rally_qualification_passes(&core))ok=0;}
    init_core(&core, 0u, 0);
    core.mod_rally_qualification_pending = 0u;
    memset(&core.wram[0x1F12u], 0xFF, 20u);
    if (!tg_mod_rally_qualification_passes(&core)) {
        fprintf(stderr, "initial Rally launch must bypass qualification before points are awarded\n");
        ok = 0;
    }

    init_core(&core, 1u, 1);
    core.mod_menu_remodel_active = 1u;
    tg_mod_rally_qualification_failed(&core);
    if (core.mod_rally_active != 1u || core.mod_rally_schedule_valid != 1u ||
        core.mod_continue_screen != 5u || !core.mod_continue_rally) {
        fprintf(stderr, "qualification-failure state transition is incorrect\n");
        ok = 0;
    }
    /* Terminal Rally failure, never a continue selector. */
    if(tg_mod_continue_complete(&core)!=0x918B || core.mod_rally_active ||
       !core.mod_menu_remodel_return_pending || core.mod_menu_remodel_return_selection!=1)ok=0;

    /* Rally failure schedules root/Rally return before the original failure
       screen is rendered.  That marker must suppress the unrelated Career
       password without affecting normal Career failure screens. */
    memset(&core, 0, sizeof(core));
    core.mod_menu_remodel_return_pending = 1u;
    core.mod_menu_remodel_return_page = 0u;
    core.mod_menu_remodel_return_selection = 1u;
    if (!tg_mod_rally_hide_failure_password(&core)) {
        fprintf(stderr, "Rally failure should suppress Career password renderer\n");
        ok = 0;
    }
    core.mod_menu_remodel_return_selection = 0u;
    if (tg_mod_rally_hide_failure_password(&core)) {
        fprintf(stderr, "non-Rally root return must not suppress Career password renderer\n");
        ok = 0;
    }

    /* Both compiled dispatch paths enter Options without pushing a return.
       A later Start must resume pre-race without consuming the native stack. */
    for (race=0u;race<2u;++race) {
        int (*entry)(TopGearRecomp *)=race?tg_v22_reentry_group_03E1_step:tg_v22_group_03E1;
        int (*leave)(TopGearRecomp *)=race?tg_v22_reentry_group_03E4_step:tg_v22_group_03E4;
        init_core(&core,7u,0);
        core.cpu.pbr=0x0Fu;core.cpu.pc=0x84ACu;core.cpu.s=0x1FF0u;
        if(!entry(&core)||core.cpu.pc!=0x918Bu||!core.mod_menu_post_race_context||core.cpu.s!=0x1FF0u){
            fprintf(stderr,"Rally final-results menu handoff failed, dispatch %u\n",race);ok=0;
        }
        core.cpu.pc=0x9294u;
        if(!leave(&core)||core.cpu.pc!=0x818Eu||core.mod_menu_post_race_context||core.cpu.s!=0x1FF0u){
            fprintf(stderr,"Rally restart consumed an absent return address, dispatch %u\n",race);ok=0;
        }
    }

    if (!ok) return 1;
    printf("rally qualification PASS: cutoffs 8,7,6,5,4,3,2; race 8 ungated; every active human required; one-player CPU ID1 ignored\n");
    return 0;
}
