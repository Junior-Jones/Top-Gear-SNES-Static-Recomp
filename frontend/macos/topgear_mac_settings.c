#include "topgear_mac_settings.h"

#include "topgear_audio_resampler.h"
#include "topgear_static_recomp.h"

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ARRAY_COUNT(a) (sizeof(a) / sizeof((a)[0]))

static const char *const k_action_keys[TOPGEAR_MAC_BINDING_COUNT] = {
    "Up", "Down", "Left", "Right", "B", "A", "Y", "X", "L", "R",
    "Start", "Select"
};

static const char *const k_action_names[TOPGEAR_MAC_BINDING_COUNT] = {
    "D-pad Up", "D-pad Down", "D-pad Left", "D-pad Right",
    "B Button", "A Button", "Y Button", "X Button", "L Button", "R Button",
    "Start Button", "Select Button"
};

static const uint16_t k_action_masks[TOPGEAR_MAC_BINDING_COUNT] = {
    TOPGEAR_INPUT_UP, TOPGEAR_INPUT_DOWN, TOPGEAR_INPUT_LEFT,
    TOPGEAR_INPUT_RIGHT, TOPGEAR_INPUT_B, TOPGEAR_INPUT_A, TOPGEAR_INPUT_Y,
    TOPGEAR_INPUT_X, TOPGEAR_INPUT_L, TOPGEAR_INPUT_R, TOPGEAR_INPUT_START,
    TOPGEAR_INPUT_SELECT
};

/* Readable settings.ini tokens, indexed by TopGearMacPadControl. */
static const char *const k_pad_tokens[] = {
    "none", "dpup", "dpdown", "dpleft", "dpright",
    "lsup", "lsdown", "lsleft", "lsright",
    "south", "east", "west", "north",
    "lshoulder", "rshoulder", "ltrigger", "rtrigger",
    "start", "back", "lstick", "rstick"
};

static const char *const k_pad_names[] = {
    "", "D-pad Up", "D-pad Down", "D-pad Left", "D-pad Right",
    "Left Stick Up", "Left Stick Down", "Left Stick Left",
    "Left Stick Right", "South / bottom face button",
    "East / right face button", "West / left face button",
    "North / top face button", "Left shoulder", "Right shoulder",
    "Left trigger", "Right trigger", "Start / Menu", "Back / View",
    "Left stick button", "Right stick button"
};

static int clamp_int(int value, int low, int high) {
    return value < low ? low : value > high ? high : value;
}

static int valid_output_rate(int value) {
    return value == 32040 || value == 44100 || value == 48000 ||
           value == 96000;
}

void topgear_mac_audio_settings_defaults(TopGearMacAudioSettings *audio) {
    if (!audio) return;
    /* Same defaults as the Windows DirectSound frontend. */
    memset(audio, 0, sizeof(*audio));
    audio->enabled = 1;
    audio->volume_percent = 50;
    audio->latency_enabled = 0;
    audio->latency_ms = 0;
    audio->output_sample_rate = 48000;
    audio->resampler_mode = TOPGEAR_AUDIO_RESAMPLER_HERMITE;
    audio->safety_buffer_ms = 90;
    audio->drift_correction_enabled = 1;
    audio->drift_tolerance_ms = 3;
    audio->max_rate_adjustment_ppm = 2500;
    audio->averaging_frames = 60;
    audio->integral_correction_enabled = 1;
    audio->recovery_enabled = 1;
    audio->recovery_threshold_ms = 50;
    audio->resume_fade_ms = 0;
}

void topgear_mac_settings_standard_keyboard(int keys[TOPGEAR_MAC_BINDING_COUNT]) {
    static const int standard[TOPGEAR_MAC_BINDING_COUNT] = {
        SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT,
        SDL_SCANCODE_RIGHT, SDL_SCANCODE_D, SDL_SCANCODE_F, SDL_SCANCODE_A,
        SDL_SCANCODE_S, SDL_SCANCODE_E, SDL_SCANCODE_R, SDL_SCANCODE_G,
        SDL_SCANCODE_T
    };
    memcpy(keys, standard, sizeof(standard));
}

