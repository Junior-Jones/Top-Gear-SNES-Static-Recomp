#include "topgear_internal.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "v22_reentry/topgear_v22_reentry_shards.h"

/* Experimental 2.1.0 rival extension. Fixed IDs, no additional entrants/views.
   Native ID 1 retains its adapter; IDs 2/3 own independent vehicle states.
   All three execute the original generated CPU driving instructions.
   The C arithmetic below remains a diagnostic shadow for the native CPU. */
static const char names[20][9]={"PLAYER 1","JONES===","SENNA===","MANSELL=",
    "PROST===","PIQUET==","BERGER==","ALESI===","PATRESE=","BOUTSEN=",
    "BRUNDLE=","HAKKINEN","SCHUMACH","HILL====","HERBERT=","COULTHRD",
    "ALBORETO","NANNINI=","DECESARI","WARWICK="};
static const uint16_t colors[16]={0x001f,0x03e0,0x7c00,0x03ff,0x7c1f,0x7fe0,
    0x021f,0x7d0f,0x401f,0x43e0,0x7e00,0x7fff,0x0210,0x421f,0x03ef,0x7def};
static unsigned w(const TopGearRecomp *i,unsigned a){return i->wram[a]|((unsigned)i->wram[a+1u]<<8);}
static unsigned rw(const TopGearRecomp *i,unsigned a){return i->rom[a]|((unsigned)i->rom[a+1u]<<8);}
static void put(TopGearRecomp *i,unsigned a,unsigned v){i->wram[a]=(uint8_t)v;i->wram[a+1u]=(uint8_t)(v>>8);}
static uint16_t u(int v){return (uint16_t)v;}
static int s(unsigned v){return (int)(int16_t)v;}
static int fd(int a,int b){return a>=0?a/b:-((-a+b-1)/b);}
static int clamp(int a,int lo,int hi){return a<lo?lo:a>hi?hi:a;}
static unsigned id_at(const TopGearRecomp *i,unsigned off){return off==w(i,0x204)?0u:off==w(i,0x206)?1u:w(i,0x212+off)&31u;}
static unsigned find(const TopGearRecomp *i,unsigned id){unsigned n;for(n=0;n<360;n+=18)if(id_at(i,n)==id)return n;return 360;}
static int enabled(const TopGearRecomp *i){return !i->rivals.disabled&&!i->mod_time_trial_active&&!w(i,0x1f04);}
const char *tg_rivals_name(unsigned id){return names[id<20u?id:0u];}
uint8_t tg_rivals_name_byte(unsigned offset){unsigned index=offset/8u;return (uint8_t)names[index==18u?1u:index+2u][offset&7u];}
int tg_rivals_promoted(const TopGearRecomp *i,unsigned off){unsigned id;
    if(!enabled(i)||i->rivals.extra_cpu_off||!i->rivals.ready||off>=360)return 0;
    id=id_at(i,off);return id==2u||id==3u;
}
void tg_rivals_menu_enter(TopGearRecomp *i){
    if(i->rivals.reserved){put(i,0x1fac,i->rivals.saved_p2_car);i->rivals.reserved=0;i->rivals.ready=0;i->rivals.visible.count=0;}
}
void tg_rivals_reset(TopGearRecomp *i){uint8_t disabled=i->rivals.disabled;uint64_t off=i->rivals.extra_cpu_off;memset(&i->rivals,0,sizeof(i->rivals));i->rivals.disabled=disabled;i->rivals.extra_cpu_off=off;}

