#ifndef TOPGEAR_MAC_SETTINGS_H
#define TOPGEAR_MAC_SETTINGS_H

#include <stddef.h>
#include <stdint.h>

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

/* settings.ini for the macOS launcher. Section and key names follow the
   Windows launcher; keyboard keys are stored as SDL key names because Win32
   virtual-key codes do not exist on macOS. */

#define TOPGEAR_MAC_BINDING_COUNT 12
#define TOPGEAR_MAC_PATH_CAPACITY 4096u
#define TOPGEAR_MAC_AUDIO_DEVICE_NAME_CAPACITY 128u
#define TOPGEAR_MAC_SNAPSHOT_SLOT_COUNT 5
#define TOPGEAR_MAC_MAX_INTEGER_SCALE 4

#define TOPGEAR_MAC_INPUT_SOURCE_KEYBOARD 0
#define TOPGEAR_MAC_INPUT_SOURCE_GAMEPAD 1

#define TOPGEAR_MAC_AUDIO_MIN_LATENCY_MS 0
#define TOPGEAR_MAC_AUDIO_MAX_LATENCY_MS 40
#define TOPGEAR_MAC_AUDIO_MIN_SAFETY_BUFFER_MS 0
#define TOPGEAR_MAC_AUDIO_MAX_SAFETY_BUFFER_MS 100
#define TOPGEAR_MAC_AUDIO_MIN_RECOVERY_MS 10
#define TOPGEAR_MAC_AUDIO_MAX_RECOVERY_MS 500
#define TOPGEAR_MAC_AUDIO_MIN_DRIFT_TOLERANCE_MS 0
#define TOPGEAR_MAC_AUDIO_MAX_DRIFT_TOLERANCE_MS 20
#define TOPGEAR_MAC_AUDIO_MIN_RATE_ADJUSTMENT_PPM 0
#define TOPGEAR_MAC_AUDIO_MAX_RATE_ADJUSTMENT_PPM 10000
#define TOPGEAR_MAC_AUDIO_MIN_AVERAGING_FRAMES 1
#define TOPGEAR_MAC_AUDIO_MAX_AVERAGING_FRAMES 60
#define TOPGEAR_MAC_AUDIO_MIN_FADE_MS 0
#define TOPGEAR_MAC_AUDIO_MAX_FADE_MS 100

/* Binding order matches the Windows launcher. */
enum TopGearMacBindingAction {
    TOPGEAR_MAC_BIND_UP = 0, TOPGEAR_MAC_BIND_DOWN, TOPGEAR_MAC_BIND_LEFT,
    TOPGEAR_MAC_BIND_RIGHT, TOPGEAR_MAC_BIND_SNES_B, TOPGEAR_MAC_BIND_SNES_A,
    TOPGEAR_MAC_BIND_SNES_Y, TOPGEAR_MAC_BIND_SNES_X, TOPGEAR_MAC_BIND_SNES_L,
    TOPGEAR_MAC_BIND_SNES_R, TOPGEAR_MAC_BIND_START, TOPGEAR_MAC_BIND_SELECT
};

/* Gamepad controls, numbered as SC_GAMEPAD_* in the Windows frontend. */
enum TopGearMacPadControl {
    TOPGEAR_MAC_PAD_NONE = 0,
    TOPGEAR_MAC_PAD_DPAD_UP, TOPGEAR_MAC_PAD_DPAD_DOWN,
    TOPGEAR_MAC_PAD_DPAD_LEFT, TOPGEAR_MAC_PAD_DPAD_RIGHT,
    TOPGEAR_MAC_PAD_LEFT_STICK_UP, TOPGEAR_MAC_PAD_LEFT_STICK_DOWN,
    TOPGEAR_MAC_PAD_LEFT_STICK_LEFT, TOPGEAR_MAC_PAD_LEFT_STICK_RIGHT,
    TOPGEAR_MAC_PAD_FACE_SOUTH, TOPGEAR_MAC_PAD_FACE_EAST,
    TOPGEAR_MAC_PAD_FACE_WEST, TOPGEAR_MAC_PAD_FACE_NORTH,
    TOPGEAR_MAC_PAD_LEFT_SHOULDER, TOPGEAR_MAC_PAD_RIGHT_SHOULDER,
    TOPGEAR_MAC_PAD_LEFT_TRIGGER, TOPGEAR_MAC_PAD_RIGHT_TRIGGER,
    TOPGEAR_MAC_PAD_START, TOPGEAR_MAC_PAD_BACK,
    TOPGEAR_MAC_PAD_LEFT_STICK_BUTTON, TOPGEAR_MAC_PAD_RIGHT_STICK_BUTTON,
    TOPGEAR_MAC_PAD_CONTROL_LAST = TOPGEAR_MAC_PAD_RIGHT_STICK_BUTTON
};

