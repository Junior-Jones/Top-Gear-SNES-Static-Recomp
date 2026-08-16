/* Generated ROM-wide static dispatch index, structurally sharded like a mature static recomp core. */
#include "topgear_internal.h"
#include "topgear_v22_romwide_dispatch.h"

unsigned tg_v22_generated_static_context_count(void){return 8685u;}
unsigned tg_v22_generated_static_address_count(void){return 8656u;}
int tg_v22_generated_static_step(struct TopGearRecomp *instance){
    uint32_t address,group;
    if(!instance) return 0;
    address=((uint32_t)instance->cpu.pbr<<16)|instance->cpu.pc;
    group=address>>10;
    switch(group){
    case 0x20u:return tg_v22_group_0020(instance);
    case 0x21u:return tg_v22_group_0021(instance);
    case 0x29u:return tg_v22_group_0029(instance);
    case 0x2Au:return tg_v22_group_002A(instance);
    case 0x2Bu:return tg_v22_group_002B(instance);
    case 0x2Du:return tg_v22_group_002D(instance);
    case 0x2Fu:return tg_v22_group_002F(instance);
    case 0x30u:return tg_v22_group_0030(instance);
    case 0x31u:return tg_v22_group_0031(instance);
    case 0x32u:return tg_v22_group_0032(instance);
    case 0x33u:return tg_v22_group_0033(instance);
    case 0x36u:return tg_v22_group_0036(instance);
    case 0x38u:return tg_v22_group_0038(instance);
    case 0x39u:return tg_v22_group_0039(instance);
    case 0x3Au:return tg_v22_group_003A(instance);
    case 0x3Bu:return tg_v22_group_003B(instance);
    case 0x1E0u:return tg_v22_group_01E0(instance);
    case 0x3E0u:return tg_v22_group_03E0(instance);
    case 0x3E1u:return tg_v22_group_03E1(instance);
    case 0x3E2u:return tg_v22_group_03E2(instance);
    case 0x3E3u:return tg_v22_group_03E3(instance);
    case 0x3E4u:return tg_v22_group_03E4(instance);
    case 0x3E5u:return tg_v22_group_03E5(instance);
    case 0x3E6u:return tg_v22_group_03E6(instance);
    case 0x3E7u:return tg_v22_group_03E7(instance);
    case 0x3E8u:return tg_v22_group_03E8(instance);
    case 0x3E9u:return tg_v22_group_03E9(instance);
    case 0x3ECu:return tg_v22_group_03EC(instance);
    case 0x3EDu:return tg_v22_group_03ED(instance);
    default:return tg_fail_frontier(instance,"Address is outside the Version 22 ROM-wide generated static dispatch surface.",NULL);
    }}
