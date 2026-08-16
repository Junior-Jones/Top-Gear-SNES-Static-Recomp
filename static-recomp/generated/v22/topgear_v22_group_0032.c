/* Generated ROM-wide static W65C816 shard. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

int tg_v22_group_0032(struct TopGearRecomp *instance){
    uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
    if(!instance) return 0;
    (void)address; (void)base24; (void)word; (void)byte;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x0000C801u: /* A9 08 34 LDA #$3408 */
        word = 0x3408u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC804u;
        instance->instruction_count++;
        return 1;
    case 0x0000C804u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC807u;
        instance->instruction_count++;
        return 1;
    case 0x0000C807u: /* A9 09 34 LDA #$3409 */
        word = 0x3409u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC80Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C80Au: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC80Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C80Du: /* A9 0A 34 LDA #$340A */
        word = 0x340Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC810u;
        instance->instruction_count++;
        return 1;
    case 0x0000C810u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC813u;
        instance->instruction_count++;
        return 1;
    case 0x0000C813u: /* A9 0B 34 LDA #$340B */
        word = 0x340Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC816u;
        instance->instruction_count++;
        return 1;
    case 0x0000C816u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC819u;
        instance->instruction_count++;
        return 1;
    case 0x0000C819u: /* A9 0C 34 LDA #$340C */
        word = 0x340Cu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC81Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C81Cu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC81Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C81Fu: /* A9 54 0C LDA #$0C54 */
        word = 0x0C54u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC822u;
        instance->instruction_count++;
        return 1;
    case 0x0000C822u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC825u;
        instance->instruction_count++;
        return 1;
    case 0x0000C825u: /* A9 0D 30 LDA #$300D */
        word = 0x300Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC828u;
        instance->instruction_count++;
        return 1;
    case 0x0000C828u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC82Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C82Bu: /* A9 0E 30 LDA #$300E */
        word = 0x300Eu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC82Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C82Eu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC831u;
        instance->instruction_count++;
        return 1;
    case 0x0000C831u: /* A9 74 0C LDA #$0C74 */
        word = 0x0C74u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC834u;
        instance->instruction_count++;
        return 1;
    case 0x0000C834u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC837u;
        instance->instruction_count++;
        return 1;
    case 0x0000C837u: /* A9 0F 30 LDA #$300F */
        word = 0x300Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC83Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C83Au: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC83Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C83Du: /* A9 81 0D LDA #$0D81 */
        word = 0x0D81u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC840u;
        instance->instruction_count++;
        return 1;
    case 0x0000C840u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC843u;
        instance->instruction_count++;
        return 1;
    case 0x0000C843u: /* 2C F6 1F BIT $1FF6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF6u), &word)) return 0;
        tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
        tg_set_flag(instance, TG_P_N, (word & 0x8000u) != 0u);
        tg_set_flag(instance, TG_P_V, (word & 0x4000u) != 0u);
        instance->cpu.pc = 0xC846u;
        instance->instruction_count++;
        return 1;
    case 0x0000C846u: /* 30 05 BMI $00:C84D */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xC84Du : 0xC848u;
        instance->instruction_count++;
        return 1;
    case 0x0000C848u: /* AE 7A 1F LDX $1F7A */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F7Au), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC84Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C84Bu: /* D0 1A BNE $00:C867 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xC867u : 0xC84Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C84Du: /* A9 4B 2C LDA #$2C4B */
        word = 0x2C4Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC850u;
        instance->instruction_count++;
        return 1;
    case 0x0000C850u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC853u;
        instance->instruction_count++;
        return 1;
    case 0x0000C853u: /* A9 4C 2C LDA #$2C4C */
        word = 0x2C4Cu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC856u;
        instance->instruction_count++;
        return 1;
    case 0x0000C856u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC859u;
        instance->instruction_count++;
        return 1;
    case 0x0000C859u: /* A9 44 2C LDA #$2C44 */
        word = 0x2C44u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC85Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C85Cu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC85Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C85Fu: /* A9 35 2C LDA #$2C35 */
        word = 0x2C35u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC862u;
        instance->instruction_count++;
        return 1;
    case 0x0000C862u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC865u;
        instance->instruction_count++;
        return 1;
    case 0x0000C865u: /* 80 18 BRA $00:C87F */
        instance->cpu.pc = 0xC87Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C867u: /* A9 49 2C LDA #$2C49 */
        word = 0x2C49u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC86Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C86Au: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC86Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C86Du: /* A9 4A 2C LDA #$2C4A */
        word = 0x2C4Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC870u;
        instance->instruction_count++;
        return 1;
    case 0x0000C870u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC873u;
        instance->instruction_count++;
        return 1;
    case 0x0000C873u: /* A9 4B 2C LDA #$2C4B */
        word = 0x2C4Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC876u;
        instance->instruction_count++;
        return 1;
    case 0x0000C876u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC879u;
        instance->instruction_count++;
        return 1;
    case 0x0000C879u: /* A9 47 2C LDA #$2C47 */
        word = 0x2C47u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC87Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C87Cu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC87Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C87Fu: /* A9 66 0D LDA #$0D66 */
        word = 0x0D66u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC882u;
        instance->instruction_count++;
        return 1;
    case 0x0000C882u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC885u;
        instance->instruction_count++;
        return 1;
    case 0x0000C885u: /* A9 50 2C LDA #$2C50 */
        word = 0x2C50u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC888u;
        instance->instruction_count++;
        return 1;
    case 0x0000C888u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC88Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C88Bu: /* A9 85 0D LDA #$0D85 */
        word = 0x0D85u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC88Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C88Eu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC891u;
        instance->instruction_count++;
        return 1;
    case 0x0000C891u: /* A9 41 2C LDA #$2C41 */
        word = 0x2C41u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC894u;
        instance->instruction_count++;
        return 1;
    case 0x0000C894u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC897u;
        instance->instruction_count++;
        return 1;
    case 0x0000C897u: /* A9 51 2C LDA #$2C51 */
        word = 0x2C51u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC89Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C89Au: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC89Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C89Du: /* A9 41 0D LDA #$0D41 */
        word = 0x0D41u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8A0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8A0u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC8A3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8A3u: /* A9 4D 2C LDA #$2C4D */
        word = 0x2C4Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8A6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8A6u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC8A9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8A9u: /* A9 42 2C LDA #$2C42 */
        word = 0x2C42u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8ACu;
        instance->instruction_count++;
        return 1;
    case 0x0000C8ACu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC8AFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C8AFu: /* A9 38 2C LDA #$2C38 */
        word = 0x2C38u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8B2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8B2u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC8B5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8B5u: /* AD 7A 1E LDA $1E7A */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E7Au), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8B8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8B8u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8B9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8B9u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC8BAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C8BAu: /* C9 04 00 CMP #$0004 */
        word = 0x0004u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xC8BDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C8BDu: /* 90 03 BCC $00:C8C2 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xC8C2u : 0xC8BFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C8BFu: /* A9 03 00 LDA #$0003 */
        word = 0x0003u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8C2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8C2u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8C3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8C3u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8C4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8C4u: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xC8C5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8C5u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC8C6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8C6u: /* C9 0A 00 CMP #$000A */
        word = 0x000Au;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xC8C9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8C9u: /* 90 3F BCC $00:C90A */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xC90Au : 0xC8CBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C8CBu: /* E9 0A 00 SBC #$000A */
        word = 0x000Au;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xC8CEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C8CEu: /* C9 0A 00 CMP #$000A */
        word = 0x000Au;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xC8D1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8D1u: /* 90 1E BCC $00:C8F1 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xC8F1u : 0xC8D3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8D3u: /* E9 0A 00 SBC #$000A */
        word = 0x000Au;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xC8D6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8D6u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC8D7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8D7u: /* A9 79 0D LDA #$0D79 */
        word = 0x0D79u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8DAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C8DAu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC8DDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C8DDu: /* A9 52 2C LDA #$2C52 */
        word = 0x2C52u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8E0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8E0u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC8E3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8E3u: /* A9 99 0D LDA #$0D99 */
        word = 0x0D99u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8E6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8E6u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC8E9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8E9u: /* A9 53 2C LDA #$2C53 */
        word = 0x2C53u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8ECu;
        instance->instruction_count++;
        return 1;
    case 0x0000C8ECu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC8EFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C8EFu: /* 80 19 BRA $00:C90A */
        instance->cpu.pc = 0xC90Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C8F1u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC8F2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8F2u: /* A9 79 0D LDA #$0D79 */
        word = 0x0D79u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8F5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8F5u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC8F8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C8F8u: /* A9 50 2C LDA #$2C50 */
        word = 0x2C50u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC8FBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C8FBu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC8FEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C8FEu: /* A9 99 0D LDA #$0D99 */
        word = 0x0D99u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC901u;
        instance->instruction_count++;
        return 1;
    case 0x0000C901u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC904u;
        instance->instruction_count++;
        return 1;
    case 0x0000C904u: /* A9 51 2C LDA #$2C51 */
        word = 0x2C51u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC907u;
        instance->instruction_count++;
        return 1;
    case 0x0000C907u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC90Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C90Au: /* A9 7A 0D LDA #$0D7A */
        word = 0x0D7Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC90Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C90Du: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC910u;
        instance->instruction_count++;
        return 1;
    case 0x0000C910u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC911u;
        instance->instruction_count++;
        return 1;
    case 0x0000C911u: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC912u;
        instance->instruction_count++;
        return 1;
    case 0x0000C912u: /* 69 4E 2C ADC #$2C4E */
        word = 0x2C4Eu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xC915u;
        instance->instruction_count++;
        return 1;
    case 0x0000C915u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC918u;
        instance->instruction_count++;
        return 1;
    case 0x0000C918u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xC919u;
        instance->instruction_count++;
        return 1;
    case 0x0000C919u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC91Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C91Au: /* A9 9A 0D LDA #$0D9A */
        word = 0x0D9Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC91Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C91Du: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC920u;
        instance->instruction_count++;
        return 1;
    case 0x0000C920u: /* 8E 18 21 STX $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xC923u;
        instance->instruction_count++;
        return 1;
    case 0x0000C923u: /* B9 8B CC LDA $CC8B,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xCC8Bu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC926u;
        instance->instruction_count++;
        return 1;
    case 0x0000C926u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC929u;
        instance->instruction_count++;
        return 1;
    case 0x0000C929u: /* B9 8D CC LDA $CC8D,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xCC8Du + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC92Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C92Cu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC92Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C92Fu: /* A9 17 0E LDA #$0E17 */
        word = 0x0E17u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC932u;
        instance->instruction_count++;
        return 1;
    case 0x0000C932u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC935u;
        instance->instruction_count++;
        return 1;
    case 0x0000C935u: /* A9 17 2C LDA #$2C17 */
        word = 0x2C17u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC938u;
        instance->instruction_count++;
        return 1;
    case 0x0000C938u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC93Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C93Bu: /* A9 18 2C LDA #$2C18 */
        word = 0x2C18u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC93Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C93Eu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC941u;
        instance->instruction_count++;
        return 1;
    case 0x0000C941u: /* A9 17 2C LDA #$2C17 */
        word = 0x2C17u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC944u;
        instance->instruction_count++;
        return 1;
    case 0x0000C944u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC947u;
        instance->instruction_count++;
        return 1;
    case 0x0000C947u: /* A9 18 2C LDA #$2C18 */
        word = 0x2C18u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC94Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C94Au: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC94Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C94Du: /* A9 17 2C LDA #$2C17 */
        word = 0x2C17u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC950u;
        instance->instruction_count++;
        return 1;
    case 0x0000C950u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC953u;
        instance->instruction_count++;
        return 1;
    case 0x0000C953u: /* A9 18 2C LDA #$2C18 */
        word = 0x2C18u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC956u;
        instance->instruction_count++;
        return 1;
    case 0x0000C956u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC959u;
        instance->instruction_count++;
        return 1;
    case 0x0000C959u: /* A9 37 0E LDA #$0E37 */
        word = 0x0E37u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC95Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C95Cu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC95Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C95Fu: /* A9 19 2C LDA #$2C19 */
        word = 0x2C19u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC962u;
        instance->instruction_count++;
        return 1;
    case 0x0000C962u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC965u;
        instance->instruction_count++;
        return 1;
    case 0x0000C965u: /* A9 1A 2C LDA #$2C1A */
        word = 0x2C1Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC968u;
        instance->instruction_count++;
        return 1;
    case 0x0000C968u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC96Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C96Bu: /* A9 19 2C LDA #$2C19 */
        word = 0x2C19u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC96Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C96Eu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC971u;
        instance->instruction_count++;
        return 1;
    case 0x0000C971u: /* A9 1A 2C LDA #$2C1A */
        word = 0x2C1Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC974u;
        instance->instruction_count++;
        return 1;
    case 0x0000C974u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC977u;
        instance->instruction_count++;
        return 1;
    case 0x0000C977u: /* A9 19 2C LDA #$2C19 */
        word = 0x2C19u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC97Au;
        instance->instruction_count++;
        return 1;
    case 0x0000C97Au: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC97Du;
        instance->instruction_count++;
        return 1;
    case 0x0000C97Du: /* A9 1A 2C LDA #$2C1A */
        word = 0x2C1Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC980u;
        instance->instruction_count++;
        return 1;
    case 0x0000C980u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC983u;
        instance->instruction_count++;
        return 1;
    case 0x0000C983u: /* A9 57 0E LDA #$0E57 */
        word = 0x0E57u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC986u;
        instance->instruction_count++;
        return 1;
    case 0x0000C986u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC989u;
        instance->instruction_count++;
        return 1;
    case 0x0000C989u: /* A9 35 2C LDA #$2C35 */
        word = 0x2C35u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC98Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000C98Cu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC98Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000C98Fu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC992u;
        instance->instruction_count++;
        return 1;
    case 0x0000C992u: /* A9 3F 2C LDA #$2C3F */
        word = 0x2C3Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC995u;
        instance->instruction_count++;
        return 1;
    case 0x0000C995u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC998u;
        instance->instruction_count++;
        return 1;
    case 0x0000C998u: /* A9 35 2C LDA #$2C35 */
        word = 0x2C35u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC99Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000C99Bu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC99Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000C99Eu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9A1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9A1u: /* A9 40 2C LDA #$2C40 */
        word = 0x2C40u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9A4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9A4u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9A7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9A7u: /* A9 35 2C LDA #$2C35 */
        word = 0x2C35u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9AAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C9AAu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9ADu;
        instance->instruction_count++;
        return 1;
    case 0x0000C9ADu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9B0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9B0u: /* A9 F4 0D LDA #$0DF4 */
        word = 0x0DF4u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9B3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9B3u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9B6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9B6u: /* A9 02 30 LDA #$3002 */
        word = 0x3002u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9B9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9B9u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9BCu;
        instance->instruction_count++;
        return 1;
    case 0x0000C9BCu: /* A9 03 30 LDA #$3003 */
        word = 0x3003u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9BFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C9BFu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9C2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9C2u: /* A9 04 30 LDA #$3004 */
        word = 0x3004u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9C5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9C5u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9C8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9C8u: /* A9 05 30 LDA #$3005 */
        word = 0x3005u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9CBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C9CBu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9CEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C9CEu: /* A9 06 30 LDA #$3006 */
        word = 0x3006u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9D1u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9D1u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9D4u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9D4u: /* A9 07 2C LDA #$2C07 */
        word = 0x2C07u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9D7u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9D7u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9DAu;
        instance->instruction_count++;
        return 1;
    case 0x0000C9DAu: /* A9 08 34 LDA #$3408 */
        word = 0x3408u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9DDu;
        instance->instruction_count++;
        return 1;
    case 0x0000C9DDu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9E0u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9E0u: /* A9 09 34 LDA #$3409 */
        word = 0x3409u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9E3u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9E3u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9E6u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9E6u: /* A9 0A 34 LDA #$340A */
        word = 0x340Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9E9u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9E9u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9ECu;
        instance->instruction_count++;
        return 1;
    case 0x0000C9ECu: /* A9 0B 34 LDA #$340B */
        word = 0x340Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9EFu;
        instance->instruction_count++;
        return 1;
    case 0x0000C9EFu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9F2u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9F2u: /* A9 0C 34 LDA #$340C */
        word = 0x340Cu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9F5u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9F5u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9F8u;
        instance->instruction_count++;
        return 1;
    case 0x0000C9F8u: /* A9 14 0E LDA #$0E14 */
        word = 0x0E14u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xC9FBu;
        instance->instruction_count++;
        return 1;
    case 0x0000C9FBu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xC9FEu;
        instance->instruction_count++;
        return 1;
    case 0x0000C9FEu: /* A9 0D 30 LDA #$300D */
        word = 0x300Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA01u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA01u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA04u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA04u: /* A9 0E 30 LDA #$300E */
        word = 0x300Eu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA07u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA07u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA0Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CA0Au: /* A9 34 0E LDA #$0E34 */
        word = 0x0E34u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA0Du;
        instance->instruction_count++;
        return 1;
    case 0x0000CA0Du: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA10u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA10u: /* A9 0F 30 LDA #$300F */
        word = 0x300Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA13u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA13u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA16u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA16u: /* A9 41 0F LDA #$0F41 */
        word = 0x0F41u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA19u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA19u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA1Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA1Cu: /* 2C F6 1F BIT $1FF6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF6u), &word)) return 0;
        tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
        tg_set_flag(instance, TG_P_N, (word & 0x8000u) != 0u);
        tg_set_flag(instance, TG_P_V, (word & 0x4000u) != 0u);
        instance->cpu.pc = 0xCA1Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA1Fu: /* 30 1F BMI $00:CA40 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xCA40u : 0xCA21u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA21u: /* AE 97 1F LDX $1F97 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F97u), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA24u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA24u: /* D0 1A BNE $00:CA40 */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xCA40u : 0xCA26u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA26u: /* A9 4B 2C LDA #$2C4B */
        word = 0x2C4Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA29u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA29u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA2Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA2Cu: /* A9 4C 2C LDA #$2C4C */
        word = 0x2C4Cu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA2Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA2Fu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA32u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA32u: /* A9 44 2C LDA #$2C44 */
        word = 0x2C44u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA35u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA35u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA38u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA38u: /* A9 35 2C LDA #$2C35 */
        word = 0x2C35u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA3Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA3Bu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA3Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA3Eu: /* 80 18 BRA $00:CA58 */
        instance->cpu.pc = 0xCA58u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA40u: /* A9 49 2C LDA #$2C49 */
        word = 0x2C49u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA43u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA43u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA46u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA46u: /* A9 4A 2C LDA #$2C4A */
        word = 0x2C4Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA49u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA49u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA4Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA4Cu: /* A9 4B 2C LDA #$2C4B */
        word = 0x2C4Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA4Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA4Fu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA52u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA52u: /* A9 47 2C LDA #$2C47 */
        word = 0x2C47u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA55u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA55u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA58u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA58u: /* A9 26 0F LDA #$0F26 */
        word = 0x0F26u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA5Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA5Bu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA5Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA5Eu: /* A9 50 2C LDA #$2C50 */
        word = 0x2C50u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA61u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA61u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA64u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA64u: /* A9 45 0F LDA #$0F45 */
        word = 0x0F45u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA67u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA67u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA6Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CA6Au: /* A9 41 2C LDA #$2C41 */
        word = 0x2C41u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA6Du;
        instance->instruction_count++;
        return 1;
    case 0x0000CA6Du: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA70u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA70u: /* A9 51 2C LDA #$2C51 */
        word = 0x2C51u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA73u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA73u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA76u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA76u: /* A9 01 0F LDA #$0F01 */
        word = 0x0F01u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA79u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA79u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA7Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA7Cu: /* A9 4D 2C LDA #$2C4D */
        word = 0x2C4Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA7Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA7Fu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA82u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA82u: /* A9 42 2C LDA #$2C42 */
        word = 0x2C42u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA85u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA85u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA88u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA88u: /* A9 38 2C LDA #$2C38 */
        word = 0x2C38u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA8Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA8Bu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCA8Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA8Eu: /* AD 7C 1E LDA $1E7C */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E7Cu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA91u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA91u: /* 1A INC A */
        word = (uint16_t)((instance->cpu.a) + 1u);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA92u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA92u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xCA93u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA93u: /* C9 04 00 CMP #$0004 */
        word = 0x0004u;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xCA96u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA96u: /* 90 03 BCC $00:CA9B */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xCA9Bu : 0xCA98u;
        instance->instruction_count++;
        return 1;
    case 0x0000CA98u: /* A9 03 00 LDA #$0003 */
        word = 0x0003u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA9Bu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA9Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA9Cu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCA9Du;
        instance->instruction_count++;
        return 1;
    case 0x0000CA9Du: /* A8 TAY */
        tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.y);
        instance->cpu.pc = 0xCA9Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA9Eu: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xCA9Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CA9Fu: /* C9 0A 00 CMP #$000A */
        word = 0x000Au;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xCAA2u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAA2u: /* 90 3F BCC $00:CAE3 */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xCAE3u : 0xCAA4u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAA4u: /* E9 0A 00 SBC #$000A */
        word = 0x000Au;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xCAA7u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAA7u: /* C9 0A 00 CMP #$000A */
        word = 0x000Au;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0xCAAAu;
        instance->instruction_count++;
        return 1;
    case 0x0000CAAAu: /* 90 1E BCC $00:CACA */
        instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xCACAu : 0xCAACu;
        instance->instruction_count++;
        return 1;
    case 0x0000CAACu: /* E9 0A 00 SBC #$000A */
        word = 0x000Au;
        tg_sbc16(instance, word);
        instance->cpu.pc = 0xCAAFu;
        instance->instruction_count++;
        return 1;
    case 0x0000CAAFu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xCAB0u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAB0u: /* A9 39 0F LDA #$0F39 */
        word = 0x0F39u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCAB3u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAB3u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCAB6u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAB6u: /* A9 52 2C LDA #$2C52 */
        word = 0x2C52u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCAB9u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAB9u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCABCu;
        instance->instruction_count++;
        return 1;
    case 0x0000CABCu: /* A9 59 0F LDA #$0F59 */
        word = 0x0F59u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCABFu;
        instance->instruction_count++;
        return 1;
    case 0x0000CABFu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCAC2u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAC2u: /* A9 53 2C LDA #$2C53 */
        word = 0x2C53u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCAC5u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAC5u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCAC8u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAC8u: /* 80 19 BRA $00:CAE3 */
        instance->cpu.pc = 0xCAE3u;
        instance->instruction_count++;
        return 1;
    case 0x0000CACAu: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xCACBu;
        instance->instruction_count++;
        return 1;
    case 0x0000CACBu: /* A9 39 0F LDA #$0F39 */
        word = 0x0F39u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCACEu;
        instance->instruction_count++;
        return 1;
    case 0x0000CACEu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCAD1u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAD1u: /* A9 50 2C LDA #$2C50 */
        word = 0x2C50u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCAD4u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAD4u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCAD7u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAD7u: /* A9 59 0F LDA #$0F59 */
        word = 0x0F59u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCADAu;
        instance->instruction_count++;
        return 1;
    case 0x0000CADAu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCADDu;
        instance->instruction_count++;
        return 1;
    case 0x0000CADDu: /* A9 51 2C LDA #$2C51 */
        word = 0x2C51u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCAE0u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAE0u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCAE3u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAE3u: /* A9 3A 0F LDA #$0F3A */
        word = 0x0F3Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCAE6u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAE6u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCAE9u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAE9u: /* 8A TXA */
        tg_set_acc16(instance, (uint16_t)instance->cpu.x);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xCAEAu;
        instance->instruction_count++;
        return 1;
    case 0x0000CAEAu: /* 0A ASL A */
        word = instance->cpu.a;
        tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
        word = (uint16_t)(word << 1);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCAEBu;
        instance->instruction_count++;
        return 1;
    case 0x0000CAEBu: /* 69 4E 2C ADC #$2C4E */
        word = 0x2C4Eu;
        tg_adc16(instance, word);
        instance->cpu.pc = 0xCAEEu;
        instance->instruction_count++;
        return 1;
    case 0x0000CAEEu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCAF1u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAF1u: /* AA TAX */
        tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
        tg_set_nz16(instance, (uint16_t)instance->cpu.x);
        instance->cpu.pc = 0xCAF2u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAF2u: /* E8 INX */
        word = (uint16_t)(instance->cpu.x + 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCAF3u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAF3u: /* A9 5A 0F LDA #$0F5A */
        word = 0x0F5Au;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCAF6u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAF6u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCAF9u;
        instance->instruction_count++;
        return 1;
    case 0x0000CAF9u: /* 8E 18 21 STX $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0xCAFCu;
        instance->instruction_count++;
        return 1;
    case 0x0000CAFCu: /* B9 8B CC LDA $CC8B,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xCC8Bu + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCAFFu;
        instance->instruction_count++;
        return 1;
    case 0x0000CAFFu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB02u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB02u: /* B9 8D CC LDA $CC8D,Y */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xCC8Du + instance->cpu.y)), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB05u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB05u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB08u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB08u: /* 2C F6 1F BIT $1FF6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF6u), &word)) return 0;
        tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
        tg_set_flag(instance, TG_P_N, (word & 0x8000u) != 0u);
        tg_set_flag(instance, TG_P_V, (word & 0x4000u) != 0u);
        instance->cpu.pc = 0xCB0Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CB0Bu: /* 30 3B BMI $00:CB48 */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xCB48u : 0xCB0Du;
        instance->instruction_count++;
        return 1;
    case 0x0000CB0Du: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCB0Fu;
        instance->instruction_count++;
        return 1;
    case 0x0400CB0Fu: /* AD B0 1F LDA $1FB0 */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FB0u), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xCB12u;
        instance->instruction_count++;
        return 1;
    case 0x0400CB12u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCB14u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB14u: /* F0 32 BEQ $00:CB48 */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xCB48u : 0xCB16u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB16u: /* A9 5D 0C LDA #$0C5D */
        word = 0x0C5Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB19u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB19u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB1Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CB1Cu: /* A9 2B 2C LDA #$2C2B */
        word = 0x2C2Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB1Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CB1Fu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB22u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB22u: /* A9 2C 2C LDA #$2C2C */
        word = 0x2C2Cu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB25u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB25u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB28u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB28u: /* A9 2D 2C LDA #$2C2D */
        word = 0x2C2Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB2Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CB2Bu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB2Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CB2Eu: /* A9 7D 0C LDA #$0C7D */
        word = 0x0C7Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB31u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB31u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB34u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB34u: /* A9 2E 2C LDA #$2C2E */
        word = 0x2C2Eu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB37u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB37u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB3Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CB3Au: /* A9 2F 2C LDA #$2C2F */
        word = 0x2C2Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB3Du;
        instance->instruction_count++;
        return 1;
    case 0x0000CB3Du: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB40u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB40u: /* A9 30 2C LDA #$2C30 */
        word = 0x2C30u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB43u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB43u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB46u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB46u: /* 80 24 BRA $00:CB6C */
        instance->cpu.pc = 0xCB6Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CB48u: /* A9 5D 0C LDA #$0C5D */
        word = 0x0C5Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB4Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CB4Bu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB4Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CB4Eu: /* A9 31 2C LDA #$2C31 */
        word = 0x2C31u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB51u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB51u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB54u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB54u: /* A9 32 2C LDA #$2C32 */
        word = 0x2C32u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB57u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB57u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB5Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CB5Au: /* A9 7D 0C LDA #$0C7D */
        word = 0x0C7Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB5Du;
        instance->instruction_count++;
        return 1;
    case 0x0000CB5Du: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB60u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB60u: /* A9 33 2C LDA #$2C33 */
        word = 0x2C33u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB63u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB63u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB66u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB66u: /* A9 34 2C LDA #$2C34 */
        word = 0x2C34u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB69u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB69u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB6Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CB6Cu: /* 2C F6 1F BIT $1FF6 */
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF6u), &word)) return 0;
        tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
        tg_set_flag(instance, TG_P_N, (word & 0x8000u) != 0u);
        tg_set_flag(instance, TG_P_V, (word & 0x4000u) != 0u);
        instance->cpu.pc = 0xCB6Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CB6Fu: /* 30 09 BMI $00:CB7A */
        instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xCB7Au : 0xCB71u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB71u: /* E2 20 SEP #$20 */
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCB73u;
        instance->instruction_count++;
        return 1;
    case 0x0400CB73u: /* AD B1 1F LDA $1FB1 */
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FB1u), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0xCB76u;
        instance->instruction_count++;
        return 1;
    case 0x0400CB76u: /* C2 20 REP #$20 */
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0xCB78u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB78u: /* F0 32 BEQ $00:CBAC */
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xCBACu : 0xCB7Au;
        instance->instruction_count++;
        return 1;
    case 0x0000CB7Au: /* A9 1D 0E LDA #$0E1D */
        word = 0x0E1Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB7Du;
        instance->instruction_count++;
        return 1;
    case 0x0000CB7Du: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB80u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB80u: /* A9 2B 2C LDA #$2C2B */
        word = 0x2C2Bu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB83u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB83u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB86u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB86u: /* A9 2C 2C LDA #$2C2C */
        word = 0x2C2Cu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB89u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB89u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB8Cu;
        instance->instruction_count++;
        return 1;
    case 0x0000CB8Cu: /* A9 2D 2C LDA #$2C2D */
        word = 0x2C2Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB8Fu;
        instance->instruction_count++;
        return 1;
    case 0x0000CB8Fu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB92u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB92u: /* A9 3D 0E LDA #$0E3D */
        word = 0x0E3Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB95u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB95u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB98u;
        instance->instruction_count++;
        return 1;
    case 0x0000CB98u: /* A9 2E 2C LDA #$2C2E */
        word = 0x2C2Eu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCB9Bu;
        instance->instruction_count++;
        return 1;
    case 0x0000CB9Bu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCB9Eu;
        instance->instruction_count++;
        return 1;
    case 0x0000CB9Eu: /* A9 2F 2C LDA #$2C2F */
        word = 0x2C2Fu;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBA1u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBA1u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCBA4u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBA4u: /* A9 30 2C LDA #$2C30 */
        word = 0x2C30u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBA7u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBA7u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCBAAu;
        instance->instruction_count++;
        return 1;
    case 0x0000CBAAu: /* 80 24 BRA $00:CBD0 */
        instance->cpu.pc = 0xCBD0u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBACu: /* A9 1D 0E LDA #$0E1D */
        word = 0x0E1Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBAFu;
        instance->instruction_count++;
        return 1;
    case 0x0000CBAFu: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCBB2u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBB2u: /* A9 31 2C LDA #$2C31 */
        word = 0x2C31u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBB5u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBB5u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCBB8u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBB8u: /* A9 32 2C LDA #$2C32 */
        word = 0x2C32u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBBBu;
        instance->instruction_count++;
        return 1;
    case 0x0000CBBBu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCBBEu;
        instance->instruction_count++;
        return 1;
    case 0x0000CBBEu: /* A9 3D 0E LDA #$0E3D */
        word = 0x0E3Du;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBC1u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBC1u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCBC4u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBC4u: /* A9 33 2C LDA #$2C33 */
        word = 0x2C33u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBC7u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBC7u: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCBCAu;
        instance->instruction_count++;
        return 1;
    case 0x0000CBCAu: /* A9 34 2C LDA #$2C34 */
        word = 0x2C34u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBCDu;
        instance->instruction_count++;
        return 1;
    case 0x0000CBCDu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCBD0u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBD0u: /* A9 00 0C LDA #$0C00 */
        word = 0x0C00u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBD3u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBD3u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCBD6u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBD6u: /* A9 01 2C LDA #$2C01 */
        word = 0x2C01u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBD9u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBD9u: /* A2 20 00 LDX #$0020 */
        word = 0x0020u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBDCu;
        instance->instruction_count++;
        return 1;
    case 0x0000CBDCu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCBDFu;
        instance->instruction_count++;
        return 1;
    case 0x0000CBDFu: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBE0u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBE0u: /* D0 FA BNE $00:CBDC */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xCBDCu : 0xCBE2u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBE2u: /* A9 A0 0D LDA #$0DA0 */
        word = 0x0DA0u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBE5u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBE5u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCBE8u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBE8u: /* A9 01 AC LDA #$AC01 */
        word = 0xAC01u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBEBu;
        instance->instruction_count++;
        return 1;
    case 0x0000CBEBu: /* A2 20 00 LDX #$0020 */
        word = 0x0020u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBEEu;
        instance->instruction_count++;
        return 1;
    case 0x0000CBEEu: /* 8D 18 21 STA $2118 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2118u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCBF1u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBF1u: /* CA DEX */
        word = (uint16_t)(instance->cpu.x - 1u);
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBF2u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBF2u: /* D0 FA BNE $00:CBEE */
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xCBEEu : 0xCBF4u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBF4u: /* A9 C0 0D LDA #$0DC0 */
        word = 0x0DC0u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBF7u;
        instance->instruction_count++;
        return 1;
    case 0x0000CBF7u: /* 8D 16 21 STA $2116 */
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0xCBFAu;
        instance->instruction_count++;
        return 1;
    case 0x0000CBFAu: /* A9 01 2C LDA #$2C01 */
        word = 0x2C01u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCBFDu;
        instance->instruction_count++;
        return 1;
    case 0x0000CBFDu: /* A2 20 00 LDX #$0020 */
        word = 0x0020u;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0xCC00u;
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 22 ROM-wide fixed W65C816 context in generated shard.",NULL);
    }}
