#include "topgear_v13_interleaved_ipl.h"
#include <string.h>
#define Z 2u
#define N 0x80u
const TgV13ScpuTimingVariant tg_v13_scpu_timing_variants[TOPGEAR_RECOMP_V13_SCPU_TIMING_VARIANT_COUNT]={
    {0x0000804Du,0x0400804Fu,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0000EBCAu,0x0000EBCCu,56u,7u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0000EBCCu,0x0000EBCDu,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0000EBCDu,0x0000EBCEu,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0000EBCEu,0x0000EBCFu,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0000EBCFu,0x0000EBD1u,56u,7u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0000EBD1u,0x0000EBD4u,36u,5u,2u,0u,{0x002142u, 0x002143u},{1u, 1u},{24u, 30u},{30u, 36u},{6u, 6u}},
    {0x0000EBD4u,0x0000EBD5u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0000EBD5u,0x0000EBD6u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0000EBD6u,0x0400EBD8u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0000EBF7u,0x0000EBFAu,36u,5u,2u,0u,{0x002140u, 0x002141u},{1u, 1u},{24u, 30u},{30u, 36u},{6u, 6u}},
    {0x0000EBFAu,0x0400EBFCu,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0000EC0Du,0x0000804Du,42u,6u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400804Fu,0x04008051u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x04008051u,0x04008054u,30u,4u,1u,0u,{0x002140u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}},
    {0x04008054u,0x04008057u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x04008057u,0x04008058u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x04008058u,0x04008057u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBC7u,0x0400EBC8u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBC8u,0x0000EBCAu,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBD8u,0x0400EBDAu,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBDAu,0x0400EBDDu,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBDDu,0x0400EBDEu,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBDEu,0x0400EBE1u,30u,4u,1u,0u,{0x002141u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}},
    {0x0400EBE1u,0x0400EBE3u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBE3u,0x0400EBE4u,28u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBE4u,0x0400EBE7u,30u,4u,1u,0u,{0x002140u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}},
    {0x0400EBE7u,0x0400EBEAu,30u,4u,1u,0u,{0x002140u, 0x000000u},{0u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}},
    {0x0400EBEAu,0x0400EBE7u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBEAu,0x0400EBECu,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBECu,0x0400EBEEu,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBECu,0x0400EC0Bu,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBEEu,0x0400EBF0u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBF0u,0x0400EBF1u,20u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBF1u,0x0400EBF3u,48u,6u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBF3u,0x0400EBF4u,20u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBF4u,0x0400EBF5u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBF5u,0x0000EBF7u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBFCu,0x0400EBFFu,30u,4u,1u,0u,{0x002140u, 0x000000u},{0u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}},
    {0x0400EBFFu,0x0400EBFCu,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EBFFu,0x0400EC01u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EC01u,0x0400EC02u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EC02u,0x0400EC03u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EC03u,0x0400EBF0u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EC03u,0x0400EC05u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EC05u,0x0400EC07u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EC07u,0x0400EBC7u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
    {0x0400EC0Bu,0x0000EC0Du,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}},
};
static void nz(TgV13IplCore*s,uint8_t v){s->psw=(uint8_t)(s->psw&~0x82u);if(v==0)s->psw|=Z;if(v&0x80u)s->psw|=N;}
static void cmp8(TgV13IplCore*s,uint8_t l,uint8_t r){uint8_t v=(uint8_t)(l-r);s->psw=(uint8_t)(s->psw&~0x83u);if(l>=r)s->psw|=1u;if(v==0)s->psw|=Z;if(v&0x80u)s->psw|=N;}
void tg_v13_ipl_reset(TgV13IplCore*s){if(!s)return;memset(s,0,sizeof(*s));s->sp=0xEFu;s->pc=0xFFC0u;}
static unsigned cyc(const TgV13IplCore*s){switch(s->pc){case 0xFFC0:case 0xFFC2:case 0xFFC3:case 0xFFC6:case 0xFFE4:case 0xFFF7:case 0xFFF8:return 2;case 0xFFC5:case 0xFFD4:case 0xFFE7:case 0xFFF1:case 0xFFF5:return 4;case 0xFFC9:case 0xFFCC:case 0xFFCF:case 0xFFEF:case 0xFFF3:return 5;case 0xFFD6:case 0xFFDA:case 0xFFDE:case 0xFFEB:return 3;case 0xFFE0:return 4;case 0xFFE2:return 7;case 0xFFFB:return 6;case 0xFFC7:case 0xFFD2:case 0xFFD8:case 0xFFDC:case 0xFFE5:case 0xFFF9:return (s->psw&Z)?2:4;case 0xFFE9:case 0xFFED:return (s->psw&N)?2:4;default:return 0;}}
static int step(TgV13IplCore*s,uint8_t in[4],uint8_t out[4],uint8_t r[65536]){unsigned c=cyc(s);uint16_t p;if(!c)return 0;switch(s->pc){
case 0xFFC0:s->x=0xEF;nz(s,s->x);s->pc=0xFFC2;break;case 0xFFC2:s->sp=s->x;s->pc=0xFFC3;break;case 0xFFC3:s->a=0;nz(s,0);s->pc=0xFFC5;break;case 0xFFC5:r[s->x]=s->a;s->pc=0xFFC6;break;case 0xFFC6:s->x--;nz(s,s->x);s->pc=0xFFC7;break;case 0xFFC7:s->pc=(s->psw&Z)?0xFFC9:0xFFC5;break;case 0xFFC9:out[0]=0xAA;s->pc=0xFFCC;break;case 0xFFCC:out[1]=0xBB;s->pc=0xFFCF;break;case 0xFFCF:cmp8(s,in[0],0xCC);s->pc=0xFFD2;break;case 0xFFD2:s->pc=(s->psw&Z)?0xFFD4:0xFFCF;break;case 0xFFD4:s->pc=0xFFEF;break;
case 0xFFD6:s->y=in[0];nz(s,s->y);s->pc=0xFFD8;break;case 0xFFD8:s->pc=(s->psw&Z)?0xFFDA:0xFFD6;break;case 0xFFDA:cmp8(s,s->y,in[0]);s->pc=0xFFDC;break;case 0xFFDC:s->pc=(s->psw&Z)?0xFFDE:0xFFE9;break;case 0xFFDE:s->a=in[1];nz(s,s->a);s->pc=0xFFE0;break;case 0xFFE0:out[0]=s->y;s->pc=0xFFE2;break;case 0xFFE2:p=(uint16_t)(r[0]|((uint16_t)r[1]<<8));r[(uint16_t)(p+s->y)]=s->a;s->payload_writes++;s->pc=0xFFE4;break;case 0xFFE4:s->y++;nz(s,s->y);s->pc=0xFFE5;break;case 0xFFE5:s->pc=(s->psw&Z)?0xFFE7:0xFFDA;break;case 0xFFE7:r[1]++;nz(s,r[1]);s->pc=0xFFE9;break;case 0xFFE9:s->pc=(s->psw&N)?0xFFEB:0xFFDA;break;case 0xFFEB:cmp8(s,s->y,in[0]);s->pc=0xFFED;break;case 0xFFED:s->pc=(s->psw&N)?0xFFEF:0xFFDA;break;
case 0xFFEF:s->a=in[2];s->y=in[3];nz(s,s->y);s->pc=0xFFF1;break;case 0xFFF1:r[0]=s->a;r[1]=s->y;s->pc=0xFFF3;break;case 0xFFF3:s->a=in[0];s->y=in[1];nz(s,s->y);s->pc=0xFFF5;break;case 0xFFF5:out[0]=s->a;s->pc=0xFFF7;break;case 0xFFF7:s->a=s->y;nz(s,s->a);s->pc=0xFFF8;break;case 0xFFF8:s->x=s->a;nz(s,s->x);s->pc=0xFFF9;break;case 0xFFF9:s->pc=(s->psw&Z)?0xFFFB:0xFFD6;break;case 0xFFFB:s->pc=(uint16_t)(r[s->x]|((uint16_t)r[(uint8_t)(s->x+1u)]<<8));s->program_started=1;s->program_entry_cycle=s->cycles+c;break;default:return 0;}s->cycles+=c;s->instructions++;return 1;}
int tg_v13_ipl_sync(TgV13IplCore*s,uint8_t in[4],uint8_t out[4],uint8_t r[65536],uint64_t m,uint32_t phase){uint64_t target=(m*(uint64_t)TOPGEAR_RECOMP_V13_SMP_CLOCK_NUMERATOR+phase)/(uint64_t)TOPGEAR_RECOMP_V13_SMP_CLOCK_DENOMINATOR;if(!s||!in||!out||!r)return 0;while(!s->program_started){unsigned n=cyc(s);if(!n||s->cycles+n>target)break;if(!step(s,in,out,r))return 0;}return 1;}
const TgV13ScpuTimingVariant *tg_v13_find_scpu_timing(uint32_t k,uint32_t n,int req){uint32_t i;for(i=0;i<TOPGEAR_RECOMP_V13_SCPU_TIMING_VARIANT_COUNT;i++){const TgV13ScpuTimingVariant*r=&tg_v13_scpu_timing_variants[i];if(r->context_key==k&&(!req||r->next_context_key==n))return r;}return 0;}
void tg_v13_fill_ipl_upload_info(TopGearV13IplUploadInfo*x){if(!x)return;memset(x,0,sizeof(*x));x->phase_profile_count=128u;x->ipl_context_count=34u;x->scpu_timing_variant_count=48u;x->upload_destination=0x0800u;x->upload_bytes=12489u;x->program_entrypoint=0x0800u;x->nominal_clock_numerator=TOPGEAR_RECOMP_V13_SMP_CLOCK_NUMERATOR;x->nominal_clock_denominator=TOPGEAR_RECOMP_V13_SMP_CLOCK_DENOMINATOR;x->minimum_scpu_instructions=669290ull;x->maximum_scpu_instructions=669300ull;x->minimum_entry_master_clock=17166995ull;x->maximum_entry_master_clock=17167241ull;x->minimum_smp_entry_cycle=818494ull;x->maximum_smp_entry_cycle=818505ull;x->all_profiles_completed_upload=1u;x->all_profiles_matched_upload_hash=1u;x->all_profiles_reached_entrypoint=1u;x->exact_physical_phase_selected=0u;x->exact_physical_rate_selected=0u;x->compatibility_helper_allowed=0u;x->clean_reset_route_required=1u;memcpy(x->upload_sha256,TOPGEAR_RECOMP_V13_UPLOAD_SHA256,65u);memcpy(x->aram_sha256,"5f810b59e9196d6575dc352c2ca6a981ff4ae392c538869e99f205f2e7336061",65u);memcpy(x->next_barrier,"The real IPL upload is proved. The uploaded driver must next be joined without selecting an unproved timer/DSP phase or asynchronous S-CPU schedule.",139u);}
