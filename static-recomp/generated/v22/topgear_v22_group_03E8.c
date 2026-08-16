/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_03E8(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x000FA000u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA001u;
        instance->instruction_count++;
        return 1;
    case 0x000FA001u: /* BF BB C5 0D LDA $0DC5BB,X */
        if (!tg_bus_read16(instance, ((0x0DC5BBu + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA005u;
        instance->instruction_count++;
        return 1;
    case 0x000FA005u: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA006u;
        instance->instruction_count++;
        return 1;
    case 0x000FA006u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA009u;
        instance->instruction_count++;
        return 1;
    case 0x000FA009u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA00Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA00Au: /* 69 80 00 ADC #$0080 */
        word = 0x0080u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA00Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA00Du: /* 65 54 ADC $54 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x54u) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA00Fu;
        instance->instruction_count++;
        return 1;
    case 0x000FA00Fu: /* A4 4C LDY $4C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x4Cu) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA011u;
        instance->instruction_count++;
        return 1;
    case 0x000FA011u: /* 99 00 00 STA $0000,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA014u;
        instance->instruction_count++;
        return 1;
    case 0x000FA014u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA015u;
        instance->instruction_count++;
        return 1;
    case 0x000FA015u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA016u;
        instance->instruction_count++;
        return 1;
    case 0x000FA016u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA017u;
        instance->instruction_count++;
        return 1;
    case 0x000FA017u: /* 99 00 00 STA $0000,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA01Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA01Au: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA01Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA01Bu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA01Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA01Cu: /* 84 4C STY $4C */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x4Cu) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xA01Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA01Eu: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA021u;
        instance->instruction_count++;
        return 1;
    case 0x000FA021u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA023u;
        instance->instruction_count++;
        return 1;
    case 0x040FA023u: /* 80 83 BRA $0F:9FA8 */
        instance->cpu.pc = 0x9FA8u;
        instance->instruction_count++;
        return 1;
    case 0x040FA025u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA027u;
        instance->instruction_count++;
        return 1;
    case 0x000FA027u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA028u;
        instance->instruction_count++;
        return 1;
    case 0x000FA028u: /* A5 54 LDA $54 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x54u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA02Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA02Au: /* D0 13 BNE $0F:A03F */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xA03Fu : 0xA02Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA02Cu: /* A9 10 00 LDA #$0010 */
        word = 0x0010u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA02Fu;
        instance->instruction_count++;
        return 1;
    case 0x000FA02Fu: /* 85 54 STA $54 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x54u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA031u;
        instance->instruction_count++;
        return 1;
    case 0x000FA031u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA032u;
        instance->instruction_count++;
        return 1;
    case 0x000FA032u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA033u;
        instance->instruction_count++;
        return 1;
    case 0x000FA033u: /* 69 40 00 ADC #$0040 */
        word = 0x0040u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA036u;
        instance->instruction_count++;
        return 1;
    case 0x000FA036u: /* 85 4C STA $4C */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x4Cu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA038u;
        instance->instruction_count++;
        return 1;
    case 0x000FA038u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA03Au;
        instance->instruction_count++;
        return 1;
    case 0x040FA03Au: /* A6 56 LDX $56 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x56u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA03Cu;
        instance->instruction_count++;
        return 1;
    case 0x040FA03Cu: /* 4C A8 9F JMP $9FA8 */
        instance->cpu.pc = 0x9FA8u;
        instance->instruction_count++;
        return 1;
    case 0x000FA03Fu: /* 4C 93 9F JMP $9F93 */
        instance->cpu.pc = 0x9F93u;
        instance->instruction_count++;
        return 1;
    case 0x000FA042u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA044u;
        instance->instruction_count++;
        return 1;
    case 0x000FA044u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000FA045u: /* 20 C4 A1 JSR $A1C4 */
        if (!tg_push16(instance, 0xA047u)) return 0;
        instance->cpu.pc = 0xA1C4u;
        instance->instruction_count++;
        return 1;
    case 0x000FA048u: /* 9D FE 01 STA $01FE,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x01FEu + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA04Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA04Bu: /* A5 4A LDA $4A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x4Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA04Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA04Du: /* C9 00 02 CMP #$0200 */
        word = 0x0200u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xA050u;
        instance->instruction_count++;
        return 1;
    case 0x000FA050u: /* B0 3C BCS $0F:A08E */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xA08Eu : 0xA052u;
        instance->instruction_count++;
        return 1;
    case 0x000FA052u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA055u;
        instance->instruction_count++;
        return 1;
    case 0x000FA055u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xA056u;
        instance->instruction_count++;
        return 1;
    case 0x000FA056u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA057u;
        instance->instruction_count++;
        return 1;
    case 0x000FA057u: /* F0 2C BEQ $0F:A085 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xA085u : 0xA059u;
        instance->instruction_count++;
        return 1;
    case 0x000FA059u: /* A9 C4 0E LDA #$0EC4 */
        word = 0x0EC4u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA05Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA05Cu: /* 9D 00 02 STA $0200,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0200u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA05Fu;
        instance->instruction_count++;
        return 1;
    case 0x000FA05Fu: /* C0 01 00 CPY #$0001 */
        word = 0x0001u;
        tg_compare16(instance, (uint16_t)instance->cpu.y, word);
        instance->cpu.pc = 0xA062u;
        instance->instruction_count++;
        return 1;
    case 0x000FA062u: /* D0 01 BNE $0F:A065 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xA065u : 0xA064u;
        instance->instruction_count++;
        return 1;
    case 0x000FA064u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA065u;
        instance->instruction_count++;
        return 1;
    case 0x000FA065u: /* A9 C6 0E LDA #$0EC6 */
        word = 0x0EC6u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA068u;
        instance->instruction_count++;
        return 1;
    case 0x000FA068u: /* 9D 04 02 STA $0204,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0204u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA06Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA06Bu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA06Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA06Cu: /* BD FE 01 LDA $01FE,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x01FEu + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA06Fu;
        instance->instruction_count++;
        return 1;
    case 0x000FA06Fu: /* 69 10 00 ADC #$0010 */
        word = 0x0010u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA072u;
        instance->instruction_count++;
        return 1;
    case 0x000FA072u: /* 9D 02 02 STA $0202,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0202u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA075u;
        instance->instruction_count++;
        return 1;
    case 0x000FA075u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA076u;
        instance->instruction_count++;
        return 1;
    case 0x000FA076u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA077u;
        instance->instruction_count++;
        return 1;
    case 0x000FA077u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA078u;
        instance->instruction_count++;
        return 1;
    case 0x000FA078u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA079u;
        instance->instruction_count++;
        return 1;
    case 0x000FA079u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA07Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA07Au: /* 10 E9 BPL $0F:A065 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xA065u : 0xA07Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA07Cu: /* A9 C4 4E LDA #$4EC4 */
        word = 0x4EC4u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA07Fu;
        instance->instruction_count++;
        return 1;
    case 0x000FA07Fu: /* 9D 00 02 STA $0200,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0200u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA082u;
        instance->instruction_count++;
        return 1;
    case 0x000FA082u: /* 4C 1E A1 JMP $A11E */
        instance->cpu.pc = 0xA11Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA085u: /* A9 C2 0E LDA #$0EC2 */
        word = 0x0EC2u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA088u;
        instance->instruction_count++;
        return 1;
    case 0x000FA088u: /* 9D 00 02 STA $0200,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0200u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA08Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA08Bu: /* 4C 1E A1 JMP $A11E */
        instance->cpu.pc = 0xA11Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA08Eu: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA091u;
        instance->instruction_count++;
        return 1;
    case 0x000FA091u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xA092u;
        instance->instruction_count++;
        return 1;
    case 0x000FA092u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA093u;
        instance->instruction_count++;
        return 1;
    case 0x000FA093u: /* A9 C8 0E LDA #$0EC8 */
        word = 0x0EC8u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA096u;
        instance->instruction_count++;
        return 1;
    case 0x000FA096u: /* 8D 04 02 STA $0204 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0204u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA099u;
        instance->instruction_count++;
        return 1;
    case 0x000FA099u: /* A9 C6 0E LDA #$0EC6 */
        word = 0x0EC6u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA09Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA09Cu: /* 9D 04 02 STA $0204,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0204u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA09Fu;
        instance->instruction_count++;
        return 1;
    case 0x000FA09Fu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA0A0u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0A0u: /* BD FE 01 LDA $01FE,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x01FEu + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0A3u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0A3u: /* 69 10 00 ADC #$0010 */
        word = 0x0010u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA0A6u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0A6u: /* 9D 02 02 STA $0202,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0202u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA0A9u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0A9u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0AAu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0AAu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0ABu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0ABu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0ACu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0ACu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0ADu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0ADu: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0AEu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0AEu: /* 10 E9 BPL $0F:A099 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xA099u : 0xA0B0u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0B0u: /* A9 C8 4E LDA #$4EC8 */
        word = 0x4EC8u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0B3u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0B3u: /* 9D 00 02 STA $0200,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0200u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA0B6u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0B6u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA0B7u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0B7u: /* A5 58 LDA $58 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x58u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0B9u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0B9u: /* 69 00 10 ADC #$1000 */
        word = 0x1000u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA0BCu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0BCu: /* 85 58 STA $58 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x58u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA0BEu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0BEu: /* 9D 02 02 STA $0202,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0202u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA0C1u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0C1u: /* A5 4A LDA $4A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x4Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0C3u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0C3u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xA0C4u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0C4u: /* E9 00 01 SBC #$0100 */
        word = 0x0100u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xA0C7u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0C7u: /* 85 4A STA $4A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x4Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA0C9u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0C9u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xA0CAu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0CAu: /* E2 10 SEP #$10 */
        instance->cpu.p |=0x10u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA0CCu;
        instance->instruction_count++;
        return 1;
    case 0x020FA0CCu: /* C2 10 REP #$10 */
        instance->cpu.p &= (uint8_t)~0x10u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA0CEu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0CEu: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0CFu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0CFu: /* C9 00 01 CMP #$0100 */
        word = 0x0100u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xA0D2u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0D2u: /* 90 23 BCC $0F:A0F7 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xA0F7u : 0xA0D4u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0D4u: /* A9 C6 0E LDA #$0EC6 */
        word = 0x0EC6u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0D7u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0D7u: /* 9D 04 02 STA $0204,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0204u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA0DAu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0DAu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0DBu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0DBu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0DCu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0DCu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0DDu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0DDu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0DEu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0DEu: /* A9 C6 0E LDA #$0EC6 */
        word = 0x0EC6u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0E1u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0E1u: /* 9D 04 02 STA $0204,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0204u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA0E4u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0E4u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA0E5u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0E5u: /* BD FE 01 LDA $01FE,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x01FEu + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0E8u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0E8u: /* 69 10 00 ADC #$0010 */
        word = 0x0010u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA0EBu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0EBu: /* 9D 02 02 STA $0202,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0202u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA0EEu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0EEu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0EFu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0EFu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0F0u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0F0u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0F1u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0F1u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0F2u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0F2u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0F3u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0F3u: /* 10 E9 BPL $0F:A0DE */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xA0DEu : 0xA0F5u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0F5u: /* 80 BF BRA $0F:A0B6 */
        instance->cpu.pc = 0xA0B6u;
        instance->instruction_count++;
        return 1;
    case 0x000FA0F7u: /* A9 C8 8E LDA #$8EC8 */
        word = 0x8EC8u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0FAu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0FAu: /* 9D 04 02 STA $0204,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0204u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA0FDu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0FDu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0FEu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0FEu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA0FFu;
        instance->instruction_count++;
        return 1;
    case 0x000FA0FFu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA100u;
        instance->instruction_count++;
        return 1;
    case 0x000FA100u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA101u;
        instance->instruction_count++;
        return 1;
    case 0x000FA101u: /* A9 C6 0E LDA #$0EC6 */
        word = 0x0EC6u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA104u;
        instance->instruction_count++;
        return 1;
    case 0x000FA104u: /* 9D 04 02 STA $0204,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0204u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA107u;
        instance->instruction_count++;
        return 1;
    case 0x000FA107u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA108u;
        instance->instruction_count++;
        return 1;
    case 0x000FA108u: /* BD FE 01 LDA $01FE,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x01FEu + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA10Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA10Bu: /* 69 10 00 ADC #$0010 */
        word = 0x0010u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA10Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA10Eu: /* 9D 02 02 STA $0202,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0202u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA111u;
        instance->instruction_count++;
        return 1;
    case 0x000FA111u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA112u;
        instance->instruction_count++;
        return 1;
    case 0x000FA112u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA113u;
        instance->instruction_count++;
        return 1;
    case 0x000FA113u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA114u;
        instance->instruction_count++;
        return 1;
    case 0x000FA114u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA115u;
        instance->instruction_count++;
        return 1;
    case 0x000FA115u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA116u;
        instance->instruction_count++;
        return 1;
    case 0x000FA116u: /* 10 E9 BPL $0F:A101 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xA101u : 0xA118u;
        instance->instruction_count++;
        return 1;
    case 0x000FA118u: /* A9 C8 CE LDA #$CEC8 */
        word = 0xCEC8u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA11Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA11Bu: /* 9D 00 02 STA $0200,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0200u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA11Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA11Eu: /* A9 C0 30 LDA #$30C0 */
        word = 0x30C0u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA121u;
        instance->instruction_count++;
        return 1;
    case 0x000FA121u: /* 9E 02 02 STZ $0202,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0202u + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0xA124u;
        instance->instruction_count++;
        return 1;
    case 0x000FA124u: /* 9D 04 02 STA $0204,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0204u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA127u;
        instance->instruction_count++;
        return 1;
    case 0x000FA127u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA128u;
        instance->instruction_count++;
        return 1;
    case 0x000FA128u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA129u;
        instance->instruction_count++;
        return 1;
    case 0x000FA129u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA12Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA12Au: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA12Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA12Bu: /* E0 00 02 CPX #$0200 */
        word = 0x0200u;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0xA12Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA12Eu: /* 90 EE BCC $0F:A11E */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xA11Eu : 0xA130u;
        instance->instruction_count++;
        return 1;
    case 0x000FA130u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000FA131u: /* A5 46 LDA $46 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x46u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA133u;
        instance->instruction_count++;
        return 1;
    case 0x000FA133u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA134u;
        instance->instruction_count++;
        return 1;
    case 0x000FA134u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA135u;
        instance->instruction_count++;
        return 1;
    case 0x000FA135u: /* BF 5A C7 0D LDA $0DC75A,X */
        if (!tg_bus_read16(instance, ((0x0DC75Au + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA139u;
        instance->instruction_count++;
        return 1;
    case 0x000FA139u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA13Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA13Au: /* BD 00 00 LDA $0000,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA13Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA13Du: /* D0 03 BNE $0F:A142 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xA142u : 0xA13Fu;
        instance->instruction_count++;
        return 1;
    case 0x000FA13Fu: /* 4C C3 A1 JMP $A1C3 */
        instance->cpu.pc = 0xA1C3u;
        instance->instruction_count++;
        return 1;
    case 0x000FA142u: /* 85 48 STA $48 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA144u;
        instance->instruction_count++;
        return 1;
    case 0x000FA144u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA145u;
        instance->instruction_count++;
        return 1;
    case 0x000FA145u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA146u;
        instance->instruction_count++;
        return 1;
    case 0x000FA146u: /* BD 00 00 LDA $0000,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA149u;
        instance->instruction_count++;
        return 1;
    case 0x000FA149u: /* 85 4A STA $4A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x4Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA14Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA14Bu: /* 20 D0 A1 JSR $A1D0 */
        if (!tg_push16(instance, 0xA14Du)) return 0;
        instance->cpu.pc = 0xA1D0u;
        instance->instruction_count++;
        return 1;
    case 0x000FA14Eu: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xA14Fu;
        instance->instruction_count++;
        return 1;
    case 0x000FA14Fu: /* A5 4A LDA $4A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x4Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA151u;
        instance->instruction_count++;
        return 1;
    case 0x000FA151u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA154u;
        instance->instruction_count++;
        return 1;
    case 0x000FA154u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xA155u;
        instance->instruction_count++;
        return 1;
    case 0x000FA155u: /* A6 4C LDX $4C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x4Cu) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA157u;
        instance->instruction_count++;
        return 1;
    case 0x000FA157u: /* A9 2D 00 LDA #$002D */
        word = 0x002Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA15Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA15Au: /* 95 00 STA $00,X */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x00u + instance->cpu.x) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA15Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA15Cu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA15Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA15Du: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA15Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA15Eu: /* A9 2C 00 LDA #$002C */
        word = 0x002Cu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA161u;
        instance->instruction_count++;
        return 1;
    case 0x000FA161u: /* 95 00 STA $00,X */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x00u + instance->cpu.x) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA163u;
        instance->instruction_count++;
        return 1;
    case 0x000FA163u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA164u;
        instance->instruction_count++;
        return 1;
    case 0x000FA164u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA165u;
        instance->instruction_count++;
        return 1;
    case 0x000FA165u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA166u;
        instance->instruction_count++;
        return 1;
    case 0x000FA166u: /* D0 F9 BNE $0F:A161 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xA161u : 0xA168u;
        instance->instruction_count++;
        return 1;
    case 0x000FA168u: /* A5 4B LDA $4B */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x4Bu) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA16Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA16Au: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA16Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA16Du: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xA16Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA16Eu: /* A9 2E 00 LDA #$002E */
        word = 0x002Eu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA171u;
        instance->instruction_count++;
        return 1;
    case 0x000FA171u: /* 95 00 STA $00,X */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x00u + instance->cpu.x) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA173u;
        instance->instruction_count++;
        return 1;
    case 0x000FA173u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA174u;
        instance->instruction_count++;
        return 1;
    case 0x000FA174u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA175u;
        instance->instruction_count++;
        return 1;
    case 0x000FA175u: /* 69 40 00 ADC #$0040 */
        word = 0x0040u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA178u;
        instance->instruction_count++;
        return 1;
    case 0x000FA178u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA179u;
        instance->instruction_count++;
        return 1;
    case 0x000FA179u: /* A9 2B 00 LDA #$002B */
        word = 0x002Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA17Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA17Cu: /* 95 00 STA $00,X */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x00u + instance->cpu.x) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA17Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA17Eu: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA17Fu;
        instance->instruction_count++;
        return 1;
    case 0x000FA17Fu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA180u;
        instance->instruction_count++;
        return 1;
    case 0x000FA180u: /* 69 40 00 ADC #$0040 */
        word = 0x0040u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA183u;
        instance->instruction_count++;
        return 1;
    case 0x000FA183u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA184u;
        instance->instruction_count++;
        return 1;
    case 0x000FA184u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA185u;
        instance->instruction_count++;
        return 1;
    case 0x000FA185u: /* D0 F2 BNE $0F:A179 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xA179u : 0xA187u;
        instance->instruction_count++;
        return 1;
    case 0x000FA187u: /* A9 30 00 LDA #$0030 */
        word = 0x0030u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA18Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA18Au: /* 95 00 STA $00,X */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x00u + instance->cpu.x) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA18Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA18Cu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA18Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA18Du: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA18Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA18Eu: /* A5 4A LDA $4A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x4Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA190u;
        instance->instruction_count++;
        return 1;
    case 0x000FA190u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA193u;
        instance->instruction_count++;
        return 1;
    case 0x000FA193u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xA194u;
        instance->instruction_count++;
        return 1;
    case 0x000FA194u: /* A9 2C 00 LDA #$002C */
        word = 0x002Cu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA197u;
        instance->instruction_count++;
        return 1;
    case 0x000FA197u: /* 95 00 STA $00,X */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x00u + instance->cpu.x) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA199u;
        instance->instruction_count++;
        return 1;
    case 0x000FA199u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA19Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA19Au: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA19Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA19Bu: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA19Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA19Cu: /* D0 F9 BNE $0F:A197 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xA197u : 0xA19Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA19Eu: /* A9 2F 00 LDA #$002F */
        word = 0x002Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1A1u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1A1u: /* 95 00 STA $00,X */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x00u + instance->cpu.x) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA1A3u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1A3u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA1A4u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1A4u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xA1A5u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1A5u: /* E9 40 00 SBC #$0040 */
        word = 0x0040u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xA1A8u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1A8u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA1A9u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1A9u: /* A5 4B LDA $4B */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x4Bu) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1ABu;
        instance->instruction_count++;
        return 1;
    case 0x000FA1ABu: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1AEu;
        instance->instruction_count++;
        return 1;
    case 0x000FA1AEu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xA1AFu;
        instance->instruction_count++;
        return 1;
    case 0x000FA1AFu: /* A9 2B 00 LDA #$002B */
        word = 0x002Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1B2u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1B2u: /* 95 00 STA $00,X */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x00u + instance->cpu.x) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA1B4u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1B4u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xA1B5u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1B5u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA1B6u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1B6u: /* E9 40 00 SBC #$0040 */
        word = 0x0040u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xA1B9u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1B9u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA1BAu;
        instance->instruction_count++;
        return 1;
    case 0x000FA1BAu: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1BBu;
        instance->instruction_count++;
        return 1;
    case 0x000FA1BBu: /* D0 F2 BNE $0F:A1AF */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xA1AFu : 0xA1BDu;
        instance->instruction_count++;
        return 1;
    case 0x000FA1BDu: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1BEu;
        instance->instruction_count++;
        return 1;
    case 0x000FA1BEu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1BFu;
        instance->instruction_count++;
        return 1;
    case 0x000FA1BFu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1C0u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1C0u: /* 4C 3A A1 JMP $A13A */
        instance->cpu.pc = 0xA13Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA1C3u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000FA1C4u: /* A5 48 LDA $48 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1C6u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1C6u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1C7u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1C7u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1C8u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1C8u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1C9u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1C9u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xA1CAu;
        instance->instruction_count++;
        return 1;
    case 0x000FA1CAu: /* E9 00 01 SBC #$0100 */
        word = 0x0100u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xA1CDu;
        instance->instruction_count++;
        return 1;
    case 0x000FA1CDu: /* 85 58 STA $58 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x58u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA1CFu;
        instance->instruction_count++;
        return 1;
    case 0x000FA1CFu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000FA1D0u: /* A5 48 LDA $48 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1D2u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1D2u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1D3u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1D3u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1D4u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1D4u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1D5u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1D5u: /* 29 E0 FF AND #$FFE0 */
        word = 0xFFE0u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1D8u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1D8u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA1DAu;
        instance->instruction_count++;
        return 1;
    case 0x040FA1DAu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA1DBu;
        instance->instruction_count++;
        return 1;
    case 0x040FA1DBu: /* 65 48 ADC $48 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), &byte)) return 0;
        tg_adc8(instance, byte);
        instance->cpu.pc = 0xA1DDu;
        instance->instruction_count++;
        return 1;
    case 0x040FA1DDu: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xA1DEu;
        instance->instruction_count++;
        return 1;
    case 0x040FA1DEu: /* 69 00 ADC #$00 */
        byte = 0x00u;
        tg_adc8(instance, byte);
        instance->cpu.pc = 0xA1E0u;
        instance->instruction_count++;
        return 1;
    case 0x040FA1E0u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xA1E1u;
        instance->instruction_count++;
        return 1;
    case 0x040FA1E1u: /* C2 21 REP #$21 */
        instance->cpu.p &= (uint8_t)~0x21u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA1E3u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1E3u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1E4u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1E4u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA1E5u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1E5u: /* 69 6C 0C ADC #$0C6C */
        word = 0x0C6Cu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA1E8u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1E8u: /* 85 4C STA $4C */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x4Cu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA1EAu;
        instance->instruction_count++;
        return 1;
    case 0x000FA1EAu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000FA1EBu: /* A2 FE 01 LDX #$01FE */
        word = 0x01FEu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1EEu;
        instance->instruction_count++;
        return 1;
    case 0x000FA1EEu: /* 9E 6C 04 STZ $046C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x046Cu + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0xA1F1u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1F1u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1F2u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1F2u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA1F3u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1F3u: /* 10 F9 BPL $0F:A1EE */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xA1EEu : 0xA1F5u;
        instance->instruction_count++;
        return 1;
    case 0x000FA1F5u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000FA1F6u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA1F8u;
        instance->instruction_count++;
        return 1;
    case 0x040FA1F8u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA1FAu;
        instance->instruction_count++;
        return 1;
    case 0x040FA1FAu: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA1FDu;
        instance->instruction_count++;
        return 1;
    case 0x040FA1FDu: /* 8D 21 21 STA $2121 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA200u;
        instance->instruction_count++;
        return 1;
    case 0x040FA200u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA202u;
        instance->instruction_count++;
        return 1;
    case 0x040FA202u: /* 8D 14 43 STA $4314 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4314u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA205u;
        instance->instruction_count++;
        return 1;
    case 0x040FA205u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA207u;
        instance->instruction_count++;
        return 1;
    case 0x000FA207u: /* A9 6C 04 LDA #$046C */
        word = 0x046Cu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA20Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA20Au: /* 8D 12 43 STA $4312 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4312u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA20Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA20Du: /* A9 00 02 LDA #$0200 */
        word = 0x0200u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA210u;
        instance->instruction_count++;
        return 1;
    case 0x000FA210u: /* 8D 15 43 STA $4315 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4315u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA213u;
        instance->instruction_count++;
        return 1;
    case 0x000FA213u: /* A9 02 22 LDA #$2202 */
        word = 0x2202u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA216u;
        instance->instruction_count++;
        return 1;
    case 0x000FA216u: /* 8D 10 43 STA $4310 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4310u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA219u;
        instance->instruction_count++;
        return 1;
    case 0x000FA219u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000FA23Eu: /* A2 FE 01 LDX #$01FE */
        word = 0x01FEu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA241u;
        instance->instruction_count++;
        return 1;
    case 0x000FA241u: /* BF 86 FB 0E LDA $0EFB86,X */
        if (!tg_bus_read16(instance, ((0x0EFB86u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA245u;
        instance->instruction_count++;
        return 1;
    case 0x000FA245u: /* 9D 6C 04 STA $046C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x046Cu + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA248u;
        instance->instruction_count++;
        return 1;
    case 0x000FA248u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA249u;
        instance->instruction_count++;
        return 1;
    case 0x000FA249u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA24Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA24Au: /* 10 F5 BPL $0F:A241 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xA241u : 0xA24Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA24Cu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000FA24Du: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA24Fu;
        instance->instruction_count++;
        return 1;
    case 0x040FA24Fu: /* 64 08 STZ $08 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x08u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0xA251u;
        instance->instruction_count++;
        return 1;
    case 0x040FA251u: /* C5 08 CMP $08 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x08u) & 0xFFFFu), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xA253u;
        instance->instruction_count++;
        return 1;
    case 0x040FA253u: /* D0 FC BNE $0F:A251 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xA251u : 0xA255u;
        instance->instruction_count++;
        return 1;
    case 0x040FA255u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA257u;
        instance->instruction_count++;
        return 1;
    case 0x000FA257u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000FA258u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA25Au;
        instance->instruction_count++;
        return 1;
    case 0x040FA25Au: /* A5 1E LDA $1E */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA25Cu;
        instance->instruction_count++;
        return 1;
    case 0x040FA25Cu: /* 8D 1B 21 STA $211B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA25Fu;
        instance->instruction_count++;
        return 1;
    case 0x040FA25Fu: /* A5 1F LDA $1F */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x1Fu) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA261u;
        instance->instruction_count++;
        return 1;
    case 0x040FA261u: /* 8D 1B 21 STA $211B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA264u;
        instance->instruction_count++;
        return 1;
    case 0x040FA264u: /* A5 20 LDA $20 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA266u;
        instance->instruction_count++;
        return 1;
    case 0x040FA266u: /* 8D 1C 21 STA $211C */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA269u;
        instance->instruction_count++;
        return 1;
    case 0x040FA269u: /* A5 21 LDA $21 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x21u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA26Bu;
        instance->instruction_count++;
        return 1;
    case 0x040FA26Bu: /* 8D 1C 21 STA $211C */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA26Eu;
        instance->instruction_count++;
        return 1;
    case 0x040FA26Eu: /* A5 22 LDA $22 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA270u;
        instance->instruction_count++;
        return 1;
    case 0x040FA270u: /* 8D 1D 21 STA $211D */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA273u;
        instance->instruction_count++;
        return 1;
    case 0x040FA273u: /* A5 23 LDA $23 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA275u;
        instance->instruction_count++;
        return 1;
    case 0x040FA275u: /* 8D 1D 21 STA $211D */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA278u;
        instance->instruction_count++;
        return 1;
    case 0x040FA278u: /* A5 24 LDA $24 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x24u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA27Au;
        instance->instruction_count++;
        return 1;
    case 0x040FA27Au: /* 8D 1E 21 STA $211E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA27Du;
        instance->instruction_count++;
        return 1;
    case 0x040FA27Du: /* A5 25 LDA $25 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x25u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA27Fu;
        instance->instruction_count++;
        return 1;
    case 0x040FA27Fu: /* 8D 1E 21 STA $211E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA282u;
        instance->instruction_count++;
        return 1;
    case 0x040FA282u: /* A5 26 LDA $26 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x26u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA284u;
        instance->instruction_count++;
        return 1;
    case 0x040FA284u: /* 8D 1F 21 STA $211F */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA287u;
        instance->instruction_count++;
        return 1;
    case 0x040FA287u: /* A5 27 LDA $27 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x27u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA289u;
        instance->instruction_count++;
        return 1;
    case 0x040FA289u: /* 8D 1F 21 STA $211F */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA28Cu;
        instance->instruction_count++;
        return 1;
    case 0x040FA28Cu: /* A5 28 LDA $28 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x28u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA28Eu;
        instance->instruction_count++;
        return 1;
    case 0x040FA28Eu: /* 8D 20 21 STA $2120 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2120u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA291u;
        instance->instruction_count++;
        return 1;
    case 0x040FA291u: /* A5 29 LDA $29 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x29u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA293u;
        instance->instruction_count++;
        return 1;
    case 0x040FA293u: /* 8D 20 21 STA $2120 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2120u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA296u;
        instance->instruction_count++;
        return 1;
    case 0x040FA296u: /* A5 2A LDA $2A */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x2Au) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA298u;
        instance->instruction_count++;
        return 1;
    case 0x040FA298u: /* 8D 0D 21 STA $210D */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA29Bu;
        instance->instruction_count++;
        return 1;
    case 0x040FA29Bu: /* A5 2B LDA $2B */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x2Bu) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA29Du;
        instance->instruction_count++;
        return 1;
    case 0x040FA29Du: /* 8D 0D 21 STA $210D */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA2A0u;
        instance->instruction_count++;
        return 1;
    case 0x040FA2A0u: /* A5 2C LDA $2C */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x2Cu) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA2A2u;
        instance->instruction_count++;
        return 1;
    case 0x040FA2A2u: /* 8D 0E 21 STA $210E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA2A5u;
        instance->instruction_count++;
        return 1;
    case 0x040FA2A5u: /* A5 2D LDA $2D */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x2Du) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA2A7u;
        instance->instruction_count++;
        return 1;
    case 0x040FA2A7u: /* 8D 0E 21 STA $210E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA2AAu;
        instance->instruction_count++;
        return 1;
    case 0x040FA2AAu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA2ACu;
        instance->instruction_count++;
        return 1;
    case 0x000FA2ACu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000FA2ADu: /* A5 16 LDA $16 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x16u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2AFu;
        instance->instruction_count++;
        return 1;
    case 0x000FA2AFu: /* A6 14 LDX $14 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x14u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2B1u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2B1u: /* 20 60 A3 JSR $A360 */
        if (!tg_push16(instance, 0xA2B3u)) return 0;
        instance->cpu.pc = 0xA360u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2B4u: /* A5 33 LDA $33 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x33u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2B6u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2B6u: /* 85 18 STA $18 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x18u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA2B8u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2B8u: /* A5 1A LDA $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2BAu;
        instance->instruction_count++;
        return 1;
    case 0x000FA2BAu: /* A6 14 LDX $14 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x14u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2BCu;
        instance->instruction_count++;
        return 1;
    case 0x000FA2BCu: /* 20 60 A3 JSR $A360 */
        if (!tg_push16(instance, 0xA2BEu)) return 0;
        instance->cpu.pc = 0xA360u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2BFu: /* A5 33 LDA $33 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x33u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2C1u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2C1u: /* 85 1C STA $1C */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA2C3u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2C3u: /* A5 12 LDA $12 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x12u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2C5u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2C5u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2C6u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2C6u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2C7u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2C7u: /* 29 FF 01 AND #$01FF */
        word = 0x01FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2CAu;
        instance->instruction_count++;
        return 1;
    case 0x000FA2CAu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2CBu;
        instance->instruction_count++;
        return 1;
    case 0x000FA2CBu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA2CCu;
        instance->instruction_count++;
        return 1;
    case 0x000FA2CCu: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xA2CDu;
        instance->instruction_count++;
        return 1;
    case 0x000FA2CDu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA2CEu;
        instance->instruction_count++;
        return 1;
    case 0x000FA2CEu: /* 69 80 00 ADC #$0080 */
        word = 0x0080u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA2D1u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2D1u: /* 29 FF 01 AND #$01FF */
        word = 0x01FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2D4u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2D4u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA2D5u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2D5u: /* BF 51 AC 0D LDA $0DAC51,X */
        if (!tg_bus_read16(instance, ((0x0DAC51u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2D9u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2D9u: /* A6 18 LDX $18 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x18u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2DBu;
        instance->instruction_count++;
        return 1;
    case 0x000FA2DBu: /* 20 60 A3 JSR $A360 */
        if (!tg_push16(instance, 0xA2DDu)) return 0;
        instance->cpu.pc = 0xA360u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2DEu: /* A5 32 LDA $32 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2E0u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2E0u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA2E1u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2E1u: /* 69 00 20 ADC #$2000 */
        word = 0x2000u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA2E4u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2E4u: /* 85 32 STA $32 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA2E6u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2E6u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2E9u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2E9u: /* 65 34 ADC $34 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x34u) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA2EBu;
        instance->instruction_count++;
        return 1;
    case 0x000FA2EBu: /* 06 32 ASL $32 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2EDu;
        instance->instruction_count++;
        return 1;
    case 0x000FA2EDu: /* 2A ROL A */
        word = instance->cpu.a;
        word = (uint16_t)tg_flag(instance, TG_P_C);
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)((word << 1) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2EEu;
        instance->instruction_count++;
        return 1;
    case 0x000FA2EEu: /* 06 32 ASL $32 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2F0u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2F0u: /* 2A ROL A */
        word = instance->cpu.a;
        word = (uint16_t)tg_flag(instance, TG_P_C);
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)((word << 1) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2F1u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2F1u: /* 85 1E STA $1E */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA2F3u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2F3u: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2F4u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2F4u: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xA2F5u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2F5u: /* BF 51 AC 0D LDA $0DAC51,X */
        if (!tg_bus_read16(instance, ((0x0DAC51u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2F9u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2F9u: /* A6 18 LDX $18 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x18u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA2FBu;
        instance->instruction_count++;
        return 1;
    case 0x000FA2FBu: /* 20 60 A3 JSR $A360 */
        if (!tg_push16(instance, 0xA2FDu)) return 0;
        instance->cpu.pc = 0xA360u;
        instance->instruction_count++;
        return 1;
    case 0x000FA2FEu: /* A5 32 LDA $32 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA300u;
        instance->instruction_count++;
        return 1;
    case 0x000FA300u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA301u;
        instance->instruction_count++;
        return 1;
    case 0x000FA301u: /* 69 00 20 ADC #$2000 */
        word = 0x2000u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA304u;
        instance->instruction_count++;
        return 1;
    case 0x000FA304u: /* 85 32 STA $32 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA306u;
        instance->instruction_count++;
        return 1;
    case 0x000FA306u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA309u;
        instance->instruction_count++;
        return 1;
    case 0x000FA309u: /* 65 34 ADC $34 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x34u) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA30Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA30Bu: /* 06 32 ASL $32 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA30Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA30Du: /* 2A ROL A */
        word = instance->cpu.a;
        word = (uint16_t)tg_flag(instance, TG_P_C);
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)((word << 1) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA30Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA30Eu: /* 06 32 ASL $32 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA310u;
        instance->instruction_count++;
        return 1;
    case 0x000FA310u: /* 2A ROL A */
        word = instance->cpu.a;
        word = (uint16_t)tg_flag(instance, TG_P_C);
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)((word << 1) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA311u;
        instance->instruction_count++;
        return 1;
    case 0x000FA311u: /* 85 20 STA $20 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA313u;
        instance->instruction_count++;
        return 1;
    case 0x000FA313u: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA314u;
        instance->instruction_count++;
        return 1;
    case 0x000FA314u: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xA315u;
        instance->instruction_count++;
        return 1;
    case 0x000FA315u: /* BF 51 AC 0D LDA $0DAC51,X */
        if (!tg_bus_read16(instance, ((0x0DAC51u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA319u;
        instance->instruction_count++;
        return 1;
    case 0x000FA319u: /* 49 FF FF EOR #$FFFF */
        word = 0xFFFFu;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA31Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA31Cu: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA31Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA31Du: /* A6 1C LDX $1C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA31Fu;
        instance->instruction_count++;
        return 1;
    case 0x000FA31Fu: /* 20 60 A3 JSR $A360 */
        if (!tg_push16(instance, 0xA321u)) return 0;
        instance->cpu.pc = 0xA360u;
        instance->instruction_count++;
        return 1;
    case 0x000FA322u: /* A5 32 LDA $32 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA324u;
        instance->instruction_count++;
        return 1;
    case 0x000FA324u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA325u;
        instance->instruction_count++;
        return 1;
    case 0x000FA325u: /* 69 00 20 ADC #$2000 */
        word = 0x2000u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA328u;
        instance->instruction_count++;
        return 1;
    case 0x000FA328u: /* 85 32 STA $32 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA32Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA32Au: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA32Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA32Du: /* 65 34 ADC $34 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x34u) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA32Fu;
        instance->instruction_count++;
        return 1;
    case 0x000FA32Fu: /* 06 32 ASL $32 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA331u;
        instance->instruction_count++;
        return 1;
    case 0x000FA331u: /* 2A ROL A */
        word = instance->cpu.a;
        word = (uint16_t)tg_flag(instance, TG_P_C);
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)((word << 1) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA332u;
        instance->instruction_count++;
        return 1;
    case 0x000FA332u: /* 06 32 ASL $32 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA334u;
        instance->instruction_count++;
        return 1;
    case 0x000FA334u: /* 2A ROL A */
        word = instance->cpu.a;
        word = (uint16_t)tg_flag(instance, TG_P_C);
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)((word << 1) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA335u;
        instance->instruction_count++;
        return 1;
    case 0x000FA335u: /* 85 22 STA $22 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA337u;
        instance->instruction_count++;
        return 1;
    case 0x000FA337u: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA338u;
        instance->instruction_count++;
        return 1;
    case 0x000FA338u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA339u;
        instance->instruction_count++;
        return 1;
    case 0x000FA339u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA33Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA33Au: /* 69 80 00 ADC #$0080 */
        word = 0x0080u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA33Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA33Du: /* 29 FF 01 AND #$01FF */
        word = 0x01FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA340u;
        instance->instruction_count++;
        return 1;
    case 0x000FA340u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA341u;
        instance->instruction_count++;
        return 1;
    case 0x000FA341u: /* BF 51 AC 0D LDA $0DAC51,X */
        if (!tg_bus_read16(instance, ((0x0DAC51u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA345u;
        instance->instruction_count++;
        return 1;
    case 0x000FA345u: /* A6 1C LDX $1C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA347u;
        instance->instruction_count++;
        return 1;
    case 0x000FA347u: /* 20 60 A3 JSR $A360 */
        if (!tg_push16(instance, 0xA349u)) return 0;
        instance->cpu.pc = 0xA360u;
        instance->instruction_count++;
        return 1;
    case 0x000FA34Au: /* A5 32 LDA $32 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA34Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA34Cu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA34Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA34Du: /* 69 00 20 ADC #$2000 */
        word = 0x2000u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA350u;
        instance->instruction_count++;
        return 1;
    case 0x000FA350u: /* 85 32 STA $32 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA352u;
        instance->instruction_count++;
        return 1;
    case 0x000FA352u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA355u;
        instance->instruction_count++;
        return 1;
    case 0x000FA355u: /* 65 34 ADC $34 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x34u) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA357u;
        instance->instruction_count++;
        return 1;
    case 0x000FA357u: /* 06 32 ASL $32 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA359u;
        instance->instruction_count++;
        return 1;
    case 0x000FA359u: /* 2A ROL A */
        word = instance->cpu.a;
        word = (uint16_t)tg_flag(instance, TG_P_C);
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)((word << 1) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA35Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA35Au: /* 06 32 ASL $32 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA35Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA35Cu: /* 2A ROL A */
        word = instance->cpu.a;
        word = (uint16_t)tg_flag(instance, TG_P_C);
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)((word << 1) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA35Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA35Du: /* 85 24 STA $24 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x24u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA35Fu;
        instance->instruction_count++;
        return 1;
    case 0x000FA35Fu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000FA360u: /* C9 00 00 CMP #$0000 */
        word = 0x0000u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xA363u;
        instance->instruction_count++;
        return 1;
    case 0x000FA363u: /* 10 12 BPL $0F:A377 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xA377u : 0xA365u;
        instance->instruction_count++;
        return 1;
    case 0x000FA365u: /* 49 FF FF EOR #$FFFF */
        word = 0xFFFFu;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA368u;
        instance->instruction_count++;
        return 1;
    case 0x000FA368u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA369u;
        instance->instruction_count++;
        return 1;
    case 0x000FA369u: /* 85 2E STA $2E */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x2Eu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA36Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA36Bu: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA36Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA36Cu: /* 10 12 BPL $0F:A380 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xA380u : 0xA36Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA36Eu: /* 49 FF FF EOR #$FFFF */
        word = 0xFFFFu;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA371u;
        instance->instruction_count++;
        return 1;
    case 0x000FA371u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA372u;
        instance->instruction_count++;
        return 1;
    case 0x000FA372u: /* 85 30 STA $30 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x30u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA374u;
        instance->instruction_count++;
        return 1;
    case 0x000FA374u: /* 4C 9B A3 JMP $A39B */
        instance->cpu.pc = 0xA39Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA377u: /* 85 2E STA $2E */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x2Eu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA379u;
        instance->instruction_count++;
        return 1;
    case 0x000FA379u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA37Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA37Au: /* 10 1D BPL $0F:A399 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xA399u : 0xA37Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA37Cu: /* 49 FF FF EOR #$FFFF */
        word = 0xFFFFu;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA37Fu;
        instance->instruction_count++;
        return 1;
    case 0x000FA37Fu: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA380u;
        instance->instruction_count++;
        return 1;
    case 0x000FA380u: /* 85 30 STA $30 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x30u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA382u;
        instance->instruction_count++;
        return 1;
    case 0x000FA382u: /* 20 9B A3 JSR $A39B */
        if (!tg_push16(instance, 0xA384u)) return 0;
        instance->cpu.pc = 0xA39Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA385u: /* A5 32 LDA $32 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA387u;
        instance->instruction_count++;
        return 1;
    case 0x000FA387u: /* A6 34 LDX $34 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x34u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA389u;
        instance->instruction_count++;
        return 1;
    case 0x000FA389u: /* 49 FF FF EOR #$FFFF */
        word = 0xFFFFu;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA38Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA38Cu: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA38Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA38Du: /* 85 32 STA $32 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA38Fu;
        instance->instruction_count++;
        return 1;
    case 0x000FA38Fu: /* D0 01 BNE $0F:A392 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xA392u : 0xA391u;
        instance->instruction_count++;
        return 1;
    case 0x000FA391u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA392u;
        instance->instruction_count++;
        return 1;
    case 0x000FA392u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xA393u;
        instance->instruction_count++;
        return 1;
    case 0x000FA393u: /* 49 FF FF EOR #$FFFF */
        word = 0xFFFFu;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA396u;
        instance->instruction_count++;
        return 1;
    case 0x000FA396u: /* 85 34 STA $34 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x34u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA398u;
        instance->instruction_count++;
        return 1;
    case 0x000FA398u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000FA399u: /* 85 30 STA $30 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x30u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA39Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA39Bu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA39Du;
        instance->instruction_count++;
        return 1;
    case 0x040FA39Du: /* A5 2E LDA $2E */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x2Eu) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA39Fu;
        instance->instruction_count++;
        return 1;
    case 0x040FA39Fu: /* 8D 02 42 STA $4202 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4202u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA3A2u;
        instance->instruction_count++;
        return 1;
    case 0x040FA3A2u: /* A5 30 LDA $30 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x30u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA3A4u;
        instance->instruction_count++;
        return 1;
    case 0x040FA3A4u: /* 8D 03 42 STA $4203 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4203u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA3A7u;
        instance->instruction_count++;
        return 1;
    case 0x040FA3A7u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA3A9u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3A9u: /* EA NOP */
        instance->cpu.pc = 0xA3AAu;
        instance->instruction_count++;
        return 1;
    case 0x000FA3AAu: /* EA NOP */
        instance->cpu.pc = 0xA3ABu;
        instance->instruction_count++;
        return 1;
    case 0x000FA3ABu: /* EA NOP */
        instance->cpu.pc = 0xA3ACu;
        instance->instruction_count++;
        return 1;
    case 0x000FA3ACu: /* AD 16 42 LDA $4216 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4216u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA3AFu;
        instance->instruction_count++;
        return 1;
    case 0x000FA3AFu: /* 85 32 STA $32 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA3B1u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3B1u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA3B3u;
        instance->instruction_count++;
        return 1;
    case 0x040FA3B3u: /* A5 2F LDA $2F */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x2Fu) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA3B5u;
        instance->instruction_count++;
        return 1;
    case 0x040FA3B5u: /* 8D 02 42 STA $4202 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4202u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA3B8u;
        instance->instruction_count++;
        return 1;
    case 0x040FA3B8u: /* A5 31 LDA $31 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x31u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA3BAu;
        instance->instruction_count++;
        return 1;
    case 0x040FA3BAu: /* 8D 03 42 STA $4203 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4203u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA3BDu;
        instance->instruction_count++;
        return 1;
    case 0x040FA3BDu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA3BFu;
        instance->instruction_count++;
        return 1;
    case 0x000FA3BFu: /* EA NOP */
        instance->cpu.pc = 0xA3C0u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3C0u: /* EA NOP */
        instance->cpu.pc = 0xA3C1u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3C1u: /* EA NOP */
        instance->cpu.pc = 0xA3C2u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3C2u: /* AD 16 42 LDA $4216 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4216u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA3C5u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3C5u: /* 85 34 STA $34 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x34u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA3C7u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3C7u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA3C9u;
        instance->instruction_count++;
        return 1;
    case 0x040FA3C9u: /* A5 2F LDA $2F */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x2Fu) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA3CBu;
        instance->instruction_count++;
        return 1;
    case 0x040FA3CBu: /* 8D 02 42 STA $4202 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4202u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA3CEu;
        instance->instruction_count++;
        return 1;
    case 0x040FA3CEu: /* A5 30 LDA $30 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x30u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA3D0u;
        instance->instruction_count++;
        return 1;
    case 0x040FA3D0u: /* 8D 03 42 STA $4203 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4203u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA3D3u;
        instance->instruction_count++;
        return 1;
    case 0x040FA3D3u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA3D5u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3D5u: /* EA NOP */
        instance->cpu.pc = 0xA3D6u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3D6u: /* EA NOP */
        instance->cpu.pc = 0xA3D7u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3D7u: /* EA NOP */
        instance->cpu.pc = 0xA3D8u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3D8u: /* AD 16 42 LDA $4216 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4216u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA3DBu;
        instance->instruction_count++;
        return 1;
    case 0x000FA3DBu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA3DCu;
        instance->instruction_count++;
        return 1;
    case 0x000FA3DCu: /* 65 33 ADC $33 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x33u) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA3DEu;
        instance->instruction_count++;
        return 1;
    case 0x000FA3DEu: /* 85 33 STA $33 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x33u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA3E0u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3E0u: /* 90 02 BCC $0F:A3E4 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xA3E4u : 0xA3E2u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3E2u: /* E6 35 INC $35 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x35u) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word + 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x35u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA3E4u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3E4u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA3E6u;
        instance->instruction_count++;
        return 1;
    case 0x040FA3E6u: /* A5 2E LDA $2E */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x2Eu) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA3E8u;
        instance->instruction_count++;
        return 1;
    case 0x040FA3E8u: /* 8D 02 42 STA $4202 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4202u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA3EBu;
        instance->instruction_count++;
        return 1;
    case 0x040FA3EBu: /* A5 31 LDA $31 */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x31u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA3EDu;
        instance->instruction_count++;
        return 1;
    case 0x040FA3EDu: /* 8D 03 42 STA $4203 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4203u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA3F0u;
        instance->instruction_count++;
        return 1;
    case 0x040FA3F0u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA3F2u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3F2u: /* EA NOP */
        instance->cpu.pc = 0xA3F3u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3F3u: /* EA NOP */
        instance->cpu.pc = 0xA3F4u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3F4u: /* EA NOP */
        instance->cpu.pc = 0xA3F5u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3F5u: /* AD 16 42 LDA $4216 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4216u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA3F8u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3F8u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xA3F9u;
        instance->instruction_count++;
        return 1;
    case 0x000FA3F9u: /* 65 33 ADC $33 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x33u) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xA3FBu;
        instance->instruction_count++;
        return 1;
    case 0x000FA3FBu: /* 85 33 STA $33 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x33u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA3FDu;
        instance->instruction_count++;
        return 1;
    case 0x000FA3FDu: /* 90 02 BCC $0F:A401 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xA401u : 0xA3FFu;
        instance->instruction_count++;
        return 1;
    case 0x000FA3FFu: /* E6 35 INC $35 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x35u) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word + 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x35u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA401u;
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
