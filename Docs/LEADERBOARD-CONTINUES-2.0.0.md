# Leaderboard, password standings and continues — 2.0.0

The menu bar has File and Settings. The toolbar remains a row of standard Windows text buttons, all 30 pixels high: Browse 92 wide, Play/Pause 72, Reset 66, Audio 66, Profile 72, Leaderboard 104, Settings 82, Controls 62. Full Screen and Auto-Run checkboxes follow. Minimum outer width is 940 pixels; status is below and the game starts at client y=80. Leaderboard fits without abbreviation and is also in Settings.

Leaderboard is an 850×500 resizable native window (minimum 850×440). Track selects one of 32 country/city labels. Car and gearbox include All choices. A native ListView shows five rows: Place, Name, Car, Gearbox, Total, Sector 1, Sector 2, Sector 3. Each sector is the independent fastest split across the recorded run's laps. Empty records say No record and use 0:00:000 total plus 00.0 sector placeholders. The in-game Top 5 uses the same zero placeholders; absent lap fields use 0:00:000 and 00.0. These rows remain invalid storage slots and cannot rank ahead of a real run. Tab traverses three selectors, table and centered Close; Escape closes. The game pauses while the window is open and restores its previous play state.

Live reads use the host timing store; without a ROM, the window imports Data/time-trial.dat read-only. The release supplies a valid empty TGTT v6 file instead of creating one only after the first run. Corrupt data produces a notice and remains unchanged. TGTT v6 keeps five records for every track/car/gearbox. The v5 importer retains genuine records and the durable last run; the Windows game loader first backs up the original file to a unique .bak before permitting a rewrite. Older discarded records cannot be recovered. Overall/per-car views are derived. Profiles and music retain separate Data files and formats. Launcher settings.ini remains beside the executable; snapshots and exports retain their established directories.

## Password standings

The four difficulty/country passwords retain their restrictions. Success opens CURRENT STANDINGS instead of returning to Career setup. P1 is fifth with 32 points. Rival identities shuffle, but scores remain close and strictly descending (40 down to 1), with at most one point of jitter. No arbitrary large gap or fifth-place tie is introduced. In two-player mode P2 is sixth; both humans still have to qualify. Blank human names display PLAYER 1/2. After release, any fresh button proceeds to the permitted track's native pre-race screen. Seed points survive initialization and participate in the normal eight-race section. Seed plus eight wins is at most 200, within the native byte. Both generated dispatches and Rally use the 0–255 points formatter.

## Continues

Career starts each new attempt with three continues. Rally has no continues. TT keeps unrestricted Retry. At race initialization the core saves the twenty pre-race point values. On track failure, native video/NMI initialization completes before branching to the original failure presentation; this avoids a frame-clock deadlock. The driver artwork remains, with CONTINUES and Yes/No below it. Failure bypasses result points.

Left selects Yes, Right selects No, A/Start confirms, and B declines. Held input cannot accept on entry. No timeout chooses for the user. Yes spends exactly one, restores pre-race points and starts the same course. This retry budget applies only to Career. At zero, Yes is grey and only No can be selected. No returns to root with the relevant mode highlighted. Three uses permit four attempts at a repeatedly failed track. Successful tracks do not reset the budget.

Career track cutoffs remain top 10 on tracks 1–16 and top 5 on 17–32. Rally tracks 1-7 require top 8/7/6/5/4/3/2. Track 8 has no placement gate: its points are added and the final eight-race standings determine the winner. Rally failure is terminal and never shows the continue choices. Both active humans must pass. Career standings gates after 8/16/24 require top 7/6/5; failure ends the attempt without offering or spending a continue.

## Solo display and sound

Career and Rally share the lower Top 5 checkpoint-gap panel in solo play; CPU opponents still race. Missing timing evidence displays dashes. TT retains its lower timing panel and excludes rival graphics/collisions. All solo modes publish neutral for P2 commands 0D–16 at startup/NMI, including the acknowledgement mirror. Real two-player effects remain. P1 effects, eight-voice music engines and the independent ninth effect channel are preserved.

## Headless verification

The hidden native Leaderboard test checks 480 filter combinations, all five rows, totals/sectors, tab order, Close alignment, corrupt/read-only files and toolbar geometry/text width at minimum size. Native print captures verify table/toolbar geometry. Closed combo selection text is not reliably painted while the parent is hidden; selected values and labels are additionally checked through native control messages.

The continue harness navigates actual menus/race transitions and injects finishing order at the race boundary: it does not claim natural driving completions. Career is retried three times, checking course/event index, points rollback, zero budget and early No. It also executes standings failure without continues. A RAM matrix covers every Career track and Rally event ordinal, all finishing places, one/two humans and held-button release. The Career test types all four passwords, checks P1 fifth and seed points surviving pre-race, and uses R as the any-button action for ROADKILL. Live audio probes cover Career 1P/2P, Rally 1P and TT 1P plus all NMI command/acknowledgement cases. Wider existing tests cover TT Retry/persistence, profiles, music, voice 9 and core integrity. See accompanying logs for completed results.

The current Rally rules and dedicated eight-race verification are documented in RALLY-FINAL-STANDINGS-2.0.0.md; earlier Rally-continue receipts describe a superseded version.
