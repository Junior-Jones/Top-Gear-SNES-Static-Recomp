/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_03E1(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x000F8400u: /* A9 00 00 LDA #$0000 */
  /* The live timing panel must not cover the native results transition. */
  if(instance->mod_time_trial_active)instance->mod_time_trial_font_valid=0u;
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8403u;
        instance->instruction_count++;
        return 1;
    case 0x000F8403u: /* 9C 24 04 STZ $0424 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), 0u)) return 0;
        instance->cpu.pc = 0x8406u;
        instance->instruction_count++;
        return 1;
    case 0x000F8406u: /* 64 44 STZ $44 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x44u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x8408u;
        instance->instruction_count++;
        return 1;
    case 0x000F8408u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x840Au;
        instance->instruction_count++;
        return 1;
    case 0x040F840Au: /* A9 02 LDA #$02 */
        byte = 0x02u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x840Cu;
        instance->instruction_count++;
        return 1;
    case 0x040F840Cu: /* 8D 07 21 STA $2107 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2107u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x840Fu;
        instance->instruction_count++;
        return 1;
    case 0x040F840Fu: /* A9 81 LDA #$81 */
        byte = 0x81u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8411u;
        instance->instruction_count++;
        return 1;
    case 0x040F8411u: /* 8D 00 42 STA $4200 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4200u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8414u;
        instance->instruction_count++;
        return 1;
    case 0x040F8414u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8416u;
        instance->instruction_count++;
        return 1;
    case 0x000F8416u: /* 20 4B 90 JSR $904B */
        /* Native result video setup has re-enabled the NMI frame clock. */
        if(tg_mod_attempt_pre_results(instance)){instance->cpu.pc=0x84CBu;instance->instruction_count++;return 1;}
        if (!tg_push16(instance, 0x8418u)) return 0;
        instance->cpu.pc = 0x904Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F8419u: /* A2 A1 B4 LDX #$B4A1 */
        word = 0xB4A1u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x841Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F841Cu: /* 20 93 9F JSR $9F93 */
        if (!tg_push16(instance, 0x841Eu)) return 0;
        instance->cpu.pc = 0x9F93u;
        instance->instruction_count++;
        return 1;
    case 0x000F841Fu: /* 20 D9 87 JSR $87D9 */
        if (!tg_push16(instance, 0x8421u)) return 0;
        instance->cpu.pc = 0x87D9u;
        instance->instruction_count++;
        return 1;
    case 0x000F8422u: /* 20 2D 88 JSR $882D */
        if (!tg_push16(instance, 0x8424u)) return 0;
        instance->cpu.pc = 0x882Du;
        instance->instruction_count++;
        return 1;
    case 0x000F8425u: /* 20 DD 9D JSR $9DDD */
        if (!tg_push16(instance, 0x8427u)) return 0;
        instance->cpu.pc = 0x9DDDu;
        instance->instruction_count++;
        return 1;
    case 0x000F8428u: /* A9 00 10 LDA #$1000 */
        word = 0x1000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x842Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F842Bu: /* 8D 25 43 STA $4325 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4325u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x842Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F842Eu: /* A9 0F 00 LDA #$000F */
        word = 0x000Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8431u;
        instance->instruction_count++;
        return 1;
    case 0x000F8431u: /* 85 42 STA $42 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x42u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8433u;
        instance->instruction_count++;
        return 1;
    case 0x000F8433u: /* A9 84 00 LDA #$0084 */
        word = 0x0084u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8436u;
        instance->instruction_count++;
        return 1;
    case 0x000F8436u: /* 8D 24 04 STA $0424 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8439u;
        instance->instruction_count++;
        return 1;
    case 0x000F8439u: /* 20 B2 9D JSR $9DB2 */
        if (!tg_push16(instance, 0x843Bu)) return 0;
        instance->cpu.pc = 0x9DB2u;
        instance->instruction_count++;
        return 1;
    case 0x000F843Cu: /* A2 8F B4 LDX #$B48F */
        word = 0xB48Fu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x843Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F843Fu: /* 20 93 9F JSR $9F93 */
        if (!tg_push16(instance, 0x8441u)) return 0;
        instance->cpu.pc = 0x9F93u;
        instance->instruction_count++;
        return 1;
    case 0x000F8442u: /* 20 4F 89 JSR $894F */
        if (!tg_push16(instance, 0x8444u)) return 0;
        instance->cpu.pc = 0x894Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F8445u: /* 20 DD 9D JSR $9DDD */
        if (!tg_push16(instance, 0x8447u)) return 0;
        instance->cpu.pc = 0x9DDDu;
        instance->instruction_count++;
        return 1;
    case 0x000F8448u: /* A9 84 00 LDA #$0084 */
        word = 0x0084u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x844Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F844Bu: /* 8D 24 04 STA $0424 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x844Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F844Eu: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8451u;
        instance->instruction_count++;
        return 1;
    case 0x000F8451u: /* 20 4D A2 JSR $A24D */
        if (!tg_push16(instance, 0x8453u)) return 0;
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F8454u: /* 20 88 9E JSR $9E88 */
        if (!tg_push16(instance, 0x8456u)) return 0;
        instance->cpu.pc = 0x9E88u;
        instance->instruction_count++;
        return 1;
    case 0x000F8457u: /* 20 02 88 JSR $8802 */
        if (!tg_push16(instance, 0x8459u)) return 0;
        instance->cpu.pc = 0x8802u;
        instance->instruction_count++;
        return 1;
    case 0x000F845Au: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x845Du;
        instance->instruction_count++;
        return 1;
    case 0x000F845Du: /* 8D 4C 04 STA $044C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8460u;
        instance->instruction_count++;
        return 1;
    case 0x000F8460u: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8463u;
        instance->instruction_count++;
        return 1;
    case 0x000F8463u: /* 20 4D A2 JSR $A24D */
        if (!tg_push16(instance, 0x8465u)) return 0;
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F8466u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8468u;
        instance->instruction_count++;
        return 1;
    case 0x040F8468u: /* AD 4C 04 LDA $044C */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Cu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x846Bu;
        instance->instruction_count++;
        return 1;
    case 0x040F846Bu: /* 8D 0E 21 STA $210E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x846Eu;
        instance->instruction_count++;
        return 1;
    case 0x040F846Eu: /* AD 4D 04 LDA $044D */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Du), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8471u;
        instance->instruction_count++;
        return 1;
    case 0x040F8471u: /* 8D 0E 21 STA $210E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8474u;
        instance->instruction_count++;
        return 1;
    case 0x040F8474u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8476u;
        instance->instruction_count++;
        return 1;
    case 0x000F8476u: /* AD 4C 04 LDA $044C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Cu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8479u;
        instance->instruction_count++;
        return 1;
    case 0x000F8479u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x847Au;
        instance->instruction_count++;
        return 1;
    case 0x000F847Au: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x847Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F847Bu: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x847Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F847Cu: /* C9 01 01 CMP #$0101 */
        word = 0x0101u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x847Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F847Fu: /* 90 DC BCC $0F:845D */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x845Du : 0x8481u;
        instance->instruction_count++;
        return 1;
    case 0x000F8481u: /* 20 88 9E JSR $9E88 */
        if (!tg_push16(instance, 0x8483u)) return 0;
        instance->cpu.pc = 0x9E88u;
        instance->instruction_count++;
        return 1;
    case 0x000F8484u: /* 20 C5 9D JSR $9DC5 */
        if (!tg_push16(instance, 0x8486u)) return 0;
        instance->cpu.pc = 0x9DC5u;
        instance->instruction_count++;
        return 1;
    case 0x000F8487u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8489u;
        instance->instruction_count++;
        return 1;
    case 0x040F8489u: /* A9 10 LDA #$10 */
        byte = 0x10u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x848Bu;
        instance->instruction_count++;
        return 1;
    case 0x040F848Bu: /* 8D 0E 21 STA $210E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Eu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x848Eu;
        instance->instruction_count++;
        return 1;
    case 0x040F848Eu: /* 9C 0E 21 STZ $210E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Eu), 0u)) return 0;
        instance->cpu.pc = 0x8491u;
        instance->instruction_count++;
        return 1;
    case 0x040F8491u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8493u;
        instance->instruction_count++;
        return 1;
    case 0x000F8493u: /* 20 1C 9E JSR $9E1C */
        if (!tg_push16(instance, 0x8495u)) return 0;
        instance->cpu.pc = 0x9E1Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F8496u: /* AD 00 1F LDA $1F00 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F00u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8499u;
        instance->instruction_count++;
        return 1;
    case 0x000F8499u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x849Au;
        instance->instruction_count++;
        return 1;
    case 0x000F849Au: /* 8D F8 1F STA $1FF8 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF8u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x849Du;
        instance->instruction_count++;
        return 1;
    case 0x000F849Du: /* AD 02 1F LDA $1F02 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F02u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84A0u;
        instance->instruction_count++;
        return 1;
    case 0x000F84A0u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84A1u;
        instance->instruction_count++;
        return 1;
    case 0x000F84A1u: /* 8D FA 1F STA $1FFA */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FFAu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x84A4u;
        instance->instruction_count++;
        return 1;
    case 0x000F84A4u: /* 20 1A 87 JSR $871A */
        if (!tg_push16(instance, 0x84A6u)) return 0;
        instance->cpu.pc = 0x871Au;
        instance->instruction_count++;
        return 1;
    case 0x000F84A7u: /* B0 22 BCS $0F:84CB */
        if (instance->mod_time_trial_active) {
            /* Time Trial never uses Career qualification. */
            instance->cpu.pc = 0x84A9u;
        } else if (instance->mod_rally_active) {
            /* Rally replaces Career's fixed "any human in top five" rule
               with a tightening per-race cutoff.  Every active human must
               qualify; the one-player CPU racer ID 1 never counts. */
            if (tg_mod_rally_qualification_passes(instance)) {
                instance->cpu.pc = 0x84A9u;
            } else {
                tg_mod_rally_qualification_failed(instance);
                instance->cpu.pc = 0x84CBu;
            }
        } else {
            if(tg_mod_career_qualification_passes(instance))instance->cpu.pc=0x84A9u;
            else{tg_mod_attempt_fail(instance);instance->cpu.pc=0x84CBu;}
        }
        instance->instruction_count++;
        return 1;
    case 0x000F84A9u: /* 20 E7 86 JSR $86E7 */
        if (!tg_push16(instance, 0x84ABu)) return 0;
        instance->cpu.pc = 0x86E7u;
        instance->instruction_count++;
        return 1;
    case 0x000F84ACu: /* 20 33 87 JSR $8733 */
        {
            if (tg_mod_time_trial_post_results(instance)) {
                instance->mod_menu_post_race_context=1u;
                instance->cpu.pc = 0x918Bu;
                instance->instruction_count++;
                return 1;
            }
            int rally_progress = tg_mod_rally_post_results(instance);
            if (rally_progress == 1) {
                word = UINT16_C(0x0001);
                tg_set_acc16(instance, word);
                tg_set_nz16(instance, word);
                tg_set_flag(instance, TG_P_C, 0);
                instance->cpu.pc = 0x84AFu;
                instance->instruction_count++;
                return 1;
            }
            if (rally_progress == 2) {
                instance->cpu.pc = 0x918Bu;
                instance->instruction_count++;
                return 1;
            }
        }
        if (!tg_push16(instance, 0x84AEu)) return 0;
        instance->cpu.pc = 0x8733u;
        instance->instruction_count++;
        return 1;
    case 0x000F84AFu: /* B0 30 BCS $0F:84E1 */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x84E1u : 0x84B1u;
        instance->instruction_count++;
        return 1;
    case 0x000F84B1u: /* F0 0D BEQ $0F:84C0 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x84C0u : 0x84B3u;
        instance->instruction_count++;
        return 1;
    case 0x000F84B3u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x84B5u;
        instance->instruction_count++;
        return 1;
    case 0x040F84B5u: /* 9C 0E 21 STZ $210E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Eu), 0u)) return 0;
        instance->cpu.pc = 0x84B8u;
        instance->instruction_count++;
        return 1;
    case 0x040F84B8u: /* 9C 0E 21 STZ $210E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Eu), 0u)) return 0;
        instance->cpu.pc = 0x84BBu;
        instance->instruction_count++;
        return 1;
    case 0x040F84BBu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x84BDu;
        instance->instruction_count++;
        return 1;
    case 0x000F84BDu: /* 4C 8E 81 JMP $818E */
        instance->cpu.pc = 0x818Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F84C0u: /* AE 06 1F LDX $1F06 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84C3u;
        instance->instruction_count++;
        return 1;
    case 0x000F84C3u: /* D0 03 BNE $0F:84C8 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x84C8u : 0x84C5u;
        instance->instruction_count++;
        return 1;
    case 0x000F84C5u: /* A9 03 00 LDA #$0003 */
        word = 0x0003u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84C8u;
        instance->instruction_count++;
        return 1;
    case 0x000F84C8u: /* 4C F5 84 JMP $84F5 */
        instance->cpu.pc = 0x84F5u;
        instance->instruction_count++;
        return 1;
    case 0x000F84CBu: /* A2 12 00 LDX #$0012 */
        word = 0x0012u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84CEu;
        instance->instruction_count++;
        return 1;
    case 0x000F84CEu: /* 9E 4E 1F STZ $1F4E,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F4Eu + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x84D1u;
        instance->instruction_count++;
        return 1;
    case 0x000F84D1u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84D2u;
        instance->instruction_count++;
        return 1;
    case 0x000F84D2u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84D3u;
        instance->instruction_count++;
        return 1;
    case 0x000F84D3u: /* 10 F9 BPL $0F:84CE */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x84CEu : 0x84D5u;
        instance->instruction_count++;
        return 1;
    case 0x000F84D5u: /* 9C 00 1F STZ $1F00 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F00u), 0u)) return 0;
        instance->cpu.pc = 0x84D8u;
        instance->instruction_count++;
        return 1;
    case 0x000F84D8u: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84DBu;
        instance->instruction_count++;
        return 1;
    case 0x000F84DBu: /* 8D 02 1F STA $1F02 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F02u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x84DEu;
        instance->instruction_count++;
        return 1;
    case 0x000F84DEu: /* 4C F5 84 JMP $84F5 */
        instance->cpu.pc = 0x84F5u;
        instance->instruction_count++;
        return 1;
    case 0x000F84E1u: /* A2 12 00 LDX #$0012 */
        word = 0x0012u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84E4u;
        instance->instruction_count++;
        return 1;
    case 0x000F84E4u: /* 9E 4E 1F STZ $1F4E,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F4Eu + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x84E7u;
        instance->instruction_count++;
        return 1;
    case 0x000F84E7u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84E8u;
        instance->instruction_count++;
        return 1;
    case 0x000F84E8u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84E9u;
        instance->instruction_count++;
        return 1;
    case 0x000F84E9u: /* 10 F9 BPL $0F:84E4 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x84E4u : 0x84EBu;
        instance->instruction_count++;
        return 1;
    case 0x000F84EBu: /* 9C 00 1F STZ $1F00 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F00u), 0u)) return 0;
        instance->cpu.pc = 0x84EEu;
        instance->instruction_count++;
        return 1;
    case 0x000F84EEu: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84F1u;
        instance->instruction_count++;
        return 1;
    case 0x000F84F1u: /* 8D 02 1F STA $1F02 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F02u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x84F4u;
        instance->instruction_count++;
        return 1;
    case 0x000F84F4u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84F5u;
        instance->instruction_count++;
        return 1;
    case 0x000F84F5u: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x84F6u;
        instance->instruction_count++;
        return 1;
    case 0x000F84F6u: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x84F7u;
        instance->instruction_count++;
        return 1;
    case 0x000F84F7u: /* A9 8F 00 LDA #$008F */
        word = 0x008Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84FAu;
        instance->instruction_count++;
        return 1;
    case 0x000F84FAu: /* 85 42 STA $42 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x42u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x84FCu;
        instance->instruction_count++;
        return 1;
    case 0x000F84FCu: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x84FFu;
        instance->instruction_count++;
        return 1;
    case 0x000F84FFu: /* 20 4D A2 JSR $A24D */
        if (!tg_push16(instance, 0x8501u)) return 0;
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F8502u: /* A9 0D 80 LDA #$800D */
        word = 0x800Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8505u;
        instance->instruction_count++;
        return 1;
    case 0x000F8505u: /* A2 51 AE LDX #$AE51 */
        word = 0xAE51u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8508u;
        instance->instruction_count++;
        return 1;
    case 0x000F8508u: /* A0 00 22 LDY #$2200 */
        word = 0x2200u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x850Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F850Bu: /* 20 06 B3 JSR $B306 */
        if (!tg_push16(instance, 0x850Du)) return 0;
        instance->cpu.pc = 0xB306u;
        instance->instruction_count++;
        return 1;
    case 0x000F850Eu: /* A9 0D 80 LDA #$800D */
        word = 0x800Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8511u;
        instance->instruction_count++;
        return 1;
    case 0x000F8511u: /* A2 4B C2 LDX #$C24B */
        word = 0xC24Bu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8514u;
        instance->instruction_count++;
        return 1;
    case 0x000F8514u: /* A0 00 00 LDY #$0000 */
        word = 0x0000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8517u;
        instance->instruction_count++;
        return 1;
    case 0x000F8517u: /* 20 34 B3 JSR $B334 */
        if (!tg_push16(instance, 0x8519u)) return 0;
        instance->cpu.pc = 0xB334u;
        instance->instruction_count++;
        return 1;
    case 0x000F851Au: /* A9 0F 80 LDA #$800F */
        word = 0x800Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x851Du;
        instance->instruction_count++;
        return 1;
    case 0x000F851Du: /* A2 A7 BB LDX #$BBA7 */
        word = 0xBBA7u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8520u;
        instance->instruction_count++;
        return 1;
    case 0x000F8520u: /* A0 00 10 LDY #$1000 */
        word = 0x1000u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8523u;
        instance->instruction_count++;
        return 1;
    case 0x000F8523u: /* 20 06 B3 JSR $B306 */
        if (!tg_push16(instance, 0x8525u)) return 0;
        instance->cpu.pc = 0xB306u;
        instance->instruction_count++;
        return 1;
    case 0x000F8526u: /* 20 42 9C JSR $9C42 */
        if (!tg_push16(instance, 0x8528u)) return 0;
        instance->cpu.pc = 0x9C42u;
        instance->instruction_count++;
        return 1;
    case 0x000F8529u: /* 20 EB A1 JSR $A1EB */
        if (!tg_push16(instance, 0x852Bu)) return 0;
        instance->cpu.pc = 0xA1EBu;
        instance->instruction_count++;
        return 1;
    case 0x000F852Cu: /* 20 F6 A1 JSR $A1F6 */
        if (!tg_push16(instance, 0x852Eu)) return 0;
        instance->cpu.pc = 0xA1F6u;
        instance->instruction_count++;
        return 1;
    case 0x000F852Fu: /* A9 02 00 LDA #$0002 */
        word = 0x0002u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8532u;
        instance->instruction_count++;
        return 1;
    case 0x000F8532u: /* 8D 24 04 STA $0424 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8535u;
        instance->instruction_count++;
        return 1;
    case 0x000F8535u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8536u;
        instance->instruction_count++;
        return 1;
    case 0x000F8536u: /* 20 4D A2 JSR $A24D */
        if (!tg_push16(instance, 0x8538u)) return 0;
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F8539u: /* 20 80 8F JSR $8F80 */
        if (!tg_push16(instance, 0x853Bu)) return 0;
        instance->cpu.pc = 0x8F80u;
        instance->instruction_count++;
        return 1;
    case 0x000F853Cu: /* A9 20 20 LDA #$2020 */
        word = 0x2020u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x853Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F853Fu: /* 8D 2C 04 STA $042C */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x042Cu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8542u;
        instance->instruction_count++;
        return 1;
    case 0x000F8542u: /* 8D 4A 04 STA $044A */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x044Au), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8545u;
        instance->instruction_count++;
        return 1;
    case 0x000F8545u: /* 8D 30 04 STA $0430 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0430u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8548u;
        instance->instruction_count++;
        return 1;
    case 0x000F8548u: /* 8D 32 04 STA $0432 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0432u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x854Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F854Bu: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x854Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F854Cu: /* 48 PHA */
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x854Du;
        instance->instruction_count++;
        return 1;
    case 0x000F854Du: /* 20 4E 91 JSR $914E */
        if (!tg_push16(instance, 0x854Fu)) return 0;
        instance->cpu.pc = 0x914Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F8550u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8551u;
        instance->instruction_count++;
        return 1;
    case 0x000F8551u: /* F0 31 BEQ $0F:8584 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x8584u : 0x8553u;
        instance->instruction_count++;
        return 1;
    case 0x000F8553u: /* C9 02 00 CMP #$0002 */
        word = 0x0002u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x8556u;
        instance->instruction_count++;
        return 1;
    case 0x000F8556u: /* 90 3A BCC $0F:8592 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x8592u : 0x8558u;
        instance->instruction_count++;
        return 1;
    case 0x000F8558u: /* F0 3D BEQ $0F:8597 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x8597u : 0x855Au;
        instance->instruction_count++;
        return 1;
    case 0x000F855Au: /* A2 71 B2 LDX #$B271 */
        word = 0xB271u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x855Du;
        instance->instruction_count++;
        return 1;
    case 0x000F855Du: /* 20 3E 9F JSR $9F3E */
        if (!tg_push16(instance, 0x855Fu)) return 0;
        instance->cpu.pc = 0x9F3Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F8560u: /* A9 06 00 LDA #$0006 */
        word = 0x0006u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8563u;
        instance->instruction_count++;
        return 1;
    case 0x000F8563u: /* 20 33 81 JSR $8133 */
        if (!tg_push16(instance, 0x8565u)) return 0;
        instance->cpu.pc = 0x8133u;
        instance->instruction_count++;
        return 1;
    case 0x000F8566u: /* AD 10 1F LDA $1F10 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F10u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8569u;
        instance->instruction_count++;
        return 1;
    case 0x000F8569u: /* F0 11 BEQ $0F:857C */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x857Cu : 0x856Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F856Bu: /* C9 02 00 CMP #$0002 */
        word = 0x0002u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x856Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F856Eu: /* D0 03 BNE $0F:8573 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8573u : 0x8570u;
        instance->instruction_count++;
        return 1;
    case 0x000F8570u: /* 4C F2 85 JMP $85F2 */
        instance->cpu.pc = 0x85F2u;
        instance->instruction_count++;
        return 1;
    case 0x000F8573u: /* A2 CA B2 LDX #$B2CA */
        word = 0xB2CAu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8576u;
        instance->instruction_count++;
        return 1;
    case 0x000F8576u: /* 20 3E 9F JSR $9F3E */
        if (!tg_push16(instance, 0x8578u)) return 0;
        instance->cpu.pc = 0x9F3Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F8579u: /* 4C F2 85 JMP $85F2 */
        instance->cpu.pc = 0x85F2u;
        instance->instruction_count++;
        return 1;
    case 0x000F857Cu: /* A2 9E B2 LDX #$B29E */
        word = 0xB29Eu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x857Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F857Fu: /* 20 3E 9F JSR $9F3E */
        if (!tg_push16(instance, 0x8581u)) return 0;
        instance->cpu.pc = 0x9F3Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F8582u: /* 80 6E BRA $0F:85F2 */
        instance->cpu.pc = 0x85F2u;
        instance->instruction_count++;
        return 1;
    case 0x000F8584u: /* A2 C7 B1 LDX #$B1C7 */
        word = 0xB1C7u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8587u;
        instance->instruction_count++;
        return 1;
    case 0x000F8587u: /* 20 3E 9F JSR $9F3E */
        if (!tg_push16(instance, 0x8589u)) return 0;
        instance->cpu.pc = 0x9F3Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F858Au: /* A9 05 00 LDA #$0005 */
        word = 0x0005u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x858Du;
        instance->instruction_count++;
        return 1;
    case 0x000F858Du: /* 20 33 81 JSR $8133 */
        if (!tg_push16(instance, 0x858Fu)) return 0;
        instance->cpu.pc = 0x8133u;
        instance->instruction_count++;
        return 1;
    case 0x000F8590u: /* 80 0B BRA $0F:859D */
        instance->cpu.pc = 0x859Du;
        instance->instruction_count++;
        return 1;
    case 0x000F8592u: /* A2 3B B2 LDX #$B23B */
        word = 0xB23Bu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8595u;
        instance->instruction_count++;
        return 1;
    case 0x000F8595u: /* 80 03 BRA $0F:859A */
        instance->cpu.pc = 0x859Au;
        instance->instruction_count++;
        return 1;
    case 0x000F8597u: /* A2 02 B2 LDX #$B202 */
        word = 0xB202u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x859Au;
        instance->instruction_count++;
        return 1;
    case 0x000F859Au: /* 20 3E 9F JSR $9F3E */
        if (!tg_push16(instance, 0x859Cu)) return 0;
        instance->cpu.pc = 0x9F3Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F859Du: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x859Fu;
        instance->instruction_count++;
        return 1;
    case 0x040F859Fu: /* 9C 01 21 STZ $2101 */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2101u), 0u)) return 0;
        instance->cpu.pc = 0x85A2u;
        instance->instruction_count++;
        return 1;
    case 0x040F85A2u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x85A4u;
        instance->instruction_count++;
        return 1;
    case 0x000F85A4u: /* 20 91 A6 JSR $A691 */
        if (!tg_push16(instance, 0x85A6u)) return 0;
        instance->cpu.pc = 0xA691u;
        instance->instruction_count++;
        return 1;
    case 0x000F85A7u: /* 20 05 87 JSR $8705 */
        if (!tg_push16(instance, 0x85A9u)) return 0;
        instance->cpu.pc = 0x8705u;
        instance->instruction_count++;
        return 1;
    case 0x000F85AAu: /* 64 75 STZ $75 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x75u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x85ACu;
        instance->instruction_count++;
        return 1;
    case 0x000F85ACu: /* 64 77 STZ $77 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x77u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x85AEu;
        instance->instruction_count++;
        return 1;
    case 0x000F85AEu: /* A9 11 05 LDA #$0511 */
        word = 0x0511u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x85B1u;
        instance->instruction_count++;
        return 1;
    case 0x000F85B1u: /* 85 64 STA $64 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x64u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x85B3u;
        instance->instruction_count++;
        return 1;
    case 0x000F85B3u: /* AD 04 1F LDA $1F04 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x85B6u;
        instance->instruction_count++;
        return 1;
    case 0x000F85B6u: /* F0 30 BEQ $0F:85E8 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x85E8u : 0x85B8u;
        instance->instruction_count++;
        return 1;
    case 0x000F85B8u: /* AD F8 1F LDA $1FF8 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF8u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x85BBu;
        instance->instruction_count++;
        return 1;
    case 0x000F85BBu: /* CD FA 1F CMP $1FFA */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FFAu), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x85BEu;
        instance->instruction_count++;
        return 1;
    case 0x000F85BEu: /* 90 18 BCC $0F:85D8 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x85D8u : 0x85C0u;
        instance->instruction_count++;
        return 1;
    case 0x000F85C0u: /* A9 11 06 LDA #$0611 */
        word = 0x0611u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x85C3u;
        instance->instruction_count++;
        return 1;
    case 0x000F85C3u: /* 85 64 STA $64 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x64u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x85C5u;
        instance->instruction_count++;
        return 1;
    case 0x000F85C5u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x85C8u;
        instance->instruction_count++;
        return 1;
    case 0x000F85C8u: /* 20 93 86 JSR $8693 */
        if (!tg_push16(instance, 0x85CAu)) return 0;
        instance->cpu.pc = 0x8693u;
        instance->instruction_count++;
        return 1;
    case 0x000F85CBu: /* A9 11 04 LDA #$0411 */
        word = 0x0411u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x85CEu;
        instance->instruction_count++;
        return 1;
    case 0x000F85CEu: /* 85 64 STA $64 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x64u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x85D0u;
        instance->instruction_count++;
        return 1;
    case 0x000F85D0u: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x85D3u;
        instance->instruction_count++;
        return 1;
    case 0x000F85D3u: /* 20 93 86 JSR $8693 */
        if (!tg_push16(instance, 0x85D5u)) return 0;
        instance->cpu.pc = 0x8693u;
        instance->instruction_count++;
        return 1;
    case 0x000F85D6u: /* 80 16 BRA $0F:85EE */
        instance->cpu.pc = 0x85EEu;
        instance->instruction_count++;
        return 1;
    case 0x000F85D8u: /* A9 11 06 LDA #$0611 */
        word = 0x0611u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x85DBu;
        instance->instruction_count++;
        return 1;
    case 0x000F85DBu: /* 85 64 STA $64 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x64u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x85DDu;
        instance->instruction_count++;
        return 1;
    case 0x000F85DDu: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x85E0u;
        instance->instruction_count++;
        return 1;
    case 0x000F85E0u: /* 20 93 86 JSR $8693 */
        if (!tg_push16(instance, 0x85E2u)) return 0;
        instance->cpu.pc = 0x8693u;
        instance->instruction_count++;
        return 1;
    case 0x000F85E3u: /* A9 11 04 LDA #$0411 */
        word = 0x0411u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x85E6u;
        instance->instruction_count++;
        return 1;
    case 0x000F85E6u: /* 85 64 STA $64 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x64u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x85E8u;
        instance->instruction_count++;
        return 1;
    case 0x000F85E8u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x85EBu;
        instance->instruction_count++;
        return 1;
    case 0x000F85EBu: /* 20 93 86 JSR $8693 */
        if (!tg_push16(instance, 0x85EDu)) return 0;
        instance->cpu.pc = 0x8693u;
        instance->instruction_count++;
        return 1;
    case 0x000F85EEu: /* 64 70 STZ $70 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x70u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x85F0u;
        instance->instruction_count++;
        return 1;
    case 0x000F85F0u: /* 64 72 STZ $72 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x72u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x85F2u;
        instance->instruction_count++;
        return 1;
    case 0x000F85F2u: /* AD 06 1F LDA $1F06 */
        /* Preserve the surrounding presentation; replace only its password. */
        instance->cpu.pc=tg_mod_career_password_stage(instance)?0x8626u:0x863Bu;
        instance->instruction_count++;return 1;
    case 0x000F85F5u: /* 29 1C 00 AND #$001C */
        word = 0x001Cu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x85F8u;
        instance->instruction_count++;
        return 1;
    case 0x000F85F8u: /* F0 41 BEQ $0F:863B */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x863Bu : 0x85FAu;
        instance->instruction_count++;
        return 1;
    case 0x000F85FAu: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0x85FBu;
        instance->instruction_count++;
        return 1;
    case 0x000F85FBu: /* E9 04 00 SBC #$0004 */
        word = 0x0004u;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0x85FEu;
        instance->instruction_count++;
        return 1;
    case 0x000F85FEu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x85FFu;
        instance->instruction_count++;
        return 1;
    case 0x000F85FFu: /* AE 10 1F LDX $1F10 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F10u), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8602u;
        instance->instruction_count++;
        return 1;
    case 0x000F8602u: /* F0 09 BEQ $0F:860D */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x860Du : 0x8604u;
        instance->instruction_count++;
        return 1;
    case 0x000F8604u: /* 69 38 00 ADC #$0038 */
        word = 0x0038u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x8607u;
        instance->instruction_count++;
        return 1;
    case 0x000F8607u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8608u;
        instance->instruction_count++;
        return 1;
    case 0x000F8608u: /* F0 03 BEQ $0F:860D */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x860Du : 0x860Au;
        instance->instruction_count++;
        return 1;
    case 0x000F860Au: /* 69 38 00 ADC #$0038 */
        word = 0x0038u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x860Du;
        instance->instruction_count++;
        return 1;
    case 0x000F860Du: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x860Eu;
        instance->instruction_count++;
        return 1;
    /* Version 26 map: password-table reader. $0D:C513 begins the 21 USA eight-character passwords. */
    case 0x000F860Eu: /* BF 13 C5 0D LDA $0DC513,X */
        if (!tg_bus_read16(instance, ((0x0DC513u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8612u;
        instance->instruction_count++;
        return 1;
    case 0x000F8612u: /* 85 68 STA $68 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x68u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8614u;
        instance->instruction_count++;
        return 1;
    case 0x000F8614u: /* BF 15 C5 0D LDA $0DC515,X */
        if (!tg_bus_read16(instance, ((0x0DC515u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8618u;
        instance->instruction_count++;
        return 1;
    case 0x000F8618u: /* 85 6A STA $6A */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x6Au) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x861Au;
        instance->instruction_count++;
        return 1;
    case 0x000F861Au: /* BF 17 C5 0D LDA $0DC517,X */
        if (!tg_bus_read16(instance, ((0x0DC517u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x861Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F861Eu: /* 85 6C STA $6C */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x6Cu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8620u;
        instance->instruction_count++;
        return 1;
    case 0x000F8620u: /* BF 19 C5 0D LDA $0DC519,X */
        if (!tg_bus_read16(instance, ((0x0DC519u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8624u;
        instance->instruction_count++;
        return 1;
    case 0x000F8624u: /* 85 6E STA $6E */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x6Eu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8626u;
        instance->instruction_count++;
        return 1;
    case 0x000F8626u: /* 64 70 STZ $70 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x70u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x8628u;
        instance->instruction_count++;
        return 1;
    case 0x000F8628u: /* 64 72 STZ $72 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x72u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x862Au;
        instance->instruction_count++;
        return 1;
    case 0x000F862Au: /* A9 10 1C LDA #$1C10 */
        word = 0x0110u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x862Du;
        instance->instruction_count++;
        return 1;
    case 0x000F862Du: /* 85 66 STA $66 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x862Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F862Fu: /* A2 66 00 LDX #$0066 */
        word = 0x0066u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8632u;
        instance->instruction_count++;
        return 1;
    case 0x000F8632u: /* 20 3E 9F JSR $9F3E */
        if (!tg_push16(instance, 0x8634u)) return 0;
        instance->cpu.pc = 0x9F3Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F8635u: /* A2 82 B4 LDX #$B482 */
        /* PASSWORD label shares the visible top margin with its code. */
        {static const char label[8]={80,65,83,83,87,79,82,68};unsigned n;for(n=0;n<8u;n++)instance->wram[0x68u+n]=(uint8_t)label[n];instance->wram[0x66u]=7u;instance->wram[0x67u]=1u;}
        word = 0x0066u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8638u;
        instance->instruction_count++;
        return 1;
    case 0x000F8638u: /* 20 3E 9F JSR $9F3E */
        if (!tg_push16(instance, 0x863Au)) return 0;
        instance->cpu.pc = 0x9F3Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F863Bu: /* 20 DD 9D JSR $9DDD */
        if (!tg_push16(instance, 0x863Du)) return 0;
        instance->cpu.pc = 0x9DDDu;
        instance->instruction_count++;
        return 1;
    case 0x000F863Eu: /* A9 84 00 LDA #$0084 */
        word = 0x0084u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8641u;
        instance->instruction_count++;
        return 1;
    case 0x000F8641u: /* 8D 24 04 STA $0424 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8644u;
        instance->instruction_count++;
        return 1;
    case 0x000F8644u: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8647u;
        instance->instruction_count++;
        return 1;
    case 0x000F8647u: /* 20 4D A2 JSR $A24D */
        if (!tg_push16(instance, 0x8649u)) return 0;
        instance->cpu.pc = 0xA24Du;
        instance->instruction_count++;
        return 1;
    case 0x000F864Au: /* 20 B2 9D JSR $9DB2 */
        if (!tg_push16(instance, 0x864Cu)) return 0;
        instance->cpu.pc = 0x9DB2u;
        instance->instruction_count++;
        return 1;
    case 0x000F864Du: /* 20 AC 9E JSR $9EAC */
        if(instance->mod_continue_screen==1u){instance->mod_continue_screen=2u;instance->mod_continue_released=0u;instance->mod_continue_previous=0u;}
        if (!tg_push16(instance, 0x864Fu)) return 0;
        instance->cpu.pc = 0x9EACu;
        instance->instruction_count++;
        return 1;
    case 0x000F8650u: /* 20 C5 9D JSR $9DC5 */
        if (!tg_push16(instance, 0x8652u)) return 0;
        instance->cpu.pc = 0x9DC5u;
        instance->instruction_count++;
        return 1;
    case 0x000F8653u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8655u;
        instance->instruction_count++;
        return 1;
    case 0x040F8655u: /* 9C 0E 21 STZ $210E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Eu), 0u)) return 0;
        instance->cpu.pc = 0x8658u;
        instance->instruction_count++;
        return 1;
    case 0x040F8658u: /* 9C 0E 21 STZ $210E */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Eu), 0u)) return 0;
        instance->cpu.pc = 0x865Bu;
        instance->instruction_count++;
        return 1;
    case 0x040F865Bu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x865Du;
        instance->instruction_count++;
        return 1;
    case 0x000F865Du: /* 20 5B 9C JSR $9C5B */
        if (!tg_push16(instance, 0x865Fu)) return 0;
        instance->cpu.pc = 0x9C5Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F8660u: /* 20 0E 82 JSR $820E */
        if (!tg_push16(instance, 0x8662u)) return 0;
        instance->cpu.pc = 0x820Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F8663u: /* 20 3E A2 JSR $A23E */
        if (!tg_push16(instance, 0x8665u)) return 0;
        instance->cpu.pc = 0xA23Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F8666u: /* 20 D7 90 JSR $90D7 */
        if (!tg_push16(instance, 0x8668u)) return 0;
        instance->cpu.pc = 0x90D7u;
        instance->instruction_count++;
        return 1;
    case 0x000F8669u: /* 68 PLA */
        if (!tg_pull16(instance, &word)) return 0;
        {unsigned destination=tg_mod_continue_complete(instance);if(destination){tg_set_acc16(instance,0u);tg_set_nz16(instance,0u);instance->cpu.pc=(uint16_t)destination;instance->instruction_count++;return 1;}}
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x866Au;
        instance->instruction_count++;
        return 1;
    case 0x000F866Au: /* D0 03 BNE $0F:866F */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x866Fu : 0x866Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F866Cu: /* 4C 8E 81 JMP $818E */
        instance->cpu.pc = 0x818Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F866Fu: /* 8D F6 1F STA $1FF6 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF6u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8672u;
        instance->instruction_count++;
        return 1;
    case 0x000F8672u: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8675u;
        instance->instruction_count++;
        return 1;
    case 0x000F8675u: /* 20 33 81 JSR $8133 */
        if (!tg_push16(instance, 0x8677u)) return 0;
        instance->cpu.pc = 0x8133u;
        instance->instruction_count++;
        return 1;
    case 0x000F8678u: /* AD 10 1F LDA $1F10 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F10u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x867Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F867Bu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x867Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F867Cu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x867Du;
        instance->instruction_count++;
        return 1;
    case 0x000F867Du: /* AD 06 1F LDA $1F06 */
        if(!instance->mod_time_trial_active&&!instance->mod_rally_active&&!tg_mod_rally_hide_failure_password(instance)){
            word=(uint16_t)tg_mod_career_retry_course(instance);tg_set_acc16(instance,word);tg_set_nz16(instance,word);
            instance->cpu.pc=0x8680u;instance->instruction_count++;return 1;
        }
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8680u;
        instance->instruction_count++;
        return 1;
    case 0x000F8680u: /* 29 1C 00 AND #$001C */
        word = 0x001Cu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8683u;
        instance->instruction_count++;
        return 1;
    case 0x000F8683u: /* 8D 08 1F STA $1F08 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F08u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8686u;
        instance->instruction_count++;
        return 1;
    case 0x000F8686u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8687u;
        instance->instruction_count++;
        return 1;
    case 0x000F8687u: /* 4A LSR A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
        word = (uint16_t)(word >> 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8688u;
        instance->instruction_count++;
        return 1;
    case 0x000F8688u: /* D9 0A 1F CMP $1F0A,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F0Au + instance->cpu.y)), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x868Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F868Bu: /* 90 03 BCC $0F:8690 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x8690u : 0x868Du;
        instance->instruction_count++;
        return 1;
    case 0x000F868Du: /* 99 0A 1F STA $1F0A,Y */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F0Au + instance->cpu.y)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8690u;
        instance->instruction_count++;
        return 1;
    case 0x000F8690u: /* 4C D7 83 JMP $83D7 */
        instance->cpu.pc = 0x83D7u;
        instance->instruction_count++;
        return 1;
    case 0x000F8693u: /* 85 81 STA $81 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8695u;
        instance->instruction_count++;
        return 1;
    case 0x000F8695u: /* 20 7B 9B JSR $9B7B */
        if (!tg_push16(instance, 0x8697u)) return 0;
        instance->cpu.pc = 0x9B7Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F8698u: /* A9 02 04 LDA #$0402 */
        word = 0x0402u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x869Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F869Bu: /* 85 66 STA $66 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x869Du;
        instance->instruction_count++;
        return 1;
    case 0x000F869Du: /* A9 20 20 LDA #$2020 */
        word = 0x2020u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x86A0u;
        instance->instruction_count++;
        return 1;
    case 0x000F86A0u: /* 85 70 STA $70 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x70u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x86A2u;
        instance->instruction_count++;
        return 1;
    case 0x000F86A2u: /* 85 72 STA $72 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x72u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x86A4u;
        instance->instruction_count++;
        return 1;
    case 0x000F86A4u: /* A9 54 48 LDA #$4854 */
        word = 0x4854u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x86A7u;
        instance->instruction_count++;
        return 1;
    case 0x000F86A7u: /* 85 73 STA $73 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x73u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x86A9u;
        instance->instruction_count++;
        return 1;
    case 0x000F86A9u: /* A5 81 LDA $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x86ABu;
        instance->instruction_count++;
        return 1;
    case 0x000F86ABu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x86ACu;
        instance->instruction_count++;
        return 1;
    case 0x000F86ACu: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0x86ADu;
        instance->instruction_count++;
        return 1;
    case 0x000F86ADu: /* B9 F8 1F LDA $1FF8,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1FF8u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x86B0u;
        instance->instruction_count++;
        return 1;
    case 0x000F86B0u: /* C9 04 00 CMP #$0004 */
        word = 0x0004u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x86B3u;
        instance->instruction_count++;
        return 1;
    case 0x000F86B3u: /* B0 16 BCS $0F:86CB */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x86CBu : 0x86B5u;
        instance->instruction_count++;
        return 1;
    case 0x000F86B5u: /* C9 02 00 CMP #$0002 */
        word = 0x0002u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x86B8u;
        instance->instruction_count++;
        return 1;
    case 0x000F86B8u: /* F0 07 BEQ $0F:86C1 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x86C1u : 0x86BAu;
        instance->instruction_count++;
        return 1;
    case 0x000F86BAu: /* 90 0A BCC $0F:86C6 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x86C6u : 0x86BCu;
        instance->instruction_count++;
        return 1;
    case 0x000F86BCu: /* A2 52 44 LDX #$4452 */
        word = 0x4452u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x86BFu;
        instance->instruction_count++;
        return 1;
    case 0x000F86BFu: /* 80 08 BRA $0F:86C9 */
        instance->cpu.pc = 0x86C9u;
        instance->instruction_count++;
        return 1;
    case 0x000F86C1u: /* A2 4E 44 LDX #$444E */
        word = 0x444Eu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x86C4u;
        instance->instruction_count++;
        return 1;
    case 0x000F86C4u: /* 80 03 BRA $0F:86C9 */
        instance->cpu.pc = 0x86C9u;
        instance->instruction_count++;
        return 1;
    case 0x000F86C6u: /* A2 53 54 LDX #$5453 */
        word = 0x5453u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x86C9u;
        instance->instruction_count++;
        return 1;
    case 0x000F86C9u: /* 86 73 STX $73 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x73u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x86CBu;
        instance->instruction_count++;
        return 1;
    case 0x000F86CBu: /* 20 B6 8B JSR $8BB6 */
        if (!tg_push16(instance, 0x86CDu)) return 0;
        instance->cpu.pc = 0x8BB6u;
        instance->instruction_count++;
        return 1;
    case 0x000F86CEu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x86D0u;
        instance->instruction_count++;
        return 1;
    case 0x040F86D0u: /* C9 30 CMP #$30 */
        byte = 0x30u;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x86D2u;
        instance->instruction_count++;
        return 1;
    case 0x040F86D2u: /* D0 02 BNE $0F:86D6 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x86D6u : 0x86D4u;
        instance->instruction_count++;
        return 1;
    case 0x040F86D4u: /* A9 20 LDA #$20 */
        byte = 0x20u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x86D6u;
        instance->instruction_count++;
        return 1;
    case 0x040F86D6u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x86D8u;
        instance->instruction_count++;
        return 1;
    case 0x000F86D8u: /* 85 71 STA $71 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x71u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x86DAu;
        instance->instruction_count++;
        return 1;
    case 0x000F86DAu: /* A2 64 00 LDX #$0064 */
        word = 0x0064u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x86DDu;
        instance->instruction_count++;
        return 1;
    case 0x000F86DDu: /* A4 81 LDY $81 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x81u) & 0xFFFFu), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x86DFu;
        instance->instruction_count++;
        return 1;
    case 0x000F86DFu: /* F0 03 BEQ $0F:86E4 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x86E4u : 0x86E1u;
        instance->instruction_count++;
        return 1;
    case 0x000F86E1u: /* A0 38 00 LDY #$0038 */
        word = 0x0038u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x86E4u;
        instance->instruction_count++;
        return 1;
    case 0x000F86E4u: /* 4C D3 9E JMP $9ED3 */
        instance->cpu.pc = 0x9ED3u;
        instance->instruction_count++;
        return 1;
    case 0x000F86E7u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x86E9u;
        instance->instruction_count++;
        return 1;
    /* PLAYER/COMPUTER order-slot scan: walk all 20 entries of the confirmed
       $1F62 racer-ID permutation from slot 19 down to 0.  IDs below 2 are
       PLAYER/COMPUTER; $0F:86F6 writes their slot index to $1FF8+ID*2,
       then $0F:86FC/$86FF increment the two low bytes.  This proves the
       immediate one-based slot calculation, but does not equate this staging
       storage with the separately observed HUD fields $011A/$012C. */
    case 0x040F86E9u: /* A0 13 00 LDY #$0013 */
        word = 0x0013u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x86ECu;
        instance->instruction_count++;
        return 1;
    case 0x040F86ECu: /* B9 62 1F LDA $1F62,Y */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F62u + instance->cpu.y)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x86EFu;
        instance->instruction_count++;
        return 1;
    case 0x040F86EFu: /* C9 02 CMP #$02 */
        byte = 0x02u;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x86F1u;
        instance->instruction_count++;
        return 1;
    case 0x040F86F1u: /* B0 06 BCS $0F:86F9 */
        instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0x86F9u : 0x86F3u;
        instance->instruction_count++;
        return 1;
    case 0x040F86F3u: /* 0A ASL A */
        byte = tg_acc8(instance);
        tg_set_flag(instance, TG_P_C, (byte & 0x80u) != 0u);
        byte = (uint8_t)(byte << 1);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x86F4u;
        instance->instruction_count++;
        return 1;
    case 0x040F86F4u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0x86F5u;
        instance->instruction_count++;
        return 1;
    case 0x040F86F5u: /* 98 TYA */
        tg_set_acc8(instance, (uint8_t)instance->cpu.y);
        tg_set_nz8(instance, (uint8_t)tg_acc8(instance));
        instance->cpu.pc = 0x86F6u;
        instance->instruction_count++;
        return 1;
    case 0x040F86F6u: /* 9D F8 1F STA $1FF8,X */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1FF8u + instance->cpu.x)), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x86F9u;
        instance->instruction_count++;
        return 1;
    case 0x040F86F9u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x86FAu;
        instance->instruction_count++;
        return 1;
    case 0x040F86FAu: /* 10 F0 BPL $0F:86EC */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x86ECu : 0x86FCu;
        instance->instruction_count++;
        return 1;
    case 0x040F86FCu: /* EE F8 1F INC $1FF8 */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF8u), &byte)) return 0;
        byte = (uint8_t)(byte + 1u);
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF8u), byte)) return 0;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x86FFu;
        instance->instruction_count++;
        return 1;
    case 0x040F86FFu: /* EE FA 1F INC $1FFA */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FFAu), &byte)) return 0;
        byte = (uint8_t)(byte + 1u);
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FFAu), byte)) return 0;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8702u;
        instance->instruction_count++;
        return 1;
    case 0x040F8702u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8704u;
        instance->instruction_count++;
        return 1;
    case 0x000F8704u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F8705u: /* A2 1E 00 LDX #$001E */
        word = 0x001Eu;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8708u;
        instance->instruction_count++;
        return 1;
    case 0x000F8708u: /* BF 66 FD 0E LDA $0EFD66,X */
        if (!tg_bus_read16(instance, ((0x0EFD66u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x870Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F870Cu: /* 9D 4C 06 STA $064C,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x064Cu + instance->cpu.x)), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x870Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F870Fu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8710u;
        instance->instruction_count++;
        return 1;
    case 0x000F8710u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8711u;
        instance->instruction_count++;
        return 1;
    case 0x000F8711u: /* 10 F5 BPL $0F:8708 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8708u : 0x8713u;
        instance->instruction_count++;
        return 1;
    case 0x000F8713u: /* A9 3D 23 LDA #$233D */
        word = 0x233Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8716u;
        instance->instruction_count++;
        return 1;
    case 0x000F8716u: /* 8D 4E 06 STA $064E */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x064Eu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8719u;
        instance->instruction_count++;
        return 1;
    case 0x000F8719u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F871Au: /* EE 04 1F INC $1F04 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), &word)) return 0;
        word = (uint16_t)(word + 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x871Du;
        instance->instruction_count++;
        return 1;
    case 0x000F871Du: /* A0 04 00 LDY #$0004 */
        word = 0x0004u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8720u;
        instance->instruction_count++;
        return 1;
    case 0x000F8720u: /* B9 12 1F LDA $1F12,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F12u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8723u;
        instance->instruction_count++;
        return 1;
    case 0x000F8723u: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8726u;
        instance->instruction_count++;
        return 1;
    case 0x000F8726u: /* CD 04 1F CMP $1F04 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x8729u;
        instance->instruction_count++;
        return 1;
    case 0x000F8729u: /* 90 04 BCC $0F:872F */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x872Fu : 0x872Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F872Bu: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x872Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F872Cu: /* 10 F2 BPL $0F:8720 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8720u : 0x872Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F872Eu: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0x872Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F872Fu: /* CE 04 1F DEC $1F04 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8732u;
        instance->instruction_count++;
        return 1;
    case 0x000F8732u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F8733u: /* EE 04 1F INC $1F04 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), &word)) return 0;
        word = (uint16_t)(word + 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8736u;
        instance->instruction_count++;
        return 1;
    case 0x000F8736u: /* EE 06 1F INC $1F06 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
        word = (uint16_t)(word + 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8739u;
        instance->instruction_count++;
        return 1;
    case 0x000F8739u: /* AD 06 1F LDA $1F06 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x873Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F873Cu: /* 29 1F 00 AND #$001F */
        word = 0x001Fu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x873Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F873Fu: /* 8D 06 1F STA $1F06 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8742u;
        instance->instruction_count++;
        return 1;
    case 0x000F8742u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x8743u;
        instance->instruction_count++;
        return 1;
    case 0x000F8743u: /* 29 03 00 AND #$0003 */
        word = 0x0003u;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8746u;
        instance->instruction_count++;
        return 1;
    case 0x000F8746u: /* F0 08 BEQ $0F:8750 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x8750u : 0x8748u;
        instance->instruction_count++;
        return 1;
    case 0x000F8748u: /* CE 04 1F DEC $1F04 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x874Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F874Bu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x874Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F874Cu: /* A9 01 00 LDA #$0001 */
        word = 0x0001u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x874Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F874Fu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F8750u: /* A2 12 00 LDX #$0012 */
        if(!instance->mod_time_trial_active&&!instance->mod_rally_active){
            tg_set_flag(instance,TG_P_C,!tg_mod_career_country_passes(instance));
            instance->cpu.pc=0x877Au;instance->instruction_count++;return 1;
        }
        word = 0x0012u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8753u;
        instance->instruction_count++;
        return 1;
    case 0x000F8753u: /* 9E 4E 1F STZ $1F4E,X */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F4Eu + instance->cpu.x)), 0u)) return 0;
        instance->cpu.pc = 0x8756u;
        instance->instruction_count++;
        return 1;
    case 0x000F8756u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8757u;
        instance->instruction_count++;
        return 1;
    case 0x000F8757u: /* 10 FA BPL $0F:8753 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8753u : 0x8759u;
        instance->instruction_count++;
        return 1;
    case 0x000F8759u: /* A0 02 00 LDY #$0002 */
