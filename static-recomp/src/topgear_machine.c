#include "topgear_internal.h"

#include <stdio.h>

void tg_set_flag(TopGearRecomp *instance, uint8_t flag, int enabled) {
    if (enabled) instance->cpu.p |= flag;
    else instance->cpu.p &= (uint8_t)~flag;
}
int tg_flag(const TopGearRecomp *instance, uint8_t flag) {
    return (instance->cpu.p & flag) != 0u;
}
void tg_set_nz8(TopGearRecomp *instance, uint8_t value) {
    instance->cpu.p &= (uint8_t)~(TG_P_N | TG_P_Z);
    if (value == 0u) instance->cpu.p |= TG_P_Z;
    if ((value & 0x80u) != 0u) instance->cpu.p |= TG_P_N;
}
void tg_set_nz16(TopGearRecomp *instance, uint16_t value) {
    instance->cpu.p &= (uint8_t)~(TG_P_N | TG_P_Z);
    if (value == 0u) instance->cpu.p |= TG_P_Z;
    if ((value & 0x8000u) != 0u) instance->cpu.p |= TG_P_N;
}
uint8_t tg_acc8(const TopGearRecomp *instance) { return (uint8_t)instance->cpu.a; }
uint16_t tg_acc16(const TopGearRecomp *instance) { return instance->cpu.a; }
void tg_set_acc8(TopGearRecomp *instance, uint8_t value) {
    instance->cpu.a = (uint16_t)((instance->cpu.a & 0xFF00u) | value);
}
void tg_set_acc16(TopGearRecomp *instance, uint16_t value) { instance->cpu.a = value; }
void tg_set_index8(TopGearRecomp *instance, uint16_t *reg, uint8_t value) {
    (void)instance; *reg = value;
}
void tg_set_index16(TopGearRecomp *instance, uint16_t *reg, uint16_t value) {
    (void)instance; *reg = value;
}
void tg_compare8(TopGearRecomp *instance, uint8_t left, uint8_t right) {
    uint8_t result = (uint8_t)(left - right);
    tg_set_flag(instance, TG_P_C, left >= right); tg_set_nz8(instance, result);
}
void tg_compare16(TopGearRecomp *instance, uint16_t left, uint16_t right) {
    uint16_t result = (uint16_t)(left - right);
    tg_set_flag(instance, TG_P_C, left >= right); tg_set_nz16(instance, result);
}
void tg_adc8(TopGearRecomp *instance, uint8_t value) {
    uint8_t left = tg_acc8(instance);
    unsigned carry = tg_flag(instance, TG_P_C) ? 1u : 0u;
    unsigned total = (unsigned)left + (unsigned)value + carry;
    uint8_t result = (uint8_t)total;
    tg_set_flag(instance, TG_P_C, total > 0xFFu);
    tg_set_flag(instance, TG_P_V, ((~(left ^ value) & (left ^ result) & 0x80u) != 0u));
    tg_set_acc8(instance, result); tg_set_nz8(instance, result);
}
void tg_adc16(TopGearRecomp *instance, uint16_t value) {
    uint16_t left = instance->cpu.a;
    uint32_t carry = tg_flag(instance, TG_P_C) ? 1u : 0u;
    uint32_t total = (uint32_t)left + (uint32_t)value + carry;
    uint16_t result = (uint16_t)total;
    tg_set_flag(instance, TG_P_C, total > 0xFFFFu);
    tg_set_flag(instance, TG_P_V, ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u));
    instance->cpu.a = result; tg_set_nz16(instance, result);
}
void tg_sbc8(TopGearRecomp *instance, uint8_t value) {
    uint8_t left = tg_acc8(instance); int borrow = tg_flag(instance, TG_P_C) ? 0 : 1;
    int total = (int)left - (int)value - borrow; uint8_t result = (uint8_t)total;
    tg_set_flag(instance, TG_P_C, total >= 0);
    tg_set_flag(instance, TG_P_V, (((left ^ value) & (left ^ result) & 0x80u) != 0u));
    tg_set_acc8(instance, result); tg_set_nz8(instance, result);
}
void tg_sbc16(TopGearRecomp *instance, uint16_t value) {
    uint16_t left = instance->cpu.a; int32_t borrow = tg_flag(instance, TG_P_C) ? 0 : 1;
    int32_t total = (int32_t)left - (int32_t)value - borrow; uint16_t result = (uint16_t)total;
    tg_set_flag(instance, TG_P_C, total >= 0);
    tg_set_flag(instance, TG_P_V, (((left ^ value) & (left ^ result) & 0x8000u) != 0u));
    instance->cpu.a = result; tg_set_nz16(instance, result);
}


