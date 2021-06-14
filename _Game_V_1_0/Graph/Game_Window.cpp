/*! @file Game_Window.cpp
 *В файле реализуется конструктор класса окна\n
 *Зависит от файлов:\n
 *Game_Graph.hpp\n
 *Graph_Constants_V_1_0.h\n
 *RegisterGWindowClass.cpp\n
 *Create_GButton.cpp\n
 *Create_Display.cpp\n
 *Create_GProgress_Bar.cpp\n
 *Set_GButton_Image.cpp\n
 *DisplayWndProc.cpp\n
 *Game_Proc.cpp\n
 */
#include "Game_Lib_V_1_0.hpp"
GameWindow::GameWindow(){
    /*Регистрация Классов Окон*/
    GameWindow::RegisterGWindowClass(&gbcl,(char*)GBUTTON_CLASS,NULL,NULL);
    GameWindow::RegisterGWindowClass(&sdcl,(char*)SGDISPLAY_CLASS,DefWindowProcA,(char*)"SGBACKGROUND");
    GameWindow::RegisterGWindowClass(&dcl,(char*)GDISPLAY_CLASS,DisplayWndProc,(char*)"GBACKGROUND");
    GameWindow::RegisterGWindowClass(&wcl,(char*)MAIN_GWINDOW_CLASS,GameWndProc,(char*)"GFRAME");
    /*Создание Главного Окна*/
    MainWindow = CreateWindowA(wcl.lpszClassName,/*Имя Класса Окна*/
                               "Game",/*Заголовок*/
                                MAIN_WINDOW_STYLE,/*Стиль Окна*/
                                200,/*X*/
                                200,/*Y*/
                                6*CELLSIZE+GetSystemMetrics(SM_CXFRAME),/*Ширина*/
                                6*CELLSIZE+GetSystemMetrics(SM_CYFRAME)+GetSystemMetrics(SM_CYCAPTION),/*Высота*/
                                NULL,/*Родительское Окно*/
                                NULL,/*Идентефикатор*/
                                GetModuleHandleA(NULL),/*Дескриптор Приложения*/
                                NULL);
    /*Создание Кнопок*/
    GameWindow::Create_GButton(&DeleteSButton,/*Указатель на Кнопку*/
                               &MainWindow,/*Указатель на Родительское Окно*/
                               (HMENU)DELETE_BUTTON,/*Идентефикатор*/
                               5*CELLSIZE,/*X*/
                               5*CELLSIZE);/*Y*/
    GameWindow::Create_GButton(&AttackSButton,/*Указатель на Кнопку*/
                               &MainWindow,/*Указатель на Родительское Окно*/
                               (HMENU)ATTACK_BUTTON,/*Идентефикатор*/
                               5*CELLSIZE+STONEBUTTONSIZE,/*X*/
                               5*CELLSIZE+STONEBUTTONSIZE);/*Y*/
    GameWindow::Create_GButton(&RedSButton,/*Указатель на Кнопку*/
                               &MainWindow,/*Указатель на Родительское Окно*/
                               (HMENU)RED_S_BUTTON,/*Идентефикатор*/
                               5*CELLSIZE+STONEBUTTONSIZE,/*X*/
                               5*CELLSIZE);/*Y*/
    GameWindow::Create_GButton(&GraySButton,/*Указатель на Кнопку*/
                               &MainWindow,/*Указатель на Родительское Окно*/
                               (HMENU)GRAY_S_BUTTON,/*Идентефикатор*/
                               5*CELLSIZE+2*STONEBUTTONSIZE,/*X*/
                               5*CELLSIZE);
    GameWindow::Create_GButton(&GreenSButton,/*Указатель на Кнопку*/
                               &MainWindow,/*Указатель на Родительское Окно*/
                               (HMENU)GREEN_S_BUTTON,/*Идентефикатор*/
                               5*CELLSIZE,/*X*/
                               5*CELLSIZE+STONEBUTTONSIZE);/*Y*/
    GameWindow::Create_GButton(&BlueSButton,/*Указатель на Кнопку*/
                               &MainWindow,/*Указатель на Родительское Окно*/
                               (HMENU)BLUE_S_BUTTON,/*Идентефикатор*/
                               5*CELLSIZE,/*X*/
                               5*CELLSIZE+2*STONEBUTTONSIZE);/*Y*/
    /*Установка Изображений на Кнопки*/
    GameWindow::Set_GButton_Image(&DeleteSButton,"DELETEBUTTON");
    GameWindow::Set_GButton_Image(&AttackSButton,"ATTACKBUTTON");
    GameWindow::Set_GButton_Image(&RedSButton,"REDSTONEBUTTON");
    GameWindow::Set_GButton_Image(&BlueSButton,"BLUESTONEBUTTON");
    GameWindow::Set_GButton_Image(&GraySButton,"GRAYSTONEBUTTON");
    GameWindow::Set_GButton_Image(&GreenSButton,"GREENSTONEBUTTON");
    /*Создание Прогресс Баров*/
    GameWindow::Create_GProgress_Bar(&HP1Bar,/*Указатель на Прогресс Бар*/
                                     &MainWindow,/*Указатель на Родительское Окно*/
                                     (HMENU)HP1_BAR,/*Идентефикатор*/
                                     5*CELLSIZE+3*STONEBUTTONSIZE,/*X*/
                                     5*CELLSIZE+STONEBUTTONSIZE,/*Y*/
                                     STONEBUTTONSIZE,/*Ширина*/
                                     2*STONEBUTTONSIZE);/*Высота*/
    SendMessageA(HP1Bar,PBM_SETRANGE,NULL,MAKELONG(0,32));
    SendMessageA(HP1Bar,PBM_SETSTEP,1,NULL);
    SendMessageA(HP1Bar,PBM_SETPOS,32,NULL);
    GameWindow::Create_GProgress_Bar(&HP2Bar,/*Указатель на Прогресс Бар*/
                                     &MainWindow,/*Указатель на Родительское Окно*/
                                     (HMENU)HP2_BAR,/*Идентефикатор*/
                                     5*CELLSIZE+STONEBUTTONSIZE,/*X*/
                                     5*CELLSIZE+3*STONEBUTTONSIZE,/*Y*/
                                     2*STONEBUTTONSIZE,/*Ширина*/
                                     STONEBUTTONSIZE);/*Высота*/
    SendMessageA(HP2Bar,PBM_SETRANGE,NULL,MAKELONG(0,32));
    SendMessageA(HP2Bar,PBM_SETSTEP,1,NULL);
    SendMessageA(HP2Bar,PBM_SETPOS,32,NULL);
    /*Создание Маленьких Дисплеев*/
    GameWindow::Create_Small_Display(&AGDisplay,/*Указатель на Дисплей*/
                                     &MainWindow,/*Указатель на Родительское Окно*/
                                     (HMENU)ATTACK_DISPLAY,/*Идентефикатор*/
                                     5*CELLSIZE+3*STONEBUTTONSIZE,/*X*/
                                     5*CELLSIZE);/*Y*/
    GameWindow::Create_Small_Display(&DGDisplay,/*Указатель на Дисплей*/
                                     &MainWindow,/*Указатель на Родительское Окно*/
                                     (HMENU)DEFENSE_DISPLAY,/*Идентефикатор*/
                                     5*CELLSIZE+3*STONEBUTTONSIZE,/*X*/
                                     5*CELLSIZE+3*STONEBUTTONSIZE);/*Y*/
    GameWindow::Create_Small_Display(&SGDisplay,/*Указатель на Дисплей*/
                                     &MainWindow,/*Указатель на Родительское Окно*/
                                     (HMENU)SUPPORT_DISPLAY,/*Идентефикатор*/
                                     5*CELLSIZE,/*X*/
                                     5*CELLSIZE+3*STONEBUTTONSIZE);/*Y*/
    /*Создание Дисплеев Клеток*/
    for(int i = 1;i < 5;i++){
        for(int j = 1;j < 5;j++){
            GameWindow::Create_Cell_Display(&Cell_Display_Array[(i-1)*4+(j-1)],/*Указатель на Дисплей*/
                                            &MainWindow,/*Указатель на Родительское Окно*/
                                            (HMENU)((15-((i-1)*4+(j-1)))+GOFFSET),/*Идентефикатор*/
                                            j,/*X*/
                                            i);/*Y*/
        }
    }
}