typedef struct TopGearMacAudioSettings {
    int enabled;
    int volume_percent;
    int latency_enabled;
    int latency_ms;
    int output_sample_rate;
    int resampler_mode;
    int safety_buffer_ms;
    int drift_correction_enabled;
    int drift_tolerance_ms;
    int max_rate_adjustment_ppm;
    int averaging_frames;
    int integral_correction_enabled;
    int recovery_enabled;
    int recovery_threshold_ms;
    int resume_fade_ms;
    char device_name[TOPGEAR_MAC_AUDIO_DEVICE_NAME_CAPACITY];
} TopGearMacAudioSettings;

typedef struct TopGearMacSettings {
    int integer_scale;      /* 0 = fit window at 4:3, 1-4 = integer cap */
    int pause_on_focus_loss;
    int auto_run_on_load;
    int fullscreen_on_play;
    int show_fps_counter;
    int ntsc_frame_lock;
    int snapshot_slot;
    int welcome_shown;
    int input_source;
    int keys[TOPGEAR_MAC_BINDING_COUNT];   /* SDL_Scancode values */
    int pads[TOPGEAR_MAC_BINDING_COUNT];   /* TopGearMacPadControl values */
    char rom_path[TOPGEAR_MAC_PATH_CAPACITY];
    TopGearMacAudioSettings audio;
} TopGearMacSettings;

void topgear_mac_audio_settings_defaults(TopGearMacAudioSettings *audio);
void topgear_mac_settings_defaults(TopGearMacSettings *settings);
void topgear_mac_settings_standard_keyboard(int keys[TOPGEAR_MAC_BINDING_COUNT]);
void topgear_mac_settings_classic_keyboard(int keys[TOPGEAR_MAC_BINDING_COUNT]);
void topgear_mac_settings_default_gamepad(int pads[TOPGEAR_MAC_BINDING_COUNT]);
/* Loads defaults first; returns 1 when the file existed and was read. */
int topgear_mac_settings_load(TopGearMacSettings *settings, const char *path);
int topgear_mac_settings_save(const TopGearMacSettings *settings,
                              const char *path);

uint16_t topgear_mac_binding_mask(int action);
const char *topgear_mac_action_name(int action);
/* Keys the launcher reserves for its own shortcuts (Escape, F1-F8, 1, 2). */
int topgear_mac_key_reserved(int scancode);
/* Index of the second binding of the first duplicate pair, or -1. */
int topgear_mac_first_duplicate(const int bindings[TOPGEAR_MAC_BINDING_COUNT]);

const char *topgear_mac_pad_control_name(int control);
int topgear_mac_pad_control_pressed(SDL_Gamepad *gamepad, int control);
/* First pressed control in enum order, or TOPGEAR_MAC_PAD_NONE. */
int topgear_mac_pad_capture_control(SDL_Gamepad *gamepad);
/* Adds the controller's face-button label, e.g. "South / bottom (A)". */
void topgear_mac_pad_control_display_name(SDL_Gamepad *gamepad, int control,
                                          char *text, size_t capacity);

/* Flush to the device, then atomically replace the destination. */
int topgear_mac_write_file_durable(const char *path, const void *bytes,
                                   size_t size);

#ifdef __cplusplus
}
#endif
#endif
