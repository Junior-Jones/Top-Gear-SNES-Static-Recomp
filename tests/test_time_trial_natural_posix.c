#include "topgear_internal.h"
#include "topgear_time_trial_store.h"

#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FRAME_BYTES (256u * 224u * 2u)
#define P1_PLACE_OFFSET 0x011Au
#define P1_LAP_OFFSET 0x011Eu
#define P1_SPEED_OFFSET 0x1E5Au
#define COURSE_LENGTH_OFFSET 0x0200u
#define P1_COURSE_POS_OFFSET 0x0202u
#define COURSE_WORD_OFFSET 0x1F06u
#define P1_GEAR_LO_OFFSET 0x1F7Au
#define P1_GEAR_HI_OFFSET 0x1F7Cu
#define P1_CAR_OFFSET 0x1F8Fu

#define TG_BTN_START UINT16_C(0x1000)
#define TG_BTN_DOWN UINT16_C(0x0400)
#define TG_BTN_UP UINT16_C(0x0800)
#define TG_BTN_LEFT UINT16_C(0x0200)
#define TG_BTN_RIGHT UINT16_C(0x0100)
#define TG_BTN_A UINT16_C(0x0080)
#define TG_BTN_X UINT16_C(0x0040)
#define TG_BTN_R UINT16_C(0x0010)

static const char *const track_names[32] = {
    "LAS VEGAS","LOS ANGELES","NEW YORK","SAN FRANCISCO",
    "RIO","MACHU PICCHU","CHICHEN ITZA","RAIN FOREST",
    "TOKYO","HIROSHIMA","YOKOHAMA","KYOTO",
    "MUNICH","COLOGNE","BLACK FOREST","FRANKFURT",
    "STOCKHOLM","COPENHAGEN","HELSINKI","OSLO",
    "PARIS","NICE","BORDEAUX","MONACO",
    "PISA","ROME","SICILY","FLORENCE",
    "LONDON","SHEFFIELD","LOCH NESS","STONEHENGE"
};
static const unsigned track_laps[32] = {
    3u,3u,3u,6u,6u,4u,6u,3u,7u,5u,3u,6u,7u,3u,6u,8u,
    3u,3u,3u,3u,3u,7u,6u,3u,3u,6u,3u,3u,8u,3u,3u,4u
};
static const char *const car_names[4] = {"CANNIBAL","SIDEWINDER","RAZOR","WEASEL"};

typedef struct Driver {
    int steer;
    int avoid_direction;
    unsigned avoid_frames;
    unsigned missing_road_frames;
    unsigned traffic_frames;
    unsigned boost_frames;
    unsigned boost_count;
    unsigned boost_used_lap[8];
    unsigned lap_straight_frames;
    unsigned prior_lap;
    uint32_t race_frame;
    unsigned shift_count;
    int shift_speed[2];
} Driver;

typedef struct MenuNav {
    unsigned phase;
    uint8_t source_page;
    uint8_t source_selection;
    uint16_t held_mask;
    unsigned release_frames;
    unsigned held_frames;
} MenuNav;

static int load_file(const char *path, uint8_t **data, size_t *size) {
    FILE *file = fopen(path, "rb");
    long length;
    *data = NULL; *size = 0u;
    if (!file) return 0;
    if (fseek(file, 0, SEEK_END) != 0 || (length = ftell(file)) < 0 ||
        fseek(file, 0, SEEK_SET) != 0) { fclose(file); return 0; }
    *data = (uint8_t *)malloc((size_t)length);
    if (!*data || fread(*data, 1u, (size_t)length, file) != (size_t)length) {
        free(*data); *data = NULL; fclose(file); return 0;
    }
    if (fclose(file) != 0) { free(*data); *data = NULL; return 0; }
    *size = (size_t)length;
    return 1;
}

static int ensure_directory(const char *path) {
    struct stat st;
    if (stat(path, &st) == 0) return S_ISDIR(st.st_mode);
    return mkdir(path, 0777) == 0 || errno == EEXIST;
}

