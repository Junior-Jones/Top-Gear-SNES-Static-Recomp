/* Version 27 current launcher.
   Normal builds expose only the broad current static runtime and Full Static
   S-SMP/S-DSP audio. Historical milestone runners and retired audio backends
   audio oracle are excluded from the production compile. */
#include "topgear_static_recomp.h"
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int load_file(const char *path,uint8_t **data,size_t *size){
    FILE *f;long end;uint8_t *p;*data=NULL;*size=0u;
    f=fopen(path,"rb");if(!f){fprintf(stderr,"Unable to open %s: %s\n",path,strerror(errno));return 0;}
    if(fseek(f,0,SEEK_END)!=0||(end=ftell(f))<0||fseek(f,0,SEEK_SET)!=0){fclose(f);return 0;}
    p=(uint8_t*)malloc((size_t)end);if(!p||fread(p,1u,(size_t)end,f)!=(size_t)end){free(p);fclose(f);return 0;}
    fclose(f);*data=p;*size=(size_t)end;return 1;
}
static int write_ppm(const char *path,const uint8_t *frame){
    FILE *f;unsigned x,y;if(!path||!frame)return 0;f=fopen(path,"wb");if(!f)return 0;
    fprintf(f,"P6\n256 224\n255\n");
    for(y=0;y<224u;y++)for(x=0;x<256u;x++){
        size_t p=((size_t)y*256u+x)*2u;uint16_t c=(uint16_t)(frame[p]|((uint16_t)frame[p+1u]<<8));
        uint8_t rgb[3]={(uint8_t)((c&31u)*255u/31u),(uint8_t)(((c>>5)&31u)*255u/31u),(uint8_t)(((c>>10)&31u)*255u/31u)};
        if(fwrite(rgb,1u,3u,f)!=3u){fclose(f);return 0;}
    }
    return fclose(f)==0;
}
static void le16(FILE *f,uint16_t v){fputc((int)(v&255u),f);fputc((int)(v>>8),f);}
static void le32(FILE *f,uint32_t v){le16(f,(uint16_t)v);le16(f,(uint16_t)(v>>16));}
static int wav_begin(FILE *f){
    if(!f)return 0;
    fwrite("RIFF",1u,4u,f);le32(f,0u);fwrite("WAVEfmt ",1u,8u,f);le32(f,16u);le16(f,1u);le16(f,2u);
    le32(f,32040u);le32(f,32040u*4u);le16(f,4u);le16(f,16u);fwrite("data",1u,4u,f);le32(f,0u);
    return ferror(f)==0;
}
static int wav_finish(FILE *f,uint64_t frames){
    uint64_t data64=frames*4u;uint32_t data,rifflen;if(!f||data64>0xffffffffu-36u)return 0;data=(uint32_t)data64;rifflen=36u+data;
    if(fseek(f,4,SEEK_SET)!=0)return 0;
    le32(f,rifflen);
    if(fseek(f,40,SEEK_SET)!=0)return 0;
    le32(f,data);
    return fflush(f)==0;
}

