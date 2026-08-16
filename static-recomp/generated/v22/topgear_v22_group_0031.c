/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_0031(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x0000C400u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC401u;
        instance->instruction_count++;
        return 1;
    case 0x0000C401u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC402u;
        instance->instruction_count++;
        return 1;
    case 0x0000C402u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC403u;
        instance->instruction_count++;
        return 1;
    case 0x0000C403u: /* BD 72 C5 LDA $C572,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC572u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC406u;
        instance->instruction_count++;
        return 1;
    case 0x0000C406u: /* 8D 83 01 STA $0183 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0183u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC409u;
        instance->instruction_count++;
        return 1;
    case 0x0000C409u: /* BD 74 C5 LDA $C574,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC574u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC40Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C40Cu: /* 8D 85 01 STA $0185 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0185u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC40Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C40Fu: /* BD 92 C5 LDA $C592,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC592u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC412u;
        instance->instruction_count++;
        return 1;
    case 0x0000C412u: /* 8D 47 01 STA $0147 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0147u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC415u;
        instance->instruction_count++;
        return 1;
    case 0x0000C415u: /* BD 94 C5 LDA $C594,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC594u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC418u;
        instance->instruction_count++;
        return 1;
    case 0x0000C418u: /* 8D 49 01 STA $0149 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0149u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC41Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C41Bu: /* BD 52 C5 LDA $C552,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC552u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC41Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C41Eu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xC41Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C41Fu: /* BD 54 C5 LDA $C554,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC554u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC422u;
        instance->instruction_count++;
        return 1;
    case 0x0000C422u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC423u;
        instance->instruction_count++;
        return 1;
    case 0x0000C423u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC425u;
        instance->instruction_count++;
        return 1;
    case 0x0400C425u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC427u;
        instance->instruction_count++;
        return 1;
    case 0x0400C427u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC42Au;
        instance->instruction_count++;
        return 1;
    case 0x0400C42Au: /* A9 03 LDA #$03 */
        byte = 0x03u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC42Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400C42Cu: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC42Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400C42Fu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC431u;
        instance->instruction_count++;
        return 1;
    case 0x0000C431u: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC434u;
        instance->instruction_count++;
        return 1;
    case 0x0000C434u: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC437u;
        instance->instruction_count++;
        return 1;
    case 0x0000C437u: /* 98 TYA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.y);
        tg_set_nz16(instance, (uint16_t)instance->cpu.a);
        instance->cpu.pc = 0xC438u;
        instance->instruction_count++;
        return 1;
    case 0x0000C438u: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC43Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C43Bu: /* A9 00 02 LDA #$0200 */
        word = 0x0200u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC43Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C43Eu: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC441u;
        instance->instruction_count++;
        return 1;
    case 0x0000C441u: /* A9 00 13 LDA #$1300 */
        word = 0x1300u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC444u;
        instance->instruction_count++;
        return 1;
    case 0x0000C444u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC447u;
        instance->instruction_count++;
        return 1;
    case 0x0000C447u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC449u;
        instance->instruction_count++;
        return 1;
    case 0x0400C449u: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC44Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400C44Bu: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC44Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400C44Eu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC450u;
        instance->instruction_count++;
        return 1;
    case 0x0400C450u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC453u;
        instance->instruction_count++;
        return 1;
    case 0x0400C453u: /* A9 03 LDA #$03 */
        byte = 0x03u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC455u;
        instance->instruction_count++;
        return 1;
    case 0x0400C455u: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC458u;
        instance->instruction_count++;
        return 1;
    case 0x0400C458u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC45Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C45Au: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC45Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C45Du: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC460u;
        instance->instruction_count++;
        return 1;
    case 0x0000C460u: /* 98 TYA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.y);
        tg_set_nz16(instance, (uint16_t)instance->cpu.a);
        instance->cpu.pc = 0xC461u;
        instance->instruction_count++;
        return 1;
    case 0x0000C461u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xC462u;
        instance->instruction_count++;
        return 1;
    case 0x0000C462u: /* 69 00 02 ADC #$0200 */
        word = 0x0200u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xC465u;
        instance->instruction_count++;
        return 1;
    case 0x0000C465u: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC468u;
        instance->instruction_count++;
        return 1;
    case 0x0000C468u: /* A9 00 01 LDA #$0100 */
        word = 0x0100u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC46Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C46Bu: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC46Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C46Eu: /* A9 00 18 LDA #$1800 */
        word = 0x1800u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC471u;
        instance->instruction_count++;
        return 1;
    case 0x0000C471u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC474u;
        instance->instruction_count++;
        return 1;
    case 0x0000C474u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC476u;
        instance->instruction_count++;
        return 1;
    case 0x0400C476u: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC478u;
        instance->instruction_count++;
        return 1;
    case 0x0400C478u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC47Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400C47Bu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC47Du;
        instance->instruction_count++;
        return 1;
    case 0x0400C47Du: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC480u;
        instance->instruction_count++;
        return 1;
    case 0x0400C480u: /* A9 03 LDA #$03 */
        byte = 0x03u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC482u;
        instance->instruction_count++;
        return 1;
    case 0x0400C482u: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC485u;
        instance->instruction_count++;
        return 1;
    case 0x0400C485u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC487u;
        instance->instruction_count++;
        return 1;
    case 0x0000C487u: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC48Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C48Au: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC48Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C48Du: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC48Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C48Eu: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC491u;
        instance->instruction_count++;
        return 1;
    case 0x0000C491u: /* A9 00 02 LDA #$0200 */
        word = 0x0200u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC494u;
        instance->instruction_count++;
        return 1;
    case 0x0000C494u: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC497u;
        instance->instruction_count++;
        return 1;
    case 0x0000C497u: /* A9 00 17 LDA #$1700 */
        word = 0x1700u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC49Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C49Au: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC49Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C49Du: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC49Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400C49Fu: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC4A1u;
        instance->instruction_count++;
        return 1;
    case 0x0400C4A1u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC4A4u;
        instance->instruction_count++;
        return 1;
    case 0x0400C4A4u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC4A6u;
        instance->instruction_count++;
        return 1;
    case 0x0400C4A6u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC4A9u;
        instance->instruction_count++;
        return 1;
    case 0x0400C4A9u: /* A9 03 LDA #$03 */
        byte = 0x03u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC4ABu;
        instance->instruction_count++;
        return 1;
    case 0x0400C4ABu: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC4AEu;
        instance->instruction_count++;
        return 1;
    case 0x0400C4AEu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC4B0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4B0u: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC4B3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4B3u: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC4B6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4B6u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC4B7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4B7u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xC4B8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4B8u: /* 69 00 02 ADC #$0200 */
        word = 0x0200u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xC4BBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C4BBu: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC4BEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C4BEu: /* A9 00 01 LDA #$0100 */
        word = 0x0100u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC4C1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4C1u: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC4C4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4C4u: /* A9 00 1C LDA #$1C00 */
        word = 0x1C00u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC4C7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4C7u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC4CAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C4CAu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC4CCu;
        instance->instruction_count++;
        return 1;
    case 0x0400C4CCu: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC4CEu;
        instance->instruction_count++;
        return 1;
    case 0x0400C4CEu: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC4D1u;
        instance->instruction_count++;
        return 1;
    case 0x0400C4D1u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC4D3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4D3u: /* A5 1A LDA $1A */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x1Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC4D5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4D5u: /* 29 00 0E AND #$0E00 */
        word = 0x0E00u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC4D8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4D8u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC4D9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4D9u: /* EB XBA */
        word = instance->cpu.a;
        instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
        tg_set_nz8(instance, (uint8_t)instance->cpu.a);
        instance->cpu.pc = 0xC4DAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C4DAu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC4DBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C4DBu: /* BD 72 C5 LDA $C572,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC572u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC4DEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C4DEu: /* 8D 87 01 STA $0187 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0187u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC4E1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4E1u: /* BD 74 C5 LDA $C574,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC574u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC4E4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4E4u: /* 8D 89 01 STA $0189 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0189u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC4E7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4E7u: /* BD 92 C5 LDA $C592,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC592u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC4EAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C4EAu: /* 8D 4B 01 STA $014B */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x014Bu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC4EDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C4EDu: /* BD 94 C5 LDA $C594,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC594u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC4F0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4F0u: /* 8D 4D 01 STA $014D */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x014Du), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC4F3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4F3u: /* BD 52 C5 LDA $C552,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC552u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC4F6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4F6u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xC4F7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C4F7u: /* BD 54 C5 LDA $C554,X */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xC554u + instance->cpu.x)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC4FAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C4FAu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC4FBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C4FBu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC4FDu;
        instance->instruction_count++;
        return 1;
    case 0x0400C4FDu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC4FFu;
        instance->instruction_count++;
        return 1;
    case 0x0400C4FFu: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC502u;
        instance->instruction_count++;
        return 1;
    case 0x0400C502u: /* A9 03 LDA #$03 */
        byte = 0x03u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC504u;
        instance->instruction_count++;
        return 1;
    case 0x0400C504u: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC507u;
        instance->instruction_count++;
        return 1;
    case 0x0400C507u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC509u;
        instance->instruction_count++;
        return 1;
    case 0x0000C509u: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC50Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C50Cu: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC50Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C50Fu: /* 98 TYA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.y);
        tg_set_nz16(instance, (uint16_t)instance->cpu.a);
        instance->cpu.pc = 0xC510u;
        instance->instruction_count++;
        return 1;
    case 0x0000C510u: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC513u;
        instance->instruction_count++;
        return 1;
    case 0x0000C513u: /* A9 00 03 LDA #$0300 */
        word = 0x0300u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC516u;
        instance->instruction_count++;
        return 1;
    case 0x0000C516u: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC519u;
        instance->instruction_count++;
        return 1;
    case 0x0000C519u: /* A9 80 18 LDA #$1880 */
        word = 0x1880u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC51Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C51Cu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC51Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C51Fu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC521u;
        instance->instruction_count++;
        return 1;
    case 0x0400C521u: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC523u;
        instance->instruction_count++;
        return 1;
    case 0x0400C523u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC526u;
        instance->instruction_count++;
        return 1;
    case 0x0400C526u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC528u;
        instance->instruction_count++;
        return 1;
    case 0x0400C528u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC52Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400C52Bu: /* A9 03 LDA #$03 */
        byte = 0x03u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC52Du;
        instance->instruction_count++;
        return 1;
    case 0x0400C52Du: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC530u;
        instance->instruction_count++;
        return 1;
    case 0x0400C530u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC532u;
        instance->instruction_count++;
        return 1;
    case 0x0000C532u: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC535u;
        instance->instruction_count++;
        return 1;
    case 0x0000C535u: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC538u;
        instance->instruction_count++;
        return 1;
    case 0x0000C538u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC539u;
        instance->instruction_count++;
        return 1;
    case 0x0000C539u: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC53Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C53Cu: /* A9 00 03 LDA #$0300 */
        word = 0x0300u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC53Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C53Fu: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC542u;
        instance->instruction_count++;
        return 1;
    case 0x0000C542u: /* A9 80 1C LDA #$1C80 */
        word = 0x1C80u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC545u;
        instance->instruction_count++;
        return 1;
    case 0x0000C545u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC548u;
        instance->instruction_count++;
        return 1;
    case 0x0000C548u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC54Au;
        instance->instruction_count++;
        return 1;
    case 0x0400C54Au: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC54Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400C54Cu: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC54Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400C54Fu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC551u;
        instance->instruction_count++;
        return 1;
    case 0x0000C551u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0000C5B2u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC5B4u;
        instance->instruction_count++;
        return 1;
    case 0x0400C5B4u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC5B6u;
        instance->instruction_count++;
        return 1;
    case 0x0400C5B6u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC5B9u;
        instance->instruction_count++;
        return 1;
    case 0x0400C5B9u: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC5BBu;
        instance->instruction_count++;
        return 1;
    case 0x0400C5BBu: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC5BEu;
        instance->instruction_count++;
        return 1;
    case 0x0400C5BEu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC5C0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C5C0u: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC5C3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C5C3u: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC5C6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C5C6u: /* A9 C5 F8 LDA #$F8C5 */
        word = 0xF8C5u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC5C9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C5C9u: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC5CCu;
        instance->instruction_count++;
        return 1;
    case 0x0000C5CCu: /* A9 A0 00 LDA #$00A0 */
        word = 0x00A0u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC5CFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C5CFu: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC5D2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C5D2u: /* A9 B0 27 LDA #$27B0 */
        word = 0x27B0u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC5D5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C5D5u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC5D8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C5D8u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC5DAu;
        instance->instruction_count++;
        return 1;
    case 0x0400C5DAu: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC5DCu;
        instance->instruction_count++;
        return 1;
    case 0x0400C5DCu: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC5DFu;
        instance->instruction_count++;
        return 1;
    case 0x0400C5DFu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC5E1u;
        instance->instruction_count++;
        return 1;
    case 0x0400C5E1u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC5E4u;
        instance->instruction_count++;
        return 1;
    case 0x0400C5E4u: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC5E6u;
        instance->instruction_count++;
        return 1;
    case 0x0400C5E6u: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC5E9u;
        instance->instruction_count++;
        return 1;
    case 0x0400C5E9u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC5EBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C5EBu: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC5EEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C5EEu: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC5F1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C5F1u: /* A9 65 F9 LDA #$F965 */
        word = 0xF965u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC5F4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C5F4u: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC5F7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C5F7u: /* A9 A0 00 LDA #$00A0 */
        word = 0x00A0u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC5FAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C5FAu: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC5FDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C5FDu: /* A9 B0 2F LDA #$2FB0 */
        word = 0x2FB0u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC600u;
        instance->instruction_count++;
        return 1;
    case 0x0000C600u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC603u;
        instance->instruction_count++;
        return 1;
    case 0x0000C603u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC605u;
        instance->instruction_count++;
        return 1;
    case 0x0400C605u: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC607u;
        instance->instruction_count++;
        return 1;
    case 0x0400C607u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC60Au;
        instance->instruction_count++;
        return 1;
    case 0x0400C60Au: /* C2 30 REP #$30 */
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC60Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C60Cu: /* AD 8F 1F LDA $1F8F */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Fu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC60Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C60Fu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xC610u;
        instance->instruction_count++;
        return 1;
    case 0x0000C610u: /* A9 00 80 LDA #$8000 */
        word = 0x8000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC613u;
        instance->instruction_count++;
        return 1;
    case 0x0000C613u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC614u;
        instance->instruction_count++;
        return 1;
    case 0x0000C614u: /* 30 07 BMI $00:C61D */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xC61Du : 0xC616u;
        instance->instruction_count++;
        return 1;
    case 0x0000C616u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xC617u;
        instance->instruction_count++;
        return 1;
    case 0x0000C617u: /* 69 60 0F ADC #$0F60 */
        word = 0x0F60u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xC61Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C61Au: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC61Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C61Bu: /* 10 F9 BPL $00:C616 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xC616u : 0xC61Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C61Du: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC61Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C61Eu: /* AD AC 1F LDA $1FAC */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FACu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC621u;
        instance->instruction_count++;
        return 1;
    case 0x0000C621u: /* CD 8F 1F CMP $1F8F */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Fu), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xC624u;
        instance->instruction_count++;
        return 1;
    case 0x0000C624u: /* D0 15 BNE $00:C63B */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC63Bu : 0xC626u;
        instance->instruction_count++;
        return 1;
    case 0x0000C626u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC629u;
        instance->instruction_count++;
        return 1;
    case 0x0000C629u: /* 8D 0A 1C STA $1C0A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1C0Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC62Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C62Cu: /* 8D 58 1D STA $1D58 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D58u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC62Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C62Fu: /* AD F8 1F LDA $1FF8 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF8u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC632u;
        instance->instruction_count++;
        return 1;
    case 0x0000C632u: /* CD 8F 1F CMP $1F8F */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Fu), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xC635u;
        instance->instruction_count++;
        return 1;
    case 0x0000C635u: /* D0 04 BNE $00:C63B */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC63Bu : 0xC637u;
        instance->instruction_count++;
        return 1;
    case 0x0000C637u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC638u;
        instance->instruction_count++;
        return 1;
    case 0x0000C638u: /* 29 03 00 AND #$0003 */
        word = 0x0003u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC63Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C63Bu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xC63Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C63Cu: /* A9 00 80 LDA #$8000 */
        word = 0x8000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC63Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C63Fu: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC640u;
        instance->instruction_count++;
        return 1;
    case 0x0000C640u: /* 30 07 BMI $00:C649 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xC649u : 0xC642u;
        instance->instruction_count++;
        return 1;
    case 0x0000C642u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xC643u;
        instance->instruction_count++;
        return 1;
    case 0x0000C643u: /* 69 60 0F ADC #$0F60 */
        word = 0x0F60u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xC646u;
        instance->instruction_count++;
        return 1;
    case 0x0000C646u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC647u;
        instance->instruction_count++;
        return 1;
    case 0x0000C647u: /* 10 F9 BPL $00:C642 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xC642u : 0xC649u;
        instance->instruction_count++;
        return 1;
    case 0x0000C649u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xC64Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C64Au: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC64Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400C64Cu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC64Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400C64Eu: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC651u;
        instance->instruction_count++;
        return 1;
    case 0x0400C651u: /* A9 04 LDA #$04 */
        byte = 0x04u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC653u;
        instance->instruction_count++;
        return 1;
    case 0x0400C653u: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC656u;
        instance->instruction_count++;
        return 1;
    case 0x0400C656u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC658u;
        instance->instruction_count++;
        return 1;
    case 0x0000C658u: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC65Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C65Bu: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC65Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C65Eu: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC65Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C65Fu: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC662u;
        instance->instruction_count++;
        return 1;
    case 0x0000C662u: /* A9 60 0F LDA #$0F60 */
        word = 0x0F60u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC665u;
        instance->instruction_count++;
        return 1;
    case 0x0000C665u: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC668u;
        instance->instruction_count++;
        return 1;
    case 0x0000C668u: /* A9 00 20 LDA #$2000 */
        word = 0x2000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC66Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C66Bu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC66Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C66Eu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC670u;
        instance->instruction_count++;
        return 1;
    case 0x0400C670u: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC672u;
        instance->instruction_count++;
        return 1;
    case 0x0400C672u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC675u;
        instance->instruction_count++;
        return 1;
    case 0x0400C675u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC677u;
        instance->instruction_count++;
        return 1;
    case 0x0400C677u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC67Au;
        instance->instruction_count++;
        return 1;
    case 0x0400C67Au: /* A9 04 LDA #$04 */
        byte = 0x04u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC67Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400C67Cu: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC67Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400C67Fu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC681u;
        instance->instruction_count++;
        return 1;
    case 0x0000C681u: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC684u;
        instance->instruction_count++;
        return 1;
    case 0x0000C684u: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC687u;
        instance->instruction_count++;
        return 1;
    case 0x0000C687u: /* 98 TYA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.y);
        tg_set_nz16(instance, (uint16_t)instance->cpu.a);
        instance->cpu.pc = 0xC688u;
        instance->instruction_count++;
        return 1;
    case 0x0000C688u: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC68Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C68Bu: /* A9 60 0F LDA #$0F60 */
        word = 0x0F60u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC68Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C68Eu: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC691u;
        instance->instruction_count++;
        return 1;
    case 0x0000C691u: /* A9 00 28 LDA #$2800 */
        word = 0x2800u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC694u;
        instance->instruction_count++;
        return 1;
    case 0x0000C694u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC697u;
        instance->instruction_count++;
        return 1;
    case 0x0000C697u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC699u;
        instance->instruction_count++;
        return 1;
    case 0x0400C699u: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC69Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400C69Bu: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC69Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400C69Eu: /* AC 8F 1F LDY $1F8F */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Fu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC6A1u;
        instance->instruction_count++;
        return 1;
    case 0x0400C6A1u: /* B9 DB 97 LDA $97DB,Y */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x97DBu + instance->cpu.y)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC6A4u;
        instance->instruction_count++;
        return 1;
    case 0x0400C6A4u: /* 8D FD 1E STA $1EFD */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EFDu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC6A7u;
        instance->instruction_count++;
        return 1;
    case 0x0400C6A7u: /* AC AC 1F LDY $1FAC */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FACu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC6AAu;
        instance->instruction_count++;
        return 1;
    case 0x0400C6AAu: /* AD 04 1F LDA $1F04 */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC6ADu;
        instance->instruction_count++;
        return 1;
    case 0x0400C6ADu: /* D0 03 BNE $00:C6B2 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC6B2u : 0xC6AFu;
        instance->instruction_count++;
        return 1;
    case 0x0400C6AFu: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC6B2u;
        instance->instruction_count++;
        return 1;
    case 0x0400C6B2u: /* B9 DB 97 LDA $97DB,Y */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x97DBu + instance->cpu.y)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC6B5u;
        instance->instruction_count++;
        return 1;
    case 0x0400C6B5u: /* 8D FE 1E STA $1EFE */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EFEu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC6B8u;
        instance->instruction_count++;
        return 1;
    case 0x0400C6B8u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC6BAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C6BAu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0000C6BBu: /* C2 30 REP #$30 */
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC6BDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C6BDu: /* A5 46 LDA $46 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x46u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC6BFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C6BFu: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xC6C0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6C0u: /* E9 A0 05 SBC #$05A0 */
        word = 0x05A0u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xC6C3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6C3u: /* B0 04 BCS $00:C6C9 */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xC6C9u : 0xC6C5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6C5u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xC6C6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6C6u: /* 6D 00 02 ADC $0200 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0200u), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xC6C9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6C9u: /* 85 46 STA $46 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x46u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC6CBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C6CBu: /* A5 59 LDA $59 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x59u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC6CDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C6CDu: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0xC6CEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C6CEu: /* E9 A0 05 SBC #$05A0 */
        word = 0x05A0u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xC6D1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6D1u: /* B0 04 BCS $00:C6D7 */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xC6D7u : 0xC6D3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6D3u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xC6D4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6D4u: /* 6D 00 02 ADC $0200 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0200u), &word)) return 0;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xC6D7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6D7u: /* 85 59 STA $59 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x59u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC6D9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6D9u: /* A9 2D 00 LDA #$002D */
        word = 0x002Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC6DCu;
        instance->instruction_count++;
        return 1;
    case 0x0000C6DCu: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC6DDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C6DDu: /* 20 0D E2 JSR $E20D */
        if (!tg_push16(instance, 0xC6DFu)) return 0;
        instance->cpu.pc = 0xE20Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C6E0u: /* 20 0D E2 JSR $E20D */
        if (!tg_push16(instance, 0xC6E2u)) return 0;
        instance->cpu.pc = 0xE20Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C6E3u: /* AD C2 1B LDA $1BC2 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC2u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC6E6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6E6u: /* CD C4 1B CMP $1BC4 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC4u), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xC6E9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6E9u: /* D0 F2 BNE $00:C6DD */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC6DDu : 0xC6EBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C6EBu: /* AD 10 1D LDA $1D10 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D10u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC6EEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C6EEu: /* CD 12 1D CMP $1D12 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D12u), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xC6F1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6F1u: /* D0 EA BNE $00:C6DD */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC6DDu : 0xC6F3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6F3u: /* AD C0 1B LDA $1BC0 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC0u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC6F6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6F6u: /* D0 E5 BNE $00:C6DD */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC6DDu : 0xC6F8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C6F8u: /* AD 0E 1D LDA $1D0E */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Eu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC6FBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C6FBu: /* D0 E0 BNE $00:C6DD */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC6DDu : 0xC6FDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C6FDu: /* A5 46 LDA $46 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x46u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC6FFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C6FFu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xC700u;
        instance->instruction_count++;
        return 1;
    case 0x0000C700u: /* 69 20 00 ADC #$0020 */
        word = 0x0020u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xC703u;
        instance->instruction_count++;
        return 1;
    case 0x0000C703u: /* CD 00 02 CMP $0200 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0200u), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xC706u;
        instance->instruction_count++;
        return 1;
    case 0x0000C706u: /* 90 03 BCC $00:C70B */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xC70Bu : 0xC708u;
        instance->instruction_count++;
        return 1;
    case 0x0000C708u: /* ED 00 02 SBC $0200 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0200u), &word)) return 0;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xC70Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C70Bu: /* 85 46 STA $46 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x46u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC70Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C70Du: /* A5 59 LDA $59 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x59u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC70Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C70Fu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0xC710u;
        instance->instruction_count++;
        return 1;
    case 0x0000C710u: /* 69 20 00 ADC #$0020 */
        word = 0x0020u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xC713u;
        instance->instruction_count++;
        return 1;
    case 0x0000C713u: /* CD 00 02 CMP $0200 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0200u), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xC716u;
        instance->instruction_count++;
        return 1;
    case 0x0000C716u: /* 90 03 BCC $00:C71B */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xC71Bu : 0xC718u;
        instance->instruction_count++;
        return 1;
    case 0x0000C718u: /* ED 00 02 SBC $0200 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0200u), &word)) return 0;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xC71Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C71Bu: /* 85 59 STA $59 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x59u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC71Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C71Du: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC71Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C71Eu: /* 3A DEC A */
        word = (uint16_t)((instance->cpu.a) - 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC71Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C71Fu: /* D0 BB BNE $00:C6DC */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC6DCu : 0xC721u;
        instance->instruction_count++;
        return 1;
    case 0x0000C721u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x0000C722u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC724u;
        instance->instruction_count++;
        return 1;
    case 0x0400C724u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC726u;
        instance->instruction_count++;
        return 1;
    case 0x0400C726u: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC729u;
        instance->instruction_count++;
        return 1;
    case 0x0400C729u: /* A9 02 LDA #$02 */
        byte = 0x02u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC72Bu;
        instance->instruction_count++;
        return 1;
    case 0x0400C72Bu: /* 8D 04 43 STA $4304 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4304u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC72Eu;
        instance->instruction_count++;
        return 1;
    case 0x0400C72Eu: /* C2 30 REP #$30 */
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC730u;
        instance->instruction_count++;
        return 1;
    case 0x0000C730u: /* A9 01 18 LDA #$1801 */
        word = 0x1801u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC733u;
        instance->instruction_count++;
        return 1;
    case 0x0000C733u: /* 8D 00 43 STA $4300 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4300u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC736u;
        instance->instruction_count++;
        return 1;
    case 0x0000C736u: /* A9 09 BC LDA #$BC09 */
        word = 0xBC09u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC739u;
        instance->instruction_count++;
        return 1;
    case 0x0000C739u: /* 8D 02 43 STA $4302 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC73Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C73Cu: /* A9 40 0C LDA #$0C40 */
        word = 0x0C40u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC73Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C73Fu: /* 8D 05 43 STA $4305 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4305u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC742u;
        instance->instruction_count++;
        return 1;
    case 0x0000C742u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC745u;
        instance->instruction_count++;
        return 1;
    case 0x0000C745u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC748u;
        instance->instruction_count++;
        return 1;
    case 0x0000C748u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC74Au;
        instance->instruction_count++;
        return 1;
    case 0x0400C74Au: /* A9 01 LDA #$01 */
        byte = 0x01u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC74Cu;
        instance->instruction_count++;
        return 1;
    case 0x0400C74Cu: /* 8D 0B 42 STA $420B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC74Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400C74Fu: /* A9 80 LDA #$80 */
        byte = 0x80u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xC751u;
        instance->instruction_count++;
        return 1;
    case 0x0400C751u: /* 8D 15 21 STA $2115 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2115u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0xC754u;
        instance->instruction_count++;
        return 1;
    case 0x0400C754u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xC756u;
        instance->instruction_count++;
        return 1;
    case 0x0000C756u: /* A9 57 0C LDA #$0C57 */
        word = 0x0C57u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC759u;
        instance->instruction_count++;
        return 1;
    case 0x0000C759u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC75Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C75Cu: /* A9 17 2C LDA #$2C17 */
        word = 0x2C17u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC75Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C75Fu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC762u;
        instance->instruction_count++;
        return 1;
    case 0x0000C762u: /* A9 18 2C LDA #$2C18 */
        word = 0x2C18u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC765u;
        instance->instruction_count++;
        return 1;
    case 0x0000C765u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC768u;
        instance->instruction_count++;
        return 1;
    case 0x0000C768u: /* A9 17 2C LDA #$2C17 */
        word = 0x2C17u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC76Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C76Bu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC76Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C76Eu: /* A9 18 2C LDA #$2C18 */
        word = 0x2C18u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC771u;
        instance->instruction_count++;
        return 1;
    case 0x0000C771u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC774u;
        instance->instruction_count++;
        return 1;
    case 0x0000C774u: /* A9 17 2C LDA #$2C17 */
        word = 0x2C17u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC777u;
        instance->instruction_count++;
        return 1;
    case 0x0000C777u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC77Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C77Au: /* A9 18 2C LDA #$2C18 */
        word = 0x2C18u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC77Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C77Du: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC780u;
        instance->instruction_count++;
        return 1;
    case 0x0000C780u: /* A9 77 0C LDA #$0C77 */
        word = 0x0C77u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC783u;
        instance->instruction_count++;
        return 1;
    case 0x0000C783u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC786u;
        instance->instruction_count++;
        return 1;
    case 0x0000C786u: /* A9 19 2C LDA #$2C19 */
        word = 0x2C19u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC789u;
        instance->instruction_count++;
        return 1;
    case 0x0000C789u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC78Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C78Cu: /* A9 1A 2C LDA #$2C1A */
        word = 0x2C1Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC78Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C78Fu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC792u;
        instance->instruction_count++;
        return 1;
    case 0x0000C792u: /* A9 19 2C LDA #$2C19 */
        word = 0x2C19u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC795u;
        instance->instruction_count++;
        return 1;
    case 0x0000C795u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC798u;
        instance->instruction_count++;
        return 1;
    case 0x0000C798u: /* A9 1A 2C LDA #$2C1A */
        word = 0x2C1Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC79Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C79Bu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC79Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C79Eu: /* A9 19 2C LDA #$2C19 */
        word = 0x2C19u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7A1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7A1u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7A4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7A4u: /* A9 1A 2C LDA #$2C1A */
        word = 0x2C1Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7A7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7A7u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7AAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C7AAu: /* A9 97 0C LDA #$0C97 */
        word = 0x0C97u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7ADu;
        instance->instruction_count++;
        return 1;
    case 0x0000C7ADu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7B0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7B0u: /* A9 35 2C LDA #$2C35 */
        word = 0x2C35u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7B3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7B3u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7B6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7B6u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7B9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7B9u: /* A9 3F 2C LDA #$2C3F */
        word = 0x2C3Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7BCu;
        instance->instruction_count++;
        return 1;
    case 0x0000C7BCu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7BFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C7BFu: /* A9 35 2C LDA #$2C35 */
        word = 0x2C35u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7C2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7C2u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7C5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7C5u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7C8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7C8u: /* A9 40 2C LDA #$2C40 */
        word = 0x2C40u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7CBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C7CBu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7CEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C7CEu: /* A9 35 2C LDA #$2C35 */
        word = 0x2C35u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7D1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7D1u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7D4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7D4u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7D7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7D7u: /* A9 34 0C LDA #$0C34 */
        word = 0x0C34u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7DAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C7DAu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7DDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C7DDu: /* A9 02 30 LDA #$3002 */
        word = 0x3002u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7E0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7E0u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7E3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7E3u: /* A9 03 30 LDA #$3003 */
        word = 0x3003u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7E6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7E6u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7E9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7E9u: /* A9 04 30 LDA #$3004 */
        word = 0x3004u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7ECu;
        instance->instruction_count++;
        return 1;
    case 0x0000C7ECu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7EFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C7EFu: /* A9 05 30 LDA #$3005 */
        word = 0x3005u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7F2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7F2u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7F5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7F5u: /* A9 06 30 LDA #$3006 */
        word = 0x3006u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7F8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C7F8u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC7FBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C7FBu: /* A9 07 2C LDA #$2C07 */
        word = 0x2C07u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC7FEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C7FEu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC801u;
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
