#ifndef TOPGEAR_TIME_TRIAL_FILE_WIN32_H
#define TOPGEAR_TIME_TRIAL_FILE_WIN32_H
#include "topgear_app_core.h"
#include <wchar.h>
typedef struct TopGearTimeTrialFileWin32 { int loaded; } TopGearTimeTrialFileWin32;
int topgear_time_trial_file_load(TopGearApp *,const wchar_t *,TopGearTimeTrialFileWin32 *);
int topgear_time_trial_file_save(TopGearApp *,const wchar_t *,const TopGearTimeTrialFileWin32 *);
#endif
