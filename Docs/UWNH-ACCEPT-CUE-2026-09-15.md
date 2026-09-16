# Uncharted Waters: New Horizons menu confirmation

The supplied USA ROM was run in the Mesen headless oracle with zeroed startup RAM. Its New Game/Continue menu is stable at about 40 seconds after boot. Two otherwise identical runs were compared: one remained idle and one held A briefly on New Game. Only the A run produced the confirmation sequence described below.

The effect uses a 189-byte BRR sample at source-game ARAM $4490, with its loop point at $4529. The exact bytes occur once in the supplied copier-header ROM at file offset $13F1AA. Their SHA-256 is `4d598f5cbe897f1a894c6067548b2481d3dd5bb1407ce48d6cb48d452d63d6df`.

The cue plays for every letter that the name or password editor successfully commits, as well as final setup confirmations. Pressing A when the eight-character entry buffer is already full does not play it because no character is accepted.

The source game plays the sample on voice 5 with SRCN $03, ADSR $FF/$B4 and gain $9E. It forms a rising four-note pattern at pitches $1000, $1424, $17F4 and $2000. The pattern repeats four times over about 0.63 seconds while its stereo volume falls from $22/$21 to $04/$03, then reaches silence and keys off.

Top Gear installs the sample at private cue RAM $C100, directory entry $8A44 and SRCN $11. It reproduces the observed pitch, volume and timing sequence on the existing private ninth channel. Top Gear's eight music voices, DSP registers and shared audio RAM remain untouched.

The cue is requested only when A or Start commits an ordinary menu confirmation. It covers entry into Career, Rally, Time Trial and Settings; setup confirmations for player/name, skill, gearbox, controls and car; country, track and leaderboard selections; and Time Trial result actions. The Career, Rally and Time Trial Start rows retain the Top Gear finish-line cue. Directional movement retains the SimCity cue. Ignored directions and inactive menu items remain silent.

Evidence is retained in `Top Gear/Temp/UWNH-Accept-Cue-20260915`: the oracle script, idle and A-run logs, screenshots, extracted BRR and clocked DSP proof.
