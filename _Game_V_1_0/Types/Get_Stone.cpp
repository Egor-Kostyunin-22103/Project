#include "Game_Lib_V_1_0.hpp"
Stone* Board::Get_Stone(int Pos, player Player){
    cell *BC = &Cells[Player];
    int index = 1;
    while(BC){
        if(index == Pos){
            return &BC->Cell;
        }
        BC = BC->Next;
        index++;
    }
    return NULL;
}
