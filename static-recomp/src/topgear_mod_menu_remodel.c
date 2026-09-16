#include "topgear_internal.h"

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* First-stage Top Gear menu remodel prototype.

   This is intentionally a core-owned menu-state extension, not a frontend
   overlay.  The original OPTIONS renderer establishes the Mode-1 background,
   border, font graphics and selector sprite.  This module reuses those exact
   assets and replaces only the BG1 tilemap text inside the existing frame.

   New root:
       CAREER
       RALLY
       TIME TRIAL
       SETTINGS (speed units)

   CAREER:
       1 PLAYER / 2 PLAYERS
       COUNTRY
       SKILL LEVEL
       START

   TIME TRIAL (one player only):
       PLAYER 1
       COUNTRY
       LEADERBOARD
       START
   COUNTRY and LEADERBOARD both drill down country -> one of four tracks.

   RALLY is now a real Stage-2 prototype:
       1 PLAYER / 2 PLAYERS
       SKILL LEVEL
       START
   START generates an eight-race schedule containing exactly one course from
   each country, using the game's canonical 0..31 global course ordinal.  The
   first selected course is installed before the existing PLAY GAME semantic
   action constructs the pre-race screen. Time Trial uses the same proved
   course ordinals but has separate records and progression semantics. */

enum {
    TG_REMODEL_PAGE_ROOT = 0,
    TG_REMODEL_PAGE_CAREER = 1,
    TG_REMODEL_PAGE_RALLY = 2,
    TG_REMODEL_PAGE_TIME_TRIAL = 3,
    TG_REMODEL_PAGE_TT_COUNTRY = 4,
    TG_REMODEL_PAGE_TT_TRACK = 5,
    TG_REMODEL_PAGE_TT_LEADERBOARD_COUNTRY = 6,
    TG_REMODEL_PAGE_TT_LEADERBOARD_TRACK = 7,
    TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL = 8,
    TG_REMODEL_PAGE_TT_LEADERBOARD_CAR = 9,
    TG_REMODEL_PAGE_TT_POST_RACE_DETAIL = 10,
    TG_REMODEL_PAGE_TT_POST_RACE_LEADERBOARD = 11,
    TG_REMODEL_PAGE_SETTINGS = 12,
    TG_REMODEL_PAGE_RALLY_TRACKS = 13,
    TG_REMODEL_PAGE_CAREER_COUNTRY = 14,
    TG_REMODEL_PAGE_PASSWORD_STANDINGS = 15,
    TG_REMODEL_PAGE_TT_CARS = 16
};

enum {
    TG_REMODEL_INPUT_PASSTHROUGH = 0,
    TG_REMODEL_INPUT_HANDLED = 1,
    TG_REMODEL_INPUT_REDRAW_SELECTOR = 2
};

#define TG_BTN_B      UINT16_C(0x8000)
#define TG_BTN_UP     UINT16_C(0x0800)
#define TG_BTN_DOWN   UINT16_C(0x0400)
#define TG_BTN_LEFT   UINT16_C(0x0200)
#define TG_BTN_RIGHT  UINT16_C(0x0100)
#define TG_BTN_START  UINT16_C(0x1000)
#define TG_BTN_A      UINT16_C(0x0080)
#define TG_BTN_L      UINT16_C(0x0020)
#define TG_BTN_R      UINT16_C(0x0010)

static void vram_word(TopGearRecomp *i,unsigned x,unsigned y,uint16_t word){
    uint32_t a;
    if(!i||x>=32u||y>=32u)return;
    a=((uint32_t)y*32u+(uint32_t)x)*2u;
    i->vram[a]=(uint8_t)(word&0xFFu);
    i->vram[a+1u]=(uint8_t)(word>>8u);
}

static uint16_t glyph_base(char c){
    unsigned n;
    if(c==' ')return UINT16_C(0x0080);
    if(c=='1')return UINT16_C(0x00E8);
    if(c=='2')return UINT16_C(0x00EA);
    if(c<'A'||c>'Z')return UINT16_C(0x0080);
    n=(unsigned)(c-'A');
    if(n<7u)return (uint16_t)(0x0082u+n*2u);
    if(n<15u)return (uint16_t)(0x00A0u+(n-7u)*2u);
    if(n<23u)return (uint16_t)(0x00C0u+(n-15u)*2u);
    return (uint16_t)(0x00E0u+(n-23u)*2u);
}

static unsigned text_x(const char *text){
    size_t n=text?strlen(text):0u;
    unsigned tiles=(unsigned)(n*2u);
    if(tiles>=28u)return 3u;
    return (32u-tiles)/2u;
}

static void draw_text(TopGearRecomp *i,unsigned x,unsigned y,const char *text){
    size_t n,j;
    if(!i||!text)return;
    n=strlen(text);
    for(j=0u;j<n&&x+1u<30u;j++,x+=2u){
        uint16_t t=glyph_base(text[j]);
        vram_word(i,x,y,t);
        vram_word(i,x+1u,y,(uint16_t)(t+1u));
        vram_word(i,x,y+1u,(uint16_t)(t+16u));
        vram_word(i,x+1u,y+1u,(uint16_t)(t+17u));
    }
}

static void draw_centered(TopGearRecomp *i,unsigned y,const char *text){
    draw_text(i,text_x(text),y,text);
}

static uint16_t small_glyph_word(char c){
    /* The original compact white/results font is already resident in the
       menu VRAM character set at BG1-relative tile numbers $01-$28 (absolute VRAM tiles $101-$128). */
    if(c>='A'&&c<='Z')return (uint16_t)(0x0001u+(unsigned)(c-'A'));
    if(c>='0'&&c<='9')return (uint16_t)(0x001Bu+(unsigned)(c-'0'));
    if(c=='-')return UINT16_C(0x002C);
    if(c=='.')return UINT16_C(0x0028);
    if(c==':')return UINT16_C(0x0025);
    return 0u;
}

static void draw_small_text(TopGearRecomp *i,unsigned x,unsigned y,const char *text){
    size_t n,j;
    if(!i||!text||y>=32u)return;
    n=strlen(text);
    for(j=0u;j<n&&x<30u;j++,x++)vram_word(i,x,y,small_glyph_word(text[j]));
}


static void draw_small_center_in_column(TopGearRecomp *i,unsigned x,unsigned width,unsigned y,const char *text){
    size_t n=text?strlen(text):0u;
    unsigned off=0u;
    if(n<(size_t)width)off=(width-(unsigned)n)/2u;
    draw_small_text(i,x+off,y,text);
}

static void clear_menu_text_area(TopGearRecomp *i){
    unsigned x,y;
    if(!i)return;
    /* Rebuild the title break in the existing frame, then clear only the
       interior BG1 text area.  Vertical/bottom border tiles remain untouched. */
    for(x=3u;x<=28u;x++){
        vram_word(i,x,2u,0u);
        vram_word(i,x,3u,UINT16_C(0x002C));
    }
    for(y=4u;y<=25u;y++)for(x=3u;x<=28u;x++)vram_word(i,x,y,0u);
}

static uint16_t read_word(TopGearRecomp *i,uint32_t address){
    uint16_t v=0u;
    (void)tg_bus_read16(i,address,&v);
    return v;
}

static void copy_setup(TopGearRecomp *i,unsigned player,uint8_t data[26],int restore){
    unsigned base=player?0x1F93u:0x1F76u;
    if(restore){
        memcpy(i->wram+base,data,24u);
        memcpy(i->wram+base+25u,data+24u,2u);
    }else{
        memcpy(data,i->wram+base,24u);
        memcpy(data+24u,i->wram+base+25u,2u);
    }
}

static void activate_setup(TopGearRecomp *i,int time_trial){
    if(i->mod_setup_import_pending){
        copy_setup(i,0u,i->mod_setup_shared[0],1);
        copy_setup(i,1u,i->mod_setup_shared[1],1);
        (void)tg_bus_store16(i,0x1F04u,i->mod_setup_shared_players);
        (void)tg_bus_store16(i,0x1FB0u,i->mod_settings_kph?0xFFFFu:0u);
        i->mod_setup_import_pending=0u;
        i->mod_setup_time_trial_active=0u;
    }
    if(!i->mod_setup_initialized){
        i->mod_settings_kph=1u;
        (void)tg_bus_store16(i,0x1FB0u,0xFFFFu);
        copy_setup(i,0u,i->mod_setup_shared[0],0);
        copy_setup(i,1u,i->mod_setup_shared[1],0);
        memcpy(i->mod_setup_time_trial,i->mod_setup_shared[0],26u);
        i->mod_setup_initialized=1u;
    }
    if(time_trial&&!i->mod_setup_time_trial_active){
        copy_setup(i,0u,i->mod_setup_shared[0],0);
        copy_setup(i,1u,i->mod_setup_shared[1],0);
        i->mod_setup_shared_players=read_word(i,0x1F04u);
        i->mod_setup_shared_courses[0]=read_word(i,0x1F06u);
        i->mod_setup_shared_courses[1]=read_word(i,0x1F08u);
        copy_setup(i,0u,i->mod_setup_time_trial,1);
        i->mod_setup_time_trial_active=1u;
    }else if(!time_trial&&i->mod_setup_time_trial_active){
        copy_setup(i,0u,i->mod_setup_time_trial,0);
        copy_setup(i,0u,i->mod_setup_shared[0],1);
        copy_setup(i,1u,i->mod_setup_shared[1],1);
        (void)tg_bus_store16(i,0x1F04u,i->mod_setup_shared_players);
        (void)tg_bus_store16(i,0x1F06u,i->mod_setup_shared_courses[0]);
        (void)tg_bus_store16(i,0x1F08u,i->mod_setup_shared_courses[1]);
        i->mod_setup_time_trial_active=0u;
    }
    if(i->mod_profile_pending_mask){
        if(i->mod_profile_pending_mask&1u)memcpy(i->mod_setup_shared[0],i->mod_profile_pending[0],26u);
        if(i->mod_profile_pending_mask&2u)memcpy(i->mod_setup_time_trial,i->mod_profile_pending[1],26u);
        if(i->mod_profile_pending_mask&(time_trial?2u:1u))copy_setup(i,0u,time_trial?i->mod_setup_time_trial:i->mod_setup_shared[0],1);
        i->mod_profile_pending_mask=0u;
    }
    if(time_trial)(void)tg_bus_store16(i,0x1F04u,0u);
}

