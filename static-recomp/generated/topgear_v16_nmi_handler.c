/* Generated from the exact Top Gear ROM by tools/scpu/generate_v16_nmi_handler.py.
   No runtime opcode decoder or emulator endpoint is present.
   The NMI prologue preserves the interrupted DBR/D until PHK/PLB and TCD;
   the epilogue restores those caller registers before RTI. Context masks keep
   those boundaries variable while the handler-owned body remains fail-closed. */
#include "topgear_internal.h"
#include "topgear_v16_nmi_handler.h"

unsigned tg_v16_generated_nmi_context_count(void) { return 53u; }

int tg_v16_generated_nmi_timing_step(struct TopGearRecomp *instance) {
    uint32_t key;
    if(!instance)return 0;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x040F8000u: /* C2 34 REP #$34 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,0u,"0F:8000"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8000u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8001u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,1u))return 0;
        return 1;
    case 0x000F8002u: /* 48 PHA */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8002"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8002u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_WRITE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_WRITE,0u,6u,1u))return 0;
        return 1;
    case 0x000F8003u: /* DA PHX */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8003"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8003u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_WRITE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_WRITE,0u,6u,1u))return 0;
        return 1;
    case 0x000F8004u: /* 5A PHY */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8004"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8004u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_WRITE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_WRITE,0u,6u,1u))return 0;
        return 1;
    case 0x000F8005u: /* 0B PHD */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8005"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8005u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_WRITE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_WRITE,0u,6u,1u))return 0;
        return 1;
    case 0x000F8006u: /* 8B PHB */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8006"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8006u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_WRITE,0u,6u,1u))return 0;
        return 1;
    case 0x000F8007u: /* A9 00 00 LDA #$0000 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8007"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8007u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8008u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8009u,8u,1u))return 0;
        return 1;
    case 0x000F800Au: /* 5B TCD */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:800A"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F800Au,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,1u))return 0;
        return 1;
    case 0x000F800Bu: /* 4B PHK */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_D,"0F:800B"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F800Bu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_WRITE,0u,6u,1u))return 0;
        return 1;
    case 0x000F800Cu: /* AB PLB */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_D,"0F:800C"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F800Cu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,1u))return 0;
        return 1;
    case 0x000F800Du: /* A5 90 LDA $90 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:800D"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F800Du,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F800Eu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x000090u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x000091u,8u,1u))return 0;
        return 1;
    case 0x000F800Fu: /* C9 4C 00 CMP #$004C */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:800F"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F800Fu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8010u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8011u,8u,1u))return 0;
        return 1;
    case 0x000F8012u: /* D0 0B BNE $0F:801F */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8012"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8012u,8u,0u))return 0;
        if(!tg_flag(instance,TG_P_Z)){ if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8013u,8u,0u))return 0; if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,1u))return 0; }
        else { if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8013u,8u,1u))return 0; }
        return 1;
    case 0x000F8014u: /* 64 90 STZ $90 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8014"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8014u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8015u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x000090u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x000091u,8u,1u))return 0;
        return 1;
    case 0x000F8016u: /* 20 1A A2 JSR $A21A */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8016"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8016u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8017u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8018u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_WRITE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_WRITE,0u,6u,1u))return 0;
        return 1;
    case 0x000F8019u: /* A9 02 00 LDA #$0002 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8019"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8019u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F801Au,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F801Bu,8u,1u))return 0;
        return 1;
    case 0x000F801Cu: /* 8D 24 04 STA $0424 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:801C"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F801Cu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F801Du,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F801Eu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F0424u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F0425u,8u,1u))return 0;
        return 1;
    case 0x000F801Fu: /* E2 20 SEP #$20 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:801F"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F801Fu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8020u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,1u))return 0;
        return 1;
    case 0x040F8021u: /* AD 24 04 LDA $0424 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8021"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8021u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8022u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8023u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x0F0424u,8u,1u))return 0;
        return 1;
    case 0x040F8024u: /* F0 08 BEQ $0F:802E */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8024"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8024u,8u,0u))return 0;
        if(tg_flag(instance,TG_P_Z)){ if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8025u,8u,0u))return 0; if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,1u))return 0; }
        else { if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8025u,8u,1u))return 0; }
        return 1;
    case 0x040F8026u: /* 8D 0B 42 STA $420B */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8026"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8026u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8027u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8028u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F420Bu,6u,1u))return 0;
        return 1;
    case 0x040F8029u: /* A9 00 LDA #$00 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8029"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8029u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F802Au,8u,1u))return 0;
        return 1;
    case 0x040F802Bu: /* 8D 24 04 STA $0424 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:802B"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F802Bu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F802Cu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F802Du,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F0424u,8u,1u))return 0;
        return 1;
    case 0x040F802Eu: /* A5 42 LDA $42 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:802E"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F802Eu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F802Fu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x000042u,8u,1u))return 0;
        return 1;
    case 0x040F8030u: /* 8D 00 21 STA $2100 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8030"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8030u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8031u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8032u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F2100u,6u,1u))return 0;
        return 1;
    case 0x040F8033u: /* AD 10 42 LDA $4210 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8033"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8033u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8034u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8035u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x0F4210u,6u,1u))return 0;
        return 1;
    case 0x040F8036u: /* E6 08 INC $08 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8036"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8036u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8037u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x000008u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x000008u,8u,1u))return 0;
        return 1;
    case 0x040F8038u: /* AD 12 42 LDA $4212 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8038"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8038u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8039u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F803Au,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x0F4212u,6u,1u))return 0;
        return 1;
    case 0x040F803Bu: /* 29 01 AND #$01 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:803B"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F803Bu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F803Cu,8u,1u))return 0;
        return 1;
    case 0x040F803Du: /* D0 F9 BNE $0F:8038 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:803D"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F803Du,8u,0u))return 0;
        if(!tg_flag(instance,TG_P_Z)){ if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F803Eu,8u,0u))return 0; if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,1u))return 0; }
        else { if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F803Eu,8u,1u))return 0; }
        return 1;
    case 0x040F803Fu: /* C2 20 REP #$20 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:803F"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F803Fu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8040u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,1u))return 0;
        return 1;
    case 0x000F8041u: /* EE FC 1F INC $1FFC */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8041"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8041u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8042u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8043u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x0F1FFCu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x0F1FFDu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F1FFDu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x0F1FFCu,8u,1u))return 0;
        return 1;
    case 0x000F8044u: /* AE 18 42 LDX $4218 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8044"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8044u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8045u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8046u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x0F4218u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x0F4219u,6u,1u))return 0;
        return 1;
    case 0x000F8047u: /* A5 0A LDA $0A */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8047"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8047u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8048u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x00000Au,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x00000Bu,8u,1u))return 0;
        return 1;
    case 0x000F8049u: /* 86 0A STX $0A */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8049"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8049u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F804Au,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x00000Au,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x00000Bu,8u,1u))return 0;
        return 1;
    case 0x000F804Bu: /* 49 FF FF EOR #$FFFF */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:804B"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F804Bu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F804Cu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F804Du,8u,1u))return 0;
        return 1;
    case 0x000F804Eu: /* 05 0E ORA $0E */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:804E"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F804Eu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F804Fu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x00000Eu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x00000Fu,8u,1u))return 0;
        return 1;
    case 0x000F8050u: /* 25 0A AND $0A */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8050"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8050u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8051u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x00000Au,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x00000Bu,8u,1u))return 0;
        return 1;
    case 0x000F8052u: /* 85 0E STA $0E */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8052"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8052u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8053u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x00000Eu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x00000Fu,8u,1u))return 0;
        return 1;
    case 0x000F8054u: /* AE 1A 42 LDX $421A */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8054"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8054u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8055u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8056u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x0F421Au,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x0F421Bu,6u,1u))return 0;
        return 1;
    case 0x000F8057u: /* A5 0C LDA $0C */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8057"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8057u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8058u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x00000Cu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x00000Du,8u,1u))return 0;
        return 1;
    case 0x000F8059u: /* 86 0C STX $0C */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8059"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8059u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F805Au,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x00000Cu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x00000Du,8u,1u))return 0;
        return 1;
    case 0x000F805Bu: /* 49 FF FF EOR #$FFFF */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:805B"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F805Bu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F805Cu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F805Du,8u,1u))return 0;
        return 1;
    case 0x000F805Eu: /* 05 10 ORA $10 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:805E"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F805Eu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F805Fu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x000010u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x000011u,8u,1u))return 0;
        return 1;
    case 0x000F8060u: /* 25 0C AND $0C */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8060"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8060u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8061u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x00000Cu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_READ,0x00000Du,8u,1u))return 0;
        return 1;
    case 0x000F8062u: /* 85 10 STA $10 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8062"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8062u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8063u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x000010u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_DATA_WRITE,0x000011u,8u,1u))return 0;
        return 1;
    case 0x000F8064u: /* C2 30 REP #$30 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8064"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8064u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8065u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,1u))return 0;
        return 1;
    case 0x000F8066u: /* AB PLB */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8066"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8066u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,1u))return 0;
        return 1;
    case 0x000F8067u: /* 2B PLD */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_D,"0F:8067"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8067u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,1u))return 0;
        return 1;
    case 0x000F8068u: /* 7A PLY */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8068"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8068u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,1u))return 0;
        return 1;
    case 0x000F8069u: /* FA PLX */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8069"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F8069u,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,1u))return 0;
        return 1;
    case 0x000F806Au: /* 68 PLA */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:806A"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F806Au,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,1u))return 0;
        return 1;
    case 0x000F806Bu: /* 40 RTI */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:806B"))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_FETCH,0x0F806Bu,8u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_IDLE,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,0u))return 0;
        if(!tg_v16_schedule_cpu_cycle(instance,TG_V16_CYCLE_STACK_READ,0u,6u,1u))return 0;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 16 first-NMI timing context.",NULL);
    }
}

