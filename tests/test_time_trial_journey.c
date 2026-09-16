#include "topgear_internal.h"
#include "topgear_time_trial_store.h"
#include "topgear_player_settings_file.h"

#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#ifdef _WIN32
#include <direct.h>
#include <io.h>
#include <process.h>
#include <windows.h>
#define getpid _getpid
#define fileno _fileno
#define fsync _commit
#define unlink _unlink
#else
#include <unistd.h>
#endif

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
#define TG_BTN_B UINT16_C(0x8000)
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
    unsigned stopped_frames;
    unsigned pit_seek_frames;
    unsigned shift_count;
    unsigned shift_hold,shift_release,shift_gear;
    uint16_t shift_button;
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
    if (stat(path, &st) == 0){
#ifdef _WIN32
        return (st.st_mode & _S_IFDIR)!=0;
#else
        return S_ISDIR(st.st_mode);
#endif
    }
    #ifdef _WIN32
    return _mkdir(path)==0||errno==EEXIST;
#else
    return mkdir(path,0777)==0||errno==EEXIST;
#endif
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
    int traffic=0,seeking_pit=0; unsigned lap=wram[P1_LAP_OFFSET];
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
    /* Read native roadside objects, never invent a pit location. D760-D7C0
       identifies type $74, with bit $100 selecting the left entrance.
       Approach on real steering controls before fuel becomes critical. */
    {
        unsigned fuel=read_le16(wram,0x1E62u),length=read_le16(wram,0x0200u);
        unsigned pit=read_le16(wram,0x1E86u),position=read_le16(wram,0x1ED7u),p;
        if(!pit&&length&&((fuel<0x7000u&&core->mod_time_trial_lap_count+1u<core->mod_time_trial_required_laps)||fuel<0x3000u)){
            position%=length;
            for(p=0u;p<length;p+=32u){
                unsigned obj=read_le16(wram,0x6400u+p/16u);
                if((obj&0xFE00u)==0x7400u&&(p+length-position)%length<4096u){
                    d->steer=(obj&0x100u)?-1:1;d->avoid_frames=0u;
                    d->pit_seek_frames++;seeking_pit=1;break;
                }
            }
        }
    }
    /* Use the engine's lateral coordinate as steering authority. Several
       courses have coloured road surfaces, so grey pixel sampling alone
       can aim at roadside signs and pin the car against them. OAM traffic
       can request a modest lane offset, well inside roadside obstacles. */
    if(!seeking_pit&&!read_le16(wram,0x1E86u)){
        int lateral=(int)(int16_t)read_le16(wram,0x1E8Au);
        int target=d->avoid_frames?d->avoid_direction*4000:0;
        d->steer=lateral<target-1000?1:lateral>target+1000?-1:0;
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
    /* Read the native five-gear index and per-car speed thresholds
       ($05:D391-D3AB). Operate real controls with a held pulse and release;
       a single video-frame tap can fall between game input polls. */
    if(manual){
        unsigned gear=read_le16(wram,0x1E72u),index=read_le16(wram,0x1EE8u)+gear*2u;
        uint16_t lower=0u,upper=65535u;
        (void)tg_bus_read16(core,0x0099DBu+index,&lower);
        (void)tg_bus_read16(core,0x009A15u+index,&upper);
        if(d->shift_hold){
            if(gear!=d->shift_gear){d->shift_hold=0u;d->shift_release=12u;}
            else {mask|=d->shift_button;if(!--d->shift_hold)d->shift_release=12u;}
        }else if(d->shift_release)d->shift_release--;
        else if((gear<4u&&raw_speed>=upper)||(gear>0u&&raw_speed>=0&&raw_speed<lower)){
            d->shift_button=(gear<4u&&raw_speed>=upper)?TG_BTN_R:UINT16_C(0x0020);
            d->shift_gear=gear;d->shift_hold=12u;mask|=d->shift_button;
            if(d->shift_count<2u)d->shift_speed[d->shift_count]=raw_speed;
            ++d->shift_count;
        }
    }
    if(raw_speed==0&&d->race_frame>600u)d->stopped_frames++;else d->stopped_frames=0u;
    /* Bordeaux's bend after the right pit can throw Razor into the signs
       before steering recovers. Brake when lateral drift builds, using the
       configured native brake control. Other track policies are unchanged. */
    if(core->mod_time_trial_selected_course==22u&&!seeking_pit&&!read_le16(wram,0x1E86u)&&raw_speed>0x1400){
        int lateral=(int)(int16_t)read_le16(wram,0x1E8Au);
        if(lateral < -3000 || lateral > 3000)
            mask=(uint16_t)((mask&~(TG_BTN_X|TG_BTN_A))|read_le16(wram,0x1F78u));
    }
    /* Accelerator is an EARLY EXIT request during refuelling. Release it
       for every entry/refuel phase; full fuel advances natively to FFF9. */
    if(read_le16(wram,0x1E86u)>=0xFFFAu)mask=0u;
    ++d->race_frame;
    return mask;
}