void topgear_mac_settings_classic_keyboard(int keys[TOPGEAR_MAC_BINDING_COUNT]) {
    topgear_mac_settings_standard_keyboard(keys);
    keys[TOPGEAR_MAC_BIND_SNES_B] = SDL_SCANCODE_Z;
    keys[TOPGEAR_MAC_BIND_SNES_A] = SDL_SCANCODE_X;
    keys[TOPGEAR_MAC_BIND_SNES_Y] = SDL_SCANCODE_A;
    keys[TOPGEAR_MAC_BIND_SNES_X] = SDL_SCANCODE_S;
    keys[TOPGEAR_MAC_BIND_START] = SDL_SCANCODE_RETURN;
    keys[TOPGEAR_MAC_BIND_SELECT] = SDL_SCANCODE_SPACE;
}

void topgear_mac_settings_default_gamepad(int pads[TOPGEAR_MAC_BINDING_COUNT]) {
    static const int layout[TOPGEAR_MAC_BINDING_COUNT] = {
        TOPGEAR_MAC_PAD_DPAD_UP, TOPGEAR_MAC_PAD_DPAD_DOWN,
        TOPGEAR_MAC_PAD_DPAD_LEFT, TOPGEAR_MAC_PAD_DPAD_RIGHT,
        TOPGEAR_MAC_PAD_FACE_SOUTH, TOPGEAR_MAC_PAD_FACE_EAST,
        TOPGEAR_MAC_PAD_FACE_WEST, TOPGEAR_MAC_PAD_FACE_NORTH,
        TOPGEAR_MAC_PAD_LEFT_SHOULDER, TOPGEAR_MAC_PAD_RIGHT_SHOULDER,
        TOPGEAR_MAC_PAD_START, TOPGEAR_MAC_PAD_BACK
    };
    memcpy(pads, layout, sizeof(layout));
}

void topgear_mac_settings_defaults(TopGearMacSettings *s) {
    if (!s) return;
    memset(s, 0, sizeof(*s));
    s->ntsc_frame_lock = 1;
    s->snapshot_slot = 1;
    s->input_source = TOPGEAR_MAC_INPUT_SOURCE_KEYBOARD;
    topgear_mac_settings_standard_keyboard(s->keys);
    topgear_mac_settings_default_gamepad(s->pads);
    topgear_mac_audio_settings_defaults(&s->audio);
}

uint16_t topgear_mac_binding_mask(int action) {
    return action >= 0 && action < TOPGEAR_MAC_BINDING_COUNT ?
           k_action_masks[action] : 0u;
}

const char *topgear_mac_action_name(int action) {
    return action >= 0 && action < TOPGEAR_MAC_BINDING_COUNT ?
           k_action_names[action] : "Unknown";
}

int topgear_mac_key_reserved(int scancode) {
    return scancode == SDL_SCANCODE_ESCAPE ||
           (scancode >= SDL_SCANCODE_F1 && scancode <= SDL_SCANCODE_F8) ||
           scancode == SDL_SCANCODE_1 || scancode == SDL_SCANCODE_2;
}

int topgear_mac_first_duplicate(const int bindings[TOPGEAR_MAC_BINDING_COUNT]) {
    int first;
    int second;
    for (first = 0; first < TOPGEAR_MAC_BINDING_COUNT; ++first)
        for (second = first + 1; second < TOPGEAR_MAC_BINDING_COUNT; ++second)
            if (bindings[first] == bindings[second]) return second;
    return -1;
}

static int keyboard_bindings_valid(const int keys[TOPGEAR_MAC_BINDING_COUNT]) {
    int index;
    for (index = 0; index < TOPGEAR_MAC_BINDING_COUNT; ++index)
        if (keys[index] <= SDL_SCANCODE_UNKNOWN ||
            keys[index] >= SDL_SCANCODE_COUNT ||
            topgear_mac_key_reserved(keys[index]))
            return 0;
    return topgear_mac_first_duplicate(keys) < 0;
}

