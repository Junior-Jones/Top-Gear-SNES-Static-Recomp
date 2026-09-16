#include "topgear_rally_eight_race_posix.h"

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
    MAX_CAMPAIGN_FRAMES = 180000,
    RESULTS_STABLE_FRAMES = 120,
    P1_PLACE_OFFSET = 0x011A,
    P1_LAP_OFFSET = 0x011E,
    CPU_PLACE_OFFSET = 0x012C,
    CPU_LAP_OFFSET = 0x0130,
    COURSE_LAPS_OFFSET = 0x1E56,
    P1_SPEED_OFFSET = 0x1E5A,
    POINTS_TABLE_OFFSET = 0x1F4E,
    FINISH_ORDER_OFFSET = 0x1F62
};


typedef struct InputEvent {
    uint32_t frame;
    uint16_t mask;
} InputEvent;

typedef struct RaceState {
    unsigned course_ordinal;
    unsigned required_laps;
    unsigned place;
    unsigned cpu_place;
    unsigned laps;
    unsigned max_mph;
    unsigned boosts;
    unsigned traffic_frames;
    unsigned avoidance_events;
    unsigned missing_road_frames;
    unsigned points;
    unsigned points_sum;
    unsigned points_table[20];
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
    PHASE_WAIT_FIRST_BRIEFING,
    PHASE_RACE,
    PHASE_TRANSITION,
    PHASE_WAIT_NEXT_RACE_START,
    PHASE_FINAL_TRANSITION,
    PHASE_QUALIFICATION_FAIL,
    PHASE_WAIT_MENU
} TestPhase;


typedef struct RallyEightRace {
    int active;
    TestPhase phase;
    Driver driver;
    RaceState races[8];
    wchar_t output_directory[4096];
    wchar_t report_path[4096];
    wchar_t schedule_snapshot_path[4096];
    uint64_t prior_hash;
    size_t next_event;
    uint16_t setup_mask;
    unsigned stable_frames;
    unsigned race_index;
    unsigned transition_frame;
    unsigned phase_frame;
    unsigned snapshot_reloaded;
    unsigned race_live_seen;
    unsigned final_standings_saved;
    unsigned returned_menu_saved;
    unsigned qualification_failed;
    unsigned qualification_cutoff;
    unsigned qualification_fail_screen_saved;
    uint8_t prerace_saved[8];
    uint8_t points_recorded[8];
    uint8_t schedule[8];
    uint32_t global_frame;
} RallyEightRace;

static RallyEightRace g_test;

static const wchar_t *const track_names[32] = {
    L"Las Vegas", L"Los Angeles", L"New York", L"San Francisco",
    L"Rio", L"Machu Picchu", L"Chichen Itza", L"Rain Forest",
    L"Tokyo", L"Hiroshima", L"Yokohama", L"Kyoto",
    L"Munich", L"Cologne", L"Black Forest", L"Frankfurt",
    L"Stockholm", L"Copenhagen", L"Helsinki", L"Oslo",
    L"Paris", L"Nice", L"Bordeaux", L"Monaco",
    L"Pisa", L"Rome", L"Sicily", L"Florence",
    L"London", L"Sheffield", L"Loch Ness", L"Stonehenge"
};

