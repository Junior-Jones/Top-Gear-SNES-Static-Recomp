#ifndef TOPGEAR_STATIC_RECOMP_H
#define TOPGEAR_STATIC_RECOMP_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TOPGEAR_RECOMP_VERSION 25u
#define TOPGEAR_RECOMP_ROM_SIZE 524288u
#define TOPGEAR_RECOMP_WRAM_SIZE 131072u
#define TOPGEAR_RECOMP_ARAM_SIZE 65536u
#define TOPGEAR_RECOMP_ROM_SHA256 "ca9889f17f184b3d99a2eaaa82af73e366f03ed00313fdd369e5e023b208e788"
#define TOPGEAR_RECOMP_V02_PACKET_WRAM_OFFSET 0x2000u
#define TOPGEAR_RECOMP_V02_PACKET_SIZE 12497u
#define TOPGEAR_RECOMP_V02_PACKET_SHA256 "c90bccd04c020e93a5609bb0249188357f9f0b61f1ca9a9f522f1dc4f8992b81"
#define TOPGEAR_RECOMP_V03_UPLOAD_DESTINATION 0x0800u
#define TOPGEAR_RECOMP_V03_UPLOAD_SIZE 12489u
#define TOPGEAR_RECOMP_V03_UPLOAD_SHA256 "fb50296cb92b5d7fc0f108f2aca7df36b9257cb880b4c19fed9a653560c88ba8"
#define TOPGEAR_RECOMP_V03_INITIAL_ARAM_SHA256 "1132b1b4ea43181ff98134f8dad4ad263924f7b12f12607a658ee3e098d893ce"
#define TOPGEAR_RECOMP_V03_FRONTIER_ARAM_SHA256 "b797b87d1b3ee14b68240639bcff7f42e09756b811c66e71ba2c600fbaf65f3e"
#define TOPGEAR_RECOMP_V02_INSTRUCTION_COUNT 400750u
#define TOPGEAR_RECOMP_V03_SCPU_INSTRUCTION_COUNT 681771u
#define TOPGEAR_RECOMP_V03_SMP_INSTRUCTION_COUNT 3035u
#define TOPGEAR_RECOMP_V04_SMP_INSTRUCTION_COUNT 3596u
#define TOPGEAR_RECOMP_V04_SMP_CYCLE_COUNT 16946u
#define TOPGEAR_RECOMP_V04_SMP_CONTEXT_COUNT 95u
#define TOPGEAR_RECOMP_V04_FRONTIER_ARAM_SHA256 "4feb302086459f89ecd945abf09f58763dca6472ea0da4f3b78ec4da3116104e"
#define TOPGEAR_RECOMP_V04_DSP_REGISTERS_SHA256 "d0ea0d7eeea846e3991bfc637ae4c36cb3f400260c50829a6cfd507a58765ef3"
#define TOPGEAR_RECOMP_V05_PHASE_PROFILE_COUNT 640u
#define TOPGEAR_RECOMP_V05_TIMER_PHASE_COUNT 128u
#define TOPGEAR_RECOMP_V05_READ_CYCLE_CANDIDATE_COUNT 5u
#define TOPGEAR_RECOMP_V05_PHASE_CONTEXT_UNION_COUNT 112u
#define TOPGEAR_RECOMP_V05_PHASE_NEW_CONTEXT_COUNT 17u
#define TOPGEAR_RECOMP_V05_RECONVERGENCE_ARAM_SHA256 "123aa6ca3c85fb2da34e671df80bf007253f4ce2389056faef1c90de91023b10"
#define TOPGEAR_RECOMP_V06_EXACT_SMP_INSTRUCTION_COUNT 3598u
#define TOPGEAR_RECOMP_V06_EXACT_SMP_COMPLETED_CYCLES 16954u
#define TOPGEAR_RECOMP_V06_EXACT_TIMER_READ_EVENT_CYCLE 16957u
#define TOPGEAR_RECOMP_V06_TIMER_PROFILE_COUNT 128u
#define TOPGEAR_RECOMP_V06_DSP_PHASE_COUNT 32u
#define TOPGEAR_RECOMP_V06_COMBINED_PHASE_PROFILE_COUNT 4096u
#define TOPGEAR_RECOMP_V06_TIMER_STATE_COUNT 8u
#define TOPGEAR_RECOMP_AUDIO_FIFO_FRAMES 4096u
#define TOPGEAR_RECOMP_HOST_AUDIO_SAMPLE_RATE 32040u
#define TOPGEAR_RECOMP_AUDIO_CHANNELS 2u
#define TOPGEAR_RECOMP_AUDIO_BITS_PER_SAMPLE 16u
#define TOPGEAR_RECOMP_FRAME_WIDTH 256u
#define TOPGEAR_RECOMP_FRAME_HEIGHT 224u
#define TOPGEAR_RECOMP_PRESENTATION_FPS_NUMERATOR 39375000u
#define TOPGEAR_RECOMP_PRESENTATION_FPS_DENOMINATOR 655171u
#define TOPGEAR_RECOMP_NTSC_MASTER_CLOCK_HZ 21477272u
#define TOPGEAR_RECOMP_V11_HARDWARE_EVENT_COUNT 37483u
#define TOPGEAR_RECOMP_V12_IPL_CONTEXT_COUNT 15u
#define TOPGEAR_RECOMP_V13_PHASE_PROFILE_COUNT 128u
#define TOPGEAR_RECOMP_V13_IPL_CONTEXT_COUNT 34u
#define TOPGEAR_RECOMP_V13_SCPU_TIMING_VARIANT_COUNT 48u
#define TOPGEAR_RECOMP_V15_POST_AUDIO_INSTRUCTION_COUNT 149094u
#define TOPGEAR_RECOMP_V15_POST_AUDIO_PROCESSOR_CYCLE_COUNT 382494u
#define TOPGEAR_RECOMP_V15_SCPU_VERSION 2u
#define TOPGEAR_RECOMP_V15_SCANLINE_MASTER_CLOCKS 1364u
#define TOPGEAR_RECOMP_V15_NTSC_SCANLINES 262u
#define TOPGEAR_RECOMP_V15_VBLANK_START_LINE 225u
#define TOPGEAR_RECOMP_V16_NMI_HANDLER_CONTEXT_COUNT 53u

typedef struct TopGearRecomp TopGearRecomp;

enum TopGearRecompInput {
    TOPGEAR_INPUT_B      = 0x8000u,
    TOPGEAR_INPUT_Y      = 0x4000u,
    TOPGEAR_INPUT_SELECT = 0x2000u,
    TOPGEAR_INPUT_START  = 0x1000u,
    TOPGEAR_INPUT_UP     = 0x0800u,
    TOPGEAR_INPUT_DOWN   = 0x0400u,
    TOPGEAR_INPUT_LEFT   = 0x0200u,
    TOPGEAR_INPUT_RIGHT  = 0x0100u,
    TOPGEAR_INPUT_A      = 0x0080u,
    TOPGEAR_INPUT_X      = 0x0040u,
    TOPGEAR_INPUT_L      = 0x0020u,
    TOPGEAR_INPUT_R      = 0x0010u
};

typedef struct TopGearRecompFrameResult {
    uint8_t route_continued;
    uint8_t frame_rendered;
    uint16_t player1_input_mask;
    uint16_t player2_input_mask;
    uint32_t start_frame;
    uint32_t end_frame;
    char renderer_error[192];
} TopGearRecompFrameResult;

typedef struct TopGearRomInfo {
    uint32_t file_bytes;
    uint32_t rom_bytes;
    uint32_t crc32;
    uint16_t reset_vector;
    uint16_t checksum;
    uint16_t checksum_complement;
    uint8_t copier_header_present;
    uint8_t map_mode;
    uint8_t cartridge_type;
    uint8_t country_code;
    uint8_t version;
    char title[22];
    char sha256[65];
} TopGearRomInfo;

typedef struct TopGearCpuState {
    uint16_t a,x,y,s,d,pc;
    uint8_t p,e,pbr,dbr;
} TopGearCpuState;

typedef struct TopGearSmpState {
    uint8_t a,x,y,sp,psw;
    uint16_t pc;
    uint64_t instruction_count;
    uint64_t cycle_count;
} TopGearSmpState;

typedef struct TopGearFrontierReceipt {
    uint8_t reached;
    uint64_t instruction_count;
    char address[16];
    char reason[192];
} TopGearFrontierReceipt;

typedef struct TopGearV02PacketInfo {
    uint32_t wram_offset,total_bytes;
    uint16_t first_block_bytes,first_block_destination;
    uint16_t terminal_bytes,terminal_destination;
    char sha256[65];
} TopGearV02PacketInfo;

typedef struct TopGearV03AudioBootstrapInfo {
    uint8_t ipl_running;
    uint16_t upload_destination;
    uint16_t entrypoint;
    uint32_t uploaded_bytes;
    uint64_t scpu_instruction_count;
    uint64_t smp_instruction_count;
    char upload_sha256[65];
    char initial_aram_sha256[65];
    char frontier_aram_sha256[65];
    char scpu_frontier[16];
    char smp_frontier[16];
} TopGearV03AudioBootstrapInfo;

typedef struct TopGearV04AudioInitInfo {
    uint64_t scpu_instruction_count;
    uint64_t smp_instruction_count;
    uint64_t smp_cycle_count;
    uint32_t dsp_read_count;
    uint32_t dsp_write_count;
    uint8_t dsp_address;
    uint8_t control;
    uint8_t timer_enable_mask;
    uint8_t timer_targets[3];
    uint32_t timer_zero_reads_proved;
    uint8_t scpu_to_smp[4];
    uint8_t smp_to_scpu[4];
    char dsp_registers_sha256[65];
    char frontier_aram_sha256[65];
    char scpu_frontier[16];
    char smp_frontier[16];
} TopGearV04AudioInitInfo;

typedef struct TopGearV05PhaseFamilyInfo {
    uint32_t profile_count;
    uint32_t timer_phase_count;
    uint32_t read_cycle_candidate_count;
    uint32_t generated_context_union_count;
    uint32_t new_context_count;
    uint64_t instruction_count_min;
    uint64_t instruction_count_max;
    uint64_t cycle_count_min;
    uint64_t cycle_count_max;
    uint32_t timer_read_count_min;
    uint32_t timer_read_count_max;
    uint8_t a,x,y,sp,psw;
    uint16_t pc;
    uint32_t dsp_write_count;
    uint8_t exact_timing_known;
    uint8_t all_profiles_reconverged;
    uint8_t smp_to_scpu[4];
    uint8_t scpu_to_smp[4];
    char aram_sha256[65];
    char dsp_registers_sha256[65];
} TopGearV05PhaseFamilyInfo;

