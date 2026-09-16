#define main career_contract_main
#include "test_career_v2.c"
#undef main
int main(int argc,char **argv){
 uint8_t rom[524288],expected[20]={0};FILE*f;unsigned race,n,wait;char live[1024],last[1024],name[64];
 if(argc!=3)return 2;dir=argv[2];f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
 CHECK(frames(1560,0)&&frames(120,0x1000)&&frames(220,0));CHECK(press(0x0400)&&press(0x0080)&&press(0x0400)&&press(0x0400)&&press(0x0080)&&frames(1900,0));
 CHECK(c->mod_rally_active&&c->mod_continues_remaining==0&&c->hdma_enable_mask==0x7F);snprintf(live,sizeof(live),"%s/live.snap",dir);CHECK(topgear_recomp_snapshot_save(c,live,error,sizeof(error)));
 /* Actual first-race failure: ninth is outside top eight, no continue page. */
 for(n=0;n<20;n++)c->wram[0x1F12+n]=(uint8_t)n;c->wram[0x1F12]=8;c->wram[0x1F12+8]=0;put(0x1EB0,10);
 CHECK(frames(1000,0)&&c->mod_continue_screen==5&&c->mod_continues_remaining==0&&shot("rally-failed-no-continue"));CHECK(press(0x0080)&&frames(600,0));CHECK(c->mod_menu_remodel_active&&c->mod_menu_remodel_page==0&&c->mod_menu_remodel_selection==1&&shot("rally-failure-main-menu"));
 CHECK(topgear_recomp_snapshot_load(c,live,error,sizeof(error)));memcpy(c->wram+0x1F86,"PLAYER 1",8);
 snprintf(last,sizeof(last),"%s/finale.snap",dir);
 for(race=0;race<8;race++){
  CHECK(c->mod_rally_active&&c->mod_rally_race_index==race&&c->wram[0x1F06]==c->mod_rally_schedule[race]&&c->hdma_enable_mask==0x7F);
  for(n=0;n<20;n++)c->wram[0x1F12+n]=(uint8_t)n;
  if(race==7){CHECK(topgear_recomp_snapshot_save(c,last,error,sizeof(error)));c->wram[0x1F12]=2;c->wram[0x1F12+2]=0;}
  for(n=0;n<20;n++)expected[c->wram[0x1F12+n]]+=rom[0x70024+n];
  put(0x1EB0,10);CHECK(frames(600,0));CHECK(!c->mod_continue_screen&&!c->mod_continues_remaining);
  CHECK(!memcmp(expected,c->wram+0x1F4E,20));CHECK(press(0x0080)&&frames(300,0));
  snprintf(name,sizeof(name),"rally-standings-after-%u",race+1);CHECK(shot(name));
  for(n=1;n<20;n++)CHECK(c->wram[0x1F4E + c->wram[0x1F62+n-1]]>=c->wram[0x1F4E + c->wram[0x1F62+n]]);
  printf("Race %u points P1=%u P2=%u first-ranked=%u, no continues\n",race+1,c->wram[0x1F4E],c->wram[0x1F4F],c->wram[0x1F62]);fflush(stdout);
  if(race==7)CHECK(c->wram[0x1F62]==0&&c->wram[0x1F12+2]==0);
  CHECK(press(0x0080));
  for(wait=0;wait<2400;wait++){if(race<7?c->mod_rally_race_index==race+1&&c->hdma_enable_mask==0x7F:c->mod_menu_remodel_active&&c->mod_menu_remodel_page==0)break;CHECK(frames(1,0));}
  CHECK(wait<2400&&!memcmp(expected,c->wram+0x1F4E,20));if(race<7)CHECK(frames(1800,0));
 }
 CHECK(frames(600,0)&&!c->mod_rally_active&&c->mod_menu_remodel_selection==1&&shot("rally-completed-main-menu"));CHECK(topgear_recomp_snapshot_load(c,last,error,sizeof(error)));for(n=0;n<20;n++)c->wram[0x1F12+n]=(uint8_t)n;c->wram[0x1F12]=19;c->wram[0x1F12+19]=0;put(0x1EB0,10);
 CHECK(frames(600,0)&&!c->mod_continue_screen&&c->wram[0x1F4E]==140+rom[0x70024+19]);CHECK(press(0x0080)&&frames(300,0)&&shot("rally-finale-last-place-accepted"));CHECK(press(0x0080)&&frames(600,0)&&!c->mod_rally_active&&c->mod_menu_remodel_active&&c->mod_menu_remodel_page==0);
 topgear_recomp_destroy(c);puts("PASS Rally: terminal failure, all eight points awards retained/sorted, third-place finale wins on cumulative points, last-place finale accepted, final root return");return 0;
}