static const InputEvent setup_events[] = {
    {0u, 0u},
    {1560u, TOPGEAR_INPUT_START}, {1680u, 0u},
    /* Root: move from CAREER to RALLY, then enter Rally. */
    {1920u, TOPGEAR_INPUT_DOWN}, {1935u, 0u},
    {1965u, TOPGEAR_INPUT_A}, {1995u, 0u},
    /* Rally PLAYER row: enter the original one-player configuration. */
    {2085u, TOPGEAR_INPUT_A}, {2130u, 0u},
    /* Name entry: move to END exactly as the mature four-race route does. */
    {2340u, TOPGEAR_INPUT_DOWN}, {2355u, 0u},
    {2370u, TOPGEAR_INPUT_DOWN}, {2385u, 0u},
    {2400u, TOPGEAR_INPUT_DOWN}, {2415u, 0u},
    {2430u, TOPGEAR_INPUT_DOWN}, {2445u, 0u},
    {2460u, TOPGEAR_INPUT_RIGHT}, {2475u, 0u},
    {2490u, TOPGEAR_INPUT_RIGHT}, {2505u, 0u},
    {2520u, TOPGEAR_INPUT_RIGHT}, {2535u, 0u},
    {2550u, TOPGEAR_INPUT_RIGHT}, {2565u, 0u},
    {2610u, TOPGEAR_INPUT_A}, {2655u, 0u},
    /* Automatic gearbox, TYPE A controls, then white Sidewinder. */
    {2850u, TOPGEAR_INPUT_RIGHT}, {2865u, 0u},
    {2910u, TOPGEAR_INPUT_A}, {2970u, 0u},
    {3270u, TOPGEAR_INPUT_A}, {3330u, 0u},
    {3540u, TOPGEAR_INPUT_DOWN}, {3555u, 0u},
    {3630u, TOPGEAR_INPUT_A}, {3690u, 0u},
    /* Back on Rally: open Skill Level, accept Amateur, then Start. */
    {4020u, TOPGEAR_INPUT_DOWN}, {4035u, 0u},
    {4080u, TOPGEAR_INPUT_A}, {4125u, 0u},
    {4365u, TOPGEAR_INPUT_A}, {4410u, 0u},
    {4635u, TOPGEAR_INPUT_DOWN}, {4650u, 0u},
    {4710u, TOPGEAR_INPUT_A}, {4755u, 0u}
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
                             unsigned course_ordinal) {
    unsigned local = course_ordinal & 3u;
    int samples = 0;
    unsigned row_first = local == 2u ? 55u : 40u;
    unsigned row_last = local == 2u ? 90u : 70u;
    int low_threshold = local == 2u ? 108 : 119;
    int high_threshold = local == 2u ? 148 : 137;
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
    /* Preserve the four-race traffic policy by modulo-four course slot. */
    traffic = local < 2u ? traffic_ahead(core, &traffic_x) : 0;
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
    if (local == 0u || local == 2u || local == 3u) {
        static const unsigned short_windows[3] = {1488u, 2378u, 2995u};
        static const unsigned slot2_windows[3] = {1500u, 4500u, 7500u};
        const unsigned *windows = local == 2u ? slot2_windows : short_windows;
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
        L"%ls/Test Results/Rally-8-%04u%02u%02u-%02u%02u%02u-%03u-%lu",
        executable_directory, (unsigned)(local.tm_year + 1900),
        (unsigned)(local.tm_mon + 1), (unsigned)local.tm_mday,
        (unsigned)local.tm_hour, (unsigned)local.tm_min,
        (unsigned)local.tm_sec, milliseconds, (unsigned long)getpid());
    g_test.output_directory[
        (sizeof(g_test.output_directory) / sizeof(g_test.output_directory[0])) - 1u] = L'\0';
    (void)ensure_directory(g_test.output_directory);
}

static int save_snapshot_named(TopGearRecomp *core, const wchar_t *name,
                               wchar_t *saved_path, size_t saved_capacity) {
    wchar_t wide_path[4096];
    char utf8_path[8192];
    char error[256];
    (void)swprintf(wide_path, sizeof(wide_path) / sizeof(wide_path[0]),
                   L"%ls/%ls", g_test.output_directory, name);
    wide_path[(sizeof(wide_path) / sizeof(wide_path[0])) - 1u] = L'\0';
    if (!wide_to_utf8(wide_path, utf8_path, sizeof(utf8_path))) return 0;
    if (!topgear_recomp_snapshot_save(core, utf8_path, error, sizeof(error))) {
        fprintf(stderr, "rally-8: snapshot save failed: %s\n", error);
        return 0;
    }
    if (saved_path && saved_capacity) copy_wide(saved_path, saved_capacity, wide_path);
    return 1;
}

static int write_ppm(const wchar_t *name, const uint8_t *frame) {
    wchar_t wide_path[4096];
    char utf8_path[8192];
    FILE *file;
    unsigned x, y;
    (void)swprintf(wide_path, sizeof(wide_path) / sizeof(wide_path[0]),
                   L"%ls/%ls", g_test.output_directory, name);
    if (!wide_to_utf8(wide_path, utf8_path, sizeof(utf8_path))) return 0;
    file = fopen(utf8_path, "wb");
    if (!file) return 0;
    (void)fprintf(file, "P6\n256 224\n255\n");
    for (y = 0u; y < 224u; ++y) for (x = 0u; x < 256u; ++x) {
        size_t p = ((size_t)y * 256u + x) * 2u;
        uint16_t c = (uint16_t)(frame[p] | ((uint16_t)frame[p + 1u] << 8u));
        uint8_t rgb[3] = {
            (uint8_t)((c & 31u) * 255u / 31u),
            (uint8_t)(((c >> 5u) & 31u) * 255u / 31u),
            (uint8_t)(((c >> 10u) & 31u) * 255u / 31u)};
        if (fwrite(rgb, 1u, 3u, file) != 3u) { fclose(file); return 0; }
    }
    return fclose(file) == 0;
}

