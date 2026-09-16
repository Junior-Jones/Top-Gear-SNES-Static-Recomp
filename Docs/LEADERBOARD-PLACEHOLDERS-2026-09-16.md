# Time Trial leaderboard placeholders and Data streaming

The release now includes a valid, empty 215,240-byte TGTT v6 `Data/time-trial.dat`. Empty slots retain a clear valid flag and therefore never participate in ranking. Both the in-game Top 5 and the frontend Leaderboard present those slots as `No record`, `0:00:000` total and `00.0` for each sector. An unavailable lap field uses `0:00:000` and `00.0` in the detailed results renderer. Genuine stored times retain their existing precision and ordering.

The frontend now formats sectors as tenths (`00.0`) rather than as complete race times. Its live-game and read-only paths use the same TGTT store and filtering code. Sector conversion uses a widened intermediate so a large valid tick value cannot overflow during display conversion.

End-to-end verification used a copy of the shipped empty file. A schema-aware direct byte edit installed a valid `EDITED` Las Vegas/Cannibal/Automatic run at wire offset 200 with a 1,830-tick total. The game loaded and displayed it. Four controller-driven natural races then completed: two Las Vegas runs through Retry and two Los Angeles/Sidewinder/Manual runs through Retry. Each run produced a delayed full-results screenshot and a delayed Top 5 screenshot. Every completion was atomically written and re-imported before the UI advanced.

An independent decoder checked the final physical file without calling the C store. It found exactly five valid records: the edited run, two Las Vegas runs and two Los Angeles runs. For every record, each lap equalled S1 + S2 + S3, the run total equalled the lap sum, and each saved best sector equalled the independent minimum for that sector. The hidden native frontend then imported this exact file and captured both track tables; displayed order, totals and sectors matched the decoder and in-game screenshots. Empty filters retained five placeholder rows.

Focused checks passed for the TGTT store, Time Trial routes, mode/settings/results contracts, in-game results rendering, hidden frontend Leaderboard, source integrity, and both natural two-run journeys. Test data and screenshots are verification artifacts only; the shipped file remains empty.