enum TopGearAudioBackend {
    TOPGEAR_AUDIO_BACKEND_STATIC = 0
};

typedef struct TopGearStaticAudioStatus {
    uint64_t synchronized_master_clock;
    uint64_t smp_cycles;
    uint64_t smp_instructions;
    uint64_t aot_validated_instructions;
    uint64_t pcm_frames;
    uint64_t fifo_dropped_frames;
    uint64_t sync_calls;
    uint64_t rendezvous_hash;
    uint64_t cpu_port_event_count;
    uint64_t cpu_port_event_hash;
    uint64_t sdsp_primitive_steps;
    uint64_t sdsp_brr_steps;
    uint16_t smp_pc;
    uint16_t aot_fail_pc;
    uint32_t code_write_barriers;
    uint32_t clock_ratio_numerator;
    uint32_t clock_ratio_denominator;
    uint32_t clock_remainder;
    uint8_t expected_opcode;
    uint8_t actual_opcode;
    uint8_t aot_failed;
    uint8_t aot_fail_reason;
    uint8_t sdsp_static_failed;
    uint8_t dsp_phase;
    uint8_t timer_enable_mask;
    uint8_t initialized;
    uint8_t generation_authority;
    uint8_t automatic_fallback_enabled;
    char backend_name[40];
    char clock_profile[48];
} TopGearStaticAudioStatus;

typedef struct TopGearAudioClockInfo {
    uint8_t independent_clock_domain;
    uint8_t physical_rate_variable;
    uint8_t exact_scpu_ratio_claimed;
    uint32_t nominal_resonator_hz;
    uint32_t nominal_dsp_internal_hz;
    uint32_t nominal_smp_hz;
    uint32_t nominal_sample_rate_hz;
} TopGearAudioClockInfo;

typedef struct TopGearDspScaffoldInfo {
    uint32_t phase_count;
    uint32_t possible_phase_mask;
    uint8_t exact_phase_known;
    uint8_t signal_path_implemented;
    uint64_t dsp_clock_count;
    uint64_t pcm_frames_produced;
} TopGearDspScaffoldInfo;


typedef struct TopGearV06SchedulerInfo {
    uint8_t cycle_resumable_mmio;
    uint8_t exact_initial_apu_phase_known;
    uint8_t absolute_read_cycle_offset;
    uint8_t absolute_write_cycle_offset;
    uint8_t oscillator_ticks_per_smp_cycle;
    uint8_t oscillator_ticks_per_dsp_phase;
    uint8_t dsp_phases_per_sample;
    uint8_t reserved;
    uint32_t timer01_divider_cycles;
    uint32_t timer2_divider_cycles;
    uint32_t timer_phase_count;
    uint32_t dsp_initial_phase_count;
    uint32_t combined_phase_profile_count;
    uint64_t apu_oscillator_ticks;
    uint64_t smp_cycle_count;
    uint32_t possible_dsp_phase_mask;
    uint32_t dsp_register_visibility_events;
    uint32_t timer_zero_reads_proved;
    uint8_t last_mmio_cycle_offset;
    uint8_t reserved2[3];
} TopGearV06SchedulerInfo;

typedef struct TopGearV06PhaseSetInfo {
    uint32_t timer_profile_count;
    uint32_t dsp_initial_phase_count;
    uint32_t combined_phase_profile_count;
    uint32_t timer_state_count;
    uint32_t generated_context_union_count;
    uint32_t new_context_count;
    uint64_t instruction_count_min;
    uint64_t instruction_count_max;
    uint64_t cycle_count_min;
    uint64_t cycle_count_max;
    uint32_t timer_read_count_min;
    uint32_t timer_read_count_max;
    uint8_t read_cycle_offset;
    uint8_t all_profiles_reconverged;
    uint8_t exact_physical_phase_selected;
    uint8_t a,x,y,sp,psw;
    uint16_t pc;
    uint8_t smp_to_scpu[4];
    uint8_t scpu_to_smp[4];
    char aram_sha256[65];
    char dsp_registers_sha256[65];
} TopGearV06PhaseSetInfo;


typedef struct TopGearV07BusEventInfo {
    uint64_t total_bus_reads;
    uint64_t total_bus_writes;
    uint64_t apu_port_reads;
    uint64_t apu_port_writes;
    uint64_t ppu_port_reads;
    uint64_t ppu_port_writes;
    uint64_t cpu_io_reads;
    uint64_t cpu_io_writes;
    uint32_t dma_launch_events;
    uint8_t last_dma_enable_mask;
    uint8_t exact_scpu_master_clock_timing;
    uint8_t ppu_storage_ports_implemented;
    uint8_t dma_register_latches_implemented;
} TopGearV07BusEventInfo;

typedef struct TopGearV07PpuStorageInfo {
    uint16_t vram_word_address;
    uint16_t oam_byte_address;
    uint8_t cgram_byte_address;
    uint8_t vram_increment_words;
    uint8_t vram_increment_after_high;
    uint8_t forced_blank;
    uint8_t brightness;
    uint32_t vram_write_count;
    uint32_t oam_write_count;
    uint32_t cgram_write_count;
    uint32_t dma_launch_count;
    uint8_t dma_enable_mask;
    uint8_t reserved[3];
} TopGearV07PpuStorageInfo;

typedef struct TopGearV08DmaInfo {
    uint64_t bytes_transferred;
    uint64_t master_clocks_accounted;
    uint32_t channels_completed;
    uint32_t launch_count;
    uint32_t zero_size_transfers;
    uint32_t last_source_address;
    uint32_t last_transfer_bytes;
    uint8_t requested_mask;
    uint8_t completed_mask;
    uint8_t transfer_modes_seen_mask;
    uint8_t directions_seen_mask;
    uint8_t last_channel;
    uint8_t last_mode;
    uint8_t last_direction;
    uint8_t exact_master_clock_timing;
    uint8_t last_bbus_sequence_count;
    uint8_t last_bbus_sequence[16];
    uint8_t last_data[16];
    char vram_sha256[65];
    char oam_sha256[65];
    char cgram_sha256[65];
} TopGearV08DmaInfo;

typedef struct TopGearV08InterruptInputInfo {
    uint8_t nmitimen;
    uint8_t nmi_flag;
    uint8_t irq_flag;
    uint8_t autojoy_enabled;
    uint8_t autojoy_busy;
    uint8_t exact_autojoy_start_timing;
    uint16_t htime_target;
    uint16_t vtime_target;
    uint16_t controller_state[2];
    uint16_t autojoy_result[4];
    uint32_t autojoy_master_clocks_remaining;
    uint64_t scpu_master_clock;
    uint16_t hcounter_master;
    uint16_t vcounter_line;
} TopGearV08InterruptInputInfo;


typedef struct TopGearV09ScpuBusScheduleInfo {
    uint64_t data_event_count;
    uint64_t apu_read_events;
    uint64_t apu_write_events;
    uint64_t ppu_read_events;
    uint64_t ppu_write_events;
    uint64_t cpu_io_read_events;
    uint64_t cpu_io_write_events;
    uint64_t dma_register_read_events;
    uint64_t dma_register_write_events;
    uint32_t sixteen_bit_event_bytes;
    uint32_t historical_order_discrepancy_bytes;
    uint8_t absolute_read8_data_offset;
    uint8_t absolute_read16_low_offset;
    uint8_t absolute_read16_high_offset;
    uint8_t absolute_write8_data_offset;
    uint8_t absolute_write16_low_offset;
    uint8_t absolute_write16_high_offset;
    uint8_t data_event_offsets_proved;
    uint8_t complete_master_clock_timeline_proved;
    uint8_t historical_compatibility_preserved;
} TopGearV09ScpuBusScheduleInfo;

typedef struct TopGearV09HdmaInfo {
    uint64_t bytes_transferred;
    uint64_t master_clocks_accounted;
    uint32_t frame_setup_count;
    uint32_t scanline_run_count;
    uint32_t channel_setup_count;
    uint32_t channel_completion_count;
    uint32_t direct_transfer_bytes;
    uint32_t indirect_transfer_bytes;
    uint8_t enabled_mask;
    uint8_t active_mask;
    uint8_t completed_mask;
    uint8_t transfer_modes_seen_mask;
    uint8_t last_channel;
    uint8_t last_mode;
    uint8_t last_indirect;
    uint8_t exact_trigger_timing_proved;
    uint8_t last_bbus_sequence_count;
    uint8_t last_bbus_sequence[8];
    uint8_t last_data[8];
} TopGearV09HdmaInfo;

typedef struct TopGearV09TimingInfo {
    uint64_t scpu_master_clock;
    uint64_t nmi_event_count;
    uint64_t irq_event_count;
    uint64_t autojoy_start_count;
    uint64_t autojoy_completion_count;
    uint16_t hcounter_master;
    uint16_t vcounter_line;
    uint16_t htime_target;
    uint16_t vtime_target;
    uint16_t autojoy_start_hcounter;
    uint16_t vblank_start_line;
    uint8_t nmitimen;
    uint8_t nmi_flag;
    uint8_t irq_flag;
    uint8_t autojoy_busy;
    uint8_t exact_autojoy_start_timing;
    uint8_t exact_hv_irq_target_timing;
    uint8_t natural_interrupt_entry_implemented;
    uint8_t reserved;
} TopGearV09TimingInfo;

typedef struct TopGearV09Mode1Info {
    uint32_t frame_count;
    uint32_t non_backdrop_pixels;
    uint16_t width;
    uint16_t height;
    uint16_t bg1_hofs;
    uint16_t bg1_vofs;
    uint8_t bgmode;
    uint8_t main_screen_mask;
    uint8_t bg1_4bpp_implemented;
    uint8_t obj_implemented;
    uint8_t color_math_implemented;
    uint8_t natural_game_upload_used;
    uint8_t exact_dot_timing_proved;
    uint8_t reserved;
    char frame_sha256[65];
} TopGearV09Mode1Info;

