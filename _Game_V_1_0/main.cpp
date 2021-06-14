#include <iostream>
#include <windows.h>
#include "Game_Lib_V_1_0.hpp"
using namespace std;
MSG msg;
GameWindow window;
extern bool WinFlag1;
extern bool WinFlag2;
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
    ShowWindow(GetConsoleWindow(),SW_HIDE);
    ShowWindow(*window.GetGWindow(),SW_SHOWNORMAL);
    while(GetMessageA(&msg,NULL,0,0)){
        if(WinFlag1||WinFlag2){
            break;
        }
        DispatchMessageA(&msg);
        UpdateWindow(*window.GetGWindow());
    }
    if(WinFlag1){
        MessageBoxA(NULL,"Winner","1 Palyer",NULL);
    }
    if(WinFlag2){
        MessageBoxA(NULL,"Winner","2 Palyer",NULL);
    }
    return 0;
}
