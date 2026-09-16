/* Track labels generated from Data/track-catalog.json, ordered by native course ID. */
static const wchar_t *const leaderboard_tracks[32]={
L"USA - LAS VEGAS",
L"USA - LOS ANGELES",
L"USA - NEW YORK",
L"USA - SAN FRANCISCO",
L"South America - RIO",
L"South America - MACHU PICCHU",
L"South America - CHICHEN ITZA",
L"South America - RAIN FOREST",
L"Japan - TOKYO",
L"Japan - HIROSHIMA",
L"Japan - YOKOHAMA",
L"Japan - KYOTO",
L"Germany - MUNICH",
L"Germany - COLOGNE",
L"Germany - BLACK FOREST",
L"Germany - FRANKFURT",
L"Scandinavia - STOCKHOLM",
L"Scandinavia - COPENHAGEN",
L"Scandinavia - HELSINKI",
L"Scandinavia - OSLO",
L"France - PARIS",
L"France - NICE",
L"France - BORDEAUX",
L"France - MONACO",
L"Italy - PISA",
L"Italy - ROME",
L"Italy - SICILY",
L"Italy - FLORENCE",
L"United Kingdom - LONDON",
L"United Kingdom - SHEFFIELD",
L"United Kingdom - LOCH NESS",
L"United Kingdom - STONEHENGE"
};
static const wchar_t *const leaderboard_cars[]={L"Cannibal",L"Sidewinder",L"Razor",L"Weasel"};
typedef struct LeaderboardDialog {HWND track,car,gear,table,close,notice;TopGearTimeTrialStore *disk;} LeaderboardDialog;
static void leaderboard_time(uint32_t ticks,wchar_t *out,size_t cap){
    unsigned sec=ticks/60u,ms=((ticks%60u)*1000u+30u)/60u;
    _snwprintf_s(out,cap,_TRUNCATE,L"%u:%02u.%03u",sec/60u,sec%60u,ms);
}
static void leaderboard_sector(uint32_t ticks,wchar_t *out,size_t cap){
    unsigned tenths=(unsigned)(((uint64_t)ticks*10u+30u)/60u);
    _snwprintf_s(out,cap,_TRUNCATE,L"%02u.%1u",tenths/10u,tenths%10u);
}
static void leaderboard_refresh(LeaderboardDialog *d){
    unsigned rank,n;int track=(int)SendMessageW(d->track,CB_GETCURSEL,0,0),car=(int)SendMessageW(d->car,CB_GETCURSEL,0,0)-1,gear=(int)SendMessageW(d->gear,CB_GETCURSEL,0,0)-1;
    ListView_DeleteAllItems(d->table);
    for(rank=0;rank<5;rank++){
        TopGearTimeTrialRun r;wchar_t value[8][48];LVITEMW item={0};int found;
        for(n=0;n<8;n++)wcscpy_s(value[n],48,L"-");
        wcscpy_s(value[4],48,L"0:00:000");
        wcscpy_s(value[5],48,L"00.0");wcscpy_s(value[6],48,L"00.0");wcscpy_s(value[7],48,L"00.0");
        _snwprintf_s(value[0],48,_TRUNCATE,L"%u%s",rank+1,rank==0?L"st":rank==1?L"nd":rank==2?L"rd":L"th");
        found=g_game?topgear_app_leaderboard(g_game,(unsigned)track,car,gear,rank,&r):topgear_time_trial_store_filtered_record(d->disk,(unsigned)track,car,gear,rank,&r);
        if(found){
            for(n=0;n<8;n++)value[1][n]=(wchar_t)(unsigned char)r.name[n];value[1][8]=0;
            wcscpy_s(value[2],48,leaderboard_cars[r.car_id]);wcscpy_s(value[3],48,r.gearbox?L"Manual":L"Automatic");
            leaderboard_time(r.total_time_ticks,value[4],48);leaderboard_sector(r.best_sector1_ticks,value[5],48);leaderboard_sector(r.best_sector2_ticks,value[6],48);leaderboard_sector(r.best_sector3_ticks,value[7],48);
        }else wcscpy_s(value[1],48,L"No record");
        item.mask=LVIF_TEXT;item.iItem=(int)rank;item.pszText=value[0];SendMessageW(d->table,LVM_INSERTITEMW,0,(LPARAM)&item);
        for(n=1;n<8;n++){item.iSubItem=(int)n;item.pszText=value[n];SendMessageW(d->table,LVM_SETITEMTEXTW,rank,(LPARAM)&item);}
    }
}
static void leaderboard_layout(HWND w,LeaderboardDialog *d){
    RECT r;int width,height,last_column;GetClientRect(w,&r);width=r.right;height=r.bottom;
    MoveWindow(d->track,12,34,width-24,220,TRUE);
    MoveWindow(d->table,12,136,width-24,height-220,TRUE);
    last_column=width-24-(48+94+100+86+110+100+100)-4;
    ListView_SetColumnWidth(d->table,7,last_column<100?100:last_column);
    MoveWindow(d->notice,12,height-76,width-24,24,TRUE);
    MoveWindow(d->close,(width-96)/2,height-44,96,30,TRUE);
}
static LRESULT CALLBACK leaderboard_proc(HWND w,UINT m,WPARAM wp,LPARAM lp){
    LeaderboardDialog *d=(LeaderboardDialog*)GetWindowLongPtrW(w,GWLP_USERDATA);unsigned n;
    if(m==WM_CREATE){
        static const wchar_t *const labels[]={L"Place",L"Name",L"Car",L"Gearbox",L"Total",L"Sector 1",L"Sector 2",L"Sector 3"};
        static const int widths[]={48,94,100,86,110,100,100,100};
        INITCOMMONCONTROLSEX ic={sizeof(ic),ICC_LISTVIEW_CLASSES};InitCommonControlsEx(&ic);
        d=(LeaderboardDialog*)((CREATESTRUCTW*)lp)->lpCreateParams;SetWindowLongPtrW(w,GWLP_USERDATA,(LONG_PTR)d);
        profile_control(w,L"STATIC",L"&Track",0,12,12,200,20,0);
        d->track=profile_control(w,L"COMBOBOX",L"",WS_TABSTOP|CBS_DROPDOWNLIST,12,34,780,220,4200);
        for(n=0;n<32;n++)SendMessageW(d->track,CB_ADDSTRING,0,(LPARAM)leaderboard_tracks[n]);SendMessageW(d->track,CB_SETCURSEL,0,0);
        profile_control(w,L"STATIC",L"C&ar",0,12,70,200,20,0);
        d->car=profile_control(w,L"COMBOBOX",L"",WS_TABSTOP|CBS_DROPDOWNLIST,12,92,300,180,4201);
        SendMessageW(d->car,CB_ADDSTRING,0,(LPARAM)L"All cars");for(n=0;n<4;n++)SendMessageW(d->car,CB_ADDSTRING,0,(LPARAM)leaderboard_cars[n]);SendMessageW(d->car,CB_SETCURSEL,0,0);
        profile_control(w,L"STATIC",L"&Gearbox",0,336,70,200,20,0);
        d->gear=profile_control(w,L"COMBOBOX",L"",WS_TABSTOP|CBS_DROPDOWNLIST,336,92,250,180,4202);
        SendMessageW(d->gear,CB_ADDSTRING,0,(LPARAM)L"All gearboxes");SendMessageW(d->gear,CB_ADDSTRING,0,(LPARAM)L"Automatic");SendMessageW(d->gear,CB_ADDSTRING,0,(LPARAM)L"Manual");SendMessageW(d->gear,CB_SETCURSEL,0,0);
        d->table=profile_control(w,WC_LISTVIEWW,L"Time Trial Top 5",WS_TABSTOP|LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS,12,136,800,220,4203);
        ListView_SetExtendedListViewStyle(d->table,LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_DOUBLEBUFFER);
        for(n=0;n<8;n++){LVCOLUMNW col={0};col.mask=LVCF_TEXT|LVCF_WIDTH;col.pszText=(wchar_t*)labels[n];col.cx=widths[n];SendMessageW(d->table,LVM_INSERTCOLUMNW,n,(LPARAM)&col);}
        d->notice=profile_control(w,L"STATIC",L"Top 5 by total time. Sectors show the fastest sector from any lap in that run.",0,12,370,800,24,4204);
        d->close=profile_control(w,L"BUTTON",L"&Close",WS_TABSTOP|BS_DEFPUSHBUTTON,360,410,96,30,IDCANCEL);
        if(!g_game){
            FILE *f;d->disk=(TopGearTimeTrialStore*)calloc(1,sizeof(*d->disk));
            if((f=_wfopen(g_time_trial_data_path,L"rb"))!=NULL){
                long len;void *data=NULL;char err[256];int ok=0;
                if(!fseek(f,0,SEEK_END)&&(len=ftell(f))>0&&len<=1024*1024&&!fseek(f,0,SEEK_SET)&&(data=malloc((size_t)len))!=NULL&&fread(data,1,(size_t)len,f)==(size_t)len)
                    ok=topgear_time_trial_store_import(d->disk,data,(size_t)len,err,sizeof(err));
                free(data);fclose(f);if(!ok)SetWindowTextW(d->notice,L"Saved Time Trial data could not be read. The file has not been changed.");
            }else {DWORD attributes=GetFileAttributesW(g_time_trial_data_path),reason=GetLastError();if(attributes!=INVALID_FILE_ATTRIBUTES||(reason!=ERROR_FILE_NOT_FOUND&&reason!=ERROR_PATH_NOT_FOUND))SetWindowTextW(d->notice,L"Saved Time Trial data could not be read. The file has not been changed.");}
        }
        leaderboard_refresh(d);leaderboard_layout(w,d);return 0;
    }
    if(m==WM_COMMAND){if(LOWORD(wp)==IDCANCEL||LOWORD(wp)==IDOK){DestroyWindow(w);return 0;}if(HIWORD(wp)==CBN_SELCHANGE&&d){leaderboard_refresh(d);return 0;}}
    if(m==WM_SIZE&&d){leaderboard_layout(w,d);return 0;}
    if(m==WM_GETMINMAXINFO){((MINMAXINFO*)lp)->ptMinTrackSize.x=850;((MINMAXINFO*)lp)->ptMinTrackSize.y=440;return 0;}
    if(m==WM_CLOSE){DestroyWindow(w);return 0;}
    if(m==WM_DESTROY&&d){free(d->disk);d->disk=NULL;return 0;}
    return DefWindowProcW(w,m,wp,lp);
}
static void show_leaderboard(void){
    WNDCLASSW cls={0};LeaderboardDialog state={0};MSG msg={0};HWND dialog,previous=GetFocus();int resume=g_game&&!g_paused,result=1;
    if(resume)pause_game(L"Paused while Leaderboard is open.");
    cls.lpfnWndProc=leaderboard_proc;cls.hInstance=g_instance;cls.lpszClassName=L"LauncherLeaderboard";cls.hCursor=LoadCursorW(NULL,IDC_ARROW);cls.hbrBackground=(HBRUSH)(COLOR_BTNFACE+1);RegisterClassW(&cls);
    dialog=CreateWindowExW(WS_EX_DLGMODALFRAME|WS_EX_CONTROLPARENT,cls.lpszClassName,L"Time Trial Leaderboard",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,850,500,g_window,NULL,g_instance,&state);
    if(dialog){EnableWindow(g_window,FALSE);ShowWindow(dialog,SW_SHOW);SetFocus(state.track);while(IsWindow(dialog)&&(result=GetMessageW(&msg,NULL,0,0))>0)if(!IsDialogMessageW(dialog,&msg)){TranslateMessage(&msg);DispatchMessageW(&msg);}EnableWindow(g_window,TRUE);}
    if(resume&&g_game)play_game();else restore_main_window_focus(previous);if(!result)PostQuitMessage((int)msg.wParam);
}
