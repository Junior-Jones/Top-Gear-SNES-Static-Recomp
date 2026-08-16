/* Version 27 current-runtime API.
   This translation unit deliberately contains only the broad Version 22/23/24/25/26/27
   execution surface and common host APIs. Historical linear-route milestones are
   compiled only by the explicit certification build so their large generated
   receipts do not slow every normal compile. */
#include "topgear_static_recomp.h"
#include "topgear_internal.h"
#include "sc_static_apu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint16_t read_le16(const uint8_t *p){return (uint16_t)(p[0]|((uint16_t)p[1]<<8));}
void tg_copy_text(char *d,size_t n,const char *s){if(d&&n)(void)snprintf(d,n,"%s",s?s:"");}
static void clear_frontier(TopGearRecomp *i){memset(&i->frontier,0,sizeof(i->frontier));i->last_error[0]='\0';i->failed=0u;}

static uint32_t hook_mask_for_type(uint32_t type){
    switch(type){
    case TOPGEAR_HOOK_EVENT_RESET:return TOPGEAR_HOOK_MASK_RESET;
    case TOPGEAR_HOOK_EVENT_INSTRUCTION_BEFORE:
    case TOPGEAR_HOOK_EVENT_INSTRUCTION_AFTER:return TOPGEAR_HOOK_MASK_INSTRUCTION;
    case TOPGEAR_HOOK_EVENT_BUS_READ:
    case TOPGEAR_HOOK_EVENT_BUS_WRITE:return TOPGEAR_HOOK_MASK_BUS;
    case TOPGEAR_HOOK_EVENT_CHECKPOINT:return TOPGEAR_HOOK_MASK_CHECKPOINT;
    case TOPGEAR_HOOK_EVENT_FRONTIER:return TOPGEAR_HOOK_MASK_FRONTIER;
    default:return 0u;
    }
}

static void dispatch_hook(TopGearRecomp *i,TopGearHookEvent *event){
    uint32_t mask;
    if(!i||!event||!i->hook_callback||i->hook_in_callback)return;
    mask=hook_mask_for_type(event->type);
    if(mask==0u||(i->hook_mask&mask)==0u)return;
    i->hook_event_count++;i->hook_in_callback=1u;
    if(i->hook_callback(i->hook_user,event)!=0)i->hook_stop_requested=1u;
    i->hook_in_callback=0u;
}

void tg_emit_hook(TopGearRecomp *i,uint32_t type,uint32_t address,uint8_t value,uint8_t exact_boundary){
    TopGearHookEvent event;
    if(!i)return;
    memset(&event,0,sizeof(event));
    event.type=type;event.address=address;event.instruction_count=i->instruction_count;
    event.master_clock=i->v23_event_mode?i->v23_event_master_clock:i->scpu_master_clock;
    event.master_clock_start=event.master_clock;event.processor_cycle=i->v23_event_nominal_processor_cycles;
    event.value=value;event.instruction_boundary_exact=exact_boundary;
    dispatch_hook(i,&event);
}

int tg_emit_bus_hook(TopGearRecomp *i,uint32_t type,uint32_t address,uint8_t value){
    TopGearHookEvent event;
    if(!i)return 0;
    memset(&event,0,sizeof(event));
    event.type=type;event.address=address;event.instruction_count=i->instruction_count;
    event.master_clock=i->v23_event_mode?i->v23_event_master_clock:i->scpu_master_clock;
    event.master_clock_start=event.master_clock;event.processor_cycle=i->v23_event_nominal_processor_cycles;
    event.value=value;event.instruction_boundary_exact=1u;
    /* The current broad core is semantic/event-order authority, not the archived
       route-specific Version 11 per-bus timing receipt. */
    event.cycle_timing_exact=0u;
    dispatch_hook(i,&event);
    return i->hook_stop_requested?0:1;
}

