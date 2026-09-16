#include "topgear_time_trial_store.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TGTT_HEADER_BYTES 32u
#define TGTT_RECORD_BYTES 168u
#define TGTT_VALID_COMPLETE UINT8_C(0x03)

typedef struct TgttHeaderV5 {
    uint32_t magic;
    uint16_t version;
    uint16_t record_size;
    uint32_t track_count;
    uint32_t car_count;
    uint32_t records_per_car;
    uint32_t header_size;
    uint32_t flags;
    uint32_t reserved;
} TgttHeaderV5;

typedef struct TgttFileV5 {
    TgttHeaderV5 header;
    TopGearTimeTrialRun last_run;
    TopGearTimeTrialRun records[TOPGEAR_TIME_TRIAL_TRACK_COUNT]
                                   [TOPGEAR_TIME_TRIAL_CAR_COUNT]
                                   [TOPGEAR_TIME_TRIAL_RECORDS_PER_CAR];
} TgttFileV5;

_Static_assert(sizeof(TopGearTimeTrialRun) == TGTT_RECORD_BYTES,
               "Time Trial run wire record must remain 168 bytes");
_Static_assert(sizeof(TgttHeaderV5) == TGTT_HEADER_BYTES,
               "TGTT v5 header must remain 32 bytes");
_Static_assert(sizeof(TgttFileV5) == 107720u,
               "TGTT v5 file size changed unexpectedly");

typedef struct TgttFileV6 {
    TgttHeaderV5 header;
    TopGearTimeTrialRun last_run;
    TopGearTimeTrialRun records[32][4][2][5];
} TgttFileV6;
_Static_assert(sizeof(TgttFileV6)==TOPGEAR_TT_STORE_FILE_SIZE,"TGTT v6 size");

static void set_error(char *error, size_t capacity, const char *text) {
    if (error && capacity) {
        (void)snprintf(error, capacity, "%s", text ? text : "");
        error[capacity - 1u] = '\0';
    }
}

static int valid_name_byte(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ';
}

static int validate_run(const TopGearTimeTrialRun *run, int allow_empty) {
    unsigned lap, n;
    uint64_t total = 0u;
    uint32_t best1 = UINT32_MAX, best2 = UINT32_MAX, best3 = UINT32_MAX;
    if (!run) return 0;
    if ((run->valid_flags & 1u) == 0u)
        return allow_empty && run->total_time_ticks == 0u;
    if (run->course >= TOPGEAR_TIME_TRIAL_TRACK_COUNT ||
        run->car_id >= TOPGEAR_TIME_TRIAL_CAR_COUNT ||
        run->gearbox > 1u || run->required_laps < 1u ||
        run->required_laps > TOPGEAR_TIME_TRIAL_MAX_LAPS ||
        run->completed_laps != run->required_laps ||
        run->total_time_ticks == 0u ||
        (run->valid_flags & TGTT_VALID_COMPLETE) != TGTT_VALID_COMPLETE)
        return 0;
    for (n = 0u; n < 8u; ++n)
        if (!valid_name_byte(run->name[n])) return 0;
    for (lap = 0u; lap < run->required_laps; ++lap) {
        uint32_t t = run->lap_time_ticks[lap];
        uint32_t s1 = run->lap_sector1_ticks[lap];
        uint32_t s2 = run->lap_sector2_ticks[lap];
        uint32_t s3 = run->lap_sector3_ticks[lap];
        if (!t || !s1 || !s2 || !s3 || (uint64_t)s1 + s2 + s3 != t) return 0;
        total += t;
        if (s1 < best1) best1 = s1;
        if (s2 < best2) best2 = s2;
        if (s3 < best3) best3 = s3;
    }
    for (; lap < TOPGEAR_TIME_TRIAL_MAX_LAPS; ++lap) {
        if (run->lap_time_ticks[lap] || run->lap_sector1_ticks[lap] ||
            run->lap_sector2_ticks[lap] || run->lap_sector3_ticks[lap]) return 0;
    }
    return total == run->total_time_ticks &&
           best1 == run->best_sector1_ticks &&
           best2 == run->best_sector2_ticks &&
           best3 == run->best_sector3_ticks;
}

static uint64_t best_sum(const TopGearTimeTrialRun *run) {
    return (uint64_t)run->best_sector1_ticks + run->best_sector2_ticks +
           run->best_sector3_ticks;
}

static int run_before(const TopGearTimeTrialRun *a,
                      const TopGearTimeTrialRun *b) {
    uint64_t as, bs;
    if (!b->total_time_ticks) return 1;
    if (a->total_time_ticks != b->total_time_ticks)
        return a->total_time_ticks < b->total_time_ticks;
    as = best_sum(a); bs = best_sum(b);
    if (as != bs) return as < bs;
    /* Earlier existing record wins exact ties. A newly inserted run receives a
       monotonically larger sequence number, so stable ordering is preserved. */
    return a->sequence < b->sequence;
}

