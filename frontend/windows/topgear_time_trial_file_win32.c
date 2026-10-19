#include "topgear_time_trial_file_win32.h"
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#define PATH_CAPACITY 4096
#define ARRAY_COUNT(x) (sizeof(x)/sizeof((x)[0]))

static int read_database(TopGearApp *game, const wchar_t *path) {
    FILE *file;
    void *bytes;
    size_t size,count;
    long length;
    int trailing;
    char error[256];
    if (!game || !path || !path[0]) return 0;
    file = _wfopen(path, L"rb");
    if (!file) {
        DWORD attributes=GetFileAttributesW(path),reason=GetLastError();
        /* Access/sharing errors are not an empty leaderboard. */
        return attributes==INVALID_FILE_ATTRIBUTES &&
               (reason==ERROR_FILE_NOT_FOUND||reason==ERROR_PATH_NOT_FOUND);
    }
    /* Read the actual file length so the host-side Time Trial store can
       recognize TGTT v6 and migrate TGTT v5 and safely reset semantically incomplete
       TGTT v1/v2 prototype history without assigning invented car metadata. */
    if (fseek(file, 0, SEEK_END) != 0 || (length = ftell(file)) <= 0 ||
        length > 1024L * 1024L || fseek(file, 0, SEEK_SET) != 0) {
        (void)fclose(file);
        return 0;
    }
    size = (size_t)length;
    bytes = malloc(size);
    if (!bytes) { (void)fclose(file); return 0; }
    count = fread(bytes, 1u, size, file);
    trailing = fgetc(file);
    { int failed=ferror(file); if(fclose(file)!=0)failed=1;
    if (failed || count != size || trailing != EOF) {
        free(bytes); return 0;
    }
    }
    memset(error, 0, sizeof(error));
    if (!topgear_app_time_trial_data_import(game, bytes, size, error, sizeof(error))) {
        free(bytes); return 0;
    }
    if(size>=8u&&((const unsigned char*)bytes)[4]==5u&&((const unsigned char*)bytes)[5]==0u){
        wchar_t backup[PATH_CAPACITY+64];
        _snwprintf_s(backup,ARRAY_COUNT(backup),_TRUNCATE,L"%s.v5-%lu-%llu.bak",path,(unsigned long)GetCurrentProcessId(),(unsigned long long)GetTickCount64());
        if(!CopyFileW(path,backup,TRUE)){free(bytes);return 0;}
    }
    free(bytes);
    return 1;
}

int topgear_time_trial_file_load(TopGearApp *game,const wchar_t *path,TopGearTimeTrialFileWin32 *state){
    if(!state)return 0;
    state->loaded=0;
    if(!game||!path||!path[0])return 0;
    state->loaded=read_database(game,path);
    return state->loaded;
}

int topgear_time_trial_file_save(TopGearApp *game, const wchar_t *path, const TopGearTimeTrialFileWin32 *state) {
    void *bytes;
    size_t size;
    wchar_t temporary[PATH_CAPACITY];
    FILE *file;
    int written;
    if (!game || !path || !path[0]) return 0;
    if (!state || !state->loaded) return 0;
    size = topgear_app_time_trial_data_size();
    bytes = malloc(size);
    if (!bytes) return 0;
    if (!topgear_app_time_trial_data_export(game, bytes, size)) { free(bytes); return 0; }
    written = _snwprintf(temporary, ARRAY_COUNT(temporary), L"%s.tmp-%lu",
                         path, (unsigned long)GetCurrentProcessId());
    if (written < 0 || (size_t)written >= ARRAY_COUNT(temporary)) { free(bytes); return 0; }
    file = _wfopen(temporary, L"wb");
    if (!file) { free(bytes); return 0; }
    {
        int failed = 0;
        if (fwrite(bytes, 1u, size, file) != size) failed = 1;
        if (!failed && fflush(file) != 0) failed = 1;
        /* fflush only reaches the CRT/OS boundary. _commit requests that the
           temporary TGTT bytes reach the storage device before the atomic
           replacement, matching the POSIX headless acceptance path's fsync. */
        if (!failed && _commit(_fileno(file)) != 0) failed = 1;
        if (fclose(file) != 0) failed = 1;
        if (failed ||
            !MoveFileExW(temporary, path,
                         MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)) {
            (void)DeleteFileW(temporary);
            free(bytes);
            return 0;
        }
    }
    free(bytes);
    /* This is the only point that acknowledges the completed-run handoff to
       the static core.  A failed durable save leaves the RESULTS page locked. */
    topgear_app_time_trial_data_mark_clean(game);
    return 1;
}
