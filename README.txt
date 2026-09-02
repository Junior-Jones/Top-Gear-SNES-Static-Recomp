Top Gear (SNES) Static Recompilation - Windows Source
Release 1.2.0

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
- An accessible native Windows launcher with Win32 presentation, SDL gamepad
  support and the Jungle Strike/Mesen-derived DirectSound audio frontend.

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
CTest builds the ROM-free API, renderer-instance, hook, audio FIFO, DirectSound
settings, Hermite resampler, generated dispatch, project-owned 32-phase DSP,
static-audio purity/authority, snapshot and integrity tests by default. With
the exact legally obtained ROM it also
runs cold-boot, deterministic PCM snapshot continuation and scripted 60-,
120- and 180-second gameplay/audio routes:

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
- Win32 presents the stable core framebuffer in windowed or full-screen mode
  with optional integer scaling.
- F8 captures the game framebuffer in windowed mode and the full displayed
  screen in full-screen mode.
- Logs records a detailed text report for fail-closed static-core stops.
- Full Static audio remains native 32,040 Hz inside the core.
  The project-owned S-DSP executes 32 hardware phases with BRR, Gaussian,
  envelope, noise and echo semantics; PCM knownness, hashes and overflows are
  exposed in diagnostics. The Jungle Strike/Mesen-derived DirectSound frontend
  resamples only speaker output to the selected device. It provides the full
  optional 0-40 ms latency, Hermite/linear/nearest resampler, safety-buffer,
  ring-buffer, drift, recovery and fade controls; latency is disabled and zero
  by default.
- Keyboard and SDL gamepad bindings are configurable for player one, with one
  input snapshot applied per emulated frame. Short keyboard presses remain
  latched until the core consumes one complete frame.
- Natural NTSC frame locking is enabled by default. The host advances one
  absolute deadline per completed frame and rebases after a late frame instead
  of generating catch-up bursts that can build an audio backlog. The optional
  title-bar FPS counter is disabled by default. Audio Settings exposes the last
  live output diagnostics captured before its dialog pauses the game.
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
