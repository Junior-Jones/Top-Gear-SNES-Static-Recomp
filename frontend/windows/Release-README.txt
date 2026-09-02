Top Gear (SNES) Static Recompilation
Launcher 1.2.0 for Windows 10 and 11 (64-bit)

1. Place the legally obtained Top Gear (USA) ROM in the Rom folder.
2. The ROM must be a 524,288-byte .sfc file with SHA-256:
   ca9889f17f184b3d99a2eaaa82af73e366f03ed00313fdd369e5e023b208e788
3. Run Launcher.exe.

Launcher.exe is portable. SDL and the Visual C++ runtime are statically linked.
No third-party DLL or Visual C++ redistributable needs to be installed.

Useful keys
Escape  Play or pause; pausing also leaves full-screen presentation
F1      Shortcut help
F2/F3   Save/load snapshot dialog
F4      Settings
F5      Controls
F6      Audio settings
F7      Run selected ROM
F8      Screenshot
1/2     Save/load the current snapshot slot

The Settings dialog provides the natural NTSC frame lock, optional title-bar
FPS counter, full-screen play and integer scaling. The frame lock is enabled
and the FPS counter is disabled by default. Controls supports keyboard or SDL
gamepad input for player one with configurable bindings.

F8 saves the native game framebuffer while windowed. During full-screen play it
saves the complete displayed full-screen image, including scaling and black
pillar or letterbox bars.

Audio Settings uses the Jungle Strike/Mesen-derived DirectSound output path.
Extra latency is disabled at zero by default and can be enabled from 0-40 ms.
The selected device/rate, Hermite/linear/nearest resampler, safety and ring
buffers, drift control, recovery and fade settings are all configurable.
The core itself executes the project-owned Full Static S-SMP and 32-phase S-DSP
authority at 32,040 Hz. No runtime DSP library or emulator audio fallback is
linked into Launcher.exe.

The Logs folder receives a text diagnostic report when the static core stops.
Unknown static CPU or audio execution therefore fails closed with evidence
instead of silently using an emulator fallback.

Only the Rom folder is included in a clean package. Snapshots, Screenshots,
Audio and Logs are created beside Launcher.exe only when the launcher is about
to write the corresponding first file; opening or merely viewing a feature
does not create an empty folder.

Top Gear stores progress through passwords and has no battery-backed SRAM, so
this app does not create a Saves folder. Snapshots are different: they are
optional full-machine save states (.scsnap) that restore an exact emulated
frame.
