#include "topgear_internal.h"
#include "topgear_v16_nmi_handler.h"
#include "topgear_v18_nmi_optional_dma.h"
#include "topgear_v22_interrupt_dispatch.h"
#include "topgear_v22_wram_epoch.h"
#include "topgear_v23_wram_epoch2.h"
#include "topgear_v23_wram_epoch3.h"
#include "topgear_v22_reentry_shards.h"

#include <string.h>
#include <stdio.h>

typedef int (*TgV22StaticStepFn)(TopGearRecomp *);

/* One generated function call is exactly one statically selected W65C816
   instruction.  Keep the hook boundary outside every ROM, re-entry, interrupt,
   and executable-WRAM shard so headless tools see one uniform instruction
   stream without introducing an opcode decoder. */
static int v22_hooked_static_step(TopGearRecomp *instance,TgV22StaticStepFn step){
    uint32_t address;
    if(!instance||!step||instance->failed||instance->hook_stop_requested)return 0;
    address=((uint32_t)instance->cpu.pbr<<16)|instance->cpu.pc;
    tg_emit_hook(instance,TOPGEAR_HOOK_EVENT_INSTRUCTION_BEFORE,address,0u,1u);
    if(instance->hook_stop_requested)return 0;
    if(!step(instance))return 0;
    tg_emit_hook(instance,TOPGEAR_HOOK_EVENT_INSTRUCTION_AFTER,address,0u,1u);
    /* Let the scheduler account this completed instruction's nominal time.
       The requested stop is observed before the following instruction. */
    return 1;
}

/* Interrupt vectors enter through tiny ROM-installed low-WRAM trampolines.
   These instructions are synthesized by the interrupt service because their
   bytes are copied at runtime, but they retain the same hook contract. */
static int v22_hooked_wram_jml(TopGearRecomp *instance,uint32_t target){
    uint32_t address=((uint32_t)instance->cpu.pbr<<16)|instance->cpu.pc;
    tg_emit_hook(instance,TOPGEAR_HOOK_EVENT_INSTRUCTION_BEFORE,address,0u,1u);
    if(instance->hook_stop_requested)return 0;
    instance->cpu.pbr=(uint8_t)(target>>16);instance->cpu.pc=(uint16_t)target;instance->instruction_count++;
    tg_emit_hook(instance,TOPGEAR_HOOK_EVENT_INSTRUCTION_AFTER,address,0u,1u);
    return 1;
}

static int v22_hooked_rep_34(TopGearRecomp *instance){
    uint32_t address=((uint32_t)instance->cpu.pbr<<16)|instance->cpu.pc;
    tg_emit_hook(instance,TOPGEAR_HOOK_EVENT_INSTRUCTION_BEFORE,address,0u,1u);
    if(instance->hook_stop_requested)return 0;
    instance->cpu.p&=(uint8_t)~0x34u;instance->cpu.pc=(uint16_t)(instance->cpu.pc+2u);instance->instruction_count++;
    tg_emit_hook(instance,TOPGEAR_HOOK_EVENT_INSTRUCTION_AFTER,address,0u,1u);
    return 1;
}

int topgear_recomp_v22_static_step(TopGearRecomp *instance) {
    return v22_hooked_static_step(instance,tg_v22_generated_static_step);
}

int topgear_recomp_v22_romwide_coverage_info(const TopGearRecomp *instance, TopGearV22RomwideCoverageInfo *info) {
    (void)instance;
    if (!info) return 0;
    memset(info, 0, sizeof(*info));
    info->analyser_context_count = 54330u;
    info->analyser_edge_count = 59559u;
    info->normalized_generated_context_count = tg_v22_generated_static_context_count();
    info->generated_address_count = tg_v22_generated_static_address_count();
    info->generated_shard_count = 29u;
    info->previously_generated_union_context_count = 1352u;
    info->newly_covered_normalized_context_count = info->normalized_generated_context_count - info->previously_generated_union_context_count;
    info->normalized_context_coverage_percent = info->normalized_generated_context_count == 8685u ? 100u : 0u;
    info->runtime_opcode_decoder_used = 0u;
    info->emulator_authority_used = 0u;
    info->audio_required_for_static_dispatch = 0u;
    tg_copy_text(info->claim_boundary, sizeof(info->claim_boundary),
        "Version 22 generates a fixed C dispatch case for all 8,685 normalized PBR:PC/E/M/X contexts emitted by the ROM-wide context-sensitive analyser. This certifies semantic/static dispatch surface coverage only; executable-WRAM epochs and physical scheduling/natural reachability remain separate proof obligations.");
    return 1;
}