static uint32_t settings_checksum(const uint8_t *data){
    uint32_t hash=UINT32_C(2166136261);unsigned n;
    for(n=16u;n<TOPGEAR_PLAYER_SETTINGS_SIZE;n++)hash=(hash^data[n])*UINT32_C(16777619);
    return hash;
}

int topgear_recomp_player_settings_export(TopGearRecomp *i,void *dst,size_t capacity){
    uint8_t *b=(uint8_t*)dst;
    if(!i||!b||capacity<TOPGEAR_PLAYER_SETTINGS_SIZE||!i->mod_setup_initialized||
       i->mod_setup_import_pending||!i->mod_menu_remodel_active)return 0;
    if(i->mod_setup_time_trial_active)copy_setup(i,0u,i->mod_setup_time_trial,0);
    else{
        copy_setup(i,0u,i->mod_setup_shared[0],0);copy_setup(i,1u,i->mod_setup_shared[1],0);
        i->mod_setup_shared_players=read_word(i,0x1F04u);
    }
    i->mod_settings_kph=(uint8_t)(read_word(i,0x1FB0u)!=0u);
    return topgear_recomp_profile_record(i,b,capacity);
}

static void profile_defaults(TopGearRecomp *i){
    unsigned n;if(i->mod_setup_initialized)return;
    for(n=0;n<2;n++){
        memset(i->mod_setup_shared[n],0,26u);memcpy(i->mod_setup_shared[n],i->rom+0x6C656u,16u);
        memset(i->mod_setup_shared[n]+16u,' ',8u);
    }
    memcpy(i->mod_setup_time_trial,i->mod_setup_shared[0],26u);
    memcpy(i->mod_setup_shared[0]+16u,"PLAYER 1",8u);
    memcpy(i->mod_setup_time_trial+16u,"PLAYER 1",8u);
    i->mod_settings_kph=1u;i->mod_setup_initialized=1u;i->mod_setup_import_pending=1u;
}
int topgear_recomp_profile_record(TopGearRecomp *i,void *dst,size_t capacity){
    uint8_t *b=(uint8_t*)dst;uint32_t hash;unsigned n;
    if(!i||!b||capacity<TOPGEAR_PLAYER_SETTINGS_SIZE)return 0;
    profile_defaults(i);
    memset(b,0,TOPGEAR_PLAYER_SETTINGS_SIZE);memcpy(b,"TGPS",4u);b[4]=5u;b[8]=96u;
    memcpy(b+16u,i->mod_setup_shared,52u);memcpy(b+68u,i->mod_setup_time_trial,26u);
    if(i->mod_profile_pending_mask&1u)memcpy(b+16u,i->mod_profile_pending[0],26u);
    if(i->mod_profile_pending_mask&2u)memcpy(b+68u,i->mod_profile_pending[1],26u);
    b[94]=(uint8_t)(i->mod_setup_shared_players?1u:0u);
    b[95]=(uint8_t)((i->mod_settings_kph!=0u)|(i->mod_audio_mute?2u:0u)|((i->mod_music_mode%3u)<<2u));
    hash=settings_checksum(b);for(n=0u;n<4u;n++)b[12u+n]=(uint8_t)(hash>>(8u*n));
    return 1;
}
int topgear_recomp_profile_read(TopGearRecomp *i,unsigned bank,TopGearPlayerProfile *p){
    uint8_t b[96];const uint8_t *data;unsigned n;
    if(!i||bank>1u||!p)return 0;
    if(!topgear_recomp_player_settings_export(i,b,sizeof(b))&&!topgear_recomp_profile_record(i,b,sizeof(b)))return 0;
    data=b+(bank?68u:16u);memcpy(p->name,data+16u,8u);p->name[8]=0;
    p->car=data[24];p->manual=(uint8_t)((data[4]|data[5]|data[6]|data[7])!=0u);p->controls=0;
    for(n=0;n<4;n++)if(!memcmp(data,i->rom+0x6C656u+n*16u,4u))p->controls=(uint8_t)n;
    return 1;
}
int topgear_recomp_profile_write(TopGearRecomp *i,unsigned bank,const TopGearPlayerProfile *p){
    uint8_t *data;unsigned n;TopGearPlayerProfile old;
    if(!i||bank>1u||!p||p->car>3u||p->controls>3u||p->manual>1u||p->name[8])return 0;
    for(n=0;n<8&&p->name[n];n++)if(!((p->name[n]>='A'&&p->name[n]<='Z')||(p->name[n]>='0'&&p->name[n]<='9')||p->name[n]==' '))return 0;
    if(!topgear_recomp_profile_read(i,bank,&old))return 0;
    data=i->mod_profile_pending[bank];memcpy(data,i->rom+0x6C656u+p->controls*16u,16u);
    if(!p->manual)memset(data+4u,0,4u);
    memset(data+16u,' ',8u);memcpy(data+16u,p->name,strlen(p->name));data[24]=p->car;data[25]=0u;
    i->mod_profile_pending_mask|=(uint8_t)(1u<<bank);
    if(i->mod_menu_remodel_active){activate_setup(i,i->mod_setup_time_trial_active);i->mod_menu_remodel_dirty=1u;}
    return 1;
}

int topgear_recomp_player_settings_import(TopGearRecomp *i,const void *src,size_t size){
    const uint8_t *b=(const uint8_t*)src;uint32_t hash=0u;unsigned n;
    if(!i||!b||size!=TOPGEAR_PLAYER_SETTINGS_SIZE||memcmp(b,"TGPS",4u)||
       (b[4]!=1u&&b[4]!=2u&&b[4]!=3u&&b[4]!=4u&&b[4]!=5u)||b[5]||b[6]||b[7]||b[8]!=96u||b[9]||b[10]||b[11]||b[94]>1u||b[95]>(b[4]==5u?11u:b[4]==4u?7u:b[4]==3u?3u:1u)||(b[4]==1u&&b[95]))return 0;
    for(n=0u;n<4u;n++)hash|=(uint32_t)b[12u+n]<<(8u*n);
    if(hash!=settings_checksum(b))return 0;
    for(n=0u;n<3u;n++)if(b[16u+n*26u+24u]>3u||b[16u+n*26u+25u])return 0;
    i->mod_profile_pending_mask=0u;
    memcpy(i->mod_setup_shared,b+16u,52u);memcpy(i->mod_setup_time_trial,b+68u,26u);
    i->mod_settings_kph=b[4]==1u?1u:(b[95]&1u);
    i->mod_music_mode=(uint8_t)(b[4]>=4u?((b[95]>>2u)&3u):0u);
    i->mod_audio_mute=(uint8_t)(b[4]>=3u&&((b[95]&2u)!=0u));
    i->mod_setup_shared_players=b[94];i->mod_setup_initialized=1u;
    i->mod_setup_import_pending=1u;
    return 1;
}

static int post_race_page(const TopGearRecomp *i){
    return i&&(i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_POST_RACE_DETAIL||
               i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_POST_RACE_LEADERBOARD);
}

static void render_post_race_footer(TopGearRecomp *i){
    if(topgear_recomp_time_trial_completed_run_pending(i)){
        draw_small_center_in_column(i,3u,26u,22u,"SAVING TIME DATA");
        return;
    }
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_POST_RACE_LEADERBOARD)
        draw_centered(i,24u,"FINISH");
    else{
        draw_small_center_in_column(i,3u,26u,21u,"RETRY   TRACKS   CARS");
        draw_small_center_in_column(i,3u,26u,24u,"LEADERBOARD   MAIN MENU");
    }
}

static const char *root_speed_label(TopGearRecomp *i){
    return read_word(i,UINT32_C(0x001FB0))?"SPEED KPH":"SPEED MPH";
}

static const char *career_player_label(TopGearRecomp *i){
    return read_word(i,UINT32_C(0x001F04))?"2 PLAYERS":"1 PLAYER";
}

static const char *summary_car_label(TopGearRecomp *i,unsigned player){
    static const char *const names[4]={"CANNIBAL","SIDEWINDER","RAZOR","WEASEL"};
    uint32_t a=player?UINT32_C(0x001FAC):UINT32_C(0x001F8F);
    unsigned v=(unsigned)(read_word(i,a)&UINT16_C(0x0003));
    return names[v];
}

static unsigned summary_control_type(TopGearRecomp *i,unsigned player){
    uint32_t live=player?UINT32_C(0x001F93):UINT32_C(0x001F76);
    uint16_t w0=read_word(i,live),w1=read_word(i,live+2u);
    unsigned type;
    for(type=0u;type<4u;type++){
        uint32_t rom=UINT32_C(0x0DC656)+(uint32_t)(type*0x10u);
        if(w0==read_word(i,rom)&&w1==read_word(i,rom+2u))return type;
    }
    return 4u;
}

static void setup_shortcut(TopGearRecomp *i,uint16_t input){
    if(input&TG_BTN_R){
        unsigned car=(unsigned)(read_word(i,UINT32_C(0x001F8F))&3u);
        (void)tg_bus_store16(i,UINT32_C(0x001F8F),(uint16_t)((car+1u)&3u));
    }else if(input&TG_BTN_L){
        uint16_t lo=read_word(i,UINT32_C(0x001F7A));
        uint16_t hi=read_word(i,UINT32_C(0x001F7C));
        if(lo|hi){
            (void)tg_bus_store16(i,UINT32_C(0x001F7A),0u);
            (void)tg_bus_store16(i,UINT32_C(0x001F7C),0u);
        }else{
            unsigned type=summary_control_type(i,0u);
            uint32_t rom=UINT32_C(0x0DC65A)+(uint32_t)((type<4u?type:0u)*0x10u);
            (void)tg_bus_store16(i,UINT32_C(0x001F7A),read_word(i,rom));
            (void)tg_bus_store16(i,UINT32_C(0x001F7C),read_word(i,rom+2u));
        }
    }
    tg_mod_insert_audio_accept(i);
    i->mod_menu_remodel_dirty=1u;
    i->mod_menu_remodel_reserved=1u;
}

