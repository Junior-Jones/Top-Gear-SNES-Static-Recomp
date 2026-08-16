/* Generated from the exact Top Gear (USA) ROM by
   tools/scpu/generate_v03_scpu_batch.py.
   No emulator trace or endpoint state was used. */
#include "topgear_internal.h"
#include "topgear_v03_scpu_batch.h"

unsigned tg_v03_generated_scpu_context_count(void) { return 266u; }

int tg_v03_generated_scpu_step(struct TopGearRecomp *instance) {
    uint32_t key, address = 0u, base24 = 0u;
    uint16_t word = 0u;
    uint8_t byte = 0u;
    if (!instance) return 0;
    key = tg_generated_context_key(instance);
    switch (key) {
    case 0x0E008000u: /* D8  CLD; reference visits 1 */
        if (!tg_require_context(instance, 1u, 1u, 1u, 0x00u, 0x0000u, "00:8000")) return 0;
        tg_set_flag(instance, TG_P_D, 0);
        instance->cpu.pc = 0x8001u;
        instance->instruction_count++;
        return 1;
    case 0x0E008001u: /* 78  SEI; reference visits 1 */
        if (!tg_require_context(instance, 1u, 1u, 1u, 0x00u, 0x0000u, "00:8001")) return 0;
        tg_set_flag(instance, TG_P_I, 1);
        instance->cpu.pc = 0x8002u;
        instance->instruction_count++;
        return 1;
    case 0x0E008002u: /* A9 00  LDA #$00; reference visits 1 */
        if (!tg_require_context(instance, 1u, 1u, 1u, 0x00u, 0x0000u, "00:8002")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8004u;
        instance->instruction_count++;
        return 1;
    case 0x0E008004u: /* 8D 00 42  STA $4200; reference visits 1 */
        if (!tg_require_context(instance, 1u, 1u, 1u, 0x00u, 0x0000u, "00:8004")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4200u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8007u;
        instance->instruction_count++;
        return 1;
    case 0x0E008007u: /* 18  CLC; reference visits 1 */
        if (!tg_require_context(instance, 1u, 1u, 1u, 0x00u, 0x0000u, "00:8007")) return 0;
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x8008u;
        instance->instruction_count++;
        return 1;
    case 0x0E008008u: /* FB  XCE; reference visits 1 */
        if (!tg_require_context(instance, 1u, 1u, 1u, 0x00u, 0x0000u, "00:8008")) return 0;
        {
            uint8_t old_e = instance->cpu.e;
            uint8_t old_c = (uint8_t)tg_flag(instance, TG_P_C);
            instance->cpu.e = old_c;
            tg_set_flag(instance, TG_P_C, old_e != 0u);
            if (instance->cpu.e) {
                instance->cpu.p |= (TG_P_M | TG_P_X);
                instance->cpu.s = (uint16_t)(0x0100u | (instance->cpu.s & 0x00FFu));
            }
        }
        instance->cpu.pc = 0x8009u;
        instance->instruction_count++;
        return 1;
    case 0x06008009u: /* C2 30  REP #$30; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 1u, 0x00u, 0x0000u, "00:8009")) return 0;
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x800Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000800Bu: /* A9 FE 01  LDA #$01FE; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:800B")) return 0;
        word = 0x01FEu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x800Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000800Eu: /* 1B  TCS; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:800E")) return 0;
        instance->cpu.s = instance->cpu.e ? (uint16_t)(0x0100u | (instance->cpu.a & 0x00FFu)) : instance->cpu.a;
        instance->cpu.pc = 0x800Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000800Fu: /* A9 00 00  LDA #$0000; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:800F")) return 0;
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8012u;
        instance->instruction_count++;
        return 1;
    case 0x00008012u: /* 5B  TCD; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8012")) return 0;
        instance->cpu.d = instance->cpu.a;
        tg_set_nz16(instance, instance->cpu.d);
        instance->cpu.pc = 0x8013u;
        instance->instruction_count++;
        return 1;
    case 0x00008013u: /* 9C F2 1F  STZ $1FF2; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8013")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF2u), 0u)) return 0;
        instance->cpu.pc = 0x8016u;
        instance->instruction_count++;
        return 1;
    case 0x00008016u: /* E2 20  SEP #$20; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8016")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8018u;
        instance->instruction_count++;
        return 1;
    case 0x04008018u: /* C2 10  REP #$10; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8018")) return 0;
        instance->cpu.p &= (uint8_t)~0x10u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x801Au;
        instance->instruction_count++;
        return 1;
    case 0x0400801Au: /* A9 8F  LDA #$8F; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:801A")) return 0;
        byte = 0x8Fu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x801Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400801Cu: /* 8D 00 21  STA $2100; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:801C")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2100u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x801Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400801Fu: /* A2 00 E0  LDX #$E000; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:801F")) return 0;
        word = 0xE000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8022u;
        instance->instruction_count++;
        return 1;
    case 0x04008022u: /* A9 0D  LDA #$0D; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8022")) return 0;
        byte = 0x0Du;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8024u;
        instance->instruction_count++;
        return 1;
    case 0x04008024u: /* 86 23  STX $23; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8024")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x8026u;
        instance->instruction_count++;
        return 1;
    case 0x04008026u: /* 85 25  STA $25; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8026")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x25u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8028u;
        instance->instruction_count++;
        return 1;
    case 0x04008028u: /* A2 00 00  LDX #$0000; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8028")) return 0;
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x802Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400802Bu: /* DA  PHX; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:802B")) return 0;
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x802Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400802Cu: /* 20 8E EA  JSR $EA8E; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:802C")) return 0;
        if (!tg_push16(instance, 0x802Eu)) return 0;
        instance->cpu.pc = 0xEA8Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400802Fu: /* FA  PLX; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:802F")) return 0;
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8030u;
        instance->instruction_count++;
        return 1;
    case 0x04008030u: /* B0 0C  BCS $00:803E; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8030")) return 0;
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x803Eu : 0x8032u;
        instance->instruction_count++;
        return 1;
    case 0x04008032u: /* 9F 00 20 7E  STA $7E2000,X; reference visits 12497 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8032")) return 0;
        if (!tg_bus_write8(instance, ((0x7E2000u + instance->cpu.x) & 0xFFFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8036u;
        instance->instruction_count++;
        return 1;
    case 0x04008036u: /* E8  INX; reference visits 12497 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8036")) return 0;
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8037u;
        instance->instruction_count++;
        return 1;
    case 0x04008037u: /* DA  PHX; reference visits 12497 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8037")) return 0;
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x8038u;
        instance->instruction_count++;
        return 1;
    case 0x04008038u: /* 20 9B EA  JSR $EA9B; reference visits 12497 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8038")) return 0;
        if (!tg_push16(instance, 0x803Au)) return 0;
        instance->cpu.pc = 0xEA9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400803Bu: /* FA  PLX; reference visits 12497 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:803B")) return 0;
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x803Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400803Cu: /* 90 F4  BCC $00:8032; reference visits 12497 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:803C")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x8032u : 0x803Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400803Eu: /* A9 00  LDA #$00; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:803E")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8040u;
        instance->instruction_count++;
        return 1;
    case 0x04008040u: /* 85 3A  STA $3A; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8040")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Au) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8042u;
        instance->instruction_count++;
        return 1;
    case 0x04008042u: /* A9 20  LDA #$20; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8042")) return 0;
        byte = 0x20u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8044u;
        instance->instruction_count++;
        return 1;
    case 0x04008044u: /* 85 3B  STA $3B; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8044")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Bu) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8046u;
        instance->instruction_count++;
        return 1;
    case 0x04008046u: /* A9 7E  LDA #$7E; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8046")) return 0;
        byte = 0x7Eu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8048u;
        instance->instruction_count++;
        return 1;
    case 0x04008048u: /* 85 3C  STA $3C; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8048")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Cu) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x804Au;
        instance->instruction_count++;
        return 1;
    case 0x0400804Au: /* 20 B6 EB  JSR $EBB6; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:804A")) return 0;
        if (!tg_push16(instance, 0x804Cu)) return 0;
        instance->cpu.pc = 0xEBB6u;
        instance->instruction_count++;
        return 1;
    case 0x0000804Du: /* E2 20  SEP #$20; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:804D")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x804Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400804Fu: /* A9 00  LDA #$00; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:804F")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8051u;
        instance->instruction_count++;
        return 1;
    case 0x04008051u: /* 8D 40 21  STA $2140; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8051")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8054u;
        instance->instruction_count++;
        return 1;
    case 0x04008054u: /* A2 00 00  LDX #$0000; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8054")) return 0;
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8057u;
        instance->instruction_count++;
        return 1;
    case 0x04008057u: /* E8  INX; reference visits 65536 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8057")) return 0;
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8058u;
        instance->instruction_count++;
        return 1;
    case 0x04008058u: /* D0 FD  BNE $00:8057; reference visits 65536 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:8058")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8057u : 0x805Au;
        instance->instruction_count++;
        return 1;
    case 0x0400805Au: /* A9 18  LDA #$18; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:805A")) return 0;
        byte = 0x18u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x805Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400805Cu: /* 8D 41 21  STA $2141; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:805C")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x805Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400805Fu: /* C2 20  REP #$20; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:805F")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8061u;
        instance->instruction_count++;
        return 1;
    case 0x00008061u: /* A9 00 00  LDA #$0000; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8061")) return 0;
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8064u;
        instance->instruction_count++;
        return 1;
    case 0x00008064u: /* 22 00 80 07  JSL $078000; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:8064")) return 0;
        if (!tg_push8(instance, instance->cpu.pbr)) return 0;
        if (!tg_push16(instance, 0x8067u)) return 0;
        instance->cpu.pbr = 0x07u;
        instance->cpu.pc = 0x8000u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA8Eu: /* C2 20  REP #$20; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EA8E")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEA90u;
        instance->instruction_count++;
        return 1;
    case 0x0000EA90u: /* 64 20  STZ $20; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EA90")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0xEA92u;
        instance->instruction_count++;
        return 1;
    case 0x0000EA92u: /* A9 FF 07  LDA #$07FF; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EA92")) return 0;
        word = 0x07FFu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEA95u;
        instance->instruction_count++;
        return 1;
    case 0x0000EA95u: /* 85 1E  STA $1E; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EA95")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xEA97u;
        instance->instruction_count++;
        return 1;
    case 0x0000EA97u: /* E2 20  SEP #$20; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EA97")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEA99u;
        instance->instruction_count++;
        return 1;
    case 0x0400EA99u: /* 64 22  STZ $22; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EA99")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0xEA9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA9Bu: /* E2 20  SEP #$20; reference visits 12498 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EA9B")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEA9Du;
        instance->instruction_count++;
        return 1;
    case 0x0400EA9Du: /* C2 10  REP #$10; reference visits 12498 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EA9D")) return 0;
        instance->cpu.p &= (uint8_t)~0x10u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEA9Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EA9Fu: /* A5 22  LDA $22; reference visits 12498 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EA9F")) return 0;
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEAA1u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAA1u: /* D0 61  BNE $00:EB04; reference visits 12498 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAA1")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEB04u : 0xEAA3u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAA3u: /* A4 20  LDY $20; reference visits 2278 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAA3")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAA5u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAA5u: /* B7 23  LDA [$23],Y; reference visits 2278 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAA5")) return 0;
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEAA7u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAA7u: /* D0 02  BNE $00:EAAB; reference visits 2278 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAA7")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEAABu : 0xEAA9u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAA9u: /* 38  SEC; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAA9")) return 0;
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xEAAAu;
        instance->instruction_count++;
        return 1;
    case 0x0400EAAAu: /* 60  RTS; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAAA")) return 0;
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0400EAABu: /* 30 6B  BMI $00:EB18; reference visits 2277 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAAB")) return 0;
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xEB18u : 0xEAADu;
        instance->instruction_count++;
        return 1;
    case 0x0400EAADu: /* C6 22  DEC $22; reference visits 888 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAAD")) return 0;
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), &byte)) return 0;
        byte = (uint8_t)(byte - 1u);
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), byte)) return 0;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEAAFu;
        instance->instruction_count++;
        return 1;
    case 0x0400EAAFu: /* C8  INY; reference visits 888 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAAF")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAB0u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAB0u: /* C9 40  CMP #$40; reference visits 888 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAB0")) return 0;
        byte = 0x40u;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xEAB2u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAB2u: /* 90 26  BCC $00:EADA; reference visits 888 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAB2")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xEADAu : 0xEAB4u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAB4u: /* C9 60  CMP #$60; reference visits 80 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAB4")) return 0;
        byte = 0x60u;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xEAB6u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAB6u: /* 90 0F  BCC $00:EAC7; reference visits 80 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAB6")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xEAC7u : 0xEAB8u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAC7u: /* C2 20  REP #$20; reference visits 80 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAC7")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEAC9u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAC9u: /* 29 1F 00  AND #$001F; reference visits 80 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EAC9")) return 0;
        word = 0x001Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEACCu;
        instance->instruction_count++;
        return 1;
    case 0x0000EACCu: /* 1A  INC A; reference visits 80 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EACC")) return 0;
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEACDu;
        instance->instruction_count++;
        return 1;
    case 0x0000EACDu: /* 85 1A  STA $1A; reference visits 80 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EACD")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xEACFu;
        instance->instruction_count++;
        return 1;
    case 0x0000EACFu: /* E2 20  SEP #$20; reference visits 80 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EACF")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEAD1u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAD1u: /* B7 23  LDA [$23],Y; reference visits 80 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAD1")) return 0;
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEAD3u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAD3u: /* C8  INY; reference visits 80 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAD3")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAD4u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAD4u: /* 84 20  STY $20; reference visits 80 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAD4")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xEAD6u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAD6u: /* 85 1D  STA $1D; reference visits 80 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAD6")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x1Du) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEAD8u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAD8u: /* 80 65  BRA $00:EB3F; reference visits 80 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAD8")) return 0;
        instance->cpu.pc = 0xEB3Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EADAu: /* C6 22  DEC $22; reference visits 808 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EADA")) return 0;
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), &byte)) return 0;
        byte = (uint8_t)(byte - 1u);
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), byte)) return 0;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEADCu;
        instance->instruction_count++;
        return 1;
    case 0x0400EADCu: /* C9 20  CMP #$20; reference visits 808 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EADC")) return 0;
        byte = 0x20u;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xEADEu;
        instance->instruction_count++;
        return 1;
    case 0x0400EADEu: /* 90 0F  BCC $00:EAEF; reference visits 808 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EADE")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xEAEFu : 0xEAE0u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAE0u: /* EB  XBA; reference visits 24 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAE0")) return 0;
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xEAE1u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAE1u: /* B7 23  LDA [$23],Y; reference visits 24 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAE1")) return 0;
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEAE3u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAE3u: /* C8  INY; reference visits 24 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAE3")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAE4u;
        instance->instruction_count++;
        return 1;
    case 0x0400EAE4u: /* C2 20  REP #$20; reference visits 24 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAE4")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEAE6u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAE6u: /* 29 FF 1F  AND #$1FFF; reference visits 24 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EAE6")) return 0;
        word = 0x1FFFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAE9u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAE9u: /* 18  CLC; reference visits 24 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EAE9")) return 0;
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEAEAu;
        instance->instruction_count++;
        return 1;
    case 0x0000EAEAu: /* 69 1E 00  ADC #$001E; reference visits 24 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EAEA")) return 0;
        word = 0x001Eu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xEAEDu;
        instance->instruction_count++;
        return 1;
    case 0x0000EAEDu: /* 80 0F  BRA $00:EAFE; reference visits 24 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EAED")) return 0;
        instance->cpu.pc = 0xEAFEu;
        instance->instruction_count++;
        return 1;
    case 0x0400EAEFu: /* C2 20  REP #$20; reference visits 784 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAEF")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEAF1u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAF1u: /* 29 1F 00  AND #$001F; reference visits 784 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EAF1")) return 0;
        word = 0x001Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAF4u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAF4u: /* 3A  DEC A; reference visits 784 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EAF4")) return 0;
        word = (uint16_t)((instance->cpu.a) - 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAF5u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAF5u: /* 3A  DEC A; reference visits 784 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EAF5")) return 0;
        word = (uint16_t)((instance->cpu.a) - 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEAF6u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAF6u: /* 10 06  BPL $00:EAFE; reference visits 784 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EAF6")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEAFEu : 0xEAF8u;
        instance->instruction_count++;
        return 1;
    case 0x0000EAF8u: /* E2 20  SEP #$20; reference visits 321 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EAF8")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEAFAu;
        instance->instruction_count++;
        return 1;
    case 0x0400EAFAu: /* 64 22  STZ $22; reference visits 321 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAFA")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0xEAFCu;
        instance->instruction_count++;
        return 1;
    case 0x0400EAFCu: /* 80 3C  BRA $00:EB3A; reference visits 321 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EAFC")) return 0;
        instance->cpu.pc = 0xEB3Au;
        instance->instruction_count++;
        return 1;
    case 0x0000EAFEu: /* 85 1A  STA $1A; reference visits 487 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EAFE")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xEB00u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB00u: /* E2 20  SEP #$20; reference visits 487 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB00")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEB02u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB02u: /* 80 36  BRA $00:EB3A; reference visits 487 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB02")) return 0;
        instance->cpu.pc = 0xEB3Au;
        instance->instruction_count++;
        return 1;
    case 0x0400EB04u: /* 10 4C  BPL $00:EB52; reference visits 10220 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB04")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEB52u : 0xEB06u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB06u: /* C2 20  REP #$20; reference visits 3974 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB06")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEB08u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB08u: /* C6 1A  DEC $1A; reference visits 3974 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB08")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB0Au;
        instance->instruction_count++;
        return 1;
    case 0x0000EB0Au: /* E2 20  SEP #$20; reference visits 3974 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB0A")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEB0Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB0Cu: /* 10 02  BPL $00:EB10; reference visits 3974 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB0C")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEB10u : 0xEB0Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB0Eu: /* 64 22  STZ $22; reference visits 567 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB0E")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0xEB10u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB10u: /* 49 FF  EOR #$FF; reference visits 3974 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB10")) return 0;
        byte = 0xFFu;
        byte = (uint8_t)((tg_acc8(instance)) ^ byte);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB12u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB12u: /* D0 24  BNE $00:EB38; reference visits 3974 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB12")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEB38u : 0xEB14u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB14u: /* A5 1D  LDA $1D; reference visits 371 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB14")) return 0;
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x1Du) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB16u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB16u: /* 80 27  BRA $00:EB3F; reference visits 371 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB16")) return 0;
        instance->cpu.pc = 0xEB3Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB18u: /* E6 22  INC $22; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB18")) return 0;
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), &byte)) return 0;
        byte = (uint8_t)(byte + 1u);
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), byte)) return 0;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB1Au;
        instance->instruction_count++;
        return 1;
    case 0x0400EB1Au: /* C8  INY; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB1A")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB1Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB1Bu: /* C9 C0  CMP #$C0; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB1B")) return 0;
        byte = 0xC0u;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xEB1Du;
        instance->instruction_count++;
        return 1;
    case 0x0400EB1Du: /* 90 46  BCC $00:EB65; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB1D")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xEB65u : 0xEB1Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB1Fu: /* EB  XBA; reference visits 593 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB1F")) return 0;
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xEB20u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB20u: /* B7 23  LDA [$23],Y; reference visits 593 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB20")) return 0;
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB22u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB22u: /* C8  INY; reference visits 593 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB22")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB23u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB23u: /* C2 20  REP #$20; reference visits 593 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB23")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEB25u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB25u: /* AA  TAX; reference visits 593 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB25")) return 0;
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xEB26u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB26u: /* EB  XBA; reference visits 593 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB26")) return 0;
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xEB27u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB27u: /* 4A  LSR A; reference visits 593 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB27")) return 0;
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB28u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB28u: /* 4A  LSR A; reference visits 593 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB28")) return 0;
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB29u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB29u: /* 29 0F 00  AND #$000F; reference visits 593 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB29")) return 0;
        word = 0x000Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB2Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000EB2Cu: /* 18  CLC; reference visits 593 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB2C")) return 0;
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEB2Du;
        instance->instruction_count++;
        return 1;
    case 0x0000EB2Du: /* 69 03 00  ADC #$0003; reference visits 593 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB2D")) return 0;
        word = 0x0003u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xEB30u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB30u: /* 85 1A  STA $1A; reference visits 593 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB30")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xEB32u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB32u: /* 8A  TXA; reference visits 593 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB32")) return 0;
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xEB33u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB33u: /* 29 FF 03  AND #$03FF; reference visits 593 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB33")) return 0;
        word = 0x03FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB36u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB36u: /* 80 3E  BRA $00:EB76; reference visits 593 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB36")) return 0;
        instance->cpu.pc = 0xEB76u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB38u: /* A4 20  LDY $20; reference visits 3603 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB38")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB3Au;
        instance->instruction_count++;
        return 1;
    case 0x0400EB3Au: /* B7 23  LDA [$23],Y; reference visits 4411 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB3A")) return 0;
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB3Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB3Cu: /* C8  INY; reference visits 4411 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB3C")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB3Du;
        instance->instruction_count++;
        return 1;
    case 0x0400EB3Du: /* 84 20  STY $20; reference visits 4411 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB3D")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xEB3Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB3Fu: /* A6 1E  LDX $1E; reference visits 4862 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB3F")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB41u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB41u: /* 9D B2 07  STA $07B2,X; reference visits 4862 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB41")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x07B2u + instance->cpu.x)), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEB44u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB44u: /* CA  DEX; reference visits 4862 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB44")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB45u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB45u: /* 10 03  BPL $00:EB4A; reference visits 4862 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB45")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEB4Au : 0xEB47u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB47u: /* A2 FF 07  LDX #$07FF; reference visits 3 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB47")) return 0;
        word = 0x07FFu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB4Au;
        instance->instruction_count++;
        return 1;
    case 0x0400EB4Au: /* 86 1E  STX $1E; reference visits 4862 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB4A")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xEB4Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB4Cu: /* 18  CLC; reference visits 4862 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB4C")) return 0;
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEB4Du;
        instance->instruction_count++;
        return 1;
    case 0x0400EB4Du: /* 60  RTS; reference visits 4862 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB4D")) return 0;
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0400EB4Eu: /* 86 1C  STX $1C; reference visits 4857 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB4E")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xEB50u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB50u: /* 18  CLC; reference visits 4857 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB50")) return 0;
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEB51u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB51u: /* 60  RTS; reference visits 4857 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB51")) return 0;
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0400EB52u: /* A6 1C  LDX $1C; reference visits 6246 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB52")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB54u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB54u: /* BD B2 07  LDA $07B2,X; reference visits 6246 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB54")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x07B2u + instance->cpu.x)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB57u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB57u: /* CA  DEX; reference visits 6246 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB57")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB58u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB58u: /* 10 03  BPL $00:EB5D; reference visits 6246 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB58")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEB5Du : 0xEB5Au;
        instance->instruction_count++;
        return 1;
    case 0x0400EB5Au: /* A2 FF 07  LDX #$07FF; reference visits 2 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB5A")) return 0;
        word = 0x07FFu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB5Du;
        instance->instruction_count++;
        return 1;
    case 0x0400EB5Du: /* E4 1E  CPX $1E; reference visits 6246 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB5D")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), &word)) return 0;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0xEB5Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB5Fu: /* D0 ED  BNE $00:EB4E; reference visits 6246 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB5F")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEB4Eu : 0xEB61u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB61u: /* 64 22  STZ $22; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB61")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x22u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0xEB63u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB63u: /* 18  CLC; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB63")) return 0;
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEB64u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB64u: /* 60  RTS; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB64")) return 0;
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0400EB65u: /* C2 20  REP #$20; reference visits 796 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB65")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEB67u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB67u: /* AA  TAX; reference visits 796 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB67")) return 0;
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xEB68u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB68u: /* 0A  ASL A; reference visits 796 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB68")) return 0;
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB69u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB69u: /* 0A  ASL A; reference visits 796 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB69")) return 0;
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB6Au;
        instance->instruction_count++;
        return 1;
    case 0x0000EB6Au: /* 0A  ASL A; reference visits 796 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB6A")) return 0;
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB6Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000EB6Bu: /* EB  XBA; reference visits 796 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB6B")) return 0;
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xEB6Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000EB6Cu: /* 29 01 00  AND #$0001; reference visits 796 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB6C")) return 0;
        word = 0x0001u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB6Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000EB6Fu: /* 1A  INC A; reference visits 796 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB6F")) return 0;
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB70u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB70u: /* 85 1A  STA $1A; reference visits 796 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB70")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xEB72u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB72u: /* 8A  TXA; reference visits 796 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB72")) return 0;
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xEB73u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB73u: /* 29 1F 00  AND #$001F; reference visits 796 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB73")) return 0;
        word = 0x001Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB76u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB76u: /* 84 20  STY $20; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB76")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x20u) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xEB78u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB78u: /* 38  SEC; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB78")) return 0;
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xEB79u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB79u: /* 65 1A  ADC $1A; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB79")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xEB7Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000EB7Bu: /* 18  CLC; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB7B")) return 0;
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEB7Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000EB7Cu: /* 65 1E  ADC $1E; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB7C")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xEB7Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000EB7Eu: /* 29 FF 07  AND #$07FF; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB7E")) return 0;
        word = 0x07FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB81u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB81u: /* AA  TAX; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB81")) return 0;
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xEB82u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB82u: /* A4 1E  LDY $1E; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB82")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB84u;
        instance->instruction_count++;
        return 1;
    case 0x0000EB84u: /* E2 20  SEP #$20; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EB84")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEB86u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB86u: /* BD B2 07  LDA $07B2,X; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB86")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x07B2u + instance->cpu.x)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB89u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB89u: /* 99 B2 07  STA $07B2,Y; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB89")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x07B2u + instance->cpu.y)), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEB8Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB8Cu: /* 85 1D  STA $1D; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB8C")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x1Du) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEB8Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB8Eu: /* 80 06  BRA $00:EB96; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB8E")) return 0;
        instance->cpu.pc = 0xEB96u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB90u: /* BD B2 07  LDA $07B2,X; reference visits 6246 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB90")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x07B2u + instance->cpu.x)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEB93u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB93u: /* 99 B2 07  STA $07B2,Y; reference visits 6246 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB93")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x07B2u + instance->cpu.y)), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEB96u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB96u: /* CA  DEX; reference visits 7635 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB96")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB97u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB97u: /* 10 03  BPL $00:EB9C; reference visits 7635 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB97")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEB9Cu : 0xEB99u;
        instance->instruction_count++;
        return 1;
    case 0x0400EB99u: /* A2 FF 07  LDX #$07FF; reference visits 6 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB99")) return 0;
        word = 0x07FFu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB9Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB9Cu: /* 88  DEY; reference visits 7635 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB9C")) return 0;
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEB9Du;
        instance->instruction_count++;
        return 1;
    case 0x0400EB9Du: /* 10 03  BPL $00:EBA2; reference visits 7635 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB9D")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEBA2u : 0xEB9Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400EB9Fu: /* A0 FF 07  LDY #$07FF; reference visits 3 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EB9F")) return 0;
        word = 0x07FFu;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBA2u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBA2u: /* C6 1A  DEC $1A; reference visits 7635 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBA2")) return 0;
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &byte)) return 0;
        byte = (uint8_t)(byte - 1u);
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), byte)) return 0;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBA4u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBA4u: /* 10 EA  BPL $00:EB90; reference visits 7635 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBA4")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEB90u : 0xEBA6u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBA6u: /* A5 1D  LDA $1D; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBA6")) return 0;
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x1Du) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBA8u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBA8u: /* A6 1E  LDX $1E; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBA8")) return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBAAu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBAAu: /* CA  DEX; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBAA")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBABu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBABu: /* 10 03  BPL $00:EBB0; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBAB")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xEBB0u : 0xEBADu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBADu: /* A2 FF 07  LDX #$07FF; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBAD")) return 0;
        word = 0x07FFu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBB0u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBB0u: /* 86 1C  STX $1C; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBB0")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xEBB2u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBB2u: /* 84 1E  STY $1E; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBB2")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Eu) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0xEBB4u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBB4u: /* 18  CLC; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBB4")) return 0;
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xEBB5u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBB5u: /* 60  RTS; reference visits 1389 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBB5")) return 0;
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0400EBB6u: /* C2 30  REP #$30; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBB6")) return 0;
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEBB8u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBB8u: /* A0 00 00  LDY #$0000; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBB8")) return 0;
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBBBu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBBBu: /* A9 AA BB  LDA #$BBAA; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBBB")) return 0;
        word = 0xBBAAu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBBEu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBBEu: /* CD 40 21  CMP $2140; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBBE")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xEBC1u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBC1u: /* D0 FB  BNE $00:EBBE; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBC1")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEBBEu : 0xEBC3u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBC3u: /* E2 20  SEP #$20; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBC3")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEBC5u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBC5u: /* A9 CC  LDA #$CC; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBC5")) return 0;
        byte = 0xCCu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBC7u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBC7u: /* 48  PHA; reference visits 2 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBC7")) return 0;
        if (!tg_push8(instance, (uint8_t)tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEBC8u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBC8u: /* C2 20  REP #$20; reference visits 2 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBC8")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEBCAu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBCAu: /* B7 3A  LDA [$3A],Y; reference visits 2 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBCA")) return 0;
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x3Au) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read16(instance, address, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBCCu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBCCu: /* AA  TAX; reference visits 2 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBCC")) return 0;
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xEBCDu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBCDu: /* C8  INY; reference visits 2 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBCD")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBCEu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBCEu: /* C8  INY; reference visits 2 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBCE")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBCFu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBCFu: /* B7 3A  LDA [$3A],Y; reference visits 2 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBCF")) return 0;
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x3Au) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read16(instance, address, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBD1u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBD1u: /* 8D 42 21  STA $2142; reference visits 2 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBD1")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2142u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xEBD4u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBD4u: /* C8  INY; reference visits 2 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBD4")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBD5u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBD5u: /* C8  INY; reference visits 2 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBD5")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBD6u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBD6u: /* E2 20  SEP #$20; reference visits 2 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBD6")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEBD8u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBD8u: /* A9 00  LDA #$00; reference visits 2 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBD8")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBDAu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBDAu: /* E0 01 00  CPX #$0001; reference visits 2 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBDA")) return 0;
        word = 0x0001u;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0xEBDDu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBDDu: /* 2A  ROL A; reference visits 2 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBDD")) return 0;
        byte = tg_acc8(instance);
        word = (uint16_t)tg_flag(instance, TG_P_C);
        tg_set_flag(instance, TG_P_C, (byte & 0x80u) != 0u);
        byte = (uint8_t)((byte << 1) | word);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBDEu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBDEu: /* 8D 41 21  STA $2141; reference visits 2 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBDE")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEBE1u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBE1u: /* 69 7F  ADC #$7F; reference visits 2 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBE1")) return 0;
        byte = 0x7Fu;
        tg_adc8(instance, byte);
        instance->cpu.pc = 0xEBE3u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBE3u: /* 68  PLA; reference visits 2 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBE3")) return 0;
        if (!tg_pull8(instance, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBE4u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBE4u: /* 8D 40 21  STA $2140; reference visits 2 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBE4")) return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xEBE7u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBE7u: /* CD 40 21  CMP $2140; reference visits 2 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBE7")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xEBEAu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBEAu: /* D0 FB  BNE $00:EBE7; reference visits 2 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBEA")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEBE7u : 0xEBECu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBECu: /* 50 1D  BVC $00:EC0B; reference visits 2 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBEC")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_V) ? 0xEC0Bu : 0xEBEEu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBEEu: /* A9 00  LDA #$00; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBEE")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBF0u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBF0u: /* EB  XBA; reference visits 12489 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBF0")) return 0;
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xEBF1u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBF1u: /* B7 3A  LDA [$3A],Y; reference visits 12489 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBF1")) return 0;
        if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x3Au) & 0xFFFFu), &base24)) return 0;
        address = (base24 + instance->cpu.y) & 0xFFFFFFu;
        if (!tg_bus_read8(instance, address, &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEBF3u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBF3u: /* EB  XBA; reference visits 12489 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBF3")) return 0;
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xEBF4u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBF4u: /* C8  INY; reference visits 12489 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBF4")) return 0;
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEBF5u;
        instance->instruction_count++;
        return 1;
    case 0x0400EBF5u: /* C2 20  REP #$20; reference visits 12489 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBF5")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEBF7u;
        instance->instruction_count++;
        return 1;
    case 0x0000EBF7u: /* 8D 40 21  STA $2140; reference visits 12489 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBF7")) return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xEBFAu;
        instance->instruction_count++;
        return 1;
    case 0x0000EBFAu: /* E2 20  SEP #$20; reference visits 12489 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EBFA")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEBFCu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBFCu: /* CD 40 21  CMP $2140; reference visits 12489 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBFC")) return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0xEBFFu;
        instance->instruction_count++;
        return 1;
    case 0x0400EBFFu: /* D0 FB  BNE $00:EBFC; reference visits 12489 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EBFF")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEBFCu : 0xEC01u;
        instance->instruction_count++;
        return 1;
    case 0x0400EC01u: /* 1A  INC A; reference visits 12489 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EC01")) return 0;
        byte = (uint8_t)((tg_acc8(instance)) + 1u);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xEC02u;
        instance->instruction_count++;
        return 1;
    case 0x0400EC02u: /* CA  DEX; reference visits 12489 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EC02")) return 0;
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xEC03u;
        instance->instruction_count++;
        return 1;
    case 0x0400EC03u: /* D0 EB  BNE $00:EBF0; reference visits 12489 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EC03")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEBF0u : 0xEC05u;
        instance->instruction_count++;
        return 1;
    case 0x0400EC05u: /* 69 03  ADC #$03; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EC05")) return 0;
        byte = 0x03u;
        tg_adc8(instance, byte);
        instance->cpu.pc = 0xEC07u;
        instance->instruction_count++;
        return 1;
    case 0x0400EC07u: /* D0 BE  BNE $00:EBC7; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EC07")) return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEBC7u : 0xEC09u;
        instance->instruction_count++;
        return 1;
    case 0x0400EC0Bu: /* C2 20  REP #$20; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x00u, 0x0000u, "00:EC0B")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xEC0Du;
        instance->instruction_count++;
        return 1;
    case 0x0000EC0Du: /* 60  RTS; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "00:EC0D")) return 0;
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x00078000u: /* C2 30  REP #$30; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "07:8000")) return 0;
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8002u;
        instance->instruction_count++;
        return 1;
    case 0x00078002u: /* 8B  PHB; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "07:8002")) return 0;
        if (!tg_push8(instance, instance->cpu.dbr)) return 0;
        instance->cpu.pc = 0x8003u;
        instance->instruction_count++;
        return 1;
    case 0x00078003u: /* 4B  PHK; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "07:8003")) return 0;
        if (!tg_push8(instance, instance->cpu.pbr)) return 0;
        instance->cpu.pc = 0x8004u;
        instance->instruction_count++;
        return 1;
    case 0x00078004u: /* AB  PLB; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x00u, 0x0000u, "07:8004")) return 0;
        if (!tg_pull8(instance, &byte)) return 0;
        instance->cpu.dbr = byte;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8005u;
        instance->instruction_count++;
        return 1;
    case 0x00078005u: /* 0A  ASL A; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8005")) return 0;
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8006u;
        instance->instruction_count++;
        return 1;
    case 0x00078006u: /* AA  TAX; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8006")) return 0;
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x8007u;
        instance->instruction_count++;
        return 1;
    case 0x00078007u: /* BD 64 81  LDA $8164,X; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8007")) return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8164u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x800Au;
        instance->instruction_count++;
        return 1;
    case 0x0007800Au: /* 85 1A  STA $1A; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:800A")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x800Cu;
        instance->instruction_count++;
        return 1;
    case 0x0007800Cu: /* A9 00 89  LDA #$8900; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:800C")) return 0;
        word = 0x8900u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x800Fu;
        instance->instruction_count++;
        return 1;
    case 0x0007800Fu: /* 85 24  STA $24; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:800F")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x24u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8011u;
        instance->instruction_count++;
        return 1;
    case 0x00078011u: /* A9 00 8A  LDA #$8A00; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8011")) return 0;
        word = 0x8A00u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8014u;
        instance->instruction_count++;
        return 1;
    case 0x00078014u: /* 85 26  STA $26; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8014")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x26u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8016u;
        instance->instruction_count++;
        return 1;
    case 0x00078016u: /* A9 00 8B  LDA #$8B00; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8016")) return 0;
        word = 0x8B00u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8019u;
        instance->instruction_count++;
        return 1;
    case 0x00078019u: /* 85 28  STA $28; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8019")) return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x28u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x801Bu;
        instance->instruction_count++;
        return 1;
    case 0x0007801Bu: /* E2 20  SEP #$20; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:801B")) return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x801Du;
        instance->instruction_count++;
        return 1;
    case 0x0407801Du: /* A9 00  LDA #$00; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:801D")) return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x801Fu;
        instance->instruction_count++;
        return 1;
    case 0x0407801Fu: /* 85 23  STA $23; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:801F")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8021u;
        instance->instruction_count++;
        return 1;
    case 0x04078021u: /* A9 CC  LDA #$CC; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8021")) return 0;
        byte = 0xCCu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8023u;
        instance->instruction_count++;
        return 1;
    case 0x04078023u: /* 85 1C  STA $1C; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8023")) return 0;
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x1Cu) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8025u;
        instance->instruction_count++;
        return 1;
    case 0x04078025u: /* C2 20  REP #$20; reference visits 1 */
        if (!tg_require_context(instance, 0u, 1u, 0u, 0x07u, 0x0000u, "07:8025")) return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8027u;
        instance->instruction_count++;
        return 1;
    case 0x00078027u: /* A9 AA BB  LDA #$BBAA; reference visits 1 */
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0x0000u, "07:8027")) return 0;
        word = 0xBBAAu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x802Au;
        instance->instruction_count++;
        return 1;
    case 0x0007802Au:
        if (!tg_require_context(instance, 0u, 0u, 0u, 0x07u, 0u, "07:802A")) return 0;
        return tg_fail_frontier(instance, "Version 03 S-CPU batch waits at $07:802A for the static S-SMP driver $BBAA ready token; the S-DSP/timer scheduler is the next coupled frontier.", "07:802A");
    default:
        return tg_fail_frontier(instance, "Unknown Version 03 generated W65C816 context.", NULL);
    }
}
