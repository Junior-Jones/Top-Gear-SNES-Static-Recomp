/* Generated from the exact Top Gear ROM and documented W65C816 bus cycles. */
#include "topgear_v13_post_ipl_scpu_timing.h"
#include "topgear_static_recomp.h"
#include <string.h>

const TgV13ScpuTimingVariant tg_v13_post_ipl_scpu_timing_variants[TOPGEAR_RECOMP_V13_POST_IPL_TIMING_VARIANT_COUNT]={
    {0x00008061u,0x00008064u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA imm_m a90000 */
    {0x00008064u,0x00078000u,62u,8u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* JSL long 22008007 */
    {0x00078000u,0x00078002u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* REP imm8 c230 */
    {0x00078002u,0x00078003u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* PHB imp 8b */
    {0x00078003u,0x00078004u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* PHK imp 4b */
    {0x00078004u,0x00078005u,28u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* PLB imp ab */
    {0x00078005u,0x00078006u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* ASL acc 0a */
    {0x00078006u,0x00078007u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* TAX imp aa */
    {0x00078007u,0x0007800Au,46u,6u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA abs_x bd6481 */
    {0x0007800Au,0x0007800Cu,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* STA dp 851a */
    {0x0007800Cu,0x0007800Fu,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA imm_m a90089 */
    {0x0007800Fu,0x00078011u,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* STA dp 8524 */
    {0x00078011u,0x00078014u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA imm_m a9008a */
    {0x00078014u,0x00078016u,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* STA dp 8526 */
    {0x00078016u,0x00078019u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA imm_m a9008b */
    {0x00078019u,0x0007801Bu,32u,4u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* STA dp 8528 */
    {0x0007801Bu,0x0407801Du,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* SEP imm8 e220 */
    {0x00078027u,0x0007802Au,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA imm_m a9aabb */
    {0x0007802Au,0x0007802Du,36u,5u,2u,0u,{0x072140u, 0x072141u},{0u, 0u},{24u, 30u},{30u, 36u},{6u, 6u}}, /* CMP abs cd4021 */
    {0x0007802Du,0x0007802Au,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE rel8 d0fb */
    {0x0007802Du,0x0007802Fu,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE rel8 d0fb */
    {0x04008054u,0x04008057u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDX imm_x a20000 */
    {0x04008057u,0x04008058u,14u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* INX imp e8 */
    {0x04008058u,0x04008057u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE rel8 d0fd */
    {0x04008058u,0x0400805Au,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* BNE rel8 d0fd */
    {0x0400805Au,0x0400805Cu,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA imm_m a918 */
    {0x0400805Cu,0x0400805Fu,30u,4u,1u,0u,{0x002141u, 0x000000u},{1u, 0u},{24u, 0u},{30u, 0u},{6u, 0u}}, /* STA abs 8d4121 */
    {0x0400805Fu,0x00008061u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* REP imm8 c220 */
    {0x0407801Du,0x0407801Fu,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA imm_m a900 */
    {0x0407801Fu,0x04078021u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* STA dp 8523 */
    {0x04078021u,0x04078023u,16u,2u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* LDA imm_m a9cc */
    {0x04078023u,0x04078025u,24u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* STA dp 851c */
    {0x04078025u,0x00078027u,22u,3u,0u,0u,{0x000000u, 0x000000u},{0u, 0u},{0u, 0u},{0u, 0u},{0u, 0u}}, /* REP imm8 c220 */
};

const TgV13ScpuTimingVariant *tg_v13_find_post_ipl_scpu_timing(uint32_t key,uint32_t next_key,int require_next){
    uint32_t n;
    for(n=0u;n<TOPGEAR_RECOMP_V13_POST_IPL_TIMING_VARIANT_COUNT;++n){
        const TgV13ScpuTimingVariant *row=&tg_v13_post_ipl_scpu_timing_variants[n];
        if(row->context_key==key&&(!require_next||row->next_context_key==next_key))return row;
    }
    return NULL;
}

void tg_v13_fill_post_ipl_scpu_timing_info(struct TopGearV13PostIplScpuTimingInfo *x){
    if(!x)return;
    memset(x,0,sizeof(*x));
    x->timing_variant_count=33u;x->unique_route_context_count=31u;
    x->entry_instruction_count=668970ull;x->entry_master_clock=17158696ull;
    x->consumer_instruction_count=800069ull;x->consumer_master_clock=19518680ull;
    x->command_write_master_clock=19518056ull;x->command_write_address=0x002141u;
    x->consumer_address=0x07802Au;x->release_address=0x07802Fu;
    x->fixed_context_timing_proved=1u;x->hybrid_development_path_only=1u;x->static_authority_extended=0u;
    x->automatic_fallback_allowed=0u;x->runtime_opcode_decoder_used=0u;x->emulator_oracle_used_as_authority=0u;
    memcpy(x->claim_boundary,"This ROM-derived timing table lets the explicitly selected hybrid backend continue the S-CPU from the real IPL jump through command $18 and the second-$BBAA wait-loop release. It is a development route only and does not extend static S-SMP/DSP or frame-0 authority.",244u);
}
