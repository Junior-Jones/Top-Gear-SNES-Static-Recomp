#include "topgear_static_recomp.h"

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define ARRAY_COUNT(x) (sizeof(x) / sizeof((x)[0]))

typedef struct MusicTrack {
    uint8_t selector;
    const char *name;
    const char *filename;
    uint32_t seconds;
    uint16_t sequence_address;
    const char *evidence;
} MusicTrack;

/* Human-facing names follow the preserved Top Gear SPC set. The selector and
   sequence addresses are game-derived static-core authority. Keep the labels in
   this Linux frontend rather than making external soundtrack names core truth. */
static const MusicTrack k_tracks[] = {
    {0x01u, "Title",        "selector-01-title.wav",        258u, 0x13ABu,
     "Cold boot writes selector $01 at S-CPU $00:8077."},
    {0x02u, "Frankfurt",    "selector-02-frankfurt.wav",    207u, 0x13B3u,
     "Race selector for WRAM $1F06 low bits 3 (for example Frankfurt/San Francisco position)."},
    {0x03u, "Bordeaux",     "selector-03-bordeaux.wav",     246u, 0x13BBu,
     "Race selector for WRAM $1F06 low bits 2 (for example Bordeaux/New York position)."},
    {0x04u, "Hiroshima",    "selector-04-hiroshima.wav",    243u, 0x13C3u,
     "Race selector for WRAM $1F06 low bits 1 (for example Hiroshima/Los Angeles position)."},
    {0x05u, "Las Vegas",    "selector-05-las-vegas.wav",    416u, 0x13CBu,
     "Race selector for WRAM $1F06 low bits 0 (Las Vegas is the first proved USA race)."},
    {0x06u, "Qualified",    "selector-06-qualified.wav",     13u, 0x13D3u,
     "S-CPU $0F:858A loads $05; common routine increments to selector $06 on qualification path."},
    {0x07u, "Ending Theme", "selector-07-ending-theme.wav", 135u, 0x13DBu,
     "S-CPU $0F:8560 loads $06; common routine increments to selector $07 beside completion text."}
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

static const MusicTrack *find_track(unsigned selector) {
    size_t i;
    for (i = 0u; i < ARRAY_COUNT(k_tracks); ++i)
        if (k_tracks[i].selector == selector) return &k_tracks[i];
    return NULL;
}

static int record_track(TopGearRecomp *core, const MusicTrack *track,
                        uint32_t seconds, const char *path) {
    FILE *wav;
    char error[256];
    int16_t samples[4096u * 2u];
    uint64_t target_frames = (uint64_t)TOPGEAR_RECOMP_HOST_AUDIO_SAMPLE_RATE * seconds;
    uint64_t written_frames = 0u;
    uint64_t hash = UINT64_C(1469598103934665603);
    uint64_t total_master = (uint64_t)TOPGEAR_RECOMP_NTSC_MASTER_CLOCK_HZ * seconds;
    uint64_t advanced_master = 0u;
    const uint64_t chunk_master = TOPGEAR_RECOMP_NTSC_MASTER_CLOCK_HZ / 20u;
    TopGearStaticAudioStatus status;

    if (!topgear_recomp_music_preview_prepare(core, track->selector,
                                               error, sizeof(error))) {
        fprintf(stderr, "selector %02X prepare failed: %s\n", track->selector, error);
        return 0;
    }
    wav = fopen(path, "wb");
    if (!wav) {
        fprintf(stderr, "could not create %s\n", path);
        return 0;
    }
    if (!wav_begin(wav)) {
        fclose(wav);
        return 0;
    }
    while (advanced_master < total_master && written_frames < target_frames) {
        uint64_t remain = total_master - advanced_master;
        uint64_t step = remain < chunk_master ? remain : chunk_master;
        size_t available;
        if (!topgear_recomp_audio_preview_advance(core, step, error, sizeof(error))) {
            fprintf(stderr, "selector %02X audio advance failed: %s\n", track->selector, error);
            fclose(wav);
            return 0;
        }
        advanced_master += step;
        available = topgear_recomp_audio_available(core);
        while (available && written_frames < target_frames) {
            size_t want = available > 4096u ? 4096u : available;
            uint64_t left = target_frames - written_frames;
            size_t got;
            if ((uint64_t)want > left) want = (size_t)left;
            got = topgear_recomp_audio_read(core, samples, want);
            if (!got) break;
            if (fwrite(samples, sizeof(int16_t) * 2u, got, wav) != got) {
                fprintf(stderr, "WAV write failed for %s\n", path);
                fclose(wav);
                return 0;
            }
            hash = fnv1a64_update(hash, samples, got * sizeof(int16_t) * 2u);
            written_frames += got;
            available = topgear_recomp_audio_available(core);
        }
    }
    /* The measured SNES clock ratio may leave a very small nominal-sample gap.
       Advance bounded extra master clocks until the requested PCM frame count is
       present, never padding with host-generated silence. */
    while (written_frames < target_frames) {
        size_t available;
        if (!topgear_recomp_audio_preview_advance(core, chunk_master,
                                                  error, sizeof(error))) {
            fprintf(stderr, "selector %02X tail advance failed: %s\n", track->selector, error);
            fclose(wav);
            return 0;
        }
        available = topgear_recomp_audio_available(core);
        while (available && written_frames < target_frames) {
            size_t want = available > 4096u ? 4096u : available;
            uint64_t left = target_frames - written_frames;
            size_t got;
            if ((uint64_t)want > left) want = (size_t)left;
            got = topgear_recomp_audio_read(core, samples, want);
            if (!got) break;
            if (fwrite(samples, sizeof(int16_t) * 2u, got, wav) != got) {
                fclose(wav);
                return 0;
            }
            hash = fnv1a64_update(hash, samples, got * sizeof(int16_t) * 2u);
            written_frames += got;
            available = topgear_recomp_audio_available(core);
        }
    }
    memset(&status, 0, sizeof(status));
    (void)topgear_recomp_static_audio_status(core, &status);
    if (!wav_finish(wav, written_frames) || fclose(wav) != 0) return 0;
    printf("selector=%02X name=%s seconds=%u frames=%llu pcm-fnv1a64=%016llX aot-fail=%u dsp-fail=%u file=%s\n",
           track->selector, track->name, seconds,
           (unsigned long long)written_frames,
           (unsigned long long)hash,
           status.aot_failed, status.sdsp_static_failed, path);
    return !status.aot_failed && !status.sdsp_static_failed;
}

static void print_list(void) {
    size_t i;
    printf("Top Gear static-core music selectors (32,040 Hz stereo PCM)\n");
    for (i = 0u; i < ARRAY_COUNT(k_tracks); ++i) {
        printf("$%02X  %-12s  upload-index=$%02X  sequence=$%04X  default=%us\n    %s\n",
               k_tracks[i].selector, k_tracks[i].name,
               (unsigned)(k_tracks[i].selector - 1u),
               k_tracks[i].sequence_address, k_tracks[i].seconds,
               k_tracks[i].evidence);
    }
}

static int write_readme(const char *directory) {
    char path[4096];
    FILE *file;
    size_t i;
    if (snprintf(path, sizeof(path), "%s/README.txt", directory) < 0 ||
        strlen(path) >= sizeof(path)) return 0;
    file = fopen(path, "wb");
    if (!file) return 0;
    fprintf(file, "Top Gear SNES static-core music recordings\n\n");
    fprintf(file, "Source: exact Top Gear (USA) ROM through the Full Static S-SMP/S-DSP core.\n");
    fprintf(file, "Format: 32,040 Hz, stereo, signed 16-bit PCM WAV.\n");
    fprintf(file, "No downloaded soundtrack audio is used.\n");
    fprintf(file, "Each song is prepared with the game's coupled selector-1 resource upload chain and final APUIO0 selector.\n\n");
    for (i = 0u; i < ARRAY_COUNT(k_tracks); ++i)
        fprintf(file, "$%02X  %-12s  ARAM sequence $%04X  %us  %s\n",
                k_tracks[i].selector, k_tracks[i].name,
                k_tracks[i].sequence_address, k_tracks[i].seconds,
                k_tracks[i].filename);
    return fclose(file) == 0;
}

int main(int argc, char **argv) {
    uint8_t *rom = NULL;
    size_t rom_size = 0u;
    TopGearRecomp *core = NULL;
    char error[256];
    int ok = 1;

    if (argc < 3) {
        fprintf(stderr,
            "usage:\n  %s ROM --list\n  %s ROM --record SELECTOR SECONDS OUTPUT.wav\n  %s ROM --record-all OUTPUT_DIRECTORY\n",
            argv[0], argv[0], argv[0]);
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
    } else if (strcmp(argv[2], "--record") == 0 && argc == 6) {
        unsigned selector = (unsigned)strtoul(argv[3], NULL, 0);
        unsigned long seconds = strtoul(argv[4], NULL, 0);
        const MusicTrack *track = find_track(selector);
        if (!track || seconds == 0ul || seconds > 3600ul) {
            fprintf(stderr, "selector must be 1-7 and seconds must be 1-3600\n");
            ok = 0;
        } else {
            ok = record_track(core, track, (uint32_t)seconds, argv[5]);
        }
    } else if (strcmp(argv[2], "--record-all") == 0 && argc == 4) {
        size_t i;
        if (!ensure_directory(argv[3])) {
            fprintf(stderr, "could not create output directory: %s\n", argv[3]);
            ok = 0;
        } else {
            for (i = 0u; i < ARRAY_COUNT(k_tracks) && ok; ++i) {
                char path[4096];
                int length = snprintf(path, sizeof(path), "%s/%s",
                                      argv[3], k_tracks[i].filename);
                if (length < 0 || (size_t)length >= sizeof(path)) {
                    ok = 0;
                    break;
                }
                fprintf(stderr, "recording $%02X %s (%us)\n",
                        k_tracks[i].selector, k_tracks[i].name,
                        k_tracks[i].seconds);
                ok = record_track(core, &k_tracks[i], k_tracks[i].seconds, path);
            }
            if (ok) ok = write_readme(argv[3]);
        }
    } else {
        fprintf(stderr, "invalid command; use --list, --record, or --record-all\n");
        ok = 0;
    }
    topgear_recomp_destroy(core);
    return ok ? 0 : 1;
}
