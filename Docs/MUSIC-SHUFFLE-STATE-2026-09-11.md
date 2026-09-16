# Persistent gameplay music playlists

This replaces the earlier four-song random picker. The Career Music choice remains in Data/player-settings.dat. Separate Data/music-state.dat stores the remaining songs, positions, last song and PRNG states, plus the Complete sequence position. The static core owns selection and playback; the frontend loads the record before boot and saves changes asynchronously, including changes during gameplay. Closing waits for pending writes and writes the latest state; Reset preserves the record. Corrupt records are rejected rather than overwritten.

The shared gameplay pool contains exactly 11 songs:
0 TG Las Vegas; 1 TG Hiroshima; 2 TG Bordeaux; 3 TG Frankfurt;
4 TG2 Auckland; 5 TG2 Ayers Rock; 6 TG2 Canterbury Plains;
7 TG3000 Main Theme 1; 8 Main Theme 2; 9 Main Theme 3; 10 Main Theme 4.
No title, qualified, results or ending tracks belong to this pool.

Career Classic Random shuffles all 11, draws without replacement, then reshuffles. The first song after reshuffling cannot equal the previous last song. Complete retains its ordered 11-song cycle. Time Trial uses its own persistent 11-song shuffled list; results Retry and starting a different course each consume a new song at the actual native race-music upload boundary. Each new Rally creates a shuffled eight-song event playlist from the same pool. Rally's race index selects its corresponding song, so the eight races cannot repeat a song. The three modes have independent history. The original game course RNG is untouched.

Native TG songs replace both the upload resource index and final music selector. Imported choices map only to the three TG2 gameplay packages or four TG3000 gameplay packages. All eight music voices and the independent ninth sound-effect lane retain their current implementations. Sequel title selection is suppressed on Time Trial results pages and during qualifying/gameplay; title cycling remains available on title/setup menus.

TGMS version 1 is 96 bytes: a 16-byte magic/version/size/checksum header, Complete position at byte 16, and three 18-byte records at offset 20. Each record contains an 11-song permutation, cursor, previous song (255 means none), one reserved byte and a 32-bit PRNG state. Remaining bytes are reserved and zero. Checksum is FNV-1a-32 over bytes 16-95. Validation rejects duplicate/out-of-range songs, invalid cursors, zero PRNG states, wrong size/version and checksum corruption. Initial entropy is supplied by the Windows host when the file is missing; subsequent states are deterministic and saved.

Targeted validation passed: 2,200 Career/Time Trial draws across 100 complete cycles per mode; 100 eight-song Rally events; durable file round trips and invalid-record checks; asynchronous non-menu saves, close during save, new app load and Reset continuation. Controller-driven Start routes passed for all three modes. A synthetic completed-results fixture preserved the first Time Trial run's music history and verified actual Retry and new-course Start music uploads consumed distinct subsequent songs. This fixture is not evidence of a naturally driven finish.

Final regression: all 38 CTest tests passed, including original audio routes through 180 seconds, finish-line cues in all modes/engines, title controls, snapshots, Rally, Time Trial and integrity checks.