typedef struct TopGearV10ScpuTimingInfo {
    uint64_t instruction_count;
    uint64_t processor_cycle_count;
    uint64_t master_clock_count;
    uint64_t current_instruction_count;
    uint64_t current_master_clock;
    uint64_t six_master_clock_cycles;
    uint64_t eight_master_clock_cycles;
    uint64_t twelve_master_clock_cycles;
    uint32_t unique_context_count;
    uint8_t maximum_instruction_master_clocks;
    uint8_t maximum_instruction_processor_cycles;
    uint8_t fastrom_enabled;
    uint8_t instruction_boundary_timeline_proved;
    uint8_t microcycle_resumable_executor_implemented;
    uint8_t dma_stalls_joined;
    uint8_t interrupt_entry_joined;
    uint8_t apu_phase_selected;
    uint8_t reset_vector_sequence_included;
    uint8_t reserved[3];
} TopGearV10ScpuTimingInfo;


typedef struct TopGearV11HardwareTimelineInfo {
    uint64_t hardware_event_count;
    uint64_t apu_read_events;
    uint64_t apu_write_events;
    uint64_t ppu_write_events;
    uint64_t cpu_io_write_events;
    uint64_t first_master_clock;
    uint64_t last_master_clock_end;
    uint32_t sixteen_bit_low_high_pairs;
    uint8_t hardware_cycle_timeline_proved;
    uint8_t ordinary_store_low_high_order;
    uint8_t all_runtime_bus_events_cycle_timed;
    uint8_t refresh_dma_interrupt_joined;
    uint8_t apu_phase_selected;
    uint8_t reserved[3];
} TopGearV11HardwareTimelineInfo;

typedef struct TopGearV12IplJoinInfo {
    uint32_t ipl_context_count;
    uint32_t ipl_rom_bytes;
    uint64_t ready_port0_publish_cycle;
    uint64_t ready_port1_publish_cycle;
    uint64_t first_command_write_master_clock;
    uint64_t historical_ack_read_master_clock_start;
    uint64_t historical_ack_read_master_clock_end;
    uint64_t frontier_instruction;
    uint32_t master_clocks_available;
    uint32_t maximum_smp_cycles_available;
    uint32_t minimum_smp_cycles_required;
    uint32_t first_invalid_hardware_event_index;
    uint8_t initial_ready_reads_matched;
    uint8_t historical_expected_value;
    uint8_t physical_value_at_first_read;
    uint8_t all_initial_phases_reject_ack;
    uint8_t exact_physical_phase_selected;
    uint8_t historical_compatibility_route_rejected;
    uint8_t reserved[2];
    char ipl_rom_sha256[65];
    char frontier_address[16];
    char reason[192];
} TopGearV12IplJoinInfo;

typedef struct TopGearV13IplUploadInfo {
    uint32_t ipl_context_count;
    uint32_t scpu_timing_variant_count;
    uint32_t phase_profile_count;
    uint32_t upload_destination;
    uint32_t upload_bytes;
    uint32_t program_entrypoint;
    uint32_t nominal_clock_numerator;
    uint32_t nominal_clock_denominator;
    uint64_t minimum_scpu_instructions;
    uint64_t maximum_scpu_instructions;
    uint64_t minimum_entry_master_clock;
    uint64_t maximum_entry_master_clock;
    uint64_t minimum_smp_entry_cycle;
    uint64_t maximum_smp_entry_cycle;
    uint8_t all_profiles_completed_upload;
    uint8_t all_profiles_matched_upload_hash;
    uint8_t all_profiles_reached_entrypoint;
    uint8_t exact_physical_phase_selected;
    uint8_t exact_physical_rate_selected;
    uint8_t compatibility_helper_allowed;
    uint8_t clean_reset_route_required;
    uint8_t reserved;
    char upload_sha256[65];
    char aram_sha256[65];
    char next_barrier[224];
} TopGearV13IplUploadInfo;

typedef struct TopGearV13DriverPrefixReport {
    uint32_t phase_profile;
    uint32_t initial_phase_numerator;
    uint64_t scpu_instructions_at_entry;
    uint64_t scpu_master_clock_at_entry;
    uint64_t exact_smp_entry_master_clock;
    uint64_t smp_instructions_at_entry;
    uint64_t smp_cycles_at_entry;
    uint64_t driver_completed_instructions;
    uint64_t driver_completed_cycles;
    uint64_t timer_read_event_cycle_offset;
    uint64_t cumulative_timer_read_event_cycle;
    uint32_t dsp_read_count;
    uint32_t dsp_write_count;
    uint32_t apu_port_read_count;
    uint32_t apu_port_write_count;
    uint32_t timer_zero_reads_proved;
    uint8_t entry_state_matches_generated_driver;
    uint8_t no_apu_port_access_before_frontier;
    uint8_t compatibility_helper_used;
    uint8_t scpu_parallel_execution_proved;
    uint8_t timer_phase_selected;
    uint8_t dsp_phase_selected;
    uint8_t exact_physical_rate_selected;
    uint8_t reached_frontier;
    char upload_sha256[65];
    char frontier_aram_sha256[65];
    char dsp_registers_sha256[65];
    char frontier_address[16];
    char frontier_reason[192];
} TopGearV13DriverPrefixReport;

typedef struct TopGearV13DriverBridgeInfo {
    uint32_t cold_boot_phase_profile_count;
    uint32_t timer_phase_profile_count;
    uint32_t dsp_phase_profile_count;
    uint32_t driver_phase_profile_count;
    uint32_t conservative_cross_product_count;
    uint32_t timer_state_count_at_reconvergence;
    uint64_t smp_entry_instruction_min;
    uint64_t smp_entry_instruction_max;
    uint64_t smp_entry_cycle_min;
    uint64_t smp_entry_cycle_max;
    uint64_t driver_instruction_min;
    uint64_t driver_instruction_max;
    uint64_t driver_cycle_min;
    uint64_t driver_cycle_max;
    uint64_t cumulative_instruction_min;
    uint64_t cumulative_instruction_max;
    uint64_t cumulative_cycle_min;
    uint64_t cumulative_cycle_max;
    uint32_t apu_port_read_count_max;
    uint32_t apu_port_write_count_max;
    uint8_t actual_entry_reconverges_at_timer_enable;
    uint8_t all_driver_profiles_reconverged;
    uint8_t all_cold_boot_profiles_reach_entry;
    uint8_t exact_physical_phase_selected;
    uint8_t exact_physical_rate_selected;
    uint8_t scpu_parallel_execution_proved;
    uint8_t emulator_oracle_used_as_authority;
    uint8_t reserved;
    uint16_t reconvergence_pc;
    char timer_enable_aram_sha256[65];
    char reconvergence_aram_sha256[65];
    char dsp_registers_sha256[65];
    char claim_boundary[320];
} TopGearV13DriverBridgeInfo;

typedef struct TopGearV13SecondWaitInfo {
    uint32_t scpu_entry_state_candidate_count;
    uint32_t cold_boot_phase_profile_count;
    uint32_t timer_phase_profile_count;
    uint32_t dsp_phase_profile_count;
    uint32_t combined_driver_profile_count;
    uint32_t conservative_cross_product_count;
    uint64_t scpu_instruction_delta_min;
    uint64_t scpu_instruction_delta_max;
    uint64_t scpu_port_read_master_min;
    uint64_t scpu_port_read_master_max;
    uint64_t driver_read_cycle_min;
    uint64_t driver_read_cycle_max;
    uint64_t driver_search_target_cycle;
    uint64_t driver_ending_cycle_min;
    uint64_t driver_ending_cycle_max;
    uint64_t driver_search_steps_min;
    uint64_t driver_search_steps_max;
    uint64_t driver_search_steps_total;
    uint64_t last_port_clear_cycle_max;
    uint32_t scpu_consumer_address;
    uint16_t smp_endpoint_pc;
    uint16_t observed_port_word;
    uint8_t invariant_observation_join_proved;
    uint8_t scpu_enters_wait_loop;
    uint8_t all_timer_profiles_clear_ports_before_observation;
    uint8_t second_bbaa_producer_proved;
    uint8_t exact_parallel_microcycle_schedule_proved;
    uint8_t exact_physical_phase_selected;
    uint8_t exact_physical_rate_selected;
    uint8_t emulator_oracle_used_as_authority;
    char endpoint_aram_sha256[65];
    char dsp_registers_sha256[65];
    char claim_boundary[384];
} TopGearV13SecondWaitInfo;

typedef struct TopGearV13SecondBbaaProducerInfo {
    uint32_t cold_boot_profile_count;
    uint32_t timer_phase_profile_count;
    uint32_t dsp_phase_profile_count;
    uint32_t static_producer_profile_count;
    uint32_t combined_driver_profile_count;
    uint32_t conservative_cross_product_count;
    uint64_t scpu_command_master_min;
    uint64_t scpu_command_master_max;
    uint64_t scpu_command_driver_cycle_min;
    uint64_t scpu_command_driver_cycle_max;
    uint64_t invariant_join_driver_cycle;
    uint64_t post_command_instruction_min;
    uint64_t post_command_instruction_max;
    uint64_t post_command_cycle_min;
    uint64_t post_command_cycle_max;
    uint64_t publication_cycle_min;
    uint64_t publication_cycle_max;
    uint16_t published_port_word;
    uint16_t endpoint_pc;
    uint8_t command_value;
    uint8_t command_latch_state_equivalence_proved;
    uint8_t all_timer_profiles_published_second_bbaa;
    uint8_t ipl_rom_reentry_proved;
    uint8_t indirect_command_dispatch_proved;
    uint8_t dsp_flag_write_proved;
    uint8_t hybrid_used_for_discovery_only;
    uint8_t hybrid_trace_used_as_authority;
    uint8_t emulator_oracle_used_as_authority;
    uint8_t exact_physical_phase_selected;
    uint8_t exact_physical_rate_selected;
    uint8_t reserved[2];
    char endpoint_aram_sha256[65];
    char dsp_registers_sha256[65];
    char claim_boundary[384];
} TopGearV13SecondBbaaProducerInfo;

typedef struct TopGearV13PostIplScpuTimingInfo {
    uint32_t timing_variant_count;
    uint32_t unique_route_context_count;
    uint64_t entry_instruction_count;
    uint64_t entry_master_clock;
    uint64_t consumer_instruction_count;
    uint64_t consumer_master_clock;
    uint64_t command_write_master_clock;
    uint32_t command_write_address;
    uint32_t consumer_address;
    uint32_t release_address;
    uint8_t fixed_context_timing_proved;
    uint8_t hybrid_development_path_only;
    uint8_t static_authority_extended;
    uint8_t automatic_fallback_allowed;
    uint8_t runtime_opcode_decoder_used;
    uint8_t emulator_oracle_used_as_authority;
    uint8_t reserved[2];
    char claim_boundary[320];
} TopGearV13PostIplScpuTimingInfo;

