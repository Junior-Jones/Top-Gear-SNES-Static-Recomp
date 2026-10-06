/* Native AppKit menus and dialogs for the macOS launcher. The dialogs mirror
   the Windows launcher's Settings, Controller Bindings, Audio Settings,
   Profile, Leaderboard, Snapshot and Welcome windows with standard,
   VoiceOver-accessible controls. */

#import <Cocoa/Cocoa.h>

#include "topgear_mac_ui.h"

#include "topgear_audio_resampler.h"
#include "topgear_player_settings_file.h"
#include "topgear_time_trial_store.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

static int g_modal_depth;
static TopGearMacCommandCallback g_command_callback;
static TopGearMacValidateCallback g_validate_callback;

int topgear_mac_ui_modal_active(void) { return g_modal_depth > 0; }

/* ------------------------------------------------------------------ */
/* Shared helpers                                                      */
/* ------------------------------------------------------------------ */

@interface TGFlippedView : NSView
@end
@implementation TGFlippedView
- (BOOL)isFlipped { return YES; }
@end

static NSString *ns(const char *text) {
    NSString *value = text ? [NSString stringWithUTF8String:text] : nil;
    return value ? value : @"";
}

static NSWindow *main_window(void) {
    NSWindow *window = [NSApp mainWindow];
    if (!window) window = [[NSApp windows] firstObject];
    return window;
}

static NSPanel *make_panel(NSString *title, CGFloat width, CGFloat height) {
    NSPanel *panel = [[NSPanel alloc]
        initWithContentRect:NSMakeRect(0, 0, width, height)
                  styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable
                    backing:NSBackingStoreBuffered
                      defer:NO];
    TGFlippedView *content = [[TGFlippedView alloc]
        initWithFrame:NSMakeRect(0, 0, width, height)];
    [panel setTitle:title];
    [panel setContentView:content];
    [panel setReleasedWhenClosed:NO];
    [panel setHidesOnDeactivate:NO];
    return panel;
}

static void center_on_main(NSWindow *window) {
    NSWindow *parent = main_window();
    if (parent && parent != window && [parent isVisible]) {
        NSRect p = [parent frame];
        NSRect w = [window frame];
        [window setFrameOrigin:NSMakePoint(NSMidX(p) - w.size.width / 2.0,
                                           NSMidY(p) - w.size.height / 2.0)];
    } else {
        [window center];
    }
}

/* Runs an application-modal session. Closing the window ends it. */
static NSModalResponse run_modal(NSWindow *window) {
    NSModalResponse response;
    center_on_main(window);
    ++g_modal_depth;
    response = [NSApp runModalForWindow:window];
    --g_modal_depth;
    [window orderOut:nil];
    return response;
}

@interface TGModalDelegate : NSObject <NSWindowDelegate>
@end
@implementation TGModalDelegate
- (void)windowWillClose:(NSNotification *)note {
    (void)note;
    if ([NSApp modalWindow]) [NSApp stopModalWithCode:NSModalResponseCancel];
}
@end

static TGModalDelegate *modal_delegate(void) {
    static TGModalDelegate *delegate;
    if (!delegate) delegate = [[TGModalDelegate alloc] init];
    return delegate;
}

static NSTextField *add_label(NSView *view, NSString *text, NSRect frame) {
    NSTextField *label = [NSTextField labelWithString:text];
    [label setFrame:frame];
    [label setLineBreakMode:NSLineBreakByWordWrapping];
    [[label cell] setWraps:YES];
    [view addSubview:label];
    return label;
}

static NSButton *add_button(NSView *view, NSString *title, id target,
                            SEL action, NSRect frame) {
    NSButton *button = [NSButton buttonWithTitle:title target:target
                                          action:action];
    [button setFrame:frame];
    [view addSubview:button];
    return button;
}

static NSButton *add_checkbox(NSView *view, NSString *title, BOOL checked,
                              id target, SEL action, NSRect frame) {
    NSButton *box = [NSButton checkboxWithTitle:title target:target
                                         action:action];
    [box setFrame:frame];
    [box setState:checked ? NSControlStateValueOn : NSControlStateValueOff];
    [view addSubview:box];
    return box;
}

static NSPopUpButton *add_popup(NSView *view, NSArray<NSString *> *items,
                                NSRect frame) {
    NSPopUpButton *popup = [[NSPopUpButton alloc] initWithFrame:frame
                                                      pullsDown:NO];
    [popup addItemsWithTitles:items];
    [view addSubview:popup];
    return popup;
}

static NSTextField *add_field(NSView *view, NSString *text, NSRect frame) {
    NSTextField *field = [NSTextField textFieldWithString:text];
    [field setFrame:frame];
    [view addSubview:field];
    return field;
}

static NSBox *add_group(NSView *view, NSString *title, NSRect frame) {
    NSBox *box = [[NSBox alloc] initWithFrame:frame];
    [box setTitle:title];
    [view addSubview:box positioned:NSWindowBelow relativeTo:nil];
    return box;
}

/* Plain digits: setIntValue: would add the user's locale grouping
   ("2 500"), which the strict whole-number validation then rejects. */
static void set_number(NSTextField *field, int value) {
    [field setStringValue:[NSString stringWithFormat:@"%d", value]];
}

static BOOL is_on(NSButton *button) {
    return [button state] == NSControlStateValueOn;
}

static void show_alert(NSWindow *parent, NSString *title, NSString *text,
                       NSAlertStyle style) {
    NSAlert *alert = [[NSAlert alloc] init];
    (void)parent;
    [alert setMessageText:title];
    [alert setInformativeText:text];
    [alert setAlertStyle:style];
    [alert addButtonWithTitle:@"OK"];
    [alert runModal];
}

int topgear_mac_ui_confirm(const char *title, const char *text) {
    NSAlert *alert = [[NSAlert alloc] init];
    NSModalResponse response;
    [alert setMessageText:ns(title)];
    [alert setInformativeText:ns(text)];
    [alert addButtonWithTitle:@"Yes"];
    [alert addButtonWithTitle:@"No"];
    ++g_modal_depth;
    response = [alert runModal];
    --g_modal_depth;
    return response == NSAlertFirstButtonReturn;
}

/* ------------------------------------------------------------------ */
/* Key codes                                                           */
/* ------------------------------------------------------------------ */

/* macOS virtual key codes (HIToolbox kVK_*) to SDL scancodes, so captured
   keys match what SDL reports during gameplay. */
static SDL_Scancode scancode_from_keycode(unsigned short code) {
    switch (code) {
        case 0x00: return SDL_SCANCODE_A; case 0x01: return SDL_SCANCODE_S;
        case 0x02: return SDL_SCANCODE_D; case 0x03: return SDL_SCANCODE_F;
        case 0x04: return SDL_SCANCODE_H; case 0x05: return SDL_SCANCODE_G;
        case 0x06: return SDL_SCANCODE_Z; case 0x07: return SDL_SCANCODE_X;
        case 0x08: return SDL_SCANCODE_C; case 0x09: return SDL_SCANCODE_V;
        case 0x0A: return SDL_SCANCODE_NONUSBACKSLASH;
        case 0x0B: return SDL_SCANCODE_B; case 0x0C: return SDL_SCANCODE_Q;
        case 0x0D: return SDL_SCANCODE_W; case 0x0E: return SDL_SCANCODE_E;
        case 0x0F: return SDL_SCANCODE_R; case 0x10: return SDL_SCANCODE_Y;
        case 0x11: return SDL_SCANCODE_T; case 0x12: return SDL_SCANCODE_1;
        case 0x13: return SDL_SCANCODE_2; case 0x14: return SDL_SCANCODE_3;
        case 0x15: return SDL_SCANCODE_4; case 0x16: return SDL_SCANCODE_6;
        case 0x17: return SDL_SCANCODE_5; case 0x18: return SDL_SCANCODE_EQUALS;
        case 0x19: return SDL_SCANCODE_9; case 0x1A: return SDL_SCANCODE_7;
        case 0x1B: return SDL_SCANCODE_MINUS; case 0x1C: return SDL_SCANCODE_8;
        case 0x1D: return SDL_SCANCODE_0;
        case 0x1E: return SDL_SCANCODE_RIGHTBRACKET;
        case 0x1F: return SDL_SCANCODE_O; case 0x20: return SDL_SCANCODE_U;
        case 0x21: return SDL_SCANCODE_LEFTBRACKET;
        case 0x22: return SDL_SCANCODE_I; case 0x23: return SDL_SCANCODE_P;
        case 0x24: return SDL_SCANCODE_RETURN; case 0x25: return SDL_SCANCODE_L;
        case 0x26: return SDL_SCANCODE_J;
        case 0x27: return SDL_SCANCODE_APOSTROPHE;
        case 0x28: return SDL_SCANCODE_K;
        case 0x29: return SDL_SCANCODE_SEMICOLON;
        case 0x2A: return SDL_SCANCODE_BACKSLASH;
        case 0x2B: return SDL_SCANCODE_COMMA;
        case 0x2C: return SDL_SCANCODE_SLASH; case 0x2D: return SDL_SCANCODE_N;
        case 0x2E: return SDL_SCANCODE_M; case 0x2F: return SDL_SCANCODE_PERIOD;
        case 0x30: return SDL_SCANCODE_TAB; case 0x31: return SDL_SCANCODE_SPACE;
        case 0x32: return SDL_SCANCODE_GRAVE;
        case 0x33: return SDL_SCANCODE_BACKSPACE;
        case 0x35: return SDL_SCANCODE_ESCAPE;
        case 0x36: return SDL_SCANCODE_RGUI; case 0x37: return SDL_SCANCODE_LGUI;
        case 0x38: return SDL_SCANCODE_LSHIFT;
        case 0x39: return SDL_SCANCODE_CAPSLOCK;
        case 0x3A: return SDL_SCANCODE_LALT; case 0x3B: return SDL_SCANCODE_LCTRL;
        case 0x3C: return SDL_SCANCODE_RSHIFT; case 0x3D: return SDL_SCANCODE_RALT;
        case 0x3E: return SDL_SCANCODE_RCTRL;
        case 0x41: return SDL_SCANCODE_KP_PERIOD;
        case 0x43: return SDL_SCANCODE_KP_MULTIPLY;
        case 0x45: return SDL_SCANCODE_KP_PLUS;
        case 0x47: return SDL_SCANCODE_NUMLOCKCLEAR;
        case 0x4B: return SDL_SCANCODE_KP_DIVIDE;
        case 0x4C: return SDL_SCANCODE_KP_ENTER;
        case 0x4E: return SDL_SCANCODE_KP_MINUS;
        case 0x51: return SDL_SCANCODE_KP_EQUALS;
        case 0x52: return SDL_SCANCODE_KP_0; case 0x53: return SDL_SCANCODE_KP_1;
        case 0x54: return SDL_SCANCODE_KP_2; case 0x55: return SDL_SCANCODE_KP_3;
        case 0x56: return SDL_SCANCODE_KP_4; case 0x57: return SDL_SCANCODE_KP_5;
        case 0x58: return SDL_SCANCODE_KP_6; case 0x59: return SDL_SCANCODE_KP_7;
        case 0x5B: return SDL_SCANCODE_KP_8; case 0x5C: return SDL_SCANCODE_KP_9;
        case 0x60: return SDL_SCANCODE_F5; case 0x61: return SDL_SCANCODE_F6;
        case 0x62: return SDL_SCANCODE_F7; case 0x63: return SDL_SCANCODE_F3;
        case 0x64: return SDL_SCANCODE_F8; case 0x65: return SDL_SCANCODE_F9;
        case 0x67: return SDL_SCANCODE_F11; case 0x69: return SDL_SCANCODE_F13;
        case 0x6A: return SDL_SCANCODE_F16; case 0x6B: return SDL_SCANCODE_F14;
        case 0x6D: return SDL_SCANCODE_F10; case 0x6F: return SDL_SCANCODE_F12;
        case 0x71: return SDL_SCANCODE_F15; case 0x72: return SDL_SCANCODE_INSERT;
        case 0x73: return SDL_SCANCODE_HOME; case 0x74: return SDL_SCANCODE_PAGEUP;
        case 0x75: return SDL_SCANCODE_DELETE; case 0x76: return SDL_SCANCODE_F4;
        case 0x77: return SDL_SCANCODE_END; case 0x78: return SDL_SCANCODE_F2;
        case 0x79: return SDL_SCANCODE_PAGEDOWN; case 0x7A: return SDL_SCANCODE_F1;
        case 0x7B: return SDL_SCANCODE_LEFT; case 0x7C: return SDL_SCANCODE_RIGHT;
        case 0x7D: return SDL_SCANCODE_DOWN; case 0x7E: return SDL_SCANCODE_UP;
        default: return SDL_SCANCODE_UNKNOWN;
    }
}

