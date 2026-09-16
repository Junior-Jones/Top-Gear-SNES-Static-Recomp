#include "topgear_internal.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

static uint16_t read16(TopGearRecomp *i,uint32_t a){uint16_t v=0u;(void)tg_bus_read16(i,a,&v);return v;}
static uint16_t tick_delta(uint16_t now,uint16_t then){return (uint16_t)(now-then);}

static void copy_player_name(TopGearRecomp *i,char out[8]){
    unsigned n; uint8_t b=0u;
    for(n=0u;n<8u;n++){
        if(!tg_bus_read8(i,UINT32_C(0x001F86)+n,&b))b=(uint8_t)' ';
        if(!((b>='A'&&b<='Z')||(b>='0'&&b<='9')))b=(uint8_t)' ';
        out[n]=(char)b;
    }
}

void tg_mod_career_race_reset(TopGearRecomp *i){
    unsigned n;for(n=0;n<20u;n++)i->mod_career_order[n]=(uint8_t)n;
    memset(i->mod_career_crossings,0,sizeof(i->mod_career_crossings));
    memset(i->mod_career_laps,0,sizeof(i->mod_career_laps));
    memset(i->mod_career_last_lap,0,sizeof(i->mod_career_last_lap));
    memset(i->mod_career_progress,0,sizeof(i->mod_career_progress));
    i->mod_career_last_tick=0u;
}
void tg_mod_career_panel_start(TopGearRecomp *i){
    unsigned t,n;
    i->mod_career_panel=1u;
    for(t=0;t<48;t++)for(n=0;n<32;n++)i->mod_time_trial_font_tiles[t][n]=i->vram[(0x100u+t)*32u+n];
    for(n=0;n<16;n++)i->mod_time_trial_font_palette[n]=(uint16_t)(i->cgram[n*2]|(i->cgram[n*2+1]<<8));
    i->mod_time_trial_font_valid=1u;
    tg_mod_career_race_reset(i);
}
void tg_mod_career_frame(TopGearRecomp *i){
    unsigned slot,n,id,lap,sector,progress;uint16_t length,now;uint32_t distance[20]={0};uint8_t finish_rank[20];
    memset(finish_rank,255,sizeof(finish_rank));
    if(!i->mod_career_panel||i->mod_time_trial_active||i->mod_menu_remodel_active||i->mod_audio_menu_context||i->hdma_enable_mask!=0x7Fu||read16(i,0x1F04u))return;
    length=read16(i,0x200u);now=read16(i,0x1EAEu);if(length<3u)return;
    if(now<i->mod_career_last_tick)tg_mod_career_race_reset(i);
    i->mod_career_last_tick=now;
    for(n=0;n<read16(i,0x1EB0u)&&n<20u;n++)if(i->wram[0x1F12u+n]<20u)finish_rank[i->wram[0x1F12u+n]]=(uint8_t)n;
    for(slot=0;slot<20;slot++){
        unsigned offset=slot*18u,base=0x212u+offset;uint16_t pos=read16(i,base+7u);
        id=offset==read16(i,0x204u)?0u:offset==read16(i,0x206u)?1u:(i->wram[base]&31u);
        if(id>=20u||pos>=length)continue;
        lap=i->wram[base+9u];if(lap>9u)continue;
        if(finish_rank[id]!=255u){lap=(unsigned)read16(i,0x1E56u)+1u;pos=0u;}
        distance[id]=finish_rank[id]!=255u?UINT32_C(0xFFFF0000)-finish_rank[id]:lap*(uint32_t)length+pos;
        sector=(unsigned)pos*10u/length;progress=lap?((lap-1u)*10u+sector):0u;
        if(lap&&progress<91u){
            /* Store measured checkpoint crossing times, including the start line.
               Gaps compare the SAME checkpoint for both cars; no speed guesses. */
            if(!i->mod_career_crossings[id][progress])i->mod_career_crossings[id][progress]=(uint32_t)now+1u;
            if(lap>i->mod_career_laps[id]&&lap>=2u){
                uint32_t before=i->mod_career_crossings[id][(lap-2u)*10u];
                if(before)i->mod_career_last_lap[id]=(uint32_t)now+1u-before;
            }
            i->mod_career_progress[id]=(uint16_t)progress;
        }
        i->mod_career_laps[id]=(uint8_t)lap;
    }
    for(n=0;n<20;n++)i->mod_career_order[n]=(uint8_t)n;
    for(n=1;n<20;n++){unsigned k=n;uint8_t v=i->mod_career_order[n];
        while(k&&distance[v]>distance[i->mod_career_order[k-1]]){i->mod_career_order[k]=i->mod_career_order[k-1];k--;}
        i->mod_career_order[k]=v;
    }
}

