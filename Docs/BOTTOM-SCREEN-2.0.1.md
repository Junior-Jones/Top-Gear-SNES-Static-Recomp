# Top Gear Definitive Edition 2.0.1

Settings now includes **Bottom Screen**, with **On** (default) and **Off**.
Use Left, Right, A or Start to change it. The option uses the original menu
font and selector. Back and directional wrapping include the new row.

In one-player Career, Rally and Time Trial, Off leaves the entire lower race
viewport black, including its statistics. On retains the existing top-five
panel in Career/Rally and lap/sector panel in Time Trial.

Two-player Career and Rally always display Player 2's screen, regardless of
the saved preference. Settings displays `ON - 2 PLAYERS` and cannot turn it
off while two humans are selected. Returning to one player restores the saved
preference. Time Trial continues to be one player only. Menus and results
continue to use the full screen.

Off skips lower-camera road generation, lower object construction, lower HUD
speed/gear/nitro/rank/timer/fuel/pedal graphics, the optional Career checkpoint
statistics, and lower-half object evaluation, tile/pixel composition and panel
drawing. The native absent-camera path retains a small shared HDMA terminator
and pointer setup required by the upper camera at race transitions. Shared
race simulation, opponent positions and results remain active. Existing solo
audio suppression prevents Player 2/CPU engine and effect commands; Player 1
effects and race music continue normally.

The native app also saves the preference as `[General] BottomScreen=1` (On)
or `BottomScreen=0` (Off) in `settings.ini`. A fresh app's generated configuration
includes the default On key. In-game changes update the INI; when loading a ROM,
an existing INI choice takes precedence over the profile record. Existing
installations without the key initially use the saved profile preference.
Snapshots restore race progress without overwriting this current preference.
Resets preserve it, and background/exit saves include it outside the menu.

The 96-byte TGPS settings record is version 6. Byte 95 bit 4 stores Off, so
versions 1-5 import with On. Music, mute, speed and all profile banks retain
their existing fields. Frontend profile editing accepts version 6. The core
uses one previously reserved byte, keeping the snapshot state layout size.

Verification uses the existing Temp source's `test_career_v2.c` and
`test_definitive_features.c` controller route in `test_bottom_screen.c`.
The matrix runs Career, Rally and Trial with both preferences, plus Career
and Rally with two humans and both saved preferences. It checks every lower
pixel during a ten-second driving interval, instruction observations for the
lower road/object/HUD paths, advancing timer/car position, P1/P2 audio command
traffic and solo P2 DSP silence. Settings input, held-button debounce,
navigation, legacy migration, music/mute flag combinations, physical settings
save/load and snapshot persistence are checked separately.

The existing natural `topgear-time-trial-journey` driver supports
`--bottom-screen-off` as a test configuration. It drives two complete
three-lap Las Vegas races with a Sidewinder/Auto, retries through the results
menu, reloads the physical results and player-settings files, and captures
full-screen results/leaderboard pages. This flag configures only the setting;
the existing driver supplies the race controls without forced lap/finish data.

Reproduce on Windows with CMake configured with `TOPGEAR_TEST_ROM`:

```text
cmake --build BUILD --config Release
ctest --test-dir BUILD -C Release -R topgear-bottom-screen --output-on-failure
BUILD/Release/topgear-time-trial-journey.exe ROM OUTPUT DATA_FILE 0 1 auto --bottom-screen-off
```

The release ZIP starts with default On and contains no ROM, personal settings,
saved snapshots, test times or evidence captures. The updated test installation
retains its existing Data, Rom, Saves and frontend preferences.