word = 0x0002u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x875Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F875Cu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x875Eu;
        instance->instruction_count++;
        return 1;
    case 0x040F875Eu: /* B9 62 1F LDA $1F62,Y */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F62u + instance->cpu.y)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8761u;
        instance->instruction_count++;
        return 1;
    case 0x040F8761u: /* D9 63 1F CMP $1F63,Y */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F63u + instance->cpu.y)), &byte)) return 0;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x8764u;
        instance->instruction_count++;
        return 1;
    case 0x040F8764u: /* D0 03 BNE $0F:8769 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8769u : 0x8766u;
        instance->instruction_count++;
        return 1;
    case 0x040F8766u: /* C8 INY */
        word = (uint16_t)(instance->cpu.y + 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8767u;
        instance->instruction_count++;
        return 1;
    case 0x040F8767u: /* D0 F5 BNE $0F:875E */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x875Eu : 0x8769u;
        instance->instruction_count++;
        return 1;
    case 0x040F8769u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x876Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F876Bu: /* B9 62 1F LDA $1F62,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F62u + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x876Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F876Eu: /* 29 FF 00 AND #$00FF */
        word = 0x00FFu;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8771u;
        instance->instruction_count++;
        return 1;
    case 0x000F8771u: /* CD 04 1F CMP $1F04 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), &word)) return 0;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x8774u;
        instance->instruction_count++;
        return 1;
    case 0x000F8774u: /* 90 04 BCC $0F:877A */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x877Au : 0x8776u;
        instance->instruction_count++;
        return 1;
    case 0x000F8776u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8777u;
        instance->instruction_count++;
        return 1;
    case 0x000F8777u: /* 10 F2 BPL $0F:876B */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x876Bu : 0x8779u;
        instance->instruction_count++;
        return 1;
    case 0x000F8779u: /* 38 SEC */
        tg_set_flag(instance, TG_P_C, 1);
        instance->cpu.pc = 0x877Au;
        instance->instruction_count++;
        return 1;
    case 0x000F877Au: /* CE 04 1F DEC $1F04 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), &word)) return 0;
        word = (uint16_t)(word - 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F04u), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x877Du;
        instance->instruction_count++;
        return 1;
    case 0x000F877Du: /* A9 00 00 LDA #$0000 */
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8780u;
        instance->instruction_count++;
        return 1;
    case 0x000F8780u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F8781u: /* 85 48 STA $48 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8783u;
        instance->instruction_count++;
        return 1;
    case 0x000F8783u: /* 85 66 STA $66 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8785u;
        instance->instruction_count++;
        return 1;
    case 0x000F8785u: /* A2 1A 00 LDX #$001A */
        word = 0x001Au;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8788u;
        instance->instruction_count++;
        return 1;
    case 0x000F8788u: /* BF 00 C4 0D LDA $0DC400,X */
        if (!tg_bus_read16(instance, ((0x0DC400u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x878Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F878Cu: /* 95 68 STA $68,X */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x68u + instance->cpu.x) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x878Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F878Eu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x878Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F878Fu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8790u;
        instance->instruction_count++;
        return 1;
    case 0x000F8790u: /* 10 F6 BPL $0F:8788 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8788u : 0x8792u;
        instance->instruction_count++;
        return 1;
    case 0x000F8792u: /* A0 0A 00 LDY #$000A */
        word = 0x000Au;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8795u;
        instance->instruction_count++;
        return 1;
    case 0x000F8795u: /* 5A PHY */
        if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0x8796u;
        instance->instruction_count++;
        return 1;
    case 0x000F8796u: /* A2 66 00 LDX #$0066 */
        word = 0x0066u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8799u;
        instance->instruction_count++;
        return 1;
    case 0x000F8799u: /* 20 3E 9F JSR $9F3E */
        if (!tg_push16(instance, 0x879Bu)) return 0;
        instance->cpu.pc = 0x9F3Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F879Cu: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x879Du;
        instance->instruction_count++;
        return 1;
    case 0x000F879Du: /* A5 66 LDA $66 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x879Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F879Fu: /* 69 00 02 ADC #$0200 */
        word = 0x0200u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x87A2u;
        instance->instruction_count++;
        return 1;
    case 0x000F87A2u: /* 85 66 STA $66 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x87A4u;
        instance->instruction_count++;
        return 1;
    case 0x000F87A4u: /* 7A PLY */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87A5u;
        instance->instruction_count++;
        return 1;
    case 0x000F87A5u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87A6u;
        instance->instruction_count++;
        return 1;
    case 0x000F87A6u: /* D0 ED BNE $0F:8795 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8795u : 0x87A8u;
        instance->instruction_count++;
        return 1;
    case 0x000F87A8u: /* 64 70 STZ $70 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x70u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x87AAu;
        instance->instruction_count++;
        return 1;
    case 0x000F87AAu: /* 64 72 STZ $72 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x72u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x87ACu;
        instance->instruction_count++;
        return 1;
    case 0x000F87ACu: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F87ADu: /* 85 48 STA $48 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x48u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x87AFu;
        instance->instruction_count++;
        return 1;
    case 0x000F87AFu: /* 85 66 STA $66 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x87B1u;
        instance->instruction_count++;
        return 1;
    case 0x000F87B1u: /* A2 12 00 LDX #$0012 */
        word = 0x0012u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87B4u;
        instance->instruction_count++;
        return 1;
    case 0x000F87B4u: /* BF 08 C4 0D LDA $0DC408,X */
        if (!tg_bus_read16(instance, ((0x0DC408u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87B8u;
        instance->instruction_count++;
        return 1;
    case 0x000F87B8u: /* 95 68 STA $68,X */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x68u + instance->cpu.x) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x87BAu;
        instance->instruction_count++;
        return 1;
    case 0x000F87BAu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87BBu;
        instance->instruction_count++;
        return 1;
    case 0x000F87BBu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87BCu;
        instance->instruction_count++;
        return 1;
    case 0x000F87BCu: /* 10 F6 BPL $0F:87B4 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x87B4u : 0x87BEu;
        instance->instruction_count++;
        return 1;
    case 0x000F87BEu: /* A0 14 00 LDY #$0014 */
        word = 0x0014u;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87C1u;
        instance->instruction_count++;
        return 1;
    case 0x000F87C1u: /* 5A PHY */
        if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
        instance->cpu.pc = 0x87C2u;
        instance->instruction_count++;
        return 1;
    case 0x000F87C2u: /* A2 66 00 LDX #$0066 */
        word = 0x0066u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87C5u;
        instance->instruction_count++;
        return 1;
    case 0x000F87C5u: /* 20 3E 9F JSR $9F3E */
        if (!tg_push16(instance, 0x87C7u)) return 0;
        instance->cpu.pc = 0x9F3Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F87C8u: /* 18 CLC */
        tg_set_flag(instance, TG_P_C, 0);
        instance->cpu.pc = 0x87C9u;
        instance->instruction_count++;
        return 1;
    case 0x000F87C9u: /* A5 66 LDA $66 */
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87CBu;
        instance->instruction_count++;
        return 1;
    case 0x000F87CBu: /* 69 00 01 ADC #$0100 */
        word = 0x0100u;
        tg_adc16(instance, word);
        instance->cpu.pc = 0x87CEu;
        instance->instruction_count++;
        return 1;
    case 0x000F87CEu: /* 85 66 STA $66 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x87D0u;
        instance->instruction_count++;
        return 1;
    case 0x000F87D0u: /* 7A PLY */
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87D1u;
        instance->instruction_count++;
        return 1;
    case 0x000F87D1u: /* 88 DEY */
        word = (uint16_t)(instance->cpu.y - 1u);
        tg_set_index16(instance, &instance->cpu.y, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87D2u;
        instance->instruction_count++;
        return 1;
    case 0x000F87D2u: /* D0 ED BNE $0F:87C1 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x87C1u : 0x87D4u;
        instance->instruction_count++;
        return 1;
    case 0x000F87D4u: /* 64 70 STZ $70 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x70u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x87D6u;
        instance->instruction_count++;
        return 1;
    case 0x000F87D6u: /* 64 72 STZ $72 */
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x72u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x87D8u;
        instance->instruction_count++;
        return 1;
    case 0x000F87D8u: /* 60 RTS */
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.pc = (uint16_t)(word + 1u);
        instance->instruction_count++;
        return 1;
    case 0x000F87D9u: /* A2 07 00 LDX #$0007 */
        word = 0x0007u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87DCu;
        instance->instruction_count++;
        return 1;
    case 0x000F87DCu: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x87DEu;
        instance->instruction_count++;
        return 1;
    case 0x040F87DEu: /* BD 86 1F LDA $1F86,X */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F86u + instance->cpu.x)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x87E1u;
        instance->instruction_count++;
        return 1;
    case 0x040F87E1u: /* C9 20 CMP #$20 */
        byte = 0x20u;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x87E3u;
        instance->instruction_count++;
        return 1;
    case 0x040F87E3u: /* D0 08 BNE $0F:87ED */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x87EDu : 0x87E5u;
        instance->instruction_count++;
        return 1;
    case 0x040F87E5u: /* A9 3D LDA #$3D */
        byte = 0x3Du;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x87E7u;
        instance->instruction_count++;
        return 1;
    case 0x040F87E7u: /* 9D 86 1F STA $1F86,X */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1F86u + instance->cpu.x)), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x87EAu;
        instance->instruction_count++;
        return 1;
    case 0x040F87EAu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87EBu;
        instance->instruction_count++;
        return 1;
    case 0x040F87EBu: /* 10 F1 BPL $0F:87DE */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x87DEu : 0x87EDu;
        instance->instruction_count++;
        return 1;
    case 0x040F87EDu: /* A2 07 00 LDX #$0007 */
        word = 0x0007u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87F0u;
        instance->instruction_count++;
        return 1;
    case 0x040F87F0u: /* BD A3 1F LDA $1FA3,X */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1FA3u + instance->cpu.x)), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x87F3u;
        instance->instruction_count++;
        return 1;
    case 0x040F87F3u: /* C9 20 CMP #$20 */
        byte = 0x20u;
        tg_compare8(instance, tg_acc8(instance), byte);
        instance->cpu.pc = 0x87F5u;
        instance->instruction_count++;
        return 1;
    case 0x040F87F5u: /* D0 08 BNE $0F:87FF */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x87FFu : 0x87F7u;
        instance->instruction_count++;
        return 1;
    case 0x040F87F7u: /* A9 3D LDA #$3D */
        byte = 0x3Du;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x87F9u;
        instance->instruction_count++;
        return 1;
    case 0x040F87F9u: /* 9D A3 1F STA $1FA3,X */
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1FA3u + instance->cpu.x)), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x87FCu;
        instance->instruction_count++;
        return 1;
    case 0x040F87FCu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x87FDu;
        instance->instruction_count++;
        return 1;
    case 0x040F87FDu: /* 10 F1 BPL $0F:87F0 */
        instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x87F0u : 0x87FFu;
        instance->instruction_count++;
        return 1;
    case 0x040F87FFu: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8801u;
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
