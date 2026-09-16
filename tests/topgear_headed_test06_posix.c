#include "topgear_headed_test06_posix.h"

#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

enum {
    FRAME_BYTES = 256 * 224 * 2,
    SETUP_RACE_START_FRAME = 5640,
    MAX_CAMPAIGN_FRAMES = 60000,
    RESULTS_STABLE_FRAMES = 120,
    POST_COUNTRY_FRAMES = 3600,
    P1_PLACE_OFFSET = 0x011A,
    P1_LAP_OFFSET = 0x011E,
    CPU_PLACE_OFFSET = 0x012C,
    CPU_LAP_OFFSET = 0x0130,
    P1_SPEED_OFFSET = 0x1E5A,
    P1_POINTS_OFFSET = 0x1F4E,
    FINISH_ORDER_OFFSET = 0x1F62
};

typedef struct InputEvent {
    uint32_t frame;
    uint16_t mask;
} InputEvent;

typedef struct RaceState {
    unsigned place;
    unsigned cpu_place;
    unsigned laps;
    unsigned max_mph;
    unsigned boosts;
    unsigned traffic_frames;
    unsigned avoidance_events;
    unsigned missing_road_frames;
    unsigned points;
    unsigned finish_order[10];
    uint32_t race_frames;
} RaceState;

typedef struct Driver {
    int steer;
    int avoid_direction;
    unsigned avoid_frames;
    unsigned missing_road_frames;
    unsigned missing_road_total;
    unsigned traffic_frames;
    unsigned avoidance_events;
    unsigned max_mph;
    unsigned boost_frames;
    unsigned boost_count;
    unsigned boost_used_lap[3];
    unsigned lap_straight_frames;
    unsigned prior_lap;
    uint32_t race_frame;
} Driver;

typedef enum TestPhase {
    PHASE_SETUP,
    PHASE_RACE,
    PHASE_RESULTS,
    PHASE_TRANSITION,
    PHASE_POST_COUNTRY
} TestPhase;

typedef struct HeadedTest06 {
    int active;
    TestPhase phase;
    Driver driver;
    RaceState races[4];
    wchar_t output_directory[4096];
    wchar_t report_path[4096];
    uint64_t prior_hash;
    size_t next_event;
    uint16_t setup_mask;
    unsigned stable_frames;
    unsigned race_index;
    unsigned transition_frame;
    unsigned post_frame;
    uint32_t global_frame;
} HeadedTest06;

static HeadedTest06 g_test;

static const wchar_t *const track_names[4] = {
    L"Las Vegas", L"Los Angeles", L"New York", L"San Francisco"
};

static const unsigned track_laps[4] = {3u, 3u, 3u, 6u};

static const InputEvent setup_events[] = {
    {0u, 0u},
    {1560u, TOPGEAR_INPUT_START}, {1680u, 0u},
    /* Stage-1 remodel: root defaults to CAREER, then Career defaults to the
       existing player setup semantic action. */
    {1980u, TOPGEAR_INPUT_A}, {2010u, 0u},
    {2040u, TOPGEAR_INPUT_A}, {2100u, 0u},
    {2280u, TOPGEAR_INPUT_DOWN}, {2295u, 0u},
    {2310u, TOPGEAR_INPUT_DOWN}, {2325u, 0u},
    {2340u, TOPGEAR_INPUT_DOWN}, {2355u, 0u},
    {2370u, TOPGEAR_INPUT_DOWN}, {2385u, 0u},
    {2400u, TOPGEAR_INPUT_RIGHT}, {2415u, 0u},
    {2430u, TOPGEAR_INPUT_RIGHT}, {2445u, 0u},
    {2460u, TOPGEAR_INPUT_RIGHT}, {2475u, 0u},
    {2490u, TOPGEAR_INPUT_RIGHT}, {2505u, 0u},
    {2550u, TOPGEAR_INPUT_A}, {2595u, 0u},
    {2850u, TOPGEAR_INPUT_RIGHT}, {2865u, 0u},
    {2910u, TOPGEAR_INPUT_A}, {2970u, 0u},
    {3270u, TOPGEAR_INPUT_A}, {3330u, 0u},
    /* White Sidewinder: its low fuel use is required for all four races. */
    {3540u, TOPGEAR_INPUT_DOWN}, {3555u, 0u},
    {3630u, TOPGEAR_INPUT_A}, {3690u, 0u},
    /* Returned Career menu has four rows; START is three Down presses from
       PLAYER instead of the old OPTIONS menu's four presses to PLAY GAME. */
    {4020u, TOPGEAR_INPUT_DOWN}, {4035u, 0u},
    {4050u, TOPGEAR_INPUT_DOWN}, {4065u, 0u},
    {4080u, TOPGEAR_INPUT_DOWN}, {4095u, 0u},
    {4170u, TOPGEAR_INPUT_A}, {4230u, 0u}
};

