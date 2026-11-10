#ifndef TG_60_TIMING_H
#define TG_60_TIMING_H
#include "topgear_internal.h"
#include "v22_reentry/topgear_v22_reentry_shards.h"
unsigned tg60_fuel_step(TopGearRecomp *i,unsigned actor,unsigned cost,unsigned elapsed);
unsigned tg60_shadow_fuel_cost(TopGearRecomp *i,unsigned cost);
void tg60_reset(TopGearRecomp *i);
int tg60_scale_force(TopGearRecomp *i,unsigned actor,int delta,unsigned elapsed);
int tg60_shadow_motor(TopGearRecomp *i,unsigned old_speed,int proposal);
int tg60_active(const TopGearRecomp *i);
void tg60_apply_requested(TopGearRecomp *i);
unsigned tg60_shadow_recovery_cost(TopGearRecomp *i,unsigned cost);
void tg60_shadow_lane_limits(TopGearRecomp *i,unsigned *positive,unsigned *negative);
unsigned tg60_refill_step(TopGearRecomp *i,unsigned actor);
int tg60_pit_force(TopGearRecomp *i,unsigned actor,int delta);
unsigned tg60_pit_scroll(TopGearRecomp *i,unsigned actor,unsigned step);
int tg60_countdown_step(TopGearRecomp *i,unsigned addr,unsigned channel,unsigned next);
#endif
