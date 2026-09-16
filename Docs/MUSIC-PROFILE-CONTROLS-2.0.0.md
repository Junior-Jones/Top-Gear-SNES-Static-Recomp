# Music, Profile and controls update

Career Music now has Complete (0), Random (1) and Classic (2). Complete and Random use only the 11 race songs. Classic selects the original four-song course mapping, verified against native $00:817x and $00:8197-$81A0; it does not consume either playlist. Rally and Time Trial retain their independent random choices. Voice 9 is unchanged.

TGPS version 5 keeps the 96-byte format, with byte 95 bits 2-3 holding the music mode. Versions 1-4 remain readable; the old Classic Random value migrates to Random. TGMS remains version 1 and stores the saved random bags and Complete position in Data/music-state.dat. Invalid modes fail validation.

Fresh Career/Rally and Time Trial profiles use PLAYER 1 with the original Cannibal, Manual and Type A setup. Profile opens before the ROM starts and Save writes the selected setup directly to Data/player-settings.dat. The static core imports it when the ROM loads. The Profile test creates both profiles without a running ROM, reloads the disk record, starts the ROM and checks Career/Rally plus the independent Time Trial bank in native RAM.

Gamepad support was present but its assignment rows were hidden when Keyboard was selected. The selector now says Input device, with Gamepad (USB / Bluetooth). Launcher now passes its bundled gamecontrollerdb.txt to SDL instead of NULL. A hidden Controls test checks the selector and all assignment rows without requiring a physical controller. Physical-controller compatibility is not established by that UI test.

The requested release reset removes settings.ini, legacy settings files and saved Data records from installed/test copies after the app is closed. Reference Data files remain. Launcher may create fresh default settings files when opened; this does not restore the old profiles or scores. Password values are omitted from the player-facing version notes; gameplay passwords remain implemented.