static int v22_semantic_later_interrupt_body(TopGearRecomp *i,uint32_t target,uint8_t return_pbr,uint16_t return_pc,uint16_t return_s){
    uint32_t guard=0u;
    if(!v22_hooked_wram_jml(i,target))return 0;
    while(!i->failed&&guard++<200000u){
        unsigned v23_cycles=i->v23_event_mode?tg_v23_nominal_processor_cycles(i):0u;
        if(!v22_hooked_static_step(i,tg_v22_interrupt_semantic_step))return 0;
        if(i->v23_event_mode&&!tg_v23_advance_nominal_current_instruction(i,v23_cycles?v23_cycles:3u))return 0;
        if(i->cpu.pbr==return_pbr&&i->cpu.pc==return_pc&&i->cpu.s==return_s)return 1;
    }
    return tg_fail_frontier(i,"Version 22 later interrupt handler did not return to the interrupted main-core boundary.",NULL);
}

static int v22_semantic_interrupt_service(TopGearRecomp *i,int nmi){
    uint8_t return_pbr,pushed_p;uint16_t return_pc,return_s,vector;uint32_t target;
    if(!i||i->cpu.e)return tg_fail_frontier(i,"Version 22 main-core semantic interrupt service requires the reached native-mode CPU state.",NULL);
    if(nmi)i->v22_semantic_nmi_count++;else i->v22_semantic_irq_count++;
    return_pbr=i->cpu.pbr;return_pc=i->cpu.pc;return_s=i->cpu.s;pushed_p=i->cpu.p;
    if(!tg_push8(i,return_pbr)||!tg_push8(i,(uint8_t)(return_pc>>8))||!tg_push8(i,(uint8_t)return_pc)||!tg_push8(i,pushed_p))return 0;
    i->cpu.p|=TG_P_I;i->cpu.p&=(uint8_t)~TG_P_D;
    if(!tg_bus_read16(i,nmi?0x00FFEAu:0x00FFEEu,&vector))return 0;
    i->cpu.pbr=0u;i->cpu.pc=vector;
    if(i->v23_event_mode&&!tg_v23_advance_nominal_current_instruction(i,i->cpu.e?7u:8u))return 0;
    if(nmi)i->nmi_flag=1u;else i->irq_flag=1u;
    if(vector>4u||i->wram[vector]!=0x5Cu)
        return tg_fail_frontier(i,"Version 22 semantic interrupt did not find a proved low-WRAM JML trampoline.",NULL);
    target=(uint32_t)i->wram[vector+1u]|((uint32_t)i->wram[vector+2u]<<8)|((uint32_t)i->wram[vector+3u]<<16);
    if(nmi&&target==0x0F8000u){
        uint32_t guard=0u;
        if(!v22_hooked_wram_jml(i,0x0F8000u))return 0;
        if(i->v23_event_mode&&!tg_v23_advance_nominal_current_instruction(i,4u))return 0;
        if(!v22_hooked_rep_34(i))return 0;
        if(i->v23_event_mode&&!tg_v23_advance_nominal_current_instruction(i,3u))return 0;
        while(!i->failed&&guard++<2048u){
            unsigned v23_cycles=i->v23_event_mode?tg_v23_nominal_processor_cycles(i):0u;
            if(i->cpu.pbr==0x0Fu&&i->cpu.pc>=0xA21Au&&i->cpu.pc<=0xA23Du){
                if(!v22_hooked_static_step(i,tg_v18_generated_optional_nmi_semantic_step))return 0;
            }else if(!v22_hooked_static_step(i,tg_v16_generated_nmi_semantic_step))return 0;
            if(i->v23_event_mode&&!tg_v23_advance_nominal_current_instruction(i,v23_cycles?v23_cycles:3u))return 0;
            if(i->cpu.pbr==return_pbr&&i->cpu.pc==return_pc&&i->cpu.s==return_s)return 1;
        }
        return tg_fail_frontier(i,"Version 22 first-epoch semantic NMI did not RTI to its interrupted main-core boundary.","0F:8000");
    }
    if(nmi&&target!=0x00EC1Au)return tg_fail_frontier(i,"Version 22 later NMI trampoline target is outside the ROM-proved epoch family.","00:0000");
    if(!nmi&&target!=0x00EC5Bu)return tg_fail_frontier(i,"Version 22 IRQ trampoline target is outside the ROM-proved epoch family.","00:0004");
    return v22_semantic_later_interrupt_body(i,target,return_pbr,return_pc,return_s);
}

int tg_v22_semantic_service_nmi(TopGearRecomp *i){return v22_semantic_interrupt_service(i,1);}
int tg_v22_semantic_service_irq(TopGearRecomp *i){return v22_semantic_interrupt_service(i,0);}
static int v22_semantic_nmi_service(TopGearRecomp *i){return tg_v22_semantic_service_nmi(i);}
static int v22_semantic_irq_service(TopGearRecomp *i){return tg_v22_semantic_service_irq(i);}

