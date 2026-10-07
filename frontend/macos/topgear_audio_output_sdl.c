#include "topgear_audio_output_sdl.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

#define AUDIO_FINE_RATE_STEP 0.00003125
#define AUDIO_MAX_SUB_ADJUSTMENT 3600
#define AUDIO_NATIVE_STAGING_FRAMES 4096u
#define AUDIO_HOST_STAGING_FRAMES 16384u
#define AUDIO_BLOCK_ALIGN_BYTES \
    (TOPGEAR_APP_AUDIO_CHANNELS * (uint32_t)sizeof(int16_t))

int topgear_mac_audio_device_count(void) {
    int count = 0;
    SDL_AudioDeviceID *devices = SDL_GetAudioPlaybackDevices(&count);
    SDL_free(devices);
    return devices ? count : 0;
}

int topgear_mac_audio_device_name(int index, char *name, size_t capacity) {
    int count = 0;
    int found = 0;
    SDL_AudioDeviceID *devices;
    if (!name || capacity == 0u) return 0;
    name[0] = '\0';
    devices = SDL_GetAudioPlaybackDevices(&count);
    if (devices && index >= 0 && index < count) {
        const char *text = SDL_GetAudioDeviceName(devices[index]);
        if (text && text[0]) {
            (void)snprintf(name, capacity, "%s", text);
            found = 1;
        }
    }
    SDL_free(devices);
    return found;
}

static SDL_AudioDeviceID resolve_device(const char *requested, char *resolved,
                                        size_t capacity) {
    int count = 0;
    int index;
    SDL_AudioDeviceID selected = SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK;
    SDL_AudioDeviceID *devices;
    (void)snprintf(resolved, capacity, "%s",
                   TOPGEAR_MAC_AUDIO_DEFAULT_DEVICE_LABEL);
    if (!requested || !requested[0]) return selected;
    devices = SDL_GetAudioPlaybackDevices(&count);
    for (index = 0; devices && index < count; ++index) {
        const char *name = SDL_GetAudioDeviceName(devices[index]);
        if (name && strcmp(name, requested) == 0) {
            selected = devices[index];
            (void)snprintf(resolved, capacity, "%s", requested);
            break;
        }
    }
    SDL_free(devices);
    return selected;
}

void topgear_mac_audio_output_initialize(TopGearMacAudioOutput *output) {
    if (output) memset(output, 0, sizeof(*output));
}

static void reset_rate_control(TopGearMacAudioOutput *output) {
    output->queue_history_index = 0u;
    output->queue_history_count = 0u;
    output->under_target = 0;
    memset(output->queue_history, 0, sizeof(output->queue_history));
    output->playback_ratio = 1.0;
    output->diagnostics.playback_ratio = 1.0f;
    topgear_audio_resampler_set_rates(&output->resampler,
        (double)TOPGEAR_APP_HOST_AUDIO_SAMPLE_RATE,
        (double)output->device_sample_rate);
    topgear_audio_resampler_reset(&output->resampler);
}

