# Current Definitive integration plan

Current user instructions supersede historical restrictions below. Parts 1–4 and the independent ninth voice/SimCity movement cue are complete. Preserve current Definitive menus, Career/Rally/Time Trial, 50% menu music, music-only menu Mute, Data and background settings saves.

5. Integrate sealed TG2 and TG3000 ROM-derived payloads and exact AOT authorities as isolated modules behind semantic engine/track requests. Keep original game/APU protocols intact; no runtime interpreter, Mesen, DSP-4, WAV playback or oracle-state initialization.
6. Apply one selected-engine music gain to dry/echo, with unscaled feedback and independent cues. Preserve native racing effects.
7. Use the proven ninth cue voice with all three engines without stealing music voices.
8. Snapshot engine/track, sequencing/random state, pending transitions, clocks, AOT/APU/DSP and cue state; require deterministic continuation.
9. R cycles TG/TG2/TG3000 title music at title/menu screens, once per press, without dismissing the title; leave L alone. Add Career Music: Complete / Classic Random, changed with D-pad Left/Right and saved in Data. Complete sequences gameplay-only tracks in TG, TG2, TG3000 order, looping after the last track; exclude title, qualifying, results and ending tracks. Classic Random uses a persistent shuffled bag of all 11 gameplay tracks. Rally preselects eight unique songs from that pool; each Time Trial start/retry consumes its next unused gameplay song. See MUSIC-SHUFFLE-STATE-2026-09-11.md for the current Data format and validation.
10. Qualify all imported tracks, gains, cue isolation, switches, snapshots, native race effects, menus/screenshots, persistence and full regression suite. Produce listening recordings and install only a passing build.

Parts 5–10 are implemented and qualified in the current Definitive core. See MUSIC-INTEGRATION-RESULTS-2026-09-11.md for the current implementation and test evidence. The original research plan follows as historical evidence; its old pending-approval and source-boundary statements are superseded by the current handoff and user instructions.

---

# Top Gear 2 / Top Gear 3000 Music-System Transplant into Top Gear

Date: 2026-09-08
Workspace: `/mnt/data/topgear_music_transplant`
Status: Parts 1-4 technically complete. Top Gear 2 and Top Gear 3000 standalone Full Static audio laboratories are sealed; Top Gear 3000 user listening approval is pending. `Top Gear Definitive.zip` is explicitly excluded from this music-transplant work unless the user later requests otherwise.

## User correction — authoritative source boundary

For this music-transplant project, use the static core in `top gear audio.zip`. Do **not** modify, merge from, or overwrite `Top Gear Definitive.zip`. Any earlier draft wording proposing a Definitive rebase is superseded by this instruction.

## 1. Intake completed

The requested material was copied from the ChatGPT Library into this Linux workspace and unpacked into separate trees.

Present locally:

- `top gear audio.zip` — the accepted audio-specific authority.
- `Top Gear Definitive.zip` — the newest menu/gameplay/Rally/Time Trial authority.
- `Top Gear (USA).sfc` — exact Top Gear test ROM.
- `Top Gear 2 (USA).zip` / extracted `Top Gear 2 (USA).sfc`.
- `Top Gear 3000 (USA).zip` / extracted `Top Gear 3000 (USA).sfc`.
- `Starter SNES v9.zip` — temporary fallback because no actual `Starter SNES v10.zip` could be located in the Library.
- `dsp4.rom` — Top Gear 3000 DSP-4 firmware required by Mesen.

All supplied ZIPs used for this workspace passed archive integrity testing before extraction.

The unpacked research scan contains 964 files / 107,209,900 bytes. All 860 text/source files were read into the local research index. The 104 binary files were inventoried and hashed/classified; the ROMs, ARAM captures, snapshots/audio artifacts and other binaries relevant to this research were then inspected with the appropriate binary/runtime tools rather than misreading them as text.

The workspace-wide inventories are:

- `research/all-files-manifest.csv`
- `research/all-files-manifest.json`
- `research/all-text-files.jsonl`
- `research/scan-summary.json`

## 2. Exact ROM / firmware identities

Top Gear (USA):

- size: 524,288 bytes
- SHA-256: `ca9889f17f184b3d99a2eaaa82af73e366f03ed00313fdd369e5e023b208e788`
- LoROM, no enhancement chip

Top Gear 2 (USA):

- size: 1,048,576 bytes
- SHA-256: `76b2702c4be8b668c1017f2817c280283c275eaa41535bf6ffa2b8d2220b68c6`
- FastROM LoROM, no enhancement chip

