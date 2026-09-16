# Menu sound/music interruption investigation

Reproduced 47 player-count changes using the real Windows DirectSound backend, normal frame pacing, full rendering, and settings loaded from the installed settings.ini. The harness uses its own settings file under Temp and a hidden test window. No user Data is used for writes.

Before: synchronous durable settings writes blocked the game/audio thread. Maximum measured live frame 166.712 ms; 10 underruns and 2 queue recoveries.
After: immutable exported settings records are written on a background worker. Same route: maximum measured live frame 11.175 ms; 0 underruns, 0 recoveries; 47 cues. This reproduces and resolves one concrete cause of the reported static/music skips; it is not a claim that every device or load condition is covered.

Core-only comparison: 41 left/right changes, cue enabled versus disabled, identical sample counts (2,240,134 stereo frames). Exactly 41 difference windows, each about 55.26 ms, corresponding to the cues. Music samples outside those windows match exactly; no int16 clipping (peak 24,507). Existing voice9 test verifies music registers, voice state, echo memory, all 32 DSP phases and cue equivalence to the original voice-7 synthesis primitives. No ninth-voice synthesis change was needed.

Implementation: the Windows app exports a record on the game thread; one worker owns only its immutable bytes and path. Additional edits coalesce while that write completes. The cache advances only after a successful durable atomic replacement. Failures are reported on polling and retried on later frames. App destruction waits for the worker and synchronously flushes the latest edit, preserving close-during-save behavior. The common synchronous save API still has its original semantics and delegates to the extracted byte writer. Data formats and paths are unchanged.

Verification: pending close saves newest record, reload, asynchronous write failure and successful retry passed. Seven selected CTests passed: time-trial store, audio resampler, mode settings/results, DSP phase, voice9, static-audio purity and authority. Production launcher compiles with existing /W4 /WX checks.

Reproduction sources, WAV comparisons, CSV timing/audio diagnostics, and original source backups remain in the private development archive outside this repository. The valid playback evidence used `live-playing-before.csv` and `live-playing-after.csv`; preliminary captures that did not resume the audio device were excluded.
