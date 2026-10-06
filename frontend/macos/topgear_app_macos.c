/* Top Gear Definitive Edition - macOS launcher.

   The launcher drives the same static core, Data stores and input latch as
   the Windows frontend. SDL3 supplies the window (Metal renderer), Core Audio
   output, keyboard, gamepad and native file/message dialogs. Frame pacing,
   durable Data commits and fail-closed diagnostics follow the Windows host. */

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "topgear_app_core.h"
#include "topgear_input_latch.h"

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#ifndef TOPGEAR_APP_VERSION
#define TOPGEAR_APP_VERSION "2.0.0"
#endif

#define APP_TITLE "Top Gear"
#define DATA_FOLDER_NAME "Top Gear Definitive Edition"
#define PATH_CAPACITY 4096u
#define BINDING_COUNT 12
#define SNAPSHOT_SLOT_COUNT 5
#define STATUS_DISPLAY_NS (4ull * SDL_NS_PER_SECOND)
#define LATE_REBASE_DIVISOR 8u
#define AUDIO_RATE TOPGEAR_APP_AUDIO_SAMPLE_RATE
#define AUDIO_READ_FRAMES 4096u
/* Two emulated frames of queued PCM covers Core Audio's pull period. */
#define AUDIO_BASE_TARGET_FRAMES 1068u
#define AUDIO_MAX_RATE_ADJUSTMENT 0.005
#define AUDIO_AVERAGING_FRAMES 30u
#define ARRAY_COUNT(a) (sizeof(a) / sizeof((a)[0]))

enum GamepadControl {
    PAD_NONE = 0, PAD_DPAD_UP, PAD_DPAD_DOWN, PAD_DPAD_LEFT, PAD_DPAD_RIGHT,
    PAD_LS_UP, PAD_LS_DOWN, PAD_LS_LEFT, PAD_LS_RIGHT,
    PAD_SOUTH, PAD_EAST, PAD_WEST, PAD_NORTH,
    PAD_LEFT_SHOULDER, PAD_RIGHT_SHOULDER, PAD_LEFT_TRIGGER, PAD_RIGHT_TRIGGER,
    PAD_START, PAD_BACK, PAD_LEFT_STICK, PAD_RIGHT_STICK, PAD_CONTROL_COUNT
};

static const char *const k_pad_names[PAD_CONTROL_COUNT] = {
    "none", "dpup", "dpdown", "dpleft", "dpright",
    "lsup", "lsdown", "lsleft", "lsright",
    "south", "east", "west", "north",
    "lshoulder", "rshoulder", "ltrigger", "rtrigger",
    "start", "back", "lstick", "rstick"
};

/* Binding order matches the Windows launcher's settings.ini. */
static const char *const k_binding_names[BINDING_COUNT] = {
    "Up", "Down", "Left", "Right", "B", "A", "Y", "X", "L", "R",
    "Start", "Select"
};
static const uint16_t k_binding_masks[BINDING_COUNT] = {
    TOPGEAR_INPUT_UP, TOPGEAR_INPUT_DOWN, TOPGEAR_INPUT_LEFT,
    TOPGEAR_INPUT_RIGHT, TOPGEAR_INPUT_B, TOPGEAR_INPUT_A, TOPGEAR_INPUT_Y,
    TOPGEAR_INPUT_X, TOPGEAR_INPUT_L, TOPGEAR_INPUT_R, TOPGEAR_INPUT_START,
    TOPGEAR_INPUT_SELECT
};

typedef struct MacSettings {
    int integer_scale;
    int pause_on_focus_loss;
    int fullscreen_on_play;
    int show_fps_counter;
    int ntsc_frame_lock;
    int snapshot_slot;
    int audio_enabled;
    int audio_volume;
    int audio_latency_ms;
    SDL_Scancode keys[BINDING_COUNT];
    int pads[BINDING_COUNT];
    char rom_path[PATH_CAPACITY];
} MacSettings;

typedef struct MacAudio {
    SDL_AudioStream *stream;
    int16_t pcm[AUDIO_READ_FRAMES * TOPGEAR_APP_AUDIO_CHANNELS];
    uint32_t target_frames;
    uint32_t history[AUDIO_AVERAGING_FRAMES];
    uint32_t history_count;
    uint32_t history_index;
    int playing;
    uint64_t underruns;
    uint64_t recoveries;
} MacAudio;

static SDL_Window *g_window;
static SDL_Renderer *g_renderer;
static SDL_Texture *g_texture;
static SDL_Gamepad *g_gamepad;
static TopGearApp *g_game;
static MacSettings g_settings;
static MacAudio g_audio;
static TopGearInputLatch g_keyboard_input;
static int g_quit;
static int g_paused = 1;
static int g_failed;
static int g_show_help;
static int g_startup_prompt_pending;
static int g_resume_after_dialog;
static int g_fullscreen_entered;
static uint32_t g_uploaded_frame = UINT32_MAX;
static char g_status[512];
static uint64_t g_status_until;

static uint64_t g_frame_ns_base;
static uint64_t g_frame_ns_remainder;
static uint64_t g_frame_ns_accumulator;
static uint64_t g_next_deadline;
static uint64_t g_fps_window_start;
static uint32_t g_fps_window_frame;

static SDL_AtomicInt g_dialog_result_ready;
static char g_dialog_result[PATH_CAPACITY];

static char g_resources_directory[PATH_CAPACITY];
static char g_root_directory[PATH_CAPACITY];
static char g_rom_directory[PATH_CAPACITY];
static char g_data_directory[PATH_CAPACITY];
static char g_saves_directory[PATH_CAPACITY];
static char g_screenshots_directory[PATH_CAPACITY];
static char g_logs_directory[PATH_CAPACITY];
static char g_settings_path[PATH_CAPACITY];
static char g_player_settings_path[PATH_CAPACITY];
static char g_time_trial_data_path[PATH_CAPACITY];

/* ------------------------------------------------------------------ */
/* Status and messages                                                 */
/* ------------------------------------------------------------------ */

static void set_status(const char *format, ...) SDL_PRINTF_VARARG_FUNC(1);
static void set_status(const char *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    (void)vsnprintf(g_status, sizeof(g_status), format, arguments);
    va_end(arguments);
    g_status_until = SDL_GetTicksNS() + STATUS_DISPLAY_NS;
    SDL_Log("%s", g_status);
}

static void pause_audio(void);
static void resume_audio(void);
static void reset_pacing_clock(void);

static void show_message(SDL_MessageBoxFlags flags, const char *title,
                         const char *text) {
    int resume = g_game && !g_paused;
    if (resume) pause_audio();
    (void)SDL_ShowSimpleMessageBox(flags, title, text, g_window);
    topgear_input_latch_reset(&g_keyboard_input);
    if (resume) {
        resume_audio();
        reset_pacing_clock();
    }
}

/* ------------------------------------------------------------------ */
/* Paths and files                                                     */
/* ------------------------------------------------------------------ */

static int join_path(char *output, size_t capacity, const char *directory,
                     const char *name) {
    size_t length = strlen(directory);
    const char *separator = length && directory[length - 1u] == '/' ? "" : "/";
    int written = snprintf(output, capacity, "%s%s%s", directory, separator,
                           name);
    return written >= 0 && (size_t)written < capacity;
}

static int path_is_file(const char *path) {
    struct stat info;
    return path && path[0] && stat(path, &info) == 0 && S_ISREG(info.st_mode);
}