static NSString *key_name(int scancode) {
    const char *name = SDL_GetScancodeName((SDL_Scancode)scancode);
    return name && name[0] ? ns(name) :
        [NSString stringWithFormat:@"Key %d", scancode];
}

/* ------------------------------------------------------------------ */
/* Menus                                                               */
/* ------------------------------------------------------------------ */

@interface TGMenuTarget : NSObject <NSMenuItemValidation>
@end
@implementation TGMenuTarget
- (void)perform:(NSMenuItem *)item {
    if (g_command_callback) g_command_callback((int)[item tag]);
}
- (BOOL)validateMenuItem:(NSMenuItem *)item {
    int checked = 0;
    int enabled;
    if (g_modal_depth > 0) return NO;
    enabled = g_validate_callback ?
        g_validate_callback((int)[item tag], &checked) : 1;
    if ([item tag] == TOPGEAR_MAC_COMMAND_PAUSE_PLAY)
        [item setTitle:checked ? @"Pause" : @"Play"];
    else
        [item setState:checked ? NSControlStateValueOn : NSControlStateValueOff];
    return enabled != 0;
}
@end

static TGMenuTarget *g_menu_target;

static NSMenuItem *add_item(NSMenu *menu, NSString *title, int command,
                            NSString *key, NSEventModifierFlags modifiers) {
    NSMenuItem *item = [[NSMenuItem alloc] initWithTitle:title
                                                  action:@selector(perform:)
                                           keyEquivalent:key ? key : @""];
    [item setTarget:g_menu_target];
    [item setTag:command];
    [item setKeyEquivalentModifierMask:modifiers];
    [menu addItem:item];
    return item;
}

static NSString *function_key(unichar key) {
    return [NSString stringWithCharacters:&key length:1];
}

void topgear_mac_ui_install_menus(TopGearMacCommandCallback command,
                                  TopGearMacValidateCallback validate) {
    NSMenu *bar = [NSApp mainMenu];
    NSMenu *app_menu;
    NSMenu *file;
    NSMenu *settings;
    NSMenu *help;
    NSMenuItem *holder;
    NSInteger index;
    g_command_callback = command;
    g_validate_callback = validate;
    if (!g_menu_target) g_menu_target = [[TGMenuTarget alloc] init];
    if (!bar) {
        bar = [[NSMenu alloc] init];
        [NSApp setMainMenu:bar];
    }
    /* Route SDL's About and Preferences items to the launcher. */
    app_menu = [bar numberOfItems] > 0 ? [[bar itemAtIndex:0] submenu] : nil;
    for (NSMenuItem *item in [app_menu itemArray]) {
        if ([item action] == @selector(orderFrontStandardAboutPanel:)) {
            [item setTarget:g_menu_target];
            [item setAction:@selector(perform:)];
            [item setTag:TOPGEAR_MAC_COMMAND_ABOUT];
        } else if ([[item keyEquivalent] isEqualToString:@","]) {
            [item setTitle:@"Settings…"];
            [item setTarget:g_menu_target];
            [item setAction:@selector(perform:)];
            [item setTag:TOPGEAR_MAC_COMMAND_SETTINGS];
        }
    }

    file = [[NSMenu alloc] initWithTitle:@"File"];
    add_item(file, @"Open ROM…", TOPGEAR_MAC_COMMAND_OPEN_ROM, @"o",
             NSEventModifierFlagCommand);
    add_item(file, @"Run", TOPGEAR_MAC_COMMAND_RUN,
             function_key(NSF7FunctionKey), 0);
    add_item(file, @"Play", TOPGEAR_MAC_COMMAND_PAUSE_PLAY, nil, 0);
    add_item(file, @"Reset ROM", TOPGEAR_MAC_COMMAND_RESET, @"r",
             NSEventModifierFlagCommand);
    [file addItem:[NSMenuItem separatorItem]];
    add_item(file, @"Save Current Snapshot", TOPGEAR_MAC_COMMAND_SAVE_CURRENT_SNAPSHOT,
             nil, 0);
    add_item(file, @"Load Current Snapshot", TOPGEAR_MAC_COMMAND_LOAD_CURRENT_SNAPSHOT,
             nil, 0);
    add_item(file, @"Save Snapshot…", TOPGEAR_MAC_COMMAND_SAVE_SNAPSHOT,
             function_key(NSF2FunctionKey), 0);
    add_item(file, @"Load Snapshot…", TOPGEAR_MAC_COMMAND_LOAD_SNAPSHOT,
             function_key(NSF3FunctionKey), 0);
    add_item(file, @"Capture Game Frame", TOPGEAR_MAC_COMMAND_SCREENSHOT,
             function_key(NSF8FunctionKey), 0);
    [file addItem:[NSMenuItem separatorItem]];
    add_item(file, @"Show Data Folder", TOPGEAR_MAC_COMMAND_SHOW_DATA_FOLDER,
             @"d", NSEventModifierFlagCommand);

    settings = [[NSMenu alloc] initWithTitle:@"Settings"];
    add_item(settings, @"Settings…", TOPGEAR_MAC_COMMAND_SETTINGS,
             function_key(NSF4FunctionKey), 0);
    add_item(settings, @"Controller Bindings…", TOPGEAR_MAC_COMMAND_CONTROLS,
             function_key(NSF5FunctionKey), 0);
    add_item(settings, @"Audio Settings…", TOPGEAR_MAC_COMMAND_AUDIO_SETTINGS,
             function_key(NSF6FunctionKey), 0);
    add_item(settings, @"Profile…", TOPGEAR_MAC_COMMAND_PROFILE, nil, 0);
    add_item(settings, @"Leaderboard…", TOPGEAR_MAC_COMMAND_LEADERBOARD, nil, 0);
    [settings addItem:[NSMenuItem separatorItem]];
    add_item(settings, @"Use Full Screen When Playing",
             TOPGEAR_MAC_COMMAND_FULLSCREEN_ON_PLAY, nil, 0);
    add_item(settings, @"Auto-Run at Startup", TOPGEAR_MAC_COMMAND_AUTO_RUN,
             nil, 0);

    help = [[NSMenu alloc] initWithTitle:@"Help"];
    add_item(help, @"Welcome and Shortcuts", TOPGEAR_MAC_COMMAND_WELCOME,
             function_key(NSF1FunctionKey), 0);

    index = [bar numberOfItems] > 0 ? 1 : 0;
    holder = [[NSMenuItem alloc] initWithTitle:@"File" action:nil keyEquivalent:@""];
    [holder setSubmenu:file];
    [bar insertItem:holder atIndex:index++];
    holder = [[NSMenuItem alloc] initWithTitle:@"Settings" action:nil keyEquivalent:@""];
    [holder setSubmenu:settings];
    [bar insertItem:holder atIndex:index];
    holder = [[NSMenuItem alloc] initWithTitle:@"Help" action:nil keyEquivalent:@""];
    [holder setSubmenu:help];
    [bar addItem:holder];
    [NSApp setHelpMenu:help];
}

/* ------------------------------------------------------------------ */
/* Information window                                                  */
/* ------------------------------------------------------------------ */

