#define TG_MENU_ALL_PAGES_HELPERS_ONLY
#include "test_menu_all_pages.c"

static int type_code(const char *text){
    unsigned n,x,y,tx,ty,k;
    for(n=0;n<=8u;n++){
        unsigned ch=n<8u?(unsigned)(text[n]-'A'):30u;
        tx=n<8u?ch%6u:4u;ty=n<8u?ch/6u:4u;
        x=(core->wram[0x48u]-4u)/4u;y=(core->wram[0x49u]-11u)/2u;
        for(k=0;k<8&&y!=ty;k++){if(!button(y<ty?0x0400:0x0800))return 0;y=(core->wram[0x49u]-11u)/2u;}
        for(k=0;k<8&&x!=tx;k++){if(!button(x<tx?0x0100:0x0200))return 0;x=(core->wram[0x48u]-4u)/4u;}
        if(!button(0x0080))return 0;
    }
    return frames(120,0,1);
}
static unsigned word(unsigned a){return core->wram[a]|((unsigned)core->wram[a+1u]<<8);}
static int end_name(void){
    unsigned guard,pos;
    for(guard=0;guard<20;guard++){
        pos=word(0x48);
        if(pos==0x1314)return press(0x0080,0);
        if((pos>>8)!=0x13){if(!press(0x0400,0))return 0;}
        else if(!press((pos&255)<0x14?0x0100:0x0200,0))return 0;
    }
    fprintf(stderr,"END cursor failure: cursor=%04X owner=%u PC=%02X:%04X\n",word(0x48),word(0x81),core->cpu.pbr,core->cpu.pc);capture("native-two-player-failure");
    return 0;
}
int main(int argc,char **argv){
    uint8_t rom[524288];FILE *f;unsigned mode,skill,n,count,title,p,stage;
    char root[1024],name[64];
    static const uint16_t pad[4]={0x0800,0x0400,0x0200,0x0100};
    static const char *const codes[4]={"REDLIGHT","LOWGEARS","DOWNHILL","ROADKILL"};
    if(argc!=3&&argc!=4)return 2;output=argv[2];f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
    reference=(TopGearRecomp*)malloc(sizeof(*reference));
    REQUIRE(reference&&topgear_recomp_create(&core,rom,sizeof(rom),error,sizeof(error)));
    REQUIRE(frames(1560,0,0)&&frames(120,0x1000,0)&&frames(220,0,0));
    snprintf(root,sizeof(root),"%s/misc-root.snap",output);
    REQUIRE(topgear_recomp_snapshot_save(core,root,error,sizeof(error)));
    if(argc==4)goto two_player_only;
    title=core->mod_music_title;REQUIRE(button(0x0010)&&core->mod_music_title==(title+1)%3);
    printf("PASS Definitive Edition title-music shortcut retained\n");fflush(stdout);
    /* Original skill picker and Career country/password list in every skill. */
    for(mode=0;mode<2;mode++)for(skill=0;skill<3;skill++){
        REQUIRE(load_menu_snapshot(root));
        REQUIRE(choose(mode)&&button(0x0080)&&choose(mode?1u:2u)&&button(0x0080));
        REQUIRE(!core->mod_menu_remodel_active&&frames(240,0,0));
        for(n=0;n<3;n++)REQUIRE(button(0x0400));
        for(n=0;n<3;n++)REQUIRE(button(0x0800));
        REQUIRE(button(0x0200)&&button(0x0100));
        /* The original picker commits the chosen skill on confirmation. */
        for(n=0;n<skill;n++)REQUIRE(button(0x0400));
        REQUIRE(button(0x0080)&&frames(240,0,1)&&word(0x1F10)==skill);
        REQUIRE(core->mod_menu_remodel_active&&core->mod_menu_remodel_page==mode+1);
        if(!mode){
            REQUIRE(choose(1)&&button(0x0080)&&core->mod_menu_remodel_page==14);
            count=skill==0?5u:skill==1?3u:1u;
            REQUIRE(directions(count));snprintf(name,sizeof(name),"career-country-skill-%u",skill);capture(name);
            REQUIRE(button(0x8000)&&core->mod_menu_remodel_page==1);
        }
    }
    printf("PASS original skill menus: Career/Rally, all three skills; country/password lists, wrap, unavailable passwords and return paths\n");fflush(stdout);
    /* Actual native keyboard entry; stop at standings rather than start a race. */
    for(n=0;n<4;n++){
        REQUIRE(load_menu_snapshot(root)&&button(0x0080));
        if(n==3){
            REQUIRE(choose(2)&&button(0x0080)&&frames(240,0,0));
            REQUIRE(button(0x0400)&&button(0x0080)&&frames(240,0,1));
        }
        REQUIRE(choose(1)&&button(0x0080)&&core->mod_menu_remodel_page==14);
        REQUIRE(choose(n==3?0u:n)&&button(0x0080)&&frames(200,0,0));
        REQUIRE(!core->mod_menu_remodel_active&&type_code(codes[n]));
        REQUIRE(core->mod_menu_remodel_page==15&&!core->mod_career_password_error);
        REQUIRE(core->mod_career_start_course==(n==3?16u:(n+1u)*8u));
        snprintf(name,sizeof(name),"password-standings-%u",n);capture(name);
    }
    REQUIRE(load_menu_snapshot(root)&&button(0x0080)&&choose(1)&&button(0x0080));
    REQUIRE(button(0x0080)&&frames(200,0,0)&&type_code("ROADKILL"));
    REQUIRE(core->mod_menu_remodel_page==14&&core->mod_career_password_error);
    REQUIRE(button(0x8000)&&core->mod_menu_remodel_page==1);
    REQUIRE(choose(1)&&button(0x0080)&&button(0x0080)&&frames(200,0,0));
    for(n=0;n<4;n++)REQUIRE(button(pad[n]));
    REQUIRE(button(0x8000)&&frames(240,0,1)&&core->mod_menu_remodel_page==14&&!core->mod_career_password_error);
    REQUIRE(button(0x8000)&&core->mod_menu_remodel_page==1);
    printf("PASS password keyboard: four valid codes, incorrect code, cancel and standings displays; no race started\n");fflush(stdout);
two_player_only:
    /* Two humans traverse both complete native player configuration flows. */
    for(mode=0;mode<2;mode++){
        REQUIRE(load_menu_snapshot(root)&&choose(mode)&&button(0x0080));
        REQUIRE(button(0x0100)&&word(0x1F04)&&button(0x0080)&&!core->mod_menu_remodel_active);
        both_native_controllers=1;REQUIRE(frames(240,0,0));
        for(p=0;p<2;p++){
            printf("TWO PLAYER mode=%u stageplayer=%u cursor=%04X owner=%u PC=%02X:%04X\n",mode,p,word(0x48),word(0x81),core->cpu.pbr,core->cpu.pc);fflush(stdout);
            /* Two-player setup first opens the native P1/P2/Exit chooser. */
            for(n=0;n<3;n++)REQUIRE(press(0x0400,0));
            for(n=0;n<3;n++)REQUIRE(press(0x0800,0));
            for(n=0;n<6&&word(0x5A)!=p;n++)REQUIRE(press(0x0400,0));
            REQUIRE(word(0x5A)==p&&press(0x0080,0)&&frames(240,0,0));
            for(n=0;n<4;n++)REQUIRE(press(pad[n],0));
            REQUIRE(end_name());
            for(stage=0;stage<3;stage++){
                snprintf(name,sizeof(name),"native-two-%u-p%u-stage%u",mode,p,stage);capture(name);
                for(n=0;n<4;n++)REQUIRE(press(pad[n],0));
                REQUIRE(press(0x0080,0));
            }
        }
        for(n=0;n<6&&word(0x5A)!=2u;n++)REQUIRE(press(0x0400,0));
        REQUIRE(word(0x5A)==2u&&press(0x0080,0)&&frames(240,0,1));
        both_native_controllers=0;
        REQUIRE(core->mod_menu_remodel_active&&core->mod_menu_remodel_page==mode+1&&word(0x1F04));
        printf("PASS two-player %s setup: both name/gear/control/car flows, all D-pad directions, return to custom menu\n",mode?"Rally":"Career");fflush(stdout);
    }
    /* Real Rally preview, observed without allowing its automatic race start. */
    REQUIRE(load_menu_snapshot(root)&&choose(1)&&button(0x0080)&&choose(2)&&button(0x0080));
    REQUIRE(core->mod_menu_remodel_page==13&&frames(30,0,1));capture("rally-preview");
    for(n=0;n<8;n++)REQUIRE(core->mod_rally_schedule[n]<32);
    printf("PASS Rally preview displayed; its skip/automatic-start contract is checked separately without advancing a race\n");
    for(n=0;n<17;n++)if(page_checks[n])printf("page=%u frames=%u mismatching_frames=%u\n",n,page_checks[n],page_bad[n]);
    printf("%s misc menus: %u completed frames; mismatching_frames=%u; no Time Trial race started\n",bad_frames?"FAIL":"PASS",checked,bad_frames);
    topgear_recomp_destroy(core);free(reference);return bad_frames?1:0;
}