int tg_mod_time_trial_start(TopGearRecomp *i){
    uint16_t tick;
    if(!i)return 0;
    i->mod_rally_active=0u;
    {
        unsigned t,n;
        for(t=0u;t<48u;t++)for(n=0u;n<32u;n++)
            i->mod_time_trial_font_tiles[t][n]=i->vram[((UINT32_C(0x100)+t)*32u+n)&0xFFFFu];
        for(n=0u;n<16u;n++)
            i->mod_time_trial_font_palette[n]=(uint16_t)(i->cgram[n*2u]|((uint16_t)i->cgram[n*2u+1u]<<8u));
        i->mod_time_trial_font_valid=1u;
    }
    i->mod_time_trial_active=1u;
    i->mod_time_trial_lap_count=0u;
    i->mod_time_trial_required_laps=0u;
    i->mod_time_trial_sector_mask=0u;
    i->mod_time_trial_completed_run_valid=0u;
    i->mod_time_trial_completed_run_pending=0u;
    memset(&i->mod_time_trial_completed_run,0,sizeof(i->mod_time_trial_completed_run));
    memset(i->mod_time_trial_completed_laps,0,sizeof(i->mod_time_trial_completed_laps));
    memset(i->mod_time_trial_completed_s1,0,sizeof(i->mod_time_trial_completed_s1));
    memset(i->mod_time_trial_completed_s2,0,sizeof(i->mod_time_trial_completed_s2));
    memset(i->mod_time_trial_completed_s3,0,sizeof(i->mod_time_trial_completed_s3));
    (void)tg_bus_store16(i,UINT32_C(0x001F04),0u);
    (void)tg_bus_store16(i,UINT32_C(0x001F06),i->mod_time_trial_selected_course);
    (void)tg_bus_store16(i,UINT32_C(0x001F08),i->mod_time_trial_selected_course);
    tick=read16(i,UINT32_C(0x001EAE));
    i->mod_time_trial_lap_start_tick=tick;
    i->mod_time_trial_last_tick=tick;
    return 1;
}

int tg_mod_time_trial_skip_career_points(const TopGearRecomp *i){return i&&i->mod_time_trial_active;}

/* Capture the canonical $1E76 increment at $05:E823. The HUD $011E update
   can be skipped by a fast finish path, so it is not a timing authority.
   The race timer at $1EAE is emulated game time. Sector timestamps are recorded
   separately by tg_mod_time_trial_frame from course-distance thresholds. */
void tg_mod_time_trial_note_lap(TopGearRecomp *i,uint16_t completed){
    uint16_t now,lap,s1,s2;
    unsigned slot;
    if(!i||!i->mod_time_trial_active||completed==0u||completed>8u)return;
    if(completed<=i->mod_time_trial_lap_count)return;
    now=read16(i,UINT32_C(0x001EAE));
    lap=tick_delta(now,i->mod_time_trial_lap_start_tick);
    s1=(i->mod_time_trial_sector_mask&1u)?tick_delta(i->mod_time_trial_sector1_tick,i->mod_time_trial_lap_start_tick):0u;
    s2=(i->mod_time_trial_sector_mask&2u)?tick_delta(i->mod_time_trial_sector2_tick,i->mod_time_trial_sector1_tick):0u;
    slot=(unsigned)i->mod_time_trial_lap_count;
    if(slot<8u){
        i->mod_time_trial_completed_laps[slot]=lap;
        i->mod_time_trial_completed_s1[slot]=s1;
        i->mod_time_trial_completed_s2[slot]=s2;
        i->mod_time_trial_completed_s3[slot]=(lap>=(uint16_t)(s1+s2))?(uint32_t)(lap-s1-s2):UINT32_C(0);
    }
    /* A leaderboard record represents the whole Time Trial run.  Per-lap
       timing is retained here for the live panel and is aggregated only when
       the completed race reaches the post-results rendezvous. */
    i->mod_time_trial_lap_count=(uint8_t)(completed>8u?8u:completed);
    i->mod_time_trial_lap_start_tick=now;
    /* Preserve completed S1/S2/S3 after the line. They are cleared only when
       the next lap reaches S1, exactly as the requested display contract says. */
    i->mod_time_trial_sector_mask=0u;
}

