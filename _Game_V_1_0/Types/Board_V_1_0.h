#ifndef BOARD_V_1_0_H
#define BOARD_V_1_0_H
#include "Game_Constants_V_1_0.hpp"
#include "Stone_V_1_0.h"
class Board{
    cell Cells[BOARD_SIZE];///<Доска
public:
    /**
     * @brief Board - Определяет Связи Между Клетками
     * @param Board_Map - Карта Связей
     */
    Board(int Board_Map[BOARD_SIZE]);
    /**
     * @brief Put_Stone
     * @param S
     * @param Pos
     * @param Player
     */
    void Put_Stone(Stone S,int Pos,player Player);
    /**
     * @brief Take_Stone_from_Board
     * @param Pos
     * @param Player
     */
    void Take_Stone_from_Board(int Pos,player Player);
    /**
     * @brief Attack
     * @param Player
     * @return
     */
    damage Attack(player Player);
    /**
     * @brief Get_Stone
     * @param Pos
     * @param Player
     * @return
     */
    Stone* Get_Stone(int Pos, player Player);
    ~Board();
};
#endif // BOARD_V_1_0_H
