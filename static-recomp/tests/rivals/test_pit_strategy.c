#include "topgear_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "existing_self_driver.inc"
static TopGearRecomp *c;
static char error[256];
static unsigned w(unsigned a){return c->wram[a]|(c->wram[a+1]<<8);}
static void put(unsigned a,unsigned v){c->wram[a]=(uint8_t)v;c->wram[a+1]=(uint8_t)(v>>8);}
#define CHECK(v) do{if(!(v)){fprintf(stderr,"FAIL line=%d %s error=%s pc=%02X%04X\n",__LINE__,#v,error,c->cpu.pbr,c->cpu.pc);return 1;}}while(0)
static unsigned contacts_p1,contacts_p2,ticks,mismatch_logs;
static int observe(void *user,const TopGearHookEvent *e){(void)user;if(e->type!=TOPGEAR_HOOK_EVENT_INSTRUCTION_BEFORE)return 0;
 if(e->address==0x5e8e9||e->address==0x5e538)contacts_p1++;
 if(e->address==0x5e944||e->address==0x5e717)contacts_p2++;
 if(e->address==0x5e3cb)ticks++;
 if(e->address==0x5f002&&mismatch_logs<12){TgRival *r=&c->rivals.shadow;if(r->speed!=w(0x1e5c)||r->fuel!=w(0x1e64)||r->gear!=w(0x1e74)||r->rpm!=w(0x1e60)){printf("MISMATCH physics tick=%u v=%u/%u fuel=%u/%u gear=%u/%u rpm=%u/%u lap=%u/%u pos=%u/%u target=%u/%u\n",ticks,r->speed,w(0x1e5c),r->fuel,w(0x1e64),r->gear,w(0x1e74),r->rpm,w(0x1e60),w(0x1e78),w(0x1e76),w(0x59),w(0x46),r->target,w(0x1ee2));mismatch_logs++;}}
 if(e->address==0x5f395&&mismatch_logs<12){TgRival *r=&c->rivals.shadow;if(r->steering!=w(0x1e80)||r->upper!=w(0x1ec4)||r->lower!=w(0x1ec6)){printf("MISMATCH steering tick=%u steer=%u/%u hi=%u/%u lo=%u/%u pit=%d flag=%04X\n",ticks,r->steering,w(0x1e80),r->upper,w(0x1ec4),r->lower,w(0x1ec6),(int)(int16_t)w(0x1e88),w(0x1ef2));mismatch_logs++;}}

 return 0;
}
static int shot(const char *tag,unsigned frame){char path[1024];FILE *f;uint32_t pixels[256*224];unsigned n;
 snprintf(path,sizeof(path),"%s-%u.ppm",tag,frame);if(!topgear_recomp_frame_bgra(c,pixels,256*224))return 0;f=fopen(path,"wb");if(!f)return 0;
 fprintf(f,"P6\n256 224\n255\n");for(n=0;n<256*224;n++){uint8_t b[3]={(uint8_t)(pixels[n]>>16),(uint8_t)(pixels[n]>>8),(uint8_t)pixels[n]};fwrite(b,1,3,f);}return fclose(f)==0;
}

