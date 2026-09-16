#ifndef TOPGEAR_HEADED_TEST06_POSIX_H
#define TOPGEAR_HEADED_TEST06_POSIX_H

#include <stddef.h>
#include <stdint.h>
#include <wchar.h>

#include "topgear_static_recomp.h"

/* Temporary headed counterpart of static-core Headless Test 06.  The
   launcher owns the core, presentation and audio; this module only chooses
   controller-port-1 input and records the four USA race results. */
void topgear_headed_test06_begin(const wchar_t *executable_directory);
void topgear_headed_test06_cancel(void);
int topgear_headed_test06_active(void);
uint16_t topgear_headed_test06_input(TopGearRecomp *core);

/* Call after every emulated frame.  Returns 0 while running, 1 on completion,
   and -1 on failure.  message and report_path are always safe to expose to
   the launcher's native accessibility controls. */
int topgear_headed_test06_after_frame(TopGearRecomp *core,
                                     wchar_t *message,
                                     size_t message_capacity,
                                     wchar_t *report_path,
                                     size_t report_path_capacity);

#endif
