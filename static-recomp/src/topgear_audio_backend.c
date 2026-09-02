#include "topgear_internal.h"
#include "sc_static_apu.h"
#include <stdio.h>
#include <string.h>

/* TOP GEAR FULL STATIC AUDIO BOUNDARY
   -----------------------------------
   The static core has exactly one audio authority:
     * the real Top Gear IPL/program upload reaches S-SMP through APUIO;
     * later S-SMP execution is accepted only at generated exact PC/opcode
       contexts and fails closed on unknown PCs/opcodes or compiled-code writes;
     * the runtime contains no selectable hybrid/reference backend and no
       generic SPC700 fallback;
     * S-DSP runs the fixed static signal path and emits 32,040 Hz stereo PCM
       into the deterministic core FIFO.

   Historical comparison implementations are not part of this source tree or
   build graph. Future S-SMP gaps must be repaired from ROM/ARAM provenance and
   regenerated AOT authority, never by switching runtime backends. */

static void audio_pcm_sink(void *context,int16_t left,int16_t right){
    TopGearRecomp *instance=(TopGearRecomp*)context;
    if(!instance)return;
    tg_audio_push_frame(instance,left,right);
    instance->pcm_frames_produced++;
}

static int copy_static_error(TopGearRecomp *instance,const char *operation,const char *detail){
    char message[320];
    if(!instance)return 0;
    (void)snprintf(message,sizeof(message),"Full Static audio %s failed: %.220s",operation,detail&&detail[0]?detail:"unspecified error");
    instance->static_audio_failed=1u;
    return tg_fail_frontier(instance,message,"STATIC-APU");
}

int tg_audio_backend_reset(TopGearRecomp *instance,char *error,size_t cap){
    if(!instance)return 0;
    instance->audio_last_apu_master_clock=0u;
    if(!instance->static_audio_acquired){
        if(!sc_static_apu_acquire(error,cap))return 0;
        instance->static_audio_acquired=1u;
    }else{
        sc_static_apu_reset();
        if(error&&cap)error[0]='\0';
    }
    sc_static_apu_set_sink(audio_pcm_sink,instance);
    sc_static_apu_set_trace_callbacks(NULL);
    instance->static_audio_failed=0u;
    return 1;
}

void tg_audio_backend_release(TopGearRecomp *instance){
    if(!instance)return;
    if(instance->static_audio_acquired){
        sc_static_apu_release();
        instance->static_audio_acquired=0u;
    }
}

int tg_audio_backend_sync(TopGearRecomp *instance,uint64_t master_clock){
    char error[224];
    if(!instance)return 0;
    if(!instance->static_audio_acquired)return copy_static_error(instance,"synchronization","static APU is not acquired");
    if(!sc_static_apu_sync_to_master(master_clock,error,sizeof(error)))return copy_static_error(instance,"synchronization",error);
    /* Commit the mirror only after the static engine accepts the rendezvous.
       The former dual-backend code updated it before dispatch, leaving a false
       clock in snapshots/status whenever a fail-closed sync was rejected. */
    instance->audio_last_apu_master_clock=master_clock;
    return 1;
}

int tg_audio_backend_cpu_write_port(TopGearRecomp *instance,uint64_t master_clock,unsigned port,uint8_t value){
    char error[224];
    if(!instance||port>=4u)return 0;
    if(!instance->static_audio_acquired)return copy_static_error(instance,"CPU port write","static APU is not acquired");
    if(!sc_static_apu_cpu_write_port(master_clock,port,value,error,sizeof(error)))return copy_static_error(instance,"CPU port write",error);
    instance->audio_last_apu_master_clock=master_clock;
    return 1;
}

int tg_audio_backend_cpu_read_port(TopGearRecomp *instance,uint64_t master_clock,unsigned port,uint8_t *value){
    char error[224];int ok=0;
    if(!instance||!value||port>=4u)return 0;
    if(!instance->static_audio_acquired)return copy_static_error(instance,"CPU port read","static APU is not acquired");
    *value=sc_static_apu_cpu_read_port(master_clock,port,&ok,error,sizeof(error));
    if(!ok)return copy_static_error(instance,"CPU port read",error);
    instance->audio_last_apu_master_clock=master_clock;
    instance->smp_to_scpu[port]=*value;
    return 1;
}

