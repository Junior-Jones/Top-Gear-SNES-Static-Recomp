#include "topgear_internal.h"

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <sched.h>
#endif

typedef struct RenderThread {
    TopGearRecomp *core;
    uint16_t expected;
    int passed;
} RenderThread;

#ifdef _WIN32
static DWORD WINAPI render_thread(void *opaque) {
    RenderThread *thread = (RenderThread *)opaque;
    unsigned iteration;
    thread->passed = 1;
    for (iteration = 0u; iteration < 512u; ++iteration) {
        unsigned y = iteration % TOPGEAR_RECOMP_FRAME_HEIGHT;
        size_t offset = (size_t)y * TOPGEAR_RECOMP_FRAME_WIDTH * 2u;
        uint16_t actual;
        if (!tg_v23_render_scanline(thread->core, y)) {
            thread->passed = 0;
            break;
        }
        actual = (uint16_t)(thread->core->mode1_frame[offset] |
                            ((uint16_t)thread->core->mode1_frame[offset + 1u] << 8u));
        if (actual != thread->expected) {
            thread->passed = 0;
            break;
        }
        SwitchToThread();
    }
    return 0u;
}
#else
static void *render_thread(void *opaque) {
    RenderThread *thread = (RenderThread *)opaque;
    unsigned iteration;
    thread->passed = 1;
    for (iteration = 0u; iteration < 512u; ++iteration) {
        unsigned y = iteration % TOPGEAR_RECOMP_FRAME_HEIGHT;
        size_t offset = (size_t)y * TOPGEAR_RECOMP_FRAME_WIDTH * 2u;
        uint16_t actual;
        if (!tg_v23_render_scanline(thread->core, y)) {
            thread->passed = 0;
            break;
        }
        actual = (uint16_t)(thread->core->mode1_frame[offset] |
                            ((uint16_t)thread->core->mode1_frame[offset + 1u] << 8u));
        if (actual != thread->expected) {
            thread->passed = 0;
            break;
        }
        sched_yield();
    }
    return NULL;
}
#endif

static TopGearRecomp *make_core(uint16_t backdrop) {
    TopGearRecomp *core = (TopGearRecomp *)calloc(1u, sizeof(*core));
    if (!core) return NULL;
    core->ppu_registers[0x00] = 0x0fu;
    core->ppu_registers[0x2c] = 0u;
    core->cgram[0] = (uint8_t)backdrop;
    core->cgram[1] = (uint8_t)(backdrop >> 8u);
    return core;
}

int main(void) {
    RenderThread a = {make_core(0x001fu), 0x001fu, 0};
    RenderThread b = {make_core(0x7c00u), 0x7c00u, 0};
    int passed;
    if (!a.core || !b.core) return 1;
#ifdef _WIN32
    {
        HANDLE threads[2];
        DWORD wait_result;
        threads[0] = CreateThread(NULL, 0u, render_thread, &a, 0u, NULL);
        threads[1] = CreateThread(NULL, 0u, render_thread, &b, 0u, NULL);
        if (!threads[0] || !threads[1]) return 2;
        wait_result = WaitForMultipleObjects(2u, threads, TRUE, INFINITE);
        passed = wait_result >= WAIT_OBJECT_0 && wait_result < WAIT_OBJECT_0 + 2u &&
                 a.passed && b.passed;
        CloseHandle(threads[0]);
        CloseHandle(threads[1]);
    }
#else
    {
        pthread_t threads[2];
        if (pthread_create(&threads[0], NULL, render_thread, &a) != 0 ||
            pthread_create(&threads[1], NULL, render_thread, &b) != 0) return 2;
        if (pthread_join(threads[0], NULL) != 0 || pthread_join(threads[1], NULL) != 0) return 2;
        passed = a.passed && b.passed;
    }
#endif
    free(a.core);
    free(b.core);
    return passed ? 0 : 3;
}
