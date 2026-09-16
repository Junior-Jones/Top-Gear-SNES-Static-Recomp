"""Independently audit physical matrix Data files and write a readable report."""
import argparse
import hashlib
import json
from pathlib import Path
import struct


def audit(receipt):
    folder = Path(receipt["evidence"])
    blob = (folder / "Data/time-trial.dat").read_bytes()
    assert len(blob) in (107720, 215240), "TGTT size"
    header = struct.unpack_from("<4sHH6I", blob)
    assert header[:7] in ((b"TGTT", 5, 168, 32, 4, 5, 32), (b"TGTT", 6, 168, 32, 4, 10, 32)), "TGTT header"
    assert len(blob) == (215240 if header[1] == 6 else 107720), "version/size"
    run = blob[32:200]
    car, gear, course, required, completed, flags = run[8:14]
    assert (course, car, gear) == (receipt["track"], receipt["car"],
                                  int(receipt["gearbox"] == "manual")), "identity"
    assert 1 <= required == completed <= 8 and flags & 3 == 3, "complete laps"
    total, *best = struct.unpack_from("<4I", run, 16)
    arrays = [struct.unpack_from("<8I", run, offset) for offset in (32, 64, 96, 128)]
    laps, *sectors = arrays
    assert total == sum(laps[:required]), "total"
    for lap in range(required):
        assert all(s[lap] > 0 for s in sectors), "missing sector"
        assert laps[lap] == sum(s[lap] for s in sectors), "lap sector sum"
    assert best == [min(s[:required]) for s in sectors], "independent fastest sectors"
    assert all(not any(a[required:]) for a in arrays), "unused lap slots"
    table = 200 + ((course * 4 + car) * 2 + gear) * 5 * 168 if header[1] == 6 else 200 + (course * 4 + car) * 5 * 168
    assert any(blob[table + rank*168:table + (rank+1)*168] == run
               for rank in range(5)), "canonical track/car table"
    settings = (folder / "Data/player-settings.dat").read_bytes()
    assert len(settings) == 96 and settings[:4] == b"TGPS", "TGPS size/magic"
    version, size, checksum = struct.unpack_from("<3I", settings, 4)
    assert version in (2, 3, 4, 5) and size == 96, "TGPS version"
    actual = 2166136261
    for value in settings[16:]:
        actual = ((actual ^ value) * 16777619) & 0xffffffff
    assert actual == checksum, "TGPS checksum"
    assert struct.unpack_from("<H", settings, 92)[0] == car, "TT profile car"
    assert settings[84:92] == b"A       " and settings[95] & 1 == 1, "TT name/default KPH"
    assert bool(settings[72] | settings[73] | settings[74] | settings[75]) == bool(receipt["gearbox"] == "manual"), "TT profile gearbox"
    assert (folder / "track-results.ppm").exists() or any(folder.glob("track-results-run-*.ppm")), "detail screenshot"
    assert (folder / "top-5-results.ppm").exists(), "Overall screenshot"
    return dict(laps=required, ticks=total, best=best,
                data_sha256=hashlib.sha256(blob).hexdigest())


def stamp(ticks):
    milliseconds = (ticks * 1000 + 30) // 60
    return f"{milliseconds//60000}:{milliseconds//1000%60:02d}.{milliseconds%1000:03d}"


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("matrix", type=Path)
    parser.add_argument("report", type=Path)
    parser.add_argument("--partial", action="store_true")
    parser.add_argument("--replacement-matrix", type=Path, action="append", default=[],
                        help="replace matching scenarios with a later targeted rerun")
    args = parser.parse_args()
    catalog = json.loads((Path(__file__).resolve().parents[1] / "Data/track-catalog.json").read_text())
    selected = {}
    for matrix in [args.matrix] + args.replacement_matrix:
        for path in sorted(matrix.glob("*/receipt.json")):
            receipt = json.loads(path.read_text())
            selected[(receipt["track"], receipt["car"], receipt["gearbox"])] = receipt
    receipts = list(selected.values())
    failures = []
    for receipt in receipts:
        try:
            assert receipt["status"] == "PASS", receipt["status"]
            receipt["audit"] = audit(receipt)
        except (AssertionError, OSError, ValueError, struct.error) as error:
            failures.append(f"Track {receipt['track']}, car {receipt['car']}, {receipt['gearbox']}: {error}")
    covered = {r["track"] for r in receipts if "audit" in r}
    pairs = {(r["car"], r["gearbox"]) for r in receipts if "audit" in r and r["track"] == 0}
    complete = covered == set(range(32)) and len(pairs) == 8 and not failures
    lines = ["# Physical timing-data audit", "",
             f"Audited {sum('audit' in r for r in receipts)} completed scenarios; {len(covered)}/32 tracks and {len(pairs)}/8 car/gearbox pairs on Las Vegas.", "",
             "This audit reads the actual files independently of the C store implementation. It checks record ownership, total/lap/sector sums, each independent sector minimum, canonical table placement, profile checksum/name/car/KPH, and both results screenshots.", "",
             "| Track | Laps | Car | Gearbox | Time | Best S1 / S2 / S3 (seconds) |",
             "|---|---:|---|---|---|---|"]
    cars = ["Cannibal", "Sidewinder", "Razor", "Weasel"]
    for row in catalog:
        matches = [r for r in receipts if r["track"] == row["id"] and "audit" in r]
        if not matches:
            lines.append(f"| {row['name']} | {row['laps']} | — | — | Pending or failed | — |")
            continue
        for r in matches:
            a = r["audit"]
            assert a["laps"] == row["laps"], "catalogue lap count"
            best = " / ".join(f"{t/60:.3f}" for t in a["best"])
            lines.append(f"| {row['name']} | {a['laps']} | {cars[r['car']]} | {r['gearbox']} | {stamp(a['ticks'])} | {best} |")
    lines += ["", "Status: " + ("PASS — full requested coverage." if complete else "INCOMPLETE — see coverage and failures."), ""]
    lines += failures
    args.report.write_text("\n".join(lines), encoding="utf-8")
    args.report.with_suffix(".json").write_text(json.dumps(receipts, indent=2))
    print(lines[2])
    for failure in failures:
        print(failure)
    return int(bool(failures) or (not complete and not args.partial))


if __name__ == "__main__":
    raise SystemExit(main())