void tg_v25_note_exec(TopGearRecomp *instance){
    uint8_t bank;uint16_t pc;uint32_t off,byte;uint8_t bit;
    if(!instance||!instance->v25_coverage_enabled)return;
    bank=instance->cpu.pbr;pc=instance->cpu.pc;instance->v25_coverage_instruction_count++;
    if(bank==0x7Eu){
        byte=(uint32_t)pc>>3;bit=(uint8_t)(1u<<(pc&7u));
        if((instance->v25_wram_exec_bitmap[byte]&bit)==0u){instance->v25_wram_exec_bitmap[byte]|=bit;instance->v25_unique_wram_addresses++;}
        return;
    }
    bank&=0x7Fu;
    if(bank<=0x0Fu&&pc>=0x8000u){
        off=(uint32_t)bank*0x8000u+(uint32_t)(pc-0x8000u);byte=off>>3;bit=(uint8_t)(1u<<(off&7u));
        instance->v25_rom_bank_instruction_counts[bank]++;
        if((instance->v25_rom_exec_bitmap[byte]&bit)==0u){instance->v25_rom_exec_bitmap[byte]|=bit;instance->v25_unique_rom_addresses++;instance->v25_rom_bank_unique_addresses[bank]++;}
    }
}

int tg_v22_semantic_static_step_any(TopGearRecomp *instance){
    uint32_t rkey;if(!instance)return 0;
    tg_v25_note_exec(instance);
    if(instance->cpu.pbr==0x7Eu){
        instance->v22_wram_static_steps++;rkey=tg_generated_context_key(instance);
        if(instance->v23_event_mode&&!instance->v23_wram_epoch_id&&instance->cpu.pc==0x290Au&&instance->wram[0x290Au]==0x99u&&!(instance->wram[0x290Bu]==0xFFu&&instance->wram[0x290Cu]==0xFFu))instance->v23_wram_epoch_id=1u;
        if(instance->v23_event_mode&&!instance->v23_wram_epoch_id&&instance->cpu.pc==0x3355u&&instance->wram[0x3355u]==0x99u&&!(instance->wram[0x3356u]==0xFFu&&instance->wram[0x3357u]==0xFFu))instance->v23_wram_epoch_id=1u;
        if(instance->v23_wram_epoch_id==1u){
            if(tg_v23_wram_epoch2_has_context(rkey))return v22_hooked_static_step(instance,tg_v23_wram_epoch2_semantic_step);
            instance->v23_wram_epoch_id=0u;
        }
        if(instance->v23_wram_epoch_id==2u){
            if(!tg_v23_wram_epoch3_has_context(rkey))return tg_fail_frontier(instance,"Version 23 executable-WRAM epoch 3 left its generated fixed context surface.",NULL);
            return v22_hooked_static_step(instance,tg_v23_wram_epoch3_semantic_step);
        }
        return v22_hooked_static_step(instance,tg_v22_wram_epoch_semantic_step);
    }
    rkey=tg_generated_context_key(instance);
    if(tg_v22_reentry_has_context(rkey)){instance->v22_reentry_static_steps++;return v22_hooked_static_step(instance,tg_v22_reentry_semantic_step);}
    instance->v22_romwide_static_steps++;return v22_hooked_static_step(instance,tg_v22_generated_static_step);
}

static int v22_semantic_wait_needs_nmi(TopGearRecomp *i){
    if(!i||i->cpu.pbr!=0x0Fu)return 0;
    if(i->cpu.pc==0xA251u && (uint8_t)i->cpu.a!=i->wram[8u])return 1;
    if(i->cpu.pc==0x9D27u && (i->wram[0x90u]!=0u||i->wram[0x91u]!=0u))return 1;
    return 0;
}

static int v22_semantic_wait_needs_irq(TopGearRecomp *i){
    if(!i)return 0;
    if(i->cpu.pbr==0x00u&&i->cpu.pc==0xCE43u&&((uint16_t)(i->wram[0x038Cu]|((uint16_t)i->wram[0x038Du]<<8))&0x8000u))return 1;
    if(i->cpu.pbr==0x00u&&i->cpu.pc==0xEC15u&&(i->wram[0x000Cu]!=0u||i->wram[0x000Du]!=0u))return 1;
    /* The main-game setup path deliberately waits on the sign bit of the
       overlapping $0051/$0052 raster state.  The ROM-owned IRQ phase
       selected through $000A advances this state (B4C4 -> ... -> B9xx).
       Service the generated IRQ path rather than editing the wait word. */
    if(i->cpu.pbr==0x00u&&i->cpu.pc==0x8506u&&((uint16_t)(i->wram[0x0051u]|((uint16_t)i->wram[0x0052u]<<8))&0x8000u))return 1;
    /* Later setup waits at $86C5/$86C7 until the raster IRQ phase machine
       advances $000C.  Keep the wait byte owned by the generated IRQ code. */
    if(i->cpu.pbr==0x00u&&i->cpu.pc==0x86C7u&&i->wram[0x000Cu]==0u&&i->wram[0x000Du]==0u)return 1;
    return 0;
}