/* Actual car tables occupy 16-byte rows after the common CPU row. */
void tg_rivals_physics(TopGearRecomp *i,TgRival *r,int actual_car){
    unsigned old=r->gear<5?r->gear:4,table=old*2u+(actual_car?r->car*16u:0u);
    unsigned target,drag,factor=actual_car?rw(i,0x17db+r->car):100u;
    int v=s(r->speed),q,term,diff,change,rpm;
    if(v>=0){if((unsigned)v<rw(i,(actual_car?0x19dbu+r->car*16u:0x1a4fu)+old*2u)&&r->gear)r->gear--;
        else if((unsigned)v>=rw(i,(actual_car?0x1a15u+r->car*16u:0x1a89u)+old*2u)&&r->gear<4)r->gear++;}
    target=(rw(i,0x1597+table)+((0xa7ffu-r->fuel)&65535u)/64u)&65535u;
    {int lap=s(u(r->lap-s(w(i,0x1e76))));
     int lead=lap*(int)w(i,0x200)+(r->id==1?(int)w(i,0x59)-(int)w(i,0x46):(int)(r->position>>8)-(int)w(i,0x1ed7));
     if(w(i,0x1f10)!=3u&&r->gear==4u&&lap>=0&&lead>=0){lead=clamp(lead,0,1024);target=u((int)target-(w(i,0x1f10)==0?2*lead+1:lead));}}
    r->target=(uint16_t)target;
    q=s(u(-s(w(i,0x4000+((r->position>>12)&0xfffeu)))));
    if(q<0)q=fd(q,4);
    term=s(u(fd(q*(int)(int8_t)rw(i,0x16f3+table),256)));
    v=s(u(v+fd(q,16)));v=clamp(v,-(int)target,(int)target);
    drag=((unsigned)(v<0?v+(int)rw(i,0x160b+table):-v+(int)rw(i,0x160b+table))&65535u)>>8;
    if(v<0){v+=(int)drag;if(v>=0)v=0;}else{v-=(int)drag;if(v<0)v=0;}
    if(r->fuel&&w(i,0x1eb0)<10){diff=s(u((int)target-v));change=s(u(term+((unsigned)fd(diff*(int)(int8_t)rw(i,0x167f+table),256)&65535u)/4u));if(change>=0)v=s(u(v+change));}
    else{diff=s(u(2*v-(int)target));if(diff>=0)v=s(u(v-fd(diff,128)));}
    r->speed=u(v);rpm=s(u(fd(v*(int)(int8_t)rw(i,0x1767+table),128)));
    if(rpm>0&&r->fuel){unsigned cost=1u+((unsigned)fd(rpm*(int)(int8_t)factor,16384)&1023u);
        if(cost>=r->fuel){r->fuel=0;rpm=0;r->flags|=0x20;}else r->fuel=(uint16_t)(r->fuel-cost);}
    r->rpm=u(rpm);
}

static unsigned estimate(const TopGearRecomp *i,const TgRival *r,unsigned factor){
    /* F79F uses a signed half-length/lap product, high-word truncation and wrap. */
    int remaining=s(u(w(i,0x200)/2u))*s(u((int)w(i,0x1e56)-r->lap))-(int)((r->position>>8)/2u);
    int half=s(u(fd(remaining,256)));
    return u(half*(int)(int8_t)factor*2);
}
static int wants_pit(const TopGearRecomp *i,const TgRival *r){
    return (r->id==1u&&(w(i,0x1ef2)&1u))||(w(i,0x1ef0)!=65534u&&r->fuel<0x3000u&&estimate(i,r,61u)>=r->fuel);
}

void tg_rivals_steering(TopGearRecomp *i,TgRival *r,unsigned off){
    unsigned index=(r->position>>12)&0xfffeu,front=(off+18u)%360u,wrap=front?0:w(i,0x200);
    unsigned packed=w(i,0x7002+index),hi,lo,pass=r->passing_side?0xff00u:0;
    int hc=fd(s(r->lateral),2),hf=fd(s(w(i,0x214+front)),2),clear=0,set=0;
    /* F79F enters 8-bit index mode, truncating the native CPU's saved Y.
       Preserve it in the native adapter/shadow. Private rivals deliberately
       keep a valid full neighbour offset, avoiding reads inside another record. */
    if(r->id==1u&&r->fuel<0x3000u&&!(w(i,0x1ef2)&1u))front&=255u;
    if(r->recovery){int v=s(r->steering),d=640+r->recovery;r->steering=u(v>0?(v>d?v-d:0):v<0?(v< -d?v+d:0):0);if(!r->steering)r->recovery=0;return;}
    if(wants_pit(i,r)){unsigned delta=u((int)(r->position>>8)-(int)w(i,0x1ef0));
        if(delta<1184u){index=(delta>768u?768u:delta)>>4;index&=0xfffeu;packed=rw(i,(w(i,0x1ef2)&4u?0x6198u:0x6166u)+index);}}
    hi=u((int)(int8_t)(packed>>8)*128);lo=u((int)(int8_t)packed*128);
    if(wants_pit(i,r)&&u((int)(r->position>>8)-(int)w(i,0x1ef0))<1184u&&(w(i,0x1ef2)&2u)){hi=u(-s(hi));lo=u(-s(lo));}
    {unsigned sum=u((int)w(i,0x219+front)+(int)wrap),gap=u((int)sum-(int)(r->position>>8));
     if((sum<(r->position>>8)||gap<512u)&&s(u(hf-(int)lo))>=0&&s(u(hf-(int)hi))<0){
        if(!pass){if(u((int)hi-hf)<3840)set=1;else if(s(w(i,0x216+front))<0)clear=1;else if(u(hf-(int)lo)<2560)clear=1;else if(s(u(hf-hc))<0)clear=1;else if(u(hf-hc)>=2048)set=1;else clear=1;}
        else{if(u(hf-(int)lo)<3840)clear=1;else if(s(w(i,0x216+front))>=0)set=1;else if(u((int)hi-hf)<2560)set=1;else if(s(u(hc-hf))<=0)set=1;else if(u(hc-hf)>=2048)clear=1;else set=1;}}}
    if(clear){unsigned n=u(hf+2560);pass=0;if(s(u((int)n-(int)hi))>=0)n=lo;lo=n;}
    if(set){unsigned n=u(hf-2560);pass=0xff00;if(s(u((int)n-(int)lo))<0)n=hi;hi=n;}
    {int d=s(u((int)hi-r->upper));if(d>=601)hi=u(r->upper+600);else if(d< -1281)hi=u(r->upper-1280);}
    {int d=s(u(r->lower-(int)lo));if(d>=601)lo=u(r->lower-600);else if(d< -1281)lo=u(r->lower+1280);}
    r->upper=(uint16_t)hi;r->lower=(uint16_t)lo;r->passing_side=(uint8_t)(pass!=0);
    {int center=s(u((int)hi+fd(s(u((int)lo-(int)hi)),2)));
     int curve=s(u(fd(s(r->speed)*(int)(int8_t)i->wram[0x4c08+index],256)));
     r->steering=u(clamp(s(u(center-3*curve-hc)),-4096,8191)*4);}
}

