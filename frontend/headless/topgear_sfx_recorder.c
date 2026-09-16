#include "topgear_static_recomp.h"

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define ARRAY_COUNT(x) (sizeof(x) / sizeof((x)[0]))
#define AVG_NTSC_FRAME_MASTER_CLOCKS 357366u

typedef struct EnginePitchEvent {
    uint32_t frame;
    uint16_t pitch;
} EnginePitchEvent;

#include "generated/topgear_engine_auto_timeline.inc"
#include "generated/topgear_engine_manual_timeline.inc"

typedef struct RaceEffect {
    const char *name;
    const char *filename;
    uint8_t command;
    uint32_t milliseconds;
    const char *evidence;
} RaceEffect;

static const RaceEffect k_effects[] = {
    {"boost", "04-boost.wav", 0x05u, 450u,
     "Live four-race trace: boost input A produced APUIO1=$05 at frame 7337."},
    {"tire-skid", "05-tire-skid.wav", 0x0Au, 250u,
     "Race NMI consumes WRAM $1E67 and sends APUIO1=$0A; live trace follows steering/skid events."},
    {"collision", "06-collision.wav", 0x0Bu, 600u,
     "Race NMI consumes WRAM $1EF5 bit $80 and sends APUIO1=$0B; live trace coincides with sharp collision speed losses."},
    {"finish-line", "07-finish-line.wav", 0x07u, 850u,
     "S-CPU $05:E7D5 sets WRAM $1EF5 bit $04 when lap count reaches the required count; NMI sends APUIO1=$07."}
};

static int load_file(const char *path, uint8_t **data, size_t *size) {
    FILE *file;
    long length;
    if (!data || !size) return 0;
    *data = NULL;
    *size = 0u;
    file = fopen(path, "rb");
    if (!file) return 0;
    if (fseek(file, 0, SEEK_END) != 0 || (length = ftell(file)) < 0 ||
        fseek(file, 0, SEEK_SET) != 0) {
        fclose(file);
        return 0;
    }
    *data = (uint8_t *)malloc((size_t)length);
    if (!*data || fread(*data, 1u, (size_t)length, file) != (size_t)length) {
        free(*data);
        *data = NULL;
        fclose(file);
        return 0;
    }
    fclose(file);
    *size = (size_t)length;
    return 1;
}

static int ensure_directory(const char *path) {
    char copy[4096];
    size_t index;
    struct stat st;
    if (!path || !path[0] || strlen(path) >= sizeof(copy)) return 0;
    (void)strcpy(copy, path);
    for (index = 1u; copy[index]; ++index) {
        if (copy[index] == '/') {
            copy[index] = '\0';
            if (stat(copy, &st) != 0) {
                if (mkdir(copy, 0777) != 0 && errno != EEXIST) return 0;
            } else if (!S_ISDIR(st.st_mode)) return 0;
            copy[index] = '/';
        }
    }
    if (stat(copy, &st) == 0) return S_ISDIR(st.st_mode);
    return mkdir(copy, 0777) == 0 || errno == EEXIST;
}

static void put_u16le(FILE *file, uint16_t value) {
    unsigned char bytes[2] = {(unsigned char)value, (unsigned char)(value >> 8u)};
    (void)fwrite(bytes, 1u, sizeof(bytes), file);
}

static void put_u32le(FILE *file, uint32_t value) {
    unsigned char bytes[4] = {
        (unsigned char)value, (unsigned char)(value >> 8u),
        (unsigned char)(value >> 16u), (unsigned char)(value >> 24u)
    };
    (void)fwrite(bytes, 1u, sizeof(bytes), file);
}

static int wav_begin(FILE *file) {
    if (!file) return 0;
    if (fwrite("RIFF", 1u, 4u, file) != 4u) return 0;
    put_u32le(file, 0u);
    if (fwrite("WAVEfmt ", 1u, 8u, file) != 8u) return 0;
    put_u32le(file, 16u);
    put_u16le(file, 1u);
    put_u16le(file, 2u);
    put_u32le(file, TOPGEAR_RECOMP_HOST_AUDIO_SAMPLE_RATE);
    put_u32le(file, TOPGEAR_RECOMP_HOST_AUDIO_SAMPLE_RATE * 4u);
    put_u16le(file, 4u);
    put_u16le(file, 16u);
    if (fwrite("data", 1u, 4u, file) != 4u) return 0;
    put_u32le(file, 0u);
    return ferror(file) == 0;
}

