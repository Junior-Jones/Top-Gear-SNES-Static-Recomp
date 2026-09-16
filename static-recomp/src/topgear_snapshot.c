#include "topgear_internal.h"
#include "topgear_snapshot_format.h"
#include "sc_static_apu.h"
#include "../static-audio/sequel/music_runtime.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define TOPGEAR_FRAME_MAX_INSTRUCTIONS UINT64_C(50000000)

static uint64_t snapshot_hash(const void *data, size_t size) {
    const unsigned char *bytes = (const unsigned char *)data;
    uint64_t hash = UINT64_C(1469598103934665603);
    size_t index;
    for (index = 0u; index < size; ++index) {
        hash ^= bytes[index];
        hash *= UINT64_C(1099511628211);
    }
    return hash;
}


static size_t music_snapshot_size(void){return sc_static_apu_snapshot_size()+tg2_music_snapshot_size()+tg3_music_snapshot_size()+tg0_music_snapshot_size();}
static int music_snapshot_save(void *data,size_t size){
    size_t a=sc_static_apu_snapshot_size(),b=tg2_music_snapshot_size(),c=tg3_music_snapshot_size(),d=tg0_music_snapshot_size();uint8_t *p=(uint8_t*)data;
    return size==a+b+c+d&&sc_static_apu_snapshot_save(p,a)&&tg2_music_snapshot_save(p+a,b)&&tg3_music_snapshot_save(p+a+b,c)&&tg0_music_snapshot_save(p+a+b+c,d);
}
static int music_snapshot_load(const void *data,size_t size,char *error,size_t capacity){
    size_t a=sc_static_apu_snapshot_size(),b=tg2_music_snapshot_size(),c=tg3_music_snapshot_size(),d=tg0_music_snapshot_size();const uint8_t *p=(const uint8_t*)data;
    return size==a+b+c+d&&sc_static_apu_snapshot_load(p,a,error,capacity)&&tg2_music_snapshot_load(p+a,b,error,capacity)&&tg3_music_snapshot_load(p+a+b,c,error,capacity)&&tg0_music_snapshot_load(p+a+b+c,d,error,capacity);
}

static void snapshot_error(char *error, size_t capacity, const char *message) {
    if (error && capacity) {
        (void)snprintf(error, capacity, "%s", message ? message : "");
        error[capacity - 1u] = '\0';
    }
}

static void sanitize_core_snapshot(TopGearRecomp *copy) {
    copy->rom = NULL;
    copy->v24_frame_callback = NULL;
    copy->v24_frame_callback_user = NULL;
    copy->hook_callback = NULL;
    copy->hook_user = NULL;
    copy->mod_time_trial_leaderboard_provider = NULL;
    copy->mod_time_trial_leaderboard_user = NULL;
    copy->hook_in_callback = 0u;
    copy->hook_stop_requested = 0u;
    memset(copy->audio_fifo, 0, sizeof(copy->audio_fifo));
    copy->audio_read_index = 0u;
    copy->audio_write_index = 0u;
    copy->audio_count = 0u;
}

int topgear_recomp_advance(TopGearRecomp *instance, uint16_t player1,
                           uint16_t player2, uint32_t frame_count,
                           TopGearRecompFrameResult *result) {
    uint32_t index;
    uint32_t start;
    enum TopGearRunResult run_result = TOPGEAR_RUN_ERROR;
    if (result) memset(result, 0, sizeof(*result));
    if (!instance || frame_count == 0u) return 0;
    start = (uint32_t)topgear_recomp_v27_frame_count(instance);
    for (index = 0u; index < frame_count; ++index) {
        run_result = topgear_recomp_v27_advance_frame(
            instance, tg_mod_music_input(instance,player1), player2, TOPGEAR_FRAME_MAX_INSTRUCTIONS);
        if (run_result != TOPGEAR_RUN_COMPLETE) break;
        tg_mod_time_trial_frame(instance);
        tg_mod_career_frame(instance);

    }
    if (result) {
        result->route_continued = (uint8_t)(run_result == TOPGEAR_RUN_COMPLETE);
        result->frame_rendered = result->route_continued;
        result->player1_input_mask = player1;
        result->player2_input_mask = player2;
        result->start_frame = start;
        result->end_frame = (uint32_t)topgear_recomp_v27_frame_count(instance);
        if (!result->route_continued)
            snapshot_error(result->renderer_error,
                           sizeof(result->renderer_error),
                           topgear_recomp_last_error(instance));
    }
    return run_result == TOPGEAR_RUN_COMPLETE;
}

int topgear_recomp_advance_headless(TopGearRecomp *instance, uint16_t player1,
                                    uint16_t player2, uint32_t frame_count,
                                    TopGearRecompFrameResult *result) {
    return topgear_recomp_advance(instance, player1, player2,
                                  frame_count, result);
}

uint32_t topgear_recomp_current_frame(const TopGearRecomp *instance) {
    return (uint32_t)topgear_recomp_v27_frame_count(instance);
}

