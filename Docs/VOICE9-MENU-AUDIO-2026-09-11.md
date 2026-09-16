# Voice 9 and SimCity directional menu cues

Scope: an independent ninth synthesis capability and the accepted SimCity
navigation effect in Definitive's menus. Soundtrack selection, sequel music
integration, confirmation/Start Race cues and a volume slider are separate work.

## References reread

- Top-Gear-Audio-Master/00-CODEX-MASTER-PROMPT-HANDOFF.md, the detailed audio
  report, original accepted cue implementation, revised Part 5 direction and
  the ten-phase transplant plan.
- Top Gear Menu and Gameplay Editing Knowledge/Guides: menu ownership,
  generated hooks, canonical data, and snapshot/controller testing.
- The accepted audio source was extracted into a separate Voice9-Lab folder.
  The frozen references were not edited or copied over current gameplay files.

The newer handoff says to preserve all eight music voices and provide an extra
project-owned synthesis lane. The older physical voice-7 preemption scheme is
therefore not used. The latest user instruction explicitly limits this stage
to making menu effects work; no sequel music selector has been added.

## Core implementation

The eight hardware-facing music register banks remain unchanged. When the cue
lane is attached, music register voice 7 uses internal voice state slot 8.
All original phase scheduling, PMON/NON/EON, KON/KOFF, ENDX and echo behavior
continue to use their original hardware bit positions. State migration copies
the complete voice and can occur at any of the 32 DSP phases.

The menu effect has a private single-voice DSP context using register lane 7.
Only that voice's BRR, Gaussian interpolation, envelope and key primitives run;
the context does not execute eight additional voices. It shares the main DSP's
sample clock and counter at attachment. Music and cue contributions meet inside
the project DSP before the public PCM FIFO, not in a frontend WAV player.

The reusable DSP state container has unused slots in the cue context. This is
a storage choice, not extra sounding channels. There are eight music synthesis
voices plus one cue synthesis voice. Cue sample/directory RAM is private, so
installing it cannot overwrite a music engine's sample or echo memory.

The complete music dry bus and audible echo return have a Q15 gain; its default
is unity. The cue stays outside this gain. Feedback remains unscaled. This
internal capability does not add a user-facing volume control in this stage.

## Exact SimCity resource

- Command 06, original voice 7, 54-byte BRR.
- SHA-256: acc24c77261f84da0f6704959ec38981b03befa8dba4b1a43f70a30b4e34c928.
- Private cue ARAM C000-C035, loop C01B, directory 8A40, SRCN 10.
- Volume 3C/3C, pitch 17BB, ADSR FE/F5, gain 70, echo disabled.
- Timed KOFF after 720,828 master clocks; release cleanup after another 435,336.
- Navigation events are serialized; an event during playback queues another
  cue rather than interrupting the current sound. The queue is bounded at 255.
- BRR and parameters are compiled into the static core, not supplied as a WAV
  or executed from Data. Existing Data/settings/timing ownership is unchanged.

## Accepted movement hooks

Remodeled pages emit events only when selection changes. The same applies to
the horizontal Overall results buttons and the Speed value. No event is emitted
for an ignored direction or a single-item page that cannot change selection.

Native generated commit points, applied to normal and reentry code:

| Address | Accepted action |
| --- | --- |
| 0F:924C | Career/Rally player count |
| 0F:930A | Career Country selector |
| 0F:9500 | Name/password grid movement |
| 0F:96A1, 0F:9744 | Native three-row selectors |
| 0F:986C | Gearbox selection |
| 0F:995F | Normalized Control Method selection |
| 0F:9A7B | Car grid selection |

Control Method increments/decrements RAM before its normalized store; comparing
RAM against A at 995F incorrectly suppresses ordinary moves. That store is
itself the accepted directional boundary. The old OPTIONS selector hook is
suppressed while the remodel owns input, preventing double cues and sounds on
page-entry redraws.

Speed's former HANDLED path immediately repolled a held button. A and Left/Right
now return through the native selector/wait-for-release path, accepting one
change per press. The regression checks assert that return path as well as the
actual speed value; a natural 90-frame held press checks real behavior.

## State and tests

The APU snapshot identity is TGAPU009. It contains the main and cue DSP states,
private cue RAM/knownness, routing and gain. Live pointers are cleared when saved
and rebound when loaded. Reset clears the cue context. Older build-specific
debug snapshots are rejected; player-settings.dat and time-trial.dat formats
are unchanged.

- topgear-voice9: all activation phases, key and modulation masks, independent
  music/cue state, exact cue PCM versus native voice-7 playback, gain isolation,
  and deterministic playing-state continuation.
- topgear-menu-insert-audio: eight actual root movements and exactly eight
  complete cues, private sample hash, original title resource preservation.
- topgear-menu-voice9-route: natural cold-boot controller route, all four
  directions, held input, unchanged selections, screen captures and WAV.
  It saves/reloads the whole core during a cue and compares continuation PCM.
- Existing gameplay, Data, static purity/authority and audio route checks remain
  separate gates. A stale unit expectation for Speed's former HANDLED return
  was updated to require the corrected release path; no data assertion was removed.

Run the route executable with ROM and an existing output directory, or run its
CTest entry. Outputs include events.csv, settled directional screenshots,
playing-cue.snap and Menu-Voice9-Full-Route.wav. The route doesn't persist its
test profiles or results into the user's Data folder.

Voice9-Lab-2026-09-11 contains the independent experiment receipts. A sequel
baseline comparison was completed before the user narrowed the active scope;
that is supplementary research only, not a production soundtrack integration.
Listening quality is for the user to assess from the generated WAV and app.