static void smp_publish_port(TopGearRecomp *instance, unsigned port, uint8_t value) {
    instance->smp_to_scpu[port & 3u] = value;
}

static void ipl_accept_command(TopGearRecomp *instance, uint8_t token) {
    smp_publish_port(instance, 0u, token);
    instance->ipl_destination = (uint16_t)(instance->scpu_to_smp[2] |
                                           ((uint16_t)instance->scpu_to_smp[3] << 8));
    instance->ipl_index = 0u;
    instance->ipl_block_offset = 0u;
    if (instance->scpu_to_smp[1] == 0u) {
        instance->ipl_entrypoint = instance->ipl_destination;
        instance->ipl_state = TG_IPL_RUNNING;
        instance->smp.pc = instance->ipl_entrypoint;
    } else {
        instance->ipl_state = TG_IPL_RECEIVING;
    }
}

static int ipl_port0_write(TopGearRecomp *instance, uint8_t value) {
    if (instance->ipl_state == TG_IPL_READY) {
        if (value != 0xCCu)
            return tg_fail_frontier(instance,
                                    "S-SMP IPL expected the first command token $CC.",
                                    NULL);
        ipl_accept_command(instance, value);
        return 1;
    }
    if (instance->ipl_state != TG_IPL_RECEIVING) return 1;
    if (value == instance->ipl_index) {
        uint16_t address = (uint16_t)(instance->ipl_destination + instance->ipl_block_offset);
        instance->aram[address] = instance->scpu_to_smp[1];
        instance->ipl_write_count++;
        instance->ipl_block_offset = (uint16_t)(instance->ipl_block_offset + 1u);
        instance->ipl_index = (uint8_t)instance->ipl_block_offset;
        smp_publish_port(instance, 0u, value);
        return 1;
    }
    ipl_accept_command(instance, value);
    return 1;
}

