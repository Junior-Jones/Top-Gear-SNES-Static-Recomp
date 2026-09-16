# Track coverage, timing and static-core repairs � 10 September 2026

The authoritative Windows build is produced from this Source tree. Historical recovery trees and archives are evidence, not build inputs. Runtime Data files live beside Launcher.exe. Automated test Data is isolated under each receipt folder.

## Menus and persistence

The main menu has Career, Rally, Time Trial and Settings. Settings contains Speed (KPH by default) and Back. Speed units are stored with the three player profiles in TGPS v2 (96 bytes); v1 profiles import unchanged with KPH default. Career/Rally share their P1 and P2 profiles. Time Trial has an independent P1 profile. The front end owns atomic disk persistence.

Rally Start generates its actual eight-course schedule once, then shows Selected Tracks in race order. It uses the native briefing's 0x600 frame-poll wait, approximately 25.6 seconds at 60 Hz. A later input can skip the wait after the initiating press has been released; the dispatch waits for release. The first briefing is checked against the first displayed course. No schedule is regenerated between preview and briefing.

Time Trial detailed results now provide Leaderboard, Retry, Tracks, Cars and Main Menu across two centered rows. Leaderboard opens Overall Top 5 for that course, with Finish at the bottom. Tracks opens the country and track picker on the completed run's country. Cars opens all four cars with the current car highlighted. Main Menu returns to the game's root menu. The post-race leaderboard ignores the browser's previous car filter. Footer highlights use compact-font widths and remain inside the frame. Decimal points use actual native font tile 0x28 (0x19 is Y). Long result times are displayed at reduced precision when needed to fit the table, rather than capped at 9:59.999. Sector values above 99.9 seconds use rounded whole seconds and S. Underlying Data retains ticks without these display reductions.

## Timing authorities

Required laps are captured at the native loader's $00:BF40 store to $1E56; stale menu RAM is not an authority. Completed laps are captured at the engine's $05:E823 increment of $1E76, because the $011E HUD update can be skipped by the finish path.

Distance sectors use native car world position $1ED7 against course length $0200, crossing one-third and two-thirds. The previous camera/render position $0202 diverges during pit stops and is not a timing authority. Start-line wrapping arms each lap before sectors can be recorded. Each best sector is the minimum of that sector across all completed laps, independently of the other two minima. Every lap must satisfy S1 + S2 + S3 = lap time. Incomplete or inconsistent timing is rejected before disk insertion.

The Career ten-finishers cutoff at $00:8783 cannot terminate a fuelled, still-running Time Trial player. Native Career/Rally behavior and fuel-exhaustion handling remain. The native results transition disables the live timing overlay before drawing its own results, avoiding a mixed race/results screen.

## Static CPU repairs

389 generated 16-bit ROL operations in 22 files overwrote the operand with carry before rotating it. They now retain operand and incoming carry separately. The 8-bit operations already used separate temporaries and were preserved. This notably fixes pit exit at $00:BD38/$00:BD3C. The actual generated instruction is exhaustively tested for all 65,536 operands and both incoming carry values, including C/Z/N flags.

The original emitter defect is in the historical tools/scpu/generate_v03_scpu_batch.py accumulator ROL emitter and generate_v18_post8cc9_route.py memory ROL emitter. For 16-bit ROL, use byte for incoming carry and word for the operand; for 8-bit ROL use word for carry and byte for the operand. Do not regenerate this edited tree from those old emitters without retaining this correction and all menu/timing hooks.

Four native self-modifying SBC immediate operands are written by known STA instructions: $7E:2881, $7E:29E8, $7E:32D2 and $7E:342D. Static handlers read those immediate data bytes while still guarding the fixed SBC opcode. This correction is present in every applicable frozen WRAM epoch. No runtime opcode decoder was added.

The raster routine at $00:B511, selected by the native executable-WRAM setup at $7E:2028, was missing from the dispatch. Its 20 instructions are now statically compiled with nominal timing entries and a bounded indirect-call target. The supplied USA ROM bytes were verified before adding it. The complete routine is covered by a CPU test.

## Harness

Source/tests/run_time_trial_matrix.py validates Data/track-catalog.json against the supplied ROM lap table before starting. Its default 39 scenarios cover all 32 courses with varied cars/gearboxes plus all eight car/gearbox combinations on Las Vegas. --full enables all 256 combinations. --resume-from accepts only naturally reached race-start snapshots; receipts include executable, ROM and snapshot hashes. A cold controller journey validates menu selection and saved profile reload. No harness writes gameplay RAM to finish a race.

The driver reads native lateral position for steering, with a modest traffic-avoidance offset. Pixel samples remain diagnostics because coloured roads and scenery can fool a grey-road detector. Pit entry locations and sides come from native type-$74 roadside objects. It steers towards a suitable entrance while fuel remains and releases the accelerator through entry/refuelling: accelerator requests an early exit. Full fuel advances natively to the exit phase.

Screenshots wait for menu stability, rendered lap/sector states, and 90 stable frames on custom results pages. The expanded visual fixture walks 101 menu highlights, the natural Rally preview/briefing transition, both eight-lap results pages, and slow-format cases. Fixture timing is explicitly synthetic; natural driving receipts are separate.

Each natural pass validates course/car/gear/name/controls, the required number of laps, physical TGTT v5 bytes, independent sector minima, exact per-car slot, Overall results flow, and profile save/reboot/reload. Logs include fuel, pit phase, world/lateral position, shifts, and audio failure counters. A failed run does not become a leaderboard entry.

Bordeaux driver refinement: high-speed lateral drift above 3000 units triggers the configured brake above speed $1400, except during intentional pit approaches. This targets the observed sharp bend after the right pit, where Razor could hit a roadside sign. Other course driving policies are unchanged.
