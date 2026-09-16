#include "topgear_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Synthetic RAM fixtures complement the natural headless controller route.
   Exercise the production renderer and semantic return hooks, not a copy. */
static void put16(TopGearRecomp *c,unsigned a,unsigned v){
    c->wram[a]=(uint8_t)v;c->wram[a+1u]=(uint8_t)(v>>8u);
}
static unsigned get16(TopGearRecomp *c,unsigned a){return (unsigned)c->wram[a]|((unsigned)c->wram[a+1u]<<8u);}
static int text_at(TopGearRecomp *c,unsigned x,unsigned y,const char *s){
    for(;*s;s++,x++){
        unsigned a=(y*32u+x)*2u;
        unsigned want=(*s>='A'&&*s<='Z')?(unsigned)(*s-'A'+1):
                      (*s>='0'&&*s<='9')?(unsigned)(*s-'0'+27):0u;
        if(c->vram[a]!=want||c->vram[a+1u])return 0;
    }
    return 1;
}
static int column(TopGearRecomp *c,unsigned x,unsigned y,const char *s){
    return text_at(c,x+(11u-(unsigned)strlen(s))/2u,y,s);
}
static int shortcut(TopGearRecomp *c,uint16_t button,uint16_t *sel){
    uint16_t routed=tg_mod_music_input(c,button);
    int result=tg_mod_menu_remodel_handle_input(c,routed,sel);
    (void)tg_mod_music_input(c,0u);
    (void)tg_mod_menu_remodel_handle_input(c,0u,sel);
    return result;
}
#define CHECK(expr) do { if(!(expr)){fprintf(stderr,"line %d: %s\n",__LINE__,#expr);ok=0;} } while(0)
int main(void){
    static const char *const cars[]={"CANNIBAL","SIDEWINDER","RAZOR","WEASEL"};
    static const unsigned car_addr[]={0x1F8Fu,0x1FACu};
    static const unsigned gear_addr[]={0x1F7Au,0x1F97u};
    static const unsigned ctrl_addr[]={0x1F76u,0x1F93u};
    static const unsigned career_y[]={5u,8u,11u,14u};
    TopGearRecomp *c=(TopGearRecomp*)calloc(1u,sizeof(*c));
    unsigned page,car,p,type,n;uint16_t sel=0u;int ok=1;
    if(!c)return 1;
    c->rom=(uint8_t*)calloc(0x100000u,1u);
    if(!c->rom){free(c);return 1;}
    for(type=0u;type<4u;type++){
        c->rom[0x6C656u+type*16u]=(uint8_t)(type+1u);
        c->rom[0x6C658u+type*16u]=(uint8_t)(type+5u);
        c->rom[0x6C65Au+type*16u]=(uint8_t)(0x10u+type);
        c->rom[0x6C65Cu+type*16u]=(uint8_t)(0x20u+type);
    }
    for(page=1u;page<=2u;page++)for(car=0u;car<4u;car++)for(type=0u;type<4u;type++){
        char control[]="TYPE A";
        c->mod_menu_remodel_active=1u;c->mod_menu_remodel_page=(uint8_t)page;
        c->mod_menu_remodel_selection=0u;
        put16(c,0x1F04u,1u);
        for(p=0u;p<2u;p++){
            put16(c,car_addr[p],(car+p)%4u);
            put16(c,gear_addr[p],0u);put16(c,gear_addr[p]+2u,p);
            put16(c,ctrl_addr[p],type+1u);put16(c,ctrl_addr[p]+2u,type+5u);
        }
        control[5]=(char)('A'+type);
        c->mod_menu_remodel_dirty=1u;tg_mod_menu_remodel_draw_if_dirty(c);
        if(car==0u&&type==0u){
            uint8_t title=c->mod_music_title;
            for(n=0u;n<4u;n++){
                c->mod_insert_audio_main_menu_active=1u;c->mod_insert_audio_sfx_state=0u;
                CHECK(shortcut(c,0x0010u,&sel)==1);
                CHECK((get16(c,0x1F8Fu)&3u)==((n+1u)&3u));
                CHECK(c->mod_music_title==title);
                CHECK(c->mod_insert_audio_sfx_state==7u&&c->mod_insert_audio_sfx_command==8u);
            }
            c->mod_insert_audio_sfx_state=0u;
            CHECK(shortcut(c,0x0020u,&sel)==1);
            CHECK(get16(c,0x1F7Au)==0x10u);
            CHECK(get16(c,0x1F7Cu)==0x20u);
            CHECK(c->mod_insert_audio_sfx_state==7u&&c->mod_insert_audio_sfx_command==8u);
            c->mod_insert_audio_sfx_state=0u;
            CHECK(shortcut(c,0x0020u,&sel)==1);
            CHECK(!(get16(c,0x1F7Au)|get16(c,0x1F7Cu)));
        }
        CHECK(column(c,3u,18u,"PLAYER 1"));CHECK(column(c,18u,18u,"PLAYER 2"));
        for(p=0u;p<2u;p++){
            unsigned x=p?18u:3u;
            CHECK(column(c,x,20u,cars[(car+p)%4u]));
            CHECK(column(c,x,22u,p?"MANUAL":"AUTO"));
            CHECK(column(c,x,24u,control));
        }
        /* Switching off P2 clears every old character, including long car names. */
        put16(c,0x1F04u,0u);c->mod_menu_remodel_dirty=1u;
        tg_mod_menu_remodel_draw_if_dirty(c);
        for(n=20u;n<=24u;n+=2u)CHECK(text_at(c,18u,n,"   NONE    "));
        /* Original setup action must restore the same page with fresh RAM. */
        CHECK(tg_mod_menu_remodel_handle_input(c,0x0080u,&sel)==0);
        CHECK(!c->mod_menu_remodel_active&&c->mod_menu_remodel_return_pending);
        put16(c,car_addr[0],(car+2u)%4u);
        CHECK(tg_mod_menu_remodel_main_menu_enter(c));
        CHECK(c->mod_menu_remodel_page==page);
        tg_mod_menu_remodel_draw_if_dirty(c);
        CHECK(column(c,3u,20u,cars[(car+2u)%4u]));
        for(n=0u;n<(page==1u?4u:3u);n++){
            CHECK(((unsigned)tg_mod_menu_remodel_selector_coord(c,(uint16_t)n,0u)>>8u)==
                  (page==1u?career_y[n]:6u+4u*n));
        }
        CHECK(tg_mod_menu_remodel_handle_input(c,0x0800u,&sel)==2);
        CHECK(sel==(page==1u?3u:2u));
        CHECK(tg_mod_menu_remodel_handle_input(c,0x0400u,&sel)==2&&sel==0u);
        CHECK(tg_mod_menu_remodel_handle_input(c,0x8000u,&sel)==2);
        tg_mod_menu_remodel_draw_if_dirty(c);
        CHECK(c->mod_menu_remodel_page==0u);
        CHECK(text_at(c,7u,24u,"DEFINITIVE EDITION"));
    }
    c->mod_menu_remodel_active=1u;c->mod_menu_remodel_page=3u;c->mod_menu_remodel_selection=2u;
    put16(c,0x1F8Fu,3u);put16(c,0x1F7Au,0u);put16(c,0x1F7Cu,0u);
    put16(c,0x1F76u,1u);put16(c,0x1F78u,5u);
    CHECK(shortcut(c,0x0010u,&sel)==1&&get16(c,0x1F8Fu)==0u);
    CHECK(shortcut(c,0x0020u,&sel)==1&&(get16(c,0x1F7Au)|get16(c,0x1F7Cu)));
    CHECK(shortcut(c,0x0020u,&sel)==1&&!(get16(c,0x1F7Au)|get16(c,0x1F7Cu)));
    CHECK(shortcut(c,0x0010u,&sel)==1&&shortcut(c,0x0020u,&sel)==1);
    {uint8_t record[96];c->mod_setup_initialized=1u;c->mod_setup_import_pending=0u;c->mod_setup_time_trial_active=1u;
     CHECK(topgear_recomp_player_settings_export(c,record,sizeof(record)));
     CHECK(record[92u]==1u&&(record[72u]|record[73u]|record[74u]|record[75u]));}
    free(c->rom);free(c);
    if(ok)puts("PASS: Career/Rally/Time Trial R-car and L-gear shortcuts, title-music isolation, cars, controls, inactive P2 clearing, setup returns, selector geometry and wrap");
    return ok?0:1;
}