static const char *summary_gear_label(TopGearRecomp *i,unsigned player){
    uint32_t a=player?UINT32_C(0x001F97):UINT32_C(0x001F7A);
    uint16_t lo=read_word(i,a);
    uint16_t hi=read_word(i,a+2u);
    return (lo|hi)?"MANUAL":"AUTO";
}

static const char *summary_control_label(TopGearRecomp *i,unsigned player){
    static const char *const names[4]={"TYPE A","TYPE B","TYPE C","TYPE D"};
    unsigned type=summary_control_type(i,player);
    return type<4u?names[type]:"TYPE ?";
}

static const char *const tt_country_names[8]={
    "USA","SOUTH AMERICA","JAPAN","GERMANY","SCANDINAVIA","FRANCE","ITALY","UK"
};
static const char *const tt_track_names[32]={
    "LAS VEGAS","LOS ANGELES","NEW YORK","SAN FRANCISCO",
    "RIO","MACHU PICCHU","CHICHEN ITZA","RAIN FOREST",
    "TOKYO","HIROSHIMA","YOKOHAMA","KYOTO",
    "MUNICH","COLOGNE","BLACK FOREST","FRANKFURT",
    "STOCKHOLM","COPENHAGEN","HELSINKI","OSLO",
    "PARIS","NICE","BORDEAUX","MONACO",
    "PISA","ROME","SICILY","FLORENCE",
    "LONDON","SHEFFIELD","LOCH NESS","STONEHENGE"
};

static void tt_player_name(TopGearRecomp *i,char out[9]){
    unsigned n; uint8_t b=0u;
    for(n=0u;n<8u;n++){
        if(!tg_bus_read8(i,UINT32_C(0x001F86)+n,&b))b=(uint8_t)' ';
        if(!((b>='A'&&b<='Z')||(b>='0'&&b<='9')))b=(uint8_t)' ';
        out[n]=(char)b;
    }
    out[8]='\0';
}

static void render_time_trial_summary(TopGearRecomp *i){
    char line[31],name[9];
    unsigned course=i->mod_time_trial_selected_course<32u?i->mod_time_trial_selected_course:0u;
    tt_player_name(i,name);
    (void)snprintf(line,sizeof(line),"NAME: %s",name); draw_small_text(i,4u,17u,line);
    (void)snprintf(line,sizeof(line),"CAR: %s",summary_car_label(i,0u)); draw_small_text(i,4u,19u,line);
    (void)snprintf(line,sizeof(line),"GEARBOX: %s",summary_gear_label(i,0u)); draw_small_text(i,4u,21u,line);
    (void)snprintf(line,sizeof(line),"CONTROLS: %s",summary_control_label(i,0u)); draw_small_text(i,4u,23u,line);
    (void)snprintf(line,sizeof(line),"TRACK: %s",tt_track_names[course]); draw_small_text(i,4u,25u,line);
}

static void format_total_ticks(uint32_t ticks,char out[9]){
    uint32_t sec=ticks/60u,rem=ticks%60u,ms=(rem*1000u+30u)/60u,min;
    if(ms>=1000u){ms=0u;sec++;}
    min=sec/60u;
    /* Keep the eight-column table truthful for slow runs too. */
    if(min>=100u)(void)snprintf(out,9u,"%3u:%02u",(unsigned)min,(unsigned)(sec%60u));
    else if(min>=10u)(void)snprintf(out,9u,"%2u:%02u.%02u",(unsigned)min,(unsigned)(sec%60u),(unsigned)(ms/10u));
    else (void)snprintf(out,9u,"%u:%02u.%03u",(unsigned)min,(unsigned)(sec%60u),(unsigned)ms);
}

static void format_sector_ticks(uint32_t ticks,char out[5]){
    uint32_t tenths=(uint32_t)(((uint64_t)ticks*10u+30u)/60u);
    if(tenths>999u)(void)snprintf(out,5u,"%3uS",(unsigned)((ticks+30u)/60u));
    else (void)snprintf(out,5u,"%2u.%1u",(unsigned)(tenths/10u),(unsigned)(tenths%10u));
}

static const char *tt_car_label_id(unsigned car){
    static const char *const names[4]={"CANNIBAL","SIDEWINDER","RAZOR","WEASEL"};
    return car<4u?names[car]:"UNKNOWN";
}

static const char *tt_gear_label_id(unsigned gearbox){
    return gearbox?"MANUAL":"AUTO";
}

static void format_run_name(const TopGearTimeTrialRun *run,char out[9]){
    int end=8; unsigned n;
    if(!run){out[0]='\0';return;}
    for(n=0u;n<8u;n++){
        char c=run->name[n];
        if(!((c>='A'&&c<='Z')||(c>='0'&&c<='9')||c==' '))c=' ';
        out[n]=c;
    }
    while(end>0&&out[end-1]==' ')end--;
    out[end]='\0';
}

static void render_leaderboard_entries(TopGearRecomp *i,unsigned course,int car_filter){
    unsigned row;
    char line[31],name[9],t[9],s1[5],s2[5],s3[5];
    TopGearTimeTrialRun run;
    draw_small_center_in_column(i,3u,26u,4u,tt_track_names[course]);
    draw_small_text(i,3u,5u,"     TIME    S1   S2   S3");
    for(row=0u;row<5u;row++){
        unsigned base=6u+row*3u;
        memset(&run,0,sizeof(run));
        if(!topgear_recomp_time_trial_query_leaderboard(i,course,car_filter,row,&run)){
            draw_small_center_in_column(i,3u,26u,base,"NO RECORD");
            draw_small_center_in_column(i,3u,26u,base+1u,
                                        "0:00:000  00.0 00.0 00.0");
            continue;
        }
        format_run_name(&run,name);
        (void)snprintf(line,sizeof(line),"%s %s %s",name,
                       tt_car_label_id(run.car_id),tt_gear_label_id(run.gearbox));
        draw_small_center_in_column(i,3u,26u,base,line);
        format_total_ticks(run.total_time_ticks,t);
        format_sector_ticks(run.best_sector1_ticks,s1);
        format_sector_ticks(run.best_sector2_ticks,s2);
        format_sector_ticks(run.best_sector3_ticks,s3);
        (void)snprintf(line,sizeof(line),"%s  %s %s %s",t,s1,s2,s3);
        draw_small_center_in_column(i,3u,26u,base+1u,line);
    }
}

static void render_post_race_detail(TopGearRecomp *i){
    TopGearTimeTrialRun run;
    char line[31],name[9],t[9],s1[5],s2[5],s3[5];
    unsigned lap,course;
    if(!topgear_recomp_time_trial_completed_run(i,&run)){
        draw_small_center_in_column(i,3u,26u,10u,"NO COMPLETED RUN");
        render_post_race_footer(i);
        return;
    }
    course=run.course<32u?run.course:0u;
    draw_small_center_in_column(i,3u,26u,4u,tt_track_names[course]);
    format_run_name(&run,name);
    (void)snprintf(line,sizeof(line),"%s %s %s",name,
                   tt_car_label_id(run.car_id),tt_gear_label_id(run.gearbox));
    draw_small_center_in_column(i,3u,26u,5u,line);
    draw_small_text(i,3u,7u,"       TIME    S1   S2   S3");
    if(run.total_time_ticks)format_total_ticks(run.total_time_ticks,t);else (void)snprintf(t,sizeof(t),"0:00:000");
    if(run.best_sector1_ticks)format_sector_ticks(run.best_sector1_ticks,s1);else (void)snprintf(s1,sizeof(s1),"00.0");
    if(run.best_sector2_ticks)format_sector_ticks(run.best_sector2_ticks,s2);else (void)snprintf(s2,sizeof(s2),"00.0");
    if(run.best_sector3_ticks)format_sector_ticks(run.best_sector3_ticks,s3);else (void)snprintf(s3,sizeof(s3),"00.0");
    (void)snprintf(line,sizeof(line),"   %s  %s %s %s",t,s1,s2,s3);
    draw_small_text(i,3u,8u,line);
    (void)snprintf(line,sizeof(line),"LAPS: %u",(unsigned)run.required_laps);
    draw_small_text(i,3u,10u,line);
    draw_small_text(i,3u,11u,"LAP TIME     S1   S2   S3");
    for(lap=0u;lap<run.required_laps&&lap<8u;lap++){
        if(lap<run.completed_laps&&run.lap_time_ticks[lap])format_total_ticks(run.lap_time_ticks[lap],t);else (void)snprintf(t,sizeof(t),"0:00:000");
        if(lap<run.completed_laps&&run.lap_sector1_ticks[lap])format_sector_ticks(run.lap_sector1_ticks[lap],s1);else (void)snprintf(s1,sizeof(s1),"00.0");
        if(lap<run.completed_laps&&run.lap_sector2_ticks[lap])format_sector_ticks(run.lap_sector2_ticks[lap],s2);else (void)snprintf(s2,sizeof(s2),"00.0");
        if(lap<run.completed_laps&&run.lap_sector3_ticks[lap])format_sector_ticks(run.lap_sector3_ticks[lap],s3);else (void)snprintf(s3,sizeof(s3),"00.0");
        (void)snprintf(line,sizeof(line),"L%u %s %s %s %s",lap+1u,t,s1,s2,s3);
        draw_small_text(i,3u,12u+lap,line);
    }
    render_post_race_footer(i);
}

/* Career and Rally share canonical player setup, including the inactive-P2
   rule. Keep one renderer so a setup change is reflected identically in both. */
