/* Generated from the exact Top Gear ROM and documented W65C816 semantics. */
#include "topgear_internal.h"
#include "topgear_v13_second_protocol_scpu.h"

int tg_v13_second_protocol_scpu_step(TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u;uint16_t word=0u;uint8_t byte=0u;
    if(!instance)return 0;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x0007802Fu: /* A4 1A LDY $1A */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:802F")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8031u;
        instance->instruction_count++;
        return 1;
    case 0x00078031u: /* B9 72 81 LDA $8172,Y */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8031")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8172u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8034u;
        instance->instruction_count++;
        return 1;
    case 0x00078034u: /* E2 20 SEP #$20 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8034")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8036u;
        instance->instruction_count++;
        return 1;
    case 0x04078036u: /* 10 1D BPL $07:8055 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8036")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8055u : 0x8038u;
        instance->instruction_count++;
        return 1;
    case 0x04078038u: /* A9 00 LDA #$00 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8038")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x803Au;
        instance->instruction_count++;
        return 1;
    case 0x0407803Au: /* 8D 41 21 STA $2141 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:803A")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x803Du;
        instance->instruction_count++;
        return 1;
    case 0x0407803Du: /* C2 20 REP #$20 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:803D")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x803Fu;
        instance->instruction_count++;
        return 1;
    case 0x0007803Fu: /* B9 74 81 LDA $8174,Y */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:803F")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8174u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8042u;
        instance->instruction_count++;
        return 1;
    case 0x00078042u: /* 8D 42 21 STA $2142 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8042")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2142u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8045u;
        instance->instruction_count++;
        return 1;
    case 0x00078045u: /* E2 20 SEP #$20 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8045")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8047u;
        instance->instruction_count++;
        return 1;
    case 0x04078047u: /* A5 1C LDA $1C */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8047")) return 0;
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8049u;
        instance->instruction_count++;
        return 1;
    case 0x04078049u: /* 8D 40 21 STA $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8049")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x804Cu;
        instance->instruction_count++;
        return 1;
    case 0x0407804Cu: /* CD 40 21 CMP $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:804C")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x804Fu;
        instance->instruction_count++;
        return 1;
    case 0x0407804Fu: /* D0 FB BNE $07:804C */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:804F")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x804Cu : 0x8051u;
        instance->instruction_count++;
        return 1;
    case 0x04078051u: /* C2 20 REP #$20 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8051")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8053u;
        instance->instruction_count++;
        return 1;
    case 0x00078053u: /* AB PLB */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8053")) return 0;
        if (!tg_pull8(instance, &byte)) return 0;
        instance->cpu.dbr = byte;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8054u;
        instance->instruction_count++;
        return 1;
    case 0x00078054u: /* 6B RTL */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "07:8054")) return 0;
        if (!tg_pull16(instance, &word)) return 0;
        if (!tg_pull8(instance, &byte)) return 0;
        instance->cpu.pbr = byte;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x04078055u: /* 85 22 STA $22 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8055")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8057u;
        instance->instruction_count++;
        return 1;
    case 0x04078057u: /* C2 20 REP #$20 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8057")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8059u;
        instance->instruction_count++;
        return 1;
    case 0x00078059u: /* B9 74 81 LDA $8174,Y */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8059")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8174u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x805Cu;
        instance->instruction_count++;
        return 1;
    case 0x0007805Cu: /* 85 20 STA $20 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:805C")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x805Eu;
        instance->instruction_count++;
        return 1;
    case 0x0007805Eu: /* 98 TYA */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:805E")) return 0;
        tg_set_acc16(instance, (uint16_t)instance->cpu.y);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x805Fu;
        instance->instruction_count++;
        return 1;
    case 0x0007805Fu: /* 18 CLC */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:805F")) return 0;
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x8060u;
        instance->instruction_count++;
        return 1;
    case 0x00078060u: /* 69 04 00 ADC #$0004 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8060")) return 0;
        word = 0x0004u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x8063u;
        instance->instruction_count++;
        return 1;
    case 0x00078063u: /* 85 1A STA $1A */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8063")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8065u;
        instance->instruction_count++;
        return 1;
    case 0x00078065u: /* A0 00 00 LDY #$0000 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8065")) return 0;
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8068u;
        instance->instruction_count++;
        return 1;
    case 0x00078068u: /* E2 20 SEP #$20 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8068")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x806Au;
        instance->instruction_count++;
        return 1;
    case 0x0407806Au: /* A9 01 LDA #$01 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:806A")) return 0;
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x806Cu;
        instance->instruction_count++;
        return 1;
    case 0x0407806Cu: /* 8D 41 21 STA $2141 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:806C")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x806Fu;
        instance->instruction_count++;
        return 1;
    case 0x0407806Fu: /* C2 20 REP #$20 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:806F")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8071u;
        instance->instruction_count++;
        return 1;
    case 0x00078071u: /* A5 24 LDA $24 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8071")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x24u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8073u;
        instance->instruction_count++;
        return 1;
    case 0x00078073u: /* 8D 42 21 STA $2142 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8073")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2142u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8076u;
        instance->instruction_count++;
        return 1;
    case 0x00078076u: /* 18 CLC */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8076")) return 0;
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x8077u;
        instance->instruction_count++;
        return 1;
    case 0x00078077u: /* 69 06 00 ADC #$0006 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8077")) return 0;
        word = 0x0006u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x807Au;
        instance->instruction_count++;
        return 1;
    case 0x0007807Au: /* 85 24 STA $24 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:807A")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x24u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x807Cu;
        instance->instruction_count++;
        return 1;
    case 0x0007807Cu: /* E2 20 SEP #$20 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:807C")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x807Eu;
        instance->instruction_count++;
        return 1;
    case 0x0407807Eu: /* A5 1C LDA $1C */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:807E")) return 0;
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8080u;
        instance->instruction_count++;
        return 1;
    case 0x04078080u: /* 8D 40 21 STA $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8080")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8083u;
        instance->instruction_count++;
        return 1;
    case 0x04078083u: /* CD 40 21 CMP $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8083")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x8086u;
        instance->instruction_count++;
        return 1;
    case 0x04078086u: /* D0 FB BNE $07:8083 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8086")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8083u : 0x8088u;
        instance->instruction_count++;
        return 1;
    case 0x04078088u: /* A5 23 LDA $23 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8088")) return 0;
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x808Au;
        instance->instruction_count++;
        return 1;
    case 0x0407808Au: /* 8D 41 21 STA $2141 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:808A")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x808Du;
        instance->instruction_count++;
        return 1;
    case 0x0407808Du: /* E6 23 INC $23 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:808D")) return 0;
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), &byte)) return 0;
        byte = (uint8_t)(byte + 1u);
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), byte)) return 0;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x808Fu;
        instance->instruction_count++;
        return 1;
    case 0x0407808Fu: /* A9 00 LDA #$00 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:808F")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8091u;
        instance->instruction_count++;
        return 1;
    case 0x04078091u: /* 8D 40 21 STA $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8091")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8094u;
        instance->instruction_count++;
        return 1;
    case 0x04078094u: /* CD 40 21 CMP $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8094")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x8097u;
        instance->instruction_count++;
        return 1;
    case 0x04078097u: /* D0 FB BNE $07:8094 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8097")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8094u : 0x8099u;
        instance->instruction_count++;
        return 1;
    case 0x04078099u: /* 1A INC A */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8099")) return 0;
        byte = (uint8_t)((tg_acc8(instance)) + 1u);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x809Au;
        instance->instruction_count++;
        return 1;
    case 0x0407809Au: /* A2 05 00 LDX #$0005 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:809A")) return 0;
        word = 0x0005u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x809Du;
        instance->instruction_count++;
        return 1;
    case 0x0407809Du: /* EB XBA */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:809D")) return 0;
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0x809Eu;
        instance->instruction_count++;
        return 1;
    case 0x0407809Eu: /* B7 20 LDA [$20],Y */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:809E")) return 0;
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80A0u;
        instance->instruction_count++;
        return 1;
    case 0x040780A0u: /* 8D 41 21 STA $2141 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80A0")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80A3u;
        instance->instruction_count++;
        return 1;
    case 0x040780A3u: /* C8 INY */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80A3")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80A4u;
        instance->instruction_count++;
        return 1;
    case 0x040780A4u: /* EB XBA */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80A4")) return 0;
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0x80A5u;
        instance->instruction_count++;
        return 1;
    case 0x040780A5u: /* 8D 40 21 STA $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80A5")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80A8u;
        instance->instruction_count++;
        return 1;
    case 0x040780A8u: /* CD 40 21 CMP $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80A8")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x80ABu;
        instance->instruction_count++;
        return 1;
    case 0x040780ABu: /* D0 FB BNE $07:80A8 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80AB")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x80A8u : 0x80ADu;
        instance->instruction_count++;
        return 1;
    case 0x040780ADu: /* 1A INC A */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80AD")) return 0;
        byte = (uint8_t)((tg_acc8(instance)) + 1u);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80AEu;
        instance->instruction_count++;
        return 1;
    case 0x040780AEu: /* CA DEX */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80AE")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80AFu;
        instance->instruction_count++;
        return 1;
    case 0x040780AFu: /* D0 EC BNE $07:809D */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80AF")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x809Du : 0x80B1u;
        instance->instruction_count++;
        return 1;
    case 0x040780B1u: /* 1A INC A */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80B1")) return 0;
        byte = (uint8_t)((tg_acc8(instance)) + 1u);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80B2u;
        instance->instruction_count++;
        return 1;
    case 0x040780B2u: /* 85 1C STA $1C */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80B2")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80B4u;
        instance->instruction_count++;
        return 1;
    case 0x040780B4u: /* 8D 41 21 STA $2141 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80B4")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80B7u;
        instance->instruction_count++;
        return 1;
    case 0x040780B7u: /* C2 20 REP #$20 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80B7")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80B9u;
        instance->instruction_count++;
        return 1;
    case 0x000780B9u: /* A5 26 LDA $26 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:80B9")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x26u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80BBu;
        instance->instruction_count++;
        return 1;
    case 0x000780BBu: /* 8D 42 21 STA $2142 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:80BB")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2142u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x80BEu;
        instance->instruction_count++;
        return 1;
    case 0x000780BEu: /* 18 CLC */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:80BE")) return 0;
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x80BFu;
        instance->instruction_count++;
        return 1;
    case 0x000780BFu: /* 69 04 00 ADC #$0004 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:80BF")) return 0;
        word = 0x0004u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x80C2u;
        instance->instruction_count++;
        return 1;
    case 0x000780C2u: /* 85 26 STA $26 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:80C2")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x26u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x80C4u;
        instance->instruction_count++;
        return 1;
    case 0x000780C4u: /* E2 20 SEP #$20 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:80C4")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80C6u;
        instance->instruction_count++;
        return 1;
    case 0x040780C6u: /* A5 1C LDA $1C */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80C6")) return 0;
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80C8u;
        instance->instruction_count++;
        return 1;
    case 0x040780C8u: /* 8D 40 21 STA $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80C8")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80CBu;
        instance->instruction_count++;
        return 1;
    case 0x040780CBu: /* CD 40 21 CMP $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80CB")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x80CEu;
        instance->instruction_count++;
        return 1;
    case 0x040780CEu: /* D0 FB BNE $07:80CB */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80CE")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x80CBu : 0x80D0u;
        instance->instruction_count++;
        return 1;
    case 0x040780D0u: /* C2 20 REP #$20 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80D0")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80D2u;
        instance->instruction_count++;
        return 1;
    case 0x000780D2u: /* A5 28 LDA $28 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:80D2")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x28u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80D4u;
        instance->instruction_count++;
        return 1;
    case 0x000780D4u: /* E2 20 SEP #$20 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:80D4")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80D6u;
        instance->instruction_count++;
        return 1;
    case 0x040780D6u: /* 8D 41 21 STA $2141 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80D6")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80D9u;
        instance->instruction_count++;
        return 1;
    case 0x040780D9u: /* A9 00 LDA #$00 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80D9")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80DBu;
        instance->instruction_count++;
        return 1;
    case 0x040780DBu: /* 8D 40 21 STA $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80DB")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80DEu;
        instance->instruction_count++;
        return 1;
    case 0x040780DEu: /* CD 40 21 CMP $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80DE")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x80E1u;
        instance->instruction_count++;
        return 1;
    case 0x040780E1u: /* D0 FB BNE $07:80DE */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80E1")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x80DEu : 0x80E3u;
        instance->instruction_count++;
        return 1;
    case 0x040780E3u: /* EB XBA */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80E3")) return 0;
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0x80E4u;
        instance->instruction_count++;
        return 1;
    case 0x040780E4u: /* 8D 41 21 STA $2141 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80E4")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80E7u;
        instance->instruction_count++;
        return 1;
    case 0x040780E7u: /* A9 01 LDA #$01 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80E7")) return 0;
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80E9u;
        instance->instruction_count++;
        return 1;
    case 0x040780E9u: /* 8D 40 21 STA $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80E9")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80ECu;
        instance->instruction_count++;
        return 1;
    case 0x040780ECu: /* CD 40 21 CMP $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80EC")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x80EFu;
        instance->instruction_count++;
        return 1;
    case 0x040780EFu: /* D0 FB BNE $07:80EC */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80EF")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x80ECu : 0x80F1u;
        instance->instruction_count++;
        return 1;
    case 0x040780F1u: /* C2 20 REP #$20 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80F1")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80F3u;
        instance->instruction_count++;
        return 1;
    case 0x000780F3u: /* B7 20 LDA [$20],Y */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:80F3")) return 0;
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read16(instance, address, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80F5u;
        instance->instruction_count++;
        return 1;
    case 0x000780F5u: /* 18 CLC */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:80F5")) return 0;
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x80F6u;
        instance->instruction_count++;
        return 1;
    case 0x000780F6u: /* 65 28 ADC $28 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:80F6")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x28u) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x80F8u;
        instance->instruction_count++;
        return 1;
    case 0x000780F8u: /* C8 INY */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:80F8")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80F9u;
        instance->instruction_count++;
        return 1;
    case 0x000780F9u: /* C8 INY */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:80F9")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80FAu;
        instance->instruction_count++;
        return 1;
    case 0x000780FAu: /* E2 20 SEP #$20 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:80FA")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80FCu;
        instance->instruction_count++;
        return 1;
    case 0x040780FCu: /* 8D 41 21 STA $2141 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80FC")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80FFu;
        instance->instruction_count++;
        return 1;
    case 0x040780FFu: /* A9 02 LDA #$02 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:80FF")) return 0;
        byte = 0x02u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8101u;
        instance->instruction_count++;
        return 1;
    case 0x04078101u: /* 8D 40 21 STA $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8101")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8104u;
        instance->instruction_count++;
        return 1;
    case 0x04078104u: /* CD 40 21 CMP $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8104")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x8107u;
        instance->instruction_count++;
        return 1;
    case 0x04078107u: /* D0 FB BNE $07:8104 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8107")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8104u : 0x8109u;
        instance->instruction_count++;
        return 1;
    case 0x04078109u: /* EB XBA */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8109")) return 0;
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0x810Au;
        instance->instruction_count++;
        return 1;
    case 0x0407810Au: /* 8D 41 21 STA $2141 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:810A")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x810Du;
        instance->instruction_count++;
        return 1;
    case 0x0407810Du: /* A9 03 LDA #$03 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:810D")) return 0;
        byte = 0x03u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x810Fu;
        instance->instruction_count++;
        return 1;
    case 0x0407810Fu: /* 8D 40 21 STA $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:810F")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8112u;
        instance->instruction_count++;
        return 1;
    case 0x04078112u: /* CD 40 21 CMP $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8112")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x8115u;
        instance->instruction_count++;
        return 1;
    case 0x04078115u: /* D0 FB BNE $07:8112 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8115")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8112u : 0x8117u;
        instance->instruction_count++;
        return 1;
    case 0x04078117u: /* C2 20 REP #$20 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8117")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8119u;
        instance->instruction_count++;
        return 1;
    case 0x00078119u: /* B7 20 LDA [$20],Y */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8119")) return 0;
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read16(instance, address, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x811Bu;
        instance->instruction_count++;
        return 1;
    case 0x0007811Bu: /* E2 20 SEP #$20 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:811B")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x811Du;
        instance->instruction_count++;
        return 1;
    case 0x0407811Du: /* D0 04 BNE $07:8123 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:811D")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8123u : 0x811Fu;
        instance->instruction_count++;
        return 1;
    case 0x0407811Fu: /* A9 05 LDA #$05 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:811F")) return 0;
        byte = 0x05u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8121u;
        instance->instruction_count++;
        return 1;
    case 0x04078121u: /* 80 3A BRA $07:815D */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8121")) return 0;
        instance->cpu.pc = 0x815Du;
        instance->instruction_count++;
        return 1;
    case 0x04078123u: /* C8 INY */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8123")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8124u;
        instance->instruction_count++;
        return 1;
    case 0x04078124u: /* C8 INY */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8124")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8125u;
        instance->instruction_count++;
        return 1;
    case 0x04078125u: /* AA TAX */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8125")) return 0;
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x8126u;
        instance->instruction_count++;
        return 1;
    case 0x04078126u: /* A9 05 LDA #$05 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8126")) return 0;
        byte = 0x05u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8128u;
        instance->instruction_count++;
        return 1;
    case 0x04078128u: /* 8D 41 21 STA $2141 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8128")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x812Bu;
        instance->instruction_count++;
        return 1;
    case 0x0407812Bu: /* C2 20 REP #$20 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:812B")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x812Du;
        instance->instruction_count++;
        return 1;
    case 0x0007812Du: /* A5 28 LDA $28 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:812D")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x28u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x812Fu;
        instance->instruction_count++;
        return 1;
    case 0x0007812Fu: /* 8D 42 21 STA $2142 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:812F")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2142u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8132u;
        instance->instruction_count++;
        return 1;
    case 0x00078132u: /* 8A TXA */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8132")) return 0;
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x8133u;
        instance->instruction_count++;
        return 1;
    case 0x00078133u: /* 18 CLC */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8133")) return 0;
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x8134u;
        instance->instruction_count++;
        return 1;
    case 0x00078134u: /* 65 28 ADC $28 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8134")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x28u) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x8136u;
        instance->instruction_count++;
        return 1;
    case 0x00078136u: /* 85 28 STA $28 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8136")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x28u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8138u;
        instance->instruction_count++;
        return 1;
    case 0x00078138u: /* E2 20 SEP #$20 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8138")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x813Au;
        instance->instruction_count++;
        return 1;
    case 0x0407813Au: /* A9 05 LDA #$05 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:813A")) return 0;
        byte = 0x05u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x813Cu;
        instance->instruction_count++;
        return 1;
    case 0x0407813Cu: /* 8D 40 21 STA $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:813C")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x813Fu;
        instance->instruction_count++;
        return 1;
    case 0x0407813Fu: /* CD 40 21 CMP $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:813F")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x8142u;
        instance->instruction_count++;
        return 1;
    case 0x04078142u: /* D0 FB BNE $07:813F */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8142")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x813Fu : 0x8144u;
        instance->instruction_count++;
        return 1;
    case 0x04078144u: /* A9 00 LDA #$00 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8144")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8146u;
        instance->instruction_count++;
        return 1;
    case 0x04078146u: /* EB XBA */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8146")) return 0;
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0x8147u;
        instance->instruction_count++;
        return 1;
    case 0x04078147u: /* B7 20 LDA [$20],Y */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8147")) return 0;
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8149u;
        instance->instruction_count++;
        return 1;
    case 0x04078149u: /* 8D 41 21 STA $2141 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8149")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x814Cu;
        instance->instruction_count++;
        return 1;
    case 0x0407814Cu: /* C8 INY */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:814C")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x814Du;
        instance->instruction_count++;
        return 1;
    case 0x0407814Du: /* EB XBA */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:814D")) return 0;
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0x814Eu;
        instance->instruction_count++;
        return 1;
    case 0x0407814Eu: /* 8D 40 21 STA $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:814E")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8151u;
        instance->instruction_count++;
        return 1;
    case 0x04078151u: /* CD 40 21 CMP $2140 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8151")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x8154u;
        instance->instruction_count++;
        return 1;
    case 0x04078154u: /* D0 FB BNE $07:8151 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8154")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8151u : 0x8156u;
        instance->instruction_count++;
        return 1;
    case 0x04078156u: /* 1A INC A */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8156")) return 0;
        byte = (uint8_t)((tg_acc8(instance)) + 1u);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8157u;
        instance->instruction_count++;
        return 1;
    case 0x04078157u: /* CA DEX */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8157")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8158u;
        instance->instruction_count++;
        return 1;
    case 0x04078158u: /* D0 EC BNE $07:8146 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8158")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8146u : 0x815Au;
        instance->instruction_count++;
        return 1;
    case 0x0407815Au: /* 1A INC A */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:815A")) return 0;
        byte = (uint8_t)((tg_acc8(instance)) + 1u);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x815Bu;
        instance->instruction_count++;
        return 1;
    case 0x0407815Bu: /* F0 FD BEQ $07:815A */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:815B")) return 0;
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x815Au : 0x815Du;
        instance->instruction_count++;
        return 1;
    case 0x0407815Du: /* 85 1C STA $1C */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:815D")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x815Fu;
        instance->instruction_count++;
        return 1;
    case 0x0407815Fu: /* C2 20 REP #$20 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:815F")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8161u;
        instance->instruction_count++;
        return 1;
    case 0x00078161u: /* 82 CB FE BRL $07:802F */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8161")) return 0;
        instance->cpu.pc = 0x802Fu;
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 13 second-protocol generated W65C816 context.",NULL);
    }
}