Top Gear 3000 (USA):

- size: 1,048,576 bytes
- SHA-256: `6be49983976564f1fd9eff2f14f5bb41d3a0ff48573e39318088ecce286aca62`
- FastROM LoROM, DSP-4 title

DSP-4 firmware found in the Library:

- file: `dsp4.rom`
- size: 8,192 bytes
- SHA-256: `752d03b2d74441e430b7f713001fa241f8bbcfc1a0d890ed4143f174dbe031da`

The bundled MesenCE source expects the combined firmware name `dsp4.rom` (or split `dsp4.program.rom` / `dsp4.data.rom`). Its default DSP firmware sizes are 0x1800 program + 0x0800 data = 0x2000 / 8,192 bytes, exactly matching the Library file.

## 3. Starter SNES / Mesen status

No real `Starter SNES v10.zip` was found after exact-name and broad Library searches. The newest actual Starter archive located was `Starter SNES v9.zip`, so it was copied only as an explicitly marked fallback. It has not been renamed or treated as v10.

Starter v9 contains the complete MesenCE 2.2.1 SNES headless oracle package. It was unpacked locally and its self-test passes. The headless package exposes SNES CPU, SPC/S-SMP, S-DSP memory/register domains and NEC DSP domains, which is sufficient for this investigation.

## 4. Authoritative base for this music-transplant project

The user clarified that this project must **not touch `Top Gear Definitive.zip`**. The authoritative working base is the altered static core already stored inside `/Top gear mods/top gear audio.zip`, specifically `02-ACCEPTED-SOURCE/`.

`Top Gear Definitive.zip` may exist in the Library for a separate gameplay/menu project, but it is outside this music-transplant work and must not be merged, overwritten, patched, or used as the production source unless the user explicitly changes that instruction later.

The accepted audio architecture that must remain locked as the Part 1 baseline is:

- original Top Gear Full Static S-SMP/S-DSP music path remains authoritative;
- voices 0-6 form the current Top Gear music bus;
- one Q15 gain scales the complete music bus, approved test value 50%;
- audible echo return is scaled once while internal echo feedback is not altered;
- voice 7 bypasses the music gain and carries accessibility cues;
- SimCity navigation cue = accepted movement;
- Top Gear boost = ordinary accepted confirmation;
- Top Gear finish-line cue = Start Race confirmation.

## 5. Existing Top Gear music command architecture

The current Top Gear static core already has a mature map of its own soundtrack system.

Top Gear has seven proved music selectors `$01-$07`. A song change is not merely one APUIO0 write: the S-CPU first calls the real `$07:8000` song-resource uploader with `selector-1`, then delivers the final selector. The uploader walks song-specific resource chains and populates high ARAM sample/instrument state. The live S-SMP resolves seven sequence descriptors and channel streams. APUIO1 is a separate sound-effect/control command surface.

This is useful because the transplant should fit behind a project-level music-engine abstraction rather than replacing game/menu logic with emulator-specific calls.

## 6. Headless Mesen findings — Top Gear 2

Top Gear 2 runs normally in the bundled headless Mesen without extra firmware. A 600-frame no-input run reaches its main menu and continues producing normal SPC/DSP activity.

Observed audio characteristics:

- first main uploaded driver execution appears around SPC `$0810`;
- initial S-DSP directory register: `DIR=$40`;
- echo start: `ESA=$FF`;
- echo delay: `EDL=$00` during the observed opening state;
- normal KON/KOFF sequencing continues after the upload;
- once the initial upload is complete, the observed 100-700 frame window contains no new S-CPU APUIO writes while the SPC driver keeps generating music. This strongly suggests an autonomous resident APU music engine after initialization.

Large frame-600 ARAM regions match immutable Top Gear 2 ROM data directly. Examples include:

- ARAM `$CFA7-$FE6E` (11,976 bytes) from ROM `$0DBF2D-$0DEDF4`;
- ARAM `$7D90-$A45F` (9,936 bytes) from ROM `$0C9956-$0CC025`;
- ARAM `$AA3F-$C24A` (6,156 bytes) from ROM `$0CD75A-$0CEF65`;
- ARAM `$4628-$584B` (4,644 bytes) from ROM `$0D3538-$0D475B`;
- ARAM `$65E7-$74E9` (3,843 bytes) from ROM `$0D61C3-$0D70C5`.

