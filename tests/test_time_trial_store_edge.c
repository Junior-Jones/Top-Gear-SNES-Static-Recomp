#define main original_store_test_main
#include "test_time_trial_store.c"
#undef main
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL edge line %d: %s\n",__LINE__,#x);goto fail;}}while(0)
int main(void){
    TopGearTimeTrialStore *s=malloc(sizeof(*s)),*reload=malloc(sizeof(*reload)),*prior=malloc(sizeof(*prior));
    size_t bytes=topgear_time_trial_store_data_size();unsigned char *blob=malloc(bytes+1),*bad=malloc(bytes+1);
    TopGearTimeTrialRun a,b,out;unsigned n,t,c,g,k,mutations=0;char error[256];int ok=0;
    CHECK(s&&reload&&prior&&blob&&bad);
    topgear_time_trial_store_init(s);a=make_run(7,1,0,100,"FIRST   ");
    CHECK(topgear_time_trial_store_insert(s,&a));*prior=*s;
    for(n=0;n<14;n++){
        b=a;
        switch(n){
        case 0:b.course=32;break;case 1:b.car_id=4;break;case 2:b.gearbox=2;break;
        case 3:b.required_laps=0;break;case 4:b.required_laps=9;break;
        case 5:b.completed_laps=2;break;case 6:b.valid_flags=1;break;
        case 7:b.name[0]='a';break;case 8:b.total_time_ticks=0;break;
        case 9:b.total_time_ticks++;break;case 10:b.best_sector1_ticks++;break;
        case 11:b.lap_sector1_ticks[0]++;break;case 12:b.lap_time_ticks[7]=1;break;
        case 13:b.required_laps=b.completed_laps=8;b.total_time_ticks=0;
            b.best_sector1_ticks=b.best_sector2_ticks=b.best_sector3_ticks=0x20000000;
            for(k=0;k<8;k++){b.lap_time_ticks[k]=0x60000000;b.lap_sector1_ticks[k]=b.lap_sector2_ticks[k]=b.lap_sector3_ticks[k]=0x20000000;b.total_time_ticks+=b.lap_time_ticks[k];}break;
        }
        CHECK(!topgear_time_trial_store_insert(s,&b)&&!memcmp(s,prior,sizeof(*s)));mutations++;
    }
    CHECK(topgear_time_trial_store_export(s,blob,bytes));
    for(n=0;n<32;n++)CHECK(!topgear_time_trial_store_import(s,blob,n,error,sizeof(error))&&!memcmp(s,prior,sizeof(*s)));
    for(n=0;n<10;n++){
        size_t size=bytes;memcpy(bad,blob,bytes);bad[bytes]=0;
        if(n<6)bad[n==0?0:n==1?4:n==2?6:n==3?8:n==4?12:16]^=0x55;
        if(n==6)size=bytes-1;if(n==7)size=bytes+1;
        if(n==8)bad[32+64]^=1;if(n==9)bad[200+((7*4+1)*2)*5*168+10]=8;
        CHECK(!topgear_time_trial_store_import(s,bad,size,error,sizeof(error))&&!memcmp(s,prior,sizeof(*s)));mutations++;
    }
    /* Stable exact ties survive a reload, including saturated sequence IDs. */
    topgear_time_trial_store_init(s);s->next_sequence=UINT32_MAX-1u;
    for(n=0;n<3;n++){b=a;b.name[0]=(char)('A'+n);CHECK(topgear_time_trial_store_insert(s,&b));}
    CHECK(s->next_sequence==UINT32_MAX&&topgear_time_trial_store_export(s,blob,bytes));
    CHECK(topgear_time_trial_store_import(reload,blob,bytes,error,sizeof(error)));
    for(n=0;n<3;n++)CHECK(topgear_time_trial_store_car_record(reload,7,1,n,&out)&&out.name[0]=='A'+n);
    /* Fill every track/car/gearbox bank, then independently query all slots. */
    topgear_time_trial_store_init(s);
    for(t=0;t<32;t++)for(c=0;c<4;c++)for(g=0;g<2;g++)for(k=0;k<5;k++){
        b=make_run(t,c,g,100+g*100+k*10,"ALLSLOTS");CHECK(topgear_time_trial_store_insert(s,&b));
    }
    CHECK(topgear_time_trial_store_export(s,blob,bytes)&&topgear_time_trial_store_import(reload,blob,bytes,error,sizeof(error)));
    for(t=0;t<32;t++)for(c=0;c<4;c++)for(g=0;g<2;g++)for(k=0;k<5;k++)
        CHECK(topgear_time_trial_store_filtered_record(reload,t,(int)c,(int)g,k,&out)&&out.course==t&&out.car_id==c&&out.gearbox==g&&out.lap_time_ticks[0]==100+g*100+k*10);
    CHECK(!topgear_time_trial_store_filtered_record(reload,32,0,0,0,&out));
    CHECK(!topgear_time_trial_store_filtered_record(reload,0,4,0,0,&out));
    CHECK(!topgear_time_trial_store_filtered_record(reload,0,-2,0,0,&out));
    CHECK(!topgear_time_trial_store_filtered_record(reload,0,0,2,0,&out));
    CHECK(!topgear_time_trial_store_filtered_record(reload,0,0,0,5,&out));
    CHECK(!topgear_time_trial_store_insert(NULL,&a)&&!topgear_time_trial_store_insert(s,NULL));
    ok=1;printf("PASS timing edge cases: %u corrupt/invalid mutations, 32 short headers, unchanged store on failure, exact ties and sequence saturation, all 1280 track/car/gearbox records, invalid queries\n",mutations);
fail:free(s);free(reload);free(prior);free(blob);free(bad);return ok?0:1;
}