static void copy_wide(wchar_t *output, size_t capacity,
                      const wchar_t *input) {
    if (!output || capacity == 0u) return;
    if (!input) input = L"";
    (void)wcsncpy(output, input, capacity - 1u);
    output[capacity - 1u] = L'\0';
}

static uint16_t read_le16(const uint8_t *data, unsigned offset) {
    return (uint16_t)(data[offset] | ((uint16_t)data[offset + 1u] << 8u));
}

static uint64_t fnv1a64(const void *data, size_t bytes) {
    const uint8_t *input = (const uint8_t *)data;
    uint64_t hash = UINT64_C(1469598103934665603);
    size_t index;
    for (index = 0u; index < bytes; ++index) {
        hash ^= input[index];
        hash *= UINT64_C(1099511628211);
    }
    return hash;
}

static int wide_to_utf8(const wchar_t *wide, char *utf8, size_t capacity) {
    size_t converted;
    if (!wide || !utf8 || capacity == 0u) return 0;
    converted = wcstombs(utf8, wide, capacity - 1u);
    if (converted == (size_t)-1) {
        utf8[0] = '\0';
        return 0;
    }
    utf8[converted] = '\0';
    return 1;
}

static int ensure_directory(const wchar_t *path) {
    char utf8[8192];
    char work[8192];
    size_t index;
    struct stat st;
    if (!wide_to_utf8(path, utf8, sizeof(utf8))) return 0;
    if (strlen(utf8) >= sizeof(work)) return 0;
    (void)strcpy(work, utf8);
    for (index = 1u; work[index]; ++index) {
        if (work[index] == '/') {
            char saved = work[index];
            work[index] = '\0';
            if (stat(work, &st) != 0) {
                if (mkdir(work, 0777) != 0 && errno != EEXIST) return 0;
            } else if (!S_ISDIR(st.st_mode)) {
                return 0;
            }
            work[index] = saved;
        }
    }
    if (stat(work, &st) == 0) return S_ISDIR(st.st_mode);
    return mkdir(work, 0777) == 0 || errno == EEXIST;
}

static int road_center(const uint8_t *frame, int *samples,
                       unsigned row_first, unsigned row_last) {
    unsigned x;
    unsigned y;
    int64_t weighted_x = 0;
    int64_t total = 0;
    int count = 0;
    for (y = row_first; y <= row_last; y += 2u) {
        int weight = 1 + (int)(y - row_first) / 10;
        for (x = 0u; x < 238u; ++x) {
            size_t offset = ((size_t)y * 256u + x) * 2u;
            uint16_t colour = (uint16_t)(frame[offset] |
                ((uint16_t)frame[offset + 1u] << 8u));
            int red = colour & 31u;
            int green = (colour >> 5u) & 31u;
            int blue = (colour >> 10u) & 31u;
            int low = red < green ? (red < blue ? red : blue) :
                                    (green < blue ? green : blue);
            int high = red > green ? (red > blue ? red : blue) :
                                     (green > blue ? green : blue);
            if (red >= 5 && red <= 14 && green >= 5 && green <= 15 &&
                blue >= 5 && blue <= 15 && high - low <= 4) {
                weighted_x += (int64_t)x * weight;
                total += weight;
                ++count;
            }
        }
    }
    *samples = count;
    return total ? (int)(weighted_x / total) : -1;
}

