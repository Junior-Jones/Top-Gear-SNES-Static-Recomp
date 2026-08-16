#include "topgear_diagnostics_log_win32.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#define DIAGNOSTIC_PATH_CAPACITY 4096u
#define WRAM_BYTES 0x20000u
#define ARAM_BYTES 0x10000u

static volatile LONG g_diagnostic_sequence;

static void copy_wide(wchar_t *output, size_t capacity,
                      const wchar_t *input) {
    if (!output || capacity == 0u) return;
    if (!input) input = L"";
    wcsncpy(output, input, capacity - 1u);
    output[capacity - 1u] = L'\0';
}

static int wide_to_utf8(const wchar_t *input, char *output, size_t capacity) {
    int result;
    if (!output || capacity == 0u) return 0;
    if (!input) input = L"";
    result = WideCharToMultiByte(CP_UTF8, 0, input, -1, output,
                                 (int)capacity, NULL, NULL);
    if (result <= 0) output[0] = '\0';
    output[capacity - 1u] = '\0';
    return result > 0;
}

static void sanitize_event_token(const wchar_t *event_name, wchar_t *output,
                                 size_t capacity) {
    size_t source = 0u;
    size_t destination = 0u;
    if (!output || capacity == 0u) return;
    if (!event_name || !event_name[0]) event_name = L"diagnostic";
    while (event_name[source] && destination + 1u < capacity) {
        wchar_t value = event_name[source++];
        if ((value >= L'a' && value <= L'z') ||
            (value >= L'A' && value <= L'Z') ||
            (value >= L'0' && value <= L'9') || value == L'-' ||
            value == L'_')
            output[destination++] = value;
        else
            output[destination++] = L'-';
    }
    output[destination] = L'\0';
}

static uint64_t fnv1a_update(uint64_t hash, const uint8_t *bytes,
                             size_t size) {
    size_t index;
    for (index = 0u; index < size; ++index) {
        hash ^= bytes[index];
        hash *= UINT64_C(1099511628211);
    }
    return hash;
}

typedef int (*DiagnosticMemoryReader)(const TopGearRecomp *, uint32_t,
                                      void *, size_t);

static int hash_memory(const TopGearRecomp *game, DiagnosticMemoryReader read,
                       uint32_t bytes, uint64_t *result) {
    uint8_t buffer[4096];
    uint32_t offset = 0u;
    uint64_t hash = UINT64_C(1469598103934665603);
    if (!game || !read || !result) return 0;
    while (offset < bytes) {
        size_t count = bytes - offset;
        if (count > sizeof(buffer)) count = sizeof(buffer);
        if (!read(game, offset, buffer, count)) return 0;
        hash = fnv1a_update(hash, buffer, count);
        offset += (uint32_t)count;
    }
    *result = hash;
    return 1;
}

static int hash_frame(TopGearRecomp *game, uint64_t *result) {
    size_t count = (size_t)TOPGEAR_RECOMP_FRAME_WIDTH *
                   TOPGEAR_RECOMP_FRAME_HEIGHT;
    uint32_t *pixels;
    if (!game || !result) return 0;
    pixels = (uint32_t *)malloc(count * sizeof(*pixels));
    if (!pixels) return 0;
    if (!topgear_recomp_frame_bgra(game, pixels, count)) {
        free(pixels);
        return 0;
    }
    *result = fnv1a_update(UINT64_C(1469598103934665603),
                           (const uint8_t *)pixels,
                           count * sizeof(*pixels));
    free(pixels);
    return 1;
}

static void write_register_dump(FILE *file, const TopGearRecomp *game) {
    uint16_t address;
    uint8_t value;
    unsigned port;
    if (!file || !game) return;
    fputs("\n[CPU-IO]\n", file);
    for (address = 0x4200u; address <= 0x421fu; ++address)
        if (topgear_recomp_read_cpu_io_register(game, address, &value))
            fprintf(file, "%04X=%02X\n", address, value);
    fputs("\n[PPU]\n", file);
    for (address = 0x2100u; address <= 0x213fu; ++address)
        if (topgear_recomp_read_ppu_register(game, address, &value))
            fprintf(file, "%04X=%02X\n", address, value);
    fputs("\n[APU-Ports]\n", file);
    for (port = 0u; port < 4u; ++port) {
        if (topgear_recomp_read_apu_port(game, port, &value))
            fprintf(file, "SMP-to-SCPU-%u=%02X\n", port, value);
        if (topgear_recomp_read_scpu_to_smp_port(game, port, &value))
            fprintf(file, "SCPU-to-SMP-%u=%02X\n", port, value);
    }
}

