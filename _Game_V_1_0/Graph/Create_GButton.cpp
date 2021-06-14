#include "Game_Lib_V_1_0.hpp"
void GameWindow::Create_GButton(HWND *Button,HWND *pWnd,HMENU id,int xpos, int ypos, int w, int h){
    *Button = CreateWindowA(GBUTTON_CLASS,
                            "",
                            GAME_BUTTON_STYLE,
                            xpos,
                            ypos,
                            w,
                            h,
                            *pWnd,
                            id,
                            GetModuleHandleA(NULL),
                            NULL);
}
void GameWindow::Create_GButton(HWND *Button,HWND *pWnd,HMENU id,int xpos, int ypos){
    *Button = CreateWindowA(GBUTTON_CLASS,
                            "",
                            GAME_BUTTON_STYLE,
                            xpos,
                            ypos,
                            STONEBUTTONSIZE,
                            STONEBUTTONSIZE,
                            *pWnd,
                            id,
                            GetModuleHandleA(NULL),
                            NULL);
}
