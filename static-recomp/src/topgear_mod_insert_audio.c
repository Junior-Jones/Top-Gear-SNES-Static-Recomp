#include "topgear_internal.h"
#include "sc_static_apu.h"
#include "topgear_finish_brr.inc"
#include "topgear_uwnh_accept_brr.inc"

#include <stddef.h>
#include <stdint.h>

/* Voice 9 integration, 2026-09-11.
   Music register voice 7 is synthesized in internal state slot 8. The cue
   owns a private single-voice DSP context and private sample RAM. The following
   historical asset proof remains authoritative; no shared music ARAM or
   music DSP registers are now overwritten.

   Original Explore - Insert audio, Test 1 Part 2.

   Navigation now uses the real SimCity (USA) menu cursor sound rather than
   Top Gear's skid effect.  The asset was proved from a live SimCity static-core
   Down transition:
     S-CPU DP $05 = $06 -> APUIO2 ($2142)
     DSP voice 7, SRCN $03, DIR $35
     BRR start $3AD1, loop $3AEC, 6 blocks / 54 bytes
     VOLL/VOLR $3C/$3C, pitch $17BB, ADSR $FE/$F5, GAIN $70
     echo disabled for voice 7
     key-on -> key-off = 720,828 SNES master clocks (~33.56 ms)

   Top Gear keeps its own S-SMP/S-DSP engine and Title music.  Only the 54-byte
   BRR resource and the proved playback contract are imported.  Title voice 7
   is idle at this menu.  The sample is placed in the previously proved free
   Title ARAM region at $C000 and installed as Top Gear SRCN $10 via DIR $8A.

   The SimCity BRR END block has LOOP=1, so merely keying the sample and leaving
   it active would repeat forever.  The prototype therefore reproduces the
   source game's finite key-on/key-off behavior.  The normal Top Gear audio
   timeline remains authoritative; mod DSP writes occur only after a normal
   Full Static synchronization rendezvous. */

#define TG_MOD_SIMCITY_BRR_ARAM       UINT32_C(0x00C000)
#define TG_MOD_UWNH_ACCEPT_BRR_ARAM   UINT32_C(0x00C100)
#define TG_MOD_SRCN10_DIR             UINT32_C(0x008A40)
#define TG_MOD_SRCN11_DIR             UINT32_C(0x008A44)
#define TG_MOD_SIMCITY_SRCN           UINT8_C(0x10)
#define TG_MOD_UWNH_ACCEPT_SRCN       UINT8_C(0x11)
#define TG_MOD_SIMCITY_VOICE_MASK     UINT8_C(0x80)
#define TG_MOD_SIMCITY_ACTIVE_CLOCKS  UINT64_C(720828)
#define TG_MOD_SIMCITY_RESTORE_CLOCKS UINT64_C(435336)

static const uint8_t tg_mod_simcity_menu_brr[54] = {
    0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x7A,0x04,0x23,0x22,0x11,0x1F,0xFF,0xED,0xFF,
    0x6A,0xBD,0xF0,0xEE,0xFE,0xDD,0xDC,0xEC,0xCE,
    0x6A,0xED,0xE0,0xFF,0x11,0x32,0x45,0x55,0x55,
    0x6A,0x56,0x64,0x44,0x31,0x2F,0xDC,0xDC,0xEC,
    0x6B,0xCE,0xEF,0xFF,0xED,0xDE,0xDC,0xEC,0xCD
};

static int mod_fail(TopGearRecomp *i,const char *message){
    return tg_fail_frontier(i,message,"MOD-INSERT-AUDIO");
}

static int dsp_write(TopGearRecomp *i,uint8_t reg,uint8_t value){
    return tg_audio_backend_mod_write_dsp_register(i,reg,value);
}

