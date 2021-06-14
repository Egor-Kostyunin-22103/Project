#ifndef STONE_V_1_0_H
#define STONE_V_1_0_H
#include "Game_Constants_V_1_0.hpp"
class Stone{
    stone_type Type;///<Тип Камня
public:
    /**
     * @brief Stone
     * @param T
     */
    Stone(stone_type T = NOINIT);
    /**
     * @brief Set_Stone
     * @param T
     */
    void Set_Stone(stone_type T);
    /**
     * @brief Get_Type
     * @return stone_type
     */
    stone_type Get_Type();
    ~Stone();
};
#endif // STONE_V_1_0_H