@interface TGInfoController : NSObject
@end
@implementation TGInfoController
- (void)close:(id)sender { (void)sender; [NSApp stopModalWithCode:NSModalResponseOK]; }
@end

void topgear_mac_ui_information(const char *title, const char *heading,
                                const char *text) {
    @autoreleasepool {
        CGFloat width = 760;
        CGFloat height = 600;
        NSPanel *panel = make_panel(ns(title), width, height);
        NSView *view = [panel contentView];
        TGInfoController *controller = [[TGInfoController alloc] init];
        NSScrollView *scroll;
        NSTextView *body;
        NSButton *close;
        CGFloat top = 16;
        [panel setDelegate:modal_delegate()];
        if (heading && heading[0]) {
            NSTextField *label = add_label(view, ns(heading),
                                           NSMakeRect(20, 14, width - 40, 28));
            [label setFont:[NSFont boldSystemFontOfSize:18]];
            top = 50;
        }
        scroll = [[NSScrollView alloc]
            initWithFrame:NSMakeRect(20, top, width - 40, height - top - 64)];
        [scroll setHasVerticalScroller:YES];
        [scroll setBorderType:NSBezelBorder];
        body = [[NSTextView alloc] initWithFrame:[[scroll contentView] bounds]];
        [body setEditable:NO];
        [body setSelectable:YES];
        [body setFont:[NSFont systemFontOfSize:13]];
        [body setTextContainerInset:NSMakeSize(8, 8)];
        [body setAutoresizingMask:NSViewWidthSizable];
        [body setString:ns(text)];
        [scroll setDocumentView:body];
        [view addSubview:scroll];
        close = add_button(view, @"Close", controller, @selector(close:),
                           NSMakeRect((width - 110) / 2, height - 48, 110, 32));
        [close setKeyEquivalent:@"\r"];
        [panel makeFirstResponder:body];
        (void)run_modal(panel);
        [panel setDelegate:nil];
    }
}

/* ------------------------------------------------------------------ */
/* Settings                                                            */
/* ------------------------------------------------------------------ */

@interface TGSettingsController : NSObject
@property(nonatomic, assign) TopGearMacSettings *value;
@property(nonatomic, strong) NSButton *autoRun, *pauseFocus, *fullscreen, *fps, *ntsc;
@property(nonatomic, strong) NSPopUpButton *scale;
@property(nonatomic, assign) BOOL accepted;
@end
@implementation TGSettingsController
- (void)apply:(id)sender {
    (void)sender;
    self.value->integer_scale = (int)[self.scale indexOfSelectedItem];
    self.value->pause_on_focus_loss = is_on(self.pauseFocus);
    self.value->auto_run_on_load = is_on(self.autoRun);
    self.value->fullscreen_on_play = is_on(self.fullscreen);
    self.value->show_fps_counter = is_on(self.fps);
    self.value->ntsc_frame_lock = is_on(self.ntsc);
    self.accepted = YES;
    [NSApp stopModalWithCode:NSModalResponseOK];
}
- (void)cancel:(id)sender { (void)sender; [NSApp stopModalWithCode:NSModalResponseCancel]; }
@end

int topgear_mac_ui_settings(TopGearMacSettings *settings) {
    @autoreleasepool {
        NSPanel *panel = make_panel(@"Top Gear Settings", 540, 370);
        NSView *v = [panel contentView];
        TGSettingsController *c = [[TGSettingsController alloc] init];
        NSMutableArray<NSString *> *scales = [NSMutableArray array];
        NSButton *apply;
        NSButton *close;
        int n;
        if (!settings) return 0;
        c.value = settings;
        [panel setDelegate:modal_delegate()];
        add_group(v, @"General", NSMakeRect(14, 10, 512, 100));
        c.autoRun = add_checkbox(v, @"Start a valid ROM automatically when the launcher opens",
                                 settings->auto_run_on_load, nil, nil,
                                 NSMakeRect(32, 38, 470, 22));
        c.pauseFocus = add_checkbox(v, @"Pause the game when the app loses keyboard focus",
                                    settings->pause_on_focus_loss, nil, nil,
                                    NSMakeRect(32, 68, 470, 22));
        add_group(v, @"Display", NSMakeRect(14, 120, 512, 180));
        add_label(v, @"Game image scale:", NSMakeRect(32, 152, 150, 22));
        [scales addObject:@"Automatic (fit window)"];
        for (n = 1; n <= TOPGEAR_MAC_MAX_INTEGER_SCALE; ++n)
            [scales addObject:[NSString stringWithFormat:@"%dx integer scale", n]];
        c.scale = add_popup(v, scales, NSMakeRect(190, 147, 200, 26));
        [c.scale selectItemAtIndex:settings->integer_scale];
        c.fullscreen = add_checkbox(v, @"Use full screen when Play starts",
                                    settings->fullscreen_on_play, nil, nil,
                                    NSMakeRect(32, 186, 470, 22));
        c.fps = add_checkbox(v, @"Show live FPS counter in the game title bar",
                             settings->show_fps_counter, nil, nil,
                             NSMakeRect(32, 216, 470, 22));
        c.ntsc = add_checkbox(v, @"Lock game speed to natural NTSC (60.0988 FPS)",
                              settings->ntsc_frame_lock, nil, nil,
                              NSMakeRect(32, 246, 470, 22));
        apply = add_button(v, @"Apply", c, @selector(apply:),
                           NSMakeRect(340, 318, 90, 32));
        [apply setKeyEquivalent:@"\r"];
        close = add_button(v, @"Close", c, @selector(cancel:),
                           NSMakeRect(436, 318, 90, 32));
        [close setKeyEquivalent:@"\e"];
        [panel makeFirstResponder:c.autoRun];
        (void)run_modal(panel);
        [panel setDelegate:nil];
        return c.accepted ? 1 : 0;
    }
}

/* ------------------------------------------------------------------ */
/* Controller bindings                                                 */
/* ------------------------------------------------------------------ */

@class TGControlsController;

@interface TGCapturePanel : NSPanel
@property(nonatomic, weak) TGControlsController *controller;
@end

@interface TGControlsController : NSObject
@property(nonatomic, assign) TopGearMacSettings *target;
@property(nonatomic, assign) TopGearMacSettings value;
@property(nonatomic, assign) TopGearMacGamepadProvider gamepad;
@property(nonatomic, strong) NSPopUpButton *source;
@property(nonatomic, strong) NSTextField *statusLabel, *assignedHeader, *changeHeader, *keyboardHelp, *gamepadHelp;
@property(nonatomic, strong) NSBox *keyboardHelpGroup, *gamepadHelpGroup;
@property(nonatomic, strong) NSMutableArray<NSButton *> *keyButtons, *changeButtons;
@property(nonatomic, strong) NSMutableArray<NSTextField *> *padLabels;
@property(nonatomic, strong) NSButton *standardDefaults, *classicDefaults, *padDefaults, *applyButton;
@property(nonatomic, strong) NSTimer *timer;
@property(nonatomic, assign) int keyboardCapture, gamepadCapture;
@property(nonatomic, assign) BOOL waitForNeutral, accepted;
@property(nonatomic, weak) NSPanel *panel;
- (BOOL)handleCaptureEvent:(NSEvent *)event;
@end

@implementation TGCapturePanel
- (void)sendEvent:(NSEvent *)event {
    if (self.controller && [self.controller handleCaptureEvent:event]) return;
    [super sendEvent:event];
}
@end

