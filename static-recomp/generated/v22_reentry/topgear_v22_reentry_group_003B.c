/* Generated Version 22 ROM re-entry shard. */
#include "topgear_internal.h"
#include "topgear_v22_reentry_shards.h"

int tg_v22_reentry_group_003B_has(uint32_t key){switch(key){
 case 0x0000EC0Eu:return 1;
 case 0x0000EC10u:return 1;
 case 0x0000EC13u:return 1;
 case 0x0000EC15u:return 1;
 case 0x0000EC17u:return 1;
 case 0x0000EC19u:return 1;
 default:return 0;}}
int tg_v22_reentry_group_003B_step(struct TopGearRecomp *instance){
 uint32_t key,address=0u,base24=0u;uint16_t word=0u;uint8_t byte=0u;
 if(!instance)return 0;
 (void)address;(void)base24;(void)word;(void)byte;
 key=tg_generated_context_key(instance);switch(key){
 case 0x0000EC0Eu: /* C2 20 REP #$20 */
  instance->cpu.p &= (uint8_t)~0x20u;
  if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
  if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
  instance->cpu.pc = 0xEC10u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC10u: /* 49 FF FF EOR #$FFFF */
  word = 0xFFFFu;
  word = (uint16_t)((instance->cpu.a) ^ word);
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC13u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC13u: /* 85 0C STA $0C */
  if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Cu) & 0xFFFFu), instance->cpu.a)) return 0;
  instance->cpu.pc = 0xEC15u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC15u: /* A5 0C LDA $0C */
  if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Cu) & 0xFFFFu), &word)) return 0;
  tg_set_acc16(instance, word);
  tg_set_nz16(instance, word);
  instance->cpu.pc = 0xEC17u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC17u: /* D0 FC BNE $00:EC15 */
  instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0xEC15u : 0xEC19u;
  instance->instruction_count++;
  return 1;
 case 0x0000EC19u: /* 60 RTS */
  if (!tg_pull16(instance, &word)) return 0;
  instance->cpu.pc = (uint16_t)(word + 1u);
  instance->instruction_count++;
  return 1;
 default:return tg_fail_frontier(instance,"Unknown Version 22 post-WRAM ROM re-entry context in shard.",NULL);
 }}