static int gamepad_bindings_valid(const int pads[TOPGEAR_MAC_BINDING_COUNT]) {
    int index;
    for (index = 0; index < TOPGEAR_MAC_BINDING_COUNT; ++index)
        if (pads[index] < TOPGEAR_MAC_PAD_DPAD_UP ||
            pads[index] > TOPGEAR_MAC_PAD_CONTROL_LAST)
            return 0;
    return 1;
}

/* ------------------------------------------------------------------ */
/* INI file                                                            */
/* ------------------------------------------------------------------ */

static char *trim(char *text) {
    char *end;
    while (*text == ' ' || *text == '\t') ++text;
    end = text + strlen(text);
    while (end > text && (end[-1] == ' ' || end[-1] == '\t' ||
                          end[-1] == '\r' || end[-1] == '\n'))
        *--end = '\0';
    return text;
}

static int read_text_file(const char *path, char **text) {
    FILE *file = fopen(path, "rb");
    long length;
    size_t count;
    *text = NULL;
    if (!file) return 0;
    if (fseek(file, 0, SEEK_END) != 0 || (length = ftell(file)) < 0 ||
        length > 1024L * 1024L || fseek(file, 0, SEEK_SET) != 0) {
        (void)fclose(file);
        return 0;
    }
    *text = (char *)malloc((size_t)length + 1u);
    if (!*text) {
        (void)fclose(file);
        return 0;
    }
    count = fread(*text, 1u, (size_t)length, file);
    (void)fclose(file);
    if (count != (size_t)length) {
        free(*text);
        *text = NULL;
        return 0;
    }
    (*text)[count] = '\0';
    return 1;
}

static int is(const char *a, const char *b) {
    return SDL_strcasecmp(a, b) == 0;
}

static void apply_audio(TopGearMacAudioSettings *a, const char *key,
                        const char *value) {
    int number = atoi(value);
    if (is(key, "Enabled")) a->enabled = number != 0;
    else if (is(key, "VolumePercent")) a->volume_percent = number;
    else if (is(key, "LatencyEnabled")) a->latency_enabled = number != 0;
    else if (is(key, "LatencyMs")) a->latency_ms = number;
    else if (is(key, "OutputSampleRate")) a->output_sample_rate = number;
    else if (is(key, "ResamplerMode")) a->resampler_mode = number;
    else if (is(key, "SafetyBufferMs")) a->safety_buffer_ms = number;
    else if (is(key, "DriftCorrectionEnabled")) a->drift_correction_enabled = number != 0;
    else if (is(key, "DriftToleranceMs")) a->drift_tolerance_ms = number;
    else if (is(key, "MaxRateAdjustmentPpm")) a->max_rate_adjustment_ppm = number;
    else if (is(key, "AveragingFrames")) a->averaging_frames = number;
    else if (is(key, "IntegralCorrectionEnabled")) a->integral_correction_enabled = number != 0;
    else if (is(key, "RecoveryEnabled")) a->recovery_enabled = number != 0;
    else if (is(key, "RecoveryThresholdMs")) a->recovery_threshold_ms = number;
    else if (is(key, "ResumeFadeMs")) a->resume_fade_ms = number;
    else if (is(key, "DeviceName"))
        (void)snprintf(a->device_name, sizeof(a->device_name), "%s", value);
}