static uint16_t fixed_setup_input(unsigned frame, unsigned car, int manual) {
    if(frame>=1560u&&frame<1680u)return TG_BTN_START;
    if(frame>=1920u&&frame<1935u)return TG_BTN_DOWN;
    if(frame>=1965u&&frame<1980u)return TG_BTN_DOWN;
    if(frame>=2010u&&frame<2040u)return TG_BTN_A;
    if(frame>=2070u&&frame<2130u)return TG_BTN_A;
    if(frame>=2220u&&frame<2232u)return TG_BTN_A;
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
            nav->held_mask=0u;nav->held_frames=0u;nav->release_frames=90u;return 0u;
        }
        ++nav->held_frames;return nav->held_mask;
    }
    if(!core->mod_menu_remodel_active)return 0u;
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
    #ifdef _WIN32
    if(!MoveFileExA(tmp,path,MOVEFILE_REPLACE_EXISTING|MOVEFILE_WRITE_THROUGH))goto done;
#else
    if(rename(tmp,path)!=0)goto done;
#endif
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
    /* Unlimited retries may produce a valid last run outside the saved Top 5. */
    for(rank=0u;rank<TOPGEAR_TIME_TRIAL_RECORDS_PER_CAR;++rank){
        uint64_t old_sectors,new_sectors;
        if(!topgear_time_trial_store_car_record(&reload,expected->course,expected->car_id,rank,&ranked))break;
        old_sectors=(uint64_t)ranked.best_sector1_ticks+ranked.best_sector2_ticks+ranked.best_sector3_ticks;
        new_sectors=(uint64_t)last.best_sector1_ticks+last.best_sector2_ticks+last.best_sector3_ticks;
        if(ranked.total_time_ticks<last.total_time_ticks)continue;
        if(ranked.total_time_ticks==last.total_time_ticks&&
           (old_sectors<new_sectors||(old_sectors==new_sectors&&ranked.sequence<=last.sequence)))continue;
        break;
    }
    if(rank==TOPGEAR_TIME_TRIAL_RECORDS_PER_CAR){error[0]='\0';return 1;}
    snprintf(error,cap,"qualifying race missing from exact Data[%u][%u] car table",
             (unsigned)expected->course,(unsigned)expected->car_id);return 0;
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
            (unsigned)run->car_id,rank<5u?rank+1u:0u,data_size);
    for(lap=0u;lap<run->completed_laps;++lap){char lt[16],s1[16],s2[16],s3[16];
        format_time(run->lap_time_ticks[lap],lt);format_sector(run->lap_sector1_ticks[lap],s1);
        format_sector(run->lap_sector2_ticks[lap],s2);format_sector(run->lap_sector3_ticks[lap],s3);
        fprintf(f,"L%u: %s | S1 %s s | S2 %s s | S3 %s s\n",lap+1u,lt,s1,s2,s3);
    }
    if(run->gearbox)fprintf(f,"Manual shift requests: %u; raw speeds at shifts: %d, %d\n",
                            driver->shift_count,driver->shift_speed[0],driver->shift_speed[1]);
    return fclose(f)==0;
}

