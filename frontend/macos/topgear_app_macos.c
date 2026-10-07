/* Top Gear Definitive Edition - macOS launcher.

   The launcher drives the same static core, Data stores and input latch as
   the Windows frontend. SDL3 supplies the window (Metal renderer), the Core
   Audio device, keyboard and gamepad input; topgear_mac_ui.m supplies native
   AppKit menus and dialogs. Frame pacing, audio control, durable Data
   commits and fail-closed diagnostics follow the Windows host. */

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "topgear_app_core.h"
#include "topgear_audio_output_sdl.h"
#include "topgear_input_latch.h"
#include "topgear_mac_settings.h"
#include "topgear_mac_ui.h"

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
#define PATH_CAPACITY TOPGEAR_MAC_PATH_CAPACITY
#define STATUS_DISPLAY_NS (4ull * SDL_NS_PER_SECOND)
#define LATE_REBASE_DIVISOR 8u
#define ARRAY_COUNT(a) (sizeof(a) / sizeof((a)[0]))

static SDL_Window *g_window;
static SDL_Renderer *g_renderer;
static SDL_Texture *g_texture;
static SDL_Gamepad *g_gamepad;
static TopGearApp *g_game;
static TopGearMacSettings g_settings;
static TopGearMacAudioOutput g_audio;
static TopGearInputLatch g_keyboard_input;
static Uint32 g_command_event;
static int g_quit;
static int g_paused = 1;
static int g_failed;
static int g_fullscreen_by_play;
static int g_capture_fullscreen;
static int g_loaded_snapshot_slot = -1;
static int g_resume_after_dialog;
static uint32_t g_uploaded_frame = UINT32_MAX;
static char g_selected_rom[PATH_CAPACITY];
static char g_status[PATH_CAPACITY + 256u];
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

static const char k_welcome_text[] =
    "Frontend shortcuts\n"
    "Escape - Switch between the game and the launcher (pause)\n"
    "1 - Save the current snapshot slot\n"
    "2 - Load the current snapshot slot\n"
    "F1 - Welcome and shortcut guide\n"
    "F2 - Open the Save Snapshot window\n"
    "F3 - Open the Load Snapshot window\n"
    "F4 - Settings (also Command-Comma)\n"
    "F5 - Controls\n"
    "F6 - Audio settings\n"
    "F7 - Run the selected ROM\n"
    "F8 - Capture the current game frame\n"
    "Command-O - Open a ROM\n"
    "Command-R - Reset the ROM\n"
    "Control-Command-F - Toggle full screen\n"
    "Command-D - Show the data folder in Finder\n"
    "Command-Q - Quit\n\n"
    "On most Mac keyboards, hold Fn to use the F keys.\n\n"
    "ROM title: Top Gear\n"
    "Region: USA NTSC\n"
    "File type: .sfc\n"
    "Place the ROM in the Rom folder (inside the data folder, Command-D) "
    "or choose File > Open ROM.";

/* ------------------------------------------------------------------ */
/* Status                                                              */
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

static const char *last_status(void) { return g_status; }

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

