#include "Game_Lib_V_1_0.hpp"
#include <math.h>
extern damage HP1;
extern damage HP2;
using namespace std;
bool R_Flag = false;
bool B_Flag = false;
bool Gr_Flag = false;
bool G_Flag = false;
damage Actions[16] =
{ 4, 3, 2, 1,
  8, 6, 4, 2,
 12, 9, 6, 3,
 16,12, 8, 4};
void Actions_Init();
damage Board::Attack(player Player){
    damage attack = 0;
    cell *BC = &Cells[Player];
    while(BC){
        if(BC->Next != NULL){
        if(BC->Cell.Get_Type() == FIRE && BC->Next->Cell.Get_Type() != WATER){
           attack= attack + 2;
           if(BC->Next->Cell.Get_Type() != FIRE){
              attack++;
           }
        }
        if(BC->Cell.Get_Type() == WATER && BC->Next->Cell.Get_Type() != EARTH){
           attack= attack + 2;
           if(BC->Next->Cell.Get_Type() != WATER){
              attack++;
           }
        }
        if(BC->Cell.Get_Type() == AIR && BC->Next->Cell.Get_Type() != FIRE){
           attack= attack + 2;
           if(BC->Next->Cell.Get_Type() != AIR){
              attack++;
           }
        }
        if(BC->Cell.Get_Type() == EARTH && BC->Next->Cell.Get_Type() != AIR){
           attack= attack + 2;
           if(BC->Next->Cell.Get_Type() != EARTH){
              attack++;
           }
        }
        }
        BC = BC->Next;
    }
    if(attack > 0){
        return attack;
    }
    else{
        return 0;
    }
}
