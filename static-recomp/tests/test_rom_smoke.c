#include "topgear_static_recomp.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *file;
    long size;
    uint8_t *rom;
    TopGearRecomp *core = NULL;
    TopGearRecompFrameResult frame;
    char error[256];
    int ok;
    if (argc != 2) return 2;
#ifdef _WIN32
    if (fopen_s(&file, argv[1], "rb") != 0) file = NULL;
#else
    file = fopen(argv[1], "rb");
#endif
    if (!file) return 3;
    if (fseek(file, 0, SEEK_END) != 0 || (size = ftell(file)) <= 0 ||
        fseek(file, 0, SEEK_SET) != 0) return 4;
    rom = (uint8_t *)malloc((size_t)size);
    if (!rom) return 5;
    if (fread(rom, 1u, (size_t)size, file) != (size_t)size) return 6;
    fclose(file);
    ok = topgear_recomp_create(&core, rom, (size_t)size, error, sizeof(error));
    if (ok) ok = topgear_recomp_reset(core, error, sizeof(error));
    if (ok) ok = topgear_recomp_advance_headless(core, 0u, 0u, 1u, &frame);
    topgear_recomp_destroy(core);
    free(rom);
    return ok ? 0 : 7;
}