static int wram_offset(uint32_t address, uint32_t *offset) {
    uint8_t bank = (uint8_t)(address >> 16);
    uint16_t local = (uint16_t)address;
    if (bank == 0x7Eu || bank == 0x7Fu) {
        *offset = ((uint32_t)(bank - 0x7Eu) << 16) | local; return 1;
    }
    if ((bank <= 0x3Fu || (bank >= 0x80u && bank <= 0xBFu)) && local < 0x2000u) {
        *offset = local; return 1;
    }
    return 0;
}
static int lorom_offset(const TopGearRecomp *instance, uint32_t address, uint32_t *offset) {
    uint8_t bank = (uint8_t)(address >> 16);
    uint16_t local = (uint16_t)address;
    uint8_t low_bank;
    if (bank == 0x7Eu || bank == 0x7Fu) return 0;
    low_bank = (uint8_t)(bank & 0x7Fu);
    if (low_bank < 0x40u && local < 0x8000u) return 0;
    *offset = (((uint32_t)low_bank << 15) | (local & 0x7FFFu)) % TOPGEAR_RECOMP_ROM_SIZE;
    (void)instance; return 1;
}
static int finish_bus_read(TopGearRecomp *instance,uint32_t address,uint8_t value){
    /* Pinned 5A22 behavior: CPU-internal $4000-$43ff reads do not update MDR;
       ordinary and unmapped/open-bus reads do. */
    if((address & 0x40FC00u) != 0x4000u) instance->cpu_mdr=value;
    return tg_emit_bus_hook(instance,TOPGEAR_HOOK_EVENT_BUS_READ,address,value);
}
static int finish_bus_write(TopGearRecomp *instance,uint32_t address,uint8_t value){
    instance->cpu_mdr=value;
    return tg_emit_bus_hook(instance,TOPGEAR_HOOK_EVENT_BUS_WRITE,address,value);
}
static int tg_exact_cart_open_bus(uint8_t bank,uint16_t local){
    if(!(bank<=0x3Fu||(bank>=0x80u&&bank<=0xBFu)))return 0;
    if(local>=0x2000u&&local<=0x20FFu)return 1;
    if(local>=0x2184u&&local<=0x3FFFu)return 1;
    if(local>=0x4000u&&local<=0x4015u)return 1;
    if(local>=0x4018u&&local<=0x41FFu)return 1;
    if(local>=0x4400u&&local<=0x7FFFu)return 1; /* exact ROM has no SRAM/coprocessor */
    return 0;
}
void tg_v25_note_mmio_read(TopGearRecomp *i,uint16_t local){
    if(!i||!i->v25_coverage_enabled)return;
    if(local>=0x2100u&&local<=0x213Fu)i->v25_ppu_read_mask|=1ull<<(local-0x2100u);
    else if(local>=0x2140u&&local<=0x217Fu)i->v25_apu_read_mask|=(uint8_t)(1u<<((local-0x2140u)&3u));
    else if(local>=0x4200u&&local<=0x421Fu)i->v25_cpuio_read_mask|=1u<<(local-0x4200u);
    else if(local>=0x4300u&&local<=0x437Fu){i->v25_dma_channel_touched_mask|=(uint8_t)(1u<<((local-0x4300u)>>4));i->v25_dma_register_offset_mask|=(uint16_t)(1u<<(local&0x0Fu));}
}
void tg_v25_note_mmio_write(TopGearRecomp *i,uint16_t local){
    if(!i||!i->v25_coverage_enabled)return;
    if(local>=0x2100u&&local<=0x213Fu)i->v25_ppu_write_mask|=1ull<<(local-0x2100u);
    else if(local>=0x2140u&&local<=0x217Fu)i->v25_apu_write_mask|=(uint8_t)(1u<<((local-0x2140u)&3u));
    else if(local>=0x4200u&&local<=0x421Fu)i->v25_cpuio_write_mask|=1u<<(local-0x4200u);
    else if(local>=0x4300u&&local<=0x437Fu){i->v25_dma_channel_touched_mask|=(uint8_t)(1u<<((local-0x4300u)>>4));i->v25_dma_register_offset_mask|=(uint16_t)(1u<<(local&0x0Fu));}
}

/* TOP GEAR INPUT OWNERSHIP: both SNES controller ports flow through auto-joy
   $4218-$421F or serial $4016/$4017.  Later runtime NMI/input ownership is
   ROM 00:EC1A-EC5A.  Frontend scripts set physical controller state only. */
