#include "topgear_app_core.h"

#include "topgear_static_recomp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TopGearApp {
    TopGearRecomp *core;
    uint32_t frame[TOPGEAR_APP_FRAME_WIDTH * TOPGEAR_APP_FRAME_HEIGHT];
    char error[192];
};

static void copy_error(TopGearApp *app, char *error, size_t capacity,
                       const char *text) {
    if (!text) text = "";
    if (app) (void)snprintf(app->error, sizeof(app->error), "%s", text);
    if (error && capacity) (void)snprintf(error, capacity, "%s", text);
}

static void refresh_frame(TopGearApp *app) {
    if (app) (void)topgear_recomp_frame_bgra(
        app->core, app->frame,
        sizeof(app->frame) / sizeof(app->frame[0]));
}

int topgear_app_create(TopGearApp **out, const uint8_t *rom, size_t size,
                       char *error, size_t capacity) {
    TopGearApp *app;
    if (!out || !rom || size != TOPGEAR_APP_ROM_SIZE) {
        if (error && capacity) (void)snprintf(
            error, capacity,
            "The exact 524,288-byte Top Gear (USA) ROM is required.");
        return 0;
    }
    *out = NULL;
    app = (TopGearApp *)calloc(1u, sizeof(*app));
    if (!app) return 0;
    if (!topgear_recomp_create(&app->core, rom, size, error, capacity)) {
        free(app);
        return 0;
    }
    refresh_frame(app);
    copy_error(app, error, capacity, "");
    *out = app;
    return 1;
}

void topgear_app_destroy(TopGearApp *app) {
    if (!app) return;
    topgear_recomp_destroy(app->core);
    free(app);
}

int topgear_app_reset(TopGearApp *app, char *error, size_t capacity) {
    if (!app || !topgear_recomp_reset(app->core, error, capacity)) return 0;
    refresh_frame(app);
    copy_error(app, error, capacity, "");
    return 1;
}

int topgear_app_advance_streamed(TopGearApp *app, uint16_t input,
    uint32_t frames, TopGearAppAudioProgressCallback progress, void *opaque,
    TopGearAppFrameResult *result) {
    TopGearRecompFrameResult core_result;
    uint32_t completed;
    if (!app || !result) return 0;
    memset(result, 0, sizeof(*result));
    result->input_mask = input;
    result->start_frame = topgear_recomp_current_frame(app->core);
    for (completed = 0u; completed < frames; ++completed) {
        memset(&core_result, 0, sizeof(core_result));
        if (!topgear_recomp_advance(app->core, input, 0u, 1u,
                                    &core_result)) {
            copy_error(app, NULL, 0u,
                       topgear_recomp_last_error(app->core));
            result->end_frame = topgear_recomp_current_frame(app->core);
            return 0;
        }
        result->route_continued = core_result.route_continued;
        result->frame_rendered = core_result.frame_rendered;
        (void)snprintf(result->renderer_error,
                       sizeof(result->renderer_error), "%s",
                       core_result.renderer_error);
        if (progress) progress(app, opaque);
    }
    result->end_frame = topgear_recomp_current_frame(app->core);
    refresh_frame(app);
    copy_error(app, NULL, 0u, "");
    return 1;
}

