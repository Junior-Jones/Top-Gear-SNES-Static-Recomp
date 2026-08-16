#ifndef TOPGEAR_V20_POST1098_APU_WRITE_H
#define TOPGEAR_V20_POST1098_APU_WRITE_H
#include <stdint.h>
struct TgV20SmpPost1098State { uint32_t source_target_driver_cycle,initial_timer_phase,next_apu_write_cycle,instruction_count,cycle_count,instructions_after_109a; uint16_t next_apu_write_pc,next_apu_write_address,pc_after_write_instruction; uint8_t next_apu_write_value,write_cycle_offset,a,x,y,sp,psw,timer_phase,timer_stage2,timer_output,cpu_to_smp[4],smp_to_cpu[4]; uint64_t aram_hash64,dsp_hash64; uint32_t dsp_write_count; };
struct TgV20SmpPost1098Summary { uint32_t source_target_driver_cycle,timer_phase_count,dsp_phase_count,combined_phase_count,cycle_class_count,cycle_min,cycle_max,architecture_class_count,unique_aram_hash_count,unique_dsp_hash_count; };
int tg_v20_generated_post1098_state(uint32_t,uint32_t,struct TgV20SmpPost1098State*);
int tg_v20_generated_post1098_summary(uint32_t,struct TgV20SmpPost1098Summary*);
#endif