static void save_settings(void) {
    if (!topgear_mac_settings_save(&g_settings, g_settings_path))
        set_status("Settings changed, but the settings file could not be written.");
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
        !topgear_mac_write_file_durable(g_time_trial_data_path, bytes, size)) {
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

static void close_audio(void) {
    topgear_mac_audio_output_close(&g_audio);
    if (g_game) (void)topgear_app_audio_discard(g_game);
}

static int open_audio(int show_error) {
    char error[512];
    close_audio();
    if (!g_game || !g_settings.audio.enabled) return 1;
    if (!topgear_mac_audio_output_open(&g_audio, &g_settings.audio, error,
                                       sizeof(error))) {
        set_status("%s", error[0] ? error : "Unable to start audio output.");
        if (show_error)
            topgear_mac_ui_information("Audio Settings", NULL,
                error[0] ? error : "Unable to start audio output.");
        return 0;
    }
    return 1;
}

static void audio_progress(TopGearApp *game, void *opaque) {
    (void)opaque;
    topgear_mac_audio_output_pump_progress(&g_audio, game);
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
    int index;
    for (index = 0; index < TOPGEAR_MAC_BINDING_COUNT; ++index)
        if (g_settings.keys[index] == (int)code)
            return topgear_mac_binding_mask(index);
    return 0u;
}

static SDL_Gamepad *current_gamepad(void) {
    if (g_gamepad && !SDL_GamepadConnected(g_gamepad)) {
        SDL_CloseGamepad(g_gamepad);
        g_gamepad = NULL;
    }
    if (!g_gamepad) {
        int count = 0;
        SDL_JoystickID *pads = SDL_GetGamepads(&count);
        if (pads && count > 0) g_gamepad = SDL_OpenGamepad(pads[0]);
        SDL_free(pads);
    }
    return g_gamepad;
}

static int gamepad_gameplay_active(void) {
    return g_settings.input_source == TOPGEAR_MAC_INPUT_SOURCE_GAMEPAD &&
           g_gamepad && SDL_GamepadConnected(g_gamepad);
}

static uint16_t gamepad_input(void) {
    uint16_t mask = 0u;
    int index;
    if (!(SDL_GetWindowFlags(g_window) & SDL_WINDOW_INPUT_FOCUS)) return 0u;
    for (index = 0; index < TOPGEAR_MAC_BINDING_COUNT; ++index)
        if (topgear_mac_pad_control_pressed(g_gamepad, g_settings.pads[index]))
            mask |= topgear_mac_binding_mask(index);
    return mask;
}

/* The selected source supplies player one; the keyboard takes over while
   no gamepad is connected, as on Windows. */
static uint16_t current_gameplay_input(void) {
    return gamepad_gameplay_active() ? gamepad_input() :
           topgear_input_latch_sample(&g_keyboard_input);
}

/* ------------------------------------------------------------------ */
/* Pacing                                                              */
/* ------------------------------------------------------------------ */

static void initialize_pacing(void) {
    /* One NTSC frame is 655171/39375000 s. Keep the remainder exactly. */
    const uint64_t scaled = SDL_NS_PER_SECOND *
                            (uint64_t)TOPGEAR_APP_PRESENTATION_FPS_DENOMINATOR;
    g_frame_ns_base = scaled / TOPGEAR_APP_PRESENTATION_FPS_NUMERATOR;
    g_frame_ns_remainder = scaled % TOPGEAR_APP_PRESENTATION_FPS_NUMERATOR;
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
/* Presentation                                                        */
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

static void set_fullscreen(int fullscreen) {
    int active = (SDL_GetWindowFlags(g_window) & SDL_WINDOW_FULLSCREEN) != 0;
    if (active == (fullscreen != 0)) return;
    (void)SDL_SetWindowFullscreen(g_window, fullscreen != 0);
    (void)SDL_SyncWindow(g_window);
}

static void wrap_lines(const char *text, size_t width, char lines[][128],
                       int *count, int max_lines) {
    const char *cursor = text;
    *count = 0;
    while (*cursor && *count < max_lines) {
        size_t length = strlen(cursor);
        size_t take = length < width ? length : width;
        if (take < length) {
            size_t space = take;
            while (space > 0 && cursor[space] != ' ') --space;
            if (space > 0) take = space;
        }
        if (take > 127u) take = 127u;
        memcpy(lines[*count], cursor, take);
        lines[*count][take] = '\0';
        ++*count;
        cursor += take;
        while (*cursor == ' ') ++cursor;
    }
}

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

static void game_rect(int output_w, int output_h, SDL_FRect *rect) {
    float w;
    float h;
    if (g_settings.integer_scale >= 1) {
        /* The selected integer scale, reduced until it fits. */
        int scale = g_settings.integer_scale;
        while (scale > 1 &&
               (scale * (int)TOPGEAR_APP_FRAME_WIDTH > output_w ||
                scale * (int)TOPGEAR_APP_FRAME_HEIGHT > output_h))
            --scale;
        w = (float)(scale * (int)TOPGEAR_APP_FRAME_WIDTH);
        h = (float)(scale * (int)TOPGEAR_APP_FRAME_HEIGHT);
    } else {
        /* Automatic: fit the window at the Windows launcher's 4:3. */
        h = (float)output_h;
        w = h * 4.0f / 3.0f;
        if (w > (float)output_w) {
            w = (float)output_w;
            h = w * 3.0f / 4.0f;
        }
    }
    rect->x = SDL_floorf(((float)output_w - w) / 2.0f);
    rect->y = SDL_floorf(((float)output_h - h) / 2.0f);
    rect->w = w;
    rect->h = h;
}

static void save_fullscreen_capture(int output_w, int output_h) {
    char stamp[32];
    char name[128];
    char path[PATH_CAPACITY];
    SDL_Surface *surface;
    int ok = 0;
    g_capture_fullscreen = 0;
    /* The displayed screen exactly as presented, including the 4:3 scaling
       and letterbox bars, before any launcher overlay is drawn. */
    surface = SDL_RenderReadPixels(g_renderer, NULL);
    timestamp(stamp, sizeof(stamp));
    (void)snprintf(name, sizeof(name),
                   "topgear-fullscreen-%dx%d-frame-%08u-%s.bmp", output_w,
                   output_h, topgear_app_current_frame(g_game), stamp);
    if (surface && ensure_directory_tree(g_screenshots_directory) &&
        join_path(path, sizeof(path), g_screenshots_directory, name))
        ok = SDL_SaveBMP(surface, path);
    SDL_DestroySurface(surface);
    if (ok) set_status("Fullscreen screenshot saved: Screenshots/%s", name);
    else set_status("Unable to save the fullscreen screenshot.");
}

static void present(void) {
    int output_w = 0;
    int output_h = 0;
    int show_status;
    (void)SDL_GetCurrentRenderOutputSize(g_renderer, &output_w, &output_h);
    (void)SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);
    (void)SDL_RenderClear(g_renderer);
    if (g_game) {
        SDL_FRect destination;
        uint32_t frame = topgear_app_current_frame(g_game);
        if (frame != g_uploaded_frame) {
            (void)SDL_UpdateTexture(g_texture, NULL,
                                    topgear_app_frame_bgra(g_game),
                                    (int)TOPGEAR_APP_FRAME_WIDTH * 4);
            g_uploaded_frame = frame;
        }
        game_rect(output_w, output_h, &destination);
        (void)SDL_RenderTexture(g_renderer, g_texture, NULL, &destination);
        if (g_capture_fullscreen) save_fullscreen_capture(output_w, output_h);
    }
    if (!g_game) {
        static const char *const lines[] = {
            ("Top Gear Definitive Edition " TOPGEAR_APP_VERSION),
            "",
            "File > Open ROM (Command-O) selects the Top Gear (USA) ROM.",
            "F7 runs it. You can also drop the .sfc file here.",
            "",
            "F1 shows the Welcome window and all shortcuts.",
        };
        draw_text_block(lines, (int)ARRAY_COUNT(lines), output_w, output_h, 0);
    } else if (g_paused && !g_failed) {
        static const char *const lines[] = {
            "Paused",
            "",
            "Escape resumes. F1 shows all shortcuts.",
        };
        draw_text_block(lines, (int)ARRAY_COUNT(lines), output_w, output_h, 0);
    }
    /* Like the Windows status bar, the latest status stays visible while
       the launcher is paused; during play it fades after a few seconds. */
    show_status = g_status[0] &&
                  (!g_game || g_paused || SDL_GetTicksNS() < g_status_until);
    if (show_status) {
        char wrapped[4][128];
        const char *lines[4];
        int count;
        int index;
        int columns = output_w / (SDL_max(1, output_h / 300) *
                                  SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE) - 4;
        wrap_lines(g_status, (size_t)SDL_clamp(columns, 20, 127), wrapped,
                   &count, 4);
        for (index = 0; index < count; ++index) lines[index] = wrapped[index];
        draw_text_block(lines, count, output_w, output_h, 1);
    }
    (void)SDL_RenderPresent(g_renderer);
}

/* ------------------------------------------------------------------ */
/* Game lifecycle                                                      */
/* ------------------------------------------------------------------ */

static void pause_game(const char *message) {
    topgear_mac_audio_output_pause(&g_audio);
    g_paused = 1;
    topgear_input_latch_reset(&g_keyboard_input);
    /* As on Windows, pausing restores the windowed launcher presentation. */
    if (g_fullscreen_by_play) {
        g_fullscreen_by_play = 0;
        set_fullscreen(0);
    }
    if (message) set_status("%s", message);
    update_window_title();
}

static void play_game(void) {
    if (!g_game || g_failed) return;
    g_paused = 0;
    topgear_input_latch_reset(&g_keyboard_input);
    if (g_settings.fullscreen_on_play &&
        !(SDL_GetWindowFlags(g_window) & SDL_WINDOW_FULLSCREEN)) {
        set_fullscreen(1);
        g_fullscreen_by_play = 1;
    }
    topgear_mac_audio_output_resume(&g_audio);
    reset_pacing_clock();
    if (topgear_mac_audio_output_is_open(&g_audio))
        set_status("Top Gear is running.");
    else
        set_status("Running generated static code. Audio output is disabled in Audio Settings.");
    update_window_title();
}

static void toggle_pause_play(void) {
    if (!g_game || g_failed) return;
    if (g_paused) play_game();
    else pause_game("Paused. Choose Play or press Escape to continue.");
}

/* Dialogs pause the game and resume it afterwards when it was running. */
static int begin_dialog(const char *message) {
    int resume = g_game && !g_paused && !g_failed;
    if (resume) pause_game(message);
    else if (g_fullscreen_by_play) pause_game(NULL);
    present();
    return resume;
}

static void end_dialog(int resume) {
    topgear_input_latch_reset(&g_keyboard_input);
    if (resume && g_game) play_game();
    else update_window_title();
}

static void stop_game_on_core_failure(void) {
    char stamp[32];
    char log_name[96];
    char log_path[PATH_CAPACITY];
    char error[192];
    char text[PATH_CAPACITY + 2048u];
    const char *detail;
    int log_written;
    /* A missing static authority is a production error: stop, keep the last
       frame, write the diagnostics and never fall back to an interpreter. */
    topgear_mac_audio_output_pause(&g_audio);
    g_paused = 1;
    g_failed = 1;
    topgear_input_latch_reset(&g_keyboard_input);
    if (g_fullscreen_by_play) {
        g_fullscreen_by_play = 0;
        set_fullscreen(0);
    }
    detail = topgear_app_last_error(g_game);
    if (!detail || !detail[0])
        detail = "The static core stopped without a text description.";
    timestamp(stamp, sizeof(stamp));
    (void)snprintf(log_name, sizeof(log_name),
                   "Static-Core-Failure-%s.txt", stamp);
    log_written = ensure_directory_tree(g_logs_directory) &&
        join_path(log_path, sizeof(log_path), g_logs_directory, log_name) &&
        topgear_app_write_diagnostic_log(g_game, log_path, NULL, error,
                                         sizeof(error));
    if (log_written) {
        set_status("Static core stopped fail-closed. Diagnostic log: %s", log_path);
        (void)snprintf(text, sizeof(text),
            "Top Gear stopped because the static-recompiled core reached an "
            "execution or hardware state that is not in its compiled production "
            "authority. No interpreter or emulator fallback was used.\n\n"
            "Error details\n-------------\n%s\n\n"
            "Diagnostic log\n--------------\n%s\n\n"
            "Keep this text file when reporting the problem. It contains the "
            "processor state, exact source and target contexts, expected "
            "successors, recent execution history, timing, audio, PPU and "
            "machine-state hashes needed to reproduce and repair the gap.",
            detail, log_path);
    } else {
        set_status("Static core stopped fail-closed, but its diagnostic log could not be written.");
        (void)snprintf(text, sizeof(text),
            "Top Gear stopped because the static-recompiled core reached an "
            "execution or hardware state that is not in its compiled production "
            "authority. No interpreter or emulator fallback was used.\n\n"
            "Error details\n-------------\n%s\n\n"
            "The Logs folder or diagnostic text file could not be created. "
            "Check that the data folder is writable, then reproduce the error.",
            detail);
    }
    update_window_title();
    present();
    topgear_mac_ui_information("Static Recompilation Error", NULL, text);
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

static void start_rom_load(int play_after_load) {
    uint8_t *rom = NULL;
    TopGearApp *game = NULL;
    char error[256];
    int resume_after_failure = g_game && !g_paused && !g_failed;
    if (!g_selected_rom[0]) return;
    memset(error, 0, sizeof(error));
    pause_game(NULL);
    set_status("Loading and verifying the exact Top Gear ROM...");
    present();
    if (!read_rom_file(g_selected_rom, &rom, error, sizeof(error)) ||
        !topgear_app_create(&game, rom, TOPGEAR_APP_ROM_SIZE, error,
                            sizeof(error))) {
        free(rom);
        set_status("%s", error[0] ? error : "Run failed.");
        topgear_mac_ui_information(APP_TITLE, NULL,
            error[0] ? error : "The static recompilation could not be started.");
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
    g_loaded_snapshot_slot = -1;
    g_uploaded_frame = UINT32_MAX;
    (void)load_time_trial_data(g_game);
    (void)topgear_app_player_settings_load(g_game, g_player_settings_path);
    (void)open_audio(1);
    if (play_after_load) {
        play_game();
    } else {
        update_window_title();
        set_status("Top Gear is loaded and ready. Choose Play to start.");
    }
}

/* A selected ROM is verified when it runs; selection alone only remembers
   it, as the Windows launcher's Browse does. */
static void select_rom(const char *path, int run_now) {
    (void)snprintf(g_selected_rom, sizeof(g_selected_rom), "%s", path);
    (void)snprintf(g_settings.rom_path, sizeof(g_settings.rom_path), "%s", path);
    save_settings();
    if (run_now || g_settings.auto_run_on_load) {
        set_status("ROM selected. Starting now.");
        start_rom_load(1);
    } else {
        set_status("ROM selected. Choose Run or press F7.");
    }
}

static void reset_game(void) {
    char error[256];
    if (!g_game) return;
    pause_game(NULL);
    close_audio();
    memset(error, 0, sizeof(error));
    if (!topgear_app_reset(g_game, error, sizeof(error))) {
        set_status("%s", error[0] ? error : "Unable to reset the ROM.");
        topgear_mac_ui_information(APP_TITLE, NULL, "The ROM could not be reset.");
        (void)open_audio(1);
        return;
    }
    (void)open_audio(1);
    g_failed = 0;
    g_loaded_snapshot_slot = -1;
    g_uploaded_frame = UINT32_MAX;
    set_status("ROM returned to the real cold-reset frame.");
    play_game();
}

static void advance_one_frame(void) {
    TopGearAppFrameResult result;
    uint16_t input;
    memset(&result, 0, sizeof(result));
    input = current_gameplay_input();
    if (!topgear_app_advance_streamed(g_game, input, 1u, audio_progress, NULL,
                                      &result)) {
        stop_game_on_core_failure();
        return;
    }
    if (!gamepad_gameplay_active())
        topgear_input_latch_consume(&g_keyboard_input, input);
    topgear_mac_audio_output_pump(&g_audio, g_game);
    if (!flush_player_settings())
        set_status("Player or music settings could not be saved. The last "
                   "committed Data files have been preserved; check the file "
                   "and folder permissions.");
    if (!flush_time_trial_data(0) && topgear_app_time_trial_data_dirty(g_game))
        set_status("Time Trial Data save failed. The completed result is not "
                   "committed; the Results page will remain locked while "
                   "saving is retried.");
    if (topgear_app_audio_overflowed(g_game))
        topgear_app_audio_clear_overflow(g_game);
    if (!result.frame_rendered && result.renderer_error[0])
        set_status("%s", result.renderer_error);
}

/* ------------------------------------------------------------------ */
/* Snapshots and screenshots                                           */
/* ------------------------------------------------------------------ */

static int snapshot_path(int slot, char *path, size_t capacity) {
    char name[64];
    if (slot < 1 || slot > TOPGEAR_MAC_SNAPSHOT_SLOT_COUNT) return 0;
    (void)snprintf(name, sizeof(name), "snapshot-slot-%d.scsnap", slot);
    return ensure_directory_tree(g_saves_directory) &&
           join_path(path, capacity, g_saves_directory, name);
}

static int snapshot_exists(int slot) {
    char path[PATH_CAPACITY];
    return snapshot_path(slot, path, sizeof(path)) && path_is_file(path);
}

static void snapshot_describe(int slot, int load_mode, char *text,
                              size_t capacity) {
    char path[PATH_CAPACITY];
    char date[96];
    struct stat info;
    struct tm local;
    if (!snapshot_path(slot, path, sizeof(path)) || stat(path, &info) != 0) {
        (void)snprintf(text, capacity, "%s",
                       load_mode ? "Empty slot - Not loaded" : "Empty slot");
        return;
    }
    if (localtime_r(&info.st_mtime, &local))
        (void)strftime(date, sizeof(date), "%x %H:%M", &local);
    else
        (void)snprintf(date, sizeof(date), "Date unavailable");
    if (load_mode)
        (void)snprintf(text, capacity, "Saved %s - %s", date,
                       g_loaded_snapshot_slot == slot ? "Loaded" : "Not loaded");
    else
        (void)snprintf(text, capacity, "Saved %s", date);
}

static int save_snapshot_slot(int slot) {
    char path[PATH_CAPACITY];
    char error[256];
    if (slot < 1 || slot > TOPGEAR_MAC_SNAPSHOT_SLOT_COUNT) slot = 1;
    g_settings.snapshot_slot = slot;
    save_settings();
    if (!snapshot_path(slot, path, sizeof(path))) {
        set_status("The Saves folder could not be created.");
        return 0;
    }
    memset(error, 0, sizeof(error));
    if (!topgear_app_snapshot_save(g_game, path, error, sizeof(error))) {
        set_status("%s", error[0] ? error : "Snapshot save failed.");
        return 0;
    }
    set_status("Snapshot slot %d saved at frame %u: %s", slot,
               topgear_app_current_frame(g_game), path);
    return 1;
}

static int load_snapshot_slot(int slot) {
    char path[PATH_CAPACITY];
    char error[256];
    if (slot < 1 || slot > TOPGEAR_MAC_SNAPSHOT_SLOT_COUNT) slot = 1;
    g_settings.snapshot_slot = slot;
    save_settings();
    if (!snapshot_exists(slot)) {
        set_status("Snapshot slot %d is empty.", slot);
        return 0;
    }
    (void)snapshot_path(slot, path, sizeof(path));
    /* A snapshot changes emulated machine time, not the host audio device:
       keep the device open and discard only queued audio. */
    topgear_mac_audio_output_pause(&g_audio);
    topgear_mac_audio_output_flush(&g_audio);
    (void)topgear_app_audio_discard(g_game);
    memset(error, 0, sizeof(error));
    if (!topgear_app_snapshot_load(g_game, path, error, sizeof(error))) {
        set_status("%s", error[0] ? error : "Snapshot load failed.");
        return 0;
    }
    (void)topgear_app_audio_discard(g_game);
    topgear_mac_audio_output_flush(&g_audio);
    topgear_mac_audio_output_pause(&g_audio);
    g_failed = 0;
    g_loaded_snapshot_slot = slot;
    g_uploaded_frame = UINT32_MAX;
    set_status("Snapshot slot %d loaded at frame %u.", slot,
               topgear_app_current_frame(g_game));
    return 1;
}

static void save_current_snapshot(void) {
    int resume;
    if (!g_game) {
        set_status("Load and run the ROM before using snapshots.");
        return;
    }
    resume = !g_paused && !g_failed;
    if (resume) pause_game("Paused while saving the current snapshot.");
    (void)save_snapshot_slot(g_settings.snapshot_slot);
    if (resume) play_game();
}

static void load_current_snapshot(void) {
    int resume;
    if (!g_game) {
        set_status("Load and run the ROM before using snapshots.");
        return;
    }
    resume = !g_paused && !g_failed;
    if (resume) pause_game("Paused while loading the current snapshot.");
    (void)load_snapshot_slot(g_settings.snapshot_slot);
    if (resume) play_game();
}

static void show_snapshot_window(int save_mode) {
    TopGearMacSnapshotHost host;
    int resume;
    int loaded;
    if (!g_game) {
        set_status("Load and run the ROM before using snapshots.");
        return;
    }
    if (!ensure_directory_tree(g_saves_directory)) {
        topgear_mac_ui_information(APP_TITLE, NULL,
                                   "The Saves folder could not be created.");
        return;
    }
    memset(&host, 0, sizeof(host));
    host.save = save_snapshot_slot;
    host.load = load_snapshot_slot;
    host.exists = snapshot_exists;
    host.describe = snapshot_describe;
    host.last_status = last_status;
    host.selected_slot = g_settings.snapshot_slot;
    host.loaded_slot = g_loaded_snapshot_slot;
    resume = begin_dialog("Paused while the Snapshot window is open.");
    loaded = topgear_mac_ui_snapshots(save_mode, &host);
    if ((resume || loaded) && g_game) {
        end_dialog(1);
    } else {
        set_status("Snapshot window closed. The game remains paused.");
        end_dialog(0);
    }
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
    if (SDL_GetWindowFlags(g_window) & SDL_WINDOW_FULLSCREEN) {
        /* Full screen captures the displayed screen on the next present. */
        g_capture_fullscreen = 1;
        if (g_paused) present();
        return;
    }
    /* Windowed: encode a private copy of the last completed core frame,
       never the window surface. */
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
    if (ok) set_status("Screenshot saved at frame %u: Screenshots/%s",
                       topgear_app_current_frame(g_game), name);
    else set_status("Unable to save the current game-frame screenshot.");
}

/* ------------------------------------------------------------------ */
/* Dialog commands                                                     */
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
        { "SNES ROM images (*.sfc)", "sfc" }
    };
    char directory[PATH_CAPACITY];
    char *slash;
    (void)snprintf(directory, sizeof(directory), "%s",
                   g_selected_rom[0] ? g_selected_rom : g_rom_directory);
    slash = g_selected_rom[0] ? strrchr(directory, '/') : NULL;
    if (slash) *slash = '\0';
    g_resume_after_dialog = begin_dialog(NULL);
    SDL_ShowOpenFileDialog(rom_dialog_done, NULL, g_window, filters,
                           (int)ARRAY_COUNT(filters), directory, false);
}

static void service_dialog_result(void) {
    int ready = SDL_GetAtomicInt(&g_dialog_result_ready);
    int resume = g_resume_after_dialog;
    if (!ready) return;
    SDL_SetAtomicInt(&g_dialog_result_ready, 0);
    g_resume_after_dialog = 0;
    if (ready == 1) select_rom(g_dialog_result, 0);
    if (!g_game || g_paused) end_dialog(resume);
}

static void show_settings(void) {
    TopGearMacSettings edited = g_settings;
    int resume = begin_dialog("Paused while Settings is open.");
    if (topgear_mac_ui_settings(&edited)) {
        g_settings = edited;
        if (topgear_mac_settings_save(&g_settings, g_settings_path))
            set_status("Settings changed and saved.");
        else
            set_status("Settings changed, but the settings file could not be written.");
        reset_pacing_clock();
    }
    end_dialog(resume);
}

static void show_controls(void) {
    TopGearMacSettings edited = g_settings;
    int resume = begin_dialog("Paused while Controller Bindings is open.");
    if (topgear_mac_ui_controls(&edited, current_gamepad)) {
        g_settings = edited;
        if (topgear_mac_settings_save(&g_settings, g_settings_path))
            set_status("Control settings changed and saved.");
        else
            set_status("Control settings changed, but the settings file could not be written.");
    }
    end_dialog(resume);
}

static void show_audio_settings(void) {
    TopGearMacAudioSettings edited = g_settings.audio;
    TopGearMacAudioDiagnostics diagnostics;
    char device[TOPGEAR_MAC_AUDIO_DEVICE_NAME_CAPACITY];
    int resume;
    topgear_mac_audio_output_get_diagnostics(&g_audio, &diagnostics);
    (void)snprintf(device, sizeof(device), "%s", g_audio.opened_device_name);
    resume = begin_dialog("Paused while Audio Settings is open.");
    if (topgear_mac_ui_audio(&edited, &diagnostics, device)) {
        g_settings.audio = edited;
        save_settings();
        if (g_game) {
            if (open_audio(1) && topgear_mac_audio_output_is_open(&g_audio))
                set_status("Audio settings applied.");
            else if (!g_settings.audio.enabled)
                set_status("Audio settings applied. Audio output is disabled.");
        } else {
            set_status("Audio settings saved. They will be used when the game starts.");
        }
    }
    end_dialog(resume);
}

static void show_profile(void) {
    char status[256];
    int resume = begin_dialog("Paused while editing the profile.");
    int result = topgear_mac_ui_profile(g_game, g_player_settings_path,
                                        g_data_directory, status,
                                        sizeof(status));
    if (result) set_status("%s", status);
    if (result == 2 && g_game) reset_game();
    else end_dialog(resume);
}

static void show_leaderboard(void) {
    int resume = begin_dialog("Paused while Leaderboard is open.");
    topgear_mac_ui_leaderboard(g_game, g_time_trial_data_path);
    end_dialog(resume);
}

static void show_welcome(void) {
    int resume = begin_dialog("Paused while Welcome is open.");
    topgear_mac_ui_information("Welcome",
                               "Welcome to Top Gear (SNES) Static Recompilation",
                               k_welcome_text);
    end_dialog(resume);
}

static void show_about(void) {
    int resume = begin_dialog(NULL);
    topgear_mac_ui_information("About Top Gear",
        "Top Gear (SNES) Static Recompilation",
        "Version " TOPGEAR_APP_VERSION "\n\n"
        "Title: Top Gear\nRegion: USA NTSC\nFile type: .sfc\n\n"
        "F1 - Open the Welcome window\n\n"
        "SDL is used under the zlib license; see SDL-LICENSE.txt and "
        "THIRD-PARTY-NOTICES.txt inside the application bundle.");
    end_dialog(resume);
}

static void show_data_folder(void) {
    char url[PATH_CAPACITY + 16u];
    (void)snprintf(url, sizeof(url), "file://%s", g_root_directory);
    if (!SDL_OpenURL(url))
        set_status("Data folder: %s", g_root_directory);
}

/* ------------------------------------------------------------------ */
/* Commands                                                            */
/* ------------------------------------------------------------------ */

static int validate_command(int command, int *checked) {
    int running = g_game && !g_paused && !g_failed;
    if (checked) *checked = 0;
    switch (command) {
        case TOPGEAR_MAC_COMMAND_OPEN_ROM: return !g_game;
        case TOPGEAR_MAC_COMMAND_RUN: return g_selected_rom[0] && !g_game;
        case TOPGEAR_MAC_COMMAND_PAUSE_PLAY:
            if (checked) *checked = running;
            return g_game && !g_failed;
        case TOPGEAR_MAC_COMMAND_RESET:
        case TOPGEAR_MAC_COMMAND_SAVE_CURRENT_SNAPSHOT:
        case TOPGEAR_MAC_COMMAND_LOAD_CURRENT_SNAPSHOT:
        case TOPGEAR_MAC_COMMAND_SAVE_SNAPSHOT:
        case TOPGEAR_MAC_COMMAND_LOAD_SNAPSHOT:
        case TOPGEAR_MAC_COMMAND_SCREENSHOT:
            return g_game != NULL;
        case TOPGEAR_MAC_COMMAND_FULLSCREEN_ON_PLAY:
            if (checked) *checked = g_settings.fullscreen_on_play;
            return 1;
        case TOPGEAR_MAC_COMMAND_AUTO_RUN:
            if (checked) *checked = g_settings.auto_run_on_load;
            return 1;
        default:
            return 1;
    }
}

static void execute_command(int command) {
    if (!validate_command(command, NULL) || topgear_mac_ui_modal_active())
        return;
    switch (command) {
        case TOPGEAR_MAC_COMMAND_OPEN_ROM: browse_for_rom(); break;
        case TOPGEAR_MAC_COMMAND_RUN: start_rom_load(1); break;
        case TOPGEAR_MAC_COMMAND_PAUSE_PLAY: toggle_pause_play(); break;
        case TOPGEAR_MAC_COMMAND_RESET: reset_game(); break;
        case TOPGEAR_MAC_COMMAND_SAVE_CURRENT_SNAPSHOT: save_current_snapshot(); break;
        case TOPGEAR_MAC_COMMAND_LOAD_CURRENT_SNAPSHOT: load_current_snapshot(); break;
        case TOPGEAR_MAC_COMMAND_SAVE_SNAPSHOT: show_snapshot_window(1); break;
        case TOPGEAR_MAC_COMMAND_LOAD_SNAPSHOT: show_snapshot_window(0); break;
        case TOPGEAR_MAC_COMMAND_SCREENSHOT: capture_screenshot(); break;
        case TOPGEAR_MAC_COMMAND_SHOW_DATA_FOLDER: show_data_folder(); break;
        case TOPGEAR_MAC_COMMAND_SETTINGS: show_settings(); break;
        case TOPGEAR_MAC_COMMAND_CONTROLS: show_controls(); break;
        case TOPGEAR_MAC_COMMAND_AUDIO_SETTINGS: show_audio_settings(); break;
        case TOPGEAR_MAC_COMMAND_PROFILE: show_profile(); break;
        case TOPGEAR_MAC_COMMAND_LEADERBOARD: show_leaderboard(); break;
        case TOPGEAR_MAC_COMMAND_FULLSCREEN_ON_PLAY:
            g_settings.fullscreen_on_play = !g_settings.fullscreen_on_play;
            save_settings();
            break;
        case TOPGEAR_MAC_COMMAND_AUTO_RUN:
            g_settings.auto_run_on_load = !g_settings.auto_run_on_load;
            save_settings();
            break;
        case TOPGEAR_MAC_COMMAND_WELCOME: show_welcome(); break;
        case TOPGEAR_MAC_COMMAND_ABOUT: show_about(); break;
        default: break;
    }
}

/* Menu actions arrive inside SDL's event pump; queue them so dialogs run
   from the main loop rather than re-entrantly. */
static void post_command(int command) {
    SDL_Event event;
    SDL_zero(event);
    event.type = g_command_event;
    event.user.code = command;
    (void)SDL_PushEvent(&event);
}

/* ------------------------------------------------------------------ */
/* Events                                                              */
/* ------------------------------------------------------------------ */

static void handle_key_down(const SDL_KeyboardEvent *key) {
    uint16_t mask;
    if (key->mod & SDL_KMOD_GUI) return;
    switch (key->scancode) {
        case SDL_SCANCODE_ESCAPE:
            if (!key->repeat) execute_command(TOPGEAR_MAC_COMMAND_PAUSE_PLAY);
            return;
        /* The menu normally consumes these; this path covers keys the menu
           bar passes through. */
        case SDL_SCANCODE_F1: execute_command(TOPGEAR_MAC_COMMAND_WELCOME); return;
        case SDL_SCANCODE_F2: execute_command(TOPGEAR_MAC_COMMAND_SAVE_SNAPSHOT); return;
        case SDL_SCANCODE_F3: execute_command(TOPGEAR_MAC_COMMAND_LOAD_SNAPSHOT); return;
        case SDL_SCANCODE_F4: execute_command(TOPGEAR_MAC_COMMAND_SETTINGS); return;
        case SDL_SCANCODE_F5: execute_command(TOPGEAR_MAC_COMMAND_CONTROLS); return;
        case SDL_SCANCODE_F6: execute_command(TOPGEAR_MAC_COMMAND_AUDIO_SETTINGS); return;
        case SDL_SCANCODE_F7: execute_command(TOPGEAR_MAC_COMMAND_RUN); return;
        case SDL_SCANCODE_F8: execute_command(TOPGEAR_MAC_COMMAND_SCREENSHOT); return;
        case SDL_SCANCODE_1:
            if (!key->repeat) execute_command(TOPGEAR_MAC_COMMAND_SAVE_CURRENT_SNAPSHOT);
            return;
        case SDL_SCANCODE_2:
            if (!key->repeat) execute_command(TOPGEAR_MAC_COMMAND_LOAD_CURRENT_SNAPSHOT);
            return;
        default: break;
    }
    if (!g_game || g_paused || gamepad_gameplay_active()) return;
    mask = key_to_input(key->scancode);
    if (mask)
        topgear_input_latch_press(&g_keyboard_input, mask,
                                  opposite_direction(mask), key->repeat);
}

static void handle_event(const SDL_Event *event) {
    if (event->type == g_command_event) {
        execute_command(event->user.code);
        return;
    }
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
            if (g_settings.pause_on_focus_loss && g_game && !g_paused &&
                !topgear_mac_ui_modal_active())
                pause_game("Paused because the launcher lost keyboard focus.");
            break;
        case SDL_EVENT_DROP_FILE:
            if (event->drop.data && !g_game) select_rom(event->drop.data, 1);
            else if (event->drop.data)
                set_status("Top Gear is already loaded. Quit and reopen the app to change the ROM.");
            break;
        case SDL_EVENT_GAMEPAD_ADDED:
            if (!g_gamepad && current_gamepad())
                set_status("Gamepad connected: %s", SDL_GetGamepadName(g_gamepad));
            break;
        case SDL_EVENT_GAMEPAD_REMOVED:
            if (g_gamepad && SDL_GetGamepadID(g_gamepad) == event->gdevice.which) {
                SDL_CloseGamepad(g_gamepad);
                g_gamepad = NULL;
                set_status("Gamepad disconnected.");
                (void)current_gamepad();
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
            /* Unlocked: audio remains the safety throttle so a benchmark
               cannot overwrite queued PCM. */
            if (topgear_mac_audio_output_is_open(&g_audio) && g_audio.playing &&
                topgear_mac_audio_output_queued_frames(&g_audio) >
                    g_audio.target_latency_frames +
                    (uint32_t)(g_audio.device_sample_rate / 30)) {
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
    topgear_mac_audio_output_pause(&g_audio);
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
    topgear_mac_audio_output_initialize(&g_audio);
    if (!topgear_mac_settings_load(&g_settings, g_settings_path))
        save_settings();
    if (join_path(mappings, sizeof(mappings), g_resources_directory,
                  "gamecontrollerdb.txt") && path_is_file(mappings))
        (void)SDL_AddGamepadMappingsFromFile(mappings);
    g_command_event = SDL_RegisterEvents(1);

    if (!SDL_CreateWindowAndRenderer(APP_TITLE, 1024, 820,
                                     SDL_WINDOW_RESIZABLE |
                                     SDL_WINDOW_HIGH_PIXEL_DENSITY,
                                     &g_window, &g_renderer)) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, APP_TITLE,
                                 SDL_GetError(), NULL);
        SDL_Quit();
        return 1;
    }
    SDL_SetWindowMinimumSize(g_window, 512, 448);
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
    topgear_mac_ui_install_menus(post_command, validate_command);
    /* Device discovery does not choose the input source; the keyboard stays
       active until Gamepad is selected in Controller Bindings. */
    (void)current_gamepad();

    /* A ROM passed on the command line wins, then the remembered path, then
       the first .sfc in the Rom folder. */
    if (argc > 1 && path_is_file(argv[1]))
        (void)snprintf(g_selected_rom, sizeof(g_selected_rom), "%s", argv[1]);
    else if (path_is_file(g_settings.rom_path))
        (void)snprintf(g_selected_rom, sizeof(g_selected_rom), "%s",
                       g_settings.rom_path);
    else
        (void)find_sfc_rom(g_selected_rom, sizeof(g_selected_rom));
    present();

    if (!g_settings.welcome_shown) {
        topgear_mac_ui_information("Welcome",
                                   "Welcome to Top Gear (SNES) Static Recompilation",
                                   k_welcome_text);
        g_settings.welcome_shown = 1;
        if (!topgear_mac_settings_save(&g_settings, g_settings_path)) {
            g_settings.welcome_shown = 0;
            set_status("Welcome closed, but its one-time setting could not be saved; it will appear again next launch.");
        }
    }
    if (g_selected_rom[0]) {
        if (g_settings.auto_run_on_load) {
            set_status("ROM found. Loading and starting Top Gear.");
            start_rom_load(1);
        } else {
            set_status("ROM found. Choose Run or press F7 to start.");
        }
    } else {
        set_status("Choose File > Open ROM to select the required Top Gear ROM.");
    }

    run_loop();
    shutdown_launcher();
    return 0;
}