static uint8_t tg_controller_serial_bit(TopGearRecomp *i,unsigned port,int shift){
    uint8_t bit=(uint8_t)((i->controller_shift[port]>>15)&1u);
    if(shift&&!i->controller_strobe)i->controller_shift[port]=(uint16_t)(i->controller_shift[port]<<1);
    return bit;
}
int tg_bus_read8(TopGearRecomp *instance, uint32_t address, uint8_t *value) {
    uint32_t offset;
    uint8_t bank = (uint8_t)(address >> 16); uint16_t local = (uint16_t)address;
    if (!instance || !value) return 0;
    instance->scpu_bus_reads++;
    if (wram_offset(address, &offset)) { *value = instance->wram[offset]; return finish_bus_read(instance,address,*value); }
    if (bank <= 0x3Fu || (bank >= 0x80u && bank <= 0xBFu)) {
        if(local==0x4016u||local==0x4017u){
            uint8_t data=instance->cpu_mdr;unsigned port=(local==0x4016u)?0u:1u;
            uint8_t serial=tg_controller_serial_bit(instance,port,1);
            if(local==0x4016u)data=(uint8_t)((data&0xFCu)|serial);
            else data=(uint8_t)((data&0xE0u)|0x1Cu|serial);
            *value=data;instance->controller_serial_read_count++;return finish_bus_read(instance,address,*value);
        }
        if (local >= 0x2100u && local <= 0x2183u) {
            tg_v25_note_mmio_read(instance,local);
            if (local >= 0x2140u && local <= 0x217Fu) {
                unsigned port=(unsigned)((local-0x2140u)&3u);
                instance->scpu_apu_reads++;
                if(instance->v14_post_audio_mode){instance->v14_post_audio_apu_read_blocked=1u;return tg_fail_frontier(instance,"Version 14 post-$8068 static S-SMP read schedule is not yet joined; APUIO reads fail closed rather than fabricating a response.",NULL);}
                if(instance->v13_nominal_join_mode){
                    if(!tg_v13_sync_before_apu_access(instance,address,TOPGEAR_HOOK_EVENT_BUS_READ))return 0;
                    if(!tg_audio_backend_cpu_read_port(instance,instance->audio_last_apu_master_clock,port,value))return 0;
                    instance->smp_to_scpu[port]=*value;
                    return finish_bus_read(instance,address,*value);
                }
                /* Version 27 production join: the broad generated S-CPU observes the
                   live Full Static S-SMP output ports at the same event-order master
                   clock used by the SNES scheduler. The semantic AA/BB shim below is
                   retained only for archived/non-audio certification paths. */
                if(instance->v23_event_mode && instance->v22_semantic_main_mode){
                    if(!tg_audio_backend_cpu_read_port(instance,instance->v23_event_master_clock,port,value))return 0;
                    instance->smp_to_scpu[port]=*value;
                    return finish_bus_read(instance,address,*value);
                }
                if(instance->v22_semantic_main_mode && port==0u && instance->cpu.pbr==0x07u && instance->cpu.pc==0x802Au &&
                   instance->scpu_to_smp[1]==0x18u && (instance->smp_to_scpu[0]!=0xAAu || instance->smp_to_scpu[1]!=0xBBu)){
                    /* Main-core-only gate shim: Version 13 already proved the exact ROM-owned
                       command-$18 producer reaches IPL and publishes AA/BB. Version 22 injects
                       only that previously proved semantic token so non-audio ROM execution can
                       continue without making a physical audio/timing claim. */
                    instance->smp_to_scpu[0]=0xAAu;instance->smp_to_scpu[1]=0xBBu;
                    instance->v22_main_audio_shim_active=1u;instance->v22_main_audio_bbaa_injected=1u;
                }
                *value = instance->smp_to_scpu[port];
                if(instance->v12_physical_join_mode){
                    if(instance->instruction_count==400750ull&&local==0x2140u&&*value==0xAAu)instance->v12_matched_apu_reads++;
                    if(instance->instruction_count==400750ull&&local==0x2141u&&*value==0xBBu)instance->v12_matched_apu_reads++;
                    if(instance->instruction_count==400772ull&&local==0x2140u){
                        instance->v12_actual_port0=*value;
                        instance->v10_route_master_clock=10610284ull;
                        if(!finish_bus_read(instance,address,*value))return 0;
                        return tg_fail_frontier(instance,
                            "Version 12 physically joined execution stopped at the first impossible historical IPL acknowledgement: port 0 is still $AA; the old route expected an instantaneous $CC.",
                            "00:EBE7");
                    }
                }
                return finish_bus_read(instance,address,*value);
            }
            instance->scpu_ppu_reads++; if(!tg_ppu_read(instance,local,value))return 0;return finish_bus_read(instance,address,*value);
        }
        if (local >= 0x4200u && local <= 0x43FFu) {
            tg_v25_note_mmio_read(instance,local);
            instance->scpu_cpuio_reads++; if(!tg_cpu_io_read(instance,local,value))return 0;return finish_bus_read(instance,address,*value);
        }
        if(tg_exact_cart_open_bus(bank,local)){*value=instance->cpu_mdr;instance->open_bus_read_count++;return finish_bus_read(instance,address,*value);}
    }
    if (lorom_offset(instance, address, &offset)) { *value = instance->rom[offset]; return finish_bus_read(instance,address,*value); }
    {
        char message[192];
        (void)snprintf(message, sizeof(message), "Unsupported Version 03 bus read from %02X:%04X.", bank, local);
        return tg_fail_frontier(instance, message, NULL);
    }
}
int tg_bus_read16(TopGearRecomp *instance, uint32_t address, uint16_t *value) {
    uint8_t lo = 0u, hi = 0u; uint32_t bank = address & 0xFF0000u; uint16_t local = (uint16_t)address;
    if (!tg_bus_read8(instance, bank | local, &lo)) return 0;
    if (!tg_bus_read8(instance, bank | (uint16_t)(local + 1u), &hi)) return 0;
    *value = (uint16_t)(lo | ((uint16_t)hi << 8)); return 1;
}
int tg_bus_read24(TopGearRecomp *instance, uint32_t address, uint32_t *value) {
    uint8_t b0 = 0u, b1 = 0u, b2 = 0u; uint32_t bank=address&0xFF0000u; uint16_t local=(uint16_t)address;
    if (!tg_bus_read8(instance, bank|local, &b0)) return 0;
    if (!tg_bus_read8(instance, bank|(uint16_t)(local+1u), &b1)) return 0;
    if (!tg_bus_read8(instance, bank|(uint16_t)(local+2u), &b2)) return 0;
    *value=(uint32_t)b0|((uint32_t)b1<<8)|((uint32_t)b2<<16);return 1;
}
int tg_bus_write8(TopGearRecomp *instance, uint32_t address, uint8_t value) {
    uint32_t offset; uint8_t bank=(uint8_t)(address>>16); uint16_t local=(uint16_t)address;
    if(!instance)return 0;
    instance->scpu_bus_writes++;
    if (wram_offset(address,&offset)) { instance->wram[offset]=value; return finish_bus_write(instance,address,value); }
    if (bank<=0x3Fu || (bank>=0x80u && bank<=0xBFu)) {
        if(local==0x4016u){
            uint8_t strobe=(uint8_t)(value&1u);
            instance->controller_strobe=strobe;
            if(strobe){instance->controller_shift[0]=instance->controller_state[0];instance->controller_shift[1]=instance->controller_state[1];}
            return finish_bus_write(instance,address,value);
        }
        if(local==0x4017u)return finish_bus_write(instance,address,value);
        if (local>=0x2100u && local<=0x2183u) {
            tg_v25_note_mmio_write(instance,local);
            if (local>=0x2140u && local<=0x217Fu) {
                unsigned port=(unsigned)((local-0x2140u)&3u);
                instance->scpu_apu_writes++;
                if(instance->v14_post_audio_mode){
                    instance->scpu_to_smp[port]=value;
                    return finish_bus_write(instance,address,value);
                }
                if(instance->v13_nominal_join_mode){
                    if(!tg_v13_sync_before_apu_access(instance,address,TOPGEAR_HOOK_EVENT_BUS_WRITE))return 0;
                    instance->scpu_to_smp[port]=value;
                    tg_v14_note_apu_write(instance,address,port,value);
                    if(!tg_audio_backend_cpu_write_port(instance,instance->audio_last_apu_master_clock,port,value))return 0;
                    return finish_bus_write(instance,address,value);
                }
                instance->scpu_to_smp[port]=value;
                /* Version 27 production join: send every real CPU->APU write into the
                   Full Static S-SMP at the current event-order master clock. Once joined,
                   no semantic echo/AA-BB fabrication is permitted. */
                if(instance->v23_event_mode && instance->v22_semantic_main_mode){
                    if(!tg_audio_backend_cpu_write_port(instance,instance->v23_event_master_clock,port,value))return 0;
                    return finish_bus_write(instance,address,value);
                }
                if(instance->v22_semantic_main_mode && instance->v22_main_audio_shim_active && port==0u){
                    /* Once the proved second AA/BB publication returns the driver to IPL, the
                       S-CPU protocol requires a port-0 echo. Echoing the CPU token is a semantic
                       development shim only; exact S-SMP timing remains deferred. */
                    instance->smp_to_scpu[0]=value;instance->v22_main_audio_echo_count++;
                    return finish_bus_write(instance,address,value);
                }
                if (port==0u) {
                    if (instance->scpu_defer_ipl_port0) {
                        instance->scpu_deferred_ipl_port0_valid=1u;
                        instance->scpu_deferred_ipl_port0_value=value;
                    } else if (instance->v12_physical_join_mode || instance->v14_post_audio_mode) {
                        /* The CPU-to-SMP latch changes here. The generated IPL
                           core, not the historical synchronous helper, owns
                           any later acknowledgement. */
                    } else {
                        instance->v12_compatibility_helper_used=1u;
                        if (!ipl_port0_write(instance,value)) return 0;
                    }
                }
            } else {instance->scpu_ppu_writes++;if(!tg_ppu_write(instance,local,value))return 0;}
            return finish_bus_write(instance,address,value);
        }
        if (local>=0x4200u && local<=0x43FFu) { tg_v25_note_mmio_write(instance,local); instance->scpu_cpuio_writes++; if(!tg_dma_io_write(instance,local,value))return 0;return finish_bus_write(instance,address,value); }
        if(tg_exact_cart_open_bus(bank,local)){instance->open_bus_write_count++;return finish_bus_write(instance,address,value);}
    }
    {
        char message[192];
        (void)snprintf(message,sizeof(message),"Unsupported Version 03 bus write to %02X:%04X.",bank,local);
        return tg_fail_frontier(instance,message,NULL);
    }
}
int tg_bus_write16(TopGearRecomp *instance,uint32_t address,uint16_t value) {
    uint32_t bank=address&0xFF0000u;uint16_t local=(uint16_t)address;
    /* Reached 16-bit read-modify-write instructions drive the high result
       byte before the low result byte. Plain stores use tg_bus_store16(). */
    if (!tg_bus_write8(instance,bank|(uint16_t)(local+1u),(uint8_t)(value>>8)))return 0;
    return tg_bus_write8(instance,bank|local,(uint8_t)value);
}
int tg_bus_store16(TopGearRecomp *instance,uint32_t address,uint16_t value) {
    uint32_t bank=address&0xFF0000u;uint16_t local=(uint16_t)address;
    uint8_t defer_ipl=(uint8_t)((local==0x2140u)&&(((uint8_t)(address>>16)<=0x3Fu)||((uint8_t)(address>>16)>=0x80u&&(uint8_t)(address>>16)<=0xBFu)));
    if(!instance)return 0;
    if(defer_ipl){instance->scpu_defer_ipl_port0=1u;instance->scpu_deferred_ipl_port0_valid=0u;}
    if(!tg_bus_write8(instance,bank|local,(uint8_t)value)){
        instance->scpu_defer_ipl_port0=0u;instance->scpu_deferred_ipl_port0_valid=0u;return 0;
    }
    if(!tg_bus_write8(instance,bank|(uint16_t)(local+1u),(uint8_t)(value>>8))){
        instance->scpu_defer_ipl_port0=0u;instance->scpu_deferred_ipl_port0_valid=0u;return 0;
    }
    if(defer_ipl){
        uint8_t valid=instance->scpu_deferred_ipl_port0_valid;
        uint8_t token=instance->scpu_deferred_ipl_port0_value;
        instance->scpu_defer_ipl_port0=0u;instance->scpu_deferred_ipl_port0_valid=0u;
        if(valid){
            if(instance->v12_physical_join_mode||instance->v13_nominal_join_mode||instance->v14_post_audio_mode){
                /* Retain only the directional CPU-to-SMP latch. */
            }else{
                instance->v12_compatibility_helper_used=1u;
                if(!ipl_port0_write(instance,token))return 0;
            }
        }
    }
    return 1;
}
int tg_push8(TopGearRecomp *instance,uint8_t value) {
    uint16_t address=instance->cpu.e?(uint16_t)(0x0100u|(instance->cpu.s&0xFFu)):instance->cpu.s;
    if (!tg_bus_write8(instance,address,value))return 0;
    instance->cpu.s=(uint16_t)(instance->cpu.s-1u);
    if (instance->cpu.e)instance->cpu.s=(uint16_t)(0x0100u|(instance->cpu.s&0xFFu));
    return 1;
}
int tg_push16(TopGearRecomp *instance,uint16_t value) {
    return tg_push8(instance,(uint8_t)(value>>8))&&tg_push8(instance,(uint8_t)value);
}
int tg_pull8(TopGearRecomp *instance,uint8_t *value) {
    instance->cpu.s=(uint16_t)(instance->cpu.s+1u);
    if (instance->cpu.e)instance->cpu.s=(uint16_t)(0x0100u|(instance->cpu.s&0xFFu));
    return tg_bus_read8(instance,instance->cpu.s,value);
}
int tg_pull16(TopGearRecomp *instance,uint16_t *value) {
    uint8_t lo = 0u, hi = 0u;if(!tg_pull8(instance,&lo)||!tg_pull8(instance,&hi))return 0;
    *value=(uint16_t)(lo|((uint16_t)hi<<8));return 1;
}
uint32_t tg_generated_context_key(const TopGearRecomp *instance) {
    unsigned m=instance->cpu.e?1u:(unsigned)((instance->cpu.p&TG_P_M)!=0u);
    unsigned x=instance->cpu.e?1u:(unsigned)((instance->cpu.p&TG_P_X)!=0u);
    return ((uint32_t)instance->cpu.e<<27)|((uint32_t)m<<26)|((uint32_t)x<<25)|((uint32_t)instance->cpu.pbr<<16)|instance->cpu.pc;
}
/* Generated interrupt handlers use register_mask only where hardware preserves
   caller DBR/D across a prologue or epilogue. Normal generated contexts call
   tg_require_context and remain exact for both registers. */