/* Invoked only by the native course loader after its $1E56 store.
   Menu WRAM can still hold the previous track's lap count on Retry/new track. */
void tg_mod_time_trial_capture_required_laps(TopGearRecomp *i,uint16_t laps){
    if(i&&i->mod_time_trial_active)
        i->mod_time_trial_required_laps=(uint8_t)(laps>=1u&&laps<=8u?laps:0u);
}

/* Distance sectors use native player world position $1ED7 and course length
   $0200. The renderer's $0202 camera position diverges during pits and must
   not advance timing sectors while the player is stationary. */
void tg_mod_time_trial_frame(TopGearRecomp *i){
    uint16_t length,pos,now;
    uint32_t one,two;
    if(!i||!i->mod_time_trial_active)return;
    now=read16(i,UINT32_C(0x001EAE));
    /* Race timer resets during transition from menu/pre-race into the live
       course. Re-anchor lap zero there so countdown/loading time is excluded. */
    if(i->mod_time_trial_lap_count==0u&&now<i->mod_time_trial_last_tick){
        i->mod_time_trial_lap_start_tick=now;
        i->mod_time_trial_sector1_tick=0u;
        i->mod_time_trial_sector2_tick=0u;
        i->mod_time_trial_sector_mask=0u;
    }
    i->mod_time_trial_last_tick=now;
    /* Top Gear's live split-screen race is reported by the current renderer
       as PPU mode 1, so do not use a Mode-7 gate here.  The real course
       geometry words become self-validating once $0200 is a sensible length
       and Player 1's engine world position at $1ED7 lies within it. */
    length=read16(i,UINT32_C(0x000200));
    pos=read16(i,UINT32_C(0x001ED7));
    if(length<3u||pos>length)return;
    one=(uint32_t)length/3u; two=((uint32_t)length*2u)/3u;

    /* The lap-count writer can precede the course-position wrap. Do not turn
       that previous lap's high position into two zero-length new sectors.
       Arm each later lap only after observing its low course position. */
    if(i->mod_time_trial_lap_count>0u&&(i->mod_time_trial_sector_mask&UINT8_C(0x80))==0u){
        if((uint32_t)pos<one)i->mod_time_trial_sector_mask|=UINT8_C(0x80);
        return;
    }

    /* The grid is positioned just before the start/finish wrap.  Do not
       mistake that high initial course position for first-lap S1/S2.  Bits
       6/7 of the sector mask are private first-lap arming state: see the
       high start position, then arm timing when position wraps low. */
    if(i->mod_time_trial_lap_count==0u&&(i->mod_time_trial_sector_mask&UINT8_C(0x80))==0u){
        if((i->mod_time_trial_sector_mask&UINT8_C(0x40))==0u){
            if((uint32_t)pos>=two)i->mod_time_trial_sector_mask|=UINT8_C(0x40);
            return;
        }
        if((uint32_t)pos<one){
            i->mod_time_trial_lap_start_tick=now;
            i->mod_time_trial_sector1_tick=0u;
            i->mod_time_trial_sector2_tick=0u;
            i->mod_time_trial_sector_mask=UINT8_C(0x80);
        }
        return;
    }

    if((i->mod_time_trial_sector_mask&1u)==0u&&(uint32_t)pos>=one){
        /* New-lap S1 is the point where the previous completed sectors cease
           to be displayed; timing state is replaced here, not at the line. */
        i->mod_time_trial_sector1_tick=now;
        i->mod_time_trial_sector2_tick=0u;
        i->mod_time_trial_sector_mask|=1u;
    }
    if((i->mod_time_trial_sector_mask&2u)==0u&&(i->mod_time_trial_sector_mask&1u)&&(uint32_t)pos>=two){
        i->mod_time_trial_sector2_tick=now;
        i->mod_time_trial_sector_mask|=2u;
    }
}


