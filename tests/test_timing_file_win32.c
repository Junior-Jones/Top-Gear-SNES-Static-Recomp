#include "topgear_time_trial_file_win32.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#x);return 1;}}while(0)
static void discard(TopGearApp *a,void *u){(void)u;(void)topgear_app_audio_discard(a);}
static int write_file(const wchar_t *p,const void *b,size_t n){FILE *f=_wfopen(p,L"wb");int ok;if(!f)return 0;ok=fwrite(b,1,n,f)==n;if(fclose(f))ok=0;return ok;}
static int equal_file(const wchar_t *p,const void *b,size_t n){unsigned char *v;FILE *f=_wfopen(p,L"rb");int ok;if(!f)return 0;v=malloc(n+1);ok=v&&fread(v,1,n+1,f)==n&&!memcmp(v,b,n);free(v);fclose(f);return ok;}
int main(int argc,char **argv){
    TopGearApp *app;TopGearTimeTrialFileWin32 state={0};TopGearAppFrameResult result;
    unsigned char rom[524288],*good,*bad,*memory;size_t bytes=topgear_app_time_trial_data_size();
    wchar_t path[4096],missing[4096];FILE *f;HANDLE lock;unsigned test;char error[256];
    if(argc!=5)return 2;
    good=malloc(bytes);bad=malloc(bytes+1);memory=malloc(bytes);CHECK(good&&bad&&memory);
    f=fopen(argv[1],"rb");CHECK(f&&fread(rom,1,sizeof(rom),f)==sizeof(rom));fclose(f);
    f=fopen(argv[3],"rb");CHECK(f&&fread(good,1,bytes,f)==bytes);fclose(f);
    swprintf(path,4096,L"%hs/time-trial.dat",argv[2]);swprintf(missing,4096,L"%hs/new-user.dat",argv[2]);
    CHECK(topgear_app_create(&app,rom,sizeof(rom),error,sizeof(error)));
    CHECK(write_file(path,good,bytes));
    CHECK(!topgear_time_trial_file_save(app,path,&state)); /* Cannot save before load. */
    CHECK(topgear_time_trial_file_load(app,path,&state)&&state.loaded);
    for(test=0;test<7;test++){
        size_t size=bytes;memcpy(bad,good,bytes);bad[bytes]=1;
        if(test==0)bad[0]^=0x55;
        if(test==1)size=0;
        if(test==2)size=7;
        if(test==3)size=bytes-1;
        if(test==4)size=bytes+1;
        if(test==5)bad[32+10]=32; /* Invalid last-run ownership. */
        if(test==6)bad[32+64]^=1; /* Invalid sector sum. */
        CHECK(write_file(path,bad,size));
        CHECK(!topgear_time_trial_file_load(app,path,&state)&&!state.loaded);
        CHECK(!topgear_time_trial_file_save(app,path,&state));
        CHECK(equal_file(path,bad,size));
        CHECK(topgear_app_time_trial_data_export(app,memory,bytes)&&!memcmp(memory,good,bytes));
    }
    CHECK(write_file(path,good,bytes));
    lock=CreateFileW(path,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);CHECK(lock!=INVALID_HANDLE_VALUE);
    CHECK(!topgear_time_trial_file_load(app,path,&state)&&!state.loaded);
    CHECK(!topgear_time_trial_file_save(app,path,&state));CloseHandle(lock);CHECK(equal_file(path,good,bytes));
    CHECK(topgear_time_trial_file_load(app,path,&state)&&state.loaded);
    CHECK(topgear_app_snapshot_load(app,argv[4],error,sizeof(error)));
    CHECK(topgear_app_advance_streamed(app,0,1,discard,NULL,&result));
    CHECK(topgear_app_time_trial_data_dirty(app));
    CHECK(SetFileAttributesW(path,FILE_ATTRIBUTE_READONLY));
    CHECK(!topgear_time_trial_file_save(app,path,&state));
    CHECK(equal_file(path,good,bytes)&&topgear_app_time_trial_data_dirty(app));
    CHECK(SetFileAttributesW(path,FILE_ATTRIBUTE_NORMAL));
    CHECK(topgear_time_trial_file_save(app,path,&state)&&!topgear_app_time_trial_data_dirty(app));
    CHECK(topgear_time_trial_file_load(app,path,&state));
    DeleteFileW(missing);
    CHECK(topgear_time_trial_file_load(app,missing,&state)&&state.loaded);
    CHECK(topgear_time_trial_file_save(app,missing,&state));
    topgear_app_destroy(app);free(good);free(bad);free(memory);
    puts("PASS timing file: corrupt/empty/truncated/trailing/invalid timing and locked loads preserve disk and memory; failed replacement preserves pending run; recovery, durable save and new file work");return 0;
}
