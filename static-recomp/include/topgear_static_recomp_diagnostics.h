#ifndef TOPGEAR_STATIC_RECOMP_DIAGNOSTICS_H
#define TOPGEAR_STATIC_RECOMP_DIAGNOSTICS_H

/*
 * Opt-in historical research and certification API.
 *
 * Include this header instead of topgear_static_recomp.h when a research tool
 * needs milestone-specific V02-V27 receipts or low-level semantic entry points.
 * Desktop frontends and third-party integrations should include only the stable
 * public header. Research declarations may change independently of the stable
 * lifecycle/frame/input/audio/snapshot/hook/status contract.
 */
#define TOPGEAR_ENABLE_RESEARCH_API 1
#include "topgear_static_recomp.h"
#undef TOPGEAR_ENABLE_RESEARCH_API

#endif
