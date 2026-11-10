#include "topgear_60_timing.h"
#include <string.h>

static int force_step(int *remainder,int delta,unsigned dt);

int tg60_active(const TopGearRecomp *i){return i&&i->experimental_60fps_enabled!=0u;}
int topgear_recomp_experimental_60fps_enabled(const TopGearRecomp *i){return i&&i->experimental_60fps_requested!=0u;}
void tg60_apply_requested(TopGearRecomp *i){
    if(i&&i->experimental_60fps_enabled!=i->experimental_60fps_requested){
        tg60_reset(i);i->experimental_60fps_enabled=i->experimental_60fps_requested;
    }
}
void topgear_recomp_set_experimental_60fps_enabled(TopGearRecomp *i,int enabled){
    if(!i)return;i->experimental_60fps_requested=enabled?1u:0u;
    if(i->hdma_enable_mask!=0x7fu||i->mod_menu_remodel_active)tg60_apply_requested(i);
}

void tg60_reset(TopGearRecomp *i){memset(&i->timing60,0,sizeof(i->timing60));}
/* Native fuel cost is per nominal 20 Hz simulation tick. Carry thirds rather
   than rounding each 60 Hz charge, especially the minimum one-unit cost.
   The division precedes the original tank arithmetic, so its empty-tank,
   RPM and warning branches still use the actual charged quantity. */
