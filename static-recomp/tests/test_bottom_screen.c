/* Uses the existing test_career_v2/test_definitive_features controller route.
   Race entry and settings changes use controller input. No forced finishes. */
#include "topgear_internal.h"
#include "../static-audio/topgear-bapu-aot/sc_static_apu.h"
#include "topgear_player_settings_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static TopGearRecomp *c;
static const char *dir;
static char error[256];
static unsigned commands[256],road,objects,hud;
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d: %s (%s)\n",__LINE__,#x,error);return 1;}}while(0)
static int frames(unsigned n,uint16_t b){TopGearRecompFrameResult r;while(n--){if(!topgear_recomp_advance_headless(c,b,0,1,&r)){snprintf(error,sizeof(error),"%s",topgear_recomp_last_error(c));return 0;}topgear_recomp_audio_clear(c);}return 1;}
static int press(uint16_t b){return frames(6,b)&&frames(90,0);}
static int shot(const char *name){char path[1024];FILE *f;unsigned p;snprintf(path,sizeof(path),"%s/%s.ppm",dir,name);f=fopen(path,"wb");if(!f)return 0;fprintf(f,"P6\n256 224\n255\n");for(p=0;p<256*224;p++){unsigned v=c->mode1_frame[p*2]|c->mode1_frame[p*2+1]<<8;uint8_t rgb[3]={(uint8_t)((v&31)*255/31),(uint8_t)(((v>>5)&31)*255/31),(uint8_t)(((v>>10)&31)*255/31)};fwrite(rgb,1,3,f);}return fclose(f)==0;}
static unsigned lit(unsigned first,unsigned last){unsigned n,v=0;for(n=first*512;n<last*512;n++)v+=c->mode1_frame[n]!=0;return v;}
static int hook(void *user,const TopGearHookEvent *e){(void)user;if(e->type==TOPGEAR_HOOK_EVENT_INSTRUCTION_BEFORE){if(e->address==0x7E2030u)road++;if(e->address==0x01856Cu)objects++;if(e->address==0x00CF36u||e->address==0x00D029u||e->address==0x00D067u||e->address==0x00D11Cu||e->address==0x00D23Fu||e->address==0x00D34Du||e->address==0x00D51Du)hud++;}return 0;}
static void audio_trace(uint64_t clock,unsigned port,uint8_t value){(void)clock;if(port==1&&c->cpu.pbr==0&&(c->cpu.pc==0x81AB||c->cpu.pc==0x81B3||c->cpu.pc==0xB959))commands[value]++;}
static int settings(void){return press(0x0800)&&press(0x0080)&&press(0x0400)&&press(0x0400)&&press(0x0400)&&press(0x0400);}
static unsigned w(unsigned a){return c->wram[a]|c->wram[a+1]<<8;}
int main(int argc,char **argv){
    uint8_t rom[524288],record[96],again[96],env,out;FILE *f;
    unsigned mode,off,n,top,bottom,tick,position;char root[1024],path[1024],name[80];
    int rally_two_only=argc==4&&!strcmp(argv[3],"--rally-two-only");
    if(argc!=3&&!rally_two_only)return 2;dir=argv[2];f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
    CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
    CHECK(frames(1560,0)&&frames(120,0x1000)&&frames(220,0));
    snprintf(root,sizeof(root),"%s/root.snap",dir);CHECK(topgear_recomp_snapshot_save(c,root,error,sizeof(error)));
    CHECK(settings());CHECK(c->mod_menu_remodel_page==12&&c->mod_menu_remodel_selection==4);
    CHECK(!c->mod_bottom_screen_off);CHECK(shot("settings-bottom-on"));
    CHECK(press(0x0100));CHECK(c->mod_bottom_screen_off&&tg_mod_bottom_screen_off(c));CHECK(shot("settings-bottom-off"));
    CHECK(frames(90,0x0100));CHECK(!c->mod_bottom_screen_off);CHECK(frames(90,0));
    CHECK(press(0x0200)&&c->mod_bottom_screen_off);
    CHECK(topgear_recomp_player_settings_export(c,record,sizeof(record))&&record[4]==6&&(record[95]&16));
    snprintf(path,sizeof(path),"%s/player-settings.dat",dir);memset(again,0,sizeof(again));CHECK(topgear_player_settings_save_file(c,path,again));
    c->mod_bottom_screen_off=0;CHECK(topgear_player_settings_load_file(c,path,again)&&c->mod_bottom_screen_off);
    snprintf(path,sizeof(path),"%s/off.snap",dir);
    CHECK(topgear_recomp_snapshot_save(c,path,error,sizeof(error)));c->mod_bottom_screen_off=0;
    CHECK(topgear_recomp_snapshot_load(c,path,error,sizeof(error))&&c->mod_bottom_screen_off);
    /* Every pre-2.0.1 settings generation imports with default On. */
    for(n=1;n<=5;n++){
        uint32_t hash=2166136261u;unsigned k;memcpy(again,record,96);again[4]=(uint8_t)n;again[95]=(uint8_t)(n==1?0:1);
        for(k=16;k<96;k++)hash=(hash^again[k])*16777619u;for(k=0;k<4;k++)again[12+k]=(uint8_t)(hash>>(k*8));
        CHECK(topgear_recomp_player_settings_import(c,again,96)&&!c->mod_bottom_screen_off);
    }
    for(n=0;n<32;n++){
        uint32_t hash=2166136261u;unsigned k;int valid=((n>>2)&3)<3;
        memcpy(again,record,96);again[95]=(uint8_t)n;
        for(k=16;k<96;k++)hash=(hash^again[k])*16777619u;for(k=0;k<4;k++)again[12+k]=(uint8_t)(hash>>(k*8));
        CHECK(topgear_recomp_player_settings_import(c,again,96)==valid);
        if(valid)CHECK(c->mod_bottom_screen_off==((n&16)!=0)&&c->mod_music_mode==((n>>2)&3)&&c->mod_audio_mute==((n&2)!=0));
    }
    CHECK(topgear_recomp_snapshot_load(c,root,error,sizeof(error))&&settings());
    /* Down wraps through Back and Up returns to the new row. */
    CHECK(press(0x0400)&&c->mod_menu_remodel_selection==5&&shot("settings-back"));
    CHECK(press(0x0400)&&c->mod_menu_remodel_selection==0);
    CHECK(press(0x0800)&&c->mod_menu_remodel_selection==5&&press(0x0080)&&c->mod_menu_remodel_page==0);
    puts("PASS menu: default On, left/right/A, held input debounce, wrap/Back; v1-v5 migration; physical settings and snapshot persistence");fflush(stdout);
    for(mode=rally_two_only?4u:0u;mode<5;mode++)for(off=0;off<2;off++){
        CHECK(topgear_recomp_snapshot_load(c,root,error,sizeof(error)));
        if(off){CHECK(settings()&&press(0x0080)&&c->mod_bottom_screen_off&&press(0x8000));}
        /* Settings returns to root row 3; move to the desired mode. */
        if(off){CHECK(press(0x0400));}
        if(mode==1||mode==4)CHECK(press(0x0400));
        if(mode==2)CHECK(press(0x0400)&&press(0x0400));
        CHECK(press(0x0080));
        if(mode>=3){
            CHECK(press(0x0100)&&w(0x1F04)!=0);
            CHECK(!tg_mod_bottom_screen_off(c));
            CHECK(press(0x8000)&&press(0x0800));
            if(mode==4)CHECK(press(0x0800));
            CHECK(press(0x0080)&&c->mod_menu_remodel_page==12);
            CHECK(press(0x0400)&&press(0x0400)&&press(0x0400)&&press(0x0400));
            CHECK(shot(mode==3?"settings-career-two-forced-on":"settings-rally-two-forced-on"));
            CHECK(press(0x0080)&&!tg_mod_bottom_screen_off(c));
            CHECK(c->mod_bottom_screen_off==off);
            CHECK(press(0x8000)&&press(0x0400));
            if(mode==4)CHECK(press(0x0400));
            CHECK(press(0x0080));
        }
        memset(commands,0,sizeof(commands));sc_static_apu_set_cpu_port_observer(audio_trace);
        CHECK(press(0x0400)&&press(0x0400));
        if(mode!=1&&mode!=4)CHECK(press(0x0400));
        CHECK(press(0x0080)&&frames(1900,0));
        CHECK(c->hdma_enable_mask==0x7F&&!c->mod_audio_menu_context);
        road=objects=hud=0;CHECK(topgear_recomp_set_hook(c,TOPGEAR_HOOK_MASK_INSTRUCTION,hook,NULL));
        tick=w(0x1EAE);position=w(0x1ED7);
        for(n=0;n<600;n++){
            CHECK(frames(1,(n%120)<110?(uint16_t)w(0x1F76):0));
            if(n>2&&off&&mode<3)CHECK(!lit(108,224));
        }
        topgear_recomp_clear_hook(c);sc_static_apu_set_cpu_port_observer(NULL);
        top=lit(0,108);bottom=lit(108,224);
        printf("Observed mode=%u off=%u top=%u bottom=%u timer=%u->%u position=%u->%u lower road=%u objects=%u\n",mode,off,top,bottom,tick,w(0x1EAE),position,w(0x1ED7),road,objects);fflush(stdout);
        CHECK(top>1000&&w(0x1EAE)>tick&&w(0x1ED7)!=position);
        CHECK((bottom==0)==(off&&mode<3));
        CHECK((road==0)==(off&&mode<3));CHECK((objects==0)==(off&&mode<3));
        CHECK((hud==0)==(off&&mode<3));
        CHECK(commands[2]&&commands[3]);
        if(mode<3){
            for(n=13;n<=22;n++)CHECK(!commands[n]);
            for(n=6;n<8;n++)CHECK(sc_static_apu_read_dsp_register((uint8_t)(n*16+8),&env)&&sc_static_apu_read_dsp_register((uint8_t)(n*16+9),&out)&&!env&&!out);
        }else CHECK(commands[13]&&commands[14]);
        snprintf(name,sizeof(name),"%s-%s",mode==0?"career":mode==1?"rally":mode==2?"trial":mode==3?"career-two": "rally-two",off?"off":"on");CHECK(shot(name));
        printf("PASS %s: top=%u bottom=%u lower road=%u objects=%u HUD=%u P1 audio=%u/%u P2=%u/%u; moving race timer/position\n",name,top,bottom,road,objects,hud,commands[2],commands[3],commands[13],commands[14]);fflush(stdout);
    }
    topgear_recomp_destroy(c);puts(rally_two_only?"PASS Bottom Screen Rally two-player override":"PASS Bottom Screen race/menu/persistence/2P matrix");return 0;
}
