/* Reuse the WAV/file helpers; the original eight-movement test remains an
   independent CTest gate. This route uses real controller input, not RAM writes. */
#define main original_menu_audio_test
#include "test_menu_insert_audio.c"
#undef main

typedef struct Action {unsigned start,length;uint16_t input;const char*name;unsigned expected;} Action;
static const Action actions[]={
 {1560,120,TOPGEAR_INPUT_START,"Title Start",0},
 {1920,15,TOPGEAR_INPUT_DOWN,"Root Down Rally",1},
 {1965,15,TOPGEAR_INPUT_DOWN,"Root Down Time Trial",1},
 {2010,30,TOPGEAR_INPUT_A,"Enter Time Trial",1},
 {2070,60,TOPGEAR_INPUT_A,"Enter Player 1",1},
 {2220,12,TOPGEAR_INPUT_A,"Name character A",1},
 {2280,15,TOPGEAR_INPUT_UP,"Name Up",1},
 {2310,15,TOPGEAR_INPUT_DOWN,"Name Down",1},
 {2340,15,TOPGEAR_INPUT_LEFT,"Name Left",1},
 {2370,15,TOPGEAR_INPUT_RIGHT,"Name Right",1},
 {2430,15,TOPGEAR_INPUT_DOWN,"Name Down 1",1},
 {2460,15,TOPGEAR_INPUT_DOWN,"Name Down 2",1},
 {2490,15,TOPGEAR_INPUT_DOWN,"Name Down 3",1},
 {2520,15,TOPGEAR_INPUT_DOWN,"Name Down 4",1},
 {2550,15,TOPGEAR_INPUT_RIGHT,"Name Right 1",1},
 {2580,15,TOPGEAR_INPUT_RIGHT,"Name Right 2",1},
 {2610,15,TOPGEAR_INPUT_RIGHT,"Name Right 3",1},
 {2640,15,TOPGEAR_INPUT_RIGHT,"Name Right 4",1},
 {2700,45,TOPGEAR_INPUT_A,"Accept Name",1},
 {3000,15,TOPGEAR_INPUT_RIGHT,"Gear Right Auto",1},
 {3045,15,TOPGEAR_INPUT_LEFT,"Gear Left Manual",1},
 {3090,15,TOPGEAR_INPUT_RIGHT,"Gear Right Auto Again",1},
 {3150,60,TOPGEAR_INPUT_A,"Accept Gear",1},
 {3495,15,TOPGEAR_INPUT_RIGHT,"Controls Right",1},
 {3540,15,TOPGEAR_INPUT_LEFT,"Controls Left",1},
 {3600,60,TOPGEAR_INPUT_A,"Accept Controls",1},
 {3900,15,TOPGEAR_INPUT_DOWN,"Car Down",1},
 {3945,15,TOPGEAR_INPUT_UP,"Car Up",1},
 {3990,15,TOPGEAR_INPUT_RIGHT,"Car Right",1},
 {4035,15,TOPGEAR_INPUT_LEFT,"Car Left",1},
 {4110,60,TOPGEAR_INPUT_A,"Accept Car",1},
 {4410,15,TOPGEAR_INPUT_DOWN,"Time Trial Country",1},
 {4470,30,TOPGEAR_INPUT_A,"Enter Countries",1},
 {4530,15,TOPGEAR_INPUT_DOWN,"Country Down",1},
 {4590,15,TOPGEAR_INPUT_UP,"Country Up",1},
 {4650,30,TOPGEAR_INPUT_A,"Enter USA",1},
 {4710,15,TOPGEAR_INPUT_DOWN,"Track Down",1},
 {4770,15,TOPGEAR_INPUT_UP,"Track Up",1},
 {4830,30,TOPGEAR_INPUT_A,"Select Las Vegas",1},
 {4920,15,TOPGEAR_INPUT_DOWN,"Time Trial Leaderboard",1},
 {4980,30,TOPGEAR_INPUT_A,"Enter Leaderboard Countries",1},
 {5040,30,TOPGEAR_INPUT_A,"Enter Leaderboard USA",1},
 {5100,30,TOPGEAR_INPUT_A,"Enter Overall Table",1},
 {5160,15,TOPGEAR_INPUT_RIGHT,"Overall Right",1},
 {5220,15,TOPGEAR_INPUT_LEFT,"Overall Left",1},
 {5280,15,TOPGEAR_INPUT_RIGHT,"Overall Car",1},
 {5340,30,TOPGEAR_INPUT_A,"Open Car Table",1},
 {5430,15,TOPGEAR_INPUT_DOWN,"One-item Table Down No Change",0},
 {5490,15,TOPGEAR_INPUT_UP,"One-item Table Up No Change",0},
 {5580,30,TOPGEAR_INPUT_B,"Back Overall",0},
 {5640,30,TOPGEAR_INPUT_B,"Back Tracks",0},
 {5700,30,TOPGEAR_INPUT_B,"Back Countries",0},
 {5760,30,TOPGEAR_INPUT_B,"Back Time Trial",0},
 {5820,30,TOPGEAR_INPUT_B,"Back Root",0},
 {5910,15,TOPGEAR_INPUT_DOWN,"Root Settings",1},
 {5970,30,TOPGEAR_INPUT_A,"Enter Settings",1},
 {6030,15,TOPGEAR_INPUT_LEFT,"Speed Left",1},
 {6090,15,TOPGEAR_INPUT_RIGHT,"Speed Right",1},
 {6150,15,TOPGEAR_INPUT_DOWN,"Settings Down Back",1},
 {6210,15,TOPGEAR_INPUT_UP,"Settings Up Speed",1},
 {6270,90,TOPGEAR_INPUT_LEFT,"Speed Held Left One Change",1},
 {6420,15,TOPGEAR_INPUT_RIGHT,"Speed Restore KPH",1},
 {6480,30,TOPGEAR_INPUT_B,"Settings Back Root",0},
 {6540,15,TOPGEAR_INPUT_DOWN,"Root Wrap Career",1},
 {6600,30,TOPGEAR_INPUT_A,"Enter Career",1},
 {6690,15,TOPGEAR_INPUT_LEFT,"Career Two Players",1},
 {6750,15,TOPGEAR_INPUT_RIGHT,"Career One Player",1},
 {6810,15,TOPGEAR_INPUT_DOWN,"Career Country",1},
 {6870,15,TOPGEAR_INPUT_DOWN,"Career Skill",1},
 {6930,30,TOPGEAR_INPUT_A,"Enter Skill",1},
 {7230,15,TOPGEAR_INPUT_DOWN,"Skill Down",1},
 {7290,15,TOPGEAR_INPUT_UP,"Skill Up",1},
 {7350,30,TOPGEAR_INPUT_A,"Accept Skill",1},
 {7650,30,TOPGEAR_INPUT_B,"Career Back Root",0},
 {7740,15,TOPGEAR_INPUT_DOWN,"Root Rally",1},
 {7800,30,TOPGEAR_INPUT_START,"Enter Rally with Start",1},
 {7890,15,TOPGEAR_INPUT_LEFT,"Rally Two Players",1},
 {7950,15,TOPGEAR_INPUT_RIGHT,"Rally One Player",1},
 {8010,15,TOPGEAR_INPUT_DOWN,"Rally Skill",1},
 {8070,15,TOPGEAR_INPUT_UP,"Rally Up Player Setup",1},
 {8150,30,TOPGEAR_INPUT_B,"Rally Back Root",0},
 {8210,15,TOPGEAR_INPUT_UP,"Root Career",1},
 {8270,30,TOPGEAR_INPUT_A,"Career Again",1},
 {8360,15,TOPGEAR_INPUT_DOWN,"Career Country Row",1},
 {8420,30,TOPGEAR_INPUT_A,"Enter Career Country",1},
 {8710,15,TOPGEAR_INPUT_DOWN,"Career Country Down",1},
 {8770,15,TOPGEAR_INPUT_UP,"Career Country Up",1},
 {8830,30,TOPGEAR_INPUT_A,"Accept Career Country",1}
};
static int screenshot(TopGearRecomp *core,const char*dir,unsigned f){
 char path[1024];uint8_t frame[256u*224u*2u];FILE*out;unsigned x,y;
 if(!topgear_recomp_v22_read_frame_bgr555(core,0u,frame,sizeof(frame)))return 0;
 snprintf(path,sizeof(path),"%s/frame-%04u.ppm",dir,f);out=fopen(path,"wb");if(!out)return 0;
 fprintf(out,"P6\n256 224\n255\n");
 for(y=0;y<224;y++)for(x=0;x<256;x++){unsigned pos=(y*256+x)*2;uint16_t v=(uint16_t)(frame[pos]|((uint16_t)frame[pos+1]<<8));unsigned char rgb[3]={(unsigned char)((v&31)*255/31),(unsigned char)(((v>>5)&31)*255/31),(unsigned char)(((v>>10)&31)*255/31)};fwrite(rgb,1,3,out);}
 return fclose(out)==0;
}
static int snapshot_cue(TopGearRecomp*core,const char*dir){
 char path[1024],err[256];int16_t pcm[2][32768];size_t count[2]={0,0},n;unsigned run,f;TopGearRecompFrameResult result;
 snprintf(path,sizeof(path),"%s/playing-cue.snap",dir);
 if(!topgear_recomp_snapshot_save(core,path,err,sizeof(err)))return 0;
 for(run=0;run<2;run++){
  for(f=0;f<12;f++){
   if(!topgear_recomp_advance_headless(core,TOPGEAR_INPUT_UP,0,1,&result))return 0;
   while((n=topgear_recomp_audio_read(core,pcm[run]+count[run],(32768-count[run])/2))!=0)count[run]+=n*2;
  }
  if(!topgear_recomp_snapshot_load(core,path,err,sizeof(err)))return 0;
 }
 if(count[0]!=count[1]||!count[0]||memcmp(pcm[0],pcm[1],count[0]*sizeof(int16_t)))return 0;
 printf("PASS: whole-core snapshot during cue, %zu identical stereo PCM frames after reload\n",count[0]/2);return 1;
}
int main(int argc,char**argv){
 TopGearRecomp*core=NULL;TopGearRecompFrameResult result;TopGearStaticAudioStatus st;
 uint8_t*rom=NULL;size_t bytes=0,n;unsigned f;uint64_t before=0,total=0;char error[256],path[1024];WavCapture wav;FILE*log;
 if(argc!=3)return 2;
 if(!load_file(argv[1],&rom,&bytes)||!topgear_recomp_create(&core,rom,bytes,error,sizeof(error)))return 2;
 snprintf(path,sizeof(path),"%s/Menu-Voice9-Full-Route.wav",argv[2]);if(!wav_open(&wav,path))return 2;
 snprintf(path,sizeof(path),"%s/events.csv",argv[2]);log=fopen(path,"wb");if(!log)return 2;
 fprintf(log,"action,frame,page,selection,accepted,cues\n");
 for(f=0;f<9180;f++){
  uint16_t input=0;
  for(n=0;n<sizeof(actions)/sizeof(actions[0]);n++)if(f>=actions[n].start&&f<actions[n].start+actions[n].length)input=actions[n].input;
  for(n=0;n<sizeof(actions)/sizeof(actions[0]);n++)if(f==actions[n].start)before=core->mod_insert_audio_command_start_count;
  if(!topgear_recomp_advance_headless(core,input,0,1,&result)){fprintf(stderr,"frame %u: %s\n",f,topgear_recomp_last_error(core));return 1;}
  if(!wav_drain(core,&wav))return 1;
  if(f==2281&&!snapshot_cue(core,argv[2])){fprintf(stderr,"playing cue snapshot failed\n");return 1;}
  for(n=0;n<sizeof(actions)/sizeof(actions[0]);n++)if(f==actions[n].start+actions[n].length+10){
   uint64_t delta=core->mod_insert_audio_command_start_count-before;
   fprintf(log,"%s,%u,%u,%u,%llu,%llu\n",actions[n].name,f,core->mod_menu_remodel_page,core->mod_menu_remodel_selection,(unsigned long long)delta,(unsigned long long)core->mod_insert_audio_cue_keyon_count);fflush(log);
   if(delta!=actions[n].expected){fprintf(stderr,"%s expected %u accepted menu sounds got %llu at %u PC %02X:%04X\n",actions[n].name,actions[n].expected,(unsigned long long)delta,f,core->cpu.pbr,core->cpu.pc);screenshot(core,argv[2],f);wav_close(&wav);return 1;}
   total+=delta;if(!screenshot(core,argv[2],f))return 1;
  }
 }
 if(!wav_close(&wav)||fclose(log))return 1;
 if(!topgear_recomp_static_audio_status(core,&st))return 1;
 printf("Audio failures: AOT=%u DSP=%u unknown-PCM=%llu DSP-overflow=%llu dropped=%llu code-write=%u\n",
   st.aot_failed,st.sdsp_static_failed,(unsigned long long)st.pcm_unknown_frames,
   (unsigned long long)st.dsp_pcm_overflows,(unsigned long long)st.fifo_dropped_frames,st.code_write_barriers);
 if(st.aot_failed||st.sdsp_static_failed||st.pcm_unknown_frames||st.dsp_pcm_overflows||st.fifo_dropped_frames||st.code_write_barriers)return 1;
 if(total!=core->mod_insert_audio_cue_keyon_count||total!=core->mod_insert_audio_cue_keyoff_count||total!=core->mod_insert_audio_cue_restore_count||core->mod_insert_audio_sfx_state)return 1;
 printf("PASS: natural menu route, %llu accepted movements/confirmations = %llu complete private-lane cues; ignored inputs stay silent; AOT/DSP clean\n",(unsigned long long)total,(unsigned long long)core->mod_insert_audio_cue_keyon_count);
 topgear_recomp_destroy(core);free(rom);return 0;
}