int tg_fail_frontier(TopGearRecomp *i,const char *reason,const char *address){
    char generated[16];
    if(!i)return 0;
    if(!address){(void)snprintf(generated,sizeof(generated),"%02X:%04X",i->cpu.pbr,i->cpu.pc);address=generated;}
    i->failed=1u;i->frontier.reached=1u;i->frontier.instruction_count=i->instruction_count+i->smp.instruction_count;
    tg_copy_text(i->frontier.address,sizeof(i->frontier.address),address);
    tg_copy_text(i->frontier.reason,sizeof(i->frontier.reason),reason);
    tg_copy_text(i->last_error,sizeof(i->last_error),reason);
    tg_emit_hook(i,TOPGEAR_HOOK_EVENT_FRONTIER,((uint32_t)i->cpu.pbr<<16)|i->cpu.pc,0u,1u);
    return 0;
}

const char *topgear_recomp_version_string(void){return "Version 27";}
const char *topgear_recomp_video_standard(void){return "NTSC";}
unsigned topgear_recomp_generated_context_count(void){return 266u;}
unsigned topgear_recomp_generated_smp_context_count(void){return 1148u;}

int topgear_recomp_verify_rom(const uint8_t *rom,size_t rom_size,TopGearRomInfo *info,char *error,size_t error_capacity){
    char sha[65];uint16_t sum=0u;size_t k;const uint8_t *header;
    if(info)memset(info,0,sizeof(*info));
    if(!rom||rom_size!=TOPGEAR_RECOMP_ROM_SIZE){tg_copy_text(error,error_capacity,"The exact 524,288-byte unheadered Top Gear (USA) ROM is required.");return 0;}
    tg_sha256_hex(rom,rom_size,sha);
    if(strcmp(sha,TOPGEAR_RECOMP_ROM_SHA256)!=0){tg_copy_text(error,error_capacity,"ROM SHA-256 mismatch; this build accepts only Top Gear (USA) revision 1.0.");return 0;}
    header=rom+0x7FC0u;
    if(memcmp(header,"TOP GEAR",8u)!=0||header[0x15]!=0x20u||header[0x16]!=0x00u||header[0x19]!=0x01u||read_le16(rom+0x7FFCu)!=0x8000u){tg_copy_text(error,error_capacity,"ROM header contract mismatch.");return 0;}
    for(k=0;k<rom_size;++k)sum=(uint16_t)(sum+rom[k]);
    if(sum!=read_le16(header+0x1Eu)||(uint16_t)(read_le16(header+0x1Cu)^read_le16(header+0x1Eu))!=0xFFFFu){tg_copy_text(error,error_capacity,"ROM checksum contract mismatch.");return 0;}
    if(info){info->file_bytes=(uint32_t)rom_size;info->rom_bytes=(uint32_t)rom_size;info->crc32=tg_crc32(rom,rom_size);info->reset_vector=read_le16(rom+0x7FFCu);info->checksum_complement=read_le16(header+0x1Cu);info->checksum=read_le16(header+0x1Eu);info->map_mode=header[0x15];info->cartridge_type=header[0x16];info->country_code=header[0x19];info->version=header[0x1Bu];memcpy(info->title,header,21u);info->title[21]='\0';tg_copy_text(info->sha256,sizeof(info->sha256),sha);}
    tg_copy_text(error,error_capacity,"");return 1;
}

int topgear_recomp_create(TopGearRecomp **out,const uint8_t *rom,size_t n,char *error,size_t cap){
    TopGearRecomp *i;if(out)*out=NULL;if(!out||!topgear_recomp_verify_rom(rom,n,NULL,error,cap))return 0;
    i=(TopGearRecomp*)calloc(1u,sizeof(*i));if(!i){tg_copy_text(error,cap,"Unable to allocate the Top Gear static core.");return 0;}
    i->rom=(uint8_t*)malloc(n);if(!i->rom){free(i);tg_copy_text(error,cap,"Unable to copy the external ROM.");return 0;}memcpy(i->rom,rom,n);*out=i;
    if(!topgear_recomp_reset(i,error,cap)){topgear_recomp_destroy(i);*out=NULL;return 0;}return 1;
}