int tg_v16_generated_nmi_semantic_step(struct TopGearRecomp *instance) {
    uint32_t key; uint32_t address=0u,base24=0u; uint16_t word=0u; uint8_t byte=0u,pcl=0u,pch=0u,pbr=0u;
    if(!instance)return 0;
    (void)address; (void)base24;
    key=tg_generated_context_key(instance);
    switch(key){
    case 0x040F8000u: /* C2 34 REP #$34 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,0u,"0F:8000"))return 0;
        instance->cpu.p &= (uint8_t)~0x34u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8002u;
        instance->instruction_count++;
        return 1;
    case 0x000F8002u: /* 48 PHA */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8002"))return 0;
        if (!tg_push16(instance, (uint16_t)instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8003u;
        instance->instruction_count++;
        return 1;
    case 0x000F8003u: /* DA PHX */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8003"))return 0;
        if (!tg_push16(instance, (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x8004u;
        instance->instruction_count++;
        return 1;
    case 0x000F8004u: /* 5A PHY */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8004"))return 0;
        if (!tg_push16(instance, instance->cpu.y)) return 0;
        instance->cpu.pc = 0x8005u;
        instance->instruction_count++;
        return 1;
    case 0x000F8005u: /* 0B PHD */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8005"))return 0;
        if (!tg_push16(instance, instance->cpu.d)) return 0;
        instance->cpu.pc = 0x8006u;
        instance->instruction_count++;
        return 1;
    case 0x000F8006u: /* 8B PHB */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8006"))return 0;
        if (!tg_push8(instance, instance->cpu.dbr)) return 0;
        instance->cpu.pc = 0x8007u;
        instance->instruction_count++;
        return 1;
    case 0x000F8007u: /* A9 00 00 LDA #$0000 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8007"))return 0;
        word = 0x0000u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x800Au;
        instance->instruction_count++;
        return 1;
    case 0x000F800Au: /* 5B TCD */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:800A"))return 0;
        instance->cpu.d = instance->cpu.a;
        tg_set_nz16(instance, instance->cpu.d);
        instance->cpu.pc = 0x800Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F800Bu: /* 4B PHK */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_D,"0F:800B"))return 0;
        if (!tg_push8(instance, instance->cpu.pbr)) return 0;
        instance->cpu.pc = 0x800Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F800Cu: /* AB PLB */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_D,"0F:800C"))return 0;
        if (!tg_pull8(instance, &byte)) return 0;
        instance->cpu.dbr = byte;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x800Du;
        instance->instruction_count++;
        return 1;
    case 0x000F800Du: /* A5 90 LDA $90 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:800D"))return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x90u) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x800Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F800Fu: /* C9 4C 00 CMP #$004C */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:800F"))return 0;
        word = 0x004Cu;
        tg_compare16(instance, instance->cpu.a, word);
        instance->cpu.pc = 0x8012u;
        instance->instruction_count++;
        return 1;
    case 0x000F8012u: /* D0 0B BNE $0F:801F */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8012"))return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x801Fu : 0x8014u;
        instance->instruction_count++;
        return 1;
    case 0x000F8014u: /* 64 90 STZ $90 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8014"))return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x90u) & 0xFFFFu), 0u)) return 0;
        instance->cpu.pc = 0x8016u;
        instance->instruction_count++;
        return 1;
    case 0x000F8016u: /* 20 1A A2 JSR $A21A */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8016"))return 0;
        if (!tg_push16(instance, 0x8018u)) return 0;
        instance->cpu.pc = 0xA21Au;
        instance->instruction_count++;
        return 1;
    case 0x000F8019u: /* A9 02 00 LDA #$0002 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8019"))return 0;
        word = 0x0002u;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x801Cu;
        instance->instruction_count++;
        return 1;
    case 0x000F801Cu: /* 8D 24 04 STA $0424 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:801C"))return 0;
        if (!tg_bus_store16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x801Fu;
        instance->instruction_count++;
        return 1;
    case 0x000F801Fu: /* E2 20 SEP #$20 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:801F"))return 0;
        instance->cpu.p |=0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8021u;
        instance->instruction_count++;
        return 1;
    case 0x040F8021u: /* AD 24 04 LDA $0424 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8021"))return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8024u;
        instance->instruction_count++;
        return 1;
    case 0x040F8024u: /* F0 08 BEQ $0F:802E */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8024"))return 0;
        instance->cpu.pc = tg_flag(instance, TG_P_Z) ? 0x802Eu : 0x8026u;
        instance->instruction_count++;
        return 1;
    case 0x040F8026u: /* 8D 0B 42 STA $420B */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8026"))return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x420Bu), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8029u;
        instance->instruction_count++;
        return 1;
    case 0x040F8029u: /* A9 00 LDA #$00 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8029"))return 0;
        byte = 0x00u;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x802Bu;
        instance->instruction_count++;
        return 1;
    case 0x040F802Bu: /* 8D 24 04 STA $0424 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:802B"))return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x0424u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x802Eu;
        instance->instruction_count++;
        return 1;
    case 0x040F802Eu: /* A5 42 LDA $42 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:802E"))return 0;
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x42u) & 0xFFFFu), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8030u;
        instance->instruction_count++;
        return 1;
    case 0x040F8030u: /* 8D 00 21 STA $2100 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8030"))return 0;
        if (!tg_bus_write8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x2100u), tg_acc8(instance))) return 0;
        instance->cpu.pc = 0x8033u;
        instance->instruction_count++;
        return 1;
    case 0x040F8033u: /* AD 10 42 LDA $4210 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8033"))return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4210u), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8036u;
        instance->instruction_count++;
        return 1;
    case 0x040F8036u: /* E6 08 INC $08 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8036"))return 0;
        if (!tg_bus_read8(instance, (uint32_t)((instance->cpu.d + 0x08u) & 0xFFFFu), &byte)) return 0;
        byte = (uint8_t)(byte + 1u);
        if (!tg_bus_write8(instance, (uint32_t)((instance->cpu.d + 0x08u) & 0xFFFFu), byte)) return 0;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8038u;
        instance->instruction_count++;
        return 1;
    case 0x040F8038u: /* AD 12 42 LDA $4212 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8038"))return 0;
        if (!tg_bus_read8(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4212u), &byte)) return 0;
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x803Bu;
        instance->instruction_count++;
        return 1;
    case 0x040F803Bu: /* 29 01 AND #$01 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:803B"))return 0;
        byte = 0x01u;
        byte = (uint8_t)((tg_acc8(instance)) & byte);
        tg_set_acc8(instance, byte);
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x803Du;
        instance->instruction_count++;
        return 1;
    case 0x040F803Du: /* D0 F9 BNE $0F:8038 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:803D"))return 0;
        instance->cpu.pc = !tg_flag(instance, TG_P_Z) ? 0x8038u : 0x803Fu;
        instance->instruction_count++;
        return 1;
    case 0x040F803Fu: /* C2 20 REP #$20 */
        if(!tg_require_context_masked(instance,0u,1u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:803F"))return 0;
        instance->cpu.p &= (uint8_t)~0x20u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8041u;
        instance->instruction_count++;
        return 1;
    case 0x000F8041u: /* EE FC 1F INC $1FFC */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8041"))return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FFCu), &word)) return 0;
        word = (uint16_t)(word + 1u);
        if (!tg_bus_write16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x1FFCu), word)) return 0;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8044u;
        instance->instruction_count++;
        return 1;
    case 0x000F8044u: /* AE 18 42 LDX $4218 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8044"))return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x4218u), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8047u;
        instance->instruction_count++;
        return 1;
    case 0x000F8047u: /* A5 0A LDA $0A */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8047"))return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8049u;
        instance->instruction_count++;
        return 1;
    case 0x000F8049u: /* 86 0A STX $0A */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8049"))return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x804Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F804Bu: /* 49 FF FF EOR #$FFFF */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:804B"))return 0;
        word = 0xFFFFu;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x804Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F804Eu: /* 05 0E ORA $0E */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:804E"))return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Eu) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8050u;
        instance->instruction_count++;
        return 1;
    case 0x000F8050u: /* 25 0A AND $0A */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8050"))return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Au) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8052u;
        instance->instruction_count++;
        return 1;
    case 0x000F8052u: /* 85 0E STA $0E */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8052"))return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Eu) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8054u;
        instance->instruction_count++;
        return 1;
    case 0x000F8054u: /* AE 1A 42 LDX $421A */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8054"))return 0;
        if (!tg_bus_read16(instance, (((uint32_t)instance->cpu.dbr << 16) | 0x421Au), &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8057u;
        instance->instruction_count++;
        return 1;
    case 0x000F8057u: /* A5 0C LDA $0C */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8057"))return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Cu) & 0xFFFFu), &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8059u;
        instance->instruction_count++;
        return 1;
    case 0x000F8059u: /* 86 0C STX $0C */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8059"))return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x0Cu) & 0xFFFFu), (uint16_t)instance->cpu.x)) return 0;
        instance->cpu.pc = 0x805Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F805Bu: /* 49 FF FF EOR #$FFFF */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:805B"))return 0;
        word = 0xFFFFu;
        word = (uint16_t)((instance->cpu.a) ^ word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x805Eu;
        instance->instruction_count++;
        return 1;
    case 0x000F805Eu: /* 05 10 ORA $10 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:805E"))return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x10u) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) | word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8060u;
        instance->instruction_count++;
        return 1;
    case 0x000F8060u: /* 25 0C AND $0C */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8060"))return 0;
        if (!tg_bus_read16(instance, (uint32_t)((instance->cpu.d + 0x0Cu) & 0xFFFFu), &word)) return 0;
        word = (uint16_t)((instance->cpu.a) & word);
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8062u;
        instance->instruction_count++;
        return 1;
    case 0x000F8062u: /* 85 10 STA $10 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8062"))return 0;
        if (!tg_bus_store16(instance, (uint32_t)((instance->cpu.d + 0x10u) & 0xFFFFu), instance->cpu.a)) return 0;
        instance->cpu.pc = 0x8064u;
        instance->instruction_count++;
        return 1;
    case 0x000F8064u: /* C2 30 REP #$30 */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8064"))return 0;
        instance->cpu.p &= (uint8_t)~0x30u;
        if (instance->cpu.e) instance->cpu.p |= (TG_P_M | TG_P_X);
        if (instance->cpu.e || (instance->cpu.p & TG_P_X) != 0u) { instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        instance->cpu.pc = 0x8066u;
        instance->instruction_count++;
        return 1;
    case 0x000F8066u: /* AB PLB */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_DBR | TG_CONTEXT_REQUIRE_D,"0F:8066"))return 0;
        if (!tg_pull8(instance, &byte)) return 0;
        instance->cpu.dbr = byte;
        tg_set_nz8(instance, byte);
        instance->cpu.pc = 0x8067u;
        instance->instruction_count++;
        return 1;
    case 0x000F8067u: /* 2B PLD */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,TG_CONTEXT_REQUIRE_D,"0F:8067"))return 0;
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.d = word;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8068u;
        instance->instruction_count++;
        return 1;
    case 0x000F8068u: /* 7A PLY */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8068"))return 0;
        if (!tg_pull16(instance, &word)) return 0;
        instance->cpu.y = word;
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x8069u;
        instance->instruction_count++;
        return 1;
    case 0x000F8069u: /* FA PLX */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:8069"))return 0;
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_index16(instance, &instance->cpu.x, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x806Au;
        instance->instruction_count++;
        return 1;
    case 0x000F806Au: /* 68 PLA */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:806A"))return 0;
        if (!tg_pull16(instance, &word)) return 0;
        tg_set_acc16(instance, word);
        tg_set_nz16(instance, word);
        instance->cpu.pc = 0x806Bu;
        instance->instruction_count++;
        return 1;
    case 0x000F806Bu: /* 40 RTI */
        if(!tg_require_context_masked(instance,0u,0u,0u,0x0Fu,0x0000u,0u,"0F:806B"))return 0;
        if (!tg_pull8(instance, &byte)) return 0;
        instance->cpu.p = byte;
        if (instance->cpu.e) { instance->cpu.p |= (TG_P_M | TG_P_X); instance->cpu.x &= 0x00FFu; instance->cpu.y &= 0x00FFu; }
        if (!tg_pull8(instance, &pcl) || !tg_pull8(instance, &pch) || !tg_pull8(instance, &pbr)) return 0;
        instance->cpu.pc = (uint16_t)((uint16_t)pcl | ((uint16_t)pch << 8));
        instance->cpu.pbr = pbr;
        instance->instruction_count++;
        return 1;
    default:return tg_fail_frontier(instance,"Unknown Version 16 first-NMI semantic context.",NULL);
    }
}
