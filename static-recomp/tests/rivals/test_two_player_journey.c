#define main career_contract_main
#include "../test_career_v2.c"
#undef main
#include "two_player_self_driver.inc"
#include <windows.h>

static unsigned word(unsigned a){return read_le16(c->wram,a);}
static TopGearRecomp *view;
static const char *tracks[32]={"Las Vegas","Los Angeles","New York","San Francisco","Rio","Machu Picchu","Chichen Itza","Rain Forest","Tokyo","Hiroshima","Yokohama","Kyoto","Munich","Cologne","Black Forest","Frankfurt","Stockholm","Copenhagen","Helsinki","Oslo","Paris","Nice","Bordeaux","Monaco","Pisa","Rome","Sicily","Florence","London","Sheffield","Loch Ness","Stonehenge"};
static uint16_t human_input(unsigned player,Driver *driver){
    static const unsigned pairs[]={0x1E5A,0x1E62,0x1E6C,0x1E72,0x1E76,0x1E86,0x1E8A,0x1ED7,0x1EE8};
    unsigned n,a;uint8_t frame[256u*224u*2u];
    memcpy(view->wram,c->wram,sizeof(c->wram));view->rom=c->rom;
    memcpy(frame,c->mode1_frame,sizeof(frame));
    if(player){
        for(n=0;n<sizeof(pairs)/sizeof(pairs[0]);n++){
            a=pairs[n];memcpy(view->wram+a,c->wram+a+2u,2u);
            memcpy(view->wram+a+2u,c->wram+a,2u);
        }
        memcpy(view->wram+0x204,c->wram+0x206,2);
        memcpy(view->wram+0x206,c->wram+0x204,2);
        memcpy(view->wram+0x1F76,c->wram+0x1F93,8);
        memcpy(view->wram+0x1F8F,c->wram+0x1FAC,2);
        view->wram[0x11E]=(uint8_t)(read_le16(view->wram,0x1E76)+1u);
        memcpy(frame,c->mode1_frame+112u*256u*2u,112u*256u*2u);
    }
    return driver_input(view,driver,view->wram,frame,0);
}
static void save_state(const char *label){
    char path[1024];snprintf(path,sizeof(path),"%s/%s.snap",dir,label);
    if(!topgear_recomp_snapshot_save(c,path,error,sizeof(error))){fprintf(stderr,"save: %s\n",error);exit(1);}
}
int main(int argc,char **argv){
    uint8_t rom[524288],profile[96];FILE *f,*csv;unsigned mode,n,k,race,wait,course,limit;
    char path[1024],label[80];LARGE_INTEGER frequency;
    if(argc!=4)return 2;mode=!strcmp(argv[2],"rally");if(!mode&&strcmp(argv[2],"career"))return 2;
    dir=argv[3];f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
    CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
    view=(TopGearRecomp*)calloc(1,sizeof(*view));CHECK(view);
    CHECK(frames(1560,0)&&frames(120,0x1000)&&frames(220,0));
    CHECK(topgear_recomp_player_settings_export(c,profile,sizeof(profile)));
    memset(profile+20,0,4);memset(profile+46,0,4);profile[40]=1;profile[66]=3;
    memcpy(profile+58,"PLAYER 2",8);profile[94]=0;
    {uint32_t hash=2166136261u;for(n=16;n<96;n++)hash=(hash^profile[n])*16777619u;for(n=0;n<4;n++)profile[12+n]=(uint8_t)(hash>>(8*n));}
    CHECK(topgear_recomp_player_settings_import(c,profile,sizeof(profile))&&tg_mod_menu_remodel_main_menu_enter(c));
    topgear_recomp_set_center_screen_enabled(c,0);topgear_recomp_set_bottom_screen_enabled(c,0);
    if(mode)CHECK(press(0x0400));CHECK(press(0x0080)&&press(0x0100)&&word(0x1F04)==1);
    CHECK(press(0x0400)&&press(0x0400));if(!mode)CHECK(press(0x0400));CHECK(press(0x0080));
    for(wait=0;wait<4000&&c->hdma_enable_mask!=0x7F;wait++)CHECK(frames(1,0));CHECK(wait<4000);
    snprintf(path,sizeof(path),"%s/results.csv",dir);csv=fopen(path,"wb");CHECK(csv);
    fprintf(csv,"race,course,track,driver,car,crossed,finish_place,classified_place,fuel,pit_stops,points,standing,disqualified\n");
    QueryPerformanceFrequency(&frequency);limit=mode?8u:1u;
    for(race=0;race<limit;race++){
        Driver drivers[2]={{0},{0}};unsigned pits[2]={0},previous_pit[2]={0},finish[20]={0},classified[2],fuel[2],dq;
        LARGE_INTEGER start,end;TopGearRecompFrameResult result;
        course=word(0x1F06);CHECK(course<32&&!c->mod_time_trial_active&&word(0x1F04)==1&&!c->rivals.ready&&!tg_mod_bottom_screen_off(c));
        CHECK(word(0x1F8F)==1&&word(0x1FAC)==3);if(!mode)CHECK(course==0);
        printf("START mode=%s race=%u track=%s course=%u laps=%u P1=White-Sidewinder P2=Blue-Weasel auto/auto fuel=%u/%u extra_CPU_updates=%u/%u\n",argv[2],race+1,tracks[course],course,word(0x1E56),word(0x1E62),word(0x1E64),c->rivals.rival[0].updates,c->rivals.rival[1].updates);fflush(stdout);
        snprintf(label,sizeof(label),"race-%u-start",race+1);save_state(label);QueryPerformanceCounter(&start);
        for(n=0;n<60000&&word(0x1EB0)<10;n++){
            uint16_t p1=human_input(0,&drivers[0]),p2=human_input(1,&drivers[1]);
            CHECK(topgear_recomp_advance_headless(c,p1,p2,1,&result));topgear_recomp_audio_clear(c);
            CHECK(!c->mod_time_trial_active&&!c->rivals.ready&&!c->rivals.rival[0].updates&&!c->rivals.rival[1].updates);
            for(k=0;k<2;k++){unsigned pit=word(0x1E86+k*2);if(!previous_pit[k]&&pit>=0x8000){pits[k]++;printf("PIT race=%u player=%u frame=%u fuel=%u intended=%u\n",race+1,k+1,n,word(0x1E62+k*2),drivers[k].pit_intent);}previous_pit[k]=pit;}
            if(n%2000==0){printf("PROGRESS race=%u frame=%u lap=%d/%d speed=%u/%u fuel=%u/%u finishers=%u\n",race+1,n,(int16_t)word(0x1E76),(int16_t)word(0x1E78),word(0x1E5A),word(0x1E5C),word(0x1E62),word(0x1E64),word(0x1EB0));fflush(stdout);}
        }
        QueryPerformanceCounter(&end);CHECK(n<60000);
        printf("PERFORMANCE race=%u frames=%u headless_throughput_fps=%.2f (not window presentation FPS)\n",race+1,n,(double)n*frequency.QuadPart/(end.QuadPart-start.QuadPart));
        for(k=0;k<word(0x1EB0)&&k<20;k++){unsigned id=c->wram[0x1F12+k];CHECK(id<20);finish[id]=k+1;}
        for(k=0;k<2;k++){classified[k]=finish[k]?finish[k]:word(0x1E7A+k*2)+1;fuel[k]=word(0x1E62+k*2);}
        snprintf(label,sizeof(label),"race-%u-finish",race+1);save_state(label);CHECK(frames(600,0));dq=c->mod_continue_screen!=0;
        snprintf(label,sizeof(label),"race-%u-results",race+1);CHECK(shot(label));
        if(!dq){CHECK(press(0x0080)&&frames(300,0));snprintf(label,sizeof(label),"race-%u-standings",race+1);CHECK(shot(label));}
        for(k=0;k<2;k++){
            unsigned rank=0,j;for(j=0;j<20;j++)if(c->wram[0x1F62+j]==k)rank=j+1;
            fprintf(csv,"%u,%u,%s,P%u,%s,%u,%u,%u,%u,%u,%u,%u,%u\n",race+1,course,tracks[course],k+1,k?"Blue Weasel":"White Sidewinder",finish[k]!=0,finish[k],classified[k],fuel[k],pits[k],c->wram[0x1F4E+k],rank,dq);
            printf("RESULT race=%u player=%u crossed=%u finish=%u classified=%u fuel=%u pits=%u points=%u standing=%u disqualified=%u\n",race+1,k+1,finish[k]!=0,finish[k],classified[k],fuel[k],pits[k],c->wram[0x1F4E+k],rank,dq);
        }
        fflush(csv);fflush(stdout);
        if(dq){printf("STOP first disqualification; retries=0\n");break;}
        if(!mode){puts("STOP Career after first track; retries=0");break;}
        CHECK(press(0x0080));
        for(wait=0;wait<4000;wait++){if(race==7?(c->mod_menu_remodel_active&&c->mod_menu_remodel_page==0):c->mod_rally_active&&c->mod_rally_race_index==race+1&&c->hdma_enable_mask==0x7F)break;CHECK(frames(1,0));}CHECK(wait<4000);
    }
    fclose(csv);free(view);topgear_recomp_destroy(c);printf("PASS requested two-player %s test scope; no retries or CPU AI changes\n",argv[2]);return 0;
}
