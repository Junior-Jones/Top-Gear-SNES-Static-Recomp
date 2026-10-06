#ifndef TOPGEAR_AUDIO_OUTPUT_SDL_H
#define TOPGEAR_AUDIO_OUTPUT_SDL_H

#include <stddef.h>
#include <stdint.h>

#include <SDL3/SDL.h>

#include "topgear_app_core.h"
#include "topgear_audio_resampler.h"
#include "topgear_mac_settings.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Speaker output for the macOS launcher. This is the Windows frontend's
   Jungle Strike/Mesen-derived audio manager with the DirectSound ring
   replaced by an SDL audio stream bound to a Core Audio device: the project
   resampler converts 32,040 Hz to the selected output rate, and priming,
   drift correction, recovery, volume and resume fade follow the same rules.
   SDL never resamples; the stream format equals the device request. */

#define TOPGEAR_MAC_AUDIO_QUEUE_HISTORY_CAPACITY 60u
#define TOPGEAR_MAC_AUDIO_DEFAULT_DEVICE_LABEL "Default macOS audio device"

typedef struct TopGearMacAudioDiagnostics {
    uint64_t native_frames_queued;
    uint64_t underruns;
    uint64_t queue_failures;
    uint64_t queue_recoveries;
    uint64_t device_reopens;
    uint32_t queue_depth_frames;
    uint32_t peak_queue_depth_frames;
    uint32_t target_latency_frames;
    float playback_ratio;
    float average_latency_ms;
    int device_sample_rate;
} TopGearMacAudioDiagnostics;

typedef struct TopGearMacAudioOutput {
    SDL_AudioDeviceID device;
    SDL_AudioStream *stream;
    TopGearAudioHermiteResampler resampler;
    uint32_t target_latency_frames;
    uint32_t queue_history[TOPGEAR_MAC_AUDIO_QUEUE_HISTORY_CAPACITY];
    uint32_t queue_history_index;
    uint32_t queue_history_count;
    int32_t under_target;
    int paused;
    int playing;
    int priming;
    int volume_percent;
    int device_sample_rate;
    int drift_correction_enabled;
    int drift_tolerance_ms;
    int max_rate_adjustment_ppm;
    int averaging_frames;
    int integral_correction_enabled;
    int recovery_enabled;
    int recovery_threshold_ms;
    uint32_t fade_frames_remaining;
    uint32_t fade_frames_total;
    int starved_last_pump;
    double playback_ratio;
    char opened_device_name[TOPGEAR_MAC_AUDIO_DEVICE_NAME_CAPACITY];
    TopGearMacAudioDiagnostics diagnostics;
} TopGearMacAudioOutput;

/* Playback device names, excluding the default entry. */
int topgear_mac_audio_device_count(void);
int topgear_mac_audio_device_name(int index, char *name, size_t capacity);

void topgear_mac_audio_output_initialize(TopGearMacAudioOutput *output);
/* Returns 1 when disabled audio is requested; the output then stays closed. */
int topgear_mac_audio_output_open(TopGearMacAudioOutput *output,
                                  const TopGearMacAudioSettings *settings,
                                  char *error, size_t error_capacity);
void topgear_mac_audio_output_close(TopGearMacAudioOutput *output);
/* Pause keeps queued audio; flush discards it and re-primes. */
void topgear_mac_audio_output_pause(TopGearMacAudioOutput *output);
void topgear_mac_audio_output_resume(TopGearMacAudioOutput *output);
void topgear_mac_audio_output_flush(TopGearMacAudioOutput *output);
int topgear_mac_audio_output_is_open(const TopGearMacAudioOutput *output);
void topgear_mac_audio_output_get_diagnostics(
    const TopGearMacAudioOutput *output,
    TopGearMacAudioDiagnostics *diagnostics);
uint32_t topgear_mac_audio_output_queued_frames(
    const TopGearMacAudioOutput *output);

/* Once per emulated frame: drain core PCM and run latency control. */
void topgear_mac_audio_output_pump(TopGearMacAudioOutput *output,
                                   TopGearApp *game);
/* Drain a partial in-frame DSP batch without end-of-frame control. */
void topgear_mac_audio_output_pump_progress(TopGearMacAudioOutput *output,
                                            TopGearApp *game);

#ifdef __cplusplus
}
#endif
#endif
