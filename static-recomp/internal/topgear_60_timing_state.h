#ifndef TOPGEAR_60_TIMING_STATE_H
#define TOPGEAR_60_TIMING_STATE_H
/* Pointer-free, per-instance state. Native private CPU clones copy it with
   their core and return it with their authoritative driving results. */
typedef struct Tg60Fuel {
    unsigned remainder[4];
    unsigned long long calls[4],raw[4],emitted[4];
} Tg60Fuel;
typedef struct Tg60TimingState {
    Tg60Fuel fuel;
    unsigned shadow_remainder[4];
    int force_remainder[4],shadow_force_remainder[4];
    unsigned motor_initial[4],motor_pending[4];
    unsigned long long motor_calls[4];
    int traffic_speed_remainder[20],traffic_lane_remainder[20];
    unsigned traffic_timer_remainder[20];
    unsigned long long traffic_speed_calls[20],traffic_lane_calls[20];
    unsigned recovery_remainder[4],shadow_recovery_remainder[4];
    unsigned lane_limit_remainder[4],shadow_lane_limit_remainder[4];
    unsigned lane_positive[4],lane_negative[4];
    unsigned refill_remainder[4],pit_scroll_remainder[4],countdown_remainder[3];
    int pit_force_remainder[4];
    /* Uses the previously zeroed trailing word; snapshot/core size stays
       unchanged. Retain one request until the renderer acknowledges it. */
    unsigned finish_request_pending;
} Tg60TimingState;
_Static_assert(sizeof(Tg60TimingState)==944,"60 Hz snapshot extension ABI changed");
#endif