static void apply_setting(TopGearMacSettings *s, const char *section,
                          const char *key, const char *value) {
    int number = atoi(value);
    int index;
    if (is(section, "General")) {
        if (is(key, "IntegerScale")) s->integer_scale = number;
        else if (is(key, "PauseOnFocusLoss")) s->pause_on_focus_loss = number != 0;
        else if (is(key, "AutoRunOnLoad")) s->auto_run_on_load = number != 0;
        else if (is(key, "FullScreenOnPlay")) s->fullscreen_on_play = number != 0;
        else if (is(key, "ShowFpsCounter")) s->show_fps_counter = number != 0;
        else if (is(key, "NtscFrameLock")) s->ntsc_frame_lock = number != 0;
        else if (is(key, "SnapshotSlot")) s->snapshot_slot = number;
        else if (is(key, "WelcomeShown")) s->welcome_shown = number != 0;
    } else if (is(section, "Input")) {
        if (is(key, "Source") &&
            (number == TOPGEAR_MAC_INPUT_SOURCE_KEYBOARD ||
             number == TOPGEAR_MAC_INPUT_SOURCE_GAMEPAD))
            s->input_source = number;
    } else if (is(section, "Keyboard")) {
        for (index = 0; index < TOPGEAR_MAC_BINDING_COUNT; ++index)
            if (is(key, k_action_keys[index]))
                s->keys[index] = (int)SDL_GetScancodeFromName(value);
    } else if (is(section, "Gamepad")) {
        for (index = 0; index < TOPGEAR_MAC_BINDING_COUNT; ++index) {
            size_t control;
            if (!is(key, k_action_keys[index])) continue;
            s->pads[index] = TOPGEAR_MAC_PAD_NONE;
            for (control = 1u; control < ARRAY_COUNT(k_pad_tokens); ++control)
                if (is(value, k_pad_tokens[control])) s->pads[index] = (int)control;
        }
    } else if (is(section, "Audio")) {
        apply_audio(&s->audio, key, value);
    } else if (is(section, "ROM")) {
        if (is(key, "Path"))
            (void)snprintf(s->rom_path, sizeof(s->rom_path), "%s", value);
    }
}

static void clamp_settings(TopGearMacSettings *s) {
    TopGearMacAudioSettings *a = &s->audio;
    if (s->integer_scale < 0 || s->integer_scale > TOPGEAR_MAC_MAX_INTEGER_SCALE)
        s->integer_scale = 0;
    if (s->snapshot_slot < 1 || s->snapshot_slot > TOPGEAR_MAC_SNAPSHOT_SLOT_COUNT)
        s->snapshot_slot = 1;
    if (!keyboard_bindings_valid(s->keys))
        topgear_mac_settings_standard_keyboard(s->keys);
    if (!gamepad_bindings_valid(s->pads))
        topgear_mac_settings_default_gamepad(s->pads);
    a->volume_percent = clamp_int(a->volume_percent, 0, 100);
    a->latency_ms = clamp_int(a->latency_ms, TOPGEAR_MAC_AUDIO_MIN_LATENCY_MS,
                              TOPGEAR_MAC_AUDIO_MAX_LATENCY_MS);
    if (!valid_output_rate(a->output_sample_rate)) a->output_sample_rate = 48000;
    a->resampler_mode = clamp_int(a->resampler_mode,
                                  TOPGEAR_AUDIO_RESAMPLER_HERMITE,
                                  TOPGEAR_AUDIO_RESAMPLER_NEAREST);
    a->safety_buffer_ms = clamp_int(a->safety_buffer_ms,
                                    TOPGEAR_MAC_AUDIO_MIN_SAFETY_BUFFER_MS,
                                    TOPGEAR_MAC_AUDIO_MAX_SAFETY_BUFFER_MS);
    a->drift_tolerance_ms = clamp_int(a->drift_tolerance_ms,
                                      TOPGEAR_MAC_AUDIO_MIN_DRIFT_TOLERANCE_MS,
                                      TOPGEAR_MAC_AUDIO_MAX_DRIFT_TOLERANCE_MS);
    a->max_rate_adjustment_ppm = clamp_int(a->max_rate_adjustment_ppm,
        TOPGEAR_MAC_AUDIO_MIN_RATE_ADJUSTMENT_PPM,
        TOPGEAR_MAC_AUDIO_MAX_RATE_ADJUSTMENT_PPM);
    a->averaging_frames = clamp_int(a->averaging_frames,
                                    TOPGEAR_MAC_AUDIO_MIN_AVERAGING_FRAMES,
                                    TOPGEAR_MAC_AUDIO_MAX_AVERAGING_FRAMES);
    a->recovery_threshold_ms = clamp_int(a->recovery_threshold_ms,
                                         TOPGEAR_MAC_AUDIO_MIN_RECOVERY_MS,
                                         TOPGEAR_MAC_AUDIO_MAX_RECOVERY_MS);
    a->resume_fade_ms = clamp_int(a->resume_fade_ms,
                                  TOPGEAR_MAC_AUDIO_MIN_FADE_MS,
                                  TOPGEAR_MAC_AUDIO_MAX_FADE_MS);
}