static int ensure_directory_tree(const char *path) {
    char partial[PATH_CAPACITY];
    size_t length;
    size_t index;
    struct stat info;
    if (!path || !path[0]) return 0;
    length = strlen(path);
    if (length >= sizeof(partial)) return 0;
    memcpy(partial, path, length + 1u);
    for (index = 1u; index <= length; ++index) {
        if (partial[index] != '/' && partial[index] != '\0') continue;
        partial[index] = '\0';
        if (mkdir(partial, 0755) != 0 && errno != EEXIST) return 0;
        partial[index] = path[index];
    }
    return stat(path, &info) == 0 && S_ISDIR(info.st_mode);
}

static int read_whole_file(const char *path, size_t limit, uint8_t **bytes,
                           size_t *size) {
    FILE *file = fopen(path, "rb");
    long length;
    uint8_t *buffer;
    size_t count;
    int trailing;
    *bytes = NULL;
    *size = 0u;
    if (!file) return 0;
    if (fseek(file, 0, SEEK_END) != 0 || (length = ftell(file)) < 0 ||
        (size_t)length > limit || fseek(file, 0, SEEK_SET) != 0) {
        (void)fclose(file);
        return 0;
    }
    buffer = (uint8_t *)malloc(length ? (size_t)length : 1u);
    if (!buffer) {
        (void)fclose(file);
        return 0;
    }
    count = fread(buffer, 1u, (size_t)length, file);
    trailing = fgetc(file);
    if (ferror(file) || fclose(file) != 0 || count != (size_t)length ||
        trailing != EOF) {
        free(buffer);
        return 0;
    }
    *bytes = buffer;
    *size = count;
    return 1;
}

