#include "topgear_time_trial_store.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static TopGearTimeTrialRun make_run(unsigned track,unsigned car,unsigned gearbox,
                                    uint32_t lap_base,const char name[8]){
    TopGearTimeTrialRun r;
    unsigned lap;
    memset(&r,0,sizeof(r));
    memcpy(r.name,name,8u);
    r.course=(uint8_t)track;r.car_id=(uint8_t)car;r.gearbox=(uint8_t)gearbox;
    r.required_laps=3u;r.completed_laps=3u;
    r.valid_flags=TOPGEAR_TIME_TRIAL_RUN_VALID|TOPGEAR_TIME_TRIAL_RUN_COMPLETE;
    r.best_sector1_ticks=UINT32_MAX;r.best_sector2_ticks=UINT32_MAX;r.best_sector3_ticks=UINT32_MAX;
    for(lap=0u;lap<3u;lap++){
        uint32_t t=lap_base+lap*3u;
        uint32_t s1=20u+lap;
        uint32_t s2=30u+(2u-lap);
        uint32_t s3=t-s1-s2;
        r.lap_time_ticks[lap]=t;r.lap_sector1_ticks[lap]=s1;
        r.lap_sector2_ticks[lap]=s2;r.lap_sector3_ticks[lap]=s3;
        r.total_time_ticks+=t;
        if(s1<r.best_sector1_ticks)r.best_sector1_ticks=s1;
        if(s2<r.best_sector2_ticks)r.best_sector2_ticks=s2;
        if(s3<r.best_sector3_ticks)r.best_sector3_ticks=s3;
    }
    return r;
}

static int same_run(const TopGearTimeTrialRun *a,const TopGearTimeTrialRun *b){
    TopGearTimeTrialRun ac=*a,bc=*b;
    ac.sequence=0u;bc.sequence=0u;
    return memcmp(&ac,&bc,sizeof(ac))==0;
}