static unsigned tt_font_tile(char c){
    if(c>='A'&&c<='Z')return 1u+(unsigned)(c-'A');
    if(c>='0'&&c<='9')return 0x1Bu+(unsigned)(c-'0');
    if(c=='-')return 0x2Cu;
    if(c=='.')return 0x28u;
    if(c==':')return 0x25u;
    if(c=='+')return 0x2Bu;
    return 0u;
}
static uint8_t tt_font_pixel(const TopGearRecomp *i,unsigned tile,unsigned x,unsigned y){
    const uint8_t *d; unsigned bit; uint8_t c=0u;
    if(tile>=48u||x>=8u||y>=8u)return 0u;
    d=i->mod_time_trial_font_tiles[tile]; bit=7u-x;
    c|=(uint8_t)((d[y*2u]>>bit)&1u);
    c|=(uint8_t)(((d[y*2u+1u]>>bit)&1u)<<1u);
    c|=(uint8_t)(((d[16u+y*2u]>>bit)&1u)<<2u);
    c|=(uint8_t)(((d[16u+y*2u+1u]>>bit)&1u)<<3u);
    return c;
}
static void tt_overlay_text_line(TopGearRecomp *i,unsigned scan,unsigned x,unsigned y,const char *text){
    unsigned ci,px,gy;
    if(scan<y||scan>=y+8u||!text)return;
    gy=scan-y;
    for(ci=0u;text[ci]&&x+ci*8u<256u;ci++){
        unsigned tile=tt_font_tile(text[ci]);
        if(text[ci]=='+'||text[ci]=='-'){
            for(px=0;px<7u;px++)if((gy==3u&&px>=1u&&px<=5u)||(text[ci]=='+'&&px==3u&&gy>=1u&&gy<=5u)){
                uint32_t a=(scan*256u+x+ci*8u+px)*2u;i->mode1_frame[a]=255u;i->mode1_frame[a+1u]=127u;
            }
            continue;
        }
        if(!tile)continue;
        for(px=0u;px<8u&&x+ci*8u+px<256u;px++){
            uint8_t pal=tt_font_pixel(i,tile,px,gy);
            if(pal){
                uint16_t color=i->mod_time_trial_font_palette[pal&15u]&UINT16_C(0x7FFF);
                uint32_t a=(scan*256u+x+ci*8u+px)*2u;
                if(color==0u)color=UINT16_C(0x7FFF);
                i->mode1_frame[a]=(uint8_t)color;i->mode1_frame[a+1u]=(uint8_t)(color>>8u);
            }
        }
    }
}
static void tt_format_ticks(uint32_t ticks,char out[12]){
    uint32_t sec=ticks/60u,rem=ticks%60u,hundredths=(rem*100u+30u)/60u,min;
    if(hundredths>=100u){hundredths=0u;sec++;}
    min=sec/60u;
    (void)snprintf(out,12u,"%u:%02u.%02u",(unsigned)min,(unsigned)(sec%60u),(unsigned)hundredths);
}
static void career_overlay(TopGearRecomp *i,unsigned y){
    unsigned rank,leader=i->mod_career_order[0];char line[33],name[9],tm[12];
    if(!i->mod_career_panel||i->mod_time_trial_active||read16(i,0x1F04u)||i->mod_menu_remodel_active||i->mod_audio_menu_context||i->hdma_enable_mask!=0x7Fu||!i->mod_time_trial_font_valid||y<108u||y>=224u)return;
    memset(&i->mode1_frame[y*512u],0,512u);
    tt_overlay_text_line(i,y,8u,112u,"TOP 5  CHECKPOINT GAPS");
    for(rank=0;rank<5;rank++){
        unsigned id=i->mod_career_order[rank],n,cp=i->mod_career_progress[id];uint32_t a=0,b=0;
        if(id==0u){memcpy(name,i->wram+0x1F86u,8u);}
        else{
            /* CPU ID 1 is COMPUTER; IDs 2..19 use the native eight-byte names. */
            unsigned index=id==1u?18u:id-2u;
            memcpy(name,i->rom+0x6C47Bu+index*8u,8u);
        }
        name[8]=0;for(n=0;n<8;n++)if(name[n]<' '||name[n]>'Z'||name[n]=='=')name[n]=' ';
        if(rank==0u){
            if(i->mod_career_last_lap[id])tt_format_ticks(i->mod_career_last_lap[id],tm);else (void)snprintf(tm,sizeof(tm),"--:--.--");
        }else{
            while(cp<91u){a=i->mod_career_crossings[id][cp];b=i->mod_career_crossings[leader][cp];if(a&&b)break;if(!cp)break;cp--;}
            if(a&&b&&a>=b){uint32_t ms=(a-b)*1000u/60u;(void)snprintf(tm,sizeof(tm),"%u.%03u",(unsigned)(ms/1000u),(unsigned)(ms%1000u));}
            else (void)snprintf(tm,sizeof(tm),"--.---");
        }
        (void)snprintf(line,sizeof(line),"%u %.8s %s%s",rank+1u,name,rank?"+":"",tm);
        tt_overlay_text_line(i,y,8u,132u+rank*17u,line);
    }
}
static void continue_overlay(TopGearRecomp *i,unsigned y){
    char text[24];unsigned x,left=i->mod_continue_selection?144u:64u,right=left+48u;
    if(y<168u||y>=224u||!i->mod_time_trial_font_valid)return;
    memset(i->mode1_frame+y*512u,0,512u);
    snprintf(text,sizeof(text),"CONTINUES: %u",i->mod_continues_remaining);
    tt_overlay_text_line(i,y,80u,179u,text);
    if(y>=201u&&y<=214u)for(x=left;x<right;x++){
        uint16_t color=(y==201u||y==214u||x==left||x==right-1u)?0x7C1Fu:0x6000u;
        unsigned at=(y*256u+x)*2u;i->mode1_frame[at]=(uint8_t)color;i->mode1_frame[at+1]=(uint8_t)(color>>8);
    }
    tt_overlay_text_line(i,y,76u,204u,"YES");tt_overlay_text_line(i,y,160u,204u,"NO");
    if(!i->mod_continues_remaining&&y>=204u&&y<212u)for(x=76u;x<100u;x++){
        unsigned at=(y*256u+x)*2u;if(i->mode1_frame[at]||i->mode1_frame[at+1]){i->mode1_frame[at]=0x10;i->mode1_frame[at+1]=0x42;}
    }
}
void tg_mod_time_trial_overlay_scanline(TopGearRecomp *i,unsigned y){
    char line[24],tm[12]; unsigned n; uint16_t now;
    uint32_t s1=0u,s2=0u,s3=0u;
    if(i&&i->mod_continue_screen>=2u&&i->mod_continue_screen<=4u){continue_overlay(i,y);return;}
    if(i&&!i->mod_time_trial_active){career_overlay(i,y);return;}
    if(!i||!i->mod_time_trial_active||!i->mod_time_trial_font_valid||y<108u||y>=224u)return;
    /* Repurpose the COMPUTER half: intentionally blank its pixels first. */
    memset(&i->mode1_frame[y*256u*2u],0,256u*2u);
    if((i->mod_time_trial_sector_mask&3u)==0u&&i->mod_time_trial_lap_count>0u){
        n=(unsigned)i->mod_time_trial_lap_count-1u;
        s1=i->mod_time_trial_completed_s1[n];s2=i->mod_time_trial_completed_s2[n];s3=i->mod_time_trial_completed_s3[n];
    }else{
        now=read16(i,UINT32_C(0x001EAE));
        if(i->mod_time_trial_sector_mask&1u)s1=tick_delta(i->mod_time_trial_sector1_tick,i->mod_time_trial_lap_start_tick);
        if(i->mod_time_trial_sector_mask&2u)s2=tick_delta(i->mod_time_trial_sector2_tick,i->mod_time_trial_sector1_tick);
        (void)now;
    }
    (void)snprintf(line,sizeof(line),"LAP %u",(unsigned)(i->mod_time_trial_lap_count<8u?i->mod_time_trial_lap_count+1u:8u));
    tt_overlay_text_line(i,y,8u,112u,line);
    tt_format_ticks((i->mod_time_trial_lap_count==0u&&!(i->mod_time_trial_sector_mask&0x80u))?0u:tick_delta(read16(i,UINT32_C(0x001EAE)),i->mod_time_trial_lap_start_tick),tm);
    (void)snprintf(line,sizeof(line),"L: %s",tm);tt_overlay_text_line(i,y,8u,128u,line);
    if(s1){tt_format_ticks(s1,tm);(void)snprintf(line,sizeof(line),"S1: %s",tm);}else (void)snprintf(line,sizeof(line),"S1: --.--");
    tt_overlay_text_line(i,y,8u,148u,line);
    if(s2){tt_format_ticks(s2,tm);(void)snprintf(line,sizeof(line),"S2: %s",tm);}else (void)snprintf(line,sizeof(line),"S2: --.--");
    tt_overlay_text_line(i,y,8u,164u,line);
    if(s3){tt_format_ticks(s3,tm);(void)snprintf(line,sizeof(line),"S3: %s",tm);}else (void)snprintf(line,sizeof(line),"S3: --.--");
    tt_overlay_text_line(i,y,8u,180u,line);
    for(n=0u;n<8u;n++){
        if(i->mod_time_trial_completed_laps[n]){tt_format_ticks(i->mod_time_trial_completed_laps[n],tm);(void)snprintf(line,sizeof(line),"L%u: %s",n+1u,tm);}
        else (void)snprintf(line,sizeof(line),"L%u: --.--",n+1u);
        tt_overlay_text_line(i,y,136u,112u+n*13u,line);
    }
}