Low driver fragments map back around ROM `$0D0005` onward. This is strong static evidence that the driver/assets can be reconstructed from immutable ROM authority rather than treating an emulator ARAM dump as production data.

One caution already exposed by the trace: Top Gear 2 issues KON value `$C0`, which includes DSP voices 6 and 7. During the observed title/menu state voice-7 VOLL/VOLR remained zero, but the driver still touches/keys that voice. Therefore the current Top Gear assumption that physical voice 7 is always safe for accessibility cues cannot simply be carried into every Top Gear 2 track without a complete voice-occupancy survey.

## 7. Headless Mesen findings — Top Gear 3000

Without DSP-4 firmware, Top Gear 3000 does not progress correctly in Mesen: the oracle reports only two CPUs, the picture stays black through frame 600, and the SNES CPU remains in an early startup loop.

After putting the Library `dsp4.rom` in Mesen's isolated `Firmware` directory:

- Mesen reports three CPUs;
- frame 120 renders the Kemco / Top Gear 3000 presentation;
- later frames progress through the starfield/story introduction;
- the S-CPU performs a large CPU-to-APU upload;
- the SPC/S-DSP driver initializes normally.

This proves the user's firmware suggestion was correct and the Library firmware is the required Mesen dependency for this ROM.

Observed audio characteristics after the firmware fix:

- uploaded driver execution appears around SPC `$0840`;
- `DIR=$40`;
- `ESA=$F0`;
- `EDL=$00` during the observed opening state;
- the initial CPU/APUIO upload is large;
- after initialization, the observed 120-700 frame window contains no S-CPU APUIO writes while the SPC driver continues its own DSP/event work.

Frame-600 Top Gear 3000 ARAM also maps strongly to immutable ROM regions. Examples:

- ARAM `$459C-$6620` (8,325 bytes) from ROM `$0C5DCA-$0C7E4E`;
- ARAM `$9FC0-$B80A` (6,219 bytes) from ROM `$0CE3FF-$0CFC49`;
- ARAM `$6621-$76CA` (4,266 bytes) from ROM `$0DBC71-$0DCD1A`;
- ARAM `$7CAA-$881F` (2,934 bytes) from ROM `$0FD11C-$0FDC91`;
- ARAM `$9642-$9FBF` (2,430 bytes) from ROM `$06ED04-$06F681`;
- low driver fragments map directly around ROM `$0364B1-$036F75`.

The important architectural hypothesis is now testable: DSP-4 is definitely necessary to boot Top Gear 3000 as a game/oracle, but the music itself appears to become resident/autonomous on the SNES APU after upload. The final transplant should not include a DSP-4 dependency unless a later static dependency proof shows that music commands or resources actually require it. This must be proved rather than assumed.

## 8. Top Gear 2 and Top Gear 3000 use a closely related SPC music-driver family

This is the strongest structural finding from the sequel comparison.

A rolling exact comparison of the low SPC code region `$0800-$1800` found 1,212 nontrivial matching 16-byte windows between Top Gear 2 and Top Gear 3000, clustered around consistent relocation deltas. The strongest relocation families include:

- `+0x121`: 372 windows;
- `+0x0E8`: 192 windows;
- `+0x08A`: 187 windows;
- `-0x02B`: 75 windows;
- `-0x00F`: 56 windows;
- `-0x02D`: 52 windows.

In the same low-code comparison, original Top Gear versus Top Gear 2 produced zero nontrivial 16-byte matches, and original Top Gear versus Top Gear 3000 also produced zero.

At frame 600, Top Gear 2 and Top Gear 3000 additionally share a 3,238-byte identical same-address ARAM run at `$335A-$3FFF`, plus smaller identical regions. That large run should be classified before assuming it is code; it may contain tables/data as well.

Conclusion: the two sequel games clearly use the same or a closely related later music-driver lineage, while original Top Gear uses a different earlier driver. The safest implementation is therefore **shared sequel-driver infrastructure with separately proved Top Gear 2 and Top Gear 3000 generated authority/assets**, not two entirely unrelated backends and not one blindly deduplicated code blob.

## 9. Production architecture recommendation

Do not transplant Mesen, an SPC interpreter, or captured ARAM snapshots into production.

Reuse the existing Top Gear project-owned S-DSP implementation. The sequel games target the same SNES S-DSP hardware; what changes is principally the resident S-SMP/SPC program, ARAM layout, sequence/instrument/sample resources, and S-CPU command/upload contract.

