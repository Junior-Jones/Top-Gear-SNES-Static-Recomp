#define main menu_regression_main
#include "test_menu_flicker.c"
#undef main

static unsigned original_builders, replacement_calls, sound_cues;
static int trace(void *user,const TopGearHookEvent *event){
    (void)user;
    if(event->type!=TOPGEAR_HOOK_EVENT_INSTRUCTION_BEFORE)return 0;
    if(event->address==0x0F9F93u){
        if(original_builders<8u)printf("Native layout builder: X=%04X DBR=%02X DP=%04X frame=%u\n",core->cpu.x,core->cpu.dbr,core->cpu.d,(unsigned)topgear_recomp_v27_frame_count(core));
        original_builders++;
    }
    if(event->address==0x0F9223u&&core->mod_menu_remodel_active)replacement_calls++;
    if(event->address==0x0F922Cu&&core->cpu.a==0x84u)sound_cues++;
    return 0;
}
int main(int argc,char **argv){
    uint8_t rom[524288];char path[1024];FILE *f;unsigned n,enabled;
    if(argc!=4&&argc!=5)return 2;output=argv[3];
    f=fopen(argv[1],"rb");if(!f||fread(rom,1,sizeof(rom),f)!=sizeof(rom))return 2;fclose(f);
    if(!topgear_recomp_create(&core,rom,sizeof(rom),error,sizeof(error)))return 2;
    if(argc==5){
        unsigned mode,d,stage,guard,position;
        static const uint16_t buttons[4]={0x0800,0x0400,0x0200,0x0100};
        if(strcmp(argv[4],"--native-setup"))return 2;
        for(mode=0;mode<3;mode++){
            if(!topgear_recomp_snapshot_load(core,argv[2],error,sizeof(error)))return 3;
            for(n=0;n<mode;n++)if(!press(0x0400,0))return 3;
            if(!press(0x0080,0)||!core->mod_menu_remodel_active||core->mod_menu_remodel_page!=mode+1)return 4;
            if(!press(0x0080,0)||core->mod_menu_remodel_active)return 4;
            snprintf(path,sizeof(path),"native-mode-%u-setup",mode);capture(path);
            for(d=0;d<8;d++)if(!press(buttons[d%4],0)||core->mod_menu_remodel_active||core->mod_time_trial_active)return 5;
            /* The native name editor uses B to erase, not to exit. Follow
               the published v1.2 route to END, then gear/controls/car. */
            if(!press(0x8000,0))return 6;
            /* Read the native cursor after exercising wrapping. The fixed
               v1.2 button recipe assumes the untouched initial cursor. */
            for(guard=0;guard<20;guard++){
                position=core->wram[0x48]|((unsigned)core->wram[0x49]<<8);
                if(position==0x1314u)break;
                if((position>>8)!=0x13u){if(!press(0x0400,0))return 6;}
                else if(!press((position&255u)<0x14u?0x0100:0x0200,0))return 6;
            }
            if(guard==20){fprintf(stderr,"Native END not reached: cursor=%04X\n",position);return 6;}
            if(!press(0x0080,0))return 6;
            for(stage=0;stage<3;stage++){
                snprintf(path,sizeof(path),"native-mode-%u-stage-%u",mode,stage);capture(path);
                for(d=0;d<4;d++)if(!press(buttons[d],0)||core->mod_menu_remodel_active||core->mod_time_trial_active)return 6;
                if(!press(0x0080,0))return 6;
            }
            if(!core->mod_menu_remodel_active||core->mod_menu_remodel_page!=mode+1){fprintf(stderr,"Native setup return failed: mode=%u PC=%02X:%04X page=%u active=%u\n",mode,core->cpu.pbr,core->cpu.pc,core->mod_menu_remodel_page,core->mod_menu_remodel_active);return 7;}
            printf("PASS mode=%u native player setup: name editor, gear, controls and car; all D-pad directions; END/confirm returned to custom page=%u; no race started\n",mode,core->mod_menu_remodel_page);fflush(stdout);
        }
        topgear_recomp_destroy(core);return 0;
    }
    for(enabled=0;enabled<2;enabled++){
        if(!topgear_recomp_snapshot_load(core,argv[2],error,sizeof(error)))return 3;
        core->mod_menu_remodel_active=(uint8_t)enabled;
        original_builders=replacement_calls=sound_cues=0;
        if(!topgear_recomp_set_hook(core,TOPGEAR_HOOK_MASK_INSTRUCTION,trace,NULL))return 3;
        for(n=0;n<4;n++)if(!press(n<2?0x0400:0x0800,0))return 4;
        topgear_recomp_clear_hook(core);
        capture(enabled?"replacement-layout":"original-layout");
        snprintf(path,sizeof(path),"%s/%s-map.bin",output,enabled?"replacement":"original");
        f=fopen(path,"wb");if(!f||fwrite(core->wram+0x0C6Cu,1,0x800u,f)!=0x800u)return 4;fclose(f);
        printf("%s: stock_layout_builder_entries=%u replacement_layout_calls=%u native_sound_84=%u\n",enabled?"Replacement":"Original",original_builders,replacement_calls,sound_cues);
        if(enabled){if(original_builders||replacement_calls!=4||sound_cues!=4)return 5;}
        else if(!original_builders||replacement_calls||sound_cues!=4)return 5;
    }
    topgear_recomp_destroy(core);printf("PASS original/replacement comparison; no race started\n");return 0;
}