static void insert_ranked(TopGearTimeTrialStore *s,const TopGearTimeTrialRun *r){
    TopGearTimeTrialRun *bank=s->gear_records[r->course][r->car_id][r->gearbox], merged[10];
    unsigned n,pos,count=0,g,j;
    for(n=0;n<5;n++)if(bank[n].valid_flags&1u){if(!memcmp(&bank[n],r,sizeof(*r)))return;}
    for(pos=0;pos<5;pos++)if(!bank[pos].total_time_ticks||run_before(r,&bank[pos]))break;
    if(pos<5){for(n=4;n>pos;n--)bank[n]=bank[n-1];bank[pos]=*r;}
    for(g=0;g<2;g++)for(n=0;n<5;n++)if(s->gear_records[r->course][r->car_id][g][n].valid_flags&1u)merged[count++]=s->gear_records[r->course][r->car_id][g][n];
    for(n=1;n<count;n++){TopGearTimeTrialRun key=merged[n];for(j=n;j&&run_before(&key,&merged[j-1]);j--)merged[j]=merged[j-1];merged[j]=key;}
    memset(s->records[r->course][r->car_id],0,sizeof(s->records[0][0]));
    for(n=0;n<count&&n<5;n++)s->records[r->course][r->car_id][n]=merged[n];
}

void topgear_time_trial_store_init(TopGearTimeTrialStore *store) {
    if (!store) return;
    memset(store, 0, sizeof(*store));
    store->next_sequence = 1u;
}

size_t topgear_time_trial_store_data_size(void){return sizeof(TgttFileV6);}
int topgear_time_trial_store_export(const TopGearTimeTrialStore *s,void *data,size_t capacity){
    TgttFileV6 *f;
    if(!s||!data||capacity<sizeof(*f))return 0;
    f=(TgttFileV6*)data;memset(f,0,sizeof(*f));
    f->header.magic=TOPGEAR_TT_STORE_MAGIC;f->header.version=6;f->header.record_size=168;
    f->header.track_count=32;f->header.car_count=4;f->header.records_per_car=10;
    f->header.header_size=32;f->header.flags=3;
    f->last_run=s->last_run;memcpy(f->records,s->gear_records,sizeof(f->records));return 1;
}
int topgear_time_trial_store_import(TopGearTimeTrialStore *s,const void *data,size_t size,char *error,size_t cap){
    TgttHeaderV5 h;TopGearTimeTrialStore *tmp;TopGearTimeTrialRun last;
    unsigned track,car,g,rank,gears;uint32_t maxseq=0;const TopGearTimeTrialRun *records;
    if(!s||!data||size<8){set_error(error,cap,"Time Trial data is missing or truncated.");return 0;}
    memset(&h,0,sizeof(h));memcpy(&h,data,size<sizeof(h)?size:sizeof(h));
    if(h.magic==TOPGEAR_TT_STORE_MAGIC&&(h.version==1||h.version==2)){topgear_time_trial_store_init(s);s->dirty=1;set_error(error,cap,"");return 1;}
    if(h.magic!=TOPGEAR_TT_STORE_MAGIC||h.record_size!=168||h.track_count!=32||h.car_count!=4||h.header_size!=32||
       !((h.version==5&&size==sizeof(TgttFileV5)&&h.records_per_car==5)||(h.version==6&&size==sizeof(TgttFileV6)&&h.records_per_car==10))){set_error(error,cap,"Unsupported Top Gear Time Trial data format.");return 0;}
    memcpy(&last,(const unsigned char*)data+32,sizeof(last));
    if(!validate_run(&last,1)){set_error(error,cap,"Time Trial last-run record is invalid.");return 0;}
    tmp=(TopGearTimeTrialStore*)calloc(1,sizeof(*tmp));if(!tmp){set_error(error,cap,"Out of memory loading Time Trial data.");return 0;}
    gears=h.version==6?2:1;records=(const TopGearTimeTrialRun*)((const unsigned char*)data+32+168);
    for(track=0;track<32;track++)for(car=0;car<4;car++)for(g=0;g<gears;g++)for(rank=0;rank<5;rank++){
        const TopGearTimeTrialRun *r=records+(((track*4+car)*gears+g)*5+rank);
        if(!validate_run(r,1)||((r->valid_flags&1u)&&(r->course!=track||r->car_id!=car||(h.version==6&&r->gearbox!=g)))){free(tmp);set_error(error,cap,"Time Trial contains an invalid track/car/gearbox record.");return 0;}
        if(r->valid_flags&1u)insert_ranked(tmp,r);
        if(r->sequence>maxseq)maxseq=r->sequence;
    }
    /* Recover a genuine legacy last run that may not have fitted the combined Top 5. */
    if(h.version==5&&(last.valid_flags&1u))insert_ranked(tmp,&last);
    tmp->last_run=last;if(last.sequence>maxseq)maxseq=last.sequence;
    tmp->next_sequence=maxseq==UINT32_MAX?UINT32_MAX:maxseq+1u;tmp->dirty=h.version==5;
    *s=*tmp;free(tmp);set_error(error,cap,"");return 1;
}

