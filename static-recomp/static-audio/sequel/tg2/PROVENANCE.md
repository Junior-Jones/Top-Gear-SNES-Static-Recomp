# Top Gear static S-SMP/S-DSP AOT provenance

The S-SMP lane uses the fail-closed AOT transformation pattern proven by the
earlier SimCity and Top Gear research. Its mature SPC700 semantics retain their
Snes9x provenance, but production contains no generic runtime opcode switch.
Each fetched opcode is validation-only; the frozen Top Gear exact-PC authority
in `smp/sc_smp_aot_lookup.inc` selects one of the finite generated instruction
forms in `smp/sc_smp_aot_dispatch.inc`.

The authority is generated offline from Top Gear's exact ROM-derived APU upload
and development-oracle PC/opcode coverage. Unknown PCs, opcode mismatches,
unemitted opcodes, and writes to statically owned driver code fail closed. There
is no automatic fallback. The governing route, code bitmap, generator and
metadata are included under `generated/audio/v27-static-smp` and reproduce the
1,148 exact PCs, 115 used forms and 2,261 protected code bytes.

S-DSP authority is the Top Gear-owned fixed hardware model under
`static-audio/topgear-project-dsp`. It implements the 32 hardware phases,
register visibility, BRR decode, Gaussian interpolation, envelopes, noise,
pitch modulation, echo/FIR, native 32,040 Hz PCM, explicit ARAM/register/PCM
knownness, overflow accounting and deterministic PCM hashing. The former
`SPC_DSP.cpp` emulator-derived owner and its helper files are not present or
linked. DSP state and knownness are serialized explicitly for deterministic
PCM continuation after snapshot load.
