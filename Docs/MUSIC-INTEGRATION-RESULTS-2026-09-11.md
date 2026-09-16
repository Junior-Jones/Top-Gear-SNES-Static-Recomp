# Music integration — 11 September 2026

The random-selection and Rally/Time Trial music behavior described below is superseded by MUSIC-SHUFFLE-STATE-2026-09-11.md; the engine/audio qualification remains applicable.

The current Definitive Windows core now contains isolated, fail-closed TG2 and TG3000 AOT music engines. They use the qualified ROM-derived driver seed and real transfer transactions. No recorded audio, generic SPC interpreter, Mesen or DSP-4 is used at runtime. Startup builds in-memory ready states from those transactions so switching does not stall audio for uploads.

All eight authentic voices remain available in each imported engine. The existing independent SimCity ninth cue lane, BRR bytes, envelope, pitch and timing are unchanged. Music volume applies to the selected music engine's dry and echo output; echo feedback stays unscaled. The original TG APU continues receiving game commands. Its native P1/P2 engine and effect voices remain audible when imported Career music is selected.

R cycles TG, TG2, TG3000 title music throughout the title and menu routes, once per released press. It is consumed before the original game can treat it as Start. L retains its existing behavior. Gameplay keeps its original R input. TG's resident title continues in the background when another title is selected; selecting an imported title starts its prepared beginning.

Settings now contains Speed, Mute, Career Music, Back. Career Music displays Complete or Classic Random below its highlighted label and changes once per Left/Right press. It is saved asynchronously in Data/player-settings.dat, TGPS version 4, 96 bytes. Versions 1–3 remain readable. Byte 95 bits: 0 KPH, 1 menu music mute, 2 Classic Random. Existing player profiles and Time Trial history are preserved.

Complete advances one gameplay song per Career race: TG Las Vegas, Hiroshima, Bordeaux, Frankfurt; TG2 Auckland, Ayers Rock, Canterbury Plains; TG3000 Main Themes 1–4; then loops. Title, qualified, results and ending tracks are excluded. Classic Random selects among the four original TG gameplay songs using a separate core RNG. Rally and Time Trial retain native race music. Menu music remains level 5/10, Select calibration is disabled, and gameplay restores full volume.

Whole-core snapshots include both imported APUs/DSPs, master and service clocks, unread PCM queues, selection, playlist/RNG state and the existing cue state. Runtime-generated startup caches are not external capture authority.

Verification:
- All 13 sequel tracks: 20-second PCM byte-identical to approved laboratory references after integration with the current DSP.
- All 13: playing snapshot replay, mute, half volume and cached restart checks passed.
- All 11 Complete playlist entries reached actual Career gameplay with the expected engine/selector; final entry wrapped to index 0.
- Title R stayed on Press Start; held R switched once; every engine passed music mute with audible independent ninth cue and whole-core snapshot continuation.
- Both Career Music Settings states were inspected from delayed screenshots and fit the highlight/frame.
- Existing 32-test regression suite passed, including ninth-voice phase/echo/modulation tests, original music uploads, native racing effects, menu routes, Rally, Time Trial and 180-second audio.
- Windows DirectSound check: 47 menu cues and title-engine switching, zero underruns and zero queue recoveries across 2,500 paced frames. Switching frames took 4.821–5.116 ms; the maximum 31.490 ms frame occurred during output startup.

The permanent headless targets are topgear-sequel-runtime, topgear-music-menu and topgear-music-career. Detailed evidence is retained in Test-Receipts/Music-Integration-2026-09-11 and the Temp/Music-Integration-2026-09-11 laboratory.
