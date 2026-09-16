#include "topgear_internal.h"
#include <string.h>
#include "../static-audio/sequel/music_runtime.h"
static int select_engine(TopGearRecomp *i,unsigned engine,unsigned track){
    int ok=engine==1u?tg2_music_select(track):engine==2u?tg3_music_select(track):1;
    if(!ok)return tg_fail_frontier(i,"Imported music transaction failed.","STATIC-MUSIC");
    i->mod_music_engine=(uint8_t)engine;return 1;
}
static int player_select(TopGearRecomp *i){
    unsigned t=i->mod_music_player_track;
    int ok=t<7u?tg0_music_select(t):t<13u?tg2_music_select(t-7u):tg3_music_select(t-13u);
    if(!ok)return tg_fail_frontier(i,"Music Player selection failed.","STATIC-MUSIC");
    i->mod_music_player_state=1u;return 1;
}
const char *tg_mod_music_player_label(const TopGearRecomp *i){
    static const char *const names[20]={"TG TITLE","TG FRANKFURT","TG BORDEAUX","TG HIROSHIMA","TG LAS VEGAS","TG QUALIFIED","TG ENDING THEME",
    "TG2 TITLE","TG2 AUCKLAND","TG2 AYERS ROCK","TG2 CANTERBURY PLAINS","TG2 QUALIFIED","TG2 ENDING THEME",
    "TG3000 TITLE","TG3000 MAIN THEME 1","TG3000 MAIN THEME 2","TG3000 MAIN THEME 3","TG3000 MAIN THEME 4","TG3000 RESULTS","TG3000 ENDING THEME"};
    return names[i->mod_music_player_track%20u];
}
void tg_mod_music_player_action(TopGearRecomp *i,int direction){
    if(direction){i->mod_music_player_track=(uint8_t)((i->mod_music_player_track+20+direction)%20);(void)player_select(i);}
    else if(i->mod_music_player_state==1u)i->mod_music_player_state=2u;
    else (void)player_select(i);
}
uint16_t tg_mod_music_input(TopGearRecomp *i,uint16_t input){
    if(i&&i->mod_menu_remodel_active&&i->mod_menu_remodel_page==15u)return input;
    int menu=!i->mod_music_race||i->mod_menu_remodel_active;
    int player=i->mod_menu_remodel_active&&i->mod_menu_remodel_page==12u&&i->mod_menu_remodel_selection==3u;
    int setup=i->mod_menu_remodel_active&&(i->mod_menu_remodel_page==1u||i->mod_menu_remodel_page==2u||i->mod_menu_remodel_page==3u);
    if(player&&!i->mod_music_player_state){(void)player_select(i);i->mod_menu_remodel_dirty=1u;}
    if(!player&&i->mod_music_player_state){i->mod_music_player_state=0u;(void)select_engine(i,i->mod_music_title,0u);}
    uint8_t pressed=(uint8_t)((input&0x10u)!=0u);
    if(menu&&!setup&&!(i->mod_menu_remodel_active&&(i->mod_menu_remodel_page==10u||i->mod_menu_remodel_page==11u))&&pressed&&!i->mod_music_r_held){
        i->mod_music_title=(uint8_t)((i->mod_music_title+1u)%3u);
        (void)select_engine(i,i->mod_music_title,0u);
        if(player){
            static const uint8_t title_tracks[3]={0u,7u,13u};
            i->mod_music_player_track=title_tracks[i->mod_music_title];
            (void)player_select(i);i->mod_menu_remodel_dirty=1u;
        }
    }
    i->mod_music_r_held=pressed;
    return menu&&!setup?(uint16_t)(input&~0x10u):input;
}
void tg_mod_music_menu_enter(TopGearRecomp *i){
    if(i->mod_menu_remodel_return_pending&&(i->mod_menu_remodel_return_page==10u||i->mod_menu_remodel_return_page==11u)){
        i->mod_music_engine=0u;i->mod_music_race=1u;return;
    }
    if(i->mod_music_race){i->mod_music_race=0u;(void)select_engine(i,i->mod_music_title,0u);}
}