int topgear_mac_settings_load(TopGearMacSettings *s, const char *path) {
    char *text;
    char *line;
    char *next;
    char section[64] = "";
    int latency_enabled_seen = 0;
    if (!s) return 0;
    topgear_mac_settings_defaults(s);
    if (!path || !path[0] || !read_text_file(path, &text)) return 0;
    for (line = text; line && *line; line = next) {
        char *equals;
        char *entry;
        next = strchr(line, '\n');
        if (next) *next++ = '\0';
        entry = trim(line);
        if (!*entry || *entry == ';' || *entry == '#') continue;
        if (*entry == '[') {
            char *close = strchr(entry, ']');
            if (close) {
                *close = '\0';
                (void)snprintf(section, sizeof(section), "%s", trim(entry + 1));
            }
            continue;
        }
        equals = strchr(entry, '=');
        if (!equals) continue;
        *equals = '\0';
        if (is(section, "Audio") && is(trim(entry), "LatencyEnabled"))
            latency_enabled_seen = 1;
        apply_setting(s, section, trim(entry), trim(equals + 1));
    }
    free(text);
    /* As on Windows, a latency value without an explicit enable switch is
       not a user choice and is ignored. */
    if (!latency_enabled_seen) {
        s->audio.latency_enabled = 0;
        s->audio.latency_ms = 0;
    }
    clamp_settings(s);
    return 1;
}

int topgear_mac_settings_save(const TopGearMacSettings *s, const char *path) {
    char text[16384];
    size_t used = 0u;
    int index;
    const TopGearMacAudioSettings *a;
    if (!s || !path || !path[0]) return 0;
    a = &s->audio;
#define APPEND(...) do { \
        int n_ = snprintf(text + used, sizeof(text) - used, __VA_ARGS__); \
        if (n_ < 0 || (size_t)n_ >= sizeof(text) - used) return 0; \
        used += (size_t)n_; \
    } while (0)
    APPEND("; Top Gear Definitive Edition - macOS launcher settings.\n"
           "; Most settings are also available from the Settings menu.\n\n");
    APPEND("[General]\nIntegerScale=%d\nPauseOnFocusLoss=%d\nAutoRunOnLoad=%d\n"
           "FullScreenOnPlay=%d\nShowFpsCounter=%d\nNtscFrameLock=%d\n"
           "SnapshotSlot=%d\nWelcomeShown=%d\n\n",
           s->integer_scale, s->pause_on_focus_loss, s->auto_run_on_load,
           s->fullscreen_on_play, s->show_fps_counter, s->ntsc_frame_lock,
           s->snapshot_slot, s->welcome_shown);
    APPEND("[Input]\nSource=%d\n\n[Keyboard]\n", s->input_source);
    for (index = 0; index < TOPGEAR_MAC_BINDING_COUNT; ++index)
        APPEND("%s=%s\n", k_action_keys[index],
               SDL_GetScancodeName((SDL_Scancode)s->keys[index]));
    APPEND("\n[Gamepad]\n");
    for (index = 0; index < TOPGEAR_MAC_BINDING_COUNT; ++index)
        APPEND("%s=%s\n", k_action_keys[index],
               k_pad_tokens[clamp_int(s->pads[index], 0,
                                      TOPGEAR_MAC_PAD_CONTROL_LAST)]);
    APPEND("\n[Audio]\nEnabled=%d\nVolumePercent=%d\nLatencyEnabled=%d\n"
           "LatencyMs=%d\nOutputSampleRate=%d\nResamplerMode=%d\n"
           "SafetyBufferMs=%d\nDriftCorrectionEnabled=%d\nDriftToleranceMs=%d\n"
           "MaxRateAdjustmentPpm=%d\nAveragingFrames=%d\n"
           "IntegralCorrectionEnabled=%d\nRecoveryEnabled=%d\n"
           "RecoveryThresholdMs=%d\nResumeFadeMs=%d\nDeviceName=%s\n\n",
           a->enabled, a->volume_percent, a->latency_enabled, a->latency_ms,
           a->output_sample_rate, a->resampler_mode, a->safety_buffer_ms,
           a->drift_correction_enabled, a->drift_tolerance_ms,
           a->max_rate_adjustment_ppm, a->averaging_frames,
           a->integral_correction_enabled, a->recovery_enabled,
           a->recovery_threshold_ms, a->resume_fade_ms, a->device_name);
    APPEND("[ROM]\nPath=%s\n", s->rom_path);
