#define main old_menu_audio_main
#include "test_menu_insert_audio.c"
#undef main
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d %s: %s\n",__LINE__,#x,topgear_recomp_last_error(c));return 1;}}while(0)
static int frames(TopGearRecomp*c,uint16_t input,unsigned count){TopGearRecompFrameResult result;int16_t pcm[4096];for(unsigned n=0;n<count;n++){if(!topgear_recomp_advance_headless(c,input,0,1,&result))return 0;while(topgear_recomp_audio_read(c,pcm,2048)){} }return 1;}
static int press(TopGearRecomp*c,uint16_t input){return frames(c,input,15)&&frames(c,0,45);}
static int playing_snapshot(TopGearRecomp*c,const char*dir){
 char path[1024],error[256];int16_t samples[2][32768];size_t used[2]={0,0},n;TopGearRecompFrameResult result;
 snprintf(path,sizeof(path),"%s/finish-playing.snap",dir);
 if(!topgear_recomp_snapshot_save(c,path,error,sizeof(error)))return 0;
 for(unsigned pass=0;pass<2;pass++){
  for(unsigned f=0;f<12;f++){
   if(!topgear_recomp_advance_headless(c,TOPGEAR_INPUT_A,0,1,&result))return 0;
   while((n=topgear_recomp_audio_read(c,samples[pass]+used[pass],(32768-used[pass])/2))!=0)used[pass]+=n*2;
  }
  if(!topgear_recomp_snapshot_load(c,path,error,sizeof(error)))return 0;
 }
 return used[0]&&used[0]==used[1]&&!memcmp(samples[0],samples[1],used[0]*sizeof(int16_t));
}
int main(int argc,char**argv){
 TopGearRecomp*c=0;TopGearRecompFrameResult result;uint8_t*rom=0;size_t bytes;char error[256],baseline[1024],path[1024];
 if(argc!=3)return 2;if(!load_file(argv[1],&rom,&bytes)||!topgear_recomp_create(&c,rom,bytes,error,sizeof(error)))return 2;
 CHECK(frames(c,0,1560));CHECK(frames(c,TOPGEAR_INPUT_START,120));CHECK(frames(c,0,220));
 snprintf(baseline,sizeof(baseline),"%s/start-baseline.snap",argv[2]);CHECK(topgear_recomp_snapshot_save(c,baseline,error,sizeof(error)));
 for(unsigned engine=0;engine<3;engine++)for(unsigned mode=0;mode<3;mode++){
  WavCapture wav;uint64_t before;unsigned sounding=0;int16_t pcm[2048];size_t count;
  uint16_t start_button=mode==2u?TOPGEAR_INPUT_START:TOPGEAR_INPUT_A;
  CHECK(topgear_recomp_snapshot_load(c,baseline,error,sizeof(error)));
  for(unsigned n=0;n<engine;n++)CHECK(press(c,0x10u));
  CHECK(c->mod_music_engine==engine);c->mod_audio_mute=1u;
  for(unsigned n=0;n<mode;n++)CHECK(press(c,TOPGEAR_INPUT_DOWN));
  CHECK(press(c,TOPGEAR_INPUT_A));
  for(unsigned n=0;n<(mode==1?2u:3u);n++)CHECK(press(c,TOPGEAR_INPUT_DOWN));
  CHECK(c->mod_menu_remodel_page==mode+1u);CHECK(c->mod_insert_audio_sfx_state==0u);
  before=c->mod_insert_audio_cue_keyon_count;
  snprintf(path,sizeof(path),"%s/finish-mode-%u-engine-%u.wav",argv[2],mode,engine);CHECK(wav_open(&wav,path));
  for(unsigned f=0;f<100;f++){
   CHECK(topgear_recomp_advance_headless(c,f<90?start_button:0,0,1,&result));
   while((count=topgear_recomp_audio_read(c,pcm,1024))!=0){for(size_t k=0;k<count*2;k++)if(pcm[k])sounding++;CHECK(fwrite(pcm,4,count,wav.file)==count);wav.frames+=count;}
   if(f==5){CHECK(c->mod_insert_audio_sfx_state==6u);CHECK(playing_snapshot(c,argv[2]));}
  }
  CHECK(wav_close(&wav));CHECK(sounding>20000u);CHECK(c->mod_insert_audio_cue_keyon_count==before+1u);CHECK(c->mod_insert_audio_sfx_state==0u);
  printf("PASS %s / %s: one-shot held Start, natural completion, playing snapshot, music mute, audible finish cue (%u samples)\n",mode==0?"Career":mode==1?"Rally":"Time Trial",engine==0?"Top Gear":engine==1?"Top Gear 2":"Top Gear 3000",sounding);
 }
 topgear_recomp_destroy(c);free(rom);return 0;
}