int tg_audio_backend_read_aram(const TopGearRecomp *instance,uint32_t offset,void *output,size_t bytes){
    if(!instance||!output||offset>TOPGEAR_RECOMP_ARAM_SIZE||bytes>TOPGEAR_RECOMP_ARAM_SIZE-offset||!instance->static_audio_acquired)return 0;
    return sc_static_apu_read_aram(offset,output,bytes);
}

int tg_audio_backend_read_dsp_register(const TopGearRecomp *instance,uint8_t address,uint8_t *value){
    if(!instance||!value||address>=128u||!instance->static_audio_acquired)return 0;
    return sc_static_apu_read_dsp_register(address,value);
}

/* Compatibility surface retained for frontends built against Version 27.
   There is no longer a selectable backend: only FULL STATIC is accepted. */
int topgear_recomp_set_audio_backend(TopGearRecomp *instance,enum TopGearAudioBackend backend,char *error,size_t cap){
    if(!instance){if(error&&cap)(void)snprintf(error,cap,"No Top Gear instance.");return 0;}
    if(backend!=TOPGEAR_AUDIO_BACKEND_STATIC){if(error&&cap)(void)snprintf(error,cap,"Only Full Static AOT S-SMP/S-DSP audio is supported.");return 0;}
    if(error&&cap)error[0]='\0';
    return 1;
}

enum TopGearAudioBackend topgear_recomp_audio_backend(const TopGearRecomp *instance){
    (void)instance;return TOPGEAR_AUDIO_BACKEND_STATIC;
}

const char *topgear_recomp_audio_backend_name(const TopGearRecomp *instance){
    (void)instance;return "full-static-aot-smp-sdsp";
}

int topgear_recomp_static_audio_status(const TopGearRecomp *instance,TopGearStaticAudioStatus *output){
    SCStaticApuStatus source;
    if(!instance||!output||!instance->static_audio_acquired)return 0;
    if(!sc_static_apu_status(&source))return 0;
    memset(output,0,sizeof(*output));
    output->synchronized_master_clock=source.synchronized_master_clock;
    output->smp_cycles=source.smp_cycles;output->smp_instructions=source.smp_instructions;output->aot_validated_instructions=source.aot_validated_instructions;
    output->pcm_frames=source.pcm_frames;output->pcm_known_frames=source.pcm_known_frames;
    output->pcm_unknown_frames=source.pcm_unknown_frames;output->pcm_hash=source.pcm_hash;
    output->dsp_pcm_overflows=source.pcm_overflows;output->fifo_dropped_frames=instance->audio_fifo_dropped_frames;
    output->sync_calls=source.sync_calls;output->rendezvous_hash=source.rendezvous_hash;output->cpu_port_event_count=source.cpu_port_event_count;output->cpu_port_event_hash=source.cpu_port_event_hash;
    output->sdsp_primitive_steps=source.sdsp_primitive_steps;output->sdsp_brr_steps=source.sdsp_brr_steps;
    output->smp_pc=source.smp_pc;output->aot_fail_pc=source.aot_fail_pc;output->code_write_barriers=source.code_write_barriers;
    output->clock_ratio_numerator=source.clock_ratio_numerator;output->clock_ratio_denominator=source.clock_ratio_denominator;output->clock_remainder=source.clock_remainder;
    output->expected_opcode=source.expected_opcode;output->actual_opcode=source.actual_opcode;output->aot_failed=source.aot_failed;output->aot_fail_reason=source.aot_fail_reason;
    output->sdsp_static_failed=source.sdsp_static_failed;output->dsp_phase=source.dsp_phase;output->timer_enable_mask=source.timer_enable_mask;output->initialized=source.initialized;
    output->generation_authority=1u;output->automatic_fallback_enabled=0u;
    (void)snprintf(output->backend_name,sizeof(output->backend_name),"full-static-aot-smp-sdsp");
    (void)snprintf(output->clock_profile,sizeof(output->clock_profile),"topgear-ntsc-measured-32040");
    return 1;
}
