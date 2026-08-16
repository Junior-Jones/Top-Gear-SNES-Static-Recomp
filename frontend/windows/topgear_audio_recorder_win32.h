#ifndef TOPGEAR_AUDIO_RECORDER_WIN32_H
#define TOPGEAR_AUDIO_RECORDER_WIN32_H
#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

typedef struct TopGearAudioRecorderWin32 {
    FILE *file;
    uint64_t frames_written;
    int write_failed;
    wchar_t path[4096];
    wchar_t last_error[256];
} TopGearAudioRecorderWin32;
void topgear_audio_recorder_win32_init(TopGearAudioRecorderWin32 *r);
int topgear_audio_recorder_win32_start(TopGearAudioRecorderWin32 *r,
                                      const wchar_t *audio_directory);
int topgear_audio_recorder_win32_write(TopGearAudioRecorderWin32 *r,
                                      const int16_t *samples,size_t frames);
int topgear_audio_recorder_win32_stop(TopGearAudioRecorderWin32 *r);
int topgear_audio_recorder_win32_active(const TopGearAudioRecorderWin32 *r);
#endif
