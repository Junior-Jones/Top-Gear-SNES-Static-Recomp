#include "topgear_rally_eight_race_posix.h"

#include <locale.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

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

int main(int argc, char **argv) {
    uint8_t *rom;
    size_t rom_size;
    TopGearRecomp *core = NULL;
    TopGearRecompFrameResult advance;
    wchar_t output_directory[4096];
    wchar_t message[512];
    wchar_t report_path[4096];
    char error[256];
    unsigned frame;
    unsigned batch_index = 0u;
    int result = 0;
    int converted;
    static const unsigned catchup_pattern[] = {1u, 2u, 1u, 3u, 1u, 8u};
    if (argc != 3) {
        fprintf(stderr, "usage: %s ROM OUTPUT_DIRECTORY\n", argv[0]);
        return 2;
    }
    fprintf(stderr, "rally-8: loading ROM\n"); fflush(stderr);
    if (!load_file(argv[1], &rom, &rom_size)) return 2;
    fprintf(stderr, "rally-8: creating core\n"); fflush(stderr);
    if (!topgear_recomp_create(&core, rom, rom_size, error, sizeof(error))) {
        fprintf(stderr, "create failed: %s\n", error);
        free(rom);
        return 1;
    }
    free(rom);
    fprintf(stderr, "rally-8: core created\n"); fflush(stderr);
    (void)setlocale(LC_ALL, "");
    converted = (int)mbstowcs(output_directory, argv[2],
                              (sizeof(output_directory) /
                               sizeof(output_directory[0])) - 1u);
    if (converted < 0) {
        topgear_recomp_destroy(core);
        return 2;
    }
    output_directory[converted] = L'\0';
    topgear_rally_eight_race_begin(output_directory);
    fprintf(stderr, "rally-8: controller begun\n"); fflush(stderr);
    frame = 0u;
    while (frame < 180000u && result == 0) {
        unsigned batch = catchup_pattern[batch_index %
            (sizeof(catchup_pattern) / sizeof(catchup_pattern[0]))];
        unsigned index;
        ++batch_index;
        for (index = 0u; index < batch && frame < 180000u && result == 0;
             ++index, ++frame) {
            uint16_t input = topgear_rally_eight_race_input(core);
            if (!topgear_recomp_advance_headless(
                    core, input, 0u, 1u, &advance)) {
                uint8_t fail_wram[TOPGEAR_RECOMP_WRAM_SIZE];
                TopGearCpuState fail_cpu;
                unsigned indirect = 0u;
                memset(&fail_cpu, 0, sizeof(fail_cpu));
                if (topgear_recomp_read_wram(core, 0u, fail_wram,
                                             sizeof(fail_wram)))
                    indirect = (unsigned)fail_wram[0xACu] |
                               ((unsigned)fail_wram[0xADu] << 8u);
                topgear_recomp_cpu_state(core, &fail_cpu);
                fprintf(stderr,
                        "advance failed at %u: %s; cpu=%02X:%04X A=%04X X=%04X Y=%04X S=%04X D=%04X DBR=%02X P=%02X; [$00AC]=%04X\n",
                        frame, topgear_recomp_last_error(core),
                        fail_cpu.pbr, fail_cpu.pc, fail_cpu.a, fail_cpu.x,
                        fail_cpu.y, fail_cpu.s, fail_cpu.d, fail_cpu.dbr,
                        fail_cpu.p, indirect);
                result = -1;
                break;
            }
            result = topgear_rally_eight_race_after_frame(
                core, message, sizeof(message) / sizeof(message[0]),
                report_path, sizeof(report_path) / sizeof(report_path[0]));
        }
    }
    if (result > 0) {
        wprintf(L"RALLY EIGHT-RACE DRIVER PASS after %u frames\n%ls\n%ls\n",
                frame, message, report_path);
    } else {
        char message_utf8[2048];
        size_t converted_message = wcstombs(message_utf8, message,
                                             sizeof(message_utf8) - 1u);
        if (converted_message == (size_t)-1) {
            (void)snprintf(message_utf8, sizeof(message_utf8),
                           "(wide failure message conversion failed)");
        } else {
            message_utf8[converted_message] = '\0';
        }
        fprintf(stderr, "RALLY EIGHT-RACE DRIVER FAIL after %u frames: %s\n",
                frame, message_utf8);
    }
    topgear_recomp_destroy(core);
    return result > 0 ? 0 : 1;
}