static int ensure_parent_directory(const char *path) {
    char copy[4096]; char *slash;
    if (!path || strlen(path) >= sizeof(copy)) return 0;
    (void)strcpy(copy, path);
    slash = strrchr(copy, '/');
    if (!slash) return 1;
    *slash = '\0';
    if (!copy[0]) return 1;
    return ensure_directory(copy);
}

static uint16_t read_le16(const uint8_t *data, unsigned offset) {
    return (uint16_t)(data[offset] | ((uint16_t)data[offset + 1u] << 8u));
}

static void format_time(uint32_t units, char out[16]) {
    uint32_t seconds = units / 60u;
    uint32_t remainder = units % 60u;
    uint32_t milliseconds = (remainder * 1000u + 30u) / 60u;
    uint32_t minutes;
    if (milliseconds >= 1000u) { milliseconds = 0u; ++seconds; }
    minutes = seconds / 60u;
    (void)snprintf(out, 16u, "%u:%02u.%03u", (unsigned)minutes,
                   (unsigned)(seconds % 60u), (unsigned)milliseconds);
}

static void format_sector(uint32_t units, char out[16]) {
    uint32_t milliseconds = (units * 1000u + 30u) / 60u;
    (void)snprintf(out, 16u, "%u.%03u", (unsigned)(milliseconds / 1000u),
                   (unsigned)(milliseconds % 1000u));
}

static int write_ppm(TopGearRecomp *core, const char *path) {
    uint8_t frame[FRAME_BYTES]; FILE *file; unsigned x,y;
    if (!topgear_recomp_v22_read_frame_bgr555(core, 0u, frame, sizeof(frame))) return 0;
    file = fopen(path, "wb"); if (!file) return 0;
    (void)fprintf(file, "P6\n256 224\n255\n");
    for (y=0u;y<224u;++y) for (x=0u;x<256u;++x) {
        size_t p=((size_t)y*256u+x)*2u;
        uint16_t c=(uint16_t)(frame[p]|((uint16_t)frame[p+1u]<<8u));
        uint8_t rgb[3]={(uint8_t)((c&31u)*255u/31u),
                        (uint8_t)(((c>>5u)&31u)*255u/31u),
                        (uint8_t)(((c>>10u)&31u)*255u/31u)};
        if (fwrite(rgb,1u,sizeof(rgb),file)!=sizeof(rgb)){fclose(file);return 0;}
    }
    return fclose(file)==0;
}

static int road_center(const uint8_t *frame, int *samples,
                       unsigned row_first,unsigned row_last) {
    unsigned x,y; int64_t weighted_x=0,total=0; int count=0;
    for(y=row_first;y<=row_last;y+=2u){
        int weight=1+(int)(y-row_first)/10;
        for(x=0u;x<238u;++x){
            size_t o=((size_t)y*256u+x)*2u;
            uint16_t c=(uint16_t)(frame[o]|((uint16_t)frame[o+1u]<<8u));
            int r=c&31u,g=(c>>5u)&31u,b=(c>>10u)&31u;
            int low=r<g?(r<b?r:b):(g<b?g:b);
            int high=r>g?(r>b?r:b):(g>b?g:b);
            if(r>=5&&r<=14&&g>=5&&g<=15&&b>=5&&b<=15&&high-low<=4){
                weighted_x+=(int64_t)x*weight; total+=weight; ++count;
            }
        }
    }
    *samples=count;
    return total?(int)(weighted_x/total):-1;
}

static int traffic_ahead(TopGearRecomp *core, int *traffic_x) {
    uint8_t oam[544]; unsigned index,found=0u; int x_total=0;
    *traffic_x=124;
    if(!topgear_recomp_v07_read_oam(core,0u,oam,sizeof(oam)))return -1;
    for(index=0u;index<128u;++index){
        unsigned high=oam[512u+index/4u],shift=(index%4u)*2u;
        int x=(int)oam[index*4u]+(int)(((high>>shift)&1u)*256u);
        int y=(int)oam[index*4u+1u];
        int half_width=((high>>(shift+1u))&1u)?8:4;
        int center;
        if(index>=3u&&index<=14u)continue;
        if(x>=256)x-=512;
        center=x+half_width;
        if(y>=34&&y<=70&&center>=92&&center<=156){x_total+=center;++found;}
    }
    if(found)*traffic_x=x_total/(int)found;
    return found!=0u;
}