static uint16_t button_bit(const char *n){
    if(!n)return 0u;
    if(!strcmp(n,"B"))return 0x8000u;
    if(!strcmp(n,"Y"))return 0x4000u;
    if(!strcmp(n,"SELECT"))return 0x2000u;
    if(!strcmp(n,"START"))return 0x1000u;
    if(!strcmp(n,"UP"))return 0x0800u;
    if(!strcmp(n,"DOWN"))return 0x0400u;
    if(!strcmp(n,"LEFT"))return 0x0200u;
    if(!strcmp(n,"RIGHT"))return 0x0100u;
    if(!strcmp(n,"A"))return 0x0080u;
    if(!strcmp(n,"X"))return 0x0040u;
    if(!strcmp(n,"L"))return 0x0020u;
    if(!strcmp(n,"R"))return 0x0010u;
    return 0u;
}
static int parse_buttons(const char *text,uint16_t *mask){
    char tmp[192],*tok;uint16_t out=0u;if(!text||!mask||strlen(text)>=sizeof(tmp))return 0;snprintf(tmp,sizeof(tmp),"%s",text);
    if(!strcmp(tmp,"NONE")||!strcmp(tmp,"0")){*mask=0u;return 1;}tok=strtok(tmp,"+,");
    while(tok){char up[32];size_t n=strlen(tok),j;uint16_t bit;if(!n||n>=sizeof(up))return 0;for(j=0;j<n;j++)up[j]=(char)((tok[j]>='a'&&tok[j]<='z')?tok[j]-'a'+'A':tok[j]);up[n]='\0';bit=button_bit(up);if(!bit)return 0;out=(uint16_t)(out|bit);tok=strtok(NULL,"+,");}
    *mask=out;return 1;
}
static uint64_t master_to_ms(uint64_t c){return (c*11000ull)/236250000ull;}
static const char *known_screen(const TopGearV24FrameInfo *f){
    if(!f)return "UNKNOWN";
    if(!strcmp(f->bgr555_sha256,"4851c862ee1a0123622f5fe0f3fce1e7f599a586385b11af856bb09c6cdc580b"))return "TITLE_PRESS_START";
    if(!strcmp(f->bgr555_sha256,"dc6f0aea332cda2358768b9f6638b21fbf8de5c802a8b281d072a2a07baa7f7e"))return "BOOT_KEMCO_PRESENTS";
    if(!strcmp(f->bgr555_sha256,"96c94d0826105fe47c587fd79e8869ce5edbfbacdddab9f4f30c5fecba2ca6a3"))return "BLANK_OR_TRANSITION";
    if(!strcmp(f->bgr555_sha256,"fcfd1cc20df9d73f4399c20ad8cb45a9cd2996d1d0679530d5e91ba96f4aeca6"))return "OPTIONS_MENU";
    if(!strcmp(f->bgr555_sha256,"b33e0cc5b6fc2b4a03fee3b2e4b471da62cbf2239ed644afdf34716b6798f71d"))return "ENTER_NAME";
    if(!strcmp(f->bgr555_sha256,"b337a01e6e690d155a5a9b3ba47a0f4f7080d6cfadaa983ac058406999a5560a"))return "GEAR_SELECT";
    if(!strcmp(f->bgr555_sha256,"505145b6ecbd5057f0dd854094098492e47b3e9180d483e221cc9b1a1db98cb5"))return "CONTROL_METHOD";
    if(!strcmp(f->bgr555_sha256,"c9d50da9113f8e571311249376f6a7d4115d5ed7334a60e7dc5110746aa0fdc6"))return "CAR_TYPE";
    if(!strcmp(f->bgr555_sha256,"100f69ba78b40119d65dabefe84cf1d53da8dc3df3066ebde60e4c001d57d370"))return "TRACK_BRIEFING";
    return "UNCLASSIFIED";
}

#define MAX_EVENTS 512u
typedef struct{uint64_t at_ms;uint16_t p1,p2;char label[96];}Event;
typedef struct{
    TopGearRecomp *core;FILE *csv;Event events[MAX_EVENTS];size_t count,next;uint16_t p1,p2;char prefix[768];unsigned capture_number;int capture_pending;
    uint64_t frames,title_ms,post_start_ms;int start_seen;
    FILE *wav;uint64_t wav_start_ms,wav_target_frames,wav_frames;
}Ctx;