/* Flush to the device, then atomically replace the destination. */
static int write_file_durable(const char *path, const void *bytes,
                              size_t size) {
    char temporary[PATH_CAPACITY + 32u];
    int descriptor;
    const uint8_t *cursor = (const uint8_t *)bytes;
    size_t remaining = size;
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

static int copy_file_exclusive(const char *source, const char *destination) {
    uint8_t *bytes;
    size_t size;
    int descriptor;
    int ok;
    if (!read_whole_file(source, 64u * 1024u * 1024u, &bytes, &size)) return 0;
    descriptor = open(destination, O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (descriptor < 0) {
        free(bytes);
        return 0;
    }
    ok = write(descriptor, bytes, size) == (ssize_t)size &&
         fsync(descriptor) == 0;
    ok = close(descriptor) == 0 && ok;
    if (!ok) (void)unlink(destination);
    free(bytes);
    return ok;
}

static void timestamp(char *output, size_t capacity) {
    struct timespec now;
    struct tm local;
    (void)clock_gettime(CLOCK_REALTIME, &now);
    (void)localtime_r(&now.tv_sec, &local);
    (void)snprintf(output, capacity, "%04d%02d%02d-%02d%02d%02d-%03ld",
                   local.tm_year + 1900, local.tm_mon + 1, local.tm_mday,
                   local.tm_hour, local.tm_min, local.tm_sec,
                   now.tv_nsec / 1000000L);
}

static void seed_data_file(const char *name) {
    char source[PATH_CAPACITY];
    char destination[PATH_CAPACITY];
    if (!join_path(source, sizeof(source), g_resources_directory, "Data") ||
        !join_path(source, sizeof(source), source, name) ||
        !join_path(destination, sizeof(destination), g_data_directory, name))
        return;
    if (!path_is_file(destination) && path_is_file(source))
        (void)copy_file_exclusive(source, destination);
}

static void initialize_paths(void) {
    const char *base = SDL_GetBasePath();
    if (!base) base = "./";
    (void)snprintf(g_resources_directory, sizeof(g_resources_directory), "%s",
                   base);
    /* Inside an .app bundle the executable directory is read-only and
       signed, so player data lives in Application Support. A loose build
       keeps the Windows-style portable layout beside the executable. */
    if (strstr(base, ".app/Contents/")) {
        char *preferences = SDL_GetPrefPath("", DATA_FOLDER_NAME);
        (void)snprintf(g_root_directory, sizeof(g_root_directory), "%s",
                       preferences ? preferences : base);
        SDL_free(preferences);
    } else {
        (void)snprintf(g_root_directory, sizeof(g_root_directory), "%s", base);
    }
    (void)join_path(g_rom_directory, PATH_CAPACITY, g_root_directory, "Rom");
    (void)join_path(g_data_directory, PATH_CAPACITY, g_root_directory, "Data");
    (void)join_path(g_saves_directory, PATH_CAPACITY, g_root_directory, "Saves");
    (void)join_path(g_screenshots_directory, PATH_CAPACITY, g_root_directory,
                    "Screenshots");
    (void)join_path(g_logs_directory, PATH_CAPACITY, g_root_directory, "Logs");
    (void)join_path(g_settings_path, PATH_CAPACITY, g_root_directory,
                    "settings.ini");
    (void)join_path(g_player_settings_path, PATH_CAPACITY, g_data_directory,
                    "player-settings.dat");
    (void)join_path(g_time_trial_data_path, PATH_CAPACITY, g_data_directory,
                    "time-trial.dat");
    (void)ensure_directory_tree(g_rom_directory);
    if (ensure_directory_tree(g_data_directory)) {
        seed_data_file("player-settings.dat");
        seed_data_file("time-trial.dat");
        seed_data_file("README.txt");
    }
}

static int find_sfc_rom(char *path, size_t capacity) {
    DIR *directory = opendir(g_rom_directory);
    struct dirent *entry;
    char selected[PATH_CAPACITY];
    selected[0] = '\0';
    if (!directory) return 0;
    while ((entry = readdir(directory)) != NULL) {
        size_t length = strlen(entry->d_name);
        char candidate[PATH_CAPACITY];
        if (length < 5u || entry->d_name[0] == '.' ||
            strcasecmp(entry->d_name + length - 4u, ".sfc") != 0)
            continue;
        if (!join_path(candidate, sizeof(candidate), g_rom_directory,
                       entry->d_name) || !path_is_file(candidate))
            continue;
        if (!selected[0] || strcasecmp(entry->d_name, selected) < 0)
            (void)snprintf(selected, sizeof(selected), "%s", entry->d_name);
    }
    (void)closedir(directory);
    return selected[0] && join_path(path, capacity, g_rom_directory, selected);
}

/* ------------------------------------------------------------------ */
/* settings.ini                                                        */
/* ------------------------------------------------------------------ */

static void settings_defaults(MacSettings *s) {
    int index;
    static const SDL_Scancode keys[BINDING_COUNT] = {
        SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT,
        SDL_SCANCODE_RIGHT, SDL_SCANCODE_D, SDL_SCANCODE_F, SDL_SCANCODE_A,
        SDL_SCANCODE_S, SDL_SCANCODE_E, SDL_SCANCODE_R, SDL_SCANCODE_G,
        SDL_SCANCODE_T
    };
    static const int pads[BINDING_COUNT] = {
        PAD_DPAD_UP, PAD_DPAD_DOWN, PAD_DPAD_LEFT, PAD_DPAD_RIGHT,
        PAD_SOUTH, PAD_EAST, PAD_WEST, PAD_NORTH,
        PAD_LEFT_SHOULDER, PAD_RIGHT_SHOULDER, PAD_START, PAD_BACK
    };
    memset(s, 0, sizeof(*s));
    s->ntsc_frame_lock = 1;
    s->snapshot_slot = 1;
    s->audio_enabled = 1;
    s->audio_volume = 100;
    for (index = 0; index < BINDING_COUNT; ++index) {
        s->keys[index] = keys[index];
        s->pads[index] = pads[index];
    }
}

static char *trim(char *text) {
    char *end;
    while (*text == ' ' || *text == '\t') ++text;
    end = text + strlen(text);
    while (end > text && (end[-1] == ' ' || end[-1] == '\t' ||
                          end[-1] == '\r' || end[-1] == '\n'))
        *--end = '\0';
    return text;
}

static int clamp_int(int value, int low, int high) {
    return value < low ? low : value > high ? high : value;
}

static void apply_setting(MacSettings *s, const char *section,
                          const char *key, const char *value) {
    int index;
    int number = atoi(value);
    if (!SDL_strcasecmp(section, "General")) {
        if (!SDL_strcasecmp(key, "IntegerScale")) s->integer_scale = number != 0;
        else if (!SDL_strcasecmp(key, "PauseOnFocusLoss")) s->pause_on_focus_loss = number != 0;
        else if (!SDL_strcasecmp(key, "FullScreenOnPlay")) s->fullscreen_on_play = number != 0;
        else if (!SDL_strcasecmp(key, "ShowFpsCounter")) s->show_fps_counter = number != 0;
        else if (!SDL_strcasecmp(key, "NtscFrameLock")) s->ntsc_frame_lock = number != 0;
        else if (!SDL_strcasecmp(key, "SnapshotSlot"))
            s->snapshot_slot = clamp_int(number, 1, SNAPSHOT_SLOT_COUNT);
    } else if (!SDL_strcasecmp(section, "Audio")) {
        if (!SDL_strcasecmp(key, "Enabled")) s->audio_enabled = number != 0;
        else if (!SDL_strcasecmp(key, "Volume")) s->audio_volume = clamp_int(number, 0, 100);
        else if (!SDL_strcasecmp(key, "LatencyMs")) s->audio_latency_ms = clamp_int(number, 0, 40);
    } else if (!SDL_strcasecmp(section, "ROM")) {
        if (!SDL_strcasecmp(key, "Path"))
            (void)snprintf(s->rom_path, sizeof(s->rom_path), "%s", value);
    } else if (!SDL_strcasecmp(section, "Keyboard")) {
        for (index = 0; index < BINDING_COUNT; ++index) {
            if (SDL_strcasecmp(key, k_binding_names[index])) continue;
            {
                SDL_Scancode code = SDL_GetScancodeFromName(value);
                if (code != SDL_SCANCODE_UNKNOWN) s->keys[index] = code;
            }
        }
    } else if (!SDL_strcasecmp(section, "Gamepad")) {
        for (index = 0; index < BINDING_COUNT; ++index) {
            int control;
            if (SDL_strcasecmp(key, k_binding_names[index])) continue;
            for (control = 0; control < PAD_CONTROL_COUNT; ++control)
                if (!SDL_strcasecmp(value, k_pad_names[control]))
                    s->pads[index] = control;
        }
    }
}

static void settings_load(MacSettings *s, const char *path) {
    uint8_t *bytes;
    size_t size;
    char section[64] = "";
    char *line;
    char *next;
    settings_defaults(s);
    if (!read_whole_file(path, 1024u * 1024u, &bytes, &size)) return;
    bytes = (uint8_t *)realloc(bytes, size + 1u);
    if (!bytes) return;
    bytes[size] = '\0';
    for (line = (char *)bytes; line && *line; line = next) {
        char *equals;
        char *text;
        next = strchr(line, '\n');
        if (next) *next++ = '\0';
        text = trim(line);
        if (*text == ';' || *text == '#' || !*text) continue;
        if (*text == '[') {
            char *close = strchr(text, ']');
            if (close) {
                *close = '\0';
                (void)snprintf(section, sizeof(section), "%s", trim(text + 1));
            }
            continue;
        }
        equals = strchr(text, '=');
        if (!equals) continue;
        *equals = '\0';
        apply_setting(s, section, trim(text), trim(equals + 1));
    }
    free(bytes);
}

static int settings_save(const MacSettings *s, const char *path) {
    char text[16384];
    size_t used = 0u;
    int index;
#define APPEND(...) do { \
        int n = snprintf(text + used, sizeof(text) - used, __VA_ARGS__); \
        if (n < 0 || (size_t)n >= sizeof(text) - used) return 0; \
        used += (size_t)n; \
    } while (0)
    APPEND("; Top Gear Definitive Edition - macOS launcher settings.\n"
           "; Edit while the app is closed. See README.txt in the app bundle.\n\n");
    APPEND("[General]\nIntegerScale=%d\nPauseOnFocusLoss=%d\n"
           "FullScreenOnPlay=%d\nShowFpsCounter=%d\nNtscFrameLock=%d\n"
           "SnapshotSlot=%d\n\n",
           s->integer_scale, s->pause_on_focus_loss, s->fullscreen_on_play,
           s->show_fps_counter, s->ntsc_frame_lock, s->snapshot_slot);
    APPEND("[Audio]\nEnabled=%d\nVolume=%d\nLatencyMs=%d\n\n",
           s->audio_enabled, s->audio_volume, s->audio_latency_ms);
    APPEND("[ROM]\nPath=%s\n\n[Keyboard]\n", s->rom_path);
    for (index = 0; index < BINDING_COUNT; ++index)
        APPEND("%s=%s\n", k_binding_names[index],
               SDL_GetScancodeName(s->keys[index]));
    APPEND("\n[Gamepad]\n");
    for (index = 0; index < BINDING_COUNT; ++index)
        APPEND("%s=%s\n", k_binding_names[index],
               k_pad_names[clamp_int(s->pads[index], 0, PAD_CONTROL_COUNT - 1)]);
#undef APPEND
    return write_file_durable(path, text, used);
}

static void save_settings(void) {
    if (!settings_save(&g_settings, g_settings_path))
        set_status("settings.ini could not be saved in %s.", g_root_directory);
}

/* ------------------------------------------------------------------ */
/* Data persistence                                                    */
/* ------------------------------------------------------------------ */

static int load_time_trial_data(TopGearApp *game) {
    uint8_t *bytes;
    size_t size;
    char error[256];
    if (!game) return 1;
    if (!read_whole_file(g_time_trial_data_path, 1024u * 1024u, &bytes,
                         &size)) {
        /* Permission or read errors are not an empty leaderboard. */
        return !path_is_file(g_time_trial_data_path) && errno == ENOENT;
    }
    memset(error, 0, sizeof(error));
    if (!topgear_app_time_trial_data_import(game, bytes, size, error,
                                            sizeof(error))) {
        free(bytes);
        return 0;
    }
    /* Preserve a TGTT v5 original before the first v6 rewrite. */
    if (size >= 8u && bytes[4] == 5u && bytes[5] == 0u) {
        char backup[PATH_CAPACITY + 64u];
        char stamp[32];
        timestamp(stamp, sizeof(stamp));
        (void)snprintf(backup, sizeof(backup), "%s.v5-%ld-%s.bak",
                       g_time_trial_data_path, (long)getpid(), stamp);
        if (!copy_file_exclusive(g_time_trial_data_path, backup)) {
            free(bytes);
            return 0;
        }
    }
    free(bytes);
    return 1;
}

static int flush_time_trial_data(int force) {
    void *bytes;
    size_t size;
    if (!g_game) return 1;
    if (!force && !topgear_app_time_trial_data_dirty(g_game)) return 1;
    if (!ensure_directory_tree(g_data_directory)) return 0;
    size = topgear_app_time_trial_data_size();
    bytes = malloc(size);
    if (!bytes) return 0;
    if (!topgear_app_time_trial_data_export(g_game, bytes, size) ||
        !write_file_durable(g_time_trial_data_path, bytes, size)) {
        free(bytes);
        return 0;
    }
    free(bytes);
    /* Only a durable commit acknowledges the completed run to the core; a
       failed save keeps the Results page locked while saving is retried. */
    topgear_app_time_trial_data_mark_clean(g_game);
    return 1;
}

static int flush_player_settings(void) {
    if (!g_game) return 1;
    return ensure_directory_tree(g_data_directory) &&
           topgear_app_player_settings_save(g_game, g_player_settings_path);
}

/* ------------------------------------------------------------------ */
/* Audio                                                               */
/* ------------------------------------------------------------------ */

static uint32_t audio_queued_frames(void) {
    int bytes = g_audio.stream ? SDL_GetAudioStreamQueued(g_audio.stream) : 0;
    return bytes > 0 ? (uint32_t)bytes /
                       (TOPGEAR_APP_AUDIO_CHANNELS * sizeof(int16_t)) : 0u;
}

static void close_audio(void) {
    if (g_audio.stream) SDL_DestroyAudioStream(g_audio.stream);
    memset(&g_audio, 0, sizeof(g_audio));
    if (g_game) (void)topgear_app_audio_discard(g_game);
}

static void open_audio(void) {
    SDL_AudioSpec spec;
    close_audio();
    if (!g_settings.audio_enabled) return;
    spec.format = SDL_AUDIO_S16;
    spec.channels = (int)TOPGEAR_APP_AUDIO_CHANNELS;
    spec.freq = (int)AUDIO_RATE;
    /* The device stream opens paused; SDL converts 32,040 Hz to the device
       rate for speaker output only, never inside the core. */
    g_audio.stream = SDL_OpenAudioDeviceStream(
        SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, NULL, NULL);
    if (!g_audio.stream) {
        set_status("Audio output is unavailable: %s", SDL_GetError());
        return;
    }
    (void)SDL_SetAudioStreamGain(g_audio.stream,
                                 (float)g_settings.audio_volume / 100.0f);
    g_audio.target_frames = AUDIO_BASE_TARGET_FRAMES +
        (uint32_t)g_settings.audio_latency_ms * AUDIO_RATE / 1000u;
}

static void pause_audio(void) {
    if (!g_audio.stream) return;
    (void)SDL_PauseAudioStreamDevice(g_audio.stream);
    (void)SDL_ClearAudioStream(g_audio.stream);
    g_audio.playing = 0;
}

static void resume_audio(void) {
    static const int16_t silence[AUDIO_BASE_TARGET_FRAMES * 2u];
    if (g_game) (void)topgear_app_audio_discard(g_game);
    if (!g_audio.stream) return;
    (void)SDL_ClearAudioStream(g_audio.stream);
    /* Prime the target depth so the first frames cannot underrun. */
    (void)SDL_PutAudioStreamData(g_audio.stream, silence, sizeof(silence));
    (void)SDL_SetAudioStreamFrequencyRatio(g_audio.stream, 1.0f);
    g_audio.history_count = 0u;
    g_audio.history_index = 0u;
    (void)SDL_ResumeAudioStreamDevice(g_audio.stream);
    g_audio.playing = 1;
}

static void drain_core_audio(TopGearApp *game) {
    size_t frames;
    while ((frames = topgear_app_audio_read(game, g_audio.pcm,
                                            AUDIO_READ_FRAMES)) > 0u) {
        if (g_audio.stream && g_audio.playing)
            (void)SDL_PutAudioStreamData(
                g_audio.stream, g_audio.pcm,
                (int)(frames * TOPGEAR_APP_AUDIO_CHANNELS * sizeof(int16_t)));
    }
}

static void audio_progress(TopGearApp *game, void *opaque) {
    (void)opaque;
    drain_core_audio(game);
}

/* Once per emulated frame: steer the queue toward its target depth with a
   small playback-rate correction, and recover from a runaway backlog. */
static void audio_end_of_frame(void) {
    uint32_t queued;
    uint64_t sum = 0u;
    uint32_t index;
    double average;
    double error;
    double ratio;
    if (!g_audio.stream || !g_audio.playing) return;
    queued = audio_queued_frames();
    if (queued == 0u) ++g_audio.underruns;
    if (queued > g_audio.target_frames + AUDIO_RATE / 5u) {
        (void)SDL_ClearAudioStream(g_audio.stream);
        g_audio.history_count = 0u;
        ++g_audio.recoveries;
        return;
    }
    g_audio.history[g_audio.history_index] = queued;
    g_audio.history_index = (g_audio.history_index + 1u) %
                            AUDIO_AVERAGING_FRAMES;
    if (g_audio.history_count < AUDIO_AVERAGING_FRAMES) ++g_audio.history_count;
    for (index = 0u; index < g_audio.history_count; ++index)
        sum += g_audio.history[index];
    average = (double)sum / (double)g_audio.history_count;
    error = (average - (double)g_audio.target_frames) / (double)AUDIO_RATE;
    ratio = 1.0 + error * 0.1;
    if (ratio > 1.0 + AUDIO_MAX_RATE_ADJUSTMENT)
        ratio = 1.0 + AUDIO_MAX_RATE_ADJUSTMENT;
    if (ratio < 1.0 - AUDIO_MAX_RATE_ADJUSTMENT)
        ratio = 1.0 - AUDIO_MAX_RATE_ADJUSTMENT;
    (void)SDL_SetAudioStreamFrequencyRatio(g_audio.stream, (float)ratio);
}

/* ------------------------------------------------------------------ */
/* Input                                                               */
/* ------------------------------------------------------------------ */

static uint16_t opposite_direction(uint16_t mask) {
    if (mask == TOPGEAR_INPUT_UP) return TOPGEAR_INPUT_DOWN;
    if (mask == TOPGEAR_INPUT_DOWN) return TOPGEAR_INPUT_UP;
    if (mask == TOPGEAR_INPUT_LEFT) return TOPGEAR_INPUT_RIGHT;
    if (mask == TOPGEAR_INPUT_RIGHT) return TOPGEAR_INPUT_LEFT;
    return 0u;
}

static uint16_t key_to_input(SDL_Scancode code) {
    uint16_t mask = 0u;
    int index;
    for (index = 0; index < BINDING_COUNT; ++index)
        if (g_settings.keys[index] == code) mask |= k_binding_masks[index];
    return mask;
}

static int pad_control_pressed(int control) {
    const Sint16 stick = 16384;
    const Sint16 trigger = 8192;
    SDL_Gamepad *pad = g_gamepad;
    switch (control) {
        case PAD_DPAD_UP: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_DPAD_UP);
        case PAD_DPAD_DOWN: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_DPAD_DOWN);
        case PAD_DPAD_LEFT: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_DPAD_LEFT);
        case PAD_DPAD_RIGHT: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_DPAD_RIGHT);
        case PAD_LS_UP: return SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFTY) < -stick;
        case PAD_LS_DOWN: return SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFTY) > stick;
        case PAD_LS_LEFT: return SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFTX) < -stick;
        case PAD_LS_RIGHT: return SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFTX) > stick;
        case PAD_SOUTH: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_SOUTH);
        case PAD_EAST: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_EAST);
        case PAD_WEST: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_WEST);
        case PAD_NORTH: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_NORTH);
        case PAD_LEFT_SHOULDER: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_LEFT_SHOULDER);
        case PAD_RIGHT_SHOULDER: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER);
        case PAD_LEFT_TRIGGER: return SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFT_TRIGGER) > trigger;
        case PAD_RIGHT_TRIGGER: return SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER) > trigger;
        case PAD_START: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_START);
        case PAD_BACK: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_BACK);
        case PAD_LEFT_STICK: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_LEFT_STICK);
        case PAD_RIGHT_STICK: return SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_RIGHT_STICK);
        default: return 0;
    }
}

