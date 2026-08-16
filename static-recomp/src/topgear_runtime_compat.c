/* Current-runtime compatibility hooks for historical timing layers.
   The broad Version 22/23 core never enables the old V13/V15 timing modes, but
   shared MMIO/DMA code keeps these hook calls for certification builds. */
#include "topgear_internal.h"

int tg_v13_sync_before_apu_access(TopGearRecomp *i,uint32_t address,uint32_t hook_type){
    (void)address;(void)hook_type;
    if(!i)return 0;
    if(i->v13_nominal_join_mode)return tg_fail_frontier(i,"Version 13 timing mode is unavailable in the Version 26 current-runtime build.",NULL);
    return 1;
}
void tg_v14_note_apu_write(TopGearRecomp *i,uint32_t address,unsigned port,uint8_t value){(void)i;(void)address;(void)port;(void)value;}
int tg_v16_capture_dma_channel(TopGearRecomp *i,unsigned channel,uint8_t dmap,uint8_t target,uint16_t source,uint8_t bank,uint32_t bytes){(void)channel;(void)dmap;(void)target;(void)source;(void)bank;(void)bytes;if(!i)return 0;if(i->v15_post_audio_timing_mode)return tg_fail_frontier(i,"Version 15/16 DMA timing capture is unavailable in the current-runtime build.",NULL);return 1;}
int tg_v16_capture_dma_byte(TopGearRecomp *i,unsigned channel,uint32_t index,uint32_t address_a,uint8_t address_b,uint8_t data){(void)channel;(void)index;(void)address_a;(void)address_b;(void)data;if(!i)return 0;if(i->v15_post_audio_timing_mode)return tg_fail_frontier(i,"Version 15/16 DMA timing capture is unavailable in the current-runtime build.",NULL);return 1;}
void tg_v16_note_hdma_enable(TopGearRecomp *i,uint8_t mask){(void)i;(void)mask;}
int tg_v16_schedule_cpu_cycle(TopGearRecomp *i,uint8_t kind,uint32_t address,uint8_t clocks,uint8_t last_cycle){(void)kind;(void)address;(void)clocks;(void)last_cycle;if(!i)return 0;/* The broad V22 interrupt path advances timing through V23 nominal instruction classes after semantic execution. */return 1;}
