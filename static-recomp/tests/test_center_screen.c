/* Real controller path shared with the existing Career/Bottom Screen tests.
   No race completion, standings, collision or AI state is fabricated. */
#include "topgear_internal.h"
#include "topgear_player_settings_file.h"
#include <stdio.h>
#include <string.h>
#include "existing_self_driver.inc"
static TopGearRecomp *c;
static const char *dir;
static char error[256];
static uint32_t pixels[256*224];
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d: %s (%s)\n",__LINE__,#x,error);return 1;}}while(0)
static unsigned w(unsigned a){return c->wram[a]|c->wram[a+1]<<8;}
static int frames(unsigned n,uint16_t b){TopGearRecompFrameResult result;while(n--){if(!topgear_recomp_advance_headless(c,b,0,1,&result))return 0;topgear_recomp_audio_clear(c);}return 1;}
static int press(uint16_t b){return frames(6,b)&&frames(90,0);}
static int shot(const char *name){char path[1024];FILE *f;unsigned p;if(!topgear_recomp_frame_bgra(c,pixels,256*224))return 0;snprintf(path,sizeof(path),"%s/%s.ppm",dir,name);f=fopen(path,"wb");if(!f)return 0;fprintf(f,"P6\n256 224\n255\n");for(p=0;p<256*224;p++){uint8_t rgb[3]={(uint8_t)(pixels[p]>>16),(uint8_t)(pixels[p]>>8),(uint8_t)pixels[p]};fwrite(rgb,1,3,f);}return fclose(f)==0;}
static uint32_t rgb(unsigned n){unsigned v=c->mode1_frame[n*2]|c->mode1_frame[n*2+1]<<8,r=v&31,g=(v>>5)&31,b=(v>>10)&31;return 0xff000000u|(((r<<3)|(r>>2))<<16)|(((g<<3)|(g>>2))<<8)|((b<<3)|(b>>2));}
static int layout(void){
    unsigned x,y;
    if(!topgear_recomp_frame_bgra(c,pixels,256*224)||!tg_mod_bottom_screen_race_off(c))return 0;
    for(y=108;y<224;y++)for(x=0;x<256;x++)if(c->mode1_frame[(y*256+x)*2]||c->mode1_frame[(y*256+x)*2+1])return 0;
    for(y=0;y<224;y++)for(x=0;x<256;x++){
        if(y<60u||y>=164u){if(pixels[y*256+x]!=0xff000000u)return 0;}
        else if(pixels[y*256+x]!=rgb((y-56u)*256+x))return 0;
    }
    return 1;
}
static int dump(const char *mode,unsigned sample){char path[1024];FILE *f;unsigned slot,n;snprintf(path,sizeof(path),"%s/%s-ai.csv",dir,mode);f=fopen(path,sample?"a":"w");if(!f)return 0;if(!sample)fprintf(f,"sample,timer,p1_offset,p2_offset,slot,base,id,kind,flags,lateral16,word4,byte6,position,lap,bytes10_17\n");for(slot=0;slot<20;slot++){unsigned o=slot*18,b=0x212+o,id=o==w(0x204)?0:o==w(0x206)?1:c->wram[b]&31;fprintf(f,"%u,%u,%u,%u,%u,%04X,%u,%s,%04X,%d,%04X,%u,%u,%u,",sample,w(0x1eae),w(0x204),w(0x206),slot,b,id,id==0?"P1":id==1?"CPU":"AI",w(b),(int)(int16_t)w(b+2),w(b+4),c->wram[b+6],w(b+7),c->wram[b+9]);for(n=10;n<18;n++)fprintf(f,"%02X",c->wram[b+n]);fputc('\n',f);}fclose(f);snprintf(path,sizeof(path),"%s/%s-%u.wram",dir,mode,sample);f=fopen(path,"wb");if(!f)return 0;fwrite(c->wram,1,sizeof(c->wram),f);fclose(f);snprintf(path,sizeof(path),"%s/%s-%u.oam",dir,mode,sample);f=fopen(path,"wb");if(!f)return 0;fwrite(c->oam,1,sizeof(c->oam),f);fclose(f);return 1;}
int main(int argc,char **argv){
    uint8_t rom[524288],record[96],again[96];char root[1024],path[1024],name[80];FILE *f;unsigned mode,n;
    if(argc!=3&&argc!=4)return 2;dir=argv[2];f=fopen(argv[1],"rb");CHECK(f&&fread(rom,1,sizeof(rom),f)==sizeof(rom));fclose(f);
    CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
    if(argc==4){
        CHECK(!strcmp(argv[3],"--verify-saved-starts"));
        for(mode=0;mode<2;mode++){
            Driver driver;memset(&driver,0,sizeof(driver));
            const char *label=mode?"rally":"career";
            snprintf(path,sizeof(path),"%s/%s-centered-start.scsnap",dir,label);
            CHECK(topgear_recomp_snapshot_load(c,path,error,sizeof(error)));
            CHECK(!c->mod_time_trial_active&&!!c->mod_rally_active==!!mode&&tg_mod_center_screen_race(c));
            CHECK(frames(2,0)&&layout());
            for(n=0;n<600;n++){
                uint16_t input=driver_input(c,&driver,c->wram,c->mode1_frame,(w(0x1f7a)|w(0x1f7c))!=0);
                CHECK(frames(1,input));
            }
            CHECK(layout());snprintf(name,sizeof(name),"%s-black-final",label);CHECK(shot(name));
            topgear_recomp_set_center_screen_enabled(c,0);CHECK(frames(2,0));
            CHECK(topgear_recomp_frame_bgra(c,pixels,256*224));for(n=0;n<256*224;n++)CHECK(pixels[n]==rgb(n));
            printf("PASS final %s: 600 driven frames, lower native raster entirely black, both 60-line margins entirely black, exact unscaled P1, normal view restored\n",label);fflush(stdout);
        }
        topgear_recomp_destroy(c);return 0;
    }
    CHECK(!topgear_recomp_center_screen_enabled(c)&&topgear_recomp_bottom_screen_enabled(c));
    topgear_recomp_set_bottom_screen_enabled(c,1);
    CHECK(topgear_recomp_profile_record(c,record,96));
    for(n=1;n<=6;n++){
        unsigned k;uint32_t hash=2166136261u;
        memcpy(again,record,96);again[4]=(uint8_t)n;again[95]=(uint8_t)(n==1?0:1);
        for(k=16;k<96;k++)hash=(hash^again[k])*16777619u;
        for(k=0;k<4;k++)again[12+k]=(uint8_t)(hash>>(k*8));
        topgear_recomp_set_center_screen_enabled(c,1);
        CHECK(topgear_recomp_player_settings_import(c,again,96)&&!topgear_recomp_center_screen_enabled(c));
    }
    CHECK(frames(1560,0)&&frames(120,0x1000)&&frames(220,0));
    CHECK(press(0x0800)&&press(0x0080));
    for(n=0;n<5;n++)CHECK(press(0x0400));
    CHECK(c->mod_menu_remodel_page==12&&c->mod_menu_remodel_selection==5&&shot("settings-center-default-off"));
    CHECK(press(0x0080)&&!topgear_recomp_center_screen_enabled(c));
    CHECK(press(0x0800)&&press(0x0080)&&press(0x0400));
    CHECK(press(0x0080)&&topgear_recomp_center_screen_enabled(c)&&shot("settings-center-on"));
    CHECK(press(0x0800)&&press(0x0080)&&topgear_recomp_bottom_screen_enabled(c)&&!topgear_recomp_center_screen_enabled(c));
    CHECK(press(0x0400)&&press(0x0100)&&!topgear_recomp_center_screen_enabled(c)&&shot("settings-bottom-off-lock"));
    CHECK(press(0x0800)&&press(0x0080)&&press(0x0400)&&press(0x0080)&&topgear_recomp_center_screen_enabled(c));
    CHECK(topgear_recomp_player_settings_export(c,record,96)&&record[4]==8&&(record[95]&32));
    snprintf(path,sizeof(path),"%s/player-settings.dat",dir);CHECK(topgear_player_settings_save_file(c,path,again));
    topgear_recomp_set_center_screen_enabled(c,0);CHECK(topgear_player_settings_load_file(c,path,again)&&topgear_recomp_center_screen_enabled(c));
    CHECK(tg_bus_store16(c,0x1f04,1)&&!w(0x1f04));
    CHECK(press(0x0400)&&c->mod_menu_remodel_selection==6&&press(0x0400)&&c->mod_menu_remodel_selection==7&&press(0x0400)&&c->mod_menu_remodel_selection==0);
    CHECK(press(0x0800)&&c->mod_menu_remodel_selection==7&&press(0x0080)&&c->mod_menu_remodel_page==0);
    CHECK(press(0x0400));
    snprintf(root,sizeof(root),"%s/root-center.snap",dir);CHECK(topgear_recomp_snapshot_save(c,root,error,sizeof(error)));
    for(mode=0;mode<2;mode++){
        Driver driver;memset(&driver,0,sizeof(driver));
        const char *label=mode==0?"career":"rally";
        CHECK(topgear_recomp_snapshot_load(c,root,error,sizeof(error)));
        for(n=0;n<mode;n++)CHECK(press(0x0400));
        CHECK(press(0x0080));
        if(mode<2){CHECK(press(0x0100)&&!w(0x1f04)&&press(0x0200)&&!w(0x1f04));}
        CHECK(press(0x0400)&&press(0x0400));if(mode!=1)CHECK(press(0x0400));
        CHECK(press(0x0080)&&frames(1900,0)&&tg_mod_center_screen_race(c));
        CHECK((c->mod_rally_active!=0)==(mode==1));
        CHECK((c->mod_time_trial_active!=0)==(mode==2));
        CHECK(dump(label,0));
        CHECK(layout());snprintf(name,sizeof(name),"%s-centered-start",label);CHECK(shot(name));
        snprintf(path,sizeof(path),"%s/%s-centered-start.scsnap",dir,label);CHECK(topgear_recomp_snapshot_save(c,path,error,sizeof(error)));
        for(n=0;n<600;n++){
            uint16_t input=driver_input(c,&driver,c->wram,c->mode1_frame,(w(0x1f7a)|w(0x1f7c))!=0);
            CHECK(frames(1,input));
            if(n==119)CHECK(dump(label,120));
        }
        CHECK(dump(label,600)&&layout());
        snprintf(name,sizeof(name),"%s-centered-driving",label);CHECK(shot(name));
        topgear_recomp_set_center_screen_enabled(c,0);CHECK(frames(2,0)&&!tg_mod_center_screen_race(c));
        CHECK(topgear_recomp_frame_bgra(c,pixels,256*224));for(n=0;n<256*224;n++)CHECK(pixels[n]==rgb(n));
        printf("PASS %s: natural race start, exact unscaled P1 at y60, upper/lower 60-line areas entirely black, normal layout restored; AI WRAM/OAM samples saved\n",label);fflush(stdout);
    }
    CHECK(topgear_recomp_snapshot_load(c,root,error,sizeof(error)));
    topgear_recomp_set_center_screen_enabled(c,0);CHECK(tg_bus_store16(c,0x1f04,1)&&w(0x1f04)==1);
    topgear_recomp_set_center_screen_enabled(c,1);CHECK(!w(0x1f04)&&!c->mod_setup_shared_players);
    topgear_recomp_set_bottom_screen_enabled(c,1);CHECK(!topgear_recomp_center_screen_enabled(c));
    CHECK(topgear_recomp_snapshot_load(c,root,error,sizeof(error)));
    CHECK(press(0x0800)&&press(0x0080));for(n=0;n<5;n++)CHECK(press(0x0400));
    CHECK(shot("settings-final"));snprintf(path,sizeof(path),"%s/settings-center.scsnap",dir);CHECK(topgear_recomp_snapshot_save(c,path,error,sizeof(error)));
    topgear_recomp_destroy(c);puts("PASS Center Screen menu, dependency, physical persistence, solo lock, and Career/Rally start matrix; no Trial races");return 0;
}