Create a project-level selectable music-engine layer with three identities:

1. original Top Gear;
2. Top Gear 2;
3. Top Gear 3000.

Under that layer:

- original Top Gear continues using its existing Full Static S-SMP authority;
- Top Gear 2 gets its own generated exact-PC/opcode static S-SMP authority plus immutable asset/upload manifest;
- Top Gear 3000 gets its own generated exact-PC/opcode static S-SMP authority plus immutable asset/upload manifest;
- both sequel implementations share generator/runtime infrastructure where semantics are proved identical;
- Mesen remains an external oracle only.

No generic runtime SPC700 fetch/decode/interpreter should be introduced.

## 10. Plan of action

### Phase 0 / Part 1 — Lock the accepted audio static core as the safe baseline — COMPLETE

1. Start only from `top gear audio.zip` -> `02-ACCEPTED-SOURCE/`.
2. Keep `Top Gear Definitive.zip` outside the working tree and do not merge from it.
3. Verify the audio archive and exact Top Gear ROM identity.
4. Rebuild the accepted altered static core in a fresh Linux build directory.
5. Run the deterministic/core regression set plus all accepted audio-specific gates.
6. Rerun the saved 82-second all-directions route and capture the approved 81-second WAV.
7. Require the fresh WAV and route trace to reproduce the archived accepted artifacts byte-for-byte.
8. Package the accepted source, accepted listening evidence, fresh Part 1 validation, the research plan, Starter/Mesen fallback material, and a Part 2 handoff. Keep copyrighted game ROMs external and identify them by exact filename/hash.

Part 1 result on 2026-09-08: fresh build succeeded; 17/17 fast deterministic/core tests passed; integrity manifests reproduced exactly; the 82-second route reached the documented endpoint with zero AOT/DSP/fallback failures; the fresh 81-second WAV SHA-256 is `df70838ae7da07ff9fee2a980c6e2849536b8b302a2a7579b75359fd4dc9ff73` and is byte-for-byte identical to the accepted WAV; the fresh route CSV is also byte-for-byte identical to the archived route CSV.

### Phase 1 / Part 2 — Complete the Top Gear 2 audio authority map — COMPLETE

1. Freeze the exact Top Gear 2 ROM hash above.
2. Build a deterministic ROM-to-ARAM upload manifest from immutable ROM bytes, including driver code, sequence data, instrument tables, source directory entries and BRR sample blocks.
3. Statically discover the resident SPC program from the uploaded ARAM and identify every executable exact PC/opcode context required by the music engine.
4. Use Mesen only to validate reached state and timing, never to create production authority.
5. Map every S-CPU-to-APU command and every song selector by controlled title/menu/race transitions.
6. Catalogue every song/track and record its command/resource requirements.
7. Survey DSP voice occupancy for every song, including voice 7, plus PMON/NON/EON/echo behavior.
8. Capture known-good ARAM, DSP-register, KON/KOFF and native PCM fingerprints for regression.

Top Gear 2 should be first because it has no coprocessor firmware dependency and its ROM-to-ARAM payload mapping is already especially clean.

### Phase 2 / Part 3 — Build a sequel-audio laboratory before touching gameplay — COMPLETE

Create a research/test executable that uses the Top Gear project's real S-DSP and new static S-SMP authority but is isolated from Career/Rally/Time Trial gameplay.

For Top Gear 2 first, it should:

1. initialize the exact sequel ARAM/resources from immutable ROM-derived data;
2. start the exact generated static S-SMP driver;
3. accept a song ID through a research-only API;
4. advance S-SMP/S-DSP deterministically;
5. record native PCM/WAV, ARAM and DSP traces;
6. compare the result against Mesen for the same song.

This separates “can we reproduce the sequel audio system exactly?” from “have we integrated it into Top Gear's game state correctly?” and makes failures much easier to isolate.

### Phase 3 / Part 3 — Lower Top Gear 2 to production Full Static audio — COMPLETE

1. Generate the exact-PC/opcode S-SMP AOT owner for the proved Top Gear 2 driver contexts.
2. Keep fail-closed behavior for any unproved SPC execution, ARAM read, DSP state or command path.
3. Reuse the existing project S-DSP hardware implementation rather than adding another DSP emulator.
4. Implement the Top Gear 2 upload/resource initializer from immutable ROM-authoritative blocks.
5. Implement the proved Top Gear 2 song-command adapter.
6. Match Mesen ARAM/DSP/PCM checkpoints and command transitions.
7. Add snapshot serialization for the new driver state.
8. Seal the Top Gear 2 laboratory before linking it to gameplay.


