#ifndef TOPGEAR_INTERNAL_H
#define TOPGEAR_INTERNAL_H

#include "topgear_static_recomp.h"
#define TG_V16_CYCLE_FETCH 1u
#define TG_V16_CYCLE_IDLE 2u
#define TG_V16_CYCLE_DATA_READ 3u
#define TG_V16_CYCLE_DATA_WRITE 4u
#define TG_V16_CYCLE_STACK_READ 5u
#define TG_V16_CYCLE_STACK_WRITE 6u
#include "topgear_v13_interleaved_ipl.h"
#include "topgear_v14_static_join.h"
#include "topgear_v14_post_audio_scpu.h"
#include "topgear_v15_post_audio_timing.h"

#include <stddef.h>
#include <stdint.h>

#define TG_P_C 0x01u
#define TG_P_Z 0x02u
#define TG_P_I 0x04u
#define TG_P_D 0x08u
#define TG_P_X 0x10u
#define TG_P_M 0x20u
#define TG_P_V 0x40u
#define TG_P_N 0x80u

#define TG_SMP_P_C 0x01u
#define TG_SMP_P_Z 0x02u
#define TG_SMP_P_I 0x04u
#define TG_SMP_P_H 0x08u
#define TG_SMP_P_B 0x10u
#define TG_SMP_P_P 0x20u
#define TG_SMP_P_V 0x40u
#define TG_SMP_P_N 0x80u

#define TG_IPL_READY 0u
#define TG_IPL_RECEIVING 1u
#define TG_IPL_RUNNING 2u

typedef struct TopGearCpuInternal {
    uint16_t a, x, y, s, d, pc;
    uint8_t p, e, pbr, dbr;
} TopGearCpuInternal;

typedef struct TopGearSmpInternal {
    uint8_t a, x, y, sp, psw;
    uint16_t pc;
    uint64_t instruction_count;
    uint64_t cycle_count;
} TopGearSmpInternal;

