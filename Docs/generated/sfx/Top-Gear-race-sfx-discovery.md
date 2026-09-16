# Top Gear race sound-effect discovery

ROM: Top Gear (USA), SHA-256 `ca9889f17f184b3d99a2eaaa82af73e366f03ed00313fdd369e5e023b208e788`.

## Proved Player 1 race commands

- Engine start `$02` configures DSP voice 4. Engine update `$03` consumes the 16-bit APUIO2/APUIO3 parameter. The S-CPU NMI path reads signed WRAM `$1E5E`, clamps negative values to zero, adds `$0400`, writes the result to `$2142/$2143`, then sends `$03`. Manual gear changes alter the gameplay value that feeds this pitch; they do not swap engine samples.
- Boost `$05`: live four-race trace at global frame 7337 contains the real A-button boost input and APUIO1 `$05`. S-SMP handler `$1124` configures voice 5 with SRCN `$12`, pitch `$0400`.
- Finish `$07`: race code `$05:E7B6-$05:E7DD` increments the lap counter and, when the required count is reached, sets WRAM `$1EF5` bit `$04`; NMI clears that bit and sends `$07`. S-SMP handler `$114F` uses DSP voice 4 / SRCN `$13`, centered.
- Tire/skid `$0A`: NMI edge-detects WRAM `$1E67` and sends `$0A`; live steering trace reaches it repeatedly. Handler `$1191` uses voice 5 / SRCN `$10`, pitch `$0800`.
- Collision `$0B`: NMI consumes WRAM `$1EF5` bit `$80` and sends `$0B`; live trace coincides with sharp collision speed losses. Handler `$11AF` uses voice 5 / SRCN `$14`, pitch `$0400`.

Player 2 mirrors are engine `$0D/$0E`, boost `$10`, finish `$12`, tire/skid `$15`, collision `$16`.

## One-shot command and BRR behavior

Boost and tire/skid use DSP voice 5; finish uses DSP voice 4. The proved BRR sources for the three requested effects are self-terminating rather than looping: boost SRCN `$12` starts at `$BF10` and reaches END block `$C55B` header `$01`; skid SRCN `$10` starts `$B580` and reaches END block `$BB68` header `$C5`; finish SRCN `$13` starts `$C570` and reaches END block `$D20F` header `$99`. Each end header has END=1 and LOOP=0.

The earlier multi-second previews were wrong for a different reason: APUIO1 is level-sensitive. The S-SMP dispatcher echoes an accepted port-1 command but does not remember that an unchanged non-zero value has already been consumed. Holding `$05`, `$0A`, or `$07` on APUIO1 therefore dispatches/key-ons it repeatedly. The corrected Linux helper waits for the exact S-SMP acknowledgement, immediately writes neutral `$00`, verifies neutral acknowledgement, then lets one BRR traversal finish. Active output is approximately 0.349 s for boost, 0.166 s for skid, and 0.714 s for finish. The regression records a full second and requires at least 100 ms of exact natural silence after the final non-zero sample.

## Other driver entries

`$08/$09` are SRCN `$13` left/right pan variants of the same family as `$07`; `$13/$14` are the Player-2 mirrors. `$1A-$1D` configure SRCN `$16` on the P1/P2 effect voices with two envelope variants, but no normal four-race gameplay trigger has been proved for them. They remain explicitly unmapped. Control `$19` is used by the S-CPU driver/protocol and is not catalogued as a race sound effect.
