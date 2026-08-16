#include "topgear_internal.h"
#include "topgear_v23_nominal_timing.h"
#include "topgear_v22_wram_epoch.h"
#include "topgear_v22_reentry_shards.h"
#include <string.h>
#include <stdio.h>

static uint16_t v23_line_period(const TopGearRecomp *i){return (uint16_t)((i->v23_event_field&&i->v23_event_vcounter==240u)?1360u:1364u);}
static uint16_t v23_refresh_position(const TopGearRecomp *i){return (uint16_t)(538u-(i->v23_event_cpu_mod8&7u));}
static uint8_t v23_hdma_mode_length(uint8_t mode){static const uint8_t n[8]={1,2,2,4,4,4,2,4};return n[mode&7u];}
static uint8_t v23_hdma_bbus_offset(uint8_t mode,uint8_t index){static const uint8_t p[8][4]={{0,0,0,0},{0,1,0,1},{0,0,0,0},{0,0,1,1},{0,1,2,3},{0,1,0,1},{0,0,0,0},{0,0,1,1}};return p[mode&7u][index&3u];}

static void v23_complete_autojoy(TopGearRecomp *i){unsigned n;i->autojoy_result[0]=i->controller_state[0];i->autojoy_result[1]=i->controller_state[1];i->autojoy_result[2]=0u;i->autojoy_result[3]=0u;for(n=0;n<4;n++){i->cpu_io_registers[0x18u+n*2u]=(uint8_t)i->autojoy_result[n];i->cpu_io_registers[0x19u+n*2u]=(uint8_t)(i->autojoy_result[n]>>8);}i->autojoy_busy=0u;i->v23_event_autojoy_remaining=0u;i->v23_event_autojoy_completion_count++;}
static void v23_begin_autojoy(TopGearRecomp *i){if((i->nmitimen&1u)==0u)return;i->autojoy_busy=1u;i->v23_event_autojoy_remaining=4224u;i->v23_event_autojoy_start_count++;}

static int v23_hdma_read8(TopGearRecomp *i,uint32_t a,uint8_t *v){return tg_bus_read8(i,a,v);}
static int v23_hdma_reload(TopGearRecomp *i,unsigned ch){unsigned reg=0x100u+ch*0x10u;uint8_t bank=i->cpu_io_registers[reg+4u],dmap=i->cpu_io_registers[reg],line,lo,hi;if(!v23_hdma_read8(i,((uint32_t)bank<<16)|i->hdma_table_address[ch],&line))return 0;i->hdma_table_address[ch]++;i->hdma_line_counter[ch]=line;if(!line){i->hdma_active_mask&=(uint8_t)~(1u<<ch);i->hdma_completed_mask|=(uint8_t)(1u<<ch);i->hdma_do_transfer[ch]=0u;i->hdma_channel_completion_count++;return 1;}i->hdma_do_transfer[ch]=1u;if(dmap&0x40u){if(!v23_hdma_read8(i,((uint32_t)bank<<16)|i->hdma_table_address[ch]++,&lo)||!v23_hdma_read8(i,((uint32_t)bank<<16)|i->hdma_table_address[ch]++,&hi))return 0;i->hdma_indirect_address[ch]=(uint16_t)(lo|((uint16_t)hi<<8));}return 1;}
static int v23_hdma_setup(TopGearRecomp *i){unsigned ch;i->hdma_active_mask=i->hdma_enable_mask;i->hdma_completed_mask=0u;if(!i->hdma_active_mask)return 1;i->hdma_frame_setup_count++;for(ch=0;ch<8;ch++){unsigned reg=0x100u+ch*0x10u;if((i->hdma_active_mask&(1u<<ch))==0u)continue;i->hdma_table_address[ch]=(uint16_t)(i->cpu_io_registers[reg+2u]|((uint16_t)i->cpu_io_registers[reg+3u]<<8));i->hdma_line_counter[ch]=0u;i->hdma_do_transfer[ch]=1u;i->hdma_channel_setup_count++;if(!v23_hdma_reload(i,ch))return 0;}return 1;}
static int v23_hdma_line(TopGearRecomp *i){unsigned ch;uint8_t n;if(!i->hdma_active_mask)return 1;i->hdma_scanline_run_count++;for(ch=0;ch<8;ch++){unsigned reg=0x100u+ch*0x10u;uint8_t bit=(uint8_t)(1u<<ch),dmap,mode,indirect,direction,bbad,bank,len;if((i->hdma_active_mask&bit)==0u)continue;dmap=i->cpu_io_registers[reg];mode=dmap&7u;indirect=(dmap>>6)&1u;direction=(dmap>>7)&1u;bbad=i->cpu_io_registers[reg+1u];bank=indirect?i->cpu_io_registers[reg+7u]:i->cpu_io_registers[reg+4u];if(direction)return tg_fail_frontier(i,"Version 23 non-audio scheduler reached an unimplemented B-to-A HDMA transfer.","HDMA");if(i->hdma_do_transfer[ch]){len=v23_hdma_mode_length(mode);for(n=0;n<len;n++){uint16_t *src=indirect?&i->hdma_indirect_address[ch]:&i->hdma_table_address[ch];uint32_t a=((uint32_t)bank<<16)|*src;uint16_t b=(uint16_t)(0x2100u+bbad+v23_hdma_bbus_offset(mode,n));uint8_t data;if(!v23_hdma_read8(i,a,&data)||!tg_ppu_write(i,b,data))return 0;(*src)++;i->hdma_bytes_transferred++;if(indirect)i->hdma_indirect_transfer_bytes++;else i->hdma_direct_transfer_bytes++;}}i->hdma_line_counter[ch]--;i->hdma_do_transfer[ch]=(uint8_t)((i->hdma_line_counter[ch]>>7)&1u);if((i->hdma_line_counter[ch]&0x7fu)==0u&&!v23_hdma_reload(i,ch))return 0;}return 1;}