#undef APPEND
    return topgear_mac_write_file_durable(path, text, used);
}

/* ------------------------------------------------------------------ */
/* Gamepad controls                                                    */
/* ------------------------------------------------------------------ */

const char *topgear_mac_pad_control_name(int control) {
    if (control < TOPGEAR_MAC_PAD_DPAD_UP || control > TOPGEAR_MAC_PAD_CONTROL_LAST)
        return "Unknown gamepad control";
    return k_pad_names[control];
}

int topgear_mac_pad_control_pressed(SDL_Gamepad *pad, int control) {
    const Sint16 stick = 16384;
    const Sint16 trigger = 8192;
    if (!pad) return 0;
    switch (control) {
        case TOPGEAR_MAC_PAD_DPAD_UP: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_DPAD_UP);
        case TOPGEAR_MAC_PAD_DPAD_DOWN: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_DPAD_DOWN);
        case TOPGEAR_MAC_PAD_DPAD_LEFT: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_DPAD_LEFT);
        case TOPGEAR_MAC_PAD_DPAD_RIGHT: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_DPAD_RIGHT);
        case TOPGEAR_MAC_PAD_LEFT_STICK_UP: return SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFTY) < -stick;
        case TOPGEAR_MAC_PAD_LEFT_STICK_DOWN: return SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFTY) > stick;
        case TOPGEAR_MAC_PAD_LEFT_STICK_LEFT: return SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFTX) < -stick;
        case TOPGEAR_MAC_PAD_LEFT_STICK_RIGHT: return SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFTX) > stick;
        case TOPGEAR_MAC_PAD_FACE_SOUTH: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_SOUTH);
        case TOPGEAR_MAC_PAD_FACE_EAST: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_EAST);
        case TOPGEAR_MAC_PAD_FACE_WEST: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_WEST);
        case TOPGEAR_MAC_PAD_FACE_NORTH: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_NORTH);
        case TOPGEAR_MAC_PAD_LEFT_SHOULDER: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_LEFT_SHOULDER);
        case TOPGEAR_MAC_PAD_RIGHT_SHOULDER: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER);
        case TOPGEAR_MAC_PAD_LEFT_TRIGGER: return SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFT_TRIGGER) > trigger;
        case TOPGEAR_MAC_PAD_RIGHT_TRIGGER: return SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER) > trigger;
        case TOPGEAR_MAC_PAD_START: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_START);
        case TOPGEAR_MAC_PAD_BACK: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_BACK);
        case TOPGEAR_MAC_PAD_LEFT_STICK_BUTTON: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_LEFT_STICK);
        case TOPGEAR_MAC_PAD_RIGHT_STICK_BUTTON: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_RIGHT_STICK);
        default: return 0;
    }
}

