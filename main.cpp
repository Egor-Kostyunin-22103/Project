#include <iostream>
#include <windows.h>
#include "Game_Lib_V_1_0.hpp"
using namespace std;
MSG msg;
GameWindow window;
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
    ShowWindow(GetConsoleWindow(),SW_HIDE);
    ShowWindow(*window.GetGWindow(),SW_SHOWNORMAL);
    while(GetMessageA(&msg,NULL,0,0)){
        DispatchMessageA(&msg);
        UpdateWindow(*window.GetGWindow());
    }
    return 0;
}
