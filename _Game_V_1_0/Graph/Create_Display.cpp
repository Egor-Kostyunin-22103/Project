#include "Game_Lib_V_1_0.hpp"
void GameWindow::Create_Cell_Display(HWND *Cell_Display,HWND *pWnd,HMENU id,int xpos, int ypos){
    *Cell_Display = CreateWindowA(GDISPLAY_CLASS,
                                  "",
                                  GDISPLAY_STYLE,
                                  xpos*CELLSIZE,
                                  ypos*CELLSIZE,
                                  CELLSIZE,
                                  CELLSIZE,
                                  *pWnd,
                                  id,
                                  NULL,
                                  NULL);
}
void GameWindow::Create_Small_Display(HWND *Display,HWND *pWnd,HMENU id,int xpos, int ypos){
    *Display = CreateWindowA(SGDISPLAY_CLASS,
                             "",
                             GDISPLAY_STYLE,
                             xpos,
                             ypos,
                             STONEBUTTONSIZE,
                             STONEBUTTONSIZE,
                             *pWnd,
                             id,
                             NULL,
                             NULL);
}