/* OAM entries 3-14 are P1's composite car on the proven one-player route. */
static int traffic_ahead(TopGearRecomp *core, int *traffic_x) {
    uint8_t oam[544];
    unsigned index;
    unsigned found = 0u;
    int x_total = 0;
    *traffic_x = 124;
    if (!topgear_recomp_v07_read_oam(core, 0u, oam, sizeof(oam))) return -1;
    for (index = 0u; index < 128u; ++index) {
        unsigned high = oam[512u + index / 4u];
        unsigned shift = (index % 4u) * 2u;
        int x = (int)oam[index * 4u] +
                (int)(((high >> shift) & 1u) * 256u);
        int y = (int)oam[index * 4u + 1u];
        int half_width = ((high >> (shift + 1u)) & 1u) ? 8 : 4;
        int object_center;
        if (index >= 3u && index <= 14u) continue;
        if (x >= 256) x -= 512;
        object_center = x + half_width;
        if (y >= 34 && y <= 67 && object_center >= 92 &&
            object_center <= 156) {
            x_total += object_center;
            ++found;
        }
    }
    if (found) *traffic_x = x_total / (int)found;
    return found != 0u;
}

static uint16_t driver_input(TopGearRecomp *core, Driver *driver,
                             const uint8_t *wram, const uint8_t *frame,
                             unsigned race_index) {
    int samples = 0;
    unsigned row_first = race_index == 2u ? 55u : 40u;
    unsigned row_last = race_index == 2u ? 90u : 70u;
    int low_threshold = race_index == 2u ? 108 : 119;
    int high_threshold = race_index == 2u ? 148 : 137;
    int center = road_center(frame, &samples, row_first, row_last);
    int traffic_x = 124;
    int traffic;
    unsigned lap = wram[P1_LAP_OFFSET];
    uint16_t mask = TOPGEAR_INPUT_X;
    int raw_speed = (int)(int16_t)read_le16(wram, P1_SPEED_OFFSET);
    unsigned mph = raw_speed > 0 ? ((unsigned)raw_speed * 15u) >> 10u : 0u;
    if (mph > driver->max_mph) driver->max_mph = mph;
    if (center >= 0 && samples >= 24) {
        if (center < low_threshold) driver->steer = -1;
        else if (center > high_threshold) driver->steer = 1;
        else driver->steer = 0;
        driver->missing_road_frames = 0u;
    } else {
        ++driver->missing_road_frames;
        ++driver->missing_road_total;
        if ((driver->missing_road_frames % 120u) == 0u)
            driver->steer = -driver->steer;
        if (!driver->steer)
            driver->steer = (driver->missing_road_frames / 120u) & 1u ? 1 : -1;
    }
    traffic = race_index < 2u ? traffic_ahead(core, &traffic_x) : 0;
    if (traffic > 0) {
        ++driver->traffic_frames;
        if (!driver->avoid_frames) {
            driver->avoid_direction = traffic_x < 124 ? 1 : -1;
            driver->avoid_frames = 18u;
            ++driver->avoidance_events;
        } else if (driver->avoid_frames < 8u) {
            driver->avoid_frames = 8u;
        }
    }
    if (driver->avoid_frames) {
        if (center >= 0 && center < 108) driver->steer = -1;
        else if (center > 148) driver->steer = 1;
        else driver->steer = driver->avoid_direction;
        --driver->avoid_frames;
    }
    if (driver->steer < 0) mask = (uint16_t)(mask | TOPGEAR_INPUT_LEFT);
    if (driver->steer > 0) mask = (uint16_t)(mask | TOPGEAR_INPUT_RIGHT);

    if (lap != driver->prior_lap) {
        driver->prior_lap = lap;
        driver->lap_straight_frames = 0u;
    }
    if (race_index == 0u || race_index == 2u || race_index == 3u) {
        static const unsigned short_windows[3] = {1488u, 2378u, 2995u};
        static const unsigned new_york_windows[3] = {1500u, 4500u, 7500u};
        const unsigned *windows = race_index == 2u ?
                                  new_york_windows : short_windows;
        if (!driver->boost_frames && driver->boost_count < 3u &&
            driver->race_frame >= windows[driver->boost_count] && traffic <= 0) {
            driver->boost_used_lap[driver->boost_count] = lap + 1u;
            ++driver->boost_count;
            driver->boost_frames = 12u;
        }
    } else if (driver->boost_count < 3u && lap < 3u) {
        if (center >= 118 && center <= 132 && samples >= 500 && traffic <= 0 &&
            !driver->avoid_frames) ++driver->lap_straight_frames;
        else driver->lap_straight_frames = 0u;
        if (!driver->boost_frames && !driver->boost_used_lap[lap] &&
            driver->race_frame >= 480u && driver->lap_straight_frames >= 12u) {
            driver->boost_used_lap[lap] = lap + 1u;
            ++driver->boost_count;
            driver->boost_frames = 12u;
        }
    }
    if (driver->boost_frames) {
        mask = (uint16_t)(mask | TOPGEAR_INPUT_A);
        --driver->boost_frames;
    }
    ++driver->race_frame;
    return mask;
}

