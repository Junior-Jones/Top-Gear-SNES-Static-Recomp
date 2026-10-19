Top Gear Definitive Edition 2.1.1
Launcher for Windows 10/11 x64

Getting started
---------------
Place Top Gear (USA).sfc in Rom, then run Launcher.exe.

Required ROM size: 524,288 bytes
SHA-256: ca9889f17f184b3d99a2eaaa82af73e366f03ed00313fdd369e5e023b208e788

The portable Launcher does not need a separate runtime or SDL DLL.

Game modes
----------
Career has revised race and championship qualification rules, three continues
for a failed race, and difficulty-specific passwords. Career and Rally share
their two-player setup. Rally selects and previews eight tracks, uses a harder
finishing target in each of its first seven races, and has no continues.

Time Trial is a solo mode with no CPU cars. Its results screen provides
Leaderboard, Retry, Tracks, Cars and Main Menu. Retry can be used without a
limit. The Top 5 records total time, the best three sectors and lap times for
each track, car and gearbox.

See VERSION.txt for the latest fixes and history.txt for all four versions,
including the full rules and earlier features.

Settings and audio
------------------
Changes save automatically; there is no Save button. Back returns to the main
menu. Keep settings.ini and Data/player-settings.dat for the next launch.

Settings provides KPH/MPH, music mute, Career Music, Music Player, Bottom Screen,
Center Screen and Extra CPUs.
Bottom Screen defaults to On. Off disables the lower race view and statistics
in one-player Career, Rally and Time Trial, leaving that area black. Two-player
Career and Rally force it On so Player 2 can see. Use Left/Right or A to change
the option; the choice is saved with player settings and in settings.ini as
[General] BottomScreen=1 (On) or BottomScreen=0 (Off). The generated config
includes the default On key. Snapshot loads and resets preserve your current
choice; loading an older saved race cannot turn the preference back On.
Career Music offers Complete, Random and Classic. Complete plays all race
songs in order. Random plays every race song once before reshuffling. Classic
uses the original Top Gear race music. Title, qualifying and results songs are
not selected as race songs. Music Player uses Left/Right to choose a song and
A to stop or resume it. R cycles the three title songs on title and menu
screens. On the per-car leaderboard, L/R changes the car filter instead.

Menu movement and confirmation effects use a separate cue channel, so music
mute and the lower menu-music level do not silence them. Starting Career,
Rally or Time Trial uses the finish-line confirmation effect.

On a Career, Rally or Time Trial setup page, R cycles Player 1's car and L
switches Player 1 between Manual and Automatic.

Launcher and saved data
-----------------------
Profile edits the shared Career/Rally setup or the separate Time Trial setup.
Leaderboard reads the saved Time Trial Top 5 without requiring a loaded ROM.
Controls supports configurable keyboard and USB/Bluetooth gamepads.

Keep the Data folder when updating. It stores profiles, game options, music
playlist state and Time Trial records. Frontend settings.ini remains beside
Launcher.exe. Snapshots, Screenshots, Audio and Logs are created when used.

Launcher shortcuts
------------------
Escape  Switch between the game and Launcher
1       Save the current snapshot slot
2       Load the current snapshot slot
F1      Welcome and shortcut guide
F2      Open the Save Snapshot window
F3      Open the Load Snapshot window
F4      Settings
F5      Controls
F6      Audio settings
F7      Run the selected ROM
F8      Capture the current game frame

The source Docs folder contains implementation and test notes.

Center Screen is a single-player presentation option in the in-game Settings
menu. It defaults to Off and requires Bottom Screen Off. Enable it to centre
the original-sized race view and leave the upper and lower areas entirely
black. No live stats appear beneath the centred view. While enabled, Career
and Rally cannot select two
players. These settings are saved in settings.ini; CenterScreen=0 is the default.

Extra CPUs is On by default. In one-player Career/Rally, SENNA and
MANSELL join JONES using the three cars not chosen by Player 1. Off restores
the two extra drivers to ordinary opponents. Two-player mode always disables
the two extra main CPUs. The named ordinary opponents keep stable colours.
ExtraCPUDrivers=1/0 is saved in settings.ini and in the player profile.

Timing file protection (2.1.1)
If an existing timing file cannot be loaded, the launcher reports the problem
and prevents saves from replacing it. Close the game, restore a valid
Data/time-trial.dat, and reload the ROM to retry. A missing file is created
automatically. A failed disk save keeps the results menu waiting for a retry.
