#include "topgear_app_core.h"

#include "topgear_static_recomp.h"
#include "topgear_time_trial_store.h"
#include "topgear_player_settings_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct TopGearApp {
    TopGearRecomp *core;
    TopGearTimeTrialStore time_trial_store;
    uint8_t time_trial_run_staged;
    uint8_t player_settings_cache[TOPGEAR_PLAYER_SETTINGS_SIZE];
    int player_settings_load_failed;
    HANDLE player_settings_writer;
    HANDLE music_writer;
    int music_load_failed;
    uint8_t music_cache[TOPGEAR_MUSIC_STATE_SIZE],music_write_bytes[TOPGEAR_MUSIC_STATE_SIZE];
    char music_path[4096];
    uint8_t player_settings_write_bytes[TOPGEAR_PLAYER_SETTINGS_SIZE];
    char player_settings_write_path[4096];
    uint32_t frame[TOPGEAR_APP_FRAME_WIDTH * TOPGEAR_APP_FRAME_HEIGHT];
    char error[192];
};

/* The worker owns only an immutable exported record, never the live core.
   The game thread coalesces edits while a durable replacement is in flight. */
static DWORD WINAPI write_player_settings_worker(void *opaque) {
    TopGearApp *app=(TopGearApp *)opaque;
    return topgear_player_settings_write_bytes(app->player_settings_write_path,
        app->player_settings_write_bytes)?0u:1u;
}
static int finish_player_settings_write(TopGearApp *app,DWORD wait) {
    DWORD result=1u;
    if(!app->player_settings_writer)return 1;
    if(WaitForSingleObject(app->player_settings_writer,wait)==WAIT_TIMEOUT)return 1;
    if(!GetExitCodeThread(app->player_settings_writer,&result))result=1u;
    CloseHandle(app->player_settings_writer);app->player_settings_writer=NULL;
    if(!result)memcpy(app->player_settings_cache,app->player_settings_write_bytes,
        TOPGEAR_PLAYER_SETTINGS_SIZE);
    return result==0u;
}


static DWORD WINAPI write_music_worker(void *opaque){TopGearApp *a=(TopGearApp*)opaque;return topgear_settings_write_record(a->music_path,a->music_write_bytes,TOPGEAR_MUSIC_STATE_SIZE)?0u:1u;}
static int finish_music_write(TopGearApp *a,DWORD wait){
    DWORD result=1u;if(!a->music_writer)return 1;
    if(WaitForSingleObject(a->music_writer,wait)==WAIT_TIMEOUT)return 1;
    if(!GetExitCodeThread(a->music_writer,&result))result=1u;
    CloseHandle(a->music_writer);a->music_writer=NULL;
    if(!result)memcpy(a->music_cache,a->music_write_bytes,TOPGEAR_MUSIC_STATE_SIZE);return result==0u;
}
static int music_path(TopGearApp *a,const char *settings){
    const char *slash=strrchr(settings,'/'),*back=strrchr(settings,'\\');size_t prefix;
    if(back&&(!slash||back>slash))slash=back;prefix=slash?(size_t)(slash-settings)+1u:0u;
    if(prefix+sizeof("music-state.dat")>sizeof(a->music_path))return 0;
    memcpy(a->music_path,settings,prefix);memcpy(a->music_path+prefix,"music-state.dat",sizeof("music-state.dat"));return 1;
}
static int save_music(TopGearApp *a){
    uint8_t b[TOPGEAR_MUSIC_STATE_SIZE];
    if(a->music_load_failed)return 0;
    if(!a->music_path[0])return 1;
    if(!finish_music_write(a,0u))return 0;if(a->music_writer)return 1;
    if(!topgear_recomp_music_state_export(a->core,b,sizeof(b)))return 0;
    if(!memcmp(b,a->music_cache,sizeof(b)))return 1;
    memcpy(a->music_write_bytes,b,sizeof(b));a->music_writer=CreateThread(NULL,0u,write_music_worker,a,0u,NULL);return a->music_writer!=NULL;
}
static void copy_error(TopGearApp *app, char *error, size_t capacity,
                       const char *text) {
    if (!text) text = "";
    if (app) (void)snprintf(app->error, sizeof(app->error), "%s", text);
    if (error && capacity) (void)snprintf(error, capacity, "%s", text);
}

static void refresh_frame(TopGearApp *app) {
    if (app) (void)topgear_recomp_frame_bgra(
        app->core, app->frame,
        sizeof(app->frame) / sizeof(app->frame[0]));
}

