#ifndef TOPGEAR_AUDIO_OUTPUT_SDL3_H
#define TOPGEAR_AUDIO_OUTPUT_SDL3_H

#if !defined(_WIN32)
#error This audio backend is for Windows only.
#endif

#include <windows.h>
#include <stdint.h>

#include <SDL3/SDL_audio.h>

#include "topgear_static_recomp.h"
#include "topgear_audio_recorder_win32.h"

#define TOPGEAR_AUDIO_DEVICE_NAME_CAPACITY 128u

typedef struct TopGearAudioSettings {
    int enabled;
    int volume_percent;
    int latency_ms;
    wchar_t device_name[TOPGEAR_AUDIO_DEVICE_NAME_CAPACITY];
} TopGearAudioSettings;

typedef struct TopGearAudioDiagnostics {
    uint64_t native_frames_queued;
    uint64_t underruns;
    uint64_t queue_failures;
    uint64_t device_reopens;
    uint32_t queue_depth_frames;
    uint32_t target_latency_frames;
    float playback_ratio;
    int device_sample_rate;
} TopGearAudioDiagnostics;

typedef struct TopGearAudioOutput {
    SDL_AudioStream *stream;
    uint32_t target_latency_frames;
    uint32_t fade_frames_remaining;
    int paused;
    int priming;
    int volume_percent;
    int audio_subsystem_initialized;
    int starved_last_pump;
    float playback_ratio;
    wchar_t opened_device_name[TOPGEAR_AUDIO_DEVICE_NAME_CAPACITY];
    TopGearAudioDiagnostics diagnostics;
} TopGearAudioOutput;

void topgear_audio_settings_defaults(TopGearAudioSettings *settings);
void topgear_audio_settings_load(TopGearAudioSettings *settings,
                                 const wchar_t *ini_path);
void topgear_audio_settings_save(const TopGearAudioSettings *settings,
                                 const wchar_t *ini_path);

UINT topgear_audio_device_count(void);
int topgear_audio_device_name(UINT device_index, wchar_t *name,
                              size_t name_capacity);

void topgear_audio_output_initialize(TopGearAudioOutput *output);
int topgear_audio_output_open(TopGearAudioOutput *output,
                              const TopGearAudioSettings *settings,
                              wchar_t *error, size_t error_capacity);
void topgear_audio_output_close(TopGearAudioOutput *output);
void topgear_audio_output_pause(TopGearAudioOutput *output);
void topgear_audio_output_resume(TopGearAudioOutput *output);
void topgear_audio_output_flush(TopGearAudioOutput *output);
int topgear_audio_output_is_open(const TopGearAudioOutput *output);
void topgear_audio_output_get_diagnostics(
    const TopGearAudioOutput *output, TopGearAudioDiagnostics *diagnostics);

/* Recording remains native 32,040 Hz PCM; only speaker output is resampled. */
void topgear_audio_output_pump(TopGearAudioOutput *output,
                               TopGearAudioRecorderWin32 *recorder,
                               TopGearRecomp *game);

#endif