typedef struct TopGearV13HybridSecondBbaaReport {
    uint64_t program_entry_master_clock;
    uint64_t program_entry_scpu_instruction;
    uint64_t command18_master_clock;
    uint64_t command18_scpu_instruction;
    uint64_t consumer_master_clock;
    uint64_t consumer_scpu_instruction;
    uint64_t second_bbaa_master_clock;
    uint64_t second_bbaa_scpu_instruction;
    uint64_t release_master_clock;
    uint64_t release_scpu_instruction;
    uint64_t smp_instruction_count;
    uint64_t smp_cycle_count;
    uint64_t pcm_frames;
    uint32_t wait_comparison_count;
    uint32_t bbaa_publish_count;
    uint16_t smp_pc;
    uint16_t observed_port_word;
    uint8_t output_ports[4];
    uint8_t command_value;
    uint8_t hybrid_development_only;
    uint8_t static_authority_extended;
    uint8_t automatic_fallback_used;
    uint8_t compatibility_helper_used;
    uint8_t second_bbaa_observed;
    uint8_t reached_release_address;
    uint8_t exact_scpu_timing_used;
    uint8_t emulator_oracle_used_as_authority;
    char frontier_address[16];
    char claim_boundary[320];
} TopGearV13HybridSecondBbaaReport;

typedef struct TopGearV13HybridSecondProtocolReport {
    TopGearV13HybridSecondBbaaReport second_bbaa;
    uint64_t protocol_entry_master_clock;
    uint64_t protocol_entry_scpu_instruction;
    uint64_t protocol_exit_master_clock;
    uint64_t protocol_exit_scpu_instruction;
    uint64_t protocol_scpu_instructions;
    uint64_t smp_instruction_count;
    uint64_t smp_cycle_count;
    uint64_t pcm_frames;
    uint32_t generated_context_count;
    uint32_t timing_variant_count;
    uint32_t bbaa_publish_count;
    TopGearCpuState final_cpu;
    uint16_t smp_pc;
    uint8_t output_ports[4];
    uint8_t hybrid_development_only;
    uint8_t rom_derived_fixed_contexts;
    uint8_t exact_scpu_timing_used;
    uint8_t static_audio_authority_extended;
    uint8_t automatic_fallback_used;
    uint8_t compatibility_helper_used;
    uint8_t emulator_oracle_used_as_authority;
    uint8_t reached_protocol_exit;
    char frontier_address[16];
    char claim_boundary[384];
} TopGearV13HybridSecondProtocolReport;


typedef struct TopGearV14StaticJoinReport {
    uint32_t cold_profile;
    uint32_t timer_profile;
    uint32_t wait_comparison_count;
    uint32_t wait_comparison_target;
    uint64_t command18_master_clock;
    uint64_t second_bbaa_master_clock;
    uint64_t exit_master_clock;
    uint64_t exit_instruction_count;
    TopGearCpuState final_cpu;
    uint16_t smp_pc;
    uint8_t output_ports[4];
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t compatibility_helper_used;
    uint8_t second_bbaa_published;
    uint8_t reached_8068;
    uint8_t exact_physical_phase_selected;
    uint8_t exact_physical_rate_selected;
    uint8_t runtime_opcode_decoder_used;
    char claim_boundary[384];
} TopGearV14StaticJoinReport;

typedef struct TopGearV14PreinterruptReport {
    uint64_t static_join_exit_instruction;
    uint64_t static_join_exit_master_clock;
    uint64_t semantic_additional_instructions;
    uint64_t total_instruction_count;
    uint32_t generated_context_count;
    TopGearCpuState final_cpu;
    uint8_t reached_a251;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t compatibility_helper_used;
    uint8_t physical_post_8068_timing_proved;
    uint8_t runtime_opcode_decoder_used;
    uint8_t post_audio_apu_read_blocked;
    uint8_t reserved;
    char claim_boundary[384];
} TopGearV14PreinterruptReport;

typedef struct TopGearV14HardwareInfo {
    uint16_t rddiv;
    uint16_t rdmpy;
    uint16_t m7a;
    uint16_t m7b;
    uint32_t generated_post_audio_contexts;
    uint8_t cpu_math_functional;
    uint8_t cpu_math_exact_latency_proved;
    uint8_t mode7_multiply_functional;
    uint8_t mode7_exact_latency_proved;
    uint8_t native_interrupt_entry_functional;
    uint8_t exact_interrupt_recognition_proved;
    uint8_t apu_mirrors_2140_217f;
    uint8_t reserved;
} TopGearV14HardwareInfo;

typedef struct TopGearV15PostAudioTimingInfo {
    uint64_t instruction_count;
    uint64_t processor_cycle_count;
    uint64_t active_master_clock_count;
    uint64_t join_master_clock;
    uint64_t join_instruction_count;
    uint64_t absolute_master_clock_without_refresh_dma;
    uint64_t six_master_clock_cycles;
    uint64_t eight_master_clock_cycles;
    uint64_t twelve_master_clock_cycles;
    uint32_t unique_context_count;
    uint8_t instruction_boundary_timing_proved;
    uint8_t runtime_opcode_decoder_used;
    uint8_t refresh_joined;
    uint8_t dma_hdma_joined;
    uint8_t interrupt_recognition_joined;
    uint8_t beam_origin_selected;
    uint8_t reserved[2];
} TopGearV15PostAudioTimingInfo;

typedef struct TopGearV15RefreshBeamReport {
    uint32_t cold_profile;
    uint32_t timer_profile;
    uint32_t route_instruction_count;
    uint32_t initial_hcounter_master;
    uint32_t initial_vcounter_line;
    uint32_t initial_cpu_counter_mod8;
    uint32_t initial_field;
    uint32_t final_hcounter_master;
    uint32_t final_vcounter_line;
    uint32_t final_cpu_counter_mod8;
    uint32_t final_field;
    uint32_t final_line_master_clocks;
    uint32_t final_refresh_position;
    uint64_t active_master_clocks;
    uint64_t processor_cycles;
    uint64_t refresh_master_clocks;
    uint64_t post_join_elapsed_master_clocks;
    uint64_t refresh_event_count;
    uint64_t scanline_boundary_count;
    uint64_t short_scanline_count;
    uint64_t dma_bytes_transferred;
    uint64_t legacy_dma_master_clocks_accounted;
    uint64_t dma_timed_master_clocks;
    uint64_t dma_alignment_master_clocks;
    uint64_t dma_body_master_clocks;
    uint64_t dma_tail_master_clocks;
    uint32_t dma_timed_launch_count;
    uint32_t dma_arbitration_route_index;
    uint32_t dma_arbitration_cycle_index;
    TopGearCpuState final_cpu;
    uint8_t reached_a251;
    uint8_t exact_active_cycle_timing_proved;
    uint8_t refresh_sequence_joined;
    uint8_t hblank_vblank_counter_model_joined;
    uint8_t beam_origin_user_parameterized;
    uint8_t absolute_beam_origin_proved;
    uint8_t dma_scpu_arbitration_timing_joined;
    uint8_t dma_ppu_bus_event_timing_joined;
    uint8_t hdma_arbitration_joined;
    uint8_t interrupt_recognition_joined;
    uint8_t short_scanline_quirk_joined;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    char frontier_address[16];
    char claim_boundary[512];
} TopGearV15RefreshBeamReport;

typedef struct TopGearV15NaturalNmiReport {
    uint32_t cold_profile;
    uint32_t timer_profile;
    uint32_t initial_hcounter_master;
    uint32_t initial_vcounter_line;
    uint32_t initial_cpu_counter_mod8;
    uint32_t initial_field;
    uint32_t semantic_route_instructions_before_nmi;
    uint32_t nmi_enable_route_index;
    uint32_t nmi_pending_route_index;
    uint32_t nmi_pending_cycle_index;
    uint32_t nmi_poll_count;
    uint64_t active_master_clocks_before_nmi;
    uint64_t refresh_master_clocks_before_nmi;
    uint64_t dma_timed_master_clocks_before_nmi;
    uint64_t elapsed_master_clocks_before_nmi;
    uint64_t nmi_enable_elapsed_master_clock;
    uint64_t nmi_transition_elapsed_master_clock;
    uint64_t nmi_pending_elapsed_master_clock;
    uint64_t nmi_entry_master_clocks;
    uint64_t nmi_trampoline_master_clocks;
    uint8_t wram_nmi_trampoline[4];
    TopGearCpuState cpu_before_nmi_entry;
    TopGearCpuState cpu_at_handler;
    uint8_t nmi_line_latched_before_enable;
    uint8_t nmitimen_write_timed;
    uint8_t first_nmi_recognized;
    uint8_t native_nmi_entry_timed;
    uint8_t reached_native_vector_0000;
    uint8_t trampoline_epoch_verified;
    uint8_t reached_handler_0f8000;
    uint8_t exact_last_cycle_sampling_joined;
    uint8_t absolute_beam_origin_proved;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    char frontier_address[16];
    char claim_boundary[512];
} TopGearV15NaturalNmiReport;


typedef struct TopGearV16DmaBusTimingReport {
    uint32_t cold_profile;
    uint32_t timer_profile;
    uint32_t initial_hcounter_master;
    uint32_t initial_vcounter_line;
    uint32_t initial_cpu_counter_mod8;
    uint32_t initial_field;
    uint32_t dma_arbitration_route_index;
    uint32_t dma_arbitration_cycle_index;
    uint32_t dma_timed_launch_count;
    uint32_t dma_channel_count;
    uint32_t channel_transfer_bytes[3];
    uint32_t channel_source_address[3];
    uint8_t channel_dmap[3];
    uint8_t channel_target[3];
    uint8_t captured_channel_mask;
    uint8_t natural_hdma_enable_mask;
    uint64_t dma_transfer_bytes;
    uint64_t a_bus_event_count;
    uint64_t b_bus_event_count;
    uint64_t ppu_write_event_count;
    uint64_t first_a_elapsed_master_clock;
    uint64_t first_b_elapsed_master_clock;
    uint64_t last_a_elapsed_master_clock;
    uint64_t last_b_elapsed_master_clock;
    uint32_t first_a_address;
    uint32_t last_a_address;
    uint16_t first_b_address;
    uint16_t last_b_address;
    uint8_t first_data;
    uint8_t last_data;
    uint64_t functional_stream_hash;
    uint64_t timed_stream_hash;
    uint64_t timed_event_hash;
    uint64_t channel_first_b_elapsed_master_clock[3];
    uint64_t channel_last_b_elapsed_master_clock[3];
    uint8_t exact_a_bus_phase_timing_joined;
    uint8_t exact_b_bus_phase_timing_joined;
    uint8_t ppu_bus_event_timing_joined;
    uint8_t functional_stream_reconciled;
    uint8_t natural_pre_nmi_hdma_disabled_proved;
    uint8_t active_dma_hdma_collision_proved;
    uint8_t absolute_beam_origin_proved;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    char frontier_address[16];
    char claim_boundary[640];
} TopGearV16DmaBusTimingReport;