struct TopGearRecomp {
    uint8_t *rom;
    TopGearCpuInternal cpu;
    TopGearSmpInternal smp;
    uint8_t wram[TOPGEAR_RECOMP_WRAM_SIZE];
    uint8_t aram[TOPGEAR_RECOMP_ARAM_SIZE];
    uint8_t ppu_registers[0x100];
    uint8_t vram[65536];
    uint8_t oam[544];
    uint8_t cgram[512];
    uint16_t vram_word_address;
    uint16_t oam_byte_address;
    uint16_t cgram_byte_address;
    uint8_t vram_increment_words;
    uint8_t vram_increment_after_high;
    uint8_t cgram_latch_low;
    uint8_t cgram_latch_pending;
    uint8_t oam_latch_low;
    uint8_t oam_latch_pending;
    uint8_t vram_mapping;
    uint16_t vram_read_latch;
    uint32_t wram_port_address;
    uint8_t forced_blank;
    uint8_t brightness;
    uint32_t vram_write_count;
    uint32_t oam_write_count;
    uint32_t cgram_write_count;
    uint32_t dma_launch_count;
    uint8_t dma_enable_mask;
    uint8_t dma_completed_mask;
    uint8_t dma_transfer_modes_seen_mask;
    uint8_t dma_directions_seen_mask;
    uint8_t dma_last_channel;
    uint8_t dma_last_mode;
    uint8_t dma_last_direction;
    uint8_t dma_last_bbus_sequence_count;
    uint8_t dma_last_bbus_sequence[16];
    uint8_t dma_last_data[16];
    uint64_t dma_bytes_transferred;
    uint64_t dma_master_clocks_accounted;
    uint32_t dma_channels_completed;
    uint32_t dma_zero_size_transfers;
    uint32_t dma_last_source_address;
    uint32_t dma_last_transfer_bytes;
    uint64_t scpu_bus_reads;
    uint64_t scpu_bus_writes;
    uint64_t scpu_apu_reads;
    uint64_t scpu_apu_writes;
    uint64_t scpu_ppu_reads;
    uint64_t scpu_ppu_writes;
    uint64_t scpu_cpuio_reads;
    uint64_t scpu_cpuio_writes;
    uint8_t cpu_mdr;
    uint8_t controller_strobe;
    uint16_t controller_shift[2];
    uint64_t open_bus_read_count;
    uint64_t open_bus_write_count;
    uint64_t controller_serial_read_count;
    uint8_t cpu_io_registers[0x200];
    uint8_t nmitimen;
    uint8_t nmi_flag;
    uint8_t irq_flag;
    uint8_t autojoy_busy;
    uint16_t htime_target;
    uint16_t vtime_target;
    uint16_t controller_state[2];
    uint16_t autojoy_result[4];
    uint32_t autojoy_master_clocks_remaining;
    uint64_t scpu_master_clock;
    uint16_t hcounter_master;
    uint16_t vcounter_line;
    uint8_t hdma_enable_mask;
    uint8_t hdma_active_mask;
    uint8_t hdma_completed_mask;
    uint8_t hdma_transfer_modes_seen_mask;
    uint16_t hdma_table_address[8];
    uint16_t hdma_indirect_address[8];
    uint8_t hdma_line_counter[8];
    uint8_t hdma_do_transfer[8];
    uint64_t hdma_bytes_transferred;
    uint64_t hdma_master_clocks_accounted;
    uint32_t hdma_frame_setup_count;
    uint32_t hdma_scanline_run_count;
    uint32_t hdma_channel_setup_count;
    uint32_t hdma_channel_completion_count;
    uint32_t hdma_direct_transfer_bytes;
    uint32_t hdma_indirect_transfer_bytes;
    uint8_t hdma_last_channel;
    uint8_t hdma_last_mode;
    uint8_t hdma_last_indirect;
    uint8_t hdma_last_bbus_sequence_count;
    uint8_t hdma_last_bbus_sequence[8];
    uint8_t hdma_last_data[8];
    uint64_t nmi_event_count;
    uint64_t irq_event_count;
    uint64_t autojoy_start_count;
    uint64_t autojoy_completion_count;
    uint8_t autojoy_exact_schedule;
    uint8_t irq_exact_schedule;
    uint16_t bg1_hofs;
    uint16_t bg1_vofs;
    uint8_t bg1_hofs_low;
    uint8_t bg1_vofs_low;
    uint8_t bg1_hofs_pending;
    uint8_t bg1_vofs_pending;
    uint16_t bg_scroll[8];
    uint8_t bgofs_ppu1_latch;
    uint8_t bgofs_ppu2_latch;
    uint8_t mode7_latch;
    uint16_t mode7_hofs;
    uint16_t mode7_vofs;
    uint16_t mode7_c;
    uint16_t mode7_d;
    uint16_t mode7_x;
    uint16_t mode7_y;
    uint16_t ppu_fixed_color;
    uint8_t oam_priority_rotation;
    uint8_t mode1_frame[256u * 224u * 2u];
    uint32_t mode1_frame_count;
    uint32_t mode1_non_backdrop_pixels;
    uint8_t scpu_to_smp[4];
    uint8_t smp_to_scpu[4];
    uint8_t smp_control;
    uint8_t smp_dsp_address;
    uint8_t smp_dsp_registers[128];
    uint32_t smp_dsp_read_count;
    uint32_t smp_dsp_write_count;
    uint32_t smp_apu_port_read_count;
    uint32_t smp_apu_port_write_count;
    uint8_t smp_timer_targets[3];
    uint8_t smp_timer_enable_mask;
    uint8_t smp_timer_outputs[3];
    uint16_t smp_timer_stage2[3];
    uint64_t smp_timer_enable_cycle_min[3];
    uint64_t smp_timer_enable_cycle_max[3];
    uint32_t smp_timer_guaranteed_zero_reads[3];
    uint8_t smp_current_instruction_cycles;
    uint8_t smp_instruction_cycle_cursor;
    uint8_t smp_last_mmio_cycle_offset;
    uint8_t smp_cycle_resumable;
    uint64_t apu_oscillator_ticks;
    uint32_t dsp_possible_phase_mask;
    uint64_t dsp_clock_count;
    uint64_t pcm_frames_produced;
    uint64_t dsp_register_visibility_events;
    uint32_t dsp_last_write_phase_mask;
    uint8_t static_audio_acquired;
    uint8_t static_audio_failed;
    uint64_t audio_last_apu_master_clock;
    uint64_t audio_fifo_dropped_frames;
    int16_t audio_fifo[TOPGEAR_RECOMP_AUDIO_FIFO_FRAMES * 2u];
    uint32_t audio_read_index;
    uint32_t audio_write_index;
    uint32_t audio_count;
    uint8_t ipl_state;
    uint16_t ipl_destination;
    uint16_t ipl_block_offset;
    uint8_t ipl_index;
    uint32_t ipl_write_count;
    uint16_t ipl_entrypoint;
    uint64_t instruction_count;
    uint64_t v10_route_master_clock;
    uint64_t v10_route_processor_cycle;
    uint32_t v11_hardware_event_index;
    uint8_t scpu_defer_ipl_port0;
    uint8_t scpu_deferred_ipl_port0_valid;
    uint8_t scpu_deferred_ipl_port0_value;
    uint8_t v12_physical_join_mode;
    uint8_t v12_compatibility_helper_used;
    uint8_t v12_matched_apu_reads;
    uint8_t v12_actual_port0;
    uint8_t v13_nominal_join_mode;
    uint8_t v13_compatibility_helper_used;
    uint8_t v13_program_entry_reached;
    uint8_t v13_dynamic_timing;
    uint8_t v13_event_count;
    uint8_t v13_event_cursor;
    uint8_t v13_last_event_valid;
    uint8_t v13_reserved0[7];
    uint32_t v13_initial_phase;
    uint32_t v13_old_context_key;
    uint32_t v13_event_address[TOPGEAR_RECOMP_V13_MAX_EVENTS_PER_INSTRUCTION];
    uint8_t v13_event_type[TOPGEAR_RECOMP_V13_MAX_EVENTS_PER_INSTRUCTION];
    uint8_t v13_event_duration[TOPGEAR_RECOMP_V13_MAX_EVENTS_PER_INSTRUCTION];
    uint64_t v13_event_start[TOPGEAR_RECOMP_V13_MAX_EVENTS_PER_INSTRUCTION];
    uint64_t v13_event_end[TOPGEAR_RECOMP_V13_MAX_EVENTS_PER_INSTRUCTION];
    uint64_t v13_program_entry_master_clock;
    uint64_t v13_program_entry_scpu_instruction;
    TgV13IplCore v13_ipl;
    uint8_t v14_static_join_mode;
    uint8_t v14_second_bbaa_published;
    uint8_t v14_static_protocol_reached;
    uint8_t v14_reserved0;
    uint32_t v14_cold_profile;
    uint32_t v14_timer_profile;
    uint32_t v14_wait_comparisons;
    uint32_t v14_wait_comparison_target;
    uint64_t v14_command18_master_clock;
    uint64_t v14_second_bbaa_master_clock;
    uint8_t v14_post_audio_mode;
    uint8_t v14_post_audio_reached_a251;
    uint8_t v14_post_audio_apu_read_blocked;
    uint8_t v14_reserved1;
    uint64_t v14_post_audio_start_instruction;
    uint64_t v14_post_audio_semantic_instructions;
    uint8_t v14_wrmpya;
    uint8_t v14_wrmpyb;
    uint8_t v14_wrdivb;
    uint8_t v14_m7a_latch;
    uint8_t v14_m7b_latch;
    uint8_t v14_m7a_pending;
    uint8_t v14_m7b_pending;
    uint8_t v14_math_reserved;
    uint16_t v14_wrdiva;
    uint16_t v14_rddiv;
    uint16_t v14_rdmpy;
    uint16_t v14_m7a;
    uint16_t v14_m7b;
    uint8_t v15_post_audio_timing_mode;
    uint8_t v15_refresh_done;
    uint8_t v15_cpu_counter_mod8;
    uint8_t v15_dma_pending;
    uint8_t v15_field;
    uint8_t v15_short_scanline_active;
    uint8_t v15_reserved0[2];
    uint16_t v15_hcounter_master;
    uint16_t v15_vcounter_line;
    uint16_t v15_current_line_master_clocks;
    uint16_t v15_refresh_position;
    uint8_t v15_dma_active;
    uint8_t v15_dma_launch_seen;
    uint8_t v15_interrupt_recognition_mode;
    uint8_t v15_nmi_enable;
    uint8_t v15_nmi_valid;
    uint8_t v15_nmi_line;
    uint8_t v15_nmi_hold;
    uint8_t v15_nmi_transition;
    uint8_t v15_nmi_pending;
    uint8_t v15_interrupt_pending;
    uint8_t v15_nmitimen_write_seen;
    uint8_t v15_nmi_entry_completed;
    uint8_t v15_nmi_trampoline_completed;
    uint8_t v15_reserved1[2];
    uint32_t v15_route_index;
    uint64_t v15_active_master_clocks;
    uint64_t v15_processor_cycles;
    uint64_t v15_refresh_master_clocks;
    uint64_t v15_dma_master_clocks;
    uint64_t v15_dma_alignment_master_clocks;
    uint64_t v15_dma_body_master_clocks;
    uint64_t v15_dma_tail_master_clocks;
    uint64_t v15_dma_semantic_bytes_start;
    uint64_t v15_post_join_elapsed_master_clocks;
    uint64_t v15_refresh_event_count;
    uint64_t v15_scanline_boundary_count;
    uint64_t v15_short_scanline_count;
    uint32_t v15_dma_timed_launch_count;
    uint32_t v15_dma_arbitration_route_index;
    uint32_t v15_dma_arbitration_cycle_index;
    uint32_t v15_nmi_poll_count;
    uint32_t v15_nmi_enable_route_index;
    uint32_t v15_nmi_pending_route_index;
    uint32_t v15_nmi_pending_cycle_index;
    uint64_t v15_nmi_enable_elapsed_master_clock;
    uint64_t v15_nmi_transition_elapsed_master_clock;
    uint64_t v15_nmi_pending_elapsed_master_clock;
    uint64_t v15_nmi_entry_master_clocks;
    uint64_t v15_nmi_trampoline_master_clocks;
    uint16_t v15_nmi_enable_hcounter_master;
    uint16_t v15_nmi_enable_vcounter_line;
    uint8_t v15_nmi_enable_field;
    uint8_t v15_reserved2[3];
    uint8_t v16_handler_timing_mode;
    uint8_t v16_initial_cpu_counter_mod256;
    uint8_t v16_cpu_counter_mod256;
    uint8_t v16_autojoy_enabled;
    uint8_t v16_autojoy_counter;
    uint8_t v16_timed_read_head;
    uint8_t v16_timed_read_count;
    uint8_t v16_rdnmi_value;
    uint8_t v16_last_hvbjoy_value;
    uint8_t v16_reserved0[3];
    uint16_t v16_timed_read_address[8];
    uint8_t v16_timed_read_value[8];
    uint16_t v16_autojoy_result[4];
    uint64_t v16_handler_active_master_clocks;
    uint64_t v16_handler_processor_cycles;
    uint64_t v16_handler_elapsed_start;
    uint64_t v16_handler_refresh_start;
    uint64_t v16_rdnmi_elapsed_master_clock;
    uint64_t v16_first_hvbjoy_elapsed_master_clock;
    uint64_t v16_last_hvbjoy_elapsed_master_clock;
    uint64_t v16_brightness_write_elapsed_master_clock;
    uint64_t v16_autojoy_start_elapsed_master_clock;
    uint64_t v16_autojoy_completion_elapsed_master_clock;
    uint32_t v16_handler_instruction_count;
    uint32_t v16_hvbjoy_read_count;
    uint32_t v16_hvbjoy_busy_read_count;
    uint32_t v16_autojoy_start_count;
    uint32_t v16_autojoy_completion_count;
    uint8_t v16_rdnmi_read_seen;
    uint8_t v16_rti_completed;
    uint8_t v16_brightness_write_seen;
    uint8_t v16_reserved1;
    uint32_t v17_second_apu_target_driver_cycle;
    uint8_t v17_second_apu_family_valid;
    uint8_t v17_reserved0[3];
    uint8_t v16_dma_capture_mask;
    uint8_t v16_dma_timed_hdma_enable_mask;
    uint8_t v16_dma_first_a_data;
    uint8_t v16_dma_last_b_data;
    uint8_t v16_dma_dmap[8];
    uint8_t v16_dma_target[8];
    uint8_t v16_dma_source_bank[8];
    uint8_t v16_dma_first_data[8];
    uint8_t v16_dma_all_data_same[8];
    uint8_t v16_dma_reserved0[3];
    uint16_t v16_dma_source_address[8];
    uint32_t v16_dma_transfer_bytes[8];
    uint64_t v16_dma_functional_stream_hash;
    uint64_t v16_dma_timed_stream_hash;
    uint64_t v16_dma_event_hash;
    uint64_t v16_dma_a_event_count;
    uint64_t v16_dma_b_event_count;
    uint64_t v16_dma_ppu_write_event_count;
    uint64_t v16_dma_first_a_elapsed_master_clock;
    uint64_t v16_dma_first_b_elapsed_master_clock;
    uint64_t v16_dma_last_a_elapsed_master_clock;
    uint64_t v16_dma_last_b_elapsed_master_clock;
    uint32_t v16_dma_first_a_address;
    uint32_t v16_dma_last_a_address;
    uint16_t v16_dma_first_b_address;
    uint16_t v16_dma_last_b_address;
    uint64_t v16_dma_channel_first_b_elapsed[8];
    uint64_t v16_dma_channel_last_b_elapsed[8];
    uint8_t v18_optional_nmi_mode;
    uint8_t v18_optional_setup_epoch;
    uint8_t v18_dma_request_mask;
    uint8_t v18_optional_dma_pending;
    uint8_t v18_optional_dma_active;
    uint8_t v18_optional_dma_completed;
    uint8_t v18_optional_dma_reserved_mode[2];
    uint32_t v18_optional_dma_launch_count;
    uint64_t v18_optional_dma_master_clocks;
    uint64_t v18_optional_dma_alignment_clocks;
    uint64_t v18_optional_dma_body_clocks;
    uint64_t v18_optional_dma_tail_clocks;
    uint32_t v18_optional_dma_total_launch_count;
    uint32_t v18_deferred_mainline_dma_total_launch_count;
    uint64_t v18_optional_dma_total_master_clocks;
    uint64_t v18_optional_dma_total_bytes;
    uint64_t v18_deferred_mainline_dma_total_bytes;
    uint8_t v22_semantic_main_mode;
    uint8_t v22_semantic_hblank_toggle;
    uint8_t v22_main_audio_shim_active;
    uint8_t v22_main_audio_bbaa_injected;
    uint8_t v22_reserved_mode[4];
    uint32_t v22_main_audio_echo_count;
    uint64_t v22_semantic_nmi_count;
    uint64_t v22_semantic_irq_count;
    uint64_t v22_semantic_hblank_read_count;
    uint64_t v22_romwide_static_steps;
    uint64_t v22_reentry_static_steps;
    uint64_t v22_wram_static_steps;
    /* Version 23 broad non-audio event scheduler. This state is deliberately
       separate from the exact route-specific V15-V21 timing certificates. */
    uint8_t v23_event_mode;
    uint8_t v23_event_field;
    uint8_t v23_event_refresh_done;
    uint8_t v23_event_nmi_pending;
    uint8_t v23_event_irq_pending;
    uint8_t v23_event_irq_line;
    uint8_t v23_event_frame_ready;
    uint8_t v23_event_audio_deferred;
    uint8_t v23_event_nmi_issued_this_vblank;
    uint8_t v27_realtime_initialized;
    uint8_t v23_event_reserved1[2];
    uint16_t v23_event_hcounter;
    uint16_t v23_event_vcounter;
    uint16_t v23_event_line_period;
    uint16_t v23_event_refresh_position;
    uint8_t v23_event_cpu_mod8;
    uint8_t v23_event_in_interrupt;
    uint8_t v23_event_seen_scanline_render;
    uint8_t v23_event_reserved0;
    uint8_t v23_wram_epoch_id;
    uint8_t v23_reserved_epoch[3];
    uint64_t v23_event_master_clock;
    uint64_t v23_event_nominal_processor_cycles;
    uint64_t v23_event_refresh_count;
    uint64_t v23_event_nmi_count;
    uint64_t v23_event_irq_count;
    uint64_t v23_event_frame_count;
    uint64_t v23_event_scanline_render_count;
    uint64_t v23_event_timing_context_miss_count;
    uint64_t v23_event_autojoy_start_count;
    uint64_t v23_event_autojoy_completion_count;
    uint32_t v23_event_autojoy_remaining;
    char v23_event_last_frame_sha256[65];
    TopGearV24FrameCallback v24_frame_callback;
    void *v24_frame_callback_user;
    uint64_t v24_frame_index_base;
    uint64_t v24_frame_sequence_fnv1a64;
    uint8_t v24_trace_enabled;
    uint8_t v24_observed_bgmode_mask;
    uint8_t v24_reserved0[6];
    char v24_first_frame_sha256[65];
    /* Version 25 broad main-core coverage.  This is runtime coverage of the
       already-generated static surface, not a decoder and not a new authority. */
    uint8_t v25_coverage_enabled;
    uint8_t v25_apu_read_mask;
    uint8_t v25_apu_write_mask;
    uint8_t v25_dma_channel_touched_mask;
    uint16_t v25_dma_register_offset_mask;
    uint32_t v25_cpuio_read_mask;
    uint32_t v25_cpuio_write_mask;
    uint64_t v25_ppu_read_mask;
    uint64_t v25_ppu_write_mask;
    uint64_t v25_coverage_instruction_count;
    uint64_t v25_rom_bank_instruction_counts[16];
    uint32_t v25_rom_bank_unique_addresses[16];
    uint32_t v25_unique_rom_addresses;
    uint32_t v25_unique_wram_addresses;
    uint8_t v25_rom_exec_bitmap[65536];
    uint8_t v25_wram_exec_bitmap[8192];
    uint64_t hook_event_count;
    uint32_t hook_mask;
    TopGearHookCallback hook_callback;
    void *hook_user;
    uint8_t hook_stop_requested;
    uint8_t hook_in_callback;
    uint8_t failed;
    TopGearFrontierReceipt frontier;
    char last_error[256];
};

