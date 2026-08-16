/* Generated from the exact Top Gear ROM by tools/scpu/generate_v18_nmi_optional_dma.py.
   Version 18 $90=$4C NMI subroutine only; no runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v18_nmi_optional_dma.h"

unsigned tg_v18_generated_optional_nmi_context_count(void){return 14u;}

int tg_v18_generated_optional_nmi_timing_step(struct TopGearRecomp *instance){
    uint32_t key;if(!instance)return 0;key=tg_generated_context_key(instance);switch(key){
    case 0x000FA21Au: /* E2 20 SEP #$20 */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A21A"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA21Au,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA21Bu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,1u))return 0;
        return 1;
    case 0x040FA21Cu: /* A9 00 LDA #$00 */
        if(!tg_require_context(instance,0u,1u,0u,0x0Fu,0x0000u,"0F:A21C"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA21Cu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA21Du,8u,1u))return 0;
        return 1;
    case 0x040FA21Eu: /* 8D 0B 42 STA $420B */
        if(!tg_require_context(instance,0u,1u,0u,0x0Fu,0x0000u,"0F:A21E"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA21Eu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA21Fu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA220u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F420Bu,6u,1u))return 0;
        return 1;
    case 0x040FA221u: /* 8D 21 21 STA $2121 */
        if(!tg_require_context(instance,0u,1u,0u,0x0Fu,0x0000u,"0F:A221"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA221u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA222u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA223u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F2121u,6u,1u))return 0;
        return 1;
    case 0x040FA224u: /* A9 00 LDA #$00 */
        if(!tg_require_context(instance,0u,1u,0u,0x0Fu,0x0000u,"0F:A224"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA224u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA225u,8u,1u))return 0;
        return 1;
    case 0x040FA226u: /* 8D 14 43 STA $4314 */
        if(!tg_require_context(instance,0u,1u,0u,0x0Fu,0x0000u,"0F:A226"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA226u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA227u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA228u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F4314u,6u,1u))return 0;
        return 1;
    case 0x040FA229u: /* C2 20 REP #$20 */
        if(!tg_require_context(instance,0u,1u,0u,0x0Fu,0x0000u,"0F:A229"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA229u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA22Au,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,1u))return 0;
        return 1;
    case 0x000FA22Bu: /* A9 6C 04 LDA #$046C */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A22B"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA22Bu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA22Cu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA22Du,8u,1u))return 0;
        return 1;
    case 0x000FA22Eu: /* 8D 12 43 STA $4312 */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A22E"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA22Eu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA22Fu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA230u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F4312u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F4313u,6u,1u))return 0;
        return 1;
    case 0x000FA231u: /* A9 00 02 LDA #$0200 */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A231"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA231u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA232u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA233u,8u,1u))return 0;
        return 1;
    case 0x000FA234u: /* 8D 15 43 STA $4315 */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A234"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA234u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA235u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA236u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F4315u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F4316u,6u,1u))return 0;
        return 1;
    case 0x000FA237u: /* A9 02 22 LDA #$2202 */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A237"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA237u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA238u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA239u,8u,1u))return 0;
        return 1;
    case 0x000FA23Au: /* 8D 10 43 STA $4310 */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A23A"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA23Au,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA23Bu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA23Cu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F4310u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F4311u,6u,1u))return 0;
        return 1;
    case 0x000FA23Du: /* 60 RTS */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A23D"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0FA23Du,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,1u))return 0;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 18 optional NMI DMA timing context.",NULL);
    }}

int tg_v18_generated_optional_nmi_semantic_step(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u;uint16_t word=0u;uint8_t byte=0u;if(!instance)return 0;
    (void)address;(void)base24;key=tg_generated_context_key(instance);switch(key){
    case 0x000FA21Au: /* E2 20 SEP #$20 */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A21A"))return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA21Cu;
        instance->instruction_count++;
        return 1;
    case 0x040FA21Cu: /* A9 00 LDA #$00 */
        if(!tg_require_context(instance,0u,1u,0u,0x0Fu,0x0000u,"0F:A21C"))return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA21Eu;
        instance->instruction_count++;
        return 1;
    case 0x040FA21Eu: /* 8D 0B 42 STA $420B */
        if(!tg_require_context(instance,0u,1u,0u,0x0Fu,0x0000u,"0F:A21E"))return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA221u;
        instance->instruction_count++;
        return 1;
    case 0x040FA221u: /* 8D 21 21 STA $2121 */
        if(!tg_require_context(instance,0u,1u,0u,0x0Fu,0x0000u,"0F:A221"))return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA224u;
        instance->instruction_count++;
        return 1;
    case 0x040FA224u: /* A9 00 LDA #$00 */
        if(!tg_require_context(instance,0u,1u,0u,0x0Fu,0x0000u,"0F:A224"))return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA226u;
        instance->instruction_count++;
        return 1;
    case 0x040FA226u: /* 8D 14 43 STA $4314 */
        if(!tg_require_context(instance,0u,1u,0u,0x0Fu,0x0000u,"0F:A226"))return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4314u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA229u;
        instance->instruction_count++;
        return 1;
    case 0x040FA229u: /* C2 20 REP #$20 */
        if(!tg_require_context(instance,0u,1u,0u,0x0Fu,0x0000u,"0F:A229"))return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA22Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA22Bu: /* A9 6C 04 LDA #$046C */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A22B"))return 0;
        word = 0x046Cu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA22Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA22Eu: /* 8D 12 43 STA $4312 */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A22E"))return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4312u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA231u;
        instance->instruction_count++;
        return 1;
    case 0x000FA231u: /* A9 00 02 LDA #$0200 */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A231"))return 0;
        word = 0x0200u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA234u;
        instance->instruction_count++;
        return 1;
    case 0x000FA234u: /* 8D 15 43 STA $4315 */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A234"))return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4315u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA237u;
        instance->instruction_count++;
        return 1;
    case 0x000FA237u: /* A9 02 22 LDA #$2202 */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A237"))return 0;
        word = 0x2202u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA23Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA23Au: /* 8D 10 43 STA $4310 */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A23A"))return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4310u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA23Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA23Du: /* 60 RTS */
        if(!tg_require_context(instance,0u,0u,0u,0x0Fu,0x0000u,"0F:A23D"))return 0;
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 18 optional NMI DMA semantic context.",NULL);
    }}