static uint16_t gamepad_input(void) {
    uint16_t mask = 0u;
    int index;
    if (!g_gamepad ||
        !(SDL_GetWindowFlags(g_window) & SDL_WINDOW_INPUT_FOCUS)) return 0u;
    for (index = 0; index < BINDING_COUNT; ++index)
        if (pad_control_pressed(g_settings.pads[index]))
            mask |= k_binding_masks[index];
    /* Opposite directions cancel, as on the original controller. */
    if ((mask & (TOPGEAR_INPUT_LEFT | TOPGEAR_INPUT_RIGHT)) ==
        (TOPGEAR_INPUT_LEFT | TOPGEAR_INPUT_RIGHT))
        mask &= (uint16_t)~(TOPGEAR_INPUT_LEFT | TOPGEAR_INPUT_RIGHT);
    if ((mask & (TOPGEAR_INPUT_UP | TOPGEAR_INPUT_DOWN)) ==
        (TOPGEAR_INPUT_UP | TOPGEAR_INPUT_DOWN))
        mask &= (uint16_t)~(TOPGEAR_INPUT_UP | TOPGEAR_INPUT_DOWN);
    return mask;
}

static void open_first_gamepad(void) {
    SDL_JoystickID *pads;
    int count = 0;
    if (g_gamepad) return;
    pads = SDL_GetGamepads(&count);
    if (pads && count > 0) {
        g_gamepad = SDL_OpenGamepad(pads[0]);
        if (g_gamepad)
            set_status("Gamepad connected: %s", SDL_GetGamepadName(g_gamepad));
    }
    SDL_free(pads);
}