static int save_prerace_frame(const uint8_t *frame, unsigned race_index,
                              unsigned course) {
    wchar_t name[160];
    (void)swprintf(name, sizeof(name) / sizeof(name[0]),
                   L"Race-%u-pre-race-course-%02u.ppm", race_index + 1u, course);
    return write_ppm(name, frame);
}

static unsigned nonblack_pixels(const uint8_t *frame) {
    unsigned n, total = 0u;
    for (n = 0u; n < 256u * 224u; ++n) {
        if (frame[n * 2u] != 0u || frame[n * 2u + 1u] != 0u) ++total;
    }
    return total;
}

static unsigned points_sum(const uint8_t *wram) {
    unsigned n, total = 0u;
    for (n = 0u; n < 20u; ++n) total += wram[POINTS_TABLE_OFFSET + n];
    return total;
}

/* $1F26-$1F4D is the 20-racer finish-tick table.  A word remains $FFFF
   until that racer has a recorded finish time.  The original four-race
   test watched only one CPU lap byte, which is sufficient for its fixed
   USA route but not for arbitrary Rally courses: a different CPU can win
   first.  Use the game's own finish-time table plus a stable framebuffer
   to recognize the results screen for every scheduled track. */
static int any_racer_finished(const uint8_t *wram) {
    unsigned n;
    for (n = 0u; n < 20u; ++n)
        if (read_le16(wram, 0x1F26u + n * 2u) != UINT16_C(0xFFFF))
            return 1;
    return 0;
}

static int next_race_state_is_reset(const uint8_t *wram) {
    /* CPU finish-time slots are intentionally carried across parts of the
       transition, so they cannot all be required to return to $FFFF.  The
       new briefing is ready once the new course metadata exists, both live
       lap counters are reset, and the live race timer has restarted near 0. */
    if (read_le16(wram, COURSE_LAPS_OFFSET) == 0u) return 0;
    if (wram[P1_LAP_OFFSET] != 0u || wram[CPU_LAP_OFFSET] != 0u) return 0;
    if (read_le16(wram, 0x1EAEu) >= 120u) return 0;
    return 1;
}

static int write_report(TopGearRecomp *core) {
    TopGearStaticAudioStatus audio;
    FILE *file;
    unsigned race_index, n;
    (void)swprintf(g_test.report_path,
        sizeof(g_test.report_path) / sizeof(g_test.report_path[0]),
        L"%ls/RALLY-8-RESULTS.txt", g_test.output_directory);
    g_test.report_path[(sizeof(g_test.report_path) /
        sizeof(g_test.report_path[0])) - 1u] = L'\0';
    {
        char utf8_path[8192];
        if (!wide_to_utf8(g_test.report_path, utf8_path, sizeof(utf8_path))) return 0;
        file = fopen(utf8_path, "wb");
    }
    if (!file) return 0;
    memset(&audio, 0, sizeof(audio));
    (void)topgear_recomp_static_audio_status(core, &audio);
    (void)fprintf(file,
        "Top Gear (SNES) - Rally Eight-Race Qualification\r\n"
        "Car: Sidewinder (white; low fuel use)\r\n"
        "Transmission: automatic\r\n"
        "Input: controller port 1 only; no WRAM patches from test\r\n"
        "Rally schedule is generated by static-core mod logic, snapshotted, core-reset, then reloaded before race 1.\r\n\r\n"
        "Schedule ordinals:");
    for (n = 0u; n < 8u; ++n) (void)fprintf(file, " %u", (unsigned)g_test.schedule[n]);
    (void)fprintf(file, "\r\n\r\n");
    for (race_index = 0u; race_index < 8u; ++race_index) {
        const RaceState *race = &g_test.races[race_index];
        (void)fprintf(file,
            "Race %u - %ls (course %u)\r\nRequired laps: %u\r\n"
            "Place: %u\r\nCPU rival: %u\r\nPlayer laps: %u\r\n"
            "Maximum speed: %u mph\r\nBoosts: %u\r\nRace frames: %u\r\n"
            "Traffic frames: %u\r\nAvoidance events: %u\r\n"
            "Player cumulative points: %u\r\nAll-racer points sum: %u (expected %u)\r\n"
            "Points table:", race_index + 1u,
            track_names[race->course_ordinal], race->course_ordinal,
            race->required_laps, race->place, race->cpu_place, race->laps,
            race->max_mph, race->boosts, race->race_frames,
            race->traffic_frames, race->avoidance_events,
            race->points, race->points_sum, 81u * (race_index + 1u));
        for (n = 0u; n < 20u; ++n) (void)fprintf(file, " %u", race->points_table[n]);
        (void)fprintf(file, "\r\nTop 10 racer IDs:");
        for (n = 0u; n < 10u; ++n) (void)fprintf(file, " %u", race->finish_order[n]);
        (void)fprintf(file, "\r\n\r\n");
    }
    (void)fprintf(file,
        "Final standings screen captured: %s\r\n"
        "A accepted final standings and returned to remodeled main menu: %s\r\n"
        "Static audio AOT failures: %u\r\nStatic DSP failures: %u\r\n"
        "Automatic fallback enabled: %u\r\n",
        g_test.final_standings_saved ? "YES" : "NO",
        g_test.returned_menu_saved ? "YES" : "NO",
        audio.aot_failed, audio.sdsp_static_failed,
        audio.automatic_fallback_enabled);
    return fclose(file) == 0;
}

