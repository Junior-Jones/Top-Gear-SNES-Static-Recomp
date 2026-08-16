Top Gear (SNES) Static Recompilation
Launcher 1.0.0 for Windows 10 and 11 (64-bit)

1. Place the legally obtained Top Gear (USA) ROM in the Rom folder.
2. The ROM must be a 524,288-byte .sfc file with SHA-256:
   ca9889f17f184b3d99a2eaaa82af73e366f03ed00313fdd369e5e023b208e788
3. Run Launcher.exe.

Launcher.exe is portable. SDL and the Visual C++ runtime are statically linked.
No third-party DLL or Visual C++ redistributable needs to be installed.

Useful keys
Escape  Play or pause
F1      Shortcut help
F2/F3   Save/load snapshot dialog
F4      Audio settings
F5      Frontend settings
F6      Controls
F7      Run selected ROM
F8      Screenshot
F9      Start or stop native Full Static WAV recording
1/2     Save/load the current snapshot slot

The Settings dialog provides VSync, corrected SNES 4:3 output and integer
scaling. Controls supports keyboard, gamepad, or combined input for two players,
plus analogue deadzone and opposing-direction filtering.

The Logs folder receives a text diagnostic report and a complete .scsnap core
state whenever the static core stops, the process encounters an unhandled
Windows exception, or F8 requests an in-app screenshot. Reports include the
CPU, S-SMP, static audio, host audio/video, input, timing, frontier, hardware
registers and state hashes from that exact moment.

Only the Rom folder is included in a clean package. Snapshots, Screenshots,
Audio and Logs are created beside Launcher.exe only when the launcher is about
to write the corresponding first file; opening or merely viewing a feature
does not create an empty folder.

Top Gear stores progress through passwords and has no battery-backed SRAM, so
this app does not create a Saves folder. Snapshots are different: they are
optional full-machine save states (.scsnap) that restore an exact emulated
frame.