int topgear_time_trial_store_insert(TopGearTimeTrialStore *store,
                                    const TopGearTimeTrialRun *run) {
    TopGearTimeTrialRun saved;
    if (!store || !validate_run(run, 0)) return 0;
    saved = *run;
    saved.sequence = store->next_sequence;
    if (store->next_sequence != UINT32_MAX) ++store->next_sequence;
    store->last_run = saved;
    insert_ranked(store,&saved);
    store->dirty = 1u;
    return 1;
}

int topgear_time_trial_store_last_run(const TopGearTimeTrialStore *store,
                                      TopGearTimeTrialRun *out) {
    if (!store || !out || (store->last_run.valid_flags & 1u) == 0u) return 0;
    *out = store->last_run;
    return 1;
}

int topgear_time_trial_store_car_record(const TopGearTimeTrialStore *store,
                                        unsigned track, unsigned car,
                                        unsigned rank,
                                        TopGearTimeTrialRun *out) {
    const TopGearTimeTrialRun *run;
    if (!store || !out || track >= TOPGEAR_TIME_TRIAL_TRACK_COUNT ||
        car >= TOPGEAR_TIME_TRIAL_CAR_COUNT ||
        rank >= TOPGEAR_TIME_TRIAL_RECORDS_PER_CAR) return 0;
    run = &store->records[track][car][rank];
    if ((run->valid_flags & 1u) == 0u) return 0;
    *out = *run;
    return 1;
}

int topgear_time_trial_store_overall_record(const TopGearTimeTrialStore *store,
                                            unsigned track, unsigned rank,
                                            TopGearTimeTrialRun *out) {
    TopGearTimeTrialRun merged[TOPGEAR_TIME_TRIAL_CAR_COUNT * TOPGEAR_TIME_TRIAL_RECORDS_PER_CAR];
    unsigned car, r, count = 0u, i, j;
    if (!store || !out || track >= TOPGEAR_TIME_TRIAL_TRACK_COUNT ||
        rank >= TOPGEAR_TIME_TRIAL_RECORDS_PER_CAR) return 0;
    for (car = 0u; car < TOPGEAR_TIME_TRIAL_CAR_COUNT; ++car)
        for (r = 0u; r < TOPGEAR_TIME_TRIAL_RECORDS_PER_CAR; ++r)
            if (store->records[track][car][r].valid_flags & 1u)
                merged[count++] = store->records[track][car][r];
    for (i = 1u; i < count; ++i) {
        TopGearTimeTrialRun key = merged[i];
        j = i;
        while (j > 0u && run_before(&key, &merged[j - 1u])) {
            merged[j] = merged[j - 1u];
            --j;
        }
        merged[j] = key;
    }
    if (rank >= count) return 0;
    *out = merged[rank];
    return 1;
}

int topgear_time_trial_store_provider(void *user, unsigned track,
                                      int car_filter, unsigned rank,
                                      TopGearTimeTrialRun *out) {
    TopGearTimeTrialStore *store = (TopGearTimeTrialStore *)user;
    if (car_filter < 0)
        return topgear_time_trial_store_overall_record(store, track, rank, out);
    return topgear_time_trial_store_car_record(store, track,
                                                (unsigned)car_filter, rank, out);
}

int topgear_time_trial_store_filtered_record(const TopGearTimeTrialStore *s,unsigned track,int car,int gearbox,unsigned rank,TopGearTimeTrialRun *out){
    TopGearTimeTrialRun list[40];unsigned c,g,r,n=0,i,j;
    if(!s||!out||track>=32||car< -1||car>=4||gearbox< -1||gearbox>1||rank>=5)return 0;
    for(c=0;c<4;c++)if(car<0||c==(unsigned)car)for(g=0;g<2;g++)if(gearbox<0||g==(unsigned)gearbox)for(r=0;r<5;r++)if(s->gear_records[track][c][g][r].valid_flags&1u)list[n++]=s->gear_records[track][c][g][r];
    for(i=1;i<n;i++){TopGearTimeTrialRun key=list[i];for(j=i;j&&run_before(&key,&list[j-1]);j--)list[j]=list[j-1];list[j]=key;}
    if(rank>=n)return 0;*out=list[rank];return 1;
}
int topgear_time_trial_store_dirty(const TopGearTimeTrialStore *store) {
    return store && store->dirty != 0u;
}

void topgear_time_trial_store_mark_clean(TopGearTimeTrialStore *store) {
    if (store) store->dirty = 0u;
}