/* ------------------------------------------------------------------ */
/* Pacing                                                              */
/* ------------------------------------------------------------------ */

static void initialize_pacing(void) {
    /* One NTSC frame is 655171/39375000 s. Keep the remainder exactly. */
    const uint64_t numerator = TOPGEAR_APP_PRESENTATION_FPS_NUMERATOR;
    const uint64_t scaled = SDL_NS_PER_SECOND *
                            (uint64_t)TOPGEAR_APP_PRESENTATION_FPS_DENOMINATOR;
    g_frame_ns_base = scaled / numerator;
    g_frame_ns_remainder = scaled % numerator;
}

static void reset_pacing_clock(void) {
    g_frame_ns_accumulator = 0u;
    g_next_deadline = SDL_GetTicksNS();
    g_fps_window_start = g_next_deadline;
    g_fps_window_frame = g_game ? topgear_app_current_frame(g_game) : 0u;
}

static void advance_frame_deadline(void) {
    uint64_t frame_ns = g_frame_ns_base;
    g_frame_ns_accumulator += g_frame_ns_remainder;
    if (g_frame_ns_accumulator >= TOPGEAR_APP_PRESENTATION_FPS_NUMERATOR) {
        ++frame_ns;
        g_frame_ns_accumulator -= TOPGEAR_APP_PRESENTATION_FPS_NUMERATOR;
    }
    g_next_deadline += frame_ns;
}

/* ------------------------------------------------------------------ */
/* Game lifecycle                                                      */
/* ------------------------------------------------------------------ */

static void update_window_title(void) {
    char title[160];
    if (g_game && !g_paused && g_settings.show_fps_counter) {
        uint64_t now = SDL_GetTicksNS();
        uint64_t elapsed = now - g_fps_window_start;
        if (elapsed < SDL_NS_PER_SECOND) return;
        (void)snprintf(title, sizeof(title), "%s - %.2f FPS", APP_TITLE,
                       (double)(topgear_app_current_frame(g_game) -
                                g_fps_window_frame) *
                           (double)SDL_NS_PER_SECOND / (double)elapsed);
        g_fps_window_start = now;
        g_fps_window_frame = topgear_app_current_frame(g_game);
    } else {
        (void)snprintf(title, sizeof(title), "%s%s", APP_TITLE,
                       g_game && g_paused ? " - Paused" : "");
    }
    SDL_SetWindowTitle(g_window, title);
}

static void pause_game(const char *message) {
    pause_audio();
    g_paused = 1;
    topgear_input_latch_reset(&g_keyboard_input);
    if (message) set_status("%s", message);
    update_window_title();
}

static void play_game(void) {
    if (!g_game || g_failed) return;
    g_paused = 0;
    g_show_help = 0;
    topgear_input_latch_reset(&g_keyboard_input);
    resume_audio();
    reset_pacing_clock();
    if (g_settings.fullscreen_on_play && !g_fullscreen_entered) {
        g_fullscreen_entered = 1;
        (void)SDL_SetWindowFullscreen(g_window, true);
    }
    update_window_title();
}

static void toggle_pause_play(void) {
    if (!g_game || g_failed) return;
    if (g_paused) play_game();
    else pause_game("Paused. Press Escape to continue.");
}

static void stop_game_on_core_failure(void) {
    char stamp[32];
    char log_name[96];
    char log_path[PATH_CAPACITY];
    char error[192];
    char text[PATH_CAPACITY + 1024u];
    int log_written;
    /* A missing static authority is a production error: stop, keep the last
       frame, write the diagnostics and never fall back to an interpreter. */
    pause_audio();
    g_paused = 1;
    g_failed = 1;
    topgear_input_latch_reset(&g_keyboard_input);
    timestamp(stamp, sizeof(stamp));
    (void)snprintf(log_name, sizeof(log_name),
                   "Static-Core-Failure-%s.txt", stamp);
    log_written = ensure_directory_tree(g_logs_directory) &&
        join_path(log_path, sizeof(log_path), g_logs_directory, log_name) &&
        topgear_app_write_diagnostic_log(g_game, log_path, NULL, error,
                                         sizeof(error));
    (void)snprintf(text, sizeof(text),
        "Top Gear stopped because the static-recompiled core reached an "
        "execution or hardware state that is not in its compiled production "
        "authority. No interpreter or emulator fallback was used.\n\n"
        "Error details:\n%s\n\n%s%s",
        topgear_app_last_error(g_game)[0] ? topgear_app_last_error(g_game) :
            "The static core stopped without a text description.",
        log_written ? "Diagnostic log:\n" :
            "The Logs folder or diagnostic text file could not be created.",
        log_written ? log_path : "");
    set_status("Static core stopped fail-closed. Cmd+R resets the game.");
    update_window_title();
    show_message(SDL_MESSAGEBOX_ERROR, "Static Recompilation Error", text);
}

static int read_rom_file(const char *path, uint8_t **rom, char *error,
                         size_t capacity) {
    size_t size;
    if (!read_whole_file(path, TOPGEAR_APP_ROM_SIZE + 1u, rom, &size)) {
        (void)snprintf(error, capacity, "Unable to open the selected ROM file.");
        return 0;
    }
    if (size != TOPGEAR_APP_ROM_SIZE) {
        free(*rom);
        *rom = NULL;
        (void)snprintf(error, capacity,
            "The exact 524,288-byte Top Gear (USA) NTSC ROM is required.");
        return 0;
    }
    return 1;
}

static void present(void);