@implementation TGControlsController
- (int)selectedSource { return (int)[self.source indexOfSelectedItem]; }
- (SDL_Gamepad *)pad { return self.gamepad ? self.gamepad() : NULL; }
- (void)showStatus:(NSString *)text { [self.statusLabel setStringValue:text ? text : @""]; }
- (void)updateStatus {
    SDL_Gamepad *pad = [self pad];
    NSString *name = pad ? ns(SDL_GetGamepadName(pad)) : @"";
    if ([name length] == 0) name = @"Connected gamepad";
    if ([self selectedSource] == TOPGEAR_MAC_INPUT_SOURCE_GAMEPAD)
        [self showStatus:pad ?
            [NSString stringWithFormat:@"Gamepad selected: %@. Keyboard shortcuts remain available.", name] :
            @"Gamepad selected, but none is connected. Gameplay uses the keyboard until one connects."];
    else
        [self showStatus:pad ?
            [NSString stringWithFormat:@"Keyboard selected. %@ is connected and can be selected above.", name] :
            @"Keyboard selected. No gamepad is currently connected."];
}
- (void)refresh {
    int source = [self selectedSource];
    BOOL keyboard = source == TOPGEAR_MAC_INPUT_SOURCE_KEYBOARD;
    BOOL idle = self.keyboardCapture < 0 && self.gamepadCapture < 0;
    SDL_Gamepad *pad = [self pad];
    TopGearMacSettings value = self.value;
    int i;
    [self.assignedHeader setStringValue:keyboard ? @"Current key - choose to change" :
                                                   @"Assigned input"];
    [self.changeHeader setHidden:keyboard];
    [self.keyboardHelpGroup setHidden:!keyboard];
    [self.gamepadHelpGroup setHidden:keyboard];
    for (i = 0; i < TOPGEAR_MAC_BINDING_COUNT; ++i) {
        NSButton *key = self.keyButtons[(NSUInteger)i];
        NSButton *change = self.changeButtons[(NSUInteger)i];
        NSTextField *label = self.padLabels[(NSUInteger)i];
        char name[192];
        [key setHidden:!keyboard];
        [label setHidden:keyboard];
        [change setHidden:keyboard];
        if (keyboard) {
            if (i != self.keyboardCapture) [key setTitle:key_name(value.keys[i])];
            [key setEnabled:self.keyboardCapture < 0 || i == self.keyboardCapture];
        } else {
            topgear_mac_pad_control_display_name(pad, value.pads[i], name, sizeof(name));
            [label setStringValue:ns(name)];
            [change setEnabled:pad != NULL && self.gamepadCapture < 0];
        }
    }
    [self.standardDefaults setHidden:!keyboard];
    [self.classicDefaults setHidden:!keyboard];
    [self.padDefaults setHidden:keyboard];
    [self.standardDefaults setEnabled:idle];
    [self.classicDefaults setEnabled:idle];
    [self.padDefaults setEnabled:idle];
    [self.source setEnabled:idle];
    [self.applyButton setEnabled:idle];
    if (idle) [self updateStatus];
}
- (void)sourceChanged:(id)sender {
    TopGearMacSettings value = self.value;
    (void)sender;
    value.input_source = [self selectedSource];
    self.value = value;
    [self refresh];
}
- (void)standard:(id)sender {
    TopGearMacSettings value = self.value;
    (void)sender;
    topgear_mac_settings_standard_keyboard(value.keys);
    self.value = value;
    [self refresh];
}
- (void)classic:(id)sender {
    TopGearMacSettings value = self.value;
    (void)sender;
    topgear_mac_settings_classic_keyboard(value.keys);
    self.value = value;
    [self refresh];
}
- (void)padDefaultsPressed:(id)sender {
    TopGearMacSettings value = self.value;
    (void)sender;
    topgear_mac_settings_default_gamepad(value.pads);
    self.value = value;
    [self refresh];
}
- (void)startKeyCapture:(NSButton *)sender {
    int action = (int)[sender tag];
    if (self.keyboardCapture >= 0) return;
    self.keyboardCapture = action;
    [sender setTitle:@"Press a key…"];
    [self refresh];
    [self showStatus:[NSString stringWithFormat:@"Press the new keyboard key for %s. Escape cancels.",
                     topgear_mac_action_name(action)]];
}
- (void)finishKeyCapture:(NSString *)message {
    int action = self.keyboardCapture;
    self.keyboardCapture = -1;
    [self refresh];
    if (message) [self showStatus:message];
    if (action >= 0) [self.panel makeFirstResponder:self.keyButtons[(NSUInteger)action]];
}
- (BOOL)handleCaptureEvent:(NSEvent *)event {
    SDL_Scancode code;
    int action = self.keyboardCapture;
    NSEventType type = [event type];
    if (self.gamepadCapture >= 0 && type == NSEventTypeKeyDown &&
        [event keyCode] == 0x35) {
        [self cancelPadCapture:@"Gamepad assignment capture cancelled."];
        return YES;
    }
    if (action < 0) return NO;
    if (type == NSEventTypeFlagsChanged) {
        NSEventModifierFlags flags = [event modifierFlags];
        unsigned short key = [event keyCode];
        BOOL down = ((key == 0x38 || key == 0x3C) && (flags & NSEventModifierFlagShift)) ||
                    ((key == 0x3B || key == 0x3E) && (flags & NSEventModifierFlagControl)) ||
                    ((key == 0x3A || key == 0x3D) && (flags & NSEventModifierFlagOption));
        if (!down) return YES;
        code = scancode_from_keycode(key);
    } else if (type == NSEventTypeKeyDown) {
        if ([event keyCode] == 0x35) {
            [self finishKeyCapture:@"Keyboard assignment capture cancelled."];
            return YES;
        }
        if ([event modifierFlags] & NSEventModifierFlagCommand) return YES;
        code = scancode_from_keycode([event keyCode]);
    } else {
        return type == NSEventTypeKeyUp;
    }
    if (code == SDL_SCANCODE_UNKNOWN) {
        [self showStatus:@"That key cannot be assigned. Press a different key, or Escape to cancel."];
        return YES;
    }
    if (topgear_mac_key_reserved(code)) {
        [self showStatus:@"That key is reserved for a launcher shortcut. Press a different key, or Escape to cancel."];
        return YES;
    }
    {
        TopGearMacSettings value = self.value;
        value.keys[action] = code;
        self.value = value;
    }
    [self finishKeyCapture:[NSString stringWithFormat:@"%s is now assigned to %@. Choose Apply to save.",
                            topgear_mac_action_name(action), key_name(code)]];
    return YES;
}
- (void)startPadCapture:(NSButton *)sender {
    int action = (int)[sender tag];
    if (![self pad]) {
        [self showStatus:@"Connect a gamepad before changing a gamepad assignment."];
        return;
    }
    self.gamepadCapture = action;
    self.waitForNeutral = YES;
    [self refresh];
    [self showStatus:[NSString stringWithFormat:@"Release all gamepad controls, then press the control for %s. Escape cancels.",
                     topgear_mac_action_name(action)]];
    self.timer = [NSTimer timerWithTimeInterval:1.0 / 60.0 target:self
                                       selector:@selector(pollPad:)
                                       userInfo:nil repeats:YES];
    [[NSRunLoop currentRunLoop] addTimer:self.timer forMode:NSRunLoopCommonModes];
}
- (void)cancelPadCapture:(NSString *)message {
    int action = self.gamepadCapture;
    [self.timer invalidate];
    self.timer = nil;
    self.gamepadCapture = -1;
    self.waitForNeutral = NO;
    [self refresh];
    if (message) [self showStatus:message];
    if (action >= 0) [self.panel makeFirstResponder:self.changeButtons[(NSUInteger)action]];
}
- (void)pollPad:(NSTimer *)timer {
    SDL_Gamepad *pad;
    int control;
    int action = self.gamepadCapture;
    (void)timer;
    if (action < 0) return;
    SDL_UpdateGamepads();
    pad = [self pad];
    if (!pad) {
        [self cancelPadCapture:@"Gamepad disconnected. Capture cancelled; keyboard gameplay remains available."];
        return;
    }
    control = topgear_mac_pad_capture_control(pad);
    if (self.waitForNeutral) {
        if (control == TOPGEAR_MAC_PAD_NONE) {
            self.waitForNeutral = NO;
            [self showStatus:[NSString stringWithFormat:@"Press the new gamepad control for %s. Escape cancels.",
                             topgear_mac_action_name(action)]];
        }
    } else if (control != TOPGEAR_MAC_PAD_NONE) {
        char name[192];
        TopGearMacSettings value = self.value;
        value.pads[action] = control;
        self.value = value;
        topgear_mac_pad_control_display_name(pad, control, name, sizeof(name));
        [self cancelPadCapture:nil];
        [self showStatus:[NSString stringWithFormat:@"%s is now assigned to %s. Choose Apply to save.",
                         topgear_mac_action_name(action), name]];
    }
}
- (void)apply:(id)sender {
    TopGearMacSettings value = self.value;
    int source = [self selectedSource];
    int duplicate;
    (void)sender;
    duplicate = topgear_mac_first_duplicate(
        source == TOPGEAR_MAC_INPUT_SOURCE_GAMEPAD ? value.pads : value.keys);
    if (duplicate >= 0) {
        show_alert(self.panel, @"Controls",
                   @"Each SNES control needs a different assigned input. Change the duplicate before applying.",
                   NSAlertStyleWarning);
        [self.panel makeFirstResponder:source == TOPGEAR_MAC_INPUT_SOURCE_GAMEPAD ?
            self.changeButtons[(NSUInteger)duplicate] : self.keyButtons[(NSUInteger)duplicate]];
        return;
    }
    value.input_source = source;
    *self.target = value;
    self.accepted = YES;
    [NSApp stopModalWithCode:NSModalResponseOK];
}
- (void)cancel:(id)sender {
    (void)sender;
    if (self.keyboardCapture >= 0) {
        [self finishKeyCapture:@"Keyboard assignment capture cancelled."];
        return;
    }
    if (self.gamepadCapture >= 0) {
        [self cancelPadCapture:@"Gamepad assignment capture cancelled."];
        return;
    }
    [NSApp stopModalWithCode:NSModalResponseCancel];
}
@end

