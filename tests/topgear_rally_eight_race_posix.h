#ifndef TOPGEAR_RALLY_EIGHT_RACE_POSIX_H
#define TOPGEAR_RALLY_EIGHT_RACE_POSIX_H

#include <stddef.h>
#include <stdint.h>
#include <wchar.h>

#include "topgear_static_recomp.h"

/* Permanent Rally qualification derived from the mature four-race USA test.
   It creates the Rally schedule, snapshots/reloads it, drives the white
   Sidewinder through eight randomly selected country tracks, records points
   and evidence, and proves final-standings return to the remodeled menu. */
void topgear_rally_eight_race_begin(const wchar_t *executable_directory);
void topgear_rally_eight_race_cancel(void);
int topgear_rally_eight_race_active(void);
uint16_t topgear_rally_eight_race_input(TopGearRecomp *core);

/* Call after every emulated frame.  Returns 0 while running, 1 on completion,
   and -1 on failure.  message and report_path are always safe to expose to
   the launcher's native accessibility controls. */
int topgear_rally_eight_race_after_frame(TopGearRecomp *core,
                                     wchar_t *message,
                                     size_t message_capacity,
                                     wchar_t *report_path,
                                     size_t report_path_capacity);

#endif