typedef struct FuelAudit {int ready,phase,lap;unsigned fuel,used,added,stops,empty;} FuelAudit;
static FuelAudit fuel_audit[3];
static void audit_fuel(unsigned frame){unsigned k;
 for(k=0;k<3;k++){
  FuelAudit *a=&fuel_audit[k];TgRival *r=k?&c->rivals.rival[k-1]:NULL;
  int phase=r?r->pit_phase:(int)(int16_t)w(0x1e88),lap=r?r->lap:(int)(int16_t)w(0x1e78);
  unsigned fuel=r?r->fuel:w(0x1e64),pos=r?r->position>>8:w(0x1eda),car=r?r->car:w(0x1fac);
  int remaining=((int)w(0x1e56)-lap)*(int)w(0x200)-(int)pos;
  unsigned estimate61=(unsigned)((remaining/512)*122)&65535u,estimate80=(unsigned)((remaining/512)*160)&65535u;
  if(a->ready){if(fuel<a->fuel)a->used+=a->fuel-fuel;else a->added+=fuel-a->fuel;}
  if(!a->ready||phase!=a->phase||lap!=a->lap||(!fuel&&!a->empty)){
   printf("FUEL_EVENT frame=%u id=%u car=%u lap=%d pos=%u remaining=%d phase=%d->%d fuel=%u used=%u added=%u entry_estimate=%u refill_estimate=%u finish_index=%u\n",frame,k+1,car,lap,pos,remaining,a->ready?a->phase:0,phase,fuel,a->used,a->added,estimate61,estimate80,r?r->finish_index:65535u);
   fflush(stdout);
  }
  if(a->ready&&a->phase==-6&&phase==-7)printf("REFILL_EXIT id=%u fuel=%u remaining=%d full=%u refill_estimate=%u\n",k+1,fuel,remaining,fuel==43007u,estimate80);
  if(!fuel&&!a->empty){a->empty=1;printf("FUEL_EMPTY id=%u frame=%u lap=%d remaining=%d finish_index=%u\n",k+1,frame,lap,remaining,r?r->finish_index:65535u);}
  a->ready=1;a->phase=phase;a->lap=lap;a->fuel=fuel;a->stops=r?r->pit_stops:0;
 }
}

