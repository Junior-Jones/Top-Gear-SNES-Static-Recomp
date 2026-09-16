#include "topgear_internal.h"
#include "../static-audio/topgear-bapu-aot/sc_static_apu.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct WavCapture {
    FILE *file;
    uint64_t frames;
} WavCapture;

static void write_le16(FILE *file, uint16_t value) {
    (void)fputc((int)(value & 0xffu), file);
    (void)fputc((int)((value >> 8u) & 0xffu), file);
}

static void write_le32(FILE *file, uint32_t value) {
    write_le16(file, (uint16_t)value);
    write_le16(file, (uint16_t)(value >> 16u));
}

static int wav_open(WavCapture *wav, const char *path) {
    if (!wav || !path) return 0;
    memset(wav, 0, sizeof(*wav));
    wav->file = fopen(path, "wb");
    if (!wav->file) return 0;
    (void)fwrite("RIFF", 1u, 4u, wav->file);
    write_le32(wav->file, 0u);
    (void)fwrite("WAVEfmt ", 1u, 8u, wav->file);
    write_le32(wav->file, 16u);
    write_le16(wav->file, 1u);
    write_le16(wav->file, TOPGEAR_RECOMP_AUDIO_CHANNELS);
    write_le32(wav->file, TOPGEAR_RECOMP_HOST_AUDIO_SAMPLE_RATE);
    write_le32(wav->file, TOPGEAR_RECOMP_HOST_AUDIO_SAMPLE_RATE * 4u);
    write_le16(wav->file, 4u);
    write_le16(wav->file, TOPGEAR_RECOMP_AUDIO_BITS_PER_SAMPLE);
    (void)fwrite("data", 1u, 4u, wav->file);
    write_le32(wav->file, 0u);
    return 1;
}

static int wav_drain(TopGearRecomp *core, WavCapture *wav) {
    int16_t samples[4096u * 2u];
    size_t count;
    if (!core || !wav || !wav->file) return 0;
    while ((count = topgear_recomp_audio_read(core, samples, 4096u)) != 0u) {
        if (fwrite(samples, sizeof(int16_t) * 2u, count, wav->file) != count)
            return 0;
        wav->frames += count;
    }
    return 1;
}

static int wav_close(WavCapture *wav) {
    uint32_t bytes;
    int ok;
    if (!wav || !wav->file || wav->frames > UINT32_MAX / 4u) return 0;
    bytes = (uint32_t)wav->frames * 4u;
    if (fseek(wav->file, 4L, SEEK_SET) != 0) return 0;
    write_le32(wav->file, 36u + bytes);
    if (fseek(wav->file, 40L, SEEK_SET) != 0) return 0;
    write_le32(wav->file, bytes);
    ok = fclose(wav->file) == 0;
    wav->file = NULL;
    return ok;
}

static int load_file(const char *path, uint8_t **data, size_t *bytes) {
    FILE *file;
    long size;
    if (!path || !data || !bytes) return 0;
    file = fopen(path, "rb");
    if (!file) return 0;
    if (fseek(file, 0L, SEEK_END) != 0 || (size = ftell(file)) < 0L ||
        fseek(file, 0L, SEEK_SET) != 0) {
        fclose(file);
        return 0;
    }
    *data = (uint8_t *)malloc((size_t)size);
    *bytes = (size_t)size;
    if (!*data || fread(*data, 1u, *bytes, file) != *bytes) {
        free(*data);
        *data = NULL;
        fclose(file);
        return 0;
    }
    return fclose(file) == 0;
}

static uint16_t input_for_frame(uint32_t frame) {
    static const uint32_t down[] = {1860u, 1890u, 1920u, 1950u};
    static const uint32_t up[] = {1980u, 2010u, 2040u, 2070u};
    size_t index;
    if (frame >= 1560u && frame < 1680u) return TOPGEAR_INPUT_START;
    for (index = 0u; index < sizeof(down) / sizeof(down[0]); ++index)
        if (frame >= down[index] && frame < down[index] + 6u)
            return TOPGEAR_INPUT_DOWN;
    for (index = 0u; index < sizeof(up) / sizeof(up[0]); ++index)
        if (frame >= up[index] && frame < up[index] + 6u)
            return TOPGEAR_INPUT_UP;
    return 0u;
}

static uint64_t fnv1a64(const uint8_t *data, size_t bytes) {
    uint64_t hash = UINT64_C(1469598103934665603);
    size_t index;
    for (index = 0u; index < bytes; ++index) {
        hash ^= data[index];
        hash *= UINT64_C(1099511628211);
    }
    return hash;
}

static int advance_neutral(TopGearRecomp *core, unsigned frames) {
    TopGearRecompFrameResult result;
    int16_t discard[4096u * 2u];
    unsigned frame;
    for (frame = 0u; frame < frames; ++frame) {
        if (!topgear_recomp_advance_headless(core, 0u, 0u, 1u, &result))
            return 0;
        while (topgear_recomp_audio_read(core, discard, 4096u) != 0u) {}
    }
    return 1;
}