static uint16_t driver_input(TopGearRecomp *core, Driver *d,
                             const uint8_t *wram, const uint8_t *frame,
                             int manual) {
    unsigned local=(unsigned)(core->mod_time_trial_selected_course&3u);
    unsigned row_first=local==2u?55u:40u;
    unsigned row_last=local==2u?90u:70u;
    int low_threshold=local==2u?108:119;
    int high_threshold=local==2u?148:137;
    int samples=0,center=road_center(frame,&samples,row_first,row_last),traffic_x=124;
    int traffic=0; unsigned lap=wram[P1_LAP_OFFSET];
    int raw_speed=(int)(int16_t)read_le16(wram,P1_SPEED_OFFSET);
    uint16_t mask=TG_BTN_X;
    if(center>=0&&samples>=24){
        if(center<low_threshold)d->steer=-1; else if(center>high_threshold)d->steer=1; else d->steer=0;
        d->missing_road_frames=0u;
    }else{
        ++d->missing_road_frames;
        if((d->missing_road_frames%120u)==0u)d->steer=-d->steer;
        if(!d->steer)d->steer=((d->missing_road_frames/120u)&1u)?1:-1;
    }
    /* Reuse the mature eight-race driver policy: OAM traffic avoidance is
       reliable for local track slots 0/1, while slots 2/3 can expose scenery
       sprites in the same OAM region and must not be treated as traffic. */
    if(local<2u)traffic=traffic_ahead(core,&traffic_x);
    if(traffic>0){
        ++d->traffic_frames;
        if(!d->avoid_frames){d->avoid_direction=traffic_x<124?1:-1;d->avoid_frames=18u;}
        else if(d->avoid_frames<8u)d->avoid_frames=8u;
    }
    if(d->avoid_frames){
        if(center>=0&&center<108)d->steer=-1;
        else if(center>148)d->steer=1;
        else d->steer=d->avoid_direction;
        --d->avoid_frames;
    }
    if(d->steer<0)mask=(uint16_t)(mask|TG_BTN_LEFT);
    if(d->steer>0)mask=(uint16_t)(mask|TG_BTN_RIGHT);
    if(lap!=d->prior_lap){d->prior_lap=lap;d->lap_straight_frames=0u;}
    if(local==0u||local==2u||local==3u){
        static const unsigned short_windows[3]={1488u,2378u,2995u};
        static const unsigned slot2_windows[3]={1500u,4500u,7500u};
        const unsigned *windows=local==2u?slot2_windows:short_windows;
        if(!d->boost_frames&&d->boost_count<3u&&
           d->race_frame>=windows[d->boost_count]&&traffic<=0){
            d->boost_used_lap[d->boost_count]=lap+1u;
            ++d->boost_count;d->boost_frames=12u;
        }
    }else if(d->boost_count<3u&&lap<3u){
        if(center>=118&&center<=132&&samples>=500&&traffic<=0&&!d->avoid_frames)
            ++d->lap_straight_frames;
        else d->lap_straight_frames=0u;
        if(!d->boost_frames&&!d->boost_used_lap[lap]&&d->race_frame>=480u&&
           d->lap_straight_frames>=12u){
            d->boost_used_lap[lap]=lap+1u;
            ++d->boost_count;d->boost_frames=12u;
        }
    }
    if(d->boost_frames){mask=(uint16_t)(mask|TG_BTN_A);--d->boost_frames;}
    /* Real MANUAL controller input only.  The preserved live engine route has
       the 1->2 and 2->3 shifts at these race-driver frames. */
    if(manual&&(d->race_frame==64u||d->race_frame==243u)){
        if(d->shift_count<2u)d->shift_speed[d->shift_count]=raw_speed;
        ++d->shift_count;
        mask=(uint16_t)(mask|TG_BTN_R);
    }
    ++d->race_frame;
    return mask;
}