static void load_rom(const char *path) {
    uint8_t *rom = NULL;
    TopGearApp *game = NULL;
    char error[256];
    int resume_after_failure = (g_game && !g_paused && !g_failed) ||
                               g_resume_after_dialog;
    g_resume_after_dialog = 0;
    memset(error, 0, sizeof(error));
    pause_game(NULL);
    set_status("Loading and verifying the exact Top Gear ROM...");
    present();
    if (!read_rom_file(path, &rom, error, sizeof(error)) ||
        !topgear_app_create(&game, rom, TOPGEAR_APP_ROM_SIZE, error,
                            sizeof(error))) {
        free(rom);
        set_status("%s", error[0] ? error : "Run failed.");
        show_message(SDL_MESSAGEBOX_ERROR, APP_TITLE,
                     error[0] ? error :
                     "The static recompilation could not be started.");
        if (resume_after_failure) play_game();
        return;
    }
    free(rom);
    /* Commit the previous game's Data before the new core reads it. */
    close_audio();
    (void)flush_time_trial_data(1);
    (void)flush_player_settings();
    topgear_app_destroy(g_game);
    g_game = game;
    g_failed = 0;
    g_uploaded_frame = UINT32_MAX;
    if (!load_time_trial_data(g_game))
        set_status("Time Trial Data could not be read; the file was left unchanged.");
    if (!topgear_app_player_settings_load(g_game, g_player_settings_path))
        set_status("Player or music settings could not be read; the file was left unchanged.");
    (void)snprintf(g_settings.rom_path, sizeof(g_settings.rom_path), "%s", path);
    save_settings();
    open_audio();
    play_game();
}

static void reset_game(void) {
    char error[256];
    if (!g_game) return;
    pause_game(NULL);
    memset(error, 0, sizeof(error));
    if (!topgear_app_reset(g_game, error, sizeof(error))) {
        set_status("%s", error[0] ? error : "Unable to reset the ROM.");
        show_message(SDL_MESSAGEBOX_ERROR, APP_TITLE,
                     "The ROM could not be reset.");
        return;
    }
    g_failed = 0;
    g_uploaded_frame = UINT32_MAX;
    set_status("ROM returned to the real cold-reset frame.");
    play_game();
}

static void advance_one_frame(void) {
    TopGearAppFrameResult result;
    uint16_t input;
    memset(&result, 0, sizeof(result));
    input = topgear_input_latch_sample(&g_keyboard_input) | gamepad_input();
    if (!topgear_app_advance_streamed(g_game, input, 1u, audio_progress, NULL,
                                      &result)) {
        stop_game_on_core_failure();
        return;
    }
    topgear_input_latch_consume(&g_keyboard_input, input);
    drain_core_audio(g_game);
    audio_end_of_frame();
    if (!flush_player_settings())
        set_status("Player or music settings could not be saved. The last "
                   "committed Data files have been preserved.");
    if (!flush_time_trial_data(0) && topgear_app_time_trial_data_dirty(g_game))
        set_status("Time Trial Data save failed. The Results page stays "
                   "locked while saving is retried.");
    if (topgear_app_audio_overflowed(g_game))
        topgear_app_audio_clear_overflow(g_game);
}

/* ------------------------------------------------------------------ */
/* Snapshots and screenshots                                           */
/* ------------------------------------------------------------------ */

static int snapshot_path(int slot, char *path, size_t capacity) {
    char name[64];
    (void)snprintf(name, sizeof(name), "snapshot-slot-%d.scsnap", slot);
    return ensure_directory_tree(g_saves_directory) &&
           join_path(path, capacity, g_saves_directory, name);
}

static void save_snapshot(void) {
    char path[PATH_CAPACITY];
    char error[256];
    int slot = g_settings.snapshot_slot;
    if (!g_game) {
        set_status("Load the ROM before using snapshots.");
        return;
    }
    memset(error, 0, sizeof(error));
    if (!snapshot_path(slot, path, sizeof(path))) {
        set_status("The Saves folder could not be created.");
        return;
    }
    if (!topgear_app_snapshot_save(g_game, path, error, sizeof(error))) {
        set_status("%s", error[0] ? error : "Snapshot save failed.");
        return;
    }
    set_status("Snapshot slot %d saved at frame %u.", slot,
               topgear_app_current_frame(g_game));
}

static void load_snapshot(void) {
    char path[PATH_CAPACITY];
    char error[256];
    int slot = g_settings.snapshot_slot;
    int resume = !g_paused;
    if (!g_game) {
        set_status("Load the ROM before using snapshots.");
        return;
    }
    if (!snapshot_path(slot, path, sizeof(path)) || !path_is_file(path)) {
        set_status("Snapshot slot %d is empty.", slot);
        return;
    }
    memset(error, 0, sizeof(error));
    pause_audio();
    if (!topgear_app_snapshot_load(g_game, path, error, sizeof(error))) {
        set_status("%s", error[0] ? error : "Snapshot load failed.");
        if (resume) resume_audio();
        return;
    }
    g_failed = 0;
    g_uploaded_frame = UINT32_MAX;
    if (resume) {
        resume_audio();
        reset_pacing_clock();
    }
    set_status("Snapshot slot %d loaded at frame %u.", slot,
               topgear_app_current_frame(g_game));
}

static void select_snapshot_slot(int slot) {
    g_settings.snapshot_slot = clamp_int(slot, 1, SNAPSHOT_SLOT_COUNT);
    save_settings();
    set_status("Snapshot slot %d selected. 1 saves, 2 loads.",
               g_settings.snapshot_slot);
}

static void capture_screenshot(void) {
    char stamp[32];
    char name[96];
    char path[PATH_CAPACITY];
    uint32_t *pixels;
    SDL_Surface *surface;
    int ok = 0;
    const size_t count = (size_t)TOPGEAR_APP_FRAME_WIDTH *
                         TOPGEAR_APP_FRAME_HEIGHT;
    if (!g_game) return;
    /* Encode a private copy of the last completed core frame, never the
       window surface. */
    pixels = (uint32_t *)malloc(count * sizeof(*pixels));
    if (!pixels) return;
    memcpy(pixels, topgear_app_frame_bgra(g_game), count * sizeof(*pixels));
    timestamp(stamp, sizeof(stamp));
    (void)snprintf(name, sizeof(name), "topgear-frame-%08u-%s.bmp",
                   topgear_app_current_frame(g_game), stamp);
    surface = SDL_CreateSurfaceFrom((int)TOPGEAR_APP_FRAME_WIDTH,
                                    (int)TOPGEAR_APP_FRAME_HEIGHT,
                                    SDL_PIXELFORMAT_XRGB8888, pixels,
                                    (int)TOPGEAR_APP_FRAME_WIDTH * 4);
    if (surface && ensure_directory_tree(g_screenshots_directory) &&
        join_path(path, sizeof(path), g_screenshots_directory, name))
        ok = SDL_SaveBMP(surface, path);
    SDL_DestroySurface(surface);
    free(pixels);
    if (ok) set_status("Screenshot saved: Screenshots/%s", name);
    else set_status("Unable to save the current game-frame screenshot.");
}

/* ------------------------------------------------------------------ */
/* File dialog                                                         */
/* ------------------------------------------------------------------ */

static void SDLCALL rom_dialog_done(void *userdata, const char *const *files,
                                    int filter) {
    (void)userdata;
    (void)filter;
    if (!files || !files[0]) {
        SDL_SetAtomicInt(&g_dialog_result_ready, 2);
        return;
    }
    (void)snprintf(g_dialog_result, sizeof(g_dialog_result), "%s", files[0]);
    SDL_SetAtomicInt(&g_dialog_result_ready, 1);
}

