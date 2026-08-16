/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_002A(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x0000A89Eu: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA89Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000A89Fu: /* AD F4 1F LDA $1FF4 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF4u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8A2u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8A2u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA8A3u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8A3u: /* 69 07 00 ADC #$0007 */
        word = 0x0007u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA8A6u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8A6u: /* 8D F7 1E STA $1EF7 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF7u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA8A9u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8A9u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8AAu;
        instance->instruction_count++;
        return 1;
    case 0x0000A8AAu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8ABu;
        instance->instruction_count++;
        return 1;
    case 0x0000A8ABu: /* 8D F9 1E STA $1EF9 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF9u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA8AEu;
        instance->instruction_count++;
        return 1;
    case 0x0000A8AEu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8AFu;
        instance->instruction_count++;
        return 1;
    case 0x0000A8AFu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA8B0u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8B0u: /* 6D F9 1E ADC $1EF9 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF9u), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA8B3u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8B3u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA8B4u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8B4u: /* 6D F7 1E ADC $1EF7 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF7u), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA8B7u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8B7u: /* 8D F4 1F STA $1FF4 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF4u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA8BAu;
        instance->instruction_count++;
        return 1;
    case 0x0000A8BAu: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xA8BBu;
        instance->instruction_count++;
        return 1;
    case 0x0000A8BBu: /* 4D F4 1F EOR $1FF4 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF4u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8BEu;
        instance->instruction_count++;
        return 1;
    case 0x0000A8BEu: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8C1u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8C1u: /* 8D F7 1E STA $1EF7 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF7u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA8C4u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8C4u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8C5u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8C5u: /* F0 16 BEQ $00:A8DD */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xA8DDu : 0xA8C7u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8C7u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8C8u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8C8u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA8CAu;
        instance->instruction_count++;
        return 1;
    case 0x0400A8CAu: /* 8D 1B 21 STA $211B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA8CDu;
        instance->instruction_count++;
        return 1;
    case 0x0400A8CDu: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xA8CEu;
        instance->instruction_count++;
        return 1;
    case 0x0400A8CEu: /* 8D 1B 21 STA $211B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA8D1u;
        instance->instruction_count++;
        return 1;
    case 0x0400A8D1u: /* AD F7 1E LDA $1EF7 */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF7u), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA8D4u;
        instance->instruction_count++;
        return 1;
    case 0x0400A8D4u: /* 8D 1C 21 STA $211C */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA8D7u;
        instance->instruction_count++;
        return 1;
    case 0x0400A8D7u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA8D9u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8D9u: /* AD 35 21 LDA $2135 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2135u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8DCu;
        instance->instruction_count++;
        return 1;
    case 0x0000A8DCu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0000A8DDu: /* AD F7 1E LDA $1EF7 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF7u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8E0u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8E0u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0000A8E1u: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8E4u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8E4u: /* BF 00 58 7E LDA $7E5800,X */
        if (!tg_bus_read16(instance, ((0x7E5800u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8E8u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8E8u: /* 29 FF 7F AND #$7FFF */
        word = 0x7FFFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8EBu;
        instance->instruction_count++;
        return 1;
    case 0x0000A8EBu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xA8ECu;
        instance->instruction_count++;
        return 1;
    case 0x0000A8ECu: /* B9 3F 9B LDA $9B3F,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x9B3Fu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8EFu;
        instance->instruction_count++;
        return 1;
    case 0x0000A8EFu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xA8F0u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8F0u: /* B9 41 01 LDA $0141,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0141u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8F3u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8F3u: /* 8D AA 1E STA $1EAA */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EAAu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA8F6u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8F6u: /* 8D AC 1E STA $1EAC */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EACu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA8F9u;
        instance->instruction_count++;
        return 1;
    case 0x0000A8F9u: /* B9 3F 01 LDA $013F,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x013Fu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA8FCu;
        instance->instruction_count++;
        return 1;
    case 0x0000A8FCu: /* 8D A6 1E STA $1EA6 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA6u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA8FFu;
        instance->instruction_count++;
        return 1;
    case 0x0000A8FFu: /* 8D A8 1E STA $1EA8 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA8u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA902u;
        instance->instruction_count++;
        return 1;
    case 0x0000A902u: /* BF 00 58 7E LDA $7E5800,X */
        if (!tg_bus_read16(instance, ((0x7E5800u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA906u;
        instance->instruction_count++;
        return 1;
    case 0x0000A906u: /* 29 FF 7F AND #$7FFF */
        word = 0x7FFFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA909u;
        instance->instruction_count++;
        return 1;
    case 0x0000A909u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xA90Au;
        instance->instruction_count++;
        return 1;
    case 0x0000A90Au: /* B9 3F 9B LDA $9B3F,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x9B3Fu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA90Du;
        instance->instruction_count++;
        return 1;
    case 0x0000A90Du: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xA90Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000A90Eu: /* BF 00 64 7E LDA $7E6400,X */
        if (!tg_bus_read16(instance, ((0x7E6400u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA912u;
        instance->instruction_count++;
        return 1;
    case 0x0000A912u: /* D0 03 BNE $00:A917 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xA917u : 0xA914u;
        instance->instruction_count++;
        return 1;
    case 0x0000A914u: /* 4C A4 A9 JMP $A9A4 */
        instance->cpu.pc = 0xA9A4u;
        instance->instruction_count++;
        return 1;
    case 0x0000A917u: /* 30 FB BMI $00:A914 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xA914u : 0xA919u;
        instance->instruction_count++;
        return 1;
    case 0x0000A919u: /* 89 00 01 BIT #$0100 */
        word = 0x0100u;
        tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
        instance->cpu.pc = 0xA91Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000A91Cu: /* F0 09 BEQ $00:A927 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xA927u : 0xA91Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000A91Eu: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA921u;
        instance->instruction_count++;
        return 1;
    case 0x0000A921u: /* 49 FF FF EOR #$FFFF */
        word = 0xFFFFu;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA924u;
        instance->instruction_count++;
        return 1;
    case 0x0000A924u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA925u;
        instance->instruction_count++;
        return 1;
    case 0x0000A925u: /* 80 03 BRA $00:A92A */
        instance->cpu.pc = 0xA92Au;
        instance->instruction_count++;
        return 1;
    case 0x0000A927u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA92Au;
        instance->instruction_count++;
        return 1;
    case 0x0000A92Au: /* 30 07 BMI $00:A933 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xA933u : 0xA92Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000A92Cu: /* D9 41 01 CMP $0141,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0141u + instance->cpu.y)), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xA92Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000A92Fu: /* B0 73 BCS $00:A9A4 */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xA9A4u : 0xA931u;
        instance->instruction_count++;
        return 1;
    case 0x0000A931u: /* 80 05 BRA $00:A938 */
        instance->cpu.pc = 0xA938u;
        instance->instruction_count++;
        return 1;
    case 0x0000A933u: /* D9 3F 01 CMP $013F,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x013Fu + instance->cpu.y)), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xA936u;
        instance->instruction_count++;
        return 1;
    case 0x0000A936u: /* 90 6C BCC $00:A9A4 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xA9A4u : 0xA938u;
        instance->instruction_count++;
        return 1;
    case 0x0000A938u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xA939u;
        instance->instruction_count++;
        return 1;
    case 0x0000A939u: /* E9 40 00 SBC #$0040 */
        word = 0x0040u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xA93Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000A93Cu: /* 85 1A STA $1A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA93Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000A93Eu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA93Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000A93Fu: /* 69 80 00 ADC #$0080 */
        word = 0x0080u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA942u;
        instance->instruction_count++;
        return 1;
    case 0x0000A942u: /* 85 1C STA $1C */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA944u;
        instance->instruction_count++;
        return 1;
    case 0x0000A944u: /* 9C A2 1E STZ $1EA2 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA2u), 0u)) return 0;
        instance->cpu.pc = 0xA947u;
        instance->instruction_count++;
        return 1;
    case 0x0000A947u: /* 9C A4 1E STZ $1EA4 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA4u), 0u)) return 0;
        instance->cpu.pc = 0xA94Au;
        instance->instruction_count++;
        return 1;
    case 0x0000A94Au: /* B9 3F 01 LDA $013F,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x013Fu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA94Du;
        instance->instruction_count++;
        return 1;
    case 0x0000A94Du: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xA94Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000A94Eu: /* ED A6 1E SBC $1EA6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA6u), &word)) return 0;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xA951u;
        instance->instruction_count++;
        return 1;
    case 0x0000A951u: /* 30 03 BMI $00:A956 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xA956u : 0xA953u;
        instance->instruction_count++;
        return 1;
    case 0x0000A953u: /* 8D A2 1E STA $1EA2 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA2u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA956u;
        instance->instruction_count++;
        return 1;
    case 0x0000A956u: /* AD AA 1E LDA $1EAA */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EAAu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA959u;
        instance->instruction_count++;
        return 1;
    case 0x0000A959u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xA95Au;
        instance->instruction_count++;
        return 1;
    case 0x0000A95Au: /* E5 1A SBC $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xA95Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000A95Cu: /* 30 08 BMI $00:A966 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xA966u : 0xA95Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000A95Eu: /* CD A2 1E CMP $1EA2 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA2u), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xA961u;
        instance->instruction_count++;
        return 1;
    case 0x0000A961u: /* 90 03 BCC $00:A966 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xA966u : 0xA963u;
        instance->instruction_count++;
        return 1;
    case 0x0000A963u: /* 8D A2 1E STA $1EA2 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA2u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA966u;
        instance->instruction_count++;
        return 1;
    case 0x0000A966u: /* A5 1C LDA $1C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA968u;
        instance->instruction_count++;
        return 1;
    case 0x0000A968u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xA969u;
        instance->instruction_count++;
        return 1;
    case 0x0000A969u: /* ED A6 1E SBC $1EA6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA6u), &word)) return 0;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xA96Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000A96Cu: /* 30 03 BMI $00:A971 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xA971u : 0xA96Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000A96Eu: /* 8D A4 1E STA $1EA4 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA4u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA971u;
        instance->instruction_count++;
        return 1;
    case 0x0000A971u: /* AD AA 1E LDA $1EAA */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EAAu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA974u;
        instance->instruction_count++;
        return 1;
    case 0x0000A974u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xA975u;
        instance->instruction_count++;
        return 1;
    case 0x0000A975u: /* F9 41 01 SBC $0141,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0141u + instance->cpu.y)), &word)) return 0;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xA978u;
        instance->instruction_count++;
        return 1;
    case 0x0000A978u: /* 30 08 BMI $00:A982 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xA982u : 0xA97Au;
        instance->instruction_count++;
        return 1;
    case 0x0000A97Au: /* CD A4 1E CMP $1EA4 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA4u), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xA97Du;
        instance->instruction_count++;
        return 1;
    case 0x0000A97Du: /* 90 03 BCC $00:A982 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xA982u : 0xA97Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000A97Fu: /* 8D A4 1E STA $1EA4 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA4u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA982u;
        instance->instruction_count++;
        return 1;
    case 0x0000A982u: /* AD A2 1E LDA $1EA2 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA2u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA985u;
        instance->instruction_count++;
        return 1;
    case 0x0000A985u: /* CD A4 1E CMP $1EA4 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA4u), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xA988u;
        instance->instruction_count++;
        return 1;
    case 0x0000A988u: /* B0 0D BCS $00:A997 */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xA997u : 0xA98Au;
        instance->instruction_count++;
        return 1;
    case 0x0000A98Au: /* B9 3F 01 LDA $013F,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x013Fu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA98Du;
        instance->instruction_count++;
        return 1;
    case 0x0000A98Du: /* 8D A8 1E STA $1EA8 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA8u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA990u;
        instance->instruction_count++;
        return 1;
    case 0x0000A990u: /* A5 1A LDA $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA992u;
        instance->instruction_count++;
        return 1;
    case 0x0000A992u: /* 8D AC 1E STA $1EAC */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EACu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA995u;
        instance->instruction_count++;
        return 1;
    case 0x0000A995u: /* 80 25 BRA $00:A9BC */
        instance->cpu.pc = 0xA9BCu;
        instance->instruction_count++;
        return 1;
    case 0x0000A997u: /* A5 1C LDA $1C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA999u;
        instance->instruction_count++;
        return 1;
    case 0x0000A999u: /* 8D A8 1E STA $1EA8 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA8u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA99Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000A99Cu: /* B9 41 01 LDA $0141,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0141u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA99Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000A99Fu: /* 8D AC 1E STA $1EAC */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EACu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA9A2u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9A2u: /* 80 18 BRA $00:A9BC */
        instance->cpu.pc = 0xA9BCu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9A4u: /* BF 00 58 7E LDA $7E5800,X */
        if (!tg_bus_read16(instance, ((0x7E5800u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9A8u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9A8u: /* 29 FF 7F AND #$7FFF */
        word = 0x7FFFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9ABu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9ABu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xA9ACu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9ACu: /* B9 3F 9B LDA $9B3F,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x9B3Fu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9AFu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9AFu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xA9B0u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9B0u: /* B9 3F 01 LDA $013F,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x013Fu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9B3u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9B3u: /* 8D A8 1E STA $1EA8 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA8u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA9B6u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9B6u: /* B9 41 01 LDA $0141,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0141u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9B9u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9B9u: /* 8D AC 1E STA $1EAC */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EACu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA9BCu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9BCu: /* AD A8 1E LDA $1EA8 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA8u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9BFu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9BFu: /* CD A6 1E CMP $1EA6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA6u), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xA9C2u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9C2u: /* 10 0C BPL $00:A9D0 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xA9D0u : 0xA9C4u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9C4u: /* AD A6 1E LDA $1EA6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA6u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9C7u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9C7u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xA9C8u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9C8u: /* E9 0F 00 SBC #$000F */
        word = 0x000Fu;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xA9CBu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9CBu: /* CD A8 1E CMP $1EA8 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA8u), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xA9CEu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9CEu: /* 10 03 BPL $00:A9D3 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xA9D3u : 0xA9D0u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9D0u: /* AD A8 1E LDA $1EA8 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA8u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9D3u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9D3u: /* 8D A6 1E STA $1EA6 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA6u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA9D6u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9D6u: /* AD AC 1E LDA $1EAC */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EACu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9D9u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9D9u: /* CD AA 1E CMP $1EAA */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EAAu), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xA9DCu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9DCu: /* F0 14 BEQ $00:A9F2 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xA9F2u : 0xA9DEu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9DEu: /* 30 0C BMI $00:A9EC */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xA9ECu : 0xA9E0u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9E0u: /* AD AA 1E LDA $1EAA */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EAAu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9E3u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9E3u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA9E4u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9E4u: /* 69 0F 00 ADC #$000F */
        word = 0x000Fu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA9E7u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9E7u: /* CD AC 1E CMP $1EAC */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EACu), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xA9EAu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9EAu: /* 30 03 BMI $00:A9EF */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xA9EFu : 0xA9ECu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9ECu: /* AD AC 1E LDA $1EAC */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EACu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9EFu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9EFu: /* 8D AA 1E STA $1EAA */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EAAu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA9F2u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9F2u: /* AD A8 1E LDA $1EA8 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA8u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9F5u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9F5u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9F6u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9F6u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9F9u;
        instance->instruction_count++;
        return 1;
    case 0x0000A9F9u: /* 85 1A STA $1A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA9FBu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9FBu: /* AD AC 1E LDA $1EAC */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EACu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9FEu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9FEu: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA9FFu;
        instance->instruction_count++;
        return 1;
    case 0x0000A9FFu: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xAA00u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA00u: /* 29 00 FF AND #$FF00 */
        word = 0xFF00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA03u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA03u: /* 05 1A ORA $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA05u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA05u: /* 9F 00 70 7E STA $7E7000,X */
        if (!tg_bus_store16(instance, ((0x7E7000u + instance->cpu.x) & 0xFFFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xAA09u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA09u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA0Au;
        instance->instruction_count++;
        return 1;
    case 0x0000AA0Au: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA0Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000AA0Bu: /* EC 00 02 CPX $0200 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0200u), &word)) return 0;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0xAA0Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000AA0Eu: /* F0 03 BEQ $00:AA13 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xAA13u : 0xAA10u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA10u: /* 4C 02 A9 JMP $A902 */
        instance->cpu.pc = 0xA902u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA13u: /* A9 00 80 LDA #$8000 */
        word = 0x8000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA16u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA16u: /* 8D A6 1E STA $1EA6 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA6u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xAA19u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA19u: /* A9 FF 7F LDA #$7FFF */
        word = 0x7FFFu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA1Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000AA1Cu: /* 8D AA 1E STA $1EAA */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EAAu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xAA1Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000AA1Fu: /* AE 00 02 LDX $0200 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0200u), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA22u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA22u: /* BF FE 6F 7E LDA $7E6FFE,X */
        if (!tg_bus_read16(instance, ((0x7E6FFEu + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA26u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA26u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xAA27u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA27u: /* 29 00 FF AND #$FF00 */
        word = 0xFF00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA2Au;
        instance->instruction_count++;
        return 1;
    case 0x0000AA2Au: /* C9 00 80 CMP #$8000 */
        word = 0x8000u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xAA2Du;
        instance->instruction_count++;
        return 1;
    case 0x0000AA2Du: /* 6A ROR A */
        word = instance->cpu.a;
        address = (uint32_t)tg_flag(instance, TG_P_C);
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)((word >> 1) | (address ? 0x8000u : 0u));
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA2Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000AA2Eu: /* CD A6 1E CMP $1EA6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA6u), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xAA31u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA31u: /* 30 03 BMI $00:AA36 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xAA36u : 0xAA33u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA33u: /* 8D A6 1E STA $1EA6 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA6u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xAA36u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA36u: /* AD A6 1E LDA $1EA6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA6u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA39u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA39u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA3Au;
        instance->instruction_count++;
        return 1;
    case 0x0000AA3Au: /* 29 00 FF AND #$FF00 */
        word = 0xFF00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA3Du;
        instance->instruction_count++;
        return 1;
    case 0x0000AA3Du: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xAA3Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000AA3Eu: /* 85 1A STA $1A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xAA40u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA40u: /* AD A6 1E LDA $1EA6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA6u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA43u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA43u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xAA44u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA44u: /* E9 2C 01 SBC #$012C */
        word = 0x012Cu;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xAA47u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA47u: /* 8D A6 1E STA $1EA6 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EA6u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xAA4Au;
        instance->instruction_count++;
        return 1;
    case 0x0000AA4Au: /* BF FE 6F 7E LDA $7E6FFE,X */
        if (!tg_bus_read16(instance, ((0x7E6FFEu + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA4Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000AA4Eu: /* 29 00 FF AND #$FF00 */
        word = 0xFF00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA51u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA51u: /* C9 00 80 CMP #$8000 */
        word = 0x8000u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xAA54u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA54u: /* 6A ROR A */
        word = instance->cpu.a;
        address = (uint32_t)tg_flag(instance, TG_P_C);
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)((word >> 1) | (address ? 0x8000u : 0u));
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA55u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA55u: /* CD AA 1E CMP $1EAA */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EAAu), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xAA58u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA58u: /* 10 03 BPL $00:AA5D */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xAA5Du : 0xAA5Au;
        instance->instruction_count++;
        return 1;
    case 0x0000AA5Au: /* 8D AA 1E STA $1EAA */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EAAu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xAA5Du;
        instance->instruction_count++;
        return 1;
    case 0x0000AA5Du: /* AD AA 1E LDA $1EAA */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EAAu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA60u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA60u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA61u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA61u: /* 29 00 FF AND #$FF00 */
        word = 0xFF00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA64u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA64u: /* 05 1A ORA $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA66u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA66u: /* 9F FE 6F 7E STA $7E6FFE,X */
        if (!tg_bus_store16(instance, ((0x7E6FFEu + instance->cpu.x) & 0xFFFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xAA6Au;
        instance->instruction_count++;
        return 1;
    case 0x0000AA6Au: /* AD AA 1E LDA $1EAA */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EAAu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA6Du;
        instance->instruction_count++;
        return 1;
    case 0x0000AA6Du: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xAA6Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000AA6Eu: /* 69 2C 01 ADC #$012C */
        word = 0x012Cu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xAA71u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA71u: /* 8D AA 1E STA $1EAA */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EAAu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xAA74u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA74u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA75u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA75u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAA76u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA76u: /* D0 AA BNE $00:AA22 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xAA22u : 0xAA78u;
        instance->instruction_count++;
        return 1;
    case 0x0000AA78u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0000ABFCu: /* C2 30 REP #$30 */
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xABFEu;
        instance->instruction_count++;
        return 1;
    case 0x0000ABFEu: /* AD DB 1E LDA $1EDB */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EDBu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xAC01u;
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
