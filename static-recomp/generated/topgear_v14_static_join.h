#ifndef TOPGEAR_V14_STATIC_JOIN_H
#define TOPGEAR_V14_STATIC_JOIN_H
#include <stdint.h>
#define TOPGEAR_RECOMP_V14_COLD_PROFILE_COUNT 128u
#define TOPGEAR_RECOMP_V14_TIMER_PROFILE_COUNT 128u
typedef struct TgV14AxisRow { uint64_t exit_master,exit_instruction,command_master; uint32_t command_driver_cycle,comparisons; uint8_t endpoint_residual; } TgV14AxisRow;
extern const TgV14AxisRow tg_v14_cold_axis[128];
extern const TgV14AxisRow tg_v14_timer_axis[128];
#endif