static uint16_t fixed_setup_input(unsigned frame, unsigned car, int manual) {
    if(frame>=1560u&&frame<1680u)return TG_BTN_START;
    if(frame>=1920u&&frame<1935u)return TG_BTN_DOWN;
    if(frame>=1965u&&frame<1980u)return TG_BTN_DOWN;
    if(frame>=2010u&&frame<2040u)return TG_BTN_A;
    if(frame>=2070u&&frame<2130u)return TG_BTN_A;
    if((frame>=2280u&&frame<2295u)||(frame>=2310u&&frame<2325u)||
       (frame>=2340u&&frame<2355u)||(frame>=2370u&&frame<2385u))return TG_BTN_DOWN;
    if((frame>=2400u&&frame<2415u)||(frame>=2430u&&frame<2445u)||
       (frame>=2460u&&frame<2475u)||(frame>=2490u&&frame<2505u))return TG_BTN_RIGHT;
    if(frame>=2550u&&frame<2595u)return TG_BTN_A;
    if(!manual&&frame>=2850u&&frame<2865u)return TG_BTN_RIGHT;
    if(frame>=2910u&&frame<2970u)return TG_BTN_A;
    if(frame>=3270u&&frame<3330u)return TG_BTN_A;
    if(car==3u&&frame>=3480u&&frame<3495u)return TG_BTN_DOWN;
    if(frame>=3540u&&frame<3555u){
        if(car==1u||car==3u)return TG_BTN_RIGHT;
        if(car==2u)return TG_BTN_DOWN;
    }
    if(frame>=3630u&&frame<3690u)return TG_BTN_A;
    return 0u;
}

static uint16_t nav_action(MenuNav *nav, TopGearRecomp *core,
                           unsigned target_course) {
    uint8_t page=core->mod_menu_remodel_page;
    uint8_t selection=core->mod_menu_remodel_selection;
    unsigned target_country=target_course/4u,target_track=target_course%4u;
    uint16_t action=0u;
    if(nav->held_mask){
        if(page!=nav->source_page||selection!=nav->source_selection||nav->held_frames>=30u){
            nav->held_mask=0u;nav->held_frames=0u;nav->release_frames=8u;return 0u;
        }
        ++nav->held_frames;return nav->held_mask;
    }
    if(nav->release_frames){--nav->release_frames;return 0u;}
    if(!core->mod_menu_remodel_active)return 0u;
    if(nav->phase==0u){
        if(page!=3u)return 0u;
        if(selection<1u)action=TG_BTN_DOWN;
        else if(selection>1u)action=TG_BTN_UP;
        else {action=TG_BTN_A;nav->phase=1u;}
    }else if(nav->phase==1u){
        if(page==4u){
            if(selection<target_country)action=TG_BTN_DOWN;
            else if(selection>target_country)action=TG_BTN_UP;
            else action=TG_BTN_A;
        }else if(page==5u){
            if(selection<target_track)action=TG_BTN_DOWN;
            else if(selection>target_track)action=TG_BTN_UP;
            else {action=TG_BTN_A;nav->phase=2u;}
        }
    }else if(nav->phase==2u){
        if(page!=3u)return 0u;
        if(selection<3u)action=TG_BTN_DOWN;
        else if(selection>3u)action=TG_BTN_UP;
        else {action=TG_BTN_A;nav->phase=3u;}
    }
    if(action){
        nav->source_page=page;nav->source_selection=selection;
        nav->held_mask=action;nav->held_frames=1u;
    }
    return action;
}

static int run_equal(const TopGearTimeTrialRun *a,const TopGearTimeTrialRun *b) {
    TopGearTimeTrialRun aa,bb;
    if(!a||!b)return 0;
    aa=*a;bb=*b;aa.sequence=0u;bb.sequence=0u;
    return memcmp(&aa,&bb,sizeof(aa))==0;
}