static void synchronize(TopGearRecomp *i,TgRival *r,unsigned off){
    put(i,0x214+off,r->lateral);put(i,0x216+off,0);
    i->wram[0x218+off]=(uint8_t)r->position;put(i,0x219+off,r->position>>8);
    i->wram[0x21b+off]=(uint8_t)(r->lap+1);
    /* Nonzero proxy is only a compatibility interface, never the state owner. */
    put(i,0x21c+off,r->gate?1u:(unsigned)(r->speed>>1)?r->speed>>1:1u);
    put(i,0x21e+off,0);put(i,0x220+off,0);
}
static void initialize(TopGearRecomp *i){
    TgRivals *x=&i->rivals;unsigned n,k,available[4],count=0;
    x->abi=1;x->course=(uint16_t)w(i,0x1f06);x->players=(uint16_t)w(i,0x1f04);x->cars[0]=(uint8_t)(w(i,0x1f8f)&3u);if(!x->reserved)x->saved_p2_car=i->mod_setup_initialized?(uint16_t)(i->mod_setup_shared[1][24]|((unsigned)i->mod_setup_shared[1][25]<<8)):(uint16_t)w(i,0x1fac);
    x->cars[1]=(uint8_t)(w(i,0x1fac)&3u);
    for(n=0;n<4;n++)if(n!=x->cars[0]&&(!x->players||n!=x->cars[1]))available[count++]=n;
    if(!x->players){x->cars[1]=(uint8_t)available[0];x->cars[2]=(uint8_t)available[1];x->cars[3]=(uint8_t)available[2];}
    else{x->cars[2]=(uint8_t)available[0];x->cars[3]=(uint8_t)available[1];}
    for(n=0;n<2;n++){unsigned off=find(i,n+2u);TgRival *r=&x->rival[n];memset(r,0,sizeof(*r));
        r->id=(uint8_t)(n+2u);r->car=x->cars[n+2u];r->fuel=43007;r->nitro=0;r->finish_index=65535;
        r->upper=6144;r->lower=u(-6144);r->lap=(int16_t)((int)i->wram[0x21b+off]-1);
        r->position=((uint32_t)w(i,0x219+off)<<8)|i->wram[0x218+off];r->lateral=(uint16_t)w(i,0x214+off);}
    for(n=0;n<4;n++){memcpy(x->tiles[n],i->rom+0x20000+n*3936u,3936);for(k=0;k<16;k++)x->palettes[n][k]=(uint16_t)rw(i,0x412da+n*32u+k*2u);}
    for(n=4;n<22;n++)for(k=0;k<16;k++){
        unsigned base=rw(i,0x4135a+k*2u),c=n<20u?colors[n-4u]:(n==20u?0x5ad6u:0x02ffu);
        if(k>=8&&k<=13){unsigned shade=31u-(k-8u)*4u;base=((c&31u)*shade/31u)|((((c>>5)&31u)*shade/31u)<<5)|((((c>>10)&31u)*shade/31u)<<10);}
        x->palettes[n][k]=(uint16_t)base;
    }
    if(!x->players){
        x->reserved=1;
        put(i,0x1fac,x->cars[1]);memcpy(i->vram+0x5000,x->tiles[x->cars[1]],3936);
        for(k=0;k<16;k++){unsigned c=x->palettes[x->cars[1]][k];i->cgram[288u+k*2u]=(uint8_t)c;i->cgram[289u+k*2u]=(uint8_t)(c>>8);}
    }
    x->ready=1;
}

