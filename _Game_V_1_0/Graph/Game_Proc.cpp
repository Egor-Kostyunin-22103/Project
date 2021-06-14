#include "Game_Lib_V_1_0.hpp"
#include <iostream>
using namespace std;
int GMap[16] =
{ 4, 5, 6, 7,
 -1, 0, 1, 2,
 13,14,15,-1,
  8, 9,10,11};
Board Game_Board(GMap);
Stone S;
int HP1 = 32;
int HP2 = 32;
int counter = 1;
bool WinFlag1 = false;
bool WinFlag2 = false;
extern GameWindow window;
extern void Load_SImage(HWND hwnd,Stone *stone);
WINBOOL CALLBACK EnumGProc(HWND hwnd,LPARAM lparam);
LRESULT GameWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam){

    switch (Msg){
    case WM_COMMAND:{
        switch (wParam) {
            case RED_S_BUTTON:{
                S.Set_Stone(FIRE);
                break;
            }
            case BLUE_S_BUTTON:{
                S.Set_Stone(WATER);
                break;
            }
            case GRAY_S_BUTTON:{
                S.Set_Stone(AIR);
                break;
            }
            case GREEN_S_BUTTON:{
                S.Set_Stone(EARTH);
                break;
            }
            case DELETE_BUTTON:{
                EnumChildWindows(hWnd,&EnumGProc,WM_RBUTTONDOWN);
                break;
            }
            case ATTACK_BUTTON:{
            for(int i = 2;i < 4;i++){
                for(int j = 0;j < 4;j++){
                        InvalidateRect(*window.GetCDisplay(i*4+j),NULL,true);
                }
            }
                if(counter%2 !=0){
                    HP2 -= Game_Board.Attack(FIRST_PLAYER);
                    cout<<HP2<<endl;
                    SendMessageA(*window.GetHPBar(true),PBM_SETPOS,HP2,NULL);
                    for(int i = 0;i < 2;i++){
                        for(int j = 0;j < 4;j++){
                            if(Game_Board.Get_Stone(i*4+j+1,FIRST_PLAYER)->Get_Type() != NOINIT){
                                Load_SImage(*window.GetCDisplay(i*4+j),Game_Board.Get_Stone(i*4+j+1,FIRST_PLAYER));
                            }
                            else{
                                InvalidateRect(*window.GetCDisplay(i*4+j),NULL,true);
                            }
                        }
                    }
                }
                else{
                    HP1 -= Game_Board.Attack(SECOND_PLAYER);
                    cout<<HP1<<endl;
                    SendMessageA(*window.GetHPBar(false),PBM_SETPOS,HP1,NULL);
                    Game_Board.~Board();
                    for(int i = 0;i < 4;i++){
                        for(int j = 0;j < 4;j++){
                            InvalidateRect(*window.GetCDisplay(i*4+j),NULL,true);
                        }
                    }
                }
                counter++;
            }
            break;
        }
        break;
    }
    case DISPLAY_LCLICK:{
        if(counter%2 !=0){
            Game_Board.Put_Stone(S,lParam-GOFFSET+1,FIRST_PLAYER);
        }
        else{
            Game_Board.Put_Stone(S,lParam-GOFFSET+1,SECOND_PLAYER);
        }
        break;
    }
    case DISPLAY_RCLICK:{
        if(counter%2 !=0){
            Game_Board.Take_Stone_from_Board(lParam-GOFFSET+1,FIRST_PLAYER);
        }
        else{
            Game_Board.Take_Stone_from_Board(lParam-GOFFSET+1,SECOND_PLAYER);
        }
        break;
    }
    case WM_DESTROY:{
        PostQuitMessage(0);
        break;
    }
    default:
    if(HP1 <= 0){
        WinFlag2 = true;
    }
    if(HP2 <= 0){
        WinFlag1 = true;
    }
    return DefWindowProcA(hWnd,Msg,wParam,lParam);
    }

    return DefWindowProcA(hWnd,Msg,wParam,lParam);
}
WINBOOL CALLBACK EnumGProc(HWND hwnd,LPARAM lparam){
    SendMessageA(hwnd,lparam,NULL,NULL);
    return true;
}
