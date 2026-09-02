#if !defined(_WIN32)
#error This test requires Windows.
#endif

#include <windows.h>
#include <stdio.h>
#include <string.h>

#include "topgear_frontend_settings_win32.h"

#define CHECK(expression) do { \
    if (!(expression)) { \
        fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #expression); \
        return 1; \
    } \
} while (0)

int main(void) {
    TopGearFrontendSettingsWin32 settings;
    TopGearFrontendSettingsWin32 loaded;
    wchar_t path[MAX_PATH];
    int index;

    CHECK(GetFullPathNameW(L"topgear-frontend-settings-contract.ini",
                           MAX_PATH, path, NULL) > 0u);
    (void)DeleteFileW(path);
    topgear_frontend_settings_win32_defaults(&settings);
    CHECK(settings.show_fps_counter == 0);
    CHECK(settings.ntsc_frame_lock == 1);
    CHECK(settings.pause_on_focus_loss == 0);
    CHECK(settings.input_source == TOPGEAR_INPUT_SOURCE_KEYBOARD);

    settings.show_fps_counter = 1;
    settings.ntsc_frame_lock = 0;
    settings.integer_scale = 3;
    settings.pause_on_focus_loss = 1;
    settings.auto_run_on_load = 1;
    settings.fullscreen_on_play = 1;
    settings.snapshot_slot = 4;
    settings.input_source = TOPGEAR_INPUT_SOURCE_GAMEPAD;
    settings.welcome_shown = 1;
    for (index = 0; index < TOPGEAR_WIN_BINDING_COUNT; ++index) {
        settings.bindings[index] = (UINT)('A' + index);
        settings.gamepad_bindings[index] = SC_GAMEPAD_DPAD_UP + index;
    }
    CHECK(topgear_frontend_settings_win32_save(&settings, path));
    memset(&loaded, 0, sizeof(loaded));
    topgear_frontend_settings_win32_load(&loaded, path);
    CHECK(loaded.show_fps_counter == 1);
    CHECK(loaded.ntsc_frame_lock == 0);
    CHECK(loaded.integer_scale == 3);
    CHECK(loaded.pause_on_focus_loss == 1);
    CHECK(loaded.auto_run_on_load == 1);
    CHECK(loaded.fullscreen_on_play == 1);
    CHECK(loaded.snapshot_slot == 4);
    CHECK(loaded.input_source == TOPGEAR_INPUT_SOURCE_GAMEPAD);
    CHECK(loaded.welcome_shown == 1);
    for (index = 0; index < TOPGEAR_WIN_BINDING_COUNT; ++index) {
        CHECK(loaded.bindings[index] == (UINT)('A' + index));
        CHECK(loaded.gamepad_bindings[index] == SC_GAMEPAD_DPAD_UP + index);
    }

    CHECK(WritePrivateProfileStringW(L"Input", L"Action0", L"113", path));
    topgear_frontend_settings_win32_load(&loaded, path);
    CHECK(loaded.bindings[0] == VK_UP);
    CHECK(DeleteFileW(path));
    puts("PASS all frontend settings persist and reserved bindings fail safe");
    return 0;
}
