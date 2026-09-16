# Top Gear static-core field guide (release 1.2.0)

This note separates three kinds of knowledge so future work does not turn a screen label or a player guide into an invented variable name:

- **Core-proved:** established by the exact ROM, generated fixed-C cases, or an explicit core API.
- **Headless-observed:** reproduced from reset by this core with controller scripts and framebuffer/event receipts.
- **Gameplay hypothesis:** described by the manual or experienced players, but not yet tied to a proved game-logic address. These items are targets for characterization tests.

The accepted ROM is the unheadered 524,288-byte US revision with SHA-256 `ca9889f17f184b3d99a2eaaa82af73e366f03ed00313fdd369e5e023b208e788`.

## What each static-core layer does

| Layer | Current responsibility | Evidence boundary |
|---|---|---|
| Generated W65C816 | 8,685 normalized PBR:PC/E/M/X contexts in 29 fixed-C shards, plus generated ROM re-entry and executable-WRAM epochs | No runtime opcode decoder. Static dispatch coverage is not the same as natural gameplay reachability. |
| Machine bus | LoROM/WRAM mapping, open bus, PPU/CPU I/O, DMA, controller ports and CPU/APU latches | Current runtime guarantees semantic/event order, not exact physical 5A22 wait timing for every bus cycle. |
| V23 scheduler | NTSC beam order, refresh, NMI/IRQ, auto-joy, HDMA and scanline events | Nominal instruction timing; `cycle_timing_exact` remains false for current-runtime bus hooks. |
| V22 video | Mode 1 menus/HUD, Mode 7 affine path, OBJ/OAM cars and display objects, final BGR555 framebuffer | It renders state produced by the game. It does not infer speed, fuel, gear, AI or track state from pixels. |
| V27 audio | Fail-closed static S-SMP exact-PC/opcode path and static S-DSP PCM production | S-CPU/APU rendezvous is on the event-order clock. The retired alternate audio backend has been removed from the current core. |
| Snapshot | Serializes the live core and restores it only against the matching ROM/core contract | Top Gear has password progress and no battery SRAM; the SRAM compatibility API intentionally reports zero bytes. |
| Hooks | Reset, generated instruction before/after, data/MMIO bus read/write, completed-frame checkpoint and frontier | Instruction fetches are compiled into C and are not BUS events. A checkpoint is the completed framebuffer at V=240. |

## Menus and setup

The normal one-player route is **headless-observed**:

`boot/Kemco -> PRESS START -> OPTIONS -> 1 PLAYER -> ENTER NAME -> GEAR SELECT -> CONTROL METHOD -> CAR TYPE -> OPTIONS -> PLAY GAME -> track briefing -> race`

Useful **core-proved ROM data landmarks** are:

| Display/data item | LoROM address |
|---|---|
| `1 PLAYER`, `2 PLAYERS` | `0F:A6B3`, `0F:A6FD` |
| `SKILL LEVEL`, `COUNTRY` | `0F:A6BF`/`0F:A735`, `0F:A6CD`/`0F:A962`/`0F:B1F8`/`0F:B231` |
| `PLAY GAME`, `OPTIONS` | `0F:A6D7`, `0F:A6E3` |
| `GEAR SELECT`, `CAR TYPE` | `0F:A7E2`, `0F:A8D6` |
| `PLAYER SETUP`, players 1/2 | `0F:AC44`, `0F:AC53`/`0F:B4BC`, `0F:AC5E`/`0F:B4C9` |
| `PRESS START` | `0F:AFFB` |
| `CONTROL METHOD` and control labels | `0F:B0F2`; `BRAKE`, `GEARS`, `ACCEL`, `NITRO` occupy `0F:B0C3-0F:B1B2` data landmarks |

The four controller layouts and manual/automatic transmission are described in the gameplay guide. Manual mode uses shoulder buttons for gear changes. These control labels prove ROM data ownership, not the location of a live control-selection variable.

### Proved name fields and code paths

Headless Test 02 uses three controlled branches (blank, enter `A`, enter `B`) and traces the last generated instruction that writes each differing WRAM byte. It proves:

| Meaning | Live location | Proved code |
|---|---|---|
| Name-entry character index | direct page `$005E` | value becomes 1 after one committed character |
| Currently selected keyboard character | direct page `$0060` | `$0F:9578` writes ASCII `A`/`B` |
| Shared name/password text staging buffer | direct page `$0068-$006F` | `$0F:9583` commits the selected byte; this buffer is reused and is not persistent storage |
| Persistent Player 1 name | WRAM `$1F86-$1F8D` | `$0F:9BCF-$0F:9BE0` copies four words from `$68-$6F`; `$0F:9BD1` writes the first word |
| Player 1 name display/readback | WRAM `$1F86-$1F8D` -> direct page `$0068-$006F` | `$0F:9B7F-$0F:9B91`; `$0F:9B82` writes the first staging word |

The normal generated core and re-entry core now carry these comments beside the corresponding instructions. Nearby alternate storage at `$1FA3` is intentionally not labeled as Player 2 yet: the layout strongly suggests it, but a controlled two-player A/B test is still required.

The opponent names are different: they are fixed ROM records, not one contiguous WRAM string block. ROM `$0D:C47B-$0D:C512` contains 19 records of exactly eight bytes. `$0F:88A2` and `$0F:89B2` index that table with `opponent_index * 8`, then copy four words through `$0D:C481,X` into `$68-$6F` for text rendering. The records are:

`SIMON`, `RITCHIE`, `ASH`, `GREGS`, `CHRIS`, `ADE`, `T C`, `TIM`, `SIZ`, `MARK`, `BERNI`, `TONY`, `MATT`, `ROB`, `IAN`, `JAMES`, `SHAUN`, `PAUL`, `COMPUTER`.

## Cars

The names and published characteristics below are **manual/gameplay-reference facts**, not yet mapped live WRAM fields:

| Car | Colour | Maximum speed | 0-60 mph / 0-100 km/h | Grip | Fuel use |
|---|---|---:|---:|---|---|
| Cannibal | red | 147 mph / 235 km/h | 6.9 s | low | high |
| Razor | purple | 137 mph / 220 km/h | 5.0 s | low | medium |
| Weasel | blue | 137 mph / 220 km/h | 4.3 s | medium | medium |
| Sidewinder | white | 131 mph / 210 km/h | 3.5 s | high | low |

The important test implication is that a car-selection test must measure at least top speed, acceleration, lateral response, fuel drain and pit demand independently. A framebuffer car colour alone is not a physics oracle.

## Tracks and progression

The 32 **core-proved ROM course-name records** run from `0F:AC93` (`LAS VEGAS`) through `0F:AFAD` (`STONEHENGE`). The existing ROM table tests cover:

| Region | Courses |
|---|---|
| USA | Las Vegas, Los Angeles, New York, San Francisco |
| South America | Rio, Machu Picchu, Chichen Itza, Rain Forest |
| Japan | Tokyo, Hiroshima, Yokohama, Kyoto |
| Germany | Munich, Cologne, Black Forest, Frankfurt |
| Scandinavia | Stockholm, Copenhagen, Helsinki, Oslo |
| France | Paris, Nice, Bordeaux, Monaco |
| Italy | Pisa, Rome, Sicily, Florence |
| United Kingdom | London, Sheffield, Loch Ness, Stonehenge |

The game groups races into four-course regions. A top-five finish is required to continue to the next race; after four races the player must rank in the top three overall to advance to the next region. The reported points are 20, 15, 12, 10, 8, 6, 4, 3, 2 and 1 for positions 1 through 10. The exact US ROM also has 21 tested progress passwords (seven later regions across three skill levels).

Gameplay references describe longer tracks with pits, road obstacles, changing surfaces and night visibility. Fuel can be partially or fully replenished by remaining in the pit, and running out ends the race. Each car starts a course with three nitro boosts. Those behaviors are test targets until their writers/readers and live state are mapped.

## Race display and AI

The split-screen race HUD contains a course map, tachometer, speed, elapsed time, fuel, rank, gear and remaining nitro for each view. In one-player mode the lower view is still active and belongs to the computer rival; in two-player mode it belongs to player 2. The field has 20 cars total.