int topgear_app_create(TopGearApp **out, const uint8_t *rom, size_t size,
                       char *error, size_t capacity) {
    TopGearApp *app;
    if (!out || !rom || size != TOPGEAR_APP_ROM_SIZE) {
        if (error && capacity) (void)snprintf(
            error, capacity,
            "The exact 524,288-byte Top Gear (USA) ROM is required.");
        return 0;
    }
    *out = NULL;
    app = (TopGearApp *)calloc(1u, sizeof(*app));
    if (!app) return 0;
    if (!topgear_recomp_create(&app->core, rom, size, error, capacity)) {
        free(app);
        return 0;
    }
    topgear_time_trial_store_init(&app->time_trial_store);
    topgear_recomp_time_trial_set_leaderboard_provider(
        app->core, topgear_time_trial_store_provider, &app->time_trial_store);
    refresh_frame(app);
    copy_error(app, error, capacity, "");
    *out = app;
    return 1;
}

void topgear_app_destroy(TopGearApp *app) {
    if (!app) return;
    (void)finish_player_settings_write(app,INFINITE);
    /* Include the latest edits, even if the user closes during a write. */
    if(app->player_settings_write_path[0]&&!app->player_settings_load_failed)
        (void)topgear_player_settings_save_file(app->core,
            app->player_settings_write_path,app->player_settings_cache);
    (void)finish_music_write(app,INFINITE);
    if(app->music_path[0]&&!app->music_load_failed){
        uint8_t music[TOPGEAR_MUSIC_STATE_SIZE];
        if(topgear_recomp_music_state_export(app->core,music,sizeof(music))&&memcmp(music,app->music_cache,sizeof(music)))
            (void)topgear_settings_write_record(app->music_path,music,sizeof(music));
    }
    topgear_recomp_destroy(app->core);
    free(app);
}

int topgear_app_reset(TopGearApp *app, char *error, size_t capacity) {
    uint8_t settings[TOPGEAR_PLAYER_SETTINGS_SIZE],music[TOPGEAR_MUSIC_STATE_SIZE];int have;
    if(!app)return 0;
    (void)topgear_recomp_music_state_export(app->core,music,sizeof(music));
    have=topgear_recomp_player_settings_export(app->core,settings,sizeof(settings));
    if (!app || !topgear_recomp_reset(app->core, error, capacity)) return 0;
    (void)topgear_recomp_music_state_import(app->core,music,sizeof(music));
    if(have)(void)topgear_recomp_player_settings_import(app->core,settings,sizeof(settings));
    else if(app->player_settings_cache[0])
        (void)topgear_recomp_player_settings_import(app->core,app->player_settings_cache,sizeof(app->player_settings_cache));
    refresh_frame(app);
    copy_error(app, error, capacity, "");
    return 1;
}

int topgear_app_player_settings_load(TopGearApp *app,const char *path){
    if(!app)return 0;
    (void)finish_player_settings_write(app,INFINITE);
    app->player_settings_load_failed=!topgear_player_settings_load_file(app->core,path,app->player_settings_cache);
    (void)finish_music_write(app,INFINITE);
    app->music_load_failed=!music_path(app,path)||!topgear_music_state_load_file(app->core,app->music_path,app->music_cache);
    if(!app->music_load_failed&&!app->music_cache[0]){LARGE_INTEGER ticks;QueryPerformanceCounter(&ticks);topgear_recomp_music_state_seed(app->core,(uint32_t)ticks.QuadPart^(uint32_t)(ticks.QuadPart>>32));}
    return !app->player_settings_load_failed&&!app->music_load_failed;
}
int topgear_app_player_settings_save(TopGearApp *app,const char *path){
    uint8_t bytes[TOPGEAR_PLAYER_SETTINGS_SIZE];
    size_t length;
    if(!app||!path||app->player_settings_load_failed)return 0;
    if(!app->music_path[0]&&!music_path(app,path))return 0;
    if(!save_music(app))return 0;
    if(!finish_player_settings_write(app,0u))return 0;
    if(app->player_settings_writer)return 1;
    if(!topgear_recomp_player_settings_export(app->core,bytes,sizeof(bytes)))return 1;
    if(!memcmp(bytes,app->player_settings_cache,sizeof(bytes)))return 1;
    length=strlen(path);
    if(length>=sizeof(app->player_settings_write_path))return 0;
    memcpy(app->player_settings_write_path,path,length+1u);
    memcpy(app->player_settings_write_bytes,bytes,sizeof(bytes));
    app->player_settings_writer=CreateThread(NULL,0u,write_player_settings_worker,app,0u,NULL);
    return app->player_settings_writer!=NULL;
}