void topgear_recomp_destroy(TopGearRecomp *i){if(!i)return;tg_audio_backend_release(i);free(i->rom);memset(i,0,sizeof(*i));free(i);}

int topgear_recomp_reset(TopGearRecomp *i,char *error,size_t cap){
    uint8_t *rom;TopGearHookCallback hook_callback;void *hook_user;uint32_t hook_mask;uint8_t static_audio_acquired;
    if(!i||!i->rom){tg_copy_text(error,cap,"Static core is incomplete.");return 0;}
    rom=i->rom;hook_callback=i->hook_callback;hook_user=i->hook_user;hook_mask=i->hook_mask;static_audio_acquired=i->static_audio_acquired;
    memset(i,0,sizeof(*i));
    i->rom=rom;i->hook_callback=hook_callback;i->hook_user=hook_user;i->hook_mask=hook_mask;i->static_audio_acquired=static_audio_acquired;
    i->vram_increment_words=1u;i->forced_blank=1u;i->cpu.s=0x01FFu;i->cpu.p=(uint8_t)(TG_P_I|TG_P_M|TG_P_X);i->cpu.e=1u;i->cpu.pc=0x8000u;
    i->smp.sp=0xEFu;i->smp_control=0xB0u;i->smp_to_scpu[0]=0xAAu;i->smp_to_scpu[1]=0xBBu;i->ipl_state=TG_IPL_READY;i->smp_cycle_resumable=1u;i->dsp_possible_phase_mask=0xFFFFFFFFu;i->vtime_target=0x01FFu;
    clear_frontier(i);if(!tg_audio_backend_reset(i,error,cap))return 0;tg_copy_text(error,cap,"");tg_emit_hook(i,TOPGEAR_HOOK_EVENT_RESET,0x008000u,0u,1u);return 1;
}

int topgear_recomp_set_hook(TopGearRecomp *i,uint32_t mask,TopGearHookCallback callback,void *user){if(!i||!callback||(mask&~TOPGEAR_HOOK_MASK_ALL)!=0u)return 0;i->hook_mask=mask;i->hook_callback=callback;i->hook_user=user;i->hook_stop_requested=0u;return 1;}
void topgear_recomp_clear_hook(TopGearRecomp *i){if(!i)return;i->hook_mask=0u;i->hook_callback=NULL;i->hook_user=NULL;i->hook_stop_requested=0u;}
void topgear_recomp_request_stop(TopGearRecomp *i){if(i)i->hook_stop_requested=1u;}

/* Linear Version 01-21 stepping belongs to the archived certification build. */
int topgear_recomp_step(TopGearRecomp *i){return i?tg_fail_frontier(i,"Historical linear stepping is excluded from the Version 27 current-runtime build; use the explicit certification build.",NULL):0;}
int topgear_recomp_step_smp(TopGearRecomp *i){(void)i;return 0;}


