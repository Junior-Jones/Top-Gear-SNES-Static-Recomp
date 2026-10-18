#define main career_contract_main
#include "../test_career_v2.c"
#undef main
static unsigned stock_cues;
static int trace(void *user,const TopGearHookEvent *e){
 (void)user;if(e->type==TOPGEAR_HOOK_EVENT_INSTRUCTION_BEFORE&&e->address==0x0f922cu&&c->cpu.a==0x84u)stock_cues++;return 0;
}
static int16_t pcm[2][65536];static size_t used[2];
static int capture(unsigned run,uint16_t input){
 TopGearRecompFrameResult result;unsigned frame;size_t count;
 used[run]=0;topgear_recomp_audio_clear(c);
 for(frame=0;frame<48;frame++){
  if(!topgear_recomp_advance_headless(c,frame<6?input:0,0,1,&result))return 0;
  while((count=topgear_recomp_audio_read(c,pcm[run]+used[run],(65536-used[run])/2))!=0)used[run]+=count*2;
 }
 return used[run]>0;
}
static int wav(const char *path){
 FILE *f=fopen(path,"wb");uint32_t bytes=(uint32_t)(used[1]*2),riff=bytes+36,fmt=16,rate=32000,byte_rate=128000;uint16_t type=1,channels=2,align=4,bits=16;
 if(!f)return 0;
 fwrite("RIFF",1,4,f);fwrite(&riff,4,1,f);fwrite("WAVEfmt ",1,8,f);fwrite(&fmt,4,1,f);fwrite(&type,2,1,f);fwrite(&channels,2,1,f);fwrite(&rate,4,1,f);fwrite(&byte_rate,4,1,f);fwrite(&align,2,1,f);fwrite(&bits,2,1,f);fwrite("data",1,4,f);fwrite(&bytes,4,1,f);fwrite(pcm[1],1,bytes,f);return fclose(f)==0;
}
int main(int argc,char **argv){
 uint8_t rom[524288];FILE *f;unsigned row,d,n;char start[2048],row_start[2048],clip[2048];
 const unsigned rows[]={0,4,5,6,5};const char *names[]={"speed-reference","bottom-screen","center-screen","extra-cpus","center-disabled"};
 if(argc!=4&&argc!=5)return 2;dir=argv[3];f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
 CHECK(topgear_recomp_snapshot_load(c,argv[2],error,sizeof(error)));
 CHECK(press(0x0400)&&press(0x0400)&&press(0x0400)&&press(0x0080)&&c->mod_menu_remodel_selection==0);
 snprintf(start,sizeof(start),"%s/settings.snap",dir);CHECK(topgear_recomp_snapshot_save(c,start,error,sizeof(error)));
 for(row=0;row<5;row++)for(d=0;d<2;d++){
  unsigned changed=0,peak=0;uint64_t total=0;
  CHECK(topgear_recomp_snapshot_load(c,start,error,sizeof(error)));
  for(n=0;n<rows[row];n++)CHECK(press(0x0400));
  topgear_recomp_set_bottom_screen_enabled(c,1);topgear_recomp_set_center_screen_enabled(c,0);CHECK(frames(60,0));
  if(row==2)topgear_recomp_set_bottom_screen_enabled(c,0);
  snprintf(row_start,sizeof(row_start),"%s/action.snap",dir);CHECK(topgear_recomp_snapshot_save(c,row_start,error,sizeof(error)));
  CHECK(capture(0,0));CHECK(topgear_recomp_snapshot_load(c,row_start,error,sizeof(error)));
  stock_cues=0;CHECK(topgear_recomp_set_hook(c,TOPGEAR_HOOK_MASK_INSTRUCTION,trace,NULL));
  CHECK(capture(1,d?0x0100:0x0200));topgear_recomp_clear_hook(c);
  CHECK(used[0]==used[1]);
  for(n=0;n<used[1];n++){int delta=pcm[1][n]-pcm[0][n];unsigned magnitude=(unsigned)(delta<0?-delta:delta);if(magnitude)changed++;if(magnitude>peak)peak=magnitude;total+=magnitude;}
  snprintf(clip,sizeof(clip),"%s/%s-%s.wav",dir,names[row],d?"right":"left");CHECK(wav(clip));
  printf("%s %s: native_sound_84=%u PCM_changed_samples=%u peak_delta=%u mean_absolute_delta=%.2f frames=%zu\n",names[row],d?"Right":"Left",stock_cues,changed,peak,(double)total/used[1],used[1]/2);fflush(stdout);
  if(argc==4){
   if(row==4){CHECK(stock_cues==0&&changed==0);CHECK(!topgear_recomp_center_screen_enabled(c));}
   else {CHECK(stock_cues==1);CHECK(changed>100&&peak>500);}
  }
 }
 topgear_recomp_destroy(c);return 0;
}
