#!/usr/bin/env python3
"""Fail if retired emulator DSP authority can enter the Top Gear source/build."""
from __future__ import annotations

import argparse
import pathlib
import subprocess
import sys


def fail(message: str) -> None:
    raise SystemExit(f"FAIL: {message}")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=pathlib.Path, required=True)
    parser.add_argument("--library", type=pathlib.Path)
    parser.add_argument("--dumpbin", type=pathlib.Path)
    args = parser.parse_args()
    root = args.root.resolve()
    retired = [
        root / "static-recomp/static-audio/topgear-bapu-aot/dsp/SPC_DSP.cpp",
        root / "static-recomp/static-audio/topgear-bapu-aot/dsp/SPC_DSP.h",
        root / "static-recomp/static-audio/topgear-bapu-aot/dsp/sc_static_sdsp_primitives.inc",
    ]
    present = [str(path.relative_to(root)) for path in retired if path.exists()]
    if present:
        fail("retired DSP source remains: " + ", ".join(present))

    cmake = (root / "static-recomp/CMakeLists.txt").read_text(encoding="utf-8")
    if "topgear-project-dsp/topgear_dsp.c" not in cmake:
        fail("project-owned DSP is absent from the production target")
    for banned in ("SPC_DSP.cpp", "SCStaticSPC_DSP_CUSTOM_RUN"):
        if banned in cmake:
            fail(f"retired build token remains: {banned}")

    if args.library and args.dumpbin and args.dumpbin.is_file():
        result = subprocess.run(
            [str(args.dumpbin), "/symbols", str(args.library)],
            check=True,
            capture_output=True,
            text=True,
            errors="replace",
        )
        symbols = result.stdout
        for banned in ("SCStaticSPC_DSP", "SPC_DSP"):
            if banned in symbols:
                fail(f"retired linked symbol remains: {banned}")
        if "topgear_dsp_step_phase" not in symbols:
            fail("project-owned DSP phase authority is absent from the library")

    print("PASS: project-owned Top Gear S-DSP is the only production DSP authority")
    return 0


if __name__ == "__main__":
    sys.exit(main())