unsigned tg60_fuel_step(TopGearRecomp *i,unsigned actor,unsigned cost,unsigned elapsed){
    unsigned total,charge;
    if(!tg60_active(i)||actor>=4)return cost;
    total=cost*elapsed+i->timing60.fuel.remainder[actor];
    charge=total/3;i->timing60.fuel.remainder[actor]=total%3;
    i->timing60.fuel.calls[actor]++;i->timing60.fuel.raw[actor]+=cost*elapsed;
    i->timing60.fuel.emitted[actor]+=charge;return charge;
}
static unsigned tw(const TopGearRecomp *i,unsigned a){return i->wram[a]|((unsigned)i->wram[a+1]<<8);}
static unsigned cpu_actor(const TopGearRecomp *i){
    unsigned off=tw(i,0x206),id;
    if(off>=360||off%18)return 1;
    id=tw(i,0x212+off)&31u;return id>=1&&id<=3?id:1;
}
static unsigned positive_step(unsigned *remainder,unsigned cost,unsigned dt){unsigned total=cost*dt+*remainder;*remainder=total%3;return total/3;}
unsigned tg60_shadow_recovery_cost(TopGearRecomp *i,unsigned cost){
    unsigned dt=tw(i,0x1e90);
    if(!tg60_active(i)||i->hdma_enable_mask!=0x7f||i->mod_menu_remodel_active||!dt||dt>255)return cost;
    return positive_step(i->timing60.shadow_recovery_remainder+cpu_actor(i),cost,dt);
}
static unsigned recovery_operand(TopGearRecomp *i,unsigned actor,unsigned addr){
    unsigned old=tw(i,addr),dt=tw(i,0x1e90),value=positive_step(i->timing60.recovery_remainder+actor,old,dt);
    i->wram[addr]=(uint8_t)value;i->wram[addr+1]=(uint8_t)(value>>8);return old;
}
static int control_active(const TopGearRecomp *i){return tg60_active(i)&&i->hdma_enable_mask==0x7f&&!i->mod_menu_remodel_active&&tw(i,0x1e90)>0&&tw(i,0x1e90)<=255;}
unsigned tg60_refill_step(TopGearRecomp *i,unsigned actor){return actor<4&&control_active(i)?positive_step(i->timing60.refill_remainder+actor,127,tw(i,0x1e90)):127;}
int tg60_pit_force(TopGearRecomp *i,unsigned actor,int delta){return actor<4&&control_active(i)?force_step(i->timing60.pit_force_remainder+actor,delta,tw(i,0x1e90)):delta;}
unsigned tg60_pit_scroll(TopGearRecomp *i,unsigned actor,unsigned step){return actor<4&&control_active(i)?positive_step(i->timing60.pit_scroll_remainder+actor,step,tw(i,0x1e90)):step;}
int tg60_countdown_step(TopGearRecomp *i,unsigned addr,unsigned channel,unsigned next){
    uint16_t value;unsigned amount;
    if(channel>=3||!control_active(i))return 0;
    amount=positive_step(i->timing60.countdown_remainder+channel,1,tw(i,0x1e90));
    if(!tg_bus_read16(i,addr,&value))return 0;
    value=(uint16_t)(value-amount);if(!tg_bus_write16(i,addr,value))return 0;
    tg_set_nz16(i,value);i->cpu.pc=(uint16_t)next;i->instruction_count++;return 1;
}
void tg60_shadow_lane_limits(TopGearRecomp *i,unsigned *positive,unsigned *negative){
    if(!control_active(i)){*positive=600;*negative=1280;return;}
    *positive=600*tw(i,0x1e90)/3;
    *negative=positive_step(i->timing60.shadow_lane_limit_remainder+cpu_actor(i),1280,tw(i,0x1e90));
}
static int force_step(int *remainder,int delta,unsigned dt){
    int total=delta*(int)dt+*remainder;
    int step=total>=0?total/3:-((-total+2)/3);
    *remainder=total-3*step;return step;
}
int tg60_scale_force(TopGearRecomp *i,unsigned actor,int delta,unsigned elapsed){return tg60_active(i)&&actor<4?force_step(i->timing60.force_remainder+actor,delta,elapsed):delta;}
int tg60_shadow_motor(TopGearRecomp *i,unsigned old_speed,int proposal){
    unsigned dt=tw(i,0x1e90),id=cpu_actor(i);
    if(!tg60_active(i)||i->hdma_enable_mask!=0x7f||i->mod_menu_remodel_active||!dt||dt>255)return proposal;
    return (int16_t)(old_speed+force_step(i->timing60.shadow_force_remainder+id,(int16_t)(proposal-old_speed),dt));
}
static void motor_begin(TopGearRecomp *i,unsigned id){
    if(!tg60_active(i)||i->hdma_enable_mask!=0x7f||i->mod_menu_remodel_active)return;
    i->timing60.motor_initial[id]=tw(i,id?0x1e5c:0x1e5a);i->timing60.motor_pending[id]=1;
}
static void motor_end(TopGearRecomp *i,unsigned id){
    unsigned addr=id?0x1e5c:0x1e5a,dt=tw(i,0x1e90),value;
    if(!tg60_active(i)||!i->timing60.motor_pending[id])return;
    i->timing60.motor_pending[id]=0;if(!dt||dt>255)return;
    value=(uint16_t)(i->timing60.motor_initial[id]+tg60_scale_force(i,id,(int16_t)(tw(i,addr)-i->timing60.motor_initial[id]),dt));
    i->wram[addr]=(uint8_t)value;i->wram[addr+1]=(uint8_t)(value>>8);i->timing60.motor_calls[id]++;
}
/* Human slots 0/1 never use the private-CPU pit-force integrator. Their
   corresponding auxiliary channels carry the fractional coast RPM fade;
   private CPUs exclusively own pit-force channels 2/3. */
static unsigned rpm_fade_step(TopGearRecomp *i,unsigned actor,unsigned amount){return (unsigned)force_step(i->timing60.pit_force_remainder+actor,(int)amount,tw(i,0x1e90));}
/* Independent C shadow computes its own RPM and raw fuel cost. Only its
   time integration changes; it does not receive native fuel/RPM results. */
