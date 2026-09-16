"""Run controller-driven journeys; retain isolated evidence and failures.

Default: every track plus every car/gearbox on Las Vegas (39 scenarios).
--full: all 256 track/car/gearbox combinations. No gameplay RAM writes.
"""
import argparse
import concurrent.futures
import csv
import json
from pathlib import Path
import subprocess
import time


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("executable", type=Path)
    p.add_argument("rom", type=Path)
    p.add_argument("output", type=Path)
    p.add_argument("--full", action="store_true")
    p.add_argument("--jobs", type=int, default=4)
    p.add_argument("--timeout", type=int, default=3600)
    p.add_argument("--catalog", type=Path,
                   default=Path(__file__).resolve().parents[1] / "Data/track-catalog.json")
    p.add_argument("--resume-from", type=Path,
                   help="reuse naturally reached race-start snapshots from an earlier matrix")
    p.add_argument("--tracks", type=int, nargs="+", choices=range(32),
                   help="rerun only the selected track IDs")
    args = p.parse_args()
    catalog = json.loads(args.catalog.read_text())
    rom = args.rom.read_bytes()
    if len(catalog) != 32 or [t["id"] for t in catalog] != list(range(32)):
        p.error("catalogue must contain track IDs 0 through 31 exactly once")
    for track in catalog:
        offset = int(track["rom_lap_offset"], 16)
        if int.from_bytes(rom[offset:offset+2], "little") != track["laps"]:
            p.error(f"ROM lap count disagrees with catalogue for {track['name']}")
    args.output.mkdir(parents=True, exist_ok=True)
    scenarios = [(t, c, g) for t in range(32) for c in range(4)
                 for g in ("auto", "manual")] if args.full else sorted(
        {(t, t % 4, "manual" if (t // 4) % 2 else "auto") for t in range(32)} |
        {(0, c, g) for c in range(4) for g in ("auto", "manual")})
    if args.tracks:
        scenarios = [case for case in scenarios if case[0] in args.tracks]

    def run(case):
        track, car, gear = case
        folder = args.output / f"track-{track:02d}-car-{car}-{gear}"
        # A receipt is reusable only for the exact executable and ROM hashes.
        import hashlib
        signature = [hashlib.sha256(f.read_bytes()).hexdigest()
                     for f in (args.executable, args.rom)]
        snapshot = (args.resume_from / folder.name / "race-start.snap") if args.resume_from else None
        if snapshot and snapshot.exists():
            signature.append(hashlib.sha256(snapshot.read_bytes()).hexdigest())
        else:
            snapshot = None
        receipt = folder / "receipt.json"
        if receipt.exists():
            old = json.loads(receipt.read_text())
            if old.get("signature") == signature and old.get("status") == "PASS":
                return old
        folder.mkdir(exist_ok=True)
        start = time.monotonic()
        command = [str(args.executable.resolve()), str(args.rom.resolve()),
                   folder.resolve().as_posix(),
                   (folder / "Data/time-trial.dat").resolve().as_posix(),
                   str(track), str(car), gear]
        if snapshot:
            command.append(str(snapshot.resolve()))
        with (folder / "run.log").open("w") as log:
            try:
                code = subprocess.run(command, stdout=log, stderr=subprocess.STDOUT,
                                      timeout=args.timeout).returncode
                status = "PASS" if code == 0 else "FAIL"
            except subprocess.TimeoutExpired:
                code, status = -1, "TIMEOUT"
        result = dict(track=track, car=car, gearbox=gear, status=status,
                      exit_code=code, seconds=round(time.monotonic()-start, 1),
                      signature=signature, evidence=str(folder.resolve()))
        result["natural_start_snapshot"] = str(snapshot.resolve()) if snapshot else None
        receipt.write_text(json.dumps(result, indent=2))
        return result

    results = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=max(1, args.jobs)) as pool:
        for result in pool.map(run, scenarios):
            results.append(result)
            print(f"{len(results)}/{len(scenarios)} {result['track']:02d} "
                  f"car {result['car']} {result['gearbox']} {result['status']}", flush=True)
            (args.output / "summary.json").write_text(json.dumps(results, indent=2))
    with (args.output / "summary.csv").open("w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=[k for k in results[0] if k != "signature"])
        writer.writeheader()
        writer.writerows({k: v for k, v in r.items() if k != "signature"} for r in results)
    return int(any(r["status"] != "PASS" for r in results))


if __name__ == "__main__":
    raise SystemExit(main())