static int wav_finish(FILE *file, uint64_t frames) {
    uint64_t data_bytes = frames * 4u;
    if (!file || data_bytes > UINT32_MAX) return 0;
    if (fseek(file, 4, SEEK_SET) != 0) return 0;
    put_u32le(file, (uint32_t)(36u + data_bytes));
    if (fseek(file, 40, SEEK_SET) != 0) return 0;
    put_u32le(file, (uint32_t)data_bytes);
    return fflush(file) == 0;
}

static uint64_t fnv1a64_update(uint64_t hash, const void *data, size_t bytes) {
    const uint8_t *p = (const uint8_t *)data;
    size_t i;
    for (i = 0u; i < bytes; ++i) {
        hash ^= p[i];
        hash *= UINT64_C(1099511628211);
    }
    return hash;
}

typedef struct WavCapture {
    FILE *file;
    uint64_t frames;
    uint64_t hash;
} WavCapture;

static int drain_audio(TopGearRecomp *core, WavCapture *capture) {
    int16_t samples[4096u * 2u];
    while (topgear_recomp_audio_available(core) > 0u) {
        size_t got = topgear_recomp_audio_read(core, samples, 4096u);
        if (!got) break;
        if (capture && capture->file) {
            if (fwrite(samples, sizeof(int16_t) * 2u, got, capture->file) != got) return 0;
            capture->hash = fnv1a64_update(capture->hash, samples,
                                           got * sizeof(int16_t) * 2u);
            capture->frames += (uint64_t)got;
        }
    }
    return 1;
}

static int advance_and_capture(TopGearRecomp *core, uint64_t master_clocks,
                               WavCapture *capture, char *error, size_t cap) {
    const uint64_t chunk = TOPGEAR_RECOMP_NTSC_MASTER_CLOCK_HZ / 50u;
    uint64_t done = 0u;
    while (done < master_clocks) {
        uint64_t left = master_clocks - done;
        uint64_t step = left < chunk ? left : chunk;
        if (!topgear_recomp_audio_preview_advance(core, step, error, cap)) return 0;
        if (!drain_audio(core, capture)) {
            (void)snprintf(error, cap, "WAV write failed while draining Full Static audio.");
            return 0;
        }
        done += step;
    }
    return 1;
}

static int prepare_race_resources(TopGearRecomp *core, char *error, size_t cap) {
    /* The race effects and engines use the race upload bank. Selector $05 is
       the first USA/Las Vegas race bank proven by the four-race campaign. Load
       its full selector-1 upload chain, then stop music before isolating SFX. */
    if (!topgear_recomp_music_preview_prepare(core, 0x05u, error, cap)) return 0;
    if (!topgear_recomp_music_command(core, 0x00u, error, cap)) return 0;
    if (!topgear_recomp_audio_preview_advance(core,
            TOPGEAR_RECOMP_NTSC_MASTER_CLOCK_HZ / 5u, error, cap)) return 0;
    (void)topgear_recomp_audio_discard(core, topgear_recomp_audio_available(core));
    topgear_recomp_audio_clear(core);
    return 1;
}

static int start_wav(const char *path, WavCapture *capture) {
    memset(capture, 0, sizeof(*capture));
    capture->file = fopen(path, "wb");
    capture->hash = UINT64_C(1469598103934665603);
    if (!capture->file) return 0;
    if (!wav_begin(capture->file)) {
        fclose(capture->file);
        capture->file = NULL;
        return 0;
    }
    return 1;
}

static int close_wav(WavCapture *capture) {
    int ok;
    if (!capture || !capture->file) return 0;
    ok = wav_finish(capture->file, capture->frames) && fclose(capture->file) == 0;
    capture->file = NULL;
    return ok;
}