static uint32_t random_next(uint32_t *state){uint32_t x=*state;if(!x)x=0x54474D55u;x^=x<<13;x^=x>>17;x^=x<<5;*state=x;return x;}
void topgear_recomp_music_state_seed(TopGearRecomp *i,uint32_t seed){
    if(!i||i->mod_music_state_ready)return;
    for(unsigned mode=0;mode<3;mode++){
        i->mod_music_random_states[mode]=seed^(0x9E3779B9u*(mode+1u));
        if(!i->mod_music_random_states[mode])i->mod_music_random_states[mode]=mode+1u;
        for(unsigned n=0;n<11;n++)i->mod_music_bags[mode][n]=(uint8_t)n;
        i->mod_music_positions[mode]=11u;i->mod_music_last[mode]=255u;
    }
    i->mod_music_state_ready=1u;
}
static void ensure_state(TopGearRecomp *i){if(!i->mod_music_state_ready)topgear_recomp_music_state_seed(i,0x54474D55u^(uint32_t)i->instruction_count);}
static void shuffle(TopGearRecomp *i,unsigned mode){
    uint8_t *bag=i->mod_music_bags[mode];
    for(unsigned n=0;n<11;n++)bag[n]=(uint8_t)n;
    for(unsigned n=10;n>0;n--){unsigned j=random_next(&i->mod_music_random_states[mode])%(n+1u);uint8_t v=bag[n];bag[n]=bag[j];bag[j]=v;}
    if(bag[0]==i->mod_music_last[mode]){unsigned j=1u+random_next(&i->mod_music_random_states[mode])%10u;uint8_t v=bag[0];bag[0]=bag[j];bag[j]=v;}
    i->mod_music_positions[mode]=0u;
}
static unsigned draw(TopGearRecomp *i,unsigned mode){
    unsigned track;
    if(i->mod_music_positions[mode]>=11u)shuffle(i,mode);
    track=i->mod_music_bags[mode][i->mod_music_positions[mode]++];i->mod_music_last[mode]=(uint8_t)track;return track;
}
void tg_mod_music_rally_playlist(TopGearRecomp *i){ensure_state(i);shuffle(i,1u);}
unsigned tg_mod_music_pick_song(TopGearRecomp *i){
    unsigned track;ensure_state(i);
    if(i->mod_time_trial_active)track=draw(i,2u);
    else if(i->mod_rally_active){
        unsigned race=i->mod_rally_race_index<8u?i->mod_rally_race_index:0u;
        if(i->mod_music_positions[1]>=11u)shuffle(i,1u);
        track=i->mod_music_bags[1][race];i->mod_music_positions[1]=(uint8_t)(race+1u);i->mod_music_last[1]=(uint8_t)track;
    }else if(i->mod_music_mode==2u)track=i->wram[0x1F06u]&3u;
    else if(i->mod_music_mode==1u)track=draw(i,0u);
    else{track=i->mod_music_sequence%11u;i->mod_music_sequence=(uint8_t)((track+1u)%11u);}
    i->mod_music_selected_song=(uint8_t)track;return track;
}
static uint32_t record_hash(const uint8_t *p){uint32_t h=2166136261u;for(unsigned n=16;n<TOPGEAR_MUSIC_STATE_SIZE;n++)h=(h^p[n])*16777619u;return h;}
static void store32(uint8_t *p,uint32_t v){for(unsigned n=0;n<4;n++)p[n]=(uint8_t)(v>>(8u*n));}
static uint32_t load32(const uint8_t *p){return (uint32_t)p[0]|((uint32_t)p[1]<<8)|((uint32_t)p[2]<<16)|((uint32_t)p[3]<<24);}
int topgear_recomp_music_state_export(TopGearRecomp *i,void *output,size_t size){
    uint8_t *b=(uint8_t*)output;if(!i||!b||size<TOPGEAR_MUSIC_STATE_SIZE)return 0;ensure_state(i);
    memset(b,0,TOPGEAR_MUSIC_STATE_SIZE);memcpy(b,"TGMS",4);b[4]=1u;b[8]=TOPGEAR_MUSIC_STATE_SIZE;b[16]=i->mod_music_sequence;
    for(unsigned m=0;m<3;m++){uint8_t *p=b+20+m*18;memcpy(p,i->mod_music_bags[m],11);p[11]=i->mod_music_positions[m];p[12]=i->mod_music_last[m];store32(p+14,i->mod_music_random_states[m]);}
    store32(b+12,record_hash(b));return 1;
}
int topgear_recomp_music_state_import(TopGearRecomp *i,const void *input,size_t size){
    const uint8_t *b=(const uint8_t*)input;
    if(!i||!b||size!=TOPGEAR_MUSIC_STATE_SIZE||memcmp(b,"TGMS",4)||load32(b+4)!=1u||load32(b+8)!=TOPGEAR_MUSIC_STATE_SIZE||load32(b+12)!=record_hash(b)||b[16]>=11u)return 0;
    for(unsigned n=17;n<20;n++)if(b[n])return 0;
    for(unsigned n=74;n<96;n++)if(b[n])return 0;
    for(unsigned m=0;m<3;m++){
        const uint8_t *p=b+20+m*18;unsigned mask=0;
        for(unsigned n=0;n<11;n++){if(p[n]>=11u||(mask&(1u<<p[n])))return 0;mask|=1u<<p[n];}
        if(p[11]>11u||(p[12]>=11u&&p[12]!=255u)||p[13]||!load32(p+14))return 0;
    }
    for(unsigned m=0;m<3;m++){const uint8_t *p=b+20+m*18;memcpy(i->mod_music_bags[m],p,11);i->mod_music_positions[m]=p[11];i->mod_music_last[m]=p[12];i->mod_music_random_states[m]=load32(p+14);}
    i->mod_music_sequence=b[16];i->mod_music_state_ready=1u;return 1;
}
int tg_mod_music_race_prepare(TopGearRecomp *i){
    static const uint8_t native[4]={5u,4u,3u,2u};
    unsigned track=tg_mod_music_pick_song(i);
    i->mod_music_race=1u;i->mod_music_native_selector=0u;
    if(track<4u){i->mod_music_native_selector=native[track];tg_set_acc16(i,(uint16_t)(native[track]-1u));return select_engine(i,0u,0u);}
    if(track<7u)return select_engine(i,1u,track-3u);
    return select_engine(i,2u,track-6u);
}
