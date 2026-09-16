# In-game menu music controls

Update: the user selected level 5 (50%) after five Select presses. Menu music is now fixed at 50%, Select debug handling and its on-screen instructions are removed. Gameplay still restores unity. The following records the earlier calibration implementation and tests.

Settings now contains Speed, Mute: On/Off, Back. Left/Right or A toggles Mute with native release handling. Mute affects title/menu music only; the independent ninth-voice SimCity navigation effect stays audible. Live gameplay audio resumes at unity, preserving native engine/effect audio.

Select is a temporary music-level debug control throughout the menu session, including the native name, gearbox, control and car editors. Each rising edge subtracts one from 10 down to 0, saturating at 0. Held Select never repeats. The event is consumed before native menu input. Settings displays MENU MUSIC n OF 10 and SELECT LOWERS MUSIC. The current installed keyboard binding for Select is T. No automatic reduction level is selected yet: the user is testing levels.

Menu context starts at the original Options entry and survives submenus and pre-race transitions. Live-race HDMA enable of channels 0-6 ($420C = $7F) clears that context and resets level to 10, observed through the common bus so copied-WRAM and ROM execution agree. The natural Time Trial test reached this at frame 5542 after preserving level 6 through four native editors and the pre-race page. Generated opcode hooks were investigated but not retained because the live copied-WRAM race route did not reach them.

Music gain uses the existing project DSP dry+echo music gain, outside the ninth cue lane. The frontend volume and timing remain unchanged. Mute is stored in the existing 96-byte Data/player-settings.dat with version 3, using bit 1 of byte 95 alongside speed bit 0; checksum covers it. Version 1/2 records remain readable and import with Mute Off. Debug level is session-only, included in build-owned core snapshots but not saved as a player preference. Background durable settings writes remain in use.

Validation: natural menu harness checks held Select changes once, floor at 0, held Mute toggles once, silent music intervals, audible cue while muted and at level 0, persisted mute, and full audio on gameplay restoration. Natural route checks Select across name/gearbox/controls/car and screenshots at pre-race/live race. Eight selected regression tests passed, including mode settings, ninth DSP voice, snapshots, player summaries, static authority/purity and the complete 55-cue menu route. The version test also exercises v1/v2 migration and v3 mute round-trip.

Harness sources, logs, and screenshots remain in the private development archive outside this repository. Tests used isolated temporary outputs and never wrote user Data. Earlier failed race-trigger probes are superseded by the common-bus hook result.