static int save_store_atomic(const TopGearTimeTrialStore *store,const char *path) {
    size_t bytes=topgear_time_trial_store_data_size();
    uint8_t *blob=(uint8_t *)malloc(bytes);char tmp[4096];FILE *file=NULL;int fd,ok=0;
    if(!blob||!path||!ensure_parent_directory(path))goto done;
    if(!topgear_time_trial_store_export(store,blob,bytes))goto done;
    if(snprintf(tmp,sizeof(tmp),"%s.tmp-%ld",path,(long)getpid())<0)goto done;
    file=fopen(tmp,"wb");if(!file)goto done;
    if(fwrite(blob,1u,bytes,file)!=bytes||fflush(file)!=0)goto close_fail;
    fd=fileno(file);if(fd<0||fsync(fd)!=0)goto close_fail;
    if(fclose(file)!=0){file=NULL;goto done;} file=NULL;
    if(rename(tmp,path)!=0)goto done;
    ok=1;goto done;
close_fail:
    if(file){(void)fclose(file);file=NULL;}(void)unlink(tmp);
done:
    free(blob);return ok;
}

static int verify_saved_file(const char *path,const TopGearTimeTrialRun *expected,
                             unsigned *rank_out,char *error,size_t cap) {
    uint8_t *bytes=NULL;size_t size=0u;TopGearTimeTrialStore reload;
    TopGearTimeTrialRun last,ranked;unsigned rank;char import_error[256];
    if(rank_out)*rank_out=99u;
    if(!load_file(path,&bytes,&size)){snprintf(error,cap,"Data file could not be reopened");return 0;}
    if(size!=TOPGEAR_TT_STORE_FILE_SIZE){snprintf(error,cap,"Data file size %zu != %u",size,TOPGEAR_TT_STORE_FILE_SIZE);free(bytes);return 0;}
    topgear_time_trial_store_init(&reload);memset(import_error,0,sizeof(import_error));
    if(!topgear_time_trial_store_import(&reload,bytes,size,import_error,sizeof(import_error))){
        snprintf(error,cap,"Data reload failed: %s",import_error);free(bytes);return 0;
    }
    free(bytes);memset(&last,0,sizeof(last));
    if(!topgear_time_trial_store_last_run(&reload,&last)||!run_equal(&last,expected)){
        snprintf(error,cap,"last-run block does not match completed race");return 0;
    }
    for(rank=0u;rank<TOPGEAR_TIME_TRIAL_RECORDS_PER_CAR;++rank){
        memset(&ranked,0,sizeof(ranked));
        if(topgear_time_trial_store_car_record(&reload,expected->course,expected->car_id,rank,&ranked)&&
           run_equal(&ranked,expected)){if(rank_out)*rank_out=rank;error[0]='\0';return 1;}
    }
    snprintf(error,cap,"completed race missing from exact Data[%u][%u] car table",
             (unsigned)expected->course,(unsigned)expected->car_id);
    return 0;
}

static int write_text_report(const char *dir,const TopGearTimeTrialRun *run,
                             unsigned rank,unsigned data_size,const Driver *driver) {
    char path[4096],total[16],b1[16],b2[16],b3[16];FILE *f;unsigned lap;
    snprintf(path,sizeof(path),"%s/result.txt",dir);f=fopen(path,"wb");if(!f)return 0;
    format_time(run->total_time_ticks,total);format_sector(run->best_sector1_ticks,b1);
    format_sector(run->best_sector2_ticks,b2);format_sector(run->best_sector3_ticks,b3);
    fprintf(f,"Track: %s\nCar: %s\nGearbox: %s\nLaps: %u\nFinal time: %s\nBest S1: %s s\nBest S2: %s s\nBest S3: %s s\nData slot: track=%u car=%u rank=%u\nData bytes: %u\n",
            track_names[run->course],car_names[run->car_id],run->gearbox?"MANUAL":"AUTO",
            (unsigned)run->required_laps,total,b1,b2,b3,(unsigned)run->course,
            (unsigned)run->car_id,rank+1u,data_size);
    for(lap=0u;lap<run->completed_laps;++lap){char lt[16],s1[16],s2[16],s3[16];
        format_time(run->lap_time_ticks[lap],lt);format_sector(run->lap_sector1_ticks[lap],s1);
        format_sector(run->lap_sector2_ticks[lap],s2);format_sector(run->lap_sector3_ticks[lap],s3);
        fprintf(f,"L%u: %s | S1 %s s | S2 %s s | S3 %s s\n",lap+1u,lt,s1,s2,s3);
    }
    if(run->gearbox)fprintf(f,"Manual R shifts: %u; raw speeds at shifts: %d, %d\n",
                            driver->shift_count,driver->shift_speed[0],driver->shift_speed[1]);
    return fclose(f)==0;
}

