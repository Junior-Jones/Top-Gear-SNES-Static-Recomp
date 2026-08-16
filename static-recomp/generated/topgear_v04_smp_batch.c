/* Generated from the exact ROM-derived ARAM image and documented
   SPC700/S-SMP/S-DSP semantics by tools/smp/generate_v04_smp_batch.py.
   No emulator trace or oracle state was used. */
#include "topgear_internal.h"
#include "topgear_v04_smp_batch.h"

unsigned tg_v04_generated_smp_context_count(void){return 95u;}

int tg_v04_generated_smp_step(struct TopGearRecomp *instance){
    uint16_t address=0u;
    uint8_t byte=0u;
    uint8_t other=0u;
    if(!instance)return 0;
    switch(instance->smp.pc){
    case 0x0800u: /* 20  CLRP; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0800u]!=0x20u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0800");
        tg_smp_instruction_begin(instance,2u);
        tg_smp_set_flag(instance,TG_SMP_P_P,0);
        instance->smp.pc=0x0801u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0801u: /* CD CF  MOV X,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0801u]!=0xCDu||instance->aram[0x0802u]!=0xCFu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0801");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.x=0xCFu;
        tg_smp_set_nz(instance,instance->smp.x);
        instance->smp.pc=0x0803u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0803u: /* BD  MOV SP,X; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0803u]!=0xBDu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0803");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.sp=instance->smp.x;
        instance->smp.pc=0x0804u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0804u: /* E8 00  MOV A,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0804u]!=0xE8u||instance->aram[0x0805u]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0804");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.a=0x00u;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0806u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0806u: /* 5D  MOV X,A; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0806u]!=0x5Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0806");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.x=instance->smp.a;
        tg_smp_set_nz(instance,instance->smp.x);
        instance->smp.pc=0x0807u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0807u: /* AF  MOV (X)+,A; reference visits 240 */
        instance->smp_current_instruction_cycles=4u;
        if(instance->aram[0x0807u]!=0xAFu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0807");
        tg_smp_instruction_begin(instance,4u);
        address=(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|instance->smp.x);
        if(!tg_smp_write8(instance,address,instance->smp.a))return 0;
        instance->smp.x=(uint8_t)(instance->smp.x+1u);
        instance->smp.pc=0x0808u;
        if(!tg_smp_instruction_finish(instance,4u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0808u: /* C8 F0  CMP X,#imm; reference visits 240 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0808u]!=0xC8u||instance->aram[0x0809u]!=0xF0u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0808");
        tg_smp_instruction_begin(instance,2u);
        tg_smp_compare(instance,instance->smp.x,0xF0u);
        instance->smp.pc=0x080Au;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x080Au: /* D0 FB  BNE rel; reference visits 240 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x080Au]!=0xD0u||instance->aram[0x080Bu]!=0xFBu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:080A");
        tg_smp_instruction_begin(instance,2u);
        if(!tg_smp_flag(instance,TG_SMP_P_Z)){
            instance->smp.pc=0x0807u;
            if(!tg_smp_instruction_finish(instance,4u))return 0;
        }else{
            instance->smp.pc=0x080Cu;
            if(!tg_smp_instruction_finish(instance,2u))return 0;
        }
        instance->smp.instruction_count++;
        return 1;
    case 0x080Cu: /* 5D  MOV X,A; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x080Cu]!=0x5Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:080C");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.x=instance->smp.a;
        tg_smp_set_nz(instance,instance->smp.x);
        instance->smp.pc=0x080Du;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x080Du: /* D5 00 01  MOV abs+X,A; reference visits 256 */
        instance->smp_current_instruction_cycles=6u;
        if(instance->aram[0x080Du]!=0xD5u||instance->aram[0x080Eu]!=0x00u||instance->aram[0x080Fu]!=0x01u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:080D");
        tg_smp_instruction_begin(instance,6u);
        address=(uint16_t)(0x0100u+instance->smp.x);
        if(!tg_smp_write8_at_cycle(instance,address,instance->smp.a,5u))return 0;
        instance->smp.pc=0x0810u;
        if(!tg_smp_instruction_finish(instance,6u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0810u: /* D5 00 02  MOV abs+X,A; reference visits 256 */
        instance->smp_current_instruction_cycles=6u;
        if(instance->aram[0x0810u]!=0xD5u||instance->aram[0x0811u]!=0x00u||instance->aram[0x0812u]!=0x02u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0810");
        tg_smp_instruction_begin(instance,6u);
        address=(uint16_t)(0x0200u+instance->smp.x);
        if(!tg_smp_write8_at_cycle(instance,address,instance->smp.a,5u))return 0;
        instance->smp.pc=0x0813u;
        if(!tg_smp_instruction_finish(instance,6u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0813u: /* D5 00 03  MOV abs+X,A; reference visits 256 */
        instance->smp_current_instruction_cycles=6u;
        if(instance->aram[0x0813u]!=0xD5u||instance->aram[0x0814u]!=0x00u||instance->aram[0x0815u]!=0x03u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0813");
        tg_smp_instruction_begin(instance,6u);
        address=(uint16_t)(0x0300u+instance->smp.x);
        if(!tg_smp_write8_at_cycle(instance,address,instance->smp.a,5u))return 0;
        instance->smp.pc=0x0816u;
        if(!tg_smp_instruction_finish(instance,6u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0816u: /* D5 00 04  MOV abs+X,A; reference visits 256 */
        instance->smp_current_instruction_cycles=6u;
        if(instance->aram[0x0816u]!=0xD5u||instance->aram[0x0817u]!=0x00u||instance->aram[0x0818u]!=0x04u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0816");
        tg_smp_instruction_begin(instance,6u);
        address=(uint16_t)(0x0400u+instance->smp.x);
        if(!tg_smp_write8_at_cycle(instance,address,instance->smp.a,5u))return 0;
        instance->smp.pc=0x0819u;
        if(!tg_smp_instruction_finish(instance,6u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0819u: /* D5 00 05  MOV abs+X,A; reference visits 256 */
        instance->smp_current_instruction_cycles=6u;
        if(instance->aram[0x0819u]!=0xD5u||instance->aram[0x081Au]!=0x00u||instance->aram[0x081Bu]!=0x05u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0819");
        tg_smp_instruction_begin(instance,6u);
        address=(uint16_t)(0x0500u+instance->smp.x);
        if(!tg_smp_write8_at_cycle(instance,address,instance->smp.a,5u))return 0;
        instance->smp.pc=0x081Cu;
        if(!tg_smp_instruction_finish(instance,6u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x081Cu: /* D5 00 06  MOV abs+X,A; reference visits 256 */
        instance->smp_current_instruction_cycles=6u;
        if(instance->aram[0x081Cu]!=0xD5u||instance->aram[0x081Du]!=0x00u||instance->aram[0x081Eu]!=0x06u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:081C");
        tg_smp_instruction_begin(instance,6u);
        address=(uint16_t)(0x0600u+instance->smp.x);
        if(!tg_smp_write8_at_cycle(instance,address,instance->smp.a,5u))return 0;
        instance->smp.pc=0x081Fu;
        if(!tg_smp_instruction_finish(instance,6u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x081Fu: /* D5 00 07  MOV abs+X,A; reference visits 256 */
        instance->smp_current_instruction_cycles=6u;
        if(instance->aram[0x081Fu]!=0xD5u||instance->aram[0x0820u]!=0x00u||instance->aram[0x0821u]!=0x07u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:081F");
        tg_smp_instruction_begin(instance,6u);
        address=(uint16_t)(0x0700u+instance->smp.x);
        if(!tg_smp_write8_at_cycle(instance,address,instance->smp.a,5u))return 0;
        instance->smp.pc=0x0822u;
        if(!tg_smp_instruction_finish(instance,6u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0822u: /* 3D  INC X; reference visits 256 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0822u]!=0x3Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0822");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.x=(uint8_t)(instance->smp.x+1u);
        tg_smp_set_nz(instance,instance->smp.x);
        instance->smp.pc=0x0823u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0823u: /* D0 E8  BNE rel; reference visits 256 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0823u]!=0xD0u||instance->aram[0x0824u]!=0xE8u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0823");
        tg_smp_instruction_begin(instance,2u);
        if(!tg_smp_flag(instance,TG_SMP_P_Z)){
            instance->smp.pc=0x080Du;
            if(!tg_smp_instruction_finish(instance,4u))return 0;
        }else{
            instance->smp.pc=0x0825u;
            if(!tg_smp_instruction_finish(instance,2u))return 0;
        }
        instance->smp.instruction_count++;
        return 1;
    case 0x0825u: /* BC  INC A; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0825u]!=0xBCu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0825");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.a=(uint8_t)(instance->smp.a+1u);
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0826u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0826u: /* 3F A5 0D  CALL abs; reference visits 1 */
        instance->smp_current_instruction_cycles=8u;
        if(instance->aram[0x0826u]!=0x3Fu||instance->aram[0x0827u]!=0xA5u||instance->aram[0x0828u]!=0x0Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0826");
        tg_smp_instruction_begin(instance,8u);
        if(!tg_smp_push8(instance,0x08u))return 0;
        if(!tg_smp_push8(instance,0x29u))return 0;
        instance->smp.pc=0x0DA5u;
        if(!tg_smp_instruction_finish(instance,8u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0829u: /* A2 33  SET1 dp.5; reference visits 1 */
        instance->smp_current_instruction_cycles=4u;
        if(instance->aram[0x0829u]!=0xA2u||instance->aram[0x082Au]!=0x33u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0829");
        tg_smp_instruction_begin(instance,4u);
        address=(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x33u);
        if(!tg_smp_read8(instance,address,&byte))return 0;
        byte=(uint8_t)(byte|0x20u);
        if(!tg_smp_write8(instance,address,byte))return 0;
        instance->smp.pc=0x082Bu;
        if(!tg_smp_instruction_finish(instance,4u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x082Bu: /* E8 60  MOV A,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x082Bu]!=0xE8u||instance->aram[0x082Cu]!=0x60u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:082B");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.a=0x60u;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x082Du;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x082Du: /* 8D 0C  MOV Y,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x082Du]!=0x8Du||instance->aram[0x082Eu]!=0x0Cu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:082D");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.y=0x0Cu;
        tg_smp_set_nz(instance,instance->smp.y);
        instance->smp.pc=0x082Fu;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x082Fu: /* 3F E5 09  CALL abs; reference visits 1 */
        instance->smp_current_instruction_cycles=8u;
        if(instance->aram[0x082Fu]!=0x3Fu||instance->aram[0x0830u]!=0xE5u||instance->aram[0x0831u]!=0x09u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:082F");
        tg_smp_instruction_begin(instance,8u);
        if(!tg_smp_push8(instance,0x08u))return 0;
        if(!tg_smp_push8(instance,0x32u))return 0;
        instance->smp.pc=0x09E5u;
        if(!tg_smp_instruction_finish(instance,8u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0832u: /* 8D 1C  MOV Y,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0832u]!=0x8Du||instance->aram[0x0833u]!=0x1Cu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0832");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.y=0x1Cu;
        tg_smp_set_nz(instance,instance->smp.y);
        instance->smp.pc=0x0834u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0834u: /* 3F E5 09  CALL abs; reference visits 1 */
        instance->smp_current_instruction_cycles=8u;
        if(instance->aram[0x0834u]!=0x3Fu||instance->aram[0x0835u]!=0xE5u||instance->aram[0x0836u]!=0x09u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0834");
        tg_smp_instruction_begin(instance,8u);
        if(!tg_smp_push8(instance,0x08u))return 0;
        if(!tg_smp_push8(instance,0x37u))return 0;
        instance->smp.pc=0x09E5u;
        if(!tg_smp_instruction_finish(instance,8u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0837u: /* E8 8A  MOV A,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0837u]!=0xE8u||instance->aram[0x0838u]!=0x8Au)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0837");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.a=0x8Au;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0839u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0839u: /* 8D 5D  MOV Y,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0839u]!=0x8Du||instance->aram[0x083Au]!=0x5Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0839");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.y=0x5Du;
        tg_smp_set_nz(instance,instance->smp.y);
        instance->smp.pc=0x083Bu;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x083Bu: /* 3F E5 09  CALL abs; reference visits 1 */
        instance->smp_current_instruction_cycles=8u;
        if(instance->aram[0x083Bu]!=0x3Fu||instance->aram[0x083Cu]!=0xE5u||instance->aram[0x083Du]!=0x09u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:083B");
        tg_smp_instruction_begin(instance,8u);
        if(!tg_smp_push8(instance,0x08u))return 0;
        if(!tg_smp_push8(instance,0x3Eu))return 0;
        instance->smp.pc=0x09E5u;
        if(!tg_smp_instruction_finish(instance,8u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x083Eu: /* E8 90  MOV A,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x083Eu]!=0xE8u||instance->aram[0x083Fu]!=0x90u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:083E");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.a=0x90u;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0840u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0840u: /* C5 F1 00  MOV abs,A; reference visits 1 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x0840u]!=0xC5u||instance->aram[0x0841u]!=0xF1u||instance->aram[0x0842u]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0840");
        tg_smp_instruction_begin(instance,5u);
        if(!tg_smp_write8_at_cycle(instance,0x00F1u,instance->smp.a,4u))return 0;
        instance->smp.pc=0x0843u;
        if(!tg_smp_instruction_finish(instance,5u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0843u: /* E8 10  MOV A,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0843u]!=0xE8u||instance->aram[0x0844u]!=0x10u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0843");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.a=0x10u;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0845u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0845u: /* C5 FA 00  MOV abs,A; reference visits 1 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x0845u]!=0xC5u||instance->aram[0x0846u]!=0xFAu||instance->aram[0x0847u]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0845");
        tg_smp_instruction_begin(instance,5u);
        if(!tg_smp_write8_at_cycle(instance,0x00FAu,instance->smp.a,4u))return 0;
        instance->smp.pc=0x0848u;
        if(!tg_smp_instruction_finish(instance,5u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0848u: /* C4 3D  MOV dp,A; reference visits 1 */
        instance->smp_current_instruction_cycles=4u;
        if(instance->aram[0x0848u]!=0xC4u||instance->aram[0x0849u]!=0x3Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0848");
        tg_smp_instruction_begin(instance,4u);
        if(!tg_smp_write8_at_cycle(instance,(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x3Du),instance->smp.a,3u))return 0;
        instance->smp.pc=0x084Au;
        if(!tg_smp_instruction_finish(instance,4u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x084Au: /* E8 81  MOV A,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x084Au]!=0xE8u||instance->aram[0x084Bu]!=0x81u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:084A");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.a=0x81u;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x084Cu;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x084Cu: /* C5 F1 00  MOV abs,A; reference visits 1 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x084Cu]!=0xC5u||instance->aram[0x084Du]!=0xF1u||instance->aram[0x084Eu]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:084C");
        tg_smp_instruction_begin(instance,5u);
        if(!tg_smp_write8_at_cycle(instance,0x00F1u,instance->smp.a,4u))return 0;
        instance->smp.pc=0x084Fu;
        if(!tg_smp_instruction_finish(instance,5u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x084Fu: /* 8D 0A  MOV Y,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x084Fu]!=0x8Du||instance->aram[0x0850u]!=0x0Au)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:084F");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.y=0x0Au;
        tg_smp_set_nz(instance,instance->smp.y);
        instance->smp.pc=0x0851u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0851u: /* AD 05  CMP Y,#imm; reference visits 10 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0851u]!=0xADu||instance->aram[0x0852u]!=0x05u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0851");
        tg_smp_instruction_begin(instance,2u);
        tg_smp_compare(instance,instance->smp.y,0x05u);
        instance->smp.pc=0x0853u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0853u: /* F0 07  BEQ rel; reference visits 10 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0853u]!=0xF0u||instance->aram[0x0854u]!=0x07u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0853");
        tg_smp_instruction_begin(instance,2u);
        if(tg_smp_flag(instance,TG_SMP_P_Z)){
            instance->smp.pc=0x085Cu;
            if(!tg_smp_instruction_finish(instance,4u))return 0;
        }else{
            instance->smp.pc=0x0855u;
            if(!tg_smp_instruction_finish(instance,2u))return 0;
        }
        instance->smp.instruction_count++;
        return 1;
    case 0x0855u: /* B0 08  BCS rel; reference visits 9 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0855u]!=0xB0u||instance->aram[0x0856u]!=0x08u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0855");
        tg_smp_instruction_begin(instance,2u);
        if(tg_smp_flag(instance,TG_SMP_P_C)){
            instance->smp.pc=0x085Fu;
            if(!tg_smp_instruction_finish(instance,4u))return 0;
        }else{
            instance->smp.pc=0x0857u;
            if(!tg_smp_instruction_finish(instance,2u))return 0;
        }
        instance->smp.instruction_count++;
        return 1;
    case 0x0857u: /* 69 38 37  CMP dp,dp; reference visits 4 */
        instance->smp_current_instruction_cycles=6u;
        if(instance->aram[0x0857u]!=0x69u||instance->aram[0x0858u]!=0x38u||instance->aram[0x0859u]!=0x37u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0857");
        tg_smp_instruction_begin(instance,6u);
        if(!tg_smp_read8_at_cycle(instance,(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x38u),&byte,2u))return 0;
        if(!tg_smp_read8(instance,(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x37u),&other))return 0;
        tg_smp_compare(instance,other,byte);
        instance->smp.pc=0x085Au;
        if(!tg_smp_instruction_finish(instance,6u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x085Au: /* D0 11  BNE rel; reference visits 4 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x085Au]!=0xD0u||instance->aram[0x085Bu]!=0x11u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:085A");
        tg_smp_instruction_begin(instance,2u);
        if(!tg_smp_flag(instance,TG_SMP_P_Z)){
            instance->smp.pc=0x086Du;
            if(!tg_smp_instruction_finish(instance,4u))return 0;
        }else{
            instance->smp.pc=0x085Cu;
            if(!tg_smp_instruction_finish(instance,2u))return 0;
        }
        instance->smp.instruction_count++;
        return 1;
    case 0x085Cu: /* E3 37 0E  BBS dp.7,rel; reference visits 1 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x085Cu]!=0xE3u||instance->aram[0x085Du]!=0x37u||instance->aram[0x085Eu]!=0x0Eu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:085C");
        tg_smp_instruction_begin(instance,5u);
        if(!tg_smp_read8_at_cycle(instance,(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x37u),&byte,2u))return 0;
        if((byte&0x80u)!=0u){
            instance->smp.pc=0x086Du;
            if(!tg_smp_instruction_finish(instance,7u))return 0;
        }else{
            instance->smp.pc=0x085Fu;
            if(!tg_smp_instruction_finish(instance,5u))return 0;
        }
        instance->smp.instruction_count++;
        return 1;
    case 0x085Fu: /* F6 C4 08  MOV A,abs+Y; reference visits 5 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x085Fu]!=0xF6u||instance->aram[0x0860u]!=0xC4u||instance->aram[0x0861u]!=0x08u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:085F");
        tg_smp_instruction_begin(instance,5u);
        address=(uint16_t)(0x08C4u+instance->smp.y);
        if(!tg_smp_read8_at_cycle(instance,address,&instance->smp.a,3u))return 0;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0862u;
        if(!tg_smp_instruction_finish(instance,5u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0862u: /* C5 F2 00  MOV abs,A; reference visits 5 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x0862u]!=0xC5u||instance->aram[0x0863u]!=0xF2u||instance->aram[0x0864u]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0862");
        tg_smp_instruction_begin(instance,5u);
        if(!tg_smp_write8_at_cycle(instance,0x00F2u,instance->smp.a,4u))return 0;
        instance->smp.pc=0x0865u;
        if(!tg_smp_instruction_finish(instance,5u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0865u: /* F6 CE 08  MOV A,abs+Y; reference visits 5 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x0865u]!=0xF6u||instance->aram[0x0866u]!=0xCEu||instance->aram[0x0867u]!=0x08u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0865");
        tg_smp_instruction_begin(instance,5u);
        address=(uint16_t)(0x08CEu+instance->smp.y);
        if(!tg_smp_read8_at_cycle(instance,address,&instance->smp.a,3u))return 0;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0868u;
        if(!tg_smp_instruction_finish(instance,5u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0868u: /* 5D  MOV X,A; reference visits 5 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0868u]!=0x5Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0868");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.x=instance->smp.a;
        tg_smp_set_nz(instance,instance->smp.x);
        instance->smp.pc=0x0869u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0869u: /* E6  MOV A,(X); reference visits 5 */
        instance->smp_current_instruction_cycles=3u;
        if(instance->aram[0x0869u]!=0xE6u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0869");
        tg_smp_instruction_begin(instance,3u);
        address=(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|instance->smp.x);
        if(!tg_smp_read8_at_cycle(instance,address,&instance->smp.a,2u))return 0;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x086Au;
        if(!tg_smp_instruction_finish(instance,3u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x086Au: /* C5 F3 00  MOV abs,A; reference visits 5 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x086Au]!=0xC5u||instance->aram[0x086Bu]!=0xF3u||instance->aram[0x086Cu]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:086A");
        tg_smp_instruction_begin(instance,5u);
        if(!tg_smp_write8_at_cycle(instance,0x00F3u,instance->smp.a,4u))return 0;
        instance->smp.pc=0x086Du;
        if(!tg_smp_instruction_finish(instance,5u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x086Du: /* FE E2  DBNZ Y,rel; reference visits 10 */
        instance->smp_current_instruction_cycles=4u;
        if(instance->aram[0x086Du]!=0xFEu||instance->aram[0x086Eu]!=0xE2u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:086D");
        tg_smp_instruction_begin(instance,4u);
        instance->smp.y=(uint8_t)(instance->smp.y-1u);
        if(instance->smp.y!=0u){
            instance->smp.pc=0x0851u;
            if(!tg_smp_instruction_finish(instance,6u))return 0;
        }else{
            instance->smp.pc=0x086Fu;
            if(!tg_smp_instruction_finish(instance,4u))return 0;
        }
        instance->smp.instruction_count++;
        return 1;
    case 0x086Fu: /* CB 2F  MOV dp,Y; reference visits 1 */
        instance->smp_current_instruction_cycles=4u;
        if(instance->aram[0x086Fu]!=0xCBu||instance->aram[0x0870u]!=0x2Fu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:086F");
        tg_smp_instruction_begin(instance,4u);
        if(!tg_smp_write8_at_cycle(instance,(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x2Fu),instance->smp.y,3u))return 0;
        instance->smp.pc=0x0871u;
        if(!tg_smp_instruction_finish(instance,4u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0871u: /* CB 30  MOV dp,Y; reference visits 1 */
        instance->smp_current_instruction_cycles=4u;
        if(instance->aram[0x0871u]!=0xCBu||instance->aram[0x0872u]!=0x30u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0871");
        tg_smp_instruction_begin(instance,4u);
        if(!tg_smp_write8_at_cycle(instance,(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x30u),instance->smp.y,3u))return 0;
        instance->smp.pc=0x0873u;
        if(!tg_smp_instruction_finish(instance,4u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0873u: /* E4 18  MOV A,dp; reference visits 1 */
        instance->smp_current_instruction_cycles=3u;
        if(instance->aram[0x0873u]!=0xE4u||instance->aram[0x0874u]!=0x18u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0873");
        tg_smp_instruction_begin(instance,3u);
        if(!tg_smp_read8_at_cycle(instance,(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x18u),&instance->smp.a,2u))return 0;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0875u;
        if(!tg_smp_instruction_finish(instance,3u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0875u: /* 44 19  EOR A,dp; reference visits 1 */
        instance->smp_current_instruction_cycles=3u;
        if(instance->aram[0x0875u]!=0x44u||instance->aram[0x0876u]!=0x19u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0875");
        tg_smp_instruction_begin(instance,3u);
        if(!tg_smp_read8_at_cycle(instance,(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x19u),&byte,2u))return 0;
        instance->smp.a=(uint8_t)(instance->smp.a^byte);
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0877u;
        if(!tg_smp_instruction_finish(instance,3u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0877u: /* 5C  LSR A; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0877u]!=0x5Cu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0877");
        tg_smp_instruction_begin(instance,2u);
        tg_smp_set_flag(instance,TG_SMP_P_C,(instance->smp.a&1u)!=0u);
        instance->smp.a=(uint8_t)(instance->smp.a>>1);
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0878u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0878u: /* 5C  LSR A; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0878u]!=0x5Cu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0878");
        tg_smp_instruction_begin(instance,2u);
        tg_smp_set_flag(instance,TG_SMP_P_C,(instance->smp.a&1u)!=0u);
        instance->smp.a=(uint8_t)(instance->smp.a>>1);
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0879u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0879u: /* ED  NOTC; reference visits 1 */
        instance->smp_current_instruction_cycles=3u;
        if(instance->aram[0x0879u]!=0xEDu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0879");
        tg_smp_instruction_begin(instance,3u);
        tg_smp_set_flag(instance,TG_SMP_P_C,!tg_smp_flag(instance,TG_SMP_P_C));
        instance->smp.pc=0x087Au;
        if(!tg_smp_instruction_finish(instance,3u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x087Au: /* 6B 18  ROR dp; reference visits 1 */
        instance->smp_current_instruction_cycles=4u;
        if(instance->aram[0x087Au]!=0x6Bu||instance->aram[0x087Bu]!=0x18u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:087A");
        tg_smp_instruction_begin(instance,4u);
        address=(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x18u);
        if(!tg_smp_read8(instance,address,&byte))return 0;
        other=(uint8_t)(tg_smp_flag(instance,TG_SMP_P_C)?1u:0u);
        tg_smp_set_flag(instance,TG_SMP_P_C,(byte&1u)!=0u);
        byte=(uint8_t)((byte>>1)|(other<<7));
        if(!tg_smp_write8(instance,address,byte))return 0;
        tg_smp_set_nz(instance,byte);
        instance->smp.pc=0x087Cu;
        if(!tg_smp_instruction_finish(instance,4u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x087Cu: /* 6B 19  ROR dp; reference visits 1 */
        instance->smp_current_instruction_cycles=4u;
        if(instance->aram[0x087Cu]!=0x6Bu||instance->aram[0x087Du]!=0x19u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:087C");
        tg_smp_instruction_begin(instance,4u);
        address=(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x19u);
        if(!tg_smp_read8(instance,address,&byte))return 0;
        other=(uint8_t)(tg_smp_flag(instance,TG_SMP_P_C)?1u:0u);
        tg_smp_set_flag(instance,TG_SMP_P_C,(byte&1u)!=0u);
        byte=(uint8_t)((byte>>1)|(other<<7));
        if(!tg_smp_write8(instance,address,byte))return 0;
        tg_smp_set_nz(instance,byte);
        instance->smp.pc=0x087Eu;
        if(!tg_smp_instruction_finish(instance,4u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x087Eu: /* EC FD 00  MOV Y,abs; reference visits 199 */
        instance->smp_current_instruction_cycles=4u;
        if(instance->aram[0x087Eu]!=0xECu||instance->aram[0x087Fu]!=0xFDu||instance->aram[0x0880u]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:087E");
        tg_smp_instruction_begin(instance,4u);
        if(!tg_smp_read8_at_cycle(instance,0x00FDu,&instance->smp.y,3u))return 0;
        tg_smp_set_nz(instance,instance->smp.y);
        instance->smp.pc=0x0881u;
        if(!tg_smp_instruction_finish(instance,4u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0881u: /* F0 FB  BEQ rel; reference visits 198 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0881u]!=0xF0u||instance->aram[0x0882u]!=0xFBu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0881");
        tg_smp_instruction_begin(instance,2u);
        if(tg_smp_flag(instance,TG_SMP_P_Z)){
            instance->smp.pc=0x087Eu;
            if(!tg_smp_instruction_finish(instance,4u))return 0;
        }else{
            instance->smp.pc=0x0883u;
            if(!tg_smp_instruction_finish(instance,2u))return 0;
        }
        instance->smp.instruction_count++;
        return 1;
    case 0x09E5u: /* CC F2 00  MOV abs,Y; reference visits 6 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x09E5u]!=0xCCu||instance->aram[0x09E6u]!=0xF2u||instance->aram[0x09E7u]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:09E5");
        tg_smp_instruction_begin(instance,5u);
        if(!tg_smp_write8_at_cycle(instance,0x00F2u,instance->smp.y,4u))return 0;
        instance->smp.pc=0x09E8u;
        if(!tg_smp_instruction_finish(instance,5u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x09E8u: /* C5 F3 00  MOV abs,A; reference visits 6 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x09E8u]!=0xC5u||instance->aram[0x09E9u]!=0xF3u||instance->aram[0x09EAu]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:09E8");
        tg_smp_instruction_begin(instance,5u);
        if(!tg_smp_write8_at_cycle(instance,0x00F3u,instance->smp.a,4u))return 0;
        instance->smp.pc=0x09EBu;
        if(!tg_smp_instruction_finish(instance,5u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x09EBu: /* 6F  RET; reference visits 6 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x09EBu]!=0x6Fu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:09EB");
        tg_smp_instruction_begin(instance,5u);
        if(!tg_smp_pull8(instance,&byte))return 0;
        if(!tg_smp_pull8(instance,&other))return 0;
        address=(uint16_t)(byte|((uint16_t)other<<8));
        instance->smp.pc=address;
        if(!tg_smp_instruction_finish(instance,5u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DA5u: /* C4 38  MOV dp,A; reference visits 1 */
        instance->smp_current_instruction_cycles=4u;
        if(instance->aram[0x0DA5u]!=0xC4u||instance->aram[0x0DA6u]!=0x38u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DA5");
        tg_smp_instruction_begin(instance,4u);
        if(!tg_smp_write8_at_cycle(instance,(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x38u),instance->smp.a,3u))return 0;
        instance->smp.pc=0x0DA7u;
        if(!tg_smp_instruction_finish(instance,4u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DA7u: /* 8D 7D  MOV Y,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DA7u]!=0x8Du||instance->aram[0x0DA8u]!=0x7Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DA7");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.y=0x7Du;
        tg_smp_set_nz(instance,instance->smp.y);
        instance->smp.pc=0x0DA9u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DA9u: /* CC F2 00  MOV abs,Y; reference visits 1 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x0DA9u]!=0xCCu||instance->aram[0x0DAAu]!=0xF2u||instance->aram[0x0DABu]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DA9");
        tg_smp_instruction_begin(instance,5u);
        if(!tg_smp_write8_at_cycle(instance,0x00F2u,instance->smp.y,4u))return 0;
        instance->smp.pc=0x0DACu;
        if(!tg_smp_instruction_finish(instance,5u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DACu: /* E5 F3 00  MOV A,abs; reference visits 1 */
        instance->smp_current_instruction_cycles=4u;
        if(instance->aram[0x0DACu]!=0xE5u||instance->aram[0x0DADu]!=0xF3u||instance->aram[0x0DAEu]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DAC");
        tg_smp_instruction_begin(instance,4u);
        if(!tg_smp_read8_at_cycle(instance,0x00F3u,&instance->smp.a,3u))return 0;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0DAFu;
        if(!tg_smp_instruction_finish(instance,4u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DAFu: /* 64 38  CMP A,dp; reference visits 1 */
        instance->smp_current_instruction_cycles=3u;
        if(instance->aram[0x0DAFu]!=0x64u||instance->aram[0x0DB0u]!=0x38u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DAF");
        tg_smp_instruction_begin(instance,3u);
        if(!tg_smp_read8_at_cycle(instance,(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x38u),&byte,2u))return 0;
        tg_smp_compare(instance,instance->smp.a,byte);
        instance->smp.pc=0x0DB1u;
        if(!tg_smp_instruction_finish(instance,3u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DB1u: /* F0 2B  BEQ rel; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DB1u]!=0xF0u||instance->aram[0x0DB2u]!=0x2Bu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DB1");
        tg_smp_instruction_begin(instance,2u);
        if(tg_smp_flag(instance,TG_SMP_P_Z)){
            instance->smp.pc=0x0DDEu;
            if(!tg_smp_instruction_finish(instance,4u))return 0;
        }else{
            instance->smp.pc=0x0DB3u;
            if(!tg_smp_instruction_finish(instance,2u))return 0;
        }
        instance->smp.instruction_count++;
        return 1;
    case 0x0DB3u: /* 28 0F  AND A,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DB3u]!=0x28u||instance->aram[0x0DB4u]!=0x0Fu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DB3");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.a=(uint8_t)(instance->smp.a&0x0Fu);
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0DB5u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DB5u: /* 48 FF  EOR A,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DB5u]!=0x48u||instance->aram[0x0DB6u]!=0xFFu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DB5");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.a=(uint8_t)(instance->smp.a^0xFFu);
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0DB7u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DB7u: /* F3 37 03  BBC dp.7,rel; reference visits 1 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x0DB7u]!=0xF3u||instance->aram[0x0DB8u]!=0x37u||instance->aram[0x0DB9u]!=0x03u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DB7");
        tg_smp_instruction_begin(instance,5u);
        if(!tg_smp_read8_at_cycle(instance,(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x37u),&byte,2u))return 0;
        if((byte&0x80u)==0u){
            instance->smp.pc=0x0DBDu;
            if(!tg_smp_instruction_finish(instance,7u))return 0;
        }else{
            instance->smp.pc=0x0DBAu;
            if(!tg_smp_instruction_finish(instance,5u))return 0;
        }
        instance->smp.instruction_count++;
        return 1;
    case 0x0DBDu: /* C4 37  MOV dp,A; reference visits 1 */
        instance->smp_current_instruction_cycles=4u;
        if(instance->aram[0x0DBDu]!=0xC4u||instance->aram[0x0DBEu]!=0x37u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DBD");
        tg_smp_instruction_begin(instance,4u);
        if(!tg_smp_write8_at_cycle(instance,(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x37u),instance->smp.a,3u))return 0;
        instance->smp.pc=0x0DBFu;
        if(!tg_smp_instruction_finish(instance,4u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DBFu: /* 8D 04  MOV Y,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DBFu]!=0x8Du||instance->aram[0x0DC0u]!=0x04u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DBF");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.y=0x04u;
        tg_smp_set_nz(instance,instance->smp.y);
        instance->smp.pc=0x0DC1u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DC1u: /* F6 C4 08  MOV A,abs+Y; reference visits 4 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x0DC1u]!=0xF6u||instance->aram[0x0DC2u]!=0xC4u||instance->aram[0x0DC3u]!=0x08u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DC1");
        tg_smp_instruction_begin(instance,5u);
        address=(uint16_t)(0x08C4u+instance->smp.y);
        if(!tg_smp_read8_at_cycle(instance,address,&instance->smp.a,3u))return 0;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0DC4u;
        if(!tg_smp_instruction_finish(instance,5u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DC4u: /* C5 F2 00  MOV abs,A; reference visits 4 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x0DC4u]!=0xC5u||instance->aram[0x0DC5u]!=0xF2u||instance->aram[0x0DC6u]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DC4");
        tg_smp_instruction_begin(instance,5u);
        if(!tg_smp_write8_at_cycle(instance,0x00F2u,instance->smp.a,4u))return 0;
        instance->smp.pc=0x0DC7u;
        if(!tg_smp_instruction_finish(instance,5u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DC7u: /* E8 00  MOV A,#imm; reference visits 4 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DC7u]!=0xE8u||instance->aram[0x0DC8u]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DC7");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.a=0x00u;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0DC9u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DC9u: /* C5 F3 00  MOV abs,A; reference visits 4 */
        instance->smp_current_instruction_cycles=5u;
        if(instance->aram[0x0DC9u]!=0xC5u||instance->aram[0x0DCAu]!=0xF3u||instance->aram[0x0DCBu]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DC9");
        tg_smp_instruction_begin(instance,5u);
        if(!tg_smp_write8_at_cycle(instance,0x00F3u,instance->smp.a,4u))return 0;
        instance->smp.pc=0x0DCCu;
        if(!tg_smp_instruction_finish(instance,5u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DCCu: /* FE F3  DBNZ Y,rel; reference visits 4 */
        instance->smp_current_instruction_cycles=4u;
        if(instance->aram[0x0DCCu]!=0xFEu||instance->aram[0x0DCDu]!=0xF3u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DCC");
        tg_smp_instruction_begin(instance,4u);
        instance->smp.y=(uint8_t)(instance->smp.y-1u);
        if(instance->smp.y!=0u){
            instance->smp.pc=0x0DC1u;
            if(!tg_smp_instruction_finish(instance,6u))return 0;
        }else{
            instance->smp.pc=0x0DCEu;
            if(!tg_smp_instruction_finish(instance,4u))return 0;
        }
        instance->smp.instruction_count++;
        return 1;
    case 0x0DCEu: /* E4 33  MOV A,dp; reference visits 1 */
        instance->smp_current_instruction_cycles=3u;
        if(instance->aram[0x0DCEu]!=0xE4u||instance->aram[0x0DCFu]!=0x33u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DCE");
        tg_smp_instruction_begin(instance,3u);
        if(!tg_smp_read8_at_cycle(instance,(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x33u),&instance->smp.a,2u))return 0;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0DD0u;
        if(!tg_smp_instruction_finish(instance,3u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DD0u: /* 08 20  OR A,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DD0u]!=0x08u||instance->aram[0x0DD1u]!=0x20u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DD0");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.a=(uint8_t)(instance->smp.a|0x20u);
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0DD2u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DD2u: /* 8D 6C  MOV Y,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DD2u]!=0x8Du||instance->aram[0x0DD3u]!=0x6Cu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DD2");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.y=0x6Cu;
        tg_smp_set_nz(instance,instance->smp.y);
        instance->smp.pc=0x0DD4u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DD4u: /* 3F E5 09  CALL abs; reference visits 1 */
        instance->smp_current_instruction_cycles=8u;
        if(instance->aram[0x0DD4u]!=0x3Fu||instance->aram[0x0DD5u]!=0xE5u||instance->aram[0x0DD6u]!=0x09u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DD4");
        tg_smp_instruction_begin(instance,8u);
        if(!tg_smp_push8(instance,0x0Du))return 0;
        if(!tg_smp_push8(instance,0xD7u))return 0;
        instance->smp.pc=0x09E5u;
        if(!tg_smp_instruction_finish(instance,8u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DD7u: /* E4 38  MOV A,dp; reference visits 1 */
        instance->smp_current_instruction_cycles=3u;
        if(instance->aram[0x0DD7u]!=0xE4u||instance->aram[0x0DD8u]!=0x38u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DD7");
        tg_smp_instruction_begin(instance,3u);
        if(!tg_smp_read8_at_cycle(instance,(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x38u),&instance->smp.a,2u))return 0;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0DD9u;
        if(!tg_smp_instruction_finish(instance,3u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DD9u: /* 8D 7D  MOV Y,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DD9u]!=0x8Du||instance->aram[0x0DDAu]!=0x7Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DD9");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.y=0x7Du;
        tg_smp_set_nz(instance,instance->smp.y);
        instance->smp.pc=0x0DDBu;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DDBu: /* 3F E5 09  CALL abs; reference visits 1 */
        instance->smp_current_instruction_cycles=8u;
        if(instance->aram[0x0DDBu]!=0x3Fu||instance->aram[0x0DDCu]!=0xE5u||instance->aram[0x0DDDu]!=0x09u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DDB");
        tg_smp_instruction_begin(instance,8u);
        if(!tg_smp_push8(instance,0x0Du))return 0;
        if(!tg_smp_push8(instance,0xDEu))return 0;
        instance->smp.pc=0x09E5u;
        if(!tg_smp_instruction_finish(instance,8u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DDEu: /* 1C  ASL A; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DDEu]!=0x1Cu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DDE");
        tg_smp_instruction_begin(instance,2u);
        tg_smp_set_flag(instance,TG_SMP_P_C,(instance->smp.a&0x80u)!=0u);
        instance->smp.a=(uint8_t)(instance->smp.a<<1);
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0DDFu;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DDFu: /* 1C  ASL A; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DDFu]!=0x1Cu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DDF");
        tg_smp_instruction_begin(instance,2u);
        tg_smp_set_flag(instance,TG_SMP_P_C,(instance->smp.a&0x80u)!=0u);
        instance->smp.a=(uint8_t)(instance->smp.a<<1);
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0DE0u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DE0u: /* 1C  ASL A; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DE0u]!=0x1Cu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DE0");
        tg_smp_instruction_begin(instance,2u);
        tg_smp_set_flag(instance,TG_SMP_P_C,(instance->smp.a&0x80u)!=0u);
        instance->smp.a=(uint8_t)(instance->smp.a<<1);
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0DE1u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DE1u: /* 48 FF  EOR A,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DE1u]!=0x48u||instance->aram[0x0DE2u]!=0xFFu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DE1");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.a=(uint8_t)(instance->smp.a^0xFFu);
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0DE3u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DE3u: /* 80  SETC; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DE3u]!=0x80u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DE3");
        tg_smp_instruction_begin(instance,2u);
        tg_smp_set_flag(instance,TG_SMP_P_C,1);
        instance->smp.pc=0x0DE4u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DE4u: /* E8 39  MOV A,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DE4u]!=0xE8u||instance->aram[0x0DE5u]!=0x39u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DE4");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.a=0x39u;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0DE6u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DE6u: /* 8D 6D  MOV Y,#imm; reference visits 1 */
        instance->smp_current_instruction_cycles=2u;
        if(instance->aram[0x0DE6u]!=0x8Du||instance->aram[0x0DE7u]!=0x6Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DE6");
        tg_smp_instruction_begin(instance,2u);
        instance->smp.y=0x6Du;
        tg_smp_set_nz(instance,instance->smp.y);
        instance->smp.pc=0x0DE8u;
        if(!tg_smp_instruction_finish(instance,2u))return 0;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DE8u: /* 5F E5 09  JMP abs; reference visits 1 */
        instance->smp_current_instruction_cycles=3u;
        if(instance->aram[0x0DE8u]!=0x5Fu||instance->aram[0x0DE9u]!=0xE5u||instance->aram[0x0DEAu]!=0x09u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DE8");
        tg_smp_instruction_begin(instance,3u);
        instance->smp.pc=0x09E5u;
        if(!tg_smp_instruction_finish(instance,3u))return 0;
        instance->smp.instruction_count++;
        return 1;
    default:
        return tg_fail_frontier(instance,"Unknown Version 04 generated SPC700 context.",NULL);
    }
}