int topgear_mac_ui_controls(TopGearMacSettings *settings,
                            TopGearMacGamepadProvider gamepad) {
    @autoreleasepool {
        const CGFloat width = 740;
        const CGFloat height = 620;
        TGCapturePanel *panel = [[TGCapturePanel alloc]
            initWithContentRect:NSMakeRect(0, 0, width, height)
                      styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable
                        backing:NSBackingStoreBuffered defer:NO];
        TGFlippedView *v = [[TGFlippedView alloc] initWithFrame:NSMakeRect(0, 0, width, height)];
        TGControlsController *c = [[TGControlsController alloc] init];
        NSButton *cancel;
        int i;
        if (!settings) return 0;
        [panel setTitle:@"Top Gear Controller Bindings"];
        [panel setContentView:v];
        [panel setReleasedWhenClosed:NO];
        [panel setDelegate:modal_delegate()];
        panel.controller = c;
        c.panel = panel;
        c.target = settings;
        c.value = *settings;
        c.gamepad = gamepad;
        c.keyboardCapture = -1;
        c.gamepadCapture = -1;
        c.keyButtons = [NSMutableArray array];
        c.changeButtons = [NSMutableArray array];
        c.padLabels = [NSMutableArray array];

        add_group(v, @"Active input", NSMakeRect(14, 8, 712, 84));
        add_label(v, @"Input device:", NSMakeRect(30, 36, 120, 22));
        c.source = add_popup(v, @[ @"Keyboard", @"Gamepad (USB / Bluetooth)" ],
                             NSMakeRect(154, 31, 230, 26));
        [c.source selectItemAtIndex:settings->input_source];
        [c.source setTarget:c];
        [c.source setAction:@selector(sourceChanged:)];
        c.statusLabel = add_label(v, @"", NSMakeRect(30, 62, 680, 22));
        add_label(v, @"SNES control", NSMakeRect(24, 104, 122, 20));
        c.assignedHeader = add_label(v, @"Assigned input", NSMakeRect(158, 104, 260, 20));
        c.changeHeader = add_label(v, @"Change assignment", NSMakeRect(438, 104, 200, 20));
        for (i = 0; i < TOPGEAR_MAC_BINDING_COUNT; ++i) {
            CGFloat y = 128 + i * 30;
            NSButton *key;
            NSButton *change;
            NSTextField *label;
            add_label(v, ns(topgear_mac_action_name(i)), NSMakeRect(24, y + 4, 130, 20));
            key = add_button(v, @"", c, @selector(startKeyCapture:), NSMakeRect(154, y, 268, 28));
            [key setTag:i];
            [[key cell] setAccessibilityLabel:
                [NSString stringWithFormat:@"%s key", topgear_mac_action_name(i)]];
            label = add_label(v, @"", NSMakeRect(158, y + 4, 260, 20));
            change = add_button(v, [NSString stringWithFormat:@"Change %s…", topgear_mac_action_name(i)],
                                c, @selector(startPadCapture:), NSMakeRect(434, y, 220, 28));
            [change setTag:i];
            [c.keyButtons addObject:key];
            [c.padLabels addObject:label];
            [c.changeButtons addObject:change];
        }
        c.keyboardHelpGroup = add_group(v, @"Changing keyboard keys", NSMakeRect(434, 124, 292, 120));
        c.keyboardHelp = add_label(v, @"Choose the current-key button beside a control, then press the replacement key. Escape cancels. Choose Apply to save all changes.",
                                   NSMakeRect(10, 6, 266, 84));
        [c.keyboardHelp removeFromSuperview];
        [[c.keyboardHelpGroup contentView] addSubview:c.keyboardHelp];
        c.gamepadHelpGroup = add_group(v, @"Gamepad behavior", NSMakeRect(380, 492, 346, 76));
        c.gamepadHelp = add_label(v, @"Choose Change, release held controls, then press the new button or direction. Escape cancels capture. Keyboard resumes if the gamepad disconnects.",
                                  NSMakeRect(8, 4, 326, 48));
        [c.gamepadHelp removeFromSuperview];
        [[c.gamepadHelpGroup contentView] addSubview:c.gamepadHelp];
        add_group(v, @"Defaults", NSMakeRect(14, 492, 350, 76));
        c.standardDefaults = add_button(v, @"Standard keyboard", c, @selector(standard:),
                                        NSMakeRect(28, 522, 160, 30));
        c.classicDefaults = add_button(v, @"Classic keyboard", c, @selector(classic:),
                                       NSMakeRect(192, 522, 160, 30));
        c.padDefaults = add_button(v, @"SNES gamepad layout", c, @selector(padDefaultsPressed:),
                                   NSMakeRect(90, 522, 190, 30));
        c.applyButton = add_button(v, @"Apply", c, @selector(apply:),
                                   NSMakeRect(540, 578, 90, 32));
        [c.applyButton setKeyEquivalent:@"\r"];
        cancel = add_button(v, @"Cancel", c, @selector(cancel:),
                            NSMakeRect(636, 578, 90, 32));
        [cancel setKeyEquivalent:@"\e"];
        [c refresh];
        [panel makeFirstResponder:c.source];
        (void)run_modal(panel);
        [c.timer invalidate];
        c.timer = nil;
        panel.controller = nil;
        [panel setDelegate:nil];
        return c.accepted ? 1 : 0;
    }
}

/* ------------------------------------------------------------------ */
/* Audio settings                                                      */
/* ------------------------------------------------------------------ */

static const int k_output_rates[] = {32040, 44100, 48000, 96000};

@interface TGAudioController : NSObject
@property(nonatomic, assign) TopGearMacAudioSettings *target;
@property(nonatomic, strong) NSButton *enabled, *latencyEnabled, *driftEnabled, *integral, *recovery;
@property(nonatomic, strong) NSPopUpButton *device, *volume, *rate, *resampler, *latency;
@property(nonatomic, strong) NSTextField *fade, *safety, *recoveryLimit, *tolerance, *maxRate, *averaging;
@property(nonatomic, weak) NSPanel *panel;
@property(nonatomic, assign) BOOL accepted;
@end
@implementation TGAudioController
- (void)updateEnabled:(id)sender {
    BOOL drift = is_on(self.driftEnabled);
    (void)sender;
    [self.latency setEnabled:is_on(self.latencyEnabled)];
    [self.tolerance setEnabled:drift];
    [self.maxRate setEnabled:drift];
    [self.averaging setEnabled:drift];
    [self.integral setEnabled:drift];
    [self.recoveryLimit setEnabled:is_on(self.recovery)];
}
- (void)load:(const TopGearMacAudioSettings *)s {
    NSUInteger index;
    [self.enabled setState:s->enabled ? NSControlStateValueOn : NSControlStateValueOff];
    [self.volume selectItemAtIndex:s->volume_percent];
    [self.latencyEnabled setState:s->latency_enabled ? NSControlStateValueOn : NSControlStateValueOff];
    [self.latency selectItemAtIndex:s->latency_ms];
    for (index = 0; index < sizeof(k_output_rates) / sizeof(k_output_rates[0]); ++index)
        if (k_output_rates[index] == s->output_sample_rate)
            [self.rate selectItemAtIndex:(NSInteger)index];
    [self.resampler selectItemAtIndex:s->resampler_mode];
    set_number(self.safety, s->safety_buffer_ms);
    [self.driftEnabled setState:s->drift_correction_enabled ? NSControlStateValueOn : NSControlStateValueOff];
    set_number(self.tolerance, s->drift_tolerance_ms);
    set_number(self.maxRate, s->max_rate_adjustment_ppm);
    set_number(self.averaging, s->averaging_frames);
    [self.integral setState:s->integral_correction_enabled ? NSControlStateValueOn : NSControlStateValueOff];
    [self.recovery setState:s->recovery_enabled ? NSControlStateValueOn : NSControlStateValueOff];
    set_number(self.recoveryLimit, s->recovery_threshold_ms);
    set_number(self.fade, s->resume_fade_ms);
    [self.device selectItemAtIndex:0];
    if (s->device_name[0] && [self.device itemWithTitle:ns(s->device_name)])
        [self.device selectItemWithTitle:ns(s->device_name)];
    [self updateEnabled:nil];
}
- (BOOL)readField:(NSTextField *)field name:(NSString *)name min:(int)minimum
              max:(int)maximum into:(int *)out {
    NSString *text = [[field stringValue] stringByTrimmingCharactersInSet:
                      [NSCharacterSet whitespaceCharacterSet]];
    NSScanner *scanner = [NSScanner scannerWithString:text];
    int value = 0;
    if (![scanner scanInt:&value] || ![scanner isAtEnd] ||
        value < minimum || value > maximum) {
        show_alert(self.panel, @"Audio Settings",
                   [NSString stringWithFormat:@"%@ must be a whole number from %d to %d.",
                    name, minimum, maximum], NSAlertStyleWarning);
        [self.panel makeFirstResponder:field];
        return NO;
    }
    *out = value;
    return YES;
}
- (void)defaults:(id)sender {
    TopGearMacAudioSettings s;
    (void)sender;
    topgear_mac_audio_settings_defaults(&s);
    [self load:&s];
}
- (void)apply:(id)sender {
    TopGearMacAudioSettings s = *self.target;
    (void)sender;
    if (![self readField:self.safety name:@"Safety prebuffer"
                     min:TOPGEAR_MAC_AUDIO_MIN_SAFETY_BUFFER_MS max:TOPGEAR_MAC_AUDIO_MAX_SAFETY_BUFFER_MS
                    into:&s.safety_buffer_ms] ||
        ![self readField:self.tolerance name:@"Drift tolerance"
                     min:TOPGEAR_MAC_AUDIO_MIN_DRIFT_TOLERANCE_MS max:TOPGEAR_MAC_AUDIO_MAX_DRIFT_TOLERANCE_MS
                    into:&s.drift_tolerance_ms] ||
        ![self readField:self.maxRate name:@"Maximum rate correction"
                     min:TOPGEAR_MAC_AUDIO_MIN_RATE_ADJUSTMENT_PPM max:TOPGEAR_MAC_AUDIO_MAX_RATE_ADJUSTMENT_PPM
                    into:&s.max_rate_adjustment_ppm] ||
        ![self readField:self.averaging name:@"Averaging window"
                     min:TOPGEAR_MAC_AUDIO_MIN_AVERAGING_FRAMES max:TOPGEAR_MAC_AUDIO_MAX_AVERAGING_FRAMES
                    into:&s.averaging_frames] ||
        ![self readField:self.recoveryLimit name:@"Recovery threshold"
                     min:TOPGEAR_MAC_AUDIO_MIN_RECOVERY_MS max:TOPGEAR_MAC_AUDIO_MAX_RECOVERY_MS
                    into:&s.recovery_threshold_ms] ||
        ![self readField:self.fade name:@"Resume fade"
                     min:TOPGEAR_MAC_AUDIO_MIN_FADE_MS max:TOPGEAR_MAC_AUDIO_MAX_FADE_MS
                    into:&s.resume_fade_ms])
        return;
    s.enabled = is_on(self.enabled);
    s.volume_percent = (int)[self.volume indexOfSelectedItem];
    s.latency_enabled = is_on(self.latencyEnabled);
    s.latency_ms = (int)[self.latency indexOfSelectedItem];
    s.output_sample_rate = k_output_rates[[self.rate indexOfSelectedItem]];
    s.resampler_mode = (int)[self.resampler indexOfSelectedItem];
    s.drift_correction_enabled = is_on(self.driftEnabled);
    s.integral_correction_enabled = is_on(self.integral);
    s.recovery_enabled = is_on(self.recovery);
    s.device_name[0] = '\0';
    if ([self.device indexOfSelectedItem] > 0)
        (void)snprintf(s.device_name, sizeof(s.device_name), "%s",
                       [[self.device titleOfSelectedItem] UTF8String]);
    *self.target = s;
    self.accepted = YES;
    [NSApp stopModalWithCode:NSModalResponseOK];
}
- (void)cancel:(id)sender { (void)sender; [NSApp stopModalWithCode:NSModalResponseCancel]; }
@end

static NSTextField *add_number(NSView *v, int value, NSRect frame) {
    NSTextField *field = add_field(v, [NSString stringWithFormat:@"%d", value], frame);
    [field setAlignment:NSTextAlignmentRight];
    return field;
}

