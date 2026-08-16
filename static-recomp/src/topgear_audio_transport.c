#include "topgear_static_recomp.h"
#include "topgear_internal.h"

#include <stddef.h>

size_t topgear_recomp_audio_available(const TopGearRecomp *instance) {
    return instance ? (size_t)instance->audio_count : 0u;
}

size_t topgear_recomp_audio_read(TopGearRecomp *instance,
                                 int16_t *interleaved_stereo,
                                 size_t frame_capacity) {
    size_t frames = 0u;
    if(!instance || !interleaved_stereo) return 0u;
    while(frames < frame_capacity && instance->audio_count > 0u) {
        uint32_t index = instance->audio_read_index;
        interleaved_stereo[frames * 2u] = instance->audio_fifo[index * 2u];
        interleaved_stereo[frames * 2u + 1u] = instance->audio_fifo[index * 2u + 1u];
        instance->audio_read_index = (index + 1u) % TOPGEAR_RECOMP_AUDIO_FIFO_FRAMES;
        instance->audio_count--;
        frames++;
    }
    return frames;
}

size_t topgear_recomp_audio_discard(TopGearRecomp *instance,size_t frame_count) {
    size_t discarded;
    if(!instance) return 0u;
    discarded = frame_count < (size_t)instance->audio_count ? frame_count : (size_t)instance->audio_count;
    instance->audio_read_index = (instance->audio_read_index + (uint32_t)discarded) % TOPGEAR_RECOMP_AUDIO_FIFO_FRAMES;
    instance->audio_count -= (uint32_t)discarded;
    return discarded;
}

void topgear_recomp_audio_clear(TopGearRecomp *instance) {
    if(!instance) return;
    instance->audio_read_index = 0u;
    instance->audio_write_index = 0u;
    instance->audio_count = 0u;
}

void tg_audio_push_frame(TopGearRecomp *instance,int16_t left,int16_t right) {
    uint32_t index;
    if(!instance) return;
    if(instance->audio_count>=TOPGEAR_RECOMP_AUDIO_FIFO_FRAMES) {
        instance->audio_read_index=(instance->audio_read_index+1u)%TOPGEAR_RECOMP_AUDIO_FIFO_FRAMES;
        instance->audio_count--;
        instance->audio_fifo_dropped_frames++;
    }
    index=instance->audio_write_index;
    instance->audio_fifo[index*2u]=left;
    instance->audio_fifo[index*2u+1u]=right;
    instance->audio_write_index=(index+1u)%TOPGEAR_RECOMP_AUDIO_FIFO_FRAMES;
    instance->audio_count++;
}
