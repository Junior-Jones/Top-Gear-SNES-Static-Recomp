/* Headless native controls: gamepad view available even without hardware. */
#include "../frontend/windows/topgear_frontend_settings_win32.c"
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#x);return 1;}}while(0)
int main(void){
 WNDCLASSW cls={0};DialogContext c={0};TopGearGamepadInputWin32 pad={0};HWND w;unsigned n;wchar_t label[80];
 topgear_frontend_settings_win32_defaults(&c.value);c.gamepad=&pad;c.capture_action=-1;c.keyboard_capture_action=-1;
 cls.lpfnWndProc=controls_proc;cls.hInstance=GetModuleHandleW(NULL);cls.lpszClassName=L"ControlsHiddenTest";CHECK(RegisterClassW(&cls));
 w=CreateWindowExW(WS_EX_CONTROLPARENT,cls.lpszClassName,L"Controls",WS_OVERLAPPED,0,0,760,640,NULL,NULL,cls.hInstance,&c);CHECK(w&&!IsWindowVisible(w));
 CHECK(SendMessageW(c.source,CB_GETCOUNT,0,0)==2);
 SendMessageW(c.source,CB_GETLBTEXT,1,(LPARAM)label);CHECK(wcsstr(label,L"Gamepad"));
 SendMessageW(c.source,CB_SETCURSEL,1,0);SendMessageW(w,WM_COMMAND,MAKEWPARAM(ID_INPUT_SOURCE,CBN_SELCHANGE),0);
 CHECK(c.value.input_source==TOPGEAR_INPUT_SOURCE_GAMEPAD);
 for(n=0;n<TOPGEAR_WIN_BINDING_COUNT;n++){
 CHECK(GetWindowLongPtrW(c.gamepad_assignments[n],GWL_STYLE)&WS_VISIBLE);
 CHECK(GetWindowLongPtrW(c.gamepad_changes[n],GWL_STYLE)&WS_VISIBLE);
 CHECK(!(GetWindowLongPtrW(c.controls[n],GWL_STYLE)&WS_VISIBLE));
 }
 SendMessageW(c.source,CB_SETCURSEL,0,0);SendMessageW(w,WM_COMMAND,MAKEWPARAM(ID_INPUT_SOURCE,CBN_SELCHANGE),0);
 CHECK(c.value.input_source==TOPGEAR_INPUT_SOURCE_KEYBOARD);DestroyWindow(w);
 puts("PASS hidden Controls: keyboard/gamepad selection, all gamepad assignments, disconnected state and keyboard return");return 0;
}
