#include "topgear_internal.h"

#include <stdlib.h>

int main(void) {
    TopGearRecomp *core = (TopGearRecomp *)calloc(1u, sizeof(*core));
    int16_t first[2];
    unsigned index;
    if (!core) return 1;
    for (index = 0u; index < TOPGEAR_RECOMP_AUDIO_FIFO_FRAMES + 3u; ++index)
        tg_audio_push_frame(core, (int16_t)index, (int16_t)(0u - index));
    if (!topgear_recomp_audio_overflowed(core)) return 2;
    if (topgear_recomp_audio_available(core) != TOPGEAR_RECOMP_AUDIO_FIFO_FRAMES)
        return 3;
    if (topgear_recomp_audio_read(core, first, 1u) != 1u ||
        first[0] != 3 || first[1] != -3)
        return 4;
    if (topgear_recomp_audio_discard(core, 8u) != 8u) return 5;
    topgear_recomp_audio_clear(core);
    if (topgear_recomp_audio_available(core) != 0u) return 6;
    topgear_recomp_audio_clear_overflow(core);
    if (topgear_recomp_audio_overflowed(core)) return 7;
    free(core);
    return 0;
}