typedef struct TopGearV16FirstNmiHandlerReport {
    uint32_t cold_profile;
    uint32_t timer_profile;
    uint32_t initial_hcounter_master;
    uint32_t initial_vcounter_line;
    uint32_t initial_cpu_counter_mod256;
    uint32_t initial_field;
    uint32_t handler_instruction_count;
    uint32_t generated_handler_context_count;
    uint32_t hvbjoy_read_count;
    uint32_t hvbjoy_busy_read_count;
    uint32_t autojoy_start_count;
    uint32_t autojoy_completion_count;
    uint32_t final_hcounter_master;
    uint32_t final_vcounter_line;
    uint32_t final_cpu_counter_mod256;
    uint32_t final_field;
    uint64_t handler_active_master_clocks;
    uint64_t handler_processor_cycles;
    uint64_t handler_refresh_master_clocks;
    uint64_t handler_elapsed_master_clocks;
    uint64_t rdnmi_elapsed_master_clock;
    uint64_t first_hvbjoy_elapsed_master_clock;
    uint64_t last_hvbjoy_elapsed_master_clock;
    uint64_t brightness_write_elapsed_master_clock;
    uint64_t autojoy_start_elapsed_master_clock;
    uint64_t autojoy_completion_elapsed_master_clock;
    uint16_t joy1;
    uint16_t joy2;
    uint8_t rdnmi_value;
    uint8_t last_hvbjoy_value;
    TopGearCpuState cpu_at_handler;
    TopGearCpuState cpu_after_rti;
    uint8_t reached_handler_0f8000;
    uint8_t rdnmi_read_timed;
    uint8_t hvbjoy_read_timed;
    uint8_t autojoy_timing_joined;
    uint8_t joypad_results_joined;
    uint8_t brightness_write_timed;
    uint8_t exact_rti_timing_joined;
    uint8_t resumed_interrupted_0f8cb9;
    uint8_t absolute_beam_origin_proved;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    char frontier_address[16];
    char claim_boundary[640];
} TopGearV16FirstNmiHandlerReport;

typedef struct TopGearV16Post8068SmpRendezvousReport {
    uint32_t cold_profile;
    uint32_t timer_profile;
    uint32_t initial_hcounter_master;
    uint32_t initial_vcounter_line;
    uint32_t initial_cpu_counter_mod8;
    uint32_t initial_field;
    uint32_t scpu_route_instructions;
    uint32_t apu_write_route_index;
    uint16_t smp_pc_at_join;
    uint16_t smp_pc_at_rendezvous;
    uint8_t scpu_port0_before;
    uint8_t scpu_port0_after;
    uint8_t smp_program_started_at_rendezvous;
    uint8_t refresh_occurred_before_rendezvous;
    uint64_t static_join_master_clock;
    uint64_t rendezvous_elapsed_master_clocks;
    uint64_t rendezvous_absolute_master_clock;
    uint64_t smp_cycle_count_at_join;
    uint64_t smp_cycle_target_at_rendezvous;
    uint64_t smp_cycle_count_at_rendezvous;
    uint64_t smp_program_entry_cycle;
    uint8_t exact_scpu_apu_bus_timing_joined;
    uint8_t nominal_smp_ratio_applied;
    uint8_t canonical_ipl_advanced_physically;
    uint8_t generated_driver_instruction_executed;
    uint8_t exact_physical_smp_rate_selected;
    uint8_t absolute_beam_origin_proved;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    char frontier_address[16];
    char claim_boundary[640];
} TopGearV16Post8068SmpRendezvousReport;


typedef struct TopGearV17SmpPhaseState {
    uint32_t target_driver_cycle;
    uint32_t completed_instructions;
    uint16_t pc;
    uint16_t pending_pc;
    uint8_t a, x, y, sp, psw;
    uint8_t pending_total_cycles;
    uint8_t pending_elapsed_cycles;
    uint8_t timer_phase;
    uint8_t timer_stage2;
    uint8_t timer_output;
    uint8_t cpu_to_smp[4];
    uint8_t smp_to_cpu[4];
    uint64_t aram_hash64;
    uint64_t dsp_hash64;
    uint32_t dsp_write_count;
} TopGearV17SmpPhaseState;

typedef struct TopGearV17SecondApuRendezvousReport {
    uint32_t cold_profile;
    uint32_t timer_profile;
    uint32_t initial_hcounter_master;
    uint32_t initial_vcounter_line;
    uint32_t initial_cpu_counter_mod8;
    uint32_t initial_field;
    uint32_t scpu_route_instructions;
    uint32_t apu_write_route_index;
    uint32_t target_driver_cycle;
    uint32_t timer_phase_profile_count;
    uint32_t dsp_phase_profile_count;
    uint32_t combined_phase_profile_count;
    uint32_t architectural_class_count;
    uint32_t exact_boundary_profile_count;
    uint32_t pending_instruction_profile_count;
    uint32_t unique_aram_hash_count;
    uint32_t unique_dsp_hash_count;
    uint32_t completed_driver_instructions_min;
    uint32_t completed_driver_instructions_max;
    uint8_t scpu_port0_before_second_write;
    uint8_t scpu_port0_after_second_write;
    uint8_t generated_driver_phase_family_executed;
    uint8_t partial_instruction_cursor_retained;
    uint8_t side_effect_free_partial_cycles_only;
    uint8_t timer_phase_family_retained;
    uint8_t dsp_phase_family_retained;
    uint8_t second_apu_rendezvous_joined;
    uint8_t exact_physical_smp_rate_selected;
    uint8_t absolute_beam_origin_proved;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    uint64_t static_join_master_clock;
    uint64_t rendezvous_elapsed_master_clocks;
    uint64_t rendezvous_absolute_master_clock;
    uint64_t smp_cycle_target_at_rendezvous;
    uint64_t smp_program_entry_cycle;
    char frontier_address[24];
    char claim_boundary[768];
} TopGearV17SecondApuRendezvousReport;

typedef struct TopGearV17ResetPrefixReport {
    uint32_t reset_pending_master_clocks;
    uint32_t interrupt_entry_master_clocks;
    uint32_t total_master_clocks_to_vector;
    uint32_t cpu_counter_mod8_at_vector;
    uint32_t cpu_counter_mod256_at_vector;
    uint16_t reset_vector;
    uint16_t hcounter_master_at_vector;
    uint16_t vcounter_line_at_vector;
    uint16_t stack_pointer_at_vector;
    uint8_t field_at_vector;
    uint8_t pbr_at_vector;
    uint8_t pushed_pc_high;
    uint8_t pushed_pc_low;
    uint8_t pushed_status;
    uint8_t dram_refresh_crossed;
    uint8_t reset_prefix_proved;
    uint8_t absolute_8068_beam_proved;
    uint8_t coupled_scpu_smp_reconstruction_required;
    uint8_t static_backend_only;
    char frontier_address[24];
    char claim_boundary[640];
} TopGearV17ResetPrefixReport;

typedef struct TopGearV17SecondNmiTickReport {
    uint32_t cold_profile;
    uint32_t timer_profile;
    uint32_t initial_hcounter_master;
    uint32_t initial_vcounter_line;
    uint32_t initial_cpu_counter_mod256;
    uint32_t initial_field;
    uint32_t wait_loop_cmp_count;
    uint32_t wait_loop_bne_count;
    uint32_t second_handler_instruction_count;
    uint32_t second_nmi_return_pc;
    uint32_t final_hcounter_master;
    uint32_t final_vcounter_line;
    uint32_t final_cpu_counter_mod256;
    uint32_t final_field;
    uint64_t a251_entry_elapsed_master_clock;
    uint64_t second_nmi_pending_elapsed_master_clock;
    uint64_t second_handler_elapsed_master_clocks;
    uint64_t released_a251_elapsed_master_clock;
    uint8_t a251_wait_reached;
    uint8_t second_nmi_recognized;
    uint8_t second_nmi_handler_completed;
    uint8_t second_nmi_incremented_tick;
    uint8_t a251_wait_released;
    uint8_t returned_from_a24d_to_8cc9;
    uint8_t absolute_beam_origin_proved;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    TopGearCpuState cpu_at_a251;
    TopGearCpuState cpu_before_second_nmi;
    TopGearCpuState cpu_after_second_handler;
    TopGearCpuState cpu_after_a24d_return;
    char frontier_address[24];
    char claim_boundary[768];
} TopGearV17SecondNmiTickReport;

typedef struct TopGearV18Post8cc9RouteReport {
    uint32_t cold_profile;
    uint32_t timer_profile;
    uint32_t initial_hcounter_master;
    uint32_t initial_vcounter_line;
    uint32_t initial_cpu_counter_mod256;
    uint32_t initial_field;
    uint32_t generated_route_instruction_count;
    uint32_t generated_context_count;
    uint32_t recurring_nmi_count_before_wait;
    uint32_t two_tick_wait_nmi_count;
    uint32_t handler_instruction_count_total;
    uint32_t final_hcounter_master;
    uint32_t final_vcounter_line;
    uint32_t final_cpu_counter_mod256;
    uint32_t final_field;
    uint64_t generated_processor_cycle_count;
    uint64_t generated_active_master_clock_count;
    uint64_t physical_elapsed_master_clocks;
    uint64_t first_route_nmi_elapsed_master_clock;
    uint64_t last_route_nmi_elapsed_master_clock;
    uint64_t next_a251_elapsed_master_clock;
    uint64_t two_tick_wait_released_elapsed_master_clock;
    uint8_t live_v17_8cc9_entry_verified;
    uint8_t generated_route_reached_a251;
    uint8_t recurring_nmis_joined;
    uint8_t next_a251_required_two_ticks;
    uint8_t two_tick_wait_released;
    uint8_t returned_to_a468;
    uint8_t hdma_remained_disabled_before_wait;
    uint8_t absolute_beam_origin_proved;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    TopGearCpuState cpu_at_8cc9;
    TopGearCpuState cpu_at_next_a251;
    TopGearCpuState cpu_after_two_tick_return;
    char frontier_address[24];
    char claim_boundary[1024];
} TopGearV18Post8cc9RouteReport;

