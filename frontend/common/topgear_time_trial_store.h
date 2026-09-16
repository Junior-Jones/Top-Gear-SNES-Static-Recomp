#ifndef TOPGEAR_TIME_TRIAL_STORE_H
#define TOPGEAR_TIME_TRIAL_STORE_H

#include <stddef.h>
#include <stdint.h>

#include "topgear_static_recomp.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TOPGEAR_TT_STORE_MAGIC UINT32_C(0x54544754)
#define TOPGEAR_TT_STORE_VERSION UINT16_C(6)
#define TOPGEAR_TT_STORE_FILE_SIZE 215240u

typedef struct TopGearTimeTrialStore {
    TopGearTimeTrialRun last_run;
    TopGearTimeTrialRun records[TOPGEAR_TIME_TRIAL_TRACK_COUNT]
                                  [TOPGEAR_TIME_TRIAL_CAR_COUNT]
                                  [TOPGEAR_TIME_TRIAL_RECORDS_PER_CAR];
    TopGearTimeTrialRun gear_records[32][4][2][5];
    uint32_t next_sequence;
    uint8_t dirty;
} TopGearTimeTrialStore;

void topgear_time_trial_store_init(TopGearTimeTrialStore *store);
size_t topgear_time_trial_store_data_size(void);
int topgear_time_trial_store_import(TopGearTimeTrialStore *store,
                                    const void *data, size_t size,
                                    char *error, size_t error_capacity);
int topgear_time_trial_store_export(const TopGearTimeTrialStore *store,
                                    void *data, size_t capacity);
int topgear_time_trial_store_insert(TopGearTimeTrialStore *store,
                                    const TopGearTimeTrialRun *run);
int topgear_time_trial_store_last_run(const TopGearTimeTrialStore *store,
                                      TopGearTimeTrialRun *out);
int topgear_time_trial_store_car_record(const TopGearTimeTrialStore *store,
                                        unsigned track, unsigned car,
                                        unsigned rank,
                                        TopGearTimeTrialRun *out);
int topgear_time_trial_store_overall_record(const TopGearTimeTrialStore *store,
                                            unsigned track, unsigned rank,
                                            TopGearTimeTrialRun *out);
int topgear_time_trial_store_provider(void *user, unsigned track,
                                      int car_filter, unsigned rank,
                                      TopGearTimeTrialRun *out);
int topgear_time_trial_store_filtered_record(const TopGearTimeTrialStore *, unsigned track, int car, int gearbox, unsigned rank, TopGearTimeTrialRun *);
int topgear_time_trial_store_dirty(const TopGearTimeTrialStore *store);
void topgear_time_trial_store_mark_clean(TopGearTimeTrialStore *store);

#ifdef __cplusplus
}
#endif
#endif