static int record_effect(TopGearRecomp *core, const RaceEffect *effect,
                         const char *path) {
    char error[256];
    WavCapture wav;
    TopGearStaticAudioStatus status;
    if (!prepare_race_resources(core, error, sizeof(error))) {
        fprintf(stderr, "%s prepare failed: %s\n", effect->name, error);
        return 0;
    }
    if (!start_wav(path, &wav)) return 0;
    if (!topgear_recomp_sound_command_pulse(core, effect->command, error, sizeof(error)) ||
        !advance_and_capture(core,
            ((uint64_t)TOPGEAR_RECOMP_NTSC_MASTER_CLOCK_HZ * effect->milliseconds) / 1000u,
            &wav, error, sizeof(error))) {
        fprintf(stderr, "%s failed: %s\n", effect->name, error);
        fclose(wav.file);
        return 0;
    }
    memset(&status, 0, sizeof(status));
    (void)topgear_recomp_static_audio_status(core, &status);
    if (!close_wav(&wav)) return 0;
    printf("effect=%s command=%02X frames=%llu pcm-fnv1a64=%016llX aot-fail=%u dsp-fail=%u file=%s\n",
           effect->name, effect->command, (unsigned long long)wav.frames,
           (unsigned long long)wav.hash, status.aot_failed,
           status.sdsp_static_failed, path);
    return !status.aot_failed && !status.sdsp_static_failed;
}

static int setup_engine(TopGearRecomp *core, uint16_t initial_pitch,
                        WavCapture *wav, char *error, size_t cap) {
    if (!topgear_recomp_sound_command(core, 0x02u, error, cap)) return 0;
    /* Let the S-SMP consume the voice-4 setup command before the first $03
       parameter update, matching the real race setup -> NMI ordering. */
    if (!advance_and_capture(core, AVG_NTSC_FRAME_MASTER_CLOCKS, wav, error, cap)) return 0;
    if (!topgear_recomp_sound_parameter_command(core, 0x03u, initial_pitch,
                                                 error, cap)) return 0;
    return 1;
}

static int record_engine_fixed(TopGearRecomp *core, uint16_t pitch,
                               uint32_t milliseconds, const char *path,
                               const char *name) {
    char error[256];
    WavCapture wav;
    TopGearStaticAudioStatus status;
    if (!prepare_race_resources(core, error, sizeof(error))) {
        fprintf(stderr, "%s prepare failed: %s\n", name, error);
        return 0;
    }
    if (!start_wav(path, &wav)) return 0;
    if (!setup_engine(core, pitch, &wav, error, sizeof(error)) ||
        !advance_and_capture(core,
            ((uint64_t)TOPGEAR_RECOMP_NTSC_MASTER_CLOCK_HZ * milliseconds) / 1000u,
            &wav, error, sizeof(error))) {
        fprintf(stderr, "%s failed: %s\n", name, error);
        fclose(wav.file);
        return 0;
    }
    memset(&status, 0, sizeof(status));
    (void)topgear_recomp_static_audio_status(core, &status);
    if (!close_wav(&wav)) return 0;
    printf("engine=%s pitch=%04X frames=%llu pcm-fnv1a64=%016llX aot-fail=%u dsp-fail=%u file=%s\n",
           name, pitch, (unsigned long long)wav.frames,
           (unsigned long long)wav.hash, status.aot_failed,
           status.sdsp_static_failed, path);
    return !status.aot_failed && !status.sdsp_static_failed;
}

static int record_engine_timeline(TopGearRecomp *core,
                                  const EnginePitchEvent *events, size_t count,
                                  uint32_t tail_frames, const char *path,
                                  const char *name) {
    char error[256];
    WavCapture wav;
    TopGearStaticAudioStatus status;
    size_t index;
    uint32_t at_frame = 0u;
    if (!events || count == 0u) return 0;
    if (!prepare_race_resources(core, error, sizeof(error))) {
        fprintf(stderr, "%s prepare failed: %s\n", name, error);
        return 0;
    }
    if (!start_wav(path, &wav)) return 0;
    if (!setup_engine(core, events[0].pitch, &wav, error, sizeof(error))) {
        fprintf(stderr, "%s engine setup failed: %s\n", name, error);
        fclose(wav.file);
        return 0;
    }
    for (index = 1u; index < count; ++index) {
        uint32_t delta = events[index].frame - at_frame;
        if (delta && !advance_and_capture(core,
                (uint64_t)delta * AVG_NTSC_FRAME_MASTER_CLOCKS,
                &wav, error, sizeof(error))) {
            fprintf(stderr, "%s timeline advance failed: %s\n", name, error);
            fclose(wav.file);
            return 0;
        }
        if (!topgear_recomp_sound_parameter_command(core, 0x03u,
                    events[index].pitch, error, sizeof(error))) {
            fprintf(stderr, "%s pitch update failed: %s\n", name, error);
            fclose(wav.file);
            return 0;
        }
        at_frame = events[index].frame;
    }
    if (!advance_and_capture(core,
            (uint64_t)tail_frames * AVG_NTSC_FRAME_MASTER_CLOCKS,
            &wav, error, sizeof(error))) {
        fprintf(stderr, "%s tail failed: %s\n", name, error);
        fclose(wav.file);
        return 0;
    }
    memset(&status, 0, sizeof(status));
    (void)topgear_recomp_static_audio_status(core, &status);
    if (!close_wav(&wav)) return 0;
    printf("engine=%s events=%zu source-frames=%u frames=%llu pcm-fnv1a64=%016llX aot-fail=%u dsp-fail=%u file=%s\n",
           name, count, events[count - 1u].frame,
           (unsigned long long)wav.frames, (unsigned long long)wav.hash,
           status.aot_failed, status.sdsp_static_failed, path);
    return !status.aot_failed && !status.sdsp_static_failed;
}