static void v23_irq_poll(TopGearRecomp *i){uint8_t h=(i->nmitimen>>4)&1u,v=(i->nmitimen>>5)&1u;uint16_t th=(uint16_t)((i->htime_target+1u)*4u);int level;if(!h&&!v){i->v23_event_irq_line=0u;return;}level=(!v||i->v23_event_vcounter==i->vtime_target)&&(!h||i->v23_event_hcounter>=th);if(level&&!i->v23_event_irq_line){i->v23_event_irq_pending=1u;i->irq_flag=1u;}i->v23_event_irq_line=(uint8_t)level;}
static uint64_t v24_fnv_bytes(uint64_t h,const void *data,size_t n){const uint8_t *p=(const uint8_t*)data;size_t k;for(k=0;k<n;k++){h^=p[k];h*=1099511628211ull;}return h;}
static void v24_emit_frame(TopGearRecomp *i){
    TopGearV24FrameInfo f; uint8_t bgmode;
    if(!i->v24_trace_enabled)return;
    memset(&f,0,sizeof(f));
    f.frame_index=i->v23_event_frame_count-i->v24_frame_index_base-1u;
    f.absolute_master_clock=i->v23_event_master_clock;
    f.elapsed_master_clocks=i->v23_event_master_clock-186u;
    f.hcounter_master=i->v23_event_hcounter; f.vcounter_line=i->v23_event_vcounter; f.field=i->v23_event_field;
    bgmode=i->ppu_registers[5u]; f.bgmode_value=bgmode; f.mode=(uint8_t)(bgmode&7u);
    f.main_screen_mask=(uint8_t)(i->ppu_registers[0x2cu]&0x1fu); f.sub_screen_mask=(uint8_t)(i->ppu_registers[0x2du]&0x1fu);
    tg_copy_text(f.bgr555_sha256,sizeof(f.bgr555_sha256),i->v23_event_last_frame_sha256);
    if(f.frame_index==0u)tg_copy_text(i->v24_first_frame_sha256,sizeof(i->v24_first_frame_sha256),f.bgr555_sha256);
    i->v24_frame_sequence_fnv1a64=v24_fnv_bytes(i->v24_frame_sequence_fnv1a64,f.bgr555_sha256,64u);
    i->v24_frame_sequence_fnv1a64=v24_fnv_bytes(i->v24_frame_sequence_fnv1a64,&f.absolute_master_clock,sizeof(f.absolute_master_clock));
    i->v24_frame_sequence_fnv1a64=v24_fnv_bytes(i->v24_frame_sequence_fnv1a64,&bgmode,sizeof(bgmode));
    if(i->v24_frame_callback)i->v24_frame_callback(i->v24_frame_callback_user,&f);
}
static void v23_line_start(TopGearRecomp *i){i->v23_event_line_period=v23_line_period(i);i->v23_event_refresh_done=0u;i->v23_event_refresh_position=v23_refresh_position(i);i->v23_event_seen_scanline_render=0u;if(i->v23_event_vcounter==0u){(void)v23_hdma_setup(i);i->nmi_flag=0u;i->v23_event_nmi_issued_this_vblank=0u;}if(i->v23_event_vcounter==225u){i->nmi_flag=1u;if(i->nmitimen&0x80u){i->v23_event_nmi_pending=1u;i->v23_event_nmi_issued_this_vblank=1u;}v23_begin_autojoy(i);}if(i->v23_event_vcounter==240u){tg_sha256_hex(i->mode1_frame,sizeof(i->mode1_frame),i->v23_event_last_frame_sha256);/* APUIO accesses synchronize at their precise event-order positions.  At V=240 the static APU must also accept the frame-boundary rendezvous before video may publish a completed frame/checkpoint. */if(!tg_audio_backend_sync(i,i->v23_event_master_clock))return;i->v23_event_frame_count++;i->v23_event_frame_ready=1u;v24_emit_frame(i);tg_emit_hook(i,TOPGEAR_HOOK_EVENT_CHECKPOINT,((uint32_t)i->cpu.pbr<<16)|i->cpu.pc,0u,1u);}v23_irq_poll(i);}
static void v23_advance_raw(TopGearRecomp *i,uint32_t clocks){i->v23_event_master_clock+=clocks;i->scpu_master_clock=i->v23_event_master_clock;i->v23_event_cpu_mod8=(uint8_t)((i->v23_event_cpu_mod8+clocks)&7u);if(i->autojoy_busy){if(clocks>=i->v23_event_autojoy_remaining)v23_complete_autojoy(i);else i->v23_event_autojoy_remaining-=clocks;}i->v23_event_hcounter=(uint16_t)(i->v23_event_hcounter+clocks);i->hcounter_master=i->v23_event_hcounter;i->vcounter_line=i->v23_event_vcounter;}

