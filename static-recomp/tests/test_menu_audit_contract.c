#include "topgear_internal.h"
#include "v22_reentry/topgear_v22_reentry_shards.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned failures;
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %u: %s\n",__LINE__,#x);failures++;}}while(0)

static void reset(TopGearRecomp *c,uint8_t *rom,unsigned page,unsigned row,unsigned players){
    memset(c,0,sizeof(*c));c->rom=rom;
    c->mod_menu_remodel_active=1u;c->mod_menu_remodel_page=(uint8_t)page;
    c->mod_menu_remodel_selection=(uint8_t)row;c->wram[0x1F04u]=(uint8_t)players;
    c->cpu.s=0x01FFu;c->cpu.pbr=0x0Fu;
}

int main(void){
    TopGearRecomp *c=(TopGearRecomp*)malloc(sizeof(*c));
    uint8_t *rom=(uint8_t*)calloc(1048576u,1u);
    static const uint16_t buttons[3]={0x0200u,0x0100u,0x0080u};
    static const uint16_t calls[3]={0x91AAu,0x9223u,0x9251u};
    static const uint16_t next[3]={0x91ADu,0x9226u,0x9254u};
    unsigned row,n,preference,dispatch,active,call,skill,dirty;uint16_t selection;
    if(!c||!rom){free(c);free(rom);return 2;}
    for(row=4u;row<=6u;row+=2u)for(preference=0;preference<2;preference++)for(n=0;n<3;n++){
        int action;
        reset(c,rom,12u,row,1u);
        c->mod_bottom_screen_off=(uint8_t)preference;c->rivals.extra_cpu_off=preference;
        action=tg_mod_menu_remodel_handle_input(c,buttons[n],&selection);
        CHECK(action==1);
        CHECK(c->mod_bottom_screen_off==preference&&c->rivals.extra_cpu_off==preference);
        CHECK(c->mod_menu_remodel_reserved==0u);
    }
    for(n=0;n<2;n++){
        reset(c,rom,9u,0u,0u);
        CHECK(tg_mod_menu_remodel_handle_input(c,n?0x0400u:0x0800u,&selection)==1);
        CHECK(selection==0u&&c->mod_menu_remodel_navigation_count==0u);
    }
    reset(c,rom,12u,5u,0u);
    CHECK(tg_mod_menu_remodel_handle_input(c,0x0100u,&selection)==1);
    CHECK(!c->mod_center_screen_enabled);
    reset(c,rom,9u,0u,0u);
    CHECK(tg_mod_music_input(c,0x0010u)==0x0010u&&c->mod_music_title==0u);
    for(skill=0;skill<3;skill++){
        reset(c,rom,14u,0u,0u);c->wram[0x1F10u]=(uint8_t)skill;
        tg_mod_menu_remodel_replace_layout(c);
        c->mod_menu_remodel_page=0u;tg_mod_menu_remodel_replace_layout(c);
        dirty=0u;for(n=3;n<=28;n++)dirty|=c->vram[(32u+n)*2u]|c->vram[(32u+n)*2u+1u];
        CHECK(dirty==0u);
    }
    reset(c,rom,1u,0u,0u);c->mod_center_screen_enabled=1u;c->mod_bottom_screen_off=1u;
    for(n=3;n<=28;n++){c->vram[(26u*32u+n)*2u]=0x2Cu;c->vram[(26u*32u+n)*2u+1u]=0x80u;}
    tg_mod_menu_remodel_replace_layout(c);
    dirty=0u;for(n=3;n<=28;n++)if(c->vram[(26u*32u+n)*2u]!=0x2Cu||c->vram[(26u*32u+n)*2u+1u]!=0x80u)dirty++;
    CHECK(dirty==0u);
    /* Long results totals must not write past the cleared 26-tile interior.
       This was visible as stray last-sector digits on the next leaderboard. */
    reset(c,rom,10u,0u,0u);c->mod_time_trial_completed_run_valid=1u;
    c->mod_time_trial_completed_run.required_laps=3u;
    c->mod_time_trial_completed_run.completed_laps=3u;
    c->mod_time_trial_completed_run.total_time_ticks=8822u;
    c->mod_time_trial_completed_run.best_sector1_ticks=1181u;
    c->mod_time_trial_completed_run.best_sector2_ticks=851u;
    c->mod_time_trial_completed_run.best_sector3_ticks=764u;
    for(n=4;n<=25;n++){c->vram[(n*32u+29u)*2u]=0x2Cu;c->vram[(n*32u+29u)*2u+1u]=0x80u;}
    tg_mod_menu_remodel_replace_layout(c);
    dirty=0u;for(n=4;n<=25;n++)if(c->vram[(n*32u+29u)*2u]!=0x2Cu||c->vram[(n*32u+29u)*2u+1u]!=0x80u)dirty++;
    CHECK(dirty==0u);
    CHECK(c->vram[(7u*32u+28u)*2u]==0x1Eu); /* Header ends with S3, unclipped. */
    /* Display-only preview/standings fixtures stop at the native start
       request. No generated instruction or race frame executes here. */
    reset(c,rom,13u,0u,0u);c->mod_rally_preview_frames=300u;
    c->mod_rally_preview_deadline=(uint32_t)topgear_recomp_v27_frame_count(c)+300u;
    CHECK(tg_mod_menu_remodel_handle_input(c,0x0080u,&selection)==1);
    CHECK(c->mod_menu_remodel_active&&!c->mod_rally_preview_released);
    CHECK(tg_mod_menu_remodel_handle_input(c,0u,&selection)==1);
    CHECK(tg_mod_menu_remodel_handle_input(c,0x0080u,&selection)==3);
    CHECK(!c->mod_menu_remodel_active);
    reset(c,rom,15u,0u,0u);c->controller_state[0]=0x0080u;
    CHECK(tg_mod_menu_remodel_handle_input(c,0x0080u,&selection)==1);
    c->controller_state[0]=0u;
    CHECK(tg_mod_menu_remodel_handle_input(c,0u,&selection)==1);
    c->controller_state[0]=0x0080u;
    CHECK(tg_mod_menu_remodel_handle_input(c,0x0080u,&selection)==3);
    CHECK(!c->mod_menu_remodel_active);
    /* Both dispatch engines replace the layout calls while active; shared
       original setup routines retain their normal call/stack semantics. */
    for(dispatch=0;dispatch<2;dispatch++)for(active=0;active<2;active++)for(call=0;call<3;call++){
        reset(c,rom,0u,0u,0u);c->mod_menu_remodel_active=(uint8_t)active;c->cpu.pc=calls[call];
        CHECK(dispatch?tg_v22_reentry_semantic_step(c):tg_v22_semantic_static_step_any(c));
        CHECK(c->cpu.pc==(active?next[call]:(call==2?0x9F88u:0x9F93u)));
        CHECK(c->cpu.s==(active?0x01FFu:0x01FDu));
        if(active)CHECK(!memcmp(c->vram,c->wram+0x0C6Cu,0x0800u));
    }
    free(rom);free(c);
    printf("%s menu audit contract: disabled two-player options, single-choice navigation, Center lock, R routing and both native call paths; failures=%u\n",failures?"FAIL":"PASS",failures);
    return failures?1:0;
}
