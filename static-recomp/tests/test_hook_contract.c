#include "topgear_internal.h"

#include <stdlib.h>

typedef struct HookState {
    TopGearRecomp *core;
    unsigned calls;
    int nested;
} HookState;

static int hook_callback(void *opaque, const TopGearHookEvent *event) {
    HookState *state = (HookState *)opaque;
    if (!event || event->type != TOPGEAR_HOOK_EVENT_INSTRUCTION_BEFORE ||
        event->address != 0x008000u || event->instruction_boundary_exact == 0u)
        return 1;
    state->calls++;
    if (!state->nested) {
        state->nested = 1;
        tg_emit_hook(state->core, TOPGEAR_HOOK_EVENT_INSTRUCTION_BEFORE,
                     0x008000u, 0u, 1u);
    }
    return state->calls == 1u ? 0 : 1;
}

int main(void) {
    TopGearRecomp *core = (TopGearRecomp *)calloc(1u, sizeof(*core));
    HookState state;
    if (!core) return 1;
    state.core = core; state.calls = 0u; state.nested = 0;
    if (!topgear_recomp_set_hook(core, TOPGEAR_HOOK_MASK_INSTRUCTION,
                                 hook_callback, &state)) return 2;
    tg_emit_hook(core, TOPGEAR_HOOK_EVENT_INSTRUCTION_BEFORE, 0x008000u, 0u, 1u);
    if (state.calls != 1u || core->hook_stop_requested) return 3;
    topgear_recomp_request_stop(core);
    if (!core->hook_stop_requested) return 4;
    topgear_recomp_clear_hook(core);
    if (core->hook_callback || core->hook_mask || core->hook_stop_requested) return 5;
    free(core);
    return 0;
}