int tg_v23_advance_master_clocks(TopGearRecomp *i,uint32_t clocks){uint32_t remain=clocks;if(!i||!i->v23_event_mode)return 0;while(remain&&!i->failed){uint16_t h=i->v23_event_hcounter,period=i->v23_event_line_period;uint32_t step=remain;uint16_t next=period;uint16_t th=(uint16_t)((i->htime_target+1u)*4u);if(!i->v23_event_refresh_done&&i->v23_event_refresh_position>h&&i->v23_event_refresh_position<next)next=i->v23_event_refresh_position;if(i->v23_event_vcounter<224u&&!i->v23_event_seen_scanline_render&&1080u>h&&1080u<next)next=1080u;if(i->v23_event_vcounter<224u&&i->hdma_active_mask&&1104u>h&&1104u<next)next=1104u;if((i->nmitimen&0x10u)&&th>h&&th<next)next=th;if((uint32_t)(next-h)<step)step=(uint32_t)(next-h);if(step){v23_advance_raw(i,step);remain-=step;}h=i->v23_event_hcounter;if(!i->v23_event_refresh_done&&h==i->v23_event_refresh_position){i->v23_event_refresh_done=1u;i->v23_event_refresh_count++;/* Ricoh 5A22 v2 refresh consumes 40 master clocks. */v23_advance_raw(i,40u);continue;}if(i->v23_event_vcounter<224u&&!i->v23_event_seen_scanline_render&&h>=1080u){if(!tg_v23_render_scanline(i,i->v23_event_vcounter))return 0;i->v23_event_seen_scanline_render=1u;i->v23_event_scanline_render_count++;continue;}if(i->v23_event_vcounter<224u&&i->hdma_active_mask&&h==1104u){if(!v23_hdma_line(i))return 0;/* prevent retrigger at same H */v23_advance_raw(i,2u);continue;}v23_irq_poll(i);if(h>=period){i->v23_event_hcounter=(uint16_t)(h-period);i->hcounter_master=i->v23_event_hcounter;i->v23_event_vcounter++;if(i->v23_event_vcounter>=262u){i->v23_event_vcounter=0u;i->v23_event_field^=1u;}i->vcounter_line=i->v23_event_vcounter;v23_line_start(i);continue;}if(step==0u){/* Event at current H already consumed; guarantee progress. */v23_advance_raw(i,2u);if(remain>=2u)remain-=2u;else remain=0u;}}
return i->failed?0:1;}