int topgear_recomp_frame_bgra(TopGearRecomp *instance, uint32_t *destination,
                              size_t pixel_capacity) {
    uint16_t source[TOPGEAR_RECOMP_FRAME_WIDTH * TOPGEAR_RECOMP_FRAME_HEIGHT];
    size_t index;
    if (!instance || !destination ||
        pixel_capacity < TOPGEAR_RECOMP_FRAME_WIDTH * TOPGEAR_RECOMP_FRAME_HEIGHT ||
        !topgear_recomp_v22_read_frame_bgr555(instance, 0u, source,
                                              sizeof(source))) return 0;
    for (index = 0u; index < TOPGEAR_RECOMP_FRAME_WIDTH * TOPGEAR_RECOMP_FRAME_HEIGHT;
         ++index) {
        uint32_t pixel = source[index];
        uint32_t blue = (pixel >> 10u) & 31u;
        uint32_t green = (pixel >> 5u) & 31u;
        uint32_t red = pixel & 31u;
        red = (red << 3u) | (red >> 2u);
        green = (green << 3u) | (green >> 2u);
        blue = (blue << 3u) | (blue >> 2u);
        destination[index] = UINT32_C(0xff000000) | (red << 16u) |
                             (green << 8u) | blue;
    }
    return 1;
}

/* Version 27 snapshots contain the complete static S-CPU/core structure plus
   Full Static S-SMP, 64 KiB ARAM and S-DSP state.  Core and audio payloads are
   independently hashed.  Host callbacks/pointers and queued PCM are excluded;
   they are rebound or cleared on load.  Headless Test 04 proves a late-race
   neutral branch reproduces identical WRAM and framebuffer after repeated
   save/load cycles through the same advance-frame path used by the frontend. */
