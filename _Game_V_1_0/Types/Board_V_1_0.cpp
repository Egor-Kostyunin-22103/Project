#include "Game_Lib_V_1_0.hpp"
Board::Board(int Board_Map[BOARD_SIZE]){
    for (int i = 0;i < BOARD_SIZE;i++){
        Cells[i].Next = NULL;
    }
    for (int i = 0;i < BOARD_SIZE;i++){
        if(Board_Map[i] != -1){
            Cells[i].Next = &Cells[Board_Map[i]];
        }
    }
}
Board::~Board(){
    for(int i = 0;i < BOARD_SIZE;i++){
        Cells[i].Cell.~Stone();
    }
}