void tg_v25_note_mmio_read(struct TopGearRecomp*,uint16_t);
void tg_v25_note_mmio_write(struct TopGearRecomp*,uint16_t);
void tg_audio_push_frame(struct TopGearRecomp*,int16_t,int16_t);
int tg_audio_backend_reset(struct TopGearRecomp*,char*,size_t);
void tg_audio_backend_release(struct TopGearRecomp*);
int tg_audio_backend_sync(struct TopGearRecomp*,uint64_t);
int tg_audio_backend_cpu_write_port(struct TopGearRecomp*,uint64_t,unsigned,uint8_t);
int tg_audio_backend_cpu_read_port(struct TopGearRecomp*,uint64_t,unsigned,uint8_t*);
int tg_audio_backend_read_aram(const struct TopGearRecomp*,uint32_t,void*,size_t);
int tg_audio_backend_read_dsp_register(const struct TopGearRecomp*,uint8_t,uint8_t*);
void tg_set_flag(struct TopGearRecomp *instance, uint8_t flag, int enabled);
int tg_flag(const struct TopGearRecomp *instance, uint8_t flag);
void tg_set_nz8(struct TopGearRecomp *instance, uint8_t value);
void tg_set_nz16(struct TopGearRecomp *instance, uint16_t value);
uint8_t tg_acc8(const struct TopGearRecomp *instance);
uint16_t tg_acc16(const struct TopGearRecomp *instance);
void tg_set_acc8(struct TopGearRecomp *instance, uint8_t value);
void tg_set_acc16(struct TopGearRecomp *instance, uint16_t value);
void tg_set_index8(struct TopGearRecomp *instance, uint16_t *reg, uint8_t value);
void tg_set_index16(struct TopGearRecomp *instance, uint16_t *reg, uint16_t value);
void tg_compare8(struct TopGearRecomp *instance, uint8_t left, uint8_t right);
void tg_compare16(struct TopGearRecomp *instance, uint16_t left, uint16_t right);
void tg_adc8(struct TopGearRecomp *instance, uint8_t value);
void tg_adc16(struct TopGearRecomp *instance, uint16_t value);
void tg_sbc8(struct TopGearRecomp *instance, uint8_t value);
void tg_sbc16(struct TopGearRecomp *instance, uint16_t value);

