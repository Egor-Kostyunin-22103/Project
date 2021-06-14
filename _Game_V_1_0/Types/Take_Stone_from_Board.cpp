#include "Game_Lib_V_1_0.hpp"
void Board::Take_Stone_from_Board(int Pos, player Player){
    cell *BC = &Cells[Player];
    int index = 1;
    while(BC){
        if(index == Pos){
            BC->Cell.~Stone();
        }
        BC = BC->Next;
        index++;
    }
}
