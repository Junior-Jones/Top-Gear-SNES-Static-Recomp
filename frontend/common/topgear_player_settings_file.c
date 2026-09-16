#if defined(_MSC_VER) && !defined(_CRT_SECURE_NO_WARNINGS)
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "topgear_player_settings_file.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <io.h>
#else
#include <unistd.h>
#endif
static FILE *open_file(const char *path,int write){
#ifdef _WIN32
    wchar_t wide[4096];
    if(!MultiByteToWideChar(CP_UTF8,MB_ERR_INVALID_CHARS,path,-1,wide,4096))return NULL;
    return _wfopen(wide,write?L"wb":L"rb");
#else
    return fopen(path,write?"wb":"rb");
#endif
}

static const uint8_t profile_control_schemes[4][16]={
    {0x40,0x00,0x00,0x40,0x10,0x00,0x20,0x00,0x80,0x00,0x00,0x02,0x00,0x01,0x03,0x00},
    {0x00,0x80,0x40,0x00,0x80,0x00,0x00,0x40,0x00,0x10,0x00,0x01,0x00,0x02,0x03,0x00},
    {0x40,0x00,0x00,0x80,0x80,0x00,0x00,0x40,0x00,0x10,0x00,0x02,0x00,0x01,0x03,0x00},
    {0x00,0x80,0x00,0x40,0x10,0x00,0x20,0x00,0x80,0x00,0x00,0x02,0x00,0x01,0x03,0x00}
};

static uint32_t profile_settings_checksum(const uint8_t *data){
    uint32_t hash=UINT32_C(2166136261);unsigned n;
    for(n=16u;n<TOPGEAR_PLAYER_SETTINGS_SIZE;n++)hash=(hash^data[n])*UINT32_C(16777619);
    return hash;
}

static void profile_settings_store_checksum(uint8_t *data){
    uint32_t hash=profile_settings_checksum(data);unsigned n;
    for(n=0u;n<4u;n++)data[12u+n]=(uint8_t)(hash>>(8u*n));
}

static void profile_settings_defaults(uint8_t *data){
    unsigned n;
    memset(data,0,TOPGEAR_PLAYER_SETTINGS_SIZE);
    memcpy(data,"TGPS",4u);data[4]=5u;data[8]=TOPGEAR_PLAYER_SETTINGS_SIZE;
    for(n=0u;n<3u;n++){
        uint8_t *profile=data+16u+n*26u;
        memcpy(profile,profile_control_schemes[0],16u);
        memset(profile+16u,' ',8u);
    }
    memcpy(data+32u,"PLAYER 1",8u);
    memcpy(data+84u,"PLAYER 1",8u);
    data[95]=1u;
    profile_settings_store_checksum(data);
}

static int profile_settings_validate(const uint8_t *data,size_t size){
    uint32_t stored=0u;unsigned n,version;
    if(!data||size!=TOPGEAR_PLAYER_SETTINGS_SIZE||memcmp(data,"TGPS",4u))return 0;
    version=data[4];
    if((version<1u||version>5u)||data[5]||data[6]||data[7]||
       data[8]!=TOPGEAR_PLAYER_SETTINGS_SIZE||data[9]||data[10]||data[11]||
       data[94]>1u||data[95]>(version==5u?11u:version==4u?7u:version==3u?3u:1u)||
       (version==1u&&data[95]))return 0;
    for(n=0u;n<4u;n++)stored|=(uint32_t)data[12u+n]<<(8u*n);
    if(stored!=profile_settings_checksum(data))return 0;
    for(n=0u;n<3u;n++)if(data[16u+n*26u+24u]>3u||data[16u+n*26u+25u])return 0;
    return 1;
}

static int profile_settings_read_record(const char *path,uint8_t *data){
    uint8_t extra;size_t size;int bad;FILE *file;
    if(!path||!data)return 0;
    errno=0;file=open_file(path,0);
    if(!file){if(errno==ENOENT){profile_settings_defaults(data);return 1;}return 0;}
    size=fread(data,1u,TOPGEAR_PLAYER_SETTINGS_SIZE,file);
    if(size==TOPGEAR_PLAYER_SETTINGS_SIZE&&fread(&extra,1u,1u,file)!=0u)size++;
    bad=ferror(file);if(fclose(file))bad=1;if(bad)return 0;
    return profile_settings_validate(data,size);
}

int topgear_player_profile_file_read(const char *path,unsigned bank,TopGearPlayerProfile *profile){
    uint8_t record[TOPGEAR_PLAYER_SETTINGS_SIZE],*data;unsigned n;
    if(bank>1u||!profile||!profile_settings_read_record(path,record))return 0;
    data=record+(bank?68u:16u);memcpy(profile->name,data+16u,8u);profile->name[8]=0;
    profile->car=data[24];profile->manual=(uint8_t)((data[4]|data[5]|data[6]|data[7])!=0u);profile->controls=0u;
    for(n=0u;n<4u;n++)if(!memcmp(data,profile_control_schemes[n],4u)){profile->controls=(uint8_t)n;break;}
    return 1;
}