int topgear_diagnostics_write(
    const wchar_t *logs_directory, const wchar_t *event_name,
    const wchar_t *detail, const wchar_t *artifact_path,
    TopGearRecomp *game, const TopGearHostDiagnosticState *host,
    const EXCEPTION_POINTERS *exception, wchar_t *saved_path,
    size_t saved_capacity) {
    SYSTEMTIME now;
    wchar_t token[64];
    wchar_t log_path[DIAGNOSTIC_PATH_CAPACITY];
    wchar_t snapshot_path[DIAGNOSTIC_PATH_CAPACITY];
    char detail_utf8[1024];
    char artifact_utf8[DIAGNOSTIC_PATH_CAPACITY];
    char snapshot_utf8[DIAGNOSTIC_PATH_CAPACITY];
    char snapshot_error[256] = {0};
    FILE *file = NULL;
    LONG sequence;
    int snapshot_saved = 0;
    TopGearCpuState cpu;
    TopGearSmpState smp;
    TopGearFrontierReceipt frontier;
    TopGearStaticAudioStatus static_audio;
    uint64_t wram_hash = 0u;
    uint64_t aram_hash = 0u;
    uint64_t frame_hash = 0u;
    int have_wram_hash = 0;
    int have_aram_hash = 0;
    int have_frame_hash = 0;
    if (saved_path && saved_capacity) saved_path[0] = L'\0';
    if (!logs_directory || !logs_directory[0]) return 0;
    if (!CreateDirectoryW(logs_directory, NULL) &&
        GetLastError() != ERROR_ALREADY_EXISTS) return 0;
    GetLocalTime(&now);
    sequence = InterlockedIncrement(&g_diagnostic_sequence);
    sanitize_event_token(event_name, token,
                         sizeof(token) / sizeof(token[0]));
    (void)_snwprintf(log_path, DIAGNOSTIC_PATH_CAPACITY,
        L"%s\\%s-%04u%02u%02u-%02u%02u%02u-%03u-p%lu-%ld.txt",
        logs_directory, token, (unsigned)now.wYear, (unsigned)now.wMonth,
        (unsigned)now.wDay, (unsigned)now.wHour, (unsigned)now.wMinute,
        (unsigned)now.wSecond, (unsigned)now.wMilliseconds,
        (unsigned long)GetCurrentProcessId(), (long)sequence);
    log_path[DIAGNOSTIC_PATH_CAPACITY - 1u] = L'\0';
    (void)_snwprintf(snapshot_path, DIAGNOSTIC_PATH_CAPACITY,
        L"%s\\%s-%04u%02u%02u-%02u%02u%02u-%03u-p%lu-%ld.scsnap",
        logs_directory, token, (unsigned)now.wYear, (unsigned)now.wMonth,
        (unsigned)now.wDay, (unsigned)now.wHour, (unsigned)now.wMinute,
        (unsigned)now.wSecond, (unsigned)now.wMilliseconds,
        (unsigned long)GetCurrentProcessId(), (long)sequence);
    snapshot_path[DIAGNOSTIC_PATH_CAPACITY - 1u] = L'\0';
    wide_to_utf8(detail, detail_utf8, sizeof(detail_utf8));
    wide_to_utf8(artifact_path, artifact_utf8, sizeof(artifact_utf8));
    wide_to_utf8(snapshot_path, snapshot_utf8, sizeof(snapshot_utf8));
    if (game)
        snapshot_saved = topgear_recomp_snapshot_save(
            game, snapshot_utf8, snapshot_error, sizeof(snapshot_error));
    file = _wfopen(log_path, L"wb");
    if (!file) return 0;
    fprintf(file, "Format=TopGear-Diagnostic-v1\r\n"
                  "TimestampLocal=%04u-%02u-%02uT%02u:%02u:%02u.%03u\r\n"
                  "Event=%ls\r\nDetail=%s\r\nArtifact=%s\r\n"
                  "ProcessId=%lu\r\nThreadId=%lu\r\n",
            (unsigned)now.wYear, (unsigned)now.wMonth, (unsigned)now.wDay,
            (unsigned)now.wHour, (unsigned)now.wMinute,
            (unsigned)now.wSecond, (unsigned)now.wMilliseconds,
            event_name ? event_name : L"diagnostic", detail_utf8,
            artifact_utf8, (unsigned long)GetCurrentProcessId(),
            (unsigned long)GetCurrentThreadId());
    if (exception && exception->ExceptionRecord) {
        fprintf(file, "\r\n[Exception]\r\nCode=%08lX\r\nAddress=%p\r\nFlags=%08lX\r\n",
                (unsigned long)exception->ExceptionRecord->ExceptionCode,
                exception->ExceptionRecord->ExceptionAddress,
                (unsigned long)exception->ExceptionRecord->ExceptionFlags);
    }
    if (host) {
        fprintf(file,
            "\r\n[Host]\r\nPaused=%d\r\nPresentationHidden=%d\r\n"
            "FullscreenActive=%d\r\nLoading=%d\r\nIntegerScale=%d\r\n"
            "CorrectAspect=%d\r\nVSyncEnabled=%d\r\nAudioEnabled=%d\r\n"
            "AudioVolumePercent=%d\r\nAudioLatencyMs=%d\r\n"
            "HeldInputP1=%04X\r\nHeldInputP2=%04X\r\n"
            "GamepadInputP1=%04X\r\nGamepadInputP2=%04X\r\n"
            "EffectiveInputP1=%04X\r\nEffectiveInputP2=%04X\r\n"
            "PacingTimerTicks=%llu\r\nPacingSkippedDeadlines=%llu\r\n"
            "PacingResyncs=%llu\r\nPacingMaxBatch=%u\r\n",
            host->paused, host->presentation_hidden, host->fullscreen_active,
            host->loading, host->integer_scale, host->correct_aspect,
            host->vsync_enabled, host->audio_enabled,
            host->audio_volume_percent, host->audio_latency_ms,
            host->held_input[0], host->held_input[1],
            host->gamepad_input[0], host->gamepad_input[1],
            host->effective_input[0], host->effective_input[1],
            (unsigned long long)host->pacing_timer_ticks,
            (unsigned long long)host->pacing_skipped_deadlines,
            (unsigned long long)host->pacing_resyncs, host->pacing_max_batch);
        fprintf(file,
            "\r\n[VideoHost]\r\nRenderer=%s\r\nUsingGPU=%d\r\n"
            "VSync=%d\r\nSubmittedFrames=%llu\r\nPresentedFrames=%llu\r\n"
            "DroppedPresentations=%llu\r\nRendererRecoveries=%llu\r\n"
            "PresentationFailures=%llu\r\n",
            host->video.renderer_name, host->video.using_gpu,
            host->video.vsync_enabled,
            (unsigned long long)host->video.submitted_frames,
            (unsigned long long)host->video.presented_frames,
            (unsigned long long)host->video.dropped_presentations,
            (unsigned long long)host->video.renderer_recoveries,
            (unsigned long long)host->video.presentation_failures);
        fprintf(file,
            "\r\n[AudioHost]\r\nNativeFramesQueued=%llu\r\nUnderruns=%llu\r\n"
            "QueueFailures=%llu\r\nDeviceReopens=%llu\r\nQueueDepthFrames=%u\r\n"
            "TargetLatencyFrames=%u\r\nPlaybackRatio=%.6f\r\nDeviceSampleRate=%d\r\n",
            (unsigned long long)host->audio.native_frames_queued,
            (unsigned long long)host->audio.underruns,
            (unsigned long long)host->audio.queue_failures,
            (unsigned long long)host->audio.device_reopens,
            host->audio.queue_depth_frames, host->audio.target_latency_frames,
            (double)host->audio.playback_ratio,
            host->audio.device_sample_rate);
    }
    fprintf(file, "\r\n[StaticCore]\r\nPresent=%d\r\n", game != NULL);
    if (game) {
        memset(&cpu, 0, sizeof(cpu));
        memset(&smp, 0, sizeof(smp));
        memset(&frontier, 0, sizeof(frontier));
        memset(&static_audio, 0, sizeof(static_audio));
        topgear_recomp_cpu_state(game, &cpu);
        topgear_recomp_smp_state(game, &smp);
        topgear_recomp_frontier(game, &frontier);
        (void)topgear_recomp_static_audio_status(game, &static_audio);
        have_wram_hash = hash_memory(game, topgear_recomp_read_wram,
                                     WRAM_BYTES, &wram_hash);
        have_aram_hash = hash_memory(game, topgear_recomp_read_aram,
                                     ARAM_BYTES, &aram_hash);
        have_frame_hash = hash_frame(game, &frame_hash);
        fprintf(file,
            "Version=%s\r\nFrame=%u\r\nV27Frame=%llu\r\nInstructions=%llu\r\n"
            "Failed=%d\r\nLastError=%s\r\nFrontierReached=%u\r\n"
            "FrontierAddress=%s\r\nFrontierReason=%s\r\n"
            "FrontierInstruction=%llu\r\nCPU=%02X:%04X A=%04X X=%04X Y=%04X "
            "S=%04X D=%04X DBR=%02X P=%02X E=%u\r\n"
            "SMP=PC:%04X A=%02X X=%02X Y=%02X SP=%02X PSW=%02X "
            "Instructions=%llu Cycles=%llu\r\n",
            topgear_recomp_version_string(), topgear_recomp_current_frame(game),
            (unsigned long long)topgear_recomp_v27_frame_count(game),
            (unsigned long long)topgear_recomp_instruction_count(game),
            topgear_recomp_failed(game), topgear_recomp_last_error(game),
            frontier.reached, frontier.address, frontier.reason,
            (unsigned long long)frontier.instruction_count,
            cpu.pbr, cpu.pc, cpu.a, cpu.x, cpu.y, cpu.s, cpu.d, cpu.dbr,
            cpu.p, cpu.e, smp.pc, smp.a, smp.x, smp.y, smp.sp, smp.psw,
            (unsigned long long)smp.instruction_count,
            (unsigned long long)smp.cycle_count);
        fprintf(file,
            "\r\n[StaticAudio]\r\nBackend=%s\r\nInitialized=%u\r\n"
            "SynchronizedMasterClock=%llu\r\nSMPCycles=%llu\r\n"
            "SMPInstructions=%llu\r\nAOTValidatedInstructions=%llu\r\n"
            "PCMFrames=%llu\r\nFIFODroppedFrames=%llu\r\nSyncCalls=%llu\r\n"
            "RendezvousHash=%016llX\r\nCPUPortEvents=%llu\r\n"
            "CPUPortEventHash=%016llX\r\nSMPPC=%04X\r\nAOTFailPC=%04X\r\n"
            "AOTFailed=%u\r\nAOTFailReason=%u\r\nExpectedOpcode=%02X\r\n"
            "ActualOpcode=%02X\r\nSDSPStaticFailed=%u\r\nDSPPhase=%u\r\n",
            static_audio.backend_name, static_audio.initialized,
            (unsigned long long)static_audio.synchronized_master_clock,
            (unsigned long long)static_audio.smp_cycles,
            (unsigned long long)static_audio.smp_instructions,
            (unsigned long long)static_audio.aot_validated_instructions,
            (unsigned long long)static_audio.pcm_frames,
            (unsigned long long)static_audio.fifo_dropped_frames,
            (unsigned long long)static_audio.sync_calls,
            (unsigned long long)static_audio.rendezvous_hash,
            (unsigned long long)static_audio.cpu_port_event_count,
            (unsigned long long)static_audio.cpu_port_event_hash,
            static_audio.smp_pc, static_audio.aot_fail_pc,
            static_audio.aot_failed, static_audio.aot_fail_reason,
            static_audio.expected_opcode, static_audio.actual_opcode,
            static_audio.sdsp_static_failed, static_audio.dsp_phase);
        fprintf(file,
            "\r\n[StateArtifacts]\r\nSnapshotSaved=%d\r\nSnapshotPath=%s\r\n"
            "SnapshotError=%s\r\nWRAM-FNV1A64=%s%016llX\r\n"
            "ARAM-FNV1A64=%s%016llX\r\nFrameBGRA-FNV1A64=%s%016llX\r\n",
            snapshot_saved, snapshot_saved ? snapshot_utf8 : "",
            snapshot_error, have_wram_hash ? "" : "unavailable/",
            (unsigned long long)wram_hash,
            have_aram_hash ? "" : "unavailable/",
            (unsigned long long)aram_hash,
            have_frame_hash ? "" : "unavailable/",
            (unsigned long long)frame_hash);
        write_register_dump(file, game);
    }
    fflush(file);
    fclose(file);
    if (saved_path && saved_capacity)
        copy_wide(saved_path, saved_capacity, log_path);
    return 1;
}