typedef struct TopGearV18Post8077SmpReadReport {
    uint32_t cold_profile;
    uint32_t timer_profile;
    uint32_t source_target_driver_cycle;
    uint32_t timer_phase_profile_count;
    uint32_t dsp_phase_profile_count;
    uint32_t combined_phase_profile_count;
    uint32_t full_timing_state_class_count;
    uint32_t processor_arch_class_count;
    uint32_t next_apu_read_cycle_class_count;
    uint32_t next_apu_read_cycle_min;
    uint32_t next_apu_read_cycle_max;
    uint32_t unique_aram_hash_count;
    uint32_t unique_dsp_hash_count;
    uint32_t source_partial_instruction_profile_count;
    uint32_t verified_timer_phase_profile_count;
    uint16_t next_apu_read_pc;
    uint16_t next_apu_read_address;
    uint16_t pc_after_read_instruction;
    uint8_t next_apu_read_value;
    uint8_t read_cycle_offset;
    uint8_t source_port0_after_write;
    uint8_t partial_instruction_resume_verified;
    uint8_t timer_phase_family_retained;
    uint8_t dsp_phase_family_retained;
    uint8_t next_smp_apu_read_joined;
    uint8_t exact_physical_smp_rate_selected;
    uint8_t absolute_beam_origin_proved;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    char frontier_address[24];
    char claim_boundary[1024];
} TopGearV18Post8077SmpReadReport;

typedef struct TopGearV18NaturalHdmaReport {
    uint32_t cold_profile;
    uint32_t timer_profile;
    uint32_t generated_route_instruction_count;
    uint32_t generated_context_count;
    uint32_t synchronization_boundary_count;
    uint32_t a251_boundary_count;
    uint32_t nmi90_boundary_count;
    uint32_t recurring_nmi_count;
    uint32_t wait_nmi_count;
    uint32_t handler_instruction_count_total;
    uint32_t optional_nmi_dma_count;
    uint32_t deferred_mainline_dma_count;
    uint32_t final_hcounter_master;
    uint32_t final_vcounter_line;
    uint32_t final_cpu_counter_mod256;
    uint32_t final_field;
    uint64_t generated_processor_cycle_count;
    uint64_t generated_active_master_clock_count;
    uint64_t physical_elapsed_master_clocks;
    uint64_t optional_nmi_dma_bytes;
    uint64_t optional_nmi_dma_master_clocks;
    uint64_t deferred_mainline_dma_bytes;
    uint64_t total_pre_hdma_handler_dma_bytes;
    uint64_t first_nonzero_hdma_elapsed_master_clock;
    uint64_t a468_wram_fnv64;
    uint8_t a468_checkpoint_verified;
    uint8_t a468_phase_family_verified;
    uint8_t a468_stack_residue_01f3;
    uint8_t all_waits_serviced_by_nmi;
    uint8_t optional_nmi_dma_timing_joined;
    uint8_t no_earlier_nonzero_hdma;
    uint8_t reached_80ee_hdma18;
    uint8_t hdma_enable_mask;
    uint8_t absolute_beam_origin_proved;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    TopGearCpuState cpu_at_a468;
    TopGearCpuState cpu_after_hdma_enable;
    char frontier_address[24];
    char claim_boundary[1280];
} TopGearV18NaturalHdmaReport;



typedef struct TopGearV19NextSmpPortWriteReport {
    uint32_t source_target_driver_cycle;
    uint32_t timer_phase_profile_count;
    uint32_t dsp_phase_profile_count;
    uint32_t combined_phase_profile_count;
    uint32_t next_port_write_cycle_class_count;
    uint32_t next_port_write_cycle_min;
    uint32_t next_port_write_cycle_max;
    uint32_t verified_timer_phase_profile_count;
    uint16_t source_pc_after_read;
    uint16_t next_port_write_pc;
    uint16_t next_port_write_address;
    uint16_t pc_after_write;
    uint8_t next_port_write_value;
    uint8_t write_cycle_offset;
    uint8_t final_a,final_x,final_y,final_sp,final_psw;
    uint8_t timer_phase_family_retained;
    uint8_t dsp_phase_family_retained;
    uint8_t fixed_39_cycle_path_verified;
    uint8_t processor_architecture_converged;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    char aram_sha256[65];
    char dsp_sha256[65];
    char frontier_address[24];
    char claim_boundary[1024];
} TopGearV19NextSmpPortWriteReport;

typedef struct TopGearV19FirstHdmaReport {
    uint32_t endpoint_profile;
    uint32_t retained_cpu_mod8;
    uint32_t initial_hcounter_master;
    uint32_t initial_vcounter_line;
    uint32_t initial_field;
    uint32_t frame_start_field;
    uint32_t setup_trigger_hcounter_master;
    uint32_t setup_complete_hcounter_master;
    uint32_t first_scanline_trigger_hcounter_master;
    uint32_t first_scanline_complete_hcounter_master;
    uint32_t setup_a_bus_read_count;
    uint32_t first_scanline_a_bus_read_count;
    uint32_t first_scanline_b_bus_write_count;
    uint32_t channel_setup_count;
    uint64_t physical_elapsed_master_clocks;
    uint64_t hdma_master_clocks;
    uint32_t setup_a_bus_address[6];
    uint8_t setup_a_bus_data[6];
    uint32_t first_scanline_a_bus_address[3];
    uint16_t first_scanline_b_bus_address[3];
    uint8_t first_scanline_data[3];
    uint16_t channel3_table_address;
    uint16_t channel4_table_address;
    uint16_t channel3_indirect_address;
    uint16_t channel4_indirect_address;
    uint8_t channel3_line_counter;
    uint8_t channel4_line_counter;
    uint8_t hdma_enable_mask;
    uint8_t hdma_active_mask;
    uint8_t reached_next_frame_v0;
    uint8_t descriptors_unchanged_before_setup;
    uint8_t setup_timing_joined;
    uint8_t first_visible_line_transfer_joined;
    uint8_t first_transfer_values_verified;
    uint8_t no_nmi_before_first_transfer;
    uint8_t absolute_power_on_beam_proved;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    TopGearCpuState cpu_after_first_transfer;
    char frontier_address[24];
    char claim_boundary[1280];
} TopGearV19FirstHdmaReport;

typedef struct TopGearV20NextSmpPortWriteReport {
    uint32_t source_target_driver_cycle;
    uint32_t timer_phase_profile_count;
    uint32_t dsp_phase_profile_count;
    uint32_t combined_phase_profile_count;
    uint32_t next_port_write_cycle_class_count;
    uint32_t next_port_write_cycle_min;
    uint32_t next_port_write_cycle_max;
    uint32_t verified_timer_phase_profile_count;
    uint32_t instructions_after_109a;
    uint32_t instructions_after_109a_max;
    uint32_t post109a_instruction_count_class_count;
    uint16_t next_port_write_pc;
    uint16_t next_port_write_address;
    uint16_t pc_after_write;
    uint8_t next_port_write_value;
    uint8_t write_cycle_offset;
    uint8_t final_a,final_x,final_y,final_sp,final_psw;
    uint8_t timer_phase_family_retained;
    uint8_t dsp_phase_family_retained;
    uint8_t processor_architecture_converged;
    uint8_t new_reached_spc700_semantics_verified;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    char aram_sha256[65];
    char dsp_sha256[65];
    char frontier_address[24];
    char claim_boundary[1280];
} TopGearV20NextSmpPortWriteReport;

typedef struct TopGearV21NextSmpPortReadReport {
    uint32_t source_target_driver_cycle;
    uint32_t timer_phase_profile_count;
    uint32_t dsp_phase_profile_count;
    uint32_t combined_phase_profile_count;
    uint32_t next_port_read_cycle_class_count;
    uint32_t next_port_read_cycle_min;
    uint32_t next_port_read_cycle_max;
    uint32_t verified_timer_phase_profile_count;
    uint32_t instructions_after_08de;
    uint16_t next_port_read_pc;
    uint16_t next_port_read_address;
    uint16_t pc_after_read;
    uint8_t next_port_read_value;
    uint8_t read_cycle_offset;
    uint8_t final_a,final_x,final_y,final_sp,final_psw;
    uint8_t timer_phase_family_retained;
    uint8_t dsp_phase_family_retained;
    uint8_t processor_architecture_converged;
    uint8_t exact_fixed_path_verified;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    char aram_sha256[65];
    char dsp_sha256[65];
    char frontier_address[24];
    char claim_boundary[1280];
} TopGearV21NextSmpPortReadReport;

typedef struct TopGearV21AbsoluteApuClearReport {
    uint32_t cold_profile_count;
    uint32_t reachable_timer_phase_class_count;
    uint32_t timer_phase46_profile_count;
    uint32_t timer_phase57_profile_count;
    uint32_t dsp_phase_profile_count;
    uint32_t processor_architecture_class_count;
    uint32_t apu_clear_smp_cycle_min;
    uint32_t apu_clear_smp_cycle_max;
    uint64_t apu_clear_master_clock_min;
    uint64_t apu_clear_master_clock_max;
    uint16_t hcounter_master_min;
    uint16_t hcounter_master_max;
    uint16_t vcounter_line;
    uint8_t field;
    uint16_t first_apu_write_pc;
    uint16_t first_apu_write_address;
    uint16_t pc_after_write;
    uint8_t first_apu_write_value;
    uint8_t write_cycle_offset;
    uint8_t all_cold_profiles_verified;
    uint8_t no_inbound_apu_read_before_clear;
    uint8_t power_on_phase_mapping_retained;
    uint8_t dsp_phase_family_retained;
    uint8_t parallel_scpu_progress_proved;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    char aram_sha256[65];
    char dsp_sha256[65];
    char frontier_address[24];
    char claim_boundary[1280];
} TopGearV21AbsoluteApuClearReport;