int topgear_mac_pad_capture_control(SDL_Gamepad *pad) {
    int control;
    if (!pad) return TOPGEAR_MAC_PAD_NONE;
    for (control = TOPGEAR_MAC_PAD_DPAD_UP;
         control <= TOPGEAR_MAC_PAD_CONTROL_LAST; ++control)
        if (topgear_mac_pad_control_pressed(pad, control)) return control;
    return TOPGEAR_MAC_PAD_NONE;
}

static const char *button_label_name(SDL_GamepadButtonLabel label) {
    switch (label) {
        case SDL_GAMEPAD_BUTTON_LABEL_A: return "A";
        case SDL_GAMEPAD_BUTTON_LABEL_B: return "B";
        case SDL_GAMEPAD_BUTTON_LABEL_X: return "X";
        case SDL_GAMEPAD_BUTTON_LABEL_Y: return "Y";
        case SDL_GAMEPAD_BUTTON_LABEL_CROSS: return "Cross";
        case SDL_GAMEPAD_BUTTON_LABEL_CIRCLE: return "Circle";
        case SDL_GAMEPAD_BUTTON_LABEL_SQUARE: return "Square";
        case SDL_GAMEPAD_BUTTON_LABEL_TRIANGLE: return "Triangle";
        default: return "";
    }
}

void topgear_mac_pad_control_display_name(SDL_Gamepad *pad, int control,
                                          char *text, size_t capacity) {
    SDL_GamepadButton button = SDL_GAMEPAD_BUTTON_INVALID;
    const char *label = "";
    if (!text || capacity == 0u) return;
    if (pad && SDL_GamepadConnected(pad)) {
        switch (control) {
            case TOPGEAR_MAC_PAD_FACE_SOUTH: button = SDL_GAMEPAD_BUTTON_SOUTH; break;
            case TOPGEAR_MAC_PAD_FACE_EAST: button = SDL_GAMEPAD_BUTTON_EAST; break;
            case TOPGEAR_MAC_PAD_FACE_WEST: button = SDL_GAMEPAD_BUTTON_WEST; break;
            case TOPGEAR_MAC_PAD_FACE_NORTH: button = SDL_GAMEPAD_BUTTON_NORTH; break;
            default: break;
        }
        if (button != SDL_GAMEPAD_BUTTON_INVALID)
            label = button_label_name(SDL_GetGamepadButtonLabel(pad, button));
    }
    if (label[0])
        (void)snprintf(text, capacity, "%s (%s)",
                       topgear_mac_pad_control_name(control), label);
    else
        (void)snprintf(text, capacity, "%s",
                       topgear_mac_pad_control_name(control));
}

/* ------------------------------------------------------------------ */
/* Durable writes                                                      */
/* ------------------------------------------------------------------ */

int topgear_mac_write_file_durable(const char *path, const void *bytes,
                                   size_t size) {
    char temporary[TOPGEAR_MAC_PATH_CAPACITY + 32u];
    const uint8_t *cursor = (const uint8_t *)bytes;
    size_t remaining = size;
    int descriptor;
    int written = snprintf(temporary, sizeof(temporary), "%s.tmp-%ld", path,
                           (long)getpid());
    if (written < 0 || (size_t)written >= sizeof(temporary)) return 0;
    descriptor = open(temporary, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (descriptor < 0) return 0;
    while (remaining > 0u) {
        ssize_t chunk = write(descriptor, cursor, remaining);
        if (chunk < 0 && errno == EINTR) continue;
        if (chunk <= 0) break;
        cursor += chunk;
        remaining -= (size_t)chunk;
    }
    /* fsync only reaches the drive cache on macOS; F_FULLFSYNC commits it. */
    if (remaining != 0u ||
        (fcntl(descriptor, F_FULLFSYNC) != 0 && fsync(descriptor) != 0)) {
        (void)close(descriptor);
        (void)unlink(temporary);
        return 0;
    }
    if (close(descriptor) != 0 || rename(temporary, path) != 0) {
        (void)unlink(temporary);
        return 0;
    }
    return 1;
}
