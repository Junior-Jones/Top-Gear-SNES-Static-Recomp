#include "topgear_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static TopGearRecomp *core, *reference;
static char error[256];
static const char *output;
static int both_native_controllers;
static unsigned checked, bad_frames, page_checks[17], page_bad[17];
static uint8_t previous_gold[256u*224u];
static uint8_t older_gold[256u*224u];
static unsigned previous_page=255u;
static unsigned older_page=255u,desired_page=255u,target_seen;
static uint32_t last_desired;

static int gold(const uint8_t *pixel) {
    unsigned c=pixel[0]|((unsigned)pixel[1]<<8),r=c&31u,g=(c>>5)&31u,b=(c>>10)&31u;
    return r>6u&&g>6u&&r>b*2u&&g>b*2u;
}

static void capture(const char *label) {
    char path[1024]; unsigned n; uint32_t *pixels;
    FILE *f;
    pixels=(uint32_t*)malloc(256u*224u*sizeof(*pixels));
    if(!pixels)return;
    snprintf(path,sizeof(path),"%s/%s.ppm",output,label);
    if(topgear_recomp_frame_bgra(core,pixels,256u*224u)&&(f=fopen(path,"wb"))!=NULL){
        fprintf(f,"P6\n256 224\n255\n");
        for(n=0;n<256u*224u;n++){
            unsigned char rgb[3]={(unsigned char)(pixels[n]>>16),(unsigned char)(pixels[n]>>8),(unsigned char)pixels[n]};
            fwrite(rgb,1,3,f);
        }
        fclose(f);
    }
    free(pixels);
}

static int inspect(void) {
    TopGearV22VideoInfo info; unsigned x,y,mismatch=0,previous_mismatch=0,older_mismatch=0,page=core->mod_menu_remodel_page;
    uint32_t desired=2166136261u;
    if(!core->mod_menu_remodel_active||core->brightness!=15u||core->forced_blank)return 1;
    memcpy(reference,core,sizeof(*core));
    reference->mod_menu_remodel_dirty=1u;
    tg_mod_menu_remodel_draw_if_dirty(reference);
    if(!topgear_recomp_v22_render_current_frame(reference,&info))return 0;
    /* Compare the gold lettering, including gaps where obsolete rows appear.
       The native selector is blue and its next-frame OAM position is allowed
       to differ from the just-completed frame. The monochrome background and
       selector must not produce false positives for missing menu lettering. */
    for(y=32;y<200;y++)for(x=24;x<232;x++){
        unsigned a=(y*256u+x)*2u;
        unsigned actual=(unsigned)gold(core->mode1_frame+a),expected=(unsigned)gold(reference->mode1_frame+a);
        if(actual!=expected)mismatch++;
        if(actual!=previous_gold[y*256u+x])previous_mismatch++;
        if(actual!=older_gold[y*256u+x])older_mismatch++;
        older_gold[y*256u+x]=previous_gold[y*256u+x];
        previous_gold[y*256u+x]=(uint8_t)expected;
        desired=(desired^expected)*16777619u;
    }
    /* The native polling/upload pipeline can retain the preceding complete
       value for two frames. Reject torn layouts and any reversion after the
       new value has appeared. Neither accepted layout contains stock rows. */
    if(desired_page!=page||last_desired!=desired){target_seen=0u;desired_page=page;last_desired=desired;}
    if(!mismatch)target_seen=1u;
    else if(!target_seen&&((previous_page!=255u&&!previous_mismatch)||(older_page!=255u&&!older_mismatch)))mismatch=0;
    older_page=previous_page;
    previous_page=page;
    checked++;if(page<17u)page_checks[page]++;
    if(mismatch){
        if(!bad_frames){
            TopGearRecomp *actual=core;
            capture("first-flicker");core=reference;capture("first-flicker-expected");core=actual;
            fprintf(stderr,"First mismatch: page=%u selection=%u frame=%u pixels=%u previous_pixels=%u mute=%u dirty=%u PC=%02X:%04X\n",page,core->mod_menu_remodel_selection,(unsigned)topgear_recomp_v27_frame_count(core),mismatch,previous_mismatch,core->mod_audio_mute,core->mod_menu_remodel_dirty,core->cpu.pbr,core->cpu.pc);
        }
        bad_frames++;if(page<17u)page_bad[page]++;
    }
    return 1;
}

static int frames(unsigned count,uint16_t buttons,int verify) {
    TopGearRecompFrameResult result;
    while(count--){
        if(!topgear_recomp_advance_headless(core,buttons,both_native_controllers&&!core->mod_menu_remodel_active?buttons:0,1,&result)){fprintf(stderr,"%s\n",error);return 0;}
        topgear_recomp_audio_clear(core);
        if(verify&&!inspect())return 0;
    }
    return 1;
}
static int press(uint16_t buttons,int verify){return frames(6,buttons,verify)&&frames(90,0,verify);}

int main(int argc,char **argv) {
    uint8_t rom[524288]; FILE *f; char path[1024],name[64]; unsigned route,n;
    static const unsigned pages[4]={1,2,3,12},counts[4]={4,3,4,8};
    if(argc!=3&&argc!=4)return 2;output=argv[2];
    if(argc==4&&strcmp(argv[3],"--settings-only"))return 2;
    f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
    reference=(TopGearRecomp*)malloc(sizeof(*reference));
    if(!reference||!topgear_recomp_create(&core,rom,sizeof(rom),error,sizeof(error)))return 2;
    if(!frames(1560,0,0)||!frames(120,0x1000,0)||!frames(220,0,0)||!core->mod_menu_remodel_active||core->mod_menu_remodel_page!=0)return 3;
    snprintf(path,sizeof(path),"%s/root.snap",output);
    if(!topgear_recomp_snapshot_save(core,path,error,sizeof(error)))return 3;
    if(argc==3){
        for(n=0;n<8;n++)if(!press(n<4?0x0400:0x0800,1))return 4;
        for(n=0;n<4;n++)if(!press(0x0100,1)||!press(0x0200,1)||!press(0x0400,1))return 4;
    }
    capture("root-after-navigation");
    for(route=argc==4?3u:0u;route<4;route++){
        if(!topgear_recomp_snapshot_load(core,path,error,sizeof(error)))return 5;
        for(n=0;n<route;n++)if(!press(0x0400,1))return 5;
        if(!press(0x0080,0)||core->mod_menu_remodel_page!=pages[route])return 6;
        for(n=0;n<counts[route]*2u;n++)if(!press(n<counts[route]?0x0400:0x0800,1))return 6;
        for(n=0;n<counts[route];n++)if(!press(0x0100,1)||!press(0x0200,1)||!press(0x0400,1))return 6;
        snprintf(name,sizeof(name),"page-%u-after-navigation",pages[route]);capture(name);
        if(!press(0x8000,0)||core->mod_menu_remodel_page!=0||!frames(24,0,1))return 7;
    }
    for(n=0;n<17;n++)if(page_checks[n])printf("page=%u frames=%u mismatching_frames=%u\n",n,page_checks[n],page_bad[n]);
    printf("%s: actual completed menu frames=%u mismatching_frames=%u; all four D-pad directions, held/released inputs, wrap, values and submenu returns checked; no race started\n",bad_frames?"FAIL":"PASS",checked,bad_frames);
    topgear_recomp_destroy(core);free(reference);return bad_frames?1:0;
}