static int install_menu_simcity_resource(TopGearRecomp *i){
    /* SimCity loop offset is $3AEC-$3AD1 = $001B. */
    static const uint8_t directory[4]={0x00u,0xC0u,0x1Bu,0xC0u};
    /* UWNH source directory: start $4490, loop $4529 (offset $0099). */
    static const uint8_t accept_directory[4]={0x00u,0xC1u,0x99u,0xC1u};
    if(!i)return 0;
    /* The cue RAM is private and survives ordinary menu transitions.  Avoid
       rewriting a sample while a rapid input is still playing it. */
    if(i->mod_insert_audio_menu_resource_installed&&
       i->mod_insert_audio_simcity_resource_installed)return 1;
    if(!tg_audio_backend_mod_write_aram(i,TG_MOD_SIMCITY_BRR_ARAM,
            tg_mod_simcity_menu_brr,sizeof(tg_mod_simcity_menu_brr)))
        return mod_fail(i,"Could not install the imported SimCity menu BRR resource.");
    if(!tg_audio_backend_mod_write_aram(i,TG_MOD_SRCN10_DIR,
            directory,sizeof(directory)))
        return mod_fail(i,"Could not install the imported SimCity SRCN directory entry.");
    if(!tg_audio_backend_mod_write_aram(i,TG_MOD_UWNH_ACCEPT_BRR_ARAM,
            uwnh_accept_brr,sizeof(uwnh_accept_brr)) ||
       !tg_audio_backend_mod_write_aram(i,TG_MOD_SRCN11_DIR,
            accept_directory,sizeof(accept_directory)))
        return mod_fail(i,"Could not install the imported Uncharted Waters accept resource.");
    i->mod_insert_audio_menu_resource_installed=1u;
    i->mod_insert_audio_simcity_resource_installed=1u;
    i->mod_insert_audio_resource_install_count++;
    return 1;
}

int tg_mod_insert_audio_main_menu_enter(TopGearRecomp *i){
    if(!i)return 0;
    tg_mod_music_menu_enter(i);
    i->mod_audio_menu_level=5u; /* User-selected menu music level: 50%. */
    i->mod_audio_menu_context=1u;
    i->mod_insert_audio_main_menu_active=1u;
    i->mod_insert_audio_last_menu_selection=0u;
    return install_menu_simcity_resource(i);
}

void tg_mod_insert_audio_start_race(TopGearRecomp *i){
    if(!i||i->mod_insert_audio_sfx_state==5u||i->mod_insert_audio_sfx_state==6u)return;
    /* Start confirmation takes priority over queued movement sounds. */
    i->mod_insert_audio_sfx_queued=0u;i->mod_insert_audio_sfx_command=7u;
    i->mod_insert_audio_sfx_state=5u;
}

void tg_mod_insert_audio_accept(TopGearRecomp *i){
    if(!i||!i->mod_insert_audio_main_menu_active)return;
    if(i->mod_insert_audio_sfx_state>=5u)return;
    /* A valid confirmation replaces a still-releasing movement cue. */
    i->mod_insert_audio_sfx_queued=0u;
    i->mod_insert_audio_sfx_command=8u;
    i->mod_insert_audio_reserved[0]=0u;
    i->mod_insert_audio_sfx_state=7u;
}

void tg_mod_insert_audio_navigation(TopGearRecomp *i){
    if(!i||!i->mod_insert_audio_main_menu_active)return;
    if(i->mod_insert_audio_sfx_state>=5u)return;
    i->mod_insert_audio_navigation_change_count++;
    if(i->mod_insert_audio_sfx_state==0u)i->mod_insert_audio_sfx_state=1u;
    else if(i->mod_insert_audio_sfx_queued<255u)i->mod_insert_audio_sfx_queued++;
}

void tg_mod_insert_audio_menu_selection(TopGearRecomp *i,uint16_t selection){
    uint8_t value;
    if(!i||!i->mod_insert_audio_main_menu_active)return;
    value=(uint8_t)(selection&0xFFu);
    if(value==i->mod_insert_audio_last_menu_selection)return;
    i->mod_insert_audio_last_menu_selection=value;
    tg_mod_insert_audio_navigation(i);
}

static int configure_and_keyon(TopGearRecomp *i,uint64_t master_clock){
    uint8_t eon;
    eon=0u; /* Cue lane has no echo; music registers remain untouched. */
    /* Clear any prior private-lane key-off before the new key-on. */
    if(!dsp_write(i,0x5Cu,0x00u) || !dsp_write(i,0x4Du,eon) ||
       !dsp_write(i,0x70u,0x3Cu) || !dsp_write(i,0x71u,0x3Cu) ||
       !dsp_write(i,0x72u,0xBBu) || !dsp_write(i,0x73u,0x17u) ||
       !dsp_write(i,0x74u,TG_MOD_SIMCITY_SRCN) ||
       !dsp_write(i,0x75u,0xFEu) || !dsp_write(i,0x76u,0xF5u) ||
       !dsp_write(i,0x77u,0x70u) ||
       !dsp_write(i,0x4Cu,TG_MOD_SIMCITY_VOICE_MASK))
        return mod_fail(i,"Could not configure/key-on the imported SimCity menu cue.");
    i->mod_insert_audio_cue_keyoff_master_clock=master_clock+TG_MOD_SIMCITY_ACTIVE_CLOCKS;
    i->mod_insert_audio_cue_restore_master_clock=
        i->mod_insert_audio_cue_keyoff_master_clock+TG_MOD_SIMCITY_RESTORE_CLOCKS;
    i->mod_insert_audio_cue_keyon_count++;
    i->mod_insert_audio_command_start_count++;
    i->mod_insert_audio_sfx_state=2u;
    return 1;
}