int tg_bus_read8(struct TopGearRecomp *instance, uint32_t address, uint8_t *value);
int tg_bus_read16(struct TopGearRecomp *instance, uint32_t address, uint16_t *value);
int tg_bus_read24(struct TopGearRecomp *instance, uint32_t address, uint32_t *value);
int tg_bus_write8(struct TopGearRecomp *instance, uint32_t address, uint8_t value);
int tg_bus_write16(struct TopGearRecomp *instance, uint32_t address, uint16_t value);
int tg_bus_store16(struct TopGearRecomp *instance, uint32_t address, uint16_t value);
int tg_ppu_write(struct TopGearRecomp *instance,uint16_t address,uint8_t value);
int tg_ppu_read(struct TopGearRecomp *instance,uint16_t address,uint8_t *value);
int tg_dma_latch_write(struct TopGearRecomp *instance,uint16_t address,uint8_t value);
int tg_dma_io_write(struct TopGearRecomp *instance,uint16_t address,uint8_t value);
int tg_cpu_io_read(struct TopGearRecomp *instance,uint16_t address,uint8_t *value);
int tg_push8(struct TopGearRecomp *instance, uint8_t value);
int tg_push16(struct TopGearRecomp *instance, uint16_t value);
int tg_pull8(struct TopGearRecomp *instance, uint8_t *value);
int tg_pull16(struct TopGearRecomp *instance, uint16_t *value);

