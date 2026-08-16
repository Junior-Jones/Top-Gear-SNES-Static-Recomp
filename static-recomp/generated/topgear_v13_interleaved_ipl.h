#ifndef TOPGEAR_V13_INTERLEAVED_IPL_H
#define TOPGEAR_V13_INTERLEAVED_IPL_H
#include <stdint.h>
#include "topgear_static_recomp.h"
#define TOPGEAR_RECOMP_V13_SMP_CLOCK_NUMERATOR 128000u
#define TOPGEAR_RECOMP_V13_SMP_CLOCK_DENOMINATOR 2684659u
#define TOPGEAR_RECOMP_V13_PREFIX_INSTRUCTION_COUNT 400772ull
#define TOPGEAR_RECOMP_V13_UPLOAD_DESTINATION 0x0800u
#define TOPGEAR_RECOMP_V13_UPLOAD_SIZE 12489u
#define TOPGEAR_RECOMP_V13_UPLOAD_SHA256 "fb50296cb92b5d7fc0f108f2aca7df36b9257cb880b4c19fed9a653560c88ba8"
#define TOPGEAR_RECOMP_V13_MAX_EVENTS_PER_INSTRUCTION 2u
typedef struct TgV13ScpuTimingVariant { uint32_t context_key,next_context_key; uint16_t master_clocks; uint8_t processor_cycles,event_count,reserved; uint32_t event_address[2]; uint8_t event_type[2]; uint8_t event_start_offset[2],event_end_offset[2],event_duration[2]; } TgV13ScpuTimingVariant;
typedef struct TgV13IplCore { uint8_t a,x,y,sp,psw; uint16_t pc; uint64_t instructions,cycles,program_entry_cycle; uint32_t payload_writes; uint8_t program_started; } TgV13IplCore;
extern const TgV13ScpuTimingVariant tg_v13_scpu_timing_variants[TOPGEAR_RECOMP_V13_SCPU_TIMING_VARIANT_COUNT];
void tg_v13_ipl_reset(TgV13IplCore*);
int tg_v13_ipl_sync(TgV13IplCore*,uint8_t cpu_to_smp[4],uint8_t smp_to_cpu[4],uint8_t aram[65536],uint64_t master_clock,uint32_t initial_phase);
const TgV13ScpuTimingVariant *tg_v13_find_scpu_timing(uint32_t key,uint32_t next_key,int require_next);
void tg_v13_fill_ipl_upload_info(TopGearV13IplUploadInfo*);
#endif