int main(int argc,char **argv) {
    uint8_t *rom=NULL,*existing=NULL;size_t rom_size=0u,existing_size=0u;
    TopGearRecomp *core=NULL;TopGearTimeTrialStore store;TopGearRecompFrameResult advance;
    TopGearTimeTrialRun completed;Driver driver;MenuNav nav;uint8_t wram[TOPGEAR_RECOMP_WRAM_SIZE],frame[FRAME_BYTES];
    unsigned course,car,expected_laps,frame_number,last_lap=0u,results_frame=0u,data_rank=99u;
    int manual,results_phase=0,setup_verified=0,data_committed=0,detail_captured=0,top5_captured=0;
    unsigned detail_ready_frames=0u,top5_ready_frames=0u;
    int detail_continue_sent=0,top5_continue_sent=0,returned_country=0;uint64_t prior_hash=0u;unsigned stable_frames=0u;
    char error[256],path[4096],total[16],best1[16],best2[16],best3[16];

    if(argc!=7){fprintf(stderr,"usage: %s ROM OUTPUT_DIR DATA_FILE COURSE CAR GEARBOX(auto|manual)\n",argv[0]);return 2;}
    course=(unsigned)strtoul(argv[4],NULL,10);car=(unsigned)strtoul(argv[5],NULL,10);
    manual=strcmp(argv[6],"manual")==0;
    if(course>=32u||car>=4u||(strcmp(argv[6],"auto")!=0&&!manual)){fprintf(stderr,"invalid scenario\n");return 2;}
    expected_laps=track_laps[course];
    if(!load_file(argv[1],&rom,&rom_size)||!ensure_directory(argv[2]))return 2;
    if(!topgear_recomp_create(&core,rom,rom_size,error,sizeof(error))){fprintf(stderr,"create failed: %s\n",error);free(rom);return 1;}free(rom);
    topgear_time_trial_store_init(&store);
    if(load_file(argv[3],&existing,&existing_size)){
        if(!topgear_time_trial_store_import(&store,existing,existing_size,error,sizeof(error))){fprintf(stderr,"existing Data import failed: %s\n",error);free(existing);topgear_recomp_destroy(core);return 1;}
        free(existing);
    }
    topgear_recomp_time_trial_set_leaderboard_provider(core,topgear_time_trial_store_provider,&store);
    memset(&driver,0,sizeof(driver));memset(&nav,0,sizeof(nav));memset(&completed,0,sizeof(completed));

    for(frame_number=0u;frame_number<65000u;++frame_number){
        uint16_t input=0u;uint64_t hash;unsigned current_lap;
        if(frame_number<3750u)input=fixed_setup_input(frame_number,car,manual);
        else if(nav.phase<3u&&!results_phase&&!core->mod_time_trial_active)input=nav_action(&nav,core,course);
        else if(detail_captured&&!detail_continue_sent){input=TG_BTN_A;detail_continue_sent=1;}
        else if(top5_captured&&!top5_continue_sent){input=TG_BTN_A;top5_continue_sent=1;}
        else if(results_phase){
            if((results_frame>=120u&&results_frame<132u)||(results_frame>=600u&&results_frame<612u)||(results_frame>=1080u&&results_frame<1092u))input=TG_BTN_A;
            ++results_frame;
        }else if(core->mod_time_trial_active&&frame_number>=5649u){
            input=driver_input(core,&driver,wram,frame,manual);
        }
        if(!topgear_recomp_advance_headless(core,input,0u,1u,&advance)){
            fprintf(stderr,"advance failed frame=%u: %s\n",frame_number,topgear_recomp_last_error(core));topgear_recomp_destroy(core);return 1;
        }
        if(!topgear_recomp_read_wram(core,0u,wram,sizeof(wram))||!topgear_recomp_v22_read_frame_bgr555(core,0u,frame,sizeof(frame))){fprintf(stderr,"state read failed\n");topgear_recomp_destroy(core);return 1;}

        if(!setup_verified&&frame_number>=5650u&&core->mod_time_trial_active){
            unsigned actual_course=read_le16(wram,COURSE_WORD_OFFSET)&31u;
            unsigned actual_car=read_le16(wram,P1_CAR_OFFSET)&3u;
            int actual_manual=(read_le16(wram,P1_GEAR_LO_OFFSET)|read_le16(wram,P1_GEAR_HI_OFFSET))!=0u;
            if(actual_course!=course||actual_car!=car||actual_manual!=manual){
                fprintf(stderr,"SETUP FAIL expected course=%u car=%u gear=%s got course=%u car=%u gear=%s words=%04X/%04X page=%u sel=%u\n",
                        course,car,manual?"MANUAL":"AUTO",actual_course,actual_car,actual_manual?"MANUAL":"AUTO",
                        read_le16(wram,P1_GEAR_LO_OFFSET),read_le16(wram,P1_GEAR_HI_OFFSET),core->mod_menu_remodel_page,core->mod_menu_remodel_selection);
                topgear_recomp_destroy(core);return 1;
            }
            setup_verified=1;
            fprintf(stderr,"SETUP PASS track=%s course=%u car=%s gearbox=%s\n",track_names[course],course,car_names[car],manual?"MANUAL":"AUTO");
        }
        if(core->mod_time_trial_required_laps&&core->mod_time_trial_required_laps!=expected_laps){
            fprintf(stderr,"required laps mismatch: game=%u expected=%u\n",(unsigned)core->mod_time_trial_required_laps,expected_laps);topgear_recomp_destroy(core);return 1;
        }
        current_lap=(unsigned)wram[P1_LAP_OFFSET];
        if(current_lap!=last_lap){last_lap=current_lap;fprintf(stderr,"LAP EVENT %u frame=%u tt=%u\n",last_lap,frame_number,(unsigned)core->mod_time_trial_lap_count);}
        if(current_lap>=expected_laps&&core->mod_time_trial_active&&!results_phase){
            hash=UINT64_C(1469598103934665603);{
                size_t n;for(n=0u;n<sizeof(frame);++n){hash^=frame[n];hash*=UINT64_C(1099511628211);}
            }
            if(hash==prior_hash)++stable_frames;else stable_frames=0u;prior_hash=hash;
            if(stable_frames>=120u){results_phase=1;results_frame=0u;fprintf(stderr,"RESULTS STABLE frame=%u\n",frame_number);}
        }

        if(!data_committed&&topgear_recomp_time_trial_completed_run_pending(core)){
            TopGearTimeTrialRun staged;char verify_error[256];
            memset(&staged,0,sizeof(staged));
            if(!topgear_recomp_time_trial_completed_run(core,&staged)){fprintf(stderr,"completed handoff unavailable\n");topgear_recomp_destroy(core);return 1;}
            if(staged.course!=course||staged.car_id!=car||staged.gearbox!=(unsigned)manual||staged.required_laps!=expected_laps){fprintf(stderr,"completed handoff identity mismatch\n");topgear_recomp_destroy(core);return 1;}
            if(!topgear_time_trial_store_insert(&store,&staged)||!save_store_atomic(&store,argv[3])){fprintf(stderr,"atomic Data save failed\n");topgear_recomp_destroy(core);return 1;}
            if(!verify_saved_file(argv[3],&staged,&data_rank,verify_error,sizeof(verify_error))){fprintf(stderr,"Data verification failed: %s\n",verify_error);topgear_recomp_destroy(core);return 1;}
            if(!topgear_recomp_time_trial_commit_completed_run(core)){fprintf(stderr,"core completed-run commit failed\n");topgear_recomp_destroy(core);return 1;}
            topgear_time_trial_store_mark_clean(&store);completed=staged;data_committed=1;
            fprintf(stderr,"DATA VERIFIED bytes=%u exact-slot=[track %u][car %u] rank=%u\n",TOPGEAR_TT_STORE_FILE_SIZE,course,car,data_rank+1u);
        }

        if(data_committed&&!detail_captured&&core->mod_menu_remodel_active&&core->mod_menu_remodel_page==10u&&!core->mod_menu_remodel_dirty){
            /* Menu tile writes become visible in the rendered framebuffer on a
               later PPU frame.  Require several stable page frames so a file
               cannot be named "track-results" while still containing the
               previous OPTIONS frame. */
            if(++detail_ready_frames>=5u){
                snprintf(path,sizeof(path),"%s/track-results.ppm",argv[2]);
                if(!write_ppm(core,path)){fprintf(stderr,"track-results screenshot failed\n");topgear_recomp_destroy(core);return 1;}
                detail_captured=1;fprintf(stderr,"SCREENSHOT track-results.ppm after %u stable page frames\n",detail_ready_frames);
            }
        }else if(!detail_captured){
            detail_ready_frames=0u;
        }
        if(detail_continue_sent&&!top5_captured&&core->mod_menu_remodel_active&&core->mod_menu_remodel_page==11u&&!core->mod_menu_remodel_dirty){
            if(++top5_ready_frames>=5u){
                snprintf(path,sizeof(path),"%s/top-5-results.ppm",argv[2]);
                if(!write_ppm(core,path)){fprintf(stderr,"top-5 screenshot failed\n");topgear_recomp_destroy(core);return 1;}
                top5_captured=1;fprintf(stderr,"SCREENSHOT top-5-results.ppm after %u stable page frames\n",top5_ready_frames);
            }
        }else if(!top5_captured){
            top5_ready_frames=0u;
        }
        if(top5_continue_sent&&core->mod_menu_remodel_active&&core->mod_menu_remodel_page==3u&&core->mod_menu_remodel_selection==1u&&!core->mod_menu_remodel_dirty){returned_country=1;break;}
    }

    if(!setup_verified||!data_committed||!detail_captured||!top5_captured||!returned_country){
        fprintf(stderr,"SCENARIO INCOMPLETE frame=%u setup=%d data=%d detail=%d top5=%d country=%d page=%u sel=%u active=%u hasrun=%u laps=%u required=%u\n",
                frame_number,setup_verified,data_committed,detail_captured,top5_captured,returned_country,
                (unsigned)core->mod_menu_remodel_page,(unsigned)core->mod_menu_remodel_selection,
                (unsigned)core->mod_time_trial_active,(unsigned)core->mod_time_trial_has_run,
                (unsigned)core->mod_time_trial_lap_count,(unsigned)core->mod_time_trial_required_laps);
        topgear_recomp_destroy(core);return 1;
    }
    if(manual&&driver.shift_count<2u){fprintf(stderr,"manual run did not issue both real R shifts\n");topgear_recomp_destroy(core);return 1;}
    if(!write_text_report(argv[2],&completed,data_rank,TOPGEAR_TT_STORE_FILE_SIZE,&driver)){fprintf(stderr,"result report write failed\n");topgear_recomp_destroy(core);return 1;}
    format_time(completed.total_time_ticks,total);format_sector(completed.best_sector1_ticks,best1);
    format_sector(completed.best_sector2_ticks,best2);format_sector(completed.best_sector3_ticks,best3);
    printf("PASS track=%s laps=%u car=%s gearbox=%s final=%s bestS1=%ss bestS2=%ss bestS3=%ss Data=[%u][%u] rank=%u bytes=%u screenshots=track-results.ppm,top-5-results.ppm\n",
           track_names[course],expected_laps,car_names[car],manual?"MANUAL":"AUTO",total,best1,best2,best3,
           course,car,data_rank+1u,TOPGEAR_TT_STORE_FILE_SIZE);
    topgear_recomp_destroy(core);return 0;
}