The **core-proved** fixed-width opponent-name table and its lookup paths are documented above. This proves display-name selection, not AI behavior.

Player reports describe the lower-screen rival as steering cleanly, accelerating when ahead of it and slowing when behind it: a catch-up/rubber-band model. Treat that as a **gameplay hypothesis**. The AI test must compare deterministic traces with the player stationary, driving normally, and leading by a large margin across all three skill levels. It should measure rival position/speed or a proved derivative, never identify an AI variable solely by a correlated byte.

## Headless hook contract and readiness result

The V27 current runtime now brackets every generated ROM, re-entry, executable-WRAM and interrupt instruction with `INSTRUCTION_BEFORE` and `INSTRUCTION_AFTER`. Low-WRAM interrupt trampolines synthesized by the semantic service use the same contract. Data/MMIO BUS events remain distinct from instruction fetches. Each completed hashed framebuffer emits one `CHECKPOINT`.

`v27-hook-readiness` passed on 2026-08-09:

- first frame: 11,002 paired before/after events;
- 5,599 bus reads and 4,399 bus writes;
- one completed-frame checkpoint and no frontier;
- distinct P1 `0x1000` and P2 `0x0080` physical states retained;
- a callback stop on the 100th BEFORE event left 99 completed instructions, then resumed to the same first completed frame after the hook was cleared.

The ROM has not enabled auto-joy during the first boot frame, so its result registers correctly remain zero there. Later menu/race tests must verify ROM-owned auto-joy polling after NMITIMEN enables it.

## Headless characterization series

| ID | Route | Primary oracle | Status |
|---|---|---|---|
| H0 | Hook registration, pairing, stop/resume, P1/P2 state | Hook event invariants and completed-frame count | Implemented; passing |
| 01 | Reset -> title -> Start -> options | Known framebuffer hashes, instruction/ROM/WRAM/MMIO coverage, no frontier | Implemented; first run passing |
| 02 | Blank/A/B one-player name entry and post-entry commit | WRAM differential plus exact last-writer PCs | Implemented; passing; persistent Player 1 name proved |
| 03 | Same one-player route, neutral versus Right held in an active race | Frame hash plus WRAM/writer differential | Exploratory test passing; candidate fields retained without semantic labels |
| 04 | Save one late-race snapshot, reload for P1 direction/buttons/P2 direction/neutral replay/A branch | Raw auto-joy destinations, writer PCs, byte-identical replay, repaired turbo helper completion | Implemented; passing |
| 04 | Manual/automatic x four controller layouts | Input-to-action matrix; pause, accel, brake, nitro and gear transitions | Planned |
| 05 | Four-car matrix | Measured acceleration, steady speed, steering response, fuel drain and nitro delta | Planned |
| 06 | Track/password matrix | 32 names, 21 passwords, briefing identity and stable first-race snapshot per route | Static tables pass; dynamic matrix planned |
| 07 | Race frame-zero determinism | Snapshot immediately before race, advance one frame with zero input twice, compare CPU/WRAM/PPU/frame hashes | Planned |
| 08 | Snapshot branch/replay | Save at title/setup/briefing/race, run N frames, reload and reproduce hashes/audio counters | Basic round trip exists; multi-scene determinism planned |
| 09 | Rival/AI response | Stationary, trailing and leading branches on each skill level; compare proved race metrics | Planned; rubber-banding remains a hypothesis |
| 10 | Fuel, pits and nitro | Controlled input branches; monotonic fuel, partial/full refuel, exactly three boost consumptions | Planned |
| 11 | Collision, surface and night | Same steering/throttle input from matched snapshots; compare speed/position penalties and PPU state | Planned |
| 12 | Finish, points and qualification | Finish positions 1-10, failure below fifth, region rank, password transition | Planned |
| 13 | Endurance/audio | Several complete races with static S-SMP/S-DSP, snapshot reload and PCM continuity | In progress; repaired `$0D7C` passed, deterministic `$122F` frontier at ~178 seconds |
| 14 | Automatic first race | Closed-loop road-centre steering, continuous X, configured nitro laps, per-lap HUD speed, game clock, pass count, finish snapshot | Completed in the removed pre-release harness; findings retained here |

