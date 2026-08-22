#ifndef TOPGEAR_SNAPSHOT_FORMAT_H
#define TOPGEAR_SNAPSHOT_FORMAT_H

#include <stdint.h>

#define TOPGEAR_SNAPSHOT_MAGIC "TGSNAP27"
#define TOPGEAR_SNAPSHOT_MAGIC_SIZE 8u
#define TOPGEAR_SNAPSHOT_VERSION 1u

typedef struct TopGearSnapshotHeader {
    char magic[TOPGEAR_SNAPSHOT_MAGIC_SIZE];
    uint32_t version;
    uint32_t core_size;
    uint32_t apu_size;
    uint32_t reserved;
    uint64_t core_hash;
    uint64_t apu_hash;
} TopGearSnapshotHeader;

#endif
