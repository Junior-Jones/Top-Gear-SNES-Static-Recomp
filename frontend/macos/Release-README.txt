Top Gear Definitive Edition 2.0.0
Launcher for macOS 11 or newer (Apple silicon and Intel)

Getting started
---------------
Open Top Gear.app. On first launch, choose your Top Gear (USA) ROM in the file
dialog, or drop the .sfc file onto the window or the Dock icon. The verified
path is remembered for later launches.

Required ROM size: 524,288 bytes
SHA-256: ca9889f17f184b3d99a2eaaa82af73e366f03ed00313fdd369e5e023b208e788

Saved data
----------
The app stores everything in:

  ~/Library/Application Support/Top Gear Definitive Edition/

  Rom          Optional: a .sfc placed here is found automatically
  Data         Profiles, game options, music playlist and Time Trial records
               (the same file formats as the Windows release, so a Windows
               Data folder can be copied here)
  Saves        Full-machine snapshots (.scsnap)
  Screenshots  F8 captures
  Logs         Static-core failure reports
  settings.ini Launcher settings and key/gamepad bindings

Choose "Show Data Folder" (Cmd+D) to open this folder in Finder.

Controls
--------
Keyboard defaults:   Arrows = D-pad    D = B    F = A    A = Y    S = X
                     E = L    R = R    G = Start    T = Select
Gamepads use the SNES layout: bottom = B, right = A, left = Y, top = X,
shoulders = L/R, Start and Back/Select.

Keyboard and gamepad input are both active. Rebind them in settings.ini
([Keyboard] uses SDL key names such as "Left", "Z" or "Return"; [Gamepad] uses
dpup, dpdown, dpleft, dpright, lsup, lsdown, lsleft, lsright, south, east,
west, north, lshoulder, rshoulder, ltrigger, rtrigger, start, back, lstick,
rstick). Edit settings.ini while the app is closed.

Launcher shortcuts
------------------
Escape          Pause or resume
Cmd+O           Open a ROM
Cmd+R           Reset the game
Cmd+F / F11     Toggle full screen
Cmd+1 ... Cmd+5 Select the snapshot slot
1               Save the current snapshot slot
2               Load the current snapshot slot
F8              Capture the current game frame
Cmd+I           Toggle integer scaling (default is 4:3)
Cmd+D           Show the Data folder in Finder
F1              Show this shortcut list
Cmd+Q           Quit

On most Mac keyboards, hold Fn to use F1, F8 and F11.

settings.ini [Audio] provides Enabled, Volume (0-100) and LatencyMs (0-40).
[General] provides IntegerScale, PauseOnFocusLoss, FullScreenOnPlay,
ShowFpsCounter and NtscFrameLock.
