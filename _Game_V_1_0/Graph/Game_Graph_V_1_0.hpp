#ifndef GAME_GRAPH_V_1_0_HPP
#define GAME_GRAPH_V_1_0_HPP
#include <windows.h>
#include "Game_Proc_V_1_0.hpp"
/**
 * @brief Класс Окна Игры.
 * @details Создает объект окна игры.\n
 * Использует winAPI.\n
 */
class GameWindow{
    WNDCLASSA wcl;//!< @brief WNDCLASSA wcl - класс главного окна
    WNDCLASSA dcl;//!< @brief WNDCLASSA dcl - класс дисплея клетки
    WNDCLASSA sdcl;//!< @brief WNDCLASSA sdcl - класс маленького дисплея
    WNDCLASSA gbcl;//!< @brief WNDCLASSA gbcl - класс кнопки(Прим. все элементы управления в winAPI так же являются окнами)
    HWND MainWindow;//!< @brief HWND MainWindow - главное окно
    HWND Cell_Display_Array[16];//!<< @brief HWND Cell_Display_Array[16] - массив дисплеев клеток
    HWND AGDisplay;//!< @brief HWND AGDisplay - малый дисплей 1
    HWND DGDisplay;//!< @brief HWND DGDisplay - малый дисплей 2
    HWND SGDisplay;//!< @brief HWND SGDisplay - малый дисплей 3
    HWND DeleteSButton;//!< @brief HWND DeleteSButton - кнопка удаления камней (Прим. удаляет все камни на половине текущего игрока)
    HWND AttackSButton;//!< @brief HWND AttackSButton - кнопка передачи хода (Прим. если кнопку нажимает второй игрок начинается расчет результатов заданых игроками комбинаций)
    HWND RedSButton;//!< @brief HWND RedSButton - кнопка красного камня (Выбирает красный камень для установки)
    HWND BlueSButton;//!< @brief HWND BlueSButton - кнопка синего камня (Выбирает синий камень для установки)
    HWND GraySButton;//!< @brief HWND GraySButton - кнопка серого камня (Выбирает серый камень для установки)
    HWND GreenSButton;//!< @brief HWND GreenSButton - кнопка зеленого камня (Выбирает зеленый камень для установки)
    HWND HP1Bar;//!< @brief HWND HP1Bar - 1 Прогресс Бар (Прим. отображает HP 2 игрока)
    HWND HP2Bar;//!< @brief HWND HP2Bar  - 2 Прогресс Бар (Прим. отображает HP 1 игрока)
public:
    /**
     * @brief Конструктор
     * @code
       GameWindow::GameWindow(){
            GameWindow::RegisterGWindowClass(&gbcl,(char*)GBUTTON_CLASS,NULL,NULL);
            GameWindow::RegisterGWindowClass(&sdcl,(char*)SGDISPLAY_CLASS,DefWindowProcA,(char*)"SGBACKGROUND");
            GameWindow::RegisterGWindowClass(&dcl,(char*)GDISPLAY_CLASS,DisplayWndProc,(char*)"GBACKGROUND");
            GameWindow::RegisterGWindowClass(&wcl,(char*)MAIN_GWINDOW_CLASS,GameWndProc,(char*)"GFRAME");

            MainWindow = CreateWindowA(wcl.lpszClassName,
                                       "Game",
                                        MAIN_WINDOW_STYLE,
                                        200,
                                        200,
                                        6*CELLSIZE+GetSystemMetrics(SM_CXFRAME),
                                        6*CELLSIZE+GetSystemMetrics(SM_CYFRAME)+GetSystemMetrics(SM_CYCAPTION),
                                        NULL,
                                        NULL,
                                        GetModuleHandleA(NULL),
                                        NULL);

            GameWindow::Create_GButton(&DeleteSButton,
                                       &MainWindow,
                                       (HMENU)DELETE_BUTTON,
                                       5*CELLSIZE,
                                       5*CELLSIZE);
            GameWindow::Create_GButton(&AttackSButton,
                                       &MainWindow,
                                       (HMENU)ATTACK_BUTTON,
                                       5*CELLSIZE+STONEBUTTONSIZE,
                                       5*CELLSIZE+STONEBUTTONSIZE);
            GameWindow::Create_GButton(&RedSButton,
                                       &MainWindow,
                                       (HMENU)RED_S_BUTTON,
                                       5*CELLSIZE+STONEBUTTONSIZE,
                                       5*CELLSIZE);
            GameWindow::Create_GButton(&GraySButton,
                                       &MainWindow,
                                       (HMENU)GRAY_S_BUTTON,
                                       5*CELLSIZE+2*STONEBUTTONSIZE,
                                       5*CELLSIZE);
            GameWindow::Create_GButton(&GreenSButton,
                                       &MainWindow,
                                       (HMENU)GREEN_S_BUTTON,
                                       5*CELLSIZE,
                                       5*CELLSIZE+STONEBUTTONSIZE);
            GameWindow::Create_GButton(&BlueSButton,
                                       &MainWindow,
                                       (HMENU)BLUE_S_BUTTON,
                                       5*CELLSIZE,
                                       5*CELLSIZE+2*STONEBUTTONSIZE);
            GameWindow::Set_GButton_Image(&DeleteSButton,"DELETEBUTTON");
            GameWindow::Set_GButton_Image(&AttackSButton,"ATTACKBUTTON");
            GameWindow::Set_GButton_Image(&RedSButton,"REDSTONEBUTTON");
            GameWindow::Set_GButton_Image(&BlueSButton,"BLUESTONEBUTTON");
            GameWindow::Set_GButton_Image(&GraySButton,"GRAYSTONEBUTTON");
            GameWindow::Set_GButton_Image(&GreenSButton,"GREENSTONEBUTTON");

            GameWindow::Create_GProgress_Bar(&HP1Bar,
                                             &MainWindow,
                                             (HMENU)HP1_BAR,
                                             5*CELLSIZE+3*STONEBUTTONSIZE,
                                             5*CELLSIZE+STONEBUTTONSIZE,
                                             STONEBUTTONSIZE,
                                             2*STONEBUTTONSIZE);
            SendMessageA(HP1Bar,PBM_SETRANGE,NULL,MAKELONG(0,32));
            SendMessageA(HP1Bar,PBM_SETSTEP,1,NULL);
            SendMessageA(HP1Bar,PBM_SETPOS,32,NULL);
            GameWindow::Create_GProgress_Bar(&HP2Bar,
                                             &MainWindow,
                                             (HMENU)HP2_BAR,
                                             5*CELLSIZE+STONEBUTTONSIZE,
                                             5*CELLSIZE+3*STONEBUTTONSIZE,
                                             2*STONEBUTTONSIZE,
                                             STONEBUTTONSIZE);
            SendMessageA(HP2Bar,PBM_SETRANGE,NULL,MAKELONG(0,32));
            SendMessageA(HP2Bar,PBM_SETSTEP,1,NULL);
            SendMessageA(HP2Bar,PBM_SETPOS,32,NULL);
            GameWindow::Create_Small_Display(&AGDisplay,
                                             &MainWindow,
                                             (HMENU)ATTACK_DISPLAY,
                                             5*CELLSIZE+2*STONEBUTTONSIZE,
                                             5*CELLSIZE+2*STONEBUTTONSIZE);
            GameWindow::Create_Small_Display(&DGDisplay,
                                             &MainWindow,
                                             (HMENU)DEFENSE_DISPLAY,
                                             5*CELLSIZE+STONEBUTTONSIZE,
                                             5*CELLSIZE+2*STONEBUTTONSIZE);
            GameWindow::Create_Small_Display(&SGDisplay,
                                             &MainWindow,
                                             (HMENU)SUPPORT_DISPLAY,
                                             5*CELLSIZE+2*STONEBUTTONSIZE,
                                             5*CELLSIZE+STONEBUTTONSIZE);

            for(int i = 1;i < 5;i++){
                for(int j = 1;j < 5;j++){
                    GameWindow::Create_Cell_Display(&Cell_Display_Array[(i-1)*4+(j-1)],
                                                    &MainWindow,
                                                    (HMENU)((15-((i-1)*4+(j-1)))+GOFFSET),
                                                    j,
                                                    i);
                }
            }
       }
     * @endcode
     */
    GameWindow();
    /**
     * @brief GetGWindow - Возвращает Указатель на Главное Окно
     * @return HWND*
     * @code
       HWND* GameWindow::GetGWindow(){
            return &MainWindow;
       }
     * @endcode
     */
    HWND* GetGWindow();
    /**
     * @brief GetCDisplay - Возвращает Указатель на Дисплей Клетки
     * @param Number - Номер Клетки
     * @return HWND*
     * @code
        HWND* GameWindow::GetCDisplay(int Number){
            return &Cell_Display_Array[Number];
        }
     * @endcode
     */
    HWND* GetCDisplay(int Number);
    /**
     * @brief GetHPBar
     * @param Number
     * @return HWND*
     * @code
       HWND* GetHPBar(bool Number){
        if(Number){
            return &HP1Bar;
        }
        return &HP2Bar;
       }
     * @endcode
     */
    HWND* GetHPBar(bool Number){
        if(Number){
            return &HP1Bar;
        }
        return &HP2Bar;
    }
    /**
     * @brief RegisterGWindowClass - Регестрирует Класс Окна
     * @param WindowClass - Указатель на Структуру Типа WNDCLASSA
     * @param GWindowClassName - Название Класса
     * @param GWndProc - Процесс Обработки Оконных Сообщений
     * @param GBackGround - Фоновое Изображение
     * @code
        void GameWindow::RegisterGWindowClass(WNDCLASSA *WindowClass,LPSTR GWindowClassName,GWNDPROC GWndProc,LPSTR GBackGround){
            string str1(GBUTTON_CLASS);
            string str2(GWindowClassName);
            bool Flag = str2 != str1;
            if(Flag){
                memset(WindowClass,0,sizeof (WNDCLASSA));
                WindowClass->lpszClassName = GWindowClassName;
                WindowClass->lpfnWndProc = GWndProc;
                WindowClass->hbrBackground = CreatePatternBrush(LoadBitmapA(GetModuleHandleA(NULL),GBackGround));
                WindowClass->hIcon = LoadIconA(GetModuleHandleA(NULL),"GICON");
                WindowClass->hCursor = LoadCursorA(GetModuleHandleA(NULL),"GCURSOR");
            }
            else{
                GetClassInfoA(NULL,"BUTTON",WindowClass);
                WindowClass->lpszClassName = GWindowClassName;
                WindowClass->hCursor = LoadCursorA(GetModuleHandleA(NULL),"GCURSOR");
            }
            RegisterClassA(WindowClass);
        }
     * @endcode
     */
    static void RegisterGWindowClass(WNDCLASSA *WindowClass,LPSTR GWindowClassName,GWNDPROC GWndProc,LPSTR GBackGround);
    /**
     * @brief Create_Cell_Display - Создает Дисплей Клетки
     * @param Cell_Display - Указатель на Дисплей
     * @param pWnd - Указатель на Родительское Окно
     * @param id - Идентефикатор
     * @param xpos - x
     * @param ypos - y
     * @code
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
     * @endcode
     */
    static void Create_Cell_Display(HWND *Cell_Display,HWND *pWnd,HMENU id,int xpos, int ypos);
    /**
     * @brief Create_Small_Display - Создает Маленький Дисплей
     * @param Display - Указатель на Дисплей
     * @param pWnd - Указатель на Родительское Окно
     * @param id - Идентефикатор
     * @param xpos - x
     * @param ypos - y
     * @code
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
     * @endcode
     */
    static void Create_Small_Display(HWND *Display,HWND *pWnd,HMENU id,int xpos, int ypos);
    /**
     * @brief Create_GButton - Создает Кнопку
     * @param Button - Указатель на Кнопку
     * @param pWnd - Указатель на Родительское Окно
     * @param id - Идентефикатор
     * @param xpos - x
     * @param ypos - y
     * @param w - Ширина
     * @param h - Высота
     * @code
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
     * @endcode
     */
    static void Create_GButton(HWND *Button,HWND *pWnd,HMENU id,int xpos, int ypos,int w,int h);
    /**
     * @brief Create_GButton - Создает Кнопку
     * @param Button - Указатель на Кнопку
     * @param pWnd - Указатель на Родительское Окно
     * @param id - Идентефикатор
     * @param xpos - x
     * @param ypos - y
     * @code
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
     * @endcode
     */
    static void Create_GButton(HWND *Button,HWND *pWnd,HMENU id,int xpos, int ypos);
    /**
     * @brief Set_GButton_Image - Устанавливает Изображение на Кнопку
     * @param Button - Указатель на Кнопку
     * @param ImageName - Название Изображения
     * @code
        void GameWindow::Set_GButton_Image(HWND *Button, LPCSTR ImageName){
            SendMessageA(*Button,
                         BM_SETIMAGE,
                         IMAGE_BITMAP,
                         (LPARAM)LoadBitmapA(GetModuleHandleA(NULL),ImageName));
        }
     * @endcode
     */
    static void Set_GButton_Image(HWND *Button,LPCSTR ImageName);
    /**
     * @brief Create_GProgress_Bar - Создает Прогресс Бар
     * @param ProgressBar - Указатель на Прогресс Бар
     * @param pWnd - Указатель на Родительское Окно
     * @param id - Идентефикатор
     * @param xpos - x
     * @param ypos - y
     * @param w - Ширина
     * @param h - Высота
     * @code
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
     * @endcode
     */
    static void Create_GProgress_Bar(HWND *ProgressBar,HWND *pWnd,HMENU id,int xpos, int ypos,int w,int h);
};

#endif // GAME_GRAPH_V_1_0_HPP
