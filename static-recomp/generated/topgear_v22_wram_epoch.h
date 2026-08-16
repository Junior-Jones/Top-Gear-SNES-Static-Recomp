#ifndef TG_V22_WRAM_EPOCH_H
#define TG_V22_WRAM_EPOCH_H
#include <stdint.h>
struct TopGearRecomp;
int tg_v22_wram_epoch_semantic_step(struct TopGearRecomp *instance);
unsigned tg_v22_wram_epoch_context_count(void);
int tg_v22_wram_epoch_has_context(uint32_t key);
#endif
