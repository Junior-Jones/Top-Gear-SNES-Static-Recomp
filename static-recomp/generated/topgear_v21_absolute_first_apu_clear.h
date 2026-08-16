#ifndef TOPGEAR_V21_ABSOLUTE_FIRST_APU_CLEAR_H
#define TOPGEAR_V21_ABSOLUTE_FIRST_APU_CLEAR_H
#include <stdint.h>
struct TgV21AbsoluteApuClearState { uint32_t cold_profile,initial_phase,timer_enable_smp_cycle,apu_clear_smp_cycle; uint64_t apu_clear_master_clock; uint16_t hcounter,vcounter; uint8_t field,timer_phase_at_enable,timer_phase_after,timer_stage2_after,timer_output_after; };
struct TgV21AbsoluteApuClearSummary { uint32_t cold_profile_count,timer_phase_class_count,dsp_phase_count,architecture_class_count; uint64_t master_clock_min,master_clock_max; uint32_t smp_cycle_min,smp_cycle_max; uint16_t vcounter; uint8_t field; };
int tg_v21_generated_absolute_apu_clear_state(uint32_t,struct TgV21AbsoluteApuClearState*);
void tg_v21_generated_absolute_apu_clear_summary(struct TgV21AbsoluteApuClearSummary*);
#endif