static void render_player_setup_summary(TopGearRecomp *i){
    int two_players=read_word(i,UINT32_C(0x001F04))!=0u;
    const unsigned left_x=3u,left_w=11u,sep_x=15u,right_x=18u,right_w=11u;
    draw_small_center_in_column(i,left_x,left_w,18u,"PLAYER 1");
    draw_small_text(i,sep_x,18u,":");
    draw_small_center_in_column(i,right_x,right_w,18u,"PLAYER 2");

    draw_small_center_in_column(i,left_x,left_w,20u,summary_car_label(i,0u));
    draw_small_text(i,sep_x,20u,":");
    draw_small_center_in_column(i,right_x,right_w,20u,two_players?summary_car_label(i,1u):"NONE");

    draw_small_center_in_column(i,left_x,left_w,22u,summary_gear_label(i,0u));
    draw_small_text(i,sep_x,22u,":");
    draw_small_center_in_column(i,right_x,right_w,22u,two_players?summary_gear_label(i,1u):"NONE");

    draw_small_center_in_column(i,left_x,left_w,24u,summary_control_label(i,0u));
    draw_small_text(i,sep_x,24u,":");
    draw_small_center_in_column(i,right_x,right_w,24u,two_players?summary_control_label(i,1u):"NONE");
}

static unsigned page_item_count(const TopGearRecomp *i){
    if(!i)return 0u;
    switch(i->mod_menu_remodel_page){
    case TG_REMODEL_PAGE_SETTINGS:return 5u;
    case TG_REMODEL_PAGE_CAREER_COUNTRY:{unsigned n=tg_mod_career_password_count(i);return n?n+2u:1u;}
    case TG_REMODEL_PAGE_PASSWORD_STANDINGS:
    case TG_REMODEL_PAGE_RALLY_TRACKS:return 0u;
    case TG_REMODEL_PAGE_ROOT:return 4u;
    case TG_REMODEL_PAGE_CAREER:return 4u;
    case TG_REMODEL_PAGE_RALLY:return 3u;
    case TG_REMODEL_PAGE_TIME_TRIAL:return 4u;
    case TG_REMODEL_PAGE_TT_COUNTRY:return 8u;
    case TG_REMODEL_PAGE_TT_TRACK:return 4u;
    case TG_REMODEL_PAGE_TT_LEADERBOARD_COUNTRY:return 8u;
    case TG_REMODEL_PAGE_TT_LEADERBOARD_TRACK:return 4u;
    case TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL:return 3u;
    case TG_REMODEL_PAGE_TT_LEADERBOARD_CAR:return 1u;
    case TG_REMODEL_PAGE_TT_POST_RACE_DETAIL:return 5u;
    case TG_REMODEL_PAGE_TT_POST_RACE_LEADERBOARD:return 1u;
    case TG_REMODEL_PAGE_TT_CARS:return 4u;
    default:return 0u;
    }
}

static unsigned row_y_for(const TopGearRecomp *i,unsigned selection){
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_CAREER_COUNTRY){unsigned n=tg_mod_career_password_count(i);return selection<n?8u+selection*3u:(n&&selection==n?19u:23u);}
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_POST_RACE_DETAIL){
        static const unsigned rows[5]={24u,21u,21u,21u,24u};
        return rows[selection<5u?selection:0u];
    }
    if(post_race_page(i))return 24u;
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_SETTINGS){static const unsigned rows[5]={5u,8u,11u,16u,23u};return rows[selection<5u?selection:0u];}
    unsigned count=page_item_count(i);
    static const unsigned y1[1]={18u};
    static const unsigned y2[2]={12u,16u};
    static const unsigned y3[3]={10u,14u,18u};
    static const unsigned y4[4]={8u,12u,16u,20u};
    if(count==1u){
        if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_LEADERBOARD_CAR||
           i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_POST_RACE_DETAIL||
           i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_POST_RACE_LEADERBOARD)return 24u;
        return y1[0];
    }
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL)return 24u;
    if(count==8u&&selection<8u)return 5u+selection*2u;
    if(count==2u&&selection<2u)return y2[selection];
    if(count==3u&&selection<3u){
        static const unsigned rally_y3[3]={6u,10u,14u};
        if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_RALLY)return rally_y3[selection];
        return y3[selection];
    }
    if(count==4u&&selection<4u){
        /* Four two-tile rows, with a blank row between choices. The final
           choice ends at row 15, leaving rows 18-24 for the shared summary. */
        static const unsigned career_y4[4]={5u,8u,11u,14u};
        static const unsigned tt_y4[4]={4u,7u,10u,13u};
        if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_CAREER)return career_y4[selection];
        if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_TIME_TRIAL)return tt_y4[selection];
        return y4[selection];
    }
    return 14u;
}

static const char *page_item_label(TopGearRecomp *i,unsigned selection){
    if(!i)return "";
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_CAREER_COUNTRY){unsigned n=tg_mod_career_password_count(i);if(selection<n){unsigned country=tg_mod_career_password_country(i,selection);return country==2u?"JAPAN":country==4u?"SCANDINAVIA":"ITALY";}return n&&selection==n?"START OVER":"BACK";}
    switch(i->mod_menu_remodel_page){
    case TG_REMODEL_PAGE_ROOT:
        switch(selection){case 0u:return "CAREER";case 1u:return "RALLY";case 2u:return "TIME TRIAL";case 3u:return "SETTINGS";default:return "";}
    case TG_REMODEL_PAGE_SETTINGS:return selection==0u?root_speed_label(i):selection==1u?(i->mod_audio_mute?"MUTE: ON":"MUTE: OFF"):selection==2u?"CAREER MUSIC":selection==3u?"MUSIC PLAYER":"BACK";
    case TG_REMODEL_PAGE_CAREER:
        switch(selection){case 0u:return career_player_label(i);case 1u:return "COUNTRY";case 2u:return "SKILL LEVEL";case 3u:return "START";default:return "";}
    case TG_REMODEL_PAGE_RALLY:
        switch(selection){case 0u:return career_player_label(i);case 1u:return "SKILL LEVEL";case 2u:return "START";default:return "";}
    case TG_REMODEL_PAGE_TIME_TRIAL:
        switch(selection){case 0u:return "PLAYER 1";case 1u:return "COUNTRY";case 2u:return "LEADERBOARD";case 3u:return "START";default:return "";}
    case TG_REMODEL_PAGE_TT_COUNTRY:
    case TG_REMODEL_PAGE_TT_LEADERBOARD_COUNTRY:
        return selection<8u?tt_country_names[selection]:"";
    case TG_REMODEL_PAGE_TT_TRACK:
    case TG_REMODEL_PAGE_TT_LEADERBOARD_TRACK:{
        unsigned country=i->mod_time_trial_country&7u;
        return selection<4u?tt_track_names[country*4u+selection]:"";
    }
    case TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL:
        switch(selection){case 0u:return "OVERALL";case 1u:return "CAR";case 2u:return "BACK";default:return "";}
    case TG_REMODEL_PAGE_TT_LEADERBOARD_CAR:return selection==0u?"BACK":"";
    case TG_REMODEL_PAGE_TT_POST_RACE_DETAIL:
        switch(selection){case 0u:return "LEADERBOARD";case 1u:return "RETRY";case 2u:return "TRACKS";case 3u:return "CARS";case 4u:return "MAIN MENU";default:return "";}
    case TG_REMODEL_PAGE_TT_POST_RACE_LEADERBOARD:return "FINISH";
    case TG_REMODEL_PAGE_TT_CARS:
        switch(selection){case 0u:return "CANNIBAL";case 1u:return "SIDEWINDER";case 2u:return "RAZOR";case 3u:return "WEASEL";default:return "";}
    default:return "";
    }
}

static const char *page_title(const TopGearRecomp *i){
    if(!i)return "OPTIONS";
    switch(i->mod_menu_remodel_page){
    case TG_REMODEL_PAGE_SETTINGS:return "SETTINGS";
    case TG_REMODEL_PAGE_ROOT:return "OPTIONS";
    case TG_REMODEL_PAGE_CAREER:return "CAREER";
    case TG_REMODEL_PAGE_RALLY:return "RALLY";
    case TG_REMODEL_PAGE_TIME_TRIAL:return "TIME TRIAL";
    case TG_REMODEL_PAGE_TT_COUNTRY:return "COUNTRY";
    case TG_REMODEL_PAGE_TT_TRACK:return "TRACK";
    case TG_REMODEL_PAGE_TT_LEADERBOARD_COUNTRY:return "LEADERBOARD";
    case TG_REMODEL_PAGE_TT_LEADERBOARD_TRACK:return "TRACK";
    case TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL:
    case TG_REMODEL_PAGE_TT_LEADERBOARD_CAR:
    case TG_REMODEL_PAGE_TT_POST_RACE_LEADERBOARD:return "LEADERBOARD";
    case TG_REMODEL_PAGE_TT_POST_RACE_DETAIL:return "RESULTS";
    case TG_REMODEL_PAGE_TT_CARS:return "CARS";
    default:return "OPTIONS";
    }
}