void tg_smp_instruction_begin(struct TopGearRecomp *instance, uint8_t total_cycles);
int tg_smp_advance_cycles(struct TopGearRecomp *instance, uint8_t cycles);
int tg_smp_advance_to_cycle(struct TopGearRecomp *instance, uint8_t cycle_offset);
int tg_smp_instruction_finish(struct TopGearRecomp *instance, uint8_t total_cycles);
int tg_smp_read8_at_cycle(struct TopGearRecomp *instance, uint16_t address, uint8_t *value, uint8_t cycle_offset);
int tg_smp_write8_at_cycle(struct TopGearRecomp *instance, uint16_t address, uint8_t value, uint8_t cycle_offset);
int tg_smp_read8(struct TopGearRecomp *instance, uint16_t address, uint8_t *value);
int tg_smp_write8(struct TopGearRecomp *instance, uint16_t address, uint8_t value);
void tg_smp_set_flag(struct TopGearRecomp *instance, uint8_t flag, int enabled);
int tg_smp_flag(const struct TopGearRecomp *instance, uint8_t flag);
void tg_smp_set_nz(struct TopGearRecomp *instance, uint8_t value);
void tg_smp_compare(struct TopGearRecomp *instance, uint8_t left, uint8_t right);
int tg_smp_push8(struct TopGearRecomp *instance, uint8_t value);
int tg_smp_pull8(struct TopGearRecomp *instance, uint8_t *value);

