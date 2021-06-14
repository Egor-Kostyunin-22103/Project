#include "Game_Lib_V_1_0.hpp"
void GameWindow::Create_GProgress_Bar(HWND *ProgressBar,HWND *pWnd,HMENU id,int xpos, int ypos,int w,int h){
    if(w<h){
        *ProgressBar = CreateWindowA(PROGRESS_CLASSA,
                                    "",
                                    GPROGRESS_BAR_STYLE|PBS_VERTICAL,
                                    xpos,
                                    ypos,
                                    w,
                                    h,
                                    *pWnd,
                                    id,
                                    GetModuleHandleA(NULL),
                                    NULL);
    }
    else{
        *ProgressBar = CreateWindowA(PROGRESS_CLASSA,
                                     "",
                                     GPROGRESS_BAR_STYLE,
                                     xpos,
                                     ypos,
                                     w,
                                     h,
                                     *pWnd,
                                     id,
                                     GetModuleHandleA(NULL),
                                     NULL);
    }
}