int main(void){
    TopGearTimeTrialStore s,reloaded;
    TopGearTimeTrialRun r[4],out,slow,fast;
    unsigned char *blob=NULL,*bad=NULL;
    size_t bytes=topgear_time_trial_store_data_size();
    char error[256];
    unsigned car;
    int ok=1;

    if(bytes!=TOPGEAR_TT_STORE_FILE_SIZE||bytes!=215240u){
        fprintf(stderr,"TGTT v6 byte size is not exactly 215240\n");return 1;
    }
    topgear_time_trial_store_init(&s);
    for(car=0u;car<4u;car++){
        static const char names[4][8]={{'C','A','R','0',' ',' ',' ',' '},{'C','A','R','1',' ',' ',' ',' '},
                                       {'C','A','R','2',' ',' ',' ',' '},{'C','A','R','3',' ',' ',' ',' '}};
        r[car]=make_run(7u,car,car&1u,100u+car*20u,names[car]);
        if(!topgear_time_trial_store_insert(&s,&r[car])){fprintf(stderr,"insert car %u failed\n",car);ok=0;}
    }
    for(car=0u;car<4u;car++){
        if(!topgear_time_trial_store_car_record(&s,7u,car,0u,&out)||out.car_id!=car||out.course!=7u||
           !same_run(&out,&r[car])){
            fprintf(stderr,"[track 7][car %u] placement failed\n",car);ok=0;
        }
        if(topgear_time_trial_store_car_record(&s,6u,car,0u,&out)){
            fprintf(stderr,"record leaked to wrong track for car %u\n",car);ok=0;
        }
    }
    /* Overall is computed from the four canonical car tables and is not a
       fifth persistent collection. */
    for(car=0u;car<4u;car++){
        if(!topgear_time_trial_store_overall_record(&s,7u,car,&out)||out.car_id!=car){
            fprintf(stderr,"derived Overall ordering failed at rank %u\n",car+1u);ok=0;
        }
    }

    /* Fill car 0's table, then submit a run too slow for its Top 5.  The
       historical table stays unchanged while last_run must still update. */
    for(car=1u;car<5u;car++){
        TopGearTimeTrialRun extra=make_run(7u,0u,0u,100u+car*2u,"EXTRA   ");
        if(!topgear_time_trial_store_insert(&s,&extra)){fprintf(stderr,"Top-5 fill insert failed\n");ok=0;}
    }
    if(!topgear_time_trial_store_car_record(&s,7u,0u,4u,&out)){
        fprintf(stderr,"car 0 did not reach five historical records\n");ok=0;
    }
    slow=make_run(7u,0u,1u,1000u,"SLOWRUN ");
    if(!topgear_time_trial_store_insert(&s,&slow)||
       !topgear_time_trial_store_last_run(&s,&out)||!same_run(&out,&slow)){
        fprintf(stderr,"non-qualifying run did not persist as last_run\n");ok=0;
    }
    if(topgear_time_trial_store_car_record(&s,7u,0u,4u,&out)&&same_run(&out,&slow)){
        fprintf(stderr,"non-qualifying run incorrectly entered Top 5\n");ok=0;
    }
    /* A faster sixth qualifying run must enter at rank 1 and evict the old
       fifth-place time from the full table. */
    fast=make_run(7u,0u,0u,90u,"FASTRUN ");
    if(!topgear_time_trial_store_insert(&s,&fast)||
       !topgear_time_trial_store_car_record(&s,7u,0u,0u,&out)||!same_run(&out,&fast)||
       !topgear_time_trial_store_car_record(&s,7u,0u,4u,&out)||out.lap_time_ticks[0]!=106u){
        fprintf(stderr,"faster sixth run did not replace the old slowest Top-5 record\n");ok=0;
    }

    blob=(unsigned char*)malloc(bytes);bad=(unsigned char*)malloc(bytes);
    if(!blob||!bad||!topgear_time_trial_store_export(&s,blob,bytes)){
        fprintf(stderr,"TGTT v6 export failed\n");ok=0;
    }else{
        topgear_time_trial_store_init(&reloaded);
        if(!topgear_time_trial_store_import(&reloaded,blob,bytes,error,sizeof(error))){
            fprintf(stderr,"TGTT v6 reload failed: %s\n",error);ok=0;
        }else{
            if(!topgear_time_trial_store_last_run(&reloaded,&out)||!same_run(&out,&fast)){
                fprintf(stderr,"last_run changed across physical-format reload\n");ok=0;
            }
            for(car=0u;car<4u;car++){
                if(!topgear_time_trial_store_car_record(&reloaded,7u,car,0u,&out)||out.course!=7u||out.car_id!=car){
                    fprintf(stderr,"track/car table changed across reload: car %u\n",car);ok=0;
                }
            }
            if(topgear_time_trial_store_dirty(&reloaded)){
                fprintf(stderr,"clean reload unexpectedly dirty\n");ok=0;
            }
        }
        memcpy(bad,blob,bytes);bad[0]^=0x55u;
        if(topgear_time_trial_store_import(&reloaded,bad,bytes,error,sizeof(error))){
            fprintf(stderr,"corrupt TGTT magic accepted\n");ok=0;
        }
    }

    /* Prototype v1/v2 files are recognized only for semantic reset.  They
       cannot be relabelled as truthful per-car/best-sector v5 history. */
    {
        unsigned char legacy[8]={0};uint32_t magic=TOPGEAR_TT_STORE_MAGIC;uint16_t version=2u;
        memcpy(legacy,&magic,4u);memcpy(legacy+4u,&version,2u);
        topgear_time_trial_store_init(&reloaded);
        if(!topgear_time_trial_store_import(&reloaded,legacy,sizeof(legacy),error,sizeof(error))||
           !topgear_time_trial_store_dirty(&reloaded)||topgear_time_trial_store_last_run(&reloaded,&out)){
            fprintf(stderr,"legacy semantic-reset migration failed\n");ok=0;
        }
    }

    /* Auto results must never evict the five fastest Manual results. */
    topgear_time_trial_store_init(&s);
    for(unsigned gear=0;gear<2;gear++)for(unsigned k=0;k<7;k++){
        TopGearTimeTrialRun candidate=make_run(0,0,gear,100u+gear*100u+k*10u,"GEARTEST");
        if(!topgear_time_trial_store_insert(&s,&candidate))ok=0;
    }
    for(unsigned gear=0;gear<2;gear++)for(unsigned k=0;k<5;k++){
        if(!topgear_time_trial_store_filtered_record(&s,0,0,(int)gear,k,&out)||out.gearbox!=gear||out.lap_time_ticks[0]!=100u+gear*100u+k*10u)ok=0;
    }
    if(!topgear_time_trial_store_export(&s,blob,bytes)||!topgear_time_trial_store_import(&reloaded,blob,bytes,error,sizeof(error))||!topgear_time_trial_store_filtered_record(&reloaded,0,0,1,4,&out)||out.lap_time_ticks[0]!=240u)ok=0;
    {
        unsigned char *legacy=(unsigned char*)calloc(1,107720u);uint32_t fields[8]={TOPGEAR_TT_STORE_MAGIC,5u|(168u<<16),32,4,5,32,1,0};
        memcpy(legacy,fields,32);memcpy(legacy+32,&s.last_run,168);memcpy(legacy+200,s.records,sizeof(s.records));
        if(!topgear_time_trial_store_import(&reloaded,legacy,107720u,error,sizeof(error))||!reloaded.dirty||!topgear_time_trial_store_filtered_record(&reloaded,0,0,1,0,&out)||out.lap_time_ticks[0]!=260u)ok=0;
        /* Genuine v5 combined entries remain unchanged; only genuine last_run is recovered. */
        for(unsigned k=0;k<5;k++)if(!topgear_time_trial_store_car_record(&reloaded,0,0,k,&out)||memcmp(&out,&s.records[0][0][k],sizeof(out)))ok=0;
        free(legacy);
    }
    free(blob);free(bad);
    if(!ok)return 1;
    puts("time trial store PASS: 215240-byte TGTT v6, exact track/car ownership, derived Overall, durable non-Top-5 last run, export/reload, safe legacy reset");
    return 0;
}