void topgear_recomp_cpu_state(const TopGearRecomp *i,TopGearCpuState *s){if(!s)return;memset(s,0,sizeof(*s));if(!i)return;s->a=i->cpu.a;s->x=i->cpu.x;s->y=i->cpu.y;s->s=i->cpu.s;s->d=i->cpu.d;s->pc=i->cpu.pc;s->p=i->cpu.p;s->e=i->cpu.e;s->pbr=i->cpu.pbr;s->dbr=i->cpu.dbr;}
void topgear_recomp_smp_state(const TopGearRecomp *i,TopGearSmpState *s){SCStaticApuStatus a;if(!s)return;memset(s,0,sizeof(*s));if(!i)return;if(i->static_audio_acquired&&sc_static_apu_status(&a)){s->a=a.smp_a;s->x=a.smp_x;s->y=a.smp_y;s->sp=a.smp_sp;s->psw=a.smp_psw;s->pc=a.smp_pc;s->instruction_count=a.smp_instructions;s->cycle_count=a.smp_cycles;return;}s->a=i->smp.a;s->x=i->smp.x;s->y=i->smp.y;s->sp=i->smp.sp;s->psw=i->smp.psw;s->pc=i->smp.pc;s->instruction_count=i->smp.instruction_count;s->cycle_count=i->smp.cycle_count;}
void topgear_recomp_frontier(const TopGearRecomp *i,TopGearFrontierReceipt *r){if(!r)return;memset(r,0,sizeof(*r));if(i)*r=i->frontier;}
uint64_t topgear_recomp_instruction_count(const TopGearRecomp *i){return i?i->instruction_count:0u;}
int topgear_recomp_failed(const TopGearRecomp *i){return i?i->failed!=0u:1;}
const char *topgear_recomp_last_error(const TopGearRecomp *i){return i?i->last_error:"No Top Gear static core instance.";}

int topgear_recomp_read_wram(const TopGearRecomp *i,uint32_t o,void *d,size_t n){if(!i||!d||o>TOPGEAR_RECOMP_WRAM_SIZE||n>TOPGEAR_RECOMP_WRAM_SIZE-o)return 0;memcpy(d,i->wram+o,n);return 1;}
int topgear_recomp_read_aram(const TopGearRecomp *i,uint32_t o,void *d,size_t n){return tg_audio_backend_read_aram(i,o,d,n);}
int topgear_recomp_read_ppu_register(const TopGearRecomp *i,uint16_t a,uint8_t *v){if(!i||!v||a<0x2100u||a>0x21FFu)return 0;*v=(a>=0x2140u&&a<=0x2143u)?i->smp_to_scpu[a-0x2140u]:i->ppu_registers[a-0x2100u];return 1;}
int topgear_recomp_read_cpu_io_register(const TopGearRecomp *i,uint16_t a,uint8_t *v){if(!i||!v||a<0x4200u||a>0x43FFu)return 0;*v=i->cpu_io_registers[a-0x4200u];return 1;}
int topgear_recomp_read_apu_port(const TopGearRecomp *i,unsigned p,uint8_t *v){if(!i||!v||p>=4u)return 0;*v=i->smp_to_scpu[p];return 1;}
int topgear_recomp_read_scpu_to_smp_port(const TopGearRecomp *i,unsigned p,uint8_t *v){if(!i||!v||p>=4u)return 0;*v=i->scpu_to_smp[p];return 1;}
int topgear_recomp_read_smp_dsp_register(const TopGearRecomp *i,uint8_t reg,uint8_t *value){return tg_audio_backend_read_dsp_register(i,reg,value);}

int topgear_recomp_audio_clock_info(const TopGearRecomp *i,TopGearAudioClockInfo *x){if(!i||!x)return 0;memset(x,0,sizeof(*x));x->independent_clock_domain=1u;x->physical_rate_variable=1u;x->exact_scpu_ratio_claimed=0u;x->nominal_resonator_hz=24576000u;x->nominal_dsp_internal_hz=3072000u;x->nominal_smp_hz=1024000u;x->nominal_sample_rate_hz=TOPGEAR_RECOMP_HOST_AUDIO_SAMPLE_RATE;return 1;}
int topgear_recomp_dsp_scaffold_info(const TopGearRecomp *i,TopGearDspScaffoldInfo *x){
    SCStaticApuStatus a;
    if(!i||!x||!i->static_audio_acquired||!sc_static_apu_status(&a))return 0;
    memset(x,0,sizeof(*x));
    x->phase_count=32u;
    x->possible_phase_mask=1u<<(a.dsp_phase&31u);
    x->exact_phase_known=1u;
    x->signal_path_implemented=1u;
    x->dsp_clock_count=a.smp_cycles;
    x->pcm_frames_produced=a.pcm_frames;
    return 1;
}