int topgear_app_advance_streamed(TopGearApp *app, uint16_t input,
    uint32_t frames, TopGearAppAudioProgressCallback progress, void *opaque,
    TopGearAppFrameResult *result) {
    TopGearRecompFrameResult core_result;
    uint32_t completed;
    if (!app || !result) return 0;
    memset(result, 0, sizeof(*result));
    result->input_mask = input;
    result->start_frame = topgear_recomp_current_frame(app->core);
    for (completed = 0u; completed < frames; ++completed) {
        memset(&core_result, 0, sizeof(core_result));
        if (!topgear_recomp_advance(app->core, input, 0u, 1u,
                                    &core_result)) {
            copy_error(app, NULL, 0u,
                       topgear_recomp_last_error(app->core));
            result->end_frame = topgear_recomp_current_frame(app->core);
            return 0;
        }
        result->route_continued = core_result.route_continued;
        result->frame_rendered = core_result.frame_rendered;
        (void)snprintf(result->renderer_error,
                       sizeof(result->renderer_error), "%s",
                       core_result.renderer_error);
        if (topgear_recomp_time_trial_completed_run_pending(app->core)) {
            if (!app->time_trial_run_staged) {
                TopGearTimeTrialRun run;
                memset(&run, 0, sizeof(run));
                if (!topgear_recomp_time_trial_completed_run(app->core, &run) ||
                    !topgear_time_trial_store_insert(&app->time_trial_store, &run)) {
                    copy_error(app, NULL, 0u,
                               "Completed Time Trial could not be staged for Data persistence.");
                    result->end_frame = topgear_recomp_current_frame(app->core);
                    return 0;
                }
                app->time_trial_run_staged = 1u;
            }
        } else {
            app->time_trial_run_staged = 0u;
        }
        if (progress) progress(app, opaque);
    }
    result->end_frame = topgear_recomp_current_frame(app->core);
    refresh_frame(app);
    copy_error(app, NULL, 0u, "");
    return 1;
}

const uint32_t *topgear_app_frame_bgra(const TopGearApp *app) {
    return app ? app->frame : NULL;
}
uint32_t topgear_app_frame_width(const TopGearApp *app) {
    return app ? TOPGEAR_APP_FRAME_WIDTH : 0u;
}
uint32_t topgear_app_current_frame(const TopGearApp *app) {
    return app ? topgear_recomp_current_frame(app->core) : 0u;
}
const char *topgear_app_last_error(const TopGearApp *app) {
    return app ? app->error : "No Top Gear instance.";
}
size_t topgear_app_audio_available(const TopGearApp *app) {
    return app ? topgear_recomp_audio_available(app->core) : 0u;
}
size_t topgear_app_audio_read(TopGearApp *app, int16_t *pcm, size_t frames) {
    return app ? topgear_recomp_audio_read(app->core, pcm, frames) : 0u;
}
size_t topgear_app_audio_discard(TopGearApp *app) {
    size_t frames = topgear_app_audio_available(app);
    return app ? topgear_recomp_audio_discard(app->core, frames) : 0u;
}
int topgear_app_audio_overflowed(const TopGearApp *app) {
    return app && topgear_recomp_audio_overflowed(app->core);
}
void topgear_app_audio_clear_overflow(TopGearApp *app) {
    if (app) topgear_recomp_audio_clear_overflow(app->core);
}
uint64_t topgear_app_audio_dropped_frames(const TopGearApp *app) {
    TopGearStaticAudioStatus status;
    memset(&status, 0, sizeof(status));
    return app && topgear_recomp_static_audio_status(app->core, &status) ?
           status.fifo_dropped_frames : 0u;
}
int topgear_app_snapshot_save(const TopGearApp *app, const char *path,
                              char *error, size_t capacity) {
    return app && topgear_recomp_snapshot_save(app->core, path,
                                                error, capacity);
}
int topgear_app_snapshot_load(TopGearApp *app, const char *path,
                              char *error, size_t capacity) {
    int ok = app && topgear_recomp_snapshot_load(app->core, path,
                                                  error, capacity);
    if (ok) refresh_frame(app);
    return ok;
}
int topgear_app_sram_copy(const TopGearApp *app, void *dst, size_t capacity) {
    return app && topgear_recomp_sram_copy(app->core, dst, capacity);
}
int topgear_app_sram_load(TopGearApp *app, const void *src, size_t size,
                          char *error, size_t capacity) {
    return app && topgear_recomp_sram_load(app->core, src, size,
                                            error, capacity);
}
int topgear_app_sram_dirty(const TopGearApp *app) {
    return app && topgear_recomp_sram_dirty(app->core);
}
void topgear_app_sram_mark_clean(TopGearApp *app) {
    if (app) topgear_recomp_sram_mark_clean(app->core);
}

