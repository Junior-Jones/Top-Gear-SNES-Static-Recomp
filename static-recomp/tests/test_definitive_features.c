#include "topgear_internal.h"
#include "../static-audio/sequel/music_runtime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static TopGearRecomp *c;static const char *dir;static char error[256];
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d: %s (%s)\n",__LINE__,#x,topgear_recomp_last_error(c));return 1;}}while(0)
static int frames(unsigned n,uint16_t input){TopGearRecompFrameResult a;while(n--){if(!topgear_recomp_advance_headless(c,input,0,1,&a))return 0;topgear_recomp_audio_clear(c);}return 1;}
static int press(uint16_t b){return frames(6,b)&&frames(90,0);}
static int shot(const char *name){char path[1024];uint8_t f[256*224*2];FILE *o;unsigned p;snprintf(path,sizeof(path),"%s/%s.ppm",dir,name);if(!topgear_recomp_v22_read_frame_bgr555(c,0,f,sizeof(f)))return 0;o=fopen(path,"wb");if(!o)return 0;fprintf(o,"P6\n256 224\n255\n");for(p=0;p<256*224;p++){unsigned v=f[p*2]|f[p*2+1]<<8;uint8_t rgb[3]={(uint8_t)((v&31)*255/31),(uint8_t)(((v>>5)&31)*255/31),(uint8_t)(((v>>10)&31)*255/31)};fwrite(rgb,1,3,o);}return fclose(o)==0;}
int main(int argc,char **argv){
 uint8_t rom[524288],before[96],after[96],settings[96];FILE *f;unsigned t,n;char path[1024],name[64];TopGearPlayerProfile p,q;
 if(argc!=3)return 2;dir=argv[2];f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
 /* All four native control tables and both independent profile banks survive
    exported-record reload, including automatic gearbox clearing shift words. */
 for(t=0;t<2;t++)for(n=0;n<4;n++){
  memset(&p,0,sizeof(p));snprintf(p.name,sizeof(p.name),"BANK%uC%u",t,n);p.car=(uint8_t)n;p.controls=(uint8_t)n;p.manual=(uint8_t)(n&1u);
  CHECK(topgear_recomp_profile_write(c,t,&p));CHECK(topgear_recomp_profile_record(c,settings,sizeof(settings)));
  CHECK(topgear_recomp_player_settings_import(c,settings,sizeof(settings)));c->mod_profile_pending_mask=0;
  CHECK(topgear_recomp_profile_read(c,t,&q));CHECK(!strncmp(q.name,p.name,strlen(p.name))&&q.car==p.car&&q.controls==p.controls&&q.manual==p.manual);
 }
 CHECK(topgear_recomp_profile_read(c,0,&p)&&topgear_recomp_profile_read(c,1,&q));CHECK(p.name[4]=='0'&&q.name[4]=='1');
 CHECK(frames(1560,0)&&frames(120,0x1000)&&frames(220,0));CHECK(c->mod_menu_remodel_page==0);CHECK(shot("root"));
 snprintf(path,sizeof(path),"%s/root.snap",dir);CHECK(topgear_recomp_snapshot_save(c,path,error,sizeof(error)));
 CHECK(press(0x0800)&&press(0x0080));CHECK(c->mod_menu_remodel_page==12);
 for(n=0;n<3;n++){snprintf(name,sizeof(name),"settings-item-%u",n);CHECK(shot(name));CHECK(press(0x0400));}
 CHECK(c->mod_menu_remodel_selection==3&&c->mod_music_player_state==1);CHECK(shot("music-player-first"));
 CHECK(topgear_recomp_music_state_export(c,before,sizeof(before)));
 for(t=0;t<20;t++){
  int16_t l,r;unsigned energy=0,k;
  CHECK(c->mod_music_player_track==t);
  for(k=0;k<8000;k++){int ok=t<7?tg0_music_sample(&l,&r):t<13?tg2_music_sample(&l,&r):tg3_music_sample(&l,&r);CHECK(ok);energy+=(l!=0||r!=0);}
  CHECK(energy>100);snprintf(name,sizeof(name),"music-track-%02u",t);CHECK(shot(name));
  CHECK(press(0x0080));CHECK(c->mod_music_player_state==2);CHECK(press(0x0080));CHECK(c->mod_music_player_state==1);
  CHECK(press(0x0100));
 }
 CHECK(c->mod_music_player_track==0);CHECK(topgear_recomp_music_state_export(c,after,sizeof(after))&&!memcmp(before,after,sizeof(before)));
 CHECK(press(0x0200)&&c->mod_music_player_track==19);CHECK(shot("music-player-last"));
 CHECK(press(0x0400));CHECK(c->mod_menu_remodel_selection==4&&!c->mod_music_player_state);CHECK(shot("settings-back"));
 CHECK(topgear_recomp_snapshot_load(c,path,error,sizeof(error)));
 CHECK(press(0x0400)&&press(0x0080)&&press(0x0400)&&press(0x0400));CHECK(c->mod_menu_remodel_page==2&&c->mod_menu_remodel_selection==2);
 CHECK(frames(1,0x0080));for(n=0;n<120&&c->mod_menu_remodel_page!=13;n++)CHECK(frames(1,0x0080));CHECK(c->mod_menu_remodel_page==13);
 for(n=0;n<310&&c->mod_menu_remodel_active;n++){if(n==90)CHECK(shot("rally-selected-tracks"));CHECK(frames(1,0x0080));}
 printf("Rally held-Start deadline: %u frames\n",n);CHECK(n<=301);CHECK(frames(120,0)&&shot("rally-pre-race"));
 CHECK(topgear_recomp_snapshot_load(c,path,error,sizeof(error)));CHECK(press(0x0080)&&press(0x0400)&&press(0x0400)&&press(0x0400)&&press(0x0080));
 for(n=0;n<6000;n++){CHECK(frames(1,(n%120u)<110u?0x8000u:0u));if(n==1800||n==3600||n==5999){snprintf(name,sizeof(name),"career-race-%u",n);CHECK(shot(name));printf("Career frame %u hdma=%02X context=%u playercount=%u order",n,c->hdma_enable_mask,c->mod_audio_menu_context,c->wram[0x1F04u]);for(t=0;t<5;t++)printf(" %u(lap%u,cp%u,last%u)",c->mod_career_order[t],c->mod_career_laps[c->mod_career_order[t]],c->mod_career_progress[c->mod_career_order[t]],c->mod_career_last_lap[c->mod_career_order[t]]);puts("");}}
 CHECK(c->mod_career_panel);CHECK(c->mod_career_laps[c->mod_career_order[0]]>=2u);
 topgear_recomp_destroy(c);puts("PASS profiles, all 20 Music Player songs, playlist isolation, Rally deadline, Career telemetry");return 0;
}
