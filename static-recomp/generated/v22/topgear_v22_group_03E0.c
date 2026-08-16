/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_03E0(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x000F806Du: /* 4B PHK */
        if (!tg_push8(instance, instance->cpu.pbr)) return 0;
        instance->cpu.pc = 0x806Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F806Eu: /* AB PLB */
        if (!tg_pull8(instance, &byte)) return 0;
        instance->cpu.dbr = byte;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x806Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F806Fu: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8070u;
        instance->instruction_count++;
        return 1;
    case 0x000F8070u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8072u;
        instance->instruction_count++;
        return 1;
    case 0x040F8072u: /* 9C 0B 42 STZ $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), 0u)) return 0;
        instance->cpu.pc = 0x8075u;
        instance->instruction_count++;
        return 1;
    case 0x040F8075u: /* 9C 0C 42 STZ $420C */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Cu), 0u)) return 0;
        instance->cpu.pc = 0x8078u;
        instance->instruction_count++;
        return 1;
    case 0x040F8078u: /* C2 30 REP #$30 */
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x807Au;
        instance->instruction_count++;
        return 1;
    case 0x000F807Au: /* 64 78 STZ $78 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x78u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x807Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F807Cu: /* 64 7A STZ $7A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x7Au) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x807Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F807Eu: /* 64 70 STZ $70 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x70u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x8080u;
        instance->instruction_count++;
        return 1;
    case 0x000F8080u: /* 64 72 STZ $72 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x72u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x8082u;
        instance->instruction_count++;
        return 1;
    case 0x000F8082u: /* AD 86 1F LDA $1F86 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F86u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8085u;
        instance->instruction_count++;
        return 1;
    case 0x000F8085u: /* 0D 88 1F ORA $1F88 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F88u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8088u;
        instance->instruction_count++;
        return 1;
    case 0x000F8088u: /* 0D 8A 1F ORA $1F8A */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Au), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x808Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F808Bu: /* 0D 8C 1F ORA $1F8C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Cu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x808Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F808Eu: /* 0D A3 1F ORA $1FA3 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA3u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8091u;
        instance->instruction_count++;
        return 1;
    case 0x000F8091u: /* 0D A5 1F ORA $1FA5 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA5u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8094u;
        instance->instruction_count++;
        return 1;
    case 0x000F8094u: /* 0D A7 1F ORA $1FA7 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA7u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8097u;
        instance->instruction_count++;
        return 1;
    case 0x000F8097u: /* 0D A9 1F ORA $1FA9 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA9u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x809Au;
        instance->instruction_count++;
        return 1;
    case 0x000F809Au: /* D0 03 BNE $0F:809F */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x809Fu : 0x809Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F809Cu: /* 20 F4 80 JSR $80F4 */
        if (!tg_push16(instance, 0x809Eu)) return 0;
        instance->cpu.pc = 0x80F4u;
        instance->instruction_count++;
        return 1;
    case 0x000F809Fu: /* A9 00 80 LDA #$8000 */
        word = 0x8000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80A2u;
        instance->instruction_count++;
        return 1;
    case 0x000F80A2u: /* 85 01 STA $01 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x01u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x80A4u;
        instance->instruction_count++;
        return 1;
    case 0x000F80A4u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80A6u;
        instance->instruction_count++;
        return 1;
    case 0x040F80A6u: /* A9 5C LDA #$5C */
        byte = 0x5Cu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80A8u;
        instance->instruction_count++;
        return 1;
    case 0x040F80A8u: /* 85 00 STA $00 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x00u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80AAu;
        instance->instruction_count++;
        return 1;
    case 0x040F80AAu: /* A9 0F LDA #$0F */
        byte = 0x0Fu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80ACu;
        instance->instruction_count++;
        return 1;
    case 0x040F80ACu: /* 85 03 STA $03 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x03u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80AEu;
        instance->instruction_count++;
        return 1;
    case 0x040F80AEu: /* A9 40 LDA #$40 */
        byte = 0x40u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80B0u;
        instance->instruction_count++;
        return 1;
    case 0x040F80B0u: /* 85 04 STA $04 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x04u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80B2u;
        instance->instruction_count++;
        return 1;
    case 0x040F80B2u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80B4u;
        instance->instruction_count++;
        return 1;
    case 0x000F80B4u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80B5u;
        instance->instruction_count++;
        return 1;
    case 0x000F80B5u: /* D0 03 BNE $0F:80BA */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x80BAu : 0x80B7u;
        instance->instruction_count++;
        return 1;
    case 0x000F80B7u: /* 4C 5A 81 JMP $815A */
        instance->cpu.pc = 0x815Au;
        instance->instruction_count++;
        return 1;
    case 0x000F80BAu: /* 4C D7 83 JMP $83D7 */
        instance->cpu.pc = 0x83D7u;
        instance->instruction_count++;
        return 1;
    case 0x000F80BDu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80BFu;
        instance->instruction_count++;
        return 1;
    case 0x040F80BFu: /* 9C 0C 42 STZ $420C */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Cu), 0u)) return 0;
        instance->cpu.pc = 0x80C2u;
        instance->instruction_count++;
        return 1;
    case 0x040F80C2u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80C4u;
        instance->instruction_count++;
        return 1;
    case 0x000F80C4u: /* A9 40 21 LDA #$2140 */
        word = 0x2140u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80C7u;
        instance->instruction_count++;
        return 1;
    case 0x000F80C7u: /* 8D 30 43 STA $4330 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4330u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x80CAu;
        instance->instruction_count++;
        return 1;
    case 0x000F80CAu: /* A9 42 22 LDA #$2242 */
        word = 0x2242u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80CDu;
        instance->instruction_count++;
        return 1;
    case 0x000F80CDu: /* 8D 40 43 STA $4340 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4340u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x80D0u;
        instance->instruction_count++;
        return 1;
    case 0x000F80D0u: /* A9 BC C7 LDA #$C7BC */
        word = 0xC7BCu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80D3u;
        instance->instruction_count++;
        return 1;
    case 0x000F80D3u: /* 8D 32 43 STA $4332 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4332u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x80D6u;
        instance->instruction_count++;
        return 1;
    case 0x000F80D6u: /* A9 F3 C7 LDA #$C7F3 */
        word = 0xC7F3u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80D9u;
        instance->instruction_count++;
        return 1;
    case 0x000F80D9u: /* 8D 42 43 STA $4342 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4342u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x80DCu;
        instance->instruction_count++;
        return 1;
    case 0x000F80DCu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80DEu;
        instance->instruction_count++;
        return 1;
    case 0x040F80DEu: /* A9 0D LDA #$0D */
        byte = 0x0Du;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80E0u;
        instance->instruction_count++;
        return 1;
    case 0x040F80E0u: /* 8D 34 43 STA $4334 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4334u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80E3u;
        instance->instruction_count++;
        return 1;
    case 0x040F80E3u: /* 8D 44 43 STA $4344 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4344u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80E6u;
        instance->instruction_count++;
        return 1;
    case 0x040F80E6u: /* 8D 37 43 STA $4337 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4337u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80E9u;
        instance->instruction_count++;
        return 1;
    case 0x040F80E9u: /* 8D 47 43 STA $4347 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4347u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80ECu;
        instance->instruction_count++;
        return 1;
    case 0x040F80ECu: /* A9 18 LDA #$18 */
        byte = 0x18u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80EEu;
        instance->instruction_count++;
        return 1;
    case 0x040F80EEu: /* 8D 0C 42 STA $420C */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80F1u;
        instance->instruction_count++;
        return 1;
    case 0x040F80F1u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80F3u;
        instance->instruction_count++;
        return 1;
    case 0x000F80F3u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F80F4u: /* A9 20 20 LDA #$2020 */
        word = 0x2020u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80F7u;
        instance->instruction_count++;
        return 1;
    case 0x000F80F7u: /* 8D 86 1F STA $1F86 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F86u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x80FAu;
        instance->instruction_count++;
        return 1;
    case 0x000F80FAu: /* 8D 88 1F STA $1F88 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F88u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x80FDu;
        instance->instruction_count++;
        return 1;
    case 0x000F80FDu: /* 8D 8A 1F STA $1F8A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8100u;
        instance->instruction_count++;
        return 1;
    case 0x000F8100u: /* 8D 8C 1F STA $1F8C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8103u;
        instance->instruction_count++;
        return 1;
    case 0x000F8103u: /* 8D A3 1F STA $1FA3 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA3u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8106u;
        instance->instruction_count++;
        return 1;
    case 0x000F8106u: /* 8D A5 1F STA $1FA5 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA5u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8109u;
        instance->instruction_count++;
        return 1;
    case 0x000F8109u: /* 8D A7 1F STA $1FA7 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA7u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x810Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F810Cu: /* 8D A9 1F STA $1FA9 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA9u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x810Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F810Fu: /* A2 0E 00 LDX #$000E */
        word = 0x000Eu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8112u;
        instance->instruction_count++;
        return 1;
    case 0x000F8112u: /* BF 56 C6 0D LDA $0DC656,X */
        if (!tg_bus_read16(instance, ((0x0DC656u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8116u;
        instance->instruction_count++;
        return 1;
    case 0x000F8116u: /* 9D 76 1F STA $1F76,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F76u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8119u;
        instance->instruction_count++;
        return 1;
    case 0x000F8119u: /* 9D 93 1F STA $1F93,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F93u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x811Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F811Cu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x811Du;
        instance->instruction_count++;
        return 1;
    case 0x000F811Du: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x811Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F811Eu: /* 10 F2 BPL $0F:8112 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8112u : 0x8120u;
        instance->instruction_count++;
        return 1;
    case 0x000F8120u: /* A2 3E 00 LDX #$003E */
        word = 0x003Eu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8123u;
        instance->instruction_count++;
        return 1;
    case 0x000F8123u: /* BF 96 C6 0D LDA $0DC696,X */
        if (!tg_bus_read16(instance, ((0x0DC696u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8127u;
        instance->instruction_count++;
        return 1;
    case 0x000F8127u: /* 9D B2 1F STA $1FB2,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1FB2u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x812Au;
        instance->instruction_count++;
        return 1;
    case 0x000F812Au: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x812Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F812Bu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x812Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F812Cu: /* 10 F5 BPL $0F:8123 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8123u : 0x812Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F812Eu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x812Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F812Fu: /* 8E B0 1F STX $1FB0 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FB0u), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x8132u;
        instance->instruction_count++;
        return 1;
    case 0x000F8132u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F8133u: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8134u;
        instance->instruction_count++;
        return 1;
    case 0x000F8134u: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8135u;
        instance->instruction_count++;
        return 1;
    case 0x000F8135u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8137u;
        instance->instruction_count++;
        return 1;
    case 0x040F8137u: /* A9 18 LDA #$18 */
        byte = 0x18u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8139u;
        instance->instruction_count++;
        return 1;
    case 0x040F8139u: /* 8D 41 21 STA $2141 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x813Cu;
        instance->instruction_count++;
        return 1;
    case 0x040F813Cu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x813Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F813Eu: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x813Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F813Fu: /* 22 00 80 07 JSL $078000 */
        if (!tg_push8(instance, instance->cpu.pbr)) return 0;
        if (!tg_push16(instance, 0x8142u)) return 0;
        instance->cpu.pbr = 0x07u;
        instance->cpu.pc = 0x8000u;
        instance->instruction_count++;
        return 1;
    case 0x000F8143u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8145u;
        instance->instruction_count++;
        return 1;
    case 0x040F8145u: /* 9C 40 21 STZ $2140 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), 0u)) return 0;
        instance->cpu.pc = 0x8148u;
        instance->instruction_count++;
        return 1;
    case 0x040F8148u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x814Au;
        instance->instruction_count++;
        return 1;
    case 0x000F814Au: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x814Du;
        instance->instruction_count++;
        return 1;
    case 0x000F814Du: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x814Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F814Eu: /* D0 FD BNE $0F:814D */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x814Du : 0x8150u;
        instance->instruction_count++;
        return 1;
    case 0x000F8150u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8151u;
        instance->instruction_count++;
        return 1;
    case 0x000F8151u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8152u;
        instance->instruction_count++;
        return 1;
    case 0x000F8152u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8154u;
        instance->instruction_count++;
        return 1;
    case 0x040F8154u: /* 8D 40 21 STA $2140 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8157u;
        instance->instruction_count++;
        return 1;
    case 0x040F8157u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8159u;
        instance->instruction_count++;
        return 1;
    case 0x000F8159u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F815Au: /* 20 3C A5 JSR $A53C */
        if (!tg_push16(instance, 0x815Cu)) return 0;
        instance->cpu.pc = 0xA53Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F815Du: /* 64 81 STZ $81 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x815Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F815Fu: /* 20 95 8C JSR $8C95 */
        if (!tg_push16(instance, 0x8161u)) return 0;
        instance->cpu.pc = 0x8C95u;
        instance->instruction_count++;
        return 1;
    case 0x000F8162u: /* 64 81 STZ $81 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x8164u;
        instance->instruction_count++;
        return 1;
    case 0x000F8164u: /* AD 86 1F LDA $1F86 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F86u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8167u;
        instance->instruction_count++;
        return 1;
    case 0x000F8167u: /* 0D 88 1F ORA $1F88 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F88u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x816Au;
        instance->instruction_count++;
        return 1;
    case 0x000F816Au: /* 0D 8A 1F ORA $1F8A */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Au), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x816Du;
        instance->instruction_count++;
        return 1;
    case 0x000F816Du: /* 0D 8C 1F ORA $1F8C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Cu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8170u;
        instance->instruction_count++;
        return 1;
    case 0x000F8170u: /* C9 20 20 CMP #$2020 */
        word = 0x2020u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x8173u;
        instance->instruction_count++;
        return 1;
    case 0x000F8173u: /* D0 03 BNE $0F:8178 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8178u : 0x8175u;
        instance->instruction_count++;
        return 1;
    case 0x000F8175u: /* 20 A1 83 JSR $83A1 */
        if (!tg_push16(instance, 0x8177u)) return 0;
        instance->cpu.pc = 0x83A1u;
        instance->instruction_count++;
        return 1;
    case 0x000F8178u: /* E6 81 INC $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word + 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x817Au;
        instance->instruction_count++;
        return 1;
    case 0x000F817Au: /* AD A3 1F LDA $1FA3 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA3u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x817Du;
        instance->instruction_count++;
        return 1;
    case 0x000F817Du: /* 0D A5 1F ORA $1FA5 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA5u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8180u;
        instance->instruction_count++;
        return 1;
    case 0x000F8180u: /* 0D A7 1F ORA $1FA7 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA7u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8183u;
        instance->instruction_count++;
        return 1;
    case 0x000F8183u: /* 0D A9 1F ORA $1FA9 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA9u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8186u;
        instance->instruction_count++;
        return 1;
    case 0x000F8186u: /* C9 20 20 CMP #$2020 */
        word = 0x2020u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x8189u;
        instance->instruction_count++;
        return 1;
    case 0x000F8189u: /* D0 03 BNE $0F:818E */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x818Eu : 0x818Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F818Bu: /* 20 A1 83 JSR $83A1 */
        if (!tg_push16(instance, 0x818Du)) return 0;
        instance->cpu.pc = 0x83A1u;
        instance->instruction_count++;
        return 1;
    case 0x000F818Eu: /* 20 0E 82 JSR $820E */
        if (!tg_push16(instance, 0x8190u)) return 0;
        instance->cpu.pc = 0x820Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F8191u: /* 20 91 A6 JSR $A691 */
        if (!tg_push16(instance, 0x8193u)) return 0;
        instance->cpu.pc = 0xA691u;
        instance->instruction_count++;
        return 1;
    case 0x000F8194u: /* A9 0F 00 LDA #$000F */
        word = 0x000Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8197u;
        instance->instruction_count++;
        return 1;
    case 0x000F8197u: /* 85 46 STA $46 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x46u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8199u;
        instance->instruction_count++;
        return 1;
    case 0x000F8199u: /* 20 31 A1 JSR $A131 */
        if (!tg_push16(instance, 0x819Bu)) return 0;
        instance->cpu.pc = 0xA131u;
        instance->instruction_count++;
        return 1;
    case 0x000F819Cu: /* 20 35 9F JSR $9F35 */
        if (!tg_push16(instance, 0x819Eu)) return 0;
        instance->cpu.pc = 0x9F35u;
        instance->instruction_count++;
        return 1;
    case 0x000F819Fu: /* 20 1D 82 JSR $821D */
        if (!tg_push16(instance, 0x81A1u)) return 0;
        instance->cpu.pc = 0x821Du;
        instance->instruction_count++;
        return 1;
    case 0x000F81A2u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x81A4u;
        instance->instruction_count++;
        return 1;
    case 0x040F81A4u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x81A6u;
        instance->instruction_count++;
        return 1;
    case 0x040F81A6u: /* 8D 01 21 STA $2101 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2101u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x81A9u;
        instance->instruction_count++;
        return 1;
    case 0x040F81A9u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x81ABu;
        instance->instruction_count++;
        return 1;
    case 0x000F81ABu: /* AD 06 1F LDA $1F06 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81AEu;
        instance->instruction_count++;
        return 1;
    case 0x000F81AEu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81AFu;
        instance->instruction_count++;
        return 1;
    case 0x000F81AFu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x81B0u;
        instance->instruction_count++;
        return 1;
    case 0x000F81B0u: /* BF 7C C7 0D LDA $0DC77C,X */
        if (!tg_bus_read16(instance, ((0x0DC77Cu + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81B4u;
        instance->instruction_count++;
        return 1;
    case 0x000F81B4u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x81B5u;
        instance->instruction_count++;
        return 1;
    case 0x000F81B5u: /* 20 D0 9E JSR $9ED0 */
        if (!tg_push16(instance, 0x81B7u)) return 0;
        instance->cpu.pc = 0x9ED0u;
        instance->instruction_count++;
        return 1;
    case 0x000F81B8u: /* 20 DC 8A JSR $8ADC */
        if (!tg_push16(instance, 0x81BAu)) return 0;
        instance->cpu.pc = 0x8ADCu;
        instance->instruction_count++;
        return 1;
    case 0x000F81BBu: /* 20 81 8A JSR $8A81 */
        if (!tg_push16(instance, 0x81BDu)) return 0;
        instance->cpu.pc = 0x8A81u;
        instance->instruction_count++;
        return 1;
    case 0x000F81BEu: /* 20 DD 9D JSR $9DDD */
        if (!tg_push16(instance, 0x81C0u)) return 0;
        instance->cpu.pc = 0x9DDDu;
        instance->instruction_count++;
        return 1;
    case 0x000F81C1u: /* A9 84 00 LDA #$0084 */
        word = 0x0084u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81C4u;
        instance->instruction_count++;
        return 1;
    case 0x000F81C4u: /* 8D 24 04 STA $0424 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81C7u;
        instance->instruction_count++;
        return 1;
    case 0x000F81C7u: /* 20 3E A2 JSR $A23E */
        if (!tg_push16(instance, 0x81C9u)) return 0;
        instance->cpu.pc = 0xA23Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F81CAu: /* 20 D7 90 JSR $90D7 */
        if (!tg_push16(instance, 0x81CCu)) return 0;
        instance->cpu.pc = 0x90D7u;
        instance->instruction_count++;
        return 1;
    case 0x000F81CDu: /* A9 08 21 LDA #$2108 */
        word = 0x2108u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81D0u;
        instance->instruction_count++;
        return 1;
    case 0x000F81D0u: /* 8D 4E 05 STA $054E */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x054Eu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81D3u;
        instance->instruction_count++;
        return 1;
    case 0x000F81D3u: /* A9 18 00 LDA #$0018 */
        word = 0x0018u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81D6u;
        instance->instruction_count++;
        return 1;
    case 0x000F81D6u: /* 8D 50 05 STA $0550 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0550u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81D9u;
        instance->instruction_count++;
        return 1;
    case 0x000F81D9u: /* A9 FF 7F LDA #$7FFF */
        word = 0x7FFFu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81DCu;
        instance->instruction_count++;
        return 1;
    case 0x000F81DCu: /* 8D 52 05 STA $0552 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0552u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81DFu;
        instance->instruction_count++;
        return 1;
    case 0x000F81DFu: /* AD F6 1F LDA $1FF6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF6u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81E2u;
        instance->instruction_count++;
        return 1;
    case 0x000F81E2u: /* D0 09 BNE $0F:81ED */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x81EDu : 0x81E4u;
        instance->instruction_count++;
        return 1;
    case 0x000F81E4u: /* 20 B2 9D JSR $9DB2 */
        if (!tg_push16(instance, 0x81E6u)) return 0;
        instance->cpu.pc = 0x9DB2u;
        instance->instruction_count++;
        return 1;
    case 0x000F81E7u: /* 20 88 9E JSR $9E88 */
        if (!tg_push16(instance, 0x81E9u)) return 0;
        instance->cpu.pc = 0x9E88u;
        instance->instruction_count++;
        return 1;
    case 0x000F81EAu: /* 20 C5 9D JSR $9DC5 */
        if (!tg_push16(instance, 0x81ECu)) return 0;
        instance->cpu.pc = 0x9DC5u;
        instance->instruction_count++;
        return 1;
    case 0x000F81EDu: /* 20 1C 9E JSR $9E1C */
        if (!tg_push16(instance, 0x81EFu)) return 0;
        instance->cpu.pc = 0x9E1Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F81F0u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x81F2u;
        instance->instruction_count++;
        return 1;
    case 0x040F81F2u: /* A9 8F LDA #$8F */
        byte = 0x8Fu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x81F4u;
        instance->instruction_count++;
        return 1;
    case 0x040F81F4u: /* 85 42 STA $42 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x42u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x81F6u;
        instance->instruction_count++;
        return 1;
    case 0x040F81F6u: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x81F8u;
        instance->instruction_count++;
        return 1;
    case 0x040F81F8u: /* 8D 00 42 STA $4200 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4200u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x81FBu;
        instance->instruction_count++;
        return 1;
    case 0x040F81FBu: /* A9 80 LDA #$80 */
        byte = 0x80u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x81FDu;
        instance->instruction_count++;
        return 1;
    case 0x040F81FDu: /* 8D 00 21 STA $2100 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2100u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8200u;
        instance->instruction_count++;
        return 1;
    case 0x040F8200u: /* A9 68 LDA #$68 */
        byte = 0x68u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8202u;
        instance->instruction_count++;
        return 1;
    case 0x040F8202u: /* 8D 01 21 STA $2101 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2101u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8205u;
        instance->instruction_count++;
        return 1;
    case 0x040F8205u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8207u;
        instance->instruction_count++;
        return 1;
    case 0x000F8207u: /* 20 44 A6 JSR $A644 */
        if (!tg_push16(instance, 0x8209u)) return 0;
        instance->cpu.pc = 0xA644u;
        instance->instruction_count++;
        return 1;
    case 0x000F820Au: /* 20 F0 82 JSR $82F0 */
        if (!tg_push16(instance, 0x820Cu)) return 0;
        instance->cpu.pc = 0x82F0u;
        instance->instruction_count++;
        return 1;
    case 0x000F820Du: /* 6B RTL */
        if (!tg_pull16(instance, &word)) return 0;
        if (!tg_pull8(instance, &byte)) return 0;
        instance->cpu.pbr = byte;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F820Eu: /* A2 1E 00 LDX #$001E */
        word = 0x001Eu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8211u;
        instance->instruction_count++;
        return 1;
    case 0x000F8211u: /* BF C6 FD 0E LDA $0EFDC6,X */
        if (!tg_bus_read16(instance, ((0x0EFDC6u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8215u;
        instance->instruction_count++;
        return 1;
    case 0x000F8215u: /* 9D 2C 04 STA $042C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x042Cu + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8218u;
        instance->instruction_count++;
        return 1;
    case 0x000F8218u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8219u;
        instance->instruction_count++;
        return 1;
    case 0x000F8219u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x821Au;
        instance->instruction_count++;
        return 1;
    case 0x000F821Au: /* 10 F5 BPL $0F:8211 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8211u : 0x821Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F821Cu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F821Du: /* AD 06 1F LDA $1F06 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8220u;
        instance->instruction_count++;
        return 1;
    case 0x000F8220u: /* C9 10 00 CMP #$0010 */
        word = 0x0010u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x8223u;
        instance->instruction_count++;
        return 1;
    case 0x000F8223u: /* B0 06 BCS $0F:822B */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x822Bu : 0x8225u;
        instance->instruction_count++;
        return 1;
    case 0x000F8225u: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8226u;
        instance->instruction_count++;
        return 1;
    case 0x000F8226u: /* A2 00 80 LDX #$8000 */
        word = 0x8000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8229u;
        instance->instruction_count++;
        return 1;
    case 0x000F8229u: /* 80 07 BRA $0F:8232 */
        instance->cpu.pc = 0x8232u;
        instance->instruction_count++;
        return 1;
    case 0x000F822Bu: /* A2 1F 91 LDX #$911F */
        word = 0x911Fu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x822Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F822Eu: /* 29 0F 00 AND #$000F */
        word = 0x000Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8231u;
        instance->instruction_count++;
        return 1;
    case 0x000F8231u: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8232u;
        instance->instruction_count++;
        return 1;
    case 0x000F8232u: /* A9 0D 80 LDA #$800D */
        word = 0x800Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8235u;
        instance->instruction_count++;
        return 1;
    case 0x000F8235u: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8238u;
        instance->instruction_count++;
        return 1;
    case 0x000F8238u: /* 20 34 B3 JSR $B334 */
        if (!tg_push16(instance, 0x823Au)) return 0;
        instance->cpu.pc = 0xB334u;
        instance->instruction_count++;
        return 1;
    case 0x000F823Bu: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x823Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F823Eu: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x823Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F823Fu: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0x8240u;
        instance->instruction_count++;
        return 1;
    case 0x000F8240u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8241u;
        instance->instruction_count++;
        return 1;
    case 0x000F8241u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8242u;
        instance->instruction_count++;
        return 1;
    case 0x000F8242u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x8243u;
        instance->instruction_count++;
        return 1;
    case 0x000F8243u: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x8244u;
        instance->instruction_count++;
        return 1;
    case 0x000F8244u: /* BB TYX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.y);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x8245u;
        instance->instruction_count++;
        return 1;
    case 0x000F8245u: /* BF 00 20 7E LDA $7E2000,X */
        if (!tg_bus_read16(instance, ((0x7E2000u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8249u;
        instance->instruction_count++;
        return 1;
    case 0x000F8249u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x824Au;
        instance->instruction_count++;
        return 1;
    case 0x000F824Au: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x824Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F824Bu: /* 9B TXY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x824Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F824Cu: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x824Du;
        instance->instruction_count++;
        return 1;
    case 0x000F824Du: /* 9F 00 70 7E STA $7E7000,X */
        if (!tg_bus_store16(instance, ((0x7E7000u + instance->cpu.x) & 0xFFFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8251u;
        instance->instruction_count++;
        return 1;
    case 0x000F8251u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8252u;
        instance->instruction_count++;
        return 1;
    case 0x000F8252u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8253u;
        instance->instruction_count++;
        return 1;
    case 0x000F8253u: /* E0 F0 07 CPX #$07F0 */
        word = 0x07F0u;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0x8256u;
        instance->instruction_count++;
        return 1;
    case 0x000F8256u: /* B0 06 BCS $0F:825E */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x825Eu : 0x8258u;
        instance->instruction_count++;
        return 1;
    case 0x000F8258u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x8259u;
        instance->instruction_count++;
        return 1;
    case 0x000F8259u: /* 29 0F 00 AND #$000F */
        word = 0x000Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x825Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F825Cu: /* D0 E5 BNE $0F:8243 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8243u : 0x825Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F825Eu: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8261u;
        instance->instruction_count++;
        return 1;
    case 0x000F8261u: /* 9F 00 70 7E STA $7E7000,X */
        if (!tg_bus_store16(instance, ((0x7E7000u + instance->cpu.x) & 0xFFFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8265u;
        instance->instruction_count++;
        return 1;
    case 0x000F8265u: /* 9F 02 70 7E STA $7E7002,X */
        if (!tg_bus_store16(instance, ((0x7E7002u + instance->cpu.x) & 0xFFFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8269u;
        instance->instruction_count++;
        return 1;
    case 0x000F8269u: /* 9F 04 70 7E STA $7E7004,X */
        if (!tg_bus_store16(instance, ((0x7E7004u + instance->cpu.x) & 0xFFFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x826Du;
        instance->instruction_count++;
        return 1;
    case 0x000F826Du: /* 9F 06 70 7E STA $7E7006,X */
        if (!tg_bus_store16(instance, ((0x7E7006u + instance->cpu.x) & 0xFFFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8271u;
        instance->instruction_count++;
        return 1;
    case 0x000F8271u: /* 9F 08 70 7E STA $7E7008,X */
        if (!tg_bus_store16(instance, ((0x7E7008u + instance->cpu.x) & 0xFFFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8275u;
        instance->instruction_count++;
        return 1;
    case 0x000F8275u: /* 9F 0A 70 7E STA $7E700A,X */
        if (!tg_bus_store16(instance, ((0x7E700Au + instance->cpu.x) & 0xFFFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8279u;
        instance->instruction_count++;
        return 1;
    case 0x000F8279u: /* 9F 0C 70 7E STA $7E700C,X */
        if (!tg_bus_store16(instance, ((0x7E700Cu + instance->cpu.x) & 0xFFFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x827Du;
        instance->instruction_count++;
        return 1;
    case 0x000F827Du: /* 9F 0E 70 7E STA $7E700E,X */
        if (!tg_bus_store16(instance, ((0x7E700Eu + instance->cpu.x) & 0xFFFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8281u;
        instance->instruction_count++;
        return 1;
    case 0x000F8281u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x8282u;
        instance->instruction_count++;
        return 1;
    case 0x000F8282u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x8283u;
        instance->instruction_count++;
        return 1;
    case 0x000F8283u: /* 69 10 00 ADC #$0010 */
        word = 0x0010u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x8286u;
        instance->instruction_count++;
        return 1;
    case 0x000F8286u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x8287u;
        instance->instruction_count++;
        return 1;
    case 0x000F8287u: /* E0 00 08 CPX #$0800 */
        word = 0x0800u;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0x828Au;
        instance->instruction_count++;
        return 1;
    case 0x000F828Au: /* 90 B7 BCC $0F:8243 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x8243u : 0x828Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F828Cu: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x828Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F828Fu: /* 20 4D A2 JSR $A24D */
        if (!tg_push16(instance, 0x8291u)) return 0;
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F8292u: /* A9 00 22 LDA #$2200 */
        word = 0x2200u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8295u;
        instance->instruction_count++;
        return 1;
    case 0x000F8295u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8298u;
        instance->instruction_count++;
        return 1;
    case 0x000F8298u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x829Au;
        instance->instruction_count++;
        return 1;
    case 0x040F829Au: /* A9 80 LDA #$80 */
        byte = 0x80u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x829Cu;
        instance->instruction_count++;
        return 1;
    case 0x040F829Cu: /* 8D 15 21 STA $2115 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2115u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x829Fu;
        instance->instruction_count++;
        return 1;
    case 0x040F829Fu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x82A1u;
        instance->instruction_count++;
        return 1;
    case 0x040F82A1u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x82A4u;
        instance->instruction_count++;
        return 1;
    case 0x040F82A4u: /* A9 7E LDA #$7E */
        byte = 0x7Eu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x82A6u;
        instance->instruction_count++;
        return 1;
    case 0x040F82A6u: /* 8D 14 43 STA $4314 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4314u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x82A9u;
        instance->instruction_count++;
        return 1;
    case 0x040F82A9u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x82ABu;
        instance->instruction_count++;
        return 1;
    case 0x000F82ABu: /* A9 00 70 LDA #$7000 */
        word = 0x7000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82AEu;
        instance->instruction_count++;
        return 1;
    case 0x000F82AEu: /* 8D 12 43 STA $4312 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4312u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82B1u;
        instance->instruction_count++;
        return 1;
    case 0x000F82B1u: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82B4u;
        instance->instruction_count++;
        return 1;
    case 0x000F82B4u: /* 8D 10 43 STA $4310 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4310u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82B7u;
        instance->instruction_count++;
        return 1;
    case 0x000F82B7u: /* A9 00 08 LDA #$0800 */
        word = 0x0800u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82BAu;
        instance->instruction_count++;
        return 1;
    case 0x000F82BAu: /* 8D 15 43 STA $4315 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4315u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82BDu;
        instance->instruction_count++;
        return 1;
    case 0x000F82BDu: /* A9 02 00 LDA #$0002 */
        word = 0x0002u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82C0u;
        instance->instruction_count++;
        return 1;
    case 0x000F82C0u: /* 8D 24 04 STA $0424 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82C3u;
        instance->instruction_count++;
        return 1;
    case 0x000F82C3u: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82C6u;
        instance->instruction_count++;
        return 1;
    case 0x000F82C6u: /* 20 4D A2 JSR $A24D */
        if (!tg_push16(instance, 0x82C8u)) return 0;
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F82C9u: /* AD 06 1F LDA $1F06 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82CCu;
        instance->instruction_count++;
        return 1;
    case 0x000F82CCu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82CDu;
        instance->instruction_count++;
        return 1;
    case 0x000F82CDu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x82CEu;
        instance->instruction_count++;
        return 1;
    case 0x000F82CEu: /* BF 86 FD 0E LDA $0EFD86,X */
        if (!tg_bus_read16(instance, ((0x0EFD86u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82D2u;
        instance->instruction_count++;
        return 1;
    case 0x000F82D2u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x82D3u;
        instance->instruction_count++;
        return 1;
    case 0x000F82D3u: /* A9 20 1D LDA #$1D20 */
        word = 0x1D20u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82D6u;
        instance->instruction_count++;
        return 1;
    case 0x000F82D6u: /* A0 07 00 LDY #$0007 */
        word = 0x0007u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82D9u;
        instance->instruction_count++;
        return 1;
    case 0x000F82D9u: /* 9D 6C 0C STA $0C6C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0C6Cu + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82DCu;
        instance->instruction_count++;
        return 1;
    case 0x000F82DCu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82DDu;
        instance->instruction_count++;
        return 1;
    case 0x000F82DDu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82DEu;
        instance->instruction_count++;
        return 1;
    case 0x000F82DEu: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82DFu;
        instance->instruction_count++;
        return 1;
    case 0x000F82DFu: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82E0u;
        instance->instruction_count++;
        return 1;
    case 0x000F82E0u: /* 10 F7 BPL $0F:82D9 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x82D9u : 0x82E2u;
        instance->instruction_count++;
        return 1;
    case 0x000F82E2u: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82E3u;
        instance->instruction_count++;
        return 1;
    case 0x000F82E3u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x82E4u;
        instance->instruction_count++;
        return 1;
    case 0x000F82E4u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x82E5u;
        instance->instruction_count++;
        return 1;
    case 0x000F82E5u: /* 69 30 00 ADC #$0030 */
        word = 0x0030u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x82E8u;
        instance->instruction_count++;
        return 1;
    case 0x000F82E8u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x82E9u;
        instance->instruction_count++;
        return 1;
    case 0x000F82E9u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82EAu;
        instance->instruction_count++;
        return 1;
    case 0x000F82EAu: /* C9 60 1D CMP #$1D60 */
        word = 0x1D60u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x82EDu;
        instance->instruction_count++;
        return 1;
    case 0x000F82EDu: /* 90 E7 BCC $0F:82D6 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x82D6u : 0x82EFu;
        instance->instruction_count++;
        return 1;
    case 0x000F82EFu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F82F0u: /* A9 00 09 LDA #$0900 */
        word = 0x0900u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82F3u;
        instance->instruction_count++;
        return 1;
    case 0x000F82F3u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82F6u;
        instance->instruction_count++;
        return 1;
    case 0x000F82F6u: /* A9 91 2C LDA #$2C91 */
        word = 0x2C91u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82F9u;
        instance->instruction_count++;
        return 1;
    case 0x000F82F9u: /* 8D 4C 04 STA $044C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82FCu;
        instance->instruction_count++;
        return 1;
    case 0x000F82FCu: /* A2 1E 00 LDX #$001E */
        word = 0x001Eu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82FFu;
        instance->instruction_count++;
        return 1;
    case 0x000F82FFu: /* 9C 18 21 STZ $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), 0u)) return 0;
        instance->cpu.pc = 0x8302u;
        instance->instruction_count++;
        return 1;
    case 0x000F8302u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8303u;
        instance->instruction_count++;
        return 1;
    case 0x000F8303u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8304u;
        instance->instruction_count++;
        return 1;
    case 0x000F8304u: /* 10 F9 BPL $0F:82FF */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x82FFu : 0x8306u;
        instance->instruction_count++;
        return 1;
    case 0x000F8306u: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8309u;
        instance->instruction_count++;
        return 1;
    case 0x000F8309u: /* BB TYX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.y);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x830Au;
        instance->instruction_count++;
        return 1;
    case 0x000F830Au: /* 20 6D 83 JSR $836D */
        if (!tg_push16(instance, 0x830Cu)) return 0;
        instance->cpu.pc = 0x836Du;
        instance->instruction_count++;
        return 1;
    case 0x000F830Du: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x830Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F830Eu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x830Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F830Fu: /* C0 80 00 CPY #$0080 */
        word = 0x0080u;
        tg_compare16(instance, (uint16_t)instance->cpu.y, word);
        instance->cpu.pc = 0x8312u;
        instance->instruction_count++;
        return 1;
    case 0x000F8312u: /* 90 F6 BCC $0F:830A */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x830Au : 0x8314u;
        instance->instruction_count++;
        return 1;
    case 0x000F8314u: /* A2 40 00 LDX #$0040 */
        word = 0x0040u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8317u;
        instance->instruction_count++;
        return 1;
    case 0x000F8317u: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x831Au;
        instance->instruction_count++;
        return 1;
    case 0x000F831Au: /* A9 21 0C LDA #$0C21 */
        word = 0x0C21u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x831Du;
        instance->instruction_count++;
        return 1;
    case 0x000F831Du: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8320u;
        instance->instruction_count++;
        return 1;
    case 0x000F8320u: /* 8D 4C 04 STA $044C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8323u;
        instance->instruction_count++;
        return 1;
    case 0x000F8323u: /* B9 6C 14 LDA $146C,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x146Cu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8326u;
        instance->instruction_count++;
        return 1;
    case 0x000F8326u: /* 09 00 1C ORA #$1C00 */
        word = 0x1C00u;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8329u;
        instance->instruction_count++;
        return 1;
    case 0x000F8329u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x832Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F832Cu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x832Du;
        instance->instruction_count++;
        return 1;
    case 0x000F832Du: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x832Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F832Eu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x832Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F832Fu: /* F0 0F BEQ $0F:8340 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x8340u : 0x8331u;
        instance->instruction_count++;
        return 1;
    case 0x000F8331u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x8332u;
        instance->instruction_count++;
        return 1;
    case 0x000F8332u: /* 29 07 00 AND #$0007 */
        word = 0x0007u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8335u;
        instance->instruction_count++;
        return 1;
    case 0x000F8335u: /* D0 EC BNE $0F:8323 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8323u : 0x8337u;
        instance->instruction_count++;
        return 1;
    case 0x000F8337u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x8338u;
        instance->instruction_count++;
        return 1;
    case 0x000F8338u: /* AD 4C 04 LDA $044C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Cu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x833Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F833Bu: /* 69 20 00 ADC #$0020 */
        word = 0x0020u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x833Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F833Eu: /* D0 DD BNE $0F:831D */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x831Du : 0x8340u;
        instance->instruction_count++;
        return 1;
    case 0x000F8340u: /* A2 40 00 LDX #$0040 */
        word = 0x0040u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8343u;
        instance->instruction_count++;
        return 1;
    case 0x000F8343u: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8346u;
        instance->instruction_count++;
        return 1;
    case 0x000F8346u: /* A9 E1 0D LDA #$0DE1 */
        word = 0x0DE1u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8349u;
        instance->instruction_count++;
        return 1;
    case 0x000F8349u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x834Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F834Cu: /* 8D 4C 04 STA $044C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x834Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F834Fu: /* B9 6C 14 LDA $146C,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x146Cu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8352u;
        instance->instruction_count++;
        return 1;
    case 0x000F8352u: /* 09 00 1C ORA #$1C00 */
        word = 0x1C00u;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8355u;
        instance->instruction_count++;
        return 1;
    case 0x000F8355u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8358u;
        instance->instruction_count++;
        return 1;
    case 0x000F8358u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8359u;
        instance->instruction_count++;
        return 1;
    case 0x000F8359u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x835Au;
        instance->instruction_count++;
        return 1;
    case 0x000F835Au: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x835Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F835Bu: /* F0 0F BEQ $0F:836C */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x836Cu : 0x835Du;
        instance->instruction_count++;
        return 1;
    case 0x000F835Du: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x835Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F835Eu: /* 29 07 00 AND #$0007 */
        word = 0x0007u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8361u;
        instance->instruction_count++;
        return 1;
    case 0x000F8361u: /* D0 EC BNE $0F:834F */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x834Fu : 0x8363u;
        instance->instruction_count++;
        return 1;
    case 0x000F8363u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x8364u;
        instance->instruction_count++;
        return 1;
    case 0x000F8364u: /* AD 4C 04 LDA $044C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Cu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8367u;
        instance->instruction_count++;
        return 1;
    case 0x000F8367u: /* 69 20 00 ADC #$0020 */
        word = 0x0020u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x836Au;
        instance->instruction_count++;
        return 1;
    case 0x000F836Au: /* D0 DD BNE $0F:8349 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8349u : 0x836Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F836Cu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F836Du: /* 5A PHY */
        if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0x836Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F836Eu: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x836Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F836Fu: /* A0 0F 00 LDY #$000F */
        word = 0x000Fu;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8372u;
        instance->instruction_count++;
        return 1;
    case 0x000F8372u: /* BF 00 70 7E LDA $7E7000,X */
        if (!tg_bus_read16(instance, ((0x7E7000u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8376u;
        instance->instruction_count++;
        return 1;
    case 0x000F8376u: /* D0 0E BNE $0F:8386 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8386u : 0x8378u;
        instance->instruction_count++;
        return 1;
    case 0x000F8378u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8379u;
        instance->instruction_count++;
        return 1;
    case 0x000F8379u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x837Au;
        instance->instruction_count++;
        return 1;
    case 0x000F837Au: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x837Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F837Bu: /* 10 F5 BPL $0F:8372 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8372u : 0x837Du;
        instance->instruction_count++;
        return 1;
    case 0x000F837Du: /* 7A PLY */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x837Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F837Eu: /* 7A PLY */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x837Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F837Fu: /* A9 90 2C LDA #$2C90 */
        word = 0x2C90u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8382u;
        instance->instruction_count++;
        return 1;
    case 0x000F8382u: /* 99 6C 14 STA $146C,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x146Cu + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8385u;
        instance->instruction_count++;
        return 1;
    case 0x000F8385u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F8386u: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8387u;
        instance->instruction_count++;
        return 1;
    case 0x000F8387u: /* A0 0F 00 LDY #$000F */
        word = 0x000Fu;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x838Au;
        instance->instruction_count++;
        return 1;
    case 0x000F838Au: /* BF 00 70 7E LDA $7E7000,X */
        if (!tg_bus_read16(instance, ((0x7E7000u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x838Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F838Eu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8391u;
        instance->instruction_count++;
        return 1;
    case 0x000F8391u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8392u;
        instance->instruction_count++;
        return 1;
    case 0x000F8392u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8393u;
        instance->instruction_count++;
        return 1;
    case 0x000F8393u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8394u;
        instance->instruction_count++;
        return 1;
    case 0x000F8394u: /* 10 F4 BPL $0F:838A */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x838Au : 0x8396u;
        instance->instruction_count++;
        return 1;
    case 0x000F8396u: /* 7A PLY */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8397u;
        instance->instruction_count++;
        return 1;
    case 0x000F8397u: /* AD 4C 04 LDA $044C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Cu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x839Au;
        instance->instruction_count++;
        return 1;
    case 0x000F839Au: /* 99 6C 14 STA $146C,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x146Cu + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x839Du;
        instance->instruction_count++;
        return 1;
    case 0x000F839Du: /* EE 4C 04 INC $044C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Cu), &word)) return 0;
        word = (uint16_t)(word + 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Cu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83A0u;
        instance->instruction_count++;
        return 1;
    case 0x000F83A0u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F83A1u: /* A5 81 LDA $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83A3u;
        instance->instruction_count++;
        return 1;
    case 0x000F83A3u: /* D0 19 BNE $0F:83BE */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x83BEu : 0x83A5u;
        instance->instruction_count++;
        return 1;
    case 0x000F83A5u: /* AD BC B4 LDA $B4BC */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0xB4BCu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83A8u;
        instance->instruction_count++;
        return 1;
    case 0x000F83A8u: /* 8D 86 1F STA $1F86 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F86u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x83ABu;
        instance->instruction_count++;
        return 1;
    case 0x000F83ABu: /* AD BE B4 LDA $B4BE */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0xB4BEu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83AEu;
        instance->instruction_count++;
        return 1;
    case 0x000F83AEu: /* 8D 88 1F STA $1F88 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F88u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x83B1u;
        instance->instruction_count++;
        return 1;
    case 0x000F83B1u: /* AD C0 B4 LDA $B4C0 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0xB4C0u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83B4u;
        instance->instruction_count++;
        return 1;
    case 0x000F83B4u: /* 8D 8A 1F STA $1F8A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x83B7u;
        instance->instruction_count++;
        return 1;
    case 0x000F83B7u: /* AD C2 B4 LDA $B4C2 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0xB4C2u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83BAu;
        instance->instruction_count++;
        return 1;
    case 0x000F83BAu: /* 8D 8C 1F STA $1F8C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x83BDu;
        instance->instruction_count++;
        return 1;
    case 0x000F83BDu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F83BEu: /* AD C9 B4 LDA $B4C9 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0xB4C9u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83C1u;
        instance->instruction_count++;
        return 1;
    case 0x000F83C1u: /* 8D A3 1F STA $1FA3 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA3u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x83C4u;
        instance->instruction_count++;
        return 1;
    case 0x000F83C4u: /* AD CB B4 LDA $B4CB */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0xB4CBu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83C7u;
        instance->instruction_count++;
        return 1;
    case 0x000F83C7u: /* 8D A5 1F STA $1FA5 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA5u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x83CAu;
        instance->instruction_count++;
        return 1;
    case 0x000F83CAu: /* AD CD B4 LDA $B4CD */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0xB4CDu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83CDu;
        instance->instruction_count++;
        return 1;
    case 0x000F83CDu: /* 8D A7 1F STA $1FA7 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA7u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x83D0u;
        instance->instruction_count++;
        return 1;
    case 0x000F83D0u: /* AD CF B4 LDA $B4CF */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0xB4CFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83D3u;
        instance->instruction_count++;
        return 1;
    case 0x000F83D3u: /* 8D A9 1F STA $1FA9 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA9u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x83D6u;
        instance->instruction_count++;
        return 1;
    case 0x000F83D6u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F83D7u: /* 20 3C A5 JSR $A53C */
        if (!tg_push16(instance, 0x83D9u)) return 0;
        instance->cpu.pc = 0xA53Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F83DAu: /* 20 91 A6 JSR $A691 */
        if (!tg_push16(instance, 0x83DCu)) return 0;
        instance->cpu.pc = 0xA691u;
        instance->instruction_count++;
        return 1;
    case 0x000F83DDu: /* AD F6 1F LDA $1FF6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF6u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83E0u;
        instance->instruction_count++;
        return 1;
    case 0x000F83E0u: /* F0 09 BEQ $0F:83EB */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x83EBu : 0x83E2u;
        instance->instruction_count++;
        return 1;
    case 0x000F83E2u: /* AD 08 1F LDA $1F08 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F08u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83E5u;
        instance->instruction_count++;
        return 1;
    case 0x000F83E5u: /* 8D 06 1F STA $1F06 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x83E8u;
        instance->instruction_count++;
        return 1;
    case 0x000F83E8u: /* 4C 5A 81 JMP $815A */
        instance->cpu.pc = 0x815Au;
        instance->instruction_count++;
        return 1;
    case 0x000F83EBu: /* AD 10 1F LDA $1F10 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F10u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83EEu;
        instance->instruction_count++;
        return 1;
    case 0x000F83EEu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83EFu;
        instance->instruction_count++;
        return 1;
    case 0x000F83EFu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x83F0u;
        instance->instruction_count++;
        return 1;
    case 0x000F83F0u: /* AD 06 1F LDA $1F06 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83F3u;
        instance->instruction_count++;
        return 1;
    case 0x000F83F3u: /* 29 1C 00 AND #$001C */
        word = 0x001Cu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83F6u;
        instance->instruction_count++;
        return 1;
    case 0x000F83F6u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83F7u;
        instance->instruction_count++;
        return 1;
    case 0x000F83F7u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x83F8u;
        instance->instruction_count++;
        return 1;
    case 0x000F83F8u: /* D9 0A 1F CMP $1F0A,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F0Au + instance->cpu.y)), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x83FBu;
        instance->instruction_count++;
        return 1;
    case 0x000F83FBu: /* 90 03 BCC $0F:8400 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x8400u : 0x83FDu;
        instance->instruction_count++;
        return 1;
    case 0x000F83FDu: /* 99 0A 1F STA $1F0A,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F0Au + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8400u;
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