static void browse_for_rom(void) {
    static const SDL_DialogFileFilter filters[] = {
        { "Super Nintendo ROM (*.sfc)", "sfc" }
    };
    g_resume_after_dialog = g_game && !g_paused && !g_failed;
    pause_game(NULL);
    SDL_ShowOpenFileDialog(rom_dialog_done, NULL, g_window, filters,
                           (int)ARRAY_COUNT(filters), g_rom_directory, false);
}

static void service_dialog_result(void) {
    int ready = SDL_GetAtomicInt(&g_dialog_result_ready);
    if (!ready) return;
    SDL_SetAtomicInt(&g_dialog_result_ready, 0);
    if (ready == 1) load_rom(g_dialog_result);
    else if (g_resume_after_dialog) play_game();
}

static void show_data_folder(void) {
    char url[PATH_CAPACITY + 16u];
    (void)snprintf(url, sizeof(url), "file://%s", g_root_directory);
    if (!SDL_OpenURL(url))
        set_status("Data folder: %s", g_root_directory);
}

/* ------------------------------------------------------------------ */
/* Presentation                                                        */
/* ------------------------------------------------------------------ */

static const char *const k_help_lines[] = {
    "Esc       Pause / resume",
    "Cmd+O     Open a ROM",
    "Cmd+R     Reset",
    "Cmd+F     Full screen (also F11)",
    "Cmd+1..5  Select snapshot slot",
    "1 / 2     Save / load snapshot",
    "F8        Screenshot",
    "Cmd+I     Integer scaling",
    "Cmd+D     Show data folder",
    "Cmd+Q     Quit",
    "",
    "Keys: arrows, D=B F=A A=Y S=X",
    "      E=L R=R G=Start T=Select",
};

static void draw_text_block(const char *const *lines, int count, int output_w,
                            int output_h, int at_bottom) {
    float scale = (float)(output_h / 300);
    float width = 0.0f;
    float height;
    float x;
    float y;
    int index;
    SDL_FRect box;
    if (scale < 1.0f) scale = 1.0f;
    for (index = 0; index < count; ++index) {
        float line = (float)strlen(lines[index]) *
                     SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE;
        if (line > width) width = line;
    }
    height = (float)count * (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE + 4);
    x = ((float)output_w / scale - width) / 2.0f;
    y = at_bottom ? (float)output_h / scale - height - 12.0f :
                    ((float)output_h / scale - height) / 2.0f;
    if (x < 4.0f) x = 4.0f;
    (void)SDL_SetRenderScale(g_renderer, scale, scale);
    box.x = x - 8.0f;
    box.y = y - 8.0f;
    box.w = width + 16.0f;
    box.h = height + 12.0f;
    (void)SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 200);
    (void)SDL_RenderFillRect(g_renderer, &box);
    (void)SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);
    for (index = 0; index < count; ++index)
        (void)SDL_RenderDebugText(
            g_renderer, x,
            y + (float)index * (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE + 4),
            lines[index]);
    (void)SDL_SetRenderScale(g_renderer, 1.0f, 1.0f);
}

static void present(void) {
    int output_w = 0;
    int output_h = 0;
    (void)SDL_GetCurrentRenderOutputSize(g_renderer, &output_w, &output_h);
    (void)SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);
    (void)SDL_RenderClear(g_renderer);
    if (g_game) {
        SDL_FRect destination;
        float w;
        float h;
        uint32_t frame = topgear_app_current_frame(g_game);
        if (frame != g_uploaded_frame) {
            (void)SDL_UpdateTexture(g_texture, NULL,
                                    topgear_app_frame_bgra(g_game),
                                    (int)TOPGEAR_APP_FRAME_WIDTH * 4);
            g_uploaded_frame = frame;
        }
        if (g_settings.integer_scale) {
            int scale = SDL_min(output_w / (int)TOPGEAR_APP_FRAME_WIDTH,
                                output_h / (int)TOPGEAR_APP_FRAME_HEIGHT);
            if (scale < 1) scale = 1;
            w = (float)(scale * (int)TOPGEAR_APP_FRAME_WIDTH);
            h = (float)(scale * (int)TOPGEAR_APP_FRAME_HEIGHT);
        } else {
            /* Match the Windows launcher's default 4:3 presentation. */
            h = (float)output_h;
            w = h * 4.0f / 3.0f;
            if (w > (float)output_w) {
                w = (float)output_w;
                h = w * 3.0f / 4.0f;
            }
        }
        destination.x = SDL_floorf(((float)output_w - w) / 2.0f);
        destination.y = SDL_floorf(((float)output_h - h) / 2.0f);
        destination.w = w;
        destination.h = h;
        (void)SDL_RenderTexture(g_renderer, g_texture, NULL, &destination);
    }
    if (g_show_help) {
        draw_text_block(k_help_lines, (int)ARRAY_COUNT(k_help_lines),
                        output_w, output_h, 0);
    } else if (!g_game) {
        static const char *const lines[] = {
            ("Top Gear Definitive Edition " TOPGEAR_APP_VERSION),
            "",
            "Press Cmd+O to choose the Top Gear (USA) ROM,",
            "or drop the .sfc file onto this window.",
            "",
            "F1 shows all shortcuts.",
        };
        draw_text_block(lines, (int)ARRAY_COUNT(lines), output_w, output_h, 0);
    } else if (g_paused && !g_failed) {
        static const char *const lines[] = {
            "Paused",
            "",
            "Esc resumes. F1 shows all shortcuts.",
        };
        draw_text_block(lines, (int)ARRAY_COUNT(lines), output_w, output_h, 0);
    }
    if (g_status[0] && SDL_GetTicksNS() < g_status_until) {
        const char *line = g_status;
        draw_text_block(&line, 1, output_w, output_h, 1);
    }
    (void)SDL_RenderPresent(g_renderer);
}

/* ------------------------------------------------------------------ */
/* Events                                                              */
/* ------------------------------------------------------------------ */

static void toggle_fullscreen(void) {
    int fullscreen = (SDL_GetWindowFlags(g_window) & SDL_WINDOW_FULLSCREEN) != 0;
    (void)SDL_SetWindowFullscreen(g_window, !fullscreen);
}

static int handle_command_key(SDL_Scancode code) {
    switch (code) {
        case SDL_SCANCODE_O: browse_for_rom(); return 1;
        case SDL_SCANCODE_R: reset_game(); return 1;
        case SDL_SCANCODE_F: toggle_fullscreen(); return 1;
        case SDL_SCANCODE_D: show_data_folder(); return 1;
        case SDL_SCANCODE_I:
            g_settings.integer_scale = !g_settings.integer_scale;
            save_settings();
            set_status(g_settings.integer_scale ? "Integer scaling on." :
                                                  "4:3 presentation.");
            return 1;
        case SDL_SCANCODE_1: case SDL_SCANCODE_2: case SDL_SCANCODE_3:
        case SDL_SCANCODE_4: case SDL_SCANCODE_5:
            select_snapshot_slot((int)(code - SDL_SCANCODE_1) + 1);
            return 1;
        default: return 0;
    }
}