/* Run the original generated CPU driving instructions in an isolated machine
   context. Only this driver's vehicle state is committed. Math registers,
   scratch RAM, stack, camera and audio effects never escape into the race.
   The existing actual-car table adapter is also applied here, as for JONES. */
int tg_rivals_native_drive(TopGearRecomp *i,TgRival *r,unsigned off){
    TopGearRecomp *c=(TopGearRecomp *)malloc(sizeof(*c));unsigned guard=0;int ok;
    if(!c)return tg_fail_frontier(i,"Cannot allocate native rival context.",NULL);
    memcpy(c,i,sizeof(*c));
    c->hook_callback=NULL;c->hook_stop_requested=0;c->v23_event_mode=0;
    c->cpu.pbr=5;c->cpu.pc=0xed92;c->cpu.dbr=0;c->cpu.d=0;
    c->cpu.p=TG_P_I;c->cpu.e=0;c->cpu.s=0x1b00;
    put(c,0x206,off);put(c,0x53,0);put(c,0x1fac,r->car);
    put(c,0x1e5c,r->speed);put(c,0x1e64,r->fuel);put(c,0x1e74,r->gear);
    put(c,0x1e60,r->rpm);put(c,0x1e78,u(r->lap));
    put(c,0x1ed9,r->position&65535u);c->wram[0x1edb]=(uint8_t)(r->position>>16);
    put(c,0x59,r->position>>8);put(c,0x1e8c,r->lateral);
    put(c,0x1ec4,r->upper);put(c,0x1ec6,r->lower);c->wram[0x1ec8]=r->passing_side?0xff:0;
    put(c,0x1e80,r->steering);put(c,0x1eee,r->recovery);put(c,0x1e84,r->recovery);
    put(c,0x1ebe,r->edge?0xff00:0);put(c,0x1e88,u(r->pit_phase));
    put(c,0x1ef6,r->flags);put(c,0x1f02,0xffff);put(c,0x1ee0,3);
    put(c,0x1efe,rw(i,0x17db+r->car));
    /* Original CPU never uses nitro: this retained ABI byte owns pit intent. */
    put(c,0x1ef2,(w(i,0x1ef2)&~1u)|(r->nitro&1u));
    while(!c->failed&&!(c->cpu.pbr==5&&c->cpu.pc==0xe3b9)&&guard++<12000){
        if(c->cpu.pbr==5&&c->cpu.pc==0xee05)c->cpu.y=(uint16_t)(c->cpu.y+r->car*16u);
        if(!tg_v22_reentry_semantic_step(c))break;
    }
    ok=!c->failed&&c->cpu.pbr==5&&c->cpu.pc==0xe3b9&&c->cpu.s==0x1b00;
    if(ok){
        r->speed=(uint16_t)w(c,0x1e5c);r->fuel=(uint16_t)w(c,0x1e64);r->gear=(uint16_t)w(c,0x1e74);r->rpm=(uint16_t)w(c,0x1e60);r->target=(uint16_t)w(c,0x1ee2);
        r->position=(uint32_t)c->wram[0x1ed9]|((uint32_t)w(c,0x1eda)<<8);
        r->lateral=(uint16_t)w(c,0x1e8c);r->steering=(uint16_t)w(c,0x1e80);r->recovery=(uint16_t)w(c,0x1eee);
        r->upper=(uint16_t)w(c,0x1ec4);r->lower=(uint16_t)w(c,0x1ec6);r->passing_side=c->wram[0x1ec8]!=0;
        r->forward_step=(uint16_t)w(c,0x1e8e);r->edge=c->wram[0x1ebf]!=0;r->flags=(uint16_t)w(c,0x1ef6);
        r->pit_phase=(int16_t)w(c,0x1e88);r->nitro=(uint8_t)(w(c,0x1ef2)&1u);
    }else{char message[256];snprintf(message,sizeof(message),"Native rival %u failed at %02X:%04X: %.140s",r->id,c->cpu.pbr,c->cpu.pc,c->last_error);tg_fail_frontier(i,message,NULL);}
    free(c);return ok;
}

