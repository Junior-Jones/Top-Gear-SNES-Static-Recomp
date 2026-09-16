#include "topgear_static_recomp.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static int load_file(const char *path, uint8_t **data, size_t *size) {
    FILE *file = fopen(path, "rb");
    long length;
    *data = NULL;
    *size = 0u;
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

static uint64_t fnv1a64(const uint8_t *data, size_t size) {
    uint64_t hash = UINT64_C(1469598103934665603);
    size_t index;
    for (index = 0u; index < size; ++index) {
        hash ^= data[index];
        hash *= UINT64_C(1099511628211);
    }
    return hash;
}

int main(int argc, char **argv) {
    static const uint64_t expected[7] = {
        UINT64_C(0x9FE35574AB9179F5),
        UINT64_C(0xA48741E12A07CE75),
        UINT64_C(0x0CF979D3A34EBAAE),
        UINT64_C(0xC27E5F6D788A12CF),
        UINT64_C(0x1093611E861166CF),
        UINT64_C(0x2F9BF21E3F805E9D),
        UINT64_C(0xC5E111408720FA62)
    };
    uint8_t *rom = NULL;
    size_t rom_size = 0u;
    TopGearRecomp *core = NULL;
    uint8_t aram[0x7700u];
    char error[256];
    unsigned selector;

    if (argc != 2 || !load_file(argv[1], &rom, &rom_size)) return 2;
    if (!topgear_recomp_create(&core, rom, rom_size, error, sizeof(error))) {
        fprintf(stderr, "create failed: %s\n", error);
        free(rom);
        return 1;
    }
    free(rom);

    for (selector = 1u; selector <= 7u; ++selector) {
        uint64_t hash;
        if (!topgear_recomp_music_preview_prepare(core, (uint8_t)selector,
                                                   error, sizeof(error))) {
            fprintf(stderr, "selector %u prepare failed: %s\n", selector, error);
            topgear_recomp_destroy(core);
            return 1;
        }
        if (!topgear_recomp_read_aram(core, 0x8900u, aram, sizeof(aram))) {
            fprintf(stderr, "selector %u ARAM read failed\n", selector);
            topgear_recomp_destroy(core);
            return 1;
        }
        hash = fnv1a64(aram, sizeof(aram));
        if (hash != expected[selector - 1u]) {
            fprintf(stderr,
                    "selector %u upload-chain hash mismatch: got %016llX expected %016llX\n",
                    selector, (unsigned long long)hash,
                    (unsigned long long)expected[selector - 1u]);
            topgear_recomp_destroy(core);
            return 1;
        }
        printf("selector=%u upload-index=%u aram-8900-ffff=%016llX\n",
               selector, selector - 1u, (unsigned long long)hash);
    }

    topgear_recomp_destroy(core);
    return 0;
}
