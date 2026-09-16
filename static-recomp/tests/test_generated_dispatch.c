#include "topgear_internal.h"

#include <stdlib.h>
#include <string.h>

extern int tg_v22_wram_epoch_semantic_step(struct TopGearRecomp *);
extern int tg_v22_interrupt_semantic_step(struct TopGearRecomp *);
extern unsigned tg_v23_nominal_processor_cycles(const struct TopGearRecomp *);

int main(void) {
    TopGearRecomp *core = (TopGearRecomp *)calloc(1u, sizeof(*core));
    int result;
    if (!core) return 1;
    if (tg_v22_generated_static_context_count() == 0u ||
        tg_v22_generated_static_address_count() == 0u)
        return 2;
    /* The native STA at 287A patches the SBC immediate, never its opcode.
       Verify every operand and retain rejection of an unexpected opcode. */
    {
        unsigned operand;
        for (operand=0u;operand<256u;operand++) {
            core->cpu.pbr=0x7eu;core->cpu.pc=0x2880u;
            core->cpu.e=0u;core->cpu.p=TG_P_M|TG_P_C;core->cpu.a=0xA580u;
            core->wram[0x2880u]=0xE9u;core->wram[0x2881u]=(uint8_t)operand;
            if (!tg_v22_wram_epoch_semantic_step(core)||
                core->cpu.a!=(uint16_t)(0xA500u|(uint8_t)(0x80u-operand))||
                ((core->cpu.p&TG_P_C)!=0u)!=(operand<=0x80u)) return 4;
        }
        core->cpu.pc=0x2880u;core->wram[0x2880u]=0xEAu;
        if(tg_v22_wram_epoch_semantic_step(core)!=0||!core->failed)return 5;
        memset(core,0,sizeof(*core));
    }
    {
        unsigned steps=0u;
        core->cpu.pc=0xB511u;core->wram[0xBAu]=0x34u;core->wram[0xBBu]=0x12u;
        while(core->cpu.pc!=0xBE78u&&steps++<20u){
            if(!tg_v23_nominal_processor_cycles(core)||
               !tg_v22_interrupt_semantic_step(core))return 6;
        }
        if(steps!=20u||core->cpu.pc!=0xBE78u||core->wram[0xAu]!=0xD1u||
           core->wram[0xBu]!=0xB6u||(core->cpu.p&TG_P_M))return 7;
        memset(core,0,sizeof(*core));
    }
    core->cpu.pbr = 0x7fu;
    core->cpu.pc = 0u;
    core->cpu.e = 1u;
    core->cpu.p = TG_P_M | TG_P_X;
    result = tg_v22_generated_static_step(core);
    if (result != 0 || !core->failed || !core->frontier.reached)
        return 3;
    free(core);
    return 0;
}