static void render_page(TopGearRecomp *i){
    unsigned count,n,course;
    if(!i||!i->mod_menu_remodel_active)return;
    clear_menu_text_area(i);
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_PASSWORD_STANDINGS){
        draw_small_center_in_column(i,3u,26u,1u,"CURRENT STANDINGS");
        for(n=0;n<20;n++){
            char name[9],line[32];unsigned id=i->wram[0x1F62u+n];
            if(id==0u)memcpy(name,i->wram+0x1F86u,8);else if(id==1u&&read_word(i,0x1F04u))memcpy(name,i->wram+0x1FA3u,8);
            else memcpy(name,i->rom+0x6C47Bu+(id==1u?18u:id-2u)*8u,8);
            name[8]=0;for(course=0;course<8;course++)if(!((name[course]>='A'&&name[course]<='Z')||(name[course]>='0'&&name[course]<='9')))name[course]=' ';
            if(id<2u&&!memcmp(name,"        ",8))memcpy(name,id?"PLAYER 2":"PLAYER 1",8);
            snprintf(line,sizeof(line),"%2u %.8s %3u PTS",n+1u,name,i->wram[0x1F4Eu+id]);draw_small_text(i,5u,4u+n,line);
        }
        draw_small_center_in_column(i,3u,26u,25u,"PRESS ANY BUTTON");
        i->mod_menu_remodel_dirty=0u;i->mod_menu_remodel_render_count++;return;
    }
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_RALLY_TRACKS){
        draw_small_center_in_column(i,3u,26u,2u,"SELECTED TRACKS");
        for(n=0u;n<8u;n++){
            char line[32];
            snprintf(line,sizeof(line),"%u - %s",n+1u,tt_track_names[i->mod_rally_schedule[n]&31u]);
            draw_small_text(i,4u,5u+n*2u,line);
        }
        draw_small_center_in_column(i,3u,26u,24u,"RACE STARTS AUTOMATICALLY");
        i->mod_menu_remodel_dirty=0u;
        i->mod_menu_remodel_render_count++;
        return;
    }
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_ROOT){draw_small_text(i,7u,24u,"DEFINITIVE EDITION");}
    else if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_CAREER_COUNTRY){
        draw_centered(i,1u,tg_mod_career_skill_name(i));draw_centered(i,4u,"DIFFICULTY");
        if(!tg_mod_career_password_count(i))draw_small_center_in_column(i,3u,26u,12u,"NO PASSWORDS");
        if(i->mod_career_password_error)draw_small_center_in_column(i,3u,26u,17u,"INCORRECT PASSWORD");
    }else draw_centered(i,2u,page_title(i));
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_CAREER||
       i->mod_menu_remodel_page==TG_REMODEL_PAGE_RALLY)render_player_setup_summary(i);
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_TIME_TRIAL)render_time_trial_summary(i);
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL){
        course=i->mod_time_trial_times_course<32u?i->mod_time_trial_times_course:0u;
        render_leaderboard_entries(i,course,-1);
        draw_small_text(i,5u,24u,"OVERALL");
        draw_small_text(i,13u,24u,"-");draw_small_text(i,15u,24u,"CAR");
        draw_small_text(i,20u,24u,"-");draw_small_text(i,23u,24u,"BACK");
    }else if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_LEADERBOARD_CAR){
        course=i->mod_time_trial_times_course<32u?i->mod_time_trial_times_course:0u;
        render_leaderboard_entries(i,course,(int)(i->mod_time_trial_leaderboard_car&3u));
        draw_small_center_in_column(i,3u,26u,21u,tt_car_label_id(i->mod_time_trial_leaderboard_car&3u));
        draw_small_center_in_column(i,3u,26u,24u,"PRESS L   BACK   PRESS R");
    }else if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_POST_RACE_DETAIL){
        render_post_race_detail(i);
    }else if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_POST_RACE_LEADERBOARD){
        course=i->mod_time_trial_times_course<32u?i->mod_time_trial_times_course:0u;
        render_leaderboard_entries(i,course,-1);
        draw_small_center_in_column(i,3u,26u,21u,"OVERALL TOP 5");
        render_post_race_footer(i);
    }else{
        count=page_item_count(i);
        for(n=0u;n<count;n++)draw_centered(i,row_y_for(i,n),page_item_label(i,n));
    }
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_SETTINGS){
        if(i->mod_menu_remodel_selection==3u){
            draw_small_center_in_column(i,3u,26u,19u,tg_mod_music_player_label(i));
            draw_small_center_in_column(i,3u,26u,21u,i->mod_music_player_state==2u?"A PLAY   LEFT RIGHT TRACK":"A STOP   LEFT RIGHT TRACK");
        }
        draw_small_text(i,text_x(page_item_label(i,1u))+8u,row_y_for(i,1u),":");
        draw_small_text(i,28u,row_y_for(i,2u),":");
        draw_small_center_in_column(i,3u,26u,row_y_for(i,2u)+2u,i->mod_music_mode==2u?"CLASSIC":i->mod_music_mode==1u?"RANDOM":"COMPLETE");
    }
    i->mod_menu_remodel_dirty=0u;
    i->mod_menu_remodel_render_count++;
}

static void set_page(TopGearRecomp *i,uint8_t page,uint8_t selection){
    if(!i)return;
    i->mod_menu_remodel_page=page;
    i->mod_menu_remodel_selection=selection;
    i->mod_menu_remodel_dirty=1u;
    (void)tg_bus_store16(i,(uint32_t)((i->cpu.d+0x5Au)&0xFFFFu),selection);
}

int tg_mod_menu_remodel_main_menu_enter(TopGearRecomp *i){
    uint8_t page=TG_REMODEL_PAGE_ROOT,selection=0u;
    if(!i)return 0;
    if(i->mod_menu_remodel_return_pending){
        page=i->mod_menu_remodel_return_page;
        selection=i->mod_menu_remodel_return_selection;
        i->mod_menu_remodel_return_pending=0u;
    }
    i->mod_menu_remodel_active=1u;
    activate_setup(i,(page>=TG_REMODEL_PAGE_TIME_TRIAL&&page<=TG_REMODEL_PAGE_TT_POST_RACE_LEADERBOARD)||
                     page==TG_REMODEL_PAGE_TT_CARS);
    tg_mod_career_validate_start(i);
    /* Custom post-race returns bypass the stock $0F:84B5/$84B8 scroll
       reset. Restore its two-write BG1VOFS operation so text and OBJ
       selectors use the same menu coordinates after real race results. */
    (void)tg_bus_write8(i,UINT32_C(0x00210E),0u);
    (void)tg_bus_write8(i,UINT32_C(0x00210E),0u);
    i->mod_menu_remodel_page=page;
    i->mod_menu_remodel_selection=selection;
    i->mod_menu_remodel_dirty=1u;
    (void)tg_bus_store16(i,(uint32_t)((i->cpu.d+0x5Au)&0xFFFFu),selection);
    return 1;
}

void tg_mod_menu_remodel_draw_if_dirty(TopGearRecomp *i){
    if(i&&i->mod_menu_remodel_active&&i->mod_menu_remodel_dirty)render_page(i);
}

static void schedule_return(TopGearRecomp *i,uint8_t page,uint8_t selection){
    i->mod_menu_remodel_return_pending=1u;
    i->mod_menu_remodel_return_page=page;
    i->mod_menu_remodel_return_selection=selection;
}

static int passthrough_original_action(TopGearRecomp *i,uint16_t original_row,
                                       uint8_t return_page,uint8_t return_selection,
                                       int return_after){
    if(!i)return TG_REMODEL_INPUT_HANDLED;
    if(return_after)schedule_return(i,return_page,return_selection);
    else i->mod_menu_remodel_return_pending=0u;
    i->mod_menu_remodel_active=0u;
    (void)tg_bus_store16(i,(uint32_t)((i->cpu.d+0x5Au)&0xFFFFu),original_row);
    return TG_REMODEL_INPUT_PASSTHROUGH;
}

static int begin_career(TopGearRecomp *i){
    tg_mod_career_validate_start(i);tg_bus_store16(i,0x1F06u,i->mod_career_start_course);tg_bus_store16(i,0x1F08u,i->mod_career_start_course);
    i->mod_career_qualification_pending=0u;tg_mod_attempt_begin(i);tg_mod_career_panel_start(i);tg_mod_insert_audio_start_race(i);
    return passthrough_original_action(i,4u,TG_REMODEL_PAGE_ROOT,0u,0);
}

static int move_selection(TopGearRecomp *i,int delta,uint16_t *selection_out){
    unsigned count,current,next;
    if(!i||!selection_out)return TG_REMODEL_INPUT_HANDLED;
    count=page_item_count(i);
    if(count==0u)return TG_REMODEL_INPUT_HANDLED;
    current=i->mod_menu_remodel_selection;
    if(current>=count)current=0u;
    if(delta<0)next=current?current-1u:count-1u;
    else next=(current+1u)%count;
    i->mod_menu_remodel_selection=(uint8_t)next;
    i->mod_menu_remodel_dirty=1u;
    (void)tg_bus_store16(i,(uint32_t)((i->cpu.d+0x5Au)&0xFFFFu),(uint16_t)next);
    *selection_out=(uint16_t)next;
    if(next!=current)tg_mod_insert_audio_navigation(i);
    i->mod_menu_remodel_navigation_count++;
    return TG_REMODEL_INPUT_REDRAW_SELECTOR;
}

static int move_post_race_detail(TopGearRecomp *i,uint16_t input,uint16_t *selection_out){
    static const uint8_t left[5]={4u,3u,1u,2u,0u};
    static const uint8_t right[5]={4u,2u,3u,1u,0u};
    static const uint8_t vertical[5]={1u,0u,4u,4u,3u};
    unsigned current=i->mod_menu_remodel_selection<5u?i->mod_menu_remodel_selection:0u;
    unsigned next=(input&TG_BTN_LEFT)?left[current]:(input&TG_BTN_RIGHT)?right[current]:vertical[current];
    set_page(i,TG_REMODEL_PAGE_TT_POST_RACE_DETAIL,(uint8_t)next);
    *selection_out=(uint16_t)next;
    if(next!=current)tg_mod_insert_audio_navigation(i);
    i->mod_menu_remodel_navigation_count++;
    return TG_REMODEL_INPUT_REDRAW_SELECTOR;
}

static int go_root(TopGearRecomp *i,uint8_t selection,uint16_t *selection_out){
    activate_setup(i,0);
    set_page(i,TG_REMODEL_PAGE_ROOT,selection);
    *selection_out=selection;
    return TG_REMODEL_INPUT_REDRAW_SELECTOR;
}

static int go_time_trial(TopGearRecomp *i,uint8_t selection,uint16_t *selection_out){
    activate_setup(i,1);
    /* Time Trial is one-player-only from the first menu stage onward. */
    (void)tg_bus_store16(i,UINT32_C(0x001F04),0u);
    if(i->mod_time_trial_selected_course>=32u)i->mod_time_trial_selected_course=0u;
    i->mod_time_trial_country=(uint8_t)(i->mod_time_trial_selected_course/4u);
    i->mod_time_trial_track=(uint8_t)(i->mod_time_trial_selected_course&3u);
    set_page(i,TG_REMODEL_PAGE_TIME_TRIAL,selection);
    tg_mod_music_menu_enter(i);
    *selection_out=selection;
    return TG_REMODEL_INPUT_REDRAW_SELECTOR;
}

static uint32_t rally_next_random(uint32_t *state){
    uint32_t x=*state;
    if(x==0u)x=UINT32_C(0x6D2B79F5);
    x^=x<<13u;
    x^=x>>17u;
    x^=x<<5u;
    *state=x;
    return x;
}

