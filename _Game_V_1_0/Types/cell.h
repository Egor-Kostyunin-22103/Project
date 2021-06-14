#ifndef CELL_H
#define CELL_H
#include "Stone_V_1_0.h"
#define BOARD_SIZE 16
typedef struct _cell{
    Stone Cell;///<Stone Cell - Камень Находящийся в Клетке
    struct _cell *Next;///<Указатель на Следующую Клетку
} cell;
#endif // CELL_H
