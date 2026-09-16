# Menu music locked at level 5

The user chose five reductions from level 10: level 5, or 50% linear music gain. The core applies 50% whenever menu context is active, or zero if menu music Mute is On. This also enforces the chosen gain when loading a previous calibration snapshot. Main Options entry sets the diagnostic level to 5; live gameplay returns to level 10 and 100% gain. Navigation effects remain outside the music gain.

Removed the Select input interceptor and the two calibration display lines. Select no longer changes music volume. Settings retains Speed, Mute: On/Off, and Back. Mute persistence and Data format are unchanged.

Validation harness: Temp/Title-Check-2026-09-11/volume-locked.c checks initial level 5, repeated and held Select staying at 5, music-only mute with audible navigation, settings round-trip and full-volume restoration. The former calibration harness is retained separately as historical evidence.

Visual check: held Left revealed the stock Options rows while Mute was On. Inline Mute edits now wait for release without the stock selector redraw, and the Settings-owned text is restored before both full-frame and scanline rendering. Captured highlighted On/Off states after settling; pixel comparison confirms that only the Mute row changes, with heading and other rows identical. Screenshot receipts are mute-on-verified-final.png and mute-off-verified-final.png.