void tg_mod_rally_generate_schedule(TopGearRecomp *i){
    if(i)tg_mod_music_rally_playlist(i);
    uint32_t state;
    unsigned country;
    if(!i)return;
    /* Seed from emulated machine time, not host time, so snapshot/replay
       behavior remains deterministic while a player's Start timing supplies
       natural variation between Rally starts. */
    state=(uint32_t)i->scpu_master_clock ^
          (uint32_t)(i->scpu_master_clock>>32u) ^
          (uint32_t)i->instruction_count ^ UINT32_C(0x5447524C);
    for(country=0u;country<8u;country++){
        uint8_t local=(uint8_t)((rally_next_random(&state)>>24u)&3u);
        i->mod_rally_schedule[country]=(uint8_t)(country*4u+local);
    }
    i->mod_rally_rng_state=state;
    i->mod_rally_active=1u;
    i->mod_rally_race_index=0u;
    i->mod_rally_qualification_pending=0u;
    i->mod_rally_schedule_valid=1u;
    i->mod_rally_generation_count++;
    /* Rally standings span all eight races.  A fresh Rally therefore starts
       with the game's canonical cumulative 20-racer points table cleared,
       then keeps that same table intact until race 8 is complete. */
    for(country=0u;country<20u;country++)
        (void)tg_bus_write8(i,UINT32_C(0x001F4E)+(uint32_t)country,0u);
    /* $1F06 is the proved global course ordinal. Install race 1 before the
       original PLAY GAME action constructs the pre-race information screen. */
    (void)tg_bus_store16(i,UINT32_C(0x001F06),i->mod_rally_schedule[0]);
    (void)tg_bus_store16(i,UINT32_C(0x001F08),i->mod_rally_schedule[0]);
}

/* Rally qualification uses the same current-race finishing-order authority
   that Top Gear uses when awarding points: $1F12+rank contains the racer ID
   for each finisher, with ID 0 = Player 1 and ID 1 = Player 2 only when the
   canonical player-count setting $1F04 is nonzero.  In one-player mode ID 1
   is the CPU COMPUTER racer and is deliberately ignored.

   Rally race cutoffs tighten by one place per event:
       race 1 <= 8th, race 2 <= 7th, ... race 7 <= 2nd.
   Race 8 has no finish-position gate; the final points standings decide.
   Every active human must independently appear inside the current cutoff. */
void tg_mod_rally_note_points_award(TopGearRecomp *i){
    if(i&&!i->mod_rally_active&&!i->mod_time_trial_active){i->mod_career_qualification_pending=1u;i->mod_career_password_award=0u;}
    if(i&&i->mod_rally_active&&i->mod_rally_schedule_valid)
        i->mod_rally_qualification_pending=1u;
}

unsigned tg_mod_rally_cutoff(unsigned index){return index<7u?8u-index:20u;}

int tg_mod_rally_qualification_passes(TopGearRecomp *i){
    unsigned cutoff,rank;
    int need_p2,found_p1=0,found_p2=0;
    uint8_t racer=UINT8_C(0xFF);
    if(!i||!i->mod_rally_active||!i->mod_rally_schedule_valid)return 1;
    /* $0F:84A7 is also visited while launching the very first Rally race.
       Only enforce a cutoff after the real results path has started awarding
       points at $0F:888A. */
    if(!i->mod_rally_qualification_pending)return 1;
    i->mod_rally_qualification_pending=0u;
    if(i->mod_rally_race_index==7u)return 1; /* Final tally always accepts race 8. */
    cutoff=tg_mod_rally_cutoff(i->mod_rally_race_index);
    need_p2=read_word(i,UINT32_C(0x001F04))!=0u;
    for(rank=0u;rank<cutoff;rank++){
        if(!tg_bus_read8(i,UINT32_C(0x001F12)+(uint32_t)rank,&racer))return 0;
        if(racer==0u)found_p1=1;
        else if(need_p2&&racer==1u)found_p2=1;
    }
    return found_p1&&(!need_p2||found_p2);
}

int tg_mod_rally_hide_failure_password(const TopGearRecomp *i){
    if(!i)return 0;
    /* Rally failure deliberately ends mod_rally_active before handing control
       to Top Gear's native failure presentation.  The scheduled root-menu
       return (root page, Rally highlighted) is therefore the durable marker
       that this failure screen belongs to Rally rather than Career. */
    return i->mod_menu_remodel_return_pending!=0u &&
           i->mod_menu_remodel_return_page==TG_REMODEL_PAGE_ROOT &&
           i->mod_menu_remodel_return_selection==1u;
}

void tg_mod_rally_qualification_failed(TopGearRecomp *i){
    if(!i)return;
    tg_mod_attempt_fail(i);
}

/* Called at the original post-results progression rendezvous ($0F:84AC),
   after Rally qualification has passed and Top Gear has already awarded
   points.  Return 0 for ordinary Career behavior, 1 to continue Rally with
   the next scheduled course, or 2 after race 8 to return to the remodeled
   main menu. */
int tg_mod_rally_post_results(TopGearRecomp *i){
    uint8_t next;
    if(!i||!i->mod_rally_active||!i->mod_rally_schedule_valid)return 0;
    if(i->mod_rally_race_index<7u){
        i->mod_rally_race_index++;
        next=i->mod_rally_schedule[i->mod_rally_race_index];
        (void)tg_bus_store16(i,UINT32_C(0x001F06),(uint16_t)next);
        (void)tg_bus_store16(i,UINT32_C(0x001F08),(uint16_t)next);
        return 1;
    }
    /* Race 8 has already reached and accepted the final ranking screen.
       Preserve schedule/points for diagnostics, end Rally mode, and have the
       normal menu entry restore the root page with RALLY highlighted. */
    i->mod_rally_active=0u;
    i->mod_menu_post_race_context=1u;
    i->mod_menu_remodel_return_pending=1u;
    i->mod_menu_remodel_return_page=TG_REMODEL_PAGE_ROOT;
    i->mod_menu_remodel_return_selection=1u;
    i->mod_menu_remodel_active=0u;
    return 2;
}

