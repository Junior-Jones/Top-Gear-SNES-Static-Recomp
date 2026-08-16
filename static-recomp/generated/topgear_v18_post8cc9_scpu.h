#ifndef TOPGEAR_V18_POST8CC9_SCPU_H
#define TOPGEAR_V18_POST8CC9_SCPU_H
#include <stdint.h>
struct TopGearRecomp;
#define TOPGEAR_V18_POST8CC9_INSTRUCTION_COUNT 827109u
int tg_v18_generated_post8cc9_semantic_step(struct TopGearRecomp *instance);
int tg_v18_generated_post8cc9_timing_step(struct TopGearRecomp *instance,uint32_t route_index);
unsigned tg_v18_generated_post8cc9_context_count(void);
uint64_t tg_v18_generated_post8cc9_processor_cycle_count(void);
uint64_t tg_v18_generated_post8cc9_active_master_clock_count(void);
#endif
