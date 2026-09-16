#include "topgear_internal.h"
#include <stdio.h>
#include "../static-audio/topgear-bapu-aot/sc_static_apu.h"
#include "topgear_v22_interrupt_dispatch.h"
#include <stdlib.h>
#include <string.h>
static TopGearRecomp *c;static const char *dir;static char error[256];
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d: %s (%s) PC=%02X:%04X page=%u sel=%u\n",__LINE__,#x,topgear_recomp_last_error(c),c->cpu.pbr,c->cpu.pc,c->mod_menu_remodel_page,c->mod_menu_remodel_selection);return 1;}}while(0)
extern int tg_v22_group_0021(TopGearRecomp *);
extern int tg_v22_reentry_group_0021_step(TopGearRecomp *);
extern int tg_v22_group_03E2(TopGearRecomp *);
extern int tg_v22_reentry_group_03E2_step(TopGearRecomp *);
extern int tg_v22_group_03E1(TopGearRecomp *);
extern int tg_v22_reentry_group_03E1_step(TopGearRecomp *);
static void put(unsigned a,unsigned v){c->wram[a]=(uint8_t)v;c->wram[a+1u]=(uint8_t)(v>>8u);}
static int frames(unsigned n,uint16_t b){TopGearRecompFrameResult a;while(n--){if(!topgear_recomp_advance_headless(c,b,0,1,&a))return 0;topgear_recomp_audio_clear(c);}return 1;}
static int press(uint16_t b){return frames(6,b)&&frames(90,0);}
static int shot(const char *name){char path[1024];uint8_t f[256*224*2];FILE *o;unsigned p;snprintf(path,sizeof(path),"%s/%s.ppm",dir,name);if(!topgear_recomp_v22_read_frame_bgr555(c,0,f,sizeof(f)))return 0;o=fopen(path,"wb");if(!o)return 0;fprintf(o,"P6\n256 224\n255\n");for(p=0;p<256*224;p++){unsigned v=f[p*2]|f[p*2+1]<<8;uint8_t rgb[3]={(uint8_t)((v&31)*255/31),(uint8_t)(((v>>5)&31)*255/31),(uint8_t)(((v>>10)&31)*255/31)};fwrite(rgb,1,3,o);}return fclose(o)==0;}
static int type_password(const char *text){
    unsigned n,x,y,tx,ty,k;
    /* Native keyboard A-F, G-L, M-R, S-X, Y/Z/delete/space/end. */
    for(n=0;n<=8u;n++){
        unsigned ch=n<8u?(unsigned)(text[n]-'A'):30u;
        tx=n<8u?ch%6u:4u;ty=n<8u?ch/6u:4u;
        x=((c->wram[0x48u]-4u)/4u);y=(c->wram[0x49u]-11u)/2u;
        for(k=0;k<8u&&y!=ty;k++){if(!press(y<ty?0x0400u:0x0800u))return 0;y=(c->wram[0x49u]-11u)/2u;}
        for(k=0;k<8u&&x!=tx;k++){if(!press(x<tx?0x0100u:0x0200u))return 0;x=(c->wram[0x48u]-4u)/4u;}
        if(!press(0x0080u))return 0;
    }
    return frames(120,0);
}
static unsigned commands[256];
static void audio_trace(uint64_t clock,unsigned port,uint8_t value){(void)clock;if(port==1u&&c->cpu.pbr==0u&&(c->cpu.pc==0x81ABu||c->cpu.pc==0x81B3u||c->cpu.pc==0xB959u))commands[value]++;}
static int audio_check(const char *root){
    unsigned mode,cmd,n;uint8_t env,out;TopGearCpuInternal saved;
    for(mode=0;mode<4;mode++){
        if(!topgear_recomp_snapshot_load(c,root,error,sizeof(error)))return 0;
        if(mode>=2&&!press(0x0400))return 0;
        if(mode==3&&!press(0x0400))return 0;
        if(!press(0x0080))return 0;
        put(0x1F04,mode==1);memset(commands,0,sizeof(commands));sc_static_apu_set_cpu_port_observer(audio_trace);
        if(!press(0x0400)||!press(0x0400)||(mode!=2&&!press(0x0400))||!press(0x0080)||!frames(1900,0))return 0;
        sc_static_apu_set_cpu_port_observer(NULL);
        printf("Live mode %u (Career solo/2P, Rally solo, TT): P1 start=%u update=%u; P2 start=%u update=%u\n",mode,commands[2],commands[3],commands[13],commands[14]);fflush(stdout);
        if(!commands[2]||!commands[3]||((commands[13]>0)!=(mode==1))||((commands[14]>0)!=(mode==1)))return 0;
        if(mode!=1){
            for(cmd=13;cmd<=22;cmd++)if(commands[cmd])return 0;
            for(n=6;n<8;n++){
                if(!sc_static_apu_read_dsp_register((uint8_t)(n*16+8),&env)||!sc_static_apu_read_dsp_register((uint8_t)(n*16+9),&out)||env||out)return 0;
            }
            if(!shot(mode==0?"career-solo-silent-cpu":mode==2?"rally-solo-silent-cpu":"tt-solo-silent-cpu"))return 0;
        }
    }
    /* Actual NMI command commit and acknowledgement, every command and mode.
       v14 mode observes bus writes without driving an unclocked APU. */
    saved=c->cpu;c->v14_post_audio_mode=1;
    for(mode=0;mode<4;mode++)for(cmd=0;cmd<32;cmd++){
        unsigned expected=mode!=1&&cmd>=13&&cmd<=22?0:cmd;
        put(0x1F04,mode==1);c->mod_time_trial_active=mode==2;c->mod_rally_active=mode==3;
        c->cpu.pbr=0;c->cpu.pc=0xB959;c->cpu.dbr=0;c->cpu.d=0;c->cpu.e=0;c->cpu.p=0x30;c->cpu.a=(uint16_t)cmd;
        if(!tg_v22_interrupt_semantic_step(c)||!tg_v22_interrupt_semantic_step(c)||c->scpu_to_smp[1]!=expected||c->wram[0x3D]!=expected)return 0;
    }
    c->cpu=saved;c->v14_post_audio_mode=0;c->mod_time_trial_active=0;c->mod_rally_active=0;
    puts("PASS solo CPU audio: live engine/voice checks and all NMI command/acknowledgement cases; 2P preserved; Rally and TT solo effects suppressed");return 1;
}
static int finish_check(void){
    unsigned n,wait,lit=0;uint8_t pixels[256*224*2];
    if(c->hdma_enable_mask!=0x7F)return 0;
    put(0x1EB0,9);if(!frames(3,0)||c->hdma_enable_mask!=0x7F)return 0;
    for(n=0;n<20;n++)c->wram[0x1F12+n]=(uint8_t)((n+2u)%20u);
    put(0x1EB0,10);
    for(wait=0;wait<600&&c->hdma_enable_mask==0x7F;wait++)if(!frames(1,0))return 0;
    if(wait==600||!frames(600,0)||!shot("ten-finishers-transition"))return 0;
    if(!topgear_recomp_v22_read_frame_bgr555(c,0,pixels,sizeof(pixels)))return 0;
    for(n=0;n<sizeof(pixels);n++)lit+=pixels[n]!=0;
    printf("Controlled tenth-finisher transition: %u frames, post-fade nonzero bytes=%u\n",wait,lit);fflush(stdout);
    return lit>1000u;
}
int main(int argc,char **argv){
    uint8_t rom[524288];FILE *f;unsigned s,course,rank,n,dispatch;char path[1024],name[64];
    static const char *codes[]={"REDLIGHT","LOWGEARS","DOWNHILL","ROADKILL"};
    int points_only=argc==4&&!strcmp(argv[3],"--points");
    int screens_only=points_only||(argc==4&&!strcmp(argv[3],"--screens"));
    int audio_only=argc==4&&!strcmp(argv[3],"--audio");
    int finish_only=argc==4&&!strcmp(argv[3],"--finish");
    if(argc!=3&&!screens_only&&!finish_only&&!audio_only)return 2;dir=argv[2];f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
    c=calloc(1,sizeof(*c));if(!c)return 2;
    /* Controlled RAM matrix: every track, skill, finishing place, both player counts. */
    for(s=0;s<3;s++)for(course=0;course<32;course++)for(rank=0;rank<20;rank++)for(n=0;n<2;n++){
        unsigned cutoff=course>=16u?5u:10u;
        put(0x1F10,s);put(0x1F06,course);put(0x1F04,n);memset(c->wram+0x1F12,2,20);
        c->wram[0x1F12+rank]=0;if(n)c->wram[0x1F12+(rank?0:1)]=1;
        c->mod_career_qualification_pending=1;
        CHECK(tg_mod_career_qualification_passes(c)==(rank<cutoff));
        CHECK(tg_mod_career_qualification_passes(c));
        if(n){memset(c->wram+0x1F12,2,20);c->wram[0x1F12]=0;c->wram[0x1F12+cutoff]=1;c->mod_career_qualification_pending=1;CHECK(!tg_mod_career_qualification_passes(c));}
        put(0x1F04,0);memset(c->wram+0x1F12,2,20);c->wram[0x1F12]=1;c->mod_career_qualification_pending=1;CHECK(!tg_mod_career_qualification_passes(c));
    }
    for(s=0;s<3;s++)for(course=0;course<32;course++){
        int allowed=s==0&&(course==8||course==16||course==24)||s==1&&course==16;
        put(0x1F10,s);put(0x1F06,course);c->mod_career_password_award=1;
        CHECK(tg_mod_career_password_stage(c)==allowed);CHECK(!tg_mod_career_password_stage(c));
        if(allowed)CHECK(!memcmp(c->wram+0x68,codes[s?3:course/8-1],8));
        CHECK(tg_mod_career_retry_course(c)==(s==0?course/8*8:s==1&&course>=16?16:0));
        for(n=0;n<4;n++){
            c->mod_career_password_country=(uint8_t)(course/4);memcpy(c->wram+0x68,codes[n],8);
            tg_mod_career_password_submit(c);
            CHECK(!c->mod_career_password_error==(s==0&&n<3&&course/4==(n+1)*2||s==1&&n==3&&course/4==4));
        }
    }
    for(dispatch=0;dispatch<2;dispatch++){
        int (*step)(TopGearRecomp *)=dispatch?tg_v22_reentry_group_0021_step:tg_v22_group_0021;
        for(n=9;dispatch&&n<=10;n++){memset(&c->cpu,0,sizeof(c->cpu));c->cpu.pbr=0;c->cpu.pc=0x8780;c->cpu.a=(uint16_t)n;CHECK(step(c));CHECK(step(c));CHECK(c->cpu.pc==(n==9?0x8785:0x8790));}
        step=dispatch?tg_v22_reentry_group_03E1_step:tg_v22_group_03E1;
        memset(&c->cpu,0,sizeof(c->cpu));c->cpu.pbr=15;c->cpu.pc=0x8750;put(0x1F04,1);put(0x1F06,4);
        CHECK(step(c)&&c->cpu.pc==0x877A);CHECK(step(c)&&c->wram[0x1F04]==0);
    }
    for(dispatch=0;dispatch<2;dispatch++)for(s=0;s<3;s++)for(course=0;course<32;course+=4)for(rank=0;rank<20;rank++)for(n=0;n<2;n++){
        unsigned k,limit=course==8?7:course==16?6:course==24?5:20;
        int pass=rank<limit;
        int (*step)(TopGearRecomp *)=dispatch?tg_v22_reentry_group_03E1_step:tg_v22_group_03E1;
        put(0x1F10,s);put(0x1F06,course);put(0x1F04,n+1);
        for(k=0;k<20;k++)c->wram[0x1F62+k]=(uint8_t)k;
        c->wram[0x1F62]=c->wram[0x1F62+rank];c->wram[0x1F62+rank]=0;
        memset(c->wram+0x1F4E,80,20);
        memset(&c->cpu,0,sizeof(c->cpu));c->cpu.pbr=15;c->cpu.pc=0x8750;
        CHECK(step(c)&&c->cpu.pc==0x877A&&tg_flag(c,TG_P_C)==!pass);
        CHECK(step(c)&&c->wram[0x1F04]==n);
        CHECK(c->wram[0x1F06]==(pass?course:course-1));
        CHECK(c->mod_career_password_award==pass);
        for(k=0;k<20;k++)CHECK(c->wram[0x1F4E + k]==(pass&&!(course&7)?0:80));
        if(!pass)CHECK(tg_mod_career_retry_course(c)<course&&!tg_mod_career_password_stage(c));
        /* CPU cannot substitute; nor can a qualifying P1 carry a failing P2. */
        if(limit<20){
            put(0x1F06,course);put(0x1F04,2);memset(c->wram+0x1F62,2,20);c->wram[0x1F62]=0;c->wram[0x1F62+limit]=1;
            CHECK(!tg_mod_career_country_passes(c));
            put(0x1F06,course);put(0x1F04,1);memset(c->wram+0x1F62,2,20);c->wram[0x1F62]=1;
            CHECK(!tg_mod_career_country_passes(c));
        }
    }
    puts("PASS checkpoint matrix: standings 7/6/5, eight-race point retention/reset, failure retry/password boundaries, both dispatches");
    for(dispatch=0;dispatch<2;dispatch++)for(n=0;n<=255;n++){
        int (*step)(TopGearRecomp *)=dispatch?tg_v22_reentry_group_03E2_step:tg_v22_group_03E2;
        memset(&c->cpu,0,sizeof(c->cpu));c->cpu.pbr=15;c->cpu.pc=0x8B7B;c->cpu.a=(uint16_t)n;
        snprintf(name,sizeof(name),"%3u PTS ",n);
        CHECK(step(c)&&c->cpu.pc==0x8B95&&!memcmp(c->wram+0x68,name,8));
    }
    for(s=0;s<3;s++)for(course=1;course<8;course++)for(n=0;n<21;n++){
        put(0x1F10,s);c->mod_career_password_country=(uint8_t)course;memcpy(c->wram+0x68,rom+0x6C513+n*8,8);
        tg_mod_career_password_submit(c);CHECK(c->mod_career_password_error&&c->wram[0x1F10]==s);
    }
    free(c);c=NULL;CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
    CHECK(frames(1560,0)&&frames(120,0x1000)&&frames(220,0));CHECK(shot("main-title"));
    snprintf(path,sizeof(path),"%s/root.snap",dir);CHECK(topgear_recomp_snapshot_save(c,path,error,sizeof(error)));
    if(audio_only){CHECK(audio_check(path));topgear_recomp_destroy(c);return 0;}
    if(finish_only){CHECK(press(0x0080)&&press(0x0400)&&press(0x0400)&&press(0x0400)&&press(0x0080)&&frames(1600,0));CHECK(finish_check());topgear_recomp_destroy(c);puts("PASS controlled tenth-finisher results capture");return 0;}
    if(!screens_only){for(s=0;s<3;s++){
        CHECK(topgear_recomp_snapshot_load(c,path,error,sizeof(error)));
        CHECK(press(0x0080)&&press(0x0400)&&press(0x0400)&&press(0x0080));
        CHECK(frames(240,0));for(n=0;n<s;n++)CHECK(press(0x0400));CHECK(press(0x0080));CHECK(c->wram[0x1F10]==s);CHECK(frames(240,0));
        CHECK(press(0x0800)&&press(0x0080));CHECK(c->mod_menu_remodel_page==14);
        for(n=0;n<(s==0?5u:s==1?3u:1u);n++){snprintf(name,sizeof(name),"country-skill-%u-row-%u",s,n);CHECK(shot(name));CHECK(press(0x0400));}
        CHECK(c->mod_menu_remodel_selection==0);CHECK(press(0x8000));CHECK(c->mod_menu_remodel_page==1);
    }
    for(n=0;n<4;n++){
        CHECK(topgear_recomp_snapshot_load(c,path,error,sizeof(error)));CHECK(press(0x0080));
        if(n==3){CHECK(press(0x0400)&&press(0x0400)&&press(0x0080)&&frames(240,0)&&press(0x0400)&&press(0x0080)&&frames(240,0)&&press(0x0800));}else CHECK(press(0x0400));
        CHECK(press(0x0080));for(s=0;s<(n==3?0:n);s++)CHECK(press(0x0400));
        CHECK(press(0x0080)&&frames(200,0));snprintf(name,sizeof(name),"password-entry-%u",n);CHECK(shot(name));
        CHECK(type_password(codes[n]));CHECK(!c->mod_career_password_error&&c->mod_menu_remodel_page==15);
        CHECK(c->mod_career_start_course==(n==3?16u:(n+1u)*8u));snprintf(name,sizeof(name),"password-accepted-%u",n);CHECK(shot(name));
        CHECK(c->wram[0x1F62+4]==0&&c->wram[0x1F4E]==32);
        CHECK(press(n==3?0x0010:0x0080));
        CHECK(frames(1600,0));CHECK(c->wram[0x1F06]==(n==3?16u:(n+1u)*8u));CHECK(c->wram[0x1F4E]==32);
        snprintf(name,sizeof(name),"password-race-start-%u",n);CHECK(shot(name));
        if(n==0)CHECK(finish_check());
    }
    /* Wrong password follows the real keyboard/return route and remains escapable. */
    CHECK(topgear_recomp_snapshot_load(c,path,error,sizeof(error)));CHECK(press(0x0080)&&press(0x0400)&&press(0x0080)&&press(0x0080)&&frames(200,0));
    CHECK(type_password("ROADKILL"));CHECK(c->mod_career_password_error&&c->mod_menu_remodel_page==14&&c->wram[0x1F10]==0);
    CHECK(shot("incorrect-password"));CHECK(press(0x8000)&&c->mod_menu_remodel_page==1);
    CHECK(press(0x0080)&&press(0x0080)&&frames(200,0));
    CHECK(press(0x8000)&&frames(240,0));CHECK(c->mod_menu_remodel_page==14&&!c->mod_career_password_error&&!c->mod_career_password_open);
    CHECK(shot("cancelled-password"));CHECK(press(0x8000)&&c->mod_menu_remodel_page==1);
    }
    CHECK(topgear_recomp_snapshot_load(c,path,error,sizeof(error)));
    c->mod_menu_remodel_active=0;put(0x1F04,0);put(0x1F06,7);
    for(n=0;n<20;n++)c->wram[0x1F4E + n]=(uint8_t)(140u-n*7u);
    memcpy(c->wram+0x1F86,"PLAYER 1",8);put(0x1FF6,0);put(0x1F00,0);put(0x1F02,1);
    for(n=0;n<20;n++)c->wram[0x1F12+n]=(uint8_t)n;
    c->cpu.pbr=15;c->cpu.pc=0x83D7;c->cpu.dbr=15;c->cpu.d=0;c->cpu.p=0;c->cpu.e=0;
    CHECK(frames(600,0)&&c->wram[0x1F4E]==160u&&shot("standings-points-results"));
    CHECK(press(0x0080)&&frames(300,0)&&shot("standings-three-digit-points"));
    if(points_only){topgear_recomp_destroy(c);puts("PASS points formatter 0-255 and native standings capture");return 0;}
    /* Execute the real race/standings branches, then render pass and fail windows. */
    for(course=8;course<=24;course+=8)for(s=0;s<2;s++){
        unsigned k,limit=course==8?7:course==16?6:5;
        CHECK(topgear_recomp_snapshot_load(c,path,error,sizeof(error)));
        c->mod_menu_remodel_active=0;put(0x1F10,0);put(0x1F04,0);put(0x1F06,course-1);
        for(k=0;k<20;k++){c->wram[0x1F62+k]=(uint8_t)k;c->wram[0x1F12+k]=(uint8_t)k;}
        rank=limit-1+s;c->wram[0x1F62]=(uint8_t)rank;c->wram[0x1F62+rank]=0;
        memset(c->wram+0x1F4E,80,20);c->mod_career_qualification_pending=1;
        c->cpu.pbr=15;c->cpu.pc=0x84A4;c->cpu.dbr=15;c->cpu.d=0;c->cpu.p=0;c->cpu.e=0;
        for(k=0;k<1000&&c->cpu.pc!=0x84F5;k++)CHECK(tg_v22_reentry_group_03E1_step(c));
        CHECK(k<1000&&c->cpu.a==(s?2:0)&&c->wram[0x1F06]==course-s);
        CHECK(c->mod_career_password_award==!s);
        CHECK(frames(450,0));snprintf(name,sizeof(name),"standings-after-%u-%s",course,s?"fail":"pass");CHECK(shot(name));
    }
    /* Controlled qualification-screen fixtures, separate from natural driving. */
    for(s=0;s<3;s++)for(course=4;course<=24;course+=4){
        CHECK(topgear_recomp_snapshot_load(c,path,error,sizeof(error)));
        c->mod_menu_remodel_active=0;c->mod_career_password_award=1;put(0x1F10,s);put(0x1F06,course);put(0x1FF8,1);
        c->cpu.pbr=15;c->cpu.pc=0x84F5;c->cpu.dbr=15;c->cpu.d=0;c->cpu.p=0;c->cpu.e=0;c->cpu.a=0;
        for(n=0;n<1200&&c->mod_career_password_award;n++)CHECK(frames(1,0));CHECK(n<1200);
        CHECK(frames(90,0));snprintf(name,sizeof(name),"qualification-skill-%u-after-%u",s,course);CHECK(shot(name));
    }
    topgear_recomp_destroy(c);puts(screens_only?"PASS Career v2 controlled qualification-screen fixtures and rule matrix":"PASS Career v2: all 32 track cutoffs, three skills, 1P/2P, four passwords, native typing/cancel and tenth-finisher transition");return 0;
}
