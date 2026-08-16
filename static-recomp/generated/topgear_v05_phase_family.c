/* Generated solely from the exact ROM-derived ARAM image and documented
   SPC700/S-SMP timer semantics. No emulator trace or oracle state was used. */
#include "topgear_static_recomp.h"
#include "topgear_v05_phase_family.h"
#include <string.h>

void tg_v05_fill_phase_family_info(struct TopGearV05PhaseFamilyInfo *x){
    static const unsigned char smp_to_scpu[4]={205u,187u,0u,0u};
    static const unsigned char scpu_to_smp[4]={0u,0u,0u,8u};
    if(!x) return;
    memset(x,0,sizeof(*x));
    x->profile_count=640u;
    x->timer_phase_count=128u;
    x->read_cycle_candidate_count=5u;
    x->generated_context_union_count=112u;
    x->new_context_count=17u;
    x->instruction_count_min=3617u;
    x->instruction_count_max=3649u;
    x->cycle_count_min=17028u;
    x->cycle_count_max=17156u;
    x->timer_read_count_min=200u;
    x->timer_read_count_max=216u;
    x->a=0x00u;
    x->x=0x2Fu;
    x->y=0x00u;
    x->sp=0xCFu;
    x->psw=0x02u;
    x->pc=0x084Fu;
    x->dsp_write_count=15u;
    x->exact_timing_known=0u;
    x->all_profiles_reconverged=1u;
    memcpy(x->smp_to_scpu,smp_to_scpu,4u);
    memcpy(x->scpu_to_smp,scpu_to_smp,4u);
    memcpy(x->aram_sha256,"123aa6ca3c85fb2da34e671df80bf007253f4ce2389056faef1c90de91023b10",65u);
    memcpy(x->dsp_registers_sha256,"d0ea0d7eeea846e3991bfc637ae4c36cb3f400260c50829a6cfd507a58765ef3",65u);
}
