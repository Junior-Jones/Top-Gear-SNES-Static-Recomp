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
 {2010,30,TOPGEAR_INPUT_A,"Enter Time Trial",0},
 {2070,60,TOPGEAR_INPUT_A,"Enter Player 1",0},
 {2220,12,TOPGEAR_INPUT_A,"Name character A",0},
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
 {2700,45,TOPGEAR_INPUT_A,"Accept Name",0},
 {3000,15,TOPGEAR_INPUT_RIGHT,"Gear Right Auto",1},
 {3045,15,TOPGEAR_INPUT_LEFT,"Gear Left Manual",1},
 {3090,15,TOPGEAR_INPUT_RIGHT,"Gear Right Auto Again",1},
 {3150,60,TOPGEAR_INPUT_A,"Accept Gear",0},
 {3495,15,TOPGEAR_INPUT_RIGHT,"Controls Right",1},
 {3540,15,TOPGEAR_INPUT_LEFT,"Controls Left",1},
 {3600,60,TOPGEAR_INPUT_A,"Accept Controls",0},
 {3900,15,TOPGEAR_INPUT_DOWN,"Car Down",1},
 {3945,15,TOPGEAR_INPUT_UP,"Car Up",1},
 {3990,15,TOPGEAR_INPUT_RIGHT,"Car Right",1},
 {4035,15,TOPGEAR_INPUT_LEFT,"Car Left",1},
 {4110,60,TOPGEAR_INPUT_A,"Accept Car",0},
 {4410,15,TOPGEAR_INPUT_DOWN,"Time Trial Country",1},
 {4470,30,TOPGEAR_INPUT_A,"Enter Countries",0},
 {4530,15,TOPGEAR_INPUT_DOWN,"Country Down",1},
 {4590,15,TOPGEAR_INPUT_UP,"Country Up",1},
 {4650,30,TOPGEAR_INPUT_A,"Enter USA",0},
 {4710,15,TOPGEAR_INPUT_DOWN,"Track Down",1},
 {4770,15,TOPGEAR_INPUT_UP,"Track Up",1},
 {4830,30,TOPGEAR_INPUT_A,"Select Las Vegas",0},
 {4920,15,TOPGEAR_INPUT_DOWN,"Time Trial Leaderboard",1},
 {4980,30,TOPGEAR_INPUT_A,"Enter Leaderboard Countries",0},
 {5040,30,TOPGEAR_INPUT_A,"Enter Leaderboard USA",0},
 {5100,30,TOPGEAR_INPUT_A,"Enter Overall Table",0},
 {5160,15,TOPGEAR_INPUT_RIGHT,"Overall Right",1},
 {5220,15,TOPGEAR_INPUT_LEFT,"Overall Left",1},
 {5280,15,TOPGEAR_INPUT_RIGHT,"Overall Car",1},
 {5340,30,TOPGEAR_INPUT_A,"Open Car Table",0},
 {5430,15,TOPGEAR_INPUT_DOWN,"One-item Table Down No Change",0},
 {5490,15,TOPGEAR_INPUT_UP,"One-item Table Up No Change",0},
 {5580,30,TOPGEAR_INPUT_B,"Back Overall",0},
 {5640,30,TOPGEAR_INPUT_B,"Back Tracks",0},
 {5700,30,TOPGEAR_INPUT_B,"Back Countries",0},
 {5760,30,TOPGEAR_INPUT_B,"Back Time Trial",0},
 {5820,30,TOPGEAR_INPUT_B,"Back Root",0},
 {5910,15,TOPGEAR_INPUT_DOWN,"Root Settings",1},
 {5970,30,TOPGEAR_INPUT_A,"Enter Settings",0},
 {6030,15,TOPGEAR_INPUT_LEFT,"Speed Left",1},
 {6090,15,TOPGEAR_INPUT_RIGHT,"Speed Right",1},
 {6150,15,TOPGEAR_INPUT_DOWN,"Settings Down Back",1},
 {6210,15,TOPGEAR_INPUT_UP,"Settings Up Speed",1},
 {6270,90,TOPGEAR_INPUT_LEFT,"Speed Held Left One Change",1},
 {6420,15,TOPGEAR_INPUT_RIGHT,"Speed Restore KPH",1},
 {6480,30,TOPGEAR_INPUT_B,"Settings Back Root",0},
 {6540,15,TOPGEAR_INPUT_DOWN,"Root Wrap Career",1},
 {6600,30,TOPGEAR_INPUT_A,"Enter Career",0},
 {6690,15,TOPGEAR_INPUT_LEFT,"Career Two Players",1},
 {6750,15,TOPGEAR_INPUT_RIGHT,"Career One Player",1},
 {6810,15,TOPGEAR_INPUT_DOWN,"Career Country",1},
 {6870,15,TOPGEAR_INPUT_DOWN,"Career Skill",1},
 {6930,30,TOPGEAR_INPUT_A,"Enter Skill",0},
 {7230,15,TOPGEAR_INPUT_DOWN,"Skill Down",1},
 {7290,15,TOPGEAR_INPUT_UP,"Skill Up",1},
 {7350,30,TOPGEAR_INPUT_A,"Accept Skill",0},
 {7650,30,TOPGEAR_INPUT_B,"Career Back Root",0},
 {7740,15,TOPGEAR_INPUT_DOWN,"Root Rally",1},
 {7800,30,TOPGEAR_INPUT_A,"Enter Rally",0},
 {7890,15,TOPGEAR_INPUT_LEFT,"Rally Two Players",1},
 {7950,15,TOPGEAR_INPUT_RIGHT,"Rally One Player",1},
 {8010,15,TOPGEAR_INPUT_DOWN,"Rally Skill",1},
 {8070,15,TOPGEAR_INPUT_UP,"Rally Up Player Setup",1},
 {8150,30,TOPGEAR_INPUT_B,"Rally Back Root",0},
 {8210,15,TOPGEAR_INPUT_UP,"Root Career",1},
 {8270,30,TOPGEAR_INPUT_A,"Career Again",0},
 {8360,15,TOPGEAR_INPUT_DOWN,"Career Country Row",1},
 {8420,30,TOPGEAR_INPUT_A,"Enter Career Country",0},
 {8710,15,TOPGEAR_INPUT_DOWN,"Career Country Down",1},
 {8770,15,TOPGEAR_INPUT_UP,"Career Country Up",1},
 {8830,30,TOPGEAR_INPUT_A,"Accept Career Country",0}
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
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL frame %u line %d: %s: %s\n",f,__LINE__,#x,topgear_recomp_last_error(core));return 1;}}while(0)

