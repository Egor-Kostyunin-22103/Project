#include "Game_Lib_V_1_0.hpp"
Stone::Stone(stone_type T){
    Type = T;
}
Stone::~Stone(){
    Type = NOINIT;
}