int tg_v23_advance_nominal_current_instruction(TopGearRecomp *i,unsigned cycles){if(!i||!i->v23_event_mode)return 0;if(!cycles){i->v23_event_timing_context_miss_count++;cycles=3u;}i->v23_event_nominal_processor_cycles+=cycles;return tg_v23_advance_master_clocks(i,cycles*8u);}

static int v23_service_interrupts(TopGearRecomp *i){if(i->v23_event_nmi_pending&&!i->v23_event_in_interrupt){i->v23_event_nmi_pending=0u;i->v23_event_in_interrupt=1u;if(!tg_v22_semantic_service_nmi(i))return 0;i->v23_event_in_interrupt=0u;i->v23_event_nmi_count++;return 1;}if(i->v23_event_irq_pending&&!i->v23_event_in_interrupt&&(i->cpu.p&TG_P_I)==0u){i->v23_event_irq_pending=0u;i->v23_event_in_interrupt=1u;if(!tg_v22_semantic_service_irq(i))return 0;i->v23_event_in_interrupt=0u;i->v23_event_irq_count++;return 1;}return 1;}

static void v23_initialize(TopGearRecomp *i){i->v23_event_mode=1u;i->v22_semantic_main_mode=1u;i->v23_event_audio_deferred=0u;i->v23_event_master_clock=186u;i->scpu_master_clock=186u;i->v23_event_hcounter=186u;i->hcounter_master=186u;i->v23_event_vcounter=0u;i->vcounter_line=0u;i->v23_event_field=0u;i->v23_event_cpu_mod8=2u;i->v23_event_line_period=1364u;i->v23_event_refresh_position=v23_refresh_position(i);i->v23_event_refresh_done=0u;i->v23_event_last_frame_sha256[0]='\0';i->v24_frame_callback=NULL;i->v24_frame_callback_user=NULL;i->v24_frame_index_base=0u;i->v24_frame_sequence_fnv1a64=1469598103934665603ull;i->v24_trace_enabled=0u;i->v24_observed_bgmode_mask=0u;i->v24_first_frame_sha256[0]='\0';}