int topgear_mac_ui_audio(TopGearMacAudioSettings *settings,
                         const TopGearMacAudioDiagnostics *d,
                         const char *opened_device_name) {
    @autoreleasepool {
        const CGFloat width = 800;
        const CGFloat height = 640;
        NSPanel *panel = make_panel(@"Top Gear Audio Settings", width, height);
        NSView *v = [panel contentView];
        TGAudioController *c = [[TGAudioController alloc] init];
        NSMutableArray<NSString *> *items = [NSMutableArray array];
        TopGearMacAudioDiagnostics empty;
        NSScrollView *scroll;
        NSTextView *diagnostics;
        NSButton *ok;
        NSButton *cancel;
        int n;
        int count;
        if (!settings) return 0;
        memset(&empty, 0, sizeof(empty));
        if (!d) d = &empty;
        c.target = settings;
        c.panel = panel;
        [panel setDelegate:modal_delegate()];

        c.enabled = add_checkbox(v, @"Enable audio output", YES, nil, nil,
                                 NSMakeRect(18, 12, 220, 22));
        add_label(v, @"Core Audio, signed 16-bit stereo; static DSP source: 32,040 Hz",
                  NSMakeRect(250, 14, 530, 20));

        add_group(v, @"Output and resampling", NSMakeRect(10, 42, 380, 300));
        add_label(v, @"Output device:", NSMakeRect(25, 74, 110, 20));
        [items addObject:@TOPGEAR_MAC_AUDIO_DEFAULT_DEVICE_LABEL];
        count = topgear_mac_audio_device_count();
        for (n = 0; n < count; ++n) {
            char name[TOPGEAR_MAC_AUDIO_DEVICE_NAME_CAPACITY];
            if (topgear_mac_audio_device_name(n, name, sizeof(name)) &&
                ![items containsObject:ns(name)])
                [items addObject:ns(name)];
        }
        c.device = add_popup(v, items, NSMakeRect(140, 69, 236, 26));
        [items removeAllObjects];
        add_label(v, @"Volume (0-100):", NSMakeRect(25, 112, 110, 20));
        for (n = 0; n <= 100; ++n) [items addObject:[NSString stringWithFormat:@"%d%%", n]];
        c.volume = add_popup(v, items, NSMakeRect(140, 107, 100, 26));
        [items removeAllObjects];
        add_label(v, @"Output rate:", NSMakeRect(25, 150, 110, 20));
        for (n = 0; n < 4; ++n) [items addObject:[NSString stringWithFormat:@"%d Hz", k_output_rates[n]]];
        c.rate = add_popup(v, items, NSMakeRect(140, 145, 140, 26));
        [items removeAllObjects];
        add_label(v, @"Resampler:", NSMakeRect(25, 188, 110, 20));
        c.resampler = add_popup(v, @[ @"Cubic Hermite (Mesen)", @"Linear", @"Nearest-neighbour" ],
                                NSMakeRect(140, 183, 200, 26));
        c.latencyEnabled = add_checkbox(v, @"Enable extra latency (0-40 ms)", NO, c,
                                        @selector(updateEnabled:), NSMakeRect(25, 224, 235, 22));
        for (n = 0; n <= 40; ++n) [items addObject:[NSString stringWithFormat:@"%d ms", n]];
        c.latency = add_popup(v, items, NSMakeRect(264, 221, 100, 26));
        add_label(v, @"Resume fade (0-100 ms):", NSMakeRect(25, 266, 190, 20));
        c.fade = add_number(v, settings->resume_fade_ms, NSMakeRect(220, 263, 70, 22));

        add_group(v, @"Buffering and recovery", NSMakeRect(400, 42, 390, 300));
        add_label(v, @"Safety prebuffer (0-100 ms):", NSMakeRect(415, 74, 220, 20));
        c.safety = add_number(v, settings->safety_buffer_ms, NSMakeRect(660, 71, 70, 22));
        c.recovery = add_checkbox(v, @"Recover automatically from stale audio", NO, c,
                                  @selector(updateEnabled:), NSMakeRect(415, 110, 360, 22));
        add_label(v, @"Recovery limit (10-500 ms):", NSMakeRect(415, 150, 220, 20));
        c.recoveryLimit = add_number(v, settings->recovery_threshold_ms, NSMakeRect(660, 147, 70, 22));
        add_label(v, @"Safety prebuffer is the first control to raise for crunchy audio.",
                  NSMakeRect(415, 190, 360, 40));

        add_group(v, @"Clock synchronization", NSMakeRect(10, 350, 380, 230));
        c.driftEnabled = add_checkbox(v, @"Enable device-latency drift correction", NO, c,
                                      @selector(updateEnabled:), NSMakeRect(25, 380, 340, 22));
        add_label(v, @"Tolerance (0-20 ms):", NSMakeRect(25, 418, 220, 20));
        c.tolerance = add_number(v, settings->drift_tolerance_ms, NSMakeRect(270, 415, 90, 22));
        add_label(v, @"Maximum correction (0-10000 ppm):", NSMakeRect(25, 454, 240, 20));
        c.maxRate = add_number(v, settings->max_rate_adjustment_ppm, NSMakeRect(270, 451, 90, 22));
        add_label(v, @"Averaging window (1-60 frames):", NSMakeRect(25, 490, 240, 20));
        c.averaging = add_number(v, settings->averaging_frames, NSMakeRect(270, 487, 90, 22));
        c.integral = add_checkbox(v, @"Enable slow integral correction", NO, nil, nil,
                                  NSMakeRect(25, 526, 340, 22));

        add_group(v, @"Last live diagnostics (captured before this window paused audio)",
                  NSMakeRect(400, 350, 390, 230));
        scroll = [[NSScrollView alloc] initWithFrame:NSMakeRect(414, 378, 362, 186)];
        [scroll setHasVerticalScroller:YES];
        [scroll setBorderType:NSBezelBorder];
        diagnostics = [[NSTextView alloc] initWithFrame:[[scroll contentView] bounds]];
        [diagnostics setEditable:NO];
        [diagnostics setSelectable:YES];
        [diagnostics setFont:[NSFont monospacedSystemFontOfSize:11 weight:NSFontWeightRegular]];
        [diagnostics setString:[NSString stringWithFormat:
            @"Device: %@\nRate: %d Hz | Queue: %u frames | Target: %u\n"
            @"Peak queue: %u frames\nAverage latency: %.2f ms | Ratio: %.6f\n"
            @"Underruns: %llu | Recoveries: %llu\nWrite failures: %llu",
            opened_device_name && opened_device_name[0] ? ns(opened_device_name) :
                @"Audio device not open",
            d->device_sample_rate, d->queue_depth_frames, d->target_latency_frames,
            d->peak_queue_depth_frames, d->average_latency_ms, d->playback_ratio,
            (unsigned long long)d->underruns, (unsigned long long)d->queue_recoveries,
            (unsigned long long)d->queue_failures]];
        [scroll setDocumentView:diagnostics];
        [v addSubview:scroll];

        add_button(v, @"Restore defaults", c, @selector(defaults:), NSMakeRect(14, 596, 150, 32));
        ok = add_button(v, @"OK", c, @selector(apply:), NSMakeRect(580, 596, 100, 32));
        [ok setKeyEquivalent:@"\r"];
        cancel = add_button(v, @"Cancel", c, @selector(cancel:), NSMakeRect(686, 596, 100, 32));
        [cancel setKeyEquivalent:@"\e"];
        [c load:settings];
        [panel makeFirstResponder:c.enabled];
        (void)run_modal(panel);
        [panel setDelegate:nil];
        return c.accepted ? 1 : 0;
    }
}

/* ------------------------------------------------------------------ */
/* Profile                                                             */
/* ------------------------------------------------------------------ */

static NSString *const k_profile_controls[4] = {
    @"Accelerate: X\nBrake: Y\nShift up: R; shift down: L\nNitro: A\nSteer: D-pad Left / Right",
    @"Accelerate: B\nBrake: X\nShift up: A; shift down: Y\nNitro: Start\nSteer: D-pad Right / Left (reversed)",
    @"Accelerate: X\nBrake: B\nShift up: A; shift down: Y\nNitro: Start\nSteer: D-pad Left / Right",
    @"Accelerate: B\nBrake: Y\nShift up: R; shift down: L\nNitro: A\nSteer: D-pad Left / Right"
};

