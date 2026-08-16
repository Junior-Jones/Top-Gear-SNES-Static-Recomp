#ifndef TOPGEAR_V16_NMI_HANDLER_H
#define TOPGEAR_V16_NMI_HANDLER_H
struct TopGearRecomp;
unsigned tg_v16_generated_nmi_context_count(void);
int tg_v16_generated_nmi_timing_step(struct TopGearRecomp *instance);
int tg_v16_generated_nmi_semantic_step(struct TopGearRecomp *instance);
#endif
