Top Gear Definitive Edition 2.0.0
Launcher for macOS 11 or newer (Apple silicon and Intel)

Getting started
---------------
Open Top Gear.app. Choose File > Open ROM (Command-O) and select your
Top Gear (USA) ROM, then choose File > Run (F7). You can also drop the .sfc
file onto the window or the Dock icon, or place it in the Rom folder below.
The selected path is remembered for later launches.

Required ROM size: 524,288 bytes
SHA-256: ca9889f17f184b3d99a2eaaa82af73e366f03ed00313fdd369e5e023b208e788

Game modes
----------
Career has revised race and championship qualification rules, three continues
for a failed race, and difficulty-specific passwords. Career and Rally share
their two-player setup. Rally selects and previews eight tracks, uses a harder
finishing target in each of its first seven races, and has no continues.

Time Trial is a solo mode with no CPU cars. Its results screen provides
Leaderboard, Retry, Tracks, Cars and Main Menu. The Top 5 records total time,
the best three sectors and lap times for each track, car and gearbox.

See VERSION.txt for the full rules and complete change list.

Launcher and saved data
-----------------------
The Settings menu provides Settings, Controller Bindings (keyboard or
USB/Bluetooth gamepad, with key and button capture), Audio Settings, Profile
(the shared Career/Rally setup or the separate Time Trial setup) and
Leaderboard (the saved Time Trial Top 5, available without a loaded ROM).

The app stores its data in:

  ~/Library/Application Support/Top Gear Definitive Edition/

  Rom          A .sfc placed here is found automatically
  Data         Profiles, game options, music playlist and Time Trial records
               (the same file formats as the Windows release, so a Windows
               Data folder can be copied here)
  Saves        Full-machine snapshots (.scsnap)
  Screenshots  Game-frame and full-screen captures
  Logs         Static-core failure reports
  settings.ini Launcher settings

File > Show Data Folder (Command-D) opens this folder in Finder.

Launcher shortcuts
------------------
Escape            Switch between the game and the launcher (pause)
1                 Save the current snapshot slot
2                 Load the current snapshot slot
F1                Welcome and shortcut guide
F2                Open the Save Snapshot window
F3                Open the Load Snapshot window
F4                Settings (also Command-Comma)
F5                Controls
F6                Audio settings
F7                Run the selected ROM
F8                Capture the current game frame (the whole displayed screen
                  in full screen)
Command-O         Open a ROM
Command-R         Reset the ROM
Control-Command-F Toggle full screen
Command-D         Show the data folder
Command-Q         Quit

On most Mac keyboards, hold Fn to use the F keys.

Audio
-----
Audio Settings provides the same controls as the Windows launcher: output
device, volume, output rate, resampler, optional 0-40 ms extra latency,
safety prebuffer, automatic recovery, drift correction and resume fade, plus
the last live output diagnostics. The static core always produces native
32,040 Hz audio; only speaker output is resampled.
