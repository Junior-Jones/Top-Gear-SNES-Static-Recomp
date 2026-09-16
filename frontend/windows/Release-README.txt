Top Gear Definitive Edition 2.0.0
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

See VERSION.txt for the full rules and complete change list.

Settings and audio
------------------
Settings provides KPH/MPH, music mute, Career Music and Music Player.
Career Music offers Complete, Random and Classic. Complete plays all race
songs in order. Random plays every race song once before reshuffling. Classic
uses the original Top Gear race music. Title, qualifying and results songs are
not selected as race songs. Music Player uses Left/Right to choose a song and
A to stop or resume it. R cycles the three title songs on title and menu
screens.

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