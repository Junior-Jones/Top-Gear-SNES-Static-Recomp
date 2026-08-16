#ifndef TOPGEAR_GAMEPAD_INPUT_WIN32_H
#define TOPGEAR_GAMEPAD_INPUT_WIN32_H

#include <stddef.h>
#include <stdint.h>
#include <windows.h>

#include <SDL3/SDL_gamepad.h>

#define TOPGEAR_GAMEPAD_BINDING_COUNT 12

typedef enum TopGearGamepadControl {
    TG_GAMEPAD_DPAD_UP = 1,
    TG_GAMEPAD_DPAD_DOWN,
    TG_GAMEPAD_DPAD_LEFT,
    TG_GAMEPAD_DPAD_RIGHT,
    TG_GAMEPAD_LEFT_STICK_UP,
    TG_GAMEPAD_LEFT_STICK_DOWN,
    TG_GAMEPAD_LEFT_STICK_LEFT,
    TG_GAMEPAD_LEFT_STICK_RIGHT,
    TG_GAMEPAD_FACE_SOUTH,
    TG_GAMEPAD_FACE_EAST,
    TG_GAMEPAD_FACE_WEST,
    TG_GAMEPAD_FACE_NORTH,
    TG_GAMEPAD_LEFT_SHOULDER,
    TG_GAMEPAD_RIGHT_SHOULDER,
    TG_GAMEPAD_LEFT_TRIGGER,
    TG_GAMEPAD_RIGHT_TRIGGER,
    TG_GAMEPAD_START,
    TG_GAMEPAD_BACK,
    TG_GAMEPAD_LEFT_STICK_BUTTON,
    TG_GAMEPAD_RIGHT_STICK_BUTTON,
    TG_GAMEPAD_CONTROL_LAST = TG_GAMEPAD_RIGHT_STICK_BUTTON
} TopGearGamepadControl;

typedef struct TopGearGamepadInputWin32 {
    SDL_Gamepad *handle;
    int initialized;
    int startup_gamepad_found;
    unsigned player_index;
    unsigned refresh_countdown;
    uint32_t analog_latched;
    char preferred_guid[64];
    char guid[64];
    wchar_t name[160];
} TopGearGamepadInputWin32;

int topgear_gamepad_win32_initialize(TopGearGamepadInputWin32 *input,
                                     const wchar_t *mapping_path,
                                     unsigned player_index,
                                     const wchar_t *preferred_guid);
void topgear_gamepad_win32_shutdown(TopGearGamepadInputWin32 *input);
void topgear_gamepad_win32_begin_frame(TopGearGamepadInputWin32 *inputs,
                                       size_t input_count);
uint16_t topgear_gamepad_win32_poll(
    TopGearGamepadInputWin32 *input,
    const int bindings[TOPGEAR_GAMEPAD_BINDING_COUNT],
    int deadzone_percent);
int topgear_gamepad_win32_connected(const TopGearGamepadInputWin32 *input);
const wchar_t *topgear_gamepad_win32_name(const TopGearGamepadInputWin32 *input);
void topgear_gamepad_win32_guid(const TopGearGamepadInputWin32 *input,
                                wchar_t *guid, size_t capacity);
void topgear_gamepad_win32_default_bindings(
    int bindings[TOPGEAR_GAMEPAD_BINDING_COUNT]);
const wchar_t *topgear_gamepad_win32_control_name(int control);
int topgear_gamepad_win32_capture_control(TopGearGamepadInputWin32 *input);
void topgear_gamepad_win32_control_display_name(
    const TopGearGamepadInputWin32 *input, int control,
    wchar_t *text, size_t capacity);

#endif