int tg_require_context_masked(TopGearRecomp *instance,unsigned e,unsigned m,unsigned x,uint8_t dbr,uint16_t d,unsigned register_mask,const char *address) {
    unsigned am=instance->cpu.e?1u:(unsigned)((instance->cpu.p&TG_P_M)!=0u);
    unsigned ax=instance->cpu.e?1u:(unsigned)((instance->cpu.p&TG_P_X)!=0u);
    int dbr_mismatch=(register_mask&TG_CONTEXT_REQUIRE_DBR)!=0u&&instance->cpu.dbr!=dbr;
    int d_mismatch=(register_mask&TG_CONTEXT_REQUIRE_D)!=0u&&instance->cpu.d!=d;
    if(instance->cpu.e!=e||am!=m||ax!=x||dbr_mismatch||d_mismatch){
        char message[224];
        (void)snprintf(message,sizeof(message),"Generated context mismatch at %s: expected E%uM%uX%u DBR=%s%02X D=%s%04X, got E%uM%uX%u DBR=%02X D=%04X.",address?address:"unknown",e,m,x,(register_mask&TG_CONTEXT_REQUIRE_DBR)?"":"any/",dbr,(register_mask&TG_CONTEXT_REQUIRE_D)?"":"any/",d,instance->cpu.e,am,ax,instance->cpu.dbr,instance->cpu.d);
        return tg_fail_frontier(instance,message,address);
    }
    return 1;
}
int tg_require_context(TopGearRecomp *instance,unsigned e,unsigned m,unsigned x,uint8_t dbr,uint16_t d,const char *address) {
    return tg_require_context_masked(instance,e,m,x,dbr,d,
                                     TG_CONTEXT_REQUIRE_DBR|TG_CONTEXT_REQUIRE_D,
                                     address);
}


