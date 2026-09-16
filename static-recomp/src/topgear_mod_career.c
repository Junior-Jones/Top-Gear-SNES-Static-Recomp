#include "topgear_internal.h"
#include <string.h>

static unsigned word(const TopGearRecomp *i,unsigned a){return i->wram[a]|((unsigned)i->wram[a+1u]<<8u);}
static unsigned skill(const TopGearRecomp *i){unsigned s=word(i,0x1F10u);return s<3u?s:2u;}
static const char *password(unsigned s,unsigned course){
    if(s==0u){if(course==8u)return "REDLIGHT";if(course==16u)return "LOWGEARS";if(course==24u)return "DOWNHILL";}
    if(s==1u&&course==16u)return "ROADKILL";
    return NULL;
}
unsigned tg_mod_career_cutoff(unsigned course){return course>=16u?5u:10u;}
unsigned tg_mod_career_retry_course(const TopGearRecomp *i){unsigned c=word(i,0x1F06u);if(c>31u)c=0u;return skill(i)==0u?(c/8u)*8u:skill(i)==1u&&c>=16u?16u:0u;}
unsigned tg_mod_career_password_count(const TopGearRecomp *i){unsigned s=skill(i);return s==0u?3u:s==1u?1u:0u;}
unsigned tg_mod_career_password_country(const TopGearRecomp *i,unsigned selection){
    return selection<tg_mod_career_password_count(i)?(skill(i)==0u?(selection+1u)*2u:4u):0u;
}
const char *tg_mod_career_skill_name(const TopGearRecomp *i){static const char *names[]={"AMATEUR","PROFESSIONAL","CHAMPIONSHIP"};return names[skill(i)];}
void tg_mod_career_validate_start(TopGearRecomp *i){
    unsigned s=skill(i);
    if(i->mod_career_start_skill!=s||!password(s,i->mod_career_start_course))i->mod_career_start_course=0u;
    i->mod_career_start_skill=(uint8_t)s;
}
int tg_mod_career_qualification_passes(TopGearRecomp *i){
    unsigned n,count;int p1=0,p2=0,need2;
    if(!i->mod_career_qualification_pending)return 1;
    i->mod_career_qualification_pending=0u;
    count=tg_mod_career_cutoff(word(i,0x1F06u));need2=word(i,0x1F04u)!=0u;
    for(n=0;n<count;n++){unsigned id=i->wram[0x1F12u+n];if(id==0u)p1=1;if(id==1u)p2=1;}
    return p1&&(!need2||p2);
}
/* Called after the native course increment; $1F04 temporarily holds human count.
   Standings use the same stable sorted ID order as the displayed points table. */
int tg_mod_career_country_passes(TopGearRecomp *i){
    unsigned next=word(i,0x1F06u),n,limit=next==8u?7u:next==16u?6u:next==24u?5u:20u;
    int p1=0,p2=0,pass;
    i->mod_career_password_award=0u;
    for(n=0;n<limit;n++){unsigned id=i->wram[0x1F62u+n];if(id==0u)p1=1;if(id==1u)p2=1;}
    pass=limit==20u||(p1&&(word(i,0x1F04u)<2u||p2));
    if(!pass){
        i->mod_continue_screen=5u;i->mod_continue_rally=0u;
        /* A failed checkpoint cannot unlock the next block through Retry. */
        (void)tg_bus_store16(i,0x1F06u,(uint16_t)(next-1u));
        return 0;
    }
    /* Keep points across the middle country of each eight-race section. */
    if(!(next&7u))memset(i->wram+0x1F4Eu,0,20u);
    i->mod_career_password_award=1u;
    return 1;
}
int tg_mod_career_password_stage(TopGearRecomp *i){
    const char *p;
    if(i->mod_time_trial_active||i->mod_rally_active||!i->mod_career_password_award)return 0;
    i->mod_career_password_award=0u;
    p=password(skill(i),word(i,0x1F06u));if(!p)return 0;
    memcpy(i->wram+0x68u,p,8u);return 1;
}
void tg_mod_career_password_submit(TopGearRecomp *i){
    unsigned course=(unsigned)i->mod_career_password_country*4u;
    const char *p=password(skill(i),course);
    int cancelled=i->mod_career_password_open==3u;
    int valid=!cancelled&&p&&!memcmp(i->wram+0x68u,p,8u);
    i->mod_career_password_error=(uint8_t)(!valid&&!cancelled);
    if(valid){
        i->mod_career_start_course=(uint8_t)course;i->mod_career_start_skill=(uint8_t)skill(i);
        (void)tg_bus_store16(i,0x1F06u,(uint16_t)course);(void)tg_bus_store16(i,0x1F08u,(uint16_t)course);
    }
    i->mod_menu_remodel_return_pending=1u;
    i->mod_menu_remodel_return_page=valid?15u:14u;
    i->mod_menu_remodel_return_selection=0u;
    if(valid)tg_mod_password_standings(i);
    i->mod_career_password_open=2u;
}
