#ifndef TOPGEAR_FRONTEND_SETTINGS_WIN32_H
#define TOPGEAR_FRONTEND_SETTINGS_WIN32_H

#include <windows.h>
#include <stdint.h>

#include "topgear_gamepad_input_win32.h"

#define TOPGEAR_WIN_BINDING_COUNT 12
#define TOPGEAR_INPUT_SOURCE_KEYBOARD 0
#define TOPGEAR_INPUT_SOURCE_GAMEPAD 1

typedef enum TopGearWinBindingAction {
    TOPGEAR_WIN_BIND_UP = 0, TOPGEAR_WIN_BIND_DOWN, TOPGEAR_WIN_BIND_LEFT, TOPGEAR_WIN_BIND_RIGHT,
    TOPGEAR_WIN_BIND_SNES_B, TOPGEAR_WIN_BIND_SNES_A, TOPGEAR_WIN_BIND_SNES_Y,
    TOPGEAR_WIN_BIND_SNES_X, TOPGEAR_WIN_BIND_SNES_L, TOPGEAR_WIN_BIND_SNES_R,
    TOPGEAR_WIN_BIND_START, TOPGEAR_WIN_BIND_SELECT
} TopGearWinBindingAction;

typedef struct TopGearFrontendSettingsWin32 {
    int integer_scale;
    int pause_on_focus_loss;
    int auto_run_on_load;
    int fullscreen_on_play;
    int show_fps_counter;
    int ntsc_frame_lock;
    int snapshot_slot;
    int input_source;
    int input_source_saved;
    int welcome_shown;
    UINT bindings[TOPGEAR_WIN_BINDING_COUNT];
    int gamepad_bindings[TOPGEAR_WIN_BINDING_COUNT];
} TopGearFrontendSettingsWin32;

void topgear_frontend_settings_win32_defaults(TopGearFrontendSettingsWin32 *s);
void topgear_frontend_settings_win32_classic(TopGearFrontendSettingsWin32 *s);
void topgear_frontend_settings_win32_load(TopGearFrontendSettingsWin32 *s,
                                          const wchar_t *path);
int topgear_frontend_settings_win32_save(const TopGearFrontendSettingsWin32 *s,
                                         const wchar_t *path);
uint16_t topgear_frontend_settings_win32_input(
    const TopGearFrontendSettingsWin32 *s, UINT virtual_key);
const wchar_t *topgear_frontend_settings_win32_action_name(int action);
void topgear_frontend_settings_win32_key_name(UINT virtual_key,
                                               wchar_t *text, size_t capacity);
int topgear_frontend_settings_win32_dialog(HWND parent, HINSTANCE instance,
                                           TopGearFrontendSettingsWin32 *s);
int topgear_frontend_controls_win32_dialog(HWND parent, HINSTANCE instance,
                                           TopGearFrontendSettingsWin32 *s,
                                           TopGearGamepadInputWin32 *gamepad);

#endif