Every new test should start from reset or a snapshot produced by a preceding fully headless route, hold buttons for a time window rather than a single guessed polling instant, use framebuffer hashes only for screen identity, and retain a frontier receipt. New WRAM names require a writer/reader trace plus at least two controlled branches that distinguish the proposed meaning.

## First characterization receipt

Test 01 ran for 34 emulated seconds and passed:

- title framebuffer first observed at 18,983 ms;
- Start held from 26,000 through 27,999 ms;
- options framebuffer first observed at 29,333 ms and remained the last frame;
- 2,043 completed frames and matching checkpoints;
- 28,087,835 static instructions, 2,225 unique ROM instruction addresses, and no executable-WRAM address on this short route;
- 15,524,972 bus reads and 1,427,030 bus writes;
- classified accesses: 58,854 PPU, 195,277 APU, 134,352 CPU-I/O, 12 controller-serial, 750,623 ROM-data, and 15,816,736 WRAM/mirror accesses;
- final BGR555 SHA-256 `fcfd1cc20df9d73f4399c20ad8cb45a9cd2996d1d0679530d5e91ba96f4aeca6` (options).

The exact machine-readable receipt is `docs/generated/STATIC-CORE-HEADLESS-TEST-01.json`.

## Incremental characterization receipts

Test 02 ran blank/A/B branches and passed. At the edit capture only `$0060` and `$0068` distinguished A from B; after leaving entry the three exact A/B locations were `$0060`, `$0068`, and persistent `$1F86`. Their final writers were `$0F:9578`, `$0F:9B82`, and `$0F:9BD1`, respectively. The same test byte-compares all 19 opponent-name records in the ROM. Its receipt is `docs/generated/STATIC-CORE-HEADLESS-TEST-02-NAMES.json`.

Test 03 proves that the scripted 59-second point is already an active split-screen race, not the car-selection menu. Holding Right from 57 seconds produces a different framebuffer and 17 WRAM differences from neutral. `$0011` and `$0015` reflect the held Right bit and are both written by the controller polling path (`$00:EC3A` and `$00:EC43`). Other differences are deliberately only candidates because position, animation, road curvature, and elapsed simulation state can all correlate. Its receipt is `docs/generated/STATIC-CORE-HEADLESS-TEST-03-RACE-STEERING.json`.

An earlier alternate setup probe reached the now-closed static-audio frontier after 44,210,177 instructions: S-SMP `PC=$1124` read `$CD` where the exact static service expected `$FF`, surfaced at S-CPU `$00:B856` as `STATIC-APU`. The ROM-derived `$1124-$1139` helper is now a regression-tested part of the authority.

Test 04 proves the NMI controller-copy layout. The ROM reads 16-bit auto-joy results `$4218` and `$421A`. `$00:EC3A` stores P1's current held mask at direct page `$0010-$0011`; `$00:EC4A` stores P2 at `$0012-$0013`. The following code computes the game's new/unconsumed-input latches at `$0014-$0015` and `$0016-$0017` as `current & (~previous | previous_latch)`, with stores at `$00:EC43` and `$00:EC53`. Matched Right, Left, Down, Up, B, Y, X, L, R, A and P2-Right branches prove the raw held masks. A second neutral restoration reproduces all WRAM and the framebuffer exactly. Holding P1 A (`$0080`, turbo under the tested control method) now completes through the repaired ROM-derived S-SMP helper `PC=$1124-$1139`.

The extended manual-transmission route proves X acceleration, a Y braking interval, R upshifts, an L downshift, and continued R shifting. ROM-derived helpers `PC=$1124-$1139` and `PC=$11AF-$11C4` cover turbo and collision/rival effects. The later deterministic `PC=$0D7C` frontier is closed by freezing the complete `$0D7C-$0D82` helper (`DA 4A DA 4C A2 33 6F`) as four exact instruction PCs and seven protected bytes. Mixed, hard-left and hard-right routes subsequently exposed `PC=$122F`/`$CD`; offline analysis proved it as command `$12` in the `$10A7` dispatch table. The complete 29-command CFG contains 278 instructions / 520 code bytes, including `$122F-$1244` voice-6 setup, and raises authority to 1,148 exact PCs / 2,261 protected bytes.