/* Private pit progress is clocked by the native pit-event boundary (9222),
   independently of rendering and physics ticks. Scroll/speed milestones mirror
   BD94..BE0D; transfer phases complete on the next logical event. */
static void pit(TopGearRecomp *i,TgRival *r){
    unsigned phase=(unsigned)-r->pit_phase,scroll=r->pit_elapsed&1023u;
    if(phase==1){
        if(u((int)(r->position>>8)-(int)w(i,0x1ef0))<1184u)return;
        r->gate=1;r->speed=0x1700;r->gear=4;r->pit_elapsed=0x280;r->pit_phase=-2;return;
    }
    if(phase==2||phase==3||phase==4||phase==9||phase==10){r->pit_phase--;return;}
    if(phase==5){
        if(scroll>=0x188u)r->speed=u(r->speed+41);
        else if(scroll>=0x80u){int delta=s((u((int)scroll-512)>>2)|0xc000u),speed=s(r->speed)+delta;if(speed>=0)r->speed=u(speed);else r->speed=0;}
        else r->speed=0;
        r->pit_elapsed=u((int)r->pit_elapsed-(int)(r->speed>>11));
        if(!r->speed)r->pit_phase=-6;
        return;
    }
    if(phase==6){unsigned fuel=r->fuel+127u;r->fuel=(uint16_t)(fuel>43007u?43007u:fuel);r->refill_updates++;
        if(r->fuel>=43007u||r->fuel>estimate(i,r,80u))r->pit_phase=-7;
        return;
    }
    if(phase==7||phase==8){
        r->speed=u(s(r->speed)+fd(0x1b00-s(r->speed),64));
        r->pit_elapsed=u((int)r->pit_elapsed-(int)(r->speed>>11));scroll=r->pit_elapsed&1023u;
        if(phase==7&&scroll>=0x300u&&scroll<0x380u)r->pit_phase=-8;
        else if(phase==8&&scroll<0x300u)r->pit_phase=-9;
        return;
    }
    if(phase==11){
        unsigned bounds=w(i,0x7002+((r->position>>12)&0xfffeu));
        r->upper=u((int)(int8_t)(bounds>>8)*128);r->lower=u((int)(int8_t)bounds*128);
        r->lateral=u(s(r->upper)+s(r->lower));r->steering=0;r->recovery=0;r->edge=0;
        r->gate=0;r->pit_stops++;r->pit_phase=0;r->flags&=(uint16_t)~0x20u;
    }
}
static void progress(TopGearRecomp *i,TgRival *r){
    unsigned pos=r->position>>8,length=w(i,0x200),off=find(i,r->id),oldlap=i->wram[0x21b+off];
    if(pos>=0xfc00u){r->position=((uint32_t)u((int)pos+(int)length)<<8)|(r->position&255u);r->lap--;}
    else if(pos>=length){r->position=((pos-length)<<8)|(r->position&255u);r->lap++;
        if(oldlap==w(i,0x1e56)&&r->finish_index==65535u){unsigned place=w(i,0x1eb0),clock=w(i,0x1eae);
            if(place<20){if(place){unsigned previous=i->wram[0x1f12+place-1u],time=w(i,0x1f26+previous*2u);if(time>=clock){clock=(time+1u)&65535u;put(i,0x1eae,clock);}}
                r->finish_index=(uint16_t)place;i->wram[0x1f12+place]=r->id;put(i,0x1f26+r->id*2u,clock);put(i,0x1eb0,place+1u);}}}
}
static void contacts(TopGearRecomp *i,TgRival *r){
    unsigned n,self=find(i,r->id);if(r->gate||r->finish_index!=65535u)return;
    for(n=0;n<360;n+=18){unsigned id=id_at(i,n),pos=w(i,0x219+n),speed=w(i,0x21c+n)*2u;int gap=s(u((int)pos-(int)(r->position>>8))),lat=fd(s(r->lateral),2)-fd(s(w(i,0x214+n)),2);TgRival *other=NULL;
        if(n==self||gap<0||gap>7||lat< -2048||lat>=2048)continue;
        if(id==0){if(w(i,0x40))continue;speed=w(i,0x1e5a);}else if(id==1){if(w(i,0x53))continue;speed=w(i,0x1e5c);}else if(id<4){other=&i->rivals.rival[id-2u];if(other->gate)continue;speed=other->speed;}
        if(s(r->speed)<=s(speed))continue;
        if(other){other->speed=r->speed;other->steering=u(-lat*8);synchronize(i,other,n);}
        else if(id==0){put(i,0x1e5a,r->speed);put(i,0x1e7e,u(-lat*8));}
        else if(id==1){put(i,0x1e5c,r->speed);put(i,0x1e80,u(-lat*8));}
        else{unsigned old=w(i,0x21c+n),base=u((int)old+s(w(i,0x21e+n))*(int)(w(i,0x220+n)&255u)),delta=u((int)(r->speed>>1)-(int)base)&0xffc0u;
            put(i,0x21c+n,u((int)base+(int)delta));put(i,0x21e+n,u(-s(delta)/64));put(i,0x220+n,64);
            if(!w(i,0x21c+n)){put(i,0x21c+n,w(i,0x21e+n));put(i,0x220+n,63);}}
        r->speed=(uint16_t)speed;r->position=((uint32_t)u((int)pos-8)<<8)|(r->position&255u);r->contacts++;r->flags|=128;break;
    }
}
void tg_rivals_tick(TopGearRecomp *i){unsigned n;
    if(!enabled(i)){i->rivals.ready=0;return;}
    if(!i->rivals.ready)initialize(i);
    i->rivals.ticks++;
    if(i->rivals.extra_cpu_off)return;
    for(n=0;n<2;n++){TgRival *r=&i->rivals.rival[n];unsigned off=find(i,r->id);
        if(off>=360)continue;r->updates++;r->flags&=(uint16_t)~128u;

        if(!r->gate){if(!tg_rivals_native_drive(i,r,off))return;contacts(i,r);progress(i,r);}
        synchronize(i,r,off);
    }
}

