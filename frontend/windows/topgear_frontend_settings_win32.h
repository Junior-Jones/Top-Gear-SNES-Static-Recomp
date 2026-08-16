#ifndef TOPGEAR_FRONTEND_SETTINGS_WIN32_H
#define TOPGEAR_FRONTEND_SETTINGS_WIN32_H

#include <windows.h>
#include <stdint.h>

#include "topgear_gamepad_input_win32.h"

#define TOPGEAR_WIN_BINDING_COUNT 12
#define TOPGEAR_PLAYER_COUNT 2
#define TOPGEAR_INPUT_SOURCE_KEYBOARD 0
#define TOPGEAR_INPUT_SOURCE_GAMEPAD 1
#define TOPGEAR_INPUT_SOURCE_COMBINED 2
#define TOPGEAR_GAMEPAD_GUID_CAPACITY 64

typedef enum TopGearWinBindingAction {
    TG_WIN_BIND_UP = 0, TG_WIN_BIND_DOWN, TG_WIN_BIND_LEFT, TG_WIN_BIND_RIGHT,
    TG_WIN_BIND_SNES_B, TG_WIN_BIND_SNES_A, TG_WIN_BIND_SNES_Y,
    TG_WIN_BIND_SNES_X, TG_WIN_BIND_SNES_L, TG_WIN_BIND_SNES_R,
    TG_WIN_BIND_START, TG_WIN_BIND_SELECT
} TopGearWinBindingAction;

typedef struct TopGearFrontendSettingsWin32 {
    int integer_scale;
    int pause_on_focus_loss;
    int auto_run_on_load;
    int fullscreen_on_play;
    int show_status_text;
    int correct_aspect;
    int vsync_enabled;
    int allow_invalid_input;
    int gamepad_deadzone_percent;
    int snapshot_slot;
    int input_source[TOPGEAR_PLAYER_COUNT];
    int input_source_saved[TOPGEAR_PLAYER_COUNT];
    int getting_started_shown;
    UINT bindings[TOPGEAR_PLAYER_COUNT][TOPGEAR_WIN_BINDING_COUNT];
    int gamepad_bindings[TOPGEAR_PLAYER_COUNT][TOPGEAR_WIN_BINDING_COUNT];
    wchar_t gamepad_guid[TOPGEAR_PLAYER_COUNT][TOPGEAR_GAMEPAD_GUID_CAPACITY];
} TopGearFrontendSettingsWin32;

void topgear_frontend_settings_win32_defaults(TopGearFrontendSettingsWin32 *s);
void topgear_frontend_settings_win32_classic(TopGearFrontendSettingsWin32 *s);
void topgear_frontend_settings_win32_load(TopGearFrontendSettingsWin32 *s,
                                          const wchar_t *path);
int topgear_frontend_settings_win32_save(const TopGearFrontendSettingsWin32 *s,
                                         const wchar_t *path);
uint16_t topgear_frontend_settings_win32_input(
    const TopGearFrontendSettingsWin32 *s, unsigned player, UINT physical_key);
UINT topgear_frontend_settings_win32_physical_key(UINT virtual_key,
                                                   LPARAM key_lparam);
const wchar_t *topgear_frontend_settings_win32_action_name(int action);
void topgear_frontend_settings_win32_key_name(UINT virtual_key,
                                               wchar_t *text, size_t capacity);
int topgear_frontend_settings_win32_dialog(HWND parent, HINSTANCE instance,
                                           TopGearFrontendSettingsWin32 *s);
int topgear_frontend_controls_win32_dialog(HWND parent, HINSTANCE instance,
                                           TopGearFrontendSettingsWin32 *s,
                                           TopGearGamepadInputWin32 gamepads[TOPGEAR_PLAYER_COUNT]);

#endif
