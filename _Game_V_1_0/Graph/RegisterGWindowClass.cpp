#include "Game_Lib_V_1_0.hpp"
using namespace std;
void GameWindow::RegisterGWindowClass(WNDCLASSA *WindowClass,LPSTR GWindowClassName,GWNDPROC GWndProc,LPSTR GBackGround){
    string str1(GBUTTON_CLASS);
    string str2(GWindowClassName);
    bool Flag = str2 != str1;
    if(Flag){
        memset(WindowClass,0,sizeof (WNDCLASSA));
        WindowClass->lpszClassName = GWindowClassName;
        WindowClass->lpfnWndProc = GWndProc;
        WindowClass->hbrBackground = CreatePatternBrush(LoadBitmapA(GetModuleHandleA(NULL),GBackGround));
        WindowClass->hIcon = LoadIconA(GetModuleHandleA(NULL),"GICON");
        WindowClass->hCursor = LoadCursorA(GetModuleHandleA(NULL),"GCURSOR");
    }
    else{
        GetClassInfoA(NULL,"BUTTON",WindowClass);
        WindowClass->lpszClassName = GWindowClassName;
        WindowClass->hCursor = LoadCursorA(GetModuleHandleA(NULL),"GCURSOR");
    }
    RegisterClassA(WindowClass);
}
