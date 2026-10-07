#include "topgear_audio_resampler.h"
#include "topgear_mac_settings.h"
#include "topgear_static_recomp.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define CHECK(expression) do { \
    if (!(expression)) { \
        fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #expression); \
        return 1; \
    } \
} while (0)

static int write_text(const char *path, const char *text) {
    FILE *file = fopen(path, "wb");
    if (!file) return 0;
    if (fputs(text, file) < 0) {
        (void)fclose(file);
        return 0;
    }
    return fclose(file) == 0;
}

int main(int argc, char **argv) {
    TopGearMacSettings settings;
    TopGearMacSettings loaded;
    const char *path = argc > 1 ? argv[1] : "topgear-mac-settings-contract.ini";
    int keys[TOPGEAR_MAC_BINDING_COUNT];
    char name[128];

    (void)unlink(path);
    CHECK(!topgear_mac_settings_load(&settings, path));

    /* Defaults match the Windows launcher. */
    CHECK(settings.integer_scale == 0);
    CHECK(settings.pause_on_focus_loss == 0);
    CHECK(settings.auto_run_on_load == 0);
    CHECK(settings.fullscreen_on_play == 0);
    CHECK(settings.show_fps_counter == 0);
    CHECK(settings.ntsc_frame_lock == 1);
    CHECK(settings.snapshot_slot == 1);
    CHECK(settings.welcome_shown == 0);
    CHECK(settings.input_source == TOPGEAR_MAC_INPUT_SOURCE_KEYBOARD);
    CHECK(settings.keys[TOPGEAR_MAC_BIND_UP] == SDL_SCANCODE_UP);
    CHECK(settings.keys[TOPGEAR_MAC_BIND_SNES_B] == SDL_SCANCODE_D);
    CHECK(settings.keys[TOPGEAR_MAC_BIND_SNES_A] == SDL_SCANCODE_F);
    CHECK(settings.keys[TOPGEAR_MAC_BIND_START] == SDL_SCANCODE_G);
    CHECK(settings.keys[TOPGEAR_MAC_BIND_SELECT] == SDL_SCANCODE_T);
    CHECK(settings.pads[TOPGEAR_MAC_BIND_SNES_B] == TOPGEAR_MAC_PAD_FACE_SOUTH);
    CHECK(settings.pads[TOPGEAR_MAC_BIND_SNES_A] == TOPGEAR_MAC_PAD_FACE_EAST);
    CHECK(settings.pads[TOPGEAR_MAC_BIND_SELECT] == TOPGEAR_MAC_PAD_BACK);
    CHECK(settings.audio.enabled == 1);
    CHECK(settings.audio.volume_percent == 50);
    CHECK(settings.audio.latency_enabled == 0);
    CHECK(settings.audio.latency_ms == 0);
    CHECK(settings.audio.output_sample_rate == 48000);
    CHECK(settings.audio.resampler_mode == TOPGEAR_AUDIO_RESAMPLER_HERMITE);
    CHECK(settings.audio.safety_buffer_ms == 90);
    CHECK(settings.audio.drift_correction_enabled == 1);
    CHECK(settings.audio.drift_tolerance_ms == 3);
    CHECK(settings.audio.max_rate_adjustment_ppm == 2500);
    CHECK(settings.audio.averaging_frames == 60);
    CHECK(settings.audio.integral_correction_enabled == 1);
    CHECK(settings.audio.recovery_enabled == 1);
    CHECK(settings.audio.recovery_threshold_ms == 50);
    CHECK(settings.audio.resume_fade_ms == 0);
    CHECK(topgear_mac_binding_mask(TOPGEAR_MAC_BIND_SNES_B) == TOPGEAR_INPUT_B);
    CHECK(topgear_mac_binding_mask(TOPGEAR_MAC_BIND_SELECT) == TOPGEAR_INPUT_SELECT);
    CHECK(strcmp(topgear_mac_action_name(TOPGEAR_MAC_BIND_START), "Start Button") == 0);

    /* Every setting round-trips. */
    settings.integer_scale = 3;
    settings.pause_on_focus_loss = 1;
    settings.auto_run_on_load = 1;
    settings.fullscreen_on_play = 1;
    settings.show_fps_counter = 1;
    settings.ntsc_frame_lock = 0;
    settings.snapshot_slot = 4;
    settings.welcome_shown = 1;
    settings.input_source = TOPGEAR_MAC_INPUT_SOURCE_GAMEPAD;
    topgear_mac_settings_classic_keyboard(settings.keys);
    settings.keys[TOPGEAR_MAC_BIND_SNES_L] = SDL_SCANCODE_LSHIFT;
    settings.pads[TOPGEAR_MAC_BIND_SNES_L] = TOPGEAR_MAC_PAD_LEFT_TRIGGER;
    settings.pads[TOPGEAR_MAC_BIND_UP] = TOPGEAR_MAC_PAD_LEFT_STICK_UP;
    (void)snprintf(settings.rom_path, sizeof(settings.rom_path),
                   "/Volumes/ROMs/Top Gear (USA).sfc");
    settings.audio.enabled = 0;
    settings.audio.volume_percent = 73;
    settings.audio.latency_enabled = 1;
    settings.audio.latency_ms = 17;
    settings.audio.output_sample_rate = 96000;
    settings.audio.resampler_mode = TOPGEAR_AUDIO_RESAMPLER_LINEAR;
    settings.audio.safety_buffer_ms = 31;
    settings.audio.drift_correction_enabled = 0;
    settings.audio.drift_tolerance_ms = 7;
    settings.audio.max_rate_adjustment_ppm = 4500;
    settings.audio.averaging_frames = 24;
    settings.audio.integral_correction_enabled = 0;
    settings.audio.recovery_enabled = 0;
    settings.audio.recovery_threshold_ms = 77;
    settings.audio.resume_fade_ms = 12;
    (void)snprintf(settings.audio.device_name, sizeof(settings.audio.device_name),
                   "Persistence Test Device");
    CHECK(topgear_mac_settings_save(&settings, path));
    CHECK(topgear_mac_settings_load(&loaded, path));
    CHECK(memcmp(&loaded, &settings, sizeof(settings)) == 0);

    /* Out-of-range values clamp as on Windows. */
    CHECK(write_text(path,
        "[General]\nIntegerScale=9\nSnapshotSlot=0\n"
        "[Audio]\nLatencyEnabled=1\nLatencyMs=99\nVolumePercent=150\n"
        "SafetyBufferMs=999\nOutputSampleRate=12345\nResamplerMode=99\n"
        "AveragingFrames=0\nRecoveryThresholdMs=1\nResumeFadeMs=-4\n"));
    CHECK(topgear_mac_settings_load(&loaded, path));
    CHECK(loaded.integer_scale == 0);
    CHECK(loaded.snapshot_slot == 1);
    CHECK(loaded.audio.latency_ms == TOPGEAR_MAC_AUDIO_MAX_LATENCY_MS);
    CHECK(loaded.audio.volume_percent == 100);
    CHECK(loaded.audio.safety_buffer_ms == TOPGEAR_MAC_AUDIO_MAX_SAFETY_BUFFER_MS);
    CHECK(loaded.audio.output_sample_rate == 48000);
    CHECK(loaded.audio.resampler_mode == TOPGEAR_AUDIO_RESAMPLER_NEAREST);
    CHECK(loaded.audio.averaging_frames == TOPGEAR_MAC_AUDIO_MIN_AVERAGING_FRAMES);
    CHECK(loaded.audio.recovery_threshold_ms == TOPGEAR_MAC_AUDIO_MIN_RECOVERY_MS);
    CHECK(loaded.audio.resume_fade_ms == TOPGEAR_MAC_AUDIO_MIN_FADE_MS);

    /* A latency value without its enable switch is not a user choice. */
    CHECK(write_text(path, "[Audio]\nEnabled=1\nLatencyMs=30\n"));
    CHECK(topgear_mac_settings_load(&loaded, path));
    CHECK(loaded.audio.latency_enabled == 0);
    CHECK(loaded.audio.latency_ms == 0);

    /* Reserved, unknown or duplicate keys restore the standard keyboard. */
    CHECK(write_text(path, "[Keyboard]\nB=Escape\n"));
    CHECK(topgear_mac_settings_load(&loaded, path));
    CHECK(loaded.keys[TOPGEAR_MAC_BIND_SNES_B] == SDL_SCANCODE_D);
    CHECK(write_text(path, "[Keyboard]\nA=NotAKey\n"));
    CHECK(topgear_mac_settings_load(&loaded, path));
    CHECK(loaded.keys[TOPGEAR_MAC_BIND_SNES_A] == SDL_SCANCODE_F);
    CHECK(write_text(path, "[Keyboard]\nA=D\n"));
    CHECK(topgear_mac_settings_load(&loaded, path));
    CHECK(loaded.keys[TOPGEAR_MAC_BIND_SNES_A] == SDL_SCANCODE_F);
    CHECK(write_text(path, "[Gamepad]\nB=nonsense\n[Input]\nSource=7\n"));
    CHECK(topgear_mac_settings_load(&loaded, path));
    CHECK(loaded.pads[TOPGEAR_MAC_BIND_SNES_B] == TOPGEAR_MAC_PAD_FACE_SOUTH);
    CHECK(loaded.input_source == TOPGEAR_MAC_INPUT_SOURCE_KEYBOARD);

    /* Reserved launcher keys and duplicate detection. */
    CHECK(topgear_mac_key_reserved(SDL_SCANCODE_ESCAPE));
    CHECK(topgear_mac_key_reserved(SDL_SCANCODE_F1));
    CHECK(topgear_mac_key_reserved(SDL_SCANCODE_F8));
    CHECK(!topgear_mac_key_reserved(SDL_SCANCODE_F9));
    CHECK(topgear_mac_key_reserved(SDL_SCANCODE_1));
    CHECK(topgear_mac_key_reserved(SDL_SCANCODE_2));
    CHECK(!topgear_mac_key_reserved(SDL_SCANCODE_3));
    topgear_mac_settings_standard_keyboard(keys);
    CHECK(topgear_mac_first_duplicate(keys) < 0);
    keys[TOPGEAR_MAC_BIND_SELECT] = keys[TOPGEAR_MAC_BIND_SNES_A];
    CHECK(topgear_mac_first_duplicate(keys) == TOPGEAR_MAC_BIND_SELECT);
    topgear_mac_settings_classic_keyboard(keys);
    CHECK(keys[TOPGEAR_MAC_BIND_SNES_B] == SDL_SCANCODE_Z);
    CHECK(keys[TOPGEAR_MAC_BIND_START] == SDL_SCANCODE_RETURN);
    CHECK(keys[TOPGEAR_MAC_BIND_SELECT] == SDL_SCANCODE_SPACE);

    /* Gamepad names without a connected controller. */
    CHECK(strcmp(topgear_mac_pad_control_name(TOPGEAR_MAC_PAD_START),
                 "Start / Menu") == 0);
    topgear_mac_pad_control_display_name(NULL, TOPGEAR_MAC_PAD_FACE_SOUTH,
                                         name, sizeof(name));
    CHECK(strcmp(name, "South / bottom face button") == 0);
    CHECK(topgear_mac_pad_capture_control(NULL) == TOPGEAR_MAC_PAD_NONE);
    CHECK(!topgear_mac_pad_control_pressed(NULL, TOPGEAR_MAC_PAD_START));

    CHECK(unlink(path) == 0);
    puts("PASS macOS launcher settings persist, clamp and validate like Windows");
    return 0;
}
