/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_0020(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x0E008000u: /* D8 CLD */
        tg_set_flag(instance, TG_P_D, 0);
        instance->cpu.pc = 0x8001u;
        instance->instruction_count++;
        return 1;
    case 0x0E008001u: /* 78 SEI */
        tg_set_flag(instance, TG_P_I, 1);
        instance->cpu.pc = 0x8002u;
        instance->instruction_count++;
        return 1;
    case 0x0E008002u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8004u;
        instance->instruction_count++;
        return 1;
    case 0x0E008004u: /* 8D 00 42 STA $4200 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4200u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8007u;
        instance->instruction_count++;
        return 1;
    case 0x0E008007u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x8008u;
        instance->instruction_count++;
        return 1;
    case 0x0E008008u: /* FB XCE */
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
    case 0x06008009u: /* C2 30 REP #$30 */
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x800Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000800Bu: /* A9 FE 01 LDA #$01FE */
        word = 0x01FEu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x800Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000800Eu: /* 1B TCS */
        instance->cpu.s = instance->cpu.e ? (uint16_t)(0x0100u | (instance->cpu.a & 0x00FFu)) : instance->cpu.a;
        instance->cpu.pc = 0x800Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000800Fu: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8012u;
        instance->instruction_count++;
        return 1;
    case 0x00008012u: /* 5B TCD */
        instance->cpu.d = instance->cpu.a;
        tg_set_nz16(instance, instance->cpu.d);
        instance->cpu.pc = 0x8013u;
        instance->instruction_count++;
        return 1;
    case 0x00008013u: /* 9C F2 1F STZ $1FF2 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF2u), 0u)) return 0;
        instance->cpu.pc = 0x8016u;
        instance->instruction_count++;
        return 1;
    case 0x00008016u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8018u;
        instance->instruction_count++;
        return 1;
    case 0x04008018u: /* C2 10 REP #$10 */
        instance->cpu.p &= (uint8_t)~0x10u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x801Au;
        instance->instruction_count++;
        return 1;
    case 0x0400801Au: /* A9 8F LDA #$8F */
        byte = 0x8Fu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x801Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400801Cu: /* 8D 00 21 STA $2100 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2100u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x801Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400801Fu: /* A2 00 E0 LDX #$E000 */
        word = 0xE000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8022u;
        instance->instruction_count++;
        return 1;
    case 0x04008022u: /* A9 0D LDA #$0D */
        byte = 0x0Du;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8024u;
        instance->instruction_count++;
        return 1;
    case 0x04008024u: /* 86 23 STX $23 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x8026u;
        instance->instruction_count++;
        return 1;
    case 0x04008026u: /* 85 25 STA $25 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x25u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8028u;
        instance->instruction_count++;
        return 1;
    case 0x04008028u: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x802Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400802Bu: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x802Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400802Cu: /* 20 8E EA JSR $EA8E */
        if (!tg_push16(instance, 0x802Eu)) return 0;
        instance->cpu.pc = 0xEA8Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400802Fu: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8030u;
        instance->instruction_count++;
        return 1;
    case 0x04008030u: /* B0 0C BCS $00:803E */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x803Eu : 0x8032u;
        instance->instruction_count++;
        return 1;
    case 0x04008032u: /* 9F 00 20 7E STA $7E2000,X */
        if (!tg_bus_write8(instance, ((0x7E2000u + instance->cpu.x) & 0xFFFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8036u;
        instance->instruction_count++;
        return 1;
    case 0x04008036u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8037u;
        instance->instruction_count++;
        return 1;
    case 0x04008037u: /* DA PHX */
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x8038u;
        instance->instruction_count++;
        return 1;
    case 0x04008038u: /* 20 9B EA JSR $EA9B */
        if (!tg_push16(instance, 0x803Au)) return 0;
        instance->cpu.pc = 0xEA9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400803Bu: /* FA PLX */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x803Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400803Cu: /* 90 F4 BCC $00:8032 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x8032u : 0x803Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400803Eu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8040u;
        instance->instruction_count++;
        return 1;
    case 0x04008040u: /* 85 3A STA $3A */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Au) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8042u;
        instance->instruction_count++;
        return 1;
    case 0x04008042u: /* A9 20 LDA #$20 */
        byte = 0x20u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8044u;
        instance->instruction_count++;
        return 1;
    case 0x04008044u: /* 85 3B STA $3B */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Bu) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8046u;
        instance->instruction_count++;
        return 1;
    case 0x04008046u: /* A9 7E LDA #$7E */
        byte = 0x7Eu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8048u;
        instance->instruction_count++;
        return 1;
    case 0x04008048u: /* 85 3C STA $3C */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Cu) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x804Au;
        instance->instruction_count++;
        return 1;
    case 0x0400804Au: /* 20 B6 EB JSR $EBB6 */
        if (!tg_push16(instance, 0x804Cu)) return 0;
        instance->cpu.pc = 0xEBB6u;
        instance->instruction_count++;
        return 1;
    case 0x0000804Du: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x804Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400804Fu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8051u;
        instance->instruction_count++;
        return 1;
    case 0x04008051u: /* 8D 40 21 STA $2140 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8054u;
        instance->instruction_count++;
        return 1;
    case 0x04008054u: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8057u;
        instance->instruction_count++;
        return 1;
    case 0x04008057u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8058u;
        instance->instruction_count++;
        return 1;
    case 0x04008058u: /* D0 FD BNE $00:8057 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8057u : 0x805Au;
        instance->instruction_count++;
        return 1;
    case 0x0400805Au: /* A9 18 LDA #$18 */
        byte = 0x18u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x805Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400805Cu: /* 8D 41 21 STA $2141 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x805Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400805Fu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8061u;
        instance->instruction_count++;
        return 1;
    case 0x00008061u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8064u;
        instance->instruction_count++;
        return 1;
    case 0x00008064u: /* 22 00 80 07 JSL $078000 */
        if (!tg_push8(instance, instance->cpu.pbr)) return 0;
        if (!tg_push16(instance, 0x8067u)) return 0;
        instance->cpu.pbr = 0x07u;
        instance->cpu.pc = 0x8000u;
        instance->instruction_count++;
        return 1;
    case 0x00008068u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x806Au;
        instance->instruction_count++;
        return 1;
    case 0x0400806Au: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x806Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400806Cu: /* 8D 40 21 STA $2140 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x806Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400806Fu: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8072u;
        instance->instruction_count++;
        return 1;
    case 0x04008072u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8073u;
        instance->instruction_count++;
        return 1;
    case 0x04008073u: /* D0 FD BNE $00:8072 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8072u : 0x8075u;
        instance->instruction_count++;
        return 1;
    case 0x04008075u: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8077u;
        instance->instruction_count++;
        return 1;
    case 0x04008077u: /* 8D 40 21 STA $2140 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x807Au;
        instance->instruction_count++;
        return 1;
    case 0x0400807Au: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x807Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000807Cu: /* AD 08 1F LDA $1F08 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F08u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x807Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000807Fu: /* 29 1C 00 AND #$001C */
        word = 0x001Cu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8082u;
        instance->instruction_count++;
        return 1;
    case 0x00008082u: /* 8D 06 1F STA $1F06 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8085u;
        instance->instruction_count++;
        return 1;
    case 0x00008085u: /* AD F6 1F LDA $1FF6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF6u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8088u;
        instance->instruction_count++;
        return 1;
    case 0x00008088u: /* F0 1C BEQ $00:80A6 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x80A6u : 0x808Au;
        instance->instruction_count++;
        return 1;
    case 0x0000808Au: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x808Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400808Cu: /* 9C 90 1F STZ $1F90 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F90u), 0u)) return 0;
        instance->cpu.pc = 0x808Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400808Fu: /* 9C AD 1F STZ $1FAD */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FADu), 0u)) return 0;
        instance->cpu.pc = 0x8092u;
        instance->instruction_count++;
        return 1;
    case 0x04008092u: /* AD 3C 01 LDA $013C */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x013Cu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8095u;
        instance->instruction_count++;
        return 1;
    case 0x04008095u: /* 29 03 AND #$03 */
        byte = 0x03u;
        byte = (uint8_t)((tg_acc8(instance)) & byte);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8097u;
        instance->instruction_count++;
        return 1;
    case 0x04008097u: /* 8D 8F 1F STA $1F8F */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x809Au;
        instance->instruction_count++;
        return 1;
    case 0x0400809Au: /* AD 3C 01 LDA $013C */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x013Cu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x809Du;
        instance->instruction_count++;
        return 1;
    case 0x0400809Du: /* 4A LSR A */
        byte = tg_acc8(instance);
        tg_set_flag(instance, TG_P_C, (byte & 1u) != 0u);
        byte = (uint8_t)(byte >> 1);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x809Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400809Eu: /* 4A LSR A */
        byte = tg_acc8(instance);
        tg_set_flag(instance, TG_P_C, (byte & 1u) != 0u);
        byte = (uint8_t)(byte >> 1);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x809Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400809Fu: /* 29 03 AND #$03 */
        byte = 0x03u;
        byte = (uint8_t)((tg_acc8(instance)) & byte);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x80A1u;
        instance->instruction_count++;
        return 1;
    case 0x040080A1u: /* 8D AC 1F STA $1FAC */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FACu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x80A4u;
        instance->instruction_count++;
        return 1;
    case 0x040080A4u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x80A6u;
        instance->instruction_count++;
        return 1;
    case 0x000080A6u: /* A2 FE 1E LDX #$1EFE */
        word = 0x1EFEu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80A9u;
        instance->instruction_count++;
        return 1;
    case 0x000080A9u: /* 74 00 STZ $00,X */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x00u + instance->cpu.x) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x80ABu;
        instance->instruction_count++;
        return 1;
    case 0x000080ABu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80ACu;
        instance->instruction_count++;
        return 1;
    case 0x000080ACu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80ADu;
        instance->instruction_count++;
        return 1;
    case 0x000080ADu: /* 10 FA BPL $00:80A9 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x80A9u : 0x80AFu;
        instance->instruction_count++;
        return 1;
    case 0x000080AFu: /* A2 12 00 LDX #$0012 */
        word = 0x0012u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80B2u;
        instance->instruction_count++;
        return 1;
    case 0x000080B2u: /* 9E 4E 1F STZ $1F4E,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F4Eu + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x80B5u;
        instance->instruction_count++;
        return 1;
    case 0x000080B5u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80B6u;
        instance->instruction_count++;
        return 1;
    case 0x000080B6u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80B7u;
        instance->instruction_count++;
        return 1;
    case 0x000080B7u: /* 10 F9 BPL $00:80B2 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x80B2u : 0x80B9u;
        instance->instruction_count++;
        return 1;
    case 0x000080B9u: /* A2 08 00 LDX #$0008 */
        word = 0x0008u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80BCu;
        instance->instruction_count++;
        return 1;
    case 0x000080BCu: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80BFu;
        instance->instruction_count++;
        return 1;
    case 0x000080BFu: /* B9 86 1F LDA $1F86,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F86u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80C2u;
        instance->instruction_count++;
        return 1;
    case 0x000080C2u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80C5u;
        instance->instruction_count++;
        return 1;
    case 0x000080C5u: /* C9 20 00 CMP #$0020 */
        word = 0x0020u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x80C8u;
        instance->instruction_count++;
        return 1;
    case 0x000080C8u: /* F0 14 BEQ $00:80DE */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x80DEu : 0x80CAu;
        instance->instruction_count++;
        return 1;
    case 0x000080CAu: /* C9 31 00 CMP #$0031 */
        word = 0x0031u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x80CDu;
        instance->instruction_count++;
        return 1;
    case 0x000080CDu: /* F0 0F BEQ $00:80DE */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x80DEu : 0x80CFu;
        instance->instruction_count++;
        return 1;
    case 0x000080CFu: /* C9 32 00 CMP #$0032 */
        word = 0x0032u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x80D2u;
        instance->instruction_count++;
        return 1;
    case 0x000080D2u: /* F0 0A BEQ $00:80DE */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x80DEu : 0x80D4u;
        instance->instruction_count++;
        return 1;
    case 0x000080D4u: /* C9 41 00 CMP #$0041 */
        word = 0x0041u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x80D7u;
        instance->instruction_count++;
        return 1;
    case 0x000080D7u: /* 90 34 BCC $00:810D */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x810Du : 0x80D9u;
        instance->instruction_count++;
        return 1;
    case 0x000080D9u: /* C9 5B 00 CMP #$005B */
        word = 0x005Bu;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x80DCu;
        instance->instruction_count++;
        return 1;
    case 0x000080DCu: /* B0 2F BCS $00:810D */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x810Du : 0x80DEu;
        instance->instruction_count++;
        return 1;
    case 0x000080DEu: /* B9 A3 1F LDA $1FA3,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1FA3u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80E1u;
        instance->instruction_count++;
        return 1;
    case 0x000080E1u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80E4u;
        instance->instruction_count++;
        return 1;
    case 0x000080E4u: /* C9 20 00 CMP #$0020 */
        word = 0x0020u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x80E7u;
        instance->instruction_count++;
        return 1;
    case 0x000080E7u: /* F0 14 BEQ $00:80FD */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x80FDu : 0x80E9u;
        instance->instruction_count++;
        return 1;
    case 0x000080E9u: /* C9 31 00 CMP #$0031 */
        word = 0x0031u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x80ECu;
        instance->instruction_count++;
        return 1;
    case 0x000080ECu: /* F0 0F BEQ $00:80FD */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x80FDu : 0x80EEu;
        instance->instruction_count++;
        return 1;
    case 0x000080EEu: /* C9 32 00 CMP #$0032 */
        word = 0x0032u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x80F1u;
        instance->instruction_count++;
        return 1;
    case 0x000080F1u: /* F0 0A BEQ $00:80FD */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x80FDu : 0x80F3u;
        instance->instruction_count++;
        return 1;
    case 0x000080F3u: /* C9 41 00 CMP #$0041 */
        word = 0x0041u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x80F6u;
        instance->instruction_count++;
        return 1;
    case 0x000080F6u: /* 90 15 BCC $00:810D */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x810Du : 0x80F8u;
        instance->instruction_count++;
        return 1;
    case 0x000080F8u: /* C9 5B 00 CMP #$005B */
        word = 0x005Bu;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x80FBu;
        instance->instruction_count++;
        return 1;
    case 0x000080FBu: /* B0 10 BCS $00:810D */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x810Du : 0x80FDu;
        instance->instruction_count++;
        return 1;
    case 0x000080FDu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80FEu;
        instance->instruction_count++;
        return 1;
    case 0x000080FEu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x80FFu;
        instance->instruction_count++;
        return 1;
    case 0x000080FFu: /* D0 BE BNE $00:80BF */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x80BFu : 0x8101u;
        instance->instruction_count++;
        return 1;
    case 0x00008101u: /* AD 91 1F LDA $1F91 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F91u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8104u;
        instance->instruction_count++;
        return 1;
    case 0x00008104u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x8105u;
        instance->instruction_count++;
        return 1;
    case 0x00008105u: /* 6D AE 1F ADC $1FAE */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FAEu), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x8108u;
        instance->instruction_count++;
        return 1;
    case 0x00008108u: /* C9 43 75 CMP #$7543 */
        word = 0x7543u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x810Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000810Bu: /* F0 16 BEQ $00:8123 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x8123u : 0x810Du;
        instance->instruction_count++;
        return 1;
    case 0x0000810Du: /* A2 FE 00 LDX #$00FE */
        word = 0x00FEu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8110u;
        instance->instruction_count++;
        return 1;
    case 0x00008110u: /* 9E 00 1F STZ $1F00,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F00u + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x8113u;
        instance->instruction_count++;
        return 1;
    case 0x00008113u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8114u;
        instance->instruction_count++;
        return 1;
    case 0x00008114u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8115u;
        instance->instruction_count++;
        return 1;
    case 0x00008115u: /* 10 F9 BPL $00:8110 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8110u : 0x8117u;
        instance->instruction_count++;
        return 1;
    case 0x00008117u: /* A9 56 19 LDA #$1956 */
        word = 0x1956u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x811Au;
        instance->instruction_count++;
        return 1;
    case 0x0000811Au: /* 8D 91 1F STA $1F91 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F91u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x811Du;
        instance->instruction_count++;
        return 1;
    case 0x0000811Du: /* A9 ED 5B LDA #$5BED */
        word = 0x5BEDu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8120u;
        instance->instruction_count++;
        return 1;
    case 0x00008120u: /* 8D AE 1F STA $1FAE */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FAEu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8123u;
        instance->instruction_count++;
        return 1;
    case 0x00008123u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8126u;
        instance->instruction_count++;
        return 1;
    case 0x00008126u: /* 22 6D 80 0F JSL $0F806D */
        if (!tg_push8(instance, instance->cpu.pbr)) return 0;
        if (!tg_push16(instance, 0x8129u)) return 0;
        instance->cpu.pbr = 0x0Fu;
        instance->cpu.pc = 0x806Du;
        instance->instruction_count++;
        return 1;
    case 0x0000812Au: /* 4B PHK */
        if (!tg_push8(instance, instance->cpu.pbr)) return 0;
        instance->cpu.pc = 0x812Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000812Bu: /* AB PLB */
        if (!tg_pull8(instance, &byte)) return 0;
        instance->cpu.dbr = byte;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x812Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000812Cu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x812Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000812Eu: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8131u;
        instance->instruction_count++;
        return 1;
    case 0x00008131u: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8134u;
        instance->instruction_count++;
        return 1;
    case 0x00008134u: /* 95 00 STA $00,X */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x00u + instance->cpu.x) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8136u;
        instance->instruction_count++;
        return 1;
    case 0x00008136u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8137u;
        instance->instruction_count++;
        return 1;
    case 0x00008137u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8138u;
        instance->instruction_count++;
        return 1;
    case 0x00008138u: /* E0 00 1F CPX #$1F00 */
        word = 0x1F00u;
        tg_compare16(instance, (uint16_t)instance->cpu.x, word);
        instance->cpu.pc = 0x813Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000813Bu: /* D0 F7 BNE $00:8134 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8134u : 0x813Du;
        instance->instruction_count++;
        return 1;
    case 0x0000813Du: /* AD F6 1F LDA $1FF6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF6u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8140u;
        instance->instruction_count++;
        return 1;
    case 0x00008140u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8142u;
        instance->instruction_count++;
        return 1;
    case 0x04008142u: /* F0 31 BEQ $00:8175 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x8175u : 0x8144u;
        instance->instruction_count++;
        return 1;
    case 0x04008144u: /* AD 8F 1F LDA $1F8F */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Fu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8147u;
        instance->instruction_count++;
        return 1;
    case 0x04008147u: /* 29 03 AND #$03 */
        byte = 0x03u;
        byte = (uint8_t)((tg_acc8(instance)) & byte);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8149u;
        instance->instruction_count++;
        return 1;
    case 0x04008149u: /* 8D 3C 01 STA $013C */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x013Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x814Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400814Cu: /* AD AC 1F LDA $1FAC */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FACu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x814Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400814Fu: /* 29 03 AND #$03 */
        byte = 0x03u;
        byte = (uint8_t)((tg_acc8(instance)) & byte);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8151u;
        instance->instruction_count++;
        return 1;
    case 0x04008151u: /* 0A ASL A */
        byte = tg_acc8(instance);
        tg_set_flag(instance, TG_P_C, (byte & 0x80u) != 0u);
        byte = (uint8_t)(byte << 1);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8152u;
        instance->instruction_count++;
        return 1;
    case 0x04008152u: /* 0A ASL A */
        byte = tg_acc8(instance);
        tg_set_flag(instance, TG_P_C, (byte & 0x80u) != 0u);
        byte = (uint8_t)(byte << 1);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8153u;
        instance->instruction_count++;
        return 1;
    case 0x04008153u: /* 0D 3C 01 ORA $013C */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x013Cu), &byte)) return 0;
        byte = (uint8_t)((tg_acc8(instance)) | byte);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8156u;
        instance->instruction_count++;
        return 1;
    case 0x04008156u: /* 8D 3C 01 STA $013C */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x013Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8159u;
        instance->instruction_count++;
        return 1;
    case 0x04008159u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x815Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000815Bu: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x815Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000815Eu: /* 20 9E A8 JSR $A89E */
        if (!tg_push16(instance, 0x8160u)) return 0;
        instance->cpu.pc = 0xA89Eu;
        instance->instruction_count++;
        return 1;
    case 0x00008161u: /* 29 03 00 AND #$0003 */
        word = 0x0003u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8164u;
        instance->instruction_count++;
        return 1;
    case 0x00008164u: /* 8D 8F 1F STA $1F8F */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Fu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8167u;
        instance->instruction_count++;
        return 1;
    case 0x00008167u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x816Au;
        instance->instruction_count++;
        return 1;
    case 0x0000816Au: /* 20 9E A8 JSR $A89E */
        if (!tg_push16(instance, 0x816Cu)) return 0;
        instance->cpu.pc = 0xA89Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000816Du: /* 29 03 00 AND #$0003 */
        word = 0x0003u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8170u;
        instance->instruction_count++;
        return 1;
    case 0x00008170u: /* 8D AC 1F STA $1FAC */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FACu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8173u;
        instance->instruction_count++;
        return 1;
    case 0x00008173u: /* 80 43 BRA $00:81B8 */
        instance->cpu.pc = 0x81B8u;
        instance->instruction_count++;
        return 1;
    case 0x04008175u: /* A9 18 LDA #$18 */
        byte = 0x18u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8177u;
        instance->instruction_count++;
        return 1;
    case 0x04008177u: /* 8D 41 21 STA $2141 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x817Au;
        instance->instruction_count++;
        return 1;
    case 0x0400817Au: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x817Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000817Cu: /* AD 06 1F LDA $1F06 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x817Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000817Fu: /* 29 03 00 AND #$0003 */
        word = 0x0003u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8182u;
        instance->instruction_count++;
        return 1;
    case 0x00008182u: /* 49 03 00 EOR #$0003 */
        word = 0x0003u;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8185u;
        instance->instruction_count++;
        return 1;
    case 0x00008185u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8186u;
        instance->instruction_count++;
        return 1;
    case 0x00008186u: /* 22 00 80 07 JSL $078000 */
        if (!tg_push8(instance, instance->cpu.pbr)) return 0;
        if (!tg_push16(instance, 0x8189u)) return 0;
        instance->cpu.pbr = 0x07u;
        instance->cpu.pc = 0x8000u;
        instance->instruction_count++;
        return 1;
    case 0x0000818Au: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x818Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400818Cu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x818Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400818Eu: /* 8D 40 21 STA $2140 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8191u;
        instance->instruction_count++;
        return 1;
    case 0x04008191u: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8194u;
        instance->instruction_count++;
        return 1;
    case 0x04008194u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8195u;
        instance->instruction_count++;
        return 1;
    case 0x04008195u: /* D0 FD BNE $00:8194 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8194u : 0x8197u;
        instance->instruction_count++;
        return 1;
    case 0x04008197u: /* AD 06 1F LDA $1F06 */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x819Au;
        instance->instruction_count++;
        return 1;
    case 0x0400819Au: /* 29 03 AND #$03 */
        byte = 0x03u;
        byte = (uint8_t)((tg_acc8(instance)) & byte);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x819Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400819Cu: /* 49 03 EOR #$03 */
        byte = 0x03u;
        byte = (uint8_t)((tg_acc8(instance)) ^ byte);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x819Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400819Eu: /* 1A INC A */
        byte = (uint8_t)((tg_acc8(instance)) + 1u);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x819Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400819Fu: /* 1A INC A */
        byte = (uint8_t)((tg_acc8(instance)) + 1u);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x81A0u;
        instance->instruction_count++;
        return 1;
    case 0x040081A0u: /* 8D 40 21 STA $2140 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2140u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x81A3u;
        instance->instruction_count++;
        return 1;
    case 0x040081A3u: /* A2 00 00 LDX #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81A6u;
        instance->instruction_count++;
        return 1;
    case 0x040081A6u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81A7u;
        instance->instruction_count++;
        return 1;
    case 0x040081A7u: /* D0 FD BNE $00:81A6 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x81A6u : 0x81A9u;
        instance->instruction_count++;
        return 1;
    case 0x040081A9u: /* A9 02 LDA #$02 */
        byte = 0x02u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x81ABu;
        instance->instruction_count++;
        return 1;
    case 0x040081ABu: /* 8D 41 21 STA $2141 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x81AEu;
        instance->instruction_count++;
        return 1;
    case 0x040081AEu: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81AFu;
        instance->instruction_count++;
        return 1;
    case 0x040081AFu: /* D0 FD BNE $00:81AE */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x81AEu : 0x81B1u;
        instance->instruction_count++;
        return 1;
    case 0x040081B1u: /* A9 0D LDA #$0D */
        byte = 0x0Du;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x81B3u;
        instance->instruction_count++;
        return 1;
    case 0x040081B3u: /* 8D 41 21 STA $2141 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x81B6u;
        instance->instruction_count++;
        return 1;
    case 0x040081B6u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x81B8u;
        instance->instruction_count++;
        return 1;
    case 0x000081B8u: /* A9 5C 00 LDA #$005C */
        word = 0x005Cu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81BBu;
        instance->instruction_count++;
        return 1;
    case 0x000081BBu: /* 85 00 STA $00 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x00u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81BDu;
        instance->instruction_count++;
        return 1;
    case 0x000081BDu: /* 85 04 STA $04 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x04u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81BFu;
        instance->instruction_count++;
        return 1;
    case 0x000081BFu: /* A9 1A EC LDA #$EC1A */
        word = 0xEC1Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81C2u;
        instance->instruction_count++;
        return 1;
    case 0x000081C2u: /* 85 01 STA $01 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x01u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81C4u;
        instance->instruction_count++;
        return 1;
    case 0x000081C4u: /* A9 5B EC LDA #$EC5B */
        word = 0xEC5Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81C7u;
        instance->instruction_count++;
        return 1;
    case 0x000081C7u: /* 85 05 STA $05 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x05u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81C9u;
        instance->instruction_count++;
        return 1;
    case 0x000081C9u: /* A9 7E EC LDA #$EC7E */
        word = 0xEC7Eu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81CCu;
        instance->instruction_count++;
        return 1;
    case 0x000081CCu: /* 85 08 STA $08 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x08u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81CEu;
        instance->instruction_count++;
        return 1;
    case 0x000081CEu: /* 85 0A STA $0A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81D0u;
        instance->instruction_count++;
        return 1;
    case 0x000081D0u: /* A9 02 02 LDA #$0202 */
        word = 0x0202u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81D3u;
        instance->instruction_count++;
        return 1;
    case 0x000081D3u: /* 85 18 STA $18 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x18u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81D5u;
        instance->instruction_count++;
        return 1;
    case 0x000081D5u: /* A9 33 0D LDA #$0D33 */
        word = 0x0D33u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81D8u;
        instance->instruction_count++;
        return 1;
    case 0x000081D8u: /* 85 A0 STA $A0 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xA0u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81DAu;
        instance->instruction_count++;
        return 1;
    case 0x000081DAu: /* A9 62 B4 LDA #$B462 */
        word = 0xB462u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81DDu;
        instance->instruction_count++;
        return 1;
    case 0x000081DDu: /* 85 A2 STA $A2 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xA2u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81DFu;
        instance->instruction_count++;
        return 1;
    case 0x000081DFu: /* A9 20 00 LDA #$0020 */
        word = 0x0020u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81E2u;
        instance->instruction_count++;
        return 1;
    case 0x000081E2u: /* 85 A4 STA $A4 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xA4u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81E4u;
        instance->instruction_count++;
        return 1;
    case 0x000081E4u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81E7u;
        instance->instruction_count++;
        return 1;
    case 0x000081E7u: /* 85 A8 STA $A8 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xA8u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81E9u;
        instance->instruction_count++;
        return 1;
    case 0x000081E9u: /* A9 63 03 LDA #$0363 */
        word = 0x0363u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81ECu;
        instance->instruction_count++;
        return 1;
    case 0x000081ECu: /* 85 AA STA $AA */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xAAu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81EEu;
        instance->instruction_count++;
        return 1;
    case 0x000081EEu: /* A9 62 B4 LDA #$B462 */
        word = 0xB462u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81F1u;
        instance->instruction_count++;
        return 1;
    case 0x000081F1u: /* 85 AC STA $AC */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xACu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81F3u;
        instance->instruction_count++;
        return 1;
    case 0x000081F3u: /* A9 20 00 LDA #$0020 */
        word = 0x0020u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81F6u;
        instance->instruction_count++;
        return 1;
    case 0x000081F6u: /* 85 AE STA $AE */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xAEu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81F8u;
        instance->instruction_count++;
        return 1;
    case 0x000081F8u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x81FBu;
        instance->instruction_count++;
        return 1;
    case 0x000081FBu: /* 85 B0 STA $B0 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xB0u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x81FDu;
        instance->instruction_count++;
        return 1;
    case 0x000081FDu: /* A9 63 03 LDA #$0363 */
        word = 0x0363u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8200u;
        instance->instruction_count++;
        return 1;
    case 0x00008200u: /* 85 B2 STA $B2 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xB2u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8202u;
        instance->instruction_count++;
        return 1;
    case 0x00008202u: /* A9 33 0D LDA #$0D33 */
        word = 0x0D33u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8205u;
        instance->instruction_count++;
        return 1;
    case 0x00008205u: /* 85 B4 STA $B4 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xB4u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8207u;
        instance->instruction_count++;
        return 1;
    case 0x00008207u: /* A9 7B B5 LDA #$B57B */
        word = 0xB57Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x820Au;
        instance->instruction_count++;
        return 1;
    case 0x0000820Au: /* 85 B6 STA $B6 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xB6u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x820Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000820Cu: /* A9 90 00 LDA #$0090 */
        word = 0x0090u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x820Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000820Fu: /* 85 B8 STA $B8 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xB8u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8211u;
        instance->instruction_count++;
        return 1;
    case 0x00008211u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8214u;
        instance->instruction_count++;
        return 1;
    case 0x00008214u: /* 85 BC STA $BC */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xBCu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8216u;
        instance->instruction_count++;
        return 1;
    case 0x00008216u: /* A9 F3 02 LDA #$02F3 */
        word = 0x02F3u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8219u;
        instance->instruction_count++;
        return 1;
    case 0x00008219u: /* 85 BE STA $BE */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xBEu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x821Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000821Bu: /* A9 7B B5 LDA #$B57B */
        word = 0xB57Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x821Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000821Eu: /* 85 C0 STA $C0 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xC0u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8220u;
        instance->instruction_count++;
        return 1;
    case 0x00008220u: /* A9 90 00 LDA #$0090 */
        word = 0x0090u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8223u;
        instance->instruction_count++;
        return 1;
    case 0x00008223u: /* 85 C2 STA $C2 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xC2u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8225u;
        instance->instruction_count++;
        return 1;
    case 0x00008225u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8228u;
        instance->instruction_count++;
        return 1;
    case 0x00008228u: /* 85 C4 STA $C4 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xC4u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x822Au;
        instance->instruction_count++;
        return 1;
    case 0x0000822Au: /* A9 F3 02 LDA #$02F3 */
        word = 0x02F3u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x822Du;
        instance->instruction_count++;
        return 1;
    case 0x0000822Du: /* 85 C6 STA $C6 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xC6u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x822Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000822Fu: /* A9 80 00 LDA #$0080 */
        word = 0x0080u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8232u;
        instance->instruction_count++;
        return 1;
    case 0x00008232u: /* 85 C8 STA $C8 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xC8u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8234u;
        instance->instruction_count++;
        return 1;
    case 0x00008234u: /* 85 CE STA $CE */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xCEu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8236u;
        instance->instruction_count++;
        return 1;
    case 0x00008236u: /* 85 D4 STA $D4 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xD4u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8238u;
        instance->instruction_count++;
        return 1;
    case 0x00008238u: /* 85 DA STA $DA */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xDAu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x823Au;
        instance->instruction_count++;
        return 1;
    case 0x0000823Au: /* A9 4A 13 LDA #$134A */
        word = 0x134Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x823Du;
        instance->instruction_count++;
        return 1;
    case 0x0000823Du: /* 85 CC STA $CC */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xCCu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x823Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000823Fu: /* A9 0A 0F LDA #$0F0A */
        word = 0x0F0Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8242u;
        instance->instruction_count++;
        return 1;
    case 0x00008242u: /* 85 D2 STA $D2 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xD2u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8244u;
        instance->instruction_count++;
        return 1;
    case 0x00008244u: /* A9 6A 15 LDA #$156A */
        word = 0x156Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8247u;
        instance->instruction_count++;
        return 1;
    case 0x00008247u: /* 85 D8 STA $D8 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xD8u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8249u;
        instance->instruction_count++;
        return 1;
    case 0x00008249u: /* A9 2A 11 LDA #$112A */
        word = 0x112Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x824Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000824Cu: /* 85 DE STA $DE */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xDEu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x824Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000824Eu: /* A9 D2 08 LDA #$08D2 */
        word = 0x08D2u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8251u;
        instance->instruction_count++;
        return 1;
    case 0x00008251u: /* 85 E7 STA $E7 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xE7u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8253u;
        instance->instruction_count++;
        return 1;
    case 0x00008253u: /* A9 33 0D LDA #$0D33 */
        word = 0x0D33u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8256u;
        instance->instruction_count++;
        return 1;
    case 0x00008256u: /* 85 E9 STA $E9 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xE9u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8258u;
        instance->instruction_count++;
        return 1;
    case 0x00008258u: /* A9 54 0E LDA #$0E54 */
        word = 0x0E54u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x825Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000825Bu: /* 85 EB STA $EB */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xEBu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x825Du;
        instance->instruction_count++;
        return 1;
    case 0x0000825Du: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8260u;
        instance->instruction_count++;
        return 1;
    case 0x00008260u: /* A9 7F 00 LDA #$007F */
        word = 0x007Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8263u;
        instance->instruction_count++;
        return 1;
    case 0x00008263u: /* 91 EB STA ($EB),Y */
        if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xEBu) : (uint16_t)(instance->cpu.d + 0xEBu)), &byte)) return 0;
        word = byte;
        if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xECu) : (uint16_t)(instance->cpu.d + 0xECu)), &byte)) return 0;
        word = (uint16_t)(word | ((uint16_t)byte << 8));
        address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
        if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8265u;
        instance->instruction_count++;
        return 1;
    case 0x00008265u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8266u;
        instance->instruction_count++;
        return 1;
    case 0x00008266u: /* A9 5A 94 LDA #$945A */
        word = 0x945Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8269u;
        instance->instruction_count++;
        return 1;
    case 0x00008269u: /* 91 EB STA ($EB),Y */
        if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xEBu) : (uint16_t)(instance->cpu.d + 0xEBu)), &byte)) return 0;
        word = byte;
        if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xECu) : (uint16_t)(instance->cpu.d + 0xECu)), &byte)) return 0;
        word = (uint16_t)(word | ((uint16_t)byte << 8));
        address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
        if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
        instance->cpu.pc = 0x826Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000826Bu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x826Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000826Cu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x826Du;
        instance->instruction_count++;
        return 1;
    case 0x0000826Du: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8270u;
        instance->instruction_count++;
        return 1;
    case 0x00008270u: /* 91 EB STA ($EB),Y */
        if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xEBu) : (uint16_t)(instance->cpu.d + 0xEBu)), &byte)) return 0;
        word = byte;
        if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xECu) : (uint16_t)(instance->cpu.d + 0xECu)), &byte)) return 0;
        word = (uint16_t)(word | ((uint16_t)byte << 8));
        address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
        if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8272u;
        instance->instruction_count++;
        return 1;
    case 0x00008272u: /* A9 AF 0E LDA #$0EAF */
        word = 0x0EAFu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8275u;
        instance->instruction_count++;
        return 1;
    case 0x00008275u: /* 85 EB STA $EB */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xEBu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8277u;
        instance->instruction_count++;
        return 1;
    case 0x00008277u: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x827Au;
        instance->instruction_count++;
        return 1;
    case 0x0000827Au: /* A9 7F 00 LDA #$007F */
        word = 0x007Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x827Du;
        instance->instruction_count++;
        return 1;
    case 0x0000827Du: /* 91 EB STA ($EB),Y */
        if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xEBu) : (uint16_t)(instance->cpu.d + 0xEBu)), &byte)) return 0;
        word = byte;
        if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xECu) : (uint16_t)(instance->cpu.d + 0xECu)), &byte)) return 0;
        word = (uint16_t)(word | ((uint16_t)byte << 8));
        address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
        if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
        instance->cpu.pc = 0x827Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000827Fu: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8280u;
        instance->instruction_count++;
        return 1;
    case 0x00008280u: /* A9 5A 94 LDA #$945A */
        word = 0x945Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8283u;
        instance->instruction_count++;
        return 1;
    case 0x00008283u: /* 91 EB STA ($EB),Y */
        if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xEBu) : (uint16_t)(instance->cpu.d + 0xEBu)), &byte)) return 0;
        word = byte;
        if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xECu) : (uint16_t)(instance->cpu.d + 0xECu)), &byte)) return 0;
        word = (uint16_t)(word | ((uint16_t)byte << 8));
        address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
        if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8285u;
        instance->instruction_count++;
        return 1;
    case 0x00008285u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8286u;
        instance->instruction_count++;
        return 1;
    case 0x00008286u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8287u;
        instance->instruction_count++;
        return 1;
    case 0x00008287u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x828Au;
        instance->instruction_count++;
        return 1;
    case 0x0000828Au: /* 91 EB STA ($EB),Y */
        if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xEBu) : (uint16_t)(instance->cpu.d + 0xEBu)), &byte)) return 0;
        word = byte;
        if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xECu) : (uint16_t)(instance->cpu.d + 0xECu)), &byte)) return 0;
        word = (uint16_t)(word | ((uint16_t)byte << 8));
        address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
        if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
        instance->cpu.pc = 0x828Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000828Cu: /* A9 90 00 LDA #$0090 */
        word = 0x0090u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x828Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000828Fu: /* 8D 8A 17 STA $178A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x178Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8292u;
        instance->instruction_count++;
        return 1;
    case 0x00008292u: /* 8D DC 17 STA $17DC */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x17DCu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8295u;
        instance->instruction_count++;
        return 1;
    case 0x00008295u: /* A9 00 04 LDA #$0400 */
        word = 0x0400u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8298u;
        instance->instruction_count++;
        return 1;
    case 0x00008298u: /* 8D 8C 17 STA $178C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x178Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x829Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000829Bu: /* 8D DE 17 STA $17DE */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x17DEu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x829Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000829Eu: /* A9 00 02 LDA #$0200 */
        word = 0x0200u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82A1u;
        instance->instruction_count++;
        return 1;
    case 0x000082A1u: /* 8D 8E 17 STA $178E */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x178Eu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82A4u;
        instance->instruction_count++;
        return 1;
    case 0x000082A4u: /* 8D E0 17 STA $17E0 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x17E0u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82A7u;
        instance->instruction_count++;
        return 1;
    case 0x000082A7u: /* A9 00 04 LDA #$0400 */
        word = 0x0400u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82AAu;
        instance->instruction_count++;
        return 1;
    case 0x000082AAu: /* 8D 90 17 STA $1790 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1790u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82ADu;
        instance->instruction_count++;
        return 1;
    case 0x000082ADu: /* 8D E2 17 STA $17E2 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x17E2u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82B0u;
        instance->instruction_count++;
        return 1;
    case 0x000082B0u: /* A9 FF 7F LDA #$7FFF */
        word = 0x7FFFu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82B3u;
        instance->instruction_count++;
        return 1;
    case 0x000082B3u: /* 8D 92 17 STA $1792 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1792u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82B6u;
        instance->instruction_count++;
        return 1;
    case 0x000082B6u: /* 8D E4 17 STA $17E4 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x17E4u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82B9u;
        instance->instruction_count++;
        return 1;
    case 0x000082B9u: /* AD 8F 1F LDA $1F8F */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Fu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82BCu;
        instance->instruction_count++;
        return 1;
    case 0x000082BCu: /* 29 03 00 AND #$0003 */
        word = 0x0003u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82BFu;
        instance->instruction_count++;
        return 1;
    case 0x000082BFu: /* 8D 8F 1F STA $1F8F */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Fu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82C2u;
        instance->instruction_count++;
        return 1;
    case 0x000082C2u: /* AD AC 1F LDA $1FAC */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FACu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82C5u;
        instance->instruction_count++;
        return 1;
    case 0x000082C5u: /* 29 03 00 AND #$0003 */
        word = 0x0003u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82C8u;
        instance->instruction_count++;
        return 1;
    case 0x000082C8u: /* 8D AC 1F STA $1FAC */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FACu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82CBu;
        instance->instruction_count++;
        return 1;
    case 0x000082CBu: /* AD F8 1F LDA $1FF8 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF8u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82CEu;
        instance->instruction_count++;
        return 1;
    case 0x000082CEu: /* 29 03 00 AND #$0003 */
        word = 0x0003u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82D1u;
        instance->instruction_count++;
        return 1;
    case 0x000082D1u: /* 8D F8 1F STA $1FF8 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF8u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82D4u;
        instance->instruction_count++;
        return 1;
    case 0x000082D4u: /* A9 A6 A6 LDA #$A6A6 */
        word = 0xA6A6u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82D7u;
        instance->instruction_count++;
        return 1;
    case 0x000082D7u: /* 85 66 STA $66 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82D9u;
        instance->instruction_count++;
        return 1;
    case 0x000082D9u: /* A9 02 00 LDA #$0002 */
        word = 0x0002u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82DCu;
        instance->instruction_count++;
        return 1;
    case 0x000082DCu: /* 8D 06 01 STA $0106 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0106u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82DFu;
        instance->instruction_count++;
        return 1;
    case 0x000082DFu: /* A9 03 00 LDA #$0003 */
        word = 0x0003u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82E2u;
        instance->instruction_count++;
        return 1;
    case 0x000082E2u: /* 8D 6C 1E STA $1E6C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82E5u;
        instance->instruction_count++;
        return 1;
    case 0x000082E5u: /* 8D 6E 1E STA $1E6E */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Eu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82E8u;
        instance->instruction_count++;
        return 1;
    case 0x000082E8u: /* A9 1A 20 LDA #$201A */
        word = 0x201Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82EBu;
        instance->instruction_count++;
        return 1;
    case 0x000082EBu: /* 8D 12 01 STA $0112 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0112u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82EEu;
        instance->instruction_count++;
        return 1;
    case 0x000082EEu: /* 8D 14 01 STA $0114 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0114u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82F1u;
        instance->instruction_count++;
        return 1;
    case 0x000082F1u: /* A9 22 30 LDA #$3022 */
        word = 0x3022u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82F4u;
        instance->instruction_count++;
        return 1;
    case 0x000082F4u: /* 8D 16 01 STA $0116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82F7u;
        instance->instruction_count++;
        return 1;
    case 0x000082F7u: /* A9 03 00 LDA #$0003 */
        word = 0x0003u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x82FAu;
        instance->instruction_count++;
        return 1;
    case 0x000082FAu: /* 8D B4 1E STA $1EB4 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EB4u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x82FDu;
        instance->instruction_count++;
        return 1;
    case 0x000082FDu: /* A9 FF FF LDA #$FFFF */
        word = 0xFFFFu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8300u;
        instance->instruction_count++;
        return 1;
    case 0x00008300u: /* 8D 81 03 STA $0381 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0381u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8303u;
        instance->instruction_count++;
        return 1;
    case 0x00008303u: /* 8D 76 1E STA $1E76 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E76u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8306u;
        instance->instruction_count++;
        return 1;
    case 0x00008306u: /* 8D 78 1E STA $1E78 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E78u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8309u;
        instance->instruction_count++;
        return 1;
    case 0x00008309u: /* E2 30 SEP #$30 */
        instance->cpu.p |=0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x830Bu;
        instance->instruction_count++;
        return 1;
    case 0x0600830Bu: /* A9 80 LDA #$80 */
        byte = 0x80u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x830Du;
        instance->instruction_count++;
        return 1;
    case 0x0600830Du: /* 85 52 STA $52 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x52u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x830Fu;
        instance->instruction_count++;
        return 1;
    case 0x0600830Fu: /* 85 65 STA $65 */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x65u) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8311u;
        instance->instruction_count++;
        return 1;
    case 0x06008311u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8313u;
        instance->instruction_count++;
        return 1;
    case 0x06008313u: /* 85 3A STA $3A */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Au) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8315u;
        instance->instruction_count++;
        return 1;
    case 0x06008315u: /* A9 80 LDA #$80 */
        byte = 0x80u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8317u;
        instance->instruction_count++;
        return 1;
    case 0x06008317u: /* 85 3B STA $3B */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Bu) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8319u;
        instance->instruction_count++;
        return 1;
    case 0x06008319u: /* A9 07 LDA #$07 */
        byte = 0x07u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x831Bu;
        instance->instruction_count++;
        return 1;
    case 0x0600831Bu: /* 85 3C STA $3C */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Cu) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x831Du;
        instance->instruction_count++;
        return 1;
    case 0x0600831Du: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x831Fu;
        instance->instruction_count++;
        return 1;
    case 0x0600831Fu: /* 85 3E STA $3E */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Eu) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8321u;
        instance->instruction_count++;
        return 1;
    case 0x06008321u: /* 85 3F STA $3F */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Fu) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8323u;
        instance->instruction_count++;
        return 1;
    case 0x06008323u: /* A9 FF LDA #$FF */
        byte = 0xFFu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8325u;
        instance->instruction_count++;
        return 1;
    case 0x06008325u: /* 85 3D STA $3D */
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Du) & 0xFFFFu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8327u;
        instance->instruction_count++;
        return 1;
    case 0x06008327u: /* A9 8F LDA #$8F */
        byte = 0x8Fu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8329u;
        instance->instruction_count++;
        return 1;
    case 0x06008329u: /* 8D 00 21 STA $2100 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2100u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x832Cu;
        instance->instruction_count++;
        return 1;
    case 0x0600832Cu: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x832Eu;
        instance->instruction_count++;
        return 1;
    case 0x0600832Eu: /* 8D 01 21 STA $2101 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2101u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8331u;
        instance->instruction_count++;
        return 1;
    case 0x06008331u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8333u;
        instance->instruction_count++;
        return 1;
    case 0x06008333u: /* 8D 02 21 STA $2102 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2102u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8336u;
        instance->instruction_count++;
        return 1;
    case 0x06008336u: /* A9 80 LDA #$80 */
        byte = 0x80u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8338u;
        instance->instruction_count++;
        return 1;
    case 0x06008338u: /* 8D 03 21 STA $2103 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2103u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x833Bu;
        instance->instruction_count++;
        return 1;
    case 0x0600833Bu: /* A9 61 LDA #$61 */
        byte = 0x61u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x833Du;
        instance->instruction_count++;
        return 1;
    case 0x0600833Du: /* 8D 05 21 STA $2105 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2105u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8340u;
        instance->instruction_count++;
        return 1;
    case 0x06008340u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8342u;
        instance->instruction_count++;
        return 1;
    case 0x06008342u: /* 8D 06 21 STA $2106 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2106u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8345u;
        instance->instruction_count++;
        return 1;
    case 0x06008345u: /* A9 0C LDA #$0C */
        byte = 0x0Cu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8347u;
        instance->instruction_count++;
        return 1;
    case 0x06008347u: /* 8D 07 21 STA $2107 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2107u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x834Au;
        instance->instruction_count++;
        return 1;
    case 0x0600834Au: /* A9 13 LDA #$13 */
        byte = 0x13u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x834Cu;
        instance->instruction_count++;
        return 1;
    case 0x0600834Cu: /* 8D 08 21 STA $2108 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2108u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x834Fu;
        instance->instruction_count++;
        return 1;
    case 0x0600834Fu: /* A9 13 LDA #$13 */
        byte = 0x13u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8351u;
        instance->instruction_count++;
        return 1;
    case 0x06008351u: /* 8D 09 21 STA $2109 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2109u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8354u;
        instance->instruction_count++;
        return 1;
    case 0x06008354u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8356u;
        instance->instruction_count++;
        return 1;
    case 0x06008356u: /* 8D 0A 21 STA $210A */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Au), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8359u;
        instance->instruction_count++;
        return 1;
    case 0x06008359u: /* A9 50 LDA #$50 */
        byte = 0x50u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x835Bu;
        instance->instruction_count++;
        return 1;
    case 0x0600835Bu: /* 8D 0B 21 STA $210B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x835Eu;
        instance->instruction_count++;
        return 1;
    case 0x0600835Eu: /* A9 05 LDA #$05 */
        byte = 0x05u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8360u;
        instance->instruction_count++;
        return 1;
    case 0x06008360u: /* 8D 0C 21 STA $210C */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8363u;
        instance->instruction_count++;
        return 1;
    case 0x06008363u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8365u;
        instance->instruction_count++;
        return 1;
    case 0x06008365u: /* 8D 0D 21 STA $210D */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8368u;
        instance->instruction_count++;
        return 1;
    case 0x06008368u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x836Au;
        instance->instruction_count++;
        return 1;
    case 0x0600836Au: /* 8D 0D 21 STA $210D */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x836Du;
        instance->instruction_count++;
        return 1;
    case 0x0600836Du: /* A9 FF LDA #$FF */
        byte = 0xFFu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x836Fu;
        instance->instruction_count++;
        return 1;
    case 0x0600836Fu: /* 8D 0E 21 STA $210E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8372u;
        instance->instruction_count++;
        return 1;
    case 0x06008372u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8374u;
        instance->instruction_count++;
        return 1;
    case 0x06008374u: /* 8D 0E 21 STA $210E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8377u;
        instance->instruction_count++;
        return 1;
    case 0x06008377u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8379u;
        instance->instruction_count++;
        return 1;
    case 0x06008379u: /* 8D 0F 21 STA $210F */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x837Cu;
        instance->instruction_count++;
        return 1;
    case 0x0600837Cu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x837Eu;
        instance->instruction_count++;
        return 1;
    case 0x0600837Eu: /* 8D 0F 21 STA $210F */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8381u;
        instance->instruction_count++;
        return 1;
    case 0x06008381u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8383u;
        instance->instruction_count++;
        return 1;
    case 0x06008383u: /* 8D 10 21 STA $2110 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8386u;
        instance->instruction_count++;
        return 1;
    case 0x06008386u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8388u;
        instance->instruction_count++;
        return 1;
    case 0x06008388u: /* 8D 10 21 STA $2110 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x838Bu;
        instance->instruction_count++;
        return 1;
    case 0x0600838Bu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x838Du;
        instance->instruction_count++;
        return 1;
    case 0x0600838Du: /* 8D 11 21 STA $2111 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2111u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8390u;
        instance->instruction_count++;
        return 1;
    case 0x06008390u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8392u;
        instance->instruction_count++;
        return 1;
    case 0x06008392u: /* 8D 11 21 STA $2111 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2111u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8395u;
        instance->instruction_count++;
        return 1;
    case 0x06008395u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8397u;
        instance->instruction_count++;
        return 1;
    case 0x06008397u: /* 8D 12 21 STA $2112 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2112u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x839Au;
        instance->instruction_count++;
        return 1;
    case 0x0600839Au: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x839Cu;
        instance->instruction_count++;
        return 1;
    case 0x0600839Cu: /* 8D 12 21 STA $2112 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2112u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x839Fu;
        instance->instruction_count++;
        return 1;
    case 0x0600839Fu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83A1u;
        instance->instruction_count++;
        return 1;
    case 0x060083A1u: /* 8D 13 21 STA $2113 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2113u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83A4u;
        instance->instruction_count++;
        return 1;
    case 0x060083A4u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83A6u;
        instance->instruction_count++;
        return 1;
    case 0x060083A6u: /* 8D 13 21 STA $2113 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2113u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83A9u;
        instance->instruction_count++;
        return 1;
    case 0x060083A9u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83ABu;
        instance->instruction_count++;
        return 1;
    case 0x060083ABu: /* 8D 14 21 STA $2114 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2114u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83AEu;
        instance->instruction_count++;
        return 1;
    case 0x060083AEu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83B0u;
        instance->instruction_count++;
        return 1;
    case 0x060083B0u: /* 8D 14 21 STA $2114 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2114u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83B3u;
        instance->instruction_count++;
        return 1;
    case 0x060083B3u: /* A9 80 LDA #$80 */
        byte = 0x80u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83B5u;
        instance->instruction_count++;
        return 1;
    case 0x060083B5u: /* 8D 15 21 STA $2115 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2115u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83B8u;
        instance->instruction_count++;
        return 1;
    case 0x060083B8u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83BAu;
        instance->instruction_count++;
        return 1;
    case 0x060083BAu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83BDu;
        instance->instruction_count++;
        return 1;
    case 0x060083BDu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83BFu;
        instance->instruction_count++;
        return 1;
    case 0x060083BFu: /* 8D 17 21 STA $2117 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2117u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83C2u;
        instance->instruction_count++;
        return 1;
    case 0x060083C2u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83C4u;
        instance->instruction_count++;
        return 1;
    case 0x060083C4u: /* 8D 1A 21 STA $211A */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Au), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83C7u;
        instance->instruction_count++;
        return 1;
    case 0x060083C7u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83C9u;
        instance->instruction_count++;
        return 1;
    case 0x060083C9u: /* 8D 1B 21 STA $211B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83CCu;
        instance->instruction_count++;
        return 1;
    case 0x060083CCu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83CEu;
        instance->instruction_count++;
        return 1;
    case 0x060083CEu: /* 8D 1B 21 STA $211B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83D1u;
        instance->instruction_count++;
        return 1;
    case 0x060083D1u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83D3u;
        instance->instruction_count++;
        return 1;
    case 0x060083D3u: /* 8D 1C 21 STA $211C */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83D6u;
        instance->instruction_count++;
        return 1;
    case 0x060083D6u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83D8u;
        instance->instruction_count++;
        return 1;
    case 0x060083D8u: /* 8D 1C 21 STA $211C */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83DBu;
        instance->instruction_count++;
        return 1;
    case 0x060083DBu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83DDu;
        instance->instruction_count++;
        return 1;
    case 0x060083DDu: /* 8D 1D 21 STA $211D */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83E0u;
        instance->instruction_count++;
        return 1;
    case 0x060083E0u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83E2u;
        instance->instruction_count++;
        return 1;
    case 0x060083E2u: /* 8D 1D 21 STA $211D */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83E5u;
        instance->instruction_count++;
        return 1;
    case 0x060083E5u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83E7u;
        instance->instruction_count++;
        return 1;
    case 0x060083E7u: /* 8D 1E 21 STA $211E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83EAu;
        instance->instruction_count++;
        return 1;
    case 0x060083EAu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83ECu;
        instance->instruction_count++;
        return 1;
    case 0x060083ECu: /* 8D 1E 21 STA $211E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83EFu;
        instance->instruction_count++;
        return 1;
    case 0x060083EFu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83F1u;
        instance->instruction_count++;
        return 1;
    case 0x060083F1u: /* 8D 1F 21 STA $211F */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83F4u;
        instance->instruction_count++;
        return 1;
    case 0x060083F4u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83F6u;
        instance->instruction_count++;
        return 1;
    case 0x060083F6u: /* 8D 1F 21 STA $211F */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x211Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83F9u;
        instance->instruction_count++;
        return 1;
    case 0x060083F9u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x83FBu;
        instance->instruction_count++;
        return 1;
    case 0x060083FBu: /* 8D 20 21 STA $2120 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2120u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x83FEu;
        instance->instruction_count++;
        return 1;
    case 0x060083FEu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8400u;
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
