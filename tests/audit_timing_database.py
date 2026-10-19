"""Independently check physical TGTT-v6 timing records and preserved banks."""
import argparse
import hashlib
import json
from pathlib import Path
import struct


def audit(path):
    blob = Path(path).read_bytes()
    assert len(blob) == 215240, "file size"
    assert struct.unpack_from("<4sHH6I", blob)[:7] == (b"TGTT", 6, 168, 32, 4, 10, 32), "header"
    found = []

    def decode(run):
        car, gear, track, required, completed, flags = run[8:14]
        assert flags & 3 == 3 and required == completed and 1 <= required <= 8, "complete run"
        assert car < 4 and gear < 2 and track < 32, "ownership"
        assert all(v == 32 or 48 <= v <= 57 or 65 <= v <= 90 for v in run[:8]), "name"
        total, *best = struct.unpack_from("<4I", run, 16)
        laps, *sectors = [struct.unpack_from("<8I", run, off) for off in (32, 64, 96, 128)]
        assert total > 0 and total == sum(laps[:required]), "total/lap sum"
        for n in range(required):
            assert all(s[n] > 0 for s in sectors) and laps[n] == sum(s[n] for s in sectors), "sector sum"
        assert best == [min(s[:required]) for s in sectors], "sector minima"
        assert all(not any(a[required:]) for a in [laps] + sectors), "unused laps"
        return dict(track=track, car=car, gearbox=gear, laps=required, ticks=total,
                    best=best, sequence=struct.unpack_from("<I", run, 160)[0])

    last = decode(blob[32:200])
    for t in range(32):
        for c in range(4):
            for g in range(2):
                previous = None
                empty_seen = False
                for rank in range(5):
                    off = 200 + (((t * 4 + c) * 2 + g) * 5 + rank) * 168
                    run = blob[off:off + 168]
                    if not run[13] & 1:
                        assert not any(run), "nonzero empty slot"
                        empty_seen = True
                        continue
                    assert not empty_seen, "rank gap"
                    item = decode(run)
                    assert (item["track"], item["car"], item["gearbox"]) == (t, c, g), "wrong bank"
                    key = item["ticks"], sum(item["best"]), item["sequence"]
                    assert previous is None or previous <= key, "rank order"
                    previous = key
                    item["rank"] = rank + 1
                    found.append(item)
    return blob, dict(record_count=len(found), last_run=last, records=found,
                     sha256=hashlib.sha256(blob).hexdigest())


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("file", type=Path)
    parser.add_argument("--before", type=Path)
    parser.add_argument("--changed-track", type=int)
    parser.add_argument("--report", type=Path)
    args = parser.parse_args()
    blob, result = audit(args.file)
    if args.before:
        assert args.changed_track is not None and 0 <= args.changed_track < 32
        before, old = audit(args.before)
        bank_size = 4 * 2 * 5 * 168
        for t in range(32):
            if t != args.changed_track:
                off = 200 + t * bank_size
                assert before[off:off + bank_size] == blob[off:off + bank_size], "another track changed"
        result["other_31_tracks_byte_identical"] = True
        result["before_record_count"] = old["record_count"]
    result["status"] = "PASS"
    if args.report:
        args.report.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print("PASS physical database:", result["record_count"], "ranked records; all totals/laps/sectors/owners/ranks valid;",
          "other 31 tracks unchanged" if args.before else "all 1280 slots checked")


if __name__ == "__main__":
    main()
