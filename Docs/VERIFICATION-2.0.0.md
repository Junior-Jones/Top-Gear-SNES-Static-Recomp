# Version 2.0.0 revised Career verification

All tests are headless. User profile and timing files are isolated from automated test data.

## Results and scope

The 42-test regression run completed in 476.29 seconds. All 41 runtime/acceptance tests passed, including Career passwords, the new standings checkpoints, solo CPU audio, Rally, Time Trial/results navigation, profiles, saved playlists, imported music and private voice 9. The source-manifest test caught an out-of-date checksum while the final points-display test was still being edited. The manifests were regenerated after all edits and the integrity/menu checks rerun successfully. The original log is retained, including that resolved failure; it is not rewritten as an uninterrupted clean run.

The final three-digit Career points change was followed by focused headless points and tenth-finisher tests against the rebuilt code. These test the whole 0�255 formatter range in both generated dispatches, native accumulation from 140 to 160 points, the rendered standings screen, and the live-to-results transition at ten finishers. The broader run's password/navigation tests were completed before this isolated final formatting change.

The frontend Profile correction was tested with no running ROM. The hidden dialog starts with the PLAYER 1 clean-install name, writes both profile banks directly to Data/player-settings.dat, and preserves the unrelated bank. A newly created ROM instance then imports the file and exposes the saved Career/Rally and independent Time Trial setups. The separate Leaderboard test also opens with no ROM, reads Data/time-trial.dat, checks all filters, and leaves malformed data unchanged. The Welcome text contract checks Escape, 1, 2, then F1-F8 in that order.

## Career rules

Every track, all three skills, every finishing place and both player counts are checked: top ten for tracks 1�16 and top five for 17�32. Checkpoint tests cover seventh or better after track 8, sixth after 16, and fifth after 24. Both active humans must pass; a CPU cannot substitute. The tests check point retention at intermediate countries, reset at eight-race boundaries, and failed checkpoints withholding passwords and restarting before the failed boundary.

Native branch fixtures execute through the actual race and standings gates before rendering. Screenshots show seventh passing/eighth failing after 8, sixth passing/seventh failing after 16, and fifth passing/sixth failing after 24. Successful Amateur screens show REDLIGHT, LOWGEARS and DOWNHILL respectively; failures have no password. These are controlled RAM fixtures, not claims of naturally driving a complete championship.

All four passwords are also entered through the native controller-operated keyboard and start the correct course. Country lists, every highlight, invalid entry, cancellation, skill changes and starting-course isolation remain covered. Original passwords are rejected.

## CPU audio and screen inspection

The live solo Career probe observed one P1 engine startup and 466 P1 pitch updates, with zero P2 startups/updates. Native P2 voices 6 and 7 had zero envelope and output. The two-player comparison observed one startup and 465 updates for each player. Every NMI command/acknowledgement combination was checked across solo Career, two-player Career, Rally and Time Trial. The filter leaves P1 effects and the music/private-ninth-channel engines intact.

Main-menu inspection confirms no OPTIONS heading and DEFINITIVE EDITION restored to the small-font bottom position. The new three-digit points field fits inside the standings screen. Checkpoint and results captures wait through transitions rather than capturing a fade.

The tenth-finisher checks use controlled finisher counts: nine remains racing, ten enters the normal results transition. Natural completion of every track/car/gearbox combination is not claimed. Earlier natural repeated Time Trial runs remain historical evidence, not new runs in this revision.

## Release handoff

The executable remains version 2.0.0. Source, ZIP, test copy, Windows file/product version, archive integrity and hashes are checked. The release and GitHub test copies were reset by removing frontend settings, player profiles, music state and Time Trial records. Reference Data files remain. The portable ZIP contains no ROM or personal history; the test folder retains its existing ROM for user testing.
