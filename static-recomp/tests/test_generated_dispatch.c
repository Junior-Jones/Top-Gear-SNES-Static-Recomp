#include "topgear_internal.h"

#include <stdlib.h>

int main(void) {
    TopGearRecomp *core = (TopGearRecomp *)calloc(1u, sizeof(*core));
    int result;
    if (!core) return 1;
    if (tg_v22_generated_static_context_count() == 0u ||
        tg_v22_generated_static_address_count() == 0u)
        return 2;
    core->cpu.pbr = 0x7fu;
    core->cpu.pc = 0u;
    core->cpu.e = 1u;
    core->cpu.p = TG_P_M | TG_P_X;
    result = tg_v22_generated_static_step(core);
    if (result != 0 || !core->failed || !core->frontier.reached)
        return 3;
    free(core);
    return 0;
}
