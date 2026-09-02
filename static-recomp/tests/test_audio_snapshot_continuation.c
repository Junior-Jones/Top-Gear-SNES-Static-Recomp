#include "topgear_static_recomp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int read_rom(const char *path, unsigned char **data) {
    FILE *file = NULL;
    size_t count;
    *data = NULL;
    file = fopen(path, "rb");
    if (!file) return 0;
    *data = (unsigned char *)malloc(TOPGEAR_RECOMP_ROM_SIZE);
    if (!*data) { fclose(file); return 0; }
    count = fread(*data, 1u, TOPGEAR_RECOMP_ROM_SIZE, file);
    if (fclose(file) != 0 || count != TOPGEAR_RECOMP_ROM_SIZE) {
        free(*data); *data = NULL; return 0;
    }
    return 1;
}

int main(int argc, char **argv) {
    unsigned char *rom = NULL;
    TopGearRecomp *game = NULL;
    TopGearRecompFrameResult result;
    TopGearCpuState before_cpu, after_cpu;
    TopGearStaticAudioStatus before_audio, after_audio, replay_audio_a, replay_audio_b;
    int16_t replay_pcm_a[4096], replay_pcm_b[4096];
    size_t replay_frames_a = 0u, replay_frames_b = 0u;
    uint32_t *before_pixels = NULL, *after_pixels = NULL;
    const size_t pixels = TOPGEAR_RECOMP_FRAME_WIDTH * TOPGEAR_RECOMP_FRAME_HEIGHT;
    uint32_t before_frame;
    char error[256];
    FILE *file = NULL;
    int ok = 0;
    if (argc != 3) { fprintf(stderr, "usage: test ROM SNAPSHOT\n"); return 2; }
    remove(argv[2]);
    if (!read_rom(argv[1], &rom)) { fprintf(stderr, "ROM read failed\n"); goto cleanup; }
    if (!topgear_recomp_create(&game, rom, TOPGEAR_RECOMP_ROM_SIZE,
                               error, sizeof(error))) {
        fprintf(stderr, "create failed: %s\n", error); goto cleanup;
    }
    before_pixels = (uint32_t *)malloc(pixels * sizeof(*before_pixels));
    after_pixels = (uint32_t *)malloc(pixels * sizeof(*after_pixels));
    if (!before_pixels || !after_pixels) { fprintf(stderr, "allocation failed\n"); goto cleanup; }
    memset(&result, 0, sizeof(result));
    if (!topgear_recomp_advance(game, TOPGEAR_INPUT_START, TOPGEAR_INPUT_B,
                                3u, &result)) {
        fprintf(stderr, "initial advance failed: %s\n", topgear_recomp_last_error(game)); goto cleanup;
    }
    before_frame = topgear_recomp_current_frame(game);
    topgear_recomp_cpu_state(game, &before_cpu);
    if (!topgear_recomp_static_audio_status(game, &before_audio)) {
        fprintf(stderr, "audio status capture failed\n"); goto cleanup;
    }
    if (!topgear_recomp_frame_bgra(game, before_pixels, pixels)) {
        fprintf(stderr, "frame conversion failed\n"); goto cleanup;
    }
    if (!topgear_recomp_snapshot_save(game, argv[2], error, sizeof(error))) {
        fprintf(stderr, "save failed: %s\n", error); goto cleanup;
    }
    if (!topgear_recomp_advance(game, TOPGEAR_INPUT_RIGHT, TOPGEAR_INPUT_LEFT,
                                2u, &result)) {
        fprintf(stderr, "second advance failed\n"); goto cleanup;
    }
    if (!topgear_recomp_snapshot_load(game, argv[2], error, sizeof(error))) {
        fprintf(stderr, "load failed: %s\n", error); goto cleanup;
    }
    topgear_recomp_cpu_state(game, &after_cpu);
    if (topgear_recomp_current_frame(game) != before_frame ||
        memcmp(&before_cpu, &after_cpu, sizeof(before_cpu)) != 0 ||
        !topgear_recomp_static_audio_status(game, &after_audio) ||
        memcmp(&before_audio, &after_audio, sizeof(before_audio)) != 0 ||
        !topgear_recomp_frame_bgra(game, after_pixels, pixels) ||
        memcmp(before_pixels, after_pixels, pixels * sizeof(*before_pixels)) != 0) {
        fprintf(stderr, "restored state differs\n"); goto cleanup;
    }
    /* Replay the same frame twice from the same snapshot.  This verifies that
       the serialized S-SMP instruction cursor, timers, 32-phase S-DSP state,
       clock remainder and native PCM continuation are deterministic. */
    if (!topgear_recomp_advance(game, TOPGEAR_INPUT_A | TOPGEAR_INPUT_RIGHT, 0u,
                                1u, &result) ||
        !topgear_recomp_static_audio_status(game, &replay_audio_a)) {
        fprintf(stderr, "first deterministic replay failed\n"); goto cleanup;
    }
    replay_frames_a = topgear_recomp_audio_available(game);
    if (replay_frames_a > 2048u ||
        topgear_recomp_audio_read(game, replay_pcm_a, replay_frames_a) != replay_frames_a) {
        fprintf(stderr, "first replay PCM capture failed\n"); goto cleanup;
    }
    if (!topgear_recomp_snapshot_load(game, argv[2], error, sizeof(error)) ||
        !topgear_recomp_advance(game, TOPGEAR_INPUT_A | TOPGEAR_INPUT_RIGHT, 0u,
                                1u, &result) ||
        !topgear_recomp_static_audio_status(game, &replay_audio_b)) {
        fprintf(stderr, "second deterministic replay failed: %s\n", error); goto cleanup;
    }
    replay_frames_b = topgear_recomp_audio_available(game);
    if (replay_frames_b > 2048u ||
        topgear_recomp_audio_read(game, replay_pcm_b, replay_frames_b) != replay_frames_b ||
        replay_frames_a != replay_frames_b ||
        memcmp(&replay_audio_a, &replay_audio_b, sizeof(replay_audio_a)) != 0 ||
        memcmp(replay_pcm_a, replay_pcm_b,
               replay_frames_a * 2u * sizeof(replay_pcm_a[0])) != 0) {
        fprintf(stderr, "snapshot audio continuation differs\n"); goto cleanup;
    }
    file = fopen(argv[2], "ab");
    if (!file || fputc(0x5a, file) == EOF || fclose(file) != 0) {
        file = NULL; fprintf(stderr, "corruption setup failed\n"); goto cleanup;
    }
    file = NULL;
    if (topgear_recomp_snapshot_load(game, argv[2], error, sizeof(error))) {
        fprintf(stderr, "snapshot with trailing data was accepted\n"); goto cleanup;
    }
    if (topgear_recomp_snapshot_load(game, "snapshot-that-does-not-exist.tgs",
                                     error, sizeof(error))) {
        fprintf(stderr, "missing snapshot was accepted\n"); goto cleanup;
    }
    ok = 1;
cleanup:
    if (file) fclose(file);
    if (game) topgear_recomp_destroy(game);
    free(after_pixels);
    free(before_pixels);
    free(rom);
    remove(argv[2]);
    return ok ? 0 : 1;
}
