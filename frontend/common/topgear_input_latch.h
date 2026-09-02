#ifndef TOPGEAR_INPUT_LATCH_H
#define TOPGEAR_INPUT_LATCH_H

#include <stdint.h>

typedef struct TopGearInputLatch {
    uint16_t held;
    uint16_t pending_press;
} TopGearInputLatch;

void topgear_input_latch_reset(TopGearInputLatch *latch);
void topgear_input_latch_press(TopGearInputLatch *latch, uint16_t mask,
                           uint16_t unsampled_opposite_mask, int repeated);
void topgear_input_latch_release(TopGearInputLatch *latch, uint16_t mask);
uint16_t topgear_input_latch_sample(const TopGearInputLatch *latch);
void topgear_input_latch_consume(TopGearInputLatch *latch, uint16_t sampled_mask);

#endif
