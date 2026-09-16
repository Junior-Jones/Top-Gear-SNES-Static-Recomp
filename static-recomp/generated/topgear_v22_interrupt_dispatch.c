/* Generated Version 22 later interrupt static dispatch. No runtime opcode decoder. */
#include "topgear_internal.h"
#include "topgear_v22_interrupt_dispatch.h"

unsigned tg_v22_interrupt_context_count(void){return 2601u;}
int tg_v22_interrupt_semantic_step(struct TopGearRecomp *instance){
 uint32_t key,address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u;
 if(!instance)return 0;
 (void)address;(void)base24;(void)word;(void)byte;
 key=tg_generated_context_key(instance);switch(key){
 /* Track raster variant selected at executable-WRAM $7E:2028. */
 case 0x0000B511u: /* ROM $00:B511: a9 00 00 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB514u;
  instance->instruction_count++;
  return 1;
 case 0x0000B514u: /* ROM $00:B514: 8d 23 21 */
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2123u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB517u;
  instance->instruction_count++;
  return 1;
 case 0x0000B517u: /* ROM $00:B517: e2 20 */
  instance->cpu.p |= 0x20u;
  instance->cpu.pc = 0xB519u;
  instance->instruction_count++;
  return 1;
 case 0x0400B519u: /* ROM $00:B519: 8d 31 21 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2131u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB51Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400B51Cu: /* ROM $00:B51C: a9 09 */
  byte = 0x0009u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB51Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400B51Eu: /* ROM $00:B51E: 8d 01 21 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2101u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB521u;
  instance->instruction_count++;
  return 1;
 case 0x0400B521u: /* ROM $00:B521: a5 ba */
  if (!tg_bus_read8(instance, (uint16_t)(instance->cpu.d + 0xBAu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB523u;
  instance->instruction_count++;
  return 1;
 case 0x0400B523u: /* ROM $00:B523: 8d 0f 21 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Fu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB526u;
  instance->instruction_count++;
  return 1;
 case 0x0400B526u: /* ROM $00:B526: a5 bb */
  if (!tg_bus_read8(instance, (uint16_t)(instance->cpu.d + 0xBBu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB528u;
  instance->instruction_count++;
  return 1;
 case 0x0400B528u: /* ROM $00:B528: 8d 0f 21 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Fu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB52Bu;
  instance->instruction_count++;
  return 1;
 case 0x0400B52Bu: /* ROM $00:B52B: a9 1f */
  byte = 0x001Fu;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB52Du;
  instance->instruction_count++;
  return 1;
 case 0x0400B52Du: /* ROM $00:B52D: 8d 10 21 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB530u;
  instance->instruction_count++;
  return 1;
 case 0x0400B530u: /* ROM $00:B530: a9 03 */
  byte = 0x0003u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB532u;
  instance->instruction_count++;
  return 1;
 case 0x0400B532u: /* ROM $00:B532: 8d 10 21 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB535u;
  instance->instruction_count++;
  return 1;
 case 0x0400B535u: /* ROM $00:B535: c2 20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  instance->cpu.pc = 0xB537u;
  instance->instruction_count++;
  return 1;
 case 0x0000B537u: /* ROM $00:B537: a9 d1 b6 */
  word = 0xB6D1u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB53Au;
  instance->instruction_count++;
  return 1;
 case 0x0000B53Au: /* ROM $00:B53A: 85 0a */
  if (!tg_bus_write16(instance, (uint16_t)(instance->cpu.d + 0x0Au), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB53Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000B53Cu: /* ROM $00:B53C: a9 e0 00 */
  word = 0x00E0u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB53Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000B53Fu: /* ROM $00:B53F: 8d 09 42 */
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4209u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB542u;
  instance->instruction_count++;
  return 1;
 case 0x0000B542u: /* ROM $00:B542: 4c 78 be */
  instance->cpu.pc = 0xBE78u;
  instance->instruction_count++;
  return 1;

 case 0x00008966u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8968u;
  instance->instruction_count++;
  return 1;
 case 0x04008968u: /* 24 E0 BIT $E0 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xE0u) & 0xFFFFu), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  tg_set_flag(instance, TG_P_N, (byte & 0x80u) != 0u);
  tg_set_flag(instance, TG_P_V, (byte & 0x40u) != 0u);
  instance->cpu.pc = 0x896Au;
  instance->instruction_count++;
  return 1;
 case 0x0400896Au: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x896Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000896Cu: /* 10 11 BPL $00:897F */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x897Fu : 0x896Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000896Eu: /* 49 FF 03 EOR #$03FF */
  word = 0x03FFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8971u;
  instance->instruction_count++;
  return 1;
 case 0x00008971u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8972u;
  instance->instruction_count++;
  return 1;
 case 0x00008972u: /* 69 01 01 ADC #$0101 */
  word = 0x0101u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8975u;
  instance->instruction_count++;
  return 1;
 case 0x00008975u: /* 29 FF 03 AND #$03FF */
  word = 0x03FFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8978u;
  instance->instruction_count++;
  return 1;
 case 0x00008978u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8979u;
  instance->instruction_count++;
  return 1;
 case 0x00008979u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x897Au;
  instance->instruction_count++;
  return 1;
 case 0x0000897Au: /* 69 80 01 ADC #$0180 */
  word = 0x0180u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x897Du;
  instance->instruction_count++;
  return 1;
 case 0x0000897Du: /* 80 08 BRA $00:8987 */
  instance->cpu.pc = 0x8987u;
  instance->instruction_count++;
  return 1;
 case 0x0000897Fu: /* 29 FF 03 AND #$03FF */
  word = 0x03FFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8982u;
  instance->instruction_count++;
  return 1;
 case 0x00008982u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8983u;
  instance->instruction_count++;
  return 1;
 case 0x00008983u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8984u;
  instance->instruction_count++;
  return 1;
 case 0x00008984u: /* 69 80 00 ADC #$0080 */
  word = 0x0080u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8987u;
  instance->instruction_count++;
  return 1;
 case 0x00008987u: /* 85 A6 STA $A6 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xA6u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8989u;
  instance->instruction_count++;
  return 1;
 case 0x00008989u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x898Au;
  instance->instruction_count++;
  return 1;
 case 0x0000898Au: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x898Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000898Bu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x898Du;
  instance->instruction_count++;
  return 1;
 case 0x0400898Du: /* A2 07 00 LDX #$0007 */
  word = 0x0007u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8990u;
  instance->instruction_count++;
  return 1;
 case 0x04008990u: /* A0 80 01 LDY #$0180 */
  word = 0x0180u;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8993u;
  instance->instruction_count++;
  return 1;
 case 0x04008993u: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8995u;
  instance->instruction_count++;
  return 1;
 case 0x04008995u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8996u;
  instance->instruction_count++;
  return 1;
 case 0x04008996u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8997u;
  instance->instruction_count++;
  return 1;
 case 0x04008997u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8998u;
  instance->instruction_count++;
  return 1;
 case 0x04008998u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8999u;
  instance->instruction_count++;
  return 1;
 case 0x04008999u: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x899Bu;
  instance->instruction_count++;
  return 1;
 case 0x0400899Bu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x899Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400899Cu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x899Du;
  instance->instruction_count++;
  return 1;
 case 0x0400899Du: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x899Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400899Eu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x899Fu;
  instance->instruction_count++;
  return 1;
 case 0x0400899Fu: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x89A1u;
  instance->instruction_count++;
  return 1;
 case 0x040089A1u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89A2u;
  instance->instruction_count++;
  return 1;
 case 0x040089A2u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89A3u;
  instance->instruction_count++;
  return 1;
 case 0x040089A3u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89A4u;
  instance->instruction_count++;
  return 1;
 case 0x040089A4u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89A5u;
  instance->instruction_count++;
  return 1;
 case 0x040089A5u: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x89A7u;
  instance->instruction_count++;
  return 1;
 case 0x040089A7u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89A8u;
  instance->instruction_count++;
  return 1;
 case 0x040089A8u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89A9u;
  instance->instruction_count++;
  return 1;
 case 0x040089A9u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89AAu;
  instance->instruction_count++;
  return 1;
 case 0x040089AAu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89ABu;
  instance->instruction_count++;
  return 1;
 case 0x040089ABu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x89ACu;
  instance->instruction_count++;
  return 1;
 case 0x040089ACu: /* 69 10 ADC #$10 */
  byte = 0x10u;
  tg_adc8(instance, byte);
  instance->cpu.pc = 0x89AEu;
  instance->instruction_count++;
  return 1;
 case 0x040089AEu: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89AFu;
  instance->instruction_count++;
  return 1;
 case 0x040089AFu: /* 10 E2 BPL $00:8993 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8993u : 0x89B1u;
  instance->instruction_count++;
  return 1;
 case 0x040089B1u: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0x89B2u;
  instance->instruction_count++;
  return 1;
 case 0x040089B2u: /* E9 80 SBC #$80 */
  byte = 0x80u;
  tg_sbc8(instance, byte);
  instance->cpu.pc = 0x89B4u;
  instance->instruction_count++;
  return 1;
 case 0x040089B4u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x89B6u;
  instance->instruction_count++;
  return 1;
 case 0x000089B6u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89B7u;
  instance->instruction_count++;
  return 1;
 case 0x000089B7u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89B8u;
  instance->instruction_count++;
  return 1;
 case 0x000089B8u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89B9u;
  instance->instruction_count++;
  return 1;
 case 0x000089B9u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89BAu;
  instance->instruction_count++;
  return 1;
 case 0x000089BAu: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x89BBu;
  instance->instruction_count++;
  return 1;
 case 0x000089BBu: /* A0 00 00 LDY #$0000 */
  word = 0x0000u;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89BEu;
  instance->instruction_count++;
  return 1;
 case 0x000089BEu: /* AD 12 01 LDA $0112 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0112u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89C1u;
  instance->instruction_count++;
  return 1;
 case 0x000089C1u: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
  instance->cpu.pc = 0x89C3u;
  instance->instruction_count++;
  return 1;
 case 0x000089C3u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89C4u;
  instance->instruction_count++;
  return 1;
 case 0x000089C4u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89C5u;
  instance->instruction_count++;
  return 1;
 case 0x000089C5u: /* A9 7F 30 LDA #$307F */
  word = 0x307Fu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89C8u;
  instance->instruction_count++;
  return 1;
 case 0x000089C8u: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
  instance->cpu.pc = 0x89CAu;
  instance->instruction_count++;
  return 1;
 case 0x000089CAu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89CBu;
  instance->instruction_count++;
  return 1;
 case 0x000089CBu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89CCu;
  instance->instruction_count++;
  return 1;
 case 0x000089CCu: /* AD 16 01 LDA $0116 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0116u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89CFu;
  instance->instruction_count++;
  return 1;
 case 0x000089CFu: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
  instance->cpu.pc = 0x89D1u;
  instance->instruction_count++;
  return 1;
 case 0x000089D1u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89D2u;
  instance->instruction_count++;
  return 1;
 case 0x000089D2u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89D3u;
  instance->instruction_count++;
  return 1;
 case 0x000089D3u: /* A9 FF 30 LDA #$30FF */
  word = 0x30FFu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89D6u;
  instance->instruction_count++;
  return 1;
 case 0x000089D6u: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
  instance->cpu.pc = 0x89D8u;
  instance->instruction_count++;
  return 1;
 case 0x000089D8u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89D9u;
  instance->instruction_count++;
  return 1;
 case 0x000089D9u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89DAu;
  instance->instruction_count++;
  return 1;
 case 0x000089DAu: /* AD 14 01 LDA $0114 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0114u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89DDu;
  instance->instruction_count++;
  return 1;
 case 0x000089DDu: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
  instance->cpu.pc = 0x89DFu;
  instance->instruction_count++;
  return 1;
 case 0x000089DFu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89E0u;
  instance->instruction_count++;
  return 1;
 case 0x000089E0u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89E1u;
  instance->instruction_count++;
  return 1;
 case 0x000089E1u: /* A9 7F 32 LDA #$327F */
  word = 0x327Fu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89E4u;
  instance->instruction_count++;
  return 1;
 case 0x000089E4u: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
  instance->cpu.pc = 0x89E6u;
  instance->instruction_count++;
  return 1;
 case 0x000089E6u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x89E8u;
  instance->instruction_count++;
  return 1;
 case 0x040089E8u: /* A0 1F 02 LDY #$021F */
  word = 0x021Fu;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89EBu;
  instance->instruction_count++;
  return 1;
 case 0x040089EBu: /* BD 05 8B LDA $8B05,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8B05u + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x89EEu;
  instance->instruction_count++;
  return 1;
 case 0x040089EEu: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x89F0u;
  instance->instruction_count++;
  return 1;
 case 0x040089F0u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89F1u;
  instance->instruction_count++;
  return 1;
 case 0x040089F1u: /* BD 04 8B LDA $8B04,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8B04u + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x89F4u;
  instance->instruction_count++;
  return 1;
 case 0x040089F4u: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x89F6u;
  instance->instruction_count++;
  return 1;
 case 0x040089F6u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89F7u;
  instance->instruction_count++;
  return 1;
 case 0x040089F7u: /* BD 03 8B LDA $8B03,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8B03u + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x89FAu;
  instance->instruction_count++;
  return 1;
 case 0x040089FAu: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x89FCu;
  instance->instruction_count++;
  return 1;
 case 0x040089FCu: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x89FDu;
  instance->instruction_count++;
  return 1;
 case 0x040089FDu: /* BD 02 8B LDA $8B02,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8B02u + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8A00u;
  instance->instruction_count++;
  return 1;
 case 0x04008A00u: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8A02u;
  instance->instruction_count++;
  return 1;
 case 0x04008A02u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A03u;
  instance->instruction_count++;
  return 1;
 case 0x04008A03u: /* BD 01 8B LDA $8B01,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8B01u + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8A06u;
  instance->instruction_count++;
  return 1;
 case 0x04008A06u: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8A08u;
  instance->instruction_count++;
  return 1;
 case 0x04008A08u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A09u;
  instance->instruction_count++;
  return 1;
 case 0x04008A09u: /* BD 00 8B LDA $8B00,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8B00u + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8A0Cu;
  instance->instruction_count++;
  return 1;
 case 0x04008A0Cu: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8A0Eu;
  instance->instruction_count++;
  return 1;
 case 0x04008A0Eu: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A0Fu;
  instance->instruction_count++;
  return 1;
 case 0x04008A0Fu: /* BD FF 8A LDA $8AFF,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8AFFu + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8A12u;
  instance->instruction_count++;
  return 1;
 case 0x04008A12u: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8A14u;
  instance->instruction_count++;
  return 1;
 case 0x04008A14u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A15u;
  instance->instruction_count++;
  return 1;
 case 0x04008A15u: /* BD FE 8A LDA $8AFE,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8AFEu + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8A18u;
  instance->instruction_count++;
  return 1;
 case 0x04008A18u: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8A1Au;
  instance->instruction_count++;
  return 1;
 case 0x04008A1Au: /* A0 00 02 LDY #$0200 */
  word = 0x0200u;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A1Du;
  instance->instruction_count++;
  return 1;
 case 0x04008A1Du: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8A1Fu;
  instance->instruction_count++;
  return 1;
 case 0x04008A1Fu: /* 91 CC STA ($CC),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCCu) : (uint16_t)(instance->cpu.d + 0xCCu)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xCDu) : (uint16_t)(instance->cpu.d + 0xCDu)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8A21u;
  instance->instruction_count++;
  return 1;
 case 0x04008A21u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8A23u;
  instance->instruction_count++;
  return 1;
 case 0x00008A23u: /* A5 D2 LDA $D2 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xD2u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A25u;
  instance->instruction_count++;
  return 1;
 case 0x00008A25u: /* A6 CC LDX $CC */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xCCu) & 0xFFFFu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A27u;
  instance->instruction_count++;
  return 1;
 case 0x00008A27u: /* 85 CC STA $CC */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xCCu) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8A29u;
  instance->instruction_count++;
  return 1;
 case 0x00008A29u: /* 86 D2 STX $D2 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xD2u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0x8A2Bu;
  instance->instruction_count++;
  return 1;
 case 0x00008A2Bu: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x00008A2Cu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8A2Eu;
  instance->instruction_count++;
  return 1;
 case 0x04008A2Eu: /* 24 E0 BIT $E0 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xE0u) & 0xFFFFu), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  tg_set_flag(instance, TG_P_N, (byte & 0x80u) != 0u);
  tg_set_flag(instance, TG_P_V, (byte & 0x40u) != 0u);
  instance->cpu.pc = 0x8A30u;
  instance->instruction_count++;
  return 1;
 case 0x04008A30u: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8A32u;
  instance->instruction_count++;
  return 1;
 case 0x00008A32u: /* 10 11 BPL $00:8A45 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8A45u : 0x8A34u;
  instance->instruction_count++;
  return 1;
 case 0x00008A34u: /* 49 FF 03 EOR #$03FF */
  word = 0x03FFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A37u;
  instance->instruction_count++;
  return 1;
 case 0x00008A37u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8A38u;
  instance->instruction_count++;
  return 1;
 case 0x00008A38u: /* 69 01 01 ADC #$0101 */
  word = 0x0101u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8A3Bu;
  instance->instruction_count++;
  return 1;
 case 0x00008A3Bu: /* 29 FF 03 AND #$03FF */
  word = 0x03FFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A3Eu;
  instance->instruction_count++;
  return 1;
 case 0x00008A3Eu: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8A3Fu;
  instance->instruction_count++;
  return 1;
 case 0x00008A3Fu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8A40u;
  instance->instruction_count++;
  return 1;
 case 0x00008A40u: /* 69 80 01 ADC #$0180 */
  word = 0x0180u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8A43u;
  instance->instruction_count++;
  return 1;
 case 0x00008A43u: /* 80 08 BRA $00:8A4D */
  instance->cpu.pc = 0x8A4Du;
  instance->instruction_count++;
  return 1;
 case 0x00008A45u: /* 29 FF 03 AND #$03FF */
  word = 0x03FFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A48u;
  instance->instruction_count++;
  return 1;
 case 0x00008A48u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8A49u;
  instance->instruction_count++;
  return 1;
 case 0x00008A49u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8A4Au;
  instance->instruction_count++;
  return 1;
 case 0x00008A4Au: /* 69 80 00 ADC #$0080 */
  word = 0x0080u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8A4Du;
  instance->instruction_count++;
  return 1;
 case 0x00008A4Du: /* 85 BA STA $BA */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xBAu) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8A4Fu;
  instance->instruction_count++;
  return 1;
 case 0x00008A4Fu: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8A50u;
  instance->instruction_count++;
  return 1;
 case 0x00008A50u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A51u;
  instance->instruction_count++;
  return 1;
 case 0x00008A51u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8A53u;
  instance->instruction_count++;
  return 1;
 case 0x04008A53u: /* A2 07 00 LDX #$0007 */
  word = 0x0007u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A56u;
  instance->instruction_count++;
  return 1;
 case 0x04008A56u: /* A0 80 01 LDY #$0180 */
  word = 0x0180u;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A59u;
  instance->instruction_count++;
  return 1;
 case 0x04008A59u: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8A5Bu;
  instance->instruction_count++;
  return 1;
 case 0x04008A5Bu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A5Cu;
  instance->instruction_count++;
  return 1;
 case 0x04008A5Cu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A5Du;
  instance->instruction_count++;
  return 1;
 case 0x04008A5Du: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A5Eu;
  instance->instruction_count++;
  return 1;
 case 0x04008A5Eu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A5Fu;
  instance->instruction_count++;
  return 1;
 case 0x04008A5Fu: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8A61u;
  instance->instruction_count++;
  return 1;
 case 0x04008A61u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A62u;
  instance->instruction_count++;
  return 1;
 case 0x04008A62u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A63u;
  instance->instruction_count++;
  return 1;
 case 0x04008A63u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A64u;
  instance->instruction_count++;
  return 1;
 case 0x04008A64u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A65u;
  instance->instruction_count++;
  return 1;
 case 0x04008A65u: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8A67u;
  instance->instruction_count++;
  return 1;
 case 0x04008A67u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A68u;
  instance->instruction_count++;
  return 1;
 case 0x04008A68u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A69u;
  instance->instruction_count++;
  return 1;
 case 0x04008A69u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A6Au;
  instance->instruction_count++;
  return 1;
 case 0x04008A6Au: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A6Bu;
  instance->instruction_count++;
  return 1;
 case 0x04008A6Bu: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8A6Du;
  instance->instruction_count++;
  return 1;
 case 0x04008A6Du: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A6Eu;
  instance->instruction_count++;
  return 1;
 case 0x04008A6Eu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A6Fu;
  instance->instruction_count++;
  return 1;
 case 0x04008A6Fu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A70u;
  instance->instruction_count++;
  return 1;
 case 0x04008A70u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A71u;
  instance->instruction_count++;
  return 1;
 case 0x04008A71u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8A72u;
  instance->instruction_count++;
  return 1;
 case 0x04008A72u: /* 69 10 ADC #$10 */
  byte = 0x10u;
  tg_adc8(instance, byte);
  instance->cpu.pc = 0x8A74u;
  instance->instruction_count++;
  return 1;
 case 0x04008A74u: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A75u;
  instance->instruction_count++;
  return 1;
 case 0x04008A75u: /* 10 E2 BPL $00:8A59 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8A59u : 0x8A77u;
  instance->instruction_count++;
  return 1;
 case 0x04008A77u: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0x8A78u;
  instance->instruction_count++;
  return 1;
 case 0x04008A78u: /* E9 80 SBC #$80 */
  byte = 0x80u;
  tg_sbc8(instance, byte);
  instance->cpu.pc = 0x8A7Au;
  instance->instruction_count++;
  return 1;
 case 0x04008A7Au: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8A7Cu;
  instance->instruction_count++;
  return 1;
 case 0x00008A7Cu: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A7Du;
  instance->instruction_count++;
  return 1;
 case 0x00008A7Du: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A7Eu;
  instance->instruction_count++;
  return 1;
 case 0x00008A7Eu: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A7Fu;
  instance->instruction_count++;
  return 1;
 case 0x00008A7Fu: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A80u;
  instance->instruction_count++;
  return 1;
 case 0x00008A80u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8A81u;
  instance->instruction_count++;
  return 1;
 case 0x00008A81u: /* A0 00 00 LDY #$0000 */
  word = 0x0000u;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A84u;
  instance->instruction_count++;
  return 1;
 case 0x00008A84u: /* AD 14 01 LDA $0114 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0114u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A87u;
  instance->instruction_count++;
  return 1;
 case 0x00008A87u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8A88u;
  instance->instruction_count++;
  return 1;
 case 0x00008A88u: /* 69 00 70 ADC #$7000 */
  word = 0x7000u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8A8Bu;
  instance->instruction_count++;
  return 1;
 case 0x00008A8Bu: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8A8Du;
  instance->instruction_count++;
  return 1;
 case 0x00008A8Du: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A8Eu;
  instance->instruction_count++;
  return 1;
 case 0x00008A8Eu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A8Fu;
  instance->instruction_count++;
  return 1;
 case 0x00008A8Fu: /* A9 7F 32 LDA #$327F */
  word = 0x327Fu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A92u;
  instance->instruction_count++;
  return 1;
 case 0x00008A92u: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8A94u;
  instance->instruction_count++;
  return 1;
 case 0x00008A94u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A95u;
  instance->instruction_count++;
  return 1;
 case 0x00008A95u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A96u;
  instance->instruction_count++;
  return 1;
 case 0x00008A96u: /* AD 16 01 LDA $0116 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0116u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8A99u;
  instance->instruction_count++;
  return 1;
 case 0x00008A99u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8A9Au;
  instance->instruction_count++;
  return 1;
 case 0x00008A9Au: /* 69 00 70 ADC #$7000 */
  word = 0x7000u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8A9Du;
  instance->instruction_count++;
  return 1;
 case 0x00008A9Du: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8A9Fu;
  instance->instruction_count++;
  return 1;
 case 0x00008A9Fu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AA0u;
  instance->instruction_count++;
  return 1;
 case 0x00008AA0u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AA1u;
  instance->instruction_count++;
  return 1;
 case 0x00008AA1u: /* A9 FF 32 LDA #$32FF */
  word = 0x32FFu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AA4u;
  instance->instruction_count++;
  return 1;
 case 0x00008AA4u: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8AA6u;
  instance->instruction_count++;
  return 1;
 case 0x00008AA6u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AA7u;
  instance->instruction_count++;
  return 1;
 case 0x00008AA7u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AA8u;
  instance->instruction_count++;
  return 1;
 case 0x00008AA8u: /* AD 12 01 LDA $0112 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0112u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AABu;
  instance->instruction_count++;
  return 1;
 case 0x00008AABu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8AACu;
  instance->instruction_count++;
  return 1;
 case 0x00008AACu: /* 69 00 70 ADC #$7000 */
  word = 0x7000u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8AAFu;
  instance->instruction_count++;
  return 1;
 case 0x00008AAFu: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8AB1u;
  instance->instruction_count++;
  return 1;
 case 0x00008AB1u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AB2u;
  instance->instruction_count++;
  return 1;
 case 0x00008AB2u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AB3u;
  instance->instruction_count++;
  return 1;
 case 0x00008AB3u: /* A9 7F 30 LDA #$307F */
  word = 0x307Fu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AB6u;
  instance->instruction_count++;
  return 1;
 case 0x00008AB6u: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_store16(instance, address, instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8AB8u;
  instance->instruction_count++;
  return 1;
 case 0x00008AB8u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8ABAu;
  instance->instruction_count++;
  return 1;
 case 0x04008ABAu: /* A0 1F 02 LDY #$021F */
  word = 0x021Fu;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8ABDu;
  instance->instruction_count++;
  return 1;
 case 0x04008ABDu: /* BD 05 8B LDA $8B05,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8B05u + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8AC0u;
  instance->instruction_count++;
  return 1;
 case 0x04008AC0u: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8AC2u;
  instance->instruction_count++;
  return 1;
 case 0x04008AC2u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AC3u;
  instance->instruction_count++;
  return 1;
 case 0x04008AC3u: /* BD 04 8B LDA $8B04,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8B04u + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8AC6u;
  instance->instruction_count++;
  return 1;
 case 0x04008AC6u: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8AC8u;
  instance->instruction_count++;
  return 1;
 case 0x04008AC8u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AC9u;
  instance->instruction_count++;
  return 1;
 case 0x04008AC9u: /* BD 03 8B LDA $8B03,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8B03u + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8ACCu;
  instance->instruction_count++;
  return 1;
 case 0x04008ACCu: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8ACEu;
  instance->instruction_count++;
  return 1;
 case 0x04008ACEu: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8ACFu;
  instance->instruction_count++;
  return 1;
 case 0x04008ACFu: /* BD 02 8B LDA $8B02,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8B02u + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8AD2u;
  instance->instruction_count++;
  return 1;
 case 0x04008AD2u: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8AD4u;
  instance->instruction_count++;
  return 1;
 case 0x04008AD4u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AD5u;
  instance->instruction_count++;
  return 1;
 case 0x04008AD5u: /* BD 01 8B LDA $8B01,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8B01u + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8AD8u;
  instance->instruction_count++;
  return 1;
 case 0x04008AD8u: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8ADAu;
  instance->instruction_count++;
  return 1;
 case 0x04008ADAu: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8ADBu;
  instance->instruction_count++;
  return 1;
 case 0x04008ADBu: /* BD 00 8B LDA $8B00,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8B00u + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8ADEu;
  instance->instruction_count++;
  return 1;
 case 0x04008ADEu: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8AE0u;
  instance->instruction_count++;
  return 1;
 case 0x04008AE0u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AE1u;
  instance->instruction_count++;
  return 1;
 case 0x04008AE1u: /* BD FF 8A LDA $8AFF,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8AFFu + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8AE4u;
  instance->instruction_count++;
  return 1;
 case 0x04008AE4u: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8AE6u;
  instance->instruction_count++;
  return 1;
 case 0x04008AE6u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AE7u;
  instance->instruction_count++;
  return 1;
 case 0x04008AE7u: /* BD FE 8A LDA $8AFE,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x8AFEu + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8AEAu;
  instance->instruction_count++;
  return 1;
 case 0x04008AEAu: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8AECu;
  instance->instruction_count++;
  return 1;
 case 0x04008AECu: /* A0 00 02 LDY #$0200 */
  word = 0x0200u;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AEFu;
  instance->instruction_count++;
  return 1;
 case 0x04008AEFu: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8AF1u;
  instance->instruction_count++;
  return 1;
 case 0x04008AF1u: /* 91 D8 STA ($D8),Y */
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD8u) : (uint16_t)(instance->cpu.d + 0xD8u)), &byte)) return 0;
  word = byte;
  if (!tg_bus_read8(instance, (instance->cpu.e && (instance->cpu.d & 0x00FFu)==0u ? (uint16_t)((instance->cpu.d & 0xFF00u) | 0xD9u) : (uint16_t)(instance->cpu.d + 0xD9u)), &byte)) return 0;
  word = (uint16_t)(word | ((uint16_t)byte << 8));
  address = (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(word + instance->cpu.y));
  if (!tg_bus_write8(instance, address, tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8AF3u;
  instance->instruction_count++;
  return 1;
 case 0x04008AF3u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8AF5u;
  instance->instruction_count++;
  return 1;
 case 0x00008AF5u: /* A5 DE LDA $DE */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xDEu) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AF7u;
  instance->instruction_count++;
  return 1;
 case 0x00008AF7u: /* A6 D8 LDX $D8 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xD8u) & 0xFFFFu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8AF9u;
  instance->instruction_count++;
  return 1;
 case 0x00008AF9u: /* 85 D8 STA $D8 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xD8u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8AFBu;
  instance->instruction_count++;
  return 1;
 case 0x00008AFBu: /* 86 DE STX $DE */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xDEu) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0x8AFDu;
  instance->instruction_count++;
  return 1;
 case 0x00008AFDu: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x00008DA8u: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8DAAu;
  instance->instruction_count++;
  return 1;
 case 0x00008DAAu: /* AD 86 1E LDA $1E86 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E86u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8DADu;
  instance->instruction_count++;
  return 1;
 case 0x00008DADu: /* 10 0A BPL $00:8DB9 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8DB9u : 0x8DAFu;
  instance->instruction_count++;
  return 1;
 case 0x00008DAFu: /* C9 F7 FF CMP #$FFF7 */
  word = 0xFFF7u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0x8DB2u;
  instance->instruction_count++;
  return 1;
 case 0x00008DB2u: /* D0 05 BNE $00:8DB9 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8DB9u : 0x8DB4u;
  instance->instruction_count++;
  return 1;
 case 0x00008DB4u: /* AD B4 1B LDA $1BB4 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB4u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8DB7u;
  instance->instruction_count++;
  return 1;
 case 0x00008DB7u: /* 30 01 BMI $00:8DBA */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0x8DBAu : 0x8DB9u;
  instance->instruction_count++;
  return 1;
 case 0x00008DB9u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x00008DBAu: /* 9C 7E 05 STZ $057E */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x057Eu), 0u)) return 0;
  instance->cpu.pc = 0x8DBDu;
  instance->instruction_count++;
  return 1;
 case 0x00008DBDu: /* AC 72 05 LDY $0572 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0572u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8DC0u;
  instance->instruction_count++;
  return 1;
 case 0x00008DC0u: /* D0 0B BNE $00:8DCD */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8DCDu : 0x8DC2u;
  instance->instruction_count++;
  return 1;
 case 0x00008DC2u: /* AD E6 1B LDA $1BE6 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE6u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8DC5u;
  instance->instruction_count++;
  return 1;
 case 0x00008DC5u: /* F0 69 BEQ $00:8E30 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x8E30u : 0x8DC7u;
  instance->instruction_count++;
  return 1;
 case 0x00008DC7u: /* 8D 74 05 STA $0574 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0574u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8DCAu;
  instance->instruction_count++;
  return 1;
 case 0x00008DCAu: /* 4C 84 8E JMP $8E84 */
  instance->cpu.pc = 0x8E84u;
  instance->instruction_count++;
  return 1;
 case 0x00008DCDu: /* AD 7C 05 LDA $057C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x057Cu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8DD0u;
  instance->instruction_count++;
  return 1;
 case 0x00008DD0u: /* F0 59 BEQ $00:8E2B */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x8E2Bu : 0x8DD2u;
  instance->instruction_count++;
  return 1;
 case 0x00008DD2u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8DD3u;
  instance->instruction_count++;
  return 1;
 case 0x00008DD3u: /* 6D 7E 05 ADC $057E */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x057Eu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8DD6u;
  instance->instruction_count++;
  return 1;
 case 0x00008DD6u: /* C9 01 04 CMP #$0401 */
  word = 0x0401u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0x8DD9u;
  instance->instruction_count++;
  return 1;
 case 0x00008DD9u: /* 90 59 BCC $00:8E34 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x8E34u : 0x8DDBu;
  instance->instruction_count++;
  return 1;
 case 0x00008DDBu: /* E9 00 04 SBC #$0400 */
  word = 0x0400u;
  tg_sbc16(instance, word);
  instance->cpu.pc = 0x8DDEu;
  instance->instruction_count++;
  return 1;
 case 0x00008DDEu: /* 8D 7C 05 STA $057C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x057Cu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8DE1u;
  instance->instruction_count++;
  return 1;
 case 0x00008DE1u: /* A9 00 04 LDA #$0400 */
  word = 0x0400u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8DE4u;
  instance->instruction_count++;
  return 1;
 case 0x00008DE4u: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0x8DE5u;
  instance->instruction_count++;
  return 1;
 case 0x00008DE5u: /* ED 7E 05 SBC $057E */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x057Eu), &word)) return 0;
  tg_sbc16(instance, word);
  instance->cpu.pc = 0x8DE8u;
  instance->instruction_count++;
  return 1;
 case 0x00008DE8u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8DE9u;
  instance->instruction_count++;
  return 1;
 case 0x00008DE9u: /* AD 76 05 LDA $0576 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0576u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8DECu;
  instance->instruction_count++;
  return 1;
 case 0x00008DECu: /* 8D 16 21 STA $2116 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8DEFu;
  instance->instruction_count++;
  return 1;
 case 0x00008DEFu: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8DF0u;
  instance->instruction_count++;
  return 1;
 case 0x00008DF0u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8DF1u;
  instance->instruction_count++;
  return 1;
 case 0x00008DF1u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8DF2u;
  instance->instruction_count++;
  return 1;
 case 0x00008DF2u: /* 6D 76 05 ADC $0576 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0576u), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8DF5u;
  instance->instruction_count++;
  return 1;
 case 0x00008DF5u: /* 8D 76 05 STA $0576 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0576u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8DF8u;
  instance->instruction_count++;
  return 1;
 case 0x00008DF8u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8DFAu;
  instance->instruction_count++;
  return 1;
 case 0x04008DFAu: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8DFCu;
  instance->instruction_count++;
  return 1;
 case 0x04008DFCu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8DFFu;
  instance->instruction_count++;
  return 1;
 case 0x04008DFFu: /* AD 7A 05 LDA $057A */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x057Au), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8E02u;
  instance->instruction_count++;
  return 1;
 case 0x04008E02u: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8E05u;
  instance->instruction_count++;
  return 1;
 case 0x04008E05u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8E07u;
  instance->instruction_count++;
  return 1;
 case 0x00008E07u: /* A9 01 18 LDA #$1801 */
  word = 0x1801u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E0Au;
  instance->instruction_count++;
  return 1;
 case 0x00008E0Au: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8E0Du;
  instance->instruction_count++;
  return 1;
 case 0x00008E0Du: /* AD 78 05 LDA $0578 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0578u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E10u;
  instance->instruction_count++;
  return 1;
 case 0x00008E10u: /* 8D 72 43 STA $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8E13u;
  instance->instruction_count++;
  return 1;
 case 0x00008E13u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8E14u;
  instance->instruction_count++;
  return 1;
 case 0x00008E14u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8E15u;
  instance->instruction_count++;
  return 1;
 case 0x00008E15u: /* 6D 78 05 ADC $0578 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0578u), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8E18u;
  instance->instruction_count++;
  return 1;
 case 0x00008E18u: /* 8D 78 05 STA $0578 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0578u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8E1Bu;
  instance->instruction_count++;
  return 1;
 case 0x00008E1Bu: /* 8E 75 43 STX $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0x8E1Eu;
  instance->instruction_count++;
  return 1;
 case 0x00008E1Eu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8E20u;
  instance->instruction_count++;
  return 1;
 case 0x04008E20u: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8E22u;
  instance->instruction_count++;
  return 1;
 case 0x04008E22u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8E25u;
  instance->instruction_count++;
  return 1;
 case 0x04008E25u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8E27u;
  instance->instruction_count++;
  return 1;
 case 0x00008E27u: /* 8C 72 05 STY $0572 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0572u), (uint16_t)instance->cpu.y)) return 0;
  instance->cpu.pc = 0x8E2Au;
  instance->instruction_count++;
  return 1;
 case 0x00008E2Au: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x00008E2Bu: /* CE 74 05 DEC $0574 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0574u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0574u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E2Eu;
  instance->instruction_count++;
  return 1;
 case 0x00008E2Eu: /* D0 54 BNE $00:8E84 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8E84u : 0x8E30u;
  instance->instruction_count++;
  return 1;
 case 0x00008E30u: /* CE 86 1E DEC $1E86 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E86u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E86u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E33u;
  instance->instruction_count++;
  return 1;
 case 0x00008E33u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x00008E34u: /* AD 76 05 LDA $0576 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0576u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E37u;
  instance->instruction_count++;
  return 1;
 case 0x00008E37u: /* 8D 16 21 STA $2116 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8E3Au;
  instance->instruction_count++;
  return 1;
 case 0x00008E3Au: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8E3Cu;
  instance->instruction_count++;
  return 1;
 case 0x04008E3Cu: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8E3Eu;
  instance->instruction_count++;
  return 1;
 case 0x04008E3Eu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8E41u;
  instance->instruction_count++;
  return 1;
 case 0x04008E41u: /* AD 7A 05 LDA $057A */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x057Au), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8E44u;
  instance->instruction_count++;
  return 1;
 case 0x04008E44u: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8E47u;
  instance->instruction_count++;
  return 1;
 case 0x04008E47u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8E49u;
  instance->instruction_count++;
  return 1;
 case 0x00008E49u: /* A9 01 18 LDA #$1801 */
  word = 0x1801u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E4Cu;
  instance->instruction_count++;
  return 1;
 case 0x00008E4Cu: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8E4Fu;
  instance->instruction_count++;
  return 1;
 case 0x00008E4Fu: /* AD 78 05 LDA $0578 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0578u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E52u;
  instance->instruction_count++;
  return 1;
 case 0x00008E52u: /* 8D 72 43 STA $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8E55u;
  instance->instruction_count++;
  return 1;
 case 0x00008E55u: /* AD 7C 05 LDA $057C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x057Cu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E58u;
  instance->instruction_count++;
  return 1;
 case 0x00008E58u: /* 8D 75 43 STA $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8E5Bu;
  instance->instruction_count++;
  return 1;
 case 0x00008E5Bu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8E5Cu;
  instance->instruction_count++;
  return 1;
 case 0x00008E5Cu: /* 6D 7E 05 ADC $057E */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x057Eu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8E5Fu;
  instance->instruction_count++;
  return 1;
 case 0x00008E5Fu: /* C9 00 04 CMP #$0400 */
  word = 0x0400u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0x8E62u;
  instance->instruction_count++;
  return 1;
 case 0x00008E62u: /* D0 0F BNE $00:8E73 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8E73u : 0x8E64u;
  instance->instruction_count++;
  return 1;
 case 0x00008E64u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8E66u;
  instance->instruction_count++;
  return 1;
 case 0x04008E66u: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8E68u;
  instance->instruction_count++;
  return 1;
 case 0x04008E68u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8E6Bu;
  instance->instruction_count++;
  return 1;
 case 0x04008E6Bu: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8E6Du;
  instance->instruction_count++;
  return 1;
 case 0x00008E6Du: /* CE 74 05 DEC $0574 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0574u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0574u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E70u;
  instance->instruction_count++;
  return 1;
 case 0x00008E70u: /* F0 BE BEQ $00:8E30 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x8E30u : 0x8E72u;
  instance->instruction_count++;
  return 1;
 case 0x00008E72u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x00008E73u: /* 8D 7E 05 STA $057E */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x057Eu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8E76u;
  instance->instruction_count++;
  return 1;
 case 0x00008E76u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8E78u;
  instance->instruction_count++;
  return 1;
 case 0x04008E78u: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8E7Au;
  instance->instruction_count++;
  return 1;
 case 0x04008E7Au: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8E7Du;
  instance->instruction_count++;
  return 1;
 case 0x04008E7Du: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8E7Fu;
  instance->instruction_count++;
  return 1;
 case 0x00008E7Fu: /* CE 74 05 DEC $0574 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0574u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0574u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E82u;
  instance->instruction_count++;
  return 1;
 case 0x00008E82u: /* F0 AC BEQ $00:8E30 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x8E30u : 0x8E84u;
  instance->instruction_count++;
  return 1;
 case 0x00008E84u: /* BE E8 1B LDX $1BE8,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BE8u + instance->cpu.y)), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E87u;
  instance->instruction_count++;
  return 1;
 case 0x00008E87u: /* BD 08 1C LDA $1C08,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C08u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E8Au;
  instance->instruction_count++;
  return 1;
 case 0x00008E8Au: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E8Bu;
  instance->instruction_count++;
  return 1;
 case 0x00008E8Bu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E8Cu;
  instance->instruction_count++;
  return 1;
 case 0x00008E8Cu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E8Du;
  instance->instruction_count++;
  return 1;
 case 0x00008E8Du: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E8Eu;
  instance->instruction_count++;
  return 1;
 case 0x00008E8Eu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8E8Fu;
  instance->instruction_count++;
  return 1;
 case 0x00008E8Fu: /* 69 00 30 ADC #$3000 */
  word = 0x3000u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8E92u;
  instance->instruction_count++;
  return 1;
 case 0x00008E92u: /* 8D 76 05 STA $0576 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0576u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8E95u;
  instance->instruction_count++;
  return 1;
 case 0x00008E95u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8E96u;
  instance->instruction_count++;
  return 1;
 case 0x00008E96u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E97u;
  instance->instruction_count++;
  return 1;
 case 0x00008E97u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8E98u;
  instance->instruction_count++;
  return 1;
 case 0x00008E98u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8E99u;
  instance->instruction_count++;
  return 1;
 case 0x00008E99u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8E9Bu;
  instance->instruction_count++;
  return 1;
 case 0x04008E9Bu: /* BD 82 E8 LDA $E882,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE882u + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8E9Eu;
  instance->instruction_count++;
  return 1;
 case 0x04008E9Eu: /* 8D 7A 05 STA $057A */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x057Au), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8EA1u;
  instance->instruction_count++;
  return 1;
 case 0x04008EA1u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8EA3u;
  instance->instruction_count++;
  return 1;
 case 0x00008EA3u: /* BD 84 E8 LDA $E884,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE884u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8EA6u;
  instance->instruction_count++;
  return 1;
 case 0x00008EA6u: /* 8D 78 05 STA $0578 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0578u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8EA9u;
  instance->instruction_count++;
  return 1;
 case 0x00008EA9u: /* BD 86 E8 LDA $E886,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE886u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8EACu;
  instance->instruction_count++;
  return 1;
 case 0x00008EACu: /* 8D 7C 05 STA $057C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x057Cu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8EAFu;
  instance->instruction_count++;
  return 1;
 case 0x00008EAFu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8EB0u;
  instance->instruction_count++;
  return 1;
 case 0x00008EB0u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8EB1u;
  instance->instruction_count++;
  return 1;
 case 0x00008EB1u: /* 4C CD 8D JMP $8DCD */
  instance->cpu.pc = 0x8DCDu;
  instance->instruction_count++;
  return 1;
 case 0x00008EB4u: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8EB6u;
  instance->instruction_count++;
  return 1;
 case 0x00008EB6u: /* AD 88 1E LDA $1E88 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E88u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8EB9u;
  instance->instruction_count++;
  return 1;
 case 0x00008EB9u: /* 10 0A BPL $00:8EC5 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8EC5u : 0x8EBBu;
  instance->instruction_count++;
  return 1;
 case 0x00008EBBu: /* C9 F7 FF CMP #$FFF7 */
  word = 0xFFF7u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0x8EBEu;
  instance->instruction_count++;
  return 1;
 case 0x00008EBEu: /* D0 05 BNE $00:8EC5 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8EC5u : 0x8EC0u;
  instance->instruction_count++;
  return 1;
 case 0x00008EC0u: /* AD B4 1B LDA $1BB4 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB4u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8EC3u;
  instance->instruction_count++;
  return 1;
 case 0x00008EC3u: /* 10 01 BPL $00:8EC6 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x8EC6u : 0x8EC5u;
  instance->instruction_count++;
  return 1;
 case 0x00008EC5u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x00008EC6u: /* 9C 8C 05 STZ $058C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x058Cu), 0u)) return 0;
  instance->cpu.pc = 0x8EC9u;
  instance->instruction_count++;
  return 1;
 case 0x00008EC9u: /* AC 80 05 LDY $0580 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0580u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8ECCu;
  instance->instruction_count++;
  return 1;
 case 0x00008ECCu: /* D0 0B BNE $00:8ED9 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8ED9u : 0x8ECEu;
  instance->instruction_count++;
  return 1;
 case 0x00008ECEu: /* AD 34 1D LDA $1D34 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D34u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8ED1u;
  instance->instruction_count++;
  return 1;
 case 0x00008ED1u: /* F0 69 BEQ $00:8F3C */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x8F3Cu : 0x8ED3u;
  instance->instruction_count++;
  return 1;
 case 0x00008ED3u: /* 8D 82 05 STA $0582 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0582u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8ED6u;
  instance->instruction_count++;
  return 1;
 case 0x00008ED6u: /* 4C 90 8F JMP $8F90 */
  instance->cpu.pc = 0x8F90u;
  instance->instruction_count++;
  return 1;
 case 0x00008ED9u: /* AD 8A 05 LDA $058A */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x058Au), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8EDCu;
  instance->instruction_count++;
  return 1;
 case 0x00008EDCu: /* F0 59 BEQ $00:8F37 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x8F37u : 0x8EDEu;
  instance->instruction_count++;
  return 1;
 case 0x00008EDEu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8EDFu;
  instance->instruction_count++;
  return 1;
 case 0x00008EDFu: /* 6D 8C 05 ADC $058C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x058Cu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8EE2u;
  instance->instruction_count++;
  return 1;
 case 0x00008EE2u: /* C9 00 04 CMP #$0400 */
  word = 0x0400u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0x8EE5u;
  instance->instruction_count++;
  return 1;
 case 0x00008EE5u: /* 90 59 BCC $00:8F40 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0x8F40u : 0x8EE7u;
  instance->instruction_count++;
  return 1;
 case 0x00008EE7u: /* E9 00 04 SBC #$0400 */
  word = 0x0400u;
  tg_sbc16(instance, word);
  instance->cpu.pc = 0x8EEAu;
  instance->instruction_count++;
  return 1;
 case 0x00008EEAu: /* 8D 8A 05 STA $058A */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x058Au), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8EEDu;
  instance->instruction_count++;
  return 1;
 case 0x00008EEDu: /* A9 00 04 LDA #$0400 */
  word = 0x0400u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8EF0u;
  instance->instruction_count++;
  return 1;
 case 0x00008EF0u: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0x8EF1u;
  instance->instruction_count++;
  return 1;
 case 0x00008EF1u: /* ED 8C 05 SBC $058C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x058Cu), &word)) return 0;
  tg_sbc16(instance, word);
  instance->cpu.pc = 0x8EF4u;
  instance->instruction_count++;
  return 1;
 case 0x00008EF4u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8EF5u;
  instance->instruction_count++;
  return 1;
 case 0x00008EF5u: /* AD 84 05 LDA $0584 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0584u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8EF8u;
  instance->instruction_count++;
  return 1;
 case 0x00008EF8u: /* 8D 16 21 STA $2116 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8EFBu;
  instance->instruction_count++;
  return 1;
 case 0x00008EFBu: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8EFCu;
  instance->instruction_count++;
  return 1;
 case 0x00008EFCu: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8EFDu;
  instance->instruction_count++;
  return 1;
 case 0x00008EFDu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8EFEu;
  instance->instruction_count++;
  return 1;
 case 0x00008EFEu: /* 6D 84 05 ADC $0584 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0584u), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8F01u;
  instance->instruction_count++;
  return 1;
 case 0x00008F01u: /* 8D 84 05 STA $0584 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0584u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8F04u;
  instance->instruction_count++;
  return 1;
 case 0x00008F04u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8F06u;
  instance->instruction_count++;
  return 1;
 case 0x04008F06u: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8F08u;
  instance->instruction_count++;
  return 1;
 case 0x04008F08u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8F0Bu;
  instance->instruction_count++;
  return 1;
 case 0x04008F0Bu: /* AD 88 05 LDA $0588 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0588u), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8F0Eu;
  instance->instruction_count++;
  return 1;
 case 0x04008F0Eu: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8F11u;
  instance->instruction_count++;
  return 1;
 case 0x04008F11u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8F13u;
  instance->instruction_count++;
  return 1;
 case 0x00008F13u: /* A9 01 18 LDA #$1801 */
  word = 0x1801u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F16u;
  instance->instruction_count++;
  return 1;
 case 0x00008F16u: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8F19u;
  instance->instruction_count++;
  return 1;
 case 0x00008F19u: /* AD 86 05 LDA $0586 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0586u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F1Cu;
  instance->instruction_count++;
  return 1;
 case 0x00008F1Cu: /* 8D 72 43 STA $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8F1Fu;
  instance->instruction_count++;
  return 1;
 case 0x00008F1Fu: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8F20u;
  instance->instruction_count++;
  return 1;
 case 0x00008F20u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8F21u;
  instance->instruction_count++;
  return 1;
 case 0x00008F21u: /* 6D 86 05 ADC $0586 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0586u), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8F24u;
  instance->instruction_count++;
  return 1;
 case 0x00008F24u: /* 8D 86 05 STA $0586 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0586u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8F27u;
  instance->instruction_count++;
  return 1;
 case 0x00008F27u: /* 8E 75 43 STX $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0x8F2Au;
  instance->instruction_count++;
  return 1;
 case 0x00008F2Au: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8F2Cu;
  instance->instruction_count++;
  return 1;
 case 0x04008F2Cu: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8F2Eu;
  instance->instruction_count++;
  return 1;
 case 0x04008F2Eu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8F31u;
  instance->instruction_count++;
  return 1;
 case 0x04008F31u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8F33u;
  instance->instruction_count++;
  return 1;
 case 0x00008F33u: /* 8C 80 05 STY $0580 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0580u), (uint16_t)instance->cpu.y)) return 0;
  instance->cpu.pc = 0x8F36u;
  instance->instruction_count++;
  return 1;
 case 0x00008F36u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x00008F37u: /* CE 82 05 DEC $0582 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0582u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0582u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F3Au;
  instance->instruction_count++;
  return 1;
 case 0x00008F3Au: /* D0 54 BNE $00:8F90 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8F90u : 0x8F3Cu;
  instance->instruction_count++;
  return 1;
 case 0x00008F3Cu: /* CE 88 1E DEC $1E88 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E88u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E88u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F3Fu;
  instance->instruction_count++;
  return 1;
 case 0x00008F3Fu: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x00008F40u: /* AD 84 05 LDA $0584 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0584u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F43u;
  instance->instruction_count++;
  return 1;
 case 0x00008F43u: /* 8D 16 21 STA $2116 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8F46u;
  instance->instruction_count++;
  return 1;
 case 0x00008F46u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8F48u;
  instance->instruction_count++;
  return 1;
 case 0x04008F48u: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8F4Au;
  instance->instruction_count++;
  return 1;
 case 0x04008F4Au: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8F4Du;
  instance->instruction_count++;
  return 1;
 case 0x04008F4Du: /* AD 88 05 LDA $0588 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0588u), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8F50u;
  instance->instruction_count++;
  return 1;
 case 0x04008F50u: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8F53u;
  instance->instruction_count++;
  return 1;
 case 0x04008F53u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8F55u;
  instance->instruction_count++;
  return 1;
 case 0x00008F55u: /* A9 01 18 LDA #$1801 */
  word = 0x1801u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F58u;
  instance->instruction_count++;
  return 1;
 case 0x00008F58u: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8F5Bu;
  instance->instruction_count++;
  return 1;
 case 0x00008F5Bu: /* AD 86 05 LDA $0586 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0586u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F5Eu;
  instance->instruction_count++;
  return 1;
 case 0x00008F5Eu: /* 8D 72 43 STA $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8F61u;
  instance->instruction_count++;
  return 1;
 case 0x00008F61u: /* AD 8A 05 LDA $058A */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x058Au), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F64u;
  instance->instruction_count++;
  return 1;
 case 0x00008F64u: /* 8D 75 43 STA $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8F67u;
  instance->instruction_count++;
  return 1;
 case 0x00008F67u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8F68u;
  instance->instruction_count++;
  return 1;
 case 0x00008F68u: /* 6D 8C 05 ADC $058C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x058Cu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8F6Bu;
  instance->instruction_count++;
  return 1;
 case 0x00008F6Bu: /* C9 00 04 CMP #$0400 */
  word = 0x0400u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0x8F6Eu;
  instance->instruction_count++;
  return 1;
 case 0x00008F6Eu: /* D0 0F BNE $00:8F7F */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8F7Fu : 0x8F70u;
  instance->instruction_count++;
  return 1;
 case 0x00008F70u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8F72u;
  instance->instruction_count++;
  return 1;
 case 0x04008F72u: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8F74u;
  instance->instruction_count++;
  return 1;
 case 0x04008F74u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8F77u;
  instance->instruction_count++;
  return 1;
 case 0x04008F77u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8F79u;
  instance->instruction_count++;
  return 1;
 case 0x00008F79u: /* CE 82 05 DEC $0582 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0582u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0582u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F7Cu;
  instance->instruction_count++;
  return 1;
 case 0x00008F7Cu: /* F0 BE BEQ $00:8F3C */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x8F3Cu : 0x8F7Eu;
  instance->instruction_count++;
  return 1;
 case 0x00008F7Eu: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x00008F7Fu: /* 8D 8C 05 STA $058C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x058Cu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8F82u;
  instance->instruction_count++;
  return 1;
 case 0x00008F82u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8F84u;
  instance->instruction_count++;
  return 1;
 case 0x04008F84u: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8F86u;
  instance->instruction_count++;
  return 1;
 case 0x04008F86u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8F89u;
  instance->instruction_count++;
  return 1;
 case 0x04008F89u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8F8Bu;
  instance->instruction_count++;
  return 1;
 case 0x00008F8Bu: /* CE 82 05 DEC $0582 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0582u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0582u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F8Eu;
  instance->instruction_count++;
  return 1;
 case 0x00008F8Eu: /* F0 AC BEQ $00:8F3C */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x8F3Cu : 0x8F90u;
  instance->instruction_count++;
  return 1;
 case 0x00008F90u: /* BE 36 1D LDX $1D36,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D36u + instance->cpu.y)), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F93u;
  instance->instruction_count++;
  return 1;
 case 0x00008F93u: /* BD 56 1D LDA $1D56,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D56u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F96u;
  instance->instruction_count++;
  return 1;
 case 0x00008F96u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F97u;
  instance->instruction_count++;
  return 1;
 case 0x00008F97u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F98u;
  instance->instruction_count++;
  return 1;
 case 0x00008F98u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F99u;
  instance->instruction_count++;
  return 1;
 case 0x00008F99u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8F9Au;
  instance->instruction_count++;
  return 1;
 case 0x00008F9Au: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8F9Bu;
  instance->instruction_count++;
  return 1;
 case 0x00008F9Bu: /* 69 00 40 ADC #$4000 */
  word = 0x4000u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8F9Eu;
  instance->instruction_count++;
  return 1;
 case 0x00008F9Eu: /* 8D 84 05 STA $0584 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0584u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8FA1u;
  instance->instruction_count++;
  return 1;
 case 0x00008FA1u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8FA2u;
  instance->instruction_count++;
  return 1;
 case 0x00008FA2u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FA3u;
  instance->instruction_count++;
  return 1;
 case 0x00008FA3u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FA4u;
  instance->instruction_count++;
  return 1;
 case 0x00008FA4u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8FA5u;
  instance->instruction_count++;
  return 1;
 case 0x00008FA5u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8FA7u;
  instance->instruction_count++;
  return 1;
 case 0x04008FA7u: /* BD 82 E8 LDA $E882,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE882u + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x8FAAu;
  instance->instruction_count++;
  return 1;
 case 0x04008FAAu: /* 8D 88 05 STA $0588 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0588u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x8FADu;
  instance->instruction_count++;
  return 1;
 case 0x04008FADu: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8FAFu;
  instance->instruction_count++;
  return 1;
 case 0x00008FAFu: /* BD 84 E8 LDA $E884,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE884u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FB2u;
  instance->instruction_count++;
  return 1;
 case 0x00008FB2u: /* 8D 86 05 STA $0586 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0586u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8FB5u;
  instance->instruction_count++;
  return 1;
 case 0x00008FB5u: /* BD 86 E8 LDA $E886,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE886u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FB8u;
  instance->instruction_count++;
  return 1;
 case 0x00008FB8u: /* 8D 8A 05 STA $058A */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x058Au), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8FBBu;
  instance->instruction_count++;
  return 1;
 case 0x00008FBBu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FBCu;
  instance->instruction_count++;
  return 1;
 case 0x00008FBCu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FBDu;
  instance->instruction_count++;
  return 1;
 case 0x00008FBDu: /* 4C D9 8E JMP $8ED9 */
  instance->cpu.pc = 0x8ED9u;
  instance->instruction_count++;
  return 1;
 case 0x00008FC0u: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x8FC2u;
  instance->instruction_count++;
  return 1;
 case 0x00008FC2u: /* AD 86 1E LDA $1E86 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E86u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FC5u;
  instance->instruction_count++;
  return 1;
 case 0x00008FC5u: /* 10 7E BPL $00:9045 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x9045u : 0x8FC7u;
  instance->instruction_count++;
  return 1;
 case 0x00008FC7u: /* C9 FD FF CMP #$FFFD */
  word = 0xFFFDu;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0x8FCAu;
  instance->instruction_count++;
  return 1;
 case 0x00008FCAu: /* D0 79 BNE $00:9045 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9045u : 0x8FCCu;
  instance->instruction_count++;
  return 1;
 case 0x00008FCCu: /* AD B4 1B LDA $1BB4 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB4u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FCFu;
  instance->instruction_count++;
  return 1;
 case 0x00008FCFu: /* 10 74 BPL $00:9045 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x9045u : 0x8FD1u;
  instance->instruction_count++;
  return 1;
 case 0x00008FD1u: /* AD 72 05 LDA $0572 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0572u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FD4u;
  instance->instruction_count++;
  return 1;
 case 0x00008FD4u: /* D0 0F BNE $00:8FE5 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8FE5u : 0x8FD6u;
  instance->instruction_count++;
  return 1;
 case 0x00008FD6u: /* EE 72 05 INC $0572 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0572u), &word)) return 0;
  word = (uint16_t)(word + 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0572u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FD9u;
  instance->instruction_count++;
  return 1;
 case 0x00008FD9u: /* A9 04 00 LDA #$0004 */
  word = 0x0004u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FDCu;
  instance->instruction_count++;
  return 1;
 case 0x00008FDCu: /* 8D 74 05 STA $0574 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0574u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x8FDFu;
  instance->instruction_count++;
  return 1;
 case 0x00008FDFu: /* 9C 76 05 STZ $0576 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0576u), 0u)) return 0;
  instance->cpu.pc = 0x8FE2u;
  instance->instruction_count++;
  return 1;
 case 0x00008FE2u: /* 9C 78 05 STZ $0578 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0578u), 0u)) return 0;
  instance->cpu.pc = 0x8FE5u;
  instance->instruction_count++;
  return 1;
 case 0x00008FE5u: /* AD 8F 1F LDA $1F8F */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F8Fu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FE8u;
  instance->instruction_count++;
  return 1;
 case 0x00008FE8u: /* 29 03 00 AND #$0003 */
  word = 0x0003u;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FEBu;
  instance->instruction_count++;
  return 1;
 case 0x00008FEBu: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0x8FECu;
  instance->instruction_count++;
  return 1;
 case 0x00008FECu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FEDu;
  instance->instruction_count++;
  return 1;
 case 0x00008FEDu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FEEu;
  instance->instruction_count++;
  return 1;
 case 0x00008FEEu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FEFu;
  instance->instruction_count++;
  return 1;
 case 0x00008FEFu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FF0u;
  instance->instruction_count++;
  return 1;
 case 0x00008FF0u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8FF1u;
  instance->instruction_count++;
  return 1;
 case 0x00008FF1u: /* 69 C0 99 ADC #$99C0 */
  word = 0x99C0u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8FF4u;
  instance->instruction_count++;
  return 1;
 case 0x00008FF4u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8FF5u;
  instance->instruction_count++;
  return 1;
 case 0x00008FF5u: /* 6D 78 05 ADC $0578 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0578u), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x8FF8u;
  instance->instruction_count++;
  return 1;
 case 0x00008FF8u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x8FF9u;
  instance->instruction_count++;
  return 1;
 case 0x00008FF9u: /* AD 78 05 LDA $0578 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0578u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x8FFCu;
  instance->instruction_count++;
  return 1;
 case 0x00008FFCu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x8FFDu;
  instance->instruction_count++;
  return 1;
 case 0x00008FFDu: /* 69 00 04 ADC #$0400 */
  word = 0x0400u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x9000u;
  instance->instruction_count++;
  return 1;
 case 0x00009000u: /* 8D 78 05 STA $0578 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0578u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x9003u;
  instance->instruction_count++;
  return 1;
 case 0x00009003u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x9005u;
  instance->instruction_count++;
  return 1;
 case 0x04009005u: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x9007u;
  instance->instruction_count++;
  return 1;
 case 0x04009007u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x900Au;
  instance->instruction_count++;
  return 1;
 case 0x0400900Au: /* A9 03 LDA #$03 */
  byte = 0x03u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x900Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400900Cu: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x900Fu;
  instance->instruction_count++;
  return 1;
 case 0x0400900Fu: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x9011u;
  instance->instruction_count++;
  return 1;
 case 0x00009011u: /* A9 01 18 LDA #$1801 */
  word = 0x1801u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x9014u;
  instance->instruction_count++;
  return 1;
 case 0x00009014u: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x9017u;
  instance->instruction_count++;
  return 1;
 case 0x00009017u: /* 8E 72 43 STX $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0x901Au;
  instance->instruction_count++;
  return 1;
 case 0x0000901Au: /* A9 00 04 LDA #$0400 */
  word = 0x0400u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x901Du;
  instance->instruction_count++;
  return 1;
 case 0x0000901Du: /* 8D 75 43 STA $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x9020u;
  instance->instruction_count++;
  return 1;
 case 0x00009020u: /* A9 00 30 LDA #$3000 */
  word = 0x3000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x9023u;
  instance->instruction_count++;
  return 1;
 case 0x00009023u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x9024u;
  instance->instruction_count++;
  return 1;
 case 0x00009024u: /* 6D 76 05 ADC $0576 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0576u), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x9027u;
  instance->instruction_count++;
  return 1;
 case 0x00009027u: /* 8D 16 21 STA $2116 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x902Au;
  instance->instruction_count++;
  return 1;
 case 0x0000902Au: /* AD 76 05 LDA $0576 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0576u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x902Du;
  instance->instruction_count++;
  return 1;
 case 0x0000902Du: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x902Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000902Eu: /* 69 00 02 ADC #$0200 */
  word = 0x0200u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x9031u;
  instance->instruction_count++;
  return 1;
 case 0x00009031u: /* 8D 76 05 STA $0576 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0576u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x9034u;
  instance->instruction_count++;
  return 1;
 case 0x00009034u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x9036u;
  instance->instruction_count++;
  return 1;
 case 0x04009036u: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x9038u;
  instance->instruction_count++;
  return 1;
 case 0x04009038u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x903Bu;
  instance->instruction_count++;
  return 1;
 case 0x0400903Bu: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x903Du;
  instance->instruction_count++;
  return 1;
 case 0x0000903Du: /* CE 74 05 DEC $0574 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0574u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0574u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x9040u;
  instance->instruction_count++;
  return 1;
 case 0x00009040u: /* D0 03 BNE $00:9045 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x9045u : 0x9042u;
  instance->instruction_count++;
  return 1;
 case 0x00009042u: /* CE 86 1E DEC $1E86 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E86u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E86u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x9045u;
  instance->instruction_count++;
  return 1;
 case 0x00009045u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x00009046u: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x9048u;
  instance->instruction_count++;
  return 1;
 case 0x00009048u: /* AD 88 1E LDA $1E88 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E88u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x904Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000904Bu: /* 10 7E BPL $00:90CB */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0x90CBu : 0x904Du;
  instance->instruction_count++;
  return 1;
 case 0x0000904Du: /* C9 FD FF CMP #$FFFD */
  word = 0xFFFDu;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0x9050u;
  instance->instruction_count++;
  return 1;
 case 0x00009050u: /* D0 79 BNE $00:90CB */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x90CBu : 0x9052u;
  instance->instruction_count++;
  return 1;
 case 0x00009052u: /* AD B4 1B LDA $1BB4 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB4u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x9055u;
  instance->instruction_count++;
  return 1;
 case 0x00009055u: /* 30 74 BMI $00:90CB */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0x90CBu : 0x9057u;
  instance->instruction_count++;
  return 1;
 case 0x00009057u: /* AD 80 05 LDA $0580 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0580u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x905Au;
  instance->instruction_count++;
  return 1;
 case 0x0000905Au: /* D0 0F BNE $00:906B */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x906Bu : 0x905Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000905Cu: /* EE 80 05 INC $0580 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0580u), &word)) return 0;
  word = (uint16_t)(word + 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0580u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x905Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000905Fu: /* A9 04 00 LDA #$0004 */
  word = 0x0004u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x9062u;
  instance->instruction_count++;
  return 1;
 case 0x00009062u: /* 8D 82 05 STA $0582 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0582u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x9065u;
  instance->instruction_count++;
  return 1;
 case 0x00009065u: /* 9C 84 05 STZ $0584 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0584u), 0u)) return 0;
  instance->cpu.pc = 0x9068u;
  instance->instruction_count++;
  return 1;
 case 0x00009068u: /* 9C 86 05 STZ $0586 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0586u), 0u)) return 0;
  instance->cpu.pc = 0x906Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000906Bu: /* AD AC 1F LDA $1FAC */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FACu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x906Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000906Eu: /* 29 03 00 AND #$0003 */
  word = 0x0003u;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x9071u;
  instance->instruction_count++;
  return 1;
 case 0x00009071u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0x9072u;
  instance->instruction_count++;
  return 1;
 case 0x00009072u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x9073u;
  instance->instruction_count++;
  return 1;
 case 0x00009073u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x9074u;
  instance->instruction_count++;
  return 1;
 case 0x00009074u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x9075u;
  instance->instruction_count++;
  return 1;
 case 0x00009075u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x9076u;
  instance->instruction_count++;
  return 1;
 case 0x00009076u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x9077u;
  instance->instruction_count++;
  return 1;
 case 0x00009077u: /* 69 C0 99 ADC #$99C0 */
  word = 0x99C0u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x907Au;
  instance->instruction_count++;
  return 1;
 case 0x0000907Au: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x907Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000907Bu: /* 6D 86 05 ADC $0586 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0586u), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x907Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000907Eu: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0x907Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000907Fu: /* AD 86 05 LDA $0586 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0586u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x9082u;
  instance->instruction_count++;
  return 1;
 case 0x00009082u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x9083u;
  instance->instruction_count++;
  return 1;
 case 0x00009083u: /* 69 00 04 ADC #$0400 */
  word = 0x0400u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x9086u;
  instance->instruction_count++;
  return 1;
 case 0x00009086u: /* 8D 86 05 STA $0586 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0586u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x9089u;
  instance->instruction_count++;
  return 1;
 case 0x00009089u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x908Bu;
  instance->instruction_count++;
  return 1;
 case 0x0400908Bu: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x908Du;
  instance->instruction_count++;
  return 1;
 case 0x0400908Du: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x9090u;
  instance->instruction_count++;
  return 1;
 case 0x04009090u: /* A9 03 LDA #$03 */
  byte = 0x03u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x9092u;
  instance->instruction_count++;
  return 1;
 case 0x04009092u: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x9095u;
  instance->instruction_count++;
  return 1;
 case 0x04009095u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x9097u;
  instance->instruction_count++;
  return 1;
 case 0x00009097u: /* A9 01 18 LDA #$1801 */
  word = 0x1801u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x909Au;
  instance->instruction_count++;
  return 1;
 case 0x0000909Au: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x909Du;
  instance->instruction_count++;
  return 1;
 case 0x0000909Du: /* 8E 72 43 STX $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0x90A0u;
  instance->instruction_count++;
  return 1;
 case 0x000090A0u: /* A9 00 04 LDA #$0400 */
  word = 0x0400u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x90A3u;
  instance->instruction_count++;
  return 1;
 case 0x000090A3u: /* 8D 75 43 STA $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x90A6u;
  instance->instruction_count++;
  return 1;
 case 0x000090A6u: /* A9 00 40 LDA #$4000 */
  word = 0x4000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x90A9u;
  instance->instruction_count++;
  return 1;
 case 0x000090A9u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x90AAu;
  instance->instruction_count++;
  return 1;
 case 0x000090AAu: /* 6D 84 05 ADC $0584 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0584u), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x90ADu;
  instance->instruction_count++;
  return 1;
 case 0x000090ADu: /* 8D 16 21 STA $2116 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x90B0u;
  instance->instruction_count++;
  return 1;
 case 0x000090B0u: /* AD 84 05 LDA $0584 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0584u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x90B3u;
  instance->instruction_count++;
  return 1;
 case 0x000090B3u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0x90B4u;
  instance->instruction_count++;
  return 1;
 case 0x000090B4u: /* 69 00 02 ADC #$0200 */
  word = 0x0200u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0x90B7u;
  instance->instruction_count++;
  return 1;
 case 0x000090B7u: /* 8D 84 05 STA $0584 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0584u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0x90BAu;
  instance->instruction_count++;
  return 1;
 case 0x000090BAu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x90BCu;
  instance->instruction_count++;
  return 1;
 case 0x040090BCu: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0x90BEu;
  instance->instruction_count++;
  return 1;
 case 0x040090BEu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0x90C1u;
  instance->instruction_count++;
  return 1;
 case 0x040090C1u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0x90C3u;
  instance->instruction_count++;
  return 1;
 case 0x000090C3u: /* CE 82 05 DEC $0582 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0582u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0582u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x90C6u;
  instance->instruction_count++;
  return 1;
 case 0x000090C6u: /* D0 03 BNE $00:90CB */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x90CBu : 0x90C8u;
  instance->instruction_count++;
  return 1;
 case 0x000090C8u: /* CE 88 1E DEC $1E88 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E88u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E88u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0x90CBu;
  instance->instruction_count++;
  return 1;
 case 0x000090CBu: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000B3FEu: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB401u;
  instance->instruction_count++;
  return 1;
 case 0x0000B401u: /* 8D 23 21 STA $2123 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2123u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB404u;
  instance->instruction_count++;
  return 1;
 case 0x0000B404u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB406u;
  instance->instruction_count++;
  return 1;
 case 0x0400B406u: /* 8D 31 21 STA $2131 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2131u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB409u;
  instance->instruction_count++;
  return 1;
 case 0x0400B409u: /* A9 01 LDA #$01 */
  byte = 0x01u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB40Bu;
  instance->instruction_count++;
  return 1;
 case 0x0400B40Bu: /* 8D 01 21 STA $2101 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2101u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB40Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400B40Eu: /* A5 A6 LDA $A6 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xA6u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB410u;
  instance->instruction_count++;
  return 1;
 case 0x0400B410u: /* 8D 0F 21 STA $210F */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Fu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB413u;
  instance->instruction_count++;
  return 1;
 case 0x0400B413u: /* A5 A7 LDA $A7 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xA7u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB415u;
  instance->instruction_count++;
  return 1;
 case 0x0400B415u: /* 8D 0F 21 STA $210F */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Fu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB418u;
  instance->instruction_count++;
  return 1;
 case 0x0400B418u: /* A9 8F LDA #$8F */
  byte = 0x8Fu;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB41Au;
  instance->instruction_count++;
  return 1;
 case 0x0400B41Au: /* 8D 10 21 STA $2110 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB41Du;
  instance->instruction_count++;
  return 1;
 case 0x0400B41Du: /* A9 03 LDA #$03 */
  byte = 0x03u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB41Fu;
  instance->instruction_count++;
  return 1;
 case 0x0400B41Fu: /* 8D 10 21 STA $2110 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB422u;
  instance->instruction_count++;
  return 1;
 case 0x0400B422u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB424u;
  instance->instruction_count++;
  return 1;
 case 0x0000B424u: /* A5 C0 LDA $C0 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xC0u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB426u;
  instance->instruction_count++;
  return 1;
 case 0x0000B426u: /* 85 0A STA $0A */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB428u;
  instance->instruction_count++;
  return 1;
 case 0x0000B428u: /* A9 6C 00 LDA #$006C */
  word = 0x006Cu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB42Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000B42Bu: /* 8D 09 42 STA $4209 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4209u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB42Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000B42Eu: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000B42Fu: /* A9 30 02 LDA #$0230 */
  word = 0x0230u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB432u;
  instance->instruction_count++;
  return 1;
 case 0x0000B432u: /* 8D 23 21 STA $2123 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2123u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB435u;
  instance->instruction_count++;
  return 1;
 case 0x0000B435u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB437u;
  instance->instruction_count++;
  return 1;
 case 0x0400B437u: /* A5 66 LDA $66 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB439u;
  instance->instruction_count++;
  return 1;
 case 0x0400B439u: /* 8D 31 21 STA $2131 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2131u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB43Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400B43Cu: /* A9 01 LDA #$01 */
  byte = 0x01u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB43Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400B43Eu: /* 8D 01 21 STA $2101 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2101u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB441u;
  instance->instruction_count++;
  return 1;
 case 0x0400B441u: /* A5 B0 LDA $B0 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xB0u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB443u;
  instance->instruction_count++;
  return 1;
 case 0x0400B443u: /* 8D 0F 21 STA $210F */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Fu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB446u;
  instance->instruction_count++;
  return 1;
 case 0x0400B446u: /* A5 B1 LDA $B1 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xB1u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB448u;
  instance->instruction_count++;
  return 1;
 case 0x0400B448u: /* 8D 0F 21 STA $210F */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Fu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB44Bu;
  instance->instruction_count++;
  return 1;
 case 0x0400B44Bu: /* A5 B2 LDA $B2 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xB2u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB44Du;
  instance->instruction_count++;
  return 1;
 case 0x0400B44Du: /* 8D 10 21 STA $2110 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB450u;
  instance->instruction_count++;
  return 1;
 case 0x0400B450u: /* A5 B3 LDA $B3 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xB3u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB452u;
  instance->instruction_count++;
  return 1;
 case 0x0400B452u: /* 8D 10 21 STA $2110 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB455u;
  instance->instruction_count++;
  return 1;
 case 0x0400B455u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB457u;
  instance->instruction_count++;
  return 1;
 case 0x0000B457u: /* A5 C0 LDA $C0 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xC0u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB459u;
  instance->instruction_count++;
  return 1;
 case 0x0000B459u: /* 85 0A STA $0A */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB45Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000B45Bu: /* A9 6C 00 LDA #$006C */
  word = 0x006Cu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB45Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000B45Eu: /* 8D 09 42 STA $4209 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4209u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB461u;
  instance->instruction_count++;
  return 1;
 case 0x0000B461u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000B462u: /* A9 30 02 LDA #$0230 */
  word = 0x0230u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB465u;
  instance->instruction_count++;
  return 1;
 case 0x0000B465u: /* 8D 23 21 STA $2123 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2123u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB468u;
  instance->instruction_count++;
  return 1;
 case 0x0000B468u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB46Au;
  instance->instruction_count++;
  return 1;
 case 0x0400B46Au: /* A5 66 LDA $66 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB46Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400B46Cu: /* 8D 31 21 STA $2131 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2131u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB46Fu;
  instance->instruction_count++;
  return 1;
 case 0x0400B46Fu: /* A9 01 LDA #$01 */
  byte = 0x01u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB471u;
  instance->instruction_count++;
  return 1;
 case 0x0400B471u: /* 8D 01 21 STA $2101 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2101u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB474u;
  instance->instruction_count++;
  return 1;
 case 0x0400B474u: /* A5 B0 LDA $B0 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xB0u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB476u;
  instance->instruction_count++;
  return 1;
 case 0x0400B476u: /* 8D 0F 21 STA $210F */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Fu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB479u;
  instance->instruction_count++;
  return 1;
 case 0x0400B479u: /* A5 B1 LDA $B1 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xB1u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB47Bu;
  instance->instruction_count++;
  return 1;
 case 0x0400B47Bu: /* 8D 0F 21 STA $210F */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Fu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB47Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400B47Eu: /* A5 B2 LDA $B2 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xB2u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB480u;
  instance->instruction_count++;
  return 1;
 case 0x0400B480u: /* 8D 10 21 STA $2110 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB483u;
  instance->instruction_count++;
  return 1;
 case 0x0400B483u: /* A5 B3 LDA $B3 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xB3u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB485u;
  instance->instruction_count++;
  return 1;
 case 0x0400B485u: /* 8D 10 21 STA $2110 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB488u;
  instance->instruction_count++;
  return 1;
 case 0x0400B488u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB48Au;
  instance->instruction_count++;
  return 1;
 case 0x0000B48Au: /* A9 C4 B4 LDA #$B4C4 */
  word = 0xB4C4u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB48Du;
  instance->instruction_count++;
  return 1;
 case 0x0000B48Du: /* 85 0A STA $0A */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB48Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000B48Fu: /* A5 AE LDA $AE */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xAEu) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB491u;
  instance->instruction_count++;
  return 1;
 case 0x0000B491u: /* 8D 09 42 STA $4209 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4209u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB494u;
  instance->instruction_count++;
  return 1;
 case 0x0000B494u: /* AD 3D 01 LDA $013D */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x013Du), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB497u;
  instance->instruction_count++;
  return 1;
 case 0x0000B497u: /* 8D 07 42 STA $4207 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4207u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB49Au;
  instance->instruction_count++;
  return 1;
 case 0x0000B49Au: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000B49Bu: /* A9 20 03 LDA #$0320 */
  word = 0x0320u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB49Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000B49Eu: /* 8D 23 21 STA $2123 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2123u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB4A1u;
  instance->instruction_count++;
  return 1;
 case 0x0000B4A1u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB4A3u;
  instance->instruction_count++;
  return 1;
 case 0x0400B4A3u: /* A9 8F LDA #$8F */
  byte = 0x8Fu;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB4A5u;
  instance->instruction_count++;
  return 1;
 case 0x0400B4A5u: /* 8D 10 21 STA $2110 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB4A8u;
  instance->instruction_count++;
  return 1;
 case 0x0400B4A8u: /* A9 03 LDA #$03 */
  byte = 0x03u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB4AAu;
  instance->instruction_count++;
  return 1;
 case 0x0400B4AAu: /* 8D 10 21 STA $2110 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB4ADu;
  instance->instruction_count++;
  return 1;
 case 0x0400B4ADu: /* A5 67 LDA $67 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x67u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB4AFu;
  instance->instruction_count++;
  return 1;
 case 0x0400B4AFu: /* 8D 31 21 STA $2131 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2131u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB4B2u;
  instance->instruction_count++;
  return 1;
 case 0x0400B4B2u: /* A9 01 LDA #$01 */
  byte = 0x01u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB4B4u;
  instance->instruction_count++;
  return 1;
 case 0x0400B4B4u: /* 8D 01 21 STA $2101 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2101u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB4B7u;
  instance->instruction_count++;
  return 1;
 case 0x0400B4B7u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB4B9u;
  instance->instruction_count++;
  return 1;
 case 0x0000B4B9u: /* A5 C0 LDA $C0 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xC0u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB4BBu;
  instance->instruction_count++;
  return 1;
 case 0x0000B4BBu: /* 85 0A STA $0A */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB4BDu;
  instance->instruction_count++;
  return 1;
 case 0x0000B4BDu: /* A9 6C 00 LDA #$006C */
  word = 0x006Cu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB4C0u;
  instance->instruction_count++;
  return 1;
 case 0x0000B4C0u: /* 8D 09 42 STA $4209 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4209u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB4C3u;
  instance->instruction_count++;
  return 1;
 case 0x0000B4C3u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000B4C4u: /* A9 00 21 LDA #$2100 */
  word = 0x2100u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB4C7u;
  instance->instruction_count++;
  return 1;
 case 0x0000B4C7u: /* 5B TCD */
  instance->cpu.d = instance->cpu.a;
  tg_set_nz16(instance, instance->cpu.d);
  instance->cpu.pc = 0xB4C8u;
  instance->instruction_count++;
  return 1;
 case 0x0000B4C8u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB4CAu;
  instance->instruction_count++;
  return 1;
 case 0x0400B4CAu: /* A2 20 03 LDX #$0320 */
  word = 0x0320u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB4CDu;
  instance->instruction_count++;
  return 1;
 case 0x0400B4CDu: /* 2C 01 01 BIT $0101 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0101u), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  tg_set_flag(instance, TG_P_N, (byte & 0x80u) != 0u);
  tg_set_flag(instance, TG_P_V, (byte & 0x40u) != 0u);
  instance->cpu.pc = 0xB4D0u;
  instance->instruction_count++;
  return 1;
 case 0x0400B4D0u: /* 30 21 BMI $00:B4F3 */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xB4F3u : 0xB4D2u;
  instance->instruction_count++;
  return 1;
 case 0x0400B4D2u: /* A9 8F LDA #$8F */
  byte = 0x8Fu;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB4D4u;
  instance->instruction_count++;
  return 1;
 case 0x0400B4D4u: /* 85 10 STA $10 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x10u) & 0xFFFFu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB4D6u;
  instance->instruction_count++;
  return 1;
 case 0x0400B4D6u: /* A9 03 LDA #$03 */
  byte = 0x03u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB4D8u;
  instance->instruction_count++;
  return 1;
 case 0x0400B4D8u: /* 85 10 STA $10 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x10u) & 0xFFFFu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB4DAu;
  instance->instruction_count++;
  return 1;
 case 0x0400B4DAu: /* 86 23 STX $23 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xB4DCu;
  instance->instruction_count++;
  return 1;
 case 0x0400B4DCu: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB4DEu;
  instance->instruction_count++;
  return 1;
 case 0x0000B4DEu: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB4E1u;
  instance->instruction_count++;
  return 1;
 case 0x0000B4E1u: /* 5B TCD */
  instance->cpu.d = instance->cpu.a;
  tg_set_nz16(instance, instance->cpu.d);
  instance->cpu.pc = 0xB4E2u;
  instance->instruction_count++;
  return 1;
 case 0x0000B4E2u: /* A5 C0 LDA $C0 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xC0u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB4E4u;
  instance->instruction_count++;
  return 1;
 case 0x0000B4E4u: /* 85 0A STA $0A */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB4E6u;
  instance->instruction_count++;
  return 1;
 case 0x0000B4E6u: /* A9 6C 00 LDA #$006C */
  word = 0x006Cu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB4E9u;
  instance->instruction_count++;
  return 1;
 case 0x0000B4E9u: /* 8D 09 42 STA $4209 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4209u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB4ECu;
  instance->instruction_count++;
  return 1;
 case 0x0000B4ECu: /* A9 7C 00 LDA #$007C */
  word = 0x007Cu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB4EFu;
  instance->instruction_count++;
  return 1;
 case 0x0000B4EFu: /* 8D 07 42 STA $4207 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4207u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB4F2u;
  instance->instruction_count++;
  return 1;
 case 0x0000B4F2u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0400B4F3u: /* AD 67 00 LDA $0067 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0067u), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB4F6u;
  instance->instruction_count++;
  return 1;
 case 0x0400B4F6u: /* 86 23 STX $23 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xB4F8u;
  instance->instruction_count++;
  return 1;
 case 0x0400B4F8u: /* 85 31 STA $31 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x31u) & 0xFFFFu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB4FAu;
  instance->instruction_count++;
  return 1;
 case 0x0400B4FAu: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB4FCu;
  instance->instruction_count++;
  return 1;
 case 0x0000B4FCu: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB4FFu;
  instance->instruction_count++;
  return 1;
 case 0x0000B4FFu: /* 5B TCD */
  instance->cpu.d = instance->cpu.a;
  tg_set_nz16(instance, instance->cpu.d);
  instance->cpu.pc = 0xB500u;
  instance->instruction_count++;
  return 1;
 case 0x0000B500u: /* A5 C0 LDA $C0 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xC0u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB502u;
  instance->instruction_count++;
  return 1;
 case 0x0000B502u: /* 85 0A STA $0A */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB504u;
  instance->instruction_count++;
  return 1;
 case 0x0000B504u: /* A9 6C 00 LDA #$006C */
  word = 0x006Cu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB507u;
  instance->instruction_count++;
  return 1;
 case 0x0000B507u: /* 8D 09 42 STA $4209 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4209u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB50Au;
  instance->instruction_count++;
  return 1;
 case 0x0000B50Au: /* A9 7C 00 LDA #$007C */
  word = 0x007Cu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB50Du;
  instance->instruction_count++;
  return 1;
 case 0x0000B50Du: /* 8D 07 42 STA $4207 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4207u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB510u;
  instance->instruction_count++;
  return 1;
 case 0x0000B510u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000B57Bu: /* A9 30 02 LDA #$0230 */
  word = 0x0230u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB57Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000B57Eu: /* 8D 23 21 STA $2123 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2123u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB581u;
  instance->instruction_count++;
  return 1;
 case 0x0000B581u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB583u;
  instance->instruction_count++;
  return 1;
 case 0x0400B583u: /* A5 66 LDA $66 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB585u;
  instance->instruction_count++;
  return 1;
 case 0x0400B585u: /* 8D 31 21 STA $2131 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2131u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB588u;
  instance->instruction_count++;
  return 1;
 case 0x0400B588u: /* A9 09 LDA #$09 */
  byte = 0x09u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB58Au;
  instance->instruction_count++;
  return 1;
 case 0x0400B58Au: /* 8D 01 21 STA $2101 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2101u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB58Du;
  instance->instruction_count++;
  return 1;
 case 0x0400B58Du: /* A5 C4 LDA $C4 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xC4u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB58Fu;
  instance->instruction_count++;
  return 1;
 case 0x0400B58Fu: /* 8D 0F 21 STA $210F */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Fu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB592u;
  instance->instruction_count++;
  return 1;
 case 0x0400B592u: /* A5 C5 LDA $C5 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xC5u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB594u;
  instance->instruction_count++;
  return 1;
 case 0x0400B594u: /* 8D 0F 21 STA $210F */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x210Fu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB597u;
  instance->instruction_count++;
  return 1;
 case 0x0400B597u: /* A5 C6 LDA $C6 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xC6u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB599u;
  instance->instruction_count++;
  return 1;
 case 0x0400B599u: /* 8D 10 21 STA $2110 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB59Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400B59Cu: /* A5 C7 LDA $C7 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xC7u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB59Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400B59Eu: /* 8D 10 21 STA $2110 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB5A1u;
  instance->instruction_count++;
  return 1;
 case 0x0400B5A1u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB5A3u;
  instance->instruction_count++;
  return 1;
 case 0x0000B5A3u: /* A9 E2 B5 LDA #$B5E2 */
  word = 0xB5E2u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB5A6u;
  instance->instruction_count++;
  return 1;
 case 0x0000B5A6u: /* 85 0A STA $0A */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB5A8u;
  instance->instruction_count++;
  return 1;
 case 0x0000B5A8u: /* A5 C2 LDA $C2 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xC2u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB5AAu;
  instance->instruction_count++;
  return 1;
 case 0x0000B5AAu: /* 8D 09 42 STA $4209 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4209u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB5ADu;
  instance->instruction_count++;
  return 1;
 case 0x0000B5ADu: /* AD 3D 01 LDA $013D */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x013Du), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB5B0u;
  instance->instruction_count++;
  return 1;
 case 0x0000B5B0u: /* 8D 07 42 STA $4207 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4207u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB5B3u;
  instance->instruction_count++;
  return 1;
 case 0x0000B5B3u: /* 4C 78 BE JMP $BE78 */
  instance->cpu.pc = 0xBE78u;
  instance->instruction_count++;
  return 1;
 case 0x0000B5B6u: /* A9 20 03 LDA #$0320 */
  word = 0x0320u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB5B9u;
  instance->instruction_count++;
  return 1;
 case 0x0000B5B9u: /* 8D 23 21 STA $2123 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2123u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB5BCu;
  instance->instruction_count++;
  return 1;
 case 0x0000B5BCu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB5BEu;
  instance->instruction_count++;
  return 1;
 case 0x0400B5BEu: /* A9 1F LDA #$1F */
  byte = 0x1Fu;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB5C0u;
  instance->instruction_count++;
  return 1;
 case 0x0400B5C0u: /* 8D 10 21 STA $2110 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB5C3u;
  instance->instruction_count++;
  return 1;
 case 0x0400B5C3u: /* A9 03 LDA #$03 */
  byte = 0x03u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB5C5u;
  instance->instruction_count++;
  return 1;
 case 0x0400B5C5u: /* 8D 10 21 STA $2110 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2110u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB5C8u;
  instance->instruction_count++;
  return 1;
 case 0x0400B5C8u: /* A5 67 LDA $67 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x67u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB5CAu;
  instance->instruction_count++;
  return 1;
 case 0x0400B5CAu: /* 8D 31 21 STA $2131 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2131u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB5CDu;
  instance->instruction_count++;
  return 1;
 case 0x0400B5CDu: /* A9 09 LDA #$09 */
  byte = 0x09u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB5CFu;
  instance->instruction_count++;
  return 1;
 case 0x0400B5CFu: /* 8D 01 21 STA $2101 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2101u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB5D2u;
  instance->instruction_count++;
  return 1;
 case 0x0400B5D2u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB5D4u;
  instance->instruction_count++;
  return 1;
 case 0x0000B5D4u: /* A9 D1 B6 LDA #$B6D1 */
  word = 0xB6D1u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB5D7u;
  instance->instruction_count++;
  return 1;
 case 0x0000B5D7u: /* 85 0A STA $0A */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB5D9u;
  instance->instruction_count++;
  return 1;
 case 0x0000B5D9u: /* A9 E0 00 LDA #$00E0 */
  word = 0x00E0u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB5DCu;
  instance->instruction_count++;
  return 1;
 case 0x0000B5DCu: /* 8D 09 42 STA $4209 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4209u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB5DFu;
  instance->instruction_count++;
  return 1;
 case 0x0000B5DFu: /* 4C 78 BE JMP $BE78 */
  instance->cpu.pc = 0xBE78u;
  instance->instruction_count++;
  return 1;
 case 0x0000B5E2u: /* A9 00 21 LDA #$2100 */
  word = 0x2100u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB5E5u;
  instance->instruction_count++;
  return 1;
 case 0x0000B5E5u: /* 5B TCD */
  instance->cpu.d = instance->cpu.a;
  tg_set_nz16(instance, instance->cpu.d);
  instance->cpu.pc = 0xB5E6u;
  instance->instruction_count++;
  return 1;
 case 0x0000B5E6u: /* A2 20 03 LDX #$0320 */
  word = 0x0320u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB5E9u;
  instance->instruction_count++;
  return 1;
 case 0x0000B5E9u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB5EBu;
  instance->instruction_count++;
  return 1;
 case 0x0400B5EBu: /* 2C 01 01 BIT $0101 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0101u), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  tg_set_flag(instance, TG_P_N, (byte & 0x80u) != 0u);
  tg_set_flag(instance, TG_P_V, (byte & 0x40u) != 0u);
  instance->cpu.pc = 0xB5EEu;
  instance->instruction_count++;
  return 1;
 case 0x0400B5EEu: /* 30 22 BMI $00:B612 */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xB612u : 0xB5F0u;
  instance->instruction_count++;
  return 1;
 case 0x0400B5F0u: /* A9 1F LDA #$1F */
  byte = 0x1Fu;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB5F2u;
  instance->instruction_count++;
  return 1;
 case 0x0400B5F2u: /* 85 10 STA $10 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x10u) & 0xFFFFu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB5F4u;
  instance->instruction_count++;
  return 1;
 case 0x0400B5F4u: /* A9 03 LDA #$03 */
  byte = 0x03u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB5F6u;
  instance->instruction_count++;
  return 1;
 case 0x0400B5F6u: /* 85 10 STA $10 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x10u) & 0xFFFFu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB5F8u;
  instance->instruction_count++;
  return 1;
 case 0x0400B5F8u: /* 86 23 STX $23 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xB5FAu;
  instance->instruction_count++;
  return 1;
 case 0x0400B5FAu: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB5FCu;
  instance->instruction_count++;
  return 1;
 case 0x0000B5FCu: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB5FFu;
  instance->instruction_count++;
  return 1;
 case 0x0000B5FFu: /* 5B TCD */
  instance->cpu.d = instance->cpu.a;
  tg_set_nz16(instance, instance->cpu.d);
  instance->cpu.pc = 0xB600u;
  instance->instruction_count++;
  return 1;
 case 0x0000B600u: /* A9 D1 B6 LDA #$B6D1 */
  word = 0xB6D1u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB603u;
  instance->instruction_count++;
  return 1;
 case 0x0000B603u: /* 85 0A STA $0A */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB605u;
  instance->instruction_count++;
  return 1;
 case 0x0000B605u: /* A9 E0 00 LDA #$00E0 */
  word = 0x00E0u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB608u;
  instance->instruction_count++;
  return 1;
 case 0x0000B608u: /* 8D 09 42 STA $4209 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4209u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB60Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000B60Bu: /* A9 7C 00 LDA #$007C */
  word = 0x007Cu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB60Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000B60Eu: /* 8D 07 42 STA $4207 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4207u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB611u;
  instance->instruction_count++;
  return 1;
 case 0x0000B611u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0400B612u: /* AD 67 00 LDA $0067 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0067u), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB615u;
  instance->instruction_count++;
  return 1;
 case 0x0400B615u: /* 86 23 STX $23 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x23u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xB617u;
  instance->instruction_count++;
  return 1;
 case 0x0400B617u: /* 85 31 STA $31 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x31u) & 0xFFFFu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB619u;
  instance->instruction_count++;
  return 1;
 case 0x0400B619u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB61Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000B61Bu: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB61Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000B61Eu: /* 5B TCD */
  instance->cpu.d = instance->cpu.a;
  tg_set_nz16(instance, instance->cpu.d);
  instance->cpu.pc = 0xB61Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000B61Fu: /* A9 D1 B6 LDA #$B6D1 */
  word = 0xB6D1u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB622u;
  instance->instruction_count++;
  return 1;
 case 0x0000B622u: /* 85 0A STA $0A */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB624u;
  instance->instruction_count++;
  return 1;
 case 0x0000B624u: /* A9 E0 00 LDA #$00E0 */
  word = 0x00E0u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB627u;
  instance->instruction_count++;
  return 1;
 case 0x0000B627u: /* 8D 09 42 STA $4209 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4209u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB62Au;
  instance->instruction_count++;
  return 1;
 case 0x0000B62Au: /* A9 7C 00 LDA #$007C */
  word = 0x007Cu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB62Du;
  instance->instruction_count++;
  return 1;
 case 0x0000B62Du: /* 8D 07 42 STA $4207 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4207u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB630u;
  instance->instruction_count++;
  return 1;
 case 0x0000B630u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000B6D1u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB6D3u;
  instance->instruction_count++;
  return 1;
 case 0x0400B6D3u: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB6D5u;
  instance->instruction_count++;
  return 1;
 case 0x0400B6D5u: /* 8D 00 21 STA $2100 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2100u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB6D8u;
  instance->instruction_count++;
  return 1;
 case 0x0400B6D8u: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB6DAu;
  instance->instruction_count++;
  return 1;
 case 0x0000B6DAu: /* E6 0C INC $0C */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Cu) & 0xFFFFu), &word)) return 0;
  word = (uint16_t)(word + 1u);
  if (!tg_bus_write16(instance, (uint32_t)((instance->cpu.d + 0x0Cu) & 0xFFFFu), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB6DCu;
  instance->instruction_count++;
  return 1;
 case 0x0000B6DCu: /* AD 90 05 LDA $0590 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0590u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB6DFu;
  instance->instruction_count++;
  return 1;
 case 0x0000B6DFu: /* 10 2E BPL $00:B70F */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB70Fu : 0xB6E1u;
  instance->instruction_count++;
  return 1;
 case 0x0000B6E1u: /* 9C 90 05 STZ $0590 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0590u), 0u)) return 0;
  instance->cpu.pc = 0xB6E4u;
  instance->instruction_count++;
  return 1;
 case 0x0000B6E4u: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB6E7u;
  instance->instruction_count++;
  return 1;
 case 0x0000B6E7u: /* 8D 02 21 STA $2102 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2102u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB6EAu;
  instance->instruction_count++;
  return 1;
 case 0x0000B6EAu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB6ECu;
  instance->instruction_count++;
  return 1;
 case 0x0400B6ECu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB6EFu;
  instance->instruction_count++;
  return 1;
 case 0x0400B6EFu: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB6F2u;
  instance->instruction_count++;
  return 1;
 case 0x0400B6F2u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB6F4u;
  instance->instruction_count++;
  return 1;
 case 0x0000B6F4u: /* A9 02 04 LDA #$0402 */
  word = 0x0402u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB6F7u;
  instance->instruction_count++;
  return 1;
 case 0x0000B6F7u: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB6FAu;
  instance->instruction_count++;
  return 1;
 case 0x0000B6FAu: /* A9 92 05 LDA #$0592 */
  word = 0x0592u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB6FDu;
  instance->instruction_count++;
  return 1;
 case 0x0000B6FDu: /* 8D 72 43 STA $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB700u;
  instance->instruction_count++;
  return 1;
 case 0x0000B700u: /* A9 20 02 LDA #$0220 */
  word = 0x0220u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB703u;
  instance->instruction_count++;
  return 1;
 case 0x0000B703u: /* 8D 75 43 STA $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB706u;
  instance->instruction_count++;
  return 1;
 case 0x0000B706u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB708u;
  instance->instruction_count++;
  return 1;
 case 0x0400B708u: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB70Au;
  instance->instruction_count++;
  return 1;
 case 0x0400B70Au: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB70Du;
  instance->instruction_count++;
  return 1;
 case 0x0400B70Du: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB70Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000B70Fu: /* AD 8E 05 LDA $058E */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x058Eu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB712u;
  instance->instruction_count++;
  return 1;
 case 0x0000B712u: /* 8D 02 21 STA $2102 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2102u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB715u;
  instance->instruction_count++;
  return 1;
 case 0x0000B715u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xB716u;
  instance->instruction_count++;
  return 1;
 case 0x0000B716u: /* 69 40 00 ADC #$0040 */
  word = 0x0040u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xB719u;
  instance->instruction_count++;
  return 1;
 case 0x0000B719u: /* 29 C0 80 AND #$80C0 */
  word = 0x80C0u;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB71Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000B71Cu: /* 8D 8E 05 STA $058E */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x058Eu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB71Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000B71Fu: /* AD 8C 03 LDA $038C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x038Cu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB722u;
  instance->instruction_count++;
  return 1;
 case 0x0000B722u: /* 10 2B BPL $00:B74F */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB74Fu : 0xB724u;
  instance->instruction_count++;
  return 1;
 case 0x0000B724u: /* 9C 8C 03 STZ $038C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x038Cu), 0u)) return 0;
  instance->cpu.pc = 0xB727u;
  instance->instruction_count++;
  return 1;
 case 0x0000B727u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB729u;
  instance->instruction_count++;
  return 1;
 case 0x0400B729u: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB72Bu;
  instance->instruction_count++;
  return 1;
 case 0x0400B72Bu: /* 8D 21 21 STA $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB72Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400B72Eu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB731u;
  instance->instruction_count++;
  return 1;
 case 0x0400B731u: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB734u;
  instance->instruction_count++;
  return 1;
 case 0x0400B734u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB736u;
  instance->instruction_count++;
  return 1;
 case 0x0000B736u: /* A9 02 22 LDA #$2202 */
  word = 0x2202u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB739u;
  instance->instruction_count++;
  return 1;
 case 0x0000B739u: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB73Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000B73Cu: /* A9 8E 03 LDA #$038E */
  word = 0x038Eu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB73Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000B73Fu: /* 8D 72 43 STA $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB742u;
  instance->instruction_count++;
  return 1;
 case 0x0000B742u: /* A9 00 02 LDA #$0200 */
  word = 0x0200u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB745u;
  instance->instruction_count++;
  return 1;
 case 0x0000B745u: /* 8D 75 43 STA $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB748u;
  instance->instruction_count++;
  return 1;
 case 0x0000B748u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB74Au;
  instance->instruction_count++;
  return 1;
 case 0x0400B74Au: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB74Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400B74Cu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB74Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000B74Fu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB751u;
  instance->instruction_count++;
  return 1;
 case 0x0400B74Fu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB751u;
  instance->instruction_count++;
  return 1;
 case 0x0400B751u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB753u;
  instance->instruction_count++;
  return 1;
 case 0x0000B753u: /* A2 00 00 LDX #$0000 */
  word = 0x0000u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB756u;
  instance->instruction_count++;
  return 1;
 case 0x0000B756u: /* FC 08 00 JSR ($0008,X) */
  address = ((uint32_t)instance->cpu.pbr << 16) | (uint16_t)(0x0008u + instance->cpu.x);
  if (!tg_bus_read16(instance, address, &word)) return 0;
  if (!(word==0xEC7Eu || word==0xB75Au)) return tg_fail_frontier(instance, "Version 22 $0008 auxiliary IRQ indirect JSR target is outside its ROM-proved finite set.", NULL);
  if (!tg_push16(instance, 0xB758u)) return 0;
  instance->cpu.pc = word;
  instance->instruction_count++;
  return 1;
 case 0x0000B759u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000B75Au: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB75Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000B75Cu: /* A5 E3 LDA $E3 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xE3u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB75Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000B75Eu: /* 30 03 BMI $00:B763 */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xB763u : 0xB760u;
  instance->instruction_count++;
  return 1;
 case 0x0000B760u: /* 4C 03 B8 JMP $B803 */
  instance->cpu.pc = 0xB803u;
  instance->instruction_count++;
  return 1;
 case 0x0000B763u: /* 64 E3 STZ $E3 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xE3u) & 0xFFFFu), 0u)) return 0;
  instance->cpu.pc = 0xB765u;
  instance->instruction_count++;
  return 1;
 case 0x0000B765u: /* AD 06 01 LDA $0106 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0106u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB768u;
  instance->instruction_count++;
  return 1;
 case 0x0000B768u: /* D0 03 BNE $00:B76D */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xB76Du : 0xB76Au;
  instance->instruction_count++;
  return 1;
 case 0x0000B76Au: /* EE 06 01 INC $0106 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0106u), &word)) return 0;
  word = (uint16_t)(word + 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0106u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB76Du;
  instance->instruction_count++;
  return 1;
 case 0x0000B76Du: /* A5 40 LDA $40 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x40u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB76Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000B76Fu: /* 30 10 BMI $00:B781 */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xB781u : 0xB771u;
  instance->instruction_count++;
  return 1;
 case 0x0000B771u: /* A5 CE LDA $CE */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xCEu) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB773u;
  instance->instruction_count++;
  return 1;
 case 0x0000B773u: /* A6 C8 LDX $C8 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xC8u) & 0xFFFFu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB775u;
  instance->instruction_count++;
  return 1;
 case 0x0000B775u: /* 85 C8 STA $C8 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xC8u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB777u;
  instance->instruction_count++;
  return 1;
 case 0x0000B777u: /* 86 CE STX $CE */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xCEu) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xB779u;
  instance->instruction_count++;
  return 1;
 case 0x0000B779u: /* A5 D2 LDA $D2 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xD2u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB77Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000B77Bu: /* A6 CC LDX $CC */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xCCu) & 0xFFFFu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB77Du;
  instance->instruction_count++;
  return 1;
 case 0x0000B77Du: /* 85 CC STA $CC */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xCCu) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB77Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000B77Fu: /* 86 D2 STX $D2 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xD2u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xB781u;
  instance->instruction_count++;
  return 1;
 case 0x0000B781u: /* A5 53 LDA $53 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x53u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB783u;
  instance->instruction_count++;
  return 1;
 case 0x0000B783u: /* 30 10 BMI $00:B795 */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xB795u : 0xB785u;
  instance->instruction_count++;
  return 1;
 case 0x0000B785u: /* A5 DA LDA $DA */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xDAu) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB787u;
  instance->instruction_count++;
  return 1;
 case 0x0000B787u: /* A6 D4 LDX $D4 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xD4u) & 0xFFFFu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB789u;
  instance->instruction_count++;
  return 1;
 case 0x0000B789u: /* 85 D4 STA $D4 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xD4u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB78Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000B78Bu: /* 86 DA STX $DA */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xDAu) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xB78Du;
  instance->instruction_count++;
  return 1;
 case 0x0000B78Du: /* A5 DE LDA $DE */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xDEu) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB78Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000B78Fu: /* A6 D8 LDX $D8 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xD8u) & 0xFFFFu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB791u;
  instance->instruction_count++;
  return 1;
 case 0x0000B791u: /* 85 D8 STA $D8 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xD8u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB793u;
  instance->instruction_count++;
  return 1;
 case 0x0000B793u: /* 86 DE STX $DE */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xDEu) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xB795u;
  instance->instruction_count++;
  return 1;
 case 0x0000B795u: /* A5 CA LDA $CA */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xCAu) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB797u;
  instance->instruction_count++;
  return 1;
 case 0x0000B797u: /* 85 D0 STA $D0 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xD0u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB799u;
  instance->instruction_count++;
  return 1;
 case 0x0000B799u: /* A5 D6 LDA $D6 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xD6u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB79Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000B79Bu: /* 85 DC STA $DC */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xDCu) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB79Du;
  instance->instruction_count++;
  return 1;
 case 0x0000B79Du: /* A5 E5 LDA $E5 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xE5u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB79Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000B79Fu: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7A2u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7A2u: /* 85 E5 STA $E5 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xE5u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7A4u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7A4u: /* 10 17 BPL $00:B7BD */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB7BDu : 0xB7A6u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7A6u: /* A2 07 BF LDX #$BF07 */
  word = 0xBF07u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7A9u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7A9u: /* A0 AF 0E LDY #$0EAF */
  word = 0x0EAFu;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7ACu;
  instance->instruction_count++;
  return 1;
 case 0x0000B7ACu: /* A9 92 05 LDA #$0592 */
  word = 0x0592u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7AFu;
  instance->instruction_count++;
  return 1;
 case 0x0000B7AFu: /* 85 E7 STA $E7 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xE7u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7B1u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7B1u: /* A9 12 0C LDA #$0C12 */
  word = 0x0C12u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7B4u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7B4u: /* 85 E9 STA $E9 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xE9u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7B6u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7B6u: /* A9 54 0E LDA #$0E54 */
  word = 0x0E54u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7B9u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7B9u: /* 85 EB STA $EB */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xEBu) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7BBu;
  instance->instruction_count++;
  return 1;
 case 0x0000B7BBu: /* 80 15 BRA $00:B7D2 */
  instance->cpu.pc = 0xB7D2u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7BDu: /* A2 FA BE LDX #$BEFA */
  word = 0xBEFAu;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7C0u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7C0u: /* A0 54 0E LDY #$0E54 */
  word = 0x0E54u;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7C3u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7C3u: /* A9 D2 08 LDA #$08D2 */
  word = 0x08D2u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7C6u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7C6u: /* 85 E7 STA $E7 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xE7u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7C8u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7C8u: /* A9 33 0D LDA #$0D33 */
  word = 0x0D33u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7CBu;
  instance->instruction_count++;
  return 1;
 case 0x0000B7CBu: /* 85 E9 STA $E9 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xE9u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7CDu;
  instance->instruction_count++;
  return 1;
 case 0x0000B7CDu: /* A9 AF 0E LDA #$0EAF */
  word = 0x0EAFu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7D0u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7D0u: /* 85 EB STA $EB */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xEBu) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7D2u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7D2u: /* A5 A0 LDA $A0 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xA0u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7D4u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7D4u: /* 8D 02 43 STA $4302 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4302u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7D7u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7D7u: /* 8D 12 43 STA $4312 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4312u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7DAu;
  instance->instruction_count++;
  return 1;
 case 0x0000B7DAu: /* 8D 22 43 STA $4322 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4322u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7DDu;
  instance->instruction_count++;
  return 1;
 case 0x0000B7DDu: /* 8D 32 43 STA $4332 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4332u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7E0u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7E0u: /* 8D 42 43 STA $4342 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4342u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7E3u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7E3u: /* 8E 52 43 STX $4352 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4352u), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xB7E6u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7E6u: /* 8C 62 43 STY $4362 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4362u), (uint16_t)instance->cpu.y)) return 0;
  instance->cpu.pc = 0xB7E9u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7E9u: /* A5 BE LDA $BE */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xBEu) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7EBu;
  instance->instruction_count++;
  return 1;
 case 0x0000B7EBu: /* 85 C6 STA $C6 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xC6u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7EDu;
  instance->instruction_count++;
  return 1;
 case 0x0000B7EDu: /* A5 B8 LDA $B8 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xB8u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7EFu;
  instance->instruction_count++;
  return 1;
 case 0x0000B7EFu: /* 85 C2 STA $C2 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xC2u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7F1u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7F1u: /* A5 B6 LDA $B6 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xB6u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7F3u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7F3u: /* 85 C0 STA $C0 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xC0u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7F5u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7F5u: /* A5 AA LDA $AA */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xAAu) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7F7u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7F7u: /* 85 B2 STA $B2 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xB2u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7F9u;
  instance->instruction_count++;
  return 1;
 case 0x0000B7F9u: /* A5 A4 LDA $A4 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xA4u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7FBu;
  instance->instruction_count++;
  return 1;
 case 0x0000B7FBu: /* 85 AE STA $AE */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xAEu) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB7FDu;
  instance->instruction_count++;
  return 1;
 case 0x0000B7FDu: /* A5 A2 LDA $A2 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xA2u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB7FFu;
  instance->instruction_count++;
  return 1;
 case 0x0000B7FFu: /* 85 AC STA $AC */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xACu) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB801u;
  instance->instruction_count++;
  return 1;
 case 0x0000B801u: /* 85 0A STA $0A */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB803u;
  instance->instruction_count++;
  return 1;
 case 0x0000B803u: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB806u;
  instance->instruction_count++;
  return 1;
 case 0x0000B806u: /* 8D 02 21 STA $2102 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2102u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB809u;
  instance->instruction_count++;
  return 1;
 case 0x0000B809u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB80Bu;
  instance->instruction_count++;
  return 1;
 case 0x0400B80Bu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB80Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400B80Eu: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB811u;
  instance->instruction_count++;
  return 1;
 case 0x0400B811u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB813u;
  instance->instruction_count++;
  return 1;
 case 0x0000B813u: /* A9 02 04 LDA #$0402 */
  word = 0x0402u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB816u;
  instance->instruction_count++;
  return 1;
 case 0x0000B816u: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB819u;
  instance->instruction_count++;
  return 1;
 case 0x0000B819u: /* A5 D2 LDA $D2 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xD2u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB81Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000B81Bu: /* 8D 72 43 STA $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB81Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000B81Eu: /* A9 20 02 LDA #$0220 */
  word = 0x0220u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB821u;
  instance->instruction_count++;
  return 1;
 case 0x0000B821u: /* 8D 75 43 STA $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB824u;
  instance->instruction_count++;
  return 1;
 case 0x0000B824u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB826u;
  instance->instruction_count++;
  return 1;
 case 0x0400B826u: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB828u;
  instance->instruction_count++;
  return 1;
 case 0x0400B828u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB82Bu;
  instance->instruction_count++;
  return 1;
 case 0x0400B82Bu: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB82Du;
  instance->instruction_count++;
  return 1;
 case 0x0000B82Du: /* A5 D0 LDA $D0 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xD0u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB82Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000B82Fu: /* 09 00 80 ORA #$8000 */
  word = 0x8000u;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB832u;
  instance->instruction_count++;
  return 1;
 case 0x0000B832u: /* 8D 02 21 STA $2102 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2102u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB835u;
  instance->instruction_count++;
  return 1;
 case 0x0000B835u: /* AD 58 1E LDA $1E58 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E58u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB838u;
  instance->instruction_count++;
  return 1;
 case 0x0000B838u: /* 10 0E BPL $00:B848 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB848u : 0xB83Au;
  instance->instruction_count++;
  return 1;
 case 0x0000B83Au: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB83Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400B83Cu: /* A9 19 LDA #$19 */
  byte = 0x19u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB83Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400B83Eu: /* 8D 41 21 STA $2141 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB841u;
  instance->instruction_count++;
  return 1;
 case 0x0400B841u: /* 85 3D STA $3D */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Du) & 0xFFFFu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB843u;
  instance->instruction_count++;
  return 1;
 case 0x0400B843u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB845u;
  instance->instruction_count++;
  return 1;
 case 0x0000B845u: /* 4C 32 BE JMP $BE32 */
  instance->cpu.pc = 0xBE32u;
  instance->instruction_count++;
  return 1;
 case 0x0000B848u: /* AD F6 1F LDA $1FF6 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FF6u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB84Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000B84Bu: /* F0 03 BEQ $00:B850 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB850u : 0xB84Du;
  instance->instruction_count++;
  return 1;
 case 0x0000B84Du: /* 4C 60 B9 JMP $B960 */
  instance->cpu.pc = 0xB960u;
  instance->instruction_count++;
  return 1;
 case 0x0000B850u: /* E2 30 SEP #$30 */
  instance->cpu.p |=0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB852u;
  instance->instruction_count++;
  return 1;
 case 0x0600B852u: /* A5 3D LDA $3D */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x3Du) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB854u;
  instance->instruction_count++;
  return 1;
 case 0x0600B854u: /* 30 08 BMI $00:B85E */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xB85Eu : 0xB856u;
  instance->instruction_count++;
  return 1;
 case 0x0600B856u: /* CD 41 21 CMP $2141 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), &byte)) return 0;
  tg_compare8(instance, tg_acc8(instance), byte);
  instance->cpu.pc = 0xB859u;
  instance->instruction_count++;
  return 1;
 case 0x0600B859u: /* F0 03 BEQ $00:B85E */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB85Eu : 0xB85Bu;
  instance->instruction_count++;
  return 1;
 case 0x0600B85Bu: /* 4C 5E B9 JMP $B95E */
  instance->cpu.pc = 0xB95Eu;
  instance->instruction_count++;
  return 1;
 case 0x0600B85Eu: /* A5 3E LDA $3E */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x3Eu) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB860u;
  instance->instruction_count++;
  return 1;
 case 0x0600B860u: /* F0 03 BEQ $00:B865 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB865u : 0xB862u;
  instance->instruction_count++;
  return 1;
 case 0x0600B862u: /* 4C 55 B9 JMP $B955 */
  instance->cpu.pc = 0xB955u;
  instance->instruction_count++;
  return 1;
 case 0x0600B865u: /* A9 08 LDA #$08 */
  byte = 0x08u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB867u;
  instance->instruction_count++;
  return 1;
 case 0x0600B867u: /* 2C F5 1E BIT $1EF5 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF5u), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  tg_set_flag(instance, TG_P_N, (byte & 0x80u) != 0u);
  tg_set_flag(instance, TG_P_V, (byte & 0x40u) != 0u);
  instance->cpu.pc = 0xB86Au;
  instance->instruction_count++;
  return 1;
 case 0x0600B86Au: /* D0 72 BNE $00:B8DE */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xB8DEu : 0xB86Cu;
  instance->instruction_count++;
  return 1;
 case 0x0600B86Cu: /* 2C F6 1E BIT $1EF6 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF6u), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  tg_set_flag(instance, TG_P_N, (byte & 0x80u) != 0u);
  tg_set_flag(instance, TG_P_V, (byte & 0x40u) != 0u);
  instance->cpu.pc = 0xB86Fu;
  instance->instruction_count++;
  return 1;
 case 0x0600B86Fu: /* D0 06 BNE $00:B877 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xB877u : 0xB871u;
  instance->instruction_count++;
  return 1;
 case 0x0600B871u: /* A9 01 LDA #$01 */
  byte = 0x01u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB873u;
  instance->instruction_count++;
  return 1;
 case 0x0600B873u: /* 24 3F BIT $3F */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x3Fu) & 0xFFFFu), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  tg_set_flag(instance, TG_P_N, (byte & 0x80u) != 0u);
  tg_set_flag(instance, TG_P_V, (byte & 0x40u) != 0u);
  instance->cpu.pc = 0xB875u;
  instance->instruction_count++;
  return 1;
 case 0x0600B875u: /* D0 70 BNE $00:B8E7 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xB8E7u : 0xB877u;
  instance->instruction_count++;
  return 1;
 case 0x0600B877u: /* A9 04 LDA #$04 */
  byte = 0x04u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB879u;
  instance->instruction_count++;
  return 1;
 case 0x0600B879u: /* 1C F5 1E TRB $1EF5 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF5u), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  byte = (uint8_t)(byte & (uint8_t)~(uint8_t)tg_acc8(instance));
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF5u), byte)) return 0;
  instance->cpu.pc = 0xB87Cu;
  instance->instruction_count++;
  return 1;
 case 0x0600B87Cu: /* F0 09 BEQ $00:B887 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB887u : 0xB87Eu;
  instance->instruction_count++;
  return 1;
 case 0x0600B87Eu: /* 0A ASL A */
  byte = tg_acc8(instance);
  tg_set_flag(instance, TG_P_C, (byte & 0x80u) != 0u);
  byte = (uint8_t)(byte << 1);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB87Fu;
  instance->instruction_count++;
  return 1;
 case 0x0600B87Fu: /* 0C F5 1E TSB $1EF5 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF5u), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  byte = (uint8_t)(byte | (uint8_t)tg_acc8(instance));
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF5u), byte)) return 0;
  instance->cpu.pc = 0xB882u;
  instance->instruction_count++;
  return 1;
 case 0x0600B882u: /* A9 07 LDA #$07 */
  byte = 0x07u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB884u;
  instance->instruction_count++;
  return 1;
 case 0x0600B884u: /* 4C 4B B9 JMP $B94B */
  instance->cpu.pc = 0xB94Bu;
  instance->instruction_count++;
  return 1;
 case 0x0600B887u: /* 4A LSR A */
  byte = tg_acc8(instance);
  tg_set_flag(instance, TG_P_C, (byte & 1u) != 0u);
  byte = (uint8_t)(byte >> 1);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB888u;
  instance->instruction_count++;
  return 1;
 case 0x0600B888u: /* 24 3F BIT $3F */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x3Fu) & 0xFFFFu), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  tg_set_flag(instance, TG_P_N, (byte & 0x80u) != 0u);
  tg_set_flag(instance, TG_P_V, (byte & 0x40u) != 0u);
  instance->cpu.pc = 0xB88Au;
  instance->instruction_count++;
  return 1;
 case 0x0600B88Au: /* F0 36 BEQ $00:B8C2 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB8C2u : 0xB88Cu;
  instance->instruction_count++;
  return 1;
 case 0x0600B88Cu: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB88Eu;
  instance->instruction_count++;
  return 1;
 case 0x0600B88Eu: /* 1C F5 1E TRB $1EF5 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF5u), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  byte = (uint8_t)(byte & (uint8_t)~(uint8_t)tg_acc8(instance));
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF5u), byte)) return 0;
  instance->cpu.pc = 0xB891u;
  instance->instruction_count++;
  return 1;
 case 0x0600B891u: /* F0 05 BEQ $00:B898 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB898u : 0xB893u;
  instance->instruction_count++;
  return 1;
 case 0x0600B893u: /* A9 0B LDA #$0B */
  byte = 0x0Bu;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB895u;
  instance->instruction_count++;
  return 1;
 case 0x0600B895u: /* 4C 4B B9 JMP $B94B */
  instance->cpu.pc = 0xB94Bu;
  instance->instruction_count++;
  return 1;
 case 0x0600B898u: /* AD 6D 1E LDA $1E6D */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Du), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB89Bu;
  instance->instruction_count++;
  return 1;
 case 0x0600B89Bu: /* 10 0D BPL $00:B8AA */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB8AAu : 0xB89Du;
  instance->instruction_count++;
  return 1;
 case 0x0600B89Du: /* AE 70 1E LDX $1E70 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E70u), &byte)) return 0;
  tg_set_index8(instance, &instance->cpu.x, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB8A0u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8A0u: /* 30 08 BMI $00:B8AA */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xB8AAu : 0xB8A2u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8A2u: /* 8D 70 1E STA $1E70 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E70u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB8A5u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8A5u: /* A9 05 LDA #$05 */
  byte = 0x05u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB8A7u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8A7u: /* 4C 4B B9 JMP $B94B */
  instance->cpu.pc = 0xB94Bu;
  instance->instruction_count++;
  return 1;
 case 0x0600B8AAu: /* 8D 70 1E STA $1E70 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E70u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB8ADu;
  instance->instruction_count++;
  return 1;
 case 0x0600B8ADu: /* AD 67 1E LDA $1E67 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E67u), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB8B0u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8B0u: /* 10 0D BPL $00:B8BF */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB8BFu : 0xB8B2u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8B2u: /* AE 6A 1E LDX $1E6A */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Au), &byte)) return 0;
  tg_set_index8(instance, &instance->cpu.x, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB8B5u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8B5u: /* 30 08 BMI $00:B8BF */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xB8BFu : 0xB8B7u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8B7u: /* 8D 6A 1E STA $1E6A */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Au), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB8BAu;
  instance->instruction_count++;
  return 1;
 case 0x0600B8BAu: /* A9 0A LDA #$0A */
  byte = 0x0Au;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB8BCu;
  instance->instruction_count++;
  return 1;
 case 0x0600B8BCu: /* 4C 4B B9 JMP $B94B */
  instance->cpu.pc = 0xB94Bu;
  instance->instruction_count++;
  return 1;
 case 0x0600B8BFu: /* 8D 6A 1E STA $1E6A */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Au), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB8C2u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8C2u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB8C4u;
  instance->instruction_count++;
  return 1;
 case 0x0200B8C4u: /* AD 62 1E LDA $1E62 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E62u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB8C7u;
  instance->instruction_count++;
  return 1;
 case 0x0200B8C7u: /* F0 0C BEQ $00:B8D5 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB8D5u : 0xB8C9u;
  instance->instruction_count++;
  return 1;
 case 0x0200B8C9u: /* AD 5E 1E LDA $1E5E */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Eu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB8CCu;
  instance->instruction_count++;
  return 1;
 case 0x0200B8CCu: /* 10 03 BPL $00:B8D1 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB8D1u : 0xB8CEu;
  instance->instruction_count++;
  return 1;
 case 0x0200B8CEu: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB8D1u;
  instance->instruction_count++;
  return 1;
 case 0x0200B8D1u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xB8D2u;
  instance->instruction_count++;
  return 1;
 case 0x0200B8D2u: /* 69 00 04 ADC #$0400 */
  word = 0x0400u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xB8D5u;
  instance->instruction_count++;
  return 1;
 case 0x0200B8D5u: /* 8D 42 21 STA $2142 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2142u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB8D8u;
  instance->instruction_count++;
  return 1;
 case 0x0200B8D8u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB8DAu;
  instance->instruction_count++;
  return 1;
 case 0x0600B8DAu: /* A9 03 LDA #$03 */
  byte = 0x03u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB8DCu;
  instance->instruction_count++;
  return 1;
 case 0x0600B8DCu: /* 80 77 BRA $00:B955 */
  instance->cpu.pc = 0xB955u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8DEu: /* 2C F6 1E BIT $1EF6 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF6u), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  tg_set_flag(instance, TG_P_N, (byte & 0x80u) != 0u);
  tg_set_flag(instance, TG_P_V, (byte & 0x40u) != 0u);
  instance->cpu.pc = 0xB8E1u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8E1u: /* F0 04 BEQ $00:B8E7 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB8E7u : 0xB8E3u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8E3u: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB8E5u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8E5u: /* 80 64 BRA $00:B94B */
  instance->cpu.pc = 0xB94Bu;
  instance->instruction_count++;
  return 1;
 case 0x0600B8E7u: /* A9 04 LDA #$04 */
  byte = 0x04u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB8E9u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8E9u: /* 1C F6 1E TRB $1EF6 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF6u), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  byte = (uint8_t)(byte & (uint8_t)~(uint8_t)tg_acc8(instance));
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF6u), byte)) return 0;
  instance->cpu.pc = 0xB8ECu;
  instance->instruction_count++;
  return 1;
 case 0x0600B8ECu: /* F0 08 BEQ $00:B8F6 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB8F6u : 0xB8EEu;
  instance->instruction_count++;
  return 1;
 case 0x0600B8EEu: /* 0A ASL A */
  byte = tg_acc8(instance);
  tg_set_flag(instance, TG_P_C, (byte & 0x80u) != 0u);
  byte = (uint8_t)(byte << 1);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB8EFu;
  instance->instruction_count++;
  return 1;
 case 0x0600B8EFu: /* 0C F6 1E TSB $1EF6 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF6u), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  byte = (uint8_t)(byte | (uint8_t)tg_acc8(instance));
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF6u), byte)) return 0;
  instance->cpu.pc = 0xB8F2u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8F2u: /* A9 12 LDA #$12 */
  byte = 0x12u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB8F4u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8F4u: /* 80 55 BRA $00:B94B */
  instance->cpu.pc = 0xB94Bu;
  instance->instruction_count++;
  return 1;
 case 0x0600B8F6u: /* 4A LSR A */
  byte = tg_acc8(instance);
  tg_set_flag(instance, TG_P_C, (byte & 1u) != 0u);
  byte = (uint8_t)(byte >> 1);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB8F7u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8F7u: /* 24 3F BIT $3F */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x3Fu) & 0xFFFFu), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  tg_set_flag(instance, TG_P_N, (byte & 0x80u) != 0u);
  tg_set_flag(instance, TG_P_V, (byte & 0x40u) != 0u);
  instance->cpu.pc = 0xB8F9u;
  instance->instruction_count++;
  return 1;
 case 0x0600B8F9u: /* F0 34 BEQ $00:B92F */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB92Fu : 0xB8FBu;
  instance->instruction_count++;
  return 1;
 case 0x0600B8FBu: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB8FDu;
  instance->instruction_count++;
  return 1;
 case 0x0600B8FDu: /* 1C F6 1E TRB $1EF6 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF6u), &byte)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint8_t)tg_acc8(instance) & byte) == 0u);
  byte = (uint8_t)(byte & (uint8_t)~(uint8_t)tg_acc8(instance));
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EF6u), byte)) return 0;
  instance->cpu.pc = 0xB900u;
  instance->instruction_count++;
  return 1;
 case 0x0600B900u: /* F0 05 BEQ $00:B907 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB907u : 0xB902u;
  instance->instruction_count++;
  return 1;
 case 0x0600B902u: /* A9 16 LDA #$16 */
  byte = 0x16u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB904u;
  instance->instruction_count++;
  return 1;
 case 0x0600B904u: /* 4C 4B B9 JMP $B94B */
  instance->cpu.pc = 0xB94Bu;
  instance->instruction_count++;
  return 1;
 case 0x0600B907u: /* AD 6F 1E LDA $1E6F */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Fu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB90Au;
  instance->instruction_count++;
  return 1;
 case 0x0600B90Au: /* 10 0C BPL $00:B918 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB918u : 0xB90Cu;
  instance->instruction_count++;
  return 1;
 case 0x0600B90Cu: /* AE 71 1E LDX $1E71 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E71u), &byte)) return 0;
  tg_set_index8(instance, &instance->cpu.x, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB90Fu;
  instance->instruction_count++;
  return 1;
 case 0x0600B90Fu: /* 30 07 BMI $00:B918 */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xB918u : 0xB911u;
  instance->instruction_count++;
  return 1;
 case 0x0600B911u: /* 8D 71 1E STA $1E71 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E71u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB914u;
  instance->instruction_count++;
  return 1;
 case 0x0600B914u: /* A9 10 LDA #$10 */
  byte = 0x10u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB916u;
  instance->instruction_count++;
  return 1;
 case 0x0600B916u: /* 80 33 BRA $00:B94B */
  instance->cpu.pc = 0xB94Bu;
  instance->instruction_count++;
  return 1;
 case 0x0600B918u: /* 8D 71 1E STA $1E71 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E71u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB91Bu;
  instance->instruction_count++;
  return 1;
 case 0x0600B91Bu: /* AD 69 1E LDA $1E69 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E69u), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB91Eu;
  instance->instruction_count++;
  return 1;
 case 0x0600B91Eu: /* 10 0C BPL $00:B92C */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB92Cu : 0xB920u;
  instance->instruction_count++;
  return 1;
 case 0x0600B920u: /* AE 6B 1E LDX $1E6B */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Bu), &byte)) return 0;
  tg_set_index8(instance, &instance->cpu.x, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB923u;
  instance->instruction_count++;
  return 1;
 case 0x0600B923u: /* 30 07 BMI $00:B92C */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xB92Cu : 0xB925u;
  instance->instruction_count++;
  return 1;
 case 0x0600B925u: /* 8D 6B 1E STA $1E6B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB928u;
  instance->instruction_count++;
  return 1;
 case 0x0600B928u: /* A9 15 LDA #$15 */
  byte = 0x15u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB92Au;
  instance->instruction_count++;
  return 1;
 case 0x0600B92Au: /* 80 1F BRA $00:B94B */
  instance->cpu.pc = 0xB94Bu;
  instance->instruction_count++;
  return 1;
 case 0x0600B92Cu: /* 8D 6B 1E STA $1E6B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB92Fu;
  instance->instruction_count++;
  return 1;
 case 0x0600B92Fu: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB931u;
  instance->instruction_count++;
  return 1;
 case 0x0200B931u: /* AD 64 1E LDA $1E64 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E64u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB934u;
  instance->instruction_count++;
  return 1;
 case 0x0200B934u: /* F0 0C BEQ $00:B942 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB942u : 0xB936u;
  instance->instruction_count++;
  return 1;
 case 0x0200B936u: /* AD 60 1E LDA $1E60 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E60u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB939u;
  instance->instruction_count++;
  return 1;
 case 0x0200B939u: /* 10 03 BPL $00:B93E */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB93Eu : 0xB93Bu;
  instance->instruction_count++;
  return 1;
 case 0x0200B93Bu: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB93Eu;
  instance->instruction_count++;
  return 1;
 case 0x0200B93Eu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xB93Fu;
  instance->instruction_count++;
  return 1;
 case 0x0200B93Fu: /* 69 00 04 ADC #$0400 */
  word = 0x0400u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xB942u;
  instance->instruction_count++;
  return 1;
 case 0x0200B942u: /* 8D 42 21 STA $2142 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2142u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB945u;
  instance->instruction_count++;
  return 1;
 case 0x0200B945u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB947u;
  instance->instruction_count++;
  return 1;
 case 0x0600B947u: /* A9 0E LDA #$0E */
  byte = 0x0Eu;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB949u;
  instance->instruction_count++;
  return 1;
 case 0x0600B949u: /* 80 0A BRA $00:B955 */
  instance->cpu.pc = 0xB955u;
  instance->instruction_count++;
  return 1;
 case 0x0600B94Bu: /* C5 3D CMP $3D */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x3Du) & 0xFFFFu), &byte)) return 0;
  tg_compare8(instance, tg_acc8(instance), byte);
  instance->cpu.pc = 0xB94Du;
  instance->instruction_count++;
  return 1;
 case 0x0600B94Du: /* D0 06 BNE $00:B955 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xB955u : 0xB94Fu;
  instance->instruction_count++;
  return 1;
 case 0x0600B94Fu: /* 85 3E STA $3E */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Eu) & 0xFFFFu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB951u;
  instance->instruction_count++;
  return 1;
 case 0x0600B951u: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB953u;
  instance->instruction_count++;
  return 1;
 case 0x0600B953u: /* 80 04 BRA $00:B959 */
  instance->cpu.pc = 0xB959u;
  instance->instruction_count++;
  return 1;
 case 0x0600B955u: /* 64 3E STZ $3E */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Eu) & 0xFFFFu), 0u)) return 0;
  instance->cpu.pc = 0xB957u;
  instance->instruction_count++;
  return 1;
 case 0x0600B957u: /* E6 3F INC $3F */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x3Fu) & 0xFFFFu), &byte)) return 0;
  byte = (uint8_t)(byte + 1u);
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Fu) & 0xFFFFu), byte)) return 0;
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB959u;
  instance->instruction_count++;
  return 1;
 case 0x0600B959u: /* 8D 41 21 STA $2141 */
  /* Consume P2 events normally, but publish neutral in one-player modes.
     Updating A also updates the native acknowledgement at $3D, avoiding a stall. */
  if((instance->mod_time_trial_active||(!instance->wram[0x1F04u]&&!instance->wram[0x1F05u]))&&
     tg_acc8(instance)>=0x0Du&&tg_acc8(instance)<=0x16u)tg_set_acc8(instance,0u);
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2141u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB95Cu;
  instance->instruction_count++;
  return 1;
 case 0x0600B95Cu: /* 85 3D STA $3D */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x3Du) & 0xFFFFu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB95Eu;
  instance->instruction_count++;
  return 1;
 case 0x0600B95Eu: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB960u;
  instance->instruction_count++;
  return 1;
 case 0x0000B960u: /* EE AE 1E INC $1EAE */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EAEu), &word)) return 0;
  word = (uint16_t)(word + 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1EAEu), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB963u;
  instance->instruction_count++;
  return 1;
 case 0x0000B963u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB965u;
  instance->instruction_count++;
  return 1;
 case 0x0400B965u: /* A5 E1 LDA $E1 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xE1u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB967u;
  instance->instruction_count++;
  return 1;
 case 0x0400B967u: /* F0 24 BEQ $00:B98D */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB98Du : 0xB969u;
  instance->instruction_count++;
  return 1;
 case 0x0400B969u: /* 10 11 BPL $00:B97C */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB97Cu : 0xB96Bu;
  instance->instruction_count++;
  return 1;
 case 0x0400B96Bu: /* A5 52 LDA $52 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x52u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB96Du;
  instance->instruction_count++;
  return 1;
 case 0x0400B96Du: /* 29 0F AND #$0F */
  byte = 0x0Fu;
  byte = (uint8_t)((tg_acc8(instance)) & byte);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB96Fu;
  instance->instruction_count++;
  return 1;
 case 0x0400B96Fu: /* F0 03 BEQ $00:B974 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB974u : 0xB971u;
  instance->instruction_count++;
  return 1;
 case 0x0400B971u: /* 3A DEC A */
  byte = (uint8_t)((tg_acc8(instance)) - 1u);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB972u;
  instance->instruction_count++;
  return 1;
 case 0x0400B972u: /* D0 04 BNE $00:B978 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xB978u : 0xB974u;
  instance->instruction_count++;
  return 1;
 case 0x0400B974u: /* 64 E1 STZ $E1 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0xE1u) & 0xFFFFu), 0u)) return 0;
  instance->cpu.pc = 0xB976u;
  instance->instruction_count++;
  return 1;
 case 0x0400B976u: /* 09 80 ORA #$80 */
  byte = 0x80u;
  byte = (uint8_t)((tg_acc8(instance)) | byte);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB978u;
  instance->instruction_count++;
  return 1;
 case 0x0400B978u: /* 85 52 STA $52 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x52u) & 0xFFFFu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB97Au;
  instance->instruction_count++;
  return 1;
 case 0x0400B97Au: /* 80 11 BRA $00:B98D */
  instance->cpu.pc = 0xB98Du;
  instance->instruction_count++;
  return 1;
 case 0x0400B97Cu: /* A5 52 LDA $52 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x52u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB97Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400B97Eu: /* 29 0F AND #$0F */
  byte = 0x0Fu;
  byte = (uint8_t)((tg_acc8(instance)) & byte);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB980u;
  instance->instruction_count++;
  return 1;
 case 0x0400B980u: /* C9 0F CMP #$0F */
  byte = 0x0Fu;
  tg_compare8(instance, tg_acc8(instance), byte);
  instance->cpu.pc = 0xB982u;
  instance->instruction_count++;
  return 1;
 case 0x0400B982u: /* F0 05 BEQ $00:B989 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB989u : 0xB984u;
  instance->instruction_count++;
  return 1;
 case 0x0400B984u: /* 1A INC A */
  byte = (uint8_t)((tg_acc8(instance)) + 1u);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB985u;
  instance->instruction_count++;
  return 1;
 case 0x0400B985u: /* C9 0F CMP #$0F */
  byte = 0x0Fu;
  tg_compare8(instance, tg_acc8(instance), byte);
  instance->cpu.pc = 0xB987u;
  instance->instruction_count++;
  return 1;
 case 0x0400B987u: /* D0 02 BNE $00:B98B */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xB98Bu : 0xB989u;
  instance->instruction_count++;
  return 1;
 case 0x0400B989u: /* 64 E1 STZ $E1 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0xE1u) & 0xFFFFu), 0u)) return 0;
  instance->cpu.pc = 0xB98Bu;
  instance->instruction_count++;
  return 1;
 case 0x0400B98Bu: /* 85 52 STA $52 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x52u) & 0xFFFFu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB98Du;
  instance->instruction_count++;
  return 1;
 case 0x0400B98Du: /* A5 E2 LDA $E2 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0xE2u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB98Fu;
  instance->instruction_count++;
  return 1;
 case 0x0400B98Fu: /* F0 24 BEQ $00:B9B5 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB9B5u : 0xB991u;
  instance->instruction_count++;
  return 1;
 case 0x0400B991u: /* 10 11 BPL $00:B9A4 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB9A4u : 0xB993u;
  instance->instruction_count++;
  return 1;
 case 0x0400B993u: /* A5 65 LDA $65 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x65u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB995u;
  instance->instruction_count++;
  return 1;
 case 0x0400B995u: /* 29 0F AND #$0F */
  byte = 0x0Fu;
  byte = (uint8_t)((tg_acc8(instance)) & byte);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB997u;
  instance->instruction_count++;
  return 1;
 case 0x0400B997u: /* F0 03 BEQ $00:B99C */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB99Cu : 0xB999u;
  instance->instruction_count++;
  return 1;
 case 0x0400B999u: /* 3A DEC A */
  byte = (uint8_t)((tg_acc8(instance)) - 1u);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB99Au;
  instance->instruction_count++;
  return 1;
 case 0x0400B99Au: /* D0 04 BNE $00:B9A0 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xB9A0u : 0xB99Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400B99Cu: /* 64 E2 STZ $E2 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0xE2u) & 0xFFFFu), 0u)) return 0;
  instance->cpu.pc = 0xB99Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400B99Eu: /* 09 80 ORA #$80 */
  byte = 0x80u;
  byte = (uint8_t)((tg_acc8(instance)) | byte);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB9A0u;
  instance->instruction_count++;
  return 1;
 case 0x0400B9A0u: /* 85 65 STA $65 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x65u) & 0xFFFFu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB9A2u;
  instance->instruction_count++;
  return 1;
 case 0x0400B9A2u: /* 80 11 BRA $00:B9B5 */
  instance->cpu.pc = 0xB9B5u;
  instance->instruction_count++;
  return 1;
 case 0x0400B9A4u: /* A5 65 LDA $65 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x65u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB9A6u;
  instance->instruction_count++;
  return 1;
 case 0x0400B9A6u: /* 29 0F AND #$0F */
  byte = 0x0Fu;
  byte = (uint8_t)((tg_acc8(instance)) & byte);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB9A8u;
  instance->instruction_count++;
  return 1;
 case 0x0400B9A8u: /* C9 0F CMP #$0F */
  byte = 0x0Fu;
  tg_compare8(instance, tg_acc8(instance), byte);
  instance->cpu.pc = 0xB9AAu;
  instance->instruction_count++;
  return 1;
 case 0x0400B9AAu: /* F0 05 BEQ $00:B9B1 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB9B1u : 0xB9ACu;
  instance->instruction_count++;
  return 1;
 case 0x0400B9ACu: /* 1A INC A */
  byte = (uint8_t)((tg_acc8(instance)) + 1u);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB9ADu;
  instance->instruction_count++;
  return 1;
 case 0x0400B9ADu: /* C9 0F CMP #$0F */
  byte = 0x0Fu;
  tg_compare8(instance, tg_acc8(instance), byte);
  instance->cpu.pc = 0xB9AFu;
  instance->instruction_count++;
  return 1;
 case 0x0400B9AFu: /* D0 02 BNE $00:B9B3 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xB9B3u : 0xB9B1u;
  instance->instruction_count++;
  return 1;
 case 0x0400B9B1u: /* 64 E2 STZ $E2 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0xE2u) & 0xFFFFu), 0u)) return 0;
  instance->cpu.pc = 0xB9B3u;
  instance->instruction_count++;
  return 1;
 case 0x0400B9B3u: /* 85 65 STA $65 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x65u) & 0xFFFFu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB9B5u;
  instance->instruction_count++;
  return 1;
 case 0x0400B9B5u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB9B7u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9B7u: /* AD 9A 1E LDA $1E9A */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E9Au), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB9BAu;
  instance->instruction_count++;
  return 1;
 case 0x0000B9BAu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xB9BBu;
  instance->instruction_count++;
  return 1;
 case 0x0000B9BBu: /* 6D 96 1E ADC $1E96 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E96u), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xB9BEu;
  instance->instruction_count++;
  return 1;
 case 0x0000B9BEu: /* 8D 96 1E STA $1E96 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E96u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB9C1u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9C1u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xB9C2u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9C2u: /* C9 00 80 CMP #$8000 */
  word = 0x8000u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xB9C5u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9C5u: /* 2A ROL A */
  word = instance->cpu.a;
  byte = (uint8_t)tg_flag(instance, TG_P_C);
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)((word << 1) | byte);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB9C6u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9C6u: /* 29 FF 01 AND #$01FF */
  word = 0x01FFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB9C9u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9C9u: /* 85 B0 STA $B0 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xB0u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB9CBu;
  instance->instruction_count++;
  return 1;
 case 0x0000B9CBu: /* AD 9C 1E LDA $1E9C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E9Cu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB9CEu;
  instance->instruction_count++;
  return 1;
 case 0x0000B9CEu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xB9CFu;
  instance->instruction_count++;
  return 1;
 case 0x0000B9CFu: /* 6D 98 1E ADC $1E98 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E98u), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xB9D2u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9D2u: /* 8D 98 1E STA $1E98 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E98u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB9D5u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9D5u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xB9D6u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9D6u: /* C9 00 80 CMP #$8000 */
  word = 0x8000u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xB9D9u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9D9u: /* 2A ROL A */
  word = instance->cpu.a;
  byte = (uint8_t)tg_flag(instance, TG_P_C);
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)((word << 1) | byte);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB9DAu;
  instance->instruction_count++;
  return 1;
 case 0x0000B9DAu: /* 29 FF 01 AND #$01FF */
  word = 0x01FFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB9DDu;
  instance->instruction_count++;
  return 1;
 case 0x0000B9DDu: /* 85 C4 STA $C4 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xC4u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB9DFu;
  instance->instruction_count++;
  return 1;
 case 0x0000B9DFu: /* AD 58 1E LDA $1E58 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E58u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB9E2u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9E2u: /* F0 03 BEQ $00:B9E7 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xB9E7u : 0xB9E4u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9E4u: /* 4C 32 BE JMP $BE32 */
  instance->cpu.pc = 0xBE32u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9E7u: /* A9 FF 7F LDA #$7FFF */
  word = 0x7FFFu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB9EAu;
  instance->instruction_count++;
  return 1;
 case 0x0000B9EAu: /* 8D C0 03 STA $03C0 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x03C0u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB9EDu;
  instance->instruction_count++;
  return 1;
 case 0x0000B9EDu: /* AD 6C 1E LDA $1E6C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Cu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB9F0u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9F0u: /* 10 5E BPL $00:BA50 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xBA50u : 0xB9F2u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9F2u: /* 89 00 40 BIT #$4000 */
  word = 0x4000u;
  tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
  instance->cpu.pc = 0xB9F5u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9F5u: /* D0 47 BNE $00:BA3E */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBA3Eu : 0xB9F7u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9F7u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xB9F8u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9F8u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xB9F9u;
  instance->instruction_count++;
  return 1;
 case 0x0000B9F9u: /* 69 00 02 ADC #$0200 */
  word = 0x0200u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xB9FCu;
  instance->instruction_count++;
  return 1;
 case 0x0000B9FCu: /* 8D 6C 1E STA $1E6C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Cu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB9FFu;
  instance->instruction_count++;
  return 1;
 case 0x0000B9FFu: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBA00u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA00u: /* 29 00 3E AND #$3E00 */
  word = 0x3E00u;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA03u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA03u: /* 49 00 3E EOR #$3E00 */
  word = 0x3E00u;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA06u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA06u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA07u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA07u: /* 8D C0 03 STA $03C0 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x03C0u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBA0Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BA0Au: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBA0Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA0Bu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA0Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA0Cu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA0Du;
  instance->instruction_count++;
  return 1;
 case 0x0000BA0Du: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA0Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA0Eu: /* 0D C0 03 ORA $03C0 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x03C0u), &word)) return 0;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA11u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA11u: /* 09 1F 00 ORA #$001F */
  word = 0x001Fu;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA14u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA14u: /* 8D C0 03 STA $03C0 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x03C0u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBA17u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA17u: /* 80 37 BRA $00:BA50 */
  instance->cpu.pc = 0xBA50u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA19u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBA1Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BA1Au: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xBA1Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA1Bu: /* 69 00 01 ADC #$0100 */
  word = 0x0100u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBA1Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA1Eu: /* 30 03 BMI $00:BA23 */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xBA23u : 0xBA20u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA20u: /* F0 01 BEQ $00:BA23 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xBA23u : 0xBA22u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA22u: /* 3A DEC A */
  word = (uint16_t)((instance->cpu.a) - 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA23u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA23u: /* 8D 6C 1E STA $1E6C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Cu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBA26u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA26u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBA27u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA27u: /* 29 00 1F AND #$1F00 */
  word = 0x1F00u;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA2Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BA2Au: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA2Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA2Bu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA2Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA2Cu: /* 8D C0 03 STA $03C0 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x03C0u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBA2Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA2Fu: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBA30u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA30u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA31u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA31u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA32u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA32u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA33u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA33u: /* 0D C0 03 ORA $03C0 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x03C0u), &word)) return 0;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA36u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA36u: /* 09 1F 00 ORA #$001F */
  word = 0x001Fu;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA39u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA39u: /* 8D C0 03 STA $03C0 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x03C0u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBA3Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA3Cu: /* 80 12 BRA $00:BA50 */
  instance->cpu.pc = 0xBA50u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA3Eu: /* 89 00 20 BIT #$2000 */
  word = 0x2000u;
  tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
  instance->cpu.pc = 0xBA41u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA41u: /* D0 D6 BNE $00:BA19 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBA19u : 0xBA43u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA43u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xBA44u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA44u: /* 69 20 00 ADC #$0020 */
  word = 0x0020u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBA47u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA47u: /* 8D 6C 1E STA $1E6C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Cu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBA4Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BA4Au: /* A9 1F 00 LDA #$001F */
  word = 0x001Fu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA4Du;
  instance->instruction_count++;
  return 1;
 case 0x0000BA4Du: /* 8D C0 03 STA $03C0 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x03C0u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBA50u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA50u: /* A9 FF 7F LDA #$7FFF */
  word = 0x7FFFu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA53u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA53u: /* 8D 80 04 STA $0480 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0480u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBA56u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA56u: /* AD 6E 1E LDA $1E6E */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Eu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA59u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA59u: /* 10 5E BPL $00:BAB9 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xBAB9u : 0xBA5Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA5Bu: /* 89 00 40 BIT #$4000 */
  word = 0x4000u;
  tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
  instance->cpu.pc = 0xBA5Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA5Eu: /* D0 47 BNE $00:BAA7 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBAA7u : 0xBA60u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA60u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBA61u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA61u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xBA62u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA62u: /* 69 00 02 ADC #$0200 */
  word = 0x0200u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBA65u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA65u: /* 8D 6E 1E STA $1E6E */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Eu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBA68u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA68u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBA69u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA69u: /* 29 00 3E AND #$3E00 */
  word = 0x3E00u;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA6Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA6Cu: /* 49 00 3E EOR #$3E00 */
  word = 0x3E00u;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA6Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA6Fu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA70u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA70u: /* 8D 80 04 STA $0480 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0480u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBA73u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA73u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBA74u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA74u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA75u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA75u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA76u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA76u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA77u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA77u: /* 0D 80 04 ORA $0480 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0480u), &word)) return 0;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA7Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BA7Au: /* 09 1F 00 ORA #$001F */
  word = 0x001Fu;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA7Du;
  instance->instruction_count++;
  return 1;
 case 0x0000BA7Du: /* 8D 80 04 STA $0480 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0480u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBA80u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA80u: /* 80 37 BRA $00:BAB9 */
  instance->cpu.pc = 0xBAB9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA82u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBA83u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA83u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xBA84u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA84u: /* 69 00 01 ADC #$0100 */
  word = 0x0100u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBA87u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA87u: /* 30 03 BMI $00:BA8C */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xBA8Cu : 0xBA89u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA89u: /* F0 01 BEQ $00:BA8C */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xBA8Cu : 0xBA8Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA8Bu: /* 3A DEC A */
  word = (uint16_t)((instance->cpu.a) - 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA8Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA8Cu: /* 8D 6E 1E STA $1E6E */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Eu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBA8Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA8Fu: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBA90u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA90u: /* 29 00 1F AND #$1F00 */
  word = 0x1F00u;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA93u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA93u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA94u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA94u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA95u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA95u: /* 8D 80 04 STA $0480 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0480u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBA98u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA98u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBA99u;
  instance->instruction_count++;
  return 1;
 case 0x0000BA99u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA9Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BA9Au: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA9Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA9Bu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA9Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA9Cu: /* 0D 80 04 ORA $0480 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0480u), &word)) return 0;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBA9Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BA9Fu: /* 09 1F 00 ORA #$001F */
  word = 0x001Fu;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBAA2u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAA2u: /* 8D 80 04 STA $0480 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0480u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBAA5u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAA5u: /* 80 12 BRA $00:BAB9 */
  instance->cpu.pc = 0xBAB9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAA7u: /* 89 00 20 BIT #$2000 */
  word = 0x2000u;
  tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
  instance->cpu.pc = 0xBAAAu;
  instance->instruction_count++;
  return 1;
 case 0x0000BAAAu: /* D0 D6 BNE $00:BA82 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBA82u : 0xBAACu;
  instance->instruction_count++;
  return 1;
 case 0x0000BAACu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xBAADu;
  instance->instruction_count++;
  return 1;
 case 0x0000BAADu: /* 69 20 00 ADC #$0020 */
  word = 0x0020u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBAB0u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAB0u: /* 8D 6E 1E STA $1E6E */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E6Eu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBAB3u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAB3u: /* A9 1F 00 LDA #$001F */
  word = 0x001Fu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBAB6u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAB6u: /* 8D 80 04 STA $0480 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0480u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBAB9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAB9u: /* AD 00 01 LDA $0100 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0100u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBABCu;
  instance->instruction_count++;
  return 1;
 case 0x0000BABCu: /* 10 0D BPL $00:BACB */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xBACBu : 0xBABEu;
  instance->instruction_count++;
  return 1;
 case 0x0000BABEu: /* AE 02 01 LDX $0102 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0102u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBAC1u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAC1u: /* 30 27 BMI $00:BAEA */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xBAEAu : 0xBAC3u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAC3u: /* F0 09 BEQ $00:BACE */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xBACEu : 0xBAC5u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAC5u: /* CE 02 01 DEC $0102 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0102u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0102u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBAC8u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAC8u: /* 4C B0 BB JMP $BBB0 */
  instance->cpu.pc = 0xBBB0u;
  instance->instruction_count++;
  return 1;
 case 0x0000BACBu: /* 4C C2 BB JMP $BBC2 */
  instance->cpu.pc = 0xBBC2u;
  instance->instruction_count++;
  return 1;
 case 0x0000BACEu: /* 89 00 40 BIT #$4000 */
  word = 0x4000u;
  tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
  instance->cpu.pc = 0xBAD1u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAD1u: /* F0 75 BEQ $00:BB48 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xBB48u : 0xBAD3u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAD3u: /* AE 06 01 LDX $0106 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0106u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBAD6u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAD6u: /* 30 12 BMI $00:BAEA */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xBAEAu : 0xBAD8u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAD8u: /* E0 01 00 CPX #$0001 */
  word = 0x0001u;
  tg_compare16(instance, (uint16_t)instance->cpu.x, word);
  instance->cpu.pc = 0xBADBu;
  instance->instruction_count++;
  return 1;
 case 0x0000BADBu: /* 90 0D BCC $00:BAEA */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xBAEAu : 0xBADDu;
  instance->instruction_count++;
  return 1;
 case 0x0000BADDu: /* F0 0E BEQ $00:BAED */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xBAEDu : 0xBADFu;
  instance->instruction_count++;
  return 1;
 case 0x0000BADFu: /* AD 06 1F LDA $1F06 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBAE2u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAE2u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBAE3u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAE3u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBAE4u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAE4u: /* BD 24 E0 LDA $E024,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE024u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBAE7u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAE7u: /* 8D 06 01 STA $0106 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0106u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBAEAu;
  instance->instruction_count++;
  return 1;
 case 0x0000BAEAu: /* 4C B0 BB JMP $BBB0 */
  instance->cpu.pc = 0xBBB0u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAEDu: /* 3A DEC A */
  word = (uint16_t)((instance->cpu.a) - 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBAEEu;
  instance->instruction_count++;
  return 1;
 case 0x0000BAEEu: /* C9 DE C0 CMP #$C0DE */
  word = 0xC0DEu;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBAF1u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAF1u: /* D0 42 BNE $00:BB35 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBB35u : 0xBAF3u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAF3u: /* 8D 00 01 STA $0100 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0100u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBAF6u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAF6u: /* A9 B6 B6 LDA #$B6B6 */
  word = 0xB6B6u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBAF9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BAF9u: /* 85 66 STA $66 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBAFBu;
  instance->instruction_count++;
  return 1;
 case 0x0000BAFBu: /* AD 06 1F LDA $1F06 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBAFEu;
  instance->instruction_count++;
  return 1;
 case 0x0000BAFEu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBAFFu;
  instance->instruction_count++;
  return 1;
 case 0x0000BAFFu: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBB00u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB00u: /* A9 5A 8A LDA #$8A5A */
  word = 0x8A5Au;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB03u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB03u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xBB04u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB04u: /* 7D E4 DF ADC $DFE4,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xDFE4u + instance->cpu.x)), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBB07u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB07u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBB08u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB08u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBB0Au;
  instance->instruction_count++;
  return 1;
 case 0x0400BB0Au: /* A9 10 LDA #$10 */
  byte = 0x10u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBB0Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400BB0Cu: /* 8D 21 21 STA $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBB0Fu;
  instance->instruction_count++;
  return 1;
 case 0x0400BB0Fu: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBB11u;
  instance->instruction_count++;
  return 1;
 case 0x0400BB11u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBB14u;
  instance->instruction_count++;
  return 1;
 case 0x0400BB14u: /* A9 08 LDA #$08 */
  byte = 0x08u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBB16u;
  instance->instruction_count++;
  return 1;
 case 0x0400BB16u: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBB19u;
  instance->instruction_count++;
  return 1;
 case 0x0400BB19u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBB1Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BB1Bu: /* A9 02 22 LDA #$2202 */
  word = 0x2202u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB1Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000BB1Eu: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBB21u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB21u: /* 8E 72 43 STX $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xBB24u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB24u: /* A9 20 00 LDA #$0020 */
  word = 0x0020u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB27u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB27u: /* 8D 75 43 STA $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBB2Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BB2Au: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBB2Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400BB2Cu: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBB2Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400BB2Eu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBB31u;
  instance->instruction_count++;
  return 1;
 case 0x0400BB31u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBB33u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB33u: /* 80 7B BRA $00:BBB0 */
  instance->cpu.pc = 0xBBB0u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB35u: /* C9 00 C0 CMP #$C000 */
  word = 0xC000u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBB38u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB38u: /* D0 09 BNE $00:BB43 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBB43u : 0xBB3Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BB3Au: /* EE 06 01 INC $0106 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0106u), &word)) return 0;
  word = (uint16_t)(word + 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0106u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB3Du;
  instance->instruction_count++;
  return 1;
 case 0x0000BB3Du: /* CE 02 01 DEC $0102 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0102u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0102u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB40u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB40u: /* A9 00 80 LDA #$8000 */
  word = 0x8000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB43u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB43u: /* 8D 00 01 STA $0100 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0100u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBB46u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB46u: /* 80 68 BRA $00:BBB0 */
  instance->cpu.pc = 0xBBB0u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB48u: /* C9 DF 80 CMP #$80DF */
  word = 0x80DFu;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBB4Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BB4Bu: /* D0 5F BNE $00:BBAC */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBBACu : 0xBB4Du;
  instance->instruction_count++;
  return 1;
 case 0x0000BB4Du: /* AE 06 01 LDX $0106 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0106u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB50u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB50u: /* 30 5E BMI $00:BBB0 */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xBBB0u : 0xBB52u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB52u: /* E0 01 00 CPX #$0001 */
  word = 0x0001u;
  tg_compare16(instance, (uint16_t)instance->cpu.x, word);
  instance->cpu.pc = 0xBB55u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB55u: /* 90 59 BCC $00:BBB0 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xBBB0u : 0xBB57u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB57u: /* F0 0D BEQ $00:BB66 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xBB66u : 0xBB59u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB59u: /* AD 06 1F LDA $1F06 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB5Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BB5Cu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB5Du;
  instance->instruction_count++;
  return 1;
 case 0x0000BB5Du: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBB5Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000BB5Eu: /* BD 64 E0 LDA $E064,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE064u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB61u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB61u: /* 8D 06 01 STA $0106 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0106u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBB64u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB64u: /* 80 4A BRA $00:BBB0 */
  instance->cpu.pc = 0xBBB0u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB66u: /* A9 94 B4 LDA #$B494 */
  word = 0xB494u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB69u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB69u: /* 85 66 STA $66 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x66u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBB6Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BB6Bu: /* AD 06 1F LDA $1F06 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1F06u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB6Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000BB6Eu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB6Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BB6Fu: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBB70u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB70u: /* A9 5A 8E LDA #$8E5A */
  word = 0x8E5Au;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB73u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB73u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xBB74u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB74u: /* 7D E4 DF ADC $DFE4,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xDFE4u + instance->cpu.x)), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBB77u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB77u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBB78u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB78u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBB7Au;
  instance->instruction_count++;
  return 1;
 case 0x0400BB7Au: /* A9 10 LDA #$10 */
  byte = 0x10u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBB7Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400BB7Cu: /* 8D 21 21 STA $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBB7Fu;
  instance->instruction_count++;
  return 1;
 case 0x0400BB7Fu: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBB81u;
  instance->instruction_count++;
  return 1;
 case 0x0400BB81u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBB84u;
  instance->instruction_count++;
  return 1;
 case 0x0400BB84u: /* A9 08 LDA #$08 */
  byte = 0x08u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBB86u;
  instance->instruction_count++;
  return 1;
 case 0x0400BB86u: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBB89u;
  instance->instruction_count++;
  return 1;
 case 0x0400BB89u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBB8Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BB8Bu: /* A9 02 22 LDA #$2202 */
  word = 0x2202u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB8Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000BB8Eu: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBB91u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB91u: /* 8E 72 43 STX $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xBB94u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB94u: /* A9 20 00 LDA #$0020 */
  word = 0x0020u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBB97u;
  instance->instruction_count++;
  return 1;
 case 0x0000BB97u: /* 8D 75 43 STA $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBB9Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BB9Au: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBB9Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400BB9Cu: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBB9Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400BB9Eu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBBA1u;
  instance->instruction_count++;
  return 1;
 case 0x0400BBA1u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBBA3u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBA3u: /* EE 06 01 INC $0106 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0106u), &word)) return 0;
  word = (uint16_t)(word + 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0106u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBBA6u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBA6u: /* CE 02 01 DEC $0102 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0102u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0102u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBBA9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBA9u: /* A9 DE C0 LDA #$C0DE */
  word = 0xC0DEu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBBACu;
  instance->instruction_count++;
  return 1;
 case 0x0000BBACu: /* 1A INC A */
  word = (uint16_t)((instance->cpu.a) + 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBBADu;
  instance->instruction_count++;
  return 1;
 case 0x0000BBADu: /* 8D 00 01 STA $0100 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0100u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBBB0u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBB0u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBBB2u;
  instance->instruction_count++;
  return 1;
 case 0x0400BBB2u: /* AD 00 01 LDA $0100 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0100u), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBBB5u;
  instance->instruction_count++;
  return 1;
 case 0x0400BBB5u: /* 4A LSR A */
  byte = tg_acc8(instance);
  tg_set_flag(instance, TG_P_C, (byte & 1u) != 0u);
  byte = (uint8_t)(byte >> 1);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBBB6u;
  instance->instruction_count++;
  return 1;
 case 0x0400BBB6u: /* 4A LSR A */
  byte = tg_acc8(instance);
  tg_set_flag(instance, TG_P_C, (byte & 1u) != 0u);
  byte = (uint8_t)(byte >> 1);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBBB7u;
  instance->instruction_count++;
  return 1;
 case 0x0400BBB7u: /* 4A LSR A */
  byte = tg_acc8(instance);
  tg_set_flag(instance, TG_P_C, (byte & 1u) != 0u);
  byte = (uint8_t)(byte >> 1);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBBB8u;
  instance->instruction_count++;
  return 1;
 case 0x0400BBB8u: /* 4A LSR A */
  byte = tg_acc8(instance);
  tg_set_flag(instance, TG_P_C, (byte & 1u) != 0u);
  byte = (uint8_t)(byte >> 1);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBBB9u;
  instance->instruction_count++;
  return 1;
 case 0x0400BBB9u: /* 29 1F AND #$1F */
  byte = 0x1Fu;
  byte = (uint8_t)((tg_acc8(instance)) & byte);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBBBBu;
  instance->instruction_count++;
  return 1;
 case 0x0400BBBBu: /* 09 E0 ORA #$E0 */
  byte = 0xE0u;
  byte = (uint8_t)((tg_acc8(instance)) | byte);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBBBDu;
  instance->instruction_count++;
  return 1;
 case 0x0400BBBDu: /* 8D 32 21 STA $2132 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2132u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBBC0u;
  instance->instruction_count++;
  return 1;
 case 0x0400BBC0u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBBC2u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBC2u: /* AD 5A 1E LDA $1E5A */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Au), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBBC5u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBC5u: /* D0 0E BNE $00:BBD5 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBBD5u : 0xBBC7u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBC7u: /* 9C 0A 01 STZ $010A */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x010Au), 0u)) return 0;
  instance->cpu.pc = 0xBBCAu;
  instance->instruction_count++;
  return 1;
 case 0x0000BBCAu: /* AD 10 01 LDA $0110 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0110u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBBCDu;
  instance->instruction_count++;
  return 1;
 case 0x0000BBCDu: /* 29 FF 7F AND #$7FFF */
  word = 0x7FFFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBBD0u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBD0u: /* 8D 10 01 STA $0110 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0110u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBBD3u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBD3u: /* 80 1D BRA $00:BBF2 */
  instance->cpu.pc = 0xBBF2u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBD5u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xBBD6u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBD6u: /* 6D 0A 01 ADC $010A */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x010Au), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBBD9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBD9u: /* C9 00 20 CMP #$2000 */
  word = 0x2000u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBBDCu;
  instance->instruction_count++;
  return 1;
 case 0x0000BBDCu: /* B0 05 BCS $00:BBE3 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xBBE3u : 0xBBDEu;
  instance->instruction_count++;
  return 1;
 case 0x0000BBDEu: /* 8D 0A 01 STA $010A */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x010Au), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBBE1u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBE1u: /* 80 0F BRA $00:BBF2 */
  instance->cpu.pc = 0xBBF2u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBE3u: /* 29 FF 1F AND #$1FFF */
  word = 0x1FFFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBBE6u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBE6u: /* 8D 0A 01 STA $010A */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x010Au), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBBE9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBE9u: /* AD 10 01 LDA $0110 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0110u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBBECu;
  instance->instruction_count++;
  return 1;
 case 0x0000BBECu: /* 49 00 80 EOR #$8000 */
  word = 0x8000u;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBBEFu;
  instance->instruction_count++;
  return 1;
 case 0x0000BBEFu: /* 8D 10 01 STA $0110 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0110u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBBF2u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBF2u: /* AD 5C 1E LDA $1E5C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Cu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBBF5u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBF5u: /* D0 0E BNE $00:BC05 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBC05u : 0xBBF7u;
  instance->instruction_count++;
  return 1;
 case 0x0000BBF7u: /* 9C 0C 01 STZ $010C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x010Cu), 0u)) return 0;
  instance->cpu.pc = 0xBBFAu;
  instance->instruction_count++;
  return 1;
 case 0x0000BBFAu: /* AD 10 01 LDA $0110 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0110u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBBFDu;
  instance->instruction_count++;
  return 1;
 case 0x0000BBFDu: /* 29 FF BF AND #$BFFF */
  word = 0xBFFFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC00u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC00u: /* 8D 10 01 STA $0110 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0110u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBC03u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC03u: /* 80 1D BRA $00:BC22 */
  instance->cpu.pc = 0xBC22u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC05u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xBC06u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC06u: /* 6D 0C 01 ADC $010C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x010Cu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBC09u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC09u: /* C9 00 20 CMP #$2000 */
  word = 0x2000u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBC0Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BC0Cu: /* B0 05 BCS $00:BC13 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xBC13u : 0xBC0Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000BC0Eu: /* 8D 0C 01 STA $010C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x010Cu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBC11u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC11u: /* 80 0F BRA $00:BC22 */
  instance->cpu.pc = 0xBC22u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC13u: /* 29 FF 1F AND #$1FFF */
  word = 0x1FFFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC16u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC16u: /* 8D 0C 01 STA $010C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x010Cu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBC19u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC19u: /* AD 10 01 LDA $0110 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0110u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC1Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BC1Cu: /* 49 00 40 EOR #$4000 */
  word = 0x4000u;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC1Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BC1Fu: /* 8D 10 01 STA $0110 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0110u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBC22u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC22u: /* CE 0E 01 DEC $010E */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x010Eu), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x010Eu), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC25u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC25u: /* 10 0F BPL $00:BC36 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xBC36u : 0xBC27u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC27u: /* A9 01 00 LDA #$0001 */
  word = 0x0001u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC2Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BC2Au: /* 8D 0E 01 STA $010E */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x010Eu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBC2Du;
  instance->instruction_count++;
  return 1;
 case 0x0000BC2Du: /* AD 10 01 LDA $0110 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0110u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC30u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC30u: /* 49 00 20 EOR #$2000 */
  word = 0x2000u;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC33u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC33u: /* 8D 10 01 STA $0110 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0110u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBC36u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC36u: /* A2 6F 0C LDX #$0C6F */
  word = 0x0C6Fu;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC39u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC39u: /* AD 08 01 LDA $0108 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0108u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC3Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BC3Cu: /* 10 03 BPL $00:BC41 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xBC41u : 0xBC3Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000BC3Eu: /* A2 BF 14 LDX #$14BF */
  word = 0x14BFu;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC41u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC41u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBC42u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC42u: /* E2 30 SEP #$30 */
  instance->cpu.p |=0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBC44u;
  instance->instruction_count++;
  return 1;
 case 0x0600BC44u: /* A2 8E LDX #$8E */
  byte = 0x8Eu;
  tg_set_index8(instance, &instance->cpu.x, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBC46u;
  instance->instruction_count++;
  return 1;
 case 0x0600BC46u: /* 8E 21 21 STX $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), (uint8_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xBC49u;
  instance->instruction_count++;
  return 1;
 case 0x0600BC49u: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBC4Cu;
  instance->instruction_count++;
  return 1;
 case 0x0600BC4Cu: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBC4Du;
  instance->instruction_count++;
  return 1;
 case 0x0600BC4Du: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBC50u;
  instance->instruction_count++;
  return 1;
 case 0x0600BC50u: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBC52u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC52u: /* A2 6F 0C LDX #$0C6F */
  word = 0x0C6Fu;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC55u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC55u: /* AD 08 01 LDA $0108 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0108u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC58u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC58u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC59u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC59u: /* 10 03 BPL $00:BC5E */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xBC5Eu : 0xBC5Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BC5Bu: /* A2 BF 14 LDX #$14BF */
  word = 0x14BFu;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC5Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000BC5Eu: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBC5Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BC5Fu: /* E2 30 SEP #$30 */
  instance->cpu.p |=0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBC61u;
  instance->instruction_count++;
  return 1;
 case 0x0600BC61u: /* A2 9E LDX #$9E */
  byte = 0x9Eu;
  tg_set_index8(instance, &instance->cpu.x, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBC63u;
  instance->instruction_count++;
  return 1;
 case 0x0600BC63u: /* 8E 21 21 STX $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), (uint8_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xBC66u;
  instance->instruction_count++;
  return 1;
 case 0x0600BC66u: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBC69u;
  instance->instruction_count++;
  return 1;
 case 0x0600BC69u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBC6Au;
  instance->instruction_count++;
  return 1;
 case 0x0600BC6Au: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBC6Du;
  instance->instruction_count++;
  return 1;
 case 0x0600BC6Du: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBC6Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BC6Fu: /* A2 4A 39 LDX #$394A */
  word = 0x394Au;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC72u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC72u: /* AD 10 01 LDA $0110 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0110u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC75u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC75u: /* 10 03 BPL $00:BC7A */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xBC7Au : 0xBC77u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC77u: /* A2 21 04 LDX #$0421 */
  word = 0x0421u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC7Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BC7Au: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBC7Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BC7Bu: /* E2 30 SEP #$30 */
  instance->cpu.p |=0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBC7Du;
  instance->instruction_count++;
  return 1;
 case 0x0600BC7Du: /* A2 87 LDX #$87 */
  byte = 0x87u;
  tg_set_index8(instance, &instance->cpu.x, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBC7Fu;
  instance->instruction_count++;
  return 1;
 case 0x0600BC7Fu: /* 8E 21 21 STX $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), (uint8_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xBC82u;
  instance->instruction_count++;
  return 1;
 case 0x0600BC82u: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBC85u;
  instance->instruction_count++;
  return 1;
 case 0x0600BC85u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBC86u;
  instance->instruction_count++;
  return 1;
 case 0x0600BC86u: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBC89u;
  instance->instruction_count++;
  return 1;
 case 0x0600BC89u: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBC8Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BC8Bu: /* A2 4A 39 LDX #$394A */
  word = 0x394Au;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC8Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000BC8Eu: /* A9 00 40 LDA #$4000 */
  word = 0x4000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC91u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC91u: /* 2C 10 01 BIT $0110 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0110u), &word)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
  tg_set_flag(instance, TG_P_N, (word & 0x8000u) != 0u);
  tg_set_flag(instance, TG_P_V, (word & 0x4000u) != 0u);
  instance->cpu.pc = 0xBC94u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC94u: /* F0 03 BEQ $00:BC99 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xBC99u : 0xBC96u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC96u: /* A2 21 04 LDX #$0421 */
  word = 0x0421u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBC99u;
  instance->instruction_count++;
  return 1;
 case 0x0000BC99u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBC9Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BC9Au: /* E2 30 SEP #$30 */
  instance->cpu.p |=0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBC9Cu;
  instance->instruction_count++;
  return 1;
 case 0x0600BC9Cu: /* A2 97 LDX #$97 */
  byte = 0x97u;
  tg_set_index8(instance, &instance->cpu.x, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBC9Eu;
  instance->instruction_count++;
  return 1;
 case 0x0600BC9Eu: /* 8E 21 21 STX $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), (uint8_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xBCA1u;
  instance->instruction_count++;
  return 1;
 case 0x0600BCA1u: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBCA4u;
  instance->instruction_count++;
  return 1;
 case 0x0600BCA4u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBCA5u;
  instance->instruction_count++;
  return 1;
 case 0x0600BCA5u: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBCA8u;
  instance->instruction_count++;
  return 1;
 case 0x0600BCA8u: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBCAAu;
  instance->instruction_count++;
  return 1;
 case 0x0000BCAAu: /* A2 4A 39 LDX #$394A */
  word = 0x394Au;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBCADu;
  instance->instruction_count++;
  return 1;
 case 0x0000BCADu: /* A9 00 20 LDA #$2000 */
  word = 0x2000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBCB0u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCB0u: /* 2C 10 01 BIT $0110 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0110u), &word)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
  tg_set_flag(instance, TG_P_N, (word & 0x8000u) != 0u);
  tg_set_flag(instance, TG_P_V, (word & 0x4000u) != 0u);
  instance->cpu.pc = 0xBCB3u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCB3u: /* F0 03 BEQ $00:BCB8 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xBCB8u : 0xBCB5u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCB5u: /* A2 21 04 LDX #$0421 */
  word = 0x0421u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBCB8u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCB8u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xBCB9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCB9u: /* E2 30 SEP #$30 */
  instance->cpu.p |=0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBCBBu;
  instance->instruction_count++;
  return 1;
 case 0x0600BCBBu: /* A2 A7 LDX #$A7 */
  byte = 0xA7u;
  tg_set_index8(instance, &instance->cpu.x, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBCBDu;
  instance->instruction_count++;
  return 1;
 case 0x0600BCBDu: /* 8E 21 21 STX $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), (uint8_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xBCC0u;
  instance->instruction_count++;
  return 1;
 case 0x0600BCC0u: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBCC3u;
  instance->instruction_count++;
  return 1;
 case 0x0600BCC3u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBCC4u;
  instance->instruction_count++;
  return 1;
 case 0x0600BCC4u: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBCC7u;
  instance->instruction_count++;
  return 1;
 case 0x0600BCC7u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBCC8u;
  instance->instruction_count++;
  return 1;
 case 0x0600BCC8u: /* A2 B7 LDX #$B7 */
  byte = 0xB7u;
  tg_set_index8(instance, &instance->cpu.x, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBCCAu;
  instance->instruction_count++;
  return 1;
 case 0x0600BCCAu: /* 8E 21 21 STX $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), (uint8_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xBCCDu;
  instance->instruction_count++;
  return 1;
 case 0x0600BCCDu: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBCD0u;
  instance->instruction_count++;
  return 1;
 case 0x0600BCD0u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBCD1u;
  instance->instruction_count++;
  return 1;
 case 0x0600BCD1u: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBCD4u;
  instance->instruction_count++;
  return 1;
 case 0x0600BCD4u: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBCD6u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCD6u: /* AD 86 1E LDA $1E86 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E86u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBCD9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCD9u: /* C9 F8 FF CMP #$FFF8 */
  word = 0xFFF8u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBCDCu;
  instance->instruction_count++;
  return 1;
 case 0x0000BCDCu: /* 90 05 BCC $00:BCE3 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xBCE3u : 0xBCDEu;
  instance->instruction_count++;
  return 1;
 case 0x0000BCDEu: /* C9 FD FF CMP #$FFFD */
  word = 0xFFFDu;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBCE1u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCE1u: /* 90 03 BCC $00:BCE6 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xBCE6u : 0xBCE3u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCE3u: /* 4C 84 BD JMP $BD84 */
  instance->cpu.pc = 0xBD84u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCE6u: /* AD 86 1E LDA $1E86 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E86u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBCE9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCE9u: /* C9 FB FF CMP #$FFFB */
  word = 0xFFFBu;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBCECu;
  instance->instruction_count++;
  return 1;
 case 0x0000BCECu: /* F0 05 BEQ $00:BCF3 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xBCF3u : 0xBCEEu;
  instance->instruction_count++;
  return 1;
 case 0x0000BCEEu: /* C9 FC FF CMP #$FFFC */
  word = 0xFFFCu;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBCF1u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCF1u: /* D0 35 BNE $00:BD28 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBD28u : 0xBCF3u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCF3u: /* A5 A8 LDA $A8 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xA8u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBCF5u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCF5u: /* 29 FF 03 AND #$03FF */
  word = 0x03FFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBCF8u;
  instance->instruction_count++;
  return 1;
 case 0x0000BCF8u: /* C9 88 01 CMP #$0188 */
  word = 0x0188u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBCFBu;
  instance->instruction_count++;
  return 1;
 case 0x0000BCFBu: /* 90 0B BCC $00:BD08 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xBD08u : 0xBCFDu;
  instance->instruction_count++;
  return 1;
 case 0x0000BCFDu: /* AD 5A 1E LDA $1E5A */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Au), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD00u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD00u: /* 69 28 00 ADC #$0028 */
  word = 0x0028u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBD03u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD03u: /* 8D 5A 1E STA $1E5A */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Au), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBD06u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD06u: /* 80 47 BRA $00:BD4F */
  instance->cpu.pc = 0xBD4Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD08u: /* C9 80 00 CMP #$0080 */
  word = 0x0080u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBD0Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD0Bu: /* 90 13 BCC $00:BD20 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xBD20u : 0xBD0Du;
  instance->instruction_count++;
  return 1;
 case 0x0000BD0Du: /* E9 00 02 SBC #$0200 */
  word = 0x0200u;
  tg_sbc16(instance, word);
  instance->cpu.pc = 0xBD10u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD10u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD11u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD11u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD12u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD12u: /* 09 00 C0 ORA #$C000 */
  word = 0xC000u;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD15u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD15u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xBD16u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD16u: /* 6D 5A 1E ADC $1E5A */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Au), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBD19u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD19u: /* 30 05 BMI $00:BD20 */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xBD20u : 0xBD1Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD1Bu: /* 8D 5A 1E STA $1E5A */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Au), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBD1Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD1Eu: /* 80 2F BRA $00:BD4F */
  instance->cpu.pc = 0xBD4Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD20u: /* 9C 5A 1E STZ $1E5A */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Au), 0u)) return 0;
  instance->cpu.pc = 0xBD23u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD23u: /* CE 86 1E DEC $1E86 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E86u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E86u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD26u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD26u: /* 80 27 BRA $00:BD4F */
  instance->cpu.pc = 0xBD4Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD28u: /* C9 F9 FF CMP #$FFF9 */
  word = 0xFFF9u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBD2Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD2Bu: /* D0 22 BNE $00:BD4F */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBD4Fu : 0xBD2Du;
  instance->instruction_count++;
  return 1;
 case 0x0000BD2Du: /* A9 00 1B LDA #$1B00 */
  word = 0x1B00u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD30u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD30u: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xBD31u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD31u: /* ED 5A 1E SBC $1E5A */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Au), &word)) return 0;
  tg_sbc16(instance, word);
  instance->cpu.pc = 0xBD34u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD34u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBD35u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD35u: /* C9 00 80 CMP #$8000 */
  word = 0x8000u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBD38u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD38u: /* 2A ROL A */
  word = instance->cpu.a;
  byte = (uint8_t)tg_flag(instance, TG_P_C);
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)((word << 1) | byte);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD39u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD39u: /* C9 00 80 CMP #$8000 */
  word = 0x8000u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBD3Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD3Cu: /* 2A ROL A */
  word = instance->cpu.a;
  byte = (uint8_t)tg_flag(instance, TG_P_C);
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)((word << 1) | byte);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD3Du;
  instance->instruction_count++;
  return 1;
 case 0x0000BD3Du: /* 29 FF 03 AND #$03FF */
  word = 0x03FFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD40u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD40u: /* C9 00 02 CMP #$0200 */
  word = 0x0200u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBD43u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD43u: /* 90 04 BCC $00:BD49 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xBD49u : 0xBD45u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD45u: /* 09 00 FC ORA #$FC00 */
  word = 0xFC00u;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD48u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD48u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xBD49u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD49u: /* 6D 5A 1E ADC $1E5A */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Au), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBD4Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD4Cu: /* 8D 5A 1E STA $1E5A */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Au), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBD4Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD4Fu: /* AD 5A 1E LDA $1E5A */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Au), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD52u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD52u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBD53u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD53u: /* 29 FF 00 AND #$00FF */
  word = 0x00FFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD56u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD56u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD57u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD57u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD58u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD58u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD59u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD59u: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD5Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD5Cu: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xBD5Du;
  instance->instruction_count++;
  return 1;
 case 0x0000BD5Du: /* 65 A8 ADC $A8 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xA8u) & 0xFFFFu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBD5Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD5Fu: /* 85 A8 STA $A8 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xA8u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBD61u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD61u: /* 20 66 89 JSR $8966 */
  if (!tg_push16(instance, 0xBD63u)) return 0;
  instance->cpu.pc = 0x8966u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD64u: /* A9 63 0C LDA #$0C63 */
  word = 0x0C63u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD67u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD67u: /* E2 30 SEP #$30 */
  instance->cpu.p |=0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBD69u;
  instance->instruction_count++;
  return 1;
 case 0x0600BD69u: /* A2 87 LDX #$87 */
  byte = 0x87u;
  tg_set_index8(instance, &instance->cpu.x, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBD6Bu;
  instance->instruction_count++;
  return 1;
 case 0x0600BD6Bu: /* 8E 21 21 STX $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), (uint8_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xBD6Eu;
  instance->instruction_count++;
  return 1;
 case 0x0600BD6Eu: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBD71u;
  instance->instruction_count++;
  return 1;
 case 0x0600BD71u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBD72u;
  instance->instruction_count++;
  return 1;
 case 0x0600BD72u: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBD75u;
  instance->instruction_count++;
  return 1;
 case 0x0600BD75u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBD76u;
  instance->instruction_count++;
  return 1;
 case 0x0600BD76u: /* A2 8E LDX #$8E */
  byte = 0x8Eu;
  tg_set_index8(instance, &instance->cpu.x, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBD78u;
  instance->instruction_count++;
  return 1;
 case 0x0600BD78u: /* 8E 21 21 STX $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), (uint8_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xBD7Bu;
  instance->instruction_count++;
  return 1;
 case 0x0600BD7Bu: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBD7Eu;
  instance->instruction_count++;
  return 1;
 case 0x0600BD7Eu: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBD7Fu;
  instance->instruction_count++;
  return 1;
 case 0x0600BD7Fu: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBD82u;
  instance->instruction_count++;
  return 1;
 case 0x0600BD82u: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBD84u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD84u: /* AD 88 1E LDA $1E88 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E88u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD87u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD87u: /* C9 F8 FF CMP #$FFF8 */
  word = 0xFFF8u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBD8Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BD8Au: /* 90 05 BCC $00:BD91 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xBD91u : 0xBD8Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD8Cu: /* C9 FD FF CMP #$FFFD */
  word = 0xFFFDu;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBD8Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD8Fu: /* 90 03 BCC $00:BD94 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xBD94u : 0xBD91u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD91u: /* 4C 32 BE JMP $BE32 */
  instance->cpu.pc = 0xBE32u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD94u: /* AD 88 1E LDA $1E88 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E88u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBD97u;
  instance->instruction_count++;
  return 1;
 case 0x0000BD97u: /* C9 FB FF CMP #$FFFB */
  word = 0xFFFBu;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBD9Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BD9Au: /* F0 05 BEQ $00:BDA1 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xBDA1u : 0xBD9Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD9Cu: /* C9 FC FF CMP #$FFFC */
  word = 0xFFFCu;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBD9Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BD9Fu: /* D0 35 BNE $00:BDD6 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBDD6u : 0xBDA1u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDA1u: /* A5 BC LDA $BC */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xBCu) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBDA3u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDA3u: /* 29 FF 03 AND #$03FF */
  word = 0x03FFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBDA6u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDA6u: /* C9 88 01 CMP #$0188 */
  word = 0x0188u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBDA9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDA9u: /* 90 0B BCC $00:BDB6 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xBDB6u : 0xBDABu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDABu: /* AD 5C 1E LDA $1E5C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Cu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBDAEu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDAEu: /* 69 28 00 ADC #$0028 */
  word = 0x0028u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBDB1u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDB1u: /* 8D 5C 1E STA $1E5C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Cu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBDB4u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDB4u: /* 80 47 BRA $00:BDFD */
  instance->cpu.pc = 0xBDFDu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDB6u: /* C9 80 00 CMP #$0080 */
  word = 0x0080u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBDB9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDB9u: /* 90 13 BCC $00:BDCE */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xBDCEu : 0xBDBBu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDBBu: /* E9 00 02 SBC #$0200 */
  word = 0x0200u;
  tg_sbc16(instance, word);
  instance->cpu.pc = 0xBDBEu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDBEu: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBDBFu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDBFu: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBDC0u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDC0u: /* 09 00 C0 ORA #$C000 */
  word = 0xC000u;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBDC3u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDC3u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xBDC4u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDC4u: /* 6D 5C 1E ADC $1E5C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Cu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBDC7u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDC7u: /* 30 05 BMI $00:BDCE */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xBDCEu : 0xBDC9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDC9u: /* 8D 5C 1E STA $1E5C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Cu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBDCCu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDCCu: /* 80 2F BRA $00:BDFD */
  instance->cpu.pc = 0xBDFDu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDCEu: /* 9C 5C 1E STZ $1E5C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Cu), 0u)) return 0;
  instance->cpu.pc = 0xBDD1u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDD1u: /* CE 88 1E DEC $1E88 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E88u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E88u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBDD4u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDD4u: /* 80 27 BRA $00:BDFD */
  instance->cpu.pc = 0xBDFDu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDD6u: /* C9 F9 FF CMP #$FFF9 */
  word = 0xFFF9u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBDD9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDD9u: /* D0 22 BNE $00:BDFD */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBDFDu : 0xBDDBu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDDBu: /* A9 00 1B LDA #$1B00 */
  word = 0x1B00u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBDDEu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDDEu: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xBDDFu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDDFu: /* ED 5C 1E SBC $1E5C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Cu), &word)) return 0;
  tg_sbc16(instance, word);
  instance->cpu.pc = 0xBDE2u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDE2u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBDE3u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDE3u: /* C9 00 80 CMP #$8000 */
  word = 0x8000u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBDE6u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDE6u: /* 2A ROL A */
  word = instance->cpu.a;
  byte = (uint8_t)tg_flag(instance, TG_P_C);
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)((word << 1) | byte);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBDE7u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDE7u: /* C9 00 80 CMP #$8000 */
  word = 0x8000u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBDEAu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDEAu: /* 2A ROL A */
  word = instance->cpu.a;
  byte = (uint8_t)tg_flag(instance, TG_P_C);
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)((word << 1) | byte);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBDEBu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDEBu: /* 29 FF 03 AND #$03FF */
  word = 0x03FFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBDEEu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDEEu: /* C9 00 02 CMP #$0200 */
  word = 0x0200u;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xBDF1u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDF1u: /* 90 04 BCC $00:BDF7 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xBDF7u : 0xBDF3u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDF3u: /* 09 00 FC ORA #$FC00 */
  word = 0xFC00u;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBDF6u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDF6u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xBDF7u;
  instance->instruction_count++;
  return 1;
 case 0x0000BDF7u: /* 6D 5C 1E ADC $1E5C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Cu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBDFAu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDFAu: /* 8D 5C 1E STA $1E5C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Cu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBDFDu;
  instance->instruction_count++;
  return 1;
 case 0x0000BDFDu: /* AD 5C 1E LDA $1E5C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1E5Cu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBE00u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE00u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBE01u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE01u: /* 29 FF 00 AND #$00FF */
  word = 0x00FFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBE04u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE04u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBE05u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE05u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBE06u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE06u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBE07u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE07u: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBE0Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BE0Au: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xBE0Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000BE0Bu: /* 65 BC ADC $BC */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xBCu) & 0xFFFFu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xBE0Du;
  instance->instruction_count++;
  return 1;
 case 0x0000BE0Du: /* 85 BC STA $BC */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0xBCu) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBE0Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BE0Fu: /* 20 2C 8A JSR $8A2C */
  if (!tg_push16(instance, 0xBE11u)) return 0;
  instance->cpu.pc = 0x8A2Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BE12u: /* A9 63 0C LDA #$0C63 */
  word = 0x0C63u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBE15u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE15u: /* E2 30 SEP #$30 */
  instance->cpu.p |=0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBE17u;
  instance->instruction_count++;
  return 1;
 case 0x0600BE17u: /* A2 97 LDX #$97 */
  byte = 0x97u;
  tg_set_index8(instance, &instance->cpu.x, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBE19u;
  instance->instruction_count++;
  return 1;
 case 0x0600BE19u: /* 8E 21 21 STX $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), (uint8_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xBE1Cu;
  instance->instruction_count++;
  return 1;
 case 0x0600BE1Cu: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBE1Fu;
  instance->instruction_count++;
  return 1;
 case 0x0600BE1Fu: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBE20u;
  instance->instruction_count++;
  return 1;
 case 0x0600BE20u: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBE23u;
  instance->instruction_count++;
  return 1;
 case 0x0600BE23u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBE24u;
  instance->instruction_count++;
  return 1;
 case 0x0600BE24u: /* A2 9E LDX #$9E */
  byte = 0x9Eu;
  tg_set_index8(instance, &instance->cpu.x, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBE26u;
  instance->instruction_count++;
  return 1;
 case 0x0600BE26u: /* 8E 21 21 STX $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), (uint8_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xBE29u;
  instance->instruction_count++;
  return 1;
 case 0x0600BE29u: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBE2Cu;
  instance->instruction_count++;
  return 1;
 case 0x0600BE2Cu: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xBE2Du;
  instance->instruction_count++;
  return 1;
 case 0x0600BE2Du: /* 8D 22 21 STA $2122 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2122u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBE30u;
  instance->instruction_count++;
  return 1;
 case 0x0600BE30u: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBE32u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE32u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBE34u;
  instance->instruction_count++;
  return 1;
 case 0x0400BE34u: /* A9 20 LDA #$20 */
  byte = 0x20u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBE36u;
  instance->instruction_count++;
  return 1;
 case 0x0400BE36u: /* 8D 21 21 STA $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBE39u;
  instance->instruction_count++;
  return 1;
 case 0x0400BE39u: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBE3Bu;
  instance->instruction_count++;
  return 1;
 case 0x0400BE3Bu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBE3Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400BE3Eu: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBE41u;
  instance->instruction_count++;
  return 1;
 case 0x0400BE41u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBE43u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE43u: /* A9 02 22 LDA #$2202 */
  word = 0x2202u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBE46u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE46u: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBE49u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE49u: /* A9 8E 03 LDA #$038E */
  word = 0x038Eu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBE4Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BE4Cu: /* 8D 72 43 STA $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBE4Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BE4Fu: /* A9 C0 00 LDA #$00C0 */
  word = 0x00C0u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBE52u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE52u: /* 8D 75 43 STA $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBE55u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE55u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBE57u;
  instance->instruction_count++;
  return 1;
 case 0x0400BE57u: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBE59u;
  instance->instruction_count++;
  return 1;
 case 0x0400BE59u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBE5Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400BE5Cu: /* A5 52 LDA $52 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x52u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBE5Eu;
  instance->instruction_count++;
  return 1;
 case 0x0400BE5Eu: /* 8D 00 21 STA $2100 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2100u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBE61u;
  instance->instruction_count++;
  return 1;
 case 0x0400BE61u: /* 20 0D E2 JSR $E20D */
  if (!tg_push16(instance, 0xBE63u)) return 0;
  instance->cpu.pc = 0xE20Du;
  instance->instruction_count++;
  return 1;
 case 0x0000BE64u: /* 20 6A D8 JSR $D86A */
  if (!tg_push16(instance, 0xBE66u)) return 0;
  instance->cpu.pc = 0xD86Au;
  instance->instruction_count++;
  return 1;
 case 0x0000BE67u: /* 20 A8 8D JSR $8DA8 */
  if (!tg_push16(instance, 0xBE69u)) return 0;
  instance->cpu.pc = 0x8DA8u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE6Au: /* 20 B4 8E JSR $8EB4 */
  if (!tg_push16(instance, 0xBE6Cu)) return 0;
  instance->cpu.pc = 0x8EB4u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE6Du: /* 20 C0 8F JSR $8FC0 */
  if (!tg_push16(instance, 0xBE6Fu)) return 0;
  instance->cpu.pc = 0x8FC0u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE70u: /* 20 46 90 JSR $9046 */
  if (!tg_push16(instance, 0xBE72u)) return 0;
  instance->cpu.pc = 0x9046u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE73u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBE75u;
  instance->instruction_count++;
  return 1;
 case 0x0000BE75u: /* 6C AC 00 JMP ($00AC) */
  if (!tg_bus_read16(instance, 0x0000ACu, &word)) return 0;
  if (!(word==0xB3FEu || word==0xB42Fu || word==0xB462u || word==0xB49Bu || word==0xEC7Eu)) return tg_fail_frontier(instance, "Version 22 $00AC indirect JMP target is outside the ROM-proved finite set.", NULL);
  instance->cpu.pc = word;
  instance->instruction_count++;
  return 1;
 case 0x0000BE78u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBE7Au;
  instance->instruction_count++;
  return 1;
 case 0x0400BE7Au: /* AD 12 42 LDA $4212 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4212u), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBE7Du;
  instance->instruction_count++;
  return 1;
 case 0x0400BE7Du: /* 29 40 AND #$40 */
  byte = 0x40u;
  byte = (uint8_t)((tg_acc8(instance)) & byte);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBE7Fu;
  instance->instruction_count++;
  return 1;
 case 0x0400BE7Fu: /* F0 F9 BEQ $00:BE7A */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xBE7Au : 0xBE81u;
  instance->instruction_count++;
  return 1;
 case 0x0400BE81u: /* AD 12 42 LDA $4212 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4212u), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBE84u;
  instance->instruction_count++;
  return 1;
 case 0x0400BE84u: /* 29 40 AND #$40 */
  byte = 0x40u;
  byte = (uint8_t)((tg_acc8(instance)) & byte);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBE86u;
  instance->instruction_count++;
  return 1;
 case 0x0400BE86u: /* D0 F9 BNE $00:BE81 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBE81u : 0xBE88u;
  instance->instruction_count++;
  return 1;
 case 0x0400BE88u: /* A9 8F LDA #$8F */
  byte = 0x8Fu;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBE8Au;
  instance->instruction_count++;
  return 1;
 case 0x0400BE8Au: /* 8D 00 21 STA $2100 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2100u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBE8Du;
  instance->instruction_count++;
  return 1;
 case 0x0400BE8Du: /* A9 20 LDA #$20 */
  byte = 0x20u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBE8Fu;
  instance->instruction_count++;
  return 1;
 case 0x0400BE8Fu: /* 8D 21 21 STA $2121 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2121u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBE92u;
  instance->instruction_count++;
  return 1;
 case 0x0400BE92u: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBE94u;
  instance->instruction_count++;
  return 1;
 case 0x0400BE94u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBE97u;
  instance->instruction_count++;
  return 1;
 case 0x0400BE97u: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBE9Au;
  instance->instruction_count++;
  return 1;
 case 0x0400BE9Au: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBE9Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000BE9Cu: /* A9 02 22 LDA #$2202 */
  word = 0x2202u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBE9Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000BE9Fu: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBEA2u;
  instance->instruction_count++;
  return 1;
 case 0x0000BEA2u: /* A9 4E 04 LDA #$044E */
  word = 0x044Eu;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBEA5u;
  instance->instruction_count++;
  return 1;
 case 0x0000BEA5u: /* 8D 72 43 STA $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBEA8u;
  instance->instruction_count++;
  return 1;
 case 0x0000BEA8u: /* A9 C0 00 LDA #$00C0 */
  word = 0x00C0u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBEABu;
  instance->instruction_count++;
  return 1;
 case 0x0000BEABu: /* 8D 75 43 STA $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBEAEu;
  instance->instruction_count++;
  return 1;
 case 0x0000BEAEu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBEB0u;
  instance->instruction_count++;
  return 1;
 case 0x0400BEB0u: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBEB2u;
  instance->instruction_count++;
  return 1;
 case 0x0400BEB2u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBEB5u;
  instance->instruction_count++;
  return 1;
 case 0x0400BEB5u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBEB7u;
  instance->instruction_count++;
  return 1;
 case 0x0000BEB7u: /* A2 05 00 LDX #$0005 */
  word = 0x0005u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBEBAu;
  instance->instruction_count++;
  return 1;
 case 0x0000BEBAu: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBEBBu;
  instance->instruction_count++;
  return 1;
 case 0x0000BEBBu: /* D0 FD BNE $00:BEBA */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xBEBAu : 0xBEBDu;
  instance->instruction_count++;
  return 1;
 case 0x0000BEBDu: /* EA NOP */
  instance->cpu.pc = 0xBEBEu;
  instance->instruction_count++;
  return 1;
 case 0x0000BEBEu: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBEC1u;
  instance->instruction_count++;
  return 1;
 case 0x0000BEC1u: /* 8D 02 21 STA $2102 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2102u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBEC4u;
  instance->instruction_count++;
  return 1;
 case 0x0000BEC4u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBEC6u;
  instance->instruction_count++;
  return 1;
 case 0x0400BEC6u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBEC9u;
  instance->instruction_count++;
  return 1;
 case 0x0400BEC9u: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBECCu;
  instance->instruction_count++;
  return 1;
 case 0x0400BECCu: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBECEu;
  instance->instruction_count++;
  return 1;
 case 0x0000BECEu: /* A9 02 04 LDA #$0402 */
  word = 0x0402u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBED1u;
  instance->instruction_count++;
  return 1;
 case 0x0000BED1u: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBED4u;
  instance->instruction_count++;
  return 1;
 case 0x0000BED4u: /* A5 DE LDA $DE */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xDEu) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBED6u;
  instance->instruction_count++;
  return 1;
 case 0x0000BED6u: /* 8D 72 43 STA $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBED9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BED9u: /* A9 20 02 LDA #$0220 */
  word = 0x0220u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBEDCu;
  instance->instruction_count++;
  return 1;
 case 0x0000BEDCu: /* 8D 75 43 STA $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBEDFu;
  instance->instruction_count++;
  return 1;
 case 0x0000BEDFu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBEE1u;
  instance->instruction_count++;
  return 1;
 case 0x0400BEE1u: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBEE3u;
  instance->instruction_count++;
  return 1;
 case 0x0400BEE3u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBEE6u;
  instance->instruction_count++;
  return 1;
 case 0x0400BEE6u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBEE8u;
  instance->instruction_count++;
  return 1;
 case 0x0000BEE8u: /* A5 DC LDA $DC */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0xDCu) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBEEAu;
  instance->instruction_count++;
  return 1;
 case 0x0000BEEAu: /* 09 00 80 ORA #$8000 */
  word = 0x8000u;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xBEEDu;
  instance->instruction_count++;
  return 1;
 case 0x0000BEEDu: /* 8D 02 21 STA $2102 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2102u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xBEF0u;
  instance->instruction_count++;
  return 1;
 case 0x0000BEF0u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBEF2u;
  instance->instruction_count++;
  return 1;
 case 0x0400BEF2u: /* A5 65 LDA $65 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x65u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xBEF4u;
  instance->instruction_count++;
  return 1;
 case 0x0400BEF4u: /* 8D 00 21 STA $2100 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2100u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xBEF7u;
  instance->instruction_count++;
  return 1;
 case 0x0400BEF7u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xBEF9u;
  instance->instruction_count++;
  return 1;
 case 0x0000BEF9u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000D86Au: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xD86Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000D86Cu: /* AD B4 1B LDA $1BB4 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB4u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD86Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000D86Fu: /* 10 51 BPL $00:D8C2 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xD8C2u : 0xD871u;
  instance->instruction_count++;
  return 1;
 case 0x0000D871u: /* AE 20 01 LDX $0120 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0120u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD874u;
  instance->instruction_count++;
  return 1;
 case 0x0000D874u: /* D0 06 BNE $00:D87C */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xD87Cu : 0xD876u;
  instance->instruction_count++;
  return 1;
 case 0x0000D876u: /* AE 32 01 LDX $0132 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0132u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD879u;
  instance->instruction_count++;
  return 1;
 case 0x0000D879u: /* D0 52 BNE $00:D8CD */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xD8CDu : 0xD87Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000D87Bu: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000D87Cu: /* AD 22 01 LDA $0122 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0122u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD87Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000D87Fu: /* 8D 16 21 STA $2116 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xD882u;
  instance->instruction_count++;
  return 1;
 case 0x0000D882u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xD883u;
  instance->instruction_count++;
  return 1;
 case 0x0000D883u: /* 69 20 00 ADC #$0020 */
  word = 0x0020u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xD886u;
  instance->instruction_count++;
  return 1;
 case 0x0000D886u: /* 8D 22 01 STA $0122 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0122u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xD889u;
  instance->instruction_count++;
  return 1;
 case 0x0000D889u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xD88Bu;
  instance->instruction_count++;
  return 1;
 case 0x0400D88Bu: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xD88Du;
  instance->instruction_count++;
  return 1;
 case 0x0400D88Du: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xD890u;
  instance->instruction_count++;
  return 1;
 case 0x0400D890u: /* A9 02 LDA #$02 */
  byte = 0x02u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xD892u;
  instance->instruction_count++;
  return 1;
 case 0x0400D892u: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xD895u;
  instance->instruction_count++;
  return 1;
 case 0x0400D895u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xD897u;
  instance->instruction_count++;
  return 1;
 case 0x0000D897u: /* A9 01 18 LDA #$1801 */
  word = 0x1801u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD89Au;
  instance->instruction_count++;
  return 1;
 case 0x0000D89Au: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xD89Du;
  instance->instruction_count++;
  return 1;
 case 0x0000D89Du: /* BF 00 00 06 LDA $060000,X */
  if (!tg_bus_read16(instance, ((0x060000u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD8A1u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8A1u: /* 8D 72 43 STA $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xD8A4u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8A4u: /* A9 40 00 LDA #$0040 */
  word = 0x0040u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD8A7u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8A7u: /* 8D 75 43 STA $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xD8AAu;
  instance->instruction_count++;
  return 1;
 case 0x0000D8AAu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xD8ACu;
  instance->instruction_count++;
  return 1;
 case 0x0400D8ACu: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xD8AEu;
  instance->instruction_count++;
  return 1;
 case 0x0400D8AEu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xD8B1u;
  instance->instruction_count++;
  return 1;
 case 0x0400D8B1u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xD8B3u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8B3u: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD8B4u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8B4u: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD8B5u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8B5u: /* BF 00 00 06 LDA $060000,X */
  if (!tg_bus_read16(instance, ((0x060000u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD8B9u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8B9u: /* D0 03 BNE $00:D8BE */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xD8BEu : 0xD8BBu;
  instance->instruction_count++;
  return 1;
 case 0x0000D8BBu: /* A2 00 00 LDX #$0000 */
  word = 0x0000u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD8BEu;
  instance->instruction_count++;
  return 1;
 case 0x0000D8BEu: /* 8E 20 01 STX $0120 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0120u), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xD8C1u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8C1u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000D8C2u: /* AE 32 01 LDX $0132 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0132u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD8C5u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8C5u: /* D0 06 BNE $00:D8CD */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xD8CDu : 0xD8C7u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8C7u: /* AE 20 01 LDX $0120 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0120u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD8CAu;
  instance->instruction_count++;
  return 1;
 case 0x0000D8CAu: /* D0 B0 BNE $00:D87C */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xD87Cu : 0xD8CCu;
  instance->instruction_count++;
  return 1;
 case 0x0000D8CCu: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000D8CDu: /* AD 34 01 LDA $0134 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0134u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD8D0u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8D0u: /* 8D 16 21 STA $2116 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xD8D3u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8D3u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xD8D4u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8D4u: /* 69 20 00 ADC #$0020 */
  word = 0x0020u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xD8D7u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8D7u: /* 8D 34 01 STA $0134 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0134u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xD8DAu;
  instance->instruction_count++;
  return 1;
 case 0x0000D8DAu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xD8DCu;
  instance->instruction_count++;
  return 1;
 case 0x0400D8DCu: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xD8DEu;
  instance->instruction_count++;
  return 1;
 case 0x0400D8DEu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xD8E1u;
  instance->instruction_count++;
  return 1;
 case 0x0400D8E1u: /* A9 02 LDA #$02 */
  byte = 0x02u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xD8E3u;
  instance->instruction_count++;
  return 1;
 case 0x0400D8E3u: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xD8E6u;
  instance->instruction_count++;
  return 1;
 case 0x0400D8E6u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xD8E8u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8E8u: /* A9 01 18 LDA #$1801 */
  word = 0x1801u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD8EBu;
  instance->instruction_count++;
  return 1;
 case 0x0000D8EBu: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xD8EEu;
  instance->instruction_count++;
  return 1;
 case 0x0000D8EEu: /* BF 00 00 06 LDA $060000,X */
  if (!tg_bus_read16(instance, ((0x060000u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD8F2u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8F2u: /* 8D 72 43 STA $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xD8F5u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8F5u: /* A9 40 00 LDA #$0040 */
  word = 0x0040u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD8F8u;
  instance->instruction_count++;
  return 1;
 case 0x0000D8F8u: /* 8D 75 43 STA $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xD8FBu;
  instance->instruction_count++;
  return 1;
 case 0x0000D8FBu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xD8FDu;
  instance->instruction_count++;
  return 1;
 case 0x0400D8FDu: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xD8FFu;
  instance->instruction_count++;
  return 1;
 case 0x0400D8FFu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xD902u;
  instance->instruction_count++;
  return 1;
 case 0x0400D902u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xD904u;
  instance->instruction_count++;
  return 1;
 case 0x0000D904u: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD905u;
  instance->instruction_count++;
  return 1;
 case 0x0000D905u: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD906u;
  instance->instruction_count++;
  return 1;
 case 0x0000D906u: /* BF 00 00 06 LDA $060000,X */
  if (!tg_bus_read16(instance, ((0x060000u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD90Au;
  instance->instruction_count++;
  return 1;
 case 0x0000D90Au: /* D0 03 BNE $00:D90F */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xD90Fu : 0xD90Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000D90Cu: /* A2 00 00 LDX #$0000 */
  word = 0x0000u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xD90Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000D90Fu: /* 8E 32 01 STX $0132 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0132u), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xD912u;
  instance->instruction_count++;
  return 1;
 case 0x0000D912u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0400E20Du: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xE20Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E20Fu: /* AD 00 02 LDA $0200 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0200u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE212u;
  instance->instruction_count++;
  return 1;
 case 0x0000E212u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE213u;
  instance->instruction_count++;
  return 1;
 case 0x0000E213u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE214u;
  instance->instruction_count++;
  return 1;
 case 0x0000E214u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE215u;
  instance->instruction_count++;
  return 1;
 case 0x0000E215u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE216u;
  instance->instruction_count++;
  return 1;
 case 0x0000E216u: /* 29 FE FF AND #$FFFE */
  word = 0xFFFEu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE219u;
  instance->instruction_count++;
  return 1;
 case 0x0000E219u: /* 8D B6 1B STA $1BB6 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB6u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE21Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E21Cu: /* AD B4 1B LDA $1BB4 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB4u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE21Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E21Fu: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE222u;
  instance->instruction_count++;
  return 1;
 case 0x0000E222u: /* 8D B4 1B STA $1BB4 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB4u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE225u;
  instance->instruction_count++;
  return 1;
 case 0x0000E225u: /* 30 03 BMI $00:E22A */
  instance->cpu.pc = tg_flag(instance, TG_P_N) ? 0xE22Au : 0xE227u;
  instance->instruction_count++;
  return 1;
 case 0x0000E227u: /* 4C 5A E5 JMP $E55A */
  instance->cpu.pc = 0xE55Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E22Au: /* 24 40 BIT $40 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x40u) & 0xFFFFu), &word)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
  tg_set_flag(instance, TG_P_N, (word & 0x8000u) != 0u);
  tg_set_flag(instance, TG_P_V, (word & 0x4000u) != 0u);
  instance->cpu.pc = 0xE22Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E22Cu: /* 10 04 BPL $00:E232 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xE232u : 0xE22Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E22Eu: /* 9C C0 1B STZ $1BC0 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC0u), 0u)) return 0;
  instance->cpu.pc = 0xE231u;
  instance->instruction_count++;
  return 1;
 case 0x0000E231u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000E232u: /* A5 46 LDA $46 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x46u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE234u;
  instance->instruction_count++;
  return 1;
 case 0x0000E234u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE235u;
  instance->instruction_count++;
  return 1;
 case 0x0000E235u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE236u;
  instance->instruction_count++;
  return 1;
 case 0x0000E236u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE237u;
  instance->instruction_count++;
  return 1;
 case 0x0000E237u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE238u;
  instance->instruction_count++;
  return 1;
 case 0x0000E238u: /* 29 FE FF AND #$FFFE */
  word = 0xFFFEu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE23Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E23Bu: /* 8D B8 1B STA $1BB8 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB8u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE23Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E23Eu: /* AC E6 1B LDY $1BE6 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE6u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE241u;
  instance->instruction_count++;
  return 1;
 case 0x0000E241u: /* F0 38 BEQ $00:E27B */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE27Bu : 0xE243u;
  instance->instruction_count++;
  return 1;
 case 0x0000E243u: /* A2 00 00 LDX #$0000 */
  word = 0x0000u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE246u;
  instance->instruction_count++;
  return 1;
 case 0x0000E246u: /* BD F8 1B LDA $1BF8,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BF8u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE249u;
  instance->instruction_count++;
  return 1;
 case 0x0000E249u: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE24Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E24Au: /* ED B8 1B SBC $1BB8 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB8u), &word)) return 0;
  tg_sbc16(instance, word);
  instance->cpu.pc = 0xE24Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E24Du: /* B0 03 BCS $00:E252 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE252u : 0xE24Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E24Fu: /* 6D B6 1B ADC $1BB6 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB6u), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE252u;
  instance->instruction_count++;
  return 1;
 case 0x0000E252u: /* C9 5A 00 CMP #$005A */
  word = 0x005Au;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE255u;
  instance->instruction_count++;
  return 1;
 case 0x0000E255u: /* 90 1F BCC $00:E276 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xE276u : 0xE257u;
  instance->instruction_count++;
  return 1;
 case 0x0000E257u: /* CE E6 1B DEC $1BE6 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE6u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE6u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE25Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E25Au: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE25Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E25Bu: /* F0 1E BEQ $00:E27B */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE27Bu : 0xE25Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E25Du: /* 5A PHY */
  if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
  instance->cpu.pc = 0xE25Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E25Eu: /* DA PHX */
  if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xE25Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E25Fu: /* BD FA 1B LDA $1BFA,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BFAu + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE262u;
  instance->instruction_count++;
  return 1;
 case 0x0000E262u: /* 9D F8 1B STA $1BF8,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BF8u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE265u;
  instance->instruction_count++;
  return 1;
 case 0x0000E265u: /* BD EA 1B LDA $1BEA,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BEAu + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE268u;
  instance->instruction_count++;
  return 1;
 case 0x0000E268u: /* 9D E8 1B STA $1BE8,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BE8u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE26Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E26Bu: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE26Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E26Cu: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE26Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E26Du: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE26Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E26Eu: /* D0 EF BNE $00:E25F */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE25Fu : 0xE270u;
  instance->instruction_count++;
  return 1;
 case 0x0000E270u: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE271u;
  instance->instruction_count++;
  return 1;
 case 0x0000E271u: /* 7A PLY */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE272u;
  instance->instruction_count++;
  return 1;
 case 0x0000E272u: /* D0 D2 BNE $00:E246 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE246u : 0xE274u;
  instance->instruction_count++;
  return 1;
 case 0x0000E274u: /* 80 05 BRA $00:E27B */
  instance->cpu.pc = 0xE27Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E276u: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE277u;
  instance->instruction_count++;
  return 1;
 case 0x0000E277u: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE278u;
  instance->instruction_count++;
  return 1;
 case 0x0000E278u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE279u;
  instance->instruction_count++;
  return 1;
 case 0x0000E279u: /* D0 CB BNE $00:E246 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE246u : 0xE27Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E27Bu: /* AD B8 1B LDA $1BB8 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB8u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE27Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E27Eu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xE27Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E27Fu: /* 69 50 00 ADC #$0050 */
  word = 0x0050u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE282u;
  instance->instruction_count++;
  return 1;
 case 0x0000E282u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE283u;
  instance->instruction_count++;
  return 1;
 case 0x0000E283u: /* A0 04 00 LDY #$0004 */
  word = 0x0004u;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE286u;
  instance->instruction_count++;
  return 1;
 case 0x0000E286u: /* 5A PHY */
  if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
  instance->cpu.pc = 0xE287u;
  instance->instruction_count++;
  return 1;
 case 0x0000E287u: /* BF 00 64 7E LDA $7E6400,X */
  if (!tg_bus_read16(instance, ((0x7E6400u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE28Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E28Bu: /* D0 03 BNE $00:E290 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE290u : 0xE28Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E28Du: /* 4C 4D E3 JMP $E34D */
  instance->cpu.pc = 0xE34Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E290u: /* 10 66 BPL $00:E2F8 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xE2F8u : 0xE292u;
  instance->instruction_count++;
  return 1;
 case 0x0000E292u: /* 29 FE 3F AND #$3FFE */
  word = 0x3FFEu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE295u;
  instance->instruction_count++;
  return 1;
 case 0x0000E295u: /* A8 TAY */
  tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.y);
  instance->cpu.pc = 0xE296u;
  instance->instruction_count++;
  return 1;
 case 0x0000E296u: /* B9 88 E8 LDA $E888,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE888u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE299u;
  instance->instruction_count++;
  return 1;
 case 0x0000E299u: /* A8 TAY */
  tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.y);
  instance->cpu.pc = 0xE29Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E29Au: /* B9 9A E8 LDA $E89A,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE89Au + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE29Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E29Du: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE29Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E29Eu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE29Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E29Fu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2A0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2A0u: /* B9 9A E8 LDA $E89A,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE89Au + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2A3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2A3u: /* 5A PHY */
  if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
  instance->cpu.pc = 0xE2A4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2A4u: /* DA PHX */
  if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xE2A5u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2A5u: /* AC C2 1B LDY $1BC2 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC2u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2A8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2A8u: /* CC C4 1B CPY $1BC4 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC4u), &word)) return 0;
  tg_compare16(instance, (uint16_t)instance->cpu.y, word);
  instance->cpu.pc = 0xE2ABu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2ABu: /* F0 17 BEQ $00:E2C4 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE2C4u : 0xE2ADu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2ADu: /* D9 C6 1B CMP $1BC6,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BC6u + instance->cpu.y)), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE2B0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2B0u: /* D0 07 BNE $00:E2B9 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE2B9u : 0xE2B2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2B2u: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2B3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2B3u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE2B4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2B4u: /* 99 D6 1B STA $1BD6,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BD6u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE2B7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2B7u: /* 80 38 BRA $00:E2F1 */
  instance->cpu.pc = 0xE2F1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2B9u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE2BAu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2BAu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2BBu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2BBu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2BCu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2BCu: /* 98 TYA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.y);
  tg_set_nz16(instance, (uint16_t)instance->cpu.a);
  instance->cpu.pc = 0xE2BDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2BDu: /* 29 0E 00 AND #$000E */
  word = 0x000Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2C0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2C0u: /* A8 TAY */
  tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.y);
  instance->cpu.pc = 0xE2C1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2C1u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE2C2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2C2u: /* 80 E4 BRA $00:E2A8 */
  instance->cpu.pc = 0xE2A8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2C4u: /* AE E6 1B LDX $1BE6 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE6u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2C7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2C7u: /* F0 14 BEQ $00:E2DD */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE2DDu : 0xE2C9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2C9u: /* A0 00 00 LDY #$0000 */
  word = 0x0000u;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2CCu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2CCu: /* D9 E8 1B CMP $1BE8,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BE8u + instance->cpu.y)), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE2CFu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2CFu: /* D0 07 BNE $00:E2D8 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE2D8u : 0xE2D1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2D1u: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2D2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2D2u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE2D3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2D3u: /* 99 F8 1B STA $1BF8,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BF8u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE2D6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2D6u: /* 80 19 BRA $00:E2F1 */
  instance->cpu.pc = 0xE2F1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2D8u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2D9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2D9u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2DAu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2DAu: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2DBu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2DBu: /* D0 EF BNE $00:E2CC */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE2CCu : 0xE2DDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2DDu: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2DEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2DEu: /* AC C4 1B LDY $1BC4 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC4u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2E1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2E1u: /* 99 C6 1B STA $1BC6,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BC6u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE2E4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2E4u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE2E5u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2E5u: /* 99 D6 1B STA $1BD6,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BD6u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE2E8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2E8u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2E9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2E9u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2EAu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2EAu: /* 98 TYA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.y);
  tg_set_nz16(instance, (uint16_t)instance->cpu.a);
  instance->cpu.pc = 0xE2EBu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2EBu: /* 29 0E 00 AND #$000E */
  word = 0x000Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2EEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2EEu: /* 8D C4 1B STA $1BC4 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC4u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE2F1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2F1u: /* 7A PLY */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2F2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2F2u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2F3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2F3u: /* 3A DEC A */
  word = (uint16_t)((instance->cpu.a) - 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2F4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2F4u: /* D0 A7 BNE $00:E29D */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE29Du : 0xE2F6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2F6u: /* 80 55 BRA $00:E34D */
  instance->cpu.pc = 0xE34Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E2F8u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xE2F9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E2F9u: /* 29 7E 00 AND #$007E */
  word = 0x007Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE2FCu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2FCu: /* A8 TAY */
  tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.y);
  instance->cpu.pc = 0xE2FDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E2FDu: /* B9 BA E9 LDA $E9BA,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE9BAu + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE300u;
  instance->instruction_count++;
  return 1;
 case 0x0000E300u: /* DA PHX */
  if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xE301u;
  instance->instruction_count++;
  return 1;
 case 0x0000E301u: /* AC C2 1B LDY $1BC2 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC2u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE304u;
  instance->instruction_count++;
  return 1;
 case 0x0000E304u: /* CC C4 1B CPY $1BC4 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC4u), &word)) return 0;
  tg_compare16(instance, (uint16_t)instance->cpu.y, word);
  instance->cpu.pc = 0xE307u;
  instance->instruction_count++;
  return 1;
 case 0x0000E307u: /* F0 17 BEQ $00:E320 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE320u : 0xE309u;
  instance->instruction_count++;
  return 1;
 case 0x0000E309u: /* D9 C6 1B CMP $1BC6,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BC6u + instance->cpu.y)), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE30Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E30Cu: /* D0 07 BNE $00:E315 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE315u : 0xE30Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E30Eu: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE30Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E30Fu: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE310u;
  instance->instruction_count++;
  return 1;
 case 0x0000E310u: /* 99 D6 1B STA $1BD6,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BD6u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE313u;
  instance->instruction_count++;
  return 1;
 case 0x0000E313u: /* 80 38 BRA $00:E34D */
  instance->cpu.pc = 0xE34Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E315u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE316u;
  instance->instruction_count++;
  return 1;
 case 0x0000E316u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE317u;
  instance->instruction_count++;
  return 1;
 case 0x0000E317u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE318u;
  instance->instruction_count++;
  return 1;
 case 0x0000E318u: /* 98 TYA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.y);
  tg_set_nz16(instance, (uint16_t)instance->cpu.a);
  instance->cpu.pc = 0xE319u;
  instance->instruction_count++;
  return 1;
 case 0x0000E319u: /* 29 0E 00 AND #$000E */
  word = 0x000Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE31Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E31Cu: /* A8 TAY */
  tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.y);
  instance->cpu.pc = 0xE31Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E31Du: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE31Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E31Eu: /* 80 E4 BRA $00:E304 */
  instance->cpu.pc = 0xE304u;
  instance->instruction_count++;
  return 1;
 case 0x0000E320u: /* AE E6 1B LDX $1BE6 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE6u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE323u;
  instance->instruction_count++;
  return 1;
 case 0x0000E323u: /* F0 14 BEQ $00:E339 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE339u : 0xE325u;
  instance->instruction_count++;
  return 1;
 case 0x0000E325u: /* A0 00 00 LDY #$0000 */
  word = 0x0000u;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE328u;
  instance->instruction_count++;
  return 1;
 case 0x0000E328u: /* D9 E8 1B CMP $1BE8,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BE8u + instance->cpu.y)), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE32Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E32Bu: /* D0 07 BNE $00:E334 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE334u : 0xE32Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E32Du: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE32Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E32Eu: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE32Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E32Fu: /* 99 F8 1B STA $1BF8,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BF8u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE332u;
  instance->instruction_count++;
  return 1;
 case 0x0000E332u: /* 80 19 BRA $00:E34D */
  instance->cpu.pc = 0xE34Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E334u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE335u;
  instance->instruction_count++;
  return 1;
 case 0x0000E335u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE336u;
  instance->instruction_count++;
  return 1;
 case 0x0000E336u: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE337u;
  instance->instruction_count++;
  return 1;
 case 0x0000E337u: /* D0 EF BNE $00:E328 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE328u : 0xE339u;
  instance->instruction_count++;
  return 1;
 case 0x0000E339u: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE33Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E33Au: /* AC C4 1B LDY $1BC4 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC4u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE33Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E33Du: /* 99 C6 1B STA $1BC6,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BC6u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE340u;
  instance->instruction_count++;
  return 1;
 case 0x0000E340u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE341u;
  instance->instruction_count++;
  return 1;
 case 0x0000E341u: /* 99 D6 1B STA $1BD6,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BD6u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE344u;
  instance->instruction_count++;
  return 1;
 case 0x0000E344u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE345u;
  instance->instruction_count++;
  return 1;
 case 0x0000E345u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE346u;
  instance->instruction_count++;
  return 1;
 case 0x0000E346u: /* 98 TYA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.y);
  tg_set_nz16(instance, (uint16_t)instance->cpu.a);
  instance->cpu.pc = 0xE347u;
  instance->instruction_count++;
  return 1;
 case 0x0000E347u: /* 29 0E 00 AND #$000E */
  word = 0x000Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE34Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E34Au: /* 8D C4 1B STA $1BC4 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC4u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE34Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E34Du: /* 7A PLY */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE34Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E34Eu: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE34Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E34Fu: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE350u;
  instance->instruction_count++;
  return 1;
 case 0x0000E350u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE351u;
  instance->instruction_count++;
  return 1;
 case 0x0000E351u: /* F0 03 BEQ $00:E356 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE356u : 0xE353u;
  instance->instruction_count++;
  return 1;
 case 0x0000E353u: /* 4C 86 E2 JMP $E286 */
  instance->cpu.pc = 0xE286u;
  instance->instruction_count++;
  return 1;
 case 0x0000E356u: /* AD C0 1B LDA $1BC0 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC0u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE359u;
  instance->instruction_count++;
  return 1;
 case 0x0000E359u: /* F0 03 BEQ $00:E35E */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE35Eu : 0xE35Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E35Bu: /* 4C 00 E5 JMP $E500 */
  instance->cpu.pc = 0xE500u;
  instance->instruction_count++;
  return 1;
 case 0x0000E35Eu: /* AC E6 1B LDY $1BE6 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE6u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE361u;
  instance->instruction_count++;
  return 1;
 case 0x0000E361u: /* D0 4E BNE $00:E3B1 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE3B1u : 0xE363u;
  instance->instruction_count++;
  return 1;
 case 0x0000E363u: /* AD C2 1B LDA $1BC2 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC2u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE366u;
  instance->instruction_count++;
  return 1;
 case 0x0000E366u: /* CD C4 1B CMP $1BC4 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC4u), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE369u;
  instance->instruction_count++;
  return 1;
 case 0x0000E369u: /* D0 03 BNE $00:E36E */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE36Eu : 0xE36Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E36Bu: /* 4C 59 E5 JMP $E559 */
  instance->cpu.pc = 0xE559u;
  instance->instruction_count++;
  return 1;
 case 0x0000E36Eu: /* EE E6 1B INC $1BE6 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE6u), &word)) return 0;
  word = (uint16_t)(word + 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE6u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE371u;
  instance->instruction_count++;
  return 1;
 case 0x0000E371u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE372u;
  instance->instruction_count++;
  return 1;
 case 0x0000E372u: /* 1A INC A */
  word = (uint16_t)((instance->cpu.a) + 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE373u;
  instance->instruction_count++;
  return 1;
 case 0x0000E373u: /* 1A INC A */
  word = (uint16_t)((instance->cpu.a) + 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE374u;
  instance->instruction_count++;
  return 1;
 case 0x0000E374u: /* 29 0E 00 AND #$000E */
  word = 0x000Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE377u;
  instance->instruction_count++;
  return 1;
 case 0x0000E377u: /* 8D C2 1B STA $1BC2 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC2u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE37Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E37Au: /* BD D6 1B LDA $1BD6,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BD6u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE37Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E37Du: /* 8D F8 1B STA $1BF8 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BF8u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE380u;
  instance->instruction_count++;
  return 1;
 case 0x0000E380u: /* BD C6 1B LDA $1BC6,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BC6u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE383u;
  instance->instruction_count++;
  return 1;
 case 0x0000E383u: /* 8D E8 1B STA $1BE8 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE8u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE386u;
  instance->instruction_count++;
  return 1;
 case 0x0000E386u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE387u;
  instance->instruction_count++;
  return 1;
 case 0x0000E387u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE388u;
  instance->instruction_count++;
  return 1;
 case 0x0000E388u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE389u;
  instance->instruction_count++;
  return 1;
 case 0x0000E389u: /* A8 TAY */
  tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.y);
  instance->cpu.pc = 0xE38Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E38Au: /* A9 00 30 LDA #$3000 */
  word = 0x3000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE38Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E38Du: /* 8D BE 1B STA $1BBE */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBEu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE390u;
  instance->instruction_count++;
  return 1;
 case 0x0000E390u: /* B9 82 E8 LDA $E882,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE882u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE393u;
  instance->instruction_count++;
  return 1;
 case 0x0000E393u: /* 8D BC 1B STA $1BBC */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBCu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE396u;
  instance->instruction_count++;
  return 1;
 case 0x0000E396u: /* B9 84 E8 LDA $E884,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE884u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE399u;
  instance->instruction_count++;
  return 1;
 case 0x0000E399u: /* 8D BA 1B STA $1BBA */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE39Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E39Cu: /* B9 86 E8 LDA $E886,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE886u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE39Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E39Fu: /* 8D C0 1B STA $1BC0 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC0u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE3A2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3A2u: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3A5u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3A5u: /* 9D 08 1C STA $1C08,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C08u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE3A8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3A8u: /* B9 88 E8 LDA $E888,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE888u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3ABu;
  instance->instruction_count++;
  return 1;
 case 0x0000E3ABu: /* 9D 88 1C STA $1C88,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C88u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE3AEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E3AEu: /* 4C 59 E5 JMP $E559 */
  instance->cpu.pc = 0xE559u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3B1u: /* C0 08 00 CPY #$0008 */
  word = 0x0008u;
  tg_compare16(instance, (uint16_t)instance->cpu.y, word);
  instance->cpu.pc = 0xE3B4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3B4u: /* D0 18 BNE $00:E3CE */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE3CEu : 0xE3B6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3B6u: /* AD C4 1B LDA $1BC4 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC4u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3B9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3B9u: /* 8D C2 1B STA $1BC2 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC2u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE3BCu;
  instance->instruction_count++;
  return 1;
 case 0x0000E3BCu: /* 4C 59 E5 JMP $E559 */
  instance->cpu.pc = 0xE559u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3BFu: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3C0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3C0u: /* AC E6 1B LDY $1BE6 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE6u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3C3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3C3u: /* AD C2 1B LDA $1BC2 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC2u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3C6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3C6u: /* 1A INC A */
  word = (uint16_t)((instance->cpu.a) + 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3C7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3C7u: /* 1A INC A */
  word = (uint16_t)((instance->cpu.a) + 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3C8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3C8u: /* 29 0E 00 AND #$000E */
  word = 0x000Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3CBu;
  instance->instruction_count++;
  return 1;
 case 0x0000E3CBu: /* 8D C2 1B STA $1BC2 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC2u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE3CEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E3CEu: /* AE C2 1B LDX $1BC2 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC2u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3D1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3D1u: /* EC C4 1B CPX $1BC4 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC4u), &word)) return 0;
  tg_compare16(instance, (uint16_t)instance->cpu.x, word);
  instance->cpu.pc = 0xE3D4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3D4u: /* D0 03 BNE $00:E3D9 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE3D9u : 0xE3D6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3D6u: /* 4C 59 E5 JMP $E559 */
  instance->cpu.pc = 0xE559u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3D9u: /* BD C6 1B LDA $1BC6,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BC6u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3DCu;
  instance->instruction_count++;
  return 1;
 case 0x0000E3DCu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3DDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E3DDu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3DEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E3DEu: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE3DFu;
  instance->instruction_count++;
  return 1;
 case 0x0000E3DFu: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE3E0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3E0u: /* BD 88 E8 LDA $E888,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE888u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3E3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3E3u: /* 8D BA 1B STA $1BBA */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE3E6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3E6u: /* AE E8 1B LDX $1BE8 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE8u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3E9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3E9u: /* BD 08 1C LDA $1C08,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C08u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3ECu;
  instance->instruction_count++;
  return 1;
 case 0x0000E3ECu: /* CD BA 1B CMP $1BBA */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE3EFu;
  instance->instruction_count++;
  return 1;
 case 0x0000E3EFu: /* 90 07 BCC $00:E3F8 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xE3F8u : 0xE3F1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3F1u: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3F4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3F4u: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE3F5u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3F5u: /* 4C A3 E4 JMP $E4A3 */
  instance->cpu.pc = 0xE4A3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3F8u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE3F9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3F9u: /* D0 03 BNE $00:E3FE */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE3FEu : 0xE3FBu;
  instance->instruction_count++;
  return 1;
 case 0x0000E3FBu: /* 4C 89 E4 JMP $E489 */
  instance->cpu.pc = 0xE489u;
  instance->instruction_count++;
  return 1;
 case 0x0000E3FEu: /* BD 88 1C LDA $1C88,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C88u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE401u;
  instance->instruction_count++;
  return 1;
 case 0x0000E401u: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE402u;
  instance->instruction_count++;
  return 1;
 case 0x0000E402u: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE405u;
  instance->instruction_count++;
  return 1;
 case 0x0000E405u: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE406u;
  instance->instruction_count++;
  return 1;
 case 0x0000E406u: /* AE EA 1B LDX $1BEA */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BEAu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE409u;
  instance->instruction_count++;
  return 1;
 case 0x0000E409u: /* 7D 08 1C ADC $1C08,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C08u + instance->cpu.x)), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE40Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E40Cu: /* CD BA 1B CMP $1BBA */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE40Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E40Fu: /* 90 03 BCC $00:E414 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xE414u : 0xE411u;
  instance->instruction_count++;
  return 1;
 case 0x0000E411u: /* 4C A3 E4 JMP $E4A3 */
  instance->cpu.pc = 0xE4A3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E414u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE415u;
  instance->instruction_count++;
  return 1;
 case 0x0000E415u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE416u;
  instance->instruction_count++;
  return 1;
 case 0x0000E416u: /* F0 71 BEQ $00:E489 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE489u : 0xE418u;
  instance->instruction_count++;
  return 1;
 case 0x0000E418u: /* BD 88 1C LDA $1C88,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C88u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE41Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E41Bu: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE41Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E41Cu: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE41Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E41Fu: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE420u;
  instance->instruction_count++;
  return 1;
 case 0x0000E420u: /* AE EC 1B LDX $1BEC */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BECu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE423u;
  instance->instruction_count++;
  return 1;
 case 0x0000E423u: /* 7D 08 1C ADC $1C08,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C08u + instance->cpu.x)), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE426u;
  instance->instruction_count++;
  return 1;
 case 0x0000E426u: /* CD BA 1B CMP $1BBA */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE429u;
  instance->instruction_count++;
  return 1;
 case 0x0000E429u: /* B0 78 BCS $00:E4A3 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE4A3u : 0xE42Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E42Bu: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE42Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E42Cu: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE42Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E42Du: /* F0 5A BEQ $00:E489 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE489u : 0xE42Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E42Fu: /* BD 88 1C LDA $1C88,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C88u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE432u;
  instance->instruction_count++;
  return 1;
 case 0x0000E432u: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE433u;
  instance->instruction_count++;
  return 1;
 case 0x0000E433u: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE436u;
  instance->instruction_count++;
  return 1;
 case 0x0000E436u: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE437u;
  instance->instruction_count++;
  return 1;
 case 0x0000E437u: /* AE EE 1B LDX $1BEE */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BEEu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE43Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E43Au: /* 7D 08 1C ADC $1C08,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C08u + instance->cpu.x)), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE43Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E43Du: /* CD BA 1B CMP $1BBA */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE440u;
  instance->instruction_count++;
  return 1;
 case 0x0000E440u: /* B0 61 BCS $00:E4A3 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE4A3u : 0xE442u;
  instance->instruction_count++;
  return 1;
 case 0x0000E442u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE443u;
  instance->instruction_count++;
  return 1;
 case 0x0000E443u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE444u;
  instance->instruction_count++;
  return 1;
 case 0x0000E444u: /* F0 43 BEQ $00:E489 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE489u : 0xE446u;
  instance->instruction_count++;
  return 1;
 case 0x0000E446u: /* BD 88 1C LDA $1C88,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C88u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE449u;
  instance->instruction_count++;
  return 1;
 case 0x0000E449u: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE44Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E44Au: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE44Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E44Du: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE44Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E44Eu: /* AE F0 1B LDX $1BF0 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BF0u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE451u;
  instance->instruction_count++;
  return 1;
 case 0x0000E451u: /* 7D 08 1C ADC $1C08,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C08u + instance->cpu.x)), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE454u;
  instance->instruction_count++;
  return 1;
 case 0x0000E454u: /* CD BA 1B CMP $1BBA */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE457u;
  instance->instruction_count++;
  return 1;
 case 0x0000E457u: /* B0 4A BCS $00:E4A3 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE4A3u : 0xE459u;
  instance->instruction_count++;
  return 1;
 case 0x0000E459u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE45Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E45Au: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE45Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E45Bu: /* F0 2C BEQ $00:E489 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE489u : 0xE45Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E45Du: /* BD 88 1C LDA $1C88,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C88u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE460u;
  instance->instruction_count++;
  return 1;
 case 0x0000E460u: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE461u;
  instance->instruction_count++;
  return 1;
 case 0x0000E461u: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE464u;
  instance->instruction_count++;
  return 1;
 case 0x0000E464u: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE465u;
  instance->instruction_count++;
  return 1;
 case 0x0000E465u: /* AE F2 1B LDX $1BF2 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BF2u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE468u;
  instance->instruction_count++;
  return 1;
 case 0x0000E468u: /* 7D 08 1C ADC $1C08,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C08u + instance->cpu.x)), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE46Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E46Bu: /* CD BA 1B CMP $1BBA */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE46Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E46Eu: /* B0 33 BCS $00:E4A3 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE4A3u : 0xE470u;
  instance->instruction_count++;
  return 1;
 case 0x0000E470u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE471u;
  instance->instruction_count++;
  return 1;
 case 0x0000E471u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE472u;
  instance->instruction_count++;
  return 1;
 case 0x0000E472u: /* F0 15 BEQ $00:E489 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE489u : 0xE474u;
  instance->instruction_count++;
  return 1;
 case 0x0000E474u: /* BD 88 1C LDA $1C88,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C88u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE477u;
  instance->instruction_count++;
  return 1;
 case 0x0000E477u: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE478u;
  instance->instruction_count++;
  return 1;
 case 0x0000E478u: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE47Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E47Bu: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE47Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E47Cu: /* AE F4 1B LDX $1BF4 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BF4u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE47Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E47Fu: /* 7D 08 1C ADC $1C08,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C08u + instance->cpu.x)), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE482u;
  instance->instruction_count++;
  return 1;
 case 0x0000E482u: /* CD BA 1B CMP $1BBA */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE485u;
  instance->instruction_count++;
  return 1;
 case 0x0000E485u: /* B0 1C BCS $00:E4A3 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE4A3u : 0xE487u;
  instance->instruction_count++;
  return 1;
 case 0x0000E487u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE488u;
  instance->instruction_count++;
  return 1;
 case 0x0000E488u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE489u;
  instance->instruction_count++;
  return 1;
 case 0x0000E489u: /* A9 00 01 LDA #$0100 */
  word = 0x0100u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE48Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E48Cu: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE48Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E48Du: /* FD 88 1C SBC $1C88,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C88u + instance->cpu.x)), &word)) return 0;
  tg_sbc16(instance, word);
  instance->cpu.pc = 0xE490u;
  instance->instruction_count++;
  return 1;
 case 0x0000E490u: /* CD BA 1B CMP $1BBA */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE493u;
  instance->instruction_count++;
  return 1;
 case 0x0000E493u: /* B0 03 BCS $00:E498 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE498u : 0xE495u;
  instance->instruction_count++;
  return 1;
 case 0x0000E495u: /* 4C BF E3 JMP $E3BF */
  instance->cpu.pc = 0xE3BFu;
  instance->instruction_count++;
  return 1;
 case 0x0000E498u: /* BD 88 1C LDA $1C88,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C88u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE49Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E49Bu: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE49Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E49Cu: /* AD E6 1B LDA $1BE6 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE6u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE49Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E49Fu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4A0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4A0u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE4A1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4A1u: /* 80 16 BRA $00:E4B9 */
  instance->cpu.pc = 0xE4B9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4A3u: /* AD E6 1B LDA $1BE6 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE6u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4A6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4A6u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4A7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4A7u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE4A8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4A8u: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4A9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4A9u: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4AAu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4AAu: /* BD E8 1B LDA $1BE8,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BE8u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4ADu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4ADu: /* 9D EA 1B STA $1BEA,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BEAu + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE4B0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4B0u: /* BD F8 1B LDA $1BF8,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BF8u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4B3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4B3u: /* 9D FA 1B STA $1BFA,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BFAu + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE4B6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4B6u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4B7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4B7u: /* D0 EF BNE $00:E4A8 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE4A8u : 0xE4B9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4B9u: /* AD C2 1B LDA $1BC2 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC2u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4BCu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4BCu: /* A8 TAY */
  tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.y);
  instance->cpu.pc = 0xE4BDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4BDu: /* 1A INC A */
  word = (uint16_t)((instance->cpu.a) + 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4BEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4BEu: /* 1A INC A */
  word = (uint16_t)((instance->cpu.a) + 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4BFu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4BFu: /* 29 0E 00 AND #$000E */
  word = 0x000Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4C2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4C2u: /* 8D C2 1B STA $1BC2 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC2u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE4C5u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4C5u: /* EE E6 1B INC $1BE6 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE6u), &word)) return 0;
  word = (uint16_t)(word + 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BE6u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4C8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4C8u: /* B9 D6 1B LDA $1BD6,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BD6u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4CBu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4CBu: /* 9D F8 1B STA $1BF8,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BF8u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE4CEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4CEu: /* B9 C6 1B LDA $1BC6,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BC6u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4D1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4D1u: /* 9D E8 1B STA $1BE8,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1BE8u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE4D4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4D4u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE4D5u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4D5u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4D6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4D6u: /* 9D 08 1C STA $1C08,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C08u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE4D9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4D9u: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE4DAu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4DAu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xE4DBu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4DBu: /* 6D BA 1B ADC $1BBA */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE4DEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4DEu: /* 9D 88 1C STA $1C88,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1C88u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE4E1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4E1u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4E2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4E2u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4E3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4E3u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4E4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4E4u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4E5u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4E5u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4E6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4E6u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xE4E7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4E7u: /* 69 00 30 ADC #$3000 */
  word = 0x3000u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE4EAu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4EAu: /* 8D BE 1B STA $1BBE */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBEu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE4EDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4EDu: /* 7A PLY */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4EEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4EEu: /* B9 82 E8 LDA $E882,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE882u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4F1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4F1u: /* 8D BC 1B STA $1BBC */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBCu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE4F4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4F4u: /* B9 84 E8 LDA $E884,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE884u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4F7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E4F7u: /* 8D BA 1B STA $1BBA */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE4FAu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4FAu: /* B9 86 E8 LDA $E886,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE886u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE4FDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E4FDu: /* 8D C0 1B STA $1BC0 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC0u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE500u;
  instance->instruction_count++;
  return 1;
 case 0x0000E500u: /* 24 40 BIT $40 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x40u) & 0xFFFFu), &word)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
  tg_set_flag(instance, TG_P_N, (word & 0x8000u) != 0u);
  tg_set_flag(instance, TG_P_V, (word & 0x4000u) != 0u);
  instance->cpu.pc = 0xE502u;
  instance->instruction_count++;
  return 1;
 case 0x0000E502u: /* 10 04 BPL $00:E508 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xE508u : 0xE504u;
  instance->instruction_count++;
  return 1;
 case 0x0000E504u: /* 9C C0 1B STZ $1BC0 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC0u), 0u)) return 0;
  instance->cpu.pc = 0xE507u;
  instance->instruction_count++;
  return 1;
 case 0x0000E507u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000E508u: /* A2 00 04 LDX #$0400 */
  word = 0x0400u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE50Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E50Bu: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE50Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E50Cu: /* E9 00 04 SBC #$0400 */
  word = 0x0400u;
  tg_sbc16(instance, word);
  instance->cpu.pc = 0xE50Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E50Fu: /* B0 07 BCS $00:E518 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE518u : 0xE511u;
  instance->instruction_count++;
  return 1;
 case 0x0000E511u: /* 69 00 04 ADC #$0400 */
  word = 0x0400u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE514u;
  instance->instruction_count++;
  return 1;
 case 0x0000E514u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE515u;
  instance->instruction_count++;
  return 1;
 case 0x0000E515u: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE518u;
  instance->instruction_count++;
  return 1;
 case 0x0000E518u: /* 8D C0 1B STA $1BC0 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BC0u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE51Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E51Bu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xE51Du;
  instance->instruction_count++;
  return 1;
 case 0x0400E51Du: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xE51Fu;
  instance->instruction_count++;
  return 1;
 case 0x0400E51Fu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xE522u;
  instance->instruction_count++;
  return 1;
 case 0x0400E522u: /* AD BC 1B LDA $1BBC */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBCu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xE525u;
  instance->instruction_count++;
  return 1;
 case 0x0400E525u: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xE528u;
  instance->instruction_count++;
  return 1;
 case 0x0400E528u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xE52Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E52Au: /* A9 01 18 LDA #$1801 */
  word = 0x1801u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE52Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E52Du: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE530u;
  instance->instruction_count++;
  return 1;
 case 0x0000E530u: /* AD BA 1B LDA $1BBA */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE533u;
  instance->instruction_count++;
  return 1;
 case 0x0000E533u: /* 8D 72 43 STA $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE536u;
  instance->instruction_count++;
  return 1;
 case 0x0000E536u: /* 8E 75 43 STX $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xE539u;
  instance->instruction_count++;
  return 1;
 case 0x0000E539u: /* AD BE 1B LDA $1BBE */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBEu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE53Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E53Cu: /* 8D 16 21 STA $2116 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE53Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E53Fu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xE541u;
  instance->instruction_count++;
  return 1;
 case 0x0400E541u: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xE543u;
  instance->instruction_count++;
  return 1;
 case 0x0400E543u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xE546u;
  instance->instruction_count++;
  return 1;
 case 0x0400E546u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xE548u;
  instance->instruction_count++;
  return 1;
 case 0x0000E548u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE549u;
  instance->instruction_count++;
  return 1;
 case 0x0000E549u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xE54Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E54Au: /* 6D BA 1B ADC $1BBA */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE54Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E54Du: /* 8D BA 1B STA $1BBA */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBAu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE550u;
  instance->instruction_count++;
  return 1;
 case 0x0000E550u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE551u;
  instance->instruction_count++;
  return 1;
 case 0x0000E551u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE552u;
  instance->instruction_count++;
  return 1;
 case 0x0000E552u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xE553u;
  instance->instruction_count++;
  return 1;
 case 0x0000E553u: /* 6D BE 1B ADC $1BBE */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBEu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE556u;
  instance->instruction_count++;
  return 1;
 case 0x0000E556u: /* 8D BE 1B STA $1BBE */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BBEu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE559u;
  instance->instruction_count++;
  return 1;
 case 0x0000E559u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000E55Au: /* 24 53 BIT $53 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x53u) & 0xFFFFu), &word)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
  tg_set_flag(instance, TG_P_N, (word & 0x8000u) != 0u);
  tg_set_flag(instance, TG_P_V, (word & 0x4000u) != 0u);
  instance->cpu.pc = 0xE55Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E55Cu: /* 10 04 BPL $00:E562 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xE562u : 0xE55Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E55Eu: /* 9C 0E 1D STZ $1D0E */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Eu), 0u)) return 0;
  instance->cpu.pc = 0xE561u;
  instance->instruction_count++;
  return 1;
 case 0x0000E561u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000E562u: /* A5 59 LDA $59 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x59u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE564u;
  instance->instruction_count++;
  return 1;
 case 0x0000E564u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE565u;
  instance->instruction_count++;
  return 1;
 case 0x0000E565u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE566u;
  instance->instruction_count++;
  return 1;
 case 0x0000E566u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE567u;
  instance->instruction_count++;
  return 1;
 case 0x0000E567u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE568u;
  instance->instruction_count++;
  return 1;
 case 0x0000E568u: /* 29 FE FF AND #$FFFE */
  word = 0xFFFEu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE56Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E56Bu: /* 8D B8 1B STA $1BB8 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB8u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE56Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E56Eu: /* AC 34 1D LDY $1D34 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D34u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE571u;
  instance->instruction_count++;
  return 1;
 case 0x0000E571u: /* F0 38 BEQ $00:E5AB */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE5ABu : 0xE573u;
  instance->instruction_count++;
  return 1;
 case 0x0000E573u: /* A2 00 00 LDX #$0000 */
  word = 0x0000u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE576u;
  instance->instruction_count++;
  return 1;
 case 0x0000E576u: /* BD 46 1D LDA $1D46,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D46u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE579u;
  instance->instruction_count++;
  return 1;
 case 0x0000E579u: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE57Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E57Au: /* ED B8 1B SBC $1BB8 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB8u), &word)) return 0;
  tg_sbc16(instance, word);
  instance->cpu.pc = 0xE57Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E57Du: /* B0 03 BCS $00:E582 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE582u : 0xE57Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E57Fu: /* 6D B6 1B ADC $1BB6 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB6u), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE582u;
  instance->instruction_count++;
  return 1;
 case 0x0000E582u: /* C9 5A 00 CMP #$005A */
  word = 0x005Au;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE585u;
  instance->instruction_count++;
  return 1;
 case 0x0000E585u: /* 90 1F BCC $00:E5A6 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xE5A6u : 0xE587u;
  instance->instruction_count++;
  return 1;
 case 0x0000E587u: /* CE 34 1D DEC $1D34 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D34u), &word)) return 0;
  word = (uint16_t)(word - 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D34u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE58Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E58Au: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE58Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E58Bu: /* F0 1E BEQ $00:E5AB */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE5ABu : 0xE58Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E58Du: /* 5A PHY */
  if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
  instance->cpu.pc = 0xE58Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E58Eu: /* DA PHX */
  if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xE58Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E58Fu: /* BD 48 1D LDA $1D48,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D48u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE592u;
  instance->instruction_count++;
  return 1;
 case 0x0000E592u: /* 9D 46 1D STA $1D46,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D46u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE595u;
  instance->instruction_count++;
  return 1;
 case 0x0000E595u: /* BD 38 1D LDA $1D38,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D38u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE598u;
  instance->instruction_count++;
  return 1;
 case 0x0000E598u: /* 9D 36 1D STA $1D36,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D36u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE59Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E59Bu: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE59Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E59Cu: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE59Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E59Du: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE59Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E59Eu: /* D0 EF BNE $00:E58F */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE58Fu : 0xE5A0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5A0u: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5A1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5A1u: /* 7A PLY */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5A2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5A2u: /* D0 D2 BNE $00:E576 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE576u : 0xE5A4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5A4u: /* 80 05 BRA $00:E5AB */
  instance->cpu.pc = 0xE5ABu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5A6u: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5A7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5A7u: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5A8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5A8u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5A9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5A9u: /* D0 CB BNE $00:E576 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE576u : 0xE5ABu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5ABu: /* AD B8 1B LDA $1BB8 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1BB8u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5AEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5AEu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xE5AFu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5AFu: /* 69 50 00 ADC #$0050 */
  word = 0x0050u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE5B2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5B2u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE5B3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5B3u: /* A0 04 00 LDY #$0004 */
  word = 0x0004u;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5B6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5B6u: /* 5A PHY */
  if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
  instance->cpu.pc = 0xE5B7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5B7u: /* BF 00 64 7E LDA $7E6400,X */
  if (!tg_bus_read16(instance, ((0x7E6400u + instance->cpu.x) & 0xFFFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5BBu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5BBu: /* D0 03 BNE $00:E5C0 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE5C0u : 0xE5BDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5BDu: /* 4C 7D E6 JMP $E67D */
  instance->cpu.pc = 0xE67Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E5C0u: /* 10 66 BPL $00:E628 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xE628u : 0xE5C2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5C2u: /* 29 FE 3F AND #$3FFE */
  word = 0x3FFEu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5C5u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5C5u: /* A8 TAY */
  tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.y);
  instance->cpu.pc = 0xE5C6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5C6u: /* B9 88 E8 LDA $E888,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE888u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5C9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5C9u: /* A8 TAY */
  tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.y);
  instance->cpu.pc = 0xE5CAu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5CAu: /* B9 9A E8 LDA $E89A,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE89Au + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5CDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5CDu: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE5CEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5CEu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5CFu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5CFu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5D0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5D0u: /* B9 9A E8 LDA $E89A,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE89Au + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5D3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5D3u: /* 5A PHY */
  if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
  instance->cpu.pc = 0xE5D4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5D4u: /* DA PHX */
  if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xE5D5u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5D5u: /* AC 10 1D LDY $1D10 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D10u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5D8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5D8u: /* CC 12 1D CPY $1D12 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D12u), &word)) return 0;
  tg_compare16(instance, (uint16_t)instance->cpu.y, word);
  instance->cpu.pc = 0xE5DBu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5DBu: /* F0 17 BEQ $00:E5F4 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE5F4u : 0xE5DDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5DDu: /* D9 14 1D CMP $1D14,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D14u + instance->cpu.y)), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE5E0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5E0u: /* D0 07 BNE $00:E5E9 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE5E9u : 0xE5E2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5E2u: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5E3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5E3u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE5E4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5E4u: /* 99 24 1D STA $1D24,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D24u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE5E7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5E7u: /* 80 38 BRA $00:E621 */
  instance->cpu.pc = 0xE621u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5E9u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE5EAu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5EAu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5EBu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5EBu: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5ECu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5ECu: /* 98 TYA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.y);
  tg_set_nz16(instance, (uint16_t)instance->cpu.a);
  instance->cpu.pc = 0xE5EDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5EDu: /* 29 0E 00 AND #$000E */
  word = 0x000Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5F0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5F0u: /* A8 TAY */
  tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.y);
  instance->cpu.pc = 0xE5F1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5F1u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE5F2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5F2u: /* 80 E4 BRA $00:E5D8 */
  instance->cpu.pc = 0xE5D8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5F4u: /* AE 34 1D LDX $1D34 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D34u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5F7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5F7u: /* F0 14 BEQ $00:E60D */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE60Du : 0xE5F9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E5F9u: /* A0 00 00 LDY #$0000 */
  word = 0x0000u;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE5FCu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5FCu: /* D9 36 1D CMP $1D36,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D36u + instance->cpu.y)), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE5FFu;
  instance->instruction_count++;
  return 1;
 case 0x0000E5FFu: /* D0 07 BNE $00:E608 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE608u : 0xE601u;
  instance->instruction_count++;
  return 1;
 case 0x0000E601u: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE602u;
  instance->instruction_count++;
  return 1;
 case 0x0000E602u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE603u;
  instance->instruction_count++;
  return 1;
 case 0x0000E603u: /* 99 46 1D STA $1D46,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D46u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE606u;
  instance->instruction_count++;
  return 1;
 case 0x0000E606u: /* 80 19 BRA $00:E621 */
  instance->cpu.pc = 0xE621u;
  instance->instruction_count++;
  return 1;
 case 0x0000E608u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE609u;
  instance->instruction_count++;
  return 1;
 case 0x0000E609u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE60Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E60Au: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE60Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E60Bu: /* D0 EF BNE $00:E5FC */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE5FCu : 0xE60Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E60Du: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE60Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E60Eu: /* AC 12 1D LDY $1D12 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D12u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE611u;
  instance->instruction_count++;
  return 1;
 case 0x0000E611u: /* 99 14 1D STA $1D14,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D14u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE614u;
  instance->instruction_count++;
  return 1;
 case 0x0000E614u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE615u;
  instance->instruction_count++;
  return 1;
 case 0x0000E615u: /* 99 24 1D STA $1D24,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D24u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE618u;
  instance->instruction_count++;
  return 1;
 case 0x0000E618u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE619u;
  instance->instruction_count++;
  return 1;
 case 0x0000E619u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE61Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E61Au: /* 98 TYA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.y);
  tg_set_nz16(instance, (uint16_t)instance->cpu.a);
  instance->cpu.pc = 0xE61Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E61Bu: /* 29 0E 00 AND #$000E */
  word = 0x000Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE61Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E61Eu: /* 8D 12 1D STA $1D12 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D12u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE621u;
  instance->instruction_count++;
  return 1;
 case 0x0000E621u: /* 7A PLY */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE622u;
  instance->instruction_count++;
  return 1;
 case 0x0000E622u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE623u;
  instance->instruction_count++;
  return 1;
 case 0x0000E623u: /* 3A DEC A */
  word = (uint16_t)((instance->cpu.a) - 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE624u;
  instance->instruction_count++;
  return 1;
 case 0x0000E624u: /* D0 A7 BNE $00:E5CD */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE5CDu : 0xE626u;
  instance->instruction_count++;
  return 1;
 case 0x0000E626u: /* 80 55 BRA $00:E67D */
  instance->cpu.pc = 0xE67Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E628u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xE629u;
  instance->instruction_count++;
  return 1;
 case 0x0000E629u: /* 29 7E 00 AND #$007E */
  word = 0x007Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE62Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E62Cu: /* A8 TAY */
  tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.y);
  instance->cpu.pc = 0xE62Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E62Du: /* B9 BA E9 LDA $E9BA,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE9BAu + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE630u;
  instance->instruction_count++;
  return 1;
 case 0x0000E630u: /* DA PHX */
  if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xE631u;
  instance->instruction_count++;
  return 1;
 case 0x0000E631u: /* AC 10 1D LDY $1D10 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D10u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE634u;
  instance->instruction_count++;
  return 1;
 case 0x0000E634u: /* CC 12 1D CPY $1D12 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D12u), &word)) return 0;
  tg_compare16(instance, (uint16_t)instance->cpu.y, word);
  instance->cpu.pc = 0xE637u;
  instance->instruction_count++;
  return 1;
 case 0x0000E637u: /* F0 17 BEQ $00:E650 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE650u : 0xE639u;
  instance->instruction_count++;
  return 1;
 case 0x0000E639u: /* D9 14 1D CMP $1D14,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D14u + instance->cpu.y)), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE63Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E63Cu: /* D0 07 BNE $00:E645 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE645u : 0xE63Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E63Eu: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE63Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E63Fu: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE640u;
  instance->instruction_count++;
  return 1;
 case 0x0000E640u: /* 99 24 1D STA $1D24,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D24u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE643u;
  instance->instruction_count++;
  return 1;
 case 0x0000E643u: /* 80 38 BRA $00:E67D */
  instance->cpu.pc = 0xE67Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E645u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE646u;
  instance->instruction_count++;
  return 1;
 case 0x0000E646u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE647u;
  instance->instruction_count++;
  return 1;
 case 0x0000E647u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE648u;
  instance->instruction_count++;
  return 1;
 case 0x0000E648u: /* 98 TYA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.y);
  tg_set_nz16(instance, (uint16_t)instance->cpu.a);
  instance->cpu.pc = 0xE649u;
  instance->instruction_count++;
  return 1;
 case 0x0000E649u: /* 29 0E 00 AND #$000E */
  word = 0x000Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE64Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E64Cu: /* A8 TAY */
  tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.y);
  instance->cpu.pc = 0xE64Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E64Du: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE64Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E64Eu: /* 80 E4 BRA $00:E634 */
  instance->cpu.pc = 0xE634u;
  instance->instruction_count++;
  return 1;
 case 0x0000E650u: /* AE 34 1D LDX $1D34 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D34u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE653u;
  instance->instruction_count++;
  return 1;
 case 0x0000E653u: /* F0 14 BEQ $00:E669 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE669u : 0xE655u;
  instance->instruction_count++;
  return 1;
 case 0x0000E655u: /* A0 00 00 LDY #$0000 */
  word = 0x0000u;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE658u;
  instance->instruction_count++;
  return 1;
 case 0x0000E658u: /* D9 36 1D CMP $1D36,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D36u + instance->cpu.y)), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE65Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E65Bu: /* D0 07 BNE $00:E664 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE664u : 0xE65Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E65Du: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE65Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E65Eu: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE65Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E65Fu: /* 99 46 1D STA $1D46,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D46u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE662u;
  instance->instruction_count++;
  return 1;
 case 0x0000E662u: /* 80 19 BRA $00:E67D */
  instance->cpu.pc = 0xE67Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E664u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE665u;
  instance->instruction_count++;
  return 1;
 case 0x0000E665u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE666u;
  instance->instruction_count++;
  return 1;
 case 0x0000E666u: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE667u;
  instance->instruction_count++;
  return 1;
 case 0x0000E667u: /* D0 EF BNE $00:E658 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE658u : 0xE669u;
  instance->instruction_count++;
  return 1;
 case 0x0000E669u: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE66Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E66Au: /* AC 12 1D LDY $1D12 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D12u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE66Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E66Du: /* 99 14 1D STA $1D14,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D14u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE670u;
  instance->instruction_count++;
  return 1;
 case 0x0000E670u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE671u;
  instance->instruction_count++;
  return 1;
 case 0x0000E671u: /* 99 24 1D STA $1D24,Y */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D24u + instance->cpu.y)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE674u;
  instance->instruction_count++;
  return 1;
 case 0x0000E674u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE675u;
  instance->instruction_count++;
  return 1;
 case 0x0000E675u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE676u;
  instance->instruction_count++;
  return 1;
 case 0x0000E676u: /* 98 TYA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.y);
  tg_set_nz16(instance, (uint16_t)instance->cpu.a);
  instance->cpu.pc = 0xE677u;
  instance->instruction_count++;
  return 1;
 case 0x0000E677u: /* 29 0E 00 AND #$000E */
  word = 0x000Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE67Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E67Au: /* 8D 12 1D STA $1D12 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D12u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE67Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E67Du: /* 7A PLY */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE67Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E67Eu: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE67Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E67Fu: /* E8 INX */
  word = (uint16_t)(instance->cpu.x + 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE680u;
  instance->instruction_count++;
  return 1;
 case 0x0000E680u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE681u;
  instance->instruction_count++;
  return 1;
 case 0x0000E681u: /* F0 03 BEQ $00:E686 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE686u : 0xE683u;
  instance->instruction_count++;
  return 1;
 case 0x0000E683u: /* 4C B6 E5 JMP $E5B6 */
  instance->cpu.pc = 0xE5B6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E686u: /* AD 0E 1D LDA $1D0E */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Eu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE689u;
  instance->instruction_count++;
  return 1;
 case 0x0000E689u: /* F0 03 BEQ $00:E68E */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE68Eu : 0xE68Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E68Bu: /* 4C 30 E8 JMP $E830 */
  instance->cpu.pc = 0xE830u;
  instance->instruction_count++;
  return 1;
 case 0x0000E68Eu: /* AC 34 1D LDY $1D34 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D34u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE691u;
  instance->instruction_count++;
  return 1;
 case 0x0000E691u: /* D0 4E BNE $00:E6E1 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE6E1u : 0xE693u;
  instance->instruction_count++;
  return 1;
 case 0x0000E693u: /* AD 10 1D LDA $1D10 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D10u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE696u;
  instance->instruction_count++;
  return 1;
 case 0x0000E696u: /* CD 12 1D CMP $1D12 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D12u), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE699u;
  instance->instruction_count++;
  return 1;
 case 0x0000E699u: /* D0 03 BNE $00:E69E */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE69Eu : 0xE69Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E69Bu: /* 4C 89 E8 JMP $E889 */
  instance->cpu.pc = 0xE889u;
  instance->instruction_count++;
  return 1;
 case 0x0000E69Eu: /* EE 34 1D INC $1D34 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D34u), &word)) return 0;
  word = (uint16_t)(word + 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D34u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6A1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6A1u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE6A2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6A2u: /* 1A INC A */
  word = (uint16_t)((instance->cpu.a) + 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6A3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6A3u: /* 1A INC A */
  word = (uint16_t)((instance->cpu.a) + 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6A4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6A4u: /* 29 0E 00 AND #$000E */
  word = 0x000Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6A7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6A7u: /* 8D 10 1D STA $1D10 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D10u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE6AAu;
  instance->instruction_count++;
  return 1;
 case 0x0000E6AAu: /* BD 24 1D LDA $1D24,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D24u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6ADu;
  instance->instruction_count++;
  return 1;
 case 0x0000E6ADu: /* 8D 46 1D STA $1D46 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D46u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE6B0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6B0u: /* BD 14 1D LDA $1D14,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D14u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6B3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6B3u: /* 8D 36 1D STA $1D36 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D36u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE6B6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6B6u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE6B7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6B7u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6B8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6B8u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6B9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6B9u: /* A8 TAY */
  tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.y);
  instance->cpu.pc = 0xE6BAu;
  instance->instruction_count++;
  return 1;
 case 0x0000E6BAu: /* A9 00 40 LDA #$4000 */
  word = 0x4000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6BDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E6BDu: /* 8D 0C 1D STA $1D0C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Cu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE6C0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6C0u: /* B9 82 E8 LDA $E882,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE882u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6C3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6C3u: /* 8D 0A 1D STA $1D0A */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Au), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE6C6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6C6u: /* B9 84 E8 LDA $E884,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE884u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6C9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6C9u: /* 8D 08 1D STA $1D08 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE6CCu;
  instance->instruction_count++;
  return 1;
 case 0x0000E6CCu: /* B9 86 E8 LDA $E886,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE886u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6CFu;
  instance->instruction_count++;
  return 1;
 case 0x0000E6CFu: /* 8D 0E 1D STA $1D0E */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Eu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE6D2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6D2u: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6D5u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6D5u: /* 9D 56 1D STA $1D56,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D56u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE6D8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6D8u: /* B9 88 E8 LDA $E888,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE888u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6DBu;
  instance->instruction_count++;
  return 1;
 case 0x0000E6DBu: /* 9D D6 1D STA $1DD6,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1DD6u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE6DEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E6DEu: /* 4C 89 E8 JMP $E889 */
  instance->cpu.pc = 0xE889u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6E1u: /* C0 08 00 CPY #$0008 */
  word = 0x0008u;
  tg_compare16(instance, (uint16_t)instance->cpu.y, word);
  instance->cpu.pc = 0xE6E4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6E4u: /* D0 18 BNE $00:E6FE */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE6FEu : 0xE6E6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6E6u: /* AD 12 1D LDA $1D12 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D12u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6E9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6E9u: /* 8D 10 1D STA $1D10 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D10u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE6ECu;
  instance->instruction_count++;
  return 1;
 case 0x0000E6ECu: /* 4C 89 E8 JMP $E889 */
  instance->cpu.pc = 0xE889u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6EFu: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6F0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6F0u: /* AC 34 1D LDY $1D34 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D34u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6F3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6F3u: /* AD 10 1D LDA $1D10 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D10u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6F6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6F6u: /* 1A INC A */
  word = (uint16_t)((instance->cpu.a) + 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6F7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6F7u: /* 1A INC A */
  word = (uint16_t)((instance->cpu.a) + 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6F8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E6F8u: /* 29 0E 00 AND #$000E */
  word = 0x000Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE6FBu;
  instance->instruction_count++;
  return 1;
 case 0x0000E6FBu: /* 8D 10 1D STA $1D10 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D10u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE6FEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E6FEu: /* AE 10 1D LDX $1D10 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D10u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE701u;
  instance->instruction_count++;
  return 1;
 case 0x0000E701u: /* EC 12 1D CPX $1D12 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D12u), &word)) return 0;
  tg_compare16(instance, (uint16_t)instance->cpu.x, word);
  instance->cpu.pc = 0xE704u;
  instance->instruction_count++;
  return 1;
 case 0x0000E704u: /* D0 03 BNE $00:E709 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE709u : 0xE706u;
  instance->instruction_count++;
  return 1;
 case 0x0000E706u: /* 4C 89 E8 JMP $E889 */
  instance->cpu.pc = 0xE889u;
  instance->instruction_count++;
  return 1;
 case 0x0000E709u: /* BD 14 1D LDA $1D14,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D14u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE70Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E70Cu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE70Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E70Du: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE70Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E70Eu: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE70Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E70Fu: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE710u;
  instance->instruction_count++;
  return 1;
 case 0x0000E710u: /* BD 88 E8 LDA $E888,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE888u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE713u;
  instance->instruction_count++;
  return 1;
 case 0x0000E713u: /* 8D 08 1D STA $1D08 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE716u;
  instance->instruction_count++;
  return 1;
 case 0x0000E716u: /* AE 36 1D LDX $1D36 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D36u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE719u;
  instance->instruction_count++;
  return 1;
 case 0x0000E719u: /* BD 56 1D LDA $1D56,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D56u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE71Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E71Cu: /* CD 08 1D CMP $1D08 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE71Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E71Fu: /* 90 07 BCC $00:E728 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xE728u : 0xE721u;
  instance->instruction_count++;
  return 1;
 case 0x0000E721u: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE724u;
  instance->instruction_count++;
  return 1;
 case 0x0000E724u: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE725u;
  instance->instruction_count++;
  return 1;
 case 0x0000E725u: /* 4C D3 E7 JMP $E7D3 */
  instance->cpu.pc = 0xE7D3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E728u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE729u;
  instance->instruction_count++;
  return 1;
 case 0x0000E729u: /* D0 03 BNE $00:E72E */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE72Eu : 0xE72Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E72Bu: /* 4C B9 E7 JMP $E7B9 */
  instance->cpu.pc = 0xE7B9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E72Eu: /* BD D6 1D LDA $1DD6,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1DD6u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE731u;
  instance->instruction_count++;
  return 1;
 case 0x0000E731u: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE732u;
  instance->instruction_count++;
  return 1;
 case 0x0000E732u: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE735u;
  instance->instruction_count++;
  return 1;
 case 0x0000E735u: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE736u;
  instance->instruction_count++;
  return 1;
 case 0x0000E736u: /* AE 38 1D LDX $1D38 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D38u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE739u;
  instance->instruction_count++;
  return 1;
 case 0x0000E739u: /* 7D 56 1D ADC $1D56,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D56u + instance->cpu.x)), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE73Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E73Cu: /* CD 08 1D CMP $1D08 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE73Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E73Fu: /* 90 03 BCC $00:E744 */
  instance->cpu.pc = !tg_flag(instance, TG_P_C) ? 0xE744u : 0xE741u;
  instance->instruction_count++;
  return 1;
 case 0x0000E741u: /* 4C D3 E7 JMP $E7D3 */
  instance->cpu.pc = 0xE7D3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E744u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE745u;
  instance->instruction_count++;
  return 1;
 case 0x0000E745u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE746u;
  instance->instruction_count++;
  return 1;
 case 0x0000E746u: /* F0 71 BEQ $00:E7B9 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE7B9u : 0xE748u;
  instance->instruction_count++;
  return 1;
 case 0x0000E748u: /* BD D6 1D LDA $1DD6,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1DD6u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE74Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E74Bu: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE74Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E74Cu: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE74Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E74Fu: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE750u;
  instance->instruction_count++;
  return 1;
 case 0x0000E750u: /* AE 3A 1D LDX $1D3A */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D3Au), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE753u;
  instance->instruction_count++;
  return 1;
 case 0x0000E753u: /* 7D 56 1D ADC $1D56,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D56u + instance->cpu.x)), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE756u;
  instance->instruction_count++;
  return 1;
 case 0x0000E756u: /* CD 08 1D CMP $1D08 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE759u;
  instance->instruction_count++;
  return 1;
 case 0x0000E759u: /* B0 78 BCS $00:E7D3 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE7D3u : 0xE75Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E75Bu: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE75Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E75Cu: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE75Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E75Du: /* F0 5A BEQ $00:E7B9 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE7B9u : 0xE75Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E75Fu: /* BD D6 1D LDA $1DD6,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1DD6u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE762u;
  instance->instruction_count++;
  return 1;
 case 0x0000E762u: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE763u;
  instance->instruction_count++;
  return 1;
 case 0x0000E763u: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE766u;
  instance->instruction_count++;
  return 1;
 case 0x0000E766u: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE767u;
  instance->instruction_count++;
  return 1;
 case 0x0000E767u: /* AE 3C 1D LDX $1D3C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D3Cu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE76Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E76Au: /* 7D 56 1D ADC $1D56,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D56u + instance->cpu.x)), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE76Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E76Du: /* CD 08 1D CMP $1D08 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE770u;
  instance->instruction_count++;
  return 1;
 case 0x0000E770u: /* B0 61 BCS $00:E7D3 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE7D3u : 0xE772u;
  instance->instruction_count++;
  return 1;
 case 0x0000E772u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE773u;
  instance->instruction_count++;
  return 1;
 case 0x0000E773u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE774u;
  instance->instruction_count++;
  return 1;
 case 0x0000E774u: /* F0 43 BEQ $00:E7B9 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE7B9u : 0xE776u;
  instance->instruction_count++;
  return 1;
 case 0x0000E776u: /* BD D6 1D LDA $1DD6,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1DD6u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE779u;
  instance->instruction_count++;
  return 1;
 case 0x0000E779u: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE77Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E77Au: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE77Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E77Du: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE77Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E77Eu: /* AE 3E 1D LDX $1D3E */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D3Eu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE781u;
  instance->instruction_count++;
  return 1;
 case 0x0000E781u: /* 7D 56 1D ADC $1D56,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D56u + instance->cpu.x)), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE784u;
  instance->instruction_count++;
  return 1;
 case 0x0000E784u: /* CD 08 1D CMP $1D08 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE787u;
  instance->instruction_count++;
  return 1;
 case 0x0000E787u: /* B0 4A BCS $00:E7D3 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE7D3u : 0xE789u;
  instance->instruction_count++;
  return 1;
 case 0x0000E789u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE78Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E78Au: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE78Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E78Bu: /* F0 2C BEQ $00:E7B9 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE7B9u : 0xE78Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E78Du: /* BD D6 1D LDA $1DD6,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1DD6u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE790u;
  instance->instruction_count++;
  return 1;
 case 0x0000E790u: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE791u;
  instance->instruction_count++;
  return 1;
 case 0x0000E791u: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE794u;
  instance->instruction_count++;
  return 1;
 case 0x0000E794u: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE795u;
  instance->instruction_count++;
  return 1;
 case 0x0000E795u: /* AE 40 1D LDX $1D40 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D40u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE798u;
  instance->instruction_count++;
  return 1;
 case 0x0000E798u: /* 7D 56 1D ADC $1D56,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D56u + instance->cpu.x)), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE79Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E79Bu: /* CD 08 1D CMP $1D08 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE79Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E79Eu: /* B0 33 BCS $00:E7D3 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE7D3u : 0xE7A0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7A0u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7A1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7A1u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7A2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7A2u: /* F0 15 BEQ $00:E7B9 */
  instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0xE7B9u : 0xE7A4u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7A4u: /* BD D6 1D LDA $1DD6,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1DD6u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7A7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7A7u: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE7A8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7A8u: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7ABu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7ABu: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE7ACu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7ACu: /* AE 42 1D LDX $1D42 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D42u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7AFu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7AFu: /* 7D 56 1D ADC $1D56,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D56u + instance->cpu.x)), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE7B2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7B2u: /* CD 08 1D CMP $1D08 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE7B5u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7B5u: /* B0 1C BCS $00:E7D3 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE7D3u : 0xE7B7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7B7u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7B8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7B8u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7B9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7B9u: /* A9 00 01 LDA #$0100 */
  word = 0x0100u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7BCu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7BCu: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE7BDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7BDu: /* FD D6 1D SBC $1DD6,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1DD6u + instance->cpu.x)), &word)) return 0;
  tg_sbc16(instance, word);
  instance->cpu.pc = 0xE7C0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7C0u: /* CD 08 1D CMP $1D08 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), &word)) return 0;
  tg_compare16(instance, instance->cpu.a, word);
  instance->cpu.pc = 0xE7C3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7C3u: /* B0 03 BCS $00:E7C8 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE7C8u : 0xE7C5u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7C5u: /* 4C EF E6 JMP $E6EF */
  instance->cpu.pc = 0xE6EFu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7C8u: /* BD D6 1D LDA $1DD6,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1DD6u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7CBu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7CBu: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE7CCu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7CCu: /* AD 34 1D LDA $1D34 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D34u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7CFu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7CFu: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7D0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7D0u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE7D1u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7D1u: /* 80 16 BRA $00:E7E9 */
  instance->cpu.pc = 0xE7E9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7D3u: /* AD 34 1D LDA $1D34 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D34u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7D6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7D6u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7D7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7D7u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE7D8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7D8u: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7D9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7D9u: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7DAu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7DAu: /* BD 36 1D LDA $1D36,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D36u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7DDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7DDu: /* 9D 38 1D STA $1D38,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D38u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE7E0u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7E0u: /* BD 46 1D LDA $1D46,X */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D46u + instance->cpu.x)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7E3u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7E3u: /* 9D 48 1D STA $1D48,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D48u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE7E6u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7E6u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7E7u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7E7u: /* D0 EF BNE $00:E7D8 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xE7D8u : 0xE7E9u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7E9u: /* AD 10 1D LDA $1D10 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D10u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7ECu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7ECu: /* A8 TAY */
  tg_set_index16(instance, &instance->cpu.y, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.y);
  instance->cpu.pc = 0xE7EDu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7EDu: /* 1A INC A */
  word = (uint16_t)((instance->cpu.a) + 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7EEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7EEu: /* 1A INC A */
  word = (uint16_t)((instance->cpu.a) + 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7EFu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7EFu: /* 29 0E 00 AND #$000E */
  word = 0x000Eu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7F2u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7F2u: /* 8D 10 1D STA $1D10 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D10u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE7F5u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7F5u: /* EE 34 1D INC $1D34 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D34u), &word)) return 0;
  word = (uint16_t)(word + 1u);
  if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D34u), word)) return 0;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7F8u;
  instance->instruction_count++;
  return 1;
 case 0x0000E7F8u: /* B9 24 1D LDA $1D24,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D24u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE7FBu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7FBu: /* 9D 46 1D STA $1D46,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D46u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE7FEu;
  instance->instruction_count++;
  return 1;
 case 0x0000E7FEu: /* B9 14 1D LDA $1D14,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D14u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE801u;
  instance->instruction_count++;
  return 1;
 case 0x0000E801u: /* 9D 36 1D STA $1D36,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D36u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE804u;
  instance->instruction_count++;
  return 1;
 case 0x0000E804u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE805u;
  instance->instruction_count++;
  return 1;
 case 0x0000E805u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE806u;
  instance->instruction_count++;
  return 1;
 case 0x0000E806u: /* 9D 56 1D STA $1D56,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1D56u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE809u;
  instance->instruction_count++;
  return 1;
 case 0x0000E809u: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE80Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E80Au: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xE80Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E80Bu: /* 6D 08 1D ADC $1D08 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE80Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E80Eu: /* 9D D6 1D STA $1DD6,X */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x1DD6u + instance->cpu.x)), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE811u;
  instance->instruction_count++;
  return 1;
 case 0x0000E811u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE812u;
  instance->instruction_count++;
  return 1;
 case 0x0000E812u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE813u;
  instance->instruction_count++;
  return 1;
 case 0x0000E813u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE814u;
  instance->instruction_count++;
  return 1;
 case 0x0000E814u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE815u;
  instance->instruction_count++;
  return 1;
 case 0x0000E815u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE816u;
  instance->instruction_count++;
  return 1;
 case 0x0000E816u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xE817u;
  instance->instruction_count++;
  return 1;
 case 0x0000E817u: /* 69 00 40 ADC #$4000 */
  word = 0x4000u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE81Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E81Au: /* 8D 0C 1D STA $1D0C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Cu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE81Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E81Du: /* 7A PLY */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE81Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000E81Eu: /* B9 82 E8 LDA $E882,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE882u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE821u;
  instance->instruction_count++;
  return 1;
 case 0x0000E821u: /* 8D 0A 1D STA $1D0A */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Au), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE824u;
  instance->instruction_count++;
  return 1;
 case 0x0000E824u: /* B9 84 E8 LDA $E884,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE884u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE827u;
  instance->instruction_count++;
  return 1;
 case 0x0000E827u: /* 8D 08 1D STA $1D08 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE82Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E82Au: /* B9 86 E8 LDA $E886,Y */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0xE886u + instance->cpu.y)), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE82Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E82Du: /* 8D 0E 1D STA $1D0E */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Eu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE830u;
  instance->instruction_count++;
  return 1;
 case 0x0000E830u: /* 24 53 BIT $53 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x53u) & 0xFFFFu), &word)) return 0;
  tg_set_flag(instance, TG_P_Z, ((uint16_t)instance->cpu.a & word) == 0u);
  tg_set_flag(instance, TG_P_N, (word & 0x8000u) != 0u);
  tg_set_flag(instance, TG_P_V, (word & 0x4000u) != 0u);
  instance->cpu.pc = 0xE832u;
  instance->instruction_count++;
  return 1;
 case 0x0000E832u: /* 10 04 BPL $00:E838 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xE838u : 0xE834u;
  instance->instruction_count++;
  return 1;
 case 0x0000E834u: /* 9C 0E 1D STZ $1D0E */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Eu), 0u)) return 0;
  instance->cpu.pc = 0xE837u;
  instance->instruction_count++;
  return 1;
 case 0x0000E837u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000E838u: /* A2 00 04 LDX #$0400 */
  word = 0x0400u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE83Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E83Bu: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xE83Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E83Cu: /* E9 00 04 SBC #$0400 */
  word = 0x0400u;
  tg_sbc16(instance, word);
  instance->cpu.pc = 0xE83Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E83Fu: /* B0 07 BCS $00:E848 */
  instance->cpu.pc = tg_flag(instance, TG_P_C) ? 0xE848u : 0xE841u;
  instance->instruction_count++;
  return 1;
 case 0x0000E841u: /* 69 00 04 ADC #$0400 */
  word = 0x0400u;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE844u;
  instance->instruction_count++;
  return 1;
 case 0x0000E844u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE845u;
  instance->instruction_count++;
  return 1;
 case 0x0000E845u: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE848u;
  instance->instruction_count++;
  return 1;
 case 0x0000E848u: /* 8D 0E 1D STA $1D0E */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Eu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE84Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000E84Bu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xE84Du;
  instance->instruction_count++;
  return 1;
 case 0x0400E84Du: /* A9 00 LDA #$00 */
  byte = 0x00u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xE84Fu;
  instance->instruction_count++;
  return 1;
 case 0x0400E84Fu: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xE852u;
  instance->instruction_count++;
  return 1;
 case 0x0400E852u: /* AD 0A 1D LDA $1D0A */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Au), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xE855u;
  instance->instruction_count++;
  return 1;
 case 0x0400E855u: /* 8D 74 43 STA $4374 */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4374u), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xE858u;
  instance->instruction_count++;
  return 1;
 case 0x0400E858u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xE85Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E85Au: /* A9 01 18 LDA #$1801 */
  word = 0x1801u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE85Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E85Du: /* 8D 70 43 STA $4370 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4370u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE860u;
  instance->instruction_count++;
  return 1;
 case 0x0000E860u: /* AD 08 1D LDA $1D08 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE863u;
  instance->instruction_count++;
  return 1;
 case 0x0000E863u: /* 8D 72 43 STA $4372 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4372u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE866u;
  instance->instruction_count++;
  return 1;
 case 0x0000E866u: /* 8E 75 43 STX $4375 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4375u), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xE869u;
  instance->instruction_count++;
  return 1;
 case 0x0000E869u: /* AD 0C 1D LDA $1D0C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Cu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE86Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000E86Cu: /* 8D 16 21 STA $2116 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2116u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE86Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000E86Fu: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xE871u;
  instance->instruction_count++;
  return 1;
 case 0x0400E871u: /* A9 80 LDA #$80 */
  byte = 0x80u;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xE873u;
  instance->instruction_count++;
  return 1;
 case 0x0400E873u: /* 8D 0B 42 STA $420B */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xE876u;
  instance->instruction_count++;
  return 1;
 case 0x0400E876u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xE878u;
  instance->instruction_count++;
  return 1;
 case 0x0000E878u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE879u;
  instance->instruction_count++;
  return 1;
 case 0x0000E879u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xE87Au;
  instance->instruction_count++;
  return 1;
 case 0x0000E87Au: /* 6D 08 1D ADC $1D08 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE87Du;
  instance->instruction_count++;
  return 1;
 case 0x0000E87Du: /* 8D 08 1D STA $1D08 */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D08u), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE880u;
  instance->instruction_count++;
  return 1;
 case 0x0000E880u: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xE881u;
  instance->instruction_count++;
  return 1;
 case 0x0000E881u: /* 4A LSR A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 1u) != 0u);
  word = (uint16_t)(word >> 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xE882u;
  instance->instruction_count++;
  return 1;
 case 0x0000E882u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xE883u;
  instance->instruction_count++;
  return 1;
 case 0x0000E883u: /* 6D 0C 1D ADC $1D0C */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Cu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xE886u;
  instance->instruction_count++;
  return 1;
 case 0x0000E886u: /* 8D 0C 1D STA $1D0C */
  if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1D0Cu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xE889u;
  instance->instruction_count++;
  return 1;
 case 0x0000E889u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x0000EC1Au: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xEC1Cu;
  instance->instruction_count++;
  return 1;
 case 0x0200EC1Au: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xEC1Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400EC1Au: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xEC1Cu;
  instance->instruction_count++;
  return 1;
 case 0x0600EC1Au: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xEC1Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000EC1Cu: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xEC1Du;
  instance->instruction_count++;
  return 1;
 case 0x0000EC1Du: /* DA PHX */
  if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xEC1Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000EC1Eu: /* 5A PHY */
  if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
  instance->cpu.pc = 0xEC1Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000EC1Fu: /* 0B PHD */
  if (!tg_push16(instance, instance->cpu.d)) return 0;
  instance->cpu.pc = 0xEC20u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC20u: /* 8B PHB */
  if (!tg_push8(instance, instance->cpu.dbr)) return 0;
  instance->cpu.pc = 0xEC21u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC21u: /* 4B PHK */
  if (!tg_push8(instance, instance->cpu.pbr)) return 0;
  instance->cpu.pc = 0xEC22u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC22u: /* AB PLB */
  if (!tg_pull8(instance, &byte)) return 0;
  instance->cpu.dbr = byte;
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xEC23u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC23u: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC26u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC26u: /* 5B TCD */
  instance->cpu.d = instance->cpu.a;
  tg_set_nz16(instance, instance->cpu.d);
  instance->cpu.pc = 0xEC27u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC27u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xEC29u;
  instance->instruction_count++;
  return 1;
 case 0x0400EC29u: /* AD 10 42 LDA $4210 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4210u), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xEC2Cu;
  instance->instruction_count++;
  return 1;
 case 0x0400EC2Cu: /* AD 12 42 LDA $4212 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4212u), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xEC2Fu;
  instance->instruction_count++;
  return 1;
 case 0x0400EC2Fu: /* 29 01 AND #$01 */
  byte = 0x01u;
  byte = (uint8_t)((tg_acc8(instance)) & byte);
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xEC31u;
  instance->instruction_count++;
  return 1;
 case 0x0400EC31u: /* D0 F9 BNE $00:EC2C */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEC2Cu : 0xEC33u;
  instance->instruction_count++;
  return 1;
 case 0x0400EC33u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xEC35u;
  instance->instruction_count++;
  return 1;
 /* Controller 1 poll.  $4218 supplies the 16-bit auto-joy result.  The handler
    stores the current held mask at DP $10-$11, then computes the game's
    new/unconsumed-input latch at $14-$15 as:
        current & (~previous | previous_latch)
    Headless Test 04 proves all four directional bits in $10-$11. */
 case 0x0000EC35u: /* AE 18 42 LDX $4218 */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4218u), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC38u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC38u: /* A5 10 LDA $10 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x10u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC3Au;
  instance->instruction_count++;
  return 1;
 case 0x0000EC3Au: /* 86 10 STX $10 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x10u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xEC3Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000EC3Cu: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC3Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000EC3Fu: /* 05 14 ORA $14 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x14u) & 0xFFFFu), &word)) return 0;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC41u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC41u: /* 25 10 AND $10 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x10u) & 0xFFFFu), &word)) return 0;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC43u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC43u: /* 85 14 STA $14 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x14u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xEC45u;
  instance->instruction_count++;
  return 1;
 /* Controller 2 mirrors Controller 1: $421A -> held mask DP $12-$13, with
    its new/unconsumed-input latch at $16-$17.  Test 04 independently drives
    P2 Right from a matched race snapshot and observes the exact SNES mask
    $0100, stored as $12=$00/$13=$01. */
 case 0x0000EC45u: /* AE 1A 42 LDX $421A */
  if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x421Au), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC48u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC48u: /* A5 12 LDA $12 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x12u) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC4Au;
  instance->instruction_count++;
  return 1;
 case 0x0000EC4Au: /* 86 12 STX $12 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x12u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xEC4Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000EC4Cu: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC4Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000EC4Fu: /* 05 16 ORA $16 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x16u) & 0xFFFFu), &word)) return 0;
  word = (uint16_t)((instance->cpu.a) | word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC51u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC51u: /* 25 12 AND $12 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x12u) & 0xFFFFu), &word)) return 0;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC53u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC53u: /* 85 16 STA $16 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x16u) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xEC55u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC55u: /* AB PLB */
  if (!tg_pull8(instance, &byte)) return 0;
  instance->cpu.dbr = byte;
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xEC56u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC56u: /* 2B PLD */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.d = word;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC57u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC57u: /* 7A PLY */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC58u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC58u: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC59u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC59u: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC5Au;
  instance->instruction_count++;
  return 1;
 case 0x0000EC5Au: /* 40 RTI */
  if (!tg_pull8(instance, &byte)) return 0;
  instance->cpu.p = byte;
  if (instance->cpu.e) { instance->cpu.p |= (TG_P_M | TG_P_X); instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; } else if (instance->cpu.p & TG_P_X) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = word;
  if (!instance->cpu.e) { if (!tg_pull8(instance, &byte)) return 0; instance->cpu.pbr = byte; } else instance->cpu.pbr = 0u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC5Bu: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xEC5Du;
  instance->instruction_count++;
  return 1;
 case 0x0200EC5Bu: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xEC5Du;
  instance->instruction_count++;
  return 1;
 case 0x0400EC5Bu: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xEC5Du;
  instance->instruction_count++;
  return 1;
 case 0x0600EC5Bu: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xEC5Du;
  instance->instruction_count++;
  return 1;
 case 0x0000EC5Du: /* 48 PHA */
  if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
  instance->cpu.pc = 0xEC5Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000EC5Eu: /* DA PHX */
  if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xEC5Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000EC5Fu: /* 5A PHY */
  if (!tg_push16(instance, (uint16_t)instance->cpu.y)) return 0;
  instance->cpu.pc = 0xEC60u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC60u: /* 0B PHD */
  if (!tg_push16(instance, instance->cpu.d)) return 0;
  instance->cpu.pc = 0xEC61u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC61u: /* 8B PHB */
  if (!tg_push8(instance, instance->cpu.dbr)) return 0;
  instance->cpu.pc = 0xEC62u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC62u: /* 4B PHK */
  if (!tg_push8(instance, instance->cpu.pbr)) return 0;
  instance->cpu.pc = 0xEC63u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC63u: /* AB PLB */
  if (!tg_pull8(instance, &byte)) return 0;
  instance->cpu.dbr = byte;
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xEC64u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC64u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xEC66u;
  instance->instruction_count++;
  return 1;
 case 0x0400EC66u: /* AD 11 42 LDA $4211 */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4211u), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xEC69u;
  instance->instruction_count++;
  return 1;
 case 0x0400EC69u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xEC6Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000EC6Bu: /* A9 00 00 LDA #$0000 */
  word = 0x0000u;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC6Eu;
  instance->instruction_count++;
  return 1;
 case 0x0000EC6Eu: /* 5B TCD */
  instance->cpu.d = instance->cpu.a;
  tg_set_nz16(instance, instance->cpu.d);
  instance->cpu.pc = 0xEC6Fu;
  instance->instruction_count++;
  return 1;
 case 0x0000EC6Fu: /* A2 00 00 LDX #$0000 */
  word = 0x0000u;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC72u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC72u: /* FC 0A 00 JSR ($000A,X) */
  address = ((uint32_t)instance->cpu.pbr << 16) | (uint16_t)(0x000Au + instance->cpu.x);
  if (!tg_bus_read16(instance, address, &word)) return 0;
  if (!(word==0xEC7Eu || word==0xB511u || word==0xB4C4u || word==0xB57Bu || word==0xB5B6u || word==0xB5E2u || word==0xB6D1u)) return tg_fail_frontier(instance, "Version 22 $000A raster IRQ indirect JSR target is outside its ROM-proved finite set.", NULL);
  if (!tg_push16(instance, 0xEC74u)) return 0;
  instance->cpu.pc = word;
  instance->instruction_count++;
  return 1;
 case 0x0000EC75u: /* C2 30 REP #$30 */
  instance->cpu.p &= (uint8_t)~0x30u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xEC77u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC77u: /* AB PLB */
  if (!tg_pull8(instance, &byte)) return 0;
  instance->cpu.dbr = byte;
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xEC78u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC78u: /* 2B PLD */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.d = word;
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC79u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC79u: /* 7A PLY */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC7Au;
  instance->instruction_count++;
  return 1;
 case 0x0000EC7Au: /* FA PLX */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC7Bu;
  instance->instruction_count++;
  return 1;
 case 0x0000EC7Bu: /* 68 PLA */
  if (!tg_pull16(instance, &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC7Cu;
  instance->instruction_count++;
  return 1;
 case 0x0000EC7Cu: /* 40 RTI */
  if (!tg_pull8(instance, &byte)) return 0;
  instance->cpu.p = byte;
  if (instance->cpu.e) { instance->cpu.p |= (TG_P_M | TG_P_X); instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; } else if (instance->cpu.p & TG_P_X) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = word;
  if (!instance->cpu.e) { if (!tg_pull8(instance, &byte)) return 0; instance->cpu.pbr = byte; } else instance->cpu.pbr = 0u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC7Eu: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 default:return tg_fail_frontier(instance,"Unknown Version 22 later interrupt fixed context.",NULL);
 }}
