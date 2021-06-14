#include "Game_Lib_V_1_0.hpp"
HWND* GameWindow::GetCDisplay(int Number){
    return &Cell_Display_Array[Number];
}