int main(int argc, char **argv) {
    const uint32_t capture_start_frame = 1440u;
    const uint32_t final_frame = 2130u;
    const uint64_t title_original_b580_hash = UINT64_C(0x06E9D2E83F8B456A);
    uint8_t *rom = NULL;
    size_t rom_bytes = 0u;
    TopGearRecomp *core = NULL;
    TopGearRecompFrameResult result;
    TopGearStaticAudioStatus audio;
    WavCapture wav;
    uint8_t relocated[54u];
    uint8_t original_title[0x600u];
    uint8_t directory[4];
    uint16_t selection = UINT16_C(0xffff);
    static const uint32_t probe_frames[8] = {
        1868u, 1898u, 1928u, 1958u, 1988u, 2018u, 2048u, 2078u
    };
    /* Stage-1 menu remodel intentionally replaces the original five-row root
       OPTIONS selector with four root entries.  Keep this audio regression
       tied to semantic accepted navigation: four Down movements now wrap
       0 -> 1 -> 2 -> 3 -> 0, followed by the mirrored Up sequence. */
    static const uint16_t expected_sequence[8] = {1u, 2u, 3u, 0u, 3u, 2u, 1u, 0u};
    uint16_t observed_sequence[8] = {0u};
    size_t probe_index = 0u;
    uint32_t frame;
    char error[256];
    int recording;
    int ok = 1;

    if (argc < 2 || argc > 3) {
        fprintf(stderr, "usage: %s ROM [OUTPUT.wav]\n", argv[0]);
        return 2;
    }
    recording = argc == 3;
    memset(&wav, 0, sizeof(wav));
    if (!load_file(argv[1], &rom, &rom_bytes)) {
        fprintf(stderr, "could not read ROM\n");
        return 2;
    }
    if (!topgear_recomp_create(&core, rom, rom_bytes, error, sizeof(error))) {
        fprintf(stderr, "core create failed: %s\n", error);
        free(rom);
        return 1;
    }
    if (recording && !wav_open(&wav, argv[2])) {
        fprintf(stderr, "could not open WAV output\n");
        topgear_recomp_destroy(core);
        free(rom);
        return 1;
    }

    for (frame = 0u; frame < final_frame; ++frame) {
        uint16_t input = input_for_frame(frame);
        if (!topgear_recomp_advance_headless(core, input, 0u, 1u, &result)) {
            fprintf(stderr, "frame %u failed: %s\n", frame,
                    topgear_recomp_last_error(core));
            ok = 0;
            break;
        }
        if (probe_index < 8u && frame == probe_frames[probe_index]) {
            if (!topgear_recomp_read_wram(core, 0x005au,
                                           &observed_sequence[probe_index],
                                           sizeof(observed_sequence[probe_index]))) {
                fprintf(stderr, "could not read menu selector at probe %zu\n", probe_index);
                ok = 0;
                break;
            }
            probe_index++;
        }
        if (recording && frame >= capture_start_frame) {
            if (!wav_drain(core, &wav)) {
                fprintf(stderr, "WAV capture failed\n");
                ok = 0;
                break;
            }
        } else {
            int16_t discard[4096u * 2u];
            while (topgear_recomp_audio_read(core, discard, 4096u) != 0u) {}
        }
    }

    if (recording) {
        if (ok && !wav_drain(core, &wav)) ok = 0;
        if (!wav_close(&wav)) ok = 0;
    }

    if (!topgear_recomp_read_wram(core, 0x005au, &selection,
                                   sizeof(selection))) ok = 0;
    if (!sc_static_apu_read_cue_aram(0x00c000u, relocated,
                                  sizeof(relocated))) ok = 0;
    if (!topgear_recomp_read_aram(core, 0x00b580u, original_title,
                                  sizeof(original_title))) ok = 0;
    if (!sc_static_apu_read_cue_aram(0x008a40u, directory,
                                  sizeof(directory))) ok = 0;
    memset(&audio, 0, sizeof(audio));
    if (!topgear_recomp_static_audio_status(core, &audio)) ok = 0;

    printf("main-menu selector final=%u (expected 0 after four Down/four Up)\n",
           (unsigned)selection);
    printf("accepted selector sequence=");
    for (probe_index = 0u; probe_index < 8u; ++probe_index) {
        printf("%s%u", probe_index ? "," : "",
               (unsigned)observed_sequence[probe_index]);
    }
    putchar('\n');
    printf("resource installs=%llu navigation changes=%llu command starts=%llu acks=%llu clears=%llu neutral-acks=%llu state=%u queued=%u\n",
           (unsigned long long)core->mod_insert_audio_resource_install_count,
           (unsigned long long)core->mod_insert_audio_navigation_change_count,
           (unsigned long long)core->mod_insert_audio_command_start_count,
           (unsigned long long)core->mod_insert_audio_command_ack_count,
           (unsigned long long)core->mod_insert_audio_command_clear_count,
           (unsigned long long)core->mod_insert_audio_neutral_ack_count,
           (unsigned)core->mod_insert_audio_sfx_state,
           (unsigned)core->mod_insert_audio_sfx_queued);
    printf("SimCity cue keyons=%llu keyoffs=%llu restores=%llu imported=%u\n",
           (unsigned long long)core->mod_insert_audio_cue_keyon_count,
           (unsigned long long)core->mod_insert_audio_cue_keyoff_count,
           (unsigned long long)core->mod_insert_audio_cue_restore_count,
           (unsigned)core->mod_insert_audio_simcity_resource_installed);
    printf("SRCN10=%02X%02X/%02X%02X relocated-hash=%016llX title-B580-hash=%016llX\n",
           directory[1], directory[0], directory[3], directory[2],
           (unsigned long long)fnv1a64(relocated, sizeof(relocated)),
           (unsigned long long)fnv1a64(original_title, sizeof(original_title)));
    printf("audio aot-fail=%u dsp-fail=%u pcm=%llu hash=%016llX",
           (unsigned)audio.aot_failed, (unsigned)audio.sdsp_static_failed,
           (unsigned long long)audio.pcm_frames,
           (unsigned long long)audio.pcm_hash);
    if (recording) printf(" wav-frames=%llu file=%s",
                          (unsigned long long)wav.frames, argv[2]);
    putchar('\n');

    if (probe_index != 8u ||
        memcmp(observed_sequence, expected_sequence, sizeof(expected_sequence)) != 0 ||
        selection != 0u || core->mod_insert_audio_resource_install_count < 1u ||
        core->mod_insert_audio_navigation_change_count != 8u ||
        core->mod_insert_audio_command_start_count != 8u ||
        core->mod_insert_audio_command_ack_count != 8u ||
        core->mod_insert_audio_command_clear_count != 8u ||
        core->mod_insert_audio_neutral_ack_count != 8u ||
        core->mod_insert_audio_sfx_state != 0u ||
        core->mod_insert_audio_sfx_queued != 0u ||
        directory[0] != 0x00u || directory[1] != 0xc0u ||
        directory[2] != 0x1bu || directory[3] != 0xc0u ||
        fnv1a64(relocated, sizeof(relocated)) != UINT64_C(0xC29396B71B378632) ||
        !core->mod_insert_audio_simcity_resource_installed ||
        core->mod_insert_audio_cue_keyon_count != 8u ||
        core->mod_insert_audio_cue_keyoff_count != 8u ||
        core->mod_insert_audio_cue_restore_count != 8u ||
        fnv1a64(original_title, sizeof(original_title)) != title_original_b580_hash ||
        audio.aot_failed || audio.sdsp_static_failed) {
        ok = 0;
    }

    /* Rapid real-world input can replace a movement cue with Accept or Start.
       Verify each priority transition drains cleanly and that re-entering the
       menu does not rewrite private sample RAM during an active cue. */
    if (ok) {
        uint64_t installs = core->mod_insert_audio_resource_install_count;
        tg_mod_insert_audio_navigation(core);
        if (!advance_neutral(core, 1u) || core->mod_insert_audio_sfx_state != 2u)
            ok = 0;
        tg_mod_insert_audio_accept(core);
        if (core->mod_insert_audio_sfx_state != 7u ||
            !advance_neutral(core, 90u) || core->mod_insert_audio_sfx_state != 0u ||
            core->mod_insert_audio_sfx_queued != 0u) ok = 0;

        tg_mod_insert_audio_navigation(core);
        if (!advance_neutral(core, 1u) || core->mod_insert_audio_sfx_state != 2u)
            ok = 0;
        tg_mod_insert_audio_start_race(core);
        if (core->mod_insert_audio_sfx_state != 5u ||
            !advance_neutral(core, 120u) || core->mod_insert_audio_sfx_state != 0u ||
            core->mod_insert_audio_sfx_queued != 0u) ok = 0;

        tg_mod_insert_audio_navigation(core);
        if (!advance_neutral(core, 1u) ||
            !tg_mod_insert_audio_main_menu_enter(core) ||
            core->mod_insert_audio_resource_install_count != installs ||
            !advance_neutral(core, 90u) || core->mod_insert_audio_sfx_state != 0u)
            ok = 0;
        memset(&audio, 0, sizeof(audio));
        if (!topgear_recomp_static_audio_status(core, &audio) ||
            audio.aot_failed || audio.sdsp_static_failed) ok = 0;
    }

    topgear_recomp_destroy(core);
    free(rom);
    if (!ok) {
        fprintf(stderr, "menu insert-audio prototype FAIL\n");
        return 1;
    }
    printf("menu insert-audio prototype PASS, including rapid cue priority and idempotent resource install\n");
    return 0;
}