int main(int argc,char **argv){
 TopGearRecomp *core=0;TopGearRecompFrameResult result;uint8_t *rom=0;size_t bytes,n;char error[256],path[1024];unsigned f;WavCapture wav;
 if(argc!=3)return 2;if(!load_file(argv[1],&rom,&bytes)||!topgear_recomp_create(&core,rom,bytes,error,sizeof(error)))return 2;
 snprintf(path,sizeof(path),"%s/title-switching.wav",argv[2]);if(!wav_open(&wav,path))return 2;
 for(f=0;f<2900;f++){
 uint16_t input=0;
 if((f>=1400&&f<1450)||(f>=1530&&f<1540)||(f>=1900&&f<1910)||(f>=2500&&f<2510)||(f>=2700&&f<2710))input=0x10;
 if(f>=1560&&f<1680)input=TOPGEAR_INPUT_START;
 if(f>=2010&&f<2025)input=TOPGEAR_INPUT_UP;
 if(f>=2070&&f<2100)input=TOPGEAR_INPUT_A;
 if((f>=2130&&f<2145)||(f>=2190&&f<2205)||(f>=2600&&f<2615))input=TOPGEAR_INPUT_DOWN;
 if(f>=2250&&f<2350)input=TOPGEAR_INPUT_LEFT;
 if((f>=2410&&f<2425)||(f>=2460&&f<2470))input=TOPGEAR_INPUT_RIGHT;
 CHECK(topgear_recomp_advance_headless(core,input,0,1,&result));CHECK(wav_drain(core,&wav));
 if(f==1500)CHECK(core->mod_music_title==1&&!core->mod_menu_remodel_active);
 if(f==1550)CHECK(core->mod_music_title==2&&!core->mod_menu_remodel_active);
 if(f==1850)CHECK(core->mod_menu_remodel_active&&core->mod_music_engine==2);
 if(f==1950)CHECK(core->mod_music_engine==0);
 if(f==2320)CHECK(core->mod_music_mode==2&&core->mod_menu_remodel_selection==2);
 if(f==2450)CHECK(core->mod_music_mode==0);
 if(f==2490)CHECK(core->mod_music_mode==1);
 if(f==2550)CHECK(core->mod_music_engine==1);
 if(f==2750)CHECK(core->mod_music_engine==2);
 if(f==2320||f==2450||f==2490||f==1500||f==1550)CHECK(screenshot(core,argv[2],f));
 if(f==2601||f==2751)CHECK(snapshot_cue(core,argv[2]));
 }
 CHECK(wav_close(&wav));
 for(unsigned engine=0;engine<3;engine++){
  while(core->mod_music_engine!=engine){CHECK(topgear_recomp_advance_headless(core,0,0,1,&result));CHECK(topgear_recomp_advance_headless(core,0x10,0,1,&result));}
  core->mod_audio_mute=1;
  int16_t pcm[2048];unsigned nz=0;
  for(unsigned j=0;j<30;j++){CHECK(topgear_recomp_advance_headless(core,0,0,1,&result));while((n=topgear_recomp_audio_read(core,pcm,1024))!=0)if(j>10)for(size_t k=0;k<n*2;k++)CHECK(pcm[k]==0);}
  tg_mod_insert_audio_navigation(core);
  for(unsigned j=0;j<15;j++){CHECK(topgear_recomp_advance_headless(core,0,0,1,&result));while((n=topgear_recomp_audio_read(core,pcm,1024))!=0)for(size_t k=0;k<n*2;k++)if(pcm[k])nz++;}
  CHECK(nz>0);CHECK(snapshot_cue(core,argv[2]));core->mod_audio_mute=0;
 }
 topgear_recomp_destroy(core);free(rom);puts("PASS title R does not dismiss; one change per held press; all 3 engines; Career menu and both values; imported snapshots; music mute with independent ninth cue in every engine");return 0;
}
