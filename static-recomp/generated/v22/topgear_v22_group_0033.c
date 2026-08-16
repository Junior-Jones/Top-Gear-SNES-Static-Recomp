/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_0033(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x0000CC00u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC03u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC03u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC04u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC04u: /* D0 FA BNE $00:CC00 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xCC00u : 0xCC06u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC06u: /* A9 60 0F LDA #$0F60 */
        word = 0x0F60u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC09u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC09u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC0Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CC0Cu: /* A9 01 AC LDA #$AC01 */
        word = 0xAC01u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC0Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CC0Fu: /* A2 20 00 LDX #$0020 */
        word = 0x0020u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC12u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC12u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC15u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC15u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC16u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC16u: /* D0 FA BNE $00:CC12 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xCC12u : 0xCC18u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC18u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCC1Au;
        instance->instruction_count++;
        return 1;
    case 0x0400CC1Au: /* A9 81 LDA #$81 */
        byte = 0x81u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xCC1Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400CC1Cu: /* 8D 15 21 STA $2115 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2115u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xCC1Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400CC1Fu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCC21u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC21u: /* A9 DE 0C LDA #$0CDE */
        word = 0x0CDEu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC24u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC24u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC27u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC27u: /* A9 10 38 LDA #$3810 */
        word = 0x3810u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC2Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CC2Au: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC2Du;
        instance->instruction_count++;
        return 1;
    case 0x0000CC2Du: /* A9 11 3C LDA #$3C11 */
        word = 0x3C11u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC30u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC30u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC33u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC33u: /* A9 12 3C LDA #$3C12 */
        word = 0x3C12u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC36u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC36u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC39u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC39u: /* A9 13 38 LDA #$3813 */
        word = 0x3813u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC3Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CC3Cu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC3Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CC3Fu: /* A9 14 38 LDA #$3814 */
        word = 0x3814u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC42u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC42u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC45u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC45u: /* A9 15 38 LDA #$3815 */
        word = 0x3815u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC48u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC48u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC4Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CC4Bu: /* A9 16 38 LDA #$3816 */
        word = 0x3816u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC4Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CC4Eu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC51u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC51u: /* A9 9E 0E LDA #$0E9E */
        word = 0x0E9Eu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC54u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC54u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC57u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC57u: /* A9 10 38 LDA #$3810 */
        word = 0x3810u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC5Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CC5Au: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC5Du;
        instance->instruction_count++;
        return 1;
    case 0x0000CC5Du: /* A9 11 3C LDA #$3C11 */
        word = 0x3C11u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC60u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC60u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC63u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC63u: /* A9 12 3C LDA #$3C12 */
        word = 0x3C12u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC66u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC66u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC69u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC69u: /* A9 13 38 LDA #$3813 */
        word = 0x3813u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC6Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CC6Cu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC6Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CC6Fu: /* A9 14 38 LDA #$3814 */
        word = 0x3814u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC72u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC72u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC75u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC75u: /* A9 15 38 LDA #$3815 */
        word = 0x3815u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC78u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC78u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC7Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CC7Bu: /* A9 16 38 LDA #$3816 */
        word = 0x3816u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC7Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CC7Eu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCC81u;
        instance->instruction_count++;
        return 1;
    case 0x0000CC81u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCC83u;
        instance->instruction_count++;
        return 1;
    case 0x0400CC83u: /* A9 80 LDA #$80 */
        byte = 0x80u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xCC85u;
        instance->instruction_count++;
        return 1;
    case 0x0400CC85u: /* 8D 15 21 STA $2115 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2115u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xCC88u;
        instance->instruction_count++;
        return 1;
    case 0x0400CC88u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCC8Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CC8Au: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0000CC9Bu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCC9Du;
        instance->instruction_count++;
        return 1;
    case 0x0400CC9Du: /* C2 10 REP #$10 */
        instance->cpu.p &= (uint8_t)~0x10u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCC9Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400CC9Fu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xCCA1u;
        instance->instruction_count++;
        return 1;
    case 0x0400CCA1u: /* 8D 54 0E STA $0E54 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0E54u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xCCA4u;
        instance->instruction_count++;
        return 1;
    case 0x0400CCA4u: /* 8D AF 0E STA $0EAF */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0EAFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xCCA7u;
        instance->instruction_count++;
        return 1;
    case 0x0400CCA7u: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCAAu;
        instance->instruction_count++;
        return 1;
    case 0x0400CCAAu: /* 9D 12 0C STA $0C12,X */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0C12u + instance->cpu.x)), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xCCADu;
        instance->instruction_count++;
        return 1;
    case 0x0400CCADu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCAEu;
        instance->instruction_count++;
        return 1;
    case 0x0400CCAEu: /* E0 42 02 CPX #$0242 */
        word = 0x0242u;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0xCCB1u;
        instance->instruction_count++;
        return 1;
    case 0x0400CCB1u: /* D0 F7 BNE $00:CCAA */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xCCAAu : 0xCCB3u;
        instance->instruction_count++;
        return 1;
    case 0x0400CCB3u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCCB5u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCB5u: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCB8u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCB8u: /* A9 80 01 LDA #$0180 */
        word = 0x0180u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCBBu;
        instance->instruction_count++;
        return 1;
    case 0x0000CCBBu: /* 9D 92 05 STA $0592,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0592u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCCBEu;
        instance->instruction_count++;
        return 1;
    case 0x0000CCBEu: /* 9D D2 08 STA $08D2,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x08D2u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCCC1u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCC1u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xCCC2u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCC2u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCC3u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCC3u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCC4u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCC4u: /* 49 FF FF EOR #$FFFF */
        word = 0xFFFFu;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCC7u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCC7u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xCCC8u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCC8u: /* 69 00 03 ADC #$0300 */
        word = 0x0300u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xCCCBu;
        instance->instruction_count++;
        return 1;
    case 0x0000CCCBu: /* 9D 94 05 STA $0594,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0594u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCCCEu;
        instance->instruction_count++;
        return 1;
    case 0x0000CCCEu: /* 9D D4 08 STA $08D4,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x08D4u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCCD1u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCD1u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCD2u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCD2u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCD3u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCD3u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCD4u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCD4u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCD5u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCD5u: /* E0 40 03 CPX #$0340 */
        word = 0x0340u;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0xCCD8u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCD8u: /* D0 DE BNE $00:CCB8 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xCCB8u : 0xCCDAu;
        instance->instruction_count++;
        return 1;
    case 0x0000CCDAu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0000CCDBu: /* C2 30 REP #$30 */
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCCDDu;
        instance->instruction_count++;
        return 1;
    case 0x0000CCDDu: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCE0u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCE0u: /* A2 FE 01 LDX #$01FE */
        word = 0x01FEu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCE3u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCE3u: /* 9D 8E 03 STA $038E,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x038Eu + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCCE6u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCE6u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCE7u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCE7u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCE8u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCE8u: /* 10 F9 BPL $00:CCE3 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xCCE3u : 0xCCEAu;
        instance->instruction_count++;
        return 1;
    case 0x0000CCEAu: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCEDu;
        instance->instruction_count++;
        return 1;
    case 0x0000CCEDu: /* A2 07 00 LDX #$0007 */
        word = 0x0007u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCF0u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCF0u: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCF3u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCF3u: /* 99 9C 1B STA $1B9C,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1B9Cu + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCCF6u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCF6u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xCCF7u;
        instance->instruction_count++;
        return 1;
    case 0x0000CCF7u: /* 69 00 02 ADC #$0200 */
        word = 0x0200u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xCCFAu;
        instance->instruction_count++;
        return 1;
    case 0x0000CCFAu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCFBu;
        instance->instruction_count++;
        return 1;
    case 0x0000CCFBu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCFCu;
        instance->instruction_count++;
        return 1;
    case 0x0000CCFCu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCCFDu;
        instance->instruction_count++;
        return 1;
    case 0x0000CCFDu: /* 10 F4 BPL $00:CCF3 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xCCF3u : 0xCCFFu;
        instance->instruction_count++;
        return 1;
    case 0x0000CCFFu: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD02u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD02u: /* 8D 56 1C STA $1C56 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1C56u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCD05u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD05u: /* 8D A4 1D STA $1DA4 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1DA4u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCD08u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD08u: /* A2 9A 89 LDX #$899A */
        word = 0x899Au;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD0Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD0Bu: /* A0 EE 03 LDY #$03EE */
        word = 0x03EEu;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD0Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD0Eu: /* A9 9F 00 LDA #$009F */
        word = 0x009Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD11u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD11u: /* 54 00 08 MVN $00,$08 */
        instance->cpu.dbr = 0x00u;
        address = ((uint32_t)0x08u << 16) | (instance->cpu.x & 0xFFFFu);
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        address = ((uint32_t)0x00u << 16) | (instance->cpu.y & 0xFFFFu);
        if (!tg_bus_write8(instance, address, byte)) return 0;
        instance->cpu.x = (uint16_t)(instance->cpu.x + 1u);
        instance->cpu.y = (uint16_t)(instance->cpu.y + 1u);
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)(instance->cpu.a - 1u);
        instance->cpu.pc = word != 0u ? 0xCD11u : 0xCD14u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD14u: /* A2 5A 92 LDX #$925A */
        word = 0x925Au;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD17u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD17u: /* A0 0E 05 LDY #$050E */
        word = 0x050Eu;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD1Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CD1Au: /* A9 7F 00 LDA #$007F */
        word = 0x007Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD1Du;
        instance->instruction_count++;
        return 1;
    case 0x0000CD1Du: /* 54 00 08 MVN $00,$08 */
        instance->cpu.dbr = 0x00u;
        address = ((uint32_t)0x08u << 16) | (instance->cpu.x & 0xFFFFu);
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        address = ((uint32_t)0x00u << 16) | (instance->cpu.y & 0xFFFFu);
        if (!tg_bus_write8(instance, address, byte)) return 0;
        instance->cpu.x = (uint16_t)(instance->cpu.x + 1u);
        instance->cpu.y = (uint16_t)(instance->cpu.y + 1u);
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)(instance->cpu.a - 1u);
        instance->cpu.pc = word != 0u ? 0xCD1Du : 0xCD20u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD20u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD23u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD23u: /* 8D 08 1C STA $1C08 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1C08u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCD26u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD26u: /* 8D 56 1D STA $1D56 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D56u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCD29u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD29u: /* 8D 0C 1C STA $1C0C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1C0Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCD2Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD2Cu: /* 8D 5A 1D STA $1D5A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D5Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCD2Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD2Fu: /* A9 80 00 LDA #$0080 */
        word = 0x0080u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD32u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD32u: /* 8D 0A 1C STA $1C0A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1C0Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCD35u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD35u: /* 8D 58 1D STA $1D58 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D58u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCD38u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD38u: /* 8D 0E 1C STA $1C0E */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1C0Eu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCD3Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD3Bu: /* 8D 5C 1D STA $1D5C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D5Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCD3Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD3Eu: /* AD 8F 1F LDA $1F8F */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Fu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD41u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD41u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD42u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD42u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD43u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD43u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD44u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD44u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD45u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD45u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD46u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD46u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xCD47u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD47u: /* 69 DA 92 ADC #$92DA */
        word = 0x92DAu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xCD4Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CD4Au: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xCD4Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD4Bu: /* A0 8E 04 LDY #$048E */
        word = 0x048Eu;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD4Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD4Eu: /* A9 1F 00 LDA #$001F */
        word = 0x001Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD51u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD51u: /* 54 00 08 MVN $00,$08 */
        instance->cpu.dbr = 0x00u;
        address = ((uint32_t)0x08u << 16) | (instance->cpu.x & 0xFFFFu);
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        address = ((uint32_t)0x00u << 16) | (instance->cpu.y & 0xFFFFu);
        if (!tg_bus_write8(instance, address, byte)) return 0;
        instance->cpu.x = (uint16_t)(instance->cpu.x + 1u);
        instance->cpu.y = (uint16_t)(instance->cpu.y + 1u);
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)(instance->cpu.a - 1u);
        instance->cpu.pc = word != 0u ? 0xCD51u : 0xCD54u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD54u: /* AD AC 1F LDA $1FAC */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FACu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD57u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD57u: /* CD 8F 1F CMP $1F8F */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Fu), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xCD5Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CD5Au: /* D0 06 BNE $00:CD62 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xCD62u : 0xCD5Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD5Cu: /* 9C 0A 1C STZ $1C0A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1C0Au), 0u)) return 0;
        instance->cpu.pc = 0xCD5Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD5Fu: /* 9C 58 1D STZ $1D58 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D58u), 0u)) return 0;
        instance->cpu.pc = 0xCD62u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD62u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD63u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD63u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD64u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD64u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD65u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD65u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD66u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD66u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD67u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD67u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xCD68u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD68u: /* 69 DA 92 ADC #$92DA */
        word = 0x92DAu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xCD6Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD6Bu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xCD6Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD6Cu: /* A0 AE 04 LDY #$04AE */
        word = 0x04AEu;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD6Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD6Fu: /* A9 1F 00 LDA #$001F */
        word = 0x001Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD72u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD72u: /* 54 00 08 MVN $00,$08 */
        instance->cpu.dbr = 0x00u;
        address = ((uint32_t)0x08u << 16) | (instance->cpu.x & 0xFFFFu);
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        address = ((uint32_t)0x00u << 16) | (instance->cpu.y & 0xFFFFu);
        if (!tg_bus_write8(instance, address, byte)) return 0;
        instance->cpu.x = (uint16_t)(instance->cpu.x + 1u);
        instance->cpu.y = (uint16_t)(instance->cpu.y + 1u);
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)(instance->cpu.a - 1u);
        instance->cpu.pc = word != 0u ? 0xCD72u : 0xCD75u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD75u: /* AD F8 1F LDA $1FF8 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF8u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD78u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD78u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD79u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD79u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD7Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CD7Au: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD7Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD7Bu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD7Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD7Cu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD7Du;
        instance->instruction_count++;
        return 1;
    case 0x0000CD7Du: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xCD7Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD7Eu: /* 69 5A 93 ADC #$935A */
        word = 0x935Au;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xCD81u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD81u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xCD82u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD82u: /* A0 CE 04 LDY #$04CE */
        word = 0x04CEu;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD85u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD85u: /* A9 1F 00 LDA #$001F */
        word = 0x001Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD88u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD88u: /* 54 00 08 MVN $00,$08 */
        instance->cpu.dbr = 0x00u;
        address = ((uint32_t)0x08u << 16) | (instance->cpu.x & 0xFFFFu);
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        address = ((uint32_t)0x00u << 16) | (instance->cpu.y & 0xFFFFu);
        if (!tg_bus_write8(instance, address, byte)) return 0;
        instance->cpu.x = (uint16_t)(instance->cpu.x + 1u);
        instance->cpu.y = (uint16_t)(instance->cpu.y + 1u);
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)(instance->cpu.a - 1u);
        instance->cpu.pc = word != 0u ? 0xCD88u : 0xCD8Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD8Bu: /* AD F8 1F LDA $1FF8 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF8u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD8Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD8Eu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD8Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD8Fu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD90u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD90u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD91u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD91u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD92u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD92u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD93u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD93u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xCD94u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD94u: /* 69 DA 93 ADC #$93DA */
        word = 0x93DAu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xCD97u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD97u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xCD98u;
        instance->instruction_count++;
        return 1;
    case 0x0000CD98u: /* A0 EE 04 LDY #$04EE */
        word = 0x04EEu;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD9Bu: /* A9 1F 00 LDA #$001F */
        word = 0x001Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCD9Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CD9Eu: /* 54 00 08 MVN $00,$08 */
        instance->cpu.dbr = 0x00u;
        address = ((uint32_t)0x08u << 16) | (instance->cpu.x & 0xFFFFu);
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        address = ((uint32_t)0x00u << 16) | (instance->cpu.y & 0xFFFFu);
        if (!tg_bus_write8(instance, address, byte)) return 0;
        instance->cpu.x = (uint16_t)(instance->cpu.x + 1u);
        instance->cpu.y = (uint16_t)(instance->cpu.y + 1u);
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)(instance->cpu.a - 1u);
        instance->cpu.pc = word != 0u ? 0xCD9Eu : 0xCDA1u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDA1u: /* AD F8 1F LDA $1FF8 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF8u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDA4u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDA4u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDA5u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDA5u: /* 29 03 00 AND #$0003 */
        word = 0x0003u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDA8u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDA8u: /* 8D F8 1F STA $1FF8 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF8u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCDABu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDABu: /* AD 06 1F LDA $1F06 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDAEu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDAEu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDAFu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDAFu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xCDB0u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDB0u: /* A9 44 00 LDA #$0044 */
        word = 0x0044u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDB3u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDB3u: /* 8D 3D 01 STA $013D */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x013Du), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCDB6u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDB6u: /* B9 A4 E0 LDA $E0A4,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE0A4u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDB9u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDB9u: /* 30 27 BMI $00:CDE2 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xCDE2u : 0xCDBBu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDBBu: /* 8D 98 03 STA $0398 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0398u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCDBEu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDBEu: /* 8D 9A 03 STA $039A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x039Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCDC1u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDC1u: /* 8D 9C 03 STA $039C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x039Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCDC4u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDC4u: /* A2 20 00 LDX #$0020 */
        word = 0x0020u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDC7u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDC7u: /* 9D CC 03 STA $03CC,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x03CCu + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCDCAu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDCAu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDCBu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDCBu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDCCu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDCCu: /* D0 F9 BNE $00:CDC7 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xCDC7u : 0xCDCEu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDCEu: /* 8D 00 01 STA $0100 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0100u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCDD1u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDD1u: /* A2 FF FF LDX #$FFFF */
        word = 0xFFFFu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDD4u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDD4u: /* 8E 02 01 STX $0102 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0102u), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xCDD7u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDD7u: /* B9 24 E0 LDA $E024,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE024u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDDAu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDDAu: /* 8D 04 01 STA $0104 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0104u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCDDDu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDDDu: /* A9 5A 8A LDA #$8A5A */
        word = 0x8A5Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDE0u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDE0u: /* 80 50 BRA $00:CE32 */
        instance->cpu.pc = 0xCE32u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDE2u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xCDE3u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDE3u: /* 29 FF 3F AND #$3FFF */
        word = 0x3FFFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDE6u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDE6u: /* 3A DEC A */
        word = (uint16_t)((instance->cpu.a) - 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDE7u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDE7u: /* 8D 02 01 STA $0102 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0102u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCDEAu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDEAu: /* A9 58 00 LDA #$0058 */
        word = 0x0058u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDEDu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDEDu: /* 8D 3D 01 STA $013D */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x013Du), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCDF0u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDF0u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xCDF1u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDF1u: /* 29 00 C0 AND #$C000 */
        word = 0xC000u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDF4u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDF4u: /* 89 00 40 BIT #$4000 */
        word = 0x4000u;
        tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
        instance->cpu.pc = 0xCDF7u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDF7u: /* F0 1F BEQ $00:CE18 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xCE18u : 0xCDF9u;
        instance->instruction_count++;
        return 1;
    case 0x0000CDF9u: /* 09 DF 00 ORA #$00DF */
        word = 0x00DFu;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCDFCu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDFCu: /* 8D 00 01 STA $0100 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0100u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCDFFu;
        instance->instruction_count++;
        return 1;
    case 0x0000CDFFu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCE01u;
        instance->instruction_count++;
        return 1;
    case 0x0400CE01u: /* A9 ED LDA #$ED */
        byte = 0xEDu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xCE03u;
        instance->instruction_count++;
        return 1;
    case 0x0400CE03u: /* 8D 32 21 STA $2132 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2132u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xCE06u;
        instance->instruction_count++;
        return 1;
    case 0x0400CE06u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCE08u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE08u: /* B9 64 E0 LDA $E064,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE064u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE0Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CE0Bu: /* 8D 04 01 STA $0104 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0104u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCE0Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CE0Eu: /* A9 94 B4 LDA #$B494 */
        word = 0xB494u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE11u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE11u: /* 85 66 STA $66 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCE13u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE13u: /* A9 5A 8E LDA #$8E5A */
        word = 0x8E5Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE16u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE16u: /* 80 1A BRA $00:CE32 */
        instance->cpu.pc = 0xCE32u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE18u: /* 8D 00 01 STA $0100 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0100u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCE1Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CE1Bu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCE1Du;
        instance->instruction_count++;
        return 1;
    case 0x0400CE1Du: /* A9 E0 LDA #$E0 */
        byte = 0xE0u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xCE1Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400CE1Fu: /* 8D 32 21 STA $2132 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2132u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xCE22u;
        instance->instruction_count++;
        return 1;
    case 0x0400CE22u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCE24u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE24u: /* B9 24 E0 LDA $E024,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE024u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE27u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE27u: /* 8D 04 01 STA $0104 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0104u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCE2Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CE2Au: /* A9 B6 B6 LDA #$B6B6 */
        word = 0xB6B6u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE2Du;
        instance->instruction_count++;
        return 1;
    case 0x0000CE2Du: /* 85 66 STA $66 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCE2Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CE2Fu: /* A9 5A 8A LDA #$8A5A */
        word = 0x8A5Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE32u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE32u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xCE33u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE33u: /* 79 E4 DF ADC $DFE4,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xDFE4u + instance->cpu.y)), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xCE36u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE36u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xCE37u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE37u: /* A0 AE 03 LDY #$03AE */
        word = 0x03AEu;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE3Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CE3Au: /* A9 1F 00 LDA #$001F */
        word = 0x001Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE3Du;
        instance->instruction_count++;
        return 1;
    case 0x0000CE3Du: /* 54 00 08 MVN $00,$08 */
        instance->cpu.dbr = 0x00u;
        address = ((uint32_t)0x08u << 16) | (instance->cpu.x & 0xFFFFu);
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        address = ((uint32_t)0x00u << 16) | (instance->cpu.y & 0xFFFFu);
        if (!tg_bus_write8(instance, address, byte)) return 0;
        instance->cpu.x = (uint16_t)(instance->cpu.x + 1u);
        instance->cpu.y = (uint16_t)(instance->cpu.y + 1u);
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)(instance->cpu.a - 1u);
        instance->cpu.pc = word != 0u ? 0xCE3Du : 0xCE40u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE40u: /* 8D 8C 03 STA $038C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x038Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCE43u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE43u: /* AD 8C 03 LDA $038C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x038Cu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE46u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE46u: /* 30 FB BMI $00:CE43 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xCE43u : 0xCE48u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE48u: /* A2 CE 03 LDX #$03CE */
        word = 0x03CEu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE4Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CE4Bu: /* A0 8E 03 LDY #$038E */
        word = 0x038Eu;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE4Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CE4Eu: /* A9 BF 00 LDA #$00BF */
        word = 0x00BFu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE51u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE51u: /* 54 00 00 MVN $00,$00 */
        instance->cpu.dbr = 0x00u;
        address = ((uint32_t)0x00u << 16) | (instance->cpu.x & 0xFFFFu);
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        address = ((uint32_t)0x00u << 16) | (instance->cpu.y & 0xFFFFu);
        if (!tg_bus_write8(instance, address, byte)) return 0;
        instance->cpu.x = (uint16_t)(instance->cpu.x + 1u);
        instance->cpu.y = (uint16_t)(instance->cpu.y + 1u);
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)(instance->cpu.a - 1u);
        instance->cpu.pc = word != 0u ? 0xCE51u : 0xCE54u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE54u: /* A2 8E 03 LDX #$038E */
        word = 0x038Eu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE57u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE57u: /* A0 4E 04 LDY #$044E */
        word = 0x044Eu;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE5Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CE5Au: /* A9 BF 00 LDA #$00BF */
        word = 0x00BFu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCE5Du;
        instance->instruction_count++;
        return 1;
    case 0x0000CE5Du: /* 54 00 00 MVN $00,$00 */
        instance->cpu.dbr = 0x00u;
        address = ((uint32_t)0x00u << 16) | (instance->cpu.x & 0xFFFFu);
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        address = ((uint32_t)0x00u << 16) | (instance->cpu.y & 0xFFFFu);
        if (!tg_bus_write8(instance, address, byte)) return 0;
        instance->cpu.x = (uint16_t)(instance->cpu.x + 1u);
        instance->cpu.y = (uint16_t)(instance->cpu.y + 1u);
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)(instance->cpu.a - 1u);
        instance->cpu.pc = word != 0u ? 0xCE5Du : 0xCE60u;
        instance->instruction_count++;
        return 1;
    case 0x0000CE60u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