int topgear_player_profile_file_write(const char *path,unsigned bank,const TopGearPlayerProfile *profile){
    uint8_t record[TOPGEAR_PLAYER_SETTINGS_SIZE],*data;size_t name_length;unsigned n,version;
    if(bank>1u||!profile||profile->car>3u||profile->controls>3u||profile->manual>1u||profile->name[8])return 0;
    name_length=strlen(profile->name);
    if(name_length>8u)return 0;
    for(n=0u;n<name_length;n++)if(!((profile->name[n]>='A'&&profile->name[n]<='Z')||(profile->name[n]>='0'&&profile->name[n]<='9')||profile->name[n]==' '))return 0;
    if(!profile_settings_read_record(path,record))return 0;
    version=record[4];
    if(version<5u){
        uint8_t flags=version==1u?1u:(uint8_t)(record[95]&3u);
        uint8_t mode=version>=4u?(uint8_t)((record[95]>>2u)&3u):0u;
        record[4]=5u;record[95]=(uint8_t)(flags|(mode<<2u));
    }
    data=record+(bank?68u:16u);memcpy(data,profile_control_schemes[profile->controls],16u);
    if(!profile->manual)memset(data+4u,0,4u);
    memset(data+16u,' ',8u);memcpy(data+16u,profile->name,name_length);data[24]=profile->car;data[25]=0u;
    profile_settings_store_checksum(record);
    return topgear_player_settings_write_bytes(path,record);
}

int topgear_player_settings_load_file(TopGearRecomp *c,const char *path,uint8_t cache[TOPGEAR_PLAYER_SETTINGS_SIZE]){
    uint8_t b[TOPGEAR_PLAYER_SETTINGS_SIZE+1u];size_t size;int bad;FILE *f;
    if(!c||!path||!cache)return 0;
    memset(cache,0,TOPGEAR_PLAYER_SETTINGS_SIZE);
    errno=0;f=open_file(path,0);if(!f)return errno==ENOENT;
    size=fread(b,1u,sizeof(b),f);bad=ferror(f);if(fclose(f))bad=1;
    if(bad||!topgear_recomp_player_settings_import(c,b,size))return 0;
    memcpy(cache,b,TOPGEAR_PLAYER_SETTINGS_SIZE);return 1;
}
int topgear_settings_write_record(const char *path,const void *b,size_t size){
    char tmp[4096];FILE *f;int bad=0,written;
    if(!path||!b)return 0;
    written=snprintf(tmp,sizeof(tmp),"%s.tmp",path);
    if(written<0||(size_t)written>=sizeof(tmp))return 0;
    f=open_file(tmp,1);if(!f)return 0;
    if(fwrite(b,1u,size,f)!=size||fflush(f))bad=1;
#ifdef _WIN32
    if(!bad&&_commit(_fileno(f)))bad=1;
#else
    if(!bad&&fsync(fileno(f)))bad=1;
#endif
    if(fclose(f))bad=1;
    if(bad)return 0;
#ifdef _WIN32
    {
        wchar_t from[4096],to[4096];
        if(!MultiByteToWideChar(CP_UTF8,MB_ERR_INVALID_CHARS,tmp,-1,from,4096)||
           !MultiByteToWideChar(CP_UTF8,MB_ERR_INVALID_CHARS,path,-1,to,4096)||
           !MoveFileExW(from,to,MOVEFILE_REPLACE_EXISTING|MOVEFILE_WRITE_THROUGH))return 0;
    }
#else
    if(rename(tmp,path))return 0;
#endif
    return 1;
}

int topgear_player_settings_save_file(TopGearRecomp *c,const char *path,uint8_t cache[TOPGEAR_PLAYER_SETTINGS_SIZE]){
    uint8_t b[TOPGEAR_PLAYER_SETTINGS_SIZE];
    if(!c||!path||!cache)return 0;
    if(!topgear_recomp_player_settings_export(c,b,sizeof(b)))return 1;
    if(!memcmp(cache,b,sizeof(b)))return 1;
    if(!topgear_player_settings_write_bytes(path,b))return 0;
    memcpy(cache,b,sizeof(b));return 1;
}

int topgear_player_settings_write_bytes(const char *path,const uint8_t b[TOPGEAR_PLAYER_SETTINGS_SIZE]){return topgear_settings_write_record(path,b,TOPGEAR_PLAYER_SETTINGS_SIZE);}
int topgear_music_state_load_file(TopGearRecomp *c,const char *path,uint8_t cache[TOPGEAR_MUSIC_STATE_SIZE]){
    uint8_t b[TOPGEAR_MUSIC_STATE_SIZE+1u];size_t size;int bad;FILE *f;
    if(!c||!path||!cache)return 0;memset(cache,0,TOPGEAR_MUSIC_STATE_SIZE);
    errno=0;f=open_file(path,0);if(!f)return errno==ENOENT;
    size=fread(b,1u,sizeof(b),f);bad=ferror(f);if(fclose(f))bad=1;
    if(bad||!topgear_recomp_music_state_import(c,b,size))return 0;
    memcpy(cache,b,TOPGEAR_MUSIC_STATE_SIZE);return 1;
}