unsigned tg60_shadow_fuel_cost(TopGearRecomp *i,unsigned cost){
    unsigned id=cpu_actor(i),dt=tw(i,0x1e90),total;
    if(!tg60_active(i)||i->hdma_enable_mask!=0x7f||i->mod_menu_remodel_active||!dt||dt>255)return cost;
    total=cost*dt+i->timing60.shadow_remainder[id];i->timing60.shadow_remainder[id]=total%3;return total/3;
}
static void fuel_operand(TopGearRecomp *i,unsigned actor){
    unsigned dt=tw(i,0x1e90);
    if(!tg60_active(i)||i->hdma_enable_mask!=0x7f||i->mod_menu_remodel_active||!dt||dt>255)return;
    /* The following native EOR/SEC/ADC performs subtraction and sets flags. */
    i->cpu.a=(uint16_t)tg60_fuel_step(i,actor,i->cpu.a,dt);
}
int tg60_original_0175_step(TopGearRecomp *);
int tg_v22_reentry_group_0175_step(TopGearRecomp *i){
    if(!tg60_active(i))return tg60_original_0175_step(i);
    if(tg_generated_context_key(i)==0x0005d5e7u)motor_end(i,0);
    if(tg_generated_context_key(i)==0x0005d65eu)fuel_operand(i,0);
    return tg60_original_0175_step(i);
}
int tg60_original_0177_step(TopGearRecomp *);
int tg_v22_reentry_group_0177_step(TopGearRecomp *i){
    if(!tg60_active(i))return tg60_original_0177_step(i);
    if(tg_generated_context_key(i)==0x0005de49u)motor_end(i,1);
    if(tg_generated_context_key(i)==0x0005dec4u)fuel_operand(i,1);
    return tg60_original_0177_step(i);
}
int tg60_original_017b_step(TopGearRecomp *);
int tg_v22_reentry_group_017B_step(TopGearRecomp *i){
    if(!tg60_active(i))return tg60_original_017b_step(i);
    if(tg_generated_context_key(i)==0x0005ed92u)motor_begin(i,cpu_actor(i));
    if(tg_generated_context_key(i)==0x0005ef8cu)motor_end(i,cpu_actor(i));
    if(tg_generated_context_key(i)==0x0005efdau)fuel_operand(i,cpu_actor(i));
    return tg60_original_017b_step(i);
}
int tg60_original_0174_step(TopGearRecomp *);
int tg_v22_reentry_group_0174_step(TopGearRecomp *i){
    if(!tg60_active(i))return tg60_original_0174_step(i);
    if(control_active(i)&&tg_generated_context_key(i)==0x0005d31bu){tg_sbc16(i,(uint16_t)(48*tw(i,0x1e90)/3));i->cpu.pc=0xd31e;i->instruction_count++;return 1;}
    if(control_active(i)&&tg_generated_context_key(i)==0x0005d33cu){tg_sbc16(i,(uint16_t)rpm_fade_step(i,0,256));i->cpu.pc=0xd33f;i->instruction_count++;return 1;}
    if(tg_generated_context_key(i)==0x0005d30fu)motor_begin(i,0);
    return tg60_original_0174_step(i);
}
int tg60_original_0176_step(TopGearRecomp *);
int tg_v22_reentry_group_0176_step(TopGearRecomp *i){
    if(!tg60_active(i))return tg60_original_0176_step(i);
    uint32_t key=tg_generated_context_key(i);
    if(control_active(i)&&key==0x0005db98u){tg_sbc16(i,(uint16_t)(48*tw(i,0x1e90)/3));i->cpu.pc=0xdb9b;i->instruction_count++;return 1;}
    if(control_active(i)&&key==0x0005dbb9u){tg_sbc16(i,(uint16_t)rpm_fade_step(i,1,256));i->cpu.pc=0xdbbc;i->instruction_count++;return 1;}
    if(control_active(i)&&(key==0x0005d978u||key==0x0005d983u)){
        unsigned old=recovery_operand(i,0,0x1eec);int ok=tg60_original_0176_step(i);
        i->wram[0x1eec]=(uint8_t)old;i->wram[0x1eed]=(uint8_t)(old>>8);return ok;
    }
    if(tg_generated_context_key(i)==0x0005db5fu)motor_begin(i,1);
    return tg60_original_0176_step(i);
}
int tg60_original_0178_step(TopGearRecomp *);
int tg_v22_reentry_group_0178_step(TopGearRecomp *i){
    if(!tg60_active(i))return tg60_original_0178_step(i);
    uint32_t key=tg_generated_context_key(i);
    if(control_active(i)&&(key==0x0005e1e1u||key==0x0005e1ecu)){
        unsigned old=recovery_operand(i,1,0x1eee);int ok=tg60_original_0178_step(i);
        i->wram[0x1eee]=(uint8_t)old;i->wram[0x1eef]=(uint8_t)(old>>8);return ok;
    }
    return tg60_original_0178_step(i);
}
int tg60_original_017c_step(TopGearRecomp *);
int tg_v22_reentry_group_017C_step(TopGearRecomp *i){
    if(!tg60_active(i))return tg60_original_017c_step(i);
    uint32_t key=tg_generated_context_key(i);
    if(control_active(i)){
        unsigned id=cpu_actor(i),operand=0,next=0,operation=0;
        if(key==0x0005f2ebu){i->timing60.lane_positive[id]=600*tw(i,0x1e90)/3;i->timing60.lane_negative[id]=positive_step(i->timing60.lane_limit_remainder+id,1280,tw(i,0x1e90));}
        switch(key){
        case 0x0005f2f3u:operand=i->timing60.lane_positive[id]+1;next=0xf2f6;operation=1;break;
        case 0x0005f303u:operand=(uint16_t)(-1-(int)i->timing60.lane_negative[id]);next=0xf306;operation=1;break;
        case 0x0005f2fcu:operand=i->timing60.lane_positive[id];next=0xf2ff;operation=2;break;
        case 0x0005f30cu:operand=i->timing60.lane_negative[id];next=0xf30f;operation=3;break;
        case 0x0005f319u:operand=i->timing60.lane_positive[id]+1;next=0xf31c;operation=1;break;
        case 0x0005f329u:operand=(uint16_t)(-1-(int)i->timing60.lane_negative[id]);next=0xf32c;operation=1;break;
        case 0x0005f322u:operand=i->timing60.lane_positive[id];next=0xf325;operation=3;break;
        case 0x0005f332u:operand=i->timing60.lane_negative[id];next=0xf335;operation=2;break;
        }
        if(operation){
            if(operation==1)tg_compare16(i,i->cpu.a,(uint16_t)operand);
            else if(operation==2)tg_adc16(i,(uint16_t)operand);else tg_sbc16(i,(uint16_t)operand);
            i->cpu.pc=(uint16_t)next;i->instruction_count++;return 1;
        }
        if(key==0x0005f3a8u||key==0x0005f3b9u){
            unsigned amount=positive_step(i->timing60.recovery_remainder+id,640+tw(i,0x1eee),tw(i,0x1e90));
            if(key==0x0005f3a8u){tg_sbc16(i,(uint16_t)amount);i->cpu.pc=0xf3ab;}
            else {tg_adc16(i,(uint16_t)amount);i->cpu.pc=0xf3bc;}
            i->instruction_count++;return 1;
        }
        if(key==0x0005f3aeu||key==0x0005f3bfu){
            unsigned old=tw(i,0x1eee);int ok;
            i->wram[0x1eee]=i->wram[0x1eef]=0;ok=tg60_original_017c_step(i);
            i->wram[0x1eee]=(uint8_t)old;i->wram[0x1eef]=(uint8_t)(old>>8);return ok;
        }
    }
    return tg60_original_017c_step(i);
}
extern int tg_rivals_promoted(const TopGearRecomp *i,unsigned off);
static unsigned traffic_id(const TopGearRecomp *i,unsigned off){
    if(off>=360||off%18||off==tw(i,0x204)||off==tw(i,0x206)||tg_rivals_promoted(i,off))return 20;
    return tw(i,0x212+off)&31u;
}
static int traffic_active(const TopGearRecomp *i){return tg60_active(i)&&i->hdma_enable_mask==0x7f&&!i->mod_menu_remodel_active&&!i->mod_time_trial_active&&tw(i,0x1e90)>0&&tw(i,0x1e90)<=255;}
/* Change only the elapsed-time operand. The original ADC and subsequent
   bound/reflection decisions retain their carry/overflow/negative flags. */