static void make_output_directory(const wchar_t *executable_directory) {
    struct timespec now;
    struct tm local;
    unsigned milliseconds = 0u;
    (void)clock_gettime(CLOCK_REALTIME, &now);
    if (localtime_r(&now.tv_sec, &local) == NULL) memset(&local, 0, sizeof(local));
    if (now.tv_nsec > 0) milliseconds = (unsigned)(now.tv_nsec / 1000000L);
    (void)swprintf(g_test.output_directory,
        sizeof(g_test.output_directory) / sizeof(g_test.output_directory[0]),
        L"%ls/Test Results/USA-Campaign-%04u%02u%02u-%02u%02u%02u-%03u-%lu",
        executable_directory, (unsigned)(local.tm_year + 1900),
        (unsigned)(local.tm_mon + 1), (unsigned)local.tm_mday,
        (unsigned)local.tm_hour, (unsigned)local.tm_min,
        (unsigned)local.tm_sec, milliseconds, (unsigned long)getpid());
    g_test.output_directory[
        (sizeof(g_test.output_directory) / sizeof(g_test.output_directory[0])) - 1u] = L'\0';
    (void)ensure_directory(g_test.output_directory);
}

static int save_snapshot(TopGearRecomp *core, unsigned race_number) {
    wchar_t wide_path[4096];
    char utf8_path[8192];
    char error[256];
    (void)swprintf(wide_path, sizeof(wide_path) / sizeof(wide_path[0]),
                     L"%ls/Race-%u-results.scsnap",
                     g_test.output_directory, race_number);
    wide_path[(sizeof(wide_path) / sizeof(wide_path[0])) - 1u] = L'\0';
    if (!wide_to_utf8(wide_path, utf8_path, sizeof(utf8_path))) return 0;
    return topgear_recomp_snapshot_save(core, utf8_path, error, sizeof(error));
}

