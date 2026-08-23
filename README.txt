Top Gear (SNES) Static Recompilation - Windows Source
Release 1.1.1

This package contains the Top Gear-specific static core and its native Windows
Launcher frontend. The ROM is not included.

What "fully static recompilation" means
----------------------------------------

Top Gear is a fully static, ahead-of-time recompilation. Its executable
W65C816 game instructions were analysed and translated into fixed native C
code before the application was built. The production launcher executes this
generated code directly.

At runtime, the application does not use a general-purpose SNES CPU
interpreter, runtime opcode decoder, dynamic recompiler, JIT compiler, runtime
learning system or emulator fallback. Its static CPU authority contains 8,685
normalised processor contexts across 29 fixed-C shards, together with generated
ROM re-entry, interrupt and executable-WRAM paths. Unknown execution states
stop through fail-closed diagnostics instead of being interpreted.

The complete runtime includes:

- Generated W65C816 game-code execution.
- LoROM mapping, WRAM, open-bus and machine-bus behaviour.
- Native PPU, CPU-I/O and controller-port handling.
- Native DMA and HDMA operation.
- NTSC beam scheduling, refresh, NMI, IRQ and auto-joypad events.
- Native Mode 1 menus and HUD rendering.
- Native Mode 7 track rendering, OBJ/OAM cars and display objects.
- Fail-closed static S-SMP execution and static S-DSP PCM production.
- Full-machine snapshots, deterministic framebuffers and runtime diagnostics.
- Password-based game progress, matching the original cartridge's lack of
  battery-backed SRAM.
- An accessible native Windows launcher with statically linked SDL
  presentation, audio and gamepad support.

"Fully static" does not mean that races, graphics, music or sound effects are
prerecorded. Every frame and audio sample is produced live from player input
and current machine state. It means that the game's executable instructions
are compiled ahead of time and no interpreter or fallback emulator executes
them at runtime.

Historical reference backends and development tools are not selectable
production paths. If a future static-code coverage gap is found, it must be
repaired from verified ROM or audio provenance and rebuilt into the static
authority; it will never be covered by enabling a runtime interpreter.

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

Tests
CTest builds the ROM-free API, renderer-instance, hook, audio FIFO, generated
dispatch, snapshot and integrity tests by default. To include the optional
cold-boot smoke test, configure with the exact legally obtained ROM:

  cmake -S . -B build -G "Visual Studio 17 2022" -A x64 ^
    -DTOPGEAR_TEST_ROM="C:\path\to\Top Gear (USA).sfc"
  cmake --build build --config Release
  ctest --test-dir build -C Release --output-on-failure

Public core API
Applications should include static-recomp\include\topgear_static_recomp.h.
Historical research receipts and milestone-specific declarations are available
only through the opt-in topgear_static_recomp_diagnostics.h header.

Source integrity
SOURCE-MANIFEST.json inventories the distributable source.
GENERATED-PROVENANCE.json records every generated dispatch and static-audio
authority file and binds it to the required ROM hash. SHA256SUMS.txt pins all
three inventories. Run this check from the source root:

  py -3 -B tools\integrity_manifests.py

Frontend architecture
- Native Win32 menus, toolbar and dialogs use standard Windows controls.
- Static-core frame rendering passes its core instance through every helper;
  simultaneous cores cannot overwrite a file-global renderer context.
- SDL3 presents double-buffered game frames through Direct3D with a software
  fallback, optional VSync, integer scaling and optional SNES 4:3 correction.
- F8 screenshots overlay the stable core framebuffer and do not depend on the
  last Windows paint region.
- Logs records a replayable .scsnap plus a detailed text report for static-core
  stops, unhandled Windows exceptions and in-app screenshot captures.
- Full Static audio remains native 32,040 Hz inside the core and in WAV files.
  SDL3 resamples speaker output to the selected device and applies bounded
  queue-depth drift correction.
- Music on the toolbar lists all seven ROM music sequences and the 16
  independently playable effects, labelled with exact table/ARAM addresses.
  The real driver upload path renders a five-minute music loop or six-second
  effect offline; Play, Stop and a five-second keyboard seek slider then play
  the cached WAV without opening or advancing the game window.
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
