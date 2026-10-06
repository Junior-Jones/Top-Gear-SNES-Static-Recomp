#ifndef TOPGEAR_MAC_UI_H
#define TOPGEAR_MAC_UI_H

#include <stddef.h>

#include <SDL3/SDL.h>

#include "topgear_app_core.h"
#include "topgear_audio_output_sdl.h"
#include "topgear_mac_settings.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Native AppKit menus and dialogs for the macOS launcher. Every dialog is
   application-modal and returns when it closes; the launcher pauses the game
   before opening one, as the Windows launcher does. */

enum TopGearMacCommand {
    TOPGEAR_MAC_COMMAND_NONE = 0,
    TOPGEAR_MAC_COMMAND_OPEN_ROM,
    TOPGEAR_MAC_COMMAND_RUN,
    TOPGEAR_MAC_COMMAND_PAUSE_PLAY,
    TOPGEAR_MAC_COMMAND_RESET,
    TOPGEAR_MAC_COMMAND_SAVE_CURRENT_SNAPSHOT,
    TOPGEAR_MAC_COMMAND_LOAD_CURRENT_SNAPSHOT,
    TOPGEAR_MAC_COMMAND_SAVE_SNAPSHOT,
    TOPGEAR_MAC_COMMAND_LOAD_SNAPSHOT,
    TOPGEAR_MAC_COMMAND_SCREENSHOT,
    TOPGEAR_MAC_COMMAND_SHOW_DATA_FOLDER,
    TOPGEAR_MAC_COMMAND_SETTINGS,
    TOPGEAR_MAC_COMMAND_CONTROLS,
    TOPGEAR_MAC_COMMAND_AUDIO_SETTINGS,
    TOPGEAR_MAC_COMMAND_PROFILE,
    TOPGEAR_MAC_COMMAND_LEADERBOARD,
    TOPGEAR_MAC_COMMAND_FULLSCREEN_ON_PLAY,
    TOPGEAR_MAC_COMMAND_AUTO_RUN,
    TOPGEAR_MAC_COMMAND_WELCOME,
    TOPGEAR_MAC_COMMAND_ABOUT
};

/* Menu items post commands through this callback. validate reports whether
   a command is enabled and, for toggles, whether it is checked. */
typedef void (*TopGearMacCommandCallback)(int command);
typedef int (*TopGearMacValidateCallback)(int command, int *checked);

void topgear_mac_ui_install_menus(TopGearMacCommandCallback command,
                                  TopGearMacValidateCallback validate);
/* Nonzero while a launcher dialog is open. */
int topgear_mac_ui_modal_active(void);

/* Settings dialog (F4). Returns 1 when the user applied changes. */
int topgear_mac_ui_settings(TopGearMacSettings *settings);

/* Controller Bindings dialog (F5). The gamepad callback returns the
   currently connected gamepad (reopening one if needed) or NULL. */
typedef SDL_Gamepad *(*TopGearMacGamepadProvider)(void);
int topgear_mac_ui_controls(TopGearMacSettings *settings,
                            TopGearMacGamepadProvider gamepad);

/* Audio Settings dialog (F6). Diagnostics are the last live values captured
   before the dialog paused audio. */
int topgear_mac_ui_audio(TopGearMacAudioSettings *settings,
                         const TopGearMacAudioDiagnostics *diagnostics,
                         const char *opened_device_name);

/* Profile dialog. Edits the running game's profile, or the Data file when
   no game is loaded. Returns 0 when cancelled, 1 when saved, 2 when saved
   and the user asked to reset the game now. status receives a summary. */
int topgear_mac_ui_profile(TopGearApp *game, const char *player_settings_path,
                           const char *data_directory, char *status,
                           size_t status_capacity);

/* Time Trial Leaderboard. Reads the running game's store, or the saved
   Data file without changing it when no game is loaded. */
void topgear_mac_ui_leaderboard(TopGearApp *game, const char *time_trial_path);

typedef struct TopGearMacSnapshotHost {
    int (*save)(int slot);
    int (*load)(int slot);
    int (*exists)(int slot);
    void (*describe)(int slot, int load_mode, char *text, size_t capacity);
    const char *(*last_status)(void);
    int selected_slot;
    int loaded_slot;
} TopGearMacSnapshotHost;

/* Save Snapshot (F2) / Load Snapshot (F3). Returns 1 after a successful
   load, when the game should resume. */
int topgear_mac_ui_snapshots(int save_mode, const TopGearMacSnapshotHost *host);

/* Read-only information window (Welcome, About, failure reports). */
void topgear_mac_ui_information(const char *title, const char *heading,
                                const char *text);
int topgear_mac_ui_confirm(const char *title, const char *text);

#ifdef __cplusplus
}
#endif
#endif
