#ifndef TOPGEAR_V21_POST08DB_APU_READ_H
#define TOPGEAR_V21_POST08DB_APU_READ_H
#include <stdint.h>
struct TgV21SmpPost08dbState { uint32_t source_target_driver_cycle,initial_timer_phase,next_apu_read_cycle,instruction_count,cycle_count,instructions_after_08de; uint16_t next_apu_read_pc,next_apu_read_address,pc_after_read_instruction; uint8_t next_apu_read_value,read_cycle_offset,a,x,y,sp,psw,timer_phase,timer_stage2,timer_output,cpu_to_smp[4],smp_to_cpu[4]; uint64_t aram_hash64,dsp_hash64; uint32_t dsp_write_count; };
struct TgV21SmpPost08dbSummary { uint32_t source_target_driver_cycle,timer_phase_count,dsp_phase_count,combined_phase_count,cycle_class_count,cycle_min,cycle_max,architecture_class_count,unique_aram_hash_count,unique_dsp_hash_count; };
int tg_v21_generated_post08db_state(uint32_t,uint32_t,struct TgV21SmpPost08dbState*);
int tg_v21_generated_post08db_summary(uint32_t,struct TgV21SmpPost08dbSummary*);
#endif
