Top Gear (SNES) Static Recompilation - Windows Source
Version 28 / Launcher 1.0.0

This package contains the Top Gear-specific static core and its native Windows
Launcher frontend. The ROM is not included.

ROM requirements
Name: Top Gear
Region: USA
Format: .sfc
Size: 524,288 bytes
SHA-256: ca9889f17f184b3d99a2eaaa82af73e366f03ed00313fdd369e5e023b208e788

Windows build
Use CMake 3.20 or newer and a Visual Studio 2022 x64 toolchain:

  cmake -S . -B build -G "Visual Studio 17 2022" -A x64
  cmake --build build --config Release --target topgear-launcher

The build downloads and statically links SDL 3.4.10. Release builds also use
the static Visual C++ runtime. Launcher.exe therefore does not require a
separate SDL DLL or Visual C++ redistributable.

Frontend architecture
- Native Win32 menus, toolbar and dialogs use standard Windows controls.
- SDL3 presents double-buffered game frames through Direct3D with a software
  fallback, optional VSync, integer scaling and optional SNES 4:3 correction.
- F8 screenshots overlay the stable core framebuffer and do not depend on the
  last Windows paint region.
- Logs records a replayable .scsnap plus a detailed text report for static-core
  stops, unhandled Windows exceptions and in-app screenshot captures.
- Full Static audio remains native 32,040 Hz inside the core and in WAV files.
  SDL3 resamples speaker output to the selected device and applies bounded
  queue-depth drift correction.
- Keyboard gameplay bindings use physical scan codes. SDL gamepads use stable
  GUID preference, configurable deadzone and hysteresis, and one state snapshot
  per emulated frame.
- Short host stalls catch up core simulation while dropping intermediate
  presentation frames. About displays timing, video, audio and input-history
  diagnostics.
- A clean release contains only the Rom folder. Snapshots, Screenshots, Audio
  and Logs are created lazily immediately before their first output file.
  Top Gear uses passwords and has no battery-backed SRAM, so this app never
  creates a Saves folder. Full-machine snapshots (.scsnap) remain available.

Documentation
Docs\Static Findings.txt is the maintained guide to the commentary and known
game-specific data in the static core.
Docs\Frontend Architecture.txt documents the Windows presentation, audio,
input and portability boundaries.

Licensing
SDL's license is copied beside Launcher.exe by the build. Static audio
provenance and required third-party notices remain beside the corresponding
source under static-recomp\static-audio\topgear-bapu-aot.
