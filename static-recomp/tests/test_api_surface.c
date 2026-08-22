#include "topgear_static_recomp.h"

#include <string.h>

#ifdef TOPGEAR_RECOMP_V02_PACKET_SIZE
#error "Historical research constants leaked into the stable API"
#endif

int main(void) {
    TopGearRecompFrameResult frame;
    TopGearStaticAudioStatus audio;
    memset(&frame, 0, sizeof(frame));
    memset(&audio, 0, sizeof(audio));
    if (strcmp(topgear_recomp_version_string(), TOPGEAR_RECOMP_VERSION_STRING) != 0)
        return 1;
    if (topgear_recomp_sram_size() != 0u)
        return 2;
    return 0;
}
