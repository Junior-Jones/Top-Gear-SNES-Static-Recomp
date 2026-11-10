#include "topgear_60_timing.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL %u: %s\n",(unsigned)__LINE__,#x);return 1;}}while(0)
int main(void){
 TopGearRecomp *a=calloc(1,sizeof(*a)),*b=calloc(1,sizeof(*b));unsigned positive,negative;
 CHECK(a&&b);CHECK(!topgear_recomp_experimental_60fps_enabled(a)&&!tg60_active(a));
 CHECK(tg60_fuel_step(a,0,100,1)==100&&a->timing60.fuel.calls[0]==0);
 topgear_recomp_set_experimental_60fps_enabled(a,1);CHECK(tg60_active(a)&&topgear_recomp_experimental_60fps_enabled(a));CHECK(!tg60_active(b));
 CHECK(tg60_fuel_step(a,0,100,1)==33&&a->timing60.fuel.remainder[0]==1);
 /* Selecting an accelerated instruction must not change interrupt timing,
    including when another core is advanced before that instruction. */
 a->hdma_enable_mask=0x7f;a->cpu.pbr=1;a->cpu.pc=0x8000;
 CHECK(tg60_graphics_master_budget(a)==2u&&tg60_graphics_master_budget(b)==0u);
 a->v23_event_mode=1;a->v23_event_line_period=1364;a->v23_event_refresh_position=538;
 CHECK(tg_v23_advance_nominal_current_instruction(a,8u));CHECK(a->v23_event_master_clock==64u);
 b->v23_event_mode=1;b->v23_event_line_period=1364;b->v23_event_refresh_position=538;
 CHECK(tg_v23_advance_nominal_current_instruction(b,8u));CHECK(b->v23_event_master_clock==64u);
 a->v23_event_in_interrupt=1;CHECK(tg60_graphics_master_budget(a)==0u);
 a->v23_event_in_interrupt=0;
 a->hdma_enable_mask=0x7f;a->wram[0x1e90]=1;
 topgear_recomp_set_experimental_60fps_enabled(a,0);CHECK(!topgear_recomp_experimental_60fps_enabled(a)&&tg60_active(a));
 a->cpu.pbr=0;a->cpu.pc=0x86c7;a->cpu.p=TG_P_I;
 CHECK(tg_v22_reentry_group_0021_step(a));CHECK(!tg60_active(a)&&a->timing60.fuel.remainder[0]==0);
 CHECK(tg60_refill_step(a,0)==127&&tg60_pit_force(a,2,41)==41&&tg60_pit_scroll(a,2,2)==2);
 tg60_shadow_lane_limits(a,&positive,&negative);CHECK(positive==600&&negative==1280);
 topgear_recomp_set_experimental_60fps_enabled(a,1);CHECK(!tg60_active(a)&&topgear_recomp_experimental_60fps_enabled(a));
 a->cpu.pc=0x86c7;CHECK(tg_v22_reentry_group_0021_step(a));CHECK(tg60_active(a)&&a->cpu.pc==0x86c9);
 tg60_reset(a);CHECK(tg60_active(a)&&topgear_recomp_experimental_60fps_enabled(a));
 a->mod_menu_remodel_active=1;topgear_recomp_set_experimental_60fps_enabled(a,0);CHECK(!tg60_active(a));
 free(a);free(b);puts("PASS experimental mode: default Off, per-instance isolation, original costs Off, safe race-boundary switching and menu switching");return 0;
}