static const RaceEffect *find_effect(const char *name) {
    size_t index;
    for (index = 0u; index < ARRAY_COUNT(k_effects); ++index)
        if (strcmp(k_effects[index].name, name) == 0) return &k_effects[index];
    return NULL;
}

static void print_list(void) {
    size_t index;
    printf("Top Gear proved Player-1 race audio effects\n");
    printf("engine  setup=$02 pitch/update=$03 parameter=APUIO2/3; pitch=(max(WRAM $1E5E,0)+$0400)\n");
    for (index = 0u; index < ARRAY_COUNT(k_effects); ++index)
        printf("%-12s command=$%02X  %s\n", k_effects[index].name,
               k_effects[index].command, k_effects[index].evidence);
    printf("Player-2 mirrors: engine $0D/$0E, boost $10, finish $12, tire/skid $15, collision $16.\n");
    printf("Boost/skid are one-shot BRR effects on DSP voice 5; finish-line is a one-shot on DSP voice 4.\n");
    printf("Discrete previews pulse APUIO1 only through the S-SMP acknowledgement, then restore neutral $00 so one event cannot retrigger.\n");
    printf("Driver-only $08/$09 are SRCN $13 pan variants; $1A-$1D remain unmapped and are not named as gameplay effects.\n");
}

static int write_readme(const char *directory) {
    char path[4096];
    FILE *file;
    if (snprintf(path, sizeof(path), "%s/README.txt", directory) < 0 ||
        strlen(path) >= sizeof(path)) return 0;
    file = fopen(path, "wb");
    if (!file) return 0;
    fprintf(file, "Top Gear SNES Full Static race sound-effect recordings\n\n");
    fprintf(file, "Source: exact Top Gear (USA) ROM and game-derived race APU state.\n");
    fprintf(file, "Format: 32,040 Hz stereo signed 16-bit PCM WAV.\n");
    fprintf(file, "The Las Vegas race resource upload chain is loaded before isolation. Music is then stopped.\n");
    fprintf(file, "IMPORTANT: discrete effects are APUIO1 event commands. APUIO1 is level-sensitive, so a preview must hold the command only until the S-SMP acknowledges it and then immediately restore neutral $00. Leaving the byte asserted incorrectly retriggers the same effect over and over.\n");
    fprintf(file, "The proved BRR sources for boost, tire/skid and finish-line terminate naturally (END=1, LOOP=0). Boost/skid use DSP voice 5; finish-line uses DSP voice 4. The WAVs therefore contain one command pulse and one natural sample traversal only.\n\n");
    fprintf(file, "01-engine-idle.wav - real P1 engine voice $02 at pitch $0400.\n");
    fprintf(file, "02-engine-automatic-acceleration.wav - replay of live automatic Race-1 APUIO2/3 pitch commands.\n");
    fprintf(file, "03-engine-manual-1-to-2-to-3.wav - replay of the existing manual Las Vegas route, including real shift pitch drops.\n");
    fprintf(file, "04-boost.wav - live race command $05.\n");
    fprintf(file, "05-tire-skid.wav - live race command $0A.\n");
    fprintf(file, "06-collision.wav - live race command $0B.\n");
    fprintf(file, "07-finish-line.wav - live race command $07.\n\n");
    fprintf(file, "Driver audit: $08/$09 are left/right pan variants of the same SRCN $13 family as finish; Player-2 uses mirrored commands $12/$13/$14. Commands $1A-$1D use SRCN $16 but no normal four-race gameplay trigger has been proved, so they remain unmapped rather than being given guessed names.\n\n");
    fprintf(file, "Engine mechanism: race setup sends $02 for P1 voice 4. During race NMI, WRAM $1E5E is clamped at zero, $0400 is added, the result is written to APUIO2/APUIO3, then command $03 updates pitch. Manual gear changes alter the gameplay value feeding $1E5E; they do not swap to another engine sample.\n");
    return fclose(file) == 0;
}

