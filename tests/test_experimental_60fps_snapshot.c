#include "topgear_app_core.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL %u: %s (%s)\n",(unsigned)__LINE__,#x,error);return 1;}}while(0)
int main(int argc,char **argv){
 TopGearApp *app;unsigned char rom[524288];FILE*f;char error[256]={0},on[2048],off[2048];
 CHECK(argc==3);f=fopen(argv[1],"rb");CHECK(f&&fread(rom,1,sizeof(rom),f)==sizeof(rom));fclose(f);
 CHECK(topgear_app_create(&app,rom,sizeof(rom),error,sizeof(error)));CHECK(!topgear_app_experimental_60fps_enabled(app));
 topgear_app_set_experimental_60fps_enabled(app,1);CHECK(topgear_app_reset(app,error,sizeof(error))&&topgear_app_experimental_60fps_enabled(app));
 snprintf(on,sizeof(on),"%s/mode-on.scsnap",argv[2]);snprintf(off,sizeof(off),"%s/mode-off.scsnap",argv[2]);
 CHECK(topgear_app_snapshot_save(app,on,error,sizeof(error)));topgear_app_set_experimental_60fps_enabled(app,0);
 CHECK(topgear_app_snapshot_load(app,on,error,sizeof(error))&&!topgear_app_experimental_60fps_enabled(app));
 CHECK(topgear_app_snapshot_save(app,off,error,sizeof(error)));topgear_app_set_experimental_60fps_enabled(app,1);
 CHECK(topgear_app_snapshot_load(app,off,error,sizeof(error))&&topgear_app_experimental_60fps_enabled(app));
 topgear_app_set_experimental_60fps_enabled(app,0);CHECK(topgear_app_reset(app,error,sizeof(error))&&!topgear_app_experimental_60fps_enabled(app));
 topgear_app_destroy(app);puts("PASS experimental mode survives reset; loading a snapshot preserves the current frontend toggle in both directions");return 0;
}