static TgRivalObjects *pending(TopGearRecomp *i,unsigned view){
    unsigned owner=w(i,view?0xd8:0xcc),n;for(n=0;n<4;n++)if(i->rivals.pending[n].owner==owner)return &i->rivals.pending[n];
    n=(i->rivals.staging+1u)%4u;i->rivals.staging=(uint8_t)n;i->rivals.pending[n].owner=(uint16_t)owner;return &i->rivals.pending[n];
}
void tg_rivals_latch(TopGearRecomp *i,uint16_t owner){unsigned n;
    if(!enabled(i)||!i->rivals.ready){i->rivals.visible.count=0;return;}
    for(n=0;n<4;n++)if(i->rivals.pending[n].owner==owner){i->rivals.visible=i->rivals.pending[n];return;}
    i->rivals.visible.count=0;
}
static void submit(TopGearRecomp *i,unsigned id,unsigned style,unsigned view,unsigned clipped){
    TgRivalObjects *list=pending(i,view);unsigned a,groups,g,size,index=(style+w(i,0x1b76))&0xfffeu;
    uint32_t order=(w(i,0x1b92)/4u)*2048u+list->count;
    if(index>=0x430u)return;
    a=0xb245+rw(i,0xae15+index);groups=rw(i,a+2u);a+=4;
    for(g=0;g<groups;g++){
        unsigned adjust=w(i,0x1b9c+rw(i,a));a+=2;
        for(size=16;size>=8;size-=8){unsigned count=rw(i,a),j;a+=2;
            for(j=0;j<count;j++,a+=6){int x=s(u((int)rw(i,a)+s(w(i,0x1b88)))),y=s(u((int)rw(i,a+2u)+s(w(i,0x1b8a))));
                unsigned attr=(rw(i,a+4u)+w(i,(view?0x1d56u:0x1c08u)+rw(i,0xb245+rw(i,0xae15+index)))+adjust)&65535u;
                TgExtendedObject *o;
                if(x>=s(w(i,0xf7))||x<s(w(i,0xf9))||y>= (clipped?s(w(i,view?0x61:0x4e)):104)||y<1-(int)size)continue;
                if(list->count>=TG_RIVAL_OBJECT_CAPACITY||list->per_view[view]>=256u){i->rivals.overflow++;continue;}
                o=&list->objects[list->count++];memset(o,0,sizeof(*o));o->x=(int16_t)x;o->y=(int16_t)(y+(view?116:4));o->size=(uint8_t)size;
                o->bank=(uint8_t)((id<4&&!i->rivals.extra_cpu_off)?i->rivals.cars[id]:255u);o->palette=(uint8_t)((id<4&&!i->rivals.extra_cpu_off)?o->bank:(id<4?id+18u:id));o->tile=(uint16_t)((id<4&&!i->rivals.extra_cpu_off)?attr&127u:attr&511u);
                o->priority=(uint8_t)((attr>>12)&3u);o->hflip=(uint8_t)((attr>>14)&1u);o->vflip=(uint8_t)((attr>>15)&1u);o->math=(uint8_t)(((attr>>9)&7u)>=4u);o->driver=(uint8_t)id;o->order=order++;
                list->per_view[view]++;i->rivals.rendered[id]++;
            }
        }
    }
}