@interface TGProfileController : NSObject <NSTextFieldDelegate>
@property(nonatomic, assign) TopGearApp *game;
@property(nonatomic, assign) const char *path;
@property(nonatomic, assign) const char *dataDirectory;
@property(nonatomic, strong) NSPopUpButton *bank, *car, *controls;
@property(nonatomic, strong) NSTextField *name, *assignments;
@property(nonatomic, strong) NSButton *automatic, *manual;
@property(nonatomic, weak) NSPanel *panel;
@property(nonatomic, assign) int result;
@property(nonatomic, copy) NSString *status;
@end
@implementation TGProfileController
- (unsigned)selectedBank { return (unsigned)[self.bank indexOfSelectedItem]; }
- (BOOL)load {
    TopGearPlayerProfile p;
    char name[9];
    unsigned n;
    memset(&p, 0, sizeof(p));
    if (!(self.game ? topgear_app_profile_read(self.game, [self selectedBank], &p) :
                      topgear_player_profile_file_read(self.path, [self selectedBank], &p)))
        return NO;
    for (n = 0; n < 8; ++n) name[n] = p.name[n];
    name[8] = '\0';
    for (n = 8; n > 0 && (name[n - 1] == ' ' || name[n - 1] == '\0'); --n) name[n - 1] = '\0';
    [self.name setStringValue:ns(name)];
    [self.car selectItemAtIndex:p.car & 3];
    [self.automatic setState:p.manual ? NSControlStateValueOff : NSControlStateValueOn];
    [self.manual setState:p.manual ? NSControlStateValueOn : NSControlStateValueOff];
    [self.controls selectItemAtIndex:p.controls & 3];
    [self.assignments setStringValue:k_profile_controls[p.controls & 3]];
    return YES;
}
- (void)bankChanged:(id)sender { (void)sender; (void)[self load]; }
- (void)controlsChanged:(id)sender {
    (void)sender;
    [self.assignments setStringValue:k_profile_controls[[self.controls indexOfSelectedItem] & 3]];
}
- (void)gearboxChanged:(id)sender {
    BOOL manual = sender == self.manual;
    [self.manual setState:manual ? NSControlStateValueOn : NSControlStateValueOff];
    [self.automatic setState:manual ? NSControlStateValueOff : NSControlStateValueOn];
}
- (void)controlTextDidChange:(NSNotification *)note {
    NSString *text = [[self.name stringValue] uppercaseString];
    (void)note;
    if ([text length] > 8) text = [text substringToIndex:8];
    if (![text isEqualToString:[self.name stringValue]]) [self.name setStringValue:text];
}
- (void)save:(id)sender {
    TopGearPlayerProfile p;
    TopGearPlayerProfile verified;
    const char *text = [[[self.name stringValue] uppercaseString] UTF8String];
    char expected[8];
    unsigned n;
    unsigned bank = [self selectedBank];
    (void)sender;
    memset(&p, 0, sizeof(p));
    memset(&verified, 0, sizeof(verified));
    for (n = 0; n < 8 && text && text[n]; ++n) {
        char ch = text[n];
        if (!((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == ' ')) {
            show_alert(self.panel, @"Profile", @"Use letters, numbers, or spaces.",
                       NSAlertStyleWarning);
            [self.panel makeFirstResponder:self.name];
            return;
        }
        p.name[n] = ch;
    }
    p.car = (uint8_t)[self.car indexOfSelectedItem];
    p.controls = (uint8_t)[self.controls indexOfSelectedItem];
    p.manual = (uint8_t)is_on(self.manual);
    memset(expected, ' ', sizeof(expected));
    memcpy(expected, p.name, n);
    if ((mkdir(self.dataDirectory, 0755) != 0 && errno != EEXIST) ||
        !(self.game ? topgear_app_profile_write(self.game, bank, &p, self.path) :
                      topgear_player_profile_file_write(self.path, bank, &p)) ||
        !topgear_player_profile_file_read(self.path, bank, &verified) ||
        memcmp(verified.name, expected, sizeof(expected)) != 0 ||
        verified.car != p.car || verified.controls != p.controls ||
        verified.manual != p.manual) {
        show_alert(self.panel, @"Profile",
                   @"The saved profile could not be verified. Check the Data folder and retry.",
                   NSAlertStyleCritical);
        return;
    }
    self.result = 1;
    if (self.game && topgear_mac_ui_confirm("Profile",
            "To apply these changes, the game must be reset.\n\nReset now?"))
        self.result = 2;
    self.status = [NSString stringWithFormat:
        self.result == 2 ? @"%@ profile saved with %@ gearbox. Resetting the game now." :
        self.game ? @"%@ profile saved with %@ gearbox. It will be used after the next game reset." :
                    @"%@ profile saved with %@ gearbox. It will be loaded when the ROM starts.",
        bank ? @"Time Trial" : @"Career and Rally", p.manual ? @"Manual" : @"Automatic"];
    [NSApp stopModalWithCode:NSModalResponseOK];
}
- (void)cancel:(id)sender { (void)sender; [NSApp stopModalWithCode:NSModalResponseCancel]; }
@end

int topgear_mac_ui_profile(TopGearApp *game, const char *player_settings_path,
                           const char *data_directory, char *status,
                           size_t status_capacity) {
    @autoreleasepool {
        NSPanel *panel = make_panel(@"Profile", 480, 430);
        NSView *v = [panel contentView];
        TGProfileController *c = [[TGProfileController alloc] init];
        NSButton *save;
        NSButton *cancel;
        if (status && status_capacity) status[0] = '\0';
        if (!player_settings_path || !data_directory) return 0;
        c.game = game;
        c.path = player_settings_path;
        c.dataDirectory = data_directory;
        c.panel = panel;
        [panel setDelegate:modal_delegate()];
        add_label(v, @"Mode:", NSMakeRect(16, 18, 136, 20));
        c.bank = add_popup(v, @[ @"Career and Rally", @"Time Trial" ], NSMakeRect(155, 13, 300, 26));
        [c.bank setTarget:c];
        [c.bank setAction:@selector(bankChanged:)];
        add_label(v, @"Name (8 characters):", NSMakeRect(16, 57, 138, 20));
        c.name = add_field(v, @"", NSMakeRect(158, 53, 294, 24));
        [c.name setDelegate:c];
        add_label(v, @"Car:", NSMakeRect(16, 97, 136, 20));
        c.car = add_popup(v, @[ @"Cannibal (red)", @"Sidewinder (white)", @"Razor (purple)", @"Weasel (blue)" ],
                          NSMakeRect(155, 92, 300, 26));
        add_label(v, @"Gearbox:", NSMakeRect(16, 135, 136, 20));
        c.automatic = [NSButton radioButtonWithTitle:@"Automatic" target:c action:@selector(gearboxChanged:)];
        [c.automatic setFrame:NSMakeRect(158, 132, 140, 22)];
        [v addSubview:c.automatic];
        c.manual = [NSButton radioButtonWithTitle:@"Manual" target:c action:@selector(gearboxChanged:)];
        [c.manual setFrame:NSMakeRect(310, 132, 140, 22)];
        [v addSubview:c.manual];
        add_label(v, @"Controls:", NSMakeRect(16, 175, 136, 20));
        c.controls = add_popup(v, @[ @"Type A", @"Type B", @"Type C", @"Type D" ],
                               NSMakeRect(155, 170, 300, 26));
        [c.controls setTarget:c];
        [c.controls setAction:@selector(controlsChanged:)];
        add_label(v, @"SNES button assignments:", NSMakeRect(16, 210, 430, 20));
        c.assignments = add_label(v, @"", NSMakeRect(16, 234, 440, 110));
        [c.assignments setSelectable:YES];
        save = add_button(v, @"Save", c, @selector(save:), NSMakeRect(270, 382, 96, 32));
        [save setKeyEquivalent:@"\r"];
        cancel = add_button(v, @"Cancel", c, @selector(cancel:), NSMakeRect(372, 382, 96, 32));
        [cancel setKeyEquivalent:@"\e"];
        if (![c load]) {
            show_alert(panel, @"Profile",
                       @"The saved profile could not be read. The Data file has not been changed.",
                       NSAlertStyleCritical);
            [panel setDelegate:nil];
            return 0;
        }
        [panel makeFirstResponder:c.bank];
        (void)run_modal(panel);
        [panel setDelegate:nil];
        if (c.result && status && status_capacity && c.status)
            (void)snprintf(status, status_capacity, "%s", [c.status UTF8String]);
        return c.result;
    }
}

/* ------------------------------------------------------------------ */
/* Leaderboard                                                         */
/* ------------------------------------------------------------------ */

/* Track labels generated from Data/track-catalog.json, by native course ID. */
static NSString *const k_tracks[32] = {
    @"USA - LAS VEGAS", @"USA - LOS ANGELES", @"USA - NEW YORK", @"USA - SAN FRANCISCO",
    @"South America - RIO", @"South America - MACHU PICCHU", @"South America - CHICHEN ITZA",
    @"South America - RAIN FOREST", @"Japan - TOKYO", @"Japan - HIROSHIMA", @"Japan - YOKOHAMA",
    @"Japan - KYOTO", @"Germany - MUNICH", @"Germany - COLOGNE", @"Germany - BLACK FOREST",
    @"Germany - FRANKFURT", @"Scandinavia - STOCKHOLM", @"Scandinavia - COPENHAGEN",
    @"Scandinavia - HELSINKI", @"Scandinavia - OSLO", @"France - PARIS", @"France - NICE",
    @"France - BORDEAUX", @"France - MONACO", @"Italy - PISA", @"Italy - ROME", @"Italy - SICILY",
    @"Italy - FLORENCE", @"United Kingdom - LONDON", @"United Kingdom - SHEFFIELD",
    @"United Kingdom - LOCH NESS", @"United Kingdom - STONEHENGE"
};
static NSString *const k_cars[4] = { @"Cannibal", @"Sidewinder", @"Razor", @"Weasel" };

static NSString *leaderboard_time(uint32_t ticks) {
    unsigned seconds = ticks / 60u;
    unsigned ms = ((ticks % 60u) * 1000u + 30u) / 60u;
    return [NSString stringWithFormat:@"%u:%02u.%03u", seconds / 60u, seconds % 60u, ms];
}

static NSString *leaderboard_sector(uint32_t ticks) {
    unsigned tenths = (unsigned)(((uint64_t)ticks * 10u + 30u) / 60u);
    return [NSString stringWithFormat:@"%02u.%1u", tenths / 10u, tenths % 10u];
}

@interface TGLeaderboardController : NSObject <NSTableViewDataSource>
@property(nonatomic, assign) TopGearApp *game;
@property(nonatomic, assign) TopGearTimeTrialStore *disk;
@property(nonatomic, strong) NSPopUpButton *track, *car, *gear;
@property(nonatomic, strong) NSTableView *table;
@property(nonatomic, strong) NSMutableArray<NSArray<NSString *> *> *rows;
@end
@implementation TGLeaderboardController
- (void)refresh:(id)sender {
    unsigned rank;
    int track = (int)[self.track indexOfSelectedItem];
    int car = (int)[self.car indexOfSelectedItem] - 1;
    int gear = (int)[self.gear indexOfSelectedItem] - 1;
    (void)sender;
    self.rows = [NSMutableArray array];
    for (rank = 0; rank < 5; ++rank) {
        TopGearTimeTrialRun r;
        NSString *place = [NSString stringWithFormat:@"%u%@", rank + 1,
                           rank == 0 ? @"st" : rank == 1 ? @"nd" : rank == 2 ? @"rd" : @"th"];
        int found;
        memset(&r, 0, sizeof(r));
        found = self.game ?
            topgear_app_leaderboard(self.game, (unsigned)track, car, gear, rank, &r) :
            topgear_time_trial_store_filtered_record(self.disk, (unsigned)track, car, gear, rank, &r);
        if (found) {
            char name[9];
            memcpy(name, r.name, 8);
            name[8] = '\0';
            [self.rows addObject:@[ place, ns(name), k_cars[r.car_id & 3],
                r.gearbox ? @"Manual" : @"Automatic", leaderboard_time(r.total_time_ticks),
                leaderboard_sector(r.best_sector1_ticks), leaderboard_sector(r.best_sector2_ticks),
                leaderboard_sector(r.best_sector3_ticks) ]];
        } else {
            [self.rows addObject:@[ place, @"No record", @"-", @"-", @"0:00:000",
                                    @"00.0", @"00.0", @"00.0" ]];
        }
    }
    [self.table reloadData];
}
- (NSInteger)numberOfRowsInTableView:(NSTableView *)tableView {
    (void)tableView;
    return (NSInteger)[self.rows count];
}
- (id)tableView:(NSTableView *)tableView objectValueForTableColumn:(NSTableColumn *)column
            row:(NSInteger)row {
    (void)tableView;
    return self.rows[(NSUInteger)row][(NSUInteger)[[column identifier] integerValue]];
}
- (void)close:(id)sender { (void)sender; [NSApp stopModalWithCode:NSModalResponseOK]; }
@end

void topgear_mac_ui_leaderboard(TopGearApp *game, const char *time_trial_path) {
    @autoreleasepool {
        static NSString *const labels[8] = { @"Place", @"Name", @"Car", @"Gearbox",
                                             @"Total", @"Sector 1", @"Sector 2", @"Sector 3" };
        static const CGFloat widths[8] = { 54, 100, 100, 90, 110, 90, 90, 90 };
        NSPanel *panel = make_panel(@"Time Trial Leaderboard", 850, 440);
        NSView *v = [panel contentView];
        TGLeaderboardController *c = [[TGLeaderboardController alloc] init];
        NSMutableArray<NSString *> *tracks = [NSMutableArray array];
        NSScrollView *scroll;
        NSTextField *notice;
        NSButton *close;
        int n;
        c.game = game;
        [panel setDelegate:modal_delegate()];
        add_label(v, @"Track", NSMakeRect(12, 10, 200, 20));
        for (n = 0; n < 32; ++n) [tracks addObject:k_tracks[n]];
        c.track = add_popup(v, tracks, NSMakeRect(12, 32, 826, 26));
        add_label(v, @"Car", NSMakeRect(12, 68, 200, 20));
        c.car = add_popup(v, @[ @"All cars", k_cars[0], k_cars[1], k_cars[2], k_cars[3] ],
                          NSMakeRect(12, 90, 300, 26));
        add_label(v, @"Gearbox", NSMakeRect(336, 68, 200, 20));
        c.gear = add_popup(v, @[ @"All gearboxes", @"Automatic", @"Manual" ],
                           NSMakeRect(336, 90, 250, 26));
        for (NSPopUpButton *popup in @[ c.track, c.car, c.gear ]) {
            [popup setTarget:c];
            [popup setAction:@selector(refresh:)];
        }
        scroll = [[NSScrollView alloc] initWithFrame:NSMakeRect(12, 132, 826, 190)];
        [scroll setBorderType:NSBezelBorder];
        c.table = [[NSTableView alloc] initWithFrame:[[scroll contentView] bounds]];
        for (n = 0; n < 8; ++n) {
            NSTableColumn *column = [[NSTableColumn alloc]
                initWithIdentifier:[NSString stringWithFormat:@"%d", n]];
            [[column headerCell] setStringValue:labels[n]];
            [column setWidth:widths[n]];
            [column setEditable:NO];
            [c.table addTableColumn:column];
        }
        [c.table setUsesAlternatingRowBackgroundColors:YES];
        [c.table setGridStyleMask:NSTableViewSolidVerticalGridLineMask];
        [c.table setAccessibilityLabel:@"Time Trial Top 5"];
        [c.table setDataSource:c];
        [scroll setDocumentView:c.table];
        [v addSubview:scroll];
        notice = add_label(v, @"Top 5 by total time. Sectors show the fastest sector from any lap in that run.",
                           NSMakeRect(12, 334, 826, 36));
        close = add_button(v, @"Close", c, @selector(close:), NSMakeRect(377, 392, 96, 32));
        [close setKeyEquivalent:@"\r"];
        if (!game) {
            /* Read-only import: opening the Leaderboard never migrates or
               rewrites the Data file. */
            FILE *file;
            c.disk = (TopGearTimeTrialStore *)calloc(1u, sizeof(*c.disk));
            if (c.disk) topgear_time_trial_store_init(c.disk);
            file = time_trial_path ? fopen(time_trial_path, "rb") : NULL;
            if (file) {
                long length;
                void *data = NULL;
                char error[256];
                int ok = 0;
                if (c.disk && !fseek(file, 0, SEEK_END) && (length = ftell(file)) > 0 &&
                    length <= 1024L * 1024L && !fseek(file, 0, SEEK_SET) &&
                    (data = malloc((size_t)length)) != NULL &&
                    fread(data, 1u, (size_t)length, file) == (size_t)length)
                    ok = topgear_time_trial_store_import(c.disk, data, (size_t)length,
                                                         error, sizeof(error));
                free(data);
                (void)fclose(file);
                if (!ok) [notice setStringValue:@"Saved Time Trial data could not be read. The file has not been changed."];
            } else if (errno != ENOENT) {
                [notice setStringValue:@"Saved Time Trial data could not be read. The file has not been changed."];
            }
        }
        [c refresh:nil];
        [panel makeFirstResponder:c.track];
        (void)run_modal(panel);
        [panel setDelegate:nil];
        free(c.disk);
        c.disk = NULL;
    }
}

/* ------------------------------------------------------------------ */
/* Snapshots                                                           */
/* ------------------------------------------------------------------ */

@interface TGSnapshotController : NSObject
@property(nonatomic, assign) const TopGearMacSnapshotHost *host;
@property(nonatomic, assign) BOOL saveMode, loaded;
@property(nonatomic, strong) NSMutableArray<NSButton *> *buttons;
@property(nonatomic, strong) NSMutableArray<NSTextField *> *labels;
@property(nonatomic, strong) NSTextField *result;
@property(nonatomic, assign) int loadedSlot;
@end
@implementation TGSnapshotController
- (void)refresh {
    int slot;
    for (slot = 1; slot <= TOPGEAR_MAC_SNAPSHOT_SLOT_COUNT; ++slot) {
        char text[256];
        NSTextField *label = self.labels[(NSUInteger)(slot - 1)];
        self.host->describe(slot, !self.saveMode, text, sizeof(text));
        [label setStringValue:ns(text)];
        if (!self.saveMode)
            [label setTextColor:self.loadedSlot == slot ? [NSColor systemGreenColor] :
                                                          [NSColor systemRedColor]];
        [self.buttons[(NSUInteger)(slot - 1)] setEnabled:
            self.saveMode || self.host->exists(slot)];
    }
}
- (void)choose:(NSButton *)sender {
    int slot = (int)[sender tag];
    int ok = self.saveMode ? self.host->save(slot) : self.host->load(slot);
    if (ok) {
        if (!self.saveMode) self.loaded = YES;
        [NSApp stopModalWithCode:NSModalResponseOK];
        return;
    }
    [self refresh];
    [self.result setStringValue:ns(self.host->last_status())];
}
- (void)close:(id)sender { (void)sender; [NSApp stopModalWithCode:NSModalResponseCancel]; }
@end

int topgear_mac_ui_snapshots(int save_mode, const TopGearMacSnapshotHost *host) {
    @autoreleasepool {
        NSPanel *panel;
        NSView *v;
        TGSnapshotController *c = [[TGSnapshotController alloc] init];
        NSButton *close;
        int slot;
        int focus;
        if (!host) return 0;
        panel = make_panel(save_mode ? @"Save Snapshot" : @"Load Snapshot", 640, 420);
        v = [panel contentView];
        c.host = host;
        c.saveMode = save_mode != 0;
        c.loadedSlot = host->loaded_slot;
        c.buttons = [NSMutableArray array];
        c.labels = [NSMutableArray array];
        [panel setDelegate:modal_delegate()];
        add_label(v, save_mode ?
            @"Choose a numbered slot to save the current paused game. Snapshots are stored in the Saves folder." :
            @"Choose a numbered slot to load. Green means currently loaded; red means not loaded. Empty slots are disabled.",
            NSMakeRect(18, 14, 604, 44));
        for (slot = 1; slot <= TOPGEAR_MAC_SNAPSHOT_SLOT_COUNT; ++slot) {
            CGFloat y = 70 + (slot - 1) * 52;
            NSString *number = [NSString stringWithFormat:@"%d", slot];
            NSButton *button = add_button(v, number, c, @selector(choose:),
                                          NSMakeRect(24, y, 64, 34));
            NSTextField *label = add_label(v, @"", NSMakeRect(104, y + 7, 510, 22));
            [button setTag:slot];
            [button setKeyEquivalent:number];
            [button setAccessibilityLabel:[NSString stringWithFormat:@"Slot %d", slot]];
            [c.buttons addObject:button];
            [c.labels addObject:label];
        }
        c.result = add_label(v, @"No snapshot action has been performed.",
                             NSMakeRect(24, 334, 592, 22));
        close = add_button(v, @"Close", c, @selector(close:), NSMakeRect(262, 372, 116, 32));
        [close setKeyEquivalent:@"\e"];
        [c refresh];
        focus = host->selected_slot;
        if (focus < 1 || focus > TOPGEAR_MAC_SNAPSHOT_SLOT_COUNT) focus = 1;
        [panel makeFirstResponder:c.buttons[(NSUInteger)(focus - 1)]];
        (void)run_modal(panel);
        [panel setDelegate:nil];
        return c.loaded ? 1 : 0;
    }
}
