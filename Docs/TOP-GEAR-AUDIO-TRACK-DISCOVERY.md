# Top Gear music-selector discovery and Linux recorder

## Result

Top Gear has seven proved APUIO0 music selectors, `$01-$07`. The human-facing soundtrack names used by the Linux recorder are:

| Selector | Name | ARAM sequence descriptor | Channel-pointer block |
|---|---|---:|---:|
| `$01` | Title | `$13AB` | `$13E3` |
| `$02` | Frankfurt | `$13B3` | `$13F3` |
| `$03` | Bordeaux | `$13BB` | `$1403` |
| `$04` | Hiroshima | `$13C3` | `$1413` |
| `$05` | Las Vegas | `$13CB` | `$1423` |
| `$06` | Qualified | `$13D3` | `$1433` |
| `$07` | Ending Theme | `$13DB` | `$1443` |

The names are frontend labels based on the preserved Top Gear SPC soundtrack set. The static core continues to treat selector numbers, ROM/ARAM bytes and addresses as authority.

## Race selector proof

The generated S-CPU routine at `$00:817C-$00:81A0` reads WRAM `$1F06`, keeps the low two bits, XORs them with 3, then adds 2. Therefore the four race selector values are `$05,$04,$03,$02` for low-bit values `0,1,2,3`.

The successful Linux four-race USA snapshots provide direct runtime confirmation:

| Race | WRAM `$1F06` | Live `scpu_to_smp[0]` | Selector |
|---|---:|---:|---:|
| Las Vegas | `$0000` | `$05` | `$05` |
| Los Angeles | `$0001` | `$04` | `$04` |
| New York | `$0002` | `$03` | `$03` |
| San Francisco | `$0003` | `$02` | `$02` |

The 32-track course table is arranged as eight regions of four races. The soundtrack labels Las Vegas, Hiroshima, Bordeaux and Frankfurt occur in modulo-4 positions 0,1,2,3 respectively, giving the exact race-theme name mapping `$05=Las Vegas`, `$04=Hiroshima`, `$03=Bordeaux`, `$02=Frankfurt`.

## Non-race selector proof

Cold boot reaches `$00:8075` with accumulator `$01` and writes it to APUIO0 at `$00:8077`, proving `$01` is the opening/title selector.

The common music-change routine at `$0F:8133-$0F:8159` performs the command-`$18` driver handshake, clears APUIO0, increments the caller's value, and writes the resulting selector. The qualification path at `$0F:858A` supplies `$05`, producing `$06`; nearby ROM text is `CONGRATULATIONS / YOU QUALIFIED FOR THE NEXT / COUNTRY`. The completion path at `$0F:8560` supplies `$06`, producing `$07`; its nearby text includes `CONGRATULATIONS / ON COMPLETING TOP GEAR`. These identify `$06=Qualified` and `$07=Ending Theme`.

On the S-SMP side, `$0A17-$0A24` doubles APUIO0 and resolves the sequence-pointer table at ARAM `$1397`. Selectors `$01-$07` resolve to descriptors `$13AB,$13B3,$13BB,$13C3,$13CB,$13D3,$13DB`.

## Critical uploader correction (2026-09-04)

A selector byte is **not** sufficient to start a complete song.  The S-CPU passes
`selector-1` to `$07:8000` before it writes APUIO0.  `$07:8000` doubles that
value, indexes the seven-word offset table at `$07:8164`, and walks a
song-specific four-byte resource chain based at `$07:8172`.  The chains end in
`$FFFF,$0800` and install the per-song BRR/sample/instrument material whose live
state is concentrated in ARAM `$8900-$FFFF`.

The seven chain offsets are `$0000,$0028,$0088,$00E8,$0148,$01A8,$01BC`.
They contain respectively 9, 23, 23, 23, 23, 4 and 8 data/resource entries
before their terminators.  This explains why the earlier recorder appeared to
work only for Title: it always allowed cold boot to call `$07:8000` with A=0
(the Title chain), then changed only the final APUIO0 selector.  Selectors
`$02-$07` therefore ran their sequence logic against the wrong resident
sample/instrument resources.

The corrected `topgear_recomp_music_preview_prepare` now breaks immediately
before cold-boot `$00:8064 JSL $07:8000`, supplies `selector-1`, lets the exact
ROM uploader complete, then breaks before `$00:8077` and supplies the final
selector.  A ROM regression hashes ARAM `$8900-$FFFF` after preparation and
requires seven distinct expected states.

The saved four-race campaign independently validates the corrected uploader.
For selector `$05` (Las Vegas), the corrected preview and live Race 1 APU state
match across 65,403 of 65,536 ARAM bytes, including the complete high resource
region.  Selector `$04` matches the live Race 2 state for every byte from
`$8900-$FFFF`.  The later race snapshots retain the same common driver region
`$0400-$38FF` and most song-resource bytes; remaining high-ARAM differences are
accumulated later-race/SFX state rather than the initial music upload.

See `Docs/generated/TOPGEAR-AUDIO-UPLOAD-CHAINS.csv` for the exact resource-chain
entries and `static-recomp/tests/test_music_upload_chains.c` for the regression.

## Linux recorder

`frontend/headless/topgear_music_recorder.c` adds a ROM-driven static-core recorder. It never uses downloaded soundtrack audio. It executes the game's exact two-stage reset/upload protocol with `topgear_recomp_music_preview_prepare`—first the selector-specific `$07:8000` resource chain, then the final APUIO0 selector—advances only the isolated Full Static S-SMP/S-DSP clock, drains the deterministic PCM FIFO, and writes 32,040 Hz stereo signed 16-bit WAV.

Commands:

    topgear-music-recorder ROM --list
    topgear-music-recorder ROM --record SELECTOR SECONDS OUTPUT.wav
    topgear-music-recorder ROM --record-all OUTPUT_DIRECTORY

The seven full-length recordings were generated with zero S-SMP AOT failures and zero static DSP failures. A 30-second Title recording was also generated from both unoptimized and optimized audio-object builds and the WAV SHA-256 matched exactly, verifying that the recording acceleration did not change PCM output.

See `Docs/generated/TOPGEAR-AUDIO-MUSIC-SELECTOR-TRACE.csv` for the concise evidence log.
