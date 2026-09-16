# Finish-line Start confirmation

Career Start, Rally Start and Time Trial Start request the approved Top Gear finish-line sound on the existing private ninth cue lane. Rally requests it immediately when Start opens Selected Tracks, not after that preview. Ordinary confirmations, including the Time Trial results actions, now use the separately imported Uncharted Waters: New Horizons accept cue.

Authority: the extracted audio master's TOP-GEAR-MODS-AUDIO-RESEARCH-HANDOFF-2026-09-06.md and TOP-GEAR-AUDIO-DETAILED-PROJECT-REPORT.md; menu entry points checked against the extracted Menu and Gameplay Editing Knowledge menu playbook and current core.

Exact source: ROM file offset 0x023D89, 3,240 BRR bytes, SHA256 b5889686e926413546df879942136f3bd3820641d3f30c229bb1ab41898421dd. Private cue RAM C760-D407, SRCN 12, pitch 0400, volume 7F/7F, ADSR FF/E0 and GAIN B8. This is native BRR synthesis, not WAV playback. The historical voice-7 prototype's playback contract is used on the current private ninth lane, preserving all eight music voices.

Start has priority over queued navigation sounds. Duplicate requests during the cue are ignored. Its non-looping BRR terminates naturally, detected through the private cue ENDX register with a one-second failure guard. The existing snapshot stores the cue RAM, DSP, state and clock deadlines. No new Data format or settings are needed.

Validation: the permanent topgear-finish-start headless harness boots the game, navigates to each of the three mode Start rows, selects each title music engine and holds activation for 90 frames. Each of the nine combinations starts exactly one cue and reaches natural completion while music is muted. All nine isolated recordings are byte-identical after trimming surrounding silence: 22,873 audible stereo frames at 32,040 Hz, 0.713889 seconds, peak 19,720 with no clipping; trimmed SHA256 11e481daa88f4c2abd2d212f87225b0f24c2dd56fd82e38ad528d4cd586638a5. The harness also compares whole-core snapshot replay during the sounding cue.

Related regression checks passed: ninth-channel isolation, mode/settings/results contracts, title/menu music controls and actual Career gameplay. Evidence is under Test-Receipts/Finish-Line-Start-2026-09-11.