enum TopGearRunResult topgear_recomp_v22_run_main_core_semantic(TopGearRecomp *instance,uint64_t max_instructions,TopGearV22MainCoreReport *report){
    uint64_t start;
    TopGearCpuState cpu;
    if(!instance||!report||max_instructions==0u)return TOPGEAR_RUN_ERROR;
    memset(report,0,sizeof(*report));
    instance->v22_semantic_main_mode=1u;
    start=instance->instruction_count;
    while(instance->instruction_count-start<max_instructions){
        if(v22_semantic_wait_needs_irq(instance)){
            if(!v22_semantic_irq_service(instance))break;
            continue;
        }
        if(v22_semantic_wait_needs_nmi(instance)){
            if(!v22_semantic_nmi_service(instance))break;
            continue;
        }
        if(instance->cpu.pbr==0x7Eu){
            instance->v22_wram_static_steps++;
            if(!v22_hooked_static_step(instance,tg_v22_wram_epoch_semantic_step))break;
        }else{
            uint32_t rkey=tg_generated_context_key(instance);
            if(tg_v22_reentry_has_context(rkey)){
                instance->v22_reentry_static_steps++;
                if(!v22_hooked_static_step(instance,tg_v22_reentry_semantic_step))break;
            }else{
                instance->v22_romwide_static_steps++;
                if(!v22_hooked_static_step(instance,tg_v22_generated_static_step))break;
            }
        }
    }
    report->executed_instructions=instance->instruction_count-start;
    topgear_recomp_cpu_state(instance,&cpu);report->endpoint_cpu=cpu;
    report->historical_cycle_audits_bypassed=1u;
    report->audio_timing_deferred=1u;
    report->functional_apu_bootstrap_only=1u;
    report->runtime_opcode_decoder_used=0u;
    report->emulator_authority_used=0u;
    report->reached_non_rom_execution=(uint8_t)(cpu.pbr==0x7Eu||cpu.pbr==0x7Fu);
    report->executable_wram_reached=(uint8_t)(instance->v22_wram_static_steps!=0u);
    report->semantic_nmi_count=instance->v22_semantic_nmi_count;
    report->semantic_irq_count=instance->v22_semantic_irq_count;
    report->semantic_hblank_read_count=instance->v22_semantic_hblank_read_count;
    report->audio_shim_event_count=(uint64_t)instance->v22_main_audio_bbaa_injected+(uint64_t)instance->v22_main_audio_echo_count;
    report->open_bus_read_count=instance->open_bus_read_count;
    report->controller_serial_read_count=instance->controller_serial_read_count;
    report->romwide_static_steps=instance->v22_romwide_static_steps;
    report->reentry_static_steps=instance->v22_reentry_static_steps;
    report->wram_static_steps=instance->v22_wram_static_steps;
    if(instance->frontier.reached){
        tg_copy_text(report->frontier_address,sizeof(report->frontier_address),instance->frontier.address);
        tg_copy_text(report->frontier_reason,sizeof(report->frontier_reason),instance->frontier.reason);
    }else{
        (void)snprintf(report->frontier_address,sizeof(report->frontier_address),"%02X:%04X",cpu.pbr,cpu.pc);
    }
    tg_copy_text(report->claim_boundary,sizeof(report->claim_boundary),
        "Version 22 main-core semantic mode executes generated fixed W65C816 ROM, post-WRAM ROM re-entry, ROM-owned interrupt, and executable-WRAM cases plus deterministic functional MMIO. It intentionally bypasses historical route-specific cycle-audit receipts and uses explicitly non-authoritative audio/HBlank timing shims only to prevent deferred timing subsystems from blocking broad CPU/PPU/static-core development. Physical audio and beam timing remain separate certification layers. Unknown ROM contexts, unproved indirect targets, or executable-WRAM byte changes still fail closed.");
    if(instance->failed){
        if(report->reached_non_rom_execution)return TOPGEAR_RUN_FRONTIER;
        return TOPGEAR_RUN_ERROR;
    }
    return TOPGEAR_RUN_COMPLETE;
}
