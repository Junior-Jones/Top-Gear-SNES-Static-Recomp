# Center Screen — 2.1.0

Turn Bottom Screen Off, then Center Screen On in the in-game Settings menu.
Bottom Screen defaults to On; Center Screen defaults to Off. Center Screen is single-player only and prevents
two-player selection in Career and Rally while enabled.

Only P1's original-sized race view is shown in the middle. The upper and lower
areas are entirely black. There is no lower statistics panel, checkpoint-gap
list, second camera or recent-laps display in Center Screen mode. P1's own HUD
remains part of its race view. Menus and results retain their normal layout.

The 104 visible native P1 scanlines (source rows 4–107) occupy output rows
60–163. Both surrounding 60-line margins are black. Lower-view render/HUD
and live statistics work uses the existing disabled-screen path. Game physics,
CPU driving, car proportions and native race coordinates are unchanged.

CenterScreen=0 is the fresh default in settings.ini. The player-settings record
also retains the option. Turning Bottom Screen On disables Center Screen,
and attempts to change its disabled option are silent.

Verification: topgear-center-screen enters Career and Rally, checks exact P1
pixels and every pixel in both black margins, then drives 600 frames in each.
The final check also asserts the native lower raster is entirely black and
that turning Center Screen Off restores the normal presentation. No Trial
races were run for this correction. Evidence: Verification/Center-Black.

The later, explicitly requested three-mode display check covers Career, Rally
and player-only Time Trial: Bottom On stats, Bottom Off black, Center On black
margins, stats restoration and saved preferences. Evidence: Verification/Display-Rules.

For local manual testing, use Open-Test-Fresh.ps1 beside the Temp 2.1.0 folder.
It removes test/settings.ini before opening the app, as requested. It retains
Data/player-settings.dat and other saves. Release launchers keep normal settings
persistence; this reset procedure applies only to opening the local test app.
