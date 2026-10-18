#ifndef TOPGEAR_RIVALS_H
#define TOPGEAR_RIVALS_H

/* Private extension: no guessed free WRAM, camera, audio lane or native OAM slot. */
typedef struct TgRival {
    uint32_t position; /* native 24-bit fraction/course accumulator */
    uint32_t updates, pit_stops, refill_updates, contacts;
    uint16_t speed, fuel, gear, rpm, target, lateral, steering, recovery;
    uint16_t upper, lower, forward_step, finish_index, pit_elapsed, flags;
    int16_t lap, pit_phase;
    uint8_t id, car, passing_side, edge, nitro, gate;
} TgRival;

typedef struct TgExtendedObject {
    int16_t x,y;
    uint32_t order;
    uint16_t tile;
    uint8_t size, bank, palette, priority, hflip, vflip, math, driver;
} TgExtendedObject;

#define TG_RIVAL_OBJECT_CAPACITY 256u /* one native camera/OAM buffer */
typedef struct TgRivalObjects {
    TgExtendedObject objects[TG_RIVAL_OBJECT_CAPACITY];
    uint16_t count, owner, per_view[2];
    uint32_t generation;
} TgRivalObjects;

typedef struct TgRivals {
    uint64_t extra_cpu_off; /* saved preference; preserves the snapshot ABI */
    uint32_t abi, ticks, rendered[20], overflow, shadow_checks, shadow_failures;
    uint8_t ready, disabled, cars[4], projected[40], objects[40];
    uint8_t draw_id, body_id, staging, reserved;
    uint16_t course, players, saved_p2_car;
    TgRival rival[2];
    TgRival shadow;
    uint8_t tiles[4][4096];
    uint16_t palettes[32][16];
    TgRivalObjects pending[4], visible; /* two buffers for each existing view */
} TgRivals;

struct TopGearRecomp;
void tg_rivals_before(struct TopGearRecomp *,uint32_t);
void tg_rivals_menu_enter(struct TopGearRecomp *);
void tg_rivals_reset(struct TopGearRecomp *);
void tg_rivals_tick(struct TopGearRecomp *);
void tg_rivals_latch(struct TopGearRecomp *,uint16_t);
int tg_rivals_promoted(const struct TopGearRecomp *,unsigned);
uint8_t tg_rivals_name_byte(unsigned);
const char *tg_rivals_name(unsigned);
int tg_rivals_native_drive(struct TopGearRecomp *,TgRival *,unsigned);
void tg_rivals_physics(struct TopGearRecomp *,TgRival *,int);
void tg_rivals_steering(struct TopGearRecomp *,TgRival *,unsigned);
#endif