int tg_mod_time_trial_post_results(TopGearRecomp *i){
    TopGearTimeTrialRun run;
    uint32_t total=0u,b1=UINT32_MAX,b2=UINT32_MAX,b3=UINT32_MAX;
    unsigned n,completed,required,valid_laps=0u;
    uint16_t gear_lo,gear_hi;
    if(!i||!i->mod_time_trial_active)return 0;
    completed=(unsigned)i->mod_time_trial_lap_count;
    required=(unsigned)i->mod_time_trial_required_laps;
    /* Missing required-lap authority must never promote a partial run. */
    memset(&run,0,sizeof(run));
    copy_player_name(i,run.name);
    run.car_id=(uint8_t)(read16(i,UINT32_C(0x001F8F))&UINT16_C(0x0003));
    gear_lo=read16(i,UINT32_C(0x001F7A));
    gear_hi=read16(i,UINT32_C(0x001F7C));
    run.gearbox=(uint8_t)((gear_lo|gear_hi)?1u:0u);
    run.course=i->mod_time_trial_selected_course;
    run.required_laps=(uint8_t)required;
    run.completed_laps=(uint8_t)completed;
    for(n=0u;n<completed&&n<8u;n++){
        uint32_t lap=i->mod_time_trial_completed_laps[n];
        uint32_t s1=i->mod_time_trial_completed_s1[n];
        uint32_t s2=i->mod_time_trial_completed_s2[n];
        uint32_t s3=i->mod_time_trial_completed_s3[n];
        run.lap_time_ticks[n]=lap;
        run.lap_sector1_ticks[n]=s1;
        run.lap_sector2_ticks[n]=s2;
        run.lap_sector3_ticks[n]=s3;
        if(lap&&s1&&s2&&s3&&s1+s2+s3==lap){
            valid_laps++;
            total+=lap;
            if(s1<b1)b1=s1;
            if(s2<b2)b2=s2;
            if(s3<b3)b3=s3;
        }
    }
    run.total_time_ticks=total;
    if(b1!=UINT32_MAX)run.best_sector1_ticks=b1;
    if(b2!=UINT32_MAX)run.best_sector2_ticks=b2;
    if(b3!=UINT32_MAX)run.best_sector3_ticks=b3;
    if(completed==required&&valid_laps==required&&required>=1u&&required<=8u&&total!=0u&&
       b1!=UINT32_MAX&&b2!=UINT32_MAX&&b3!=UINT32_MAX){
        run.valid_flags=TOPGEAR_TIME_TRIAL_RUN_VALID|TOPGEAR_TIME_TRIAL_RUN_COMPLETE;
        i->mod_time_trial_completed_run=run;
        i->mod_time_trial_completed_run_valid=1u;
        i->mod_time_trial_completed_run_pending=1u;
    }else{
        i->mod_time_trial_completed_run_valid=0u;
        i->mod_time_trial_completed_run_pending=0u;
        memset(&i->mod_time_trial_completed_run,0,sizeof(i->mod_time_trial_completed_run));
    }
    i->mod_time_trial_active=0u;
    i->mod_time_trial_has_run=1u;
    i->mod_time_trial_times_course=i->mod_time_trial_selected_course;
    i->mod_menu_remodel_return_pending=1u;
    i->mod_menu_remodel_return_page=10u; /* post-race detail */
    i->mod_menu_remodel_return_selection=0u;
    i->mod_menu_remodel_active=0u;
    return 1;
}

int tg_mod_time_trial_commit_completed_run(TopGearRecomp *i){
    if(!i||!i->mod_time_trial_completed_run_valid||
       !i->mod_time_trial_completed_run_pending)return 0;
    i->mod_time_trial_completed_run_pending=0u;
    i->mod_menu_remodel_dirty=1u;
    return 1;
}
