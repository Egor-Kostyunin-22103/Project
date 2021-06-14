#ifndef GRAPH_CONSTANTS_V_1_0_
#define GRAPH_CONSTANTS_V_1_0_
#include <windows.h>
/*Размеры*/
#define CELLSIZE 64///<Размер Клетки
#define STONEBUTTONSIZE 16///<Размер Кнопки
/*Имена Классов*/
#define MAIN_GWINDOW_CLASS "MainGWindow"///<Имя Класса Главного Окна
#define GDISPLAY_CLASS "GDisplay"///<Имя Класса Дисплея Клетки
#define SGDISPLAY_CLASS "SmallGDisplay"///<Имя Класса Маленького Дисплея
#define GBUTTON_CLASS "GameButton"///<Имя Класса Кнопки
/*Стили*/
#define MAIN_WINDOW_STYLE (WS_OVERLAPPEDWINDOW&~WS_THICKFRAME&~WS_MAXIMIZEBOX|SS_BITMAP)///<Стиль Главного Окна
#define GDISPLAY_STYLE (WS_CHILD|WS_VISIBLE|SS_BITMAP)///<Стиль Дисплея
#define GAME_BUTTON_STYLE (BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|BS_BITMAP|BS_FLAT)///<Стиль Кнопки
#define GPROGRESS_BAR_STYLE (WS_CHILD|WS_VISIBLE|PBS_SMOOTH)///<Стиль Прогресс Бара
/*Идентификаторы*/
#define GOFFSET 2000///<Отступ
#define ATTACK_DISPLAY (17+GOFFSET)///<Идентефикатор Дисплея 1
#define DEFENSE_DISPLAY (18+GOFFSET)///<Идентефикатор Дисплея 2
#define SUPPORT_DISPLAY (19+GOFFSET)///<Идентефикатор Дисплея 3
#define DELETE_BUTTON (21+GOFFSET)///<Идентефикатор Кнопки Удаления Камней
#define ATTACK_BUTTON (22+GOFFSET)///<Идентефикатор Кнопки Передачи Хода
#define RED_S_BUTTON (23+GOFFSET)///<Идентефикатор Кнопки Выбора Красного Камня
#define BLUE_S_BUTTON (24+GOFFSET)///<Идентефикатор Кнопки Выбора Синего Камня
#define GRAY_S_BUTTON (25+GOFFSET)///<Идентефикатор Кнопки Выбора Серого Камня
#define GREEN_S_BUTTON (26+GOFFSET)///<Идентефикатор Кнопки Выбора Зеленого Камня
#define HP1_BAR (28+GOFFSET)///<Идентефикатор HP Бара
#define HP2_BAR (29+GOFFSET)///<Идентефикатор HP Бара
/*Сообщения*/
#define DISPLAY_LCLICK WM_USER+1
#define DISPLAY_RCLICK WM_USER+2
#endif // GRAPH_CONSTANTS_V_1_0_
