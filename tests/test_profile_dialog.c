#include "../static-recomp/internal/topgear_internal.h"
/* Native dialog contract tested with an unshown window: no desktop focus changes. */
#include "../frontend/windows/topgear_app_win32.c"
#include <stdio.h>
#define REQUIRE(x) do{if(!(x)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#x);return 1;}}while(0)
static void discard_audio(TopGearApp *app,void *opaque){(void)opaque;(void)topgear_app_audio_discard(app);}
static int prompt_answer;
static int test_reset_prompt(HWND w){(void)w;return prompt_answer;}
static int capture(HWND w,const char *path){
 RECT r;HDC dc,mem;HBITMAP bitmap;BITMAPINFO bi={0};BITMAPFILEHEADER header={0};void *bits;FILE*f;
 GetClientRect(w,&r);bi.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);bi.bmiHeader.biWidth=r.right;bi.bmiHeader.biHeight=-r.bottom;bi.bmiHeader.biPlanes=1;bi.bmiHeader.biBitCount=32;
 dc=GetDC(w);mem=CreateCompatibleDC(dc);bitmap=CreateDIBSection(dc,&bi,DIB_RGB_COLORS,&bits,NULL,0);SelectObject(mem,bitmap);FillRect(mem,&r,(HBRUSH)(COLOR_BTNFACE+1));
 if(!PrintWindow(w,mem,PW_CLIENTONLY))return 0;
 header.bfType=0x4D42;header.bfOffBits=sizeof(header)+sizeof(bi.bmiHeader);header.bfSize=header.bfOffBits+r.right*r.bottom*4;f=fopen(path,"wb");if(!f)return 0;fwrite(&header,sizeof(header),1,f);fwrite(&bi.bmiHeader,sizeof(bi.bmiHeader),1,f);fwrite(bits,4,(size_t)r.right*r.bottom,f);fclose(f);DeleteDC(mem);DeleteObject(bitmap);ReleaseDC(w,dc);return 1;
}
static uint16_t confirm_imported_auto_input(unsigned frame,unsigned mode){
 if(frame>=1560u&&frame<1680u)return 0x1000u;
 if(mode>=1u&&frame>=1920u&&frame<1935u)return 0x0400u;
 if(mode>=2u&&frame>=1965u&&frame<1980u)return 0x0400u;
 if(frame>=2010u&&frame<2040u)return 0x0080u;
 if(frame>=2070u&&frame<2130u)return 0x0080u;
 if(frame>=2220u&&frame<2232u)return 0x0080u;
 if((frame>=2280u&&frame<2295u)||(frame>=2310u&&frame<2325u)||
    (frame>=2340u&&frame<2355u)||(frame>=2370u&&frame<2385u))return 0x0400u;
 if((frame>=2400u&&frame<2415u)||(frame>=2430u&&frame<2445u)||
    (frame>=2460u&&frame<2475u)||(frame>=2490u&&frame<2505u))return 0x0100u;
 if(frame>=2550u&&frame<2595u)return 0x0080u;
 /* Do not press Right on the gearbox screen: confirm the imported choice. */
 if(frame>=2910u&&frame<2970u)return 0x0080u;
 if(frame>=3270u&&frame<3330u)return 0x0080u;
 if(frame>=3630u&&frame<3690u)return 0x0080u;
 return 0u;
}
int main(int argc,char **argv){
 WNDCLASSW cls={0};ProfileDialog state={0};HWND dialog,next;uint8_t rom[524288];FILE *f;char error[256],data_dir[1024];TopGearPlayerProfile p,q;TopGearAppFrameResult app_frame;int n;
 if(argc<3||argc>5)return 2;f=fopen(argv[1],"rb");REQUIRE(f);REQUIRE(fread(rom,1,sizeof(rom),f)==sizeof(rom));fclose(f);
 (void)remove(argv[2]);
 g_instance=GetModuleHandleW(NULL);g_game=NULL;
 snprintf(g_player_settings_path,sizeof(g_player_settings_path),"%s",argv[2]);
 snprintf(data_dir,sizeof(data_dir),"%s",argv[2]);{char *slash=strrchr(data_dir,'/');if(!slash)slash=strrchr(data_dir,'\\');REQUIRE(slash);*slash=0;}REQUIRE(MultiByteToWideChar(CP_UTF8,0,data_dir,-1,g_data_directory,PATH_CAPACITY));
 {
  const wchar_t *escape=wcsstr(g_welcome_text,L"Escape -"),*f1=wcsstr(g_welcome_text,L"F1 -"),*f2=wcsstr(g_welcome_text,L"F2 -"),*f3=wcsstr(g_welcome_text,L"F3 -"),*f4=wcsstr(g_welcome_text,L"F4 -"),*f5=wcsstr(g_welcome_text,L"F5 -"),*f6=wcsstr(g_welcome_text,L"F6 -"),*f7=wcsstr(g_welcome_text,L"F7 -"),*f8=wcsstr(g_welcome_text,L"F8 -"),*one=wcsstr(g_welcome_text,L"1 - Save"),*two=wcsstr(g_welcome_text,L"2 - Load");
  REQUIRE(escape&&escape<one&&one<two&&two<f1&&f1<f2&&f2<f3&&f3<f4&&f4<f5&&f5<f6&&f6<f7&&f7<f8);
 }
 cls.lpfnWndProc=profile_proc;cls.hInstance=g_instance;cls.lpszClassName=L"ProfileHeadlessTest";cls.hbrBackground=(HBRUSH)(COLOR_BTNFACE+1);REQUIRE(RegisterClassW(&cls));
 dialog=CreateWindowExW(WS_EX_CONTROLPARENT,cls.lpszClassName,L"Profile",WS_OVERLAPPED,CW_USEDEFAULT,CW_USEDEFAULT,490,465,NULL,NULL,g_instance,&state);REQUIRE(dialog);
 {wchar_t initial[9];GetWindowTextW(state.name,initial,9);REQUIRE(!wcscmp(initial,L"PLAYER 1"));}
 REQUIRE(!IsWindowVisible(dialog));REQUIRE(SendMessageW(state.name,EM_GETLIMITTEXT,0,0)==8);
 REQUIRE(SendMessageW(state.car,CB_GETCOUNT,0,0)==4&&SendMessageW(state.controls,CB_GETCOUNT,0,0)==4);
 REQUIRE(!(GetWindowLongPtrW(state.description,GWL_STYLE)&WS_TABSTOP));
 next=GetNextDlgTabItem(dialog,state.controls,FALSE);REQUIRE(GetDlgCtrlID(next)==IDOK);
 next=GetNextDlgTabItem(dialog,next,FALSE);REQUIRE(GetDlgCtrlID(next)==IDCANCEL);
 {wchar_t label[16];GetWindowTextW(GetDlgItem(dialog,IDOK),label,16);REQUIRE(!wcscmp(label,L"&Save"));}
 if(argc>=4){ShowWindow(dialog,SW_SHOWNOACTIVATE);UpdateWindow(dialog);REQUIRE(capture(dialog,argv[3]));ShowWindow(dialog,SW_HIDE);if(argc==5){DestroyWindow(dialog);puts("PASS Profile visual capture");return 0;}}
 REQUIRE(topgear_player_profile_file_read(argv[2],1,&q));
 for(n=0;n<4;n++){wchar_t text[256];SendMessageW(state.controls,CB_SETCURSEL,n,0);SendMessageW(dialog,WM_COMMAND,MAKEWPARAM(4105,CBN_SELCHANGE),0);GetWindowTextW(state.description,text,256);REQUIRE(!wcscmp(text,profile_controls[n]));}
 SetWindowTextW(state.name,L"Driver01");SendMessageW(state.car,CB_SETCURSEL,2,0);SendMessageW(state.automatic,BM_CLICK,0,0);
 REQUIRE(SendMessageW(state.automatic,BM_GETCHECK,0,0)==BST_CHECKED&&SendMessageW(state.manual,BM_GETCHECK,0,0)==BST_UNCHECKED);
 SendMessageW(dialog,WM_COMMAND,IDOK,0);REQUIRE(!IsWindow(dialog));REQUIRE(topgear_player_profile_file_read(argv[2],0,&p));REQUIRE(!memcmp(p.name,"DRIVER01",8)&&p.car==2&&p.controls==3&&!p.manual);
 REQUIRE(topgear_player_profile_file_read(argv[2],1,&p));REQUIRE(!memcmp(&p,&q,sizeof(p)));
 memset(&state,0,sizeof(state));
 dialog=CreateWindowExW(WS_EX_CONTROLPARENT,cls.lpszClassName,L"Profile",WS_OVERLAPPED,0,0,490,465,NULL,NULL,g_instance,&state);REQUIRE(dialog);
 SendMessageW(state.bank,CB_SETCURSEL,1,0);SendMessageW(dialog,WM_COMMAND,MAKEWPARAM(4100,CBN_SELCHANGE),0);
 SetWindowTextW(state.name,L"TRIAL001");SendMessageW(state.car,CB_SETCURSEL,1,0);SendMessageW(state.controls,CB_SETCURSEL,2,0);
 SendMessageW(state.automatic,BM_CLICK,0,0);
 REQUIRE(SendMessageW(state.automatic,BM_GETCHECK,0,0)==BST_CHECKED&&SendMessageW(state.manual,BM_GETCHECK,0,0)==BST_UNCHECKED);
 SendMessageW(dialog,WM_COMMAND,IDOK,0);REQUIRE(!IsWindow(dialog));
 REQUIRE(topgear_player_profile_file_read(argv[2],1,&q)&&!memcmp(q.name,"TRIAL001",8)&&q.car==1&&q.controls==2&&!q.manual);
 /* The saved frontend record is imported only when the ROM starts. */
 REQUIRE(topgear_app_create(&g_game,rom,sizeof(rom),error,sizeof(error)));REQUIRE(topgear_app_player_settings_load(g_game,argv[2]));
 REQUIRE(topgear_app_advance_streamed(g_game,0,1560,discard_audio,NULL,&app_frame));
 REQUIRE(topgear_app_advance_streamed(g_game,0x1000,120,discard_audio,NULL,&app_frame));
 REQUIRE(topgear_app_advance_streamed(g_game,0,220,discard_audio,NULL,&app_frame));
 REQUIRE(topgear_app_profile_read(g_game,0,&p));REQUIRE(!memcmp(p.name,"DRIVER01",8)&&p.car==2&&p.controls==3&&!p.manual);
 /* A cold core cannot use the remodeled-menu export.  Saving must fall back
    to the canonical profile record, update Data, and offer the reset choice. */
 REQUIRE(topgear_app_reset(g_game,error,sizeof(error)));
 profile_reset_prompt=test_reset_prompt;prompt_answer=0;
 memset(&state,0,sizeof(state));
 dialog=CreateWindowExW(WS_EX_CONTROLPARENT,cls.lpszClassName,L"Profile",WS_OVERLAPPED,0,0,490,465,NULL,NULL,g_instance,&state);REQUIRE(dialog);
 SendMessageW(state.bank,CB_SETCURSEL,1,0);SendMessageW(dialog,WM_COMMAND,MAKEWPARAM(4100,CBN_SELCHANGE),0);
 SetWindowTextW(state.name,L"SAVEDNO");
 SendMessageW(dialog,WM_COMMAND,IDOK,0);REQUIRE(!IsWindow(dialog)&&!state.reset_requested);
 REQUIRE(topgear_player_profile_file_read(argv[2],1,&q)&&!memcmp(q.name,"SAVEDNO ",8));
 prompt_answer=1;memset(&state,0,sizeof(state));
 dialog=CreateWindowExW(WS_EX_CONTROLPARENT,cls.lpszClassName,L"Profile",WS_OVERLAPPED,0,0,490,465,NULL,NULL,g_instance,&state);REQUIRE(dialog);
 SendMessageW(state.bank,CB_SETCURSEL,1,0);SendMessageW(dialog,WM_COMMAND,MAKEWPARAM(4100,CBN_SELCHANGE),0);SetWindowTextW(state.name,L"RESET001");
 SendMessageW(dialog,WM_COMMAND,IDOK,0);REQUIRE(!IsWindow(dialog)&&state.reset_requested);
 REQUIRE(topgear_player_profile_file_read(argv[2],1,&q)&&!memcmp(q.name,"RESET001",8)&&q.car==1&&q.controls==2&&!q.manual);
 REQUIRE(topgear_app_reset(g_game,error,sizeof(error)));
 REQUIRE(topgear_app_profile_read(g_game,1,&p)&&!memcmp(p.name,"RESET001",8)&&p.car==1&&p.controls==2&&!p.manual);
 /* Match the frontend: it asks the core to flush settings every rendered frame. */
 for(n=0;n<12;n++){
  REQUIRE(topgear_app_advance_streamed(g_game,0,1,discard_audio,NULL,&app_frame));
  REQUIRE(topgear_app_player_settings_save(g_game,argv[2]));
 }
 topgear_app_destroy(g_game);g_game=NULL;
 REQUIRE(topgear_player_profile_file_read(argv[2],0,&p));
 REQUIRE(!memcmp(p.name,"DRIVER01",8)&&p.car==2&&p.controls==3&&!p.manual);
 REQUIRE(topgear_player_profile_file_read(argv[2],1,&p));
 REQUIRE(!memcmp(p.name,"RESET001",8)&&p.car==1&&p.controls==2&&!p.manual);
 /* Load the actual frontend-written record into the game and enter each menu. */
 {TopGearRecomp *core=NULL;TopGearRecompFrameResult frame;uint8_t record[96];unsigned k,mode;uint16_t selected;
 f=fopen(argv[2],"rb");REQUIRE(f&&fread(record,1,96,f)==96);fclose(f);
 REQUIRE(topgear_recomp_create(&core,rom,sizeof(rom),error,sizeof(error)));
 REQUIRE(topgear_recomp_player_settings_import(core,record,96));
 for(k=0;k<1900;k++){REQUIRE(topgear_recomp_advance_headless(core,k>=1560&&k<1680?0x1000:0,0,1,&frame));topgear_recomp_audio_clear(core);}
 for(mode=0;mode<3;mode++){
 core->mod_menu_remodel_page=0;core->mod_menu_remodel_selection=(uint8_t)mode;
 (void)tg_mod_menu_remodel_handle_input(core,0x0080,&selected);
 REQUIRE(core->mod_menu_remodel_page==mode+1);
 REQUIRE(!memcmp(core->wram+0x1F86,mode==2?q.name:"DRIVER01",8));
 REQUIRE(core->wram[0x1F8F]==(mode==2?1:2));
 REQUIRE(!memcmp(core->wram+0x1F76,rom+0x6C656+(mode==2?2:3)*16,4));
 REQUIRE(core->wram[0x1F7A]==0&&core->wram[0x1F7B]==0&&core->wram[0x1F7C]==0&&core->wram[0x1F7D]==0);
 }
 topgear_recomp_destroy(core);}
 /* The original player-setup journey must preserve imported Automatic when
    the user confirms the highlighted gearbox without changing it. */
 {TopGearRecomp *core=NULL;TopGearRecompFrameResult frame;uint8_t record[96];unsigned k,mode;
 f=fopen(argv[2],"rb");REQUIRE(f&&fread(record,1,96,f)==96);fclose(f);
 for(mode=0;mode<3;mode++){
  REQUIRE(topgear_recomp_create(&core,rom,sizeof(rom),error,sizeof(error)));
  REQUIRE(topgear_recomp_player_settings_import(core,record,96));
  for(k=0;k<3750;k++){REQUIRE(topgear_recomp_advance_headless(core,confirm_imported_auto_input(k,mode),0,1,&frame));topgear_recomp_audio_clear(core);}
  REQUIRE(core->wram[0x1F7A]==0&&core->wram[0x1F7B]==0&&core->wram[0x1F7C]==0&&core->wram[0x1F7D]==0);
  topgear_recomp_destroy(core);core=NULL;
 }}
 puts("PASS Profile dialog before/during ROM: named default profiles, Save/Cancel with tested No/Yes reset choices, cold-core Data fallback and reset import, four cars/schemes, durable Career/Rally sharing and independent TT");return 0;
}