Part 3 technical result on 2026-09-09: the Top Gear 2 standalone Full Static laboratory is sealed under Starter SNES v10. The resident driver is regenerated from immutable ROM compression, all four packages are reconstructed without oracle ARAM, all six tracks produce non-silent project-S-DSP PCM with zero static-audio failures, final output is byte-identical to the posted listening samples, playing-state snapshot replay is byte-identical, cold AOT/payload generation is deterministic, and native Mesen 32,040-Hz settled waveform correlation is strong for all six tracks. User listening approval remains separate and must not be inferred.

### Phase 4 — Map and lower Top Gear 3000 using the shared sequel infrastructure

1. Keep `dsp4.rom` available to the Mesen oracle so the source game boots correctly.
2. Complete the Top Gear 3000 ROM-to-ARAM manifest from the now-proved frame-600 payload ranges and remaining smaller regions.
3. Map every Top Gear 3000 song command/selector and every track.
4. Prove whether any post-initialization music command/resource depends on the SNES CPU's DSP-4 interaction.
5. If no dependency exists, keep DSP-4 entirely out of the transplanted Top Gear music runtime; it remains only an oracle dependency for running the source game.
6. If a real dependency exists, isolate the exact finite music-related DSP-4 semantic requirement rather than importing a general coprocessor/emulator.
7. Generate a separate Top Gear 3000 exact-PC/opcode S-SMP AOT authority using the same sequel-driver infrastructure.
8. Validate its standalone audio laboratory against Mesen.

Part 4 technical result on 2026-09-09: **COMPLETE pending user listening approval.** All seven Top Gear 3000 soundtrack packages are reconstructed from immutable ROM authority; the resident `$0840-$15C0` SPC driver is lowered to 1,259 fail-closed exact PCs / 2,682 protected code bytes / 107 used opcodes with zero conflicts; all seven 20-second project-S-DSP runs pass with zero AOT/DSP/unknown/overflow/code-write failures; all seven playing snapshots replay byte-identically; repeated PCM is byte-identical; native Mesen pre-resampler PCM comparison is strong after correcting the package-specific `$40`/`$20` S-DSP DIR command; DSP-4 remains oracle-only and is not a production audio dependency. See `11-PART4-TOP-GEAR-3000-FULL-STATIC-LAB/`.

### Phase 5 — Add the project-level music-engine selector

Add a core-owned semantic selector such as:

- `TOP_GEAR`
- `TOP_GEAR_2`
- `TOP_GEAR_3000`

The game/menu code should request “engine + track/song” through a neutral static-core API. It should not know SPC addresses or Mesen details.

Original Top Gear stays the default until the user chooses otherwise. This also gives a clean way to decide later whether the sequels are selectable soundtracks globally, per mode, per race, or through a future audio-options screen.

### Phase 6 — Generalize the accepted music-volume bus safely

The present accepted fader assumes Top Gear music owns voices 0-6 and accessibility owns voice 7. That assumption is game-specific.

Change the DSP-side music-bus ownership from a hard-coded `voice < 7` rule to an explicit per-engine music-voice mask.

For original Top Gear, preserve the accepted mask/behavior exactly.

For each sequel soundtrack, determine the mask from the complete voice-occupancy proof. If a sequel needs all eight voices, music gain must include all eight voices without stealing one for accessibility.

Keep the accepted semantics:

- one gain on the complete music dry bus;
- one matching gain on audible echo return;
- no double-scaling of internal echo feedback;
- accessibility cues remain full-strength and outside the music fader.

### Phase 7 — Resolve the accessibility-cue / voice-7 conflict without damaging sequel music

Do not assume voice 7 is free in the sequel drivers. Top Gear 2 already keys voice 7 in the observed driver, even though its opening state kept voice-7 volume at zero.

First, survey every sequel track. If a physical S-DSP voice is proved permanently unused in every required state, that voice can be reserved.

If all eight voices are genuinely needed, do **not** sacrifice a soundtrack channel. In that case the clean design is:

- retain the existing physical voice-7 cue implementation unchanged for original Top Gear mode;
- in sequel-music modes, move accessibility cues to a deterministic project-owned accessibility overlay bus outside the eight authentic music voices;
- generate that cue from the existing exact BRR assets/parameters with a small deterministic decoder/state machine, not from a captured WAV;
- mix the cue after the authentic music bus so it remains full-strength and independent of the music-volume percentage.

