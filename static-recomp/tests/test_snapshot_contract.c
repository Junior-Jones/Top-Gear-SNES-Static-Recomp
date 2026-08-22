#include "topgear_internal.h"
#include "topgear_snapshot_format.h"

#include <stdlib.h>
#include <string.h>

int main(void) {
    TopGearRecomp *core = (TopGearRecomp *)calloc(1u, sizeof(*core));
    TopGearSnapshotHeader header;
    char error[192];
    if (!core) return 1;
    memset(&header, 0, sizeof(header));
    memcpy(header.magic, TOPGEAR_SNAPSHOT_MAGIC, TOPGEAR_SNAPSHOT_MAGIC_SIZE);
    header.version = TOPGEAR_SNAPSHOT_VERSION;
    if (memcmp(header.magic, "TGSNAP27", 8u) != 0 || header.version != 1u)
        return 2;
    if (topgear_recomp_snapshot_save(core, "invalid.snap", error,
                                     sizeof(error)) != 0 || error[0] == '\0')
        return 3;
    if (topgear_recomp_snapshot_load(core, "invalid.snap", error,
                                     sizeof(error)) != 0 || error[0] == '\0')
        return 4;
    free(core);
    return 0;
}