const TgV13ScpuTimingVariant tg_v13_second_protocol_timing_variants[TOPGEAR_RECOMP_V13_SECOND_PROTOCOL_TIMING_VARIANT_COUNT]={
    {0x0007802Fu,0x00078031u,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDY $1A a41a */
    {0x00078031u,0x00078034u,46u,6u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA $8172,Y b97281 */
    {0x00078034u,0x04078036u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* SEP #$20 e220 */
    {0x0007803Fu,0x00078042u,46u,6u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA $8174,Y b97481 */
    {0x00078042u,0x00078045u,36u,5u,2u,0u,{0x072142u, 0x072143u},{1u, 1u},{24u, 30u},{30u, 36u},{6u, 6u}}, /* STA $2142 8d4221 */
    {0x00078045u,0x04078047u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* SEP #$20 e220 */
    {0x00078053u,0x00078054u,28u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* PLB ab */
    {0x00078054u,0x00008068u,44u,6u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* RTL 6b */
    {0x00078059u,0x0007805Cu,46u,6u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA $8174,Y b97481 */
    {0x0007805Cu,0x0007805Eu,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* STA $20 8520 */
    {0x0007805Eu,0x0007805Fu,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* TYA 98 */
    {0x0007805Fu,0x00078060u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* CLC 18 */
    {0x00078060u,0x00078063u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* ADC #$0004 690400 */
    {0x00078063u,0x00078065u,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* STA $1A 851a */
    {0x00078065u,0x00078068u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDY #$0000 a00000 */
    {0x00078068u,0x0407806Au,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* SEP #$20 e220 */
    {0x00078071u,0x00078073u,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA $24 a524 */
    {0x00078073u,0x00078076u,36u,5u,2u,0u,{0x072142u, 0x072143u},{1u, 1u},{24u, 30u},{30u, 36u},{6u, 6u}}, /* STA $2142 8d4221 */
    {0x00078076u,0x00078077u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* CLC 18 */
    {0x00078077u,0x0007807Au,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* ADC #$0006 690600 */
    {0x0007807Au,0x0007807Cu,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* STA $24 8524 */
    {0x0007807Cu,0x0407807Eu,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* SEP #$20 e220 */
    {0x000780B9u,0x000780BBu,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA $26 a526 */
    {0x000780BBu,0x000780BEu,36u,5u,2u,0u,{0x072142u, 0x072143u},{1u, 1u},{24u, 30u},{30u, 36u},{6u, 6u}}, /* STA $2142 8d4221 */
    {0x000780BEu,0x000780BFu,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* CLC 18 */
    {0x000780BFu,0x000780C2u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* ADC #$0004 690400 */
    {0x000780C2u,0x000780C4u,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* STA $26 8526 */
    {0x000780C4u,0x040780C6u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* SEP #$20 e220 */
    {0x000780D2u,0x000780D4u,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA $28 a528 */
    {0x000780D4u,0x040780D6u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* SEP #$20 e220 */
    {0x000780F3u,0x000780F5u,52u,7u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA [$20],Y b720 */
    {0x000780F5u,0x000780F6u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* CLC 18 */
    {0x000780F6u,0x000780F8u,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* ADC $28 6528 */
    {0x000780F8u,0x000780F9u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* INY c8 */
    {0x000780F9u,0x000780FAu,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* INY c8 */
    {0x000780FAu,0x040780FCu,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* SEP #$20 e220 */
    {0x00078119u,0x0007811Bu,52u,7u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA [$20],Y b720 */
    {0x0007811Bu,0x0407811Du,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* SEP #$20 e220 */
    {0x0007812Du,0x0007812Fu,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA $28 a528 */
    {0x0007812Fu,0x00078132u,36u,5u,2u,0u,{0x072142u, 0x072143u},{1u, 1u},{24u, 30u},{30u, 36u},{6u, 6u}}, /* STA $2142 8d4221 */
    {0x00078132u,0x00078133u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* TXA 8a */
    {0x00078133u,0x00078134u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* CLC 18 */
    {0x00078134u,0x00078136u,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* ADC $28 6528 */
    {0x00078136u,0x00078138u,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* STA $28 8528 */
    {0x00078138u,0x0407813Au,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* SEP #$20 e220 */
    {0x00078161u,0x0007802Fu,30u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BRL $07:802F 82cbfe */
    {0x04078036u,0x04078038u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BPL $07:8055 101d */
    {0x04078036u,0x04078055u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BPL $07:8055 101d */
    {0x04078038u,0x0407803Au,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA #$00 a900 */
    {0x0407803Au,0x0407803Du,30u,4u,1u,0u,{0x072141u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2141 8d4121 */
    {0x0407803Du,0x0007803Fu,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* REP #$20 c220 */
    {0x04078047u,0x04078049u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA $1C a51c */
    {0x04078049u,0x0407804Cu,30u,4u,1u,0u,{0x072140u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2140 8d4021 */
    {0x0407804Cu,0x0407804Fu,30u,4u,1u,0u,{0x072140u, 0x000000u},{0u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* CMP $2140 cd4021 */
    {0x0407804Fu,0x0407804Cu,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:804C d0fb */
    {0x0407804Fu,0x04078051u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:804C d0fb */
    {0x04078051u,0x00078053u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* REP #$20 c220 */
    {0x04078055u,0x04078057u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* STA $22 8522 */
    {0x04078057u,0x00078059u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* REP #$20 c220 */
    {0x0407806Au,0x0407806Cu,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA #$01 a901 */
    {0x0407806Cu,0x0407806Fu,30u,4u,1u,0u,{0x072141u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2141 8d4121 */
    {0x0407806Fu,0x00078071u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* REP #$20 c220 */
    {0x0407807Eu,0x04078080u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA $1C a51c */
    {0x04078080u,0x04078083u,30u,4u,1u,0u,{0x072140u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2140 8d4021 */
    {0x04078083u,0x04078086u,30u,4u,1u,0u,{0x072140u, 0x000000u},{0u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* CMP $2140 cd4021 */
    {0x04078086u,0x04078083u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:8083 d0fb */
    {0x04078086u,0x04078088u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:8083 d0fb */
    {0x04078088u,0x0407808Au,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA $23 a523 */
    {0x0407808Au,0x0407808Du,30u,4u,1u,0u,{0x072141u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2141 8d4121 */
    {0x0407808Du,0x0407808Fu,38u,5u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* INC $23 e623 */
    {0x0407808Fu,0x04078091u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA #$00 a900 */
    {0x04078091u,0x04078094u,30u,4u,1u,0u,{0x072140u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2140 8d4021 */
    {0x04078094u,0x04078097u,30u,4u,1u,0u,{0x072140u, 0x000000u},{0u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* CMP $2140 cd4021 */
    {0x04078097u,0x04078094u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:8094 d0fb */
    {0x04078097u,0x04078099u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:8094 d0fb */
    {0x04078099u,0x0407809Au,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* INC A 1a */
    {0x0407809Au,0x0407809Du,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDX #$0005 a20500 */
    {0x0407809Du,0x0407809Eu,20u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* XBA eb */
    {0x0407809Eu,0x040780A0u,46u,6u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA [$20],Y b720 */
    {0x040780A0u,0x040780A3u,30u,4u,1u,0u,{0x072141u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2141 8d4121 */
    {0x040780A3u,0x040780A4u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* INY c8 */
    {0x040780A4u,0x040780A5u,20u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* XBA eb */
    {0x040780A5u,0x040780A8u,30u,4u,1u,0u,{0x072140u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2140 8d4021 */
    {0x040780A8u,0x040780ABu,30u,4u,1u,0u,{0x072140u, 0x000000u},{0u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* CMP $2140 cd4021 */
    {0x040780ABu,0x040780A8u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:80A8 d0fb */
    {0x040780ABu,0x040780ADu,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:80A8 d0fb */
    {0x040780ADu,0x040780AEu,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* INC A 1a */
    {0x040780AEu,0x040780AFu,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* DEX ca */
    {0x040780AFu,0x0407809Du,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:809D d0ec */
    {0x040780AFu,0x040780B1u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:809D d0ec */
    {0x040780B1u,0x040780B2u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* INC A 1a */
    {0x040780B2u,0x040780B4u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* STA $1C 851c */
    {0x040780B4u,0x040780B7u,30u,4u,1u,0u,{0x072141u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2141 8d4121 */
    {0x040780B7u,0x000780B9u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* REP #$20 c220 */
    {0x040780C6u,0x040780C8u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA $1C a51c */
    {0x040780C8u,0x040780CBu,30u,4u,1u,0u,{0x072140u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2140 8d4021 */
    {0x040780CBu,0x040780CEu,30u,4u,1u,0u,{0x072140u, 0x000000u},{0u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* CMP $2140 cd4021 */
    {0x040780CEu,0x040780CBu,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:80CB d0fb */
    {0x040780CEu,0x040780D0u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:80CB d0fb */
    {0x040780D0u,0x000780D2u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* REP #$20 c220 */
    {0x040780D6u,0x040780D9u,30u,4u,1u,0u,{0x072141u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2141 8d4121 */
    {0x040780D9u,0x040780DBu,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA #$00 a900 */
    {0x040780DBu,0x040780DEu,30u,4u,1u,0u,{0x072140u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2140 8d4021 */
    {0x040780DEu,0x040780E1u,30u,4u,1u,0u,{0x072140u, 0x000000u},{0u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* CMP $2140 cd4021 */
    {0x040780E1u,0x040780DEu,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:80DE d0fb */
    {0x040780E1u,0x040780E3u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:80DE d0fb */
    {0x040780E3u,0x040780E4u,20u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* XBA eb */
    {0x040780E4u,0x040780E7u,30u,4u,1u,0u,{0x072141u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2141 8d4121 */
    {0x040780E7u,0x040780E9u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA #$01 a901 */
    {0x040780E9u,0x040780ECu,30u,4u,1u,0u,{0x072140u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2140 8d4021 */
    {0x040780ECu,0x040780EFu,30u,4u,1u,0u,{0x072140u, 0x000000u},{0u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* CMP $2140 cd4021 */
    {0x040780EFu,0x040780ECu,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:80EC d0fb */
    {0x040780EFu,0x040780F1u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:80EC d0fb */
    {0x040780F1u,0x000780F3u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* REP #$20 c220 */
    {0x040780FCu,0x040780FFu,30u,4u,1u,0u,{0x072141u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2141 8d4121 */
    {0x040780FFu,0x04078101u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA #$02 a902 */
    {0x04078101u,0x04078104u,30u,4u,1u,0u,{0x072140u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2140 8d4021 */
    {0x04078104u,0x04078107u,30u,4u,1u,0u,{0x072140u, 0x000000u},{0u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* CMP $2140 cd4021 */
    {0x04078107u,0x04078104u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:8104 d0fb */
    {0x04078107u,0x04078109u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:8104 d0fb */
    {0x04078109u,0x0407810Au,20u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* XBA eb */
    {0x0407810Au,0x0407810Du,30u,4u,1u,0u,{0x072141u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2141 8d4121 */
    {0x0407810Du,0x0407810Fu,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA #$03 a903 */
    {0x0407810Fu,0x04078112u,30u,4u,1u,0u,{0x072140u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2140 8d4021 */
    {0x04078112u,0x04078115u,30u,4u,1u,0u,{0x072140u, 0x000000u},{0u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* CMP $2140 cd4021 */
    {0x04078115u,0x04078112u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:8112 d0fb */
    {0x04078115u,0x04078117u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:8112 d0fb */
    {0x04078117u,0x00078119u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* REP #$20 c220 */
    {0x0407811Du,0x0407811Fu,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:8123 d004 */
    {0x0407811Du,0x04078123u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:8123 d004 */
    {0x0407811Fu,0x04078121u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA #$05 a905 */
    {0x04078121u,0x0407815Du,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BRA $07:815D 803a */
    {0x04078123u,0x04078124u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* INY c8 */
    {0x04078124u,0x04078125u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* INY c8 */
    {0x04078125u,0x04078126u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* TAX aa */
    {0x04078126u,0x04078128u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA #$05 a905 */
    {0x04078128u,0x0407812Bu,30u,4u,1u,0u,{0x072141u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2141 8d4121 */
    {0x0407812Bu,0x0007812Du,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* REP #$20 c220 */
    {0x0407813Au,0x0407813Cu,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA #$05 a905 */
    {0x0407813Cu,0x0407813Fu,30u,4u,1u,0u,{0x072140u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2140 8d4021 */
    {0x0407813Fu,0x04078142u,30u,4u,1u,0u,{0x072140u, 0x000000u},{0u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* CMP $2140 cd4021 */
    {0x04078142u,0x0407813Fu,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:813F d0fb */
    {0x04078142u,0x04078144u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:813F d0fb */
    {0x04078144u,0x04078146u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA #$00 a900 */
    {0x04078146u,0x04078147u,20u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* XBA eb */
    {0x04078147u,0x04078149u,46u,6u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA [$20],Y b720 */
    {0x04078149u,0x0407814Cu,30u,4u,1u,0u,{0x072141u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2141 8d4121 */
    {0x0407814Cu,0x0407814Du,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* INY c8 */
    {0x0407814Du,0x0407814Eu,20u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* XBA eb */
    {0x0407814Eu,0x04078151u,30u,4u,1u,0u,{0x072140u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA $2140 8d4021 */
    {0x04078151u,0x04078154u,30u,4u,1u,0u,{0x072140u, 0x000000u},{0u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* CMP $2140 cd4021 */
    {0x04078154u,0x04078151u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:8151 d0fb */
    {0x04078154u,0x04078156u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:8151 d0fb */
    {0x04078156u,0x04078157u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* INC A 1a */
    {0x04078157u,0x04078158u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* DEX ca */
    {0x04078158u,0x04078146u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:8146 d0ec */
    {0x04078158u,0x0407815Au,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE $07:8146 d0ec */
    {0x0407815Au,0x0407815Bu,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* INC A 1a */
    {0x0407815Bu,0x0407815Au,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BEQ $07:815A f0fd */
    {0x0407815Bu,0x0407815Du,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BEQ $07:815A f0fd */
    {0x0407815Du,0x0407815Fu,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* STA $1C 851c */
    {0x0407815Fu,0x00078161u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* REP #$20 c220 */
};

const TgV13ScpuTimingVariant *tg_v13_find_second_protocol_timing(uint32_t key,uint32_t next_key,int require_next){
    uint32_t n;for(n=0u;n<TOPGEAR_RECOMP_V13_SECOND_PROTOCOL_TIMING_VARIANT_COUNT;++n){
        const TgV13ScpuTimingVariant *r=&tg_v13_second_protocol_timing_variants[n];
        if(r->context_key==key&&(!require_next||r->next_context_key==next_key))return r;
    }return NULL;
}
