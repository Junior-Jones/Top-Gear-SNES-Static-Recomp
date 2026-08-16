/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_0021(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x06008400u: /* 8D 20 21 STA $2120 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2120u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8403u;
        instance->instruction_count++;
        return 1;
    case 0x06008403u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8405u;
        instance->instruction_count++;
        return 1;
    case 0x06008405u: /* 8D 21 21 STA $2121 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8408u;
        instance->instruction_count++;
        return 1;
    case 0x06008408u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x840Au;
        instance->instruction_count++;
        return 1;
    case 0x0600840Au: /* 8D 23 21 STA $2123 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2123u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x840Du;
        instance->instruction_count++;
        return 1;
    case 0x0600840Du: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x840Fu;
        instance->instruction_count++;
        return 1;
    case 0x0600840Fu: /* 8D 24 21 STA $2124 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2124u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8412u;
        instance->instruction_count++;
        return 1;
    case 0x06008412u: /* A9 B0 LDA #$B0 */
        byte = 0xB0u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8414u;
        instance->instruction_count++;
        return 1;
    case 0x06008414u: /* 8D 25 21 STA $2125 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2125u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8417u;
        instance->instruction_count++;
        return 1;
    case 0x06008417u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8419u;
        instance->instruction_count++;
        return 1;
    case 0x06008419u: /* 8D 26 21 STA $2126 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2126u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x841Cu;
        instance->instruction_count++;
        return 1;
    case 0x0600841Cu: /* A9 FF LDA #$FF */
        byte = 0xFFu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x841Eu;
        instance->instruction_count++;
        return 1;
    case 0x0600841Eu: /* 8D 27 21 STA $2127 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2127u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8421u;
        instance->instruction_count++;
        return 1;
    case 0x06008421u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8423u;
        instance->instruction_count++;
        return 1;
    case 0x06008423u: /* 8D 28 21 STA $2128 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2128u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8426u;
        instance->instruction_count++;
        return 1;
    case 0x06008426u: /* A9 FF LDA #$FF */
        byte = 0xFFu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8428u;
        instance->instruction_count++;
        return 1;
    case 0x06008428u: /* 8D 29 21 STA $2129 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2129u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x842Bu;
        instance->instruction_count++;
        return 1;
    case 0x0600842Bu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x842Du;
        instance->instruction_count++;
        return 1;
    case 0x0600842Du: /* 8D 2A 21 STA $212A */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x212Au), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8430u;
        instance->instruction_count++;
        return 1;
    case 0x06008430u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8432u;
        instance->instruction_count++;
        return 1;
    case 0x06008432u: /* 8D 2B 21 STA $212B */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x212Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8435u;
        instance->instruction_count++;
        return 1;
    case 0x06008435u: /* A9 17 LDA #$17 */
        byte = 0x17u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8437u;
        instance->instruction_count++;
        return 1;
    case 0x06008437u: /* 8D 2C 21 STA $212C */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x212Cu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x843Au;
        instance->instruction_count++;
        return 1;
    case 0x0600843Au: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x843Cu;
        instance->instruction_count++;
        return 1;
    case 0x0600843Cu: /* 8D 2D 21 STA $212D */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x212Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x843Fu;
        instance->instruction_count++;
        return 1;
    case 0x0600843Fu: /* A9 06 LDA #$06 */
        byte = 0x06u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8441u;
        instance->instruction_count++;
        return 1;
    case 0x06008441u: /* 8D 2E 21 STA $212E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x212Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8444u;
        instance->instruction_count++;
        return 1;
    case 0x06008444u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8446u;
        instance->instruction_count++;
        return 1;
    case 0x06008446u: /* 8D 2F 21 STA $212F */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x212Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8449u;
        instance->instruction_count++;
        return 1;
    case 0x06008449u: /* A9 20 LDA #$20 */
        byte = 0x20u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x844Bu;
        instance->instruction_count++;
        return 1;
    case 0x0600844Bu: /* 8D 30 21 STA $2130 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2130u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x844Eu;
        instance->instruction_count++;
        return 1;
    case 0x0600844Eu: /* A9 A6 LDA #$A6 */
        byte = 0xA6u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8450u;
        instance->instruction_count++;
        return 1;
    case 0x06008450u: /* 8D 31 21 STA $2131 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2131u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8453u;
        instance->instruction_count++;
        return 1;
    case 0x06008453u: /* A9 FF LDA #$FF */
        byte = 0xFFu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8455u;
        instance->instruction_count++;
        return 1;
    case 0x06008455u: /* 8D 32 21 STA $2132 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2132u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8458u;
        instance->instruction_count++;
        return 1;
    case 0x06008458u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x845Au;
        instance->instruction_count++;
        return 1;
    case 0x0600845Au: /* 8D 33 21 STA $2133 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2133u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x845Du;
        instance->instruction_count++;
        return 1;
    case 0x0600845Du: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x845Fu;
        instance->instruction_count++;
        return 1;
    case 0x0600845Fu: /* 8D 3E 21 STA $213E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x213Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8462u;
        instance->instruction_count++;
        return 1;
    case 0x06008462u: /* A9 10 LDA #$10 */
        byte = 0x10u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8464u;
        instance->instruction_count++;
        return 1;
    case 0x06008464u: /* 8D 3F 21 STA $213F */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x213Fu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8467u;
        instance->instruction_count++;
        return 1;
    case 0x06008467u: /* A9 B1 LDA #$B1 */
        byte = 0xB1u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8469u;
        instance->instruction_count++;
        return 1;
    case 0x06008469u: /* 8D 00 42 STA $4200 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4200u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x846Cu;
        instance->instruction_count++;
        return 1;
    case 0x0600846Cu: /* A9 7C LDA #$7C */
        byte = 0x7Cu;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x846Eu;
        instance->instruction_count++;
        return 1;
    case 0x0600846Eu: /* 8D 07 42 STA $4207 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4207u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8471u;
        instance->instruction_count++;
        return 1;
    case 0x06008471u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8473u;
        instance->instruction_count++;
        return 1;
    case 0x06008473u: /* 8D 08 42 STA $4208 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4208u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8476u;
        instance->instruction_count++;
        return 1;
    case 0x06008476u: /* A9 E0 LDA #$E0 */
        byte = 0xE0u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8478u;
        instance->instruction_count++;
        return 1;
    case 0x06008478u: /* 8D 09 42 STA $4209 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4209u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x847Bu;
        instance->instruction_count++;
        return 1;
    case 0x0600847Bu: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x847Du;
        instance->instruction_count++;
        return 1;
    case 0x0600847Du: /* 8D 0A 42 STA $420A */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Au), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8480u;
        instance->instruction_count++;
        return 1;
    case 0x06008480u: /* A9 00 LDA #$00 */
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8482u;
        instance->instruction_count++;
        return 1;
    case 0x06008482u: /* 8D 0D 42 STA $420D */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Du), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8485u;
        instance->instruction_count++;
        return 1;
    case 0x06008485u: /* 58 CLI */
        tg_set_flag(instance, TG_P_I, 0);
        instance->cpu.pc = 0x8486u;
        instance->instruction_count++;
        return 1;
    case 0x06008486u: /* C2 30 REP #$30 */
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8488u;
        instance->instruction_count++;
        return 1;
    case 0x00008488u: /* A9 7E EC LDA #$EC7E */
        word = 0xEC7Eu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x848Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000848Bu: /* 85 AC STA $AC */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xACu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x848Du;
        instance->instruction_count++;
        return 1;
    case 0x0000848Du: /* A9 D1 B6 LDA #$B6D1 */
        word = 0xB6D1u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8490u;
        instance->instruction_count++;
        return 1;
    case 0x00008490u: /* 85 0A STA $0A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8492u;
        instance->instruction_count++;
        return 1;
    case 0x00008492u: /* 20 14 BF JSR $BF14 */
        if (!tg_push16(instance, 0x8494u)) return 0;
        instance->cpu.pc = 0xBF14u;
        instance->instruction_count++;
        return 1;
    case 0x00008495u: /* A9 04 00 LDA #$0004 */
        word = 0x0004u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8498u;
        instance->instruction_count++;
        return 1;
    case 0x00008498u: /* 8D B6 1E STA $1EB6 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EB6u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x849Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000849Bu: /* A9 24 00 LDA #$0024 */
        word = 0x0024u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x849Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000849Eu: /* 8D B8 1E STA $1EB8 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EB8u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x84A1u;
        instance->instruction_count++;
        return 1;
    case 0x000084A1u: /* AD F2 1F LDA $1FF2 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF2u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84A4u;
        instance->instruction_count++;
        return 1;
    case 0x000084A4u: /* D0 03 BNE $00:84A9 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x84A9u : 0x84A6u;
        instance->instruction_count++;
        return 1;
    case 0x000084A6u: /* EE F2 1F INC $1FF2 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF2u), &word)) return 0;
        word = (uint16_t)(word + 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF2u), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84A9u;
        instance->instruction_count++;
        return 1;
    case 0x000084A9u: /* A9 FF FF LDA #$FFFF */
        word = 0xFFFFu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84ACu;
        instance->instruction_count++;
        return 1;
    case 0x000084ACu: /* 8D DC 1E STA $1EDC */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EDCu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x84AFu;
        instance->instruction_count++;
        return 1;
    case 0x000084AFu: /* A9 5A B7 LDA #$B75A */
        word = 0xB75Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84B2u;
        instance->instruction_count++;
        return 1;
    case 0x000084B2u: /* 85 08 STA $08 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x08u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x84B4u;
        instance->instruction_count++;
        return 1;
    case 0x000084B4u: /* 20 FC AB JSR $ABFC */
        if (!tg_push16(instance, 0x84B6u)) return 0;
        instance->cpu.pc = 0xABFCu;
        instance->instruction_count++;
        return 1;
    case 0x000084B7u: /* 22 00 20 7E JSL $7E2000 */
        if (!tg_push8(instance, instance->cpu.pbr)) return 0;
        if (!tg_push16(instance, 0x84BAu)) return 0;
        instance->cpu.pbr = 0x7Eu;
        instance->cpu.pc = 0x2000u;
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
