# Time Trial controller harness

Build the Release target topgear-time-trial-journey. Supply the USA ROM with SHA-256 ca9889f17f184b3d99a2eaaa82af73e366f03ed00313fdd369e5e023b208e788.

One cold journey:

    topgear-time-trial-journey.exe ROM OUTPUT_DIRECTORY OUTPUT_DIRECTORY/Data/time-trial.dat TRACK_ID CAR_ID auto|manual

Optionally append a naturally reached race-start or completed-run snapshot. Track IDs and laps are in ../Data/track-catalog.json. Car IDs: 0 Cannibal, 1 Sidewinder, 2 Razor, 3 Weasel. The driver selects name A and native Type A controls, then operates accelerator, steering, nitro and actual manual shifts.

All-track coverage plus all car/gearbox pairs:

    python run_time_trial_matrix.py EXE ROM OUTPUT_DIRECTORY --jobs 4

All 256 combinations:

    python run_time_trial_matrix.py EXE ROM OUTPUT_DIRECTORY --full --jobs 4

Resume from prior natural race-start evidence:

    python run_time_trial_matrix.py EXE ROM OUTPUT_DIRECTORY --resume-from PRIOR_MATRIX_DIRECTORY --jobs 4

Each case has isolated Data, run.log, journey.csv, settled PPM screenshots, snapshots, a result report and receipt.json. Matrix summary.json/csv report every outcome. A cached PASS is reused only when all input hashes match. Failed/incomplete journeys return nonzero and do not fabricate saved times. See ../Docs/TRACK-HARNESS-AND-CORE-REPAIRS-2026-09-10.md for the native RAM authorities and fixes.

Independent physical-file audit and readable report:

    python audit_time_trial_matrix.py MATRIX_DIRECTORY REPORT.md

Use --partial only while a matrix is still running. The final audit requires all 32 tracks and all eight Las Vegas car/gearbox pairs to pass. It decodes TGTT/TGPS bytes independently of the C store and checks exact lap sums and independent sector minima.

Targeted rerun example: add --tracks 22 to rerun Bordeaux only. Keep prior evidence, then include a later targeted matrix in the audit with --replacement-matrix NEW_MATRIX_DIRECTORY. The audit keeps each selected scenario's actual executable/ROM/snapshot hashes.
