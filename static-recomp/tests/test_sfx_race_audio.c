#include "topgear_static_recomp.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AUDIO_RATE TOPGEAR_RECOMP_HOST_AUDIO_SAMPLE_RATE
#define NTSC_CLOCK TOPGEAR_RECOMP_NTSC_MASTER_CLOCK_HZ
#define AVG_NTSC_FRAME_MASTER_CLOCKS UINT64_C(357366)

typedef struct Probe { const char *name; uint8_t command; } Probe;

static int load_file(const char *path, uint8_t **data, size_t *size) {
    FILE *f = fopen(path, "rb"); long n;
    *data = NULL; *size = 0u;
    if (!f) return 0;
    if (fseek(f, 0, SEEK_END) != 0 || (n = ftell(f)) < 0 || fseek(f, 0, SEEK_SET) != 0) { fclose(f); return 0; }
    *data = (uint8_t *)malloc((size_t)n);
    if (!*data || fread(*data, 1u, (size_t)n, f) != (size_t)n) { free(*data); *data=NULL; fclose(f); return 0; }
    fclose(f); *size=(size_t)n; return 1;
}
static uint64_t fnv_update(uint64_t h, const void *data, size_t bytes) {
    const uint8_t *p=(const uint8_t *)data; size_t i;
    for(i=0;i<bytes;++i){ h^=p[i]; h*=UINT64_C(1099511628211); }
    return h;
}
static int drain_hash(TopGearRecomp *core, uint64_t *hash, uint64_t *frames) {
    int16_t pcm[4096u*2u];
    while(topgear_recomp_audio_available(core)){
        size_t got=topgear_recomp_audio_read(core,pcm,4096u);
        if(!got) break;
        *hash=fnv_update(*hash,pcm,got*2u*sizeof(pcm[0])); *frames+=got;
    }
    return 1;
}
static int drain_hash_tail(TopGearRecomp *core,uint64_t *hash,uint64_t *frames,uint64_t *last_nonzero){
    int16_t pcm[4096u*2u];
    while(topgear_recomp_audio_available(core)){
        size_t got=topgear_recomp_audio_read(core,pcm,4096u),i;
        uint64_t base=*frames;
        if(!got) break;
        for(i=0u;i<got;++i) if(pcm[i*2u]!=0||pcm[i*2u+1u]!=0)*last_nonzero=base+i+1u;
        *hash=fnv_update(*hash,pcm,got*2u*sizeof(pcm[0])); *frames+=got;
    }
    return 1;
}
static int advance_hash_tail(TopGearRecomp *core,uint64_t clocks,uint64_t *hash,uint64_t *frames,uint64_t *last_nonzero,char *err,size_t cap){
    const uint64_t chunk=NTSC_CLOCK/50u; uint64_t done=0u;
    while(done<clocks){ uint64_t step=(clocks-done)<chunk?(clocks-done):chunk;
        if(!topgear_recomp_audio_preview_advance(core,step,err,cap)) return 0;
        if(!drain_hash_tail(core,hash,frames,last_nonzero)) return 0;
        done+=step;
    }
    return 1;
}
static int advance_hash(TopGearRecomp *core, uint64_t clocks, uint64_t *hash, uint64_t *frames, char *err, size_t cap) {
    const uint64_t chunk=NTSC_CLOCK/50u; uint64_t done=0u;
    while(done<clocks){ uint64_t step=(clocks-done)<chunk?(clocks-done):chunk;
        if(!topgear_recomp_audio_preview_advance(core,step,err,cap)) return 0;
        if(!drain_hash(core,hash,frames)) return 0;
        done+=step;
    }
    return 1;
}
static int prep(TopGearRecomp *core, char *err, size_t cap){
    if(!topgear_recomp_music_preview_prepare(core,0x05u,err,cap)) return 0;
    if(!topgear_recomp_music_command(core,0x00u,err,cap)) return 0;
    if(!topgear_recomp_audio_preview_advance(core,NTSC_CLOCK/5u,err,cap)) return 0;
    (void)topgear_recomp_audio_discard(core,topgear_recomp_audio_available(core));
    topgear_recomp_audio_clear(core); return 1;
}
static int effect_probe(TopGearRecomp *core, const Probe *p, uint64_t *out, char *err, size_t cap){
    uint64_t h=UINT64_C(1469598103934665603),frames=0u,last_nonzero=0u; TopGearStaticAudioStatus st;
    if(!prep(core,err,cap) || !topgear_recomp_sound_command_pulse(core,p->command,err,cap) ||
       !advance_hash_tail(core,NTSC_CLOCK,&h,&frames,&last_nonzero,err,cap)) return 0;
    memset(&st,0,sizeof(st)); (void)topgear_recomp_static_audio_status(core,&st);
    if(st.aot_failed||st.sdsp_static_failed||frames==0u){ snprintf(err,cap,"%s static audio failure",p->name); return 0; }
    if(last_nonzero==0u||frames-last_nonzero<(uint64_t)(AUDIO_RATE/10u)){
        snprintf(err,cap,"%s did not reach at least 100 ms of natural silence after one command pulse (frames=%llu last=%llu)",p->name,(unsigned long long)frames,(unsigned long long)last_nonzero); return 0;
    }
    printf("effect=%s command=%02X frames=%llu last-nonzero=%llu tail-ms=%llu hash=%016llX\n",p->name,p->command,(unsigned long long)frames,(unsigned long long)last_nonzero,(unsigned long long)(((frames-last_nonzero)*1000u)/AUDIO_RATE),(unsigned long long)h);
    *out=h; return 1;
}
static int engine_probe(TopGearRecomp *core, uint16_t pitch, uint64_t *out, char *err, size_t cap){
    uint64_t h=UINT64_C(1469598103934665603),frames=0u; TopGearStaticAudioStatus st;
    if(!prep(core,err,cap) || !topgear_recomp_sound_command(core,0x02u,err,cap) ||
       !advance_hash(core,AVG_NTSC_FRAME_MASTER_CLOCKS,&h,&frames,err,cap) ||
       !topgear_recomp_sound_parameter_command(core,0x03u,pitch,err,cap) ||
       !advance_hash(core,NTSC_CLOCK/2u,&h,&frames,err,cap)) return 0;
    memset(&st,0,sizeof(st)); (void)topgear_recomp_static_audio_status(core,&st);
    if(st.aot_failed||st.sdsp_static_failed||frames==0u){ snprintf(err,cap,"engine static audio failure"); return 0; }
    printf("engine pitch=%04X frames=%llu hash=%016llX\n",pitch,(unsigned long long)frames,(unsigned long long)h);
    *out=h; return 1;
}
int main(int argc,char **argv){
    static const Probe probes[]={{"boost",0x05u},{"finish",0x07u},{"skid",0x0Au},{"collision",0x0Bu}};
    static const uint64_t expected[6]={
        UINT64_C(0x87B87041A57EF3B7), UINT64_C(0xE07612FC1588582F),
        UINT64_C(0x5A78E0AEA96C9393), UINT64_C(0x1A52F20609A734E7),
        UINT64_C(0xAE5E192466A90557), UINT64_C(0x6A7C3CA87FE807E7)};
    uint8_t *rom=NULL; size_t size=0u; TopGearRecomp *core=NULL; char err[256]; uint64_t hashes[6]; size_t i,j;
    if(argc!=2||!load_file(argv[1],&rom,&size)) return 2;
    if(!topgear_recomp_create(&core,rom,size,err,sizeof(err))){fprintf(stderr,"create failed: %s\n",err);free(rom);return 1;} free(rom);
    for(i=0;i<4u;++i) if(!effect_probe(core,&probes[i],&hashes[i],err,sizeof(err))){fprintf(stderr,"%s probe failed: %s\n",probes[i].name,err);topgear_recomp_destroy(core);return 1;}
    if(!engine_probe(core,0x0400u,&hashes[4],err,sizeof(err))||!engine_probe(core,0x1200u,&hashes[5],err,sizeof(err))){fprintf(stderr,"engine probe failed: %s\n",err);topgear_recomp_destroy(core);return 1;}
    for(i=0;i<6u;++i){
        if(hashes[i]!=expected[i]){fprintf(stderr,"race audio probe %zu hash mismatch: got %016llX expected %016llX\n",i,(unsigned long long)hashes[i],(unsigned long long)expected[i]);topgear_recomp_destroy(core);return 1;}
        for(j=i+1u;j<6u;++j) if(hashes[i]==hashes[j]){fprintf(stderr,"race audio probes %zu and %zu unexpectedly match\n",i,j);topgear_recomp_destroy(core);return 1;}
    }
    topgear_recomp_destroy(core); return 0;
}
