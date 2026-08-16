#ifndef TOPGEAR_V22_INTERRUPT_DISPATCH_H
#define TOPGEAR_V22_INTERRUPT_DISPATCH_H
struct TopGearRecomp;
int tg_v22_interrupt_semantic_step(struct TopGearRecomp *instance);
unsigned tg_v22_interrupt_context_count(void);
#endif
