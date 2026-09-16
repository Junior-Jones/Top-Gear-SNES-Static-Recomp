Top Gear Definitive Edition 2.0.0 - runtime Data
================================================
The Data directory beside Launcher.exe contains persistent game settings and
Time Trial history. Gameplay logic is compiled into the static core.

Data/time-trial.dat: TGTT v6, exactly 215,240 bytes
  32-byte header; 168-byte durable last run;
  32 tracks x 4 cars x 2 gearboxes x 5 records x 168 bytes.
Canonical records are Top 5 per track/car/gearbox. Combined per-car and Overall
views are derived, never separately persisted. Each record retains name, car,
gearbox, course, lap count, total ticks, independent best S1/S2/S3, and up to
8 laps with their own three sectors. Timing uses 60-Hz integer ticks and car
world position, including pits; display rounding never changes stored ticks.
Every valid completion updates last-run even when too slow for a Top 5.
Results wait for a successful flushed, atomic disk commit before advancing.
The shipped file is a valid empty TGTT v6 store, so a fresh installation does
not have to manufacture its leaderboard file on first use. Empty display rows
remain invalid storage slots and appear as 0:00:000 total, 00.0 sectors and
0:00:000 laps; they never rank as completed races.

Existing TGTT v5 (107,720 bytes) migrates its genuine records and last run into
the matching gearbox tables. The Windows loader first preserves the original
as time-trial.dat.v5-<process>-<clock>.bak before allowing a v6 rewrite. Records
that v5 already discarded cannot be reconstructed. Opening Leaderboard alone
without a game uses a read-only import and does not migrate the disk file.
Corrupt/truncated/unsupported files are rejected without overwriting them.
Prototype v1/v2 history lacks the needed metadata/sector meaning; existing
semantic-clear migration remains. No fabricated historical records are made.

Data/player-settings.dat: TGPS v5, 96 bytes
  16-byte header (magic/version/size and FNV-1a payload checksum).
  Three 26-byte profiles: Career/Rally P1, Career/Rally P2, separate TT P1.
  Each contains 16 native control/gear bytes, 8 name bytes and a car word.
  Byte 94 stores one/two-player choice. Byte 95 flags: KPH, music Mute,
  Career Music (Complete, Random or Classic). Older supported versions retain their profiles.
The shipped record gives Career/Rally P1 and TT P1 the name PLAYER 1 while
retaining the original Cannibal, Manual and Type A setup. The profiles remain
independent after either one is changed. Profile Save and stable game-menu edits use the same atomic durable writer.
Mid-race profile edits apply at the next mode menu; the other bank is unchanged.

Data/music-state.dat: TGMS v1, 96 bytes
  Separate Career and Time Trial shuffle bags, Rally event list, cursors,
  previous song, PRNG and Complete position. Eleven gameplay songs only:
  TG 4, TG2 3, TG3000 4. No title/results/qualifying tracks in racing bags.
  Career Random and TT exhaust their bags; Rally chooses eight distinct songs.
  Music Player browsing never consumes these playlists. Background saves,
  shutdown flush and Reset/reopen preserve them.
Music stays at 5/10 outside the title (10/10). Mute affects music only.
The independent ninth effect channel and engine resources are compiled.

Data/track-catalog.json is reference/harness data for the 32 native tracks.
It does not execute code or replace ROM course data.

Continues, active event progress and seeded password standings are in-memory
run state, included in build-compatible full-machine snapshots, not a new
persistent save-game format. A new Career attempt starts with three continues. Rally has none.
Keep Data when updating. Automated tests use separate fixture directories.
The ROM belongs in Rom; snapshots/screenshots/diagnostic exports retain their
separate folders. Launcher settings.ini currently remains beside the EXE.