The cumulative plain-text inventory of semantic comments and findings is `docs/Static Findings.txt`. `static-findings-sync` verifies its required source-comment anchors and key addresses so new semantic annotations must be reflected there.

The automatic Las Vegas test identifies the live P1 display/result position at
WRAM `$011A` (zero based) and its lap progression at `$011E`; the lower CPU
view uses `$012C` and `$0130`. Its first completed run held X on every race
frame, used A once on each of the three start-line transitions, and placed 5th.
The static RESULTS frame began at 179,300 ms. The test records race-only PCM,
saves start/finish snapshots, and reload-verifies the finish state and frame.
Its receipt is `docs/generated/STATIC-CORE-HEADLESS-TEST-05-CLEAN-AUTOMATIC-RACE.json`.

The pre-release race harness selected the white Sidewinder from the lower-left
car slot. It reported each lap's top visible HUD speed from proved
raw speed `$1E5A`, frozen in-game finish ticks from `$1F26` (live fallback
`$1EAE`), and forward position gains from `$011A`. The earlier blue-Weasel
results remain historical receipts. The harness and toolbar button were removed
from the release frontend after these observations were documented.

The subsequent boost-only revision preserves that car and route but replaces
lap-number targets with three geometry/phase windows: lap 1 final-corner exit,
lap 2 longest straight, and lap 2 final-corner exit onto start/finish. They
trigger at 120,166, 132,316, and 142,850 ms from reset. This run finishes P1
7th and the lower CPU rival 3rd, as independently visible on RESULTS. Its
finish snapshot reloads exactly and its 88.371-second race WAV has no Full
Static AOT/S-DSP failure.

Five completed Las Vegas snapshots identify WRAM `$1F62-$1F75` as the
20-entry racer-ID finishing-order permutation. The first ten bytes match the
RESULTS rows exactly. IDs are `0 PLAYER`, `1 COMPUTER`, `2 SIMON`, `3 RITCHIE`,
`4 ASH`, `5 GREGS`, `6 CHRIS`, `7 ADE`, `8 T C`, `9 TIM`, `10 SIZ`, `11 MARK`,
`12 BERNI`, `13 TONY`, `14 MATT`, `15 ROB`, `16 IAN`, `17 JAMES`, `18 SHAUN`,
and `19 PAUL`. The corresponding top-ten points are 20/15/12/10/8/6/4/3/2/1.

Generated code `$0F:8957-$0F:895E` initializes the identity permutation;
`$0F:888A-$0F:8891` adds the per-rank ROM award table to cumulative
championship points `$1F4E-$1F61`; `$0F:8967-$0F:8988` sorts racer IDs by those
points; and `$0F:8B6E-$0F:8BB3` consumes all 20 sorted IDs while building
results data. `$0F:86E9-$0F:86FF` finds racer IDs 0 and 1 in the order
table and produces immediate one-based slot values at `$1FF8+ID*2`; those
staging bytes are deliberately not conflated with the separately observed
HUD/result fields `$011A` and `$012C`.

The headed traffic-avoidance experiment used visible OAM state, not
a guessed AI variable. A saved one-player Las Vegas start frame places P1's
own visible car in OAM entries 3-14. Other objects in a narrow upper-view
near-road band can conservatively block a boost and request an avoiding steer.
This is route-specific display evidence only; it does not prove stable OAM
car slots or identify collision, speed, steering, or rubber-band AI state.

## Research used to form test hypotheses