const uint32_t *topgear_app_frame_bgra(const TopGearApp *app) {
    return app ? app->frame : NULL;
}
uint32_t topgear_app_frame_width(const TopGearApp *app) {
    return app ? TOPGEAR_APP_FRAME_WIDTH : 0u;
}
uint32_t topgear_app_current_frame(const TopGearApp *app) {
    return app ? topgear_recomp_current_frame(app->core) : 0u;
}
const char *topgear_app_last_error(const TopGearApp *app) {
    return app ? app->error : "No Top Gear instance.";
}
size_t topgear_app_audio_available(const TopGearApp *app) {
    return app ? topgear_recomp_audio_available(app->core) : 0u;
}
size_t topgear_app_audio_read(TopGearApp *app, int16_t *pcm, size_t frames) {
    return app ? topgear_recomp_audio_read(app->core, pcm, frames) : 0u;
}
size_t topgear_app_audio_discard(TopGearApp *app) {
    size_t frames = topgear_app_audio_available(app);
    return app ? topgear_recomp_audio_discard(app->core, frames) : 0u;
}
int topgear_app_audio_overflowed(const TopGearApp *app) {
    return app && topgear_recomp_audio_overflowed(app->core);
}
void topgear_app_audio_clear_overflow(TopGearApp *app) {
    if (app) topgear_recomp_audio_clear_overflow(app->core);
}
uint64_t topgear_app_audio_dropped_frames(const TopGearApp *app) {
    TopGearStaticAudioStatus status;
    memset(&status, 0, sizeof(status));
    return app && topgear_recomp_static_audio_status(app->core, &status) ?
           status.fifo_dropped_frames : 0u;
}
int topgear_app_snapshot_save(const TopGearApp *app, const char *path,
                              char *error, size_t capacity) {
    return app && topgear_recomp_snapshot_save(app->core, path,
                                                error, capacity);
}
int topgear_app_snapshot_load(TopGearApp *app, const char *path,
                              char *error, size_t capacity) {
    int ok = app && topgear_recomp_snapshot_load(app->core, path,
                                                  error, capacity);
    if (ok) refresh_frame(app);
    return ok;
}
int topgear_app_sram_copy(const TopGearApp *app, void *dst, size_t capacity) {
    return app && topgear_recomp_sram_copy(app->core, dst, capacity);
}
int topgear_app_sram_load(TopGearApp *app, const void *src, size_t size,
                          char *error, size_t capacity) {
    return app && topgear_recomp_sram_load(app->core, src, size,
                                            error, capacity);
}
int topgear_app_sram_dirty(const TopGearApp *app) {
    return app && topgear_recomp_sram_dirty(app->core);
}
void topgear_app_sram_mark_clean(TopGearApp *app) {
    if (app) topgear_recomp_sram_mark_clean(app->core);
}

int topgear_app_write_diagnostic_log(const TopGearApp *app, const char *path,
                                     const char *screenshot_path,
                                     char *error, size_t capacity) {
    FILE *file;
    TopGearCpuState cpu;
    TopGearSmpState smp;
    TopGearFrontierReceipt frontier;
    TopGearStaticAudioStatus audio;
    if (!app || !path || !path[0]) return 0;
    memset(&cpu, 0, sizeof(cpu));
    memset(&smp, 0, sizeof(smp));
    memset(&frontier, 0, sizeof(frontier));
    memset(&audio, 0, sizeof(audio));
    topgear_recomp_cpu_state(app->core, &cpu);
    topgear_recomp_smp_state(app->core, &smp);
    topgear_recomp_frontier(app->core, &frontier);
    (void)topgear_recomp_static_audio_status(app->core, &audio);
    file = fopen(path, "wb");
    if (!file) {
        if (error && capacity) (void)snprintf(
            error, capacity, "The diagnostic log could not be opened.");
        return 0;
    }
    (void)fprintf(file,
        "Top Gear Static Recomp - Screenshot Static-Core Log\r\n"
        "screenshot=%s\r\nframe=%u\r\ninstructions=%llu\r\n"
        "cpu=%02X:%04X\r\nsmp_pc=%04X\r\nsmp_instructions=%llu\r\n"
        "audio_pcm_frames=%llu\r\naudio_unknown_frames=%llu\r\n"
        "audio_hash=%016llX\r\naudio_aot_failed=%u\r\n"
        "failed=%d\r\nfrontier=%s\r\nreason=%s\r\n",
        screenshot_path ? screenshot_path : "",
        topgear_recomp_current_frame(app->core),
        (unsigned long long)topgear_recomp_instruction_count(app->core),
        (unsigned)cpu.pbr, (unsigned)cpu.pc, (unsigned)smp.pc,
        (unsigned long long)smp.instruction_count,
        (unsigned long long)audio.pcm_frames,
        (unsigned long long)audio.pcm_unknown_frames,
        (unsigned long long)audio.pcm_hash, (unsigned)audio.aot_failed,
        topgear_recomp_failed(app->core), frontier.address, frontier.reason);
    if (fclose(file) != 0) return 0;
    if (error && capacity) error[0] = '\0';
    return 1;
}
