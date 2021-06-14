#ifndef GAME_PROC_V_1_0_HPP
#define GAME_PROC_V_1_0_HPP
#include <windows.h>
typedef LRESULT (GWNDPROC(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam));///<Тип Оконного Процесса
LRESULT GameWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);///<Процесс Главного Окна
LRESULT DisplayWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);///Процесс Дисплея Клетки

#endif // GAME_PROC_V_1_0_HPP