int tg_v22_generated_static_step(struct TopGearRecomp *instance);
unsigned tg_v22_generated_static_context_count(void);
unsigned tg_v22_generated_static_address_count(void);

uint32_t tg_generated_context_key(const struct TopGearRecomp *instance);
#define TG_CONTEXT_REQUIRE_DBR 0x01u
#define TG_CONTEXT_REQUIRE_D   0x02u
int tg_require_context_masked(struct TopGearRecomp *instance,
                              unsigned e, unsigned m, unsigned x,
                              uint8_t dbr, uint16_t d,
                              unsigned register_mask,
                              const char *address);
int tg_require_context(struct TopGearRecomp *instance,
                       unsigned e, unsigned m, unsigned x,
                       uint8_t dbr, uint16_t d,
                       const char *address);
int tg_fail_frontier(struct TopGearRecomp *instance,
                     const char *reason, const char *address);
void tg_copy_text(char *destination, size_t capacity, const char *source);
void tg_emit_hook(struct TopGearRecomp *instance,uint32_t type,uint32_t address,uint8_t value,uint8_t exact_boundary);
int tg_emit_bus_hook(struct TopGearRecomp *instance,uint32_t type,uint32_t address,uint8_t value);


void tg_v13_initialize(struct TopGearRecomp *instance,uint32_t initial_phase);
int tg_v13_prepare_scpu_timing(struct TopGearRecomp *instance);
int tg_v13_finish_scpu_timing(struct TopGearRecomp *instance,uint32_t old_context_key);
int tg_v13_sync_before_apu_access(struct TopGearRecomp *instance,uint32_t address,uint32_t hook_type);
int tg_v13_emit_dynamic_bus_hook(struct TopGearRecomp *instance,TopGearHookEvent *event);
int tg_v14_static_wait_step(struct TopGearRecomp *instance,int *handled);
void tg_v14_note_apu_write(struct TopGearRecomp *instance,uint32_t address,unsigned port,uint8_t value);
void tg_v14_initialize(struct TopGearRecomp *instance,uint32_t cold_profile,uint32_t timer_profile);
void tg_v13_copy_smp_state(struct TopGearRecomp *instance);
void tg_v15_initialize_refresh_beam(struct TopGearRecomp *instance,uint16_t hcounter,uint16_t vcounter,uint8_t cpu_counter_mod8,uint8_t field);
int tg_v15_advance_instruction_timing(struct TopGearRecomp *instance,uint32_t route_index);
int tg_v15_enter_nmi_and_trampoline(struct TopGearRecomp *instance);
int tg_v15_v16_step_segment(struct TopGearRecomp *instance,uint32_t clocks);
void tg_v16_tick2(struct TopGearRecomp *instance);
void tg_v16_note_last_cycle(struct TopGearRecomp *instance);
int tg_v16_schedule_cpu_cycle(struct TopGearRecomp *instance,uint8_t kind,uint32_t address,uint8_t clocks,uint8_t last_cycle);
int tg_v16_begin_handler_timing(struct TopGearRecomp *instance,uint8_t initial_mod256);
int tg_v16_execute_handler_instruction(struct TopGearRecomp *instance);
void tg_v16_reset_dma_timing_capture(struct TopGearRecomp *instance);
int tg_v16_capture_dma_channel(struct TopGearRecomp *instance,unsigned channel,uint8_t dmap,uint8_t target,uint16_t source,uint8_t bank,uint32_t bytes);
int tg_v16_capture_dma_byte(struct TopGearRecomp *instance,unsigned channel,uint32_t index,uint32_t address_a,uint8_t address_b,uint8_t data);
void tg_v16_note_hdma_enable(struct TopGearRecomp *instance,uint8_t mask);
int tg_v16_record_dma_phase(struct TopGearRecomp *instance,unsigned channel,uint32_t index,uint32_t address_a,uint8_t address_b,uint8_t data,int b_phase);
int tg_v18_optional_dma_edge(struct TopGearRecomp *instance,uint8_t cpu_cycle_clocks);
int tg_v18_service_pending_nmi(struct TopGearRecomp *instance,uint8_t initial_mod256,uint32_t *handler_instructions);
int tg_v19_continue_first_hdma_from_current(struct TopGearRecomp *instance);

/* Version 23 broad non-audio event scheduler helpers. */
unsigned tg_v23_nominal_processor_cycles(const struct TopGearRecomp *instance);
unsigned tg_v23_nominal_timing_context_count(void);
int tg_v23_advance_master_clocks(struct TopGearRecomp *instance,uint32_t clocks);
int tg_v23_advance_nominal_current_instruction(struct TopGearRecomp *instance,unsigned cycles);
int tg_v23_render_scanline(struct TopGearRecomp *instance,unsigned y);
int tg_v22_semantic_service_nmi(struct TopGearRecomp *instance);
int tg_v22_semantic_service_irq(struct TopGearRecomp *instance);
int tg_v22_semantic_static_step_any(struct TopGearRecomp *instance);
void tg_v25_note_exec(struct TopGearRecomp *instance);

void tg_sha256(const uint8_t *data, size_t length, uint8_t digest[32]);
void tg_sha256_hex(const uint8_t *data, size_t length, char output[65]);
uint32_t tg_crc32(const uint8_t *data, size_t length);

#endif
