# Career 2.0.0

This supersedes the earlier Career/password and main-heading notes. The native skill names remain Amateur, Professional and Championship; easy/normal/hard refer to those three settings respectively.

## Qualification and race termination

The original race gate scans the first five finishing IDs at $1F12; the original country gate checks the top three standings positions every four races. Version 2 replaces these with two distinct requirements, identical across all three skills:

- Races 1–16: finish in the top ten. Races 17–32: finish in the top five.
- After race 8: seventh or better in the standings. After race 16: sixth or better. After race 24: fifth or better.

Standings accumulate points across each eight-race section. The intermediate four-race country presentation remains but no longer clears points or imposes a standings gate. The checkpoint uses the native displayed order at $1F62, including its stable ordering of equal points. Every active human must meet both applicable requirements; the CPU cannot substitute for P1. At a passed checkpoint, the twenty point bytes at $1F4E reset for the next section. Eight victories total 160, within the native byte range. Career standings use a three-digit points field (for example, 160 PTS), replacing the native two-digit formatter at 0F:8B7B also used in Rally. A password seed can add up to 40, giving a safe maximum of 200. A failed checkpoint awards no password and ends the attempt without a continue. Race 32 retains the normal ending after its top-five race requirement.

The generated hook now runs at 0F:8750, before the native four-race points reset. Both generated dispatch trees call the same Career helper and rejoin at 0F:877A so the temporarily incremented human count is restored on pass and failure. The race gate remains armed only by the points-award path, preserving initial-start behavior.

At 00:8780/8783, the native engine compares the finisher count $1EB0 with ten. Nine follows the racing path; ten enters the finish path. Unfinished player states are closed and the normal native post-finish/results delay remains. Time Trial retains its explicit solo exemption. The new qualification cutoff does not change this finishing-count threshold.

## Passwords

| Skill | Award after track | Country / next track | Code |
|---|---:|---|---|
| Amateur | 8 | Japan / 9 | REDLIGHT |
| Amateur | 16 | Scandinavia / 17 | LOWGEARS |
| Amateur | 24 | Italy / 25 | DOWNHILL |
| Professional | 16 | Scandinavia / 17 | ROADKILL |
| Championship | None | Beginning only | None |

The country-progress hook retains the continuation screen and resets scores at eight-race boundaries. At 0F:85F2, the password stage writes only an allowed eight-character code to the native text buffer and rejoins its renderer at 0F:8626; otherwise it skips to 0F:863B. A points-award reset and one-shot award marker prevent stale codes on failure or a later results screen. Completing track 32 still uses the native ending.

The original password text was placed at tile row 28, below the visible 224-pixel framebuffer. The label and code now use tile row 1 in the clear top margin. This leaves the existing congratulations/country message intact. The Career timing panel also draws missing-time hyphens in white instead of borrowing a blue native font tile.

Country is remodel page 14. Its two-line heading names the current skill and Difficulty. It lists only the permitted password countries; Amateur and Professional also offer Start Over and Back. Championship shows No Passwords and Back. Each selectable row uses the normal bounded selector geometry. Invalid input reports Incorrect Password without switching skill or changing the selected start.

Selecting a country launches the original eight-character keyboard. The custom 0F:93DC return validates against the chosen country and current skill, avoiding the original validator's attempt to search all three skill tables. B cancels password entry without an error or profile change. The original 21 passwords are rejected. No new codes are written into the user's ROM.

The selected Career start is separate from the live race-course RAM. It is revalidated after a skill change and on Start, preventing Rally/Time Trial or old menu state from leaking a disallowed course into Career. Start Over resets it to track 1. Failed tracks offer one of three continues to retry the same course with pre-race points restored. Declining or exhausting the budget returns to the main menu. This state is not a new disk save-game format; reset/new launch starts from the beginning until a password is entered.

## Main heading and version

The root has no OPTIONS heading. DEFINITIVE EDITION is restored to the original small-font bottom position (column 7, row 24). Career, Rally, Time Trial and Settings stay in place.

Version 2.0.0 is set in CMake, Windows executable version resources, About text, source/release readmes and the rewritten cumulative VERSION.txt. Data file schemas remain TGPS v4, TGMS v1 and TGTT v6; product version must not be confused with data schema versions. Build-owned snapshots from older executables may be rejected.

## Verification approach

The headless Career test checks all 32 course cutoffs, all skills, every finishing place and one/two-player configurations; rejects every old password across countries/skills; types the four valid codes through the native keyboard; walks every new country-menu highlight; checks wrong-entry/cancel paths; and captures qualification screens using explicitly controlled boundary fixtures. Boundary fixtures are distinguished from natural driving. The wider existing suite covers Time Trial, Rally, Profile persistence, private voice 9, music and static-core integrity.

The cumulative VERSION.txt is the user-facing change list. The separate 2.0.0 verification receipt records completed tests and any limitations.

## Solo Career CPU audio

The native startup at 00:81B3 previously started the second engine with command $0D even in one-player Career. NMI 00:B959 continued sending $0E pitch updates and the other P2 events. Every solo mode now publishes neutral at startup and for P2 commands $0D–$16 at the NMI commit. The accumulator is updated before the native $3D acknowledgement mirror, preventing a wait for an unsent command. Events are still consumed normally; CPU racing physics is unchanged. P1 commands, real two-player effects, imported music engines and private voice 9 are not altered by this filter.

The headless audio test observes only the real startup/NMI command sites (not song-upload bytes), checks live 1P/2P startup and pitch updates, verifies zero envelope/output on native P2 voices 6/7 in solo Career, and checks every command/acknowledgement for Career 1P/2P, Rally and Time Trial.

## Current extension

See LEADERBOARD-CONTINUES-2.0.0.md for password-seeded standings, continues, solo Rally telemetry and the frontend Leaderboard. These changes supersede historical failure-return and TGTT v5 descriptions.
