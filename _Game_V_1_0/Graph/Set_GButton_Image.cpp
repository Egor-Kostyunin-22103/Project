#include "Game_Lib_V_1_0.hpp"
void GameWindow::Set_GButton_Image(HWND *Button, LPCSTR ImageName){
    SendMessageA(*Button,
                 BM_SETIMAGE,
                 IMAGE_BITMAP,
                 (LPARAM)LoadBitmapA(GetModuleHandleA(NULL),ImageName));
}