int topgear_mac_audio_output_open(TopGearMacAudioOutput *output,
                                  const TopGearMacAudioSettings *settings,
                                  char *error, size_t error_capacity) {
    SDL_AudioSpec spec;
    SDL_AudioDeviceID requested;
    if (error && error_capacity) error[0] = '\0';
    if (!output || !settings) return 0;
    topgear_mac_audio_output_close(output);
    output->volume_percent = settings->volume_percent;
    output->device_sample_rate = settings->output_sample_rate;
    output->drift_correction_enabled = settings->drift_correction_enabled;
    output->drift_tolerance_ms = settings->drift_tolerance_ms;
    output->max_rate_adjustment_ppm = settings->max_rate_adjustment_ppm;
    output->averaging_frames = settings->averaging_frames;
    output->integral_correction_enabled = settings->integral_correction_enabled;
    output->recovery_enabled = settings->recovery_enabled;
    output->recovery_threshold_ms = settings->recovery_threshold_ms;
    output->fade_frames_total = (uint32_t)(
        ((uint64_t)settings->output_sample_rate *
         (uint64_t)settings->resume_fade_ms) / 1000u);
    if (!settings->enabled) return 1;

    requested = resolve_device(settings->device_name,
                               output->opened_device_name,
                               sizeof(output->opened_device_name));
    spec.format = SDL_AUDIO_S16;
    spec.channels = (int)TOPGEAR_APP_AUDIO_CHANNELS;
    spec.freq = output->device_sample_rate;
    output->device = SDL_OpenAudioDevice(requested, &spec);
    if (!output->device) {
        if (error && error_capacity)
            (void)snprintf(error, error_capacity,
                           "Unable to open the selected audio device (%s)",
                           SDL_GetError());
        memset(output, 0, sizeof(*output));
        return 0;
    }
    /* Opened devices start running; hold them until the first prime. */
    (void)SDL_PauseAudioDevice(output->device);
    output->stream = SDL_CreateAudioStream(&spec, &spec);
    if (!output->stream || !SDL_BindAudioStream(output->device, output->stream)) {
        if (error && error_capacity)
            (void)snprintf(error, error_capacity,
                           "Unable to create the playback stream (%s)",
                           SDL_GetError());
        topgear_mac_audio_output_close(output);
        return 0;
    }
    output->target_latency_frames =
        (uint32_t)(((uint64_t)output->device_sample_rate *
                    (uint64_t)(settings->safety_buffer_ms +
                        (settings->latency_enabled ? settings->latency_ms : 0))) /
                   1000u);
    topgear_audio_resampler_set_mode(&output->resampler,
                                     settings->resampler_mode);
    reset_rate_control(output);
    output->paused = 1;
    output->priming = 1;
    output->fade_frames_remaining = output->fade_frames_total;
    output->diagnostics.target_latency_frames = output->target_latency_frames;
    output->diagnostics.playback_ratio = 1.0f;
    output->diagnostics.device_sample_rate = output->device_sample_rate;
    return 1;
}

void topgear_mac_audio_output_close(TopGearMacAudioOutput *output) {
    if (!output) return;
    if (output->stream) SDL_DestroyAudioStream(output->stream);
    if (output->device) SDL_CloseAudioDevice(output->device);
    memset(output, 0, sizeof(*output));
}

int topgear_mac_audio_output_is_open(const TopGearMacAudioOutput *output) {
    return output && output->stream != NULL;
}

uint32_t topgear_mac_audio_output_queued_frames(
    const TopGearMacAudioOutput *output) {
    int bytes;
    if (!output || !output->stream) return 0u;
    /* Frames not yet pulled by the device: the producer-to-play-cursor
       distance the DirectSound manager measures. */
    bytes = SDL_GetAudioStreamQueued(output->stream);
    return bytes > 0 ? (uint32_t)bytes / AUDIO_BLOCK_ALIGN_BYTES : 0u;
}

static int start_playback(TopGearMacAudioOutput *output) {
    if (!output || !output->device) return 0;
    if (!SDL_ResumeAudioDevice(output->device)) {
        output->diagnostics.queue_failures++;
        return 0;
    }
    output->playing = 1;
    return 1;
}

static void stop_playback(TopGearMacAudioOutput *output) {
    if (output->device) (void)SDL_PauseAudioDevice(output->device);
    output->playing = 0;
}

void topgear_mac_audio_output_flush(TopGearMacAudioOutput *output) {
    if (!output || !output->stream) return;
    stop_playback(output);
    (void)SDL_ClearAudioStream(output->stream);
    output->priming = 1;
    output->starved_last_pump = 0;
    reset_rate_control(output);
    output->diagnostics.queue_depth_frames = 0u;
}

void topgear_mac_audio_output_pause(TopGearMacAudioOutput *output) {
    if (!output || !output->stream || output->paused) return;
    /* Pause stops playback without destroying queued samples; flush is the
       operation that clears them. */
    stop_playback(output);
    output->paused = 1;
}

void topgear_mac_audio_output_resume(TopGearMacAudioOutput *output) {
    if (!output || !output->stream || !output->paused) return;
    output->paused = 0;
    output->priming = topgear_mac_audio_output_queued_frames(output) <
                      output->target_latency_frames / 2u;
    output->fade_frames_remaining = output->fade_frames_total;
    if (!output->priming) (void)start_playback(output);
}