static int restore_cue_lane(TopGearRecomp *i){
    if(!dsp_write(i,0x70u,0u)||!dsp_write(i,0x71u,0u))return 0;
    i->mod_insert_audio_cue_restore_count++;
    i->mod_insert_audio_neutral_ack_count++;
    return 1;
}

static int process_uwnh_accept(TopGearRecomp *i,uint64_t master_clock){
    static const uint64_t at[17]={
        UINT64_C(0),UINT64_C(714732),UINT64_C(1429464),UINT64_C(2501564),
        UINT64_C(3573660),UINT64_C(4288392),UINT64_C(5003124),UINT64_C(5717856),
        UINT64_C(6789956),UINT64_C(7504688),UINT64_C(8219420),UINT64_C(8934152),
        UINT64_C(10363616),UINT64_C(11078348),UINT64_C(11793080),
        UINT64_C(12507812),UINT64_C(13579908)
    };
    static const uint16_t pitch[16]={
        0x1000u,0x1424u,0x17F4u,0x2000u,0x1000u,0x1424u,0x17F4u,0x2000u,
        0x1000u,0x1424u,0x17F4u,0x2000u,0x1000u,0x1424u,0x17F4u,0x2000u
    };
    static const uint8_t voll[16]={
        0x14u,0x22u,0x22u,0x22u,0x13u,0x13u,0x13u,0x13u,
        0x09u,0x09u,0x09u,0x09u,0x04u,0x04u,0x04u,0x04u
    };
    static const uint8_t volr[16]={
        0x13u,0x21u,0x21u,0x21u,0x12u,0x12u,0x12u,0x12u,
        0x08u,0x08u,0x08u,0x08u,0x03u,0x03u,0x03u,0x03u
    };
    unsigned step=i->mod_insert_audio_reserved[0];
    if(step==0u){
        i->mod_insert_audio_cue_keyoff_master_clock=master_clock;
        if(!dsp_write(i,0x5Cu,0u)||!dsp_write(i,0x4Du,0u)||
           !dsp_write(i,0x74u,TG_MOD_UWNH_ACCEPT_SRCN)||
           !dsp_write(i,0x75u,0xFFu)||!dsp_write(i,0x76u,0xB4u)||
           !dsp_write(i,0x77u,0x9Eu))
            return mod_fail(i,"Could not configure the Uncharted Waters accept cue.");
    }
    while(step<16u &&
          master_clock>=i->mod_insert_audio_cue_keyoff_master_clock+at[step]){
        uint16_t p=pitch[step];
        if(!dsp_write(i,0x70u,voll[step])||!dsp_write(i,0x71u,volr[step])||
           !dsp_write(i,0x72u,(uint8_t)p)||!dsp_write(i,0x73u,(uint8_t)(p>>8u))||
           !dsp_write(i,0x4Cu,TG_MOD_SIMCITY_VOICE_MASK))
            return mod_fail(i,"Could not play the Uncharted Waters accept cue.");
        if(step==0u){
            i->mod_insert_audio_cue_keyon_count++;
            i->mod_insert_audio_command_start_count++;
        }
        step++;
        i->mod_insert_audio_reserved[0]=(uint8_t)step;
    }
    if(step==16u &&
       master_clock>=i->mod_insert_audio_cue_keyoff_master_clock+at[16]){
        if(!dsp_write(i,0x70u,0u)||!dsp_write(i,0x71u,0u)||
           !dsp_write(i,0x5Cu,TG_MOD_SIMCITY_VOICE_MASK))
            return mod_fail(i,"Could not stop the Uncharted Waters accept cue.");
        i->mod_insert_audio_cue_keyoff_count++;
        i->mod_insert_audio_command_ack_count++;
        i->mod_insert_audio_sfx_state=8u;
    }
    return 1;
}