- [Top Gear SNES instruction booklet](https://www.retrogames.cz/manualy/SNES/Top_Gear_-_SNES_-_Manual.pdf)
- [Games Database overview and manual link](https://www.gamesdatabase.org/game/nintendo-snes/top-gear)
- [GameFAQs guide and walkthrough](https://gamefaqs.gamespot.com/snes/588802-top-gear/faqs/38181)
- [MoeGamer gameplay overview](https://moegamer.net/2018/02/23/snes-essentials-top-gear/)

The manual is preferred for controls, cars, nitro, pits and official driving rules. Community sources are useful for candidate AI behavior and edge cases but remain hypotheses until a deterministic core test confirms them.

## Headless Test 06: complete USA country

The input-only white Sidewinder campaign now completes all four USA races from reset with no WRAM patches.  It finished Las Vegas 1st (20 points), Los Angeles 4th (30 cumulative), New York 2nd (45 cumulative), and the six-lap San Francisco finale 4th (55 cumulative).  The top-ten racer IDs and a full snapshot were retained at each RESULTS page.  The framebuffer road-centre controller uses the original rows 40-70 on Las Vegas, Los Angeles and San Francisco; New York needs the nearer rows 55-90 and a wider 108-148 dead-zone.  The OAM traffic band is enabled only on the first two courses because its roadside-object false positives hurt the latter two.

Continuing for 3,600 frames after San Francisco proved the country transition instead of stopping at the finish line: PLAYER was ranked 2nd, qualified for the next country, received AMATEUR password `MOONBATH`, reached the Rio de Janeiro/Brazil briefing (four laps), and entered that race.  Static audio stayed AOT-only with zero S-SMP failures, DSP failures, or automatic fallback use throughout.

## Release 1.2.0 static audio command surface

The ROM's complete proved music selector set is `$01-$07`. `$00:817C-$00:81A0`
derives race selectors `$02-$05` from the low two bits of `$1F06` using
`(($1F06 & 3) ^ 3) + 2`. Callers `$0F:858D` and `$0F:8563` feed the common
APUIO routine `$0F:8133` and produce menu/title-side selectors `$06` and `$07`.
Caller `$0F:8675` reaches `$01`, whose sequence pointer is `$13AB`. S-SMP
`$0A17-$0A24` resolves all seven pointers from the table based at `$1397`.
The seven eight-byte descriptors are `$13AB/$13B3/$13BB/$13C3/$13CB/$13D3/
$13DB`; they select channel-pointer blocks beginning at `$13E3/$13F3/$1403/
$1413/$1423/$1433/$1443`. Those channel streams contain the pattern, loop and
instrument events that assemble the soundtrack; a selector is not itself a
complete PCM track.

APUIO1 is independent of music. Its compare/dispatch path at `$1092-$10A3`
indexes commands `$01-$1D` through the 29 little-endian entries at
`$10A7-$10E0`. The public catalogue records the table and handler address for
every command, including non-audible masks, no-ops, parameter controls and the
`$12AE` reset/IPL handler. Sixteen handlers are standalone audible effects in
the initialized title-driver state; `$02/$03` and `$0D/$0E` are paired
voice-setup/pitch controls and are not falsely presented as standalone sounds.

Music changes require two coupled values, not only a direct APUIO0 write.  The
power-on path `$00:805A-$00:807A` sends command `$18` on APUIO1, loads A=0 and
calls `$07:8000`, then clears APUIO0, waits, loads selector `$01`, and writes it
at `$00:8077`.  Other song changes supply `selector-1` to `$07:8000` before the
final APUIO0 selector.  `$07:8000` indexes the seven-word offset table at
`$07:8164` and walks a song-specific resource chain based at `$07:8172`; those
chains populate the high ARAM BRR/sample/instrument state beginning near `$8900`.

The first reset-based preview repair still changed only the final `$00:8077`
selector, so Title was complete but `$02-$07` retained Title upload resources
and played incomplete arrangements.  The corrected
`topgear_recomp_music_preview_prepare` now breaks before `$00:8064`, supplies
`selector-1` to the real `$07:8000` uploader, then breaks before `$00:8077` and
supplies the final selector.  `topgear_recomp_audio_preview_advance` then
advances only S-SMP/S-DSP time.

`test_music_upload_chains.c` prevents regression by hashing ARAM `$8900-$FFFF`
after preparation and requiring seven distinct deterministic song-resource
states.  The corrected Las Vegas and Hiroshima resource states also match the
saved live four-race campaign states.  These helpers remain research/regression
surfaces; production audio is generated live by the running game's same Full
Static S-SMP/S-DSP authority.

## Release 1.2.0 race sound-effect / engine research

Race sound effects use a compact APUIO1 command surface on top of the same Full
Static S-SMP/S-DSP authority as music.  Player 1 engine setup is command `$02`
(voice 4) and engine pitch update is `$03`.  During race NMI the S-CPU reads the
signed engine-driving value at WRAM `$1E5E`, clamps a negative value to zero,
adds `$0400`, writes the resulting 16-bit pitch to `$2142/$2143`, and then sends
`$03`.  Player 2 mirrors this at `$1E60/$1E64` with `$0D/$0E` on voice 6.
Therefore speed and manual gear changes do not select different engine samples;
they alter the gameplay value which continuously retunes the existing engine
voice.  The captured manual route proves this directly: before the first shift
the pitch reaches about `$11F6` and drops to about `$0EAC` in second gear; the
next shift falls from about `$1230` to `$0CA2` in third before rising again.

The proved Player-1 discrete race commands are boost `$05`, finish-line `$07`,
tire/skid `$0A`, and collision `$0B`.  The four-race live trace contains the real
A-button boost transition at global frame 7337 and APUIO1 `$05`.  Finish is
source-proved by `$05:E7B6-$05:E7DD`: reaching the required lap count sets
`$1EF5` bit `$04`, which NMI consumes to issue `$07`.  Tire/skid is edge-detected
from `$1E67` and collision consumes `$1EF5` bit `$80`.  Player-2 mirrors are
boost `$10`, finish `$12`, tire/skid `$15`, and collision `$16`.

The S-SMP command bodies and live DSP trace separate the effect voices correctly:
boost uses DSP voice 5 / SRCN `$12` / pitch `$0400`, tire-skid uses voice 5 /
SRCN `$10` / pitch `$0800`, collision uses voice 5 / SRCN `$14`, while finish
uses DSP voice 4 / SRCN `$13` / pitch `$0400`.  The underlying proved BRR streams
for boost, skid and finish are self-terminating: boost starts at ARAM `$BF10`
and reaches END block `$C55B` (header `$01`), skid starts `$B580` and ends at
`$BB68` (header `$C5`), and finish starts `$C570` and ends at `$D20F` (header
`$99`).  In all three cases the BRR END bit is set and LOOP bit is clear.

A second protocol detail is essential for isolated playback: APUIO1 is a
level-sensitive command latch.  The S-SMP dispatcher reads a stable port-1 byte,
echoes it back as acknowledgement, and dispatches it; it does not suppress an
unchanged non-zero value as an already-consumed event.  Therefore leaving `$05`,
`$0A`, or `$07` asserted makes the driver key-on the same effect repeatedly.
`topgear_recomp_sound_command_pulse` now holds a discrete command only until the
S-SMP acknowledgement, immediately restores neutral `$00`, verifies the neutral
acknowledgement, and then lets the BRR sample terminate naturally.  The corrected
single-occurrence active durations are about 0.349 s for boost, 0.166 s for skid,
and 0.714 s for finish.  The race-audio regression requires at least 100 ms of
natural silence after each pulsed effect, so the former repeated-command bug is
fail-closed.

Driver commands `$08/$09` are left/right pan variants using the same SRCN `$13`
family as the centered `$07`; `$13/$14` mirror those variants for Player 2.
Commands `$1A-$1D` use SRCN `$16` with two envelope variants, but no normal
four-race gameplay trigger has been proved for them. They remain named only as
unmapped driver effects instead of receiving guessed game-event labels.

`frontend/headless/topgear_sfx_recorder.c` is the Linux audio-research surface.
It loads the complete Las Vegas race resource chain, stops music, and can record
an isolated proved effect, a fixed engine pitch, or the full set.  Its automatic
and manual engine demonstrations replay pitch timelines captured from the real
game rather than synthesizing arbitrary sweeps. `test_sfx_race_audio.c` prevents
regression with fixed deterministic PCM hashes for boost, finish, skid,
collision, engine `$0400`, and engine `$1200`, while still requiring zero Full
Static AOT/DSP failures.