typedef struct TopGearV22VideoInfo {
    uint32_t non_backdrop_pixels;
    uint32_t unique_colors;
    uint8_t mode,brightness,forced_blank,main_screen_mask,sub_screen_mask;
    uint8_t tiled_modes_0_to_6,mode7,objects,windows,main_sub_screen,color_math,brightness_and_forced_blank;
    uint8_t current_state_not_natural_frame;
    uint8_t passed;
    char bgr555_sha256[65];
} TopGearV22VideoInfo;


typedef struct TopGearV22MainCoreReport {
    uint64_t executed_instructions;
    TopGearCpuState endpoint_cpu;
    uint8_t historical_cycle_audits_bypassed;
    uint8_t audio_timing_deferred;
    uint8_t functional_apu_bootstrap_only;
    uint8_t runtime_opcode_decoder_used;
    uint8_t emulator_authority_used;
    uint8_t reached_non_rom_execution;
    uint8_t executable_wram_reached;
    uint64_t semantic_nmi_count;
    uint64_t semantic_irq_count;
    uint64_t semantic_hblank_read_count;
    uint64_t audio_shim_event_count;
    uint64_t open_bus_read_count;
    uint64_t controller_serial_read_count;
    uint64_t romwide_static_steps;
    uint64_t reentry_static_steps;
    uint64_t wram_static_steps;
    char frontier_address[24];
    char frontier_reason[512];
    char claim_boundary[1024];
} TopGearV22MainCoreReport;


typedef struct TopGearV23EventReport {
    uint64_t executed_instructions;
    TopGearCpuState endpoint_cpu;
    uint64_t nominal_processor_cycles;
    uint64_t elapsed_master_clocks;
    uint64_t refresh_events,nmi_count,irq_count,frame_events,scanlines_rendered;
    uint64_t autojoy_start_count,autojoy_completion_count,timing_context_miss_count;
    uint64_t audio_shim_event_count;
    uint16_t hcounter_master,vcounter_line;
    uint8_t field,audio_deferred,runtime_opcode_decoder_used,emulator_authority_used;
    uint8_t event_order_scheduler,physical_bus_cycle_certified;
    char frame_bgr555_sha256[65];
    char frontier_address[24];
    char frontier_reason[512];
    char claim_boundary[1536];
} TopGearV23EventReport;

typedef struct TopGearV24FrameInfo {
    uint64_t frame_index;
    uint64_t absolute_master_clock;
    uint64_t elapsed_master_clocks;
    uint16_t hcounter_master;
    uint16_t vcounter_line;
    uint8_t field;
    uint8_t bgmode_value;
    uint8_t mode;
    uint8_t main_screen_mask;
    uint8_t sub_screen_mask;
    char bgr555_sha256[65];
} TopGearV24FrameInfo;

typedef void (*TopGearV24FrameCallback)(void *user, const TopGearV24FrameInfo *frame);

typedef struct TopGearV24DurationReport {
    uint32_t requested_seconds;
    uint64_t target_master_clocks;
    uint64_t achieved_master_clocks;
    uint64_t executed_instructions;
    TopGearCpuState endpoint_cpu;
    uint64_t frame_events;
    uint64_t refresh_events;
    uint64_t nmi_count;
    uint64_t irq_count;
    uint64_t autojoy_start_count;
    uint64_t autojoy_completion_count;
    uint64_t timing_context_miss_count;
    uint64_t frame_sequence_fnv1a64;
    uint8_t observed_bgmode_mask;
    uint8_t audio_deferred;
    uint8_t runtime_opcode_decoder_used;
    uint8_t emulator_authority_used;
    uint8_t event_order_scheduler;
    uint8_t physical_bus_cycle_certified;
    uint8_t instruction_limit_hit;
    char first_frame_bgr555_sha256[65];
    char last_frame_bgr555_sha256[65];
    char frontier_address[24];
    char frontier_reason[512];
    char claim_boundary[1536];
} TopGearV24DurationReport;

/* Version 26 development-audio warm boot.  This does not make the historical
   hybrid backend production authority; it only replays Top Gear's real
   ROM-derived reset/IPL upload before the broad static gameplay route mirrors
   later APUIO writes for a listenable reference capture. */
typedef struct TopGearV26HybridWarmupReport {
    uint64_t scpu_instructions;
    uint64_t apu_program_entry_master_clock;
    uint64_t broad_scheduler_audio_offset;
    uint32_t uploaded_bytes;
    uint16_t smp_program_entrypoint;
    uint8_t upload_hash_matched;
    uint8_t hybrid_backend_required;
    char upload_sha256[65];
    char claim_boundary[768];
} TopGearV26HybridWarmupReport;

typedef struct TopGearV22RomwideCoverageInfo {
    uint32_t analyser_context_count;
    uint32_t analyser_edge_count;
    uint32_t normalized_generated_context_count;
    uint32_t generated_address_count;
    uint32_t generated_shard_count;
    uint32_t previously_generated_union_context_count;
    uint32_t newly_covered_normalized_context_count;
    uint8_t normalized_context_coverage_percent;
    uint8_t runtime_opcode_decoder_used;
    uint8_t emulator_authority_used;
    uint8_t audio_required_for_static_dispatch;
    char claim_boundary[1024];
} TopGearV22RomwideCoverageInfo;

typedef struct TopGearV20Full80f1CheckpointReport {
    uint32_t endpoint_profile;
    uint16_t initial_hcounter_master;
    uint16_t initial_vcounter_line;
    uint8_t initial_cpu_counter_mod256;
    uint8_t initial_field;
    uint16_t final_hcounter_master;
    uint16_t final_vcounter_line;
    uint8_t final_cpu_counter_mod256;
    uint8_t final_field;
    uint8_t control_0090;
    uint8_t control_0091;
    uint8_t deferred_dma_0424;
    uint8_t deferred_dma_0425;
    uint8_t hdma_enable_mask;
    uint8_t full_wram_epoch_frozen;
    uint8_t full_ppu_memory_epoch_frozen;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    char wram_sha256[65];
    char vram_sha256[65];
    char oam_sha256[65];
    char cgram_sha256[65];
    TopGearCpuState cpu_at_80f1;
    char frontier_address[24];
    char claim_boundary[1280];
} TopGearV20Full80f1CheckpointReport;

typedef struct TopGearV20VisibleHdmaReport {
    uint32_t endpoint_profile;
    uint32_t retained_cpu_mod8;
    uint32_t active_visible_scanline_count;
    uint32_t last_transfer_vcounter_line;
    uint32_t channel3_record_count;
    uint32_t channel4_record_count;
    uint32_t channel3_transfer_bytes;
    uint32_t channel4_transfer_bytes;
    uint32_t table_reload_a_bus_reads;
    uint32_t transfer_a_bus_reads;
    uint32_t b_bus_write_count;
    uint32_t dma_hdma_collision_count;
    uint64_t hdma_master_clocks;
    uint64_t physical_elapsed_master_clocks;
    uint16_t final_hcounter_master;
    uint16_t final_vcounter_line;
    uint16_t channel3_table_address;
    uint16_t channel4_table_address;
    uint16_t channel3_indirect_address;
    uint16_t channel4_indirect_address;
    uint8_t channel3_line_counter;
    uint8_t channel4_line_counter;
    uint8_t hdma_enable_mask;
    uint8_t hdma_active_mask;
    uint8_t hdma_completed_mask;
    uint8_t all_visible_transfers_joined;
    uint8_t terminal_records_verified;
    uint8_t channels_completed_before_vblank;
    uint8_t no_dma_hdma_collision_before_vblank;
    uint8_t later_vblank_nmi_crossed;
    uint8_t absolute_power_on_beam_proved;
    uint8_t static_backend_only;
    uint8_t hybrid_backend_acquired;
    uint8_t runtime_opcode_decoder_used;
    char cgram_sha256[65];
    TopGearCpuState cpu_after_visible_hdma;
    char frontier_address[32];
    char claim_boundary[1280];
} TopGearV20VisibleHdmaReport;

typedef struct TopGearV25CoverageInfo {
    uint64_t instructions_observed;
    uint32_t unique_rom_addresses;
    uint32_t unique_wram_addresses;
    uint64_t rom_bank_instruction_counts[16];
    uint32_t rom_bank_unique_addresses[16];
    uint64_t ppu_read_mask;
    uint64_t ppu_write_mask;
    uint32_t cpuio_read_mask;
    uint32_t cpuio_write_mask;
    uint16_t dma_register_offset_mask;
    uint8_t dma_channel_touched_mask;
    uint8_t apu_read_mask;
    uint8_t apu_write_mask;
    uint8_t runtime_opcode_decoder_used;
    uint8_t emulator_authority_used;
    char claim_boundary[512];
} TopGearV25CoverageInfo;

typedef struct TopGearV10JoinInfo {
    uint64_t scpu_frontier_master_clock;
    uint64_t scpu_frontier_instruction_count;
    uint64_t smp_completed_cycle_count;
    uint64_t smp_timer_read_event_cycle;
    uint32_t timer_phase_profile_count;
    uint32_t dsp_initial_phase_count;
    uint8_t scpu_instruction_timeline_proved;
    uint8_t exact_cross_domain_join_proved;
    uint8_t second_bbaa_producer_proved;
    uint8_t later_wram_epoch_proved;
    char blocker[224];
} TopGearV10JoinInfo;

enum TopGearHookEventType {
    TOPGEAR_HOOK_EVENT_RESET = 1,
    TOPGEAR_HOOK_EVENT_INSTRUCTION_BEFORE = 2,
    TOPGEAR_HOOK_EVENT_INSTRUCTION_AFTER = 3,
    TOPGEAR_HOOK_EVENT_BUS_READ = 4,
    TOPGEAR_HOOK_EVENT_BUS_WRITE = 5,
    TOPGEAR_HOOK_EVENT_CHECKPOINT = 6,
    TOPGEAR_HOOK_EVENT_FRONTIER = 7
};

/* Current-runtime hook contract:
   - INSTRUCTION events bracket one generated fixed W65C816 instruction from
     ROM, ROM re-entry, executable WRAM, or an interrupt trampoline. The BEFORE
     and AFTER events carry the original PBR:PC and exact instruction boundary.
   - BUS events report generated data/MMIO accesses, not instruction fetches.
     Their event order is authoritative; cycle_timing_exact remains zero because
     Version 27 does not claim exact physical 5A22 per-bus wait timing.
   - CHECKPOINT is emitted after each completed framebuffer is hashed at V=240.
     Query topgear_recomp_current_frame() for its monotonically increasing index.
   - Returning nonzero from BEFORE stops before that instruction; returning from
     AFTER stops after its scheduler accounting. A BUS stop aborts that access
     and is intended for fail-fast diagnostics rather than resumable breakpoints.
     Clear or replace the hook before resuming. Callback recursion is suppressed,
     and callbacks must not destroy or reset their core instance. */