static int write_report(TopGearRecomp *core) {
    TopGearStaticAudioStatus audio;
    FILE *file;
    unsigned race_index;
    (void)swprintf(g_test.report_path,
        sizeof(g_test.report_path) / sizeof(g_test.report_path[0]),
        L"%ls/Test-1-results.txt", g_test.output_directory);
    g_test.report_path[
        (sizeof(g_test.report_path) / sizeof(g_test.report_path[0])) - 1u] = L'\0';
    {
        char utf8_path[8192];
        if (!wide_to_utf8(g_test.report_path, utf8_path, sizeof(utf8_path))) return 0;
        file = fopen(utf8_path, "wb");
    }
    if (!file) return 0;
    memset(&audio, 0, sizeof(audio));
    (void)topgear_recomp_static_audio_status(core, &audio);
    (void)fprintf(file,
        "Top Gear (SNES) - Temporary Headed Test 1 - USA Campaign\r\n"
        "Car: Sidewinder (white; low fuel use)\r\n"
        "Transmission: automatic\r\n"
        "Input: controller port 1 only; no memory patches\r\n"
        "Presentation: normal headed video and Full Static audio\r\n\r\n");
    for (race_index = 0u; race_index < 4u; ++race_index) {
        const RaceState *race = &g_test.races[race_index];
        unsigned order;
        (void)fprintf(file,
            "Race %u - %ls\r\nPlace: %u\r\nCPU rival: %u\r\nLaps: %u\r\n"
            "Maximum speed: %u mph\r\nBoosts: %u\r\nRace frames: %u\r\n"
            "Traffic frames: %u\r\nAvoidance events: %u\r\n"
            "Points total: %u\r\nTop 10 racer IDs:",
            race_index + 1u, track_names[race_index], race->place,
            race->cpu_place, race->laps, race->max_mph, race->boosts,
            race->race_frames, race->traffic_frames, race->avoidance_events,
            race->points);
        for (order = 0u; order < 10u; ++order)
            (void)fprintf(file, " %u", race->finish_order[order]);
        (void)fprintf(file, "\r\n\r\n");
    }
    (void)fprintf(file,
        "Post-USA observation: %u frames (60 seconds) after fourth results\r\n"
        "Final frame FNV-1a64: %016llX\r\n"
        "Static audio AOT failures: %u\r\nStatic DSP failures: %u\r\n"
        "Automatic fallback enabled: %u\r\n",
        POST_COUNTRY_FRAMES, (unsigned long long)g_test.prior_hash,
        audio.aot_failed, audio.sdsp_static_failed,
        audio.automatic_fallback_enabled);
    return fclose(file) == 0;
}

void topgear_headed_test06_begin(const wchar_t *executable_directory) {
    memset(&g_test, 0, sizeof(g_test));
    g_test.active = 1;
    g_test.phase = PHASE_SETUP;
    make_output_directory(executable_directory);
}

void topgear_headed_test06_cancel(void) {
    g_test.active = 0;
}

int topgear_headed_test06_active(void) {
    return g_test.active;
}

uint16_t topgear_headed_test06_input(TopGearRecomp *core) {
    uint8_t wram[TOPGEAR_RECOMP_WRAM_SIZE];
    uint8_t frame[FRAME_BYTES];
    uint16_t mask = 0u;
    if (!g_test.active || !core) return 0u;
    if (!topgear_recomp_read_wram(core, 0u, wram, sizeof(wram)) ||
        !topgear_recomp_v22_read_frame_bgr555(core, 0u, frame, sizeof(frame)))
        return 0u;
    if (g_test.phase == PHASE_SETUP) {
        while (g_test.next_event <
               sizeof(setup_events) / sizeof(setup_events[0]) &&
               setup_events[g_test.next_event].frame <= g_test.global_frame) {
            g_test.setup_mask = setup_events[g_test.next_event].mask;
            ++g_test.next_event;
        }
        mask = g_test.setup_mask;
        if (g_test.global_frame >= SETUP_RACE_START_FRAME)
            g_test.phase = PHASE_RACE;
    }
    if (g_test.phase == PHASE_RACE)
        mask = driver_input(core, &g_test.driver, wram, frame,
                            g_test.race_index);
    else if (g_test.phase == PHASE_TRANSITION) {
        if ((g_test.transition_frame >= 120u &&
             g_test.transition_frame < 132u) ||
            (g_test.transition_frame >= 600u &&
             g_test.transition_frame < 612u))
            mask = TOPGEAR_INPUT_A;
        ++g_test.transition_frame;
    } else if (g_test.phase == PHASE_POST_COUNTRY) {
        if (g_test.post_frame >= 120u &&
            ((g_test.post_frame - 120u) % 480u) < 12u)
            mask = TOPGEAR_INPUT_A;
    }
    return mask;
}

