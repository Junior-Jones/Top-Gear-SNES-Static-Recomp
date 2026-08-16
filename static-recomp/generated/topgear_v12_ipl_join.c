#include "topgear_v12_ipl_join.h"
#include <string.h>
#define Z 0x02u
static void nz(TgV12IplCore*s,uint8_t v){s->psw=(uint8_t)(s->psw&~0x82u);if(v==0)s->psw|=Z;if(v&0x80u)s->psw|=0x80u;}
void tg_v12_ipl_reset(TgV12IplCore*s){if(!s)return;memset(s,0,sizeof(*s));s->sp=0xEFu;s->pc=0xFFC0u;}
int tg_v12_ipl_step(TgV12IplCore*s,uint8_t in[4],uint8_t out[4],uint8_t ram[65536]){uint8_t v;if(!s||!in||!out||!ram||s->stopped)return 0;switch(s->pc){
case 0xFFC0u:s->x=0xEFu;nz(s,s->x);s->pc=0xFFC2u;s->cycles+=2u;break;
case 0xFFC2u:s->sp=s->x;s->pc=0xFFC3u;s->cycles+=2u;break;
case 0xFFC3u:s->a=0u;nz(s,s->a);s->pc=0xFFC5u;s->cycles+=2u;break;
case 0xFFC5u:ram[s->x]=s->a;s->pc=0xFFC6u;s->cycles+=4u;break;
case 0xFFC6u:s->x=(uint8_t)(s->x-1u);nz(s,s->x);s->pc=0xFFC7u;s->cycles+=2u;break;
case 0xFFC7u:if((s->psw&Z)==0u){s->pc=0xFFC5u;s->cycles+=4u;}else{s->pc=0xFFC9u;s->cycles+=2u;}break;
case 0xFFC9u:out[0]=0xAAu;s->pc=0xFFCCu;s->cycles+=5u;break;
case 0xFFCCu:out[1]=0xBBu;s->pc=0xFFCFu;s->cycles+=5u;break;
case 0xFFCFu:v=(uint8_t)(in[0]-0xCCu);s->psw=(uint8_t)(s->psw&~0x83u);if(in[0]>=0xCCu)s->psw|=1u;if(v==0)s->psw|=Z;if(v&0x80u)s->psw|=0x80u;s->pc=0xFFD2u;s->cycles+=5u;break;
case 0xFFD2u:if((s->psw&Z)==0u){s->pc=0xFFCFu;s->cycles+=4u;}else{s->pc=0xFFD4u;s->cycles+=2u;}break;
case 0xFFD4u:s->pc=0xFFEFu;s->cycles+=4u;break;
case 0xFFEFu:s->a=in[2];s->y=in[3];s->pc=0xFFF1u;s->cycles+=5u;break;
case 0xFFF1u:ram[0]=s->a;ram[1]=s->y;s->pc=0xFFF3u;s->cycles+=5u;break;
case 0xFFF3u:s->a=in[0];s->y=in[1];s->pc=0xFFF5u;s->cycles+=5u;break;
case 0xFFF5u:out[0]=s->a;s->pc=0xFFF7u;s->cycles+=4u;s->stopped=1u;break;
default:s->stopped=1u;return 0;}s->instructions++;return 1;}
void tg_v12_fill_ipl_join_info(TopGearV12IplJoinInfo*x){if(!x)return;memset(x,0,sizeof(*x));x->ipl_context_count=15u;x->ipl_rom_bytes=64u;x->ready_port0_publish_cycle=2399ull;x->ready_port1_publish_cycle=2404ull;x->first_command_write_master_clock=10610254ull;x->historical_ack_read_master_clock_start=10610278ull;x->historical_ack_read_master_clock_end=10610284ull;x->master_clocks_available=30u;x->maximum_smp_cycles_available=2u;x->minimum_smp_cycles_required=25u;x->initial_ready_reads_matched=2u;x->historical_expected_value=0xCCu;x->physical_value_at_first_read=0xAAu;x->all_initial_phases_reject_ack=1u;x->exact_physical_phase_selected=0u;x->historical_compatibility_route_rejected=1u;x->first_invalid_hardware_event_index=8u;x->frontier_instruction=400772ull;memcpy(x->ipl_rom_sha256,"c95f88b299030d5afa55b1031e2b5ef2dff650c4b4e6bb6f8b1359436521278f",sizeof(x->ipl_rom_sha256));memcpy(x->frontier_address,"00:EBE7",sizeof("00:EBE7"));memcpy(x->reason,"The first historical $CC acknowledgement is physically impossible: at most 2 S-SMP cycles are available but the IPL needs at least 25 after observing the command.",sizeof("The first historical $CC acknowledgement is physically impossible: at most 2 S-SMP cycles are available but the IPL needs at least 25 after observing the command."));}