#define TOPGEAR_HOOK_MASK_RESET (1u << 0)
#define TOPGEAR_HOOK_MASK_INSTRUCTION (1u << 1)
#define TOPGEAR_HOOK_MASK_BUS (1u << 2)
#define TOPGEAR_HOOK_MASK_CHECKPOINT (1u << 3)
#define TOPGEAR_HOOK_MASK_FRONTIER (1u << 4)
#define TOPGEAR_HOOK_MASK_ALL 0x1Fu

typedef struct TopGearHookEvent {
    uint32_t type;
    uint32_t address;
    uint64_t instruction_count;
    uint64_t master_clock;
    uint64_t master_clock_start;
    uint64_t processor_cycle;
    uint8_t value;
    uint8_t instruction_boundary_exact;
    uint8_t bus_cycle_master_clocks;
    uint8_t cycle_timing_exact;
    uint8_t documented_byte_order;
    uint8_t reserved[3];
} TopGearHookEvent;

typedef int (*TopGearHookCallback)(void *user, const TopGearHookEvent *event);

typedef struct TopGearV06ProtocolInfo {
    uint32_t reset_signature_consumer_address;
    uint32_t second_signature_consumer_address;
    uint16_t compared_signature;
    uint8_t reset_ipl_signature_proved;
    uint8_t second_epoch_consumer_proved;
    uint8_t second_epoch_producer_proved;
    uint8_t current_driver_port0;
    uint8_t current_driver_port1;
    uint8_t later_wram_epoch_proved;
    uint8_t reserved[2];
    char blocker[192];
} TopGearV06ProtocolInfo;

enum TopGearRunResult { TOPGEAR_RUN_ERROR=-1, TOPGEAR_RUN_FRONTIER=0, TOPGEAR_RUN_COMPLETE=1 };

const char *topgear_recomp_version_string(void);
const char *topgear_recomp_video_standard(void);
unsigned topgear_recomp_generated_context_count(void);
unsigned topgear_recomp_generated_smp_context_count(void);

int topgear_recomp_verify_rom(const uint8_t*,size_t,TopGearRomInfo*,char*,size_t);
int topgear_recomp_create(TopGearRecomp**,const uint8_t*,size_t,char*,size_t);
void topgear_recomp_destroy(TopGearRecomp*);
int topgear_recomp_reset(TopGearRecomp*,char*,size_t);
int topgear_recomp_set_audio_backend(TopGearRecomp*,enum TopGearAudioBackend,char*,size_t);
enum TopGearAudioBackend topgear_recomp_audio_backend(const TopGearRecomp*);
const char *topgear_recomp_audio_backend_name(const TopGearRecomp*);
int topgear_recomp_static_audio_status(const TopGearRecomp*,TopGearStaticAudioStatus*);
int topgear_recomp_set_hook(TopGearRecomp*,uint32_t,TopGearHookCallback,void*);
void topgear_recomp_clear_hook(TopGearRecomp*);
void topgear_recomp_request_stop(TopGearRecomp*);

/* Execute one fixed generated S-CPU context. No runtime opcode decoder exists. */
int topgear_recomp_step(TopGearRecomp*);
/* Execute one fixed generated S-SMP context after the verified IPL launch. */
int topgear_recomp_step_smp(TopGearRecomp*);

/* Version 22 broad semantic/static CPU surface. This performs one fixed generated
   W65C816 case selected by PBR:PC/E/M/X. It deliberately does not imply that
   physical beam/audio timing for the selected dynamic path is certified. */
int topgear_recomp_v22_static_step(TopGearRecomp*);
enum TopGearRunResult topgear_recomp_v22_run_main_core_semantic(TopGearRecomp*,uint64_t,TopGearV22MainCoreReport*);
int topgear_recomp_v22_romwide_coverage_info(const TopGearRecomp*,TopGearV22RomwideCoverageInfo*);
int topgear_recomp_v22_render_current_frame(TopGearRecomp*,TopGearV22VideoInfo*);
int topgear_recomp_v22_read_frame_bgr555(const TopGearRecomp*,uint32_t,void*,size_t);
/* Version 23 broad non-audio event-order scheduler. stop_after_frames=0 runs only by instruction cap. */
enum TopGearRunResult topgear_recomp_v23_run_main_core_events(TopGearRecomp*,uint64_t,uint32_t,TopGearV23EventReport*);
/* Version 27 incremental desktop-frontend runner. Initializes the current
   event-order scheduler once, then advances exactly one completed video frame
   per call while preserving CPU/PPU/APU state. */
enum TopGearRunResult topgear_recomp_v27_advance_frame(TopGearRecomp*,uint16_t p1_mask,uint16_t p2_mask,uint64_t max_instructions);
uint64_t topgear_recomp_v27_frame_count(const TopGearRecomp*);
int topgear_recomp_advance(TopGearRecomp*,uint16_t p1_mask,uint16_t p2_mask,
                           uint32_t frame_count,TopGearRecompFrameResult*);
int topgear_recomp_advance_headless(TopGearRecomp*,uint16_t p1_mask,
                                    uint16_t p2_mask,uint32_t frame_count,
                                    TopGearRecompFrameResult*);
uint32_t topgear_recomp_current_frame(const TopGearRecomp*);
int topgear_recomp_frame_bgra(TopGearRecomp*,uint32_t *destination,
                              size_t pixel_capacity);
int topgear_recomp_snapshot_save(const TopGearRecomp*,const char*,char*,size_t);
int topgear_recomp_snapshot_load(TopGearRecomp*,const char*,char*,size_t);
size_t topgear_recomp_sram_size(void);
int topgear_recomp_sram_copy(const TopGearRecomp*,void*,size_t);
int topgear_recomp_sram_load(TopGearRecomp*,const void*,size_t,char*,size_t);
int topgear_recomp_sram_dirty(const TopGearRecomp*);
void topgear_recomp_sram_mark_clean(TopGearRecomp*);
int topgear_recomp_audio_overflowed(const TopGearRecomp*);
void topgear_recomp_audio_clear_overflow(TopGearRecomp*);

enum TopGearRunResult topgear_recomp_v24_run_main_core_seconds(TopGearRecomp*,uint32_t,uint64_t,TopGearV24FrameCallback,void*,TopGearV24DurationReport*);
int topgear_recomp_v25_begin_coverage(TopGearRecomp*);
int topgear_recomp_v25_coverage_info(const TopGearRecomp*,TopGearV25CoverageInfo*);

void topgear_recomp_cpu_state(const TopGearRecomp*,TopGearCpuState*);
void topgear_recomp_smp_state(const TopGearRecomp*,TopGearSmpState*);
void topgear_recomp_frontier(const TopGearRecomp*,TopGearFrontierReceipt*);
uint64_t topgear_recomp_instruction_count(const TopGearRecomp*);
int topgear_recomp_failed(const TopGearRecomp*);
const char *topgear_recomp_last_error(const TopGearRecomp*);

int topgear_recomp_read_wram(const TopGearRecomp*,uint32_t,void*,size_t);
int topgear_recomp_read_aram(const TopGearRecomp*,uint32_t,void*,size_t);
int topgear_recomp_read_ppu_register(const TopGearRecomp*,uint16_t,uint8_t*);
int topgear_recomp_read_cpu_io_register(const TopGearRecomp*,uint16_t,uint8_t*);
/* S-CPU-visible APU port, written by the S-SMP. */
int topgear_recomp_read_apu_port(const TopGearRecomp*,unsigned,uint8_t*);
int topgear_recomp_read_scpu_to_smp_port(const TopGearRecomp*,unsigned,uint8_t*);
int topgear_recomp_v07_bus_event_info(const TopGearRecomp*,TopGearV07BusEventInfo*);
int topgear_recomp_v07_ppu_storage_info(const TopGearRecomp*,TopGearV07PpuStorageInfo*);
int topgear_recomp_v07_ppu_port_write(TopGearRecomp*,uint16_t,uint8_t);
int topgear_recomp_v07_ppu_port_read(TopGearRecomp*,uint16_t,uint8_t*);
int topgear_recomp_v07_dma_register_write(TopGearRecomp*,uint16_t,uint8_t);
int topgear_recomp_v07_dma_register_read(const TopGearRecomp*,uint16_t,uint8_t*);
int topgear_recomp_v07_read_vram(const TopGearRecomp*,uint32_t,void*,size_t);
int topgear_recomp_v07_read_oam(const TopGearRecomp*,uint32_t,void*,size_t);
int topgear_recomp_v07_read_cgram(const TopGearRecomp*,uint32_t,void*,size_t);
int topgear_recomp_v08_dma_register_write(TopGearRecomp*,uint16_t,uint8_t);
int topgear_recomp_v08_dma_info(const TopGearRecomp*,TopGearV08DmaInfo*);
int topgear_recomp_v08_cpu_io_write(TopGearRecomp*,uint16_t,uint8_t);
int topgear_recomp_v08_cpu_io_read(TopGearRecomp*,uint16_t,uint8_t*);
int topgear_recomp_v08_set_controller_state(TopGearRecomp*,unsigned,uint16_t);
int topgear_recomp_v08_begin_vblank(TopGearRecomp*);
int topgear_recomp_v08_advance_master_clocks(TopGearRecomp*,uint32_t);
int topgear_recomp_v08_interrupt_input_info(const TopGearRecomp*,TopGearV08InterruptInputInfo*);

int topgear_recomp_audio_clock_info(const TopGearRecomp*,TopGearAudioClockInfo*);
int topgear_recomp_dsp_scaffold_info(const TopGearRecomp*,TopGearDspScaffoldInfo*);
int topgear_recomp_read_smp_dsp_register(const TopGearRecomp*,uint8_t,uint8_t*);

/* Host transport is one-way. Reading, discarding, clearing, muting or device
   failure may never alter deterministic SNES execution state. Full Static
   S-SMP/S-DSP production audio feeds this FIFO directly. */
size_t topgear_recomp_audio_available(const TopGearRecomp*);
size_t topgear_recomp_audio_read(TopGearRecomp*,int16_t*,size_t);
size_t topgear_recomp_audio_discard(TopGearRecomp*,size_t);
void topgear_recomp_audio_clear(TopGearRecomp*);

#ifdef __cplusplus
}
#endif
#endif