static int path_join(char *out, size_t cap, const char *directory,
                     const char *name) {
    int length = snprintf(out, cap, "%s/%s", directory, name);
    return length >= 0 && (size_t)length < cap;
}

static int record_all(TopGearRecomp *core, const char *directory) {
    char path[4096];
    size_t index;
    if (!ensure_directory(directory)) return 0;
    if (!path_join(path, sizeof(path), directory, "01-engine-idle.wav") ||
        !record_engine_fixed(core, 0x0400u, 3000u, path, "idle")) return 0;
    if (!path_join(path, sizeof(path), directory, "02-engine-automatic-acceleration.wav") ||
        !record_engine_timeline(core, k_engine_auto_timeline,
            ARRAY_COUNT(k_engine_auto_timeline), 60u, path,
            "automatic-acceleration")) return 0;
    if (!path_join(path, sizeof(path), directory, "03-engine-manual-1-to-2-to-3.wav") ||
        !record_engine_timeline(core, k_engine_manual_timeline,
            ARRAY_COUNT(k_engine_manual_timeline), 60u, path,
            "manual-1-to-2-to-3")) return 0;
    for (index = 0u; index < ARRAY_COUNT(k_effects); ++index) {
        if (!path_join(path, sizeof(path), directory, k_effects[index].filename) ||
            !record_effect(core, &k_effects[index], path)) return 0;
    }
    return write_readme(directory);
}

int main(int argc, char **argv) {
    uint8_t *rom = NULL;
    size_t rom_size = 0u;
    TopGearRecomp *core = NULL;
    char error[256];
    int ok = 1;
    if (argc < 3) {
        fprintf(stderr,
            "usage:\n  %s ROM --list\n  %s ROM --record-effect NAME OUTPUT.wav\n  %s ROM --record-engine-pitch PITCH_HEX MILLISECONDS OUTPUT.wav\n  %s ROM --record-all OUTPUT_DIRECTORY\n",
            argv[0], argv[0], argv[0], argv[0]);
        return 2;
    }
    if (!load_file(argv[1], &rom, &rom_size)) {
        fprintf(stderr, "could not read ROM: %s\n", argv[1]);
        return 2;
    }
    if (!topgear_recomp_create(&core, rom, rom_size, error, sizeof(error))) {
        fprintf(stderr, "core create failed: %s\n", error);
        free(rom);
        return 1;
    }
    free(rom);
    if (strcmp(argv[2], "--list") == 0) {
        print_list();
    } else if (strcmp(argv[2], "--record-effect") == 0 && argc == 5) {
        const RaceEffect *effect = find_effect(argv[3]);
        if (!effect) {
            fprintf(stderr, "unknown effect: %s\n", argv[3]);
            ok = 0;
        } else ok = record_effect(core, effect, argv[4]);
    } else if (strcmp(argv[2], "--record-engine-pitch") == 0 && argc == 6) {
        unsigned long pitch = strtoul(argv[3], NULL, 16);
        unsigned long milliseconds = strtoul(argv[4], NULL, 0);
        if (pitch > 0xFFFFul || milliseconds == 0ul || milliseconds > 600000ul) {
            fprintf(stderr, "pitch must be 0000-FFFF and milliseconds 1-600000\n");
            ok = 0;
        } else ok = record_engine_fixed(core, (uint16_t)pitch,
                                         (uint32_t)milliseconds, argv[5],
                                         "custom-pitch");
    } else if (strcmp(argv[2], "--record-all") == 0 && argc == 4) {
        ok = record_all(core, argv[3]);
    } else {
        fprintf(stderr, "invalid command; use --list, --record-effect, --record-engine-pitch, or --record-all\n");
        ok = 0;
    }
    topgear_recomp_destroy(core);
    return ok ? 0 : 1;
}
