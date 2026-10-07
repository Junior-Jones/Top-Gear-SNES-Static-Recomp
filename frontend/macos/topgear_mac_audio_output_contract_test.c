#include "topgear_audio_output_sdl.h"

#include <stdio.h>
#include <string.h>

#define CHECK(expression) do { \
    if (!(expression)) { \
        fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #expression); \
        SDL_Quit(); \
        return 1; \
    } \
} while (0)

/* Runs against SDL's dummy audio driver (set by CTest), so the open, pause,
   resume, flush and close paths are exercised without a sound device. */
int main(int argc, char **argv) {
    TopGearMacAudioSettings settings;
    TopGearMacAudioOutput output;
    TopGearMacAudioDiagnostics diagnostics;
    char error[256];
    (void)argc;
    (void)argv;
    CHECK(SDL_Init(SDL_INIT_AUDIO));

    topgear_mac_audio_output_initialize(&output);
    CHECK(!topgear_mac_audio_output_is_open(&output));
    CHECK(topgear_mac_audio_output_queued_frames(&output) == 0u);

    /* Disabled audio succeeds without opening a device. */
    topgear_mac_audio_settings_defaults(&settings);
    settings.enabled = 0;
    CHECK(topgear_mac_audio_output_open(&output, &settings, error, sizeof(error)));
    CHECK(!topgear_mac_audio_output_is_open(&output));

    /* Default device at every supported output rate. */
    {
        static const int rates[] = {32040, 44100, 48000, 96000};
        size_t index;
        for (index = 0; index < sizeof(rates) / sizeof(rates[0]); ++index) {
            topgear_mac_audio_settings_defaults(&settings);
            settings.output_sample_rate = rates[index];
            settings.latency_enabled = 1;
            settings.latency_ms = 10;
            CHECK(topgear_mac_audio_output_open(&output, &settings, error,
                                                sizeof(error)));
            CHECK(topgear_mac_audio_output_is_open(&output));
            CHECK(strcmp(output.opened_device_name,
                         TOPGEAR_MAC_AUDIO_DEFAULT_DEVICE_LABEL) == 0);
            /* Target = safety prebuffer + enabled extra latency. */
            CHECK(output.target_latency_frames ==
                  (uint32_t)((uint64_t)rates[index] * 100u / 1000u));
            CHECK(output.paused && output.priming && !output.playing);
            topgear_mac_audio_output_get_diagnostics(&output, &diagnostics);
            CHECK(diagnostics.device_sample_rate == rates[index]);
            CHECK(diagnostics.target_latency_frames == output.target_latency_frames);
            CHECK(diagnostics.playback_ratio == 1.0f);
            topgear_mac_audio_output_close(&output);
            CHECK(!topgear_mac_audio_output_is_open(&output));
        }
    }

    /* An unknown device name falls back to the default device. */
    topgear_mac_audio_settings_defaults(&settings);
    (void)snprintf(settings.device_name, sizeof(settings.device_name),
                   "No Such Device");
    CHECK(topgear_mac_audio_output_open(&output, &settings, error, sizeof(error)));
    CHECK(strcmp(output.opened_device_name,
                 TOPGEAR_MAC_AUDIO_DEFAULT_DEVICE_LABEL) == 0);

    /* Resume with an empty queue stays priming; pumping without a game is
       harmless; pause and flush keep the state machine consistent. */
    topgear_mac_audio_output_resume(&output);
    CHECK(!output.paused && output.priming && !output.playing);
    topgear_mac_audio_output_pump(&output, NULL);
    topgear_mac_audio_output_pump_progress(&output, NULL);
    topgear_mac_audio_output_pause(&output);
    CHECK(output.paused && !output.playing);
    topgear_mac_audio_output_flush(&output);
    CHECK(output.priming && topgear_mac_audio_output_queued_frames(&output) == 0u);
    topgear_mac_audio_output_close(&output);

    /* Device enumeration never reports names out of range. */
    {
        char name[TOPGEAR_MAC_AUDIO_DEVICE_NAME_CAPACITY];
        int count = topgear_mac_audio_device_count();
        CHECK(count >= 0);
        CHECK(!topgear_mac_audio_device_name(count, name, sizeof(name)));
        CHECK(!topgear_mac_audio_device_name(-1, name, sizeof(name)));
    }

    SDL_Quit();
    puts("PASS macOS audio output opens, primes, pauses and flushes like Windows");
    return 0;
}