void tg_smp_set_flag(TopGearRecomp *instance,uint8_t flag,int enabled) {
    if(enabled) instance->smp.psw|=flag; else instance->smp.psw&=(uint8_t)~flag;
}
int tg_smp_flag(const TopGearRecomp *instance,uint8_t flag) { return (instance->smp.psw&flag)!=0u; }
void tg_smp_set_nz(TopGearRecomp *instance,uint8_t value) {
    instance->smp.psw&=(uint8_t)~(TG_SMP_P_N|TG_SMP_P_Z);
    if(value==0u)instance->smp.psw|=TG_SMP_P_Z;
    if((value&0x80u)!=0u)instance->smp.psw|=TG_SMP_P_N;
}
void tg_smp_compare(TopGearRecomp *instance,uint8_t left,uint8_t right) {
    uint8_t result=(uint8_t)(left-right);
    tg_smp_set_flag(instance,TG_SMP_P_C,left>=right);tg_smp_set_nz(instance,result);
}
int tg_smp_read8(TopGearRecomp *instance,uint16_t address,uint8_t *value) {
    if(!instance||!value)return 0;
    if(address>=0x00F0u&&address<=0x00FFu) {
        if(address==0x00F0u||address==0x00F1u||
           (address>=0x00FAu&&address<=0x00FCu)){*value=0u;return 1;}
        if(address==0x00F2u){*value=instance->smp_dsp_address;return 1;}
        if(address==0x00F3u){
            *value=instance->smp_dsp_registers[instance->smp_dsp_address&0x7Fu];
            instance->smp_dsp_read_count++;
            return 1;
        }
        if(address>=0x00F4u&&address<=0x00F7u){*value=instance->scpu_to_smp[address-0x00F4u];return 1;}
        if(address==0x00F8u||address==0x00F9u){*value=instance->aram[address];return 1;}
        if(address>=0x00FDu){
            unsigned timer=(unsigned)(address-0x00FDu);
            uint64_t divider=(timer<2u)?128u:16u;
            uint64_t target=instance->smp_timer_targets[timer];
            uint64_t earliest_increment;
            uint64_t latest_elapsed;
            if((instance->smp_timer_enable_mask&(uint8_t)(1u<<timer))==0u){
                *value=(uint8_t)(instance->smp_timer_outputs[timer]&0x0Fu);
                instance->smp_timer_outputs[timer]=0u;
                return 1;
            }
            if(target==0u)target=256u;
            earliest_increment=(target-1u)*divider;
            latest_elapsed=instance->smp.cycle_count-instance->smp_timer_enable_cycle_min[timer];
            if(instance->smp_timer_outputs[timer]==0u&&latest_elapsed<earliest_increment){
                *value=0u;
                instance->smp_timer_guaranteed_zero_reads[timer]++;
                return 1;
            }
            return tg_fail_frontier(instance,
                "Timer 0 output is now phase-dependent: the possible read window overlaps the first 8 kHz divider/target increment. A coupled microcycle scheduler is required.",
                "SMP:087E");
        }
        return tg_fail_frontier(instance,"Unmodelled Version 04 S-SMP MMIO read.","SMP:MMIO");
    }
    *value=instance->aram[address];return 1;
}
int tg_smp_write8(TopGearRecomp *instance,uint16_t address,uint8_t value) {
    if(!instance)return 0;
    if(address>=0x00F0u&&address<=0x00FFu) {
        if(address==0x00F0u)return tg_fail_frontier(instance,"S-SMP TEST writes are not a Version 04 claim.","SMP:TEST");
        if(address==0x00F1u){
            uint8_t old_mask=instance->smp_timer_enable_mask;
            unsigned timer;
            instance->smp_control=value;
            instance->smp_timer_enable_mask=(uint8_t)(value&0x07u);
            for(timer=0u;timer<3u;++timer){
                uint8_t bit=(uint8_t)(1u<<timer);
                if((old_mask&bit)==0u&&(instance->smp_timer_enable_mask&bit)!=0u){
                    instance->smp_timer_stage2[timer]=0u;
                    instance->smp_timer_outputs[timer]=0u;
                    instance->smp_timer_enable_cycle_min[timer]=instance->smp.cycle_count;
                    instance->smp_timer_enable_cycle_max[timer]=instance->smp.cycle_count;
                }
            }
            if((value&0x10u)!=0u){instance->scpu_to_smp[0]=0u;instance->scpu_to_smp[1]=0u;}
            if((value&0x20u)!=0u){instance->scpu_to_smp[2]=0u;instance->scpu_to_smp[3]=0u;}
            return 1;
        }
        if(address==0x00F2u){instance->smp_dsp_address=value;return 1;}
        if(address==0x00F3u){
            if((instance->smp_dsp_address&0x80u)==0u)
                instance->smp_dsp_registers[instance->smp_dsp_address&0x7Fu]=value;
            instance->smp_dsp_write_count++;
            instance->dsp_register_visibility_events++;
            instance->dsp_last_write_phase_mask=instance->dsp_possible_phase_mask;
            return 1;
        }
        if(address>=0x00F4u&&address<=0x00F7u){instance->smp_to_scpu[address-0x00F4u]=value;return 1;}
        if(address==0x00F8u||address==0x00F9u){instance->aram[address]=value;return 1;}
        if(address>=0x00FAu&&address<=0x00FCu){instance->smp_timer_targets[address-0x00FAu]=value;return 1;}
        if(address>=0x00FDu)return tg_fail_frontier(instance,"S-SMP timer outputs are read-only.","SMP:TIMER");
        return tg_fail_frontier(instance,"Unmodelled Version 04 S-SMP MMIO write.","SMP:MMIO");
    }
    instance->aram[address]=value;return 1;
}
int tg_smp_push8(TopGearRecomp *instance,uint8_t value) {
    if(!tg_smp_write8(instance,(uint16_t)(0x0100u|instance->smp.sp),value))return 0;
    instance->smp.sp=(uint8_t)(instance->smp.sp-1u);return 1;
}
int tg_smp_pull8(TopGearRecomp *instance,uint8_t *value) {
    instance->smp.sp=(uint8_t)(instance->smp.sp+1u);
    return tg_smp_read8(instance,(uint16_t)(0x0100u|instance->smp.sp),value);
}