int tg_mod_insert_audio_process(TopGearRecomp *i,uint64_t master_clock){
    if(!i||i->mod_insert_audio_sfx_state==0u)return 1;
    if(!i->static_audio_acquired)return mod_fail(i,"Menu cue requested before Full Static audio initialization.");
    switch(i->mod_insert_audio_sfx_state){
    case 7u:
        return process_uwnh_accept(i,master_clock);
    case 8u:
        if(!dsp_write(i,0x5Cu,0u))
            return mod_fail(i,"Could not clear the Uncharted Waters accept cue key-off.");
        i->mod_insert_audio_command_clear_count++;
        if(!restore_cue_lane(i))
            return mod_fail(i,"Could not restore the private cue lane after the Uncharted Waters accept cue.");
        i->mod_insert_audio_sfx_state=0u;
        i->mod_insert_audio_sfx_command=0u;
        i->mod_insert_audio_reserved[0]=0u;
        return 1;
    case 5u:{
        static const uint8_t directory[4]={0x60u,0xC7u,0x60u,0xC7u};
        if(!tg_audio_backend_mod_write_aram(i,0xC760u,finish_brr,sizeof(finish_brr))||
           !tg_audio_backend_mod_write_aram(i,0x8A48u,directory,sizeof(directory))||
           !dsp_write(i,0x5Cu,0u)||!dsp_write(i,0x4Du,0u)||
           !dsp_write(i,0x70u,0x7Fu)||!dsp_write(i,0x71u,0x7Fu)||
           !dsp_write(i,0x72u,0u)||!dsp_write(i,0x73u,4u)||
           !dsp_write(i,0x74u,0x12u)||!dsp_write(i,0x75u,0xFFu)||
           !dsp_write(i,0x76u,0xE0u)||!dsp_write(i,0x77u,0xB8u)||
           !dsp_write(i,0x4Cu,0x80u))return mod_fail(i,"Could not start the finish-line confirmation cue.");
        i->mod_insert_audio_cue_keyon_count++;i->mod_insert_audio_command_start_count++;
        i->mod_insert_audio_cue_keyoff_master_clock=master_clock+21477u;
        i->mod_insert_audio_cue_restore_master_clock=master_clock+21477270u;
        i->mod_insert_audio_sfx_state=6u;return 1;
    }
    case 6u:{
        uint8_t endx=0u;
        if(master_clock<i->mod_insert_audio_cue_keyoff_master_clock)return 1;
        if(!sc_static_apu_cue_endx(&endx))return mod_fail(i,"Could not read finish-line cue completion.");
        if(!(endx&0x80u)){
            if(master_clock<i->mod_insert_audio_cue_restore_master_clock)return 1;
            return mod_fail(i,"Finish-line cue did not terminate within its guard interval.");
        }
        if(!restore_cue_lane(i))return 0;
        i->mod_insert_audio_sfx_state=0u;i->mod_insert_audio_sfx_command=0u;return 1;
    }
    case 1u:
        return configure_and_keyon(i,master_clock);
    case 2u:
        if(master_clock<i->mod_insert_audio_cue_keyoff_master_clock)return 1;
        if(!dsp_write(i,0x5Cu,TG_MOD_SIMCITY_VOICE_MASK))
            return mod_fail(i,"Could not key-off the imported SimCity menu cue.");
        i->mod_insert_audio_cue_keyoff_count++;
        i->mod_insert_audio_command_ack_count++;
        i->mod_insert_audio_sfx_state=3u;
        return 1;
    case 3u:
        /* KOFF is level-sensitive. Pulse it, then clear at the next normal
           synchronization rendezvous while the voice enters release. */
        if(!dsp_write(i,0x5Cu,0x00u))
            return mod_fail(i,"Could not clear SimCity cue key-off.");
        i->mod_insert_audio_command_clear_count++;
        i->mod_insert_audio_sfx_state=4u;
        return 1;
    case 4u:
        if(master_clock<i->mod_insert_audio_cue_restore_master_clock)return 1;
        if(!restore_cue_lane(i))
            return mod_fail(i,"Could not restore the private cue lane after the SimCity cue.");
        i->mod_insert_audio_sfx_state=0u;
        if(i->mod_insert_audio_sfx_queued){
            i->mod_insert_audio_sfx_queued--;
            i->mod_insert_audio_sfx_state=1u;
        }
        return 1;
    default:
        return mod_fail(i,"Imported menu cue state machine entered an invalid state.");
    }
}

void tg_mod_audio_gameplay_start(TopGearRecomp *i){
    i->mod_audio_menu_context=0u;
    i->mod_audio_menu_level=5u;
}
