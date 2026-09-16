/* Hidden native windows: deterministic fixture data, no desktop focus changes. */
#include "../frontend/windows/topgear_app_win32.c"
#define main store_contract_main
#include "test_time_trial_store.c"
#undef main
#define REQUIRE(x) do{if(!(x)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#x);return 1;}}while(0)
static int capture(HWND w,const char *path){
 RECT r;HDC dc,mem;HBITMAP bitmap;BITMAPINFO bi={0};BITMAPFILEHEADER header={0};void *bits;FILE*f;
 GetClientRect(w,&r);bi.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);bi.bmiHeader.biWidth=r.right;bi.bmiHeader.biHeight=-r.bottom;bi.bmiHeader.biPlanes=1;bi.bmiHeader.biBitCount=32;
 dc=GetDC(w);mem=CreateCompatibleDC(dc);bitmap=CreateDIBSection(dc,&bi,DIB_RGB_COLORS,&bits,NULL,0);SelectObject(mem,bitmap);
 FillRect(mem,&r,(HBRUSH)(COLOR_BTNFACE+1));if(!PrintWindow(w,mem,PW_CLIENTONLY))return 0;
 header.bfType=0x4D42;header.bfOffBits=sizeof(header)+sizeof(bi.bmiHeader);header.bfSize=header.bfOffBits+r.right*r.bottom*4;
 f=fopen(path,"wb");if(!f)return 0;fwrite(&header,sizeof(header),1,f);fwrite(&bi.bmiHeader,sizeof(bi.bmiHeader),1,f);fwrite(bits,4,(size_t)r.right*r.bottom,f);fclose(f);DeleteDC(mem);DeleteObject(bitmap);ReleaseDC(w,dc);return 1;
}
int main(int argc,char**argv){
 WNDCLASSW cls={0};LeaderboardDialog d={0};HWND dialog;TopGearTimeTrialStore *s;TopGearTimeTrialRun r,out;uint8_t rom[524288];void*blob;FILE*f;char err[256],path[1024];unsigned track,car,gear,rank;RECT rc,close;wchar_t text[128],expected[128];
 if(argc!=3&&argc!=4)return 2;g_instance=GetModuleHandleW(NULL);f=fopen(argv[1],"rb");REQUIRE(f&&fread(rom,1,sizeof(rom),f)==sizeof(rom));fclose(f);REQUIRE(topgear_app_create(&g_game,rom,sizeof(rom),err,sizeof(err)));
 cls.lpfnWndProc=leaderboard_proc;cls.hInstance=g_instance;cls.lpszClassName=L"LeaderboardHeadlessTest";cls.hbrBackground=(HBRUSH)(COLOR_BTNFACE+1);REQUIRE(RegisterClassW(&cls)||GetLastError()==ERROR_CLASS_ALREADY_EXISTS);
 /* A fresh TGTT store is a real, empty leaderboard. Its five display rows
    use zero placeholders without manufacturing valid race records. */
 dialog=CreateWindowExW(WS_EX_CONTROLPARENT,cls.lpszClassName,L"Leaderboard",WS_OVERLAPPEDWINDOW,0,0,850,500,NULL,NULL,g_instance,&d);REQUIRE(dialog);
 for(rank=0;rank<5;rank++){
  ListView_GetItemText(d.table,rank,1,text,128);REQUIRE(!wcscmp(text,L"No record"));
  ListView_GetItemText(d.table,rank,4,text,128);REQUIRE(!wcscmp(text,L"0:00:000"));
  for(car=5;car<8;car++){ListView_GetItemText(d.table,rank,car,text,128);REQUIRE(!wcscmp(text,L"00.0"));}
 }
 ShowWindow(dialog,SW_SHOWNOACTIVATE);UpdateWindow(dialog);snprintf(path,sizeof(path),"%s/leaderboard-empty.bmp",argv[2]);REQUIRE(capture(dialog,path));ShowWindow(dialog,SW_HIDE);DestroyWindow(dialog);memset(&d,0,sizeof(d));
 s=calloc(1,sizeof(*s));REQUIRE(s);topgear_time_trial_store_init(s);blob=malloc(topgear_time_trial_store_data_size());REQUIRE(blob);
 for(track=0;track<32;track++)for(car=0;car<4;car++)for(gear=0;gear<2;gear++)for(rank=0;rank<5;rank++){r=make_run(track,car,gear,100+track*3+car*20+gear*10+rank,"DRIVER01");REQUIRE(topgear_time_trial_store_insert(s,&r));}
 REQUIRE(topgear_time_trial_store_export(s,blob,topgear_time_trial_store_data_size()));REQUIRE(topgear_app_time_trial_data_import(g_game,blob,topgear_time_trial_store_data_size(),err,sizeof(err)));
 dialog=CreateWindowExW(WS_EX_CONTROLPARENT,cls.lpszClassName,L"Leaderboard",WS_OVERLAPPEDWINDOW,0,0,850,500,NULL,NULL,g_instance,&d);REQUIRE(dialog&&!IsWindowVisible(dialog));
 REQUIRE(SendMessageW(d.track,CB_GETCOUNT,0,0)==32&&SendMessageW(d.car,CB_GETCOUNT,0,0)==5&&SendMessageW(d.gear,CB_GETCOUNT,0,0)==3);
 REQUIRE(Header_GetItemCount(ListView_GetHeader(d.table))==8);
 for(track=0;track<32;track++)for(car=0;car<5;car++)for(gear=0;gear<3;gear++){
  SendMessageW(d.track,CB_SETCURSEL,track,0);SendMessageW(d.car,CB_SETCURSEL,car,0);SendMessageW(d.gear,CB_SETCURSEL,gear,0);leaderboard_refresh(&d);REQUIRE(ListView_GetItemCount(d.table)==5);
  for(rank=0;rank<5;rank++){REQUIRE(topgear_app_leaderboard(g_game,track,(int)car-1,(int)gear-1,rank,&out));leaderboard_time(out.total_time_ticks,expected,128);ListView_GetItemText(d.table,rank,4,text,128);REQUIRE(!wcscmp(text,expected));leaderboard_sector(out.best_sector3_ticks,expected,128);ListView_GetItemText(d.table,rank,7,text,128);REQUIRE(!wcscmp(text,expected));}
 }
 REQUIRE(GetNextDlgTabItem(dialog,d.track,FALSE)==d.car&&GetNextDlgTabItem(dialog,d.car,FALSE)==d.gear&&GetNextDlgTabItem(dialog,d.gear,FALSE)==d.table&&GetNextDlgTabItem(dialog,d.table,FALSE)==d.close);
 GetClientRect(dialog,&rc);GetWindowRect(d.close,&close);MapWindowPoints(NULL,dialog,(POINT*)&close,2);REQUIRE(abs((close.left+close.right)-rc.right)<=1);
 SendMessageW(d.track,CB_SETCURSEL,1,0);SendMessageW(d.car,CB_SETCURSEL,0,0);SendMessageW(d.gear,CB_SETCURSEL,2,0);leaderboard_refresh(&d);ShowWindow(dialog,SW_SHOWNOACTIVATE);UpdateWindow(dialog);snprintf(path,sizeof(path),"%s/leaderboard.bmp",argv[2]);REQUIRE(capture(dialog,path));ShowWindow(dialog,SW_HIDE);SendMessageW(dialog,WM_COMMAND,IDCANCEL,0);REQUIRE(!IsWindow(dialog));
 snprintf(path,sizeof(path),"%s\\legacy-time-trial.dat",argv[2]);MultiByteToWideChar(CP_UTF8,0,path,-1,g_time_trial_data_path,MAX_PATH);
 {uint8_t *legacy=calloc(1,107720);uint32_t header[8]={TOPGEAR_TT_STORE_MAGIC,5u|(168u<<16),32,4,5,32,1,0};WIN32_FIND_DATAW info;wchar_t pattern[PATH_CAPACITY],backup[PATH_CAPACITY];HANDLE find,locked;
  REQUIRE(legacy);memcpy(legacy,header,32);memcpy(legacy+32,&s->last_run,168);memcpy(legacy+200,s->records,sizeof(s->records));f=fopen(path,"wb");REQUIRE(f&&fwrite(legacy,1,107720,f)==107720);fclose(f);
  REQUIRE(load_time_trial_data_win32(g_game));_snwprintf_s(pattern,PATH_CAPACITY,_TRUNCATE,L"%s.v5-*.bak",g_time_trial_data_path);find=FindFirstFileW(pattern,&info);REQUIRE(find!=INVALID_HANDLE_VALUE);FindClose(find);wcscpy_s(backup,PATH_CAPACITY,g_time_trial_data_path);{wchar_t *slash=wcsrchr(backup,L'\\');if(!slash)slash=wcsrchr(backup,L'/');REQUIRE(slash);*slash=0;}join_wide_path(pattern,PATH_CAPACITY,backup,info.cFileName);{HANDLE saved=CreateFileW(pattern,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);DWORD got=0;void*copy=malloc(107720);if(saved==INVALID_HANDLE_VALUE)fwprintf(stderr,L"backup open failed: [%ls], error %lu\n",pattern,(unsigned long)GetLastError());REQUIRE(saved!=INVALID_HANDLE_VALUE&&copy&&ReadFile(saved,copy,107720,&got,NULL)&&got==107720&&!memcmp(copy,legacy,107720));CloseHandle(saved);free(copy);}
  locked=CreateFileW(g_time_trial_data_path,GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);REQUIRE(locked!=INVALID_HANDLE_VALUE&&!load_time_trial_data_win32(g_game));CloseHandle(locked);free(legacy);
 }
 topgear_app_destroy(g_game);g_game=NULL;snprintf(path,sizeof(path),"%s\\time-trial-times.dat",argv[2]);MultiByteToWideChar(CP_UTF8,0,path,-1,g_time_trial_data_path,MAX_PATH);f=fopen(path,"wb");REQUIRE(f);fwrite(blob,1,topgear_time_trial_store_data_size(),f);fclose(f);
 dialog=CreateWindowExW(WS_EX_CONTROLPARENT,cls.lpszClassName,L"Leaderboard",WS_OVERLAPPEDWINDOW,0,0,850,500,NULL,NULL,g_instance,&d);REQUIRE(dialog&&d.disk);ListView_GetItemText(d.table,0,1,text,128);REQUIRE(!wcscmp(text,L"DRIVER01"));DestroyWindow(dialog);
 f=fopen(path,"rb");REQUIRE(f);{void *copy=malloc(topgear_time_trial_store_data_size());REQUIRE(copy&&fread(copy,1,topgear_time_trial_store_data_size(),f)==topgear_time_trial_store_data_size()&&!memcmp(copy,blob,topgear_time_trial_store_data_size()));free(copy);}fclose(f);
 f=fopen(path,"wb");REQUIRE(f);fwrite("corrupt",1,7,f);fclose(f);
 dialog=CreateWindowExW(WS_EX_CONTROLPARENT,cls.lpszClassName,L"Leaderboard",WS_OVERLAPPEDWINDOW,0,0,850,500,NULL,NULL,g_instance,&d);REQUIRE(dialog);GetWindowTextW(d.notice,text,128);REQUIRE(wcsstr(text,L"could not be read"));DestroyWindow(dialog);f=fopen(path,"rb");REQUIRE(f);REQUIRE(fread(err,1,8,f)==7&&!memcmp(err,"corrupt",7));fclose(f);
 cls.lpfnWndProc=window_proc;cls.lpszClassName=L"ToolbarHeadlessTest";REQUIRE(RegisterClassW(&cls));g_paused=1;
 dialog=CreateWindowExW(0,cls.lpszClassName,L"Launcher",WS_OVERLAPPEDWINDOW,0,0,940,580,NULL,create_menu_bar(),g_instance,NULL);REQUIRE(dialog&&!IsWindowVisible(dialog));
 layout_controls(dialog);
 {HWND buttons[]={g_browse_button,g_pause_play_button,g_reset_button,g_audio_button,g_profile_button,g_leaderboard_button,g_settings_button,g_keys_button,g_fullscreen_checkbox,g_auto_run_checkbox};int right=0;HDC dc=GetDC(dialog);SIZE size;HFONT font=(HFONT)SendMessageW(g_leaderboard_button,WM_GETFONT,0,0);if(font)SelectObject(dc,font);GetTextExtentPoint32W(dc,L"Leaderboard",11,&size);REQUIRE(size.cx+16<=104);ReleaseDC(dialog,dc);GetClientRect(dialog,&rc);for(rank=0;rank<10;rank++){GetWindowRect(buttons[rank],&close);MapWindowPoints(NULL,dialog,(POINT*)&close,2);REQUIRE(close.left>=right&&close.right<=rc.right);right=close.right;}REQUIRE(GetMenuItemCount(GetMenu(dialog))==2);}
 snprintf(path,sizeof(path),"%s/toolbar.bmp",argv[2]);REQUIRE(capture(dialog,path));SetWindowLongPtrW(dialog,GWLP_WNDPROC,(LONG_PTR)DefWindowProcW);DestroyWindow(dialog);
 /* Optional end-to-end receipt: load the exact Data file produced or edited
    outside this process, then prove the frontend table streams tracks 0 and 1
    from those bytes and capture both views. */
 if(argc==4){
  void *external=NULL;long external_size;
  f=fopen(argv[3],"rb");REQUIRE(f&&!fseek(f,0,SEEK_END)&&(external_size=ftell(f))==(long)topgear_time_trial_store_data_size()&&!fseek(f,0,SEEK_SET));
  external=malloc((size_t)external_size);REQUIRE(external&&fread(external,1,(size_t)external_size,f)==(size_t)external_size);fclose(f);
  REQUIRE(topgear_app_create(&g_game,rom,sizeof(rom),err,sizeof(err))&&topgear_app_time_trial_data_import(g_game,external,(size_t)external_size,err,sizeof(err)));
  memset(&d,0,sizeof(d));dialog=CreateWindowExW(WS_EX_CONTROLPARENT,L"LeaderboardHeadlessTest",L"Leaderboard",WS_OVERLAPPEDWINDOW,0,0,850,500,NULL,NULL,g_instance,&d);REQUIRE(dialog);
  for(track=0;track<2;track++){
   SendMessageW(d.track,CB_SETCURSEL,track,0);SendMessageW(d.car,CB_SETCURSEL,0,0);SendMessageW(d.gear,CB_SETCURSEL,0,0);leaderboard_refresh(&d);
   REQUIRE(topgear_app_leaderboard(g_game,track,-1,-1,0,&out));
   leaderboard_time(out.total_time_ticks,expected,128);ListView_GetItemText(d.table,0,4,text,128);REQUIRE(!wcscmp(text,expected));
   leaderboard_sector(out.best_sector1_ticks,expected,128);ListView_GetItemText(d.table,0,5,text,128);REQUIRE(!wcscmp(text,expected));
   ShowWindow(dialog,SW_SHOWNOACTIVATE);UpdateWindow(dialog);snprintf(path,sizeof(path),"%s/streamed-track-%u.bmp",argv[2],track);REQUIRE(capture(dialog,path));ShowWindow(dialog,SW_HIDE);
  }
  DestroyWindow(dialog);topgear_app_destroy(g_game);g_game=NULL;free(external);
 }
 free(blob);free(s);puts("PASS hidden Leaderboard: zero placeholders, 480 filters, rows/times, tab order, centered Close, read-only/corrupt/external Data streaming; toolbar fits; screenshots");return 0;
}
