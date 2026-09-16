#include "topgear/topgear_dsp.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static topgear_dsp a,b,c,saved,saved_c;
static uint8_t ar[65536],br[65536],cr[65536],ak[8192],bk[8192],ck[8192];
static const uint8_t cue_brr[54]={
  0x02,0,0,0,0,0,0,0,0,0x7a,4,0x23,0x22,0x11,0x1f,0xff,0xed,0xff,
  0x6a,0xbd,0xf0,0xee,0xfe,0xdd,0xdc,0xec,0xce,0x6a,0xed,0xe0,0xff,0x11,0x32,0x45,0x55,0x55,
  0x6a,0x56,0x64,0x44,0x31,0x2f,0xdc,0xdc,0xec,0x6b,0xce,0xef,0xff,0xed,0xde,0xdc,0xec,0xcd};
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#x);return 1;}}while(0)
static void wr(topgear_dsp*d,unsigned r,unsigned v){topgear_dsp_write_register(d,(uint8_t)r,(uint8_t)v);}
static void setup(topgear_dsp*d,uint8_t*r,uint8_t*k){
 unsigned v;memset(r,0,65536);memset(k,255,8192);topgear_dsp_power_on(d,r,k);
 memcpy(r+0xc000,cue_brr,54);r[0x8a40]=0;r[0x8a41]=0xc0;r[0x8a42]=0x1b;r[0x8a43]=0xc0;
 wr(d,0x6c,0x20);wr(d,0x5d,0x8a);wr(d,0x0c,0x7f);wr(d,0x1c,0x7f);
 for(v=0;v<8;v++){wr(d,v*16,12+v);wr(d,v*16+1,20-v);wr(d,v*16+2,0xbb);wr(d,v*16+3,0x17);wr(d,v*16+4,16);wr(d,v*16+5,0xfe);wr(d,v*16+6,0xf5);wr(d,v*16+7,0x70);}
 wr(d,0x4c,255);
}
static void cue_on(void){wr(&c,0x70,60);wr(&c,0x71,60);wr(&c,0x72,0xbb);wr(&c,0x73,0x17);wr(&c,0x74,16);wr(&c,0x75,0xfe);wr(&c,0x76,0xf5);wr(&c,0x77,0x70);wr(&c,0x5c,0);wr(&c,0x4c,128);}
int main(void){
 unsigned n,phase,mode;int16_t ap[2],bp[2],replay[4000],first[4000];unsigned nonzero=0;
 /* Every possible activation phase, with noise, PMON and echo enabled in
    combinations. Music register 7, ENDX, envelope and PCM must stay exact. */
 for(mode=0;mode<4;mode++)for(phase=0;phase<32;phase++){
  setup(&a,ar,ak);setup(&b,br,bk);
  wr(&a,0x2d,(mode&1)?128:0);wr(&b,0x2d,(mode&1)?128:0);
  wr(&a,0x3d,(mode&2)?128:0);wr(&b,0x3d,(mode&2)?128:0);
  wr(&a,0x4d,128);wr(&b,0x4d,128);wr(&a,0x2c,30);wr(&b,0x2c,30);wr(&a,0x3c,30);wr(&b,0x3c,30);
  for(n=0;n<32000;n++){
   if(n==320+phase)topgear_dsp_virtualize_voice7(&b,1);
   if(n==19000+phase)topgear_dsp_virtualize_voice7(&b,0);
   if(n==10000){wr(&a,0x5c,128);wr(&b,0x5c,128);}
   if(n==12000){wr(&a,0x5c,0);wr(&b,0x5c,0);wr(&a,0x4c,128);wr(&b,0x4c,128);}
   CHECK(topgear_dsp_step_phase(&a)==0);CHECK(topgear_dsp_step_phase(&b)==0);
   CHECK(!memcmp(a.regs,b.regs,128));
   if(topgear_dsp_pcm_available(&a)){CHECK(topgear_dsp_pcm_read(&a,ap,1)==1);CHECK(topgear_dsp_pcm_read(&b,bp,1)==1);CHECK(!memcmp(ap,bp,sizeof(ap)));}
  }
  CHECK(!memcmp(ar,br,sizeof(ar)));
 }
 /* Simultaneous ninth music lane plus cue; cue cannot alter music voice,
    ENDX, shared echo RAM or music registers. Snapshot replay while sounding. */
 setup(&a,ar,ak);setup(&b,br,bk);setup(&c,cr,ck);
 memset(c.voices,0,sizeof(c.voices));c.new_key_on=0;c.regs[0x4c]=0;
 topgear_dsp_attach_cue_lane(&b,&c);cue_on();
 for(n=0;n<2000;n++){
  CHECK(topgear_dsp_step_sample(&a)==0);CHECK(topgear_dsp_step_sample(&b)==0);
  CHECK(topgear_dsp_pcm_read(&a,ap,1)==1);CHECK(topgear_dsp_pcm_read(&b,bp,1)==1);
  if(memcmp(ap,bp,sizeof(ap)))nonzero++;
  CHECK(!memcmp(&a.voices[7],&b.voices[8],sizeof(a.voices[7])));
  CHECK(!memcmp(a.regs,b.regs,128));CHECK(!memcmp(ar,br,sizeof(ar)));
 }
 CHECK(nonzero>100);
 saved=b;saved_c=c;memcpy(br,ar,sizeof(ar));
 for(n=0;n<2000;n++){CHECK(topgear_dsp_step_sample(&b)==0);CHECK(topgear_dsp_pcm_read(&b,first+n*2,1)==1);}
 b=saved;c=saved_c;b.cue_lane=&c;
 for(n=0;n<2000;n++){CHECK(topgear_dsp_step_sample(&b)==0);CHECK(topgear_dsp_pcm_read(&b,replay+n*2,1)==1);}
 CHECK(!memcmp(first,replay,sizeof(first)));
 /* Complete music mute leaves the cue audible. */
 topgear_dsp_music_gain(&b,0);nonzero=0;
 for(n=0;n<1200;n++){CHECK(topgear_dsp_step_sample(&b)==0);CHECK(topgear_dsp_pcm_read(&b,bp,1)==1);if(bp[0]||bp[1])nonzero++;}
 CHECK(nonzero>100);
 /* The isolated SimCity lane must reproduce the original voice-7 playback
    contract exactly, including release, rather than approximate it with WAV. */
 setup(&a,ar,ak);setup(&b,br,bk);setup(&c,cr,ck);
 for(n=0;n<8;n++){wr(&a,n*16,0);wr(&a,n*16+1,0);wr(&b,n*16,0);wr(&b,n*16+1,0);}
 a.new_key_on=0;b.new_key_on=0;c.new_key_on=0;
 wr(&a,0x70,60);wr(&a,0x71,60);wr(&a,0x4c,128);
 topgear_dsp_attach_cue_lane(&b,&c);cue_on();
 nonzero=0;
 for(n=0;n<3000;n++){
  if(n==1075){wr(&a,0x5c,128);wr(&c,0x5c,128);}
  CHECK(topgear_dsp_step_sample(&a)==0);CHECK(topgear_dsp_step_sample(&b)==0);
  CHECK(topgear_dsp_pcm_read(&a,ap,1)==1);CHECK(topgear_dsp_pcm_read(&b,bp,1)==1);
  CHECK(!memcmp(ap,bp,sizeof(ap)));if(bp[0]||bp[1])nonzero++;
 }
 CHECK(nonzero>100);
 /* Imported music suppresses native music while retaining P1/P2 effects exactly. */
 setup(&a,ar,ak);setup(&b,br,bk);
 for(n=0;n<4;n++){wr(&a,n*16,0);wr(&a,n*16+1,0);}
 b.native_effects_mask=0xF0u;topgear_dsp_music_gain(&b,0u);nonzero=0;
 for(n=0;n<4000;n++){
  CHECK(topgear_dsp_step_sample(&a)==0);CHECK(topgear_dsp_step_sample(&b)==0);
  CHECK(topgear_dsp_pcm_read(&a,ap,1)==1);CHECK(topgear_dsp_pcm_read(&b,bp,1)==1);
  CHECK(!memcmp(ap,bp,sizeof(ap)));if(bp[0]||bp[1])nonzero++;
 }
 CHECK(nonzero>100u);
 puts("PASS: voice9 all 32 phases, PMON/NON/EON/KON/KOFF/ENDX, exact music PCM, cue isolation, gain mute and playing snapshot replay");return 0;
}