int tg_mod_menu_remodel_handle_input(TopGearRecomp *i,uint16_t input,
                                     uint16_t *selection_out){
    uint8_t page,sel;
    if(selection_out)*selection_out=0u;
    if(!i||!i->mod_menu_remodel_active)return TG_REMODEL_INPUT_PASSTHROUGH;
    tg_mod_menu_remodel_draw_if_dirty(i);
    /* An inline value changes without asking the stock Options renderer to
       redraw its old rows. Keep the same one-action-per-press contract. */
    if(i->mod_menu_remodel_reserved){
        if(input)return TG_REMODEL_INPUT_HANDLED;
        i->mod_menu_remodel_reserved=0u;
    }
    /* Five seconds at the native 60 Hz menu poll rate. A held button must
       never extend the deadline. Release then press may still skip early. */
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_PASSWORD_STANDINGS){
        if(!(i->controller_state[0]|i->controller_state[1]))i->mod_password_released=1u;
        if(i->mod_password_released&&input){(void)begin_career(i);return 3;}
        return TG_REMODEL_INPUT_HANDLED;
    }
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_RALLY_TRACKS){
        uint32_t now=(uint32_t)topgear_recomp_v27_frame_count(i);
        if((int32_t)(now-i->mod_rally_preview_deadline)>=0)i->mod_rally_preview_frames=0u;
        if(!input)i->mod_rally_preview_released=1u;
        if(input&&i->mod_rally_preview_released)i->mod_rally_preview_frames=0u;
        if(!i->mod_rally_preview_frames){
            (void)passthrough_original_action(i,4u,TG_REMODEL_PAGE_ROOT,1u,0);
            return 3; /* Native accept fade, without fabricated controller input. */
        }
        return TG_REMODEL_INPUT_HANDLED;
    }
    if((input&UINT16_C(0xFFF0))==0u)return TG_REMODEL_INPUT_PASSTHROUGH;
    page=i->mod_menu_remodel_page;
    sel=i->mod_menu_remodel_selection;

    /* Neither exit nor retry may discard an unacknowledged disk save. */
    if(post_race_page(i)&&topgear_recomp_time_trial_completed_run_pending(i))
        return TG_REMODEL_INPUT_HANDLED;
    if(page==TG_REMODEL_PAGE_TT_POST_RACE_DETAIL&&
       (input&(TG_BTN_UP|TG_BTN_DOWN|TG_BTN_LEFT|TG_BTN_RIGHT)))
        return move_post_race_detail(i,input,selection_out);
    /* FINISH is the only post-race Overall action. Browser navigation must
       not leak here or issue navigation cues for a nonexistent second item. */
    if(page==TG_REMODEL_PAGE_TT_POST_RACE_LEADERBOARD&&
       (input&(TG_BTN_UP|TG_BTN_DOWN|TG_BTN_LEFT|TG_BTN_RIGHT|TG_BTN_L|TG_BTN_R)))
        return TG_REMODEL_INPUT_HANDLED;

    /* Overall is a horizontal three-choice footer. Up/Down intentionally do
       nothing here; Left/Right are its only directional navigation. */
    if(page!=TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL){
        if(input&TG_BTN_UP)return move_selection(i,-1,selection_out);
        if(input&TG_BTN_DOWN)return move_selection(i,1,selection_out);
    }

    if(input&TG_BTN_B){
        switch(page){
        case TG_REMODEL_PAGE_SETTINGS:return go_root(i,3u,selection_out);
        case TG_REMODEL_PAGE_CAREER:return go_root(i,0u,selection_out);
        case TG_REMODEL_PAGE_CAREER_COUNTRY:i->mod_career_password_error=0u;set_page(i,TG_REMODEL_PAGE_CAREER,1u);*selection_out=1u;return TG_REMODEL_INPUT_REDRAW_SELECTOR;
        case TG_REMODEL_PAGE_RALLY:return go_root(i,1u,selection_out);
        case TG_REMODEL_PAGE_TIME_TRIAL:return go_root(i,2u,selection_out);
        case TG_REMODEL_PAGE_TT_COUNTRY:return go_time_trial(i,1u,selection_out);
        case TG_REMODEL_PAGE_TT_TRACK:set_page(i,TG_REMODEL_PAGE_TT_COUNTRY,i->mod_time_trial_country);*selection_out=i->mod_time_trial_country;return TG_REMODEL_INPUT_REDRAW_SELECTOR;
        case TG_REMODEL_PAGE_TT_LEADERBOARD_COUNTRY:return go_time_trial(i,2u,selection_out);
        case TG_REMODEL_PAGE_TT_LEADERBOARD_TRACK:set_page(i,TG_REMODEL_PAGE_TT_LEADERBOARD_COUNTRY,i->mod_time_trial_country);*selection_out=i->mod_time_trial_country;return TG_REMODEL_INPUT_REDRAW_SELECTOR;
        case TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL:set_page(i,TG_REMODEL_PAGE_TT_LEADERBOARD_TRACK,i->mod_time_trial_times_course&3u);*selection_out=(uint16_t)(i->mod_time_trial_times_course&3u);return TG_REMODEL_INPUT_REDRAW_SELECTOR;
        case TG_REMODEL_PAGE_TT_LEADERBOARD_CAR:set_page(i,TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL,1u);*selection_out=1u;return TG_REMODEL_INPUT_REDRAW_SELECTOR;
        case TG_REMODEL_PAGE_TT_POST_RACE_DETAIL:return TG_REMODEL_INPUT_HANDLED;
        case TG_REMODEL_PAGE_TT_POST_RACE_LEADERBOARD:set_page(i,TG_REMODEL_PAGE_TT_POST_RACE_DETAIL,0u);*selection_out=0u;return TG_REMODEL_INPUT_REDRAW_SELECTOR;
        case TG_REMODEL_PAGE_TT_CARS:set_page(i,TG_REMODEL_PAGE_TT_POST_RACE_DETAIL,3u);*selection_out=3u;return TG_REMODEL_INPUT_REDRAW_SELECTOR;
        default:return TG_REMODEL_INPUT_HANDLED;
        }
    }

    if(input&(TG_BTN_LEFT|TG_BTN_RIGHT)){
        if(post_race_page(i))return move_selection(i,(input&TG_BTN_RIGHT)?1:-1,selection_out);
        if(page==TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL){
            int d=(input&TG_BTN_RIGHT)?1:-1;
            int next=((int)sel+d+3)%3;
            tg_mod_insert_audio_navigation(i);
            set_page(i,TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL,(uint8_t)next);
            *selection_out=(uint16_t)next;
            return TG_REMODEL_INPUT_REDRAW_SELECTOR;
        }
        /* Preserve the original game's semantic state writers for the two
           inline settings. */
        if(page==TG_REMODEL_PAGE_SETTINGS&&sel==3u){
            tg_mod_music_player_action(i,(input&TG_BTN_RIGHT)?1:-1);
            i->mod_menu_remodel_dirty=1u;i->mod_menu_remodel_reserved=1u;return TG_REMODEL_INPUT_HANDLED;
        }
        if(page==TG_REMODEL_PAGE_SETTINGS&&sel==2u){
            tg_mod_insert_audio_navigation(i);i->mod_music_mode=(uint8_t)((i->mod_music_mode+((input&TG_BTN_RIGHT)?1u:2u))%3u);
            i->mod_menu_remodel_dirty=1u;i->mod_menu_remodel_reserved=1u;*selection_out=sel;return TG_REMODEL_INPUT_HANDLED;
        }
        if(page==TG_REMODEL_PAGE_SETTINGS&&sel==1u){
            tg_mod_insert_audio_navigation(i);
            i->mod_audio_mute^=1u;i->mod_menu_remodel_dirty=1u;
            i->mod_menu_remodel_reserved=1u;
            *selection_out=sel;return TG_REMODEL_INPUT_HANDLED;
        }
        if(page==TG_REMODEL_PAGE_SETTINGS&&sel==0u){
            uint16_t speed=read_word(i,UINT32_C(0x001FB0));
            tg_mod_insert_audio_navigation(i);
            (void)tg_bus_store16(i,UINT32_C(0x001FB0),(uint16_t)(speed^UINT16_C(0xFFFF)));
            i->mod_menu_remodel_dirty=1u;
            /* Rejoin the native selector/release path: HANDLED immediately
               polls the still-held direction again and toggles every frame. */
            *selection_out=sel;
            return TG_REMODEL_INPUT_REDRAW_SELECTOR;
        }
        if((page==TG_REMODEL_PAGE_CAREER||page==TG_REMODEL_PAGE_RALLY)&&sel==0u){
            i->mod_menu_remodel_dirty=1u;
            return TG_REMODEL_INPUT_PASSTHROUGH;
        }
        return TG_REMODEL_INPUT_HANDLED;
    }

    if((input&(TG_BTN_L|TG_BTN_R))&&
       (page==TG_REMODEL_PAGE_CAREER||page==TG_REMODEL_PAGE_RALLY||page==TG_REMODEL_PAGE_TIME_TRIAL)){
        setup_shortcut(i,input);*selection_out=sel;return TG_REMODEL_INPUT_HANDLED;
    }

    /* L/R cycle the active car only on the per-car leaderboard. */
    if((input&(TG_BTN_L|TG_BTN_R))&&page==TG_REMODEL_PAGE_TT_LEADERBOARD_CAR){
        int d=(input&TG_BTN_R)?1:-1;
        i->mod_time_trial_leaderboard_car=(uint8_t)(((int)(i->mod_time_trial_leaderboard_car&3u)+d+4)%4);
        i->mod_menu_remodel_dirty=1u;
        return TG_REMODEL_INPUT_HANDLED;
    }

    if((input&(TG_BTN_A|TG_BTN_START))==0u)return TG_REMODEL_INPUT_HANDLED;
    i->mod_menu_remodel_accept_count++;

    switch(page){
    case TG_REMODEL_PAGE_ROOT:
        if(sel<4u)tg_mod_insert_audio_accept(i);
        if(sel==0u){set_page(i,TG_REMODEL_PAGE_CAREER,0u);*selection_out=0u;return TG_REMODEL_INPUT_REDRAW_SELECTOR;}
        if(sel==1u){set_page(i,TG_REMODEL_PAGE_RALLY,0u);*selection_out=0u;return TG_REMODEL_INPUT_REDRAW_SELECTOR;}
        if(sel==2u)return go_time_trial(i,0u,selection_out);
        if(sel==3u){set_page(i,TG_REMODEL_PAGE_SETTINGS,0u);*selection_out=0u;return TG_REMODEL_INPUT_REDRAW_SELECTOR;}
        return TG_REMODEL_INPUT_HANDLED;
    case TG_REMODEL_PAGE_SETTINGS:
        if(sel==4u){tg_mod_insert_audio_accept(i);return go_root(i,3u,selection_out);}
        if(sel==3u){tg_mod_insert_audio_accept(i);tg_mod_music_player_action(i,0);i->mod_menu_remodel_dirty=1u;i->mod_menu_remodel_reserved=1u;return TG_REMODEL_INPUT_HANDLED;}
        if(sel==2u)return TG_REMODEL_INPUT_HANDLED;
        if(sel==1u){tg_mod_insert_audio_accept(i);i->mod_audio_mute^=1u;i->mod_menu_remodel_dirty=1u;i->mod_menu_remodel_reserved=1u;*selection_out=sel;return TG_REMODEL_INPUT_HANDLED;}
        tg_mod_insert_audio_accept(i);
        (void)tg_bus_store16(i,0x1FB0u,(uint16_t)(read_word(i,0x1FB0u)^0xFFFFu));
        i->mod_menu_remodel_dirty=1u;
        *selection_out=sel;
        return TG_REMODEL_INPUT_REDRAW_SELECTOR;
    case TG_REMODEL_PAGE_CAREER:
        if(sel==0u){tg_mod_insert_audio_accept(i);return passthrough_original_action(i,0u,TG_REMODEL_PAGE_CAREER,0u,1);}
        if(sel==1u){tg_mod_insert_audio_accept(i);tg_mod_career_validate_start(i);i->mod_career_password_error=0u;set_page(i,TG_REMODEL_PAGE_CAREER_COUNTRY,0u);*selection_out=0u;return TG_REMODEL_INPUT_REDRAW_SELECTOR;}
        if(sel==2u){tg_mod_insert_audio_accept(i);return passthrough_original_action(i,1u,TG_REMODEL_PAGE_CAREER,2u,1);}
        if(sel==3u)return begin_career(i);
        return TG_REMODEL_INPUT_HANDLED;
    case TG_REMODEL_PAGE_CAREER_COUNTRY:{
        unsigned n=tg_mod_career_password_count(i);
        if(sel<n){tg_mod_insert_audio_accept(i);i->mod_career_password_country=(uint8_t)tg_mod_career_password_country(i,sel);i->mod_career_password_open=1u;return passthrough_original_action(i,2u,TG_REMODEL_PAGE_CAREER_COUNTRY,(uint8_t)sel,1);}
        tg_mod_insert_audio_accept(i);
        if(n&&sel==n){i->mod_career_start_course=0u;(void)tg_bus_store16(i,0x1F06u,0u);(void)tg_bus_store16(i,0x1F08u,0u);}
        i->mod_career_password_error=0u;set_page(i,TG_REMODEL_PAGE_CAREER,1u);*selection_out=1u;return TG_REMODEL_INPUT_REDRAW_SELECTOR;
    }
    case TG_REMODEL_PAGE_RALLY:
        if(sel==0u){tg_mod_insert_audio_accept(i);return passthrough_original_action(i,0u,TG_REMODEL_PAGE_RALLY,0u,1);}
        if(sel==1u){tg_mod_insert_audio_accept(i);return passthrough_original_action(i,1u,TG_REMODEL_PAGE_RALLY,1u,1);}
        if(sel==2u){tg_mod_attempt_begin(i);i->mod_continues_remaining=0u;tg_mod_career_panel_start(i);tg_mod_insert_audio_start_race(i);tg_mod_rally_generate_schedule(i);i->mod_rally_preview_frames=300u;i->mod_rally_preview_deadline=(uint32_t)topgear_recomp_v27_frame_count(i)+300u;i->mod_rally_preview_released=0u;set_page(i,TG_REMODEL_PAGE_RALLY_TRACKS,0u);*selection_out=0u;return TG_REMODEL_INPUT_REDRAW_SELECTOR;}
        return TG_REMODEL_INPUT_HANDLED;
    case TG_REMODEL_PAGE_TIME_TRIAL:
        if(sel==0u){tg_mod_insert_audio_accept(i);(void)tg_bus_store16(i,UINT32_C(0x001F04),0u);return passthrough_original_action(i,0u,TG_REMODEL_PAGE_TIME_TRIAL,0u,1);}
        if(sel==1u){tg_mod_insert_audio_accept(i);set_page(i,TG_REMODEL_PAGE_TT_COUNTRY,i->mod_time_trial_country);*selection_out=i->mod_time_trial_country;return TG_REMODEL_INPUT_REDRAW_SELECTOR;}
        if(sel==2u){tg_mod_insert_audio_accept(i);set_page(i,TG_REMODEL_PAGE_TT_LEADERBOARD_COUNTRY,i->mod_time_trial_country);*selection_out=i->mod_time_trial_country;return TG_REMODEL_INPUT_REDRAW_SELECTOR;}
        if(sel==3u){tg_mod_insert_audio_start_race(i);(void)tg_mod_time_trial_start(i);return passthrough_original_action(i,4u,TG_REMODEL_PAGE_TIME_TRIAL,3u,0);}
        return TG_REMODEL_INPUT_HANDLED;
    case TG_REMODEL_PAGE_TT_COUNTRY:
        if(sel<8u){tg_mod_insert_audio_accept(i);i->mod_time_trial_country=sel;set_page(i,TG_REMODEL_PAGE_TT_TRACK,i->mod_time_trial_track);*selection_out=i->mod_time_trial_track;return TG_REMODEL_INPUT_REDRAW_SELECTOR;}
        return TG_REMODEL_INPUT_HANDLED;
    case TG_REMODEL_PAGE_TT_TRACK:
        if(sel<4u){
            tg_mod_insert_audio_accept(i);
            i->mod_time_trial_track=sel;i->mod_time_trial_selected_course=(uint8_t)(i->mod_time_trial_country*4u+sel);
            (void)tg_bus_store16(i,UINT32_C(0x001F06),i->mod_time_trial_selected_course);
            (void)tg_bus_store16(i,UINT32_C(0x001F08),i->mod_time_trial_selected_course);
            i->mod_time_trial_has_run=0u;
            return go_time_trial(i,1u,selection_out);
        }
        return TG_REMODEL_INPUT_HANDLED;
    case TG_REMODEL_PAGE_TT_LEADERBOARD_COUNTRY:
        if(sel<8u){tg_mod_insert_audio_accept(i);i->mod_time_trial_country=sel;set_page(i,TG_REMODEL_PAGE_TT_LEADERBOARD_TRACK,0u);*selection_out=0u;return TG_REMODEL_INPUT_REDRAW_SELECTOR;}
        return TG_REMODEL_INPUT_HANDLED;
    case TG_REMODEL_PAGE_TT_LEADERBOARD_TRACK:
        if(sel<4u){
            tg_mod_insert_audio_accept(i);
            i->mod_time_trial_times_course=(uint8_t)(i->mod_time_trial_country*4u+sel);
            set_page(i,TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL,0u);*selection_out=0u;
            return TG_REMODEL_INPUT_REDRAW_SELECTOR;
        }
        return TG_REMODEL_INPUT_HANDLED;
    case TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL:
        if(sel==0u){i->mod_menu_remodel_dirty=1u;return TG_REMODEL_INPUT_HANDLED;}
        if(sel==1u){
            tg_mod_insert_audio_accept(i);
            i->mod_time_trial_leaderboard_car=(uint8_t)(read_word(i,UINT32_C(0x001F8F))&UINT16_C(0x0003));
            set_page(i,TG_REMODEL_PAGE_TT_LEADERBOARD_CAR,0u);*selection_out=0u;
            return TG_REMODEL_INPUT_REDRAW_SELECTOR;
        }
        if(sel==2u){tg_mod_insert_audio_accept(i);set_page(i,TG_REMODEL_PAGE_TT_LEADERBOARD_TRACK,i->mod_time_trial_times_course&3u);*selection_out=(uint16_t)(i->mod_time_trial_times_course&3u);return TG_REMODEL_INPUT_REDRAW_SELECTOR;}
        return TG_REMODEL_INPUT_HANDLED;
    case TG_REMODEL_PAGE_TT_LEADERBOARD_CAR:
        tg_mod_insert_audio_accept(i);
        set_page(i,TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL,1u);*selection_out=1u;
        return TG_REMODEL_INPUT_REDRAW_SELECTOR;
    case TG_REMODEL_PAGE_TT_POST_RACE_DETAIL:
        if(topgear_recomp_time_trial_completed_run_pending(i))return TG_REMODEL_INPUT_HANDLED;
        if(sel==0u){tg_mod_insert_audio_accept(i);set_page(i,TG_REMODEL_PAGE_TT_POST_RACE_LEADERBOARD,0u);*selection_out=0u;return TG_REMODEL_INPUT_REDRAW_SELECTOR;}
        if(sel==1u){
            tg_mod_insert_audio_accept(i);
            i->mod_time_trial_selected_course=i->mod_time_trial_times_course;
            (void)tg_mod_time_trial_start(i);
            return passthrough_original_action(i,4u,TG_REMODEL_PAGE_TIME_TRIAL,3u,0);
        }
        if(sel==2u){
            tg_mod_insert_audio_accept(i);
            /* Results belong to the completed run. Derive the country from
               that course so TRACKS never opens on a stale earlier country. */
            i->mod_time_trial_country=(uint8_t)((i->mod_time_trial_times_course>>2u)&7u);
            set_page(i,TG_REMODEL_PAGE_TT_COUNTRY,i->mod_time_trial_country);
            *selection_out=i->mod_time_trial_country;
            return TG_REMODEL_INPUT_REDRAW_SELECTOR;
        }
        if(sel==3u){tg_mod_insert_audio_accept(i);set_page(i,TG_REMODEL_PAGE_TT_CARS,(uint8_t)(read_word(i,UINT32_C(0x001F8F))&3u));*selection_out=i->mod_menu_remodel_selection;return TG_REMODEL_INPUT_REDRAW_SELECTOR;}
        if(sel==4u){tg_mod_insert_audio_accept(i);return go_root(i,2u,selection_out);}
        return TG_REMODEL_INPUT_HANDLED;
    case TG_REMODEL_PAGE_TT_POST_RACE_LEADERBOARD:
        tg_mod_insert_audio_accept(i);
        return go_time_trial(i,1u,selection_out);
    case TG_REMODEL_PAGE_TT_CARS:
        if(sel<4u){tg_mod_insert_audio_accept(i);(void)tg_bus_store16(i,UINT32_C(0x001F8F),sel);set_page(i,TG_REMODEL_PAGE_TT_POST_RACE_DETAIL,3u);*selection_out=3u;return TG_REMODEL_INPUT_REDRAW_SELECTOR;}
        return TG_REMODEL_INPUT_HANDLED;
    default:return TG_REMODEL_INPUT_HANDLED;
    }
}