enum TopGearRunResult topgear_recomp_v23_run_main_core_events(TopGearRecomp *i,uint64_t max_instructions,uint32_t stop_after_frames,TopGearV23EventReport *r){uint64_t start,frames0,dma0;TopGearCpuState cpu;if(!i||!r||!max_instructions)return TOPGEAR_RUN_ERROR;memset(r,0,sizeof(*r));v23_initialize(i);start=i->instruction_count;frames0=i->v23_event_frame_count;while(!i->failed&&i->instruction_count-start<max_instructions){unsigned cy;uint64_t before_dma;if(stop_after_frames&&i->v23_event_frame_count-frames0>=stop_after_frames)break;if(!v23_service_interrupts(i))break;if(i->v23_event_nmi_pending||(i->v23_event_irq_pending&&(i->cpu.p&TG_P_I)==0u))continue;cy=tg_v23_nominal_processor_cycles(i);if(!cy){i->v23_event_timing_context_miss_count++;cy=3u;}before_dma=i->dma_master_clocks_accounted;if(!tg_v22_semantic_static_step_any(i))break;dma0=i->dma_master_clocks_accounted-before_dma;if(!tg_v23_advance_nominal_current_instruction(i,cy))break;if(dma0&&!tg_v23_advance_master_clocks(i,(uint32_t)(dma0>0xffffffffu?0xffffffffu:dma0)))break;/* Enabling NMI during an already-active vblank produces a transition. */if((i->nmitimen&0x80u)&&i->v23_event_vcounter>=225u&&!i->v23_event_in_interrupt&&!i->v23_event_nmi_issued_this_vblank){i->v23_event_nmi_pending=1u;i->v23_event_nmi_issued_this_vblank=1u;}}
topgear_recomp_cpu_state(i,&cpu);r->executed_instructions=i->instruction_count-start;r->endpoint_cpu=cpu;r->nominal_processor_cycles=i->v23_event_nominal_processor_cycles;r->elapsed_master_clocks=i->v23_event_master_clock-186u;r->refresh_events=i->v23_event_refresh_count;r->nmi_count=i->v23_event_nmi_count;r->irq_count=i->v23_event_irq_count;r->frame_events=i->v23_event_frame_count-frames0;r->scanlines_rendered=i->v23_event_scanline_render_count;r->autojoy_start_count=i->v23_event_autojoy_start_count;r->autojoy_completion_count=i->v23_event_autojoy_completion_count;r->timing_context_miss_count=i->v23_event_timing_context_miss_count;r->hcounter_master=i->v23_event_hcounter;r->vcounter_line=i->v23_event_vcounter;r->field=i->v23_event_field;r->audio_deferred=i->v23_event_audio_deferred;r->runtime_opcode_decoder_used=0u;r->emulator_authority_used=0u;r->event_order_scheduler=1u;r->physical_bus_cycle_certified=0u;r->audio_shim_event_count=(uint64_t)i->v22_main_audio_bbaa_injected+i->v22_main_audio_echo_count;tg_copy_text(r->frame_bgr555_sha256,sizeof(r->frame_bgr555_sha256),i->v23_event_last_frame_sha256);if(i->frontier.reached){tg_copy_text(r->frontier_address,sizeof(r->frontier_address),i->frontier.address);tg_copy_text(r->frontier_reason,sizeof(r->frontier_reason),i->frontier.reason);}else (void)snprintf(r->frontier_address,sizeof(r->frontier_address),"%02X:%04X",cpu.pbr,cpu.pc);tg_copy_text(r->claim_boundary,sizeof(r->claim_boundary),"Version 23 runs the broad fail-closed Version 22 static CPU surface under a non-audio SNES event-order scheduler. Instruction timing is generated statically for 24,899 reached contexts and never runtime-decodes an opcode, but it deliberately uses nominal W65C816 processor-cycle classes rather than claiming exact 5A22 per-bus wait timing. The scheduler supplies NTSC beam order, v2 refresh stalls, H/V IRQ/NMI boundaries, auto-joy, functional HDMA setup/visible transfers, and scanline-state rendering. Version 27 joins APUIO to the fail-closed Full Static S-SMP/S-DSP authority at event-order master-clock boundaries and emits static PCM. Exact physical 5A22 per-bus wait timing remains a separate certification layer.");return i->failed?TOPGEAR_RUN_FRONTIER:TOPGEAR_RUN_COMPLETE;}



enum TopGearRunResult topgear_recomp_v27_advance_frame(TopGearRecomp *i,uint16_t p1_mask,uint16_t p2_mask,uint64_t max_instructions){
    uint64_t start,frame0;
    if(!i||max_instructions==0u)return TOPGEAR_RUN_ERROR;
    if(!i->v27_realtime_initialized){
        v23_initialize(i);
        i->v27_realtime_initialized=1u;
    }
    if(!topgear_recomp_v08_set_controller_state(i,0u,p1_mask)||!topgear_recomp_v08_set_controller_state(i,1u,p2_mask))return TOPGEAR_RUN_ERROR;
    start=i->instruction_count;frame0=i->v23_event_frame_count;
    while(!i->failed&&i->v23_event_frame_count==frame0&&i->instruction_count-start<max_instructions){
        unsigned cy;uint64_t before_dma,dma0;
        if(!v23_service_interrupts(i))break;
        if(i->v23_event_nmi_pending||(i->v23_event_irq_pending&&(i->cpu.p&TG_P_I)==0u))continue;
        cy=tg_v23_nominal_processor_cycles(i);if(!cy){i->v23_event_timing_context_miss_count++;cy=3u;}
        before_dma=i->dma_master_clocks_accounted;
        if(!tg_v22_semantic_static_step_any(i))break;
        dma0=i->dma_master_clocks_accounted-before_dma;
        if(!tg_v23_advance_nominal_current_instruction(i,cy))break;
        if(dma0&&!tg_v23_advance_master_clocks(i,(uint32_t)(dma0>0xffffffffu?0xffffffffu:dma0)))break;
        if((i->nmitimen&0x80u)&&i->v23_event_vcounter>=225u&&!i->v23_event_in_interrupt&&!i->v23_event_nmi_issued_this_vblank){i->v23_event_nmi_pending=1u;i->v23_event_nmi_issued_this_vblank=1u;}
    }
    if(i->failed)return TOPGEAR_RUN_FRONTIER;
    return i->v23_event_frame_count>frame0?TOPGEAR_RUN_COMPLETE:TOPGEAR_RUN_FRONTIER;
}