int main(int argc,char **argv) {
    uint8_t *rom=NULL,*existing=NULL;size_t rom_size=0u,existing_size=0u;
    TopGearRecomp *core=NULL;TopGearTimeTrialStore store;TopGearRecompFrameResult advance;
    TopGearTimeTrialRun completed;Driver driver;MenuNav nav;uint8_t wram[TOPGEAR_RECOMP_WRAM_SIZE],frame[FRAME_BYTES];
    unsigned course,car,expected_laps,frame_number,last_lap=0u,results_frame=0u,data_rank=99u;
    unsigned target_runs=2u;int resume_snapshot=0;
    unsigned retry_phase=0u,retry_wait=0u,return_wait=0u,completed_runs=0u;
    int manual,results_phase=0,setup_verified=0,data_committed=0,detail_captured=0,top5_captured=0,pit_captured=0;
    unsigned detail_ready_frames=0u,top5_ready_frames=0u;
    unsigned page_stable=0u,last_page=255u,menu_captured[14][8]={{0}},last_selection=255u,sector_capture[8][4]={{0}};
    unsigned live_ticks=0u,last_tick=0u,active_frames=0u,stalled_frames=0u;
    uint8_t settings_cache[TOPGEAR_PLAYER_SETTINGS_SIZE]={0};
    char settings_path[4096];FILE *trace=NULL;
    int detail_continue_sent=0,top5_continue_sent=0,returned_country=0;uint64_t prior_hash=0u;unsigned stable_frames=0u;
    char error[256],path[4096],total[16],best1[16],best2[16],best3[16];

    if(argc==3&&!strcmp(argv[1],"--self-test-data")){
        unsigned trial,lap,rank;
        topgear_time_trial_store_init(&store);
        for(trial=0u;trial<8u;++trial){
            TopGearTimeTrialRun run;memset(&run,0,sizeof(run));
            memcpy(run.name,"RETRY   ",8u);run.course=1u;run.car_id=1u;
            run.required_laps=run.completed_laps=3u;
            run.valid_flags=TOPGEAR_TIME_TRIAL_RUN_VALID|TOPGEAR_TIME_TRIAL_RUN_COMPLETE;
            run.best_sector1_ticks=20u+trial;run.best_sector2_ticks=30u+trial;run.best_sector3_ticks=50u+trial;
            for(lap=0u;lap<3u;++lap){
                run.lap_sector1_ticks[lap]=run.best_sector1_ticks;
                run.lap_sector2_ticks[lap]=run.best_sector2_ticks;
                run.lap_sector3_ticks[lap]=run.best_sector3_ticks;
                run.lap_time_ticks[lap]=100u+3u*trial;run.total_time_ticks+=run.lap_time_ticks[lap];
            }
            if(!topgear_time_trial_store_insert(&store,&run)||!save_store_atomic(&store,argv[2])||
               !verify_saved_file(argv[2],&run,&rank,error,sizeof(error))||rank!=(trial<5u?trial:99u)){
                fprintf(stderr,"retry Data self-test failed at run %u\n",trial+1u);return 1;
            }
        }
        puts("PASS eight synthetic saved retries: first five ranked, last three durable outside Top 5");return 0;
    }

    if(argc==5&&!strcmp(argv[1],"--font")){
        FILE *f;unsigned x,y,t;
        if(!load_file(argv[2],&rom,&rom_size)||!topgear_recomp_create(&core,rom,rom_size,error,sizeof(error))||
           !topgear_recomp_snapshot_load(core,argv[3],error,sizeof(error)))return 2;
        f=fopen(argv[4],"wb");if(!f)return 2;fprintf(f,"P6\n128 24\n255\n");
        for(y=0u;y<24u;y++)for(x=0u;x<128u;x++){
            const uint8_t *d;unsigned bit=7u-(x%8u),r=(y%8u)*2u,pal;uint8_t rgb[3];
            t=(y/8u)*16u+x/8u;d=core->mod_time_trial_font_tiles[t];
            pal=((d[r]>>bit)&1u)|(((d[r+1u]>>bit)&1u)<<1u)|(((d[r+16u]>>bit)&1u)<<2u)|(((d[r+17u]>>bit)&1u)<<3u);
            rgb[0]=rgb[1]=rgb[2]=pal?255u:0u;fwrite(rgb,1u,3u,f);
        }
        fclose(f);return 0;
    }
    if(argc==5&&!strcmp(argv[1],"--probe")){
        static const unsigned masks[]={0u,0x40u,0x80u,0x8000u,0x4000u,0x20u,0x10u,0x100u,0x200u};unsigned k,n;
        if(!load_file(argv[2],&rom,&rom_size)||!topgear_recomp_create(&core,rom,rom_size,error,sizeof(error)))return 2;
        for(k=0u;k<sizeof(masks)/sizeof(masks[0]);k++){
            if(!topgear_recomp_snapshot_load(core,argv[3],error,sizeof(error)))return 2;
            for(n=0u;n<300u;n++)if(!topgear_recomp_advance_headless(core,n<60u?0u:(uint16_t)masks[k],0u,1u,&advance)){
                unsigned j;
                fprintf(stderr,"probe frame %u PC %02X:%04X: %s\n",n,core->cpu.pbr,core->cpu.pc,topgear_recomp_last_error(core));
                for(j=0x2870u;j<0x2890u;j++)fprintf(stderr,"%02X ",core->wram[j]);
                fprintf(stderr,"\n");return 1;
            }
            snprintf(path,sizeof(path),"%s-%04X.ppm",argv[4],masks[k]);(void)write_ppm(core,path);
            printf("mask=%04X speed=%u flags=%04X state=%04X pos=%u fuel=%04X gear=%u\n",masks[k],read_le16(core->wram,0x1E5Au),read_le16(core->wram,0x1E6Cu),read_le16(core->wram,0x0100u),read_le16(core->wram,0x0202u),read_le16(core->wram,0x1E62u),read_le16(core->wram,0x1E72u));fflush(stdout);
        }
        return 0;
    }
    if(argc==4&&!strcmp(argv[1],"--inspect")){
        unsigned address;
        if(!load_file(argv[2],&rom,&rom_size)||!topgear_recomp_create(&core,rom,rom_size,error,sizeof(error))||
           !topgear_recomp_snapshot_load(core,argv[3],error,sizeof(error)))return 2;
        printf("PC %02X:%04X DBR %02X TT %u laps %u/%u\n",core->cpu.pbr,core->cpu.pc,core->cpu.dbr,core->mod_time_trial_active,core->mod_time_trial_lap_count,core->mod_time_trial_required_laps);
        for(address=0u;address<0x40u;address+=2u)printf("%04X=%04X\n",address,read_le16(core->wram,address));
        for(address=0x0100u;address<0x0140u;address+=2u)printf("%04X=%04X\n",address,read_le16(core->wram,address));
        for(address=0x1E50u;address<0x1F12u;address+=2u)printf("%04X=%04X\n",address,read_le16(core->wram,address));
        for(address=0u;address<read_le16(core->wram,0x0200u);address+=32u){
            unsigned obj=read_le16(core->wram,0x6400u+address/16u);
            if((obj&0xFE00u)==0x7400u)printf("PIT position=%u object=%04X side=%s\n",address,obj,(obj&0x100u)?"LEFT":"RIGHT");
        }
        return 0;
    }
    if(argc!=7&&argc!=8){fprintf(stderr,"usage: %s ROM OUTPUT_DIR DATA_FILE COURSE CAR GEARBOX(auto|manual) [--runs=N | NATURAL_COMPLETED_SNAPSHOT]\n",argv[0]);return 2;}
    if(argc==8&&!strncmp(argv[7],"--runs=",7u)){target_runs=(unsigned)strtoul(argv[7]+7u,NULL,10);if(target_runs<2u||target_runs>1000u)return 2;}
    resume_snapshot=argc==8&&strncmp(argv[7],"--runs=",7u)!=0;
    course=(unsigned)strtoul(argv[4],NULL,10);car=(unsigned)strtoul(argv[5],NULL,10);
    manual=strcmp(argv[6],"manual")==0;
    if(course>=32u||car>=4u||(strcmp(argv[6],"auto")!=0&&!manual)){fprintf(stderr,"invalid scenario\n");return 2;}
    expected_laps=track_laps[course];
    if(!load_file(argv[1],&rom,&rom_size)||!ensure_directory(argv[2]))return 2;
    if(rom_size!=524288u||read_le16(rom,0x5EA4u+course*2u)!=expected_laps){fprintf(stderr,"ROM lap catalog mismatch\n");return 2;}
    if(!topgear_recomp_create(&core,rom,rom_size,error,sizeof(error))){fprintf(stderr,"create failed: %s\n",error);free(rom);return 1;}free(rom);
    topgear_time_trial_store_init(&store);
    if(load_file(argv[3],&existing,&existing_size)){
        if(!topgear_time_trial_store_import(&store,existing,existing_size,error,sizeof(error))){fprintf(stderr,"existing Data import failed: %s\n",error);free(existing);topgear_recomp_destroy(core);return 1;}
        free(existing);
    }
    topgear_recomp_time_trial_set_leaderboard_provider(core,topgear_time_trial_store_provider,&store);
    memset(&driver,0,sizeof(driver));memset(&nav,0,sizeof(nav));nav.release_frames=120u;memset(&completed,0,sizeof(completed));

    if(!ensure_parent_directory(argv[3]))return 2;
    snprintf(settings_path,sizeof(settings_path),"%s/Data/player-settings.dat",argv[2]);
    if(!ensure_parent_directory(settings_path))return 2;
    snprintf(path,sizeof(path),"%s/journey.csv",argv[2]);trace=fopen(path,"wb");if(!trace)return 2;
    fprintf(trace,"frame,input,page,selection,active,course,car,gear_lo,gear_hi,controls,position,length,speed,ticks,lap,required,live_gear,fuel,pit,world_position,lateral,pit_seek_frames\n");
    if(resume_snapshot){
        if(!topgear_recomp_snapshot_load(core,argv[7],error,sizeof(error))){fprintf(stderr,"resume failed: %s\n",error);return 1;}
        if(core->mod_time_trial_selected_course!=course||(read_le16(core->wram,0x1F8Fu)&3u)!=car||
           ((read_le16(core->wram,0x1F7Au)|read_le16(core->wram,0x1F7Cu))!=0u)!=manual){fprintf(stderr,"snapshot scenario mismatch\n");return 2;}
        setup_verified=1;results_phase=core->mod_time_trial_active?0:1;nav.phase=3u;
        if(core->mod_time_trial_active){active_frames=1200u;live_ticks=60u;last_tick=read_le16(core->wram,0x1EAEu);}
        fprintf(stderr,"RESUME: natural snapshot %s\n",argv[7]);
    }
    for(frame_number=resume_snapshot?12000u:0u;frame_number<65000u*target_runs;++frame_number){
        uint16_t input=0u;uint64_t hash;unsigned current_lap;
        if(frame_number<3750u)input=fixed_setup_input(frame_number,car,manual);
        else if(nav.phase<3u&&!results_phase&&!core->mod_time_trial_active)input=nav_action(&nav,core,course);
        else if(detail_captured&&!detail_continue_sent){input=TG_BTN_A;detail_continue_sent=1;}
        else if(top5_captured&&!top5_continue_sent){input=completed_runs<target_runs?TG_BTN_B:TG_BTN_A;top5_continue_sent=1;}
        else if(top5_continue_sent&&completed_runs<target_runs&&core->mod_menu_remodel_active&&core->mod_menu_remodel_page==10u){
            if(retry_phase==0u&&++retry_wait>=30u){input=TG_BTN_UP;retry_phase=1u;retry_wait=0u;}
            else if(retry_phase==1u&&++retry_wait>=90u){
                if(core->mod_menu_remodel_selection!=1u){fprintf(stderr,"Retry highlight failed\n");return 1;}
                snprintf(path,sizeof(path),"%s/retry-highlight-run-%u.ppm",argv[2],completed_runs);if(!write_ppm(core,path))return 1;
                input=TG_BTN_A;retry_phase=2u;
            }
        }
        else if(results_phase&&!data_committed){
            if((results_frame>=120u&&results_frame<132u)||(results_frame>=600u&&results_frame<612u)||(results_frame>=1080u&&results_frame<1092u))input=TG_BTN_A;
            ++results_frame;
        }else if(core->mod_time_trial_active&&live_ticks>=60u&&active_frames>=1200u){
            input=driver_input(core,&driver,wram,frame,manual);
        }
        if(!topgear_recomp_advance_headless(core,input,0u,1u,&advance)){
            unsigned j;
            fprintf(stderr,"advance failed frame=%u PC=%02X:%04X: %s\n",frame_number,core->cpu.pbr,core->cpu.pc,topgear_recomp_last_error(core));
            if(core->cpu.pbr==0x7Eu)for(j=core->cpu.pc;j<core->cpu.pc+16u;j++)fprintf(stderr,"%02X ",core->wram[j]);
            fprintf(stderr,"\n");
            snprintf(path,sizeof(path),"%s/frontier.snap",argv[2]);(void)topgear_recomp_snapshot_save(core,path,error,sizeof(error));
            topgear_recomp_destroy(core);return 1;
        }
        if(!topgear_recomp_read_wram(core,0u,wram,sizeof(wram))||!topgear_recomp_v22_read_frame_bgr555(core,0u,frame,sizeof(frame))){fprintf(stderr,"state read failed\n");topgear_recomp_destroy(core);return 1;}

        if(retry_phase==2u&&core->mod_time_trial_active){
            retry_phase=3u;setup_verified=0;data_committed=0;detail_captured=0;detail_ready_frames=0u;
            detail_continue_sent=0;top5_captured=0;top5_continue_sent=0;top5_ready_frames=0u;
            results_phase=0;results_frame=0u;stable_frames=0u;last_lap=0u;
            active_frames=0u;live_ticks=0u;last_tick=0u;stalled_frames=0u;
            memset(&driver,0,sizeof(driver));memset(sector_capture,0,sizeof(sector_capture));
            fprintf(stderr,"RETRY STARTED through results controller action\n");
        }
        if(core->mod_time_trial_active){
            unsigned tick=read_le16(wram,0x1EAEu);
            ++active_frames;
            if(tick>last_tick&&read_le16(wram,0x0200u)>3u&&core->mod_time_trial_required_laps==expected_laps)++live_ticks;
            if(driver.race_frame>600u&&tick==last_tick)stalled_frames++;else stalled_frames=0u;
            if(stalled_frames==600u&&!results_phase&&core->mod_time_trial_lap_count<expected_laps){
                snprintf(path,sizeof(path),"%s/incomplete-run.ppm",argv[2]);(void)write_ppm(core,path);
                snprintf(path,sizeof(path),"%s/incomplete-run.snap",argv[2]);(void)topgear_recomp_snapshot_save(core,path,error,sizeof(error));
                fprintf(stderr,"FAIL: race stopped with %u/%u completed laps; no timing data saved\n",core->mod_time_trial_lap_count,expected_laps);
                return 1;
            }
            last_tick=tick;
        }
        if((frame_number%60u)==0u){
            fprintf(trace,"%u,%04X,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%d,%u\n",frame_number,input,
                core->mod_menu_remodel_page,core->mod_menu_remodel_selection,core->mod_time_trial_active,
                read_le16(wram,0x1F06u),read_le16(wram,0x1F8Fu),read_le16(wram,0x1F7Au),read_le16(wram,0x1F7Cu),
                read_le16(wram,0x1F76u),read_le16(wram,0x0202u),read_le16(wram,0x0200u),read_le16(wram,0x1E5Au),
                read_le16(wram,0x1EAEu),core->mod_time_trial_lap_count,core->mod_time_trial_required_laps,read_le16(wram,0x1E72u),
                read_le16(wram,0x1E62u),read_le16(wram,0x1E86u),read_le16(wram,0x1ED7u),(int)(int16_t)read_le16(wram,0x1E8Au),driver.pit_seek_frames);
            fflush(trace);
        }
        if(core->mod_menu_remodel_active&&!core->mod_menu_remodel_dirty){
            unsigned page=core->mod_menu_remodel_page;
            if(page==last_page&&core->mod_menu_remodel_selection==last_selection)++page_stable;else {last_page=page;last_selection=core->mod_menu_remodel_selection;page_stable=0u;}
            if(page<14u&&last_selection<8u&&!menu_captured[page][last_selection]&&page_stable>=60u){
                snprintf(path,sizeof(path),"%s/menu-%u-item-%u.ppm",argv[2],page,last_selection);if(!write_ppm(core,path))return 1;
                menu_captured[page][last_selection]=1u;
            }
            if(!topgear_player_settings_save_file(core,settings_path,settings_cache))return 1;
        }else page_stable=0u;
        if(frame_number==2275u||frame_number==2900u||frame_number==3200u||frame_number==3500u||frame_number==3615u){
            snprintf(path,sizeof(path),"%s/setup-%u.ppm",argv[2],frame_number);if(!write_ppm(core,path))return 1;
        }
        if(core->mod_time_trial_active&&active_frames==600u){
            snprintf(path,sizeof(path),"%s/pre-race.ppm",argv[2]);if(!write_ppm(core,path))return 1;
        }
        if(driver.stopped_frames==180u&&!pit_captured){
            pit_captured=1;
            snprintf(path,sizeof(path),"%s/stopped-car.snap",argv[2]);(void)topgear_recomp_snapshot_save(core,path,error,sizeof(error));
            snprintf(path,sizeof(path),"%s/stopped-car.ppm",argv[2]);(void)write_ppm(core,path);
        }
        if(driver.race_frame==120u||driver.race_frame==1200u){
            snprintf(path,sizeof(path),"%s/driving-%u.ppm",argv[2],driver.race_frame);if(!write_ppm(core,path))return 1;
        }
        if(core->mod_time_trial_active&&driver.race_frame>120u){
            unsigned lap=core->mod_time_trial_lap_count;
            unsigned sector=(core->mod_time_trial_sector_mask&2u)?2u:(core->mod_time_trial_sector_mask&1u)?1u:0u;
            if(lap<8u&&++sector_capture[lap][sector]==30u){
                snprintf(path,sizeof(path),"%s/lap-%u-sector-%u.ppm",argv[2],lap+1u,sector);
                if(!write_ppm(core,path))return 1;
            }
        }
        if(!setup_verified&&live_ticks>=60u&&active_frames>=1200u&&core->mod_time_trial_active){
            unsigned actual_course=read_le16(wram,COURSE_WORD_OFFSET)&31u;
            unsigned actual_car=read_le16(wram,P1_CAR_OFFSET)&3u;
            int actual_manual=(read_le16(wram,P1_GEAR_LO_OFFSET)|read_le16(wram,P1_GEAR_HI_OFFSET))!=0u;
            if(actual_course!=course||actual_car!=car||actual_manual!=manual){
                fprintf(stderr,"SETUP FAIL expected course=%u car=%u gear=%s got course=%u car=%u gear=%s words=%04X/%04X page=%u sel=%u\n",
                        course,car,manual?"MANUAL":"AUTO",actual_course,actual_car,actual_manual?"MANUAL":"AUTO",
                        read_le16(wram,P1_GEAR_LO_OFFSET),read_le16(wram,P1_GEAR_HI_OFFSET),core->mod_menu_remodel_page,core->mod_menu_remodel_selection);
                topgear_recomp_destroy(core);return 1;
            }
            if(wram[0x1F86u]!='A'){fprintf(stderr,"name selection was not committed\n");return 1;}
            if(read_le16(wram,0x1F76u)!=read_le16(core->rom,0x6C656u)||read_le16(wram,0x1F78u)!=read_le16(core->rom,0x6C658u))return 1;
            setup_verified=1;
            snprintf(path,sizeof(path),"%s/race-start.snap",argv[2]);
            (void)topgear_recomp_snapshot_save(core,path,error,sizeof(error));
            fprintf(stderr,"SETUP PASS track=%s course=%u car=%s gearbox=%s\n",track_names[course],course,car_names[car],manual?"MANUAL":"AUTO");
        }
        if(core->mod_time_trial_required_laps&&core->mod_time_trial_required_laps!=expected_laps){
            fprintf(stderr,"required laps mismatch: game=%u expected=%u\n",(unsigned)core->mod_time_trial_required_laps,expected_laps);topgear_recomp_destroy(core);return 1;
        }
        current_lap=(unsigned)core->mod_time_trial_lap_count;
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
            snprintf(path,sizeof(path),"%s/completed-run.snap",argv[2]);
            (void)topgear_recomp_snapshot_save(core,path,error,sizeof(error));
            fprintf(stderr,"HANDOFF total=%u best=%u/%u/%u laps=%u/%u flags=%u name=%.8s\n",staged.total_time_ticks,staged.best_sector1_ticks,staged.best_sector2_ticks,staged.best_sector3_ticks,staged.completed_laps,staged.required_laps,staged.valid_flags,staged.name);
            {unsigned j;for(j=0u;j<staged.completed_laps;j++)fprintf(stderr,"HANDOFF L%u %u = %u + %u + %u\n",j+1u,staged.lap_time_ticks[j],staged.lap_sector1_ticks[j],staged.lap_sector2_ticks[j],staged.lap_sector3_ticks[j]);}
            if(!topgear_time_trial_store_insert(&store,&staged)){fprintf(stderr,"host store rejected completed-run timing metadata\n");topgear_recomp_destroy(core);return 1;}
            if(!save_store_atomic(&store,argv[3])){fprintf(stderr,"atomic Data file write failed errno=%d\n",errno);topgear_recomp_destroy(core);return 1;}
            if(!verify_saved_file(argv[3],&staged,&data_rank,verify_error,sizeof(verify_error))){fprintf(stderr,"Data verification failed: %s\n",verify_error);topgear_recomp_destroy(core);return 1;}
            if(!topgear_recomp_time_trial_commit_completed_run(core)){fprintf(stderr,"core completed-run commit failed\n");topgear_recomp_destroy(core);return 1;}
            topgear_time_trial_store_mark_clean(&store);completed=staged;data_committed=1;++completed_runs;retry_phase=0u;retry_wait=0u;
            fprintf(stderr,"DATA VERIFIED bytes=%u exact-slot=[track %u][car %u] rank=%u\n",TOPGEAR_TT_STORE_FILE_SIZE,course,car,(data_rank<5u?data_rank+1u:0u));
        }
        if(setup_verified&&!core->mod_time_trial_active&&!data_committed&&
           !core->mod_time_trial_completed_run_valid&&last_lap){
            unsigned j;
            fprintf(stderr,"FAIL: completed path rejected timing, laps=%u/%u\n",last_lap,expected_laps);
            for(j=0u;j<last_lap&&j<8u;j++)fprintf(stderr,"INVALID L%u %u = %u + %u + %u\n",j+1u,core->mod_time_trial_completed_laps[j],core->mod_time_trial_completed_s1[j],core->mod_time_trial_completed_s2[j],core->mod_time_trial_completed_s3[j]);
            snprintf(path,sizeof(path),"%s/invalid-run.snap",argv[2]);(void)topgear_recomp_snapshot_save(core,path,error,sizeof(error));return 1;
        }

        if(data_committed&&!detail_captured&&core->mod_menu_remodel_active&&core->mod_menu_remodel_page==10u&&!core->mod_menu_remodel_dirty){
            /* Menu tile writes become visible in the rendered framebuffer on a
               later PPU frame.  Require several stable page frames so a file
               cannot be named "track-results" while still containing the
               previous OPTIONS frame. */
            if(++detail_ready_frames>=90u){
                snprintf(path,sizeof(path),"%s/track-results-run-%u.ppm",argv[2],completed_runs);
                if(!write_ppm(core,path)){fprintf(stderr,"track-results screenshot failed\n");topgear_recomp_destroy(core);return 1;}
                if(core->bg_scroll[1]!=0u){fprintf(stderr,"post-race BG1 scroll was not reset\n");return 1;}
                detail_captured=1;fprintf(stderr,"SCREENSHOT track-results.ppm after %u stable page frames\n",detail_ready_frames);
            }
        }else if(!detail_captured){
            detail_ready_frames=0u;
        }
        if(detail_continue_sent&&!top5_captured&&core->mod_menu_remodel_active&&core->mod_menu_remodel_page==11u&&!core->mod_menu_remodel_dirty){
            if(++top5_ready_frames>=90u){
                snprintf(path,sizeof(path),"%s/top-5-results-run-%u.ppm",argv[2],completed_runs);
                if(!write_ppm(core,path)){fprintf(stderr,"top-5 screenshot failed\n");topgear_recomp_destroy(core);return 1;}
                if(completed_runs==target_runs){char final_path[4096];snprintf(final_path,sizeof(final_path),"%s/top-5-results.ppm",argv[2]);if(!write_ppm(core,final_path))return 1;}
                if(core->bg_scroll[1]!=0u){fprintf(stderr,"post-race BG1 scroll was not reset\n");return 1;}
                top5_captured=1;fprintf(stderr,"SCREENSHOT top-5-results-run-%u.ppm after %u stable page frames\n",completed_runs,top5_ready_frames);
            }
        }else if(!top5_captured){
            top5_ready_frames=0u;
        }
        if(top5_continue_sent&&core->mod_menu_remodel_active&&core->mod_menu_remodel_page==3u&&core->mod_menu_remodel_selection==1u&&!core->mod_menu_remodel_dirty){if(++return_wait>=90u){
            snprintf(path,sizeof(path),"%s/returned-time-trial.ppm",argv[2]);if(!write_ppm(core,path))return 1;
            returned_country=1;break;
        }}
    }

    if(completed_runs!=target_runs||!setup_verified||!data_committed||!detail_captured||!top5_captured||!returned_country){
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
    printf("COMPLETED RUNS=%u RETRIES=%u SAME COURSE=%u\n",completed_runs,completed_runs-1u,course);
    printf("PASS track=%s laps=%u car=%s gearbox=%s final=%s bestS1=%ss bestS2=%ss bestS3=%ss Data=[%u][%u] rank=%u bytes=%u screenshots=track-results.ppm,top-5-results.ppm\n",
           track_names[course],expected_laps,car_names[car],manual?"MANUAL":"AUTO",total,best1,best2,best3,
           course,car,(data_rank<5u?data_rank+1u:0u),TOPGEAR_TT_STORE_FILE_SIZE);
    {
        TopGearStaticAudioStatus audio;
        if(!topgear_recomp_static_audio_status(core,&audio)||audio.aot_failed||audio.sdsp_static_failed)return 1;
        printf("AUDIO PASS AOT-failed=%u DSP-failed=%u PCM-frames=%llu\n",(unsigned)audio.aot_failed,(unsigned)audio.sdsp_static_failed,(unsigned long long)audio.pcm_frames);
    }
    fclose(trace);
    /* Reboot the same ROM core, import the physical settings file, and prove
       the TT bank survives game-owned initialization and mode navigation. */
    if(!topgear_recomp_reset(core,error,sizeof(error))||
       !topgear_player_settings_load_file(core,settings_path,settings_cache))return 1;
    for(frame_number=0u;frame_number<2100u;frame_number++){
        uint16_t input=0u;
        if(frame_number>=1560u&&frame_number<1680u)input=TG_BTN_START;
        if((frame_number>=1920u&&frame_number<1935u)||(frame_number>=1965u&&frame_number<1980u))input=TG_BTN_DOWN;
        if(frame_number>=2010u&&frame_number<2040u)input=TG_BTN_A;
        if(!topgear_recomp_advance_headless(core,input,0u,1u,&advance))return 1;
    }
    if(core->mod_menu_remodel_page!=3u||core->wram[0x1F86u]!='A'||
       (read_le16(core->wram,0x1F8Fu)&3u)!=car||
       ((read_le16(core->wram,0x1F7Au)|read_le16(core->wram,0x1F7Cu))!=0u)!=manual)return 1;
    snprintf(path,sizeof(path),"%s/reloaded-settings.ppm",argv[2]);if(!write_ppm(core,path))return 1;
    puts("PLAYER SETTINGS physical save/reboot/reload PASS");
    topgear_recomp_destroy(core);return 0;
}
