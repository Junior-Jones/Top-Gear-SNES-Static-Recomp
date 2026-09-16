#include "topgear_internal.h"
#include <string.h>
static unsigned word(TopGearRecomp *i,unsigned a){return i->wram[a]|((unsigned)i->wram[a+1]<<8);}
void tg_mod_attempt_begin(TopGearRecomp *i){i->mod_continues_remaining=3;i->mod_continue_screen=0;i->mod_attempt_live=0;}
void tg_mod_attempt_race(TopGearRecomp *i){
    i->mod_attempt_live=(uint8_t)(!i->mod_time_trial_active&&i->mod_career_panel);
    if(i->mod_attempt_live)memcpy(i->mod_attempt_points,i->wram+0x1F4E,20);
}
void tg_mod_attempt_fail(TopGearRecomp *i){
    i->mod_continue_screen=i->mod_rally_active?5:1;i->mod_continue_selection=(uint8_t)!i->mod_continues_remaining;
    i->mod_continue_released=0;i->mod_continue_previous=0;
    i->mod_continue_course=(uint8_t)word(i,0x1F06);i->mod_continue_rally=i->mod_rally_active;
    i->mod_career_password_award=0;i->mod_career_qualification_pending=0;i->mod_rally_qualification_pending=0;
}
int tg_mod_attempt_pre_results(TopGearRecomp *i){
    unsigned n,cutoff;int p1=0,p2=0;
    if(!i->mod_attempt_live)return 0;i->mod_attempt_live=0;
    if(i->mod_time_trial_active)return 0;
    if(i->mod_rally_active&&i->mod_rally_race_index==7u)return 0; /* Finale: points, no placement gate. */
    cutoff=i->mod_rally_active?tg_mod_rally_cutoff(i->mod_rally_race_index):tg_mod_career_cutoff(word(i,0x1F06));
    for(n=0;n<20;n++){
        unsigned id=i->wram[0x1F12+n];
        if(id==0){tg_bus_store16(i,0x1FF8,(uint16_t)(n+1));if(n<cutoff)p1=1;}
        if(id==1){tg_bus_store16(i,0x1FFA,(uint16_t)(n+1));if(n<cutoff)p2=1;}
    }
    if(p1&&(!word(i,0x1F04)||p2))return 0;
    tg_mod_attempt_fail(i);return 1;
}
int tg_mod_continue_poll(TopGearRecomp *i){
    uint16_t raw=(uint16_t)(word(i,0x0A)|word(i,0x0C)),edge=(uint16_t)(raw&~i->mod_continue_previous);
    i->mod_continue_previous=raw;
    if(!raw)i->mod_continue_released=1;
    if(!i->mod_continue_released)return 0;
    if((edge&0x0300u)&&i->mod_continues_remaining){i->mod_continue_selection=(uint8_t)((edge&0x0100u)?1:0);tg_mod_insert_audio_navigation(i);}
    if(edge&0x8000u){i->mod_continue_selection=1;i->mod_continue_screen=4;return 1;}
    if(edge&(0x1000u|0x0080u)){i->mod_continue_screen=(uint8_t)(i->mod_continue_selection||!i->mod_continues_remaining?4:3);return 1;}
    return 0;
}
unsigned tg_mod_continue_complete(TopGearRecomp *i){
    unsigned state=i->mod_continue_screen;
    if(state!=3&&state!=4&&state!=5)return 0;
    i->mod_continue_screen=0;i->mod_attempt_live=0;i->mod_career_password_award=0;
    i->mod_career_qualification_pending=0;i->mod_rally_qualification_pending=0;
    if(state==3&&i->mod_continues_remaining&&!i->mod_continue_rally){
        --i->mod_continues_remaining;
        memcpy(i->wram+0x1F4E,i->mod_attempt_points,20);
        tg_bus_store16(i,0x1F06,i->mod_continue_course);tg_bus_store16(i,0x1F08,i->mod_continue_course);tg_bus_store16(i,0x1FF6,0);
        i->mod_rally_active=i->mod_continue_rally;i->mod_menu_remodel_return_pending=0;
        return 0x818E;
    }
    i->mod_menu_remodel_return_pending=1;i->mod_menu_remodel_return_page=0;
    i->mod_menu_remodel_return_selection=i->mod_continue_rally?1:0;
    i->mod_menu_remodel_active=0;i->mod_menu_post_race_context=1;i->mod_rally_active=0;
    return 0x918B;
}
static uint32_t random_next(uint32_t *v){*v^=*v<<13;*v^=*v>>17;*v^=*v<<5;return *v;}
void tg_mod_password_standings(TopGearRecomp *i){
    uint8_t rivals[19],order[20];unsigned n,k=0,pos=0,two=word(i,0x1F04)!=0;
    uint32_t seed=i->mod_password_seed^(uint32_t)topgear_recomp_v27_frame_count(i)^0x7A13B9D5u;if(!seed)seed=1;
    for(n=1;n<20;n++)if(!two||n!=1)rivals[k++]=(uint8_t)n;
    for(n=k;n>1;n--){unsigned j=random_next(&seed)%n;uint8_t x=rivals[n-1];rivals[n-1]=rivals[j];rivals[j]=x;}
    for(n=0;n<20;n++){
        unsigned id=n==4?0:two&&n==5?1:rivals[pos++];order[n]=(uint8_t)id;
        i->wram[0x1F4E + id]=(uint8_t)(n==4?32:40-2*n-(random_next(&seed)&1u));
    }
    memcpy(i->wram+0x1F62,order,20);i->mod_password_seed=seed;i->mod_password_released=0;
}