void topgear_rally_eight_race_begin(const wchar_t *executable_directory) {
    memset(&g_test, 0, sizeof(g_test));
    g_test.active = 1;
    g_test.phase = PHASE_SETUP;
    make_output_directory(executable_directory);
}

void topgear_rally_eight_race_cancel(void) { g_test.active = 0; }
int topgear_rally_eight_race_active(void) { return g_test.active; }

uint16_t topgear_rally_eight_race_input(TopGearRecomp *core) {
    uint8_t wram[TOPGEAR_RECOMP_WRAM_SIZE];
    uint8_t frame[FRAME_BYTES];
    uint16_t mask = 0u;
    (void)wram; (void)frame;
    if (!g_test.active || !core) return 0u;
    if (g_test.phase == PHASE_SETUP) {
        while (g_test.next_event < sizeof(setup_events) / sizeof(setup_events[0]) &&
               setup_events[g_test.next_event].frame <= g_test.global_frame) {
            g_test.setup_mask = setup_events[g_test.next_event].mask;
            ++g_test.next_event;
        }
        mask = g_test.setup_mask;
    } else if (g_test.phase == PHASE_RACE) {
        if (!topgear_recomp_read_wram(core, 0u, wram, sizeof(wram)) ||
            !topgear_recomp_v22_read_frame_bgr555(core, 0u, frame, sizeof(frame)))
            return 0u;
        mask = driver_input(core, &g_test.driver, wram, frame,
                            g_test.schedule[g_test.race_index]);
        /* Once any racer has a recorded finish, keep the mature driving
           controls active but suppress Rally's A/boost input.  A is also the
           menu accept button, so allowing a late boost pulse to leak into the
           stable RESULTS/WORLD RANKING sequence can skip the very screens this
           qualification is meant to prove. */
        if (g_test.race_live_seen && any_racer_finished(wram))
            mask &= (uint16_t)~TOPGEAR_INPUT_A;
    } else if (g_test.phase == PHASE_TRANSITION) {
        /* One A press advances the ordinary race World Ranking into the next
           Rally track briefing.  Do not send the historical second A here:
           it was skipping the visible briefing before evidence capture. */
        if (g_test.transition_frame >= 120u && g_test.transition_frame < 132u)
            mask = TOPGEAR_INPUT_A;
    } else if (g_test.phase == PHASE_WAIT_NEXT_RACE_START) {
        /* Match the mature four-race campaign: X/accelerate is sufficient to
           advance the already-captured pre-race briefing into the race. */
        mask = TOPGEAR_INPUT_X;
    } else if (g_test.phase == PHASE_FINAL_TRANSITION) {
        /* The capture path resets transition_frame to zero on the genuine
           final WORLD RANKING.  Give that screen two stable seconds of
           evidence, then issue exactly one A/accept pulse. */
        if (g_test.final_standings_saved &&
            g_test.transition_frame >= 120u && g_test.transition_frame < 132u)
            mask = TOPGEAR_INPUT_A;
    } else if (g_test.phase == PHASE_QUALIFICATION_FAIL) {
        /* Hold the native failure message long enough to capture it, then
           accept exactly once and let Top Gear return to the remodeled root. */
        if (g_test.qualification_fail_screen_saved &&
            g_test.transition_frame >= 120u && g_test.transition_frame < 132u)
            mask = TOPGEAR_INPUT_A;
    }
    return mask;
}

static int bg_mode(TopGearRecomp *core) {
    uint8_t value = 0u;
    if (!topgear_recomp_read_ppu_register(core, 0x2105u, &value)) return -1;
    return value & 7u;
}