static unsigned selector_x_for(TopGearRecomp *i,unsigned selection){
    const char *label=page_item_label(i,selection);
    unsigned x;
    if(i&&i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_POST_RACE_DETAIL){
        static const unsigned compact_x[5]={3u,3u,11u,20u,16u};
        return selection<5u?compact_x[selection]:3u;
    }
    if(i&&i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL){
        static const unsigned compact_x[3]={4u,14u,22u};
        return selection<3u?compact_x[selection]:5u;
    }
    if(i&&i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_LEADERBOARD_CAR)return 13u;
    x=text_x(label);
    /* Existing selector starts two tiles before normal x=5 text.  For very
       long TRACK SELECT, clamp to x=3 to avoid overwriting the frame edge. */
    return x>4u?x-2u:3u;
}

uint16_t tg_mod_menu_remodel_selector_coord(TopGearRecomp *i,uint16_t selection,
                                            uint16_t fallback){
    unsigned count,x,y;
    if(!i||!i->mod_menu_remodel_active)return fallback;
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_RALLY_TRACKS||i->mod_menu_remodel_page==TG_REMODEL_PAGE_PASSWORD_STANDINGS)return 0x1F03u;
    count=page_item_count(i);
    if(selection>=count)selection=0u;
    x=selector_x_for(i,selection);
    y=row_y_for(i,selection);
    return (uint16_t)(((uint16_t)y<<8u)|(uint16_t)x);
}

uint16_t tg_mod_menu_remodel_selector_width(TopGearRecomp *i,uint16_t selection,
                                            uint16_t fallback){
    const char *label;size_t n;uint16_t width,players;
    if(!i||!i->mod_menu_remodel_active)return fallback;
    if(selection>=page_item_count(i))selection=0u;
    label=page_item_label(i,selection);n=strlen(label);width=(uint16_t)(n+1u);
    if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL||
       i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_POST_RACE_DETAIL||
       i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_LEADERBOARD_CAR)
        width=(uint16_t)((n+2u)/2u);
    {
        /* Native OBJ builder draws width+1 sixteen-pixel spans. */
        unsigned maximum=(29u-selector_x_for(i,selection))/2u-1u;
        if(i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_LEADERBOARD_OVERALL||
           i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_POST_RACE_DETAIL||
           i->mod_menu_remodel_page==TG_REMODEL_PAGE_TT_LEADERBOARD_CAR)
            maximum=(30u-selector_x_for(i,selection))/2u;
        if(width>maximum)width=(uint16_t)maximum;
    }
    /* Original selector path adds $1F04 to row zero.  Career row zero wants
       exactly that behavior (1 PLAYER -> 9, 2 PLAYERS -> 10).  Other remodel
       pages compensate so their row-zero width is independent of player count. */
    if(i->mod_menu_remodel_page!=TG_REMODEL_PAGE_CAREER&&
       i->mod_menu_remodel_page!=TG_REMODEL_PAGE_RALLY&&selection==0u){
        players=read_word(i,UINT32_C(0x001F04));
        if(players&&width>0u)width--;
    }
    return width;
}
