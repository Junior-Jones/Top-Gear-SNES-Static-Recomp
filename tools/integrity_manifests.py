#!/usr/bin/env python3
"""Write or verify deterministic Top Gear source/evidence integrity manifests."""

from __future__ import annotations

import argparse
import hashlib
import json
import sys
from pathlib import Path


OUTPUTS = {
    "SOURCE-MANIFEST.json",
    "GENERATED-PROVENANCE.json",
    "SHA256SUMS.txt",
}
IGNORED_PARTS = {".git", "__pycache__", "build", "Build"}
GENERATED_ROOTS = (
    "static-recomp/generated/",
    "static-recomp/static-audio/topgear-bapu-aot/",
)
CHECKSUM_TARGETS = (
    "SOURCE-MANIFEST.json",
    "GENERATED-PROVENANCE.json",
    "CMakeLists.txt",
    "static-recomp/CMakeLists.txt",
    "static-recomp/include/topgear_static_recomp.h",
    "static-recomp/include/topgear_static_recomp_diagnostics.h",
    "tools/integrity_manifests.py",
)


def digest(path: Path) -> str:
    value = hashlib.sha256()
    with path.open("rb") as source:
        for block in iter(lambda: source.read(1024 * 1024), b""):
            value.update(block)
    return value.hexdigest()


def source_files(root: Path) -> list[Path]:
    result: list[Path] = []
    for path in root.rglob("*"):
        if not path.is_file():
            continue
        relative = path.relative_to(root)
        if relative.as_posix() in OUTPUTS:
            continue
        if any(part in IGNORED_PARTS for part in relative.parts):
            continue
        if path.suffix.lower() in {".pyc", ".pyo", ".obj", ".lib", ".exe", ".pdb"}:
            continue
        result.append(path)
    return sorted(result, key=lambda item: item.relative_to(root).as_posix())


def entries(root: Path, paths: list[Path]) -> list[dict[str, object]]:
    return [
        {
            "path": path.relative_to(root).as_posix(),
            "bytes": path.stat().st_size,
            "sha256": digest(path),
        }
        for path in paths
    ]


def inventory_hash(items: list[dict[str, object]]) -> str:
    value = hashlib.sha256()
    for item in items:
        value.update(str(item["path"]).encode("utf-8"))
        value.update(b"\0")
        value.update(str(item["sha256"]).encode("ascii"))
        value.update(b"\n")
    return value.hexdigest()


def build_source_manifest(root: Path) -> dict[str, object]:
    items = entries(root, source_files(root))
    return {
        "schema": "topgear-source-manifest-v1",
        "project_version": "1.2.0",
        "file_count": len(items),
        "inventory_sha256": inventory_hash(items),
        "files": items,
    }


def build_generated_manifest(root: Path) -> dict[str, object]:
    paths = [
        path
        for path in source_files(root)
        if path.relative_to(root).as_posix().startswith(GENERATED_ROOTS)
    ]
    items = entries(root, paths)
    for item in items:
        path = str(item["path"])
        item["authority"] = (
            "generated-scpu-or-reentry"
            if path.startswith("static-recomp/generated/")
            else "static-smp-sdsp-aot"
        )
    return {
        "schema": "topgear-generated-provenance-v1",
        "project_version": "1.2.0",
        "rom_sha256": "ca9889f17f184b3d99a2eaaa82af73e366f03ed00313fdd369e5e023b208e788",
        "authority_roots": list(GENERATED_ROOTS),
        "policy": (
            "The release contains pinned generated authority, not its historical "
            "research generator. Changes require offline ROM/ARAM provenance, "
            "reviewed regenerated output, updated receipts and a new manifest."
        ),
        "file_count": len(items),
        "inventory_sha256": inventory_hash(items),
        "files": items,
    }


def encoded_json(value: dict[str, object]) -> str:
    return json.dumps(value, indent=2, sort_keys=True) + "\n"


def checksum_text(root: Path) -> str:
    return "".join(f"{digest(root / name)}  {name}\n" for name in CHECKSUM_TARGETS)


def write(root: Path) -> None:
    (root / "SOURCE-MANIFEST.json").write_text(
        encoded_json(build_source_manifest(root)), encoding="utf-8", newline="\n"
    )
    (root / "GENERATED-PROVENANCE.json").write_text(
        encoded_json(build_generated_manifest(root)), encoding="utf-8", newline="\n"
    )
    (root / "SHA256SUMS.txt").write_text(
        checksum_text(root), encoding="ascii", newline="\n"
    )


def check(root: Path) -> bool:
    expected = {
        "SOURCE-MANIFEST.json": encoded_json(build_source_manifest(root)),
        "GENERATED-PROVENANCE.json": encoded_json(build_generated_manifest(root)),
    }
    errors: list[str] = []
    for name, text in expected.items():
        path = root / name
        if not path.is_file():
            errors.append(f"missing {name}")
        elif path.read_text(encoding="utf-8") != text:
            errors.append(f"stale or modified {name}")
    sums = root / "SHA256SUMS.txt"
    if not sums.is_file():
        errors.append("missing SHA256SUMS.txt")
    elif sums.read_text(encoding="ascii") != checksum_text(root):
        errors.append("stale or modified SHA256SUMS.txt")
    if errors:
        for error in errors:
            print(f"FAIL: {error}", file=sys.stderr)
        return False
    print(
        "PASS: source inventory, generated/static-audio provenance and "
        "published checksums reproduce exactly"
    )
    return True


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument("--write", action="store_true")
    args = parser.parse_args()
    root = args.root.resolve()
    if args.write:
        write(root)
        print(f"Wrote integrity manifests under {root}")
        return 0
    return 0 if check(root) else 1


if __name__ == "__main__":
    raise SystemExit(main())
