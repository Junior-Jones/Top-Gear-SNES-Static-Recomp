/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_002D(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x0000B631u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xB633u;
        instance->instruction_count++;
        return 1;
    case 0x0000B633u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xB636u;
        instance->instruction_count++;
        return 1;
    case 0x0000B636u: /* 20 0E EC JSR $EC0E */
        if (!tg_push16(instance, 0xB638u)) return 0;
        instance->cpu.pc = 0xEC0Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000B639u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xB63Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400B63Bu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xB63Du;
        instance->instruction_count++;
        return 1;
    case 0x0400B63Du: /* 8D 0C 42 STA $420C */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB640u;
        instance->instruction_count++;
        return 1;
    case 0x0400B640u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xB642u;
        instance->instruction_count++;
        return 1;
    case 0x0000B642u: /* A9 42 21 LDA #$2142 */
        word = 0x2142u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xB645u;
        instance->instruction_count++;
        return 1;
    case 0x0000B645u: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB648u;
        instance->instruction_count++;
        return 1;
    case 0x0000B648u: /* A9 42 22 LDA #$2242 */
        word = 0x2242u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xB64Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000B64Bu: /* 8D 10 43 STA $4310 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4310u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB64Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000B64Eu: /* 8D 20 43 STA $4320 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4320u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB651u;
        instance->instruction_count++;
        return 1;
    case 0x0000B651u: /* 8D 30 43 STA $4330 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4330u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB654u;
        instance->instruction_count++;
        return 1;
    case 0x0000B654u: /* 8D 40 43 STA $4340 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4340u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB657u;
        instance->instruction_count++;
        return 1;
    case 0x0000B657u: /* A9 43 11 LDA #$1143 */
        word = 0x1143u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xB65Au;
        instance->instruction_count++;
        return 1;
    case 0x0000B65Au: /* 8D 50 43 STA $4350 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4350u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB65Du;
        instance->instruction_count++;
        return 1;
    case 0x0000B65Du: /* A9 04 26 LDA #$2604 */
        word = 0x2604u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xB660u;
        instance->instruction_count++;
        return 1;
    case 0x0000B660u: /* AE 00 01 LDX $0100 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0100u), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xB663u;
        instance->instruction_count++;
        return 1;
    case 0x0000B663u: /* 10 09 BPL $00:B66E */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB66Eu : 0xB665u;
        instance->instruction_count++;
        return 1;
    case 0x0000B665u: /* A9 FF 00 LDA #$00FF */
        word = 0x00FFu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xB668u;
        instance->instruction_count++;
        return 1;
    case 0x0000B668u: /* 8D 28 21 STA $2128 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2128u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB66Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000B66Bu: /* A9 41 28 LDA #$2841 */
        word = 0x2841u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xB66Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000B66Eu: /* 8D 60 43 STA $4360 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4360u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB671u;
        instance->instruction_count++;
        return 1;
    case 0x0000B671u: /* A9 12 0C LDA #$0C12 */
        word = 0x0C12u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xB674u;
        instance->instruction_count++;
        return 1;
    case 0x0000B674u: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB677u;
        instance->instruction_count++;
        return 1;
    case 0x0000B677u: /* 8D 12 43 STA $4312 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4312u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB67Au;
        instance->instruction_count++;
        return 1;
    case 0x0000B67Au: /* 8D 22 43 STA $4322 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4322u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB67Du;
        instance->instruction_count++;
        return 1;
    case 0x0000B67Du: /* 8D 32 43 STA $4332 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4332u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB680u;
        instance->instruction_count++;
        return 1;
    case 0x0000B680u: /* 8D 42 43 STA $4342 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4342u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB683u;
        instance->instruction_count++;
        return 1;
    case 0x0000B683u: /* A9 FA BE LDA #$BEFA */
        word = 0xBEFAu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xB686u;
        instance->instruction_count++;
        return 1;
    case 0x0000B686u: /* 8D 52 43 STA $4352 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4352u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB689u;
        instance->instruction_count++;
        return 1;
    case 0x0000B689u: /* A9 54 0E LDA #$0E54 */
        word = 0x0E54u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xB68Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000B68Cu: /* 8D 62 43 STA $4362 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4362u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xB68Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000B68Fu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xB691u;
        instance->instruction_count++;
        return 1;
    case 0x0400B691u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xB693u;
        instance->instruction_count++;
        return 1;
    case 0x0400B693u: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB696u;
        instance->instruction_count++;
        return 1;
    case 0x0400B696u: /* 8D 14 43 STA $4314 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4314u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB699u;
        instance->instruction_count++;
        return 1;
    case 0x0400B699u: /* 8D 24 43 STA $4324 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4324u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB69Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400B69Cu: /* 8D 34 43 STA $4334 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4334u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB69Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400B69Fu: /* 8D 44 43 STA $4344 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4344u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB6A2u;
        instance->instruction_count++;
        return 1;
    case 0x0400B6A2u: /* 8D 54 43 STA $4354 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4354u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB6A5u;
        instance->instruction_count++;
        return 1;
    case 0x0400B6A5u: /* 8D 64 43 STA $4364 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4364u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB6A8u;
        instance->instruction_count++;
        return 1;
    case 0x0400B6A8u: /* 8D 57 43 STA $4357 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4357u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB6ABu;
        instance->instruction_count++;
        return 1;
    case 0x0400B6ABu: /* 8D 67 43 STA $4367 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4367u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB6AEu;
        instance->instruction_count++;
        return 1;
    case 0x0400B6AEu: /* A9 08 LDA #$08 */
        byte = 0x08u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xB6B0u;
        instance->instruction_count++;
        return 1;
    case 0x0400B6B0u: /* 8D 57 43 STA $4357 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4357u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB6B3u;
        instance->instruction_count++;
        return 1;
    case 0x0400B6B3u: /* 8D 67 43 STA $4367 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4367u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB6B6u;
        instance->instruction_count++;
        return 1;
    case 0x0400B6B6u: /* 8D 07 43 STA $4307 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4307u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB6B9u;
        instance->instruction_count++;
        return 1;
    case 0x0400B6B9u: /* 1A INC A */
        byte = (uint8_t)((tg_acc8(instance)) + 1u);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xB6BAu;
        instance->instruction_count++;
        return 1;
    case 0x0400B6BAu: /* 8D 17 43 STA $4317 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4317u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB6BDu;
        instance->instruction_count++;
        return 1;
    case 0x0400B6BDu: /* 1A INC A */
        byte = (uint8_t)((tg_acc8(instance)) + 1u);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xB6BEu;
        instance->instruction_count++;
        return 1;
    case 0x0400B6BEu: /* 8D 27 43 STA $4327 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4327u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB6C1u;
        instance->instruction_count++;
        return 1;
    case 0x0400B6C1u: /* 1A INC A */
        byte = (uint8_t)((tg_acc8(instance)) + 1u);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xB6C2u;
        instance->instruction_count++;
        return 1;
    case 0x0400B6C2u: /* 8D 37 43 STA $4337 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4337u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB6C5u;
        instance->instruction_count++;
        return 1;
    case 0x0400B6C5u: /* 1A INC A */
        byte = (uint8_t)((tg_acc8(instance)) + 1u);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xB6C6u;
        instance->instruction_count++;
        return 1;
    case 0x0400B6C6u: /* 8D 47 43 STA $4347 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4347u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB6C9u;
        instance->instruction_count++;
        return 1;
    case 0x0400B6C9u: /* A9 7F LDA #$7F */
        byte = 0x7Fu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xB6CBu;
        instance->instruction_count++;
        return 1;
    case 0x0400B6CBu: /* 8D 0C 42 STA $420C */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xB6CEu;
        instance->instruction_count++;
        return 1;
    case 0x0400B6CEu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xB6D0u;
        instance->instruction_count++;
        return 1;
    case 0x0000B6D0u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
