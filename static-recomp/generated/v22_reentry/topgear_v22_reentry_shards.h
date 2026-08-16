#ifndef TOPGEAR_V22_REENTRY_SHARDS_H
#define TOPGEAR_V22_REENTRY_SHARDS_H
#include <stdint.h>
struct TopGearRecomp;
int tg_v22_reentry_semantic_step(struct TopGearRecomp*);
int tg_v22_reentry_has_context(uint32_t);
unsigned tg_v22_reentry_context_count(void);
#endif
