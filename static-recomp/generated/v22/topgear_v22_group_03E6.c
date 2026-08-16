/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_03E6(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x000F9802u: /* 20 D7 90 JSR $90D7 */
        if (!tg_push16(instance, 0x9804u)) return 0;
        instance->cpu.pc = 0x90D7u;
        instance->instruction_count++;
        return 1;
    case 0x000F9805u: /* 20 0E 82 JSR $820E */
        if (!tg_push16(instance, 0x9807u)) return 0;
        instance->cpu.pc = 0x820Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9808u: /* A9 04 00 LDA #$0004 */
        word = 0x0004u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x980Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F980Bu: /* 20 31 9C JSR $9C31 */
        if (!tg_push16(instance, 0x980Du)) return 0;
        instance->cpu.pc = 0x9C31u;
        instance->instruction_count++;
        return 1;
    case 0x000F980Eu: /* 20 70 9B JSR $9B70 */
        if (!tg_push16(instance, 0x9810u)) return 0;
        instance->cpu.pc = 0x9B70u;
        instance->instruction_count++;
        return 1;
    case 0x000F9811u: /* A2 66 00 LDX #$0066 */
        word = 0x0066u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9814u;
        instance->instruction_count++;
        return 1;
    case 0x000F9814u: /* 20 93 9F JSR $9F93 */
        if (!tg_push16(instance, 0x9816u)) return 0;
        instance->cpu.pc = 0x9F93u;
        instance->instruction_count++;
        return 1;
    case 0x000F9817u: /* A4 81 LDY $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9819u;
        instance->instruction_count++;
        return 1;
    case 0x000F9819u: /* F0 0D BEQ $0F:9828 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9828u : 0x981Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F981Bu: /* AD 97 1F LDA $1F97 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F97u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x981Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F981Eu: /* 0D 99 1F ORA $1F99 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F99u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9821u;
        instance->instruction_count++;
        return 1;
    case 0x000F9821u: /* F0 10 BEQ $0F:9833 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9833u : 0x9823u;
        instance->instruction_count++;
        return 1;
    case 0x000F9823u: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9826u;
        instance->instruction_count++;
        return 1;
    case 0x000F9826u: /* D0 0B BNE $0F:9833 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9833u : 0x9828u;
        instance->instruction_count++;
        return 1;
    case 0x000F9828u: /* AD 7A 1F LDA $1F7A */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F7Au), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x982Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F982Bu: /* 0D 7C 1F ORA $1F7C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F7Cu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x982Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F982Eu: /* F0 03 BEQ $0F:9833 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9833u : 0x9830u;
        instance->instruction_count++;
        return 1;
    case 0x000F9830u: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9833u;
        instance->instruction_count++;
        return 1;
    case 0x000F9833u: /* 49 01 00 EOR #$0001 */
        word = 0x0001u;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9836u;
        instance->instruction_count++;
        return 1;
    case 0x000F9836u: /* 85 5A STA $5A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9838u;
        instance->instruction_count++;
        return 1;
    case 0x000F9838u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9839u;
        instance->instruction_count++;
        return 1;
    case 0x000F9839u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x983Au;
        instance->instruction_count++;
        return 1;
    case 0x000F983Au: /* B9 5C A8 LDA $A85C,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xA85Cu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x983Du;
        instance->instruction_count++;
        return 1;
    case 0x000F983Du: /* 85 48 STA $48 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x983Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F983Fu: /* B9 60 A8 LDA $A860,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xA860u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9842u;
        instance->instruction_count++;
        return 1;
    case 0x000F9842u: /* 85 4A STA $4A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x4Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9844u;
        instance->instruction_count++;
        return 1;
    case 0x000F9844u: /* A2 04 00 LDX #$0004 */
        word = 0x0004u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9847u;
        instance->instruction_count++;
        return 1;
    case 0x000F9847u: /* 20 45 A0 JSR $A045 */
        if (!tg_push16(instance, 0x9849u)) return 0;
        instance->cpu.pc = 0xA045u;
        instance->instruction_count++;
        return 1;
    case 0x000F984Au: /* 20 DD 9D JSR $9DDD */
        if (!tg_push16(instance, 0x984Cu)) return 0;
        instance->cpu.pc = 0x9DDDu;
        instance->instruction_count++;
        return 1;
    case 0x000F984Du: /* A9 84 00 LDA #$0084 */
        word = 0x0084u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9850u;
        instance->instruction_count++;
        return 1;
    case 0x000F9850u: /* 8D 24 04 STA $0424 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9853u;
        instance->instruction_count++;
        return 1;
    case 0x000F9853u: /* 20 B2 9D JSR $9DB2 */
        if (!tg_push16(instance, 0x9855u)) return 0;
        instance->cpu.pc = 0x9DB2u;
        instance->instruction_count++;
        return 1;
    case 0x000F9856u: /* A5 81 LDA $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9858u;
        instance->instruction_count++;
        return 1;
    case 0x000F9858u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9859u;
        instance->instruction_count++;
        return 1;
    case 0x000F9859u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x985Au;
        instance->instruction_count++;
        return 1;
    case 0x000F985Au: /* B9 0A 00 LDA $000A,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x000Au + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x985Du;
        instance->instruction_count++;
        return 1;
    case 0x000F985Du: /* 29 F0 D3 AND #$D3F0 */
        word = 0xD3F0u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9860u;
        instance->instruction_count++;
        return 1;
    case 0x000F9860u: /* F0 F4 BEQ $0F:9856 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9856u : 0x9862u;
        instance->instruction_count++;
        return 1;
    case 0x000F9862u: /* 29 00 03 AND #$0300 */
        word = 0x0300u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9865u;
        instance->instruction_count++;
        return 1;
    case 0x000F9865u: /* F0 2D BEQ $0F:9894 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9894u : 0x9867u;
        instance->instruction_count++;
        return 1;
    case 0x000F9867u: /* A5 5A LDA $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9869u;
        instance->instruction_count++;
        return 1;
    case 0x000F9869u: /* 49 01 00 EOR #$0001 */
        word = 0x0001u;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x986Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F986Cu: /* 85 5A STA $5A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x986Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F986Eu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x986Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F986Fu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x9870u;
        instance->instruction_count++;
        return 1;
    case 0x000F9870u: /* B9 5C A8 LDA $A85C,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xA85Cu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9873u;
        instance->instruction_count++;
        return 1;
    case 0x000F9873u: /* 85 48 STA $48 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9875u;
        instance->instruction_count++;
        return 1;
    case 0x000F9875u: /* B9 60 A8 LDA $A860,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xA860u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9878u;
        instance->instruction_count++;
        return 1;
    case 0x000F9878u: /* 85 4A STA $4A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x4Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x987Au;
        instance->instruction_count++;
        return 1;
    case 0x000F987Au: /* A2 04 00 LDX #$0004 */
        word = 0x0004u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x987Du;
        instance->instruction_count++;
        return 1;
    case 0x000F987Du: /* 20 45 A0 JSR $A045 */
        if (!tg_push16(instance, 0x987Fu)) return 0;
        instance->cpu.pc = 0xA045u;
        instance->instruction_count++;
        return 1;
    case 0x000F9880u: /* 20 DD 9D JSR $9DDD */
        if (!tg_push16(instance, 0x9882u)) return 0;
        instance->cpu.pc = 0x9DDDu;
        instance->instruction_count++;
        return 1;
    case 0x000F9883u: /* A9 84 00 LDA #$0084 */
        word = 0x0084u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9886u;
        instance->instruction_count++;
        return 1;
    case 0x000F9886u: /* 8D 24 04 STA $0424 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9889u;
        instance->instruction_count++;
        return 1;
    case 0x000F9889u: /* A5 81 LDA $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x988Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F988Bu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x988Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F988Cu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x988Du;
        instance->instruction_count++;
        return 1;
    case 0x000F988Du: /* B9 0A 00 LDA $000A,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x000Au + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9890u;
        instance->instruction_count++;
        return 1;
    case 0x000F9890u: /* D0 F7 BNE $0F:9889 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9889u : 0x9892u;
        instance->instruction_count++;
        return 1;
    case 0x000F9892u: /* 80 C2 BRA $0F:9856 */
        instance->cpu.pc = 0x9856u;
        instance->instruction_count++;
        return 1;
    case 0x000F9894u: /* A5 5A LDA $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9896u;
        instance->instruction_count++;
        return 1;
    case 0x000F9896u: /* 85 87 STA $87 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x87u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9898u;
        instance->instruction_count++;
        return 1;
    case 0x000F9898u: /* A5 81 LDA $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x989Au;
        instance->instruction_count++;
        return 1;
    case 0x000F989Au: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x989Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F989Bu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x989Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F989Cu: /* B9 0A 00 LDA $000A,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x000Au + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x989Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F989Fu: /* D0 F7 BNE $0F:9898 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9898u : 0x98A1u;
        instance->instruction_count++;
        return 1;
    case 0x000F98A1u: /* 20 C5 9D JSR $9DC5 */
        if (!tg_push16(instance, 0x98A3u)) return 0;
        instance->cpu.pc = 0x9DC5u;
        instance->instruction_count++;
        return 1;
    case 0x000F98A4u: /* 20 1C 9E JSR $9E1C */
        if (!tg_push16(instance, 0x98A6u)) return 0;
        instance->cpu.pc = 0x9E1Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F98A7u: /* A9 8F 00 LDA #$008F */
        word = 0x008Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98AAu;
        instance->instruction_count++;
        return 1;
    case 0x000F98AAu: /* 85 42 STA $42 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x42u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x98ACu;
        instance->instruction_count++;
        return 1;
    case 0x000F98ACu: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98AFu;
        instance->instruction_count++;
        return 1;
    case 0x000F98AFu: /* 20 4D A2 JSR $A24D */
        if (!tg_push16(instance, 0x98B1u)) return 0;
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F98B2u: /* 64 5A STZ $5A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x98B4u;
        instance->instruction_count++;
        return 1;
    case 0x000F98B4u: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98B7u;
        instance->instruction_count++;
        return 1;
    case 0x000F98B7u: /* A4 81 LDY $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98B9u;
        instance->instruction_count++;
        return 1;
    case 0x000F98B9u: /* F0 03 BEQ $0F:98BE */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x98BEu : 0x98BBu;
        instance->instruction_count++;
        return 1;
    case 0x000F98BBu: /* A0 1D 00 LDY #$001D */
        word = 0x001Du;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98BEu;
        instance->instruction_count++;
        return 1;
    case 0x000F98BEu: /* BF 56 C6 0D LDA $0DC656,X */
        if (!tg_bus_read16(instance, ((0x0DC656u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98C2u;
        instance->instruction_count++;
        return 1;
    case 0x000F98C2u: /* D9 76 1F CMP $1F76,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F76u + instance->cpu.y)), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x98C5u;
        instance->instruction_count++;
        return 1;
    case 0x000F98C5u: /* D0 09 BNE $0F:98D0 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x98D0u : 0x98C7u;
        instance->instruction_count++;
        return 1;
    case 0x000F98C7u: /* BF 58 C6 0D LDA $0DC658,X */
        if (!tg_bus_read16(instance, ((0x0DC658u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98CBu;
        instance->instruction_count++;
        return 1;
    case 0x000F98CBu: /* D9 78 1F CMP $1F78,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F78u + instance->cpu.y)), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x98CEu;
        instance->instruction_count++;
        return 1;
    case 0x000F98CEu: /* F0 0F BEQ $0F:98DF */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x98DFu : 0x98D0u;
        instance->instruction_count++;
        return 1;
    case 0x000F98D0u: /* E6 5A INC $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word + 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98D2u;
        instance->instruction_count++;
        return 1;
    case 0x000F98D2u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x98D3u;
        instance->instruction_count++;
        return 1;
    case 0x000F98D3u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x98D4u;
        instance->instruction_count++;
        return 1;
    case 0x000F98D4u: /* 69 10 00 ADC #$0010 */
        word = 0x0010u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x98D7u;
        instance->instruction_count++;
        return 1;
    case 0x000F98D7u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x98D8u;
        instance->instruction_count++;
        return 1;
    case 0x000F98D8u: /* C9 40 00 CMP #$0040 */
        word = 0x0040u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x98DBu;
        instance->instruction_count++;
        return 1;
    case 0x000F98DBu: /* D0 E1 BNE $0F:98BE */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x98BEu : 0x98DDu;
        instance->instruction_count++;
        return 1;
    case 0x000F98DDu: /* 64 5A STZ $5A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x98DFu;
        instance->instruction_count++;
        return 1;
    case 0x000F98DFu: /* A9 03 00 LDA #$0003 */
        word = 0x0003u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98E2u;
        instance->instruction_count++;
        return 1;
    case 0x000F98E2u: /* 85 44 STA $44 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x44u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x98E4u;
        instance->instruction_count++;
        return 1;
    case 0x000F98E4u: /* A9 0F 80 LDA #$800F */
        word = 0x800Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98E7u;
        instance->instruction_count++;
        return 1;
    case 0x000F98E7u: /* A2 98 DA LDX #$DA98 */
        word = 0xDA98u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98EAu;
        instance->instruction_count++;
        return 1;
    case 0x000F98EAu: /* A0 00 22 LDY #$2200 */
        word = 0x2200u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98EDu;
        instance->instruction_count++;
        return 1;
    case 0x000F98EDu: /* 20 06 B3 JSR $B306 */
        if (!tg_push16(instance, 0x98EFu)) return 0;
        instance->cpu.pc = 0xB306u;
        instance->instruction_count++;
        return 1;
    case 0x000F98F0u: /* A9 0E 80 LDA #$800E */
        word = 0x800Eu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98F3u;
        instance->instruction_count++;
        return 1;
    case 0x000F98F3u: /* A2 3F F0 LDX #$F03F */
        word = 0xF03Fu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98F6u;
        instance->instruction_count++;
        return 1;
    case 0x000F98F6u: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x98F9u;
        instance->instruction_count++;
        return 1;
    case 0x000F98F9u: /* 20 34 B3 JSR $B334 */
        if (!tg_push16(instance, 0x98FBu)) return 0;
        instance->cpu.pc = 0xB334u;
        instance->instruction_count++;
        return 1;
    case 0x000F98FCu: /* 20 F9 9B JSR $9BF9 */
        if (!tg_push16(instance, 0x98FEu)) return 0;
        instance->cpu.pc = 0x9BF9u;
        instance->instruction_count++;
        return 1;
    case 0x000F98FFu: /* A5 5A LDA $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9901u;
        instance->instruction_count++;
        return 1;
    case 0x000F9901u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9902u;
        instance->instruction_count++;
        return 1;
    case 0x000F9902u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9903u;
        instance->instruction_count++;
        return 1;
    case 0x000F9903u: /* BF 32 C6 0D LDA $0DC632,X */
        if (!tg_bus_read16(instance, ((0x0DC632u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9907u;
        instance->instruction_count++;
        return 1;
    case 0x000F9907u: /* 20 31 9C JSR $9C31 */
        if (!tg_push16(instance, 0x9909u)) return 0;
        instance->cpu.pc = 0x9C31u;
        instance->instruction_count++;
        return 1;
    case 0x000F990Au: /* A9 05 00 LDA #$0005 */
        word = 0x0005u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x990Du;
        instance->instruction_count++;
        return 1;
    case 0x000F990Du: /* 85 46 STA $46 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x46u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x990Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F990Fu: /* 20 31 A1 JSR $A131 */
        if (!tg_push16(instance, 0x9911u)) return 0;
        instance->cpu.pc = 0xA131u;
        instance->instruction_count++;
        return 1;
    case 0x000F9912u: /* 20 88 9F JSR $9F88 */
        if (!tg_push16(instance, 0x9914u)) return 0;
        instance->cpu.pc = 0x9F88u;
        instance->instruction_count++;
        return 1;
    case 0x000F9915u: /* 20 70 9B JSR $9B70 */
        if (!tg_push16(instance, 0x9917u)) return 0;
        instance->cpu.pc = 0x9B70u;
        instance->instruction_count++;
        return 1;
    case 0x000F9918u: /* A2 66 00 LDX #$0066 */
        word = 0x0066u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x991Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F991Bu: /* 20 93 9F JSR $9F93 */
        if (!tg_push16(instance, 0x991Du)) return 0;
        instance->cpu.pc = 0x9F93u;
        instance->instruction_count++;
        return 1;
    case 0x000F991Eu: /* A5 5A LDA $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9920u;
        instance->instruction_count++;
        return 1;
    case 0x000F9920u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9921u;
        instance->instruction_count++;
        return 1;
    case 0x000F9921u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x9922u;
        instance->instruction_count++;
        return 1;
    case 0x000F9922u: /* B9 12 B1 LDA $B112,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xB112u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9925u;
        instance->instruction_count++;
        return 1;
    case 0x000F9925u: /* 85 48 STA $48 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9927u;
        instance->instruction_count++;
        return 1;
    case 0x000F9927u: /* A9 02 00 LDA #$0002 */
        word = 0x0002u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x992Au;
        instance->instruction_count++;
        return 1;
    case 0x000F992Au: /* 85 4A STA $4A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x4Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x992Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F992Cu: /* A2 04 00 LDX #$0004 */
        word = 0x0004u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x992Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F992Fu: /* 20 45 A0 JSR $A045 */
        if (!tg_push16(instance, 0x9931u)) return 0;
        instance->cpu.pc = 0xA045u;
        instance->instruction_count++;
        return 1;
    case 0x000F9932u: /* 20 DD 9D JSR $9DDD */
        if (!tg_push16(instance, 0x9934u)) return 0;
        instance->cpu.pc = 0x9DDDu;
        instance->instruction_count++;
        return 1;
    case 0x000F9935u: /* A9 84 00 LDA #$0084 */
        word = 0x0084u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9938u;
        instance->instruction_count++;
        return 1;
    case 0x000F9938u: /* 8D 24 04 STA $0424 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x993Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F993Bu: /* 20 B2 9D JSR $9DB2 */
        if (!tg_push16(instance, 0x993Du)) return 0;
        instance->cpu.pc = 0x9DB2u;
        instance->instruction_count++;
        return 1;
    case 0x000F993Eu: /* A5 81 LDA $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9940u;
        instance->instruction_count++;
        return 1;
    case 0x000F9940u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9941u;
        instance->instruction_count++;
        return 1;
    case 0x000F9941u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x9942u;
        instance->instruction_count++;
        return 1;
    case 0x000F9942u: /* B9 0A 00 LDA $000A,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x000Au + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9945u;
        instance->instruction_count++;
        return 1;
    case 0x000F9945u: /* 29 F0 D3 AND #$D3F0 */
        word = 0xD3F0u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9948u;
        instance->instruction_count++;
        return 1;
    case 0x000F9948u: /* F0 F4 BEQ $0F:993E */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x993Eu : 0x994Au;
        instance->instruction_count++;
        return 1;
    case 0x000F994Au: /* 29 00 03 AND #$0300 */
        word = 0x0300u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x994Du;
        instance->instruction_count++;
        return 1;
    case 0x000F994Du: /* F0 55 BEQ $0F:99A4 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x99A4u : 0x994Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F994Fu: /* 29 00 02 AND #$0200 */
        word = 0x0200u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9952u;
        instance->instruction_count++;
        return 1;
    case 0x000F9952u: /* F0 04 BEQ $0F:9958 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9958u : 0x9954u;
        instance->instruction_count++;
        return 1;
    case 0x000F9954u: /* C6 5A DEC $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9956u;
        instance->instruction_count++;
        return 1;
    case 0x000F9956u: /* 80 02 BRA $0F:995A */
        instance->cpu.pc = 0x995Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9958u: /* E6 5A INC $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word + 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x995Au;
        instance->instruction_count++;
        return 1;
    case 0x000F995Au: /* A5 5A LDA $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x995Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F995Cu: /* 29 03 00 AND #$0003 */
        word = 0x0003u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x995Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F995Fu: /* 85 5A STA $5A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9961u;
        instance->instruction_count++;
        return 1;
    case 0x000F9961u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9962u;
        instance->instruction_count++;
        return 1;
    case 0x000F9962u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x9963u;
        instance->instruction_count++;
        return 1;
    case 0x000F9963u: /* B9 12 B1 LDA $B112,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xB112u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9966u;
        instance->instruction_count++;
        return 1;
    case 0x000F9966u: /* 85 48 STA $48 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9968u;
        instance->instruction_count++;
        return 1;
    case 0x000F9968u: /* 5A PHY */
        if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0x9969u;
        instance->instruction_count++;
        return 1;
    case 0x000F9969u: /* A9 02 00 LDA #$0002 */
        word = 0x0002u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x996Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F996Cu: /* 85 4A STA $4A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x4Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x996Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F996Eu: /* A2 04 00 LDX #$0004 */
        word = 0x0004u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9971u;
        instance->instruction_count++;
        return 1;
    case 0x000F9971u: /* 20 45 A0 JSR $A045 */
        if (!tg_push16(instance, 0x9973u)) return 0;
        instance->cpu.pc = 0xA045u;
        instance->instruction_count++;
        return 1;
    case 0x000F9974u: /* 20 F9 9B JSR $9BF9 */
        if (!tg_push16(instance, 0x9976u)) return 0;
        instance->cpu.pc = 0x9BF9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9977u: /* A2 66 00 LDX #$0066 */
        word = 0x0066u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x997Au;
        instance->instruction_count++;
        return 1;
    case 0x000F997Au: /* 20 93 9F JSR $9F93 */
        if (!tg_push16(instance, 0x997Cu)) return 0;
        instance->cpu.pc = 0x9F93u;
        instance->instruction_count++;
        return 1;
    case 0x000F997Du: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x997Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F997Eu: /* BF 32 C6 0D LDA $0DC632,X */
        if (!tg_bus_read16(instance, ((0x0DC632u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9982u;
        instance->instruction_count++;
        return 1;
    case 0x000F9982u: /* 20 31 9C JSR $9C31 */
        if (!tg_push16(instance, 0x9984u)) return 0;
        instance->cpu.pc = 0x9C31u;
        instance->instruction_count++;
        return 1;
    case 0x000F9985u: /* A9 05 00 LDA #$0005 */
        word = 0x0005u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9988u;
        instance->instruction_count++;
        return 1;
    case 0x000F9988u: /* 85 46 STA $46 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x46u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x998Au;
        instance->instruction_count++;
        return 1;
    case 0x000F998Au: /* 20 31 A1 JSR $A131 */
        if (!tg_push16(instance, 0x998Cu)) return 0;
        instance->cpu.pc = 0xA131u;
        instance->instruction_count++;
        return 1;
    case 0x000F998Du: /* 20 88 9F JSR $9F88 */
        if (!tg_push16(instance, 0x998Fu)) return 0;
        instance->cpu.pc = 0x9F88u;
        instance->instruction_count++;
        return 1;
    case 0x000F9990u: /* 20 DD 9D JSR $9DDD */
        if (!tg_push16(instance, 0x9992u)) return 0;
        instance->cpu.pc = 0x9DDDu;
        instance->instruction_count++;
        return 1;
    case 0x000F9993u: /* A9 84 00 LDA #$0084 */
        word = 0x0084u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9996u;
        instance->instruction_count++;
        return 1;
    case 0x000F9996u: /* 8D 24 04 STA $0424 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9999u;
        instance->instruction_count++;
        return 1;
    case 0x000F9999u: /* A5 81 LDA $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x999Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F999Bu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x999Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F999Cu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x999Du;
        instance->instruction_count++;
        return 1;
    case 0x000F999Du: /* B9 0A 00 LDA $000A,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x000Au + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99A0u;
        instance->instruction_count++;
        return 1;
    case 0x000F99A0u: /* D0 F7 BNE $0F:9999 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9999u : 0x99A2u;
        instance->instruction_count++;
        return 1;
    case 0x000F99A2u: /* 80 9A BRA $0F:993E */
        instance->cpu.pc = 0x993Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F99A4u: /* A5 81 LDA $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99A6u;
        instance->instruction_count++;
        return 1;
    case 0x000F99A6u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99A7u;
        instance->instruction_count++;
        return 1;
    case 0x000F99A7u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x99A8u;
        instance->instruction_count++;
        return 1;
    case 0x000F99A8u: /* B9 0A 00 LDA $000A,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x000Au + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99ABu;
        instance->instruction_count++;
        return 1;
    case 0x000F99ABu: /* D0 F7 BNE $0F:99A4 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x99A4u : 0x99ADu;
        instance->instruction_count++;
        return 1;
    case 0x000F99ADu: /* A4 81 LDY $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99AFu;
        instance->instruction_count++;
        return 1;
    case 0x000F99AFu: /* F0 03 BEQ $0F:99B4 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x99B4u : 0x99B1u;
        instance->instruction_count++;
        return 1;
    case 0x000F99B1u: /* A0 1D 00 LDY #$001D */
        word = 0x001Du;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99B4u;
        instance->instruction_count++;
        return 1;
    case 0x000F99B4u: /* A5 5A LDA $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99B6u;
        instance->instruction_count++;
        return 1;
    case 0x000F99B6u: /* 29 03 00 AND #$0003 */
        word = 0x0003u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99B9u;
        instance->instruction_count++;
        return 1;
    case 0x000F99B9u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99BAu;
        instance->instruction_count++;
        return 1;
    case 0x000F99BAu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99BBu;
        instance->instruction_count++;
        return 1;
    case 0x000F99BBu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99BCu;
        instance->instruction_count++;
        return 1;
    case 0x000F99BCu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99BDu;
        instance->instruction_count++;
        return 1;
    case 0x000F99BDu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x99BEu;
        instance->instruction_count++;
        return 1;
    case 0x000F99BEu: /* BF 56 C6 0D LDA $0DC656,X */
        if (!tg_bus_read16(instance, ((0x0DC656u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99C2u;
        instance->instruction_count++;
        return 1;
    case 0x000F99C2u: /* 99 76 1F STA $1F76,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F76u + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x99C5u;
        instance->instruction_count++;
        return 1;
    case 0x000F99C5u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99C6u;
        instance->instruction_count++;
        return 1;
    case 0x000F99C6u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99C7u;
        instance->instruction_count++;
        return 1;
    case 0x000F99C7u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99C8u;
        instance->instruction_count++;
        return 1;
    case 0x000F99C8u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99C9u;
        instance->instruction_count++;
        return 1;
    case 0x000F99C9u: /* C0 10 00 CPY #$0010 */
        word = 0x0010u;
        tg_compare16(instance, (uint16_t)instance->cpu.y, word);
        instance->cpu.pc = 0x99CCu;
        instance->instruction_count++;
        return 1;
    case 0x000F99CCu: /* F0 05 BEQ $0F:99D3 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x99D3u : 0x99CEu;
        instance->instruction_count++;
        return 1;
    case 0x000F99CEu: /* C0 2D 00 CPY #$002D */
        word = 0x002Du;
        tg_compare16(instance, (uint16_t)instance->cpu.y, word);
        instance->cpu.pc = 0x99D1u;
        instance->instruction_count++;
        return 1;
    case 0x000F99D1u: /* D0 EB BNE $0F:99BE */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x99BEu : 0x99D3u;
        instance->instruction_count++;
        return 1;
    case 0x000F99D3u: /* BB TYX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.y);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x99D4u;
        instance->instruction_count++;
        return 1;
    case 0x000F99D4u: /* A5 87 LDA $87 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x87u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99D6u;
        instance->instruction_count++;
        return 1;
    case 0x000F99D6u: /* F0 06 BEQ $0F:99DE */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x99DEu : 0x99D8u;
        instance->instruction_count++;
        return 1;
    case 0x000F99D8u: /* 9E 6A 1F STZ $1F6A,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F6Au + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x99DBu;
        instance->instruction_count++;
        return 1;
    case 0x000F99DBu: /* 9E 6C 1F STZ $1F6C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F6Cu + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x99DEu;
        instance->instruction_count++;
        return 1;
    case 0x000F99DEu: /* A5 81 LDA $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99E0u;
        instance->instruction_count++;
        return 1;
    case 0x000F99E0u: /* F0 05 BEQ $0F:99E7 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x99E7u : 0x99E2u;
        instance->instruction_count++;
        return 1;
    case 0x000F99E2u: /* AD AC 1F LDA $1FAC */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FACu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99E5u;
        instance->instruction_count++;
        return 1;
    case 0x000F99E5u: /* 80 03 BRA $0F:99EA */
        instance->cpu.pc = 0x99EAu;
        instance->instruction_count++;
        return 1;
    case 0x000F99E7u: /* AD 8F 1F LDA $1F8F */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Fu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99EAu;
        instance->instruction_count++;
        return 1;
    case 0x000F99EAu: /* 85 5A STA $5A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x99ECu;
        instance->instruction_count++;
        return 1;
    case 0x000F99ECu: /* 20 C5 9D JSR $9DC5 */
        if (!tg_push16(instance, 0x99EEu)) return 0;
        instance->cpu.pc = 0x9DC5u;
        instance->instruction_count++;
        return 1;
    case 0x000F99EFu: /* 20 1C 9E JSR $9E1C */
        if (!tg_push16(instance, 0x99F1u)) return 0;
        instance->cpu.pc = 0x9E1Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F99F2u: /* A9 8F 00 LDA #$008F */
        word = 0x008Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99F5u;
        instance->instruction_count++;
        return 1;
    case 0x000F99F5u: /* 85 42 STA $42 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x42u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x99F7u;
        instance->instruction_count++;
        return 1;
    case 0x000F99F7u: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x99FAu;
        instance->instruction_count++;
        return 1;
    case 0x000F99FAu: /* 20 4D A2 JSR $A24D */
        if (!tg_push16(instance, 0x99FCu)) return 0;
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F99FDu: /* A9 0F 80 LDA #$800F */
        word = 0x800Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A00u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A00u: /* A2 90 BF LDX #$BF90 */
        word = 0xBF90u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A03u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A03u: /* A0 00 22 LDY #$2200 */
        word = 0x2200u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A06u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A06u: /* 20 06 B3 JSR $B306 */
        if (!tg_push16(instance, 0x9A08u)) return 0;
        instance->cpu.pc = 0xB306u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A09u: /* A9 08 00 LDA #$0008 */
        word = 0x0008u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A0Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A0Cu: /* 85 44 STA $44 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x44u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9A0Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A0Eu: /* A9 06 00 LDA #$0006 */
        word = 0x0006u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A11u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A11u: /* 20 31 9C JSR $9C31 */
        if (!tg_push16(instance, 0x9A13u)) return 0;
        instance->cpu.pc = 0x9C31u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A14u: /* 20 70 9B JSR $9B70 */
        if (!tg_push16(instance, 0x9A16u)) return 0;
        instance->cpu.pc = 0x9B70u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A17u: /* A2 66 00 LDX #$0066 */
        word = 0x0066u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A1Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9A1Au: /* 20 93 9F JSR $9F93 */
        if (!tg_push16(instance, 0x9A1Cu)) return 0;
        instance->cpu.pc = 0x9F93u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A1Du: /* A9 08 00 LDA #$0008 */
        word = 0x0008u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A20u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A20u: /* 85 44 STA $44 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x44u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9A22u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A22u: /* A9 06 00 LDA #$0006 */
        word = 0x0006u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A25u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A25u: /* 20 31 9C JSR $9C31 */
        if (!tg_push16(instance, 0x9A27u)) return 0;
        instance->cpu.pc = 0x9C31u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A28u: /* A5 5A LDA $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A2Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9A2Au: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A2Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A2Bu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9A2Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A2Cu: /* A9 08 00 LDA #$0008 */
        word = 0x0008u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A2Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A2Fu: /* 85 44 STA $44 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x44u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9A31u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A31u: /* BF 3A C6 0D LDA $0DC63A,X */
        if (!tg_bus_read16(instance, ((0x0DC63Au + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A35u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A35u: /* 20 31 9C JSR $9C31 */
        if (!tg_push16(instance, 0x9A37u)) return 0;
        instance->cpu.pc = 0x9C31u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A38u: /* 20 D6 9A JSR $9AD6 */
        if (!tg_push16(instance, 0x9A3Au)) return 0;
        instance->cpu.pc = 0x9AD6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A3Bu: /* A5 5A LDA $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A3Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9A3Du: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A3Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A3Eu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x9A3Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A3Fu: /* B9 48 A9 LDA $A948,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xA948u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A42u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A42u: /* 85 48 STA $48 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9A44u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A44u: /* B9 50 A9 LDA $A950,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xA950u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A47u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A47u: /* 85 4A STA $4A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x4Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9A49u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A49u: /* A2 04 00 LDX #$0004 */
        word = 0x0004u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A4Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A4Cu: /* 20 45 A0 JSR $A045 */
        if (!tg_push16(instance, 0x9A4Eu)) return 0;
        instance->cpu.pc = 0xA045u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A4Fu: /* 20 DD 9D JSR $9DDD */
        if (!tg_push16(instance, 0x9A51u)) return 0;
        instance->cpu.pc = 0x9DDDu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A52u: /* A9 84 00 LDA #$0084 */
        word = 0x0084u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A55u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A55u: /* 8D 24 04 STA $0424 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9A58u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A58u: /* 20 B2 9D JSR $9DB2 */
        if (!tg_push16(instance, 0x9A5Au)) return 0;
        instance->cpu.pc = 0x9DB2u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A5Bu: /* A5 81 LDA $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A5Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9A5Du: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A5Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A5Eu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x9A5Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A5Fu: /* B9 0A 00 LDA $000A,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x000Au + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A62u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A62u: /* 29 F0 DF AND #$DFF0 */
        word = 0xDFF0u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A65u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A65u: /* F0 F4 BEQ $0F:9A5B */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9A5Bu : 0x9A67u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A67u: /* 29 00 0F AND #$0F00 */
        word = 0x0F00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A6Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9A6Au: /* F0 4A BEQ $0F:9AB6 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9AB6u : 0x9A6Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A6Cu: /* 29 00 03 AND #$0300 */
        word = 0x0300u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A6Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A6Fu: /* D0 05 BNE $0F:9A76 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9A76u : 0x9A71u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A71u: /* A9 02 00 LDA #$0002 */
        word = 0x0002u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A74u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A74u: /* D0 03 BNE $0F:9A79 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9A79u : 0x9A76u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A76u: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A79u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A79u: /* 45 5A EOR $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A7Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A7Bu: /* 85 5A STA $5A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9A7Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9A7Du: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A7Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A7Eu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x9A7Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A7Fu: /* B9 48 A9 LDA $A948,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xA948u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A82u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A82u: /* 85 48 STA $48 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9A84u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A84u: /* B9 50 A9 LDA $A950,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xA950u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A87u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A87u: /* 85 4A STA $4A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x4Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9A89u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A89u: /* A2 04 00 LDX #$0004 */
        word = 0x0004u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A8Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A8Cu: /* 20 45 A0 JSR $A045 */
        if (!tg_push16(instance, 0x9A8Eu)) return 0;
        instance->cpu.pc = 0xA045u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A8Fu: /* 20 DD 9D JSR $9DDD */
        if (!tg_push16(instance, 0x9A91u)) return 0;
        instance->cpu.pc = 0x9DDDu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A92u: /* A5 5A LDA $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A94u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A94u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A95u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A95u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9A96u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A96u: /* A9 08 00 LDA #$0008 */
        word = 0x0008u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A99u;
        instance->instruction_count++;
        return 1;
    case 0x000F9A99u: /* 85 44 STA $44 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x44u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9A9Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A9Bu: /* BF 3A C6 0D LDA $0DC63A,X */
        if (!tg_bus_read16(instance, ((0x0DC63Au + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9A9Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9A9Fu: /* 20 31 9C JSR $9C31 */
        if (!tg_push16(instance, 0x9AA1u)) return 0;
        instance->cpu.pc = 0x9C31u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AA2u: /* 20 D6 9A JSR $9AD6 */
        if (!tg_push16(instance, 0x9AA4u)) return 0;
        instance->cpu.pc = 0x9AD6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AA5u: /* A9 84 00 LDA #$0084 */
        word = 0x0084u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AA8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AA8u: /* 8D 24 04 STA $0424 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9AABu;
        instance->instruction_count++;
        return 1;
    case 0x000F9AABu: /* A5 81 LDA $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AADu;
        instance->instruction_count++;
        return 1;
    case 0x000F9AADu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AAEu;
        instance->instruction_count++;
        return 1;
    case 0x000F9AAEu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x9AAFu;
        instance->instruction_count++;
        return 1;
    case 0x000F9AAFu: /* B9 0A 00 LDA $000A,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x000Au + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AB2u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AB2u: /* D0 F7 BNE $0F:9AAB */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9AABu : 0x9AB4u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AB4u: /* 80 A5 BRA $0F:9A5B */
        instance->cpu.pc = 0x9A5Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9AB6u: /* A5 5A LDA $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AB8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AB8u: /* A4 81 LDY $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9ABAu;
        instance->instruction_count++;
        return 1;
    case 0x000F9ABAu: /* D0 05 BNE $0F:9AC1 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9AC1u : 0x9ABCu;
        instance->instruction_count++;
        return 1;
    case 0x000F9ABCu: /* 8D 8F 1F STA $1F8F */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Fu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9ABFu;
        instance->instruction_count++;
        return 1;
    case 0x000F9ABFu: /* 80 03 BRA $0F:9AC4 */
        instance->cpu.pc = 0x9AC4u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AC1u: /* 8D AC 1F STA $1FAC */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FACu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9AC4u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AC4u: /* A5 81 LDA $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AC6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AC6u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AC7u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AC7u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x9AC8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AC8u: /* B9 0A 00 LDA $000A,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x000Au + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9ACBu;
        instance->instruction_count++;
        return 1;
    case 0x000F9ACBu: /* D0 F7 BNE $0F:9AC4 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9AC4u : 0x9ACDu;
        instance->instruction_count++;
        return 1;
    case 0x000F9ACDu: /* 20 C5 9D JSR $9DC5 */
        if (!tg_push16(instance, 0x9ACFu)) return 0;
        instance->cpu.pc = 0x9DC5u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AD0u: /* 20 1C 9E JSR $9E1C */
        if (!tg_push16(instance, 0x9AD2u)) return 0;
        instance->cpu.pc = 0x9E1Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9AD3u: /* 4C EA 96 JMP $96EA */
        instance->cpu.pc = 0x96EAu;
        instance->instruction_count++;
        return 1;
    case 0x000F9AD6u: /* AD B0 1F LDA $1FB0 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FB0u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AD9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AD9u: /* F0 5F BEQ $0F:9B3A */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x9B3Au : 0x9ADBu;
        instance->instruction_count++;
        return 1;
    case 0x000F9ADBu: /* A9 0B 00 LDA #$000B */
        word = 0x000Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9ADEu;
        instance->instruction_count++;
        return 1;
    case 0x000F9ADEu: /* 8D DC 11 STA $11DC */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x11DCu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9AE1u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AE1u: /* A9 1C 00 LDA #$001C */
        word = 0x001Cu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AE4u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AE4u: /* 8D 00 12 STA $1200 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1200u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9AE7u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AE7u: /* A9 1B 00 LDA #$001B */
        word = 0x001Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AEAu;
        instance->instruction_count++;
        return 1;
    case 0x000F9AEAu: /* 8D 02 12 STA $1202 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1202u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9AEDu;
        instance->instruction_count++;
        return 1;
    case 0x000F9AEDu: /* 8D 04 12 STA $1204 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1204u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9AF0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AF0u: /* A5 5A LDA $5A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AF2u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AF2u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AF3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AF3u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x9AF4u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AF4u: /* BE F6 B4 LDX $B4F6,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xB4F6u + instance->cpu.y)), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AF7u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AF7u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0x9AF8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9AF8u: /* BF 42 C6 0D LDA $0DC642,X */
        if (!tg_bus_read16(instance, ((0x0DC642u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AFCu;
        instance->instruction_count++;
        return 1;
    case 0x000F9AFCu: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9AFFu;
        instance->instruction_count++;
        return 1;
    case 0x000F9AFFu: /* E9 15 00 SBC #$0015 */
        word = 0x0015u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0x9B02u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B02u: /* 8D D4 11 STA $11D4 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x11D4u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B05u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B05u: /* BF 43 C6 0D LDA $0DC643,X */
        if (!tg_bus_read16(instance, ((0x0DC643u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B09u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B09u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B0Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B0Cu: /* E9 15 00 SBC #$0015 */
        word = 0x0015u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0x9B0Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B0Fu: /* 8D D6 11 STA $11D6 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x11D6u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B12u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B12u: /* BF 44 C6 0D LDA $0DC644,X */
        if (!tg_bus_read16(instance, ((0x0DC644u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B16u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B16u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B19u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B19u: /* E9 15 00 SBC #$0015 */
        word = 0x0015u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0x9B1Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B1Cu: /* 8D D8 11 STA $11D8 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x11D8u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B1Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B1Fu: /* BB TYX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.y);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x9B20u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B20u: /* BF 4E C6 0D LDA $0DC64E,X */
        if (!tg_bus_read16(instance, ((0x0DC64Eu + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B24u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B24u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B27u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B27u: /* E9 15 00 SBC #$0015 */
        word = 0x0015u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0x9B2Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9B2Au: /* 8D 14 12 STA $1214 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1214u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B2Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9B2Du: /* BF 4F C6 0D LDA $0DC64F,X */
        if (!tg_bus_read16(instance, ((0x0DC64Fu + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B31u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B31u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B34u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B34u: /* E9 15 00 SBC #$0015 */
        word = 0x0015u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0x9B37u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B37u: /* 8D 18 12 STA $1218 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1218u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B3Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9B3Au: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9B3Bu: /* 20 7B 9B JSR $9B7B */
        if (!tg_push16(instance, 0x9B3Du)) return 0;
        instance->cpu.pc = 0x9B7Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B3Eu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9B40u;
        instance->instruction_count++;
        return 1;
    case 0x040F9B40u: /* A2 08 00 LDX #$0008 */
        word = 0x0008u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B43u;
        instance->instruction_count++;
        return 1;
    case 0x040F9B43u: /* B5 67 LDA $67,X */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x67u + instance->cpu.x) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x9B45u;
        instance->instruction_count++;
        return 1;
    case 0x040F9B45u: /* C9 20 CMP #$20 */
        byte = 0x20u;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x9B47u;
        instance->instruction_count++;
        return 1;
    case 0x040F9B47u: /* D0 03 BNE $0F:9B4C */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9B4Cu : 0x9B49u;
        instance->instruction_count++;
        return 1;
    case 0x040F9B49u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B4Au;
        instance->instruction_count++;
        return 1;
    case 0x040F9B4Au: /* D0 F7 BNE $0F:9B43 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9B43u : 0x9B4Cu;
        instance->instruction_count++;
        return 1;
    case 0x040F9B4Cu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9B4Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B4Eu: /* A9 08 07 LDA #$0708 */
        word = 0x0708u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B51u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B51u: /* 85 66 STA $66 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B53u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B53u: /* 86 5E STX $5E */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x5Eu) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x9B55u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B55u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9B56u: /* A5 5E LDA $5E */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Eu) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B58u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B58u: /* C9 08 00 CMP #$0008 */
        word = 0x0008u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x9B5Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B5Bu: /* D0 01 BNE $0F:9B5E */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9B5Eu : 0x9B5Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9B5Du: /* 3A DEC A */
        word = (uint16_t)((instance->cpu.a) - 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B5Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B5Eu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B5Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B5Fu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B60u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B60u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B61u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B61u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B62u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B62u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x9B63u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B63u: /* 69 40 38 ADC #$3840 */
        word = 0x3840u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x9B66u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B66u: /* 8D 02 02 STA $0202 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0202u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B69u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B69u: /* A9 C2 0E LDA #$0EC2 */
        word = 0x0EC2u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B6Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B6Cu: /* 8D 04 02 STA $0204 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0204u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B6Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B6Fu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9B70u: /* A2 AD B4 LDX #$B4AD */
        word = 0xB4ADu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B73u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B73u: /* 20 93 9F JSR $9F93 */
        if (!tg_push16(instance, 0x9B75u)) return 0;
        instance->cpu.pc = 0x9F93u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B76u: /* A9 08 01 LDA #$0108 */
        word = 0x0108u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B79u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B79u: /* 85 66 STA $66 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B7Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B7Bu: /* A5 81 LDA $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B7Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9B7Du: /* D0 16 BNE $0F:9B95 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9B95u : 0x9B7Fu;
        instance->instruction_count++;
        return 1;
  /* Headless Test 02 proved that $1F86-$1F8D is the persistent eight-byte
     Player 1 name.  $0F:9B7F-$0F:9B91 copies its four words into the shared
     direct-page text/name buffer at $68-$6F before it is displayed. */
  case 0x000F9B7Fu: /* AD 86 1F LDA $1F86 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F86u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B82u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B82u: /* 85 68 STA $68 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x68u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B84u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B84u: /* AD 88 1F LDA $1F88 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F88u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B87u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B87u: /* 85 6A STA $6A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x6Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B89u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B89u: /* AD 8A 1F LDA $1F8A */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Au), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B8Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B8Cu: /* 85 6C STA $6C */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x6Cu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B8Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B8Eu: /* AD 8C 1F LDA $1F8C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Cu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B91u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B91u: /* 85 6E STA $6E */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x6Eu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B93u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B93u: /* 80 14 BRA $0F:9BA9 */
        instance->cpu.pc = 0x9BA9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B95u: /* AD A3 1F LDA $1FA3 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA3u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B98u;
        instance->instruction_count++;
        return 1;
    case 0x000F9B98u: /* 85 68 STA $68 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x68u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B9Au;
        instance->instruction_count++;
        return 1;
    case 0x000F9B9Au: /* AD A5 1F LDA $1FA5 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA5u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9B9Du;
        instance->instruction_count++;
        return 1;
    case 0x000F9B9Du: /* 85 6A STA $6A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x6Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9B9Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F9B9Fu: /* AD A7 1F LDA $1FA7 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA7u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BA2u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BA2u: /* 85 6C STA $6C */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x6Cu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9BA4u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BA4u: /* AD A9 1F LDA $1FA9 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA9u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BA7u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BA7u: /* 85 6E STA $6E */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x6Eu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9BA9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BA9u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9BABu;
        instance->instruction_count++;
        return 1;
    case 0x040F9BABu: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BAEu;
        instance->instruction_count++;
        return 1;
    case 0x040F9BAEu: /* A2 07 00 LDX #$0007 */
        word = 0x0007u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BB1u;
        instance->instruction_count++;
        return 1;
    case 0x040F9BB1u: /* B5 68 LDA $68,X */
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x68u + instance->cpu.x) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x9BB3u;
        instance->instruction_count++;
        return 1;
    case 0x040F9BB3u: /* C9 20 CMP #$20 */
        byte = 0x20u;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x9BB5u;
        instance->instruction_count++;
        return 1;
    case 0x040F9BB5u: /* D0 04 BNE $0F:9BBB */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9BBBu : 0x9BB7u;
        instance->instruction_count++;
        return 1;
    case 0x040F9BB7u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BB8u;
        instance->instruction_count++;
        return 1;
    case 0x040F9BB8u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BB9u;
        instance->instruction_count++;
        return 1;
    case 0x040F9BB9u: /* D0 F6 BNE $0F:9BB1 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9BB1u : 0x9BBBu;
        instance->instruction_count++;
        return 1;
    case 0x040F9BBBu: /* 98 TYA */
        tg_set_acc8(instance, (uint8_t)instance->cpu.y);
        tg_set_nz8(instance, (uint8_t)tg_acc8(instance));
        instance->cpu.pc = 0x9BBCu;
        instance->instruction_count++;
        return 1;
    case 0x040F9BBCu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x9BBDu;
        instance->instruction_count++;
        return 1;
    case 0x040F9BBDu: /* 69 08 ADC #$08 */
        byte = 0x08u;
        tg_adc8(instance, byte);
        instance->cpu.pc = 0x9BBFu;
        instance->instruction_count++;
        return 1;
    case 0x040F9BBFu: /* 85 66 STA $66 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x9BC1u;
        instance->instruction_count++;
        return 1;
    case 0x040F9BC1u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x9BC3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BC3u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9BC4u: /* A5 5E LDA $5E */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x5Eu) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BC6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BC6u: /* D0 03 BNE $0F:9BCB */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9BCBu : 0x9BC8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BC8u: /* 4C A1 83 JMP $83A1 */
        instance->cpu.pc = 0x83A1u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BCBu: /* A5 81 LDA $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BCDu;
        instance->instruction_count++;
        return 1;
    case 0x000F9BCDu: /* D0 15 BNE $0F:9BE4 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9BE4u : 0x9BCFu;
        instance->instruction_count++;
        return 1;
  /* Player 1 name commit: $0F:9BCF-$0F:9BE0 copies the edited direct-page
     buffer $68-$6F into persistent WRAM $1F86-$1F8D.  Controlled A/B runs
     observed $0F:9BD1 as the first persistent-word writer. */
  case 0x000F9BCFu: /* A5 68 LDA $68 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x68u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BD1u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BD1u: /* 8D 86 1F STA $1F86 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F86u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9BD4u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BD4u: /* A5 6A LDA $6A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x6Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BD6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BD6u: /* 8D 88 1F STA $1F88 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F88u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9BD9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BD9u: /* A5 6C LDA $6C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x6Cu) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BDBu;
        instance->instruction_count++;
        return 1;
    case 0x000F9BDBu: /* 8D 8A 1F STA $1F8A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9BDEu;
        instance->instruction_count++;
        return 1;
    case 0x000F9BDEu: /* A5 6E LDA $6E */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x6Eu) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BE0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BE0u: /* 8D 8C 1F STA $1F8C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9BE3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BE3u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9BE4u: /* A5 68 LDA $68 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x68u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BE6u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BE6u: /* 8D A3 1F STA $1FA3 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA3u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9BE9u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BE9u: /* A5 6A LDA $6A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x6Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BEBu;
        instance->instruction_count++;
        return 1;
    case 0x000F9BEBu: /* 8D A5 1F STA $1FA5 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA5u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9BEEu;
        instance->instruction_count++;
        return 1;
    case 0x000F9BEEu: /* A5 6C LDA $6C */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x6Cu) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BF0u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BF0u: /* 8D A7 1F STA $1FA7 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA7u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9BF3u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BF3u: /* A5 6E LDA $6E */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x6Eu) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BF5u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BF5u: /* 8D A9 1F STA $1FA9 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA9u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x9BF8u;
        instance->instruction_count++;
        return 1;
    case 0x000F9BF8u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F9BF9u: /* A2 FE 07 LDX #$07FE */
        word = 0x07FEu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9BFCu;
        instance->instruction_count++;
        return 1;
    case 0x000F9BFCu: /* 9E 6C 0C STZ $0C6C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0C6Cu + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x9BFFu;
        instance->instruction_count++;
        return 1;
    case 0x000F9BFFu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x9C00u;
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