static void handle_key_down(const SDL_KeyboardEvent *key) {
    uint16_t mask;
    if (key->mod & SDL_KMOD_GUI) {
        (void)handle_command_key(key->scancode);
        return;
    }
    switch (key->scancode) {
        case SDL_SCANCODE_ESCAPE:
            if (key->repeat) return;
            if (g_show_help) g_show_help = 0;
            else toggle_pause_play();
            return;
        case SDL_SCANCODE_F1:
            if (!key->repeat) {
                g_show_help = !g_show_help;
                if (g_show_help && g_game && !g_paused) pause_game(NULL);
            }
            return;
        case SDL_SCANCODE_F7:
            if (!g_game) browse_for_rom();
            return;
        case SDL_SCANCODE_F8: capture_screenshot(); return;
        case SDL_SCANCODE_F11: toggle_fullscreen(); return;
        case SDL_SCANCODE_1: if (!key->repeat) save_snapshot(); return;
        case SDL_SCANCODE_2: if (!key->repeat) load_snapshot(); return;
        default: break;
    }
    if (!g_game || g_paused) return;
    mask = key_to_input(key->scancode);
    if (mask)
        topgear_input_latch_press(&g_keyboard_input, mask,
                                  opposite_direction(mask), key->repeat);
}

static void handle_event(const SDL_Event *event) {
    switch (event->type) {
        case SDL_EVENT_QUIT:
            g_quit = 1;
            break;
        case SDL_EVENT_KEY_DOWN:
            handle_key_down(&event->key);
            break;
        case SDL_EVENT_KEY_UP:
            if (g_game && !g_paused) {
                uint16_t mask = key_to_input(event->key.scancode);
                if (mask) topgear_input_latch_release(&g_keyboard_input, mask);
            }
            break;
        case SDL_EVENT_WINDOW_FOCUS_LOST:
            topgear_input_latch_reset(&g_keyboard_input);
            if (g_settings.pause_on_focus_loss && g_game && !g_paused)
                pause_game("Paused because the window lost focus.");
            break;
        case SDL_EVENT_DROP_FILE:
            if (event->drop.data) {
                g_startup_prompt_pending = 0;
                load_rom(event->drop.data);
            }
            break;
        case SDL_EVENT_GAMEPAD_ADDED:
            open_first_gamepad();
            break;
        case SDL_EVENT_GAMEPAD_REMOVED:
            if (g_gamepad &&
                SDL_GetGamepadID(g_gamepad) == event->gdevice.which) {
                SDL_CloseGamepad(g_gamepad);
                g_gamepad = NULL;
                set_status("Gamepad disconnected.");
                open_first_gamepad();
            }
            break;
        default:
            break;
    }
}

static void pump_events(void) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) handle_event(&event);
    service_dialog_result();
}

/* ------------------------------------------------------------------ */
/* Main loop                                                           */
/* ------------------------------------------------------------------ */

static void run_loop(void) {
    while (!g_quit) {
        pump_events();
        if (g_startup_prompt_pending && !g_game) {
            g_startup_prompt_pending = 0;
            browse_for_rom();
        }
        if (!g_game || g_paused) {
            present();
            (void)SDL_WaitEventTimeout(NULL, 100);
            continue;
        }
        if (g_settings.ntsc_frame_lock) {
            uint64_t now = SDL_GetTicksNS();
            uint64_t tolerance;
            if (now < g_next_deadline) {
                SDL_DelayPrecise(g_next_deadline - now);
                pump_events();
                if (!g_game || g_paused || g_quit) continue;
            }
            advance_one_frame();
            if (g_paused) continue;
            present();
            update_window_title();
            /* Advance one absolute deadline per frame. A materially late
               frame rebases the clock instead of producing a catch-up burst
               and an audio backlog. */
            advance_frame_deadline();
            tolerance = g_frame_ns_base / LATE_REBASE_DIVISOR;
            now = SDL_GetTicksNS();
            if (now > g_next_deadline + tolerance) {
                g_frame_ns_accumulator = 0u;
                g_next_deadline = now;
            }
        } else {
            /* Unlocked: audio remains the safety throttle. */
            if (g_audio.stream && g_audio.playing &&
                audio_queued_frames() > g_audio.target_frames + AUDIO_RATE / 30u) {
                SDL_DelayNS(SDL_NS_PER_MS);
                continue;
            }
            advance_one_frame();
            if (g_paused) continue;
            present();
            update_window_title();
        }
    }
}

static void shutdown_launcher(void) {
    pause_audio();
    if (g_game) {
        (void)flush_time_trial_data(1);
        (void)flush_player_settings();
        topgear_app_destroy(g_game);
        g_game = NULL;
    }
    close_audio();
    save_settings();
    if (g_gamepad) SDL_CloseGamepad(g_gamepad);
    SDL_DestroyTexture(g_texture);
    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);
    SDL_Quit();
}

int main(int argc, char **argv) {
    char rom_path[PATH_CAPACITY];
    char mappings[PATH_CAPACITY];
    (void)SDL_SetAppMetadata(APP_TITLE, TOPGEAR_APP_VERSION,
                             "io.github.pablovsouza.topgear-static-recomp");
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMEPAD)) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, APP_TITLE,
                                 SDL_GetError(), NULL);
        return 1;
    }
    initialize_paths();
    initialize_pacing();
    settings_load(&g_settings, g_settings_path);
    save_settings();
    if (join_path(mappings, sizeof(mappings), g_resources_directory,
                  "gamecontrollerdb.txt") && path_is_file(mappings))
        (void)SDL_AddGamepadMappingsFromFile(mappings);

    if (!SDL_CreateWindowAndRenderer(APP_TITLE, 1024, 768,
                                     SDL_WINDOW_RESIZABLE |
                                     SDL_WINDOW_HIGH_PIXEL_DENSITY,
                                     &g_window, &g_renderer)) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, APP_TITLE,
                                 SDL_GetError(), NULL);
        SDL_Quit();
        return 1;
    }
    SDL_SetWindowMinimumSize(g_window, (int)TOPGEAR_APP_FRAME_WIDTH,
                             (int)TOPGEAR_APP_FRAME_HEIGHT);
    (void)SDL_SetRenderVSync(g_renderer, 0);
    (void)SDL_SetRenderDrawBlendMode(g_renderer, SDL_BLENDMODE_BLEND);
    /* The core's BGRA bytes are XRGB8888 on little-endian hosts. */
    g_texture = SDL_CreateTexture(g_renderer, SDL_PIXELFORMAT_XRGB8888,
                                  SDL_TEXTUREACCESS_STREAMING,
                                  (int)TOPGEAR_APP_FRAME_WIDTH,
                                  (int)TOPGEAR_APP_FRAME_HEIGHT);
    if (!g_texture) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, APP_TITLE,
                                 SDL_GetError(), g_window);
        shutdown_launcher();
        return 1;
    }
    (void)SDL_SetTextureScaleMode(g_texture, SDL_SCALEMODE_NEAREST);
    (void)SDL_SetTextureBlendMode(g_texture, SDL_BLENDMODE_NONE);
    open_first_gamepad();

    /* A ROM passed on the command line wins, then the remembered path, then
       the first .sfc in the Rom folder. Otherwise ask after the first event
       pump so a ROM opened from Finder can arrive first. */
    rom_path[0] = '\0';
    if (argc > 1 && path_is_file(argv[1]))
        (void)snprintf(rom_path, sizeof(rom_path), "%s", argv[1]);
    else if (path_is_file(g_settings.rom_path))
        (void)snprintf(rom_path, sizeof(rom_path), "%s", g_settings.rom_path);
    else
        (void)find_sfc_rom(rom_path, sizeof(rom_path));
    if (rom_path[0]) load_rom(rom_path);
    else g_startup_prompt_pending = 1;

    run_loop();
    shutdown_launcher();
    return 0;
}
