#include "topgear_internal.h"
#include <stdio.h>
#include <string.h>
static TopGearRecomp *c;static char error[256];static const char *snapshot;static unsigned checks,cases;
static unsigned w(unsigned a){return c->wram[a]|(c->wram[a+1]<<8);}
static void put(unsigned a,unsigned v){c->wram[a]=(uint8_t)v;c->wram[a+1]=(uint8_t)(v>>8);}
#define CHECK(v) do{checks++;if(!(v)){fprintf(stderr,"FAIL case=%u line=%d %s (%s)\n",cases,__LINE__,#v,error);return 1;}}while(0)
static int load(void){return topgear_recomp_snapshot_load(c,snapshot,error,sizeof(error));}
static int step(unsigned start,unsigned end){unsigned n;c->cpu.pbr=5;c->cpu.pc=(uint16_t)start;c->cpu.dbr=0;c->cpu.d=0;c->cpu.e=0;c->cpu.p&=(uint8_t)~(TG_P_M|TG_P_X);
 for(n=0;n<5000&&c->cpu.pc!=end;n++)if(!tg_v22_semantic_static_step_any(c))return 0;return c->cpu.pc==end;}
int main(int argc,char **argv){uint8_t rom[524288];FILE *f;unsigned player,p1,p2,car,gear,a,b,z;unsigned assignment_cases=0,physics_cases=0;
 const int speeds[]={-2000,0,1000,8000,12000},roads[]={-256,0,256};const unsigned fuels[]={0,1,43007};
 if(argc!=3)return 2;snapshot=argv[2];f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
 for(player=0;player<2;player++)for(p1=0;p1<4;p1++)for(p2=0;p2<4;p2++){
  unsigned used=1u<<p1,k,ids=0;CHECK(load());put(0x1f04,player);put(0x1f8f,p1);put(0x1fac,p2);tg_rivals_tick(c);if(player){CHECK(!c->rivals.ready&&!c->rivals.visible.count&&w(0x1fac)==p2);cases++;assignment_cases++;continue;}CHECK(c->rivals.ready);
  CHECK(c->rivals.cars[0]==p1);if(player){CHECK(c->rivals.cars[1]==p2);CHECK(w(0x1fac)==p2);used|=1u<<p2;}
  for(k=player?2:1;k<4;k++){CHECK(!(used&(1u<<c->rivals.cars[k])));used|=1u<<c->rivals.cars[k];}
  for(k=0;k<20;k++){unsigned off=k*18u,id=off==w(0x204)?0:off==w(0x206)?1:w(0x212+off)&31u;CHECK(id<20&&!(ids&(1u<<id)));ids|=1u<<id;}
  for(k=4;k<20;k++){unsigned other;CHECK(strlen(tg_rivals_name(k))==8);for(other=4;other<k;other++)CHECK(c->rivals.palettes[k][8]!=c->rivals.palettes[other][8]);}
  CHECK(c->rivals.rival[0].id==2&&c->rivals.rival[1].id==3);cases++;assignment_cases++;
 }
 for(car=0;car<4;car++)for(gear=0;gear<5;gear++)for(a=0;a<5;a++)for(b=0;b<3;b++)for(z=0;z<3;z++){
  TgRival expected;CHECK(load());put(0x1fac,car);put(0x1e74,gear);put(0x1e5c,(unsigned)speeds[a]);put(0x1e64,fuels[b]);put(0x1efe,car==0?100:car==1?64:car==2?90:82);put(0x1eb0,cases&1?10:0);put(0x4000+((w(0x1eda)>>4)&0xfffeu),(unsigned)roads[z]);
  CHECK(step(0xedde,0xf002));expected=c->rivals.shadow;
  CHECK(w(0x1e5c)==expected.speed);CHECK(w(0x1e64)==expected.fuel);CHECK(w(0x1e74)==expected.gear);CHECK(w(0x1e60)==expected.rpm);
  cases++;physics_cases++;
 }
 {const unsigned offsets[]={0,234,252,270,342},fuel_cases[]={11000,12288,43007};
  for(a=0;a<5;a++)for(b=0;b<3;b++){
   TgRival r;CHECK(load());put(0x206,offsets[a]);put(0x1e64,fuel_cases[b]);put(0x1ef2,w(0x1ef2)&~1u);
   CHECK(step(0xf17d,0xf395));r=c->rivals.shadow;CHECK(r.steering==w(0x1e80));CHECK(r.upper==w(0x1ec4));CHECK(r.lower==w(0x1ec6));cases++;
  }
 }
 printf("PASS cases=%u checks=%u assignments=%u native_physics=%u stable_names_and_colours=16\n",cases,checks,assignment_cases,physics_cases);
 topgear_recomp_destroy(c);return 0;
}
