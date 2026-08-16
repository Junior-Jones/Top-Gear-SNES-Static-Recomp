/* Generated from exact ROM-derived receipts and documented SPC700/S-SMP rules. */
#include "topgear_static_recomp.h"
#include "topgear_v13_second_bbaa_producer.h"
#include <string.h>

void tg_v13_fill_second_bbaa_producer_info(struct TopGearV13SecondBbaaProducerInfo *x){
    if(!x)return;
    memset(x,0,sizeof(*x));
    x->cold_boot_profile_count=128u;
    x->timer_phase_profile_count=128u;
    x->dsp_phase_profile_count=32u;
    x->static_producer_profile_count=128u;
    x->combined_driver_profile_count=4096u;
    x->conservative_cross_product_count=524288u;
    x->scpu_command_master_min=19526324ull;
    x->scpu_command_master_max=19526532ull;
    x->scpu_command_driver_cycle_min=112486ull;
    x->scpu_command_driver_cycle_max=112488ull;
    x->invariant_join_driver_cycle=112535ull;
    x->post_command_instruction_min=944ull;
    x->post_command_instruction_max=976ull;
    x->post_command_cycle_min=3281ull;
    x->post_command_cycle_max=3409ull;
    x->publication_cycle_min=115811ull;
    x->publication_cycle_max=115939ull;
    x->command_value=0x18u;x->published_port_word=0xBBAAu;x->endpoint_pc=0xFFCFu;
    x->command_latch_state_equivalence_proved=1u;
    x->all_timer_profiles_published_second_bbaa=1u;
    x->ipl_rom_reentry_proved=1u;x->indirect_command_dispatch_proved=1u;x->dsp_flag_write_proved=1u;
    x->hybrid_used_for_discovery_only=1u;x->hybrid_trace_used_as_authority=0u;
    x->emulator_oracle_used_as_authority=0u;x->exact_physical_phase_selected=0u;x->exact_physical_rate_selected=0u;
    memcpy(x->endpoint_aram_sha256,"53bfbdbee8fd80866f2e979d3e4be8428e2c8d81b8fb7ae1b88a218dd144fc6b",65u);
    memcpy(x->dsp_registers_sha256,"4940ad07a0bdd6592cf7f885db883913ad07e0d1d790f7302b91240a493d8b56",65u);
    memcpy(x->claim_boundary,"This proves the ROM-derived S-SMP producer of the second $BBAA after the real S-CPU command $18 for every retained timer phase and all conservatively retained DSP phases. It does not use the hybrid endpoint as authority, select a physical oscillator phase/rate, or yet prove the complete parallel route beyond the S-CPU wait-loop release.",sizeof("This proves the ROM-derived S-SMP producer of the second $BBAA after the real S-CPU command $18 for every retained timer phase and all conservatively retained DSP phases. It does not use the hybrid endpoint as authority, select a physical oscillator phase/rate, or yet prove the complete parallel route beyond the S-CPU wait-loop release."));
}
