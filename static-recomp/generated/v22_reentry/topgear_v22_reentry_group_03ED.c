/* Generated Version 22 ROM re-entry shard. */
#include "topgear_internal.h"
#include "topgear_v22_reentry_shards.h"

int tg_v22_reentry_group_03ED_has(uint32_t key){switch(key){
 case 0x040FB41Eu:return 1;
 case 0x040FB420u:return 1;
 case 0x040FB423u:return 1;
 case 0x040FB424u:return 1;
 case 0x040FB426u:return 1;
 case 0x040FB429u:return 1;
 case 0x040FB42Bu:return 1;
 case 0x040FB404u:return 1;
 case 0x040FB42Du:return 1;
 case 0x040FB41Au:return 1;
 case 0x040FB431u:return 1;
 case 0x040FB406u:return 1;
 case 0x040FB42Fu:return 1;
 case 0x040FB41Cu:return 1;
 case 0x000FB433u:return 1;
 case 0x040FB40Bu:return 1;
 case 0x040FB408u:return 1;
 case 0x040FB430u:return 1;
 case 0x040FB41Du:return 1;
 case 0x000FB434u:return 1;
 case 0x040FB40Du:return 1;
 case 0x040FB409u:return 1;
 case 0x000FB435u:return 1;
 case 0x040FB410u:return 1;
 case 0x000FB436u:return 1;
 case 0x040FB411u:return 1;
 case 0x000FB437u:return 1;
 case 0x040FB413u:return 1;
 case 0x040FB416u:return 1;
 case 0x000FB438u:return 1;
 case 0x040FB418u:return 1;
 case 0x000FB43Bu:return 1;
 case 0x040FB419u:return 1;
 case 0x000FB43Cu:return 1;
 case 0x000FB43Eu:return 1;
 case 0x000FB43Fu:return 1;
 case 0x000FB442u:return 1;
 case 0x000FB444u:return 1;
 case 0x000FB445u:return 1;
 case 0x000FB402u:return 1;
 case 0x000FB447u:return 1;
 case 0x000FB448u:return 1;
 case 0x000FB44Au:return 1;
 case 0x000FB44Du:return 1;
 case 0x000FB44Eu:return 1;
 case 0x000FB450u:return 1;
 case 0x040FB452u:return 1;
 case 0x040FB455u:return 1;
 case 0x040FB458u:return 1;
 case 0x040FB45Au:return 1;
 case 0x040FB462u:return 1;
 case 0x040FB463u:return 1;
 case 0x040FB465u:return 1;
 case 0x040FB468u:return 1;
 case 0x040FB469u:return 1;
 case 0x040FB46Bu:return 1;
 case 0x040FB46Eu:return 1;
 case 0x040FB470u:return 1;
 case 0x040FB472u:return 1;
 case 0x040FB45Cu:return 1;
 case 0x040FB474u:return 1;
 case 0x040FB45Fu:return 1;
 case 0x040FB476u:return 1;
 case 0x040FB477u:return 1;
 case 0x040FB479u:return 1;
 case 0x040FB47Cu:return 1;
 case 0x040FB47Eu:return 1;
 case 0x040FB480u:return 1;
 case 0x040FB481u:return 1;
 default:return 0;}}
