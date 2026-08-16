#ifndef TG_V23_WRAM_EPOCH3_H
#define TG_V23_WRAM_EPOCH3_H
#include <stdint.h>
struct TopGearRecomp;
int tg_v23_wram_epoch3_semantic_step(struct TopGearRecomp *instance);
unsigned tg_v23_wram_epoch3_context_count(void);
int tg_v23_wram_epoch3_has_context(uint32_t key);
#endif
