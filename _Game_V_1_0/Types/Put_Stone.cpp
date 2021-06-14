#include "Game_Lib_V_1_0.hpp"
void Board::Put_Stone(Stone S, int Pos,player Player){
    cell *BC = &Cells[Player];
    int index = 1;
    while(BC){
        if(index == Pos){
            BC->Cell = S;
        }
        BC = BC->Next;
        index++;
    }
}