int tg_v22_reentry_group_03ED_step(struct TopGearRecomp *instance){
 uint32_t key,address=0u,base24=0u;uint16_t word=0u;uint8_t byte=0u;
 if(!instance)return 0;
 (void)address;(void)base24;(void)word;(void)byte;
 key=tg_generated_context_key(instance);switch(key){
 case 0x040FB41Eu: /* A6 30 LDX $30 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x30u) & 0xFFFFu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB420u;
  instance->instruction_count++;
  return 1;
 case 0x040FB420u: /* BD 4C 04 LDA $044C,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x044Cu + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB423u;
  instance->instruction_count++;
  return 1;
 case 0x040FB423u: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB424u;
  instance->instruction_count++;
  return 1;
 case 0x040FB424u: /* 10 03 BPL $0F:B429 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB429u : 0xB426u;
  instance->instruction_count++;
  return 1;
 case 0x040FB426u: /* A2 FF 07 LDX #$07FF */
  word = 0x07FFu;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB429u;
  instance->instruction_count++;
  return 1;
 case 0x040FB429u: /* E4 32 CPX $32 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
  tg_compare16(instance, (uint16_t)instance->cpu.x, word);
  instance->cpu.pc = 0xB42Bu;
  instance->instruction_count++;
  return 1;
 case 0x040FB42Bu: /* D0 ED BNE $0F:B41A */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xB41Au : 0xB42Du;
  instance->instruction_count++;
  return 1;
 case 0x040FB404u: /* A4 34 LDY $34 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x34u) & 0xFFFFu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB406u;
  instance->instruction_count++;
  return 1;
 case 0x040FB42Du: /* 64 36 STZ $36 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x36u) & 0xFFFFu), 0u)) return 0;
  instance->cpu.pc = 0xB42Fu;
  instance->instruction_count++;
  return 1;
 case 0x040FB41Au: /* 86 30 STX $30 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x30u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xB41Cu;
  instance->instruction_count++;
  return 1;
 case 0x040FB431u: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB433u;
  instance->instruction_count++;
  return 1;
 case 0x040FB406u: /* B7 37 LDA [$37],Y */
  if (!tg_bus_read24(instance, (uint32_t)((instance->cpu.d + 0x37u) & 0xFFFFu), &base24)) return 0;
  address = (base24 + instance->cpu.y) & 0xFFFFFFu;
  if (!tg_bus_read8(instance, address, &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB408u;
  instance->instruction_count++;
  return 1;
 case 0x040FB42Fu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xB430u;
  instance->instruction_count++;
  return 1;
 case 0x040FB41Cu: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xB41Du;
  instance->instruction_count++;
  return 1;
 case 0x000FB433u: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xB434u;
  instance->instruction_count++;
  return 1;
 case 0x040FB40Bu: /* A6 32 LDX $32 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB40Du;
  instance->instruction_count++;
  return 1;
 case 0x040FB408u: /* C8 INY */
  word = (uint16_t)(instance->cpu.y + 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB409u;
  instance->instruction_count++;
  return 1;
 case 0x040FB430u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x040FB41Du: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x000FB434u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB435u;
  instance->instruction_count++;
  return 1;
 case 0x040FB40Du: /* 9D 4C 04 STA $044C,X */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x044Cu + instance->cpu.x)), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB410u;
  instance->instruction_count++;
  return 1;
 case 0x040FB409u: /* 84 34 STY $34 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x34u) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
  instance->cpu.pc = 0xB40Bu;
  instance->instruction_count++;
  return 1;
 case 0x000FB435u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB436u;
  instance->instruction_count++;
  return 1;
 case 0x040FB410u: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB411u;
  instance->instruction_count++;
  return 1;
 case 0x000FB436u: /* 0A ASL A */
  word = instance->cpu.a;
  tg_set_flag(instance, TG_P_C, (word & 0x8000u) != 0u);
  word = (uint16_t)(word << 1);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB437u;
  instance->instruction_count++;
  return 1;
 case 0x040FB411u: /* 10 03 BPL $0F:B416 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB416u : 0xB413u;
  instance->instruction_count++;
  return 1;
 case 0x000FB437u: /* EB XBA */
  word = instance->cpu.a;
  instance->cpu.a = (uint16_t)((word << 8) | (word >> 8));
  tg_set_nz8(instance, (uint8_t)instance->cpu.a);
  instance->cpu.pc = 0xB438u;
  instance->instruction_count++;
  return 1;
 case 0x040FB413u: /* A2 FF 07 LDX #$07FF */
  word = 0x07FFu;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB416u;
  instance->instruction_count++;
  return 1;
 case 0x040FB416u: /* 86 32 STX $32 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xB418u;
  instance->instruction_count++;
  return 1;
 case 0x000FB438u: /* 29 01 00 AND #$0001 */
  word = 0x0001u;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB43Bu;
  instance->instruction_count++;
  return 1;
 case 0x040FB418u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xB419u;
  instance->instruction_count++;
  return 1;
 case 0x000FB43Bu: /* 1A INC A */
  word = (uint16_t)((instance->cpu.a) + 1u);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB43Cu;
  instance->instruction_count++;
  return 1;
 case 0x040FB419u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 case 0x000FB43Cu: /* 85 2E STA $2E */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x2Eu) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xB43Eu;
  instance->instruction_count++;
  return 1;
 case 0x000FB43Eu: /* 8A TXA */
  tg_set_acc16(instance, (uint16_t)instance->cpu.x);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xB43Fu;
  instance->instruction_count++;
  return 1;
 case 0x000FB43Fu: /* 29 1F 00 AND #$001F */
  word = 0x001Fu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB442u;
  instance->instruction_count++;
  return 1;
 case 0x000FB442u: /* 84 34 STY $34 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x34u) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
  instance->cpu.pc = 0xB444u;
  instance->instruction_count++;
  return 1;
 case 0x000FB444u: /* 38 SEC */
  tg_set_flag(instance, TG_P_C, 1);
  instance->cpu.pc = 0xB445u;
  instance->instruction_count++;
  return 1;
 case 0x000FB445u: /* 65 2E ADC $2E */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x2Eu) & 0xFFFFu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xB447u;
  instance->instruction_count++;
  return 1;
 case 0x000FB402u: /* 80 3E BRA $0F:B442 */
  instance->cpu.pc = 0xB442u;
  instance->instruction_count++;
  return 1;
 case 0x000FB447u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xB448u;
  instance->instruction_count++;
  return 1;
 case 0x000FB448u: /* 65 32 ADC $32 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
  tg_adc16(instance, word);
  instance->cpu.pc = 0xB44Au;
  instance->instruction_count++;
  return 1;
 case 0x000FB44Au: /* 29 FF 07 AND #$07FF */
  word = 0x07FFu;
  word = (uint16_t)((instance->cpu.a) & word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB44Du;
  instance->instruction_count++;
  return 1;
 case 0x000FB44Du: /* AA TAX */
  tg_set_index16(instance, &instance->cpu.x, (uint16_t)instance->cpu.a);
  tg_set_nz16(instance, (uint16_t)instance->cpu.x);
  instance->cpu.pc = 0xB44Eu;
  instance->instruction_count++;
  return 1;
 case 0x000FB44Eu: /* A4 32 LDY $32 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB450u;
  instance->instruction_count++;
  return 1;
 case 0x000FB450u: /* E2 20 SEP #$20 */
  instance->cpu.p |=0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xB452u;
  instance->instruction_count++;
  return 1;
 case 0x040FB452u: /* BD 4C 04 LDA $044C,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x044Cu + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB455u;
  instance->instruction_count++;
  return 1;
 case 0x040FB455u: /* 99 4C 04 STA $044C,Y */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x044Cu + instance->cpu.y)), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB458u;
  instance->instruction_count++;
  return 1;
 case 0x040FB458u: /* 85 31 STA $31 */
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x31u) & 0xFFFFu), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB45Au;
  instance->instruction_count++;
  return 1;
 case 0x040FB45Au: /* 80 06 BRA $0F:B462 */
  instance->cpu.pc = 0xB462u;
  instance->instruction_count++;
  return 1;
 case 0x040FB462u: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB463u;
  instance->instruction_count++;
  return 1;
 case 0x040FB463u: /* 10 03 BPL $0F:B468 */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB468u : 0xB465u;
  instance->instruction_count++;
  return 1;
 case 0x040FB465u: /* A2 FF 07 LDX #$07FF */
  word = 0x07FFu;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB468u;
  instance->instruction_count++;
  return 1;
 case 0x040FB468u: /* 88 DEY */
  word = (uint16_t)(instance->cpu.y - 1u);
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB469u;
  instance->instruction_count++;
  return 1;
 case 0x040FB469u: /* 10 03 BPL $0F:B46E */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB46Eu : 0xB46Bu;
  instance->instruction_count++;
  return 1;
 case 0x040FB46Bu: /* A0 FF 07 LDY #$07FF */
  word = 0x07FFu;
  tg_set_index16(instance, &instance->cpu.y, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB46Eu;
  instance->instruction_count++;
  return 1;
 case 0x040FB46Eu: /* C6 2E DEC $2E */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x2Eu) & 0xFFFFu), &byte)) return 0;
  byte = (uint8_t)(byte - 1u);
  if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x2Eu) & 0xFFFFu), byte)) return 0;
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB470u;
  instance->instruction_count++;
  return 1;
 case 0x040FB470u: /* 10 EA BPL $0F:B45C */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB45Cu : 0xB472u;
  instance->instruction_count++;
  return 1;
 case 0x040FB472u: /* A5 31 LDA $31 */
  if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x31u) & 0xFFFFu), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB474u;
  instance->instruction_count++;
  return 1;
 case 0x040FB45Cu: /* BD 4C 04 LDA $044C,X */
  if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x044Cu + instance->cpu.x)), &byte)) return 0;
  tg_set_acc8(instance, byte);
  tg_set_nz8(instance, byte);
  instance->cpu.pc = 0xB45Fu;
  instance->instruction_count++;
  return 1;
 case 0x040FB474u: /* A6 32 LDX $32 */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), &word)) return 0;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB476u;
  instance->instruction_count++;
  return 1;
 case 0x040FB45Fu: /* 99 4C 04 STA $044C,Y */
  if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | (uint16_t)(0x044Cu + instance->cpu.y)), tg_acc8(instance))) return 0;
  instance->cpu.pc = 0xB462u;
  instance->instruction_count++;
  return 1;
 case 0x040FB476u: /* CA DEX */
  word = (uint16_t)(instance->cpu.x - 1u);
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB477u;
  instance->instruction_count++;
  return 1;
 case 0x040FB477u: /* 10 03 BPL $0F:B47C */
  instance->cpu.pc = !tg_flag(instance, TG_P_N) ? 0xB47Cu : 0xB479u;
  instance->instruction_count++;
  return 1;
 case 0x040FB479u: /* A2 FF 07 LDX #$07FF */
  word = 0x07FFu;
  tg_set_index16(instance, &instance->cpu.x, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xB47Cu;
  instance->instruction_count++;
  return 1;
 case 0x040FB47Cu: /* 86 30 STX $30 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x30u) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
  instance->cpu.pc = 0xB47Eu;
  instance->instruction_count++;
  return 1;
 case 0x040FB47Eu: /* 84 32 STY $32 */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x32u) & 0xFFFFu), (uint16_t)instance->cpu.y)) return 0;
  instance->cpu.pc = 0xB480u;
  instance->instruction_count++;
  return 1;
 case 0x040FB480u: /* 18 CLC */
  tg_set_flag(instance, TG_P_C, 0);
  instance->cpu.pc = 0xB481u;
  instance->instruction_count++;
  return 1;
 case 0x040FB481u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 default:return tg_fail_frontier(instance,"Unknown Version 22 post-WRAM ROM re-entry context in shard.",NULL);
 }}
