/* Generated from the exact ROM-derived ARAM image by
   tools/smp/generate_v03_smp_batch.py.
   No emulator trace or oracle state was used. */
#include "topgear_internal.h"
#include "topgear_v03_smp_batch.h"

unsigned tg_v03_generated_smp_context_count(void){return 24u;}

int tg_v03_generated_smp_step(struct TopGearRecomp *instance){
    uint16_t address=0u;
    uint8_t byte=0u;
    if(!instance)return 0;
    switch(instance->smp.pc){
    case 0x0800u: /* 20  CLRP; reference visits 1 */
        if(instance->aram[0x0800u]!=0x20u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0800");
        tg_smp_set_flag(instance, TG_SMP_P_P, 0);
        instance->smp.pc=0x0801u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0801u: /* CD CF  MOV X,#imm; reference visits 1 */
        if(instance->aram[0x0801u]!=0xCDu||instance->aram[0x0802u]!=0xCFu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0801");
        instance->smp.x=0xCFu;
        tg_smp_set_nz(instance,instance->smp.x);
        instance->smp.pc=0x0803u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0803u: /* BD  MOV SP,X; reference visits 1 */
        if(instance->aram[0x0803u]!=0xBDu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0803");
        instance->smp.sp=instance->smp.x;
        instance->smp.pc=0x0804u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0804u: /* E8 00  MOV A,#imm; reference visits 1 */
        if(instance->aram[0x0804u]!=0xE8u||instance->aram[0x0805u]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0804");
        instance->smp.a=0x00u;
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0806u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0806u: /* 5D  MOV X,A; reference visits 1 */
        if(instance->aram[0x0806u]!=0x5Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0806");
        instance->smp.x=instance->smp.a;
        tg_smp_set_nz(instance,instance->smp.x);
        instance->smp.pc=0x0807u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0807u: /* AF  MOV (X)+,A; reference visits 240 */
        if(instance->aram[0x0807u]!=0xAFu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0807");
        address=(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|instance->smp.x);
        if(!tg_smp_write8(instance,address,instance->smp.a))return 0;
        instance->smp.x=(uint8_t)(instance->smp.x+1u);
        instance->smp.pc=0x0808u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0808u: /* C8 F0  CMP X,#imm; reference visits 240 */
        if(instance->aram[0x0808u]!=0xC8u||instance->aram[0x0809u]!=0xF0u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0808");
        tg_smp_compare(instance,instance->smp.x,0xF0u);
        instance->smp.pc=0x080Au;
        instance->smp.instruction_count++;
        return 1;
    case 0x080Au: /* D0 FB  BNE rel; reference visits 240 */
        if(instance->aram[0x080Au]!=0xD0u||instance->aram[0x080Bu]!=0xFBu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:080A");
        instance->smp.pc=tg_smp_flag(instance,TG_SMP_P_Z)?0x080Cu:0x0807u;
        instance->smp.instruction_count++;
        return 1;
    case 0x080Cu: /* 5D  MOV X,A; reference visits 1 */
        if(instance->aram[0x080Cu]!=0x5Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:080C");
        instance->smp.x=instance->smp.a;
        tg_smp_set_nz(instance,instance->smp.x);
        instance->smp.pc=0x080Du;
        instance->smp.instruction_count++;
        return 1;
    case 0x080Du: /* D5 00 01  MOV abs+X,A; reference visits 256 */
        if(instance->aram[0x080Du]!=0xD5u||instance->aram[0x080Eu]!=0x00u||instance->aram[0x080Fu]!=0x01u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:080D");
        address=(uint16_t)(0x0100u+instance->smp.x);
        if(!tg_smp_write8(instance,address,instance->smp.a))return 0;
        instance->smp.pc=0x0810u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0810u: /* D5 00 02  MOV abs+X,A; reference visits 256 */
        if(instance->aram[0x0810u]!=0xD5u||instance->aram[0x0811u]!=0x00u||instance->aram[0x0812u]!=0x02u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0810");
        address=(uint16_t)(0x0200u+instance->smp.x);
        if(!tg_smp_write8(instance,address,instance->smp.a))return 0;
        instance->smp.pc=0x0813u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0813u: /* D5 00 03  MOV abs+X,A; reference visits 256 */
        if(instance->aram[0x0813u]!=0xD5u||instance->aram[0x0814u]!=0x00u||instance->aram[0x0815u]!=0x03u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0813");
        address=(uint16_t)(0x0300u+instance->smp.x);
        if(!tg_smp_write8(instance,address,instance->smp.a))return 0;
        instance->smp.pc=0x0816u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0816u: /* D5 00 04  MOV abs+X,A; reference visits 256 */
        if(instance->aram[0x0816u]!=0xD5u||instance->aram[0x0817u]!=0x00u||instance->aram[0x0818u]!=0x04u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0816");
        address=(uint16_t)(0x0400u+instance->smp.x);
        if(!tg_smp_write8(instance,address,instance->smp.a))return 0;
        instance->smp.pc=0x0819u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0819u: /* D5 00 05  MOV abs+X,A; reference visits 256 */
        if(instance->aram[0x0819u]!=0xD5u||instance->aram[0x081Au]!=0x00u||instance->aram[0x081Bu]!=0x05u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0819");
        address=(uint16_t)(0x0500u+instance->smp.x);
        if(!tg_smp_write8(instance,address,instance->smp.a))return 0;
        instance->smp.pc=0x081Cu;
        instance->smp.instruction_count++;
        return 1;
    case 0x081Cu: /* D5 00 06  MOV abs+X,A; reference visits 256 */
        if(instance->aram[0x081Cu]!=0xD5u||instance->aram[0x081Du]!=0x00u||instance->aram[0x081Eu]!=0x06u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:081C");
        address=(uint16_t)(0x0600u+instance->smp.x);
        if(!tg_smp_write8(instance,address,instance->smp.a))return 0;
        instance->smp.pc=0x081Fu;
        instance->smp.instruction_count++;
        return 1;
    case 0x081Fu: /* D5 00 07  MOV abs+X,A; reference visits 256 */
        if(instance->aram[0x081Fu]!=0xD5u||instance->aram[0x0820u]!=0x00u||instance->aram[0x0821u]!=0x07u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:081F");
        address=(uint16_t)(0x0700u+instance->smp.x);
        if(!tg_smp_write8(instance,address,instance->smp.a))return 0;
        instance->smp.pc=0x0822u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0822u: /* 3D  INC X; reference visits 256 */
        if(instance->aram[0x0822u]!=0x3Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0822");
        instance->smp.x=(uint8_t)(instance->smp.x+1u);
        tg_smp_set_nz(instance,instance->smp.x);
        instance->smp.pc=0x0823u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0823u: /* D0 E8  BNE rel; reference visits 256 */
        if(instance->aram[0x0823u]!=0xD0u||instance->aram[0x0824u]!=0xE8u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0823");
        instance->smp.pc=tg_smp_flag(instance,TG_SMP_P_Z)?0x0825u:0x080Du;
        instance->smp.instruction_count++;
        return 1;
    case 0x0825u: /* BC  INC A; reference visits 1 */
        if(instance->aram[0x0825u]!=0xBCu)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0825");
        instance->smp.a=(uint8_t)(instance->smp.a+1u);
        tg_smp_set_nz(instance,instance->smp.a);
        instance->smp.pc=0x0826u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0826u: /* 3F A5 0D  CALL abs; reference visits 1 */
        if(instance->aram[0x0826u]!=0x3Fu||instance->aram[0x0827u]!=0xA5u||instance->aram[0x0828u]!=0x0Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0826");
        if(!tg_smp_push8(instance,0x08u))return 0;
        if(!tg_smp_push8(instance,0x29u))return 0;
        instance->smp.pc=0x0DA5u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DA5u: /* C4 38  MOV dp,A; reference visits 1 */
        if(instance->aram[0x0DA5u]!=0xC4u||instance->aram[0x0DA6u]!=0x38u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DA5");
        address=(uint16_t)(((instance->smp.psw&TG_SMP_P_P)!=0u?0x0100u:0u)|0x38u);
        if(!tg_smp_write8(instance,address,instance->smp.a))return 0;
        instance->smp.pc=0x0DA7u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DA7u: /* 8D 7D  MOV Y,#imm; reference visits 1 */
        if(instance->aram[0x0DA7u]!=0x8Du||instance->aram[0x0DA8u]!=0x7Du)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DA7");
        instance->smp.y=0x7Du;
        tg_smp_set_nz(instance,instance->smp.y);
        instance->smp.pc=0x0DA9u;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DA9u: /* CC F2 00  MOV abs,Y; reference visits 1 */
        if(instance->aram[0x0DA9u]!=0xCCu||instance->aram[0x0DAAu]!=0xF2u||instance->aram[0x0DABu]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DA9");
        if(!tg_smp_write8(instance,0x00F2u,instance->smp.y))return 0;
        instance->smp.pc=0x0DACu;
        instance->smp.instruction_count++;
        return 1;
    case 0x0DACu: /* E5 F3 00  MOV A,abs; reference visits 1 */
        if(instance->aram[0x0DACu]!=0xE5u||instance->aram[0x0DADu]!=0xF3u||instance->aram[0x0DAEu]!=0x00u)return tg_fail_frontier(instance,"Generated SPC700 byte contract mismatch.","SMP:0DAC");
        if(!tg_smp_read8(instance,0x00F3u,&byte))return 0;
        instance->smp.a=byte;
        tg_smp_set_nz(instance,byte);
        instance->smp.pc=0x0DAFu;
        instance->smp.instruction_count++;
        return 1;
    default:
        return tg_fail_frontier(instance,"Unknown Version 03 generated SPC700 context.",NULL);
    }
}