/* Fixed instruction-boundary integration shared by both generated dispatches. */
void tg_rivals_before(TopGearRecomp *i,uint32_t pc){TgRivals *x=&i->rivals;unsigned off,id;
    if(pc==0xa569u){tg_rivals_reset(i);return;}
    if(pc==0xc61eu&&enabled(i)&&!w(i,0x1f04)){unsigned p=w(i,0x1f8f)&3u,car=p==0?1u:0u;if(!x->reserved){x->saved_p2_car=(uint16_t)w(i,0x1fac);x->reserved=1;}put(i,0x1fac,car);}
    if(i->mod_time_trial_active&&pc==0xa175u){unsigned n;for(n=0;n<360;n+=18){put(i,0x21c+n,0);put(i,0x21e+n,0);put(i,0x220+n,0);}}
    if(!enabled(i)){x->ready=0;x->visible.count=0;return;}
    if(pc==0x5e3cbu)tg_rivals_tick(i);
    if(pc==0x5ed92u&&!w(i,0x1f04)){
        unsigned car=w(i,0x1fac)&3u;put(i,0x1efe,rw(i,0x17db+car));
    }
    if(pc==0x5ee05u&&!w(i,0x1f04))i->cpu.y=(uint16_t)(i->cpu.y+(w(i,0x1fac)&3u)*16u);
    if(pc==0x5eddeu&&!w(i,0x1f04)){
        TgRival *r=&x->shadow;memset(r,0,sizeof(*r));r->id=1;r->car=(uint8_t)(w(i,0x1fac)&3u);
        r->gear=(uint16_t)w(i,0x1e74);r->speed=(uint16_t)w(i,0x1e5c);r->fuel=(uint16_t)w(i,0x1e64);
        r->position=(uint32_t)w(i,0x1eda)<<8;r->lap=(int16_t)w(i,0x1e78);tg_rivals_physics(i,r,1);
    }
    if(pc==0x5f002u&&!w(i,0x1f04)){
        TgRival *r=&x->shadow;x->shadow_checks+=4;
        if(r->speed!=w(i,0x1e5c)||r->fuel!=w(i,0x1e64)||r->gear!=w(i,0x1e74)||r->rpm!=w(i,0x1e60))x->shadow_failures++;
    }
    if(pc==0x5f17du&&!w(i,0x1f04)){
        TgRival *r=&x->shadow;memset(r,0,sizeof(*r));r->id=1;r->speed=(uint16_t)w(i,0x1e5c);r->fuel=(uint16_t)w(i,0x1e64);r->position=(uint32_t)w(i,0x1eda)<<8;
        r->lateral=(uint16_t)w(i,0x1e8c);r->upper=(uint16_t)w(i,0x1ec4);r->lower=(uint16_t)w(i,0x1ec6);r->passing_side=i->wram[0x1ec8];r->lap=(int16_t)w(i,0x1e78);
        tg_rivals_steering(i,r,w(i,0x206));
    }
    if(pc==0x5f395u&&!w(i,0x1f04)){
        TgRival *r=&x->shadow;x->shadow_checks+=4;
        if(r->steering!=w(i,0x1e80)||r->upper!=w(i,0x1ec4)||r->lower!=w(i,0x1ec6)||r->passing_side!=(i->wram[0x1ec8]!=0))x->shadow_failures++;
    }
    if(!x->ready)return;
    if(pc==0x9222u&&!x->extra_cpu_off){unsigned n;for(n=0;n<2;n++)if(x->rival[n].pit_phase<0)pit(i,&x->rival[n]);}
    if(pc==0xa17cu&&i->cpu.x>=18u&&tg_rivals_promoted(i,i->cpu.x-18u))i->cpu.pc=0xa1b5;
    if((pc==0xaca1u||pc==0xae1eu)&&tg_rivals_promoted(i,i->cpu.x))i->cpu.pc=(uint16_t)(pc==0xaca1u?0xacd6u:0xae53u);
    if((pc==0xad25u||pc==0xaf6au)&&i->cpu.y<80u)x->projected[i->cpu.y/4u]=(uint8_t)id_at(i,i->cpu.x);
    if((pc==0x7e2da0u||pc==0x7e30ddu)&&i->cpu.x<160u&&i->cpu.y<80u)x->objects[i->cpu.x/8u]=x->projected[i->cpu.y/4u];
    if((pc==0x7e2d98u||pc==0x7e30d5u||pc==0x7e3042u||pc==0x7e3086u)&&i->cpu.x<160u)x->objects[i->cpu.x/8u]=0;
    if(pc==0x18000u||pc==0x18568u){TgRivalObjects *p=pending(i,pc==0x18568u);p->count=0;p->per_view[0]=p->per_view[1]=0;p->generation++;}
    if((pc==0xae9cu||pc==0xb035u)&&i->cpu.y<80u)x->projected[20u+i->cpu.y/4u]=(uint8_t)id_at(i,i->cpu.x);
    if((pc==0x7e2349u||pc==0x7e2686u)&&i->cpu.x<160u&&i->cpu.y<80u)x->objects[20u+i->cpu.x/8u]=x->projected[20u+i->cpu.y/4u];
    if((pc==0x7e2341u||pc==0x7e267eu||pc==0x7e25ebu||pc==0x7e262fu)&&i->cpu.x<160u)x->objects[20u+i->cpu.x/8u]=0;
    if(pc==0x180d3u||pc==0x18373u||pc==0x185e4u||pc==0x18890u)x->draw_id=0;
    if((pc==0x18202u||pc==0x18217u||pc==0x1838au)&&i->cpu.x<160u)x->draw_id=x->objects[i->cpu.x/8u];
    if((pc==0x1871fu||pc==0x18734u||pc==0x188a7u)&&i->cpu.x<160u)x->draw_id=x->objects[20u+i->cpu.x/8u];
    if(pc==0x18a87u||pc==0x18c5cu||pc==0x18e33u||pc==0x19008u){unsigned style=w(i,0x1b86),view=pc==0x18e33u||pc==0x19008u,clipped=pc==0x18c5cu||pc==0x19008u;id=x->draw_id;
        if(id>=2u&&id<20u&&style>=0x200u&&style<0x400u&&(style&255u)<0x50u){
            if(id<4u&&!x->extra_cpu_off){TgRival *r=&x->rival[id-2u];if(!r->gate&&(!view||w(i,0x1f04)))submit(i,id,style&255u,view,clipped);}
            else if(!view||w(i,0x1f04))submit(i,id,style,view,clipped);
            /* Execute the existing CLC/RTS, preserving the caller's stack. */
            i->cpu.pc=(uint16_t)(view?(clipped?0x91ddu:0x9006u):(clipped?0x8e31u:0x8c5au));
        }
    }
    if((pc==0x5e4aau||pc==0x5e689u)&&tg_rivals_promoted(i,i->cpu.x)&&x->rival[id_at(i,i->cpu.x)-2u].gate)
        i->cpu.pc=(uint16_t)(pc==0x5e4aau?0xe5a4u:0xe783u);
    if(pc==0xa2c4u&&i->cpu.x>=18u&&tg_rivals_promoted(i,i->cpu.x)){
        unsigned target=i->cpu.x,source=target-18u;
        TgRival *r=&x->rival[id_at(i,target)-2u];
        int delta=s(u((int)w(i,0x214+source)-r->lateral));
        if(!r->gate&&delta>= -2048&&delta<2048&&s(r->speed)>=0){
            unsigned old=w(i,0x21c+source),base=u((int)old+s(w(i,0x21e+source))*(int)(w(i,0x220+source)&255u));
            unsigned change=u((int)(r->speed>>1)-(int)base)&0xffc0u;
            put(i,0x21c+source,u((int)base+(int)change));put(i,0x21e+source,u(-s(change)/64));put(i,0x220+source,64);
            if(!w(i,0x21c+source)){put(i,0x21c+source,w(i,0x21e+source));put(i,0x220+source,63);}
            put(i,0x219+source,r->position>>8);r->speed=u((int)old*2);r->contacts++;r->flags|=128;synchronize(i,r,target);
        }
    }
    if(pc==0x5e8e9u||pc==0x5e944u){off=i->cpu.x;
        if(tg_rivals_promoted(i,off)){TgRival *r=&x->rival[id_at(i,off)-2u];unsigned player=pc==0x5e944u,addr=player?0x1e5c:0x1e5a;
            if(!r->gate&&s(w(i,addr))>=0){unsigned old=w(i,addr);put(i,addr,r->speed);r->speed=(uint16_t)old;r->contacts++;r->steering=u(-(fd(s(w(i,player?0x1e8c:0x1e8a)),2)-fd(s(r->lateral),2))*8);
                put(i,player?0x1eda:0x1ed7,u((int)(r->position>>8)-8));synchronize(i,r,off);}
            i->cpu.pc=(uint16_t)(player?0xe99eu:0xe943u);
        }
    }
}