uint64_t topgear_recomp_v27_frame_count(const TopGearRecomp *i){return i?i->v23_event_frame_count:0u;}

/* Reset-oriented characterization runner: every call initializes the Version 23
   event timeline at power-on.  It is not the continuation API for a loaded
   snapshot.  Snapshot/replay tests and the frontend continue with the
   idempotently initialized topgear_recomp_v27_advance_frame() path instead. */
enum TopGearRunResult topgear_recomp_v24_run_main_core_seconds(TopGearRecomp *i,uint32_t seconds,uint64_t max_instructions,TopGearV24FrameCallback cb,void *user,TopGearV24DurationReport *r){
    uint64_t start,frames0,dma0,target,elapsed;
    TopGearCpuState cpu;
    if(!i||!r||seconds==0u||seconds>86400u||max_instructions==0u)return TOPGEAR_RUN_ERROR;
    memset(r,0,sizeof(*r));
    v23_initialize(i);
    start=i->instruction_count;frames0=i->v23_event_frame_count;
    target=(236250000ull*(uint64_t)seconds+5ull)/11ull;
    i->v24_trace_enabled=1u;i->v24_frame_callback=cb;i->v24_frame_callback_user=user;i->v24_frame_index_base=frames0;
    i->v24_frame_sequence_fnv1a64=1469598103934665603ull;i->v24_observed_bgmode_mask=(uint8_t)(1u<<(i->ppu_registers[5u]&7u));i->v24_first_frame_sha256[0]='\0';
    while(!i->failed&&i->instruction_count-start<max_instructions){
        unsigned cy;uint64_t before_dma;
        elapsed=i->v23_event_master_clock-186u;if(elapsed>=target)break;
        if(!v23_service_interrupts(i))break;
        if(i->v23_event_nmi_pending||(i->v23_event_irq_pending&&(i->cpu.p&TG_P_I)==0u))continue;
        cy=tg_v23_nominal_processor_cycles(i);if(!cy){i->v23_event_timing_context_miss_count++;cy=3u;}
        before_dma=i->dma_master_clocks_accounted;
        if(!tg_v22_semantic_static_step_any(i))break;
        i->v24_observed_bgmode_mask|=(uint8_t)(1u<<(i->ppu_registers[5u]&7u));
        dma0=i->dma_master_clocks_accounted-before_dma;
        if(!tg_v23_advance_nominal_current_instruction(i,cy))break;
        if(dma0&&!tg_v23_advance_master_clocks(i,(uint32_t)(dma0>0xffffffffu?0xffffffffu:dma0)))break;
        if((i->nmitimen&0x80u)&&i->v23_event_vcounter>=225u&&!i->v23_event_in_interrupt&&!i->v23_event_nmi_issued_this_vblank){i->v23_event_nmi_pending=1u;i->v23_event_nmi_issued_this_vblank=1u;}
    }
    i->v24_frame_callback=NULL;i->v24_frame_callback_user=NULL;i->v24_trace_enabled=0u;
    topgear_recomp_cpu_state(i,&cpu);elapsed=i->v23_event_master_clock-186u;
    r->requested_seconds=seconds;r->target_master_clocks=target;r->achieved_master_clocks=elapsed;r->executed_instructions=i->instruction_count-start;r->endpoint_cpu=cpu;
    r->frame_events=i->v23_event_frame_count-frames0;r->refresh_events=i->v23_event_refresh_count;r->nmi_count=i->v23_event_nmi_count;r->irq_count=i->v23_event_irq_count;
    r->autojoy_start_count=i->v23_event_autojoy_start_count;r->autojoy_completion_count=i->v23_event_autojoy_completion_count;r->timing_context_miss_count=i->v23_event_timing_context_miss_count;
    r->frame_sequence_fnv1a64=i->v24_frame_sequence_fnv1a64;r->observed_bgmode_mask=i->v24_observed_bgmode_mask;r->audio_deferred=i->v23_event_audio_deferred;r->runtime_opcode_decoder_used=0u;r->emulator_authority_used=0u;r->event_order_scheduler=1u;r->physical_bus_cycle_certified=0u;
    r->instruction_limit_hit=(uint8_t)(!i->failed&&elapsed<target&&i->instruction_count-start>=max_instructions);
    tg_copy_text(r->first_frame_bgr555_sha256,sizeof(r->first_frame_bgr555_sha256),i->v24_first_frame_sha256);tg_copy_text(r->last_frame_bgr555_sha256,sizeof(r->last_frame_bgr555_sha256),i->v23_event_last_frame_sha256);
    if(i->frontier.reached){tg_copy_text(r->frontier_address,sizeof(r->frontier_address),i->frontier.address);tg_copy_text(r->frontier_reason,sizeof(r->frontier_reason),i->frontier.reason);}else (void)snprintf(r->frontier_address,sizeof(r->frontier_address),"%02X:%04X",cpu.pbr,cpu.pc);
    tg_copy_text(r->claim_boundary,sizeof(r->claim_boundary),"Version 24 duration-run receipt drives the broad static S-CPU core from reset under the Version 23 non-audio event-order scheduler for a requested NTSC master-clock duration (236250000/11 Hz). Every V=240 completed-frame event can be traced with its framebuffer hash and BGMODE. Audio is generated by the Version 27 fail-closed Full Static S-SMP/S-DSP lane at the same event-order master-clock timeline. This is a deterministic functional/event-order run, not an exact per-bus-cycle 5A22 timing certificate and not emulator execution.");
    if(i->failed)return TOPGEAR_RUN_FRONTIER;
    return elapsed>=target?TOPGEAR_RUN_COMPLETE:TOPGEAR_RUN_FRONTIER;
}