int topgear_rally_eight_race_after_frame(TopGearRecomp *core,
                                     wchar_t *message,
                                     size_t message_capacity,
                                     wchar_t *report_path,
                                     size_t report_path_capacity) {
    uint8_t wram[TOPGEAR_RECOMP_WRAM_SIZE];
    uint8_t frame[FRAME_BYTES];
    uint64_t hash;
    TopGearRallyDebugStatus rally;
    int mode;
    if (message && message_capacity) message[0] = L'\0';
    if (report_path && report_path_capacity) report_path[0] = L'\0';
    if (!g_test.active || !core) return 0;
    if (!topgear_recomp_read_wram(core, 0u, wram, sizeof(wram)) ||
        !topgear_recomp_v22_read_frame_bgr555(core, 0u, frame, sizeof(frame)) ||
        !topgear_recomp_rally_debug_status(core, &rally)) {
        copy_wide(message, message_capacity,
                  L"Rally test stopped because static state could not be read.");
        g_test.active = 0;
        return -1;
    }
    mode = bg_mode(core);
    hash = fnv1a64(frame, sizeof(frame));
    if (hash == g_test.prior_hash) ++g_test.stable_frames;
    else g_test.stable_frames = 0u;
    g_test.prior_hash = hash;

    if (g_test.phase == PHASE_SETUP && rally.schedule_valid &&
        rally.generation_count != 0u) {
        unsigned n;
        char error[256];
        TopGearRallyDebugStatus loaded;
        for (n = 0u; n < 8u; ++n) g_test.schedule[n] = rally.schedule[n];
        if (!save_snapshot_named(core, L"Rally-generated-schedule.scsnap",
                                 g_test.schedule_snapshot_path,
                                 sizeof(g_test.schedule_snapshot_path) /
                                 sizeof(g_test.schedule_snapshot_path[0]))) {
            copy_wide(message, message_capacity, L"Failed to save Rally schedule snapshot.");
            g_test.active = 0; return -1;
        }
        if (!topgear_recomp_reset(core, error, sizeof(error))) {
            copy_wide(message, message_capacity, L"Failed to reset before Rally snapshot reload.");
            g_test.active = 0; return -1;
        }
        {
            char path[8192];
            if (!wide_to_utf8(g_test.schedule_snapshot_path, path, sizeof(path)) ||
                !topgear_recomp_snapshot_load(core, path, error, sizeof(error))) {
                copy_wide(message, message_capacity, L"Failed to reload Rally schedule snapshot.");
                g_test.active = 0; return -1;
            }
        }
        if (!topgear_recomp_rally_debug_status(core, &loaded) ||
            !loaded.active || !loaded.schedule_valid || loaded.race_index != 0u ||
            memcmp(loaded.schedule, g_test.schedule, sizeof(g_test.schedule)) != 0) {
            copy_wide(message, message_capacity,
                      L"Rally schedule did not survive reset plus snapshot reload.");
            g_test.active = 0; return -1;
        }
        g_test.snapshot_reloaded = 1u;
        g_test.setup_mask = 0u;
        g_test.next_event = sizeof(setup_events) / sizeof(setup_events[0]);
        g_test.phase = PHASE_WAIT_FIRST_BRIEFING;
        g_test.phase_frame = 0u;
        g_test.stable_frames = 0u;
        fprintf(stderr, "rally-8: schedule snapshot reloaded; ordinals=");
        for (n = 0u; n < 8u; ++n) fprintf(stderr, "%s%u", n ? "," : "", g_test.schedule[n]);
        fprintf(stderr, "\n");
    } else if (g_test.phase == PHASE_WAIT_FIRST_BRIEFING) {
        unsigned current_course = g_test.schedule[g_test.race_index];
        ++g_test.phase_frame;
        /* Capture the actual stable pre-race information screen rather than
           assuming a fixed delay from snapshot reload.  The first snapshot is
           deliberately taken immediately after Rally schedule generation, so
           the remaining transition time can vary slightly with that state. */
        if (!g_test.prerace_saved[g_test.race_index] &&
            g_test.phase_frame > 60u && mode == 1 &&
            read_le16(wram, COURSE_LAPS_OFFSET) != 0u &&
            read_le16(wram, 0x1F06u) == current_course &&
            nonblack_pixels(frame) > 20000u &&
            g_test.stable_frames >= 20u) {
            if (!save_prerace_frame(frame, g_test.race_index, current_course)) {
                copy_wide(message, message_capacity,
                          L"Failed to capture the Rally pre-race information screen.");
                g_test.active = 0; return -1;
            }
            g_test.prerace_saved[g_test.race_index] = 1u;
            fprintf(stderr, "rally-8: pre-race %u %ls laps=%u; handing control to white-car driver\n",
                    g_test.race_index + 1u, track_names[current_course],
                    read_le16(wram, COURSE_LAPS_OFFSET));
            /* Match the mature four-race test: once the stable pre-race
               information screen has been captured, immediately begin the
               normal race-driver input.  Its held X/accelerator input also
               advances the pre-race screen into the race.  Waiting for Mode 7
               while sending neutral input deadlocks on the briefing screen. */
            memset(&g_test.driver, 0, sizeof(g_test.driver));
            g_test.race_live_seen = 0u;
            g_test.phase = PHASE_RACE;
            g_test.stable_frames = 0u;
        }
    } else if (g_test.phase == PHASE_RACE) {
        unsigned required = read_le16(wram, COURSE_LAPS_OFFSET);
        if (!g_test.race_live_seen) {
            uint16_t timer = read_le16(wram, 0x1EAEu);
            /* The white-car input must begin on the briefing so X can advance
               it, but race-finish state from menu/setup must not be trusted
               until the actual live race framebuffer/timer has appeared. */
            if (g_test.driver.race_frame > 300u && required != 0u &&
                wram[P1_LAP_OFFSET] == 0u && wram[CPU_LAP_OFFSET] == 0u &&
                timer > 0u && timer < 120u &&
                nonblack_pixels(frame) > 20000u) {
                memset(&g_test.driver, 0, sizeof(g_test.driver));
                g_test.race_live_seen = 1u;
                g_test.stable_frames = 0u;
                fprintf(stderr, "rally-8: race %u live %ls laps=%u\n",
                        g_test.race_index + 1u,
                        track_names[g_test.schedule[g_test.race_index]], required);
            }
        }
        if (g_test.race_live_seen && g_test.driver.race_frame != 0u &&
            (g_test.driver.race_frame % 3000u) == 0u) {
            fprintf(stderr,
                    "rally-8: race %u telemetry frame=%u lap=%u/%u place=%u speed_raw=%d missing=%u mode=%d\n",
                    g_test.race_index + 1u, g_test.driver.race_frame,
                    (unsigned)wram[P1_LAP_OFFSET], required,
                    (unsigned)wram[P1_PLACE_OFFSET] + 1u,
                    (int)(int16_t)read_le16(wram, P1_SPEED_OFFSET),
                    g_test.driver.missing_road_total, mode);
        }
        if (g_test.race_live_seen && g_test.driver.race_frame >= 2500u && required != 0u &&
            any_racer_finished(wram) &&
            g_test.stable_frames >= RESULTS_STABLE_FRAMES) {
            RaceState *race = &g_test.races[g_test.race_index];
            unsigned n;
            race->course_ordinal = g_test.schedule[g_test.race_index];
            race->required_laps = required;
            race->place = (unsigned)wram[P1_PLACE_OFFSET] + 1u;
            race->cpu_place = (unsigned)wram[CPU_PLACE_OFFSET] + 1u;
            race->laps = (unsigned)wram[P1_LAP_OFFSET];
            race->max_mph = g_test.driver.max_mph;
            race->boosts = g_test.driver.boost_count;
            race->traffic_frames = g_test.driver.traffic_frames;
            race->avoidance_events = g_test.driver.avoidance_events;
            race->missing_road_frames = g_test.driver.missing_road_total;
            race->race_frames = g_test.driver.race_frame - g_test.stable_frames;
            for (n = 0u; n < 10u; ++n) race->finish_order[n] = wram[FINISH_ORDER_OFFSET + n];
            /* Top Gear commits cumulative points while advancing from the
               first stable race-results screen into its ranking/results flow.
               Record race driving facts here, then validate points in the
               transition phase after the real game has awarded them. */
            {
                wchar_t result_name[96];
                (void)swprintf(result_name, sizeof(result_name) / sizeof(result_name[0]),
                               L"Race-%u-results.ppm", g_test.race_index + 1u);
                (void)write_ppm(result_name, frame);
            }
            fprintf(stderr, "rally-8: race %u %ls finished place=%u; awaiting points commit\n",
                    g_test.race_index + 1u, track_names[race->course_ordinal],
                    race->place);
            g_test.transition_frame = 0u;
            g_test.stable_frames = 0u;
            g_test.phase = g_test.race_index == 7u ?
                           PHASE_FINAL_TRANSITION : PHASE_TRANSITION;
        }
    } else if (g_test.phase == PHASE_TRANSITION) {
        unsigned expected_sum = 81u * (g_test.race_index + 1u);
        unsigned cutoff = 10u - g_test.race_index;
        ++g_test.transition_frame;
        if (!rally.active && g_test.races[g_test.race_index].place > cutoff) {
            g_test.qualification_failed = 1u;
            g_test.qualification_cutoff = cutoff;
            g_test.phase = PHASE_QUALIFICATION_FAIL;
            g_test.transition_frame = 0u;
            g_test.stable_frames = 0u;
            fprintf(stderr,
                    "rally-8: qualification correctly failed after race %u: place=%u cutoff=%u\n",
                    g_test.race_index + 1u, g_test.races[g_test.race_index].place, cutoff);
            goto frame_done;
        }
        if ((g_test.transition_frame % 120u) == 0u) {
            TopGearCpuState dbg_cpu;
            TopGearRallyDebugStatus dbg_rally;
            memset(&dbg_cpu, 0, sizeof(dbg_cpu));
            memset(&dbg_rally, 0, sizeof(dbg_rally));
            (void)topgear_recomp_cpu_state(core, &dbg_cpu);
            (void)topgear_recomp_rally_debug_status(core, &dbg_rally);
            fprintf(stderr,
                    "rally-8: transition race=%u frame=%u pc=%02X:%04X points=%u course=%u rally_index=%u active=%u mode=%d\n",
                    g_test.race_index + 1u, g_test.transition_frame,
                    dbg_cpu.pbr, dbg_cpu.pc, points_sum(wram),
                    read_le16(wram, 0x1F06u), dbg_rally.race_index,
                    dbg_rally.active, mode);
        }
        if (!g_test.points_recorded[g_test.race_index] &&
            points_sum(wram) == expected_sum) {
            RaceState *race = &g_test.races[g_test.race_index];
            unsigned n;
            wchar_t snap_name[96];
            race->points = wram[POINTS_TABLE_OFFSET];
            race->points_sum = expected_sum;
            for (n = 0u; n < 20u; ++n)
                race->points_table[n] = wram[POINTS_TABLE_OFFSET + n];
            if (g_test.race_index > 0u &&
                race->points < g_test.races[g_test.race_index - 1u].points) {
                copy_wide(message, message_capacity,
                          L"Player cumulative points decreased during Rally.");
                g_test.active = 0; return -1;
            }
            g_test.points_recorded[g_test.race_index] = 1u;
            if ((g_test.race_index & 1u) != 0u) {
                (void)swprintf(snap_name, sizeof(snap_name) / sizeof(snap_name[0]),
                               L"Rally-Race-%u-points.scsnap", g_test.race_index + 1u);
                if (!save_snapshot_named(core, snap_name, NULL, 0u)) {
                    copy_wide(message, message_capacity,
                              L"Failed to save even-race Rally points snapshot.");
                    g_test.active = 0; return -1;
                }
            }
            fprintf(stderr, "rally-8: race %u points committed player=%u sum=%u\n",
                    g_test.race_index + 1u, race->points, expected_sum);
        }
        if (g_test.points_recorded[g_test.race_index] &&
            !g_test.prerace_saved[g_test.race_index + 1u] &&
            rally.race_index == g_test.race_index + 1u &&
            read_le16(wram, 0x1F06u) == g_test.schedule[g_test.race_index + 1u] &&
            mode == 1 && g_test.transition_frame >= 280u &&
            nonblack_pixels(frame) > 20000u &&
            g_test.stable_frames >= 20u) {
            /* The visible track briefing is presented while some live race
               fields still contain the prior race.  Course ordinal + a
               stable non-black framebuffer is the correct evidence boundary;
               waiting for live lap/timer reset lands in the subsequent black
               race-loading fade. */
            if (!save_prerace_frame(frame, g_test.race_index + 1u,
                                    g_test.schedule[g_test.race_index + 1u])) {
                copy_wide(message, message_capacity, L"Failed to capture next Rally pre-race screen.");
                g_test.active = 0; return -1;
            }
            g_test.prerace_saved[g_test.race_index + 1u] = 1u;
            fprintf(stderr, "rally-8: captured visible pre-race %u %ls\n",
                    g_test.race_index + 2u,
                    track_names[g_test.schedule[g_test.race_index + 1u]]);
            ++g_test.race_index;
            g_test.phase = PHASE_WAIT_NEXT_RACE_START;
            g_test.phase_frame = 0u;
            g_test.stable_frames = 0u;
        }
    } else if (g_test.phase == PHASE_WAIT_NEXT_RACE_START) {
        ++g_test.phase_frame;
        if (read_le16(wram, 0x1F06u) == g_test.schedule[g_test.race_index] &&
            mode == 1 && next_race_state_is_reset(wram) &&
            nonblack_pixels(frame) > 20000u) {
            memset(&g_test.driver, 0, sizeof(g_test.driver));
            g_test.race_live_seen = 1u;
            fprintf(stderr, "rally-8: race %u live after briefing %ls laps=%u\n",
                    g_test.race_index + 1u,
                    track_names[g_test.schedule[g_test.race_index]],
                    read_le16(wram, COURSE_LAPS_OFFSET));
            g_test.phase = PHASE_RACE;
            g_test.phase_frame = 0u;
            g_test.stable_frames = 0u;
        }
    } else if (g_test.phase == PHASE_QUALIFICATION_FAIL) {
        ++g_test.transition_frame;
        if (!g_test.qualification_fail_screen_saved &&
            g_test.transition_frame >= 120u && mode == 1 &&
            nonblack_pixels(frame) > 10000u && g_test.stable_frames >= 20u) {
            if (!write_ppm(L"Rally-Qualification-Failed.ppm", frame)) {
                copy_wide(message, message_capacity,
                          L"Failed to capture Rally qualification-failure screen.");
                g_test.active = 0; return -1;
            }
            g_test.qualification_fail_screen_saved = 1u;
            fprintf(stderr, "rally-8: captured native qualification-failure screen\n");
            g_test.active = 0;
            copy_wide(message, message_capacity,
                      L"Rally qualification gate correctly ended the event on the native next-race failure screen.");
            return 1;
        }
    } else if (g_test.phase == PHASE_FINAL_TRANSITION) {
        unsigned expected_sum = 81u * 8u;
        ++g_test.transition_frame;
        if (!g_test.points_recorded[7] && points_sum(wram) == expected_sum) {
            RaceState *race = &g_test.races[7];
            unsigned n;
            race->points = wram[POINTS_TABLE_OFFSET];
            race->points_sum = expected_sum;
            for (n = 0u; n < 20u; ++n)
                race->points_table[n] = wram[POINTS_TABLE_OFFSET + n];
            if (race->points < g_test.races[6].points) {
                copy_wide(message, message_capacity,
                          L"Player cumulative points decreased after Rally race 8.");
                g_test.active = 0; return -1;
            }
            g_test.points_recorded[7] = 1u;
            if (!save_snapshot_named(core, L"Rally-Race-8-points.scsnap", NULL, 0u)) {
                copy_wide(message, message_capacity,
                          L"Failed to save Rally race-8 points snapshot.");
                g_test.active = 0; return -1;
            }
            fprintf(stderr, "rally-8: race 8 points committed player=%u sum=%u\n",
                    race->points, expected_sum);
        }
        if (g_test.points_recorded[7] && !g_test.final_standings_saved &&
            rally.active && mode == 1 &&
            nonblack_pixels(frame) > 20000u && g_test.stable_frames >= 20u) {
            if (!write_ppm(L"Final-Standings.ppm", frame)) {
                copy_wide(message, message_capacity, L"Failed to capture final Rally standings.");
                g_test.active = 0; return -1;
            }
            g_test.final_standings_saved = 1u;
            /* From this point transition_frame measures time since the
               verified WORLD RANKING capture, so the single A pulse cannot
               race ahead of the evidence screen. */
            g_test.transition_frame = 0u;
            fprintf(stderr, "rally-8: captured final WORLD RANKING standings\n");
        }
        if (!rally.active && g_test.transition_frame > 600u) {
            g_test.phase = PHASE_WAIT_MENU;
            g_test.phase_frame = 0u;
            g_test.stable_frames = 0u;
        }
    } else if (g_test.phase == PHASE_WAIT_MENU) {
        ++g_test.phase_frame;
        if (mode == 1 && g_test.phase_frame > 120u && g_test.stable_frames >= 30u) {
            int report_ok;
            if (!write_ppm(L"Return-Main-Menu.ppm", frame)) {
                copy_wide(message, message_capacity, L"Failed to capture Rally return menu.");
                g_test.active = 0; return -1;
            }
            g_test.returned_menu_saved = 1u;
            report_ok = write_report(core);
            g_test.active = 0;
            copy_wide(report_path, report_path_capacity, g_test.report_path);
            copy_wide(message, message_capacity,
                report_ok ?
                L"Rally completed all eight scheduled races, final standings, and returned to the main menu." :
                L"Rally completed, but its text report could not be written.");
            return 1;
        }
    }

frame_done:
    ++g_test.global_frame;
    if (g_test.global_frame >= MAX_CAMPAIGN_FRAMES) {
        copy_wide(message, message_capacity,
                  L"Rally test stopped after reaching its maximum frame limit.");
        g_test.active = 0; return -1;
    }
    return 0;
}