static void process_end_of_frame(TopGearMacAudioOutput *output) {
    uint32_t queue_frames;
    uint64_t queue_sum = 0u;
    double average_latency_ms;
    double latency_gap;
    double adjustment;
    double sub_adjustment;
    double requested;
    uint32_t index;
    if (output->priming || output->paused || !output->playing) return;
    queue_frames = topgear_mac_audio_output_queued_frames(output);
    output->queue_history[output->queue_history_index] = queue_frames;
    output->queue_history_index = (output->queue_history_index + 1u) %
        (uint32_t)output->averaging_frames;
    if (output->queue_history_count < (uint32_t)output->averaging_frames)
        output->queue_history_count++;
    if (output->queue_history_count < (uint32_t)output->averaging_frames)
        return;
    for (index = 0u; index < (uint32_t)output->averaging_frames; ++index)
        queue_sum += output->queue_history[index];
    average_latency_ms =
        ((double)queue_sum / (double)output->averaging_frames) * 1000.0 /
        (double)output->device_sample_rate;
    output->diagnostics.average_latency_ms = (float)average_latency_ms;
    latency_gap = average_latency_ms -
        ((double)output->target_latency_frames * 1000.0 /
         (double)output->device_sample_rate);
    if (!output->drift_correction_enabled) {
        output->under_target = 0;
        output->playback_ratio = 1.0;
        topgear_audio_resampler_set_rates(&output->resampler,
            (double)TOPGEAR_APP_HOST_AUDIO_SAMPLE_RATE,
            (double)output->device_sample_rate);
        output->diagnostics.playback_ratio = 1.0f;
    }
    adjustment = ceil((fabs(latency_gap) -
                       (double)output->drift_tolerance_ms) * 8.0) *
                 AUDIO_FINE_RATE_STEP;
    if (adjustment < 0.0) adjustment = 0.0;
    if (adjustment > (double)output->max_rate_adjustment_ppm / 1000000.0)
        adjustment = (double)output->max_rate_adjustment_ppm / 1000000.0;
    if (output->drift_correction_enabled &&
        output->integral_correction_enabled && latency_gap < 0.0 &&
        output->under_target < AUDIO_MAX_SUB_ADJUSTMENT)
        output->under_target++;
    else if (output->drift_correction_enabled &&
             output->integral_correction_enabled && latency_gap > 0.0 &&
             output->under_target > -AUDIO_MAX_SUB_ADJUSTMENT)
        output->under_target--;
    if (!output->drift_correction_enabled ||
        !output->integral_correction_enabled) output->under_target = 0;
    sub_adjustment = AUDIO_FINE_RATE_STEP *
                     (double)output->under_target / 180.0;
    requested = output->playback_ratio;
    if (output->drift_correction_enabled && adjustment > 0.0) {
        if (latency_gap > (double)output->drift_tolerance_ms)
            requested = 1.0 - adjustment + sub_adjustment;
        else if (latency_gap < -(double)output->drift_tolerance_ms)
            requested = 1.0 + adjustment + sub_adjustment;
    } else if (output->drift_correction_enabled && fabs(latency_gap) < 1.0) {
        requested = 1.0 + sub_adjustment;
    }
    if (output->drift_correction_enabled) {
        output->playback_ratio = requested;
        topgear_audio_resampler_set_rates(&output->resampler,
            (double)TOPGEAR_APP_HOST_AUDIO_SAMPLE_RATE,
            (double)output->device_sample_rate * requested);
        output->diagnostics.playback_ratio = (float)requested;
    }
    if (output->recovery_enabled && average_latency_ms > 0.0 &&
        fabs(latency_gap) > (double)output->recovery_threshold_ms) {
        /* Stop and re-prime when the measured latency drifts beyond the
           recovery limit, as the Windows frontend does. */
        stop_playback(output);
        if (SDL_ClearAudioStream(output->stream)) {
            output->diagnostics.queue_recoveries++;
            output->priming = 1;
            output->starved_last_pump = 0;
            reset_rate_control(output);
            output->diagnostics.queue_depth_frames = 0u;
        } else {
            output->diagnostics.queue_failures++;
        }
    }
}

