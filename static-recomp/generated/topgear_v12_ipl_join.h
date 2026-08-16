#ifndef TOPGEAR_V12_IPL_JOIN_H
#define TOPGEAR_V12_IPL_JOIN_H
#include <stdint.h>
#include "topgear_static_recomp.h"
typedef struct TgV12IplCore { uint8_t a,x,y,sp,psw; uint16_t pc; uint64_t instructions,cycles; uint8_t stopped; } TgV12IplCore;
void tg_v12_ipl_reset(TgV12IplCore *s);
int tg_v12_ipl_step(TgV12IplCore *s,uint8_t cpu_to_smp[4],uint8_t smp_to_cpu[4],uint8_t aram[65536]);
void tg_v12_fill_ipl_join_info(TopGearV12IplJoinInfo *x);
#endif
