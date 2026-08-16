#ifndef TG_V23_WRAM_EPOCH2_H
#define TG_V23_WRAM_EPOCH2_H
#include <stdint.h>
struct TopGearRecomp;
int tg_v23_wram_epoch2_semantic_step(struct TopGearRecomp *instance);
unsigned tg_v23_wram_epoch2_context_count(void);
int tg_v23_wram_epoch2_has_context(uint32_t key);
#endif
