/* The original race loop waits for a frame at 86C7, then calls EC0E and
   waits for another frame before doing physics. Once graphics fits inside
   one frame, allow $0C==0 at the first gate: INC A then yields elapsed=1.
   EC0E remains intact and is still the single vblank pacing authority.
   This is limited to the racing loop, not menus, countdowns or pause code. */
#include "topgear_60_timing.h"
int tg_experiment_original_group_0021_step(TopGearRecomp *);
int tg_v22_reentry_group_0021_step(TopGearRecomp *i){
    if(tg_generated_context_key(i)==0x000086c7u)tg60_apply_requested(i);
    if(!tg60_active(i))return tg_experiment_original_group_0021_step(i);

    uint32_t key=tg_generated_context_key(i);
    if(key==0x0000878au||key==0x00008804u)i->timing60.finish_request_pending=0;
    if(key==0x0000870du&&i->hdma_enable_mask==0x7f&&!i->mod_menu_remodel_active){
        if(i->timing60.finish_request_pending){i->cpu.pc=0x870f;i->instruction_count++;return 1;}
        i->timing60.finish_request_pending=1;
    }
    if(tg_generated_context_key(i)==0x000087f1u&&i->hdma_enable_mask==0x7f&&!i->mod_menu_remodel_active&&i->wram[0x1e90])return tg60_countdown_step(i,0x1ee0,0,0x87f4);

    if(tg_generated_context_key(i)==0x000086c7u&&i->hdma_enable_mask==0x7fu&&!i->mod_menu_remodel_active){
        i->cpu.pc=0x86c9u;i->instruction_count++;return 1;
    }
    return tg_experiment_original_group_0021_step(i);
}
