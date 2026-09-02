#ifndef TOPGEAR_APP_CORE_H
#define TOPGEAR_APP_CORE_H

#include <stddef.h>
#include <stdint.h>

#include "topgear_static_recomp.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TOPGEAR_APP_ROM_SIZE 524288u
#define TOPGEAR_APP_FRAME_WIDTH 256u
#define TOPGEAR_APP_FRAME_HEIGHT 224u
#define TOPGEAR_APP_AUDIO_SAMPLE_RATE 32040u
#define TOPGEAR_APP_HOST_AUDIO_SAMPLE_RATE 32040u
#define TOPGEAR_APP_AUDIO_CHANNELS 2u
#define TOPGEAR_APP_AUDIO_BITS_PER_SAMPLE 16u
#define TOPGEAR_APP_PRESENTATION_FPS_NUMERATOR 39375000u
#define TOPGEAR_APP_PRESENTATION_FPS_DENOMINATOR 655171u

typedef struct TopGearApp TopGearApp;
typedef void (*TopGearAppAudioProgressCallback)(TopGearApp *, void *);

typedef struct TopGearAppFrameResult {
    uint8_t route_continued;
    uint8_t frame_rendered;
    uint16_t input_mask;
    uint32_t start_frame;
    uint32_t end_frame;
    char renderer_error[192];
} TopGearAppFrameResult;

int topgear_app_create(TopGearApp **, const uint8_t *, size_t,
                       char *, size_t);
void topgear_app_destroy(TopGearApp *);
int topgear_app_reset(TopGearApp *, char *, size_t);
int topgear_app_advance_streamed(TopGearApp *, uint16_t, uint32_t,
    TopGearAppAudioProgressCallback, void *, TopGearAppFrameResult *);
const uint32_t *topgear_app_frame_bgra(const TopGearApp *);
uint32_t topgear_app_frame_width(const TopGearApp *);
uint32_t topgear_app_current_frame(const TopGearApp *);
const char *topgear_app_last_error(const TopGearApp *);
size_t topgear_app_audio_available(const TopGearApp *);
size_t topgear_app_audio_read(TopGearApp *, int16_t *, size_t);
size_t topgear_app_audio_discard(TopGearApp *);
int topgear_app_audio_overflowed(const TopGearApp *);
void topgear_app_audio_clear_overflow(TopGearApp *);
uint64_t topgear_app_audio_dropped_frames(const TopGearApp *);
int topgear_app_snapshot_save(const TopGearApp *, const char *, char *, size_t);
int topgear_app_snapshot_load(TopGearApp *, const char *, char *, size_t);
int topgear_app_sram_copy(const TopGearApp *, void *, size_t);
int topgear_app_sram_load(TopGearApp *, const void *, size_t, char *, size_t);
int topgear_app_sram_dirty(const TopGearApp *);
void topgear_app_sram_mark_clean(TopGearApp *);
int topgear_app_write_diagnostic_log(const TopGearApp *, const char *,
                                     const char *, char *, size_t);

#ifdef __cplusplus
}
#endif
#endif
