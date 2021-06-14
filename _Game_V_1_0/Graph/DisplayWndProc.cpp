#include "Game_Lib_V_1_0.hpp"
HBITMAP Stone_Image;
RECT r;
HBRUSH Brush;
PWINDOWINFO GWindow_Info;
bool ChooseStoneFlag = false;
int id;
extern Board Game_Board;
extern Stone S;
extern GameWindow window;
void Load_SImage(HWND hwnd,Stone *stone);
void Delete_SImage(HWND hwnd);
LRESULT DisplayWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam){
    switch (Msg){
    case WM_LBUTTONDOWN:{
        id = GetWindowLongA(hWnd,GWL_ID)-GOFFSET;
        if(id<=8){
            SendMessageA(GetParent(hWnd),DISPLAY_LCLICK,NULL,GetWindowLongA(hWnd,GWL_ID));
            Load_SImage(hWnd,&S);
        }
        break;
    }
    case WM_RBUTTONDOWN:{
        id = GetWindowLongA(hWnd,GWL_ID)-GOFFSET;
        if(id<8){
            SendMessageA(GetParent(hWnd),DISPLAY_RCLICK,NULL,GetWindowLongA(hWnd,GWL_ID));
            Delete_SImage(hWnd);
        }
        break;
    }
    default:
    return DefWindowProcA(hWnd,Msg,wParam,lParam);
    }
    return DefWindowProcA(hWnd,Msg,wParam,lParam);
}
void Load_SImage(HWND hwnd,Stone *stone){
    switch (stone->Get_Type()) {
        case FIRE:{
            ChooseStoneFlag = true;
            Stone_Image = LoadBitmapA(GetModuleHandleA(NULL),"REDSTONE");
            break;
        }
        case WATER:{
            ChooseStoneFlag = true;
            Stone_Image = LoadBitmapA(GetModuleHandleA(NULL),"BLUESTONE");
            break;
        }
        case AIR:{
            ChooseStoneFlag = true;
            Stone_Image = LoadBitmapA(GetModuleHandleA(NULL),"GRAYSTONE");
            break;
        }
        case EARTH:{
            ChooseStoneFlag = true;
            Stone_Image = LoadBitmapA(GetModuleHandleA(NULL),"GREENSTONE");
            break;
        }
    }
    if(ChooseStoneFlag){
    GetClientRect(hwnd,&r);
    Brush = (HBRUSH)CreatePatternBrush(Stone_Image);
    FillRect(GetDC(hwnd),&r,Brush);
    DeleteObject(Brush);
    DeleteObject(&r);
    DeleteObject(Stone_Image);
    ChooseStoneFlag = false;
    }
}
void Delete_SImage(HWND hwnd){
    DeleteObject(Brush);
    DeleteObject(&r);
    DeleteObject(Stone_Image);
    GetClientRect(hwnd,&r);
    InvalidateRect(hwnd,&r,true);
}
