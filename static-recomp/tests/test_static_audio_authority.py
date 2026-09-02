#!/usr/bin/env python3
"""Quick release gate for Version 27 Full Static S-SMP/S-DSP authority.

This is intentionally a build/source authority test, not an audio quality oracle.
The audible title/gameplay routes are preserved separately as acceptance evidence.
"""
from __future__ import annotations
import hashlib,json,subprocess,sys,tempfile
from pathlib import Path

project=Path(sys.argv[1]).resolve() if len(sys.argv)>1 else Path(__file__).resolve().parents[1]
gen=project/'generated/audio/v27-static-smp'
route=gen/'TOPGEAR-V27-SMP-AOT-ROUTE.csv'
bitmap=gen/'TOPGEAR-V27-SMP-CODE-BITMAP.bin'
meta=json.loads((gen/'TOPGEAR-V27-SMP-AOT-GENERATION.json').read_text())
lookup=project/'static-recomp/static-audio/topgear-bapu-aot/smp/sc_smp_aot_lookup.inc'
dispatch=project/'static-recomp/static-audio/topgear-bapu-aot/smp/sc_smp_aot_dispatch.inc'
smp=project/'static-recomp/static-audio/topgear-bapu-aot/smp/smp.cpp'
core=project/'static-recomp/static-audio/topgear-bapu-aot/smp/core.cpp'
cmake=(project/'static-recomp/CMakeLists.txt').read_text()
backend=(project/'static-recomp/src/topgear_audio_backend.c').read_text()
runtime=(project/'static-recomp/src/topgear_runtime_api.c').read_text()

def sha(path:Path)->str:return hashlib.sha256(path.read_bytes()).hexdigest()

def check(cond,msg):
    if not cond: raise SystemExit('FAIL: '+msg)

check(meta.get('result')=='pass','generation metadata did not pass')
check(meta.get('unique_pcs')==1148 and meta.get('pc_opcode_contexts')==1148,'expected 1,148 exact S-SMP PCs')
check(meta.get('used_opcode_count')==115,'expected 115 used SPC700 opcode forms')
check(meta.get('generic_switch_in_static_mode') is False,'generic switch must be excluded in static mode')
check(meta.get('route_sha256')==sha(route),'route hash mismatch')
check(meta.get('code_bitmap_sha256')==sha(bitmap),'code bitmap hash mismatch')
check(meta.get('lookup_sha256')==sha(lookup),'lookup include hash mismatch')
check(meta.get('dispatch_sha256')==sha(dispatch),'dispatch include hash mismatch')
check('sc_aot_reset_metrics' in smp.read_text(),'S-SMP AOT metrics/authority support missing')
check('sc_aot_prepare' in core.read_text(),'AOT PC/opcode validation missing')
check('SC_SMP_AOT=1' in cmake or 'SC_SMP_AOT' in cmake,'production static-audio target does not define SC_SMP_AOT')
check('TOPGEAR_AUDIO_AOT_LEARNING' not in (project/'CMakeLists.txt').read_text()+cmake,'retired AOT learning build option remains')
check('TOPGEAR_ENABLE_HISTORICAL_HYBRID_AUDIO' not in (project/'CMakeLists.txt').read_text()+cmake,'retired hybrid build option remains')
check(not (project/'static-recomp/hybrid-audio').exists(),'retired hybrid implementation directory remains')
check('switch(opcode_number)' not in core.read_text().replace(' ',''),'generic runtime SPC700 opcode switch remains in core.cpp')
check('full-static-aot-smp-sdsp' in backend,'Full Static production backend name missing')
check('automatic_fallback_enabled=0u' in backend.replace(' ',''),'production status must report no automatic fallback')
check('return 1148u;' in runtime,'public generated S-SMP context count is stale')

# Re-emit the lookup/dispatcher from the frozen route and compare byte-for-byte.
with tempfile.TemporaryDirectory(prefix='topgear-v27-audio-audit-') as td:
    td=Path(td)
    l=td/'lookup.inc';d=td/'dispatch.inc';m=td/'metadata.json'
    cmd=[sys.executable,str(project/'tools/audio/generate_static_smp_aot_v27.py'),
         '--route',str(route),'--pseudo-dir',str(project/'static-recomp/static-audio/topgear-bapu-aot/smp/core'),
         '--lookup',str(l),'--dispatch',str(d),'--metadata',str(m),'--code-bitmap',str(bitmap)]
    subprocess.run(cmd,check=True,stdout=subprocess.DEVNULL)
    check(l.read_bytes()==lookup.read_bytes(),'regenerated S-SMP lookup differs')
    check(d.read_bytes()==dispatch.read_bytes(),'regenerated used-opcode dispatcher differs')
print('PASS: Version 27 Full Static audio authority: 1,148 exact S-SMP PCs, 115 opcode forms, generated dispatcher reproducible, no generic production switch/fallback.')