int topgear_headed_test06_after_frame(TopGearRecomp *core,
                                     wchar_t *message,
                                     size_t message_capacity,
                                     wchar_t *report_path,
                                     size_t report_path_capacity) {
    uint8_t wram[TOPGEAR_RECOMP_WRAM_SIZE];
    uint8_t frame[FRAME_BYTES];
    uint64_t hash;
    if (message && message_capacity) message[0] = L'\0';
    if (report_path && report_path_capacity) report_path[0] = L'\0';
    if (!g_test.active || !core) return 0;
    if (!topgear_recomp_read_wram(core, 0u, wram, sizeof(wram)) ||
        !topgear_recomp_v22_read_frame_bgr555(core, 0u, frame, sizeof(frame))) {
        copy_wide(message, message_capacity,
                  L"Test 1 stopped because static state could not be read.");
        g_test.active = 0;
        return -1;
    }
    hash = fnv1a64(frame, sizeof(frame));
    if (hash == g_test.prior_hash) ++g_test.stable_frames;
    else g_test.stable_frames = 0u;
    g_test.prior_hash = hash;

    if (g_test.phase == PHASE_RACE && g_test.driver.race_frame >= 3000u &&
        (wram[P1_LAP_OFFSET] >= track_laps[g_test.race_index] ||
         wram[CPU_LAP_OFFSET] >= track_laps[g_test.race_index]) &&
        g_test.stable_frames >= RESULTS_STABLE_FRAMES) {
        RaceState *race = &g_test.races[g_test.race_index];
        unsigned order;
        race->place = (unsigned)wram[P1_PLACE_OFFSET] + 1u;
        race->cpu_place = (unsigned)wram[CPU_PLACE_OFFSET] + 1u;
        race->laps = (unsigned)wram[P1_LAP_OFFSET];
        race->max_mph = g_test.driver.max_mph;
        race->boosts = g_test.driver.boost_count;
        race->traffic_frames = g_test.driver.traffic_frames;
        race->avoidance_events = g_test.driver.avoidance_events;
        race->missing_road_frames = g_test.driver.missing_road_total;
        race->points = wram[P1_POINTS_OFFSET];
        race->race_frames = g_test.driver.race_frame - g_test.stable_frames;
        for (order = 0u; order < 10u; ++order)
            race->finish_order[order] = wram[FINISH_ORDER_OFFSET + order];
        (void)save_snapshot(core, g_test.race_index + 1u);
        if (race->place > 5u) {
            (void)swprintf(message, message_capacity,
                L"Test 1 stopped: race %u, %s, finished %u and did not qualify.",
                g_test.race_index + 1u, track_names[g_test.race_index],
                race->place);
            if (message && message_capacity) message[message_capacity - 1u] = L'\0';
            g_test.active = 0;
            return -1;
        }
        if (g_test.race_index == 3u) {
            g_test.phase = PHASE_POST_COUNTRY;
            g_test.post_frame = 0u;
        } else {
            g_test.phase = PHASE_TRANSITION;
            g_test.transition_frame = 0u;
        }
        g_test.stable_frames = 0u;
    } else if (g_test.phase == PHASE_TRANSITION &&
               g_test.transition_frame > 900u &&
               wram[P1_LAP_OFFSET] == 0u &&
               (unsigned)wram[P1_PLACE_OFFSET] + 1u >= 10u) {
        ++g_test.race_index;
        memset(&g_test.driver, 0, sizeof(g_test.driver));
        g_test.phase = PHASE_RACE;
        g_test.stable_frames = 0u;
    } else if (g_test.phase == PHASE_POST_COUNTRY) {
        ++g_test.post_frame;
        if (g_test.post_frame >= POST_COUNTRY_FRAMES) {
            int report_ok = write_report(core);
            g_test.active = 0;
            copy_wide(report_path, report_path_capacity, g_test.report_path);
            copy_wide(message, message_capacity,
                report_ok ?
                L"Test 1 completed all four USA races and the 60-second post-country check." :
                L"Test 1 completed all four USA races, but its text report could not be written.");
            return 1;
        }
    }
    ++g_test.global_frame;
    if (g_test.global_frame >= MAX_CAMPAIGN_FRAMES) {
        copy_wide(message, message_capacity,
                  L"Test 1 stopped after reaching its maximum frame limit.");
        g_test.active = 0;
        return -1;
    }
    return 0;
}
