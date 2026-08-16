#ifndef TOPGEAR_V17_SECOND_APU_RENDEZVOUS_H
#define TOPGEAR_V17_SECOND_APU_RENDEZVOUS_H
#include <stdint.h>
struct TgV17SmpFamilySummary { uint32_t target_driver_cycle; uint32_t architectural_class_count; uint32_t exact_boundary_profile_count; uint32_t pending_profile_count; uint32_t unique_aram_hash_count; uint32_t unique_dsp_hash_count; };
struct TgV17SmpPhaseState { uint32_t target_driver_cycle; uint32_t completed_instructions; uint16_t pc,pending_pc; uint8_t a,x,y,sp,psw,pending_total_cycles,pending_elapsed_cycles,timer_phase,timer_stage2,timer_output; uint8_t cpu_to_smp[4],smp_to_cpu[4]; uint64_t aram_hash64,dsp_hash64; uint32_t dsp_write_count; };
int tg_v17_generated_smp_phase_state(uint32_t target_driver_cycle,uint32_t timer_phase,struct TgV17SmpPhaseState*out);
unsigned tg_v17_generated_smp_timer_phase_count(void);
unsigned tg_v17_generated_smp_dsp_phase_count(void);
int tg_v17_generated_smp_family_summary(uint32_t target_driver_cycle,struct TgV17SmpFamilySummary*out);
#endif