static void traffic_operand(TopGearRecomp *i,unsigned addr,int *remainder){
    unsigned value=(uint16_t)force_step(remainder,(int16_t)tw(i,addr),tw(i,0x1e90));
    i->wram[addr]=(uint8_t)value;i->wram[addr+1]=(uint8_t)(value>>8);
}
int tg60_original_0028_step(TopGearRecomp *);
int tg_v22_reentry_group_0028_step(TopGearRecomp *i){
    if(!tg60_active(i))return tg60_original_0028_step(i);
    uint32_t key=tg_generated_context_key(i);unsigned off=i->cpu.x>=18?i->cpu.x-18:360,id=traffic_id(i,off);
    if(traffic_active(i)&&id<20){
        if(key==0x0000a181u){
            unsigned addr=0x21e+off,old=tw(i,addr);int ok;
            traffic_operand(i,addr,i->timing60.traffic_speed_remainder+id);ok=tg60_original_0028_step(i);
            i->wram[addr]=(uint8_t)old;i->wram[addr+1]=(uint8_t)(old>>8);i->timing60.traffic_speed_calls[id]++;return ok;
        }
        if(key==0x0000a185u){
            unsigned addr=0x220+off,total=i->timing60.traffic_timer_remainder[id]+tw(i,0x1e90);uint16_t value;
            if(!tg_bus_read16(i,addr,&value))return 0;
            value=(uint16_t)(value-total/3);i->timing60.traffic_timer_remainder[id]=total%3;
            if(!tg_bus_write16(i,addr,value))return 0;
            tg_set_nz16(i,value);i->cpu.pc=0xa187;i->instruction_count++;return 1;
        }
    }
    return tg60_original_0028_step(i);
}
int tg60_original_002b_step(TopGearRecomp *);
int tg_v22_reentry_group_002B_step(TopGearRecomp *i){
    if(!tg60_active(i))return tg60_original_002b_step(i);
    uint32_t key=tg_generated_context_key(i);unsigned id=traffic_id(i,i->cpu.x);
    if(traffic_active(i)&&id<20&&(key==0x0000aca5u||key==0x0000ae22u)){
        unsigned addr=0x216+i->cpu.x,old=tw(i,addr);int ok;
        traffic_operand(i,addr,i->timing60.traffic_lane_remainder+id);ok=tg60_original_002b_step(i);
        i->wram[addr]=(uint8_t)old;i->wram[addr+1]=(uint8_t)(old>>8);i->timing60.traffic_lane_calls[id]++;return ok;
    }
    return tg60_original_002b_step(i);
}
int tg60_original_0024_step(TopGearRecomp *);
int tg_v22_reentry_group_0024_step(TopGearRecomp *i){
    if(!tg60_active(i))return tg60_original_0024_step(i);
    uint32_t key=tg_generated_context_key(i);
    if(control_active(i)&&(key==0x00009176u||key==0x000092cfu)){
        unsigned actor=key==0x00009176u?0:1;
        tg_adc16(i,(uint16_t)tg60_refill_step(i,actor));i->cpu.pc=(uint16_t)(actor?0x92d2:0x9179);i->instruction_count++;return 1;
    }
    return tg60_original_0024_step(i);
}
int tg60_original_002c_step(TopGearRecomp *);
int tg_v22_reentry_group_002C_step(TopGearRecomp *i){
    if(!tg60_active(i))return tg60_original_002c_step(i);
    uint32_t key=tg_generated_context_key(i);
    if(control_active(i)&&key==0x0000b3cau)return tg60_countdown_step(i,0x1efb,1,0xb3cd);
    if(control_active(i)&&key==0x0000b3eeu)return tg60_countdown_step(i,0x1efc,2,0xb3f1);
    return tg60_original_002c_step(i);
}
