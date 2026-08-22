#include "topgear_static_recomp_diagnostics.h"

#ifndef TOPGEAR_RECOMP_V02_PACKET_SIZE
#error "Diagnostics header did not expose historical research declarations"
#endif

int main(void) {
    if (topgear_recomp_generated_context_count() == 0u)
        return 1;
    if (topgear_recomp_generated_smp_context_count() == 0u)
        return 2;
    return 0;
}
