#ifndef TOPGEAR_VIDEO_OUTPUT_SDL3_H
#define TOPGEAR_VIDEO_OUTPUT_SDL3_H

#if !defined(_WIN32)
#error This video presenter is for Windows only.
#endif

#include <windows.h>
#include <stdint.h>

#include <SDL3/SDL.h>

#include "topgear_static_recomp.h"

typedef struct TopGearVideoDiagnostics {
    uint64_t submitted_frames;
    uint64_t presented_frames;
    uint64_t dropped_presentations;
    uint64_t renderer_recoveries;
    uint64_t presentation_failures;
    int using_gpu;
    int vsync_enabled;
    char renderer_name[64];
} TopGearVideoDiagnostics;

typedef struct TopGearVideoOutput {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    uint32_t frame_buffers[2][TOPGEAR_RECOMP_FRAME_WIDTH *
                              TOPGEAR_RECOMP_FRAME_HEIGHT];
    unsigned front_buffer;
    int frame_valid;
    int video_subsystem_initialized;
    int vsync_enabled;
    TopGearVideoDiagnostics diagnostics;
} TopGearVideoOutput;

void topgear_video_output_initialize(TopGearVideoOutput *output);
int topgear_video_output_open(TopGearVideoOutput *output, HWND window,
                              int vsync_enabled, wchar_t *error,
                              size_t error_capacity);
void topgear_video_output_close(TopGearVideoOutput *output);
int topgear_video_output_set_vsync(TopGearVideoOutput *output, int enabled);
int topgear_video_output_submit(TopGearVideoOutput *output,
                                const uint32_t *pixels, size_t pixel_count);
int topgear_video_output_present(TopGearVideoOutput *output, int render_top,
                                 int integer_scale, int correct_aspect);
int topgear_video_output_available(const TopGearVideoOutput *output);
void topgear_video_output_get_diagnostics(
    const TopGearVideoOutput *output, TopGearVideoDiagnostics *diagnostics);
void topgear_video_output_calculate_destination(
    int output_width, int output_height, int render_top, int integer_scale,
    int correct_aspect, int *x, int *y, int *width, int *height);

#endif
