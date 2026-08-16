/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_0036(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x0000D913u: /* C2 30 REP #$30 */
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xD915u;
        instance->instruction_count++;
        return 1;
    case 0x0000D915u: /* AD F6 1F LDA $1FF6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF6u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD918u;
        instance->instruction_count++;
        return 1;
    case 0x0000D918u: /* F0 28 BEQ $00:D942 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xD942u : 0xD91Au;
        instance->instruction_count++;
        return 1;
    case 0x0000D91Au: /* A9 44 45 LDA #$4544 */
        word = 0x4544u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD91Du;
        instance->instruction_count++;
        return 1;
    case 0x0000D91Du: /* 8D 4E 05 STA $054E */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x054Eu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD920u;
        instance->instruction_count++;
        return 1;
    case 0x0000D920u: /* 8D 5E 05 STA $055E */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x055Eu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD923u;
        instance->instruction_count++;
        return 1;
    case 0x0000D923u: /* A9 4D 4F LDA #$4F4D */
        word = 0x4F4Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD926u;
        instance->instruction_count++;
        return 1;
    case 0x0000D926u: /* 8D 50 05 STA $0550 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0550u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD929u;
        instance->instruction_count++;
        return 1;
    case 0x0000D929u: /* 8D 60 05 STA $0560 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0560u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD92Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000D92Cu: /* A9 20 20 LDA #$2020 */
        word = 0x2020u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD92Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000D92Fu: /* 8D 52 05 STA $0552 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0552u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD932u;
        instance->instruction_count++;
        return 1;
    case 0x0000D932u: /* 8D 62 05 STA $0562 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0562u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD935u;
        instance->instruction_count++;
        return 1;
    case 0x0000D935u: /* A9 20 20 LDA #$2020 */
        word = 0x2020u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD938u;
        instance->instruction_count++;
        return 1;
    case 0x0000D938u: /* 8D 54 05 STA $0554 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0554u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD93Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000D93Bu: /* 8D 64 05 STA $0564 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0564u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD93Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000D93Eu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xD940u;
        instance->instruction_count++;
        return 1;
    case 0x0400D940u: /* 80 3F BRA $00:D981 */
        instance->cpu.pc = 0xD981u;
        instance->instruction_count++;
        return 1;
    case 0x0000D942u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xD944u;
        instance->instruction_count++;
        return 1;
    case 0x0400D944u: /* A2 07 00 LDX #$0007 */
        word = 0x0007u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD947u;
        instance->instruction_count++;
        return 1;
    case 0x0400D947u: /* BD 86 1F LDA $1F86,X */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F86u + instance->cpu.x)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xD94Au;
        instance->instruction_count++;
        return 1;
    case 0x0400D94Au: /* 9D 4E 05 STA $054E,X */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x054Eu + instance->cpu.x)), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xD94Du;
        instance->instruction_count++;
        return 1;
    case 0x0400D94Du: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD94Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400D94Eu: /* 10 F7 BPL $00:D947 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xD947u : 0xD950u;
        instance->instruction_count++;
        return 1;
    case 0x0400D950u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xD952u;
        instance->instruction_count++;
        return 1;
    case 0x0000D952u: /* AD 04 1F LDA $1F04 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD955u;
        instance->instruction_count++;
        return 1;
    case 0x0000D955u: /* D0 1C BNE $00:D973 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xD973u : 0xD957u;
        instance->instruction_count++;
        return 1;
    case 0x0000D957u: /* A9 43 4F LDA #$4F43 */
        word = 0x4F43u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD95Au;
        instance->instruction_count++;
        return 1;
    case 0x0000D95Au: /* 8D 5E 05 STA $055E */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x055Eu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD95Du;
        instance->instruction_count++;
        return 1;
    case 0x0000D95Du: /* A9 4D 50 LDA #$504D */
        word = 0x504Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD960u;
        instance->instruction_count++;
        return 1;
    case 0x0000D960u: /* 8D 60 05 STA $0560 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0560u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD963u;
        instance->instruction_count++;
        return 1;
    case 0x0000D963u: /* A9 55 54 LDA #$5455 */
        word = 0x5455u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD966u;
        instance->instruction_count++;
        return 1;
    case 0x0000D966u: /* 8D 62 05 STA $0562 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0562u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD969u;
        instance->instruction_count++;
        return 1;
    case 0x0000D969u: /* A9 45 52 LDA #$5245 */
        word = 0x5245u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD96Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000D96Cu: /* 8D 64 05 STA $0564 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0564u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD96Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000D96Fu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xD971u;
        instance->instruction_count++;
        return 1;
    case 0x0400D971u: /* 80 0E BRA $00:D981 */
        instance->cpu.pc = 0xD981u;
        instance->instruction_count++;
        return 1;
    case 0x0000D973u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xD975u;
        instance->instruction_count++;
        return 1;
    case 0x0400D975u: /* A2 07 00 LDX #$0007 */
        word = 0x0007u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD978u;
        instance->instruction_count++;
        return 1;
    case 0x0400D978u: /* BD A3 1F LDA $1FA3,X */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1FA3u + instance->cpu.x)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xD97Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400D97Bu: /* 9D 5E 05 STA $055E,X */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x055Eu + instance->cpu.x)), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xD97Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400D97Eu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD97Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400D97Fu: /* 10 F7 BPL $00:D978 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xD978u : 0xD981u;
        instance->instruction_count++;
        return 1;
    case 0x0400D981u: /* 8B PHB */
        if (!tg_push8(instance, instance->cpu.dbr)) return 0;
        instance->cpu.pc = 0xD982u;
        instance->instruction_count++;
        return 1;
    case 0x0400D982u: /* A9 06 LDA #$06 */
        byte = 0x06u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xD984u;
        instance->instruction_count++;
        return 1;
    case 0x0400D984u: /* 48 PHA */
        if (!tg_push8(instance, (uint8_t)tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xD985u;
        instance->instruction_count++;
        return 1;
    case 0x0400D985u: /* AB PLB */
        if (!tg_pull8(instance, &byte)) return 0;
        instance->cpu.dbr = byte;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xD986u;
        instance->instruction_count++;
        return 1;
    case 0x0400D986u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xD988u;
        instance->instruction_count++;
        return 1;
    case 0x0000D988u: /* AD 7A 1E LDA $1E7A */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E7Au), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD98Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000D98Bu: /* 8D 1A 01 STA $011A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x011Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD98Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000D98Eu: /* AD 7C 1E LDA $1E7C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E7Cu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD991u;
        instance->instruction_count++;
        return 1;
    case 0x0000D991u: /* 8D 2C 01 STA $012C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x012Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD994u;
        instance->instruction_count++;
        return 1;
    case 0x0000D994u: /* A9 FF A7 LDA #$A7FF */
        word = 0xA7FFu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD997u;
        instance->instruction_count++;
        return 1;
    case 0x0000D997u: /* 8D 62 1E STA $1E62 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E62u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD99Au;
        instance->instruction_count++;
        return 1;
    case 0x0000D99Au: /* 8D 64 1E STA $1E64 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E64u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD99Du;
        instance->instruction_count++;
        return 1;
    case 0x0000D99Du: /* A9 20 06 LDA #$0620 */
        word = 0x0620u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9A0u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9A0u: /* 8D 22 01 STA $0122 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0122u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD9A3u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9A3u: /* A9 20 07 LDA #$0720 */
        word = 0x0720u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9A6u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9A6u: /* 8D 34 01 STA $0134 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0134u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD9A9u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9A9u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xD9ABu;
        instance->instruction_count++;
        return 1;
    case 0x0400D9ABu: /* A2 07 00 LDX #$0007 */
        word = 0x0007u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9AEu;
        instance->instruction_count++;
        return 1;
    case 0x0400D9AEu: /* A9 20 LDA #$20 */
        byte = 0x20u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xD9B0u;
        instance->instruction_count++;
        return 1;
    case 0x0400D9B0u: /* DD 4E 05 CMP $054E,X */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x054Eu + instance->cpu.x)), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xD9B3u;
        instance->instruction_count++;
        return 1;
    case 0x0400D9B3u: /* 30 03 BMI $00:D9B8 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xD9B8u : 0xD9B5u;
        instance->instruction_count++;
        return 1;
    case 0x0400D9B5u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9B6u;
        instance->instruction_count++;
        return 1;
    case 0x0400D9B6u: /* D0 F8 BNE $00:D9B0 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xD9B0u : 0xD9B8u;
        instance->instruction_count++;
        return 1;
    case 0x0400D9B8u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xD9BAu;
        instance->instruction_count++;
        return 1;
    case 0x0000D9BAu: /* 86 1A STX $1A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xD9BCu;
        instance->instruction_count++;
        return 1;
    case 0x0000D9BCu: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xD9BDu;
        instance->instruction_count++;
        return 1;
    case 0x0000D9BDu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xD9BEu;
        instance->instruction_count++;
        return 1;
    case 0x0000D9BEu: /* 69 37 00 ADC #$0037 */
        word = 0x0037u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xD9C1u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9C1u: /* 8D 24 01 STA $0124 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0124u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD9C4u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9C4u: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9C7u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9C7u: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9CAu;
        instance->instruction_count++;
        return 1;
    case 0x0000D9CAu: /* BD 4E 05 LDA $054E,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x054Eu + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9CDu;
        instance->instruction_count++;
        return 1;
    case 0x0000D9CDu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9CEu;
        instance->instruction_count++;
        return 1;
    case 0x0000D9CEu: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9D1u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9D1u: /* C9 20 00 CMP #$0020 */
        word = 0x0020u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xD9D4u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9D4u: /* D0 05 BNE $00:D9DB */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xD9DBu : 0xD9D6u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9D6u: /* A9 49 D0 LDA #$D049 */
        word = 0xD049u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9D9u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9D9u: /* 80 10 BRA $00:D9EB */
        instance->cpu.pc = 0xD9EBu;
        instance->instruction_count++;
        return 1;
    case 0x0000D9DBu: /* C9 41 00 CMP #$0041 */
        word = 0x0041u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xD9DEu;
        instance->instruction_count++;
        return 1;
    case 0x0000D9DEu: /* 10 04 BPL $00:D9E4 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xD9E4u : 0xD9E0u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9E0u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xD9E1u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9E1u: /* 69 2F 00 ADC #$002F */
        word = 0x002Fu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xD9E4u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9E4u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xD9E5u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9E5u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9E6u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9E6u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9E7u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9E7u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xD9E8u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9E8u: /* 69 49 C0 ADC #$C049 */
        word = 0xC049u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xD9EBu;
        instance->instruction_count++;
        return 1;
    case 0x0000D9EBu: /* 99 0E 05 STA $050E,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x050Eu + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD9EEu;
        instance->instruction_count++;
        return 1;
    case 0x0000D9EEu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9EFu;
        instance->instruction_count++;
        return 1;
    case 0x0000D9EFu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9F0u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9F0u: /* C6 1A DEC $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9F2u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9F2u: /* 10 D6 BPL $00:D9CA */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xD9CAu : 0xD9F4u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9F4u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9F7u;
        instance->instruction_count++;
        return 1;
    case 0x0000D9F7u: /* 99 0E 05 STA $050E,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x050Eu + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xD9FAu;
        instance->instruction_count++;
        return 1;
    case 0x0000D9FAu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xD9FCu;
        instance->instruction_count++;
        return 1;
    case 0x0400D9FCu: /* A2 07 00 LDX #$0007 */
        word = 0x0007u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xD9FFu;
        instance->instruction_count++;
        return 1;
    case 0x0400D9FFu: /* A9 20 LDA #$20 */
        byte = 0x20u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xDA01u;
        instance->instruction_count++;
        return 1;
    case 0x0400DA01u: /* DD 5E 05 CMP $055E,X */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x055Eu + instance->cpu.x)), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xDA04u;
        instance->instruction_count++;
        return 1;
    case 0x0400DA04u: /* 30 03 BMI $00:DA09 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xDA09u : 0xDA06u;
        instance->instruction_count++;
        return 1;
    case 0x0400DA06u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA07u;
        instance->instruction_count++;
        return 1;
    case 0x0400DA07u: /* D0 F8 BNE $00:DA01 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xDA01u : 0xDA09u;
        instance->instruction_count++;
        return 1;
    case 0x0400DA09u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xDA0Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA0Bu: /* 86 1A STX $1A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xDA0Du;
        instance->instruction_count++;
        return 1;
    case 0x0000DA0Du: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xDA0Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA0Eu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xDA0Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA0Fu: /* 69 76 00 ADC #$0076 */
        word = 0x0076u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xDA12u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA12u: /* 8D 36 01 STA $0136 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0136u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xDA15u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA15u: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA18u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA18u: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA1Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA1Bu: /* BD 5E 05 LDA $055E,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x055Eu + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA1Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA1Eu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA1Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA1Fu: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA22u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA22u: /* C9 20 00 CMP #$0020 */
        word = 0x0020u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xDA25u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA25u: /* D0 05 BNE $00:DA2C */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xDA2Cu : 0xDA27u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA27u: /* A9 49 D0 LDA #$D049 */
        word = 0xD049u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA2Au;
        instance->instruction_count++;
        return 1;
    case 0x0000DA2Au: /* 80 10 BRA $00:DA3C */
        instance->cpu.pc = 0xDA3Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA2Cu: /* C9 41 00 CMP #$0041 */
        word = 0x0041u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xDA2Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA2Fu: /* 10 04 BPL $00:DA35 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xDA35u : 0xDA31u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA31u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xDA32u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA32u: /* 69 2F 00 ADC #$002F */
        word = 0x002Fu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xDA35u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA35u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xDA36u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA36u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA37u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA37u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA38u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA38u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xDA39u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA39u: /* 69 49 C0 ADC #$C049 */
        word = 0xC049u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xDA3Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA3Cu: /* 99 2E 05 STA $052E,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x052Eu + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xDA3Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA3Fu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA40u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA40u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA41u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA41u: /* C6 1A DEC $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA43u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA43u: /* 10 D6 BPL $00:DA1B */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xDA1Bu : 0xDA45u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA45u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA48u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA48u: /* 99 2E 05 STA $052E,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x052Eu + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xDA4Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA4Bu: /* AD 24 01 LDA $0124 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0124u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA4Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA4Eu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA4Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA4Fu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xDA50u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA50u: /* 9C 26 01 STZ $0126 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0126u), 0u)) return 0;
        instance->cpu.pc = 0xDA53u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA53u: /* BD 80 DB LDA $DB80,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xDB80u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA56u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA56u: /* 8D 28 01 STA $0128 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0128u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xDA59u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA59u: /* BD 84 DC LDA $DC84,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xDC84u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA5Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA5Cu: /* 8D 20 01 STA $0120 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0120u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xDA5Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000DA5Fu: /* AD 36 01 LDA $0136 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0136u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA62u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA62u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA63u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA63u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xDA64u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA64u: /* 9C 38 01 STZ $0138 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0138u), 0u)) return 0;
        instance->cpu.pc = 0xDA67u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA67u: /* BD 80 DB LDA $DB80,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xDB80u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA6Au;
        instance->instruction_count++;
        return 1;
    case 0x0000DA6Au: /* 8D 3A 01 STA $013A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x013Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xDA6Du;
        instance->instruction_count++;
        return 1;
    case 0x0000DA6Du: /* BD 84 DC LDA $DC84,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xDC84u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xDA70u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA70u: /* 8D 32 01 STA $0132 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0132u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xDA73u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA73u: /* AB PLB */
        if (!tg_pull8(instance, &byte)) return 0;
        instance->cpu.dbr = byte;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xDA74u;
        instance->instruction_count++;
        return 1;
    case 0x0000DA74u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
