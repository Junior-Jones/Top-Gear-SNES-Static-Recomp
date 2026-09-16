/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_03E7(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x000F9C00u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C01u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C01u: /* D0 F9 BNE $0F:9BFC */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9BFCu : 0x9C03u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C03u: /* A9 3F 01 LDA #$013F */
        word = 0x013Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C06u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C06u: /* 8D 4C 04 STA $044C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9C09u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C09u: /* A5 5A LDA $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C0Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C0Bu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C0Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C0Cu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9C0Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9C0Du: /* BF 22 C6 0D LDA $0DC622,X */
        if (!tg_bus_read16(instance, ((0x0DC622u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C11u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C11u: /* 85 83 STA $83 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x83u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9C13u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C13u: /* BF 1A C6 0D LDA $0DC61A,X */
        if (!tg_bus_read16(instance, ((0x0DC61Au + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C17u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C17u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x9C18u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C18u: /* BF 2A C6 0D LDA $0DC62A,X */
        if (!tg_bus_read16(instance, ((0x0DC62Au + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C1Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C1Cu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9C1Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9C1Du: /* BF 00 20 7E LDA $7E2000,X */
        if (!tg_bus_read16(instance, ((0x7E2000u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C21u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C21u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x9C22u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C22u: /* 65 83 ADC $83 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x83u) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x9C24u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C24u: /* 99 6C 0C STA $0C6C,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0C6Cu + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9C27u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C27u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C28u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C28u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C29u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C29u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C2Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9C2Au: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C2Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C2Bu: /* CE 4C 04 DEC $044C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Cu), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Cu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C2Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C2Eu: /* 10 ED BPL $0F:9C1D */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x9C1Du : 0x9C30u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C30u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9C31u: /* 85 46 STA $46 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x46u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9C33u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C33u: /* 20 31 A1 JSR $A131 */
        if (!tg_push16(instance, 0x9C35u)) return 0;
        instance->cpu.pc = 0xA131u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C36u: /* 20 35 9F JSR $9F35 */
        if (!tg_push16(instance, 0x9C38u)) return 0;
        instance->cpu.pc = 0x9F35u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C39u: /* 20 88 9F JSR $9F88 */
        if (!tg_push16(instance, 0x9C3Bu)) return 0;
        instance->cpu.pc = 0x9F88u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C3Cu: /* 20 3E A2 JSR $A23E */
        if (!tg_push16(instance, 0x9C3Eu)) return 0;
        instance->cpu.pc = 0xA23Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C3Fu: /* 4C D7 90 JMP $90D7 */
        instance->cpu.pc = 0x90D7u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C42u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C45u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C45u: /* F0 08 BEQ $0F:9C4F */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9C4Fu : 0x9C47u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C47u: /* A9 00 04 LDA #$0400 */
        word = 0x0400u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C4Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9C4Au: /* D0 03 BNE $0F:9C4F */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9C4Fu : 0x9C4Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C4Cu: /* A9 00 08 LDA #$0800 */
        word = 0x0800u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C4Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C4Fu: /* A2 00 04 LDX #$0400 */
        word = 0x0400u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C52u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C52u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9C55u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C55u: /* 9C 18 21 STZ $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), 0u)) return 0;
        instance->cpu.pc = 0x9C58u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C58u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C59u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C59u: /* D0 FA BNE $0F:9C55 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9C55u : 0x9C5Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C5Bu: /* A2 FE 0F LDX #$0FFE */
        word = 0x0FFEu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C5Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C5Eu: /* 9E 6C 0C STZ $0C6C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0C6Cu + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x9C61u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C61u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C62u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C62u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C63u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C63u: /* 10 F9 BPL $0F:9C5E */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x9C5Eu : 0x9C65u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C65u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9C66u: /* 9C 26 04 STZ $0426 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0426u), 0u)) return 0;
        instance->cpu.pc = 0x9C69u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C69u: /* A2 FE 05 LDX #$05FE */
        word = 0x05FEu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C6Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C6Cu: /* 9E 6C 06 STZ $066C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x066Cu + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x9C6Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C6Fu: /* 9E 6C 14 STZ $146C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x146Cu + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x9C72u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C72u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C73u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C73u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C74u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C74u: /* 10 F6 BPL $0F:9C6C */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x9C6Cu : 0x9C76u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C76u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9C77u: /* 20 66 9C JSR $9C66 */
        if (!tg_push16(instance, 0x9C79u)) return 0;
        instance->cpu.pc = 0x9C66u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C7Au: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C7Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9C7Du: /* 9B TXY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x9C7Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C7Eu: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x9C7Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C7Fu: /* AE 26 04 LDX $0426 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0426u), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C82u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C82u: /* BD 2C 04 LDA $042C,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x042Cu + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C85u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C85u: /* D0 0D BNE $0F:9C94 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9C94u : 0x9C87u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C87u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C88u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C88u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x9C89u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C89u: /* 69 20 00 ADC #$0020 */
        word = 0x0020u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x9C8Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C8Cu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9C8Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9C8Du: /* 98 TYA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.y);
        tg_set_nz16(instance, (uint16_t)instance->cpu.a);
        instance->cpu.pc = 0x9C8Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C8Eu: /* 69 60 00 ADC #$0060 */
        word = 0x0060u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x9C91u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C91u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x9C92u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C92u: /* 80 04 BRA $0F:9C98 */
        instance->cpu.pc = 0x9C98u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C94u: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C95u;
        instance->instruction_count++;
        return 1;
    case 0x000F9C95u: /* 20 BC 9C JSR $9CBC */
        if (!tg_push16(instance, 0x9C97u)) return 0;
        instance->cpu.pc = 0x9CBCu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C98u: /* EE 26 04 INC $0426 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0426u), &word)) return 0;
        word = (uint16_t)(word + 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0426u), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C9Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C9Bu: /* EE 26 04 INC $0426 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0426u), &word)) return 0;
        word = (uint16_t)(word + 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0426u), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C9Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9C9Eu: /* E0 00 02 CPX #$0200 */
        word = 0x0200u;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0x9CA1u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CA1u: /* 90 DB BCC $0F:9C7E */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x9C7Eu : 0x9CA3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CA3u: /* AD 22 04 LDA $0422 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0422u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CA6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CA6u: /* F0 13 BEQ $0F:9CBB */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9CBBu : 0x9CA8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CA8u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CA9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CA9u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CAAu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CAAu: /* 30 0F BMI $0F:9CBB */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0x9CBBu : 0x9CACu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CACu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x9CADu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CADu: /* B9 6C 06 LDA $066C,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x066Cu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CB0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CB0u: /* 49 FF FF EOR #$FFFF */
        word = 0xFFFFu;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CB3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CB3u: /* 69 01 00 ADC #$0001 */
        word = 0x0001u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x9CB6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CB6u: /* 99 6C 06 STA $066C,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x066Cu + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9CB9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CB9u: /* 80 ED BRA $0F:9CA8 */
        instance->cpu.pc = 0x9CA8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CBBu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9CBCu: /* A9 0F 00 LDA #$000F */
        word = 0x000Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CBFu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CBFu: /* 8D 2A 04 STA $042A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x042Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9CC2u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CC2u: /* BD 6C 04 LDA $046C,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x046Cu + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CC5u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CC5u: /* 29 1F 00 AND #$001F */
        word = 0x001Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CC8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CC8u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CC9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CC9u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CCAu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CCAu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CCBu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CCBu: /* 99 6C 06 STA $066C,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x066Cu + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9CCEu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CCEu: /* BD 6C 04 LDA $046C,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x046Cu + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CD1u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CD1u: /* 29 E0 03 AND #$03E0 */
        word = 0x03E0u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CD4u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CD4u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CD5u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CD5u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CD6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CD6u: /* 99 6E 06 STA $066E,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x066Eu + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9CD9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CD9u: /* BD 6C 04 LDA $046C,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x046Cu + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CDCu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CDCu: /* 29 00 7C AND #$7C00 */
        word = 0x7C00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CDFu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CDFu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CE0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CE0u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0x9CE1u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CE1u: /* 99 70 06 STA $0670,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0670u + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9CE4u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CE4u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CE5u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CE5u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CE6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CE6u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CE7u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CE7u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CE8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CE8u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CE9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CE9u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CEAu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CEAu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CEBu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CEBu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CECu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CECu: /* CE 2A 04 DEC $042A */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x042Au), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x042Au), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CEFu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CEFu: /* 10 D1 BPL $0F:9CC2 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x9CC2u : 0x9CF1u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CF1u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9CF2u: /* A9 20 00 LDA #$0020 */
        word = 0x0020u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CF5u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CF5u: /* 8D 26 04 STA $0426 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0426u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9CF8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9CF8u: /* A9 20 00 LDA #$0020 */
        word = 0x0020u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9CFBu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CFBu: /* 8D 2A 04 STA $042A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x042Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9CFEu;
        instance->instruction_count++;
        return 1;
    case 0x000F9CFEu: /* CE 2A 04 DEC $042A */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x042Au), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x042Au), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D01u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D01u: /* CE 2A 04 DEC $042A */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x042Au), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x042Au), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D04u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D04u: /* 30 1C BMI $0F:9D22 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0x9D22u : 0x9D06u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D06u: /* AE 2A 04 LDX $042A */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x042Au), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D09u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D09u: /* BD 2C 04 LDA $042C,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x042Cu + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D0Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D0Cu: /* F0 F0 BEQ $0F:9CFE */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9CFEu : 0x9D0Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D0Eu: /* BC D4 B4 LDY $B4D4,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xB4D4u + instance->cpu.x)), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D11u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D11u: /* BF FA C5 0D LDA $0DC5FA,X */
        if (!tg_bus_read16(instance, ((0x0DC5FAu + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D15u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D15u: /* 8D 28 04 STA $0428 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0428u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9D18u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D18u: /* BF F8 C5 0D LDA $0DC5F8,X */
        if (!tg_bus_read16(instance, ((0x0DC5F8u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D1Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D1Cu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9D1Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9D1Du: /* 20 31 9D JSR $9D31 */
        if (!tg_push16(instance, 0x9D1Fu)) return 0;
        instance->cpu.pc = 0x9D31u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D20u: /* 80 DC BRA $0F:9CFE */
        instance->cpu.pc = 0x9CFEu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D22u: /* A9 4C 00 LDA #$004C */
        word = 0x004Cu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D25u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D25u: /* 85 90 STA $90 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x90u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9D27u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D27u: /* A5 90 LDA $90 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x90u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D29u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D29u: /* D0 FC BNE $0F:9D27 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9D27u : 0x9D2Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D2Bu: /* CE 26 04 DEC $0426 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0426u), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0426u), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D2Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D2Eu: /* D0 C8 BNE $0F:9CF8 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9CF8u : 0x9D30u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D30u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9D31u: /* BD 6C 04 LDA $046C,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x046Cu + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D34u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D34u: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9D35u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D35u: /* 29 E0 FF AND #$FFE0 */
        word = 0xFFE0u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D38u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D38u: /* 9D 6C 04 STA $046C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x046Cu + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9D3Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D3Bu: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D3Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D3Cu: /* 29 1F 00 AND #$001F */
        word = 0x001Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D3Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D3Fu: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0x9D40u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D40u: /* 19 6C 14 ORA $146C,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x146Cu + instance->cpu.y)), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D43u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D43u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x9D44u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D44u: /* 79 6C 06 ADC $066C,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x066Cu + instance->cpu.y)), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x9D47u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D47u: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9D48u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D48u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D4Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D4Bu: /* 99 6C 14 STA $146C,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x146Cu + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9D4Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D4Eu: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D4Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D4Fu: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0x9D50u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D50u: /* 29 1F 00 AND #$001F */
        word = 0x001Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D53u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D53u: /* 1D 6C 04 ORA $046C,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x046Cu + instance->cpu.x)), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D56u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D56u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D57u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D57u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D58u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D58u: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9D59u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D59u: /* 29 1F FC AND #$FC1F */
        word = 0xFC1Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D5Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D5Cu: /* 9D 6C 04 STA $046C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x046Cu + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9D5Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D5Fu: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D60u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D60u: /* 29 E0 03 AND #$03E0 */
        word = 0x03E0u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D63u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D63u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D64u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D64u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D65u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D65u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D66u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D66u: /* 19 6C 14 ORA $146C,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x146Cu + instance->cpu.y)), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D69u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D69u: /* 79 6C 06 ADC $066C,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x066Cu + instance->cpu.y)), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x9D6Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D6Cu: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9D6Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9D6Du: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D70u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D70u: /* 99 6C 14 STA $146C,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x146Cu + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9D73u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D73u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D74u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D74u: /* 29 00 1F AND #$1F00 */
        word = 0x1F00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D77u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D77u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D78u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D78u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D79u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D79u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D7Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9D7Au: /* 1D 6C 04 ORA $046C,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x046Cu + instance->cpu.x)), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D7Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9D7Du: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D7Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D7Eu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D7Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D7Fu: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9D80u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D80u: /* 29 FF 83 AND #$83FF */
        word = 0x83FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D83u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D83u: /* 9D 6C 04 STA $046C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x046Cu + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9D86u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D86u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D87u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D87u: /* 29 00 7C AND #$7C00 */
        word = 0x7C00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D8Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9D8Au: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D8Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D8Bu: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D8Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D8Cu: /* 19 6C 14 ORA $146C,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x146Cu + instance->cpu.y)), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D8Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D8Fu: /* 79 6C 06 ADC $066C,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x066Cu + instance->cpu.y)), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x9D92u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D92u: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9D93u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D93u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D96u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D96u: /* 99 6C 14 STA $146C,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x146Cu + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9D99u;
        instance->instruction_count++;
        return 1;
    case 0x000F9D99u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D9Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9D9Au: /* 29 00 1F AND #$1F00 */
        word = 0x1F00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D9Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9D9Du: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D9Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D9Eu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9D9Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9D9Fu: /* 1D 6C 04 ORA $046C,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x046Cu + instance->cpu.x)), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9DA2u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DA2u: /* 9D 6C 04 STA $046C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x046Cu + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9DA5u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DA5u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9DA6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DA6u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9DA7u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DA7u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9DA8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DA8u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9DA9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DA9u: /* EC 28 04 CPX $0428 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0428u), &word)) return 0;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0x9DACu;
        instance->instruction_count++;
        return 1;
    case 0x000F9DACu: /* F0 03 BEQ $0F:9DB1 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9DB1u : 0x9DAEu;
        instance->instruction_count++;
        return 1;
    case 0x000F9DAEu: /* 4C 31 9D JMP $9D31 */
        instance->cpu.pc = 0x9D31u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DB1u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9DB2u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9DB4u;
        instance->instruction_count++;
        return 1;
    case 0x040F9DB4u: /* A9 20 LDA #$20 */
        byte = 0x20u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x9DB6u;
        instance->instruction_count++;
        return 1;
    case 0x040F9DB6u: /* 8D 31 21 STA $2131 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2131u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x9DB9u;
        instance->instruction_count++;
        return 1;
    case 0x040F9DB9u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9DBBu;
        instance->instruction_count++;
        return 1;
    case 0x000F9DBBu: /* A9 0F 00 LDA #$000F */
        word = 0x000Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9DBEu;
        instance->instruction_count++;
        return 1;
    case 0x000F9DBEu: /* 85 42 STA $42 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x42u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9DC0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DC0u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9DC3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DC3u: /* 80 0C BRA $0F:9DD1 */
        instance->cpu.pc = 0x9DD1u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DC5u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9DC7u;
        instance->instruction_count++;
        return 1;
    case 0x040F9DC7u: /* A9 20 LDA #$20 */
        byte = 0x20u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x9DC9u;
        instance->instruction_count++;
        return 1;
    case 0x040F9DC9u: /* 8D 31 21 STA $2131 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2131u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x9DCCu;
        instance->instruction_count++;
        return 1;
    case 0x040F9DCCu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9DCEu;
        instance->instruction_count++;
        return 1;
    case 0x000F9DCEu: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9DD1u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DD1u: /* 8D 22 04 STA $0422 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0422u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9DD4u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DD4u: /* 20 77 9C JSR $9C77 */
        if (!tg_push16(instance, 0x9DD6u)) return 0;
        instance->cpu.pc = 0x9C77u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DD7u: /* 20 5E 9E JSR $9E5E */
        if (!tg_push16(instance, 0x9DD9u)) return 0;
        instance->cpu.pc = 0x9E5Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9DDAu: /* 4C F2 9C JMP $9CF2 */
        instance->cpu.pc = 0x9CF2u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DDDu: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9DE0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DE0u: /* 8D 02 21 STA $2102 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2102u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9DE3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DE3u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9DE5u;
        instance->instruction_count++;
        return 1;
    case 0x040F9DE5u: /* 8D 74 43 STA $4374 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x9DE8u;
        instance->instruction_count++;
        return 1;
    case 0x040F9DE8u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9DEAu;
        instance->instruction_count++;
        return 1;
    case 0x000F9DEAu: /* A9 02 04 LDA #$0402 */
        word = 0x0402u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9DEDu;
        instance->instruction_count++;
        return 1;
    case 0x000F9DEDu: /* 8D 70 43 STA $4370 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9DF0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DF0u: /* A9 02 02 LDA #$0202 */
        word = 0x0202u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9DF3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DF3u: /* 8D 72 43 STA $4372 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9DF6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DF6u: /* A9 20 02 LDA #$0220 */
        word = 0x0220u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9DF9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9DF9u: /* 8D 75 43 STA $4375 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9DFCu;
        instance->instruction_count++;
        return 1;
    case 0x000F9DFCu: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9DFFu;
        instance->instruction_count++;
        return 1;
    case 0x000F9DFFu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9E02u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E02u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9E04u;
        instance->instruction_count++;
        return 1;
    case 0x040F9E04u: /* 8D 24 43 STA $4324 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4324u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x9E07u;
        instance->instruction_count++;
        return 1;
    case 0x040F9E07u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9E09u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E09u: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E0Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E0Cu: /* 8D 20 43 STA $4320 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4320u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9E0Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E0Fu: /* A9 6C 0C LDA #$0C6C */
        word = 0x0C6Cu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E12u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E12u: /* 8D 22 43 STA $4322 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4322u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9E15u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E15u: /* A9 00 10 LDA #$1000 */
        word = 0x1000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E18u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E18u: /* 8D 25 43 STA $4325 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4325u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9E1Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E1Bu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9E1Cu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9E1Eu;
        instance->instruction_count++;
        return 1;
    case 0x040F9E1Eu: /* A9 80 LDA #$80 */
        byte = 0x80u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x9E20u;
        instance->instruction_count++;
        return 1;
    case 0x040F9E20u: /* 8D 15 21 STA $2115 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2115u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x9E23u;
        instance->instruction_count++;
        return 1;
    case 0x040F9E23u: /* A9 0F LDA #$0F */
        byte = 0x0Fu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x9E25u;
        instance->instruction_count++;
        return 1;
    case 0x040F9E25u: /* 8D 14 43 STA $4314 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4314u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x9E28u;
        instance->instruction_count++;
        return 1;
    case 0x040F9E28u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9E2Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9E2Au: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E2Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9E2Du: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9E30u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E30u: /* A9 2B 9E LDA #$9E2B */
        word = 0x9E2Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E33u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E33u: /* 8D 12 43 STA $4312 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4312u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9E36u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E36u: /* A9 00 10 LDA #$1000 */
        word = 0x1000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E39u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E39u: /* 8D 15 43 STA $4315 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4315u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9E3Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E3Cu: /* A9 09 18 LDA #$1809 */
        word = 0x1809u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E3Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E3Fu: /* 8D 10 43 STA $4310 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4310u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9E42u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E42u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E45u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E45u: /* A2 FE 07 LDX #$07FE */
        word = 0x07FEu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E48u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E48u: /* 9D 6C 0C STA $0C6C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0C6Cu + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9E4Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E4Bu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E4Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E4Cu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E4Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9E4Du: /* D0 F9 BNE $0F:9E48 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9E48u : 0x9E4Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E4Fu: /* 8D 6C 0C STA $0C6C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0C6Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9E52u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E52u: /* A9 02 00 LDA #$0002 */
        word = 0x0002u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E55u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E55u: /* 8D 24 04 STA $0424 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9E58u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E58u: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E5Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E5Bu: /* 4C 4D A2 JMP $A24D */
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9E5Eu: /* AD 22 04 LDA $0422 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0422u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E61u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E61u: /* D0 24 BNE $0F:9E87 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9E87u : 0x9E63u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E63u: /* A0 1E 00 LDY #$001E */
        word = 0x001Eu;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E66u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E66u: /* A2 FE 01 LDX #$01FE */
        word = 0x01FEu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E69u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E69u: /* B9 2C 04 LDA $042C,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x042Cu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E6Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E6Cu: /* D0 08 BNE $0F:9E76 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9E76u : 0x9E6Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E6Eu: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9E6Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E6Fu: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0x9E70u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E70u: /* E9 20 00 SBC #$0020 */
        word = 0x0020u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0x9E73u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E73u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9E74u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E74u: /* 80 0D BRA $0F:9E83 */
        instance->cpu.pc = 0x9E83u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E76u: /* 5A PHY */
        if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0x9E77u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E77u: /* A0 10 00 LDY #$0010 */
        word = 0x0010u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E7Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9E7Au: /* 9E 6C 04 STZ $046C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x046Cu + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x9E7Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9E7Du: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E7Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E7Eu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E7Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E7Fu: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E80u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E80u: /* D0 F8 BNE $0F:9E7A */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9E7Au : 0x9E82u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E82u: /* 7A PLY */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E83u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E83u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E84u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E84u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E85u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E85u: /* 10 E2 BPL $0F:9E69 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x9E69u : 0x9E87u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E87u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9E88u: /* A2 00 02 LDX #$0200 */
        word = 0x0200u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E8Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E8Bu: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E8Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9E8Eu: /* 20 4D A2 JSR $A24D */
        if (!tg_push16(instance, 0x9E90u)) return 0;
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9E91u: /* A5 0A LDA $0A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E93u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E93u: /* 05 0C ORA $0C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Cu) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E95u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E95u: /* D0 03 BNE $0F:9E9A */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9E9Au : 0x9E97u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E97u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E98u;
        instance->instruction_count++;
        return 1;
    case 0x000F9E98u: /* D0 F1 BNE $0F:9E8B */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9E8Bu : 0x9E9Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9E9Au: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9E9Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9E9Du: /* 20 4D A2 JSR $A24D */
        if (!tg_push16(instance, 0x9E9Fu)) return 0;
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9EA0u: /* A5 0A LDA $0A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EA2u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EA2u: /* 05 0C ORA $0C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Cu) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EA4u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EA4u: /* D0 F4 BNE $0F:9E9A */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9E9Au : 0x9EA6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EA6u: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EA9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EA9u: /* 4C 4D A2 JMP $A24D */
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9EACu: /* A2 00 06 LDX #$0600 */
        word = 0x0600u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EAFu;
        instance->instruction_count++;
        return 1;
    case 0x000F9EAFu: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EB2u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EB2u: /* 20 4D A2 JSR $A24D */
        if (!tg_push16(instance, 0x9EB4u)) return 0;
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9EB5u: /* A5 0A LDA $0A */
        if(instance->mod_continue_screen==2u){instance->cpu.pc=tg_mod_continue_poll(instance)?0x9EBEu:0x9EAFu;instance->instruction_count++;return 1;}
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EB7u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EB7u: /* 05 0C ORA $0C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Cu) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EB9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EB9u: /* D0 03 BNE $0F:9EBE */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9EBEu : 0x9EBBu;
        instance->instruction_count++;
        return 1;
    case 0x000F9EBBu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EBCu;
        instance->instruction_count++;
        return 1;
    case 0x000F9EBCu: /* D0 F1 BNE $0F:9EAF */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9EAFu : 0x9EBEu;
        instance->instruction_count++;
        return 1;
    case 0x000F9EBEu: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EC1u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EC1u: /* 20 4D A2 JSR $A24D */
        if (!tg_push16(instance, 0x9EC3u)) return 0;
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9EC4u: /* A5 0A LDA $0A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EC6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EC6u: /* 05 0C ORA $0C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Cu) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EC8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EC8u: /* D0 F4 BNE $0F:9EBE */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9EBEu : 0x9ECAu;
        instance->instruction_count++;
        return 1;
    case 0x000F9ECAu: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9ECDu;
        instance->instruction_count++;
        return 1;
    case 0x000F9ECDu: /* 4C 4D A2 JMP $A24D */
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9ED0u: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9ED3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9ED3u: /* BD 00 00 LDA $0000,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9ED6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9ED6u: /* F0 54 BEQ $0F:9F2C */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9F2Cu : 0x9ED8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9ED8u: /* 85 48 STA $48 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9EDAu;
        instance->instruction_count++;
        return 1;
    case 0x000F9EDAu: /* 20 C4 A1 JSR $A1C4 */
        if (!tg_push16(instance, 0x9EDCu)) return 0;
        instance->cpu.pc = 0xA1C4u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EDDu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EDEu;
        instance->instruction_count++;
        return 1;
    case 0x000F9EDEu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EDFu;
        instance->instruction_count++;
        return 1;
    case 0x000F9EDFu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x9EE0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EE0u: /* BD 00 00 LDA $0000,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EE3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EE3u: /* 65 58 ADC $58 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x58u) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x9EE5u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EE5u: /* 99 02 02 STA $0202,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0202u + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9EE8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EE8u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EEBu;
        instance->instruction_count++;
        return 1;
    case 0x000F9EEBu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9EEDu;
        instance->instruction_count++;
        return 1;
    case 0x040F9EEDu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EEEu;
        instance->instruction_count++;
        return 1;
    case 0x040F9EEEu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EEFu;
        instance->instruction_count++;
        return 1;
    case 0x040F9EEFu: /* BD 00 00 LDA $0000,X */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.x)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x9EF2u;
        instance->instruction_count++;
        return 1;
    case 0x040F9EF2u: /* F0 33 BEQ $0F:9F27 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9F27u : 0x9EF4u;
        instance->instruction_count++;
        return 1;
    case 0x040F9EF4u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9EF6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EF6u: /* C9 21 00 CMP #$0021 */
        word = 0x0021u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x9EF9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9EF9u: /* B0 05 BCS $0F:9F00 */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x9F00u : 0x9EFBu;
        instance->instruction_count++;
        return 1;
    case 0x000F9EFBu: /* A9 00 01 LDA #$0100 */
        word = 0x0100u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9EFEu;
        instance->instruction_count++;
        return 1;
    case 0x000F9EFEu: /* D0 0C BNE $0F:9F0C */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9F0Cu : 0x9F00u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F00u: /* C9 41 00 CMP #$0041 */
        word = 0x0041u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x9F03u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F03u: /* B0 03 BCS $0F:9F08 */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x9F08u : 0x9F05u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F05u: /* 69 2C 00 ADC #$002C */
        word = 0x002Cu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x9F08u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F08u: /* 69 BE 00 ADC #$00BE */
        word = 0x00BEu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x9F0Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F0Bu: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F0Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F0Cu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F0Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9F0Du: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F0Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F0Eu: /* 09 00 3E ORA #$3E00 */
        word = 0x3E00u;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F11u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F11u: /* 99 02 02 STA $0202,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0202u + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9F14u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F14u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F15u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F15u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F16u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F16u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x9F17u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F17u: /* B9 FE 01 LDA $01FE,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x01FEu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F1Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9F1Au: /* 69 08 00 ADC #$0008 */
        word = 0x0008u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x9F1Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9F1Du: /* 99 02 02 STA $0202,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0202u + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9F20u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F20u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F23u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F23u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9F25u;
        instance->instruction_count++;
        return 1;
    case 0x040F9F25u: /* 80 C7 BRA $0F:9EEE */
        instance->cpu.pc = 0x9EEEu;
        instance->instruction_count++;
        return 1;
    case 0x040F9F27u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9F29u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F29u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F2Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9F2Au: /* D0 A7 BNE $0F:9ED3 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9ED3u : 0x9F2Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F2Cu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9F2Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F2Eu: /* A9 00 F0 LDA #$F000 */
        word = 0xF000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F31u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F31u: /* 99 02 02 STA $0202,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0202u + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9F34u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F34u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9F35u: /* A5 46 LDA $46 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x46u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F37u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F37u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F38u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F38u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9F39u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F39u: /* BF 16 C7 0D LDA $0DC716,X */
        if (!tg_bus_read16(instance, ((0x0DC716u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F3Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9F3Du: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9F3Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F3Eu: /* BD 00 00 LDA $0000,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F41u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F41u: /* F0 42 BEQ $0F:9F85 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9F85u : 0x9F43u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F43u: /* 85 48 STA $48 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9F45u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F45u: /* 20 D0 A1 JSR $A1D0 */
        if (!tg_push16(instance, 0x9F47u)) return 0;
        instance->cpu.pc = 0xA1D0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F48u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F4Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F4Bu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9F4Du;
        instance->instruction_count++;
        return 1;
    case 0x040F9F4Du: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F4Eu;
        instance->instruction_count++;
        return 1;
    case 0x040F9F4Eu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F4Fu;
        instance->instruction_count++;
        return 1;
    case 0x040F9F4Fu: /* BD 00 00 LDA $0000,X */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.x)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x9F52u;
        instance->instruction_count++;
        return 1;
    case 0x040F9F52u: /* F0 2C BEQ $0F:9F80 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9F80u : 0x9F54u;
        instance->instruction_count++;
        return 1;
    case 0x040F9F54u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9F56u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F56u: /* C9 21 00 CMP #$0021 */
        word = 0x0021u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x9F59u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F59u: /* B0 05 BCS $0F:9F60 */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x9F60u : 0x9F5Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F5Bu: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F5Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F5Eu: /* F0 10 BEQ $0F:9F70 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9F70u : 0x9F60u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F60u: /* C9 41 00 CMP #$0041 */
        word = 0x0041u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x9F63u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F63u: /* B0 03 BCS $0F:9F68 */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x9F68u : 0x9F65u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F65u: /* 69 2C 00 ADC #$002C */
        word = 0x002Cu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x9F68u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F68u: /* 69 BE 00 ADC #$00BE */
        word = 0x00BEu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x9F6Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F6Bu: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F6Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F6Cu: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0x9F6Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9F6Du: /* E9 00 01 SBC #$0100 */
        word = 0x0100u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0x9F70u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F70u: /* A4 4C LDY $4C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x4Cu) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F72u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F72u: /* 99 00 00 STA $0000,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9F75u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F75u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F76u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F76u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F77u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F77u: /* 84 4C STY $4C */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x4Cu) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0x9F79u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F79u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F7Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F7Cu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9F7Eu;
        instance->instruction_count++;
        return 1;
    case 0x040F9F7Eu: /* 80 CE BRA $0F:9F4E */
        instance->cpu.pc = 0x9F4Eu;
        instance->instruction_count++;
        return 1;
    case 0x040F9F80u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9F82u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F82u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F83u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F83u: /* D0 B9 BNE $0F:9F3E */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9F3Eu : 0x9F85u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F85u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9F87u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F87u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9F88u: /* C2 30 REP #$30 */
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9F8Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9F8Au: /* A5 46 LDA $46 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x46u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F8Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F8Cu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F8Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9F8Du: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9F8Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F8Eu: /* BF 38 C7 0D LDA $0DC738,X */
        if (!tg_bus_read16(instance, ((0x0DC738u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F92u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F92u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9F93u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F93u: /* 64 54 STZ $54 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x54u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x9F95u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F95u: /* BD 00 00 LDA $0000,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9F98u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F98u: /* D0 03 BNE $0F:9F9D */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9F9Du : 0x9F9Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9F9Au: /* 4C 42 A0 JMP $A042 */
        instance->cpu.pc = 0xA042u;
        instance->instruction_count++;
        return 1;
    case 0x000F9F9Du: /* 85 48 STA $48 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9F9Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9F9Fu: /* 20 D0 A1 JSR $A1D0 */
        if (!tg_push16(instance, 0x9FA1u)) return 0;
        instance->cpu.pc = 0xA1D0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FA2u: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9FA3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FA3u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9FA5u;
        instance->instruction_count++;
        return 1;
    case 0x040F9FA5u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FA6u;
        instance->instruction_count++;
        return 1;
    case 0x040F9FA6u: /* 86 56 STX $56 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x56u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x9FA8u;
        instance->instruction_count++;
        return 1;
    case 0x040F9FA8u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FA9u;
        instance->instruction_count++;
        return 1;
    case 0x040F9FA9u: /* BD 00 00 LDA $0000,X */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.x)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x9FACu;
        instance->instruction_count++;
        return 1;
    case 0x040F9FACu: /* F0 77 BEQ $0F:A025 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xA025u : 0x9FAEu;
        instance->instruction_count++;
        return 1;
    case 0x040F9FAEu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9FB0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FB0u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FB3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FB3u: /* C9 A0 00 CMP #$00A0 */
        word = 0x00A0u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x9FB6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FB6u: /* 90 1B BCC $0F:9FD3 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x9FD3u : 0x9FB8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FB8u: /* C9 FF 00 CMP #$00FF */
        word = 0x00FFu;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x9FBBu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FBBu: /* D0 08 BNE $0F:9FC5 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9FC5u : 0x9FBDu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FBDu: /* A5 54 LDA $54 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x54u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FBFu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FBFu: /* D0 60 BNE $0F:A021 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xA021u : 0x9FC1u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FC1u: /* E6 44 INC $44 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x44u) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word + 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x44u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FC3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FC3u: /* 80 5C BRA $0F:A021 */
        instance->cpu.pc = 0xA021u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FC5u: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x9FC6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FC6u: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9FC7u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FC7u: /* A5 44 LDA $44 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x44u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FC9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FC9u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FCAu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FCAu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9FCBu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FCBu: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FCCu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FCCu: /* 1F E0 C5 0D ORA $0DC5E0,X */
        if (!tg_bus_read16(instance, ((0x0DC5E0u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FD0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FD0u: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FD1u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FD1u: /* 80 36 BRA $0F:A009 */
        instance->cpu.pc = 0xA009u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FD3u: /* C9 20 00 CMP #$0020 */
        word = 0x0020u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x9FD6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FD6u: /* F0 15 BEQ $0F:9FED */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9FEDu : 0x9FD8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FD8u: /* B0 18 BCS $0F:9FF2 */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x9FF2u : 0x9FDAu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FDAu: /* BD 00 00 LDA $0000,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0000u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FDDu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FDDu: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x9FDEu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FDEu: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0x9FDFu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FDFu: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9FE0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FE0u: /* A5 44 LDA $44 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x44u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FE2u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FE2u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FE3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FE3u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9FE4u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FE4u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FE5u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FE5u: /* 1F E0 C5 0D ORA $0DC5E0,X */
        if (!tg_bus_read16(instance, ((0x0DC5E0u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FE9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FE9u: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FEAu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FEAu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FEBu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FEBu: /* 80 1C BRA $0F:A009 */
        instance->cpu.pc = 0xA009u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FEDu: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9FF0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FF0u: /* F0 0D BEQ $0F:9FFF */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9FFFu : 0x9FF2u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FF2u: /* C9 3B 00 CMP #$003B */
        word = 0x003Bu;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x9FF5u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FF5u: /* B0 05 BCS $0F:9FFC */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x9FFCu : 0x9FF7u;
        instance->instruction_count++;
        return 1;
    case 0x000F9FF7u: /* E9 14 00 SBC #$0014 */
        word = 0x0014u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0x9FFAu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FFAu: /* D0 03 BNE $0F:9FFF */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9FFFu : 0x9FFCu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FFCu: /* E9 40 00 SBC #$0040 */
        word = 0x0040u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0x9FFFu;
        instance->instruction_count++;
        return 1;
    case 0x000F9FFFu: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xA000u;
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