static int load_script(const char *path,Ctx *c){
    FILE *f;char line[640];unsigned ln=0u;uint64_t prev=0u;int have=0;if(!path||!c)return 0;f=fopen(path,"rb");if(!f){fprintf(stderr,"Unable to open dual input script %s: %s\n",path,strerror(errno));return 0;}
    while(fgets(line,sizeof(line),f)){
        char p1[192],p2[192],label[96]="";unsigned long long ms;char *q=line;int fields;while(*q==' '||*q=='\t')q++;if(!*q||*q=='\n'||*q=='#')continue;ln++;
        fields=sscanf(q,"%llu %191s %191s %95[^\n]",&ms,p1,p2,label);if(fields<3||c->count>=MAX_EVENTS||(have&&(uint64_t)ms<prev)){fprintf(stderr,"Invalid dual input script line %u.\n",ln);fclose(f);return 0;}
        c->events[c->count].at_ms=(uint64_t)ms;if(!parse_buttons(p1,&c->events[c->count].p1)||!parse_buttons(p2,&c->events[c->count].p2)){fprintf(stderr,"Unknown buttons on line %u.\n",ln);fclose(f);return 0;}
        if(fields>=4){char *z=label;while(*z==' '||*z=='\t')z++;snprintf(c->events[c->count].label,sizeof(c->events[c->count].label),"%s",z);}else snprintf(c->events[c->count].label,sizeof(c->events[c->count].label),"event-%zu",c->count);
        prev=(uint64_t)ms;have=1;c->count++;
    }
    fclose(f);return 1;
}
static void capture_state(Ctx *c){
    const size_t fb=256u*224u*2u;uint8_t *frame,*wram;char path[1024];FILE *f;if(!c||!c->capture_pending)return;
    frame=(uint8_t*)malloc(fb);if(frame&&topgear_recomp_v22_read_frame_bgr555(c->core,0u,frame,fb)){snprintf(path,sizeof(path),"%s.event-%03u.ppm",c->prefix,c->capture_number);(void)write_ppm(path,frame);}free(frame);
    wram=(uint8_t*)malloc(TOPGEAR_RECOMP_WRAM_SIZE);if(wram&&topgear_recomp_read_wram(c->core,0u,wram,TOPGEAR_RECOMP_WRAM_SIZE)){snprintf(path,sizeof(path),"%s.event-%03u.wram.bin",c->prefix,c->capture_number);f=fopen(path,"wb");if(f){fwrite(wram,1u,TOPGEAR_RECOMP_WRAM_SIZE,f);fclose(f);}}free(wram);
    { uint8_t *vram=(uint8_t*)malloc(65536u); if(vram&&topgear_recomp_v07_read_vram(c->core,0u,vram,65536u)){snprintf(path,sizeof(path),"%s.event-%03u.vram.bin",c->prefix,c->capture_number);f=fopen(path,"wb");if(f){fwrite(vram,1u,65536u,f);fclose(f);}} free(vram); }
    { uint8_t oam[544]; if(topgear_recomp_v07_read_oam(c->core,0u,oam,sizeof(oam))){snprintf(path,sizeof(path),"%s.event-%03u.oam.bin",c->prefix,c->capture_number);f=fopen(path,"wb");if(f){fwrite(oam,1u,sizeof(oam),f);fclose(f);}} }
    c->capture_pending=0;
}
static void drain_audio(Ctx *c,uint64_t ms){
    int16_t samples[4096u*2u];size_t got;if(!c||!c->core)return;
    while(topgear_recomp_audio_available(c->core)>0u){
        got=topgear_recomp_audio_read(c->core,samples,4096u);if(!got)break;
        if(c->wav&&ms>=c->wav_start_ms&&c->wav_frames<c->wav_target_frames){
            uint64_t left=c->wav_target_frames-c->wav_frames;size_t use=got;if((uint64_t)use>left)use=(size_t)left;
            if(use&&fwrite(samples,sizeof(int16_t)*2u,use,c->wav)!=use){fprintf(stderr,"WAV write failed.\n");c->wav_target_frames=c->wav_frames;return;}
            c->wav_frames+=(uint64_t)use;
        }
    }
}
static void frame_cb(void *user,const TopGearV24FrameInfo *frame){
    Ctx *c=(Ctx*)user;uint64_t ms;const char *screen;TopGearV08InterruptInputInfo in;if(!c||!frame||!c->csv)return;ms=master_to_ms(frame->elapsed_master_clocks);
    while(c->next<c->count&&c->events[c->next].at_ms<=ms){Event *e=&c->events[c->next];c->p1=e->p1;c->p2=e->p2;(void)topgear_recomp_v08_set_controller_state(c->core,0u,c->p1);(void)topgear_recomp_v08_set_controller_state(c->core,1u,c->p2);if(c->p1&0x1000u)c->start_seen=1;if(!strncmp(e->label,"capture",7u)){c->capture_number=(unsigned)c->next;c->capture_pending=1;}c->next++;}
    screen=known_screen(frame);if(!strcmp(screen,"TITLE_PRESS_START")&&c->title_ms==0u)c->title_ms=ms;if(c->start_seen&&strcmp(screen,"TITLE_PRESS_START")&&strcmp(screen,"BOOT_KEMCO_PRESENTS")&&strcmp(screen,"BLANK_OR_TRANSITION")&&c->post_start_ms==0u)c->post_start_ms=ms;
    memset(&in,0,sizeof(in));(void)topgear_recomp_v08_interrupt_input_info(c->core,&in);
    fprintf(c->csv,"%llu,%llu,%llu,%04X,%04X,%s,%u,%02X,%02X,%04X,%04X,%04X,%04X,%s\n",(unsigned long long)frame->frame_index,(unsigned long long)frame->elapsed_master_clocks,(unsigned long long)ms,c->p1,c->p2,screen,frame->mode,frame->main_screen_mask,frame->sub_screen_mask,in.controller_state[0],in.controller_state[1],in.autojoy_result[0],in.autojoy_result[1],frame->bgr555_sha256);
    capture_state(c);drain_audio(c,ms);c->frames++;
}

