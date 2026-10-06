/* Opens every launcher dialog in turn and closes each one from a timer.
   Usage: topgear-mac-ui-smoke [seconds-per-dialog] [scratch-directory]
   Requires a logged-in macOS GUI session; it needs no ROM. */

#import <Cocoa/Cocoa.h>

#include "topgear_mac_ui.h"

#include <stdio.h>
#include <stdlib.h>

static double g_hold = 0.3;
static int g_dialogs;

@interface TGSmokeCloser : NSObject
@end
@implementation TGSmokeCloser
- (void)close:(NSTimer *)timer {
    (void)timer;
    if ([NSApp modalWindow]) [NSApp stopModal];
}
@end

static void close_after_hold(void) {
    static TGSmokeCloser *closer;
    NSTimer *timer;
    if (!closer) closer = [[TGSmokeCloser alloc] init];
    timer = [NSTimer timerWithTimeInterval:g_hold target:closer
                                  selector:@selector(close:)
                                  userInfo:nil repeats:NO];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSRunLoopCommonModes];
    ++g_dialogs;
}

static SDL_Gamepad *no_gamepad(void) { return NULL; }
static int fake_save(int slot) { (void)slot; return 0; }
static int fake_load(int slot) { (void)slot; return 0; }
static int fake_exists(int slot) { return slot == 2; }
static void fake_describe(int slot, int load_mode, char *text, size_t capacity) {
    (void)snprintf(text, capacity, slot == 2 ? "Saved 06/10/2026 13:00%s" : "Empty slot%s",
                   load_mode ? (slot == 2 ? " - Loaded" : " - Not loaded") : "");
}
static const char *fake_status(void) { return "Smoke test status."; }
static int g_last_command;
static void command(int id) { g_last_command = id; }
static int validate(int id, int *checked) { (void)id; if (checked) *checked = 0; return 1; }

int main(int argc, char **argv) {
    @autoreleasepool {
        TopGearMacSettings settings;
        TopGearMacAudioDiagnostics diagnostics;
        TopGearMacSnapshotHost host;
        char status[256];
        char profile_path[1024];
        char leaderboard_path[1024];
        const char *scratch = argc > 2 ? argv[2] : "/tmp";
        if (argc > 1) g_hold = atof(argv[1]);
        if (g_hold <= 0.0) g_hold = 0.3;
        (void)snprintf(profile_path, sizeof(profile_path), "%s/smoke-player-settings.dat", scratch);
        (void)snprintf(leaderboard_path, sizeof(leaderboard_path), "%s/smoke-missing-time-trial.dat", scratch);

        [NSApplication sharedApplication];
        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
        [NSApp activateIgnoringOtherApps:YES];
        topgear_mac_ui_install_menus(command, validate);
        if ([[NSApp mainMenu] numberOfItems] < 3) {
            fprintf(stderr, "FAIL menus were not installed\n");
            return 1;
        }

        topgear_mac_settings_defaults(&settings);
        memset(&diagnostics, 0, sizeof(diagnostics));
        diagnostics.device_sample_rate = 48000;
        diagnostics.target_latency_frames = 4320;
        diagnostics.playback_ratio = 1.0f;

        close_after_hold();
        if (topgear_mac_ui_settings(&settings)) return 1;
        close_after_hold();
        if (topgear_mac_ui_controls(&settings, no_gamepad)) return 1;
        settings.input_source = TOPGEAR_MAC_INPUT_SOURCE_GAMEPAD;
        close_after_hold();
        if (topgear_mac_ui_controls(&settings, no_gamepad)) return 1;
        close_after_hold();
        if (topgear_mac_ui_audio(&settings.audio, &diagnostics,
                                 TOPGEAR_MAC_AUDIO_DEFAULT_DEVICE_LABEL)) return 1;
        close_after_hold();
        if (topgear_mac_ui_profile(NULL, profile_path, scratch, status,
                                   sizeof(status))) return 1;
        close_after_hold();
        topgear_mac_ui_leaderboard(NULL, leaderboard_path);
        memset(&host, 0, sizeof(host));
        host.save = fake_save;
        host.load = fake_load;
        host.exists = fake_exists;
        host.describe = fake_describe;
        host.last_status = fake_status;
        host.selected_slot = 2;
        host.loaded_slot = 2;
        close_after_hold();
        if (topgear_mac_ui_snapshots(1, &host)) return 1;
        close_after_hold();
        if (topgear_mac_ui_snapshots(0, &host)) return 1;
        close_after_hold();
        topgear_mac_ui_information("About Top Gear", "Top Gear (SNES) Static Recompilation",
                                   "Smoke test information text.");
        if (topgear_mac_ui_modal_active()) {
            fprintf(stderr, "FAIL modal depth was not restored\n");
            return 1;
        }
        printf("PASS opened and closed %d launcher dialogs\n", g_dialogs);
    }
    return 0;
}