size_t topgear_app_time_trial_data_size(void) {
    return topgear_time_trial_store_data_size();
}
int topgear_app_time_trial_data_export(const TopGearApp *app, void *dst, size_t capacity) {
    return app && topgear_time_trial_store_export(&app->time_trial_store, dst, capacity);
}
int topgear_app_time_trial_data_import(TopGearApp *app, const void *src, size_t size,
                                       char *error, size_t capacity) {
    return app && topgear_time_trial_store_import(&app->time_trial_store, src, size,
                                                  error, capacity);
}
int topgear_app_time_trial_data_dirty(const TopGearApp *app) {
    return app && topgear_time_trial_store_dirty(&app->time_trial_store);
}
void topgear_app_time_trial_data_mark_clean(TopGearApp *app) {
    if (!app) return;
    topgear_time_trial_store_mark_clean(&app->time_trial_store);
    if (app->time_trial_run_staged) {
        if (topgear_recomp_time_trial_commit_completed_run(app->core))
            app->time_trial_run_staged = 0u;
    }
}

int topgear_app_write_diagnostic_log(const TopGearApp *app, const char *path,
                                     const char *screenshot_path,
                                     char *error, size_t capacity) {
    FILE *file;
    TopGearCpuState cpu;
    TopGearSmpState smp;
    TopGearFrontierReceipt frontier;
    TopGearStaticAudioStatus audio;
    if (!app || !path || !path[0]) return 0;
    memset(&cpu, 0, sizeof(cpu));
    memset(&smp, 0, sizeof(smp));
    memset(&frontier, 0, sizeof(frontier));
    memset(&audio, 0, sizeof(audio));
    topgear_recomp_cpu_state(app->core, &cpu);
    topgear_recomp_smp_state(app->core, &smp);
    topgear_recomp_frontier(app->core, &frontier);
    (void)topgear_recomp_static_audio_status(app->core, &audio);
    file = fopen(path, "wb");
    if (!file) {
        if (error && capacity) (void)snprintf(
            error, capacity, "The diagnostic log could not be opened.");
        return 0;
    }
    (void)fprintf(file,
        "Top Gear Static Recomp - Screenshot Static-Core Log\r\n"
        "screenshot=%s\r\nframe=%u\r\ninstructions=%llu\r\n"
        "cpu=%02X:%04X\r\nsmp_pc=%04X\r\nsmp_instructions=%llu\r\n"
        "audio_pcm_frames=%llu\r\naudio_unknown_frames=%llu\r\n"
        "audio_hash=%016llX\r\naudio_aot_failed=%u\r\n"
        "failed=%d\r\nfrontier=%s\r\nreason=%s\r\n",
        screenshot_path ? screenshot_path : "",
        topgear_recomp_current_frame(app->core),
        (unsigned long long)topgear_recomp_instruction_count(app->core),
        (unsigned)cpu.pbr, (unsigned)cpu.pc, (unsigned)smp.pc,
        (unsigned long long)smp.instruction_count,
        (unsigned long long)audio.pcm_frames,
        (unsigned long long)audio.pcm_unknown_frames,
        (unsigned long long)audio.pcm_hash, (unsigned)audio.aot_failed,
        topgear_recomp_failed(app->core), frontier.address, frontier.reason);
    if (fclose(file) != 0) return 0;
    if (error && capacity) error[0] = '\0';
    return 1;
}

int topgear_app_profile_read(TopGearApp *a,unsigned bank,TopGearPlayerProfile *p){return a&&topgear_recomp_profile_read(a->core,bank,p);}
int topgear_app_profile_write(TopGearApp *a,unsigned bank,const TopGearPlayerProfile *p,const char *path){
    TopGearPlayerProfile old;
    uint8_t bytes[TOPGEAR_PLAYER_SETTINGS_SIZE];
    if(!a||!p||!path||!topgear_recomp_profile_read(a->core,bank,&old)||
       !finish_player_settings_write(a,INFINITE)||
       !topgear_recomp_profile_write(a->core,bank,p))return 0;
    /* The regular menu export is intentionally unavailable while the ROM is
       outside the remodeled menus.  Profile is a launcher operation, so use
       the canonical profile record as the fallback and write it synchronously
       before the dialog verifies the saved values. */
    if((!topgear_recomp_player_settings_export(a->core,bytes,sizeof(bytes))&&
        !topgear_recomp_profile_record(a->core,bytes,sizeof(bytes)))||
       !topgear_player_settings_write_bytes(path,bytes)){
        (void)topgear_recomp_profile_write(a->core,bank,&old);
        return 0;
    }
    memcpy(a->player_settings_cache,bytes,sizeof(bytes));
    a->player_settings_load_failed=0;
    return 1;
}

int topgear_app_leaderboard(const TopGearApp *a,unsigned track,int car,int gear,unsigned rank,TopGearTimeTrialRun *out){return a&&topgear_time_trial_store_filtered_record(&a->time_trial_store,track,car,gear,rank,out);}
