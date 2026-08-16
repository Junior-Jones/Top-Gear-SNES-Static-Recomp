/* Generated from the exact Top Gear ROM and the frozen Version 14 static-$8068 semantic context receipt.
   No runtime opcode decoder, hybrid trace, or emulator endpoint is used. */
#include "topgear_internal.h"
#include "topgear_v14_post_audio_scpu.h"

unsigned tg_v14_generated_post_audio_context_count(void) { return 275u; }

int tg_v14_generated_post_audio_step(struct TopGearRecomp *instance) {
    uint32_t key;
    uint16_t word = 0u;
    uint8_t byte = 0u;
    if (!instance) return 0;
    key = tg_generated_context_key(instance);
    switch (key) {
    case 0x00008068u: /* E2 20  SEP #$20; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8068")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x806Au;
        instance->instruction_count++;
        return 1;
    case 0x0400806Au: /* A9 00  LDA #$00; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:806A")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x806Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400806Cu: /* 8D 40 21  STA $2140; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:806C")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x806Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400806Fu: /* A2 00 00  LDX #$0000; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:806F")) return 0;
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8072u;
        instance->instruction_count++;
        return 1;
    case 0x04008072u: /* E8  INX; semantic visits 65536 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8072")) return 0;
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8073u;
        instance->instruction_count++;
        return 1;
    case 0x04008073u: /* D0 FD  BNE $00:8072; semantic visits 65536 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8073")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8072u : 0x8075u;
        instance->instruction_count++;
        return 1;
    case 0x04008075u: /* A9 01  LDA #$01; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8075")) return 0;
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8077u;
        instance->instruction_count++;
        return 1;
    case 0x04008077u: /* 8D 40 21  STA $2140; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8077")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x807Au;
        instance->instruction_count++;
        return 1;
    case 0x0400807Au: /* C2 20  REP #$20; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:807A")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x807Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000807Cu: /* AD 08 1F  LDA $1F08; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:807C")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F08u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x807Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000807Fu: /* 29 1C 00  AND #$001C; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:807F")) return 0;
        word = 0x001Cu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8082u;
        instance->instruction_count++;
        return 1;
    case 0x00008082u: /* 8D 06 1F  STA $1F06; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8082")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8085u;
        instance->instruction_count++;
        return 1;
    case 0x00008085u: /* AD F6 1F  LDA $1FF6; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8085")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF6u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8088u;
        instance->instruction_count++;
        return 1;
    case 0x00008088u: /* F0 1C  BEQ $00:80A6; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8088")) return 0;
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x80A6u : 0x808Au;
        instance->instruction_count++;
        return 1;
    case 0x000080A6u: /* A2 FE 1E  LDX #$1EFE; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80A6")) return 0;
        word = 0x1EFEu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80A9u;
        instance->instruction_count++;
        return 1;
    case 0x000080A9u: /* 74 00  STZ $00,X; semantic visits 3968 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80A9")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x00u + instance->cpu.x) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x80ABu;
        instance->instruction_count++;
        return 1;
    case 0x000080ABu: /* CA  DEX; semantic visits 3968 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80AB")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80ACu;
        instance->instruction_count++;
        return 1;
    case 0x000080ACu: /* CA  DEX; semantic visits 3968 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80AC")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80ADu;
        instance->instruction_count++;
        return 1;
    case 0x000080ADu: /* 10 FA  BPL $00:80A9; semantic visits 3968 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80AD")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x80A9u : 0x80AFu;
        instance->instruction_count++;
        return 1;
    case 0x000080AFu: /* A2 12 00  LDX #$0012; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80AF")) return 0;
        word = 0x0012u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80B2u;
        instance->instruction_count++;
        return 1;
    case 0x000080B2u: /* 9E 4E 1F  STZ $1F4E,X; semantic visits 10 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80B2")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F4Eu + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x80B5u;
        instance->instruction_count++;
        return 1;
    case 0x000080B5u: /* CA  DEX; semantic visits 10 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80B5")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80B6u;
        instance->instruction_count++;
        return 1;
    case 0x000080B6u: /* CA  DEX; semantic visits 10 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80B6")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80B7u;
        instance->instruction_count++;
        return 1;
    case 0x000080B7u: /* 10 F9  BPL $00:80B2; semantic visits 10 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80B7")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x80B2u : 0x80B9u;
        instance->instruction_count++;
        return 1;
    case 0x000080B9u: /* A2 08 00  LDX #$0008; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80B9")) return 0;
        word = 0x0008u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80BCu;
        instance->instruction_count++;
        return 1;
    case 0x000080BCu: /* A0 00 00  LDY #$0000; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80BC")) return 0;
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80BFu;
        instance->instruction_count++;
        return 1;
    case 0x000080BFu: /* B9 86 1F  LDA $1F86,Y; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80BF")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F86u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80C2u;
        instance->instruction_count++;
        return 1;
    case 0x000080C2u: /* 29 FF 00  AND #$00FF; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80C2")) return 0;
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80C5u;
        instance->instruction_count++;
        return 1;
    case 0x000080C5u: /* C9 20 00  CMP #$0020; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80C5")) return 0;
        word = 0x0020u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x80C8u;
        instance->instruction_count++;
        return 1;
    case 0x000080C8u: /* F0 14  BEQ $00:80DE; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80C8")) return 0;
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x80DEu : 0x80CAu;
        instance->instruction_count++;
        return 1;
    case 0x000080CAu: /* C9 31 00  CMP #$0031; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80CA")) return 0;
        word = 0x0031u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x80CDu;
        instance->instruction_count++;
        return 1;
    case 0x000080CDu: /* F0 0F  BEQ $00:80DE; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80CD")) return 0;
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x80DEu : 0x80CFu;
        instance->instruction_count++;
        return 1;
    case 0x000080CFu: /* C9 32 00  CMP #$0032; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80CF")) return 0;
        word = 0x0032u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x80D2u;
        instance->instruction_count++;
        return 1;
    case 0x000080D2u: /* F0 0A  BEQ $00:80DE; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80D2")) return 0;
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x80DEu : 0x80D4u;
        instance->instruction_count++;
        return 1;
    case 0x000080D4u: /* C9 41 00  CMP #$0041; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80D4")) return 0;
        word = 0x0041u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x80D7u;
        instance->instruction_count++;
        return 1;
    case 0x000080D7u: /* 90 34  BCC $00:810D; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:80D7")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x810Du : 0x80D9u;
        instance->instruction_count++;
        return 1;
    case 0x0000810Du: /* A2 FE 00  LDX #$00FE; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:810D")) return 0;
        word = 0x00FEu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8110u;
        instance->instruction_count++;
        return 1;
    case 0x00008110u: /* 9E 00 1F  STZ $1F00,X; semantic visits 128 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8110")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F00u + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x8113u;
        instance->instruction_count++;
        return 1;
    case 0x00008113u: /* CA  DEX; semantic visits 128 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8113")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8114u;
        instance->instruction_count++;
        return 1;
    case 0x00008114u: /* CA  DEX; semantic visits 128 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8114")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8115u;
        instance->instruction_count++;
        return 1;
    case 0x00008115u: /* 10 F9  BPL $00:8110; semantic visits 128 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8115")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8110u : 0x8117u;
        instance->instruction_count++;
        return 1;
    case 0x00008117u: /* A9 56 19  LDA #$1956; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8117")) return 0;
        word = 0x1956u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x811Au;
        instance->instruction_count++;
        return 1;
    case 0x0000811Au: /* 8D 91 1F  STA $1F91; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:811A")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F91u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x811Du;
        instance->instruction_count++;
        return 1;
    case 0x0000811Du: /* A9 ED 5B  LDA #$5BED; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:811D")) return 0;
        word = 0x5BEDu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8120u;
        instance->instruction_count++;
        return 1;
    case 0x00008120u: /* 8D AE 1F  STA $1FAE; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8120")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FAEu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8123u;
        instance->instruction_count++;
        return 1;
    case 0x00008123u: /* A9 00 00  LDA #$0000; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8123")) return 0;
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8126u;
        instance->instruction_count++;
        return 1;
    case 0x00008126u: /* 22 6D 80 0F  JSL $0F806D; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8126")) return 0;
        if (!tg_push8(instance, instance->cpu.pbr)) return 0;
        if (!tg_push16(instance, 0x8129u)) return 0;
        instance->cpu.pbr = 0x0Fu;
        instance->cpu.pc = 0x806Du;
        instance->instruction_count++;
        return 1;
    case 0x000F806Du: /* 4B  PHK; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "0F:806D")) return 0;
        if (!tg_push8(instance, instance->cpu.pbr)) return 0;
        instance->cpu.pc = 0x806Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F806Eu: /* AB  PLB; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "0F:806E")) return 0;
        if (!tg_pull8(instance, &byte)) return 0;
        instance->cpu.dbr = byte;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x806Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F806Fu: /* 48  PHA; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:806F")) return 0;
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8070u;
        instance->instruction_count++;
        return 1;
    case 0x000F8070u: /* E2 20  SEP #$20; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8070")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8072u;
        instance->instruction_count++;
        return 1;
    case 0x040F8072u: /* 9C 0B 42  STZ $420B; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:8072")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), 0u)) return 0;
        instance->cpu.pc = 0x8075u;
        instance->instruction_count++;
        return 1;
    case 0x040F8075u: /* 9C 0C 42  STZ $420C; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:8075")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Cu), 0u)) return 0;
        instance->cpu.pc = 0x8078u;
        instance->instruction_count++;
        return 1;
    case 0x040F8078u: /* C2 30  REP #$30; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:8078")) return 0;
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x807Au;
        instance->instruction_count++;
        return 1;
    case 0x000F807Au: /* 64 78  STZ $78; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:807A")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x78u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x807Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F807Cu: /* 64 7A  STZ $7A; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:807C")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x7Au) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x807Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F807Eu: /* 64 70  STZ $70; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:807E")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x70u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x8080u;
        instance->instruction_count++;
        return 1;
    case 0x000F8080u: /* 64 72  STZ $72; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8080")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x72u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x8082u;
        instance->instruction_count++;
        return 1;
    case 0x000F8082u: /* AD 86 1F  LDA $1F86; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8082")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F86u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8085u;
        instance->instruction_count++;
        return 1;
    case 0x000F8085u: /* 0D 88 1F  ORA $1F88; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8085")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F88u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8088u;
        instance->instruction_count++;
        return 1;
    case 0x000F8088u: /* 0D 8A 1F  ORA $1F8A; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8088")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Au), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x808Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F808Bu: /* 0D 8C 1F  ORA $1F8C; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:808B")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Cu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x808Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F808Eu: /* 0D A3 1F  ORA $1FA3; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:808E")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA3u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8091u;
        instance->instruction_count++;
        return 1;
    case 0x000F8091u: /* 0D A5 1F  ORA $1FA5; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8091")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA5u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8094u;
        instance->instruction_count++;
        return 1;
    case 0x000F8094u: /* 0D A7 1F  ORA $1FA7; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8094")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA7u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8097u;
        instance->instruction_count++;
        return 1;
    case 0x000F8097u: /* 0D A9 1F  ORA $1FA9; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8097")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA9u), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x809Au;
        instance->instruction_count++;
        return 1;
    case 0x000F809Au: /* D0 03  BNE $0F:809F; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:809A")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x809Fu : 0x809Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F809Cu: /* 20 F4 80  JSR $80F4; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:809C")) return 0;
        if (!tg_push16(instance, 0x809Eu)) return 0;
        instance->cpu.pc = 0x80F4u;
        instance->instruction_count++;
        return 1;
    case 0x000F80F4u: /* A9 20 20  LDA #$2020; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:80F4")) return 0;
        word = 0x2020u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80F7u;
        instance->instruction_count++;
        return 1;
    case 0x000F80F7u: /* 8D 86 1F  STA $1F86; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:80F7")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F86u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x80FAu;
        instance->instruction_count++;
        return 1;
    case 0x000F80FAu: /* 8D 88 1F  STA $1F88; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:80FA")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F88u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x80FDu;
        instance->instruction_count++;
        return 1;
    case 0x000F80FDu: /* 8D 8A 1F  STA $1F8A; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:80FD")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8100u;
        instance->instruction_count++;
        return 1;
    case 0x000F8100u: /* 8D 8C 1F  STA $1F8C; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8100")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8103u;
        instance->instruction_count++;
        return 1;
    case 0x000F8103u: /* 8D A3 1F  STA $1FA3; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8103")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA3u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8106u;
        instance->instruction_count++;
        return 1;
    case 0x000F8106u: /* 8D A5 1F  STA $1FA5; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8106")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA5u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8109u;
        instance->instruction_count++;
        return 1;
    case 0x000F8109u: /* 8D A7 1F  STA $1FA7; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8109")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA7u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x810Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F810Cu: /* 8D A9 1F  STA $1FA9; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:810C")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA9u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x810Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F810Fu: /* A2 0E 00  LDX #$000E; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:810F")) return 0;
        word = 0x000Eu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8112u;
        instance->instruction_count++;
        return 1;
    case 0x000F8112u: /* BF 56 C6 0D  LDA $0DC656,X; semantic visits 8 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8112")) return 0;
        if (!tg_bus_read16(instance, ((0x0DC656u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8116u;
        instance->instruction_count++;
        return 1;
    case 0x000F8116u: /* 9D 76 1F  STA $1F76,X; semantic visits 8 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8116")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F76u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8119u;
        instance->instruction_count++;
        return 1;
    case 0x000F8119u: /* 9D 93 1F  STA $1F93,X; semantic visits 8 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8119")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F93u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x811Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F811Cu: /* CA  DEX; semantic visits 8 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:811C")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x811Du;
        instance->instruction_count++;
        return 1;
    case 0x000F811Du: /* CA  DEX; semantic visits 8 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:811D")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x811Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F811Eu: /* 10 F2  BPL $0F:8112; semantic visits 8 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:811E")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8112u : 0x8120u;
        instance->instruction_count++;
        return 1;
    case 0x000F8120u: /* A2 3E 00  LDX #$003E; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8120")) return 0;
        word = 0x003Eu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8123u;
        instance->instruction_count++;
        return 1;
    case 0x000F8123u: /* BF 96 C6 0D  LDA $0DC696,X; semantic visits 32 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8123")) return 0;
        if (!tg_bus_read16(instance, ((0x0DC696u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8127u;
        instance->instruction_count++;
        return 1;
    case 0x000F8127u: /* 9D B2 1F  STA $1FB2,X; semantic visits 32 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8127")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1FB2u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x812Au;
        instance->instruction_count++;
        return 1;
    case 0x000F812Au: /* CA  DEX; semantic visits 32 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:812A")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x812Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F812Bu: /* CA  DEX; semantic visits 32 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:812B")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x812Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F812Cu: /* 10 F5  BPL $0F:8123; semantic visits 32 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:812C")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8123u : 0x812Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F812Eu: /* E8  INX; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:812E")) return 0;
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x812Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F812Fu: /* 8E B0 1F  STX $1FB0; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:812F")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FB0u), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x8132u;
        instance->instruction_count++;
        return 1;
    case 0x000F8132u: /* 60  RTS; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8132")) return 0;
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F809Fu: /* A9 00 80  LDA #$8000; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:809F")) return 0;
        word = 0x8000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80A2u;
        instance->instruction_count++;
        return 1;
    case 0x000F80A2u: /* 85 01  STA $01; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:80A2")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x01u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x80A4u;
        instance->instruction_count++;
        return 1;
    case 0x000F80A4u: /* E2 20  SEP #$20; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:80A4")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80A6u;
        instance->instruction_count++;
        return 1;
    case 0x040F80A6u: /* A9 5C  LDA #$5C; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:80A6")) return 0;
        byte = 0x5Cu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80A8u;
        instance->instruction_count++;
        return 1;
    case 0x040F80A8u: /* 85 00  STA $00; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:80A8")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x00u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80AAu;
        instance->instruction_count++;
        return 1;
    case 0x040F80AAu: /* A9 0F  LDA #$0F; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:80AA")) return 0;
        byte = 0x0Fu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80ACu;
        instance->instruction_count++;
        return 1;
    case 0x040F80ACu: /* 85 03  STA $03; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:80AC")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x03u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80AEu;
        instance->instruction_count++;
        return 1;
    case 0x040F80AEu: /* A9 40  LDA #$40; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:80AE")) return 0;
        byte = 0x40u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80B0u;
        instance->instruction_count++;
        return 1;
    case 0x040F80B0u: /* 85 04  STA $04; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:80B0")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x04u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80B2u;
        instance->instruction_count++;
        return 1;
    case 0x040F80B2u: /* C2 20  REP #$20; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:80B2")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80B4u;
        instance->instruction_count++;
        return 1;
    case 0x000F80B4u: /* 68  PLA; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:80B4")) return 0;
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80B5u;
        instance->instruction_count++;
        return 1;
    case 0x000F80B5u: /* D0 03  BNE $0F:80BA; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:80B5")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x80BAu : 0x80B7u;
        instance->instruction_count++;
        return 1;
    case 0x000F80B7u: /* 4C 5A 81  JMP $815A; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:80B7")) return 0;
        instance->cpu.pc = 0x815Au;
        instance->instruction_count++;
        return 1;
    case 0x000F815Au: /* 20 3C A5  JSR $A53C; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:815A")) return 0;
        if (!tg_push16(instance, 0x815Cu)) return 0;
        instance->cpu.pc = 0xA53Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA53Cu: /* E2 30  SEP #$30; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:A53C")) return 0;
        instance->cpu.p |=0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA53Eu;
        instance->instruction_count++;
        return 1;
    case 0x060FA53Eu: /* A9 8F  LDA #$8F; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A53E")) return 0;
        byte = 0x8Fu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA540u;
        instance->instruction_count++;
        return 1;
    case 0x060FA540u: /* 8D 00 21  STA $2100; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A540")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2100u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA543u;
        instance->instruction_count++;
        return 1;
    case 0x060FA543u: /* A9 6B  LDA #$6B; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A543")) return 0;
        byte = 0x6Bu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA545u;
        instance->instruction_count++;
        return 1;
    case 0x060FA545u: /* 8D 01 21  STA $2101; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A545")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2101u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA548u;
        instance->instruction_count++;
        return 1;
    case 0x060FA548u: /* A9 00  LDA #$00; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A548")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA54Au;
        instance->instruction_count++;
        return 1;
    case 0x060FA54Au: /* 8D 02 21  STA $2102; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A54A")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2102u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA54Du;
        instance->instruction_count++;
        return 1;
    case 0x060FA54Du: /* 8D 03 21  STA $2103; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A54D")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2103u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA550u;
        instance->instruction_count++;
        return 1;
    case 0x060FA550u: /* A9 01  LDA #$01; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A550")) return 0;
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA552u;
        instance->instruction_count++;
        return 1;
    case 0x060FA552u: /* 8D 05 21  STA $2105; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A552")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2105u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA555u;
        instance->instruction_count++;
        return 1;
    case 0x060FA555u: /* A9 00  LDA #$00; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A555")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA557u;
        instance->instruction_count++;
        return 1;
    case 0x060FA557u: /* 8D 06 21  STA $2106; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A557")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2106u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA55Au;
        instance->instruction_count++;
        return 1;
    case 0x060FA55Au: /* 8D 07 21  STA $2107; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A55A")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2107u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA55Du;
        instance->instruction_count++;
        return 1;
    case 0x060FA55Du: /* A9 08  LDA #$08; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A55D")) return 0;
        byte = 0x08u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA55Fu;
        instance->instruction_count++;
        return 1;
    case 0x060FA55Fu: /* 8D 08 21  STA $2108; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A55F")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2108u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA562u;
        instance->instruction_count++;
        return 1;
    case 0x060FA562u: /* A9 0C  LDA #$0C; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A562")) return 0;
        byte = 0x0Cu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA564u;
        instance->instruction_count++;
        return 1;
    case 0x060FA564u: /* 8D 09 21  STA $2109; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A564")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2109u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA567u;
        instance->instruction_count++;
        return 1;
    case 0x060FA567u: /* A9 00  LDA #$00; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A567")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA569u;
        instance->instruction_count++;
        return 1;
    case 0x060FA569u: /* 8D 0A 21  STA $210A; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A569")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Au), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA56Cu;
        instance->instruction_count++;
        return 1;
    case 0x060FA56Cu: /* A9 41  LDA #$41; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A56C")) return 0;
        byte = 0x41u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA56Eu;
        instance->instruction_count++;
        return 1;
    case 0x060FA56Eu: /* 8D 0B 21  STA $210B; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A56E")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA571u;
        instance->instruction_count++;
        return 1;
    case 0x060FA571u: /* A9 44  LDA #$44; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A571")) return 0;
        byte = 0x44u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA573u;
        instance->instruction_count++;
        return 1;
    case 0x060FA573u: /* 8D 0C 21  STA $210C; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A573")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA576u;
        instance->instruction_count++;
        return 1;
    case 0x060FA576u: /* A9 00  LDA #$00; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A576")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA578u;
        instance->instruction_count++;
        return 1;
    case 0x060FA578u: /* 8D 0D 21  STA $210D; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A578")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA57Bu;
        instance->instruction_count++;
        return 1;
    case 0x060FA57Bu: /* 8D 0D 21  STA $210D; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A57B")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA57Eu;
        instance->instruction_count++;
        return 1;
    case 0x060FA57Eu: /* 8D 0E 21  STA $210E; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A57E")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA581u;
        instance->instruction_count++;
        return 1;
    case 0x060FA581u: /* 8D 0E 21  STA $210E; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A581")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA584u;
        instance->instruction_count++;
        return 1;
    case 0x060FA584u: /* 8D 0F 21  STA $210F; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A584")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA587u;
        instance->instruction_count++;
        return 1;
    case 0x060FA587u: /* 8D 0F 21  STA $210F; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A587")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA58Au;
        instance->instruction_count++;
        return 1;
    case 0x060FA58Au: /* 8D 10 21  STA $2110; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A58A")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA58Du;
        instance->instruction_count++;
        return 1;
    case 0x060FA58Du: /* 8D 10 21  STA $2110; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A58D")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA590u;
        instance->instruction_count++;
        return 1;
    case 0x060FA590u: /* 8D 11 21  STA $2111; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A590")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2111u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA593u;
        instance->instruction_count++;
        return 1;
    case 0x060FA593u: /* 8D 11 21  STA $2111; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A593")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2111u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA596u;
        instance->instruction_count++;
        return 1;
    case 0x060FA596u: /* 8D 12 21  STA $2112; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A596")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2112u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA599u;
        instance->instruction_count++;
        return 1;
    case 0x060FA599u: /* 8D 12 21  STA $2112; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A599")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2112u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA59Cu;
        instance->instruction_count++;
        return 1;
    case 0x060FA59Cu: /* 8D 13 21  STA $2113; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A59C")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2113u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA59Fu;
        instance->instruction_count++;
        return 1;
    case 0x060FA59Fu: /* 8D 13 21  STA $2113; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A59F")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2113u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5A2u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5A2u: /* 8D 14 21  STA $2114; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5A2")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2114u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5A5u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5A5u: /* 8D 14 21  STA $2114; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5A5")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2114u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5A8u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5A8u: /* A9 80  LDA #$80; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5A8")) return 0;
        byte = 0x80u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA5AAu;
        instance->instruction_count++;
        return 1;
    case 0x060FA5AAu: /* 8D 15 21  STA $2115; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5AA")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2115u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5ADu;
        instance->instruction_count++;
        return 1;
    case 0x060FA5ADu: /* A9 00  LDA #$00; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5AD")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA5AFu;
        instance->instruction_count++;
        return 1;
    case 0x060FA5AFu: /* 8D 16 21  STA $2116; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5AF")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5B2u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5B2u: /* 8D 17 21  STA $2117; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5B2")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2117u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5B5u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5B5u: /* A9 C0  LDA #$C0; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5B5")) return 0;
        byte = 0xC0u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA5B7u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5B7u: /* 8D 1A 21  STA $211A; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5B7")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Au), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5BAu;
        instance->instruction_count++;
        return 1;
    case 0x060FA5BAu: /* A9 00  LDA #$00; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5BA")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA5BCu;
        instance->instruction_count++;
        return 1;
    case 0x060FA5BCu: /* 8D 1B 21  STA $211B; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5BC")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5BFu;
        instance->instruction_count++;
        return 1;
    case 0x060FA5BFu: /* 8D 1B 21  STA $211B; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5BF")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5C2u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5C2u: /* 8D 1C 21  STA $211C; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5C2")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5C5u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5C5u: /* 8D 1C 21  STA $211C; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5C5")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5C8u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5C8u: /* 8D 1D 21  STA $211D; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5C8")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5CBu;
        instance->instruction_count++;
        return 1;
    case 0x060FA5CBu: /* 8D 1D 21  STA $211D; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5CB")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5CEu;
        instance->instruction_count++;
        return 1;
    case 0x060FA5CEu: /* 8D 1E 21  STA $211E; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5CE")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5D1u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5D1u: /* 8D 1E 21  STA $211E; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5D1")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5D4u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5D4u: /* 8D 1F 21  STA $211F; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5D4")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5D7u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5D7u: /* 8D 1F 21  STA $211F; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5D7")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5DAu;
        instance->instruction_count++;
        return 1;
    case 0x060FA5DAu: /* 8D 20 21  STA $2120; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5DA")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2120u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5DDu;
        instance->instruction_count++;
        return 1;
    case 0x060FA5DDu: /* 8D 20 21  STA $2120; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5DD")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2120u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5E0u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5E0u: /* 8D 21 21  STA $2121; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5E0")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5E3u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5E3u: /* 8D 23 21  STA $2123; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5E3")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2123u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5E6u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5E6u: /* 8D 24 21  STA $2124; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5E6")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2124u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5E9u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5E9u: /* 8D 25 21  STA $2125; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5E9")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2125u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5ECu;
        instance->instruction_count++;
        return 1;
    case 0x060FA5ECu: /* 8D 26 21  STA $2126; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5EC")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2126u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5EFu;
        instance->instruction_count++;
        return 1;
    case 0x060FA5EFu: /* 8D 27 21  STA $2127; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5EF")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2127u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5F2u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5F2u: /* 8D 28 21  STA $2128; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5F2")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2128u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5F5u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5F5u: /* 8D 29 21  STA $2129; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5F5")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2129u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5F8u;
        instance->instruction_count++;
        return 1;
    case 0x060FA5F8u: /* 8D 2A 21  STA $212A; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5F8")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x212Au), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5FBu;
        instance->instruction_count++;
        return 1;
    case 0x060FA5FBu: /* 8D 2B 21  STA $212B; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5FB")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x212Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA5FEu;
        instance->instruction_count++;
        return 1;
    case 0x060FA5FEu: /* A9 17  LDA #$17; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A5FE")) return 0;
        byte = 0x17u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA600u;
        instance->instruction_count++;
        return 1;
    case 0x060FA600u: /* 8D 2C 21  STA $212C; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A600")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x212Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA603u;
        instance->instruction_count++;
        return 1;
    case 0x060FA603u: /* A9 02  LDA #$02; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A603")) return 0;
        byte = 0x02u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA605u;
        instance->instruction_count++;
        return 1;
    case 0x060FA605u: /* 8D 2D 21  STA $212D; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A605")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x212Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA608u;
        instance->instruction_count++;
        return 1;
    case 0x060FA608u: /* A9 00  LDA #$00; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A608")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA60Au;
        instance->instruction_count++;
        return 1;
    case 0x060FA60Au: /* 8D 2E 21  STA $212E; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A60A")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x212Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA60Du;
        instance->instruction_count++;
        return 1;
    case 0x060FA60Du: /* 8D 2F 21  STA $212F; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A60D")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x212Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA610u;
        instance->instruction_count++;
        return 1;
    case 0x060FA610u: /* A9 02  LDA #$02; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A610")) return 0;
        byte = 0x02u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA612u;
        instance->instruction_count++;
        return 1;
    case 0x060FA612u: /* 8D 30 21  STA $2130; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A612")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2130u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA615u;
        instance->instruction_count++;
        return 1;
    case 0x060FA615u: /* A9 20  LDA #$20; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A615")) return 0;
        byte = 0x20u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA617u;
        instance->instruction_count++;
        return 1;
    case 0x060FA617u: /* 8D 31 21  STA $2131; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A617")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2131u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA61Au;
        instance->instruction_count++;
        return 1;
    case 0x060FA61Au: /* A9 E0  LDA #$E0; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A61A")) return 0;
        byte = 0xE0u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA61Cu;
        instance->instruction_count++;
        return 1;
    case 0x060FA61Cu: /* 8D 32 21  STA $2132; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A61C")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2132u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA61Fu;
        instance->instruction_count++;
        return 1;
    case 0x060FA61Fu: /* A9 00  LDA #$00; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A61F")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA621u;
        instance->instruction_count++;
        return 1;
    case 0x060FA621u: /* 8D 33 21  STA $2133; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A621")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2133u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA624u;
        instance->instruction_count++;
        return 1;
    case 0x060FA624u: /* 8D 3E 21  STA $213E; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A624")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x213Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA627u;
        instance->instruction_count++;
        return 1;
    case 0x060FA627u: /* 8D 3F 21  STA $213F; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A627")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x213Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA62Au;
        instance->instruction_count++;
        return 1;
    case 0x060FA62Au: /* A9 84  LDA #$84; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A62A")) return 0;
        byte = 0x84u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA62Cu;
        instance->instruction_count++;
        return 1;
    case 0x060FA62Cu: /* 8D 07 42  STA $4207; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A62C")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4207u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA62Fu;
        instance->instruction_count++;
        return 1;
    case 0x060FA62Fu: /* A9 00  LDA #$00; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A62F")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA631u;
        instance->instruction_count++;
        return 1;
    case 0x060FA631u: /* 8D 08 42  STA $4208; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A631")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4208u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA634u;
        instance->instruction_count++;
        return 1;
    case 0x060FA634u: /* A9 01  LDA #$01; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A634")) return 0;
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA636u;
        instance->instruction_count++;
        return 1;
    case 0x060FA636u: /* 8D 09 42  STA $4209; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A636")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4209u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA639u;
        instance->instruction_count++;
        return 1;
    case 0x060FA639u: /* A9 00  LDA #$00; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A639")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA63Bu;
        instance->instruction_count++;
        return 1;
    case 0x060FA63Bu: /* 8D 0A 42  STA $420A; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A63B")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Au), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA63Eu;
        instance->instruction_count++;
        return 1;
    case 0x060FA63Eu: /* A9 01  LDA #$01; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A63E")) return 0;
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA640u;
        instance->instruction_count++;
        return 1;
    case 0x060FA640u: /* 8D 0D 42  STA $420D; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A640")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA643u;
        instance->instruction_count++;
        return 1;
    case 0x060FA643u: /* 58  CLI; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A643")) return 0;
        tg_set_flag(instance, TG_P_I, 0);
        instance->cpu.pc = 0xA644u;
        instance->instruction_count++;
        return 1;
    case 0x060FA644u: /* E2 20  SEP #$20; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A644")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA646u;
        instance->instruction_count++;
        return 1;
    case 0x060FA646u: /* A9 00  LDA #$00; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A646")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA648u;
        instance->instruction_count++;
        return 1;
    case 0x060FA648u: /* 8D 0B 42  STA $420B; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A648")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA64Bu;
        instance->instruction_count++;
        return 1;
    case 0x060FA64Bu: /* A9 0F  LDA #$0F; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A64B")) return 0;
        byte = 0x0Fu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA64Du;
        instance->instruction_count++;
        return 1;
    case 0x060FA64Du: /* 8D 04 43  STA $4304; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A64D")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA650u;
        instance->instruction_count++;
        return 1;
    case 0x060FA650u: /* 8D 14 43  STA $4314; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A650")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4314u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA653u;
        instance->instruction_count++;
        return 1;
    case 0x060FA653u: /* 8D 24 43  STA $4324; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A653")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4324u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA656u;
        instance->instruction_count++;
        return 1;
    case 0x060FA656u: /* C2 20  REP #$20; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A656")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA658u;
        instance->instruction_count++;
        return 1;
    case 0x020FA658u: /* A9 7D A6  LDA #$A67D; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A658")) return 0;
        word = 0xA67Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA65Bu;
        instance->instruction_count++;
        return 1;
    case 0x020FA65Bu: /* 8D 02 43  STA $4302; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A65B")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA65Eu;
        instance->instruction_count++;
        return 1;
    case 0x020FA65Eu: /* 8D 12 43  STA $4312; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A65E")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4312u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA661u;
        instance->instruction_count++;
        return 1;
    case 0x020FA661u: /* 8D 22 43  STA $4322; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A661")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4322u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA664u;
        instance->instruction_count++;
        return 1;
    case 0x020FA664u: /* A9 0A 04  LDA #$040A; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A664")) return 0;
        word = 0x040Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA667u;
        instance->instruction_count++;
        return 1;
    case 0x020FA667u: /* 8D 00 43  STA $4300; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A667")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA66Au;
        instance->instruction_count++;
        return 1;
    case 0x020FA66Au: /* A9 09 18  LDA #$1809; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A66A")) return 0;
        word = 0x1809u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA66Du;
        instance->instruction_count++;
        return 1;
    case 0x020FA66Du: /* 8D 10 43  STA $4310; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A66D")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4310u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA670u;
        instance->instruction_count++;
        return 1;
    case 0x020FA670u: /* A9 0A 22  LDA #$220A; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A670")) return 0;
        word = 0x220Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA673u;
        instance->instruction_count++;
        return 1;
    case 0x020FA673u: /* 8D 20 43  STA $4320; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A673")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4320u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA676u;
        instance->instruction_count++;
        return 1;
    case 0x020FA676u: /* A9 20 02  LDA #$0220; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A676")) return 0;
        word = 0x0220u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA679u;
        instance->instruction_count++;
        return 1;
    case 0x020FA679u: /* 8D 05 43  STA $4305; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A679")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA67Cu;
        instance->instruction_count++;
        return 1;
    case 0x020FA67Cu: /* A9 00 00  LDA #$0000; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A67C")) return 0;
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA67Fu;
        instance->instruction_count++;
        return 1;
    case 0x020FA67Fu: /* 8D 15 43  STA $4315; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A67F")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4315u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA682u;
        instance->instruction_count++;
        return 1;
    case 0x020FA682u: /* A9 00 02  LDA #$0200; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A682")) return 0;
        word = 0x0200u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA685u;
        instance->instruction_count++;
        return 1;
    case 0x020FA685u: /* 8D 25 43  STA $4325; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A685")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4325u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA688u;
        instance->instruction_count++;
        return 1;
    case 0x020FA688u: /* E2 20  SEP #$20; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 1u, 0x0Fu, 0x0000u, "0F:A688")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA68Au;
        instance->instruction_count++;
        return 1;
    case 0x060FA68Au: /* A9 07  LDA #$07; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A68A")) return 0;
        byte = 0x07u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xA68Cu;
        instance->instruction_count++;
        return 1;
    case 0x060FA68Cu: /* 8D 0B 42  STA $420B; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A68C")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xA68Fu;
        instance->instruction_count++;
        return 1;
    case 0x060FA68Fu: /* C2 30  REP #$30; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x0Fu, 0x0000u, "0F:A68F")) return 0;
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA691u;
        instance->instruction_count++;
        return 1;
    case 0x000FA691u: /* A2 FE 01  LDX #$01FE; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:A691")) return 0;
        word = 0x01FEu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA694u;
        instance->instruction_count++;
        return 1;
    case 0x000FA694u: /* A9 00 F0  LDA #$F000; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:A694")) return 0;
        word = 0xF000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA697u;
        instance->instruction_count++;
        return 1;
    case 0x000FA697u: /* 9D 02 02  STA $0202,X; semantic visits 256 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:A697")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0202u + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xA69Au;
        instance->instruction_count++;
        return 1;
    case 0x000FA69Au: /* CA  DEX; semantic visits 256 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:A69A")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA69Bu;
        instance->instruction_count++;
        return 1;
    case 0x000FA69Bu: /* CA  DEX; semantic visits 256 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:A69B")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA69Cu;
        instance->instruction_count++;
        return 1;
    case 0x000FA69Cu: /* 10 F9  BPL $0F:A697; semantic visits 256 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:A69C")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xA697u : 0xA69Eu;
        instance->instruction_count++;
        return 1;
    case 0x000FA69Eu: /* A2 1E 00  LDX #$001E; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:A69E")) return 0;
        word = 0x001Eu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA6A1u;
        instance->instruction_count++;
        return 1;
    case 0x000FA6A1u: /* 9E 02 04  STZ $0402,X; semantic visits 16 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:A6A1")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x0402u + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0xA6A4u;
        instance->instruction_count++;
        return 1;
    case 0x000FA6A4u: /* CA  DEX; semantic visits 16 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:A6A4")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA6A5u;
        instance->instruction_count++;
        return 1;
    case 0x000FA6A5u: /* CA  DEX; semantic visits 16 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:A6A5")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xA6A6u;
        instance->instruction_count++;
        return 1;
    case 0x000FA6A6u: /* 10 F9  BPL $0F:A6A1; semantic visits 16 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:A6A6")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xA6A1u : 0xA6A8u;
        instance->instruction_count++;
        return 1;
    case 0x000FA6A8u: /* 60  RTS; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:A6A8")) return 0;
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F815Du: /* 64 81  STZ $81; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:815D")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x815Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F815Fu: /* 20 95 8C  JSR $8C95; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:815F")) return 0;
        if (!tg_push16(instance, 0x8161u)) return 0;
        instance->cpu.pc = 0x8C95u;
        instance->instruction_count++;
        return 1;
    case 0x000F8C95u: /* C2 30  REP #$30; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8C95")) return 0;
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8C97u;
        instance->instruction_count++;
        return 1;
    case 0x000F8C97u: /* 20 80 8F  JSR $8F80; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8C97")) return 0;
        if (!tg_push16(instance, 0x8C99u)) return 0;
        instance->cpu.pc = 0x8F80u;
        instance->instruction_count++;
        return 1;
    case 0x000F8F80u: /* A2 1E 00  LDX #$001E; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8F80")) return 0;
        word = 0x001Eu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8F83u;
        instance->instruction_count++;
        return 1;
    case 0x000F8F83u: /* 9E 2C 04  STZ $042C,X; semantic visits 16 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8F83")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x042Cu + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x8F86u;
        instance->instruction_count++;
        return 1;
    case 0x000F8F86u: /* CA  DEX; semantic visits 16 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8F86")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8F87u;
        instance->instruction_count++;
        return 1;
    case 0x000F8F87u: /* CA  DEX; semantic visits 16 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8F87")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8F88u;
        instance->instruction_count++;
        return 1;
    case 0x000F8F88u: /* 10 F9  BPL $0F:8F83; semantic visits 16 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8F88")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8F83u : 0x8F8Au;
        instance->instruction_count++;
        return 1;
    case 0x000F8F8Au: /* 60  RTS; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8F8A")) return 0;
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F8C9Au: /* A9 08 07  LDA #$0708; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8C9A")) return 0;
        word = 0x0708u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8C9Du;
        instance->instruction_count++;
        return 1;
    case 0x000F8C9Du: /* 85 66  STA $66; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8C9D")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8C9Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F8C9Fu: /* A9 07 01  LDA #$0107; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8C9F")) return 0;
        word = 0x0107u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8CA2u;
        instance->instruction_count++;
        return 1;
    case 0x000F8CA2u: /* 8D 84 1F  STA $1F84; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8CA2")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F84u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8CA5u;
        instance->instruction_count++;
        return 1;
    case 0x000F8CA5u: /* 8D A1 1F  STA $1FA1; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8CA5")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FA1u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8CA8u;
        instance->instruction_count++;
        return 1;
    case 0x000F8CA8u: /* E2 20  SEP #$20; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8CA8")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8CAAu;
        instance->instruction_count++;
        return 1;
    case 0x040F8CAAu: /* A9 10  LDA #$10; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:8CAA")) return 0;
        byte = 0x10u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8CACu;
        instance->instruction_count++;
        return 1;
    case 0x040F8CACu: /* 8D 2C 21  STA $212C; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:8CAC")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x212Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8CAFu;
        instance->instruction_count++;
        return 1;
    case 0x040F8CAFu: /* 9C 2D 21  STZ $212D; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:8CAF")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x212Du), 0u)) return 0;
        instance->cpu.pc = 0x8CB2u;
        instance->instruction_count++;
        return 1;
    case 0x040F8CB2u: /* A9 81  LDA #$81; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:8CB2")) return 0;
        byte = 0x81u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8CB4u;
        instance->instruction_count++;
        return 1;
    case 0x040F8CB4u: /* 8D 00 42  STA $4200; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:8CB4")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4200u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8CB7u;
        instance->instruction_count++;
        return 1;
    case 0x040F8CB7u: /* A9 03  LDA #$03; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:8CB7")) return 0;
        byte = 0x03u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8CB9u;
        instance->instruction_count++;
        return 1;
    case 0x040F8CB9u: /* 8D 01 21  STA $2101; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:8CB9")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2101u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8CBCu;
        instance->instruction_count++;
        return 1;
    case 0x040F8CBCu: /* C2 20  REP #$20; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:8CBC")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8CBEu;
        instance->instruction_count++;
        return 1;
    case 0x000F8CBEu: /* A9 8F 00  LDA #$008F; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8CBE")) return 0;
        word = 0x008Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8CC1u;
        instance->instruction_count++;
        return 1;
    case 0x000F8CC1u: /* 85 42  STA $42; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8CC1")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x42u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8CC3u;
        instance->instruction_count++;
        return 1;
    case 0x000F8CC3u: /* A9 01 00  LDA #$0001; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8CC3")) return 0;
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8CC6u;
        instance->instruction_count++;
        return 1;
    case 0x000F8CC6u: /* 20 4D A2  JSR $A24D; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:8CC6")) return 0;
        if (!tg_push16(instance, 0x8CC8u)) return 0;
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000FA24Du: /* E2 20  SEP #$20; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x0Fu, 0x0000u, "0F:A24D")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xA24Fu;
        instance->instruction_count++;
        return 1;
    case 0x040FA24Fu: /* 64 08  STZ $08; semantic visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x0Fu, 0x0000u, "0F:A24F")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x08u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0xA251u;
        instance->instruction_count++;
        return 1;
    case 0x060FA251u:
        return tg_fail_frontier(instance, "Version 14 static semantic route reached $0F:A251, where Top Gear waits for the first interrupt-produced $08 tick. Exact NMI/IRQ recognition timing is the next physical scheduler barrier.", "0F:A251");
    default:
        return tg_fail_frontier(instance, "Unknown Version 14 post-audio fixed W65C816 context.", NULL);
    }
}