static void apply_volume(TopGearMacAudioOutput *output, int16_t *samples,
                         size_t frame_count) {
    size_t frame;
    for (frame = 0u; frame < frame_count; ++frame) {
        int percent = output->volume_percent;
        if (output->fade_frames_remaining && output->fade_frames_total) {
            uint32_t completed = output->fade_frames_total -
                                 output->fade_frames_remaining;
            percent = (int)((uint64_t)percent * completed /
                            output->fade_frames_total);
            output->fade_frames_remaining--;
        }
        samples[frame * 2u] = (int16_t)(
            (int32_t)samples[frame * 2u] * percent / 100);
        samples[frame * 2u + 1u] = (int16_t)(
            (int32_t)samples[frame * 2u + 1u] * percent / 100);
    }
}

static void pump_audio(TopGearMacAudioOutput *output, TopGearApp *game,
                       int end_of_frame) {
    int16_t native_staging[AUDIO_NATIVE_STAGING_FRAMES *
                           TOPGEAR_APP_AUDIO_CHANNELS];
    int16_t host_staging[AUDIO_HOST_STAGING_FRAMES *
                         TOPGEAR_APP_AUDIO_CHANNELS];
    if (output && output->stream && !output->paused && output->playing) {
        int starved = topgear_mac_audio_output_queued_frames(output) == 0u;
        if (starved && !output->starved_last_pump)
            output->diagnostics.underruns++;
        output->starved_last_pump = starved;
    }
    if (!game) return;
    while (topgear_app_audio_available(game) > 0u) {
        size_t available = topgear_app_audio_available(game);
        size_t request = available > AUDIO_NATIVE_STAGING_FRAMES ?
                         AUDIO_NATIVE_STAGING_FRAMES : available;
        size_t frames = topgear_app_audio_read(game, native_staging, request);
        if (!frames) break;
        if (output && output->stream) {
            size_t host_frames = topgear_audio_resampler_process(
                &output->resampler, native_staging, frames, host_staging,
                AUDIO_HOST_STAGING_FRAMES);
            apply_volume(output, host_staging, host_frames);
            if (!SDL_PutAudioStreamData(output->stream, host_staging,
                    (int)(host_frames * AUDIO_BLOCK_ALIGN_BYTES)))
                output->diagnostics.queue_failures++;
            else
                output->diagnostics.native_frames_queued += frames;
        }
    }
    if (!output || !output->stream) return;
    output->diagnostics.queue_depth_frames =
        topgear_mac_audio_output_queued_frames(output);
    if (output->diagnostics.peak_queue_depth_frames <
        output->diagnostics.queue_depth_frames)
        output->diagnostics.peak_queue_depth_frames =
            output->diagnostics.queue_depth_frames;
    /* Begin playback once half the requested latency has been queued. */
    if (output->priming && !output->paused &&
        output->diagnostics.queue_depth_frames >=
            output->target_latency_frames / 2u) {
        if (start_playback(output)) output->priming = 0;
    }
    if (end_of_frame && !output->paused && !output->priming &&
        output->playing) {
        if (output->diagnostics.queue_depth_frames > 0u)
            output->starved_last_pump = 0;
        process_end_of_frame(output);
    }
}

void topgear_mac_audio_output_pump(TopGearMacAudioOutput *output,
                                   TopGearApp *game) {
    pump_audio(output, game, 1);
}

void topgear_mac_audio_output_pump_progress(TopGearMacAudioOutput *output,
                                            TopGearApp *game) {
    pump_audio(output, game, 0);
}

void topgear_mac_audio_output_get_diagnostics(
    const TopGearMacAudioOutput *output,
    TopGearMacAudioDiagnostics *diagnostics) {
    if (!diagnostics) return;
    if (!output) memset(diagnostics, 0, sizeof(*diagnostics));
    else *diagnostics = output->diagnostics;
}