static int run_v27(TopGearRecomp *core,uint32_t seconds,const char *script,const char *prefix,const char *wav_path,uint64_t wav_start_ms,uint64_t wav_duration_ms){
    TopGearV24DurationReport r;TopGearStaticAudioStatus a;Ctx c;enum TopGearRunResult rr;char trace[1024];size_t due=0u;int ok=1;memset(&c,0,sizeof(c));c.core=core;snprintf(c.prefix,sizeof(c.prefix),"%s",prefix);if(!load_script(script,&c))return 1;
    while(due<c.count&&c.events[due].at_ms<=(uint64_t)seconds*1000u)due++;
    if(wav_path){c.wav=fopen(wav_path,"wb");if(!c.wav||!wav_begin(c.wav)){fprintf(stderr,"Unable to create WAV %s.\n",wav_path);if(c.wav)fclose(c.wav);return 1;}c.wav_start_ms=wav_start_ms;c.wav_target_frames=(32040ull*wav_duration_ms+500ull)/1000ull;}
    snprintf(trace,sizeof(trace),"%s.frames.csv",prefix);c.csv=fopen(trace,"wb");if(!c.csv){fprintf(stderr,"Unable to create %s: %s\n",trace,strerror(errno));if(c.wav)fclose(c.wav);return 1;}
    fprintf(c.csv,"frame_index,elapsed_master_clocks,elapsed_ms,p1_mask,p2_mask,screen_state,mode,main_screen_mask,sub_screen_mask,controller_state0,controller_state1,autojoy_result0,autojoy_result1,bgr555_sha256\n");
    (void)topgear_recomp_v25_begin_coverage(core);(void)topgear_recomp_v08_set_controller_state(core,0u,0u);(void)topgear_recomp_v08_set_controller_state(core,1u,0u);
    rr=topgear_recomp_v24_run_main_core_seconds(core,seconds,350000000ull,frame_cb,&c,&r);drain_audio(&c,UINT64_MAX);fclose(c.csv);
    if(c.wav){if(!wav_finish(c.wav,c.wav_frames))ok=0;fclose(c.wav);c.wav=NULL;}
    memset(&a,0,sizeof(a));if(!topgear_recomp_static_audio_status(core,&a))ok=0;
    printf("Top Gear SNES Static Recomp Version 27 Full Static run\nRequested seconds: %u; frames: %llu; instructions: %llu; endpoint: %02X:%04X\n",seconds,(unsigned long long)r.frame_events,(unsigned long long)r.executed_instructions,r.endpoint_cpu.pbr,r.endpoint_cpu.pc);
    printf("Events applied: %zu/%zu due (%zu scripted); P1=%04X; P2=%04X; title=%llu ms; first post-Start=%llu ms\n",c.next,due,c.count,c.p1,c.p2,(unsigned long long)c.title_ms,(unsigned long long)c.post_start_ms);
    printf("Static audio: backend=%s SMP-PC=%04X instructions=%llu AOT=%llu PCM=%llu syncs=%llu AOT-failed=%u DSP-failed=%u code-write-barriers=%u fallback=%u\n",topgear_recomp_audio_backend_name(core),a.smp_pc,(unsigned long long)a.smp_instructions,(unsigned long long)a.aot_validated_instructions,(unsigned long long)a.pcm_frames,(unsigned long long)a.sync_calls,a.aot_failed,a.sdsp_static_failed,a.code_write_barriers,a.automatic_fallback_enabled);
    printf("PCM proof: known=%llu unknown=%llu hash=%016llX DSP-overflows=%llu host-dropped=%llu\n",
        (unsigned long long)a.pcm_known_frames,(unsigned long long)a.pcm_unknown_frames,
        (unsigned long long)a.pcm_hash,(unsigned long long)a.dsp_pcm_overflows,
        (unsigned long long)a.fifo_dropped_frames);
    if(rr!=TOPGEAR_RUN_COMPLETE)printf("Frontier/error: %s\n",topgear_recomp_last_error(core));
    if(wav_path)printf("WAV: %s; capture-start=%llu ms; requested=%llu ms; frames=%llu at 32040 Hz\n",wav_path,(unsigned long long)wav_start_ms,(unsigned long long)wav_duration_ms,(unsigned long long)c.wav_frames);
    { TopGearRallyDebugStatus rs; unsigned ri;
      if(topgear_recomp_rally_debug_status(core,&rs)&&rs.schedule_valid){
        printf("Rally schedule: generation=%llu active=%u race-index=%u ordinals=",
               (unsigned long long)rs.generation_count,(unsigned)rs.active,(unsigned)rs.race_index);
        for(ri=0u;ri<8u;ri++)printf("%s%u",ri?",":"",(unsigned)rs.schedule[ri]);
        printf(" rng=%08X\n",(unsigned)rs.rng_state);
      }
    }
    printf("Trace: %s\n",trace);
    if(wav_path&&c.wav_frames!=c.wav_target_frames)ok=0;
    return rr==TOPGEAR_RUN_COMPLETE&&!r.instruction_limit_hit&&c.next==due&&!a.aot_failed&&!a.sdsp_static_failed&&a.pcm_unknown_frames==0u&&a.dsp_pcm_overflows==0u&&a.automatic_fallback_enabled==0u&&ok?0:1;
}
static void usage(const char *n){
    printf("Top Gear SNES Static Recomp Version 27 current launcher\n");
    printf("Usage: %s --headless-v27 <Top Gear (USA).sfc> <seconds> <dual-input-script.txt> <output-prefix>\n",n);
    printf("       %s --headless-v27 <ROM> <seconds> <script> <prefix> <output.wav> <capture-start-ms> <capture-duration-ms>\n",n);
    printf("Script: <milliseconds> <P1-buttons> <P2-buttons> [label]. Use NONE for idle. Labels beginning with capture write PPM+WRAM evidence.\n");
    printf("Production audio is Full Static AOT S-SMP/S-DSP only; no alternate runtime audio backend is linked.\n");
}
int main(int argc,char **argv){
    uint8_t *rom=NULL;size_t size=0u;TopGearRecomp *core=NULL;char err[256];unsigned long seconds;unsigned long long start=0u,duration=0u;char *end=NULL;int status;const char *wav=NULL;
    if(argc==1){usage(argv[0]);return 0;}if((argc!=6&&argc!=9)||strcmp(argv[1],"--headless-v27")){usage(argv[0]);return 2;}
    seconds=strtoul(argv[3],&end,10);if(!end||*end||seconds==0u||seconds>86400u){fprintf(stderr,"Invalid seconds.\n");return 2;}
    if(argc==9){wav=argv[6];start=strtoull(argv[7],&end,10);if(!end||*end)return 2;duration=strtoull(argv[8],&end,10);if(!end||*end||duration==0u)return 2;}
    if(!load_file(argv[2],&rom,&size))return 1;
    if(!topgear_recomp_create(&core,rom,size,err,sizeof(err))){fprintf(stderr,"Core creation failed: %s\n",err);free(rom);return 1;}
    status=run_v27(core,(uint32_t)seconds,argv[4],argv[5],wav,(uint64_t)start,(uint64_t)duration);topgear_recomp_destroy(core);free(rom);return status;
}