This should be prototyped and listening-tested before being promoted. A temporary physical-voice preemption scheme is less attractive because it can cut off real notes and change the imported soundtrack.

### Phase 8 — Snapshot/state architecture

Extend snapshots so they explicitly serialize:

- selected music engine;
- selected song/track;
- active sequel S-SMP AOT state/epoch;
- complete ARAM and knownness state required by the driver;
- S-SMP timers/ports;
- S-DSP state and phase;
- per-engine music-voice mask and music gain;
- accessibility-cue state/overlay state if used;
- any command-transition state.

Snapshot restoration must resume PCM deterministically without silently reverting to original Top Gear audio.

### Phase 9 — Integration into Top Gear gameplay

Only after both sequel audio laboratories are sealed:

1. link the music-engine API to existing semantic Top Gear song-change points;
2. leave race/gameplay logic unchanged;
3. do not alter Rally or Time Trial semantics merely to trigger music;
4. map soundtrack choices to title/menu/pre-race/race/results transitions through the game's real semantic commits;
5. retain the original Top Gear engine as a regression/reference mode.

The exact user-facing soundtrack-selection UI can then be decided separately without coupling it to the low-level audio implementation.

### Phase 10 — Qualification ladder

For each engine and each representative song/transition:

1. immutable ROM/asset hash gate;
2. upload-chain / ARAM-layout hash gate;
3. exact S-SMP generated-dispatch gate;
4. static-audio purity/authority gate;
5. DSP register and KON/KOFF trace comparison against Mesen;
6. native 32,040-Hz PCM/WAV comparison/fingerprint;
7. snapshot continuation test;
8. music-gain tests at 100%, 50% and 0%;
9. accessibility-cue isolation test;
10. title/menu transition test;
11. race transition/endurance test;
12. full current Definitive gameplay regression suite.

Listening evidence remains important. For each transplanted soundtrack family, produce proper WAV recordings long enough to hear the arrangement and transitions, not tiny samples.

## 11. Recommended implementation order

The safest order is:

1. **Keep the accepted `top gear audio.zip` altered static core locked as the sole production baseline; do not use Definitive.**
2. **Complete Top Gear 2 static audio discovery and build the standalone static playback laboratory.**
3. **Lower/integrate Top Gear 2.**
4. **Complete Top Gear 3000 discovery using DSP-4-enabled Mesen.**
5. **Lower/integrate Top Gear 3000 on the same sequel-driver infrastructure.**
6. **Generalize music voice ownership / accessibility cue coexistence.**
7. **Add the user-facing soundtrack selection only after all three engines are stable.**

This order minimizes simultaneous variables and uses Top Gear 2 to establish the common later-driver infrastructure before adding Top Gear 3000's extra source-game DSP-4 complication.

## 12. Success criteria

The transplant should not be called complete until all of the following are true:

- current Definitive Career/Rally/Time Trial work is preserved;
- original Top Gear accepted audio remains a regression mode and sounds unchanged;
- Top Gear 2 music is generated by its transplanted Full Static S-SMP authority and the project S-DSP, with no runtime emulator/interpreter;
- Top Gear 3000 music is generated the same way;
- Mesen is oracle-only;
- DSP-4 is not introduced into production unless an exact music dependency is actually proved;
- all required soundtrack voices remain intact;
- accessibility cues do not steal or mute sequel music channels;
- the 0-100% music gain works for all three engines while cues stay full-strength;
- snapshots restore the selected engine and continue audio deterministically;
- song/resource transitions match source-game oracle evidence;
- no S-SMP AOT failures, S-DSP failures, unknown PCM frames or fallback paths occur in qualified tests;
- user listening tests approve the final sound.

## 13. Current conclusion

This transplant is feasible with the existing Top Gear Full Static architecture.

The key is **not** to transplant whole emulators or blindly paste ARAM dumps. Top Gear 2 and Top Gear 3000 provide a closely related later SPC music-driver family whose immutable code/assets can be recovered from their ROMs, statically lowered into separate exact generated authorities, and run through Top Gear's already project-owned S-DSP. The current Top Gear music/cue mixer then needs to become engine-aware so the accepted volume and accessibility behavior survives without reducing either sequel soundtrack.

The next concrete work item should be Phase 0 followed immediately by the Top Gear 2 standalone static-audio laboratory.