int topgear_recomp_snapshot_save(const TopGearRecomp *instance,
                                 const char *path, char *error,
                                 size_t error_capacity) {
    TopGearSnapshotHeader header;
    TopGearRecomp *core = NULL;
    unsigned char *apu = NULL;
    size_t apu_size;
    FILE *file = NULL;
    char *temporary = NULL;
    int ok = 0;
    if (!instance || !path || !path[0] || !instance->static_audio_acquired) {
        snapshot_error(error, error_capacity,
                       "A running Full Static game is required to save a snapshot.");
        return 0;
    }
    apu_size = music_snapshot_size();
    if (apu_size == 0u || apu_size > UINT32_MAX ||
        sizeof(*instance) > UINT32_MAX) {
        snapshot_error(error, error_capacity, "Snapshot state is too large.");
        return 0;
    }
    core = (TopGearRecomp *)malloc(sizeof(*core));
    apu = (unsigned char *)malloc(apu_size);
    temporary = (char *)malloc(strlen(path) + 16u);
    if (!core || !apu || !temporary) {
        snapshot_error(error, error_capacity,
                       "Not enough memory to create the snapshot.");
        goto cleanup;
    }
    *core = *instance;
    sanitize_core_snapshot(core);
    if (!music_snapshot_save(apu, apu_size)) {
        snapshot_error(error, error_capacity,
                       "Unable to capture the Full Static audio state.");
        goto cleanup;
    }
    memset(&header, 0, sizeof(header));
    memcpy(header.magic, TOPGEAR_SNAPSHOT_MAGIC, TOPGEAR_SNAPSHOT_MAGIC_SIZE);
    header.version = TOPGEAR_SNAPSHOT_VERSION;
    header.core_size = (uint32_t)sizeof(*core);
    header.apu_size = (uint32_t)apu_size;
    header.core_hash = snapshot_hash(core, sizeof(*core));
    header.apu_hash = snapshot_hash(apu, apu_size);
    (void)snprintf(temporary, strlen(path) + 16u, "%s.writing", path);
#ifdef _WIN32
    if (fopen_s(&file, temporary, "wb") != 0) file = NULL;
#else
    file = fopen(temporary, "wb");
#endif
    if (!file || fwrite(&header, 1u, sizeof(header), file) != sizeof(header) ||
        fwrite(core, 1u, sizeof(*core), file) != sizeof(*core) ||
        fwrite(apu, 1u, apu_size, file) != apu_size ||
        fflush(file) != 0 || fclose(file) != 0) {
        file = NULL;
        remove(temporary);
        snapshot_error(error, error_capacity,
                       "Unable to write the snapshot file.");
        goto cleanup;
    }
    file = NULL;
#ifdef _WIN32
    if (!MoveFileExA(temporary, path,
                     MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)) {
#else
    if (rename(temporary, path) != 0) {
#endif
        remove(temporary);
        snapshot_error(error, error_capacity,
                       "Unable to replace the snapshot file.");
        goto cleanup;
    }
    snapshot_error(error, error_capacity, "");
    ok = 1;
cleanup:
    if (file) fclose(file);
    free(temporary);
    free(apu);
    free(core);
    return ok;
}

int topgear_recomp_snapshot_load(TopGearRecomp *instance, const char *path,
                                 char *error, size_t error_capacity) {
    TopGearSnapshotHeader header;
    TopGearRecomp *core = NULL;
    unsigned char *apu = NULL;
    FILE *file = NULL;
    size_t apu_size;
    int trailing;
    uint8_t *rom;
    TopGearV24FrameCallback frame_callback;
    void *frame_user;
    TopGearHookCallback hook_callback;
    void *hook_user;
    uint32_t hook_mask;
    TopGearTimeTrialLeaderboardProvider tt_provider;
    void *tt_provider_user;
    int ok = 0;
    if (!instance || !path || !path[0] || !instance->static_audio_acquired) {
        snapshot_error(error, error_capacity,
                       "A running Full Static game is required to load a snapshot.");
        return 0;
    }
    apu_size = music_snapshot_size();
    core = (TopGearRecomp *)malloc(sizeof(*core));
    apu = (unsigned char *)malloc(apu_size);
    if (!core || !apu) {
        snapshot_error(error, error_capacity,
                       "Not enough memory to load the snapshot.");
        goto cleanup;
    }
#ifdef _WIN32
    if (fopen_s(&file, path, "rb") != 0) file = NULL;
#else
    file = fopen(path, "rb");
#endif
    if (!file) {
        snapshot_error(error, error_capacity, "Unable to open the snapshot file.");
        goto cleanup;
    }
    if (fread(&header, 1u, sizeof(header), file) != sizeof(header) ||
        memcmp(header.magic, TOPGEAR_SNAPSHOT_MAGIC,
               TOPGEAR_SNAPSHOT_MAGIC_SIZE) != 0 ||
        header.version != TOPGEAR_SNAPSHOT_VERSION ||
        header.core_size != sizeof(*core) || header.apu_size != apu_size) {
        snapshot_error(error, error_capacity,
                       "The snapshot is invalid or belongs to another build.");
        goto cleanup;
    }
    if (fread(core, 1u, sizeof(*core), file) != sizeof(*core) ||
        fread(apu, 1u, apu_size, file) != apu_size) {
        snapshot_error(error, error_capacity, "The snapshot file is truncated.");
        goto cleanup;
    }
    trailing = fgetc(file);
    if (ferror(file) || trailing != EOF ||
        snapshot_hash(core, sizeof(*core)) != header.core_hash ||
        snapshot_hash(apu, apu_size) != header.apu_hash) {
        snapshot_error(error, error_capacity,
                       "The snapshot is corrupt or has unexpected trailing data.");
        goto cleanup;
    }
    if (fclose(file) != 0) {
        file = NULL;
        snapshot_error(error, error_capacity, "Unable to finish reading the snapshot.");
        goto cleanup;
    }
    file = NULL;
    if (!music_snapshot_load(apu, apu_size, error, error_capacity))
        goto cleanup;
    rom = instance->rom;
    frame_callback = instance->v24_frame_callback;
    frame_user = instance->v24_frame_callback_user;
    hook_callback = instance->hook_callback;
    hook_user = instance->hook_user;
    hook_mask = instance->hook_mask;
    tt_provider = instance->mod_time_trial_leaderboard_provider;
    tt_provider_user = instance->mod_time_trial_leaderboard_user;
    *instance = *core;
    instance->rom = rom;
    instance->v24_frame_callback = frame_callback;
    instance->v24_frame_callback_user = frame_user;
    instance->hook_callback = hook_callback;
    instance->hook_user = hook_user;
    instance->hook_mask = hook_mask;
    instance->mod_time_trial_leaderboard_provider = tt_provider;
    instance->mod_time_trial_leaderboard_user = tt_provider_user;
    instance->static_audio_acquired = 1u;
    topgear_recomp_audio_clear(instance);
    snapshot_error(error, error_capacity, "");
    ok = 1;
cleanup:
    if (file) fclose(file);
    free(apu);
    free(core);
    return ok;
}

/* Top Gear uses passwords rather than battery-backed SRAM. These no-op APIs
   keep the shared frontend contract explicit without creating fake save RAM. */
size_t topgear_recomp_sram_size(void) { return 0u; }
int topgear_recomp_sram_copy(const TopGearRecomp *instance, void *data,
                             size_t capacity) {
    (void)instance; (void)data; (void)capacity; return 0;
}
int topgear_recomp_sram_load(TopGearRecomp *instance, const void *data,
                             size_t size, char *error, size_t capacity) {
    (void)instance; (void)data;
    if (size != 0u) {
        snapshot_error(error, capacity, "Top Gear does not use battery SRAM.");
        return 0;
    }
    snapshot_error(error, capacity, ""); return 1;
}
int topgear_recomp_sram_dirty(const TopGearRecomp *instance) {
    (void)instance; return 0;
}
void topgear_recomp_sram_mark_clean(TopGearRecomp *instance) { (void)instance; }

int topgear_recomp_audio_overflowed(const TopGearRecomp *instance) {
    return instance && instance->audio_fifo_dropped_frames != 0u;
}
void topgear_recomp_audio_clear_overflow(TopGearRecomp *instance) {
    if (instance) instance->audio_fifo_dropped_frames = 0u;
}
