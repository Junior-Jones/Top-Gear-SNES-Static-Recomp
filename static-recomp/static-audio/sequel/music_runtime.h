#pragma once
#include <stdint.h>
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif
int tg0_music_select(unsigned);
int tg0_music_sample(int16_t*,int16_t*);
void tg0_music_gain(unsigned);
int tg0_music_prepare(void);
void tg0_music_release(void);
size_t tg0_music_snapshot_size(void);
int tg0_music_snapshot_save(void*,size_t);
int tg0_music_snapshot_load(const void*,size_t,char*,size_t);
int tg2_music_select(unsigned track);
int tg2_music_sample(int16_t *left,int16_t *right);
void tg2_music_gain(unsigned percent);
int tg2_music_prepare(void);
void tg2_music_release(void);
int tg3_music_select(unsigned track);
int tg3_music_sample(int16_t *left,int16_t *right);
void tg3_music_gain(unsigned percent);
int tg3_music_prepare(void);
void tg3_music_release(void);
size_t tg2_music_snapshot_size(void);
int tg2_music_snapshot_save(void*,size_t);
int tg2_music_snapshot_load(const void*,size_t,char*,size_t);
size_t tg3_music_snapshot_size(void);
int tg3_music_snapshot_save(void*,size_t);
int tg3_music_snapshot_load(const void*,size_t,char*,size_t);
#ifdef __cplusplus
}
#endif