int main(int argc,char **argv){LARGE_INTEGER frequency,begin,end;double seconds=0;unsigned executed=0;uint8_t rom[524288];FILE *f;Driver d={0};unsigned n,frames,pitmask[2]={0},seen[20]={0},finishers=0,visible_frames=0,max_visible=0;char path[1024];
 if(argc<5)return 2;f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
 CHECK(topgear_recomp_create(&c,rom,sizeof(rom),error,sizeof(error)));
 CHECK(topgear_recomp_snapshot_load(c,argv[2],error,sizeof(error)));
 if(c->mod_time_trial_active){fprintf(stderr,"REFUSED: this rival test is restricted to Career and Rally.\n");topgear_recomp_destroy(c);return 2;}
 printf("ABI prefix=%u total=%u\n",(unsigned)offsetof(TopGearRecomp,rivals),(unsigned)sizeof(*c));
 frames=(unsigned)atoi(argv[3]);QueryPerformanceFrequency(&frequency);
 if(argc>=6&&strcmp(argv[5],"-")){put(0x1f8f,(unsigned)atoi(argv[5])&3u);tg_rivals_reset(c);}
 if(argc>=7)put(0x1f04,(unsigned)atoi(argv[6]));
 if(argc>=8)topgear_recomp_set_bottom_screen_enabled(c,atoi(argv[7]));
 topgear_recomp_set_center_screen_enabled(c,0);
 if(argc>=10&&!strcmp(argv[9],"career"))c->mod_rally_active=0;
 CHECK(!w(0x1f04));
 if(argc>=11&&!strcmp(argv[10],"no-pits")){put(0x1ef0,65534);puts("COUNTERFACTUAL pits disabled; same track geometry and full initial fuel; no fuel injections");}
 CHECK(topgear_recomp_set_hook(c,TOPGEAR_HOOK_MASK_INSTRUCTION,observe,NULL));
 printf("MODE trial=%u rally=%u course=%u length=%u laps=%u pit=%u players=%u\n",c->mod_time_trial_active,c->mod_rally_active,w(0x1f06),w(0x200),w(0x1e56),w(0x1ef0),w(0x1f04));
 for(n=0;n<frames;n++){
  TopGearRecompFrameResult result;unsigned k;
  QueryPerformanceCounter(&begin);
  CHECK(topgear_recomp_advance_headless(c,driver_input(c,&d,c->wram,c->mode1_frame,(w(0x1f7a)|w(0x1f7c))!=0),(uint16_t)(w(0x1f04)?0x40:0),1,&result));topgear_recomp_audio_clear(c);QueryPerformanceCounter(&end);seconds+=(double)(end.QuadPart-begin.QuadPart)/frequency.QuadPart;executed++;
  if(c->rivals.visible.count){visible_frames++;if(c->rivals.visible.count>max_visible)max_visible=c->rivals.visible.count;}
  if(argc>=9&&strcmp(argv[8],"-")&&n==30){c->rivals.rival[0].fuel=c->rivals.rival[1].fuel=(uint16_t)atoi(argv[8]);put(0x1e64,(unsigned)atoi(argv[8]));}
  audit_fuel(n);
  for(k=0;k<2;k++){int phase=c->rivals.rival[k].pit_phase;if(phase<0&&phase>= -11)pitmask[k]|=1u<<-phase;}
  if(n==300||n==1200||n==3000)CHECK(shot(argv[4],n));
  if(n%1000==0){printf("frame=%u tick=%u shadow=%u/%u visible=%u staged=%u/%u owners=%04X/%04X oamsrc=%06X p1lap=%u finishers=%u\n",n,c->rivals.ticks,c->rivals.shadow_failures,c->rivals.shadow_checks,c->rivals.visible.count,c->rivals.pending[0].count,c->rivals.pending[1].count,c->rivals.pending[0].owner,c->rivals.pending[1].owner,c->dma_last_source_address,w(0x1e76),w(0x1eb0));
   for(k=0;k<2;k++){TgRival *r=&c->rivals.rival[k];printf(" rival=%u car=%u speed=%d fuel=%u lap=%d pos=%u lateral=%d pit=%d stops=%u contacts=%u\n",r->id,r->car,(int)(int16_t)r->speed,r->fuel,r->lap,r->position>>8,(int)(int16_t)r->lateral,r->pit_phase,r->pit_stops,r->contacts);}fflush(stdout);}
  if(c->mod_time_trial_active){CHECK(!c->rivals.ready);CHECK(!c->rivals.visible.count);CHECK(!contacts_p1&&!contacts_p2);}
  if(w(0x1eb0)>=10&&(argc<10||strcmp(argv[9],"continue"))){finishers=w(0x1eb0);break;}
 }
 for(n=0;n<w(0x1eb0)&&n<20;n++){unsigned id=c->wram[0x1f12+n];CHECK(id<20&&!seen[id]);seen[id]=1;}
 CHECK(!c->rivals.overflow);
 if(!c->mod_time_trial_active){unsigned used=1u<<c->rivals.cars[0],k;for(k=1;k<4;k++){if(k==1&&w(0x1f04)){used|=1u<<c->rivals.cars[k];continue;}CHECK(!(used&(1u<<c->rivals.cars[k])));used|=1u<<c->rivals.cars[k];}}
 CHECK(shot(argv[4],99999));
 snprintf(path,sizeof(path),"%s-final.scsnap",argv[4]);CHECK(topgear_recomp_snapshot_save(c,path,error,sizeof(error)));
 printf("PERFORMANCE headless_frames=%u seconds=%.6f throughput_fps=%.2f (not window presentation FPS)\n",executed,seconds,executed/seconds);
 printf("GRAPHICS visible_frames=%u max_visible=%u owner=%04X\n",visible_frames,max_visible,c->rivals.visible.owner);
 printf("SUMMARY frame_limit=%u ticks=%u finishers=%u p1_place=%d shadow_checks=%u shadow_failures=%u overflow=%u native_contacts=%u/%u pit_masks=%04X/%04X stops=%u/%u rendered=",frames,ticks,finishers,(int)(int16_t)w(0x1f00),c->rivals.shadow_checks,c->rivals.shadow_failures,c->rivals.overflow,contacts_p1,contacts_p2,pitmask[0],pitmask[1],c->rivals.rival[0].pit_stops,c->rivals.rival[1].pit_stops);
 for(n=2;n<20;n++)printf("%u:%u ",n,c->rivals.rendered[n]);puts("");
 for(n=0;n<3;n++)printf("FUEL_TOTAL id=%u fuel=%u used=%u added=%u empty=%u stops=%u\n",n+1,fuel_audit[n].fuel,fuel_audit[n].used,fuel_audit[n].added,fuel_audit[n].empty,fuel_audit[n].stops);
 CHECK(!c->rivals.shadow_failures);
 topgear_recomp_destroy(c);return 0;
}