int topgear_recomp_v25_begin_coverage(TopGearRecomp *i){
    if(!i)return 0;
    i->v25_coverage_enabled=1u;
    i->v25_apu_read_mask=i->v25_apu_write_mask=i->v25_dma_channel_touched_mask=0u;
    i->v25_dma_register_offset_mask=0u;i->v25_cpuio_read_mask=i->v25_cpuio_write_mask=0u;
    i->v25_ppu_read_mask=i->v25_ppu_write_mask=0u;i->v25_coverage_instruction_count=0u;
    i->v25_unique_rom_addresses=i->v25_unique_wram_addresses=0u;
    memset(i->v25_rom_bank_instruction_counts,0,sizeof(i->v25_rom_bank_instruction_counts));
    memset(i->v25_rom_bank_unique_addresses,0,sizeof(i->v25_rom_bank_unique_addresses));
    memset(i->v25_rom_exec_bitmap,0,sizeof(i->v25_rom_exec_bitmap));
    memset(i->v25_wram_exec_bitmap,0,sizeof(i->v25_wram_exec_bitmap));
    return 1;
}

int topgear_recomp_v25_coverage_info(const TopGearRecomp *i,TopGearV25CoverageInfo *x){
    if(!i||!x)return 0;
    memset(x,0,sizeof(*x));
    x->instructions_observed=i->v25_coverage_instruction_count;x->unique_rom_addresses=i->v25_unique_rom_addresses;x->unique_wram_addresses=i->v25_unique_wram_addresses;
    memcpy(x->rom_bank_instruction_counts,i->v25_rom_bank_instruction_counts,sizeof(x->rom_bank_instruction_counts));
    memcpy(x->rom_bank_unique_addresses,i->v25_rom_bank_unique_addresses,sizeof(x->rom_bank_unique_addresses));
    x->ppu_read_mask=i->v25_ppu_read_mask;x->ppu_write_mask=i->v25_ppu_write_mask;x->cpuio_read_mask=i->v25_cpuio_read_mask;x->cpuio_write_mask=i->v25_cpuio_write_mask;
    x->dma_register_offset_mask=i->v25_dma_register_offset_mask;x->dma_channel_touched_mask=i->v25_dma_channel_touched_mask;x->apu_read_mask=i->v25_apu_read_mask;x->apu_write_mask=i->v25_apu_write_mask;
    x->runtime_opcode_decoder_used=0u;x->emulator_authority_used=0u;
    tg_copy_text(x->claim_boundary,sizeof(x->claim_boundary),"Version 25 coverage is an observation layer over the already-generated fail-closed static CPU surface. It records reached ROM/WRAM instruction addresses and MMIO register classes without decoding opcodes, changing CPU state, or using an emulator as execution authority.");
    return 1;
}
