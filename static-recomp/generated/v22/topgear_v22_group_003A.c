/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_003A(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x0000E801u: /* 9D 36 1D STA $1D36,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D36u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xE804u;
        instance->instruction_count++;
        return 1;
    case 0x0000E804u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xE805u;
        instance->instruction_count++;
        return 1;
    case 0x0000E805u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE806u;
        instance->instruction_count++;
        return 1;
    case 0x0000E806u: /* 9D 56 1D STA $1D56,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D56u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xE809u;
        instance->instruction_count++;
        return 1;
    case 0x0000E809u: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0xE80Au;
        instance->instruction_count++;
        return 1;
    case 0x0000E80Au: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xE80Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000E80Bu: /* 6D 08 1D ADC $1D08 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xE80Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000E80Eu: /* 9D D6 1D STA $1DD6,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1DD6u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xE811u;
        instance->instruction_count++;
        return 1;
    case 0x0000E811u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE812u;
        instance->instruction_count++;
        return 1;
    case 0x0000E812u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE813u;
        instance->instruction_count++;
        return 1;
    case 0x0000E813u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE814u;
        instance->instruction_count++;
        return 1;
    case 0x0000E814u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE815u;
        instance->instruction_count++;
        return 1;
    case 0x0000E815u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE816u;
        instance->instruction_count++;
        return 1;
    case 0x0000E816u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xE817u;
        instance->instruction_count++;
        return 1;
    case 0x0000E817u: /* 69 00 40 ADC #$4000 */
        word = 0x4000u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xE81Au;
        instance->instruction_count++;
        return 1;
    case 0x0000E81Au: /* 8D 0C 1D STA $1D0C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xE81Du;
        instance->instruction_count++;
        return 1;
    case 0x0000E81Du: /* 7A PLY */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE81Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000E81Eu: /* B9 82 E8 LDA $E882,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE882u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE821u;
        instance->instruction_count++;
        return 1;
    case 0x0000E821u: /* 8D 0A 1D STA $1D0A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xE824u;
        instance->instruction_count++;
        return 1;
    case 0x0000E824u: /* B9 84 E8 LDA $E884,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE884u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE827u;
        instance->instruction_count++;
        return 1;
    case 0x0000E827u: /* 8D 08 1D STA $1D08 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xE82Au;
        instance->instruction_count++;
        return 1;
    case 0x0000E82Au: /* B9 86 E8 LDA $E886,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE886u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE82Du;
        instance->instruction_count++;
        return 1;
    case 0x0000E82Du: /* 8D 0E 1D STA $1D0E */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Eu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xE830u;
        instance->instruction_count++;
        return 1;
    case 0x0000E830u: /* 24 53 BIT $53 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x53u) & 0xFFFFu), &word)) return 0;
        tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
        tg_set_flag(instance, TG_P_N, (word & 0x8000u) != 0u);
        tg_set_flag(instance, TG_P_V, (word & 0x4000u) != 0u);
        instance->cpu.pc = 0xE832u;
        instance->instruction_count++;
        return 1;
    case 0x0000E832u: /* 10 04 BPL $00:E838 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xE838u : 0xE834u;
        instance->instruction_count++;
        return 1;
    case 0x0000E834u: /* 9C 0E 1D STZ $1D0E */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Eu), 0u)) return 0;
        instance->cpu.pc = 0xE837u;
        instance->instruction_count++;
        return 1;
    case 0x0000E837u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0000E838u: /* A2 00 04 LDX #$0400 */
        word = 0x0400u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE83Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000E83Bu: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xE83Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000E83Cu: /* E9 00 04 SBC #$0400 */
        word = 0x0400u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xE83Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000E83Fu: /* B0 07 BCS $00:E848 */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE848u : 0xE841u;
        instance->instruction_count++;
        return 1;
    case 0x0000E841u: /* 69 00 04 ADC #$0400 */
        word = 0x0400u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xE844u;
        instance->instruction_count++;
        return 1;
    case 0x0000E844u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xE845u;
        instance->instruction_count++;
        return 1;
    case 0x0000E845u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE848u;
        instance->instruction_count++;
        return 1;
    case 0x0000E848u: /* 8D 0E 1D STA $1D0E */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Eu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xE84Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000E84Bu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xE84Du;
        instance->instruction_count++;
        return 1;
    case 0x0400E84Du: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xE84Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400E84Fu: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xE852u;
        instance->instruction_count++;
        return 1;
    case 0x0400E852u: /* AD 0A 1D LDA $1D0A */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Au), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xE855u;
        instance->instruction_count++;
        return 1;
    case 0x0400E855u: /* 8D 74 43 STA $4374 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xE858u;
        instance->instruction_count++;
        return 1;
    case 0x0400E858u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xE85Au;
        instance->instruction_count++;
        return 1;
    case 0x0000E85Au: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE85Du;
        instance->instruction_count++;
        return 1;
    case 0x0000E85Du: /* 8D 70 43 STA $4370 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xE860u;
        instance->instruction_count++;
        return 1;
    case 0x0000E860u: /* AD 08 1D LDA $1D08 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE863u;
        instance->instruction_count++;
        return 1;
    case 0x0000E863u: /* 8D 72 43 STA $4372 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xE866u;
        instance->instruction_count++;
        return 1;
    case 0x0000E866u: /* 8E 75 43 STX $4375 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xE869u;
        instance->instruction_count++;
        return 1;
    case 0x0000E869u: /* AD 0C 1D LDA $1D0C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Cu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE86Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000E86Cu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xE86Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000E86Fu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xE871u;
        instance->instruction_count++;
        return 1;
    case 0x0400E871u: /* A9 80 LDA #$80 */
        byte = 0x80u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xE873u;
        instance->instruction_count++;
        return 1;
    case 0x0400E873u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xE876u;
        instance->instruction_count++;
        return 1;
    case 0x0400E876u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xE878u;
        instance->instruction_count++;
        return 1;
    case 0x0000E878u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xE879u;
        instance->instruction_count++;
        return 1;
    case 0x0000E879u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xE87Au;
        instance->instruction_count++;
        return 1;
    case 0x0000E87Au: /* 6D 08 1D ADC $1D08 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xE87Du;
        instance->instruction_count++;
        return 1;
    case 0x0000E87Du: /* 8D 08 1D STA $1D08 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xE880u;
        instance->instruction_count++;
        return 1;
    case 0x0000E880u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xE881u;
        instance->instruction_count++;
        return 1;
    case 0x0000E881u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xE882u;
        instance->instruction_count++;
        return 1;
    case 0x0000E882u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xE883u;
        instance->instruction_count++;
        return 1;
    case 0x0000E883u: /* 6D 0C 1D ADC $1D0C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Cu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xE886u;
        instance->instruction_count++;
        return 1;
    case 0x0000E886u: /* 8D 0C 1D STA $1D0C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xE889u;
        instance->instruction_count++;
        return 1;
    case 0x0000E889u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0000EA40u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEA42u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA42u: /* C2 10 REP #$10 */
        instance->cpu.p &= (uint8_t)~0x10u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEA44u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA44u: /* 86 23 STX $23 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xEA46u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA46u: /* 85 25 STA $25 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x25u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEA48u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA48u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xEA49u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA49u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xEA4Au;
        instance->instruction_count++;
        return 1;
    case 0x0400EA4Au: /* 29 8F AND #$8F */
        byte = 0x8Fu;
        byte = (uint8_t)((tg_acc8(instance)) & byte);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEA4Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA4Cu: /* 8D 15 21 STA $2115 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2115u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEA4Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA4Fu: /* 8C 16 21 STY $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xEA52u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA52u: /* 8A TXA */
        tg_set_acc8(instance, (uint8_t)instance->cpu.x);
        tg_set_nz8(instance, (uint8_t)instance->cpu.x);
        instance->cpu.pc = 0xEA53u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA53u: /* 0A ASL A */
        byte = tg_acc8(instance);
        tg_set_flag(instance, TG_P_C, (byte & 0x80u) != 0u);
        byte = (uint8_t)(byte << 1);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEA54u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA54u: /* 30 17 BMI $00:EA6D */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xEA6Du : 0xEA56u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA56u: /* 20 8E EA JSR $EA8E */
        if (!tg_push16(instance, 0xEA58u)) return 0;
        instance->cpu.pc = 0xEA8Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA59u: /* B0 30 BCS $00:EA8B */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xEA8Bu : 0xEA5Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA5Bu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEA5Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA5Eu: /* 20 9B EA JSR $EA9B */
        if (!tg_push16(instance, 0xEA60u)) return 0;
        instance->cpu.pc = 0xEA9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA61u: /* 8D 19 21 STA $2119 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2119u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEA64u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA64u: /* B0 25 BCS $00:EA8B */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xEA8Bu : 0xEA66u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA66u: /* 20 9B EA JSR $EA9B */
        if (!tg_push16(instance, 0xEA68u)) return 0;
        instance->cpu.pc = 0xEA9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA69u: /* 90 F0 BCC $00:EA5B */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xEA5Bu : 0xEA6Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA6Bu: /* 80 1E BRA $00:EA8B */
        instance->cpu.pc = 0xEA8Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA6Du: /* B0 0F BCS $00:EA7E */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xEA7Eu : 0xEA6Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA6Fu: /* 20 8E EA JSR $EA8E */
        if (!tg_push16(instance, 0xEA71u)) return 0;
        instance->cpu.pc = 0xEA8Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA72u: /* B0 17 BCS $00:EA8B */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xEA8Bu : 0xEA74u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA74u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEA77u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA77u: /* 20 9B EA JSR $EA9B */
        if (!tg_push16(instance, 0xEA79u)) return 0;
        instance->cpu.pc = 0xEA9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA7Au: /* 90 F8 BCC $00:EA74 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xEA74u : 0xEA7Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA7Cu: /* 80 0D BRA $00:EA8B */
        instance->cpu.pc = 0xEA8Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA7Eu: /* 20 8E EA JSR $EA8E */
        if (!tg_push16(instance, 0xEA80u)) return 0;
        instance->cpu.pc = 0xEA8Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA81u: /* B0 08 BCS $00:EA8B */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xEA8Bu : 0xEA83u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA83u: /* 8D 19 21 STA $2119 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2119u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEA86u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA86u: /* 20 9B EA JSR $EA9B */
        if (!tg_push16(instance, 0xEA88u)) return 0;
        instance->cpu.pc = 0xEA9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA89u: /* 90 F8 BCC $00:EA83 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xEA83u : 0xEA8Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA8Bu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEA8Du;
        instance->instruction_count++;
        return 1;
    case 0x0000EA8Du: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0000EA8Eu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEA90u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA8Eu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEA90u;
        instance->instruction_count++;
        return 1;
    case 0x0000EA90u: /* 64 20 STZ $20 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0xEA92u;
        instance->instruction_count++;
        return 1;
    case 0x0000EA92u: /* A9 FF 07 LDA #$07FF */
        word = 0x07FFu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEA95u;
        instance->instruction_count++;
        return 1;
    case 0x0000EA95u: /* 85 1E STA $1E */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xEA97u;
        instance->instruction_count++;
        return 1;
    case 0x0000EA97u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEA99u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA99u: /* 64 22 STZ $22 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0xEA9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA9Bu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEA9Du;
        instance->instruction_count++;
        return 1;
    case 0x0400EA9Du: /* C2 10 REP #$10 */
        instance->cpu.p &= (uint8_t)~0x10u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEA9Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA9Fu: /* A5 22 LDA $22 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEAA1u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAA1u: /* D0 61 BNE $00:EB04 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEB04u : 0xEAA3u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAA3u: /* A4 20 LDY $20 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAA5u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAA5u: /* B7 23 LDA [$23],Y */
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEAA7u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAA7u: /* D0 02 BNE $00:EAAB */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEAABu : 0xEAA9u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAA9u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xEAAAu;
        instance->instruction_count++;
        return 1;
    case 0x0400EAAAu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0400EAABu: /* 30 6B BMI $00:EB18 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xEB18u : 0xEAADu;
        instance->instruction_count++;
        return 1;
    case 0x0400EAADu: /* C6 22 DEC $22 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), &byte)) return 0;
        byte = (uint8_t)(byte - 1u);
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), byte)) return 0;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEAAFu;
        instance->instruction_count++;
        return 1;
    case 0x0400EAAFu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAB0u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAB0u: /* C9 40 CMP #$40 */
        byte = 0x40u;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xEAB2u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAB2u: /* 90 26 BCC $00:EADA */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xEADAu : 0xEAB4u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAB4u: /* C9 60 CMP #$60 */
        byte = 0x60u;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xEAB6u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAB6u: /* 90 0F BCC $00:EAC7 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xEAC7u : 0xEAB8u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAB8u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xEAB9u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAB9u: /* B7 23 LDA [$23],Y */
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEABBu;
        instance->instruction_count++;
        return 1;
    case 0x0400EABBu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEABCu;
        instance->instruction_count++;
        return 1;
    case 0x0400EABCu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEABEu;
        instance->instruction_count++;
        return 1;
    case 0x0000EABEu: /* 29 FF 1F AND #$1FFF */
        word = 0x1FFFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAC1u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAC1u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEAC2u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAC2u: /* 69 22 00 ADC #$0022 */
        word = 0x0022u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xEAC5u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAC5u: /* 80 06 BRA $00:EACD */
        instance->cpu.pc = 0xEACDu;
        instance->instruction_count++;
        return 1;
    case 0x0400EAC7u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEAC9u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAC9u: /* 29 1F 00 AND #$001F */
        word = 0x001Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEACCu;
        instance->instruction_count++;
        return 1;
    case 0x0000EACCu: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEACDu;
        instance->instruction_count++;
        return 1;
    case 0x0000EACDu: /* 85 1A STA $1A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xEACFu;
        instance->instruction_count++;
        return 1;
    case 0x0000EACFu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEAD1u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAD1u: /* B7 23 LDA [$23],Y */
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEAD3u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAD3u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAD4u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAD4u: /* 84 20 STY $20 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xEAD6u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAD6u: /* 85 1D STA $1D */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x1Du) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEAD8u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAD8u: /* 80 65 BRA $00:EB3F */
        instance->cpu.pc = 0xEB3Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EADAu: /* C6 22 DEC $22 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), &byte)) return 0;
        byte = (uint8_t)(byte - 1u);
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), byte)) return 0;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEADCu;
        instance->instruction_count++;
        return 1;
    case 0x0400EADCu: /* C9 20 CMP #$20 */
        byte = 0x20u;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xEADEu;
        instance->instruction_count++;
        return 1;
    case 0x0400EADEu: /* 90 0F BCC $00:EAEF */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xEAEFu : 0xEAE0u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAE0u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xEAE1u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAE1u: /* B7 23 LDA [$23],Y */
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEAE3u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAE3u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAE4u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAE4u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEAE6u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAE6u: /* 29 FF 1F AND #$1FFF */
        word = 0x1FFFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAE9u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAE9u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEAEAu;
        instance->instruction_count++;
        return 1;
    case 0x0000EAEAu: /* 69 1E 00 ADC #$001E */
        word = 0x001Eu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xEAEDu;
        instance->instruction_count++;
        return 1;
    case 0x0000EAEDu: /* 80 0F BRA $00:EAFE */
        instance->cpu.pc = 0xEAFEu;
        instance->instruction_count++;
        return 1;
    case 0x0400EAEFu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEAF1u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAF1u: /* 29 1F 00 AND #$001F */
        word = 0x001Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAF4u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAF4u: /* 3A DEC A */
        word = (uint16_t)((instance->cpu.a) - 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAF5u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAF5u: /* 3A DEC A */
        word = (uint16_t)((instance->cpu.a) - 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAF6u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAF6u: /* 10 06 BPL $00:EAFE */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEAFEu : 0xEAF8u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAF8u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEAFAu;
        instance->instruction_count++;
        return 1;
    case 0x0400EAFAu: /* 64 22 STZ $22 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0xEAFCu;
        instance->instruction_count++;
        return 1;
    case 0x0400EAFCu: /* 80 3C BRA $00:EB3A */
        instance->cpu.pc = 0xEB3Au;
        instance->instruction_count++;
        return 1;
    case 0x0000EAFEu: /* 85 1A STA $1A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xEB00u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB00u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEB02u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB02u: /* 80 36 BRA $00:EB3A */
        instance->cpu.pc = 0xEB3Au;
        instance->instruction_count++;
        return 1;
    case 0x0400EB04u: /* 10 4C BPL $00:EB52 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEB52u : 0xEB06u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB06u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEB08u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB08u: /* C6 1A DEC $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB0Au;
        instance->instruction_count++;
        return 1;
    case 0x0000EB0Au: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEB0Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB0Cu: /* 10 02 BPL $00:EB10 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEB10u : 0xEB0Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB0Eu: /* 64 22 STZ $22 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0xEB10u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB10u: /* 49 FF EOR #$FF */
        byte = 0xFFu;
        byte = (uint8_t)((tg_acc8(instance)) ^ byte);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB12u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB12u: /* D0 24 BNE $00:EB38 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEB38u : 0xEB14u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB14u: /* A5 1D LDA $1D */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x1Du) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB16u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB16u: /* 80 27 BRA $00:EB3F */
        instance->cpu.pc = 0xEB3Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB18u: /* E6 22 INC $22 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), &byte)) return 0;
        byte = (uint8_t)(byte + 1u);
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), byte)) return 0;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB1Au;
        instance->instruction_count++;
        return 1;
    case 0x0400EB1Au: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB1Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB1Bu: /* C9 C0 CMP #$C0 */
        byte = 0xC0u;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xEB1Du;
        instance->instruction_count++;
        return 1;
    case 0x0400EB1Du: /* 90 46 BCC $00:EB65 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xEB65u : 0xEB1Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB1Fu: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xEB20u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB20u: /* B7 23 LDA [$23],Y */
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB22u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB22u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB23u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB23u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEB25u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB25u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xEB26u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB26u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xEB27u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB27u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB28u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB28u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB29u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB29u: /* 29 0F 00 AND #$000F */
        word = 0x000Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB2Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000EB2Cu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEB2Du;
        instance->instruction_count++;
        return 1;
    case 0x0000EB2Du: /* 69 03 00 ADC #$0003 */
        word = 0x0003u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xEB30u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB30u: /* 85 1A STA $1A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xEB32u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB32u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xEB33u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB33u: /* 29 FF 03 AND #$03FF */
        word = 0x03FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB36u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB36u: /* 80 3E BRA $00:EB76 */
        instance->cpu.pc = 0xEB76u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB38u: /* A4 20 LDY $20 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB3Au;
        instance->instruction_count++;
        return 1;
    case 0x0400EB3Au: /* B7 23 LDA [$23],Y */
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB3Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB3Cu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB3Du;
        instance->instruction_count++;
        return 1;
    case 0x0400EB3Du: /* 84 20 STY $20 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xEB3Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB3Fu: /* A6 1E LDX $1E */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB41u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB41u: /* 9D B2 07 STA $07B2,X */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x07B2u + instance->cpu.x)), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEB44u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB44u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB45u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB45u: /* 10 03 BPL $00:EB4A */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEB4Au : 0xEB47u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB47u: /* A2 FF 07 LDX #$07FF */
        word = 0x07FFu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB4Au;
        instance->instruction_count++;
        return 1;
    case 0x0400EB4Au: /* 86 1E STX $1E */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xEB4Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB4Cu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEB4Du;
        instance->instruction_count++;
        return 1;
    case 0x0400EB4Du: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0400EB4Eu: /* 86 1C STX $1C */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xEB50u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB50u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEB51u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB51u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0400EB52u: /* A6 1C LDX $1C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB54u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB54u: /* BD B2 07 LDA $07B2,X */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x07B2u + instance->cpu.x)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB57u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB57u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB58u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB58u: /* 10 03 BPL $00:EB5D */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEB5Du : 0xEB5Au;
        instance->instruction_count++;
        return 1;
    case 0x0400EB5Au: /* A2 FF 07 LDX #$07FF */
        word = 0x07FFu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB5Du;
        instance->instruction_count++;
        return 1;
    case 0x0400EB5Du: /* E4 1E CPX $1E */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), &word)) return 0;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0xEB5Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB5Fu: /* D0 ED BNE $00:EB4E */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEB4Eu : 0xEB61u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB61u: /* 64 22 STZ $22 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0xEB63u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB63u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEB64u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB64u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0400EB65u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEB67u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB67u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xEB68u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB68u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB69u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB69u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB6Au;
        instance->instruction_count++;
        return 1;
    case 0x0000EB6Au: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB6Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000EB6Bu: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xEB6Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000EB6Cu: /* 29 01 00 AND #$0001 */
        word = 0x0001u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB6Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000EB6Fu: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB70u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB70u: /* 85 1A STA $1A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xEB72u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB72u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xEB73u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB73u: /* 29 1F 00 AND #$001F */
        word = 0x001Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB76u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB76u: /* 84 20 STY $20 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xEB78u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB78u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xEB79u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB79u: /* 65 1A ADC $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xEB7Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000EB7Bu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEB7Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000EB7Cu: /* 65 1E ADC $1E */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xEB7Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000EB7Eu: /* 29 FF 07 AND #$07FF */
        word = 0x07FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB81u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB81u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xEB82u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB82u: /* A4 1E LDY $1E */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB84u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB84u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEB86u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB86u: /* BD B2 07 LDA $07B2,X */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x07B2u + instance->cpu.x)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB89u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB89u: /* 99 B2 07 STA $07B2,Y */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x07B2u + instance->cpu.y)), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEB8Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB8Cu: /* 85 1D STA $1D */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x1Du) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEB8Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB8Eu: /* 80 06 BRA $00:EB96 */
        instance->cpu.pc = 0xEB96u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB90u: /* BD B2 07 LDA $07B2,X */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x07B2u + instance->cpu.x)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB93u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB93u: /* 99 B2 07 STA $07B2,Y */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x07B2u + instance->cpu.y)), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEB96u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB96u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB97u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB97u: /* 10 03 BPL $00:EB9C */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEB9Cu : 0xEB99u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB99u: /* A2 FF 07 LDX #$07FF */
        word = 0x07FFu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB9Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB9Cu: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB9Du;
        instance->instruction_count++;
        return 1;
    case 0x0400EB9Du: /* 10 03 BPL $00:EBA2 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEBA2u : 0xEB9Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB9Fu: /* A0 FF 07 LDY #$07FF */
        word = 0x07FFu;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBA2u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBA2u: /* C6 1A DEC $1A */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &byte)) return 0;
        byte = (uint8_t)(byte - 1u);
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), byte)) return 0;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBA4u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBA4u: /* 10 EA BPL $00:EB90 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEB90u : 0xEBA6u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBA6u: /* A5 1D LDA $1D */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x1Du) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBA8u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBA8u: /* A6 1E LDX $1E */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBAAu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBAAu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBABu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBABu: /* 10 03 BPL $00:EBB0 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEBB0u : 0xEBADu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBADu: /* A2 FF 07 LDX #$07FF */
        word = 0x07FFu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBB0u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBB0u: /* 86 1C STX $1C */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xEBB2u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBB2u: /* 84 1E STY $1E */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xEBB4u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBB4u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEBB5u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBB5u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0400EBB6u: /* C2 30 REP #$30 */
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEBB8u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBB8u: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBBBu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBBBu: /* A9 AA BB LDA #$BBAA */
        word = 0xBBAAu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBBEu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBBEu: /* CD 40 21 CMP $2140 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xEBC1u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBC1u: /* D0 FB BNE $00:EBBE */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEBBEu : 0xEBC3u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBC3u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEBC5u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBC5u: /* A9 CC LDA #$CC */
        byte = 0xCCu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBC7u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBC7u: /* 48 PHA */
        if (!tg_push8(instance, (uint8_t)tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEBC8u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBC8u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEBCAu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBCAu: /* B7 3A LDA [$3A],Y */
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x3Au) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read16(instance, address, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBCCu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBCCu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xEBCDu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBCDu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBCEu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBCEu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBCFu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBCFu: /* B7 3A LDA [$3A],Y */
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x3Au) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read16(instance, address, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBD1u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBD1u: /* 8D 42 21 STA $2142 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2142u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xEBD4u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBD4u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBD5u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBD5u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBD6u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBD6u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEBD8u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBD8u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBDAu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBDAu: /* E0 01 00 CPX #$0001 */
        word = 0x0001u;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0xEBDDu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBDDu: /* 2A ROL A */
        byte = tg_acc8(instance);
        word = (uint16_t)tg_flag(instance, TG_P_C);
        tg_set_flag(instance, TG_P_C, (byte & 0x80u) != 0u);
        byte = (uint8_t)((byte << 1) | word);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBDEu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBDEu: /* 8D 41 21 STA $2141 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEBE1u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBE1u: /* 69 7F ADC #$7F */
        byte = 0x7Fu;
        tg_adc8(instance, byte);
        instance->cpu.pc = 0xEBE3u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBE3u: /* 68 PLA */
        if (!tg_pull8(instance, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBE4u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBE4u: /* 8D 40 21 STA $2140 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEBE7u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBE7u: /* CD 40 21 CMP $2140 */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xEBEAu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBEAu: /* D0 FB BNE $00:EBE7 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEBE7u : 0xEBECu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBECu: /* 50 1D BVC $00:EC0B */
        instance->cpu.pc = !tg_flag(instance, TG_P_V) ? 0xEC0Bu : 0xEBEEu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBEEu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBF0u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBF0u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xEBF1u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBF1u: /* B7 3A LDA [$3A],Y */
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x3Au) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBF3u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBF3u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xEBF4u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBF4u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBF5u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBF5u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEBF7u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBF7u: /* 8D 40 21 STA $2140 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xEBFAu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBFAu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEBFCu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBFCu: /* CD 40 21 CMP $2140 */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xEBFFu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBFFu: /* D0 FB BNE $00:EBFC */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEBFCu : 0xEC01u;
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
