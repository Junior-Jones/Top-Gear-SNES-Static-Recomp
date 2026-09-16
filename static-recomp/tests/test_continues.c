#define main career_contract_main
#include "test_career_v2.c"
#undef main
static int fail_race(void){unsigned n,w;for(n=0;n<20;n++)c->wram[0x1F12+n]=(uint8_t)((n+2)%20);put(0x1EB0,10);for(w=0;w<1800&&c->mod_continue_screen!=2;w++)if(!frames(1,0))return 0;printf("failure wait=%u state=%u course=%u PC=%02X:%04X\n",w,c->mod_continue_screen,c->wram[0x1F06],c->cpu.pbr,c->cpu.pc);fflush(stdout);return w<1800&&frames(60,0);}
int main(int argc,char **argv){
 uint8_t rom[524288],points[20];FILE*f;unsigned mode,n,k,course,index;char root[1024],live[1024],name[64];
 if(argc!=3)return 2;dir=argv[2];f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
 c=calloc(1,sizeof(*c));CHECK(c);
 for(mode=0;mode<2;mode++)for(course=0;course<32;course++)for(index=0;index<(mode?8u:1u);index++)for(k=0;k<2;k++)for(n=0;n<20;n++){
  unsigned j,cutoff=mode?(index==7?20:8-index):course<16?10:5;put(0x1F06,course);put(0x1F04,k);c->mod_rally_active=(uint8_t)mode;c->mod_rally_race_index=(uint8_t)index;
  for(j=0;j<20;j++)c->wram[0x1F12+j]=(uint8_t)j;c->wram[0x1F12]=(uint8_t)n;c->wram[0x1F12+n]=0;
  c->mod_attempt_live=1;c->mod_continue_screen=0;CHECK(tg_mod_attempt_pre_results(c)==(n>=cutoff));CHECK(!tg_mod_attempt_pre_results(c));
  if(k&&cutoff<20){for(j=0;j<20;j++)c->wram[0x1F12+j]=(uint8_t)j;c->wram[0x1F12+1]=(uint8_t)cutoff;c->wram[0x1F12+cutoff]=1;c->mod_attempt_live=1;CHECK(tg_mod_attempt_pre_results(c));}
 }
 c->mod_continue_screen=2;c->mod_continue_selection=0;c->mod_continue_previous=0;c->mod_continues_remaining=3;c->mod_continue_released=0;put(0x0A,0x0080);CHECK(!tg_mod_continue_poll(c));put(0x0A,0);CHECK(!tg_mod_continue_poll(c));put(0x0A,0x0080);CHECK(tg_mod_continue_poll(c)&&c->mod_continue_screen==3);
 free(c);c=NULL;puts("PASS continue gate matrix: 32 Career tracks, every Rally ordinal, both humans; held-button release gate");
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
 CHECK(frames(1560,0)&&frames(120,0x1000)&&frames(220,0));snprintf(root,sizeof(root),"%s/root.snap",dir);snprintf(live,sizeof(live),"%s/live.snap",dir);CHECK(topgear_recomp_snapshot_save(c,root,error,sizeof(error)));
 for(mode=0;mode<1;mode++){
  CHECK(topgear_recomp_snapshot_load(c,root,error,sizeof(error)));if(mode)CHECK(press(0x0400));CHECK(press(0x0080));
  for(n=0;n<(mode?2u:3u);n++)CHECK(press(0x0400));CHECK(press(0x0080)&&frames(1900,0));
  CHECK(c->mod_continues_remaining==3&&c->mod_attempt_live&&c->hdma_enable_mask==0x7F);
  course=c->wram[0x1F06];index=c->mod_rally_race_index;
  for(n=0;n<20;n++)c->wram[0x1F4E+n]=(uint8_t)(20-n);tg_mod_attempt_race(c);memcpy(points,c->wram+0x1F4E,20);
  snprintf(name,sizeof(name),"%s-solo-panel",mode?"rally":"career");CHECK(shot(name));CHECK(topgear_recomp_snapshot_save(c,live,error,sizeof(error)));
  for(k=0;k<4;k++){
   CHECK(fail_race());CHECK(c->mod_continues_remaining==3-k);snprintf(name,sizeof(name),"%s-continues-%u",mode?"rally":"career",3-k);CHECK(shot(name));
   if(!k){CHECK(press(0x0100)&&c->mod_continue_selection==1);CHECK(shot(mode?"rally-no-highlight":"career-no-highlight"));CHECK(press(0x0200)&&c->mod_continue_selection==0);}
   if(k==3){CHECK(press(0x0200)&&c->mod_continue_selection==1);CHECK(press(0x0080)&&frames(600,0));CHECK(c->mod_menu_remodel_active&&c->mod_menu_remodel_page==0);break;}
   CHECK(press(0x0080)&&frames(1800,0));CHECK(c->hdma_enable_mask==0x7F&&c->mod_attempt_live&&c->mod_continues_remaining==2-k);
   CHECK(c->wram[0x1F06]==course&&c->mod_rally_race_index==index&&!memcmp(points,c->wram+0x1F4E,20));
  }
  CHECK(topgear_recomp_snapshot_load(c,live,error,sizeof(error)));CHECK(fail_race());CHECK(press(0x0100)&&press(0x0080)&&frames(600,0));CHECK(c->mod_menu_remodel_active&&c->mod_menu_remodel_page==0&&c->mod_continues_remaining==3);
  printf("PASS %s: three exact-track retries, points restored, zero exhausted, No exits without spending\n",mode?"Rally":"Career");fflush(stdout);
 }
 CHECK(topgear_recomp_snapshot_load(c,root,error,sizeof(error)));c->mod_menu_remodel_active=0;put(0x1F04,0);put(0x1F06,7);c->mod_continues_remaining=3;
 for(n=0;n<20;n++){c->wram[0x1F12+n]=(uint8_t)n;c->wram[0x1F62+n]=(uint8_t)n;}c->wram[0x1F62]=7;c->wram[0x1F62+7]=0;c->mod_career_qualification_pending=1;
 c->cpu.pbr=15;c->cpu.pc=0x84A4;c->cpu.dbr=15;c->cpu.d=0;c->cpu.p=0;c->cpu.e=0;
 CHECK(frames(600,0)&&c->mod_continue_screen==5&&shot("standings-failure-no-continue"));CHECK(press(0x0080)&&frames(600,0));CHECK(c->mod_menu_remodel_active&&c->mod_menu_remodel_page==0&&c->mod_continues_remaining==3);
 topgear_recomp_destroy(c);puts("PASS standings failure ends attempt without offering/spending continues");return 0;
}
