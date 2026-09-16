/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_0030(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x0000C002u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xC003u;
        instance->instruction_count++;
        return 1;
    case 0x0000C003u: /* B9 00 00 LDA $0000,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC006u;
        instance->instruction_count++;
        return 1;
    case 0x0000C006u: /* 9F 00 4C 7E STA $7E4C00,X */
        if (!tg_bus_store16(instance, ((0x7E4C00u + instance->cpu.x) & 0xFFFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC00Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C00Au: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC00Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C00Bu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC00Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C00Cu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC00Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C00Du: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC00Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C00Eu: /* C6 20 DEC $20 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC010u;
        instance->instruction_count++;
        return 1;
    case 0x0000C010u: /* 10 F1 BPL $00:C003 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xC003u : 0xC012u;
        instance->instruction_count++;
        return 1;
    case 0x0000C012u: /* 80 24 BRA $00:C038 */
        instance->cpu.pc = 0xC038u;
        instance->instruction_count++;
        return 1;
    case 0x0000C014u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC015u;
        instance->instruction_count++;
        return 1;
    case 0x0000C015u: /* 84 1E STY $1E */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xC017u;
        instance->instruction_count++;
        return 1;
    case 0x0000C017u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xC018u;
        instance->instruction_count++;
        return 1;
    case 0x0000C018u: /* 49 FF FF EOR #$FFFF */
        word = 0xFFFFu;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC01Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C01Bu: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC01Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C01Cu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC01Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C01Du: /* 29 FF 01 AND #$01FF */
        word = 0x01FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC020u;
        instance->instruction_count++;
        return 1;
    case 0x0000C020u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xC021u;
        instance->instruction_count++;
        return 1;
    case 0x0000C021u: /* B9 91 85 LDA $8591,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8591u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC024u;
        instance->instruction_count++;
        return 1;
    case 0x0000C024u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xC025u;
        instance->instruction_count++;
        return 1;
    case 0x0000C025u: /* B9 00 00 LDA $0000,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC028u;
        instance->instruction_count++;
        return 1;
    case 0x0000C028u: /* 49 FF FF EOR #$FFFF */
        word = 0xFFFFu;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC02Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C02Bu: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC02Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C02Cu: /* 9F 00 4C 7E STA $7E4C00,X */
        if (!tg_bus_store16(instance, ((0x7E4C00u + instance->cpu.x) & 0xFFFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC030u;
        instance->instruction_count++;
        return 1;
    case 0x0000C030u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC031u;
        instance->instruction_count++;
        return 1;
    case 0x0000C031u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC032u;
        instance->instruction_count++;
        return 1;
    case 0x0000C032u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC033u;
        instance->instruction_count++;
        return 1;
    case 0x0000C033u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC034u;
        instance->instruction_count++;
        return 1;
    case 0x0000C034u: /* C6 20 DEC $20 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC036u;
        instance->instruction_count++;
        return 1;
    case 0x0000C036u: /* 10 ED BPL $00:C025 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xC025u : 0xC038u;
        instance->instruction_count++;
        return 1;
    case 0x0000C038u: /* C6 1C DEC $1C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC03Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C03Au: /* 10 AF BPL $00:BFEB */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xBFEBu : 0xC03Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C03Cu: /* A5 1A LDA $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC03Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C03Eu: /* 85 1C STA $1C */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC040u;
        instance->instruction_count++;
        return 1;
    case 0x0000C040u: /* 64 1E STZ $1E */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0xC042u;
        instance->instruction_count++;
        return 1;
    case 0x0000C042u: /* A0 00 58 LDY #$5800 */
        word = 0x5800u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC045u;
        instance->instruction_count++;
        return 1;
    case 0x0000C045u: /* A6 26 LDX $26 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x26u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC047u;
        instance->instruction_count++;
        return 1;
    case 0x0000C047u: /* BD 00 00 LDA $0000,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC04Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C04Au: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC04Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C04Bu: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xC04Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C04Cu: /* 8B PHB */
        if (!tg_push8(instance, instance->cpu.dbr)) return 0;
        instance->cpu.pc = 0xC04Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C04Du: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC04Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C04Eu: /* 29 FF 01 AND #$01FF */
        word = 0x01FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC051u;
        instance->instruction_count++;
        return 1;
    case 0x0000C051u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC052u;
        instance->instruction_count++;
        return 1;
    case 0x0000C052u: /* BD 45 85 LDA $8545,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8545u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC055u;
        instance->instruction_count++;
        return 1;
    case 0x0000C055u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC056u;
        instance->instruction_count++;
        return 1;
    case 0x0000C056u: /* A9 3F 00 LDA #$003F */
        word = 0x003Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC059u;
        instance->instruction_count++;
        return 1;
    case 0x0000C059u: /* 54 7E 0C MVN $7E,$0C */
        instance->cpu.dbr = 0x7Eu;
        address = ((uint32_t)0x0Cu << 16) | (instance->cpu.x & 0xFFFFu);
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        address = ((uint32_t)0x7Eu << 16) | (instance->cpu.y & 0xFFFFu);
        if (!tg_bus_write8(instance, address, byte)) return 0;
        instance->cpu.x = (uint16_t)(instance->cpu.x + 1u);
        instance->cpu.y = (uint16_t)(instance->cpu.y + 1u);
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)(instance->cpu.a - 1u);
        instance->cpu.pc = word != 0u ? 0xC059u : 0xC05Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C05Cu: /* AB PLB */
        if (!tg_pull8(instance, &byte)) return 0;
        instance->cpu.dbr = byte;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC05Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C05Du: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC05Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C05Eu: /* C6 1C DEC $1C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC060u;
        instance->instruction_count++;
        return 1;
    case 0x0000C060u: /* 10 E5 BPL $00:C047 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xC047u : 0xC062u;
        instance->instruction_count++;
        return 1;
    case 0x0000C062u: /* AE 10 1F LDX $1F10 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F10u), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC065u;
        instance->instruction_count++;
        return 1;
    case 0x0000C065u: /* BD 41 85 LDA $8541,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8541u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC068u;
        instance->instruction_count++;
        return 1;
    case 0x0000C068u: /* 29 00 E0 AND #$E000 */
        word = 0xE000u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC06Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C06Bu: /* 85 24 STA $24 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x24u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC06Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C06Du: /* A5 1A LDA $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC06Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C06Fu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC070u;
        instance->instruction_count++;
        return 1;
    case 0x0000C070u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC071u;
        instance->instruction_count++;
        return 1;
    case 0x0000C071u: /* 85 1C STA $1C */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC073u;
        instance->instruction_count++;
        return 1;
    case 0x0000C073u: /* A2 00 64 LDX #$6400 */
        word = 0x6400u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC076u;
        instance->instruction_count++;
        return 1;
    case 0x0000C076u: /* A4 28 LDY $28 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x28u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC078u;
        instance->instruction_count++;
        return 1;
    case 0x0000C078u: /* B9 00 00 LDA $0000,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC07Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C07Bu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC07Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C07Cu: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC07Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C07Du: /* 29 00 FF AND #$FF00 */
        word = 0xFF00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC080u;
        instance->instruction_count++;
        return 1;
    case 0x0000C080u: /* 85 EF STA $EF */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xEFu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC082u;
        instance->instruction_count++;
        return 1;
    case 0x0000C082u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC083u;
        instance->instruction_count++;
        return 1;
    case 0x0000C083u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xC084u;
        instance->instruction_count++;
        return 1;
    case 0x0000C084u: /* 29 00 FF AND #$FF00 */
        word = 0xFF00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC087u;
        instance->instruction_count++;
        return 1;
    case 0x0000C087u: /* 85 ED STA $ED */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xEDu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC089u;
        instance->instruction_count++;
        return 1;
    case 0x0000C089u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC08Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C08Au: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC08Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C08Bu: /* B9 00 00 LDA $0000,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC08Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C08Eu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC08Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C08Fu: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC090u;
        instance->instruction_count++;
        return 1;
    case 0x0000C090u: /* 29 00 FF AND #$FF00 */
        word = 0xFF00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC093u;
        instance->instruction_count++;
        return 1;
    case 0x0000C093u: /* 85 F3 STA $F3 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xF3u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC095u;
        instance->instruction_count++;
        return 1;
    case 0x0000C095u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC096u;
        instance->instruction_count++;
        return 1;
    case 0x0000C096u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xC097u;
        instance->instruction_count++;
        return 1;
    case 0x0000C097u: /* 29 00 FF AND #$FF00 */
        word = 0xFF00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC09Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C09Au: /* 85 F1 STA $F1 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xF1u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC09Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C09Cu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC09Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C09Du: /* B9 00 00 LDA $0000,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0A0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0A0u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0A1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0A1u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0A2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0A2u: /* 84 28 STY $28 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x28u) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xC0A4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0A4u: /* 29 00 FF AND #$FF00 */
        word = 0xFF00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0A7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0A7u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0A8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0A8u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0A9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0A9u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0AAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C0AAu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xC0ABu;
        instance->instruction_count++;
        return 1;
    case 0x0000C0ABu: /* A9 0F 00 LDA #$000F */
        word = 0x000Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0AEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C0AEu: /* 85 20 STA $20 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC0B0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0B0u: /* B9 15 86 LDA $8615,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8615u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0B3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0B3u: /* F0 2C BEQ $00:C0E1 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xC0E1u : 0xC0B5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0B5u: /* 24 24 BIT $24 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x24u) & 0xFFFFu), &word)) return 0;
        tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
        tg_set_flag(instance, TG_P_N, (word & 0x8000u) != 0u);
        tg_set_flag(instance, TG_P_V, (word & 0x4000u) != 0u);
        instance->cpu.pc = 0xC0B7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0B7u: /* D0 05 BNE $00:C0BE */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC0BEu : 0xC0B9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0B9u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0BCu;
        instance->instruction_count++;
        return 1;
    case 0x0000C0BCu: /* 80 23 BRA $00:C0E1 */
        instance->cpu.pc = 0xC0E1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0BEu: /* 5A PHY */
        if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xC0BFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C0BFu: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC0C0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0C0u: /* 29 FF 01 AND #$01FF */
        word = 0x01FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0C3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0C3u: /* 85 1E STA $1E */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC0C5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0C5u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0C6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0C6u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xC0C7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0C7u: /* 29 06 00 AND #$0006 */
        word = 0x0006u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0CAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C0CAu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xC0CBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C0CBu: /* B9 ED 00 LDA $00ED,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x00EDu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0CEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C0CEu: /* F0 10 BEQ $00:C0E0 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xC0E0u : 0xC0D0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0D0u: /* 10 0C BPL $00:C0DE */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xC0DEu : 0xC0D2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0D2u: /* 29 00 3E AND #$3E00 */
        word = 0x3E00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0D5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0D5u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xC0D6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0D6u: /* 85 1E STA $1E */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC0D8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0D8u: /* B9 ED 00 LDA $00ED,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x00EDu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0DBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C0DBu: /* 29 00 C0 AND #$C000 */
        word = 0xC000u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0DEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C0DEu: /* 05 1E ORA $1E */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0E0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0E0u: /* 7A PLY */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0E1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0E1u: /* 9F 00 00 7E STA $7E0000,X */
        if (!tg_bus_store16(instance, ((0x7E0000u + instance->cpu.x) & 0xFFFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC0E5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0E5u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0E6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0E6u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0E7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0E7u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0E8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0E8u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0E9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0E9u: /* C6 20 DEC $20 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0EBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C0EBu: /* 10 C3 BPL $00:C0B0 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xC0B0u : 0xC0EDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C0EDu: /* C6 1C DEC $1C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0EFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C0EFu: /* D0 85 BNE $00:C076 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC076u : 0xC0F1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0F1u: /* AB PLB */
        if (!tg_pull8(instance, &byte)) return 0;
        instance->cpu.dbr = byte;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC0F2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0F2u: /* A9 C6 ED LDA #$EDC6 */
        word = 0xEDC6u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC0F5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0F5u: /* 85 23 STA $23 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC0F7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C0F7u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC0F9u;
        instance->instruction_count++;
        return 1;
    case 0x0400C0F9u: /* A9 06 LDA #$06 */
        byte = 0x06u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC0FBu;
        instance->instruction_count++;
        return 1;
    case 0x0400C0FBu: /* 85 25 STA $25 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x25u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC0FDu;
        instance->instruction_count++;
        return 1;
    case 0x0400C0FDu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC0FFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C0FFu: /* AD 06 1F LDA $1F06 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC102u;
        instance->instruction_count++;
        return 1;
    case 0x0000C102u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC103u;
        instance->instruction_count++;
        return 1;
    case 0x0000C103u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC104u;
        instance->instruction_count++;
        return 1;
    case 0x0000C104u: /* BD E4 E0 LDA $E0E4,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE0E4u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC107u;
        instance->instruction_count++;
        return 1;
    case 0x0000C107u: /* 8D 12 01 STA $0112 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0112u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC10Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C10Au: /* 8D 14 01 STA $0114 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0114u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC10Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C10Du: /* 8D 16 01 STA $0116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC110u;
        instance->instruction_count++;
        return 1;
    case 0x0000C110u: /* BD 26 E1 LDA $E126,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE126u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC113u;
        instance->instruction_count++;
        return 1;
    case 0x0000C113u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xC114u;
        instance->instruction_count++;
        return 1;
    case 0x0000C114u: /* FD 24 E1 SBC $E124,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE124u + instance->cpu.x)), &word)) return 0;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xC117u;
        instance->instruction_count++;
        return 1;
    case 0x0000C117u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xC118u;
        instance->instruction_count++;
        return 1;
    case 0x0000C118u: /* BD 24 E1 LDA $E124,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE124u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC11Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C11Bu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC11Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C11Cu: /* 5A PHY */
        if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xC11Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C11Du: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xC11Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C11Eu: /* 20 8E EA JSR $EA8E */
        if (!tg_push16(instance, 0xC120u)) return 0;
        instance->cpu.pc = 0xEA8Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400C121u: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC122u;
        instance->instruction_count++;
        return 1;
    case 0x0400C122u: /* F0 10 BEQ $00:C134 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xC134u : 0xC124u;
        instance->instruction_count++;
        return 1;
    case 0x0400C124u: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xC125u;
        instance->instruction_count++;
        return 1;
    case 0x0400C125u: /* 20 9B EA JSR $EA9B */
        if (!tg_push16(instance, 0xC127u)) return 0;
        instance->cpu.pc = 0xEA9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400C128u: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC129u;
        instance->instruction_count++;
        return 1;
    case 0x0400C129u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC12Au;
        instance->instruction_count++;
        return 1;
    case 0x0400C12Au: /* D0 F8 BNE $00:C124 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC124u : 0xC12Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400C12Cu: /* 80 06 BRA $00:C134 */
        instance->cpu.pc = 0xC134u;
        instance->instruction_count++;
        return 1;
    case 0x0400C12Eu: /* 5A PHY */
        if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xC12Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400C12Fu: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xC130u;
        instance->instruction_count++;
        return 1;
    case 0x0400C130u: /* 20 9B EA JSR $EA9B */
        if (!tg_push16(instance, 0xC132u)) return 0;
        instance->cpu.pc = 0xEA9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400C133u: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC134u;
        instance->instruction_count++;
        return 1;
    case 0x0400C134u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xC135u;
        instance->instruction_count++;
        return 1;
    case 0x0400C135u: /* 6D 16 01 ADC $0116 */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0116u), &byte)) return 0;
        tg_adc8(instance, byte);
        instance->cpu.pc = 0xC138u;
        instance->instruction_count++;
        return 1;
    case 0x0400C138u: /* 8D 16 01 STA $0116 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0116u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC13Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400C13Bu: /* 9F 00 3E 7E STA $7E3E00,X */
        if (!tg_bus_write8(instance, ((0x7E3E00u + instance->cpu.x) & 0xFFFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC13Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400C13Fu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC140u;
        instance->instruction_count++;
        return 1;
    case 0x0400C140u: /* 7A PLY */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC141u;
        instance->instruction_count++;
        return 1;
    case 0x0400C141u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC142u;
        instance->instruction_count++;
        return 1;
    case 0x0400C142u: /* F0 16 BEQ $00:C15A */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xC15Au : 0xC144u;
        instance->instruction_count++;
        return 1;
    case 0x0400C144u: /* 5A PHY */
        if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xC145u;
        instance->instruction_count++;
        return 1;
    case 0x0400C145u: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xC146u;
        instance->instruction_count++;
        return 1;
    case 0x0400C146u: /* 20 9B EA JSR $EA9B */
        if (!tg_push16(instance, 0xC148u)) return 0;
        instance->cpu.pc = 0xEA9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400C149u: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC14Au;
        instance->instruction_count++;
        return 1;
    case 0x0400C14Au: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xC14Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400C14Bu: /* 6D 17 01 ADC $0117 */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0117u), &byte)) return 0;
        tg_adc8(instance, byte);
        instance->cpu.pc = 0xC14Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400C14Eu: /* 8D 17 01 STA $0117 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0117u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC151u;
        instance->instruction_count++;
        return 1;
    case 0x0400C151u: /* 9F 00 3E 7E STA $7E3E00,X */
        if (!tg_bus_write8(instance, ((0x7E3E00u + instance->cpu.x) & 0xFFFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC155u;
        instance->instruction_count++;
        return 1;
    case 0x0400C155u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC156u;
        instance->instruction_count++;
        return 1;
    case 0x0400C156u: /* 7A PLY */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC157u;
        instance->instruction_count++;
        return 1;
    case 0x0400C157u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC158u;
        instance->instruction_count++;
        return 1;
    case 0x0400C158u: /* D0 D4 BNE $00:C12E */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC12Eu : 0xC15Au;
        instance->instruction_count++;
        return 1;
    case 0x0400C15Au: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC15Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C15Cu: /* AD 12 01 LDA $0112 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0112u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC15Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C15Fu: /* 8D 16 01 STA $0116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC162u;
        instance->instruction_count++;
        return 1;
    case 0x0000C162u: /* AD 06 1F LDA $1F06 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC165u;
        instance->instruction_count++;
        return 1;
    case 0x0000C165u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC166u;
        instance->instruction_count++;
        return 1;
    case 0x0000C166u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC167u;
        instance->instruction_count++;
        return 1;
    case 0x0000C167u: /* A9 04 00 LDA #$0004 */
        word = 0x0004u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC16Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C16Au: /* 3C 24 DF BIT $DF24,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xDF24u + instance->cpu.x)), &word)) return 0;
        tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
        tg_set_flag(instance, TG_P_N, (word & 0x8000u) != 0u);
        tg_set_flag(instance, TG_P_V, (word & 0x4000u) != 0u);
        instance->cpu.pc = 0xC16Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C16Du: /* 10 05 BPL $00:C174 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xC174u : 0xC16Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C16Fu: /* 0C F2 1E TSB $1EF2 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF2u), &word)) return 0;
        tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
        word = (uint16_t)(word | (uint16_t)instance->cpu.a);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF2u), word)) return 0;
        instance->cpu.pc = 0xC172u;
        instance->instruction_count++;
        return 1;
    case 0x0000C172u: /* 80 03 BRA $00:C177 */
        instance->cpu.pc = 0xC177u;
        instance->instruction_count++;
        return 1;
    case 0x0000C174u: /* 1C F2 1E TRB $1EF2 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF2u), &word)) return 0;
        tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
        word = (uint16_t)(word & (uint16_t)~(uint16_t)instance->cpu.a);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF2u), word)) return 0;
        instance->cpu.pc = 0xC177u;
        instance->instruction_count++;
        return 1;
    case 0x0000C177u: /* BD 24 DF LDA $DF24,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xDF24u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC17Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C17Au: /* 29 FF 7F AND #$7FFF */
        word = 0x7FFFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC17Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C17Du: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC17Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C17Eu: /* 8D F0 1E STA $1EF0 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF0u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC181u;
        instance->instruction_count++;
        return 1;
    case 0x0000C181u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0000C182u: /* E2 30 SEP #$30 */
        instance->cpu.p |=0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC184u;
        instance->instruction_count++;
        return 1;
    case 0x0600C184u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC186u;
        instance->instruction_count++;
        return 1;
    /* Version 26 map: graphics/VRAM upload path; $2116 selects the VRAM destination word. */
    case 0x0600C186u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC189u;
        instance->instruction_count++;
        return 1;
    case 0x0600C189u: /* A9 1A LDA #$1A */
        byte = 0x1Au;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC18Bu;
        instance->instruction_count++;
        return 1;
    case 0x0600C18Bu: /* 8D 17 21 STA $2117 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2117u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC18Eu;
        instance->instruction_count++;
        return 1;
    case 0x0600C18Eu: /* A9 80 LDA #$80 */
        byte = 0x80u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC190u;
        instance->instruction_count++;
        return 1;
    case 0x0600C190u: /* A0 25 LDY #$25 */
        byte = 0x25u;
        tg_set_index8(instance, &instance->cpu.y, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC192u;
        instance->instruction_count++;
        return 1;
    case 0x0600C192u: /* A2 E0 LDX #$E0 */
        byte = 0xE0u;
        tg_set_index8(instance, &instance->cpu.x, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC194u;
        instance->instruction_count++;
        return 1;
    case 0x0600C194u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC197u;
        instance->instruction_count++;
        return 1;
    case 0x0600C197u: /* 8C 19 21 STY $2119 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2119u), (uint8_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xC19Au;
        instance->instruction_count++;
        return 1;
    case 0x0600C19Au: /* CA DEX */
        byte = (uint8_t)(instance->cpu.x - 1u);
        tg_set_index8(instance, &instance->cpu.x, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC19Bu;
        instance->instruction_count++;
        return 1;
    case 0x0600C19Bu: /* D0 F7 BNE $00:C194 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC194u : 0xC19Du;
        instance->instruction_count++;
        return 1;
    case 0x0600C19Du: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC19Fu;
        instance->instruction_count++;
        return 1;
    case 0x0600C19Fu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC1A2u;
        instance->instruction_count++;
        return 1;
    case 0x0600C1A2u: /* A9 1E LDA #$1E */
        byte = 0x1Eu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC1A4u;
        instance->instruction_count++;
        return 1;
    case 0x0600C1A4u: /* 8D 17 21 STA $2117 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2117u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC1A7u;
        instance->instruction_count++;
        return 1;
    case 0x0600C1A7u: /* A9 80 LDA #$80 */
        byte = 0x80u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC1A9u;
        instance->instruction_count++;
        return 1;
    case 0x0600C1A9u: /* A0 25 LDY #$25 */
        byte = 0x25u;
        tg_set_index8(instance, &instance->cpu.y, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC1ABu;
        instance->instruction_count++;
        return 1;
    case 0x0600C1ABu: /* A2 E0 LDX #$E0 */
        byte = 0xE0u;
        tg_set_index8(instance, &instance->cpu.x, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC1ADu;
        instance->instruction_count++;
        return 1;
    case 0x0600C1ADu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC1B0u;
        instance->instruction_count++;
        return 1;
    case 0x0600C1B0u: /* 8C 19 21 STY $2119 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2119u), (uint8_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xC1B3u;
        instance->instruction_count++;
        return 1;
    case 0x0600C1B3u: /* CA DEX */
        byte = (uint8_t)(instance->cpu.x - 1u);
        tg_set_index8(instance, &instance->cpu.x, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC1B4u;
        instance->instruction_count++;
        return 1;
    case 0x0600C1B4u: /* D0 F7 BNE $00:C1AD */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC1ADu : 0xC1B6u;
        instance->instruction_count++;
        return 1;
    case 0x0600C1B6u: /* C2 30 REP #$30 */
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC1B8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C1B8u: /* AD 06 1F LDA $1F06 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC1BBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C1BBu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC1BCu;
        instance->instruction_count++;
        return 1;
    case 0x0000C1BCu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC1BDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C1BDu: /* A9 00 02 LDA #$0200 */
        word = 0x0200u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC1C0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C1C0u: /* 85 23 STA $23 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC1C2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C1C2u: /* BD A4 DF LDA $DFA4,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xDFA4u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC1C5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C1C5u: /* 85 22 STA $22 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC1C7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C1C7u: /* A9 E0 1A LDA #$1AE0 */
        word = 0x1AE0u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC1CAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C1CAu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC1CDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C1CDu: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC1D0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C1D0u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC1D2u;
        instance->instruction_count++;
        return 1;
    case 0x0400C1D2u: /* B7 22 LDA [$22],Y */
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC1D4u;
        instance->instruction_count++;
        return 1;
    case 0x0400C1D4u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC1D7u;
        instance->instruction_count++;
        return 1;
    case 0x0400C1D7u: /* A9 05 LDA #$05 */
        byte = 0x05u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC1D9u;
        instance->instruction_count++;
        return 1;
    case 0x0400C1D9u: /* 8D 19 21 STA $2119 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2119u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC1DCu;
        instance->instruction_count++;
        return 1;
    case 0x0400C1DCu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC1DDu;
        instance->instruction_count++;
        return 1;
    case 0x0400C1DDu: /* C0 40 00 CPY #$0040 */
        word = 0x0040u;
        tg_compare16(instance, (uint16_t)instance->cpu.y, word);
        instance->cpu.pc = 0xC1E0u;
        instance->instruction_count++;
        return 1;
    case 0x0400C1E0u: /* D0 F0 BNE $00:C1D2 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC1D2u : 0xC1E2u;
        instance->instruction_count++;
        return 1;
    case 0x0400C1E2u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC1E4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C1E4u: /* A9 E0 1E LDA #$1EE0 */
        word = 0x1EE0u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC1E7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C1E7u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC1EAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C1EAu: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC1EDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C1EDu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC1EFu;
        instance->instruction_count++;
        return 1;
    case 0x0400C1EFu: /* B7 22 LDA [$22],Y */
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC1F1u;
        instance->instruction_count++;
        return 1;
    case 0x0400C1F1u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC1F4u;
        instance->instruction_count++;
        return 1;
    case 0x0400C1F4u: /* A9 05 LDA #$05 */
        byte = 0x05u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC1F6u;
        instance->instruction_count++;
        return 1;
    case 0x0400C1F6u: /* 8D 19 21 STA $2119 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2119u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC1F9u;
        instance->instruction_count++;
        return 1;
    case 0x0400C1F9u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC1FAu;
        instance->instruction_count++;
        return 1;
    case 0x0400C1FAu: /* C0 40 00 CPY #$0040 */
        word = 0x0040u;
        tg_compare16(instance, (uint16_t)instance->cpu.y, word);
        instance->cpu.pc = 0xC1FDu;
        instance->instruction_count++;
        return 1;
    case 0x0400C1FDu: /* D0 F0 BNE $00:C1EF */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC1EFu : 0xC1FFu;
        instance->instruction_count++;
        return 1;
    case 0x0400C1FFu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC201u;
        instance->instruction_count++;
        return 1;
    case 0x0000C201u: /* A9 00 68 LDA #$6800 */
        word = 0x6800u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC204u;
        instance->instruction_count++;
        return 1;
    case 0x0000C204u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC207u;
        instance->instruction_count++;
        return 1;
    case 0x0000C207u: /* E0 20 00 CPX #$0020 */
        word = 0x0020u;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0xC20Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C20Au: /* A9 05 00 LDA #$0005 */
        word = 0x0005u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC20Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C20Du: /* 2A ROL A */
        word = instance->cpu.a;
        byte = (uint8_t)tg_flag(instance, TG_P_C);
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)((word << 1) | byte);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC20Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C20Eu: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xC20Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C20Fu: /* 85 24 STA $24 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x24u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC211u;
        instance->instruction_count++;
        return 1;
    case 0x0000C211u: /* BD 64 DF LDA $DF64,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xDF64u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC214u;
        instance->instruction_count++;
        return 1;
    case 0x0000C214u: /* 85 23 STA $23 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC216u;
        instance->instruction_count++;
        return 1;
    case 0x0000C216u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC218u;
        instance->instruction_count++;
        return 1;
    case 0x0400C218u: /* 20 8E EA JSR $EA8E */
        if (!tg_push16(instance, 0xC21Au)) return 0;
        instance->cpu.pc = 0xEA8Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400C21Bu: /* B0 10 BCS $00:C22D */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xC22Du : 0xC21Du;
        instance->instruction_count++;
        return 1;
    case 0x0400C21Du: /* 8D 18 21 STA $2118 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC220u;
        instance->instruction_count++;
        return 1;
    case 0x0400C220u: /* 20 9B EA JSR $EA9B */
        if (!tg_push16(instance, 0xC222u)) return 0;
        instance->cpu.pc = 0xEA9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400C223u: /* 8D 19 21 STA $2119 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2119u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC226u;
        instance->instruction_count++;
        return 1;
    case 0x0400C226u: /* B0 05 BCS $00:C22D */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xC22Du : 0xC228u;
        instance->instruction_count++;
        return 1;
    case 0x0400C228u: /* 20 9B EA JSR $EA9B */
        if (!tg_push16(instance, 0xC22Au)) return 0;
        instance->cpu.pc = 0xEA9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400C22Bu: /* 90 F0 BCC $00:C21D */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xC21Du : 0xC22Du;
        instance->instruction_count++;
        return 1;
    case 0x0400C22Du: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC22Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C22Fu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0000C230u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC232u;
        instance->instruction_count++;
        return 1;
    case 0x0400C232u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC234u;
        instance->instruction_count++;
        return 1;
    case 0x0400C234u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC237u;
        instance->instruction_count++;
        return 1;
    case 0x0400C237u: /* A9 02 LDA #$02 */
        byte = 0x02u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC239u;
        instance->instruction_count++;
        return 1;
    case 0x0400C239u: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC23Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400C23Cu: /* C2 30 REP #$30 */
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC23Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C23Eu: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC241u;
        instance->instruction_count++;
        return 1;
    case 0x0000C241u: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC244u;
        instance->instruction_count++;
        return 1;
    case 0x0000C244u: /* A9 00 80 LDA #$8000 */
        word = 0x8000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC247u;
        instance->instruction_count++;
        return 1;
    case 0x0000C247u: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC24Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C24Au: /* A9 80 2C LDA #$2C80 */
        word = 0x2C80u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC24Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C24Du: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC250u;
        instance->instruction_count++;
        return 1;
    case 0x0000C250u: /* A9 00 50 LDA #$5000 */
        word = 0x5000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC253u;
        instance->instruction_count++;
        return 1;
    case 0x0000C253u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC256u;
        instance->instruction_count++;
        return 1;
    case 0x0000C256u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC258u;
        instance->instruction_count++;
        return 1;
    case 0x0400C258u: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC25Au;
        instance->instruction_count++;
        return 1;
    case 0x0400C25Au: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC25Du;
        instance->instruction_count++;
        return 1;
    case 0x0400C25Du: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC25Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C25Fu: /* A9 02 80 LDA #$8002 */
        word = 0x8002u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC262u;
        instance->instruction_count++;
        return 1;
    case 0x0000C262u: /* A2 80 AC LDX #$AC80 */
        word = 0xAC80u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC265u;
        instance->instruction_count++;
        return 1;
    case 0x0000C265u: /* A0 00 70 LDY #$7000 */
        word = 0x7000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC268u;
        instance->instruction_count++;
        return 1;
    case 0x0000C268u: /* 20 40 EA JSR $EA40 */
        if (!tg_push16(instance, 0xC26Au)) return 0;
        instance->cpu.pc = 0xEA40u;
        instance->instruction_count++;
        return 1;
    case 0x0000C26Bu: /* AD 06 1F LDA $1F06 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC26Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C26Eu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC26Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C26Fu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC270u;
        instance->instruction_count++;
        return 1;
    case 0x0000C270u: /* BD E4 DE LDA $DEE4,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xDEE4u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC273u;
        instance->instruction_count++;
        return 1;
    case 0x0000C273u: /* 85 1A STA $1A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC275u;
        instance->instruction_count++;
        return 1;
    case 0x0000C275u: /* 10 45 BPL $00:C2BC */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xC2BCu : 0xC277u;
        instance->instruction_count++;
        return 1;
    case 0x0000C277u: /* A9 02 00 LDA #$0002 */
        word = 0x0002u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC27Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C27Au: /* 0C F2 1E TSB $1EF2 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF2u), &word)) return 0;
        tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
        word = (uint16_t)(word | (uint16_t)instance->cpu.a);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF2u), word)) return 0;
        instance->cpu.pc = 0xC27Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C27Du: /* A9 20 1B LDA #$1B20 */
        word = 0x1B20u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC280u;
        instance->instruction_count++;
        return 1;
    case 0x0000C280u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC283u;
        instance->instruction_count++;
        return 1;
    case 0x0000C283u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC285u;
        instance->instruction_count++;
        return 1;
    case 0x0400C285u: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC288u;
        instance->instruction_count++;
        return 1;
    case 0x0400C288u: /* BF 00 98 03 LDA $039800,X */
        if (!tg_bus_read8(instance, ((0x039800u + instance->cpu.x) & 0xFFFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC28Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400C28Cu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC28Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400C28Fu: /* A9 0A LDA #$0A */
        byte = 0x0Au;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC291u;
        instance->instruction_count++;
        return 1;
    case 0x0400C291u: /* 8D 19 21 STA $2119 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2119u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC294u;
        instance->instruction_count++;
        return 1;
    case 0x0400C294u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC295u;
        instance->instruction_count++;
        return 1;
    case 0x0400C295u: /* E0 E0 00 CPX #$00E0 */
        word = 0x00E0u;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0xC298u;
        instance->instruction_count++;
        return 1;
    case 0x0400C298u: /* D0 EE BNE $00:C288 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC288u : 0xC29Au;
        instance->instruction_count++;
        return 1;
    case 0x0400C29Au: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC29Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C29Cu: /* A9 20 1F LDA #$1F20 */
        word = 0x1F20u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC29Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C29Fu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC2A2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C2A2u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC2A4u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2A4u: /* BF 00 98 03 LDA $039800,X */
        if (!tg_bus_read8(instance, ((0x039800u + instance->cpu.x) & 0xFFFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC2A8u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2A8u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC2ABu;
        instance->instruction_count++;
        return 1;
    case 0x0400C2ABu: /* A9 0A LDA #$0A */
        byte = 0x0Au;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC2ADu;
        instance->instruction_count++;
        return 1;
    case 0x0400C2ADu: /* 8D 19 21 STA $2119 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2119u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC2B0u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2B0u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC2B1u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2B1u: /* E0 C0 01 CPX #$01C0 */
        word = 0x01C0u;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0xC2B4u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2B4u: /* D0 EE BNE $00:C2A4 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC2A4u : 0xC2B6u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2B6u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC2B8u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2B8u: /* 85 E0 STA $E0 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0xE0u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC2BAu;
        instance->instruction_count++;
        return 1;
    case 0x0400C2BAu: /* 80 40 BRA $00:C2FC */
        instance->cpu.pc = 0xC2FCu;
        instance->instruction_count++;
        return 1;
    case 0x0000C2BCu: /* A9 02 00 LDA #$0002 */
        word = 0x0002u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC2BFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C2BFu: /* 1C F2 1E TRB $1EF2 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF2u), &word)) return 0;
        tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
        word = (uint16_t)(word & (uint16_t)~(uint16_t)instance->cpu.a);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF2u), word)) return 0;
        instance->cpu.pc = 0xC2C2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C2C2u: /* A9 20 1B LDA #$1B20 */
        word = 0x1B20u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC2C5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C2C5u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC2C8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C2C8u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC2CAu;
        instance->instruction_count++;
        return 1;
    case 0x0400C2CAu: /* A2 BF 01 LDX #$01BF */
        word = 0x01BFu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC2CDu;
        instance->instruction_count++;
        return 1;
    case 0x0400C2CDu: /* BF 00 98 03 LDA $039800,X */
        if (!tg_bus_read8(instance, ((0x039800u + instance->cpu.x) & 0xFFFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC2D1u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2D1u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC2D4u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2D4u: /* A9 CA LDA #$CA */
        byte = 0xCAu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC2D6u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2D6u: /* 8D 19 21 STA $2119 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2119u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC2D9u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2D9u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC2DAu;
        instance->instruction_count++;
        return 1;
    case 0x0400C2DAu: /* E0 DF 00 CPX #$00DF */
        word = 0x00DFu;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0xC2DDu;
        instance->instruction_count++;
        return 1;
    case 0x0400C2DDu: /* D0 EE BNE $00:C2CD */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC2CDu : 0xC2DFu;
        instance->instruction_count++;
        return 1;
    case 0x0400C2DFu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC2E1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C2E1u: /* A9 20 1F LDA #$1F20 */
        word = 0x1F20u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC2E4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C2E4u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC2E7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C2E7u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC2E9u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2E9u: /* BF 00 98 03 LDA $039800,X */
        if (!tg_bus_read8(instance, ((0x039800u + instance->cpu.x) & 0xFFFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC2EDu;
        instance->instruction_count++;
        return 1;
    case 0x0400C2EDu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC2F0u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2F0u: /* A9 CA LDA #$CA */
        byte = 0xCAu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC2F2u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2F2u: /* 8D 19 21 STA $2119 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2119u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC2F5u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2F5u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC2F6u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2F6u: /* 10 F1 BPL $00:C2E9 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xC2E9u : 0xC2F8u;
        instance->instruction_count++;
        return 1;
    case 0x0400C2F8u: /* A9 FF LDA #$FF */
        byte = 0xFFu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC2FAu;
        instance->instruction_count++;
        return 1;
    case 0x0400C2FAu: /* 85 E0 STA $E0 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0xE0u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC2FCu;
        instance->instruction_count++;
        return 1;
    case 0x0400C2FCu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC2FEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C2FEu: /* A5 1A LDA $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC300u;
        instance->instruction_count++;
        return 1;
    case 0x0000C300u: /* 29 07 00 AND #$0007 */
        word = 0x0007u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC303u;
        instance->instruction_count++;
        return 1;
    case 0x0000C303u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC304u;
        instance->instruction_count++;
        return 1;
    case 0x0000C304u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC305u;
        instance->instruction_count++;
        return 1;
    case 0x0000C305u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC306u;
        instance->instruction_count++;
        return 1;
    case 0x0000C306u: /* BD 72 C5 LDA $C572,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC572u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC309u;
        instance->instruction_count++;
        return 1;
    case 0x0000C309u: /* 8D 7B 01 STA $017B */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x017Bu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC30Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C30Cu: /* BD 74 C5 LDA $C574,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC574u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC30Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C30Fu: /* 8D 7D 01 STA $017D */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x017Du), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC312u;
        instance->instruction_count++;
        return 1;
    case 0x0000C312u: /* BD 92 C5 LDA $C592,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC592u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC315u;
        instance->instruction_count++;
        return 1;
    case 0x0000C315u: /* 8D 3F 01 STA $013F */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x013Fu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC318u;
        instance->instruction_count++;
        return 1;
    case 0x0000C318u: /* BD 94 C5 LDA $C594,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC594u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC31Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C31Bu: /* 8D 41 01 STA $0141 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0141u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC31Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C31Eu: /* BD 52 C5 LDA $C552,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC552u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC321u;
        instance->instruction_count++;
        return 1;
    case 0x0000C321u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xC322u;
        instance->instruction_count++;
        return 1;
    case 0x0000C322u: /* BD 54 C5 LDA $C554,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC554u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC325u;
        instance->instruction_count++;
        return 1;
    case 0x0000C325u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC326u;
        instance->instruction_count++;
        return 1;
    case 0x0000C326u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC328u;
        instance->instruction_count++;
        return 1;
    case 0x0400C328u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC32Au;
        instance->instruction_count++;
        return 1;
    case 0x0400C32Au: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC32Du;
        instance->instruction_count++;
        return 1;
    case 0x0400C32Du: /* A9 03 LDA #$03 */
        byte = 0x03u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC32Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400C32Fu: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC332u;
        instance->instruction_count++;
        return 1;
    case 0x0400C332u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC334u;
        instance->instruction_count++;
        return 1;
    case 0x0000C334u: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC337u;
        instance->instruction_count++;
        return 1;
    case 0x0000C337u: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC33Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C33Au: /* 98 TYA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.y);
        tg_set_nz16(instance, (uint16_t)instance->cpu.a);
        instance->cpu.pc = 0xC33Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C33Bu: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC33Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C33Eu: /* A9 00 03 LDA #$0300 */
        word = 0x0300u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC341u;
        instance->instruction_count++;
        return 1;
    case 0x0000C341u: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC344u;
        instance->instruction_count++;
        return 1;
    case 0x0000C344u: /* A9 00 10 LDA #$1000 */
        word = 0x1000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC347u;
        instance->instruction_count++;
        return 1;
    case 0x0000C347u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC34Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C34Au: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC34Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400C34Cu: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC34Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400C34Eu: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC351u;
        instance->instruction_count++;
        return 1;
    case 0x0400C351u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC353u;
        instance->instruction_count++;
        return 1;
    case 0x0400C353u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC356u;
        instance->instruction_count++;
        return 1;
    case 0x0400C356u: /* A9 03 LDA #$03 */
        byte = 0x03u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC358u;
        instance->instruction_count++;
        return 1;
    case 0x0400C358u: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC35Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400C35Bu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC35Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C35Du: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC360u;
        instance->instruction_count++;
        return 1;
    case 0x0000C360u: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC363u;
        instance->instruction_count++;
        return 1;
    case 0x0000C363u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC364u;
        instance->instruction_count++;
        return 1;
    case 0x0000C364u: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC367u;
        instance->instruction_count++;
        return 1;
    case 0x0000C367u: /* A9 00 03 LDA #$0300 */
        word = 0x0300u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC36Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C36Au: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC36Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C36Du: /* A9 00 14 LDA #$1400 */
        word = 0x1400u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC370u;
        instance->instruction_count++;
        return 1;
    case 0x0000C370u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC373u;
        instance->instruction_count++;
        return 1;
    case 0x0000C373u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC375u;
        instance->instruction_count++;
        return 1;
    case 0x0400C375u: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC377u;
        instance->instruction_count++;
        return 1;
    case 0x0400C377u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC37Au;
        instance->instruction_count++;
        return 1;
    case 0x0400C37Au: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC37Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C37Cu: /* A5 1A LDA $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC37Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C37Eu: /* 29 38 00 AND #$0038 */
        word = 0x0038u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC381u;
        instance->instruction_count++;
        return 1;
    case 0x0000C381u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC382u;
        instance->instruction_count++;
        return 1;
    case 0x0000C382u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC383u;
        instance->instruction_count++;
        return 1;
    case 0x0000C383u: /* BD 72 C5 LDA $C572,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC572u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC386u;
        instance->instruction_count++;
        return 1;
    case 0x0000C386u: /* 8D 7F 01 STA $017F */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x017Fu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC389u;
        instance->instruction_count++;
        return 1;
    case 0x0000C389u: /* BD 74 C5 LDA $C574,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC574u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC38Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C38Cu: /* 8D 81 01 STA $0181 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0181u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC38Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C38Fu: /* BD 92 C5 LDA $C592,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC592u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC392u;
        instance->instruction_count++;
        return 1;
    case 0x0000C392u: /* 8D 43 01 STA $0143 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0143u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC395u;
        instance->instruction_count++;
        return 1;
    case 0x0000C395u: /* BD 94 C5 LDA $C594,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC594u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC398u;
        instance->instruction_count++;
        return 1;
    case 0x0000C398u: /* 8D 45 01 STA $0145 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0145u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC39Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C39Bu: /* BD 52 C5 LDA $C552,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC552u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC39Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C39Eu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xC39Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C39Fu: /* BD 54 C5 LDA $C554,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC554u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC3A2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3A2u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC3A3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3A3u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC3A5u;
        instance->instruction_count++;
        return 1;
    case 0x0400C3A5u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC3A7u;
        instance->instruction_count++;
        return 1;
    case 0x0400C3A7u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC3AAu;
        instance->instruction_count++;
        return 1;
    case 0x0400C3AAu: /* A9 03 LDA #$03 */
        byte = 0x03u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC3ACu;
        instance->instruction_count++;
        return 1;
    case 0x0400C3ACu: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC3AFu;
        instance->instruction_count++;
        return 1;
    case 0x0400C3AFu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC3B1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3B1u: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC3B4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3B4u: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC3B7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3B7u: /* 98 TYA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.y);
        tg_set_nz16(instance, (uint16_t)instance->cpu.a);
        instance->cpu.pc = 0xC3B8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3B8u: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC3BBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C3BBu: /* A9 00 03 LDA #$0300 */
        word = 0x0300u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC3BEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C3BEu: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC3C1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3C1u: /* A9 80 11 LDA #$1180 */
        word = 0x1180u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC3C4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3C4u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC3C7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3C7u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC3C9u;
        instance->instruction_count++;
        return 1;
    case 0x0400C3C9u: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC3CBu;
        instance->instruction_count++;
        return 1;
    case 0x0400C3CBu: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC3CEu;
        instance->instruction_count++;
        return 1;
    case 0x0400C3CEu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC3D0u;
        instance->instruction_count++;
        return 1;
    case 0x0400C3D0u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC3D3u;
        instance->instruction_count++;
        return 1;
    case 0x0400C3D3u: /* A9 03 LDA #$03 */
        byte = 0x03u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC3D5u;
        instance->instruction_count++;
        return 1;
    case 0x0400C3D5u: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC3D8u;
        instance->instruction_count++;
        return 1;
    case 0x0400C3D8u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC3DAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C3DAu: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC3DDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C3DDu: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC3E0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3E0u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC3E1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3E1u: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC3E4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3E4u: /* A9 00 03 LDA #$0300 */
        word = 0x0300u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC3E7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3E7u: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC3EAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C3EAu: /* A9 80 15 LDA #$1580 */
        word = 0x1580u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC3EDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C3EDu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC3F0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3F0u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC3F2u;
        instance->instruction_count++;
        return 1;
    case 0x0400C3F2u: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC3F4u;
        instance->instruction_count++;
        return 1;
    case 0x0400C3F4u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC3F7u;
        instance->instruction_count++;
        return 1;
    case 0x0400C3F7u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC3F9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C3F9u: /* A5 1A LDA $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC3FBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C3FBu: /* 29 C0 01 AND #$01C0 */
        word = 0x01C0u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC3FEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C3FEu: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC3FFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C3FFu: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC400u;
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
