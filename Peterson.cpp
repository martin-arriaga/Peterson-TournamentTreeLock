//
// Created by Martin Arriaga on 7/10/24.
//

#include "Peterson.h"
#include <atomic>

Peterson::Peterson(){
    flag[0]=ATOMIC_VAR_INIT(0);;
    flag[1]=ATOMIC_VAR_INIT(0);
    turn = ATOMIC_VAR_INIT(0);
}

void Peterson::setFlag(int m , bool n){
    atomic_store(&flag[m],n);
}
void Peterson:: setTurn(int n){
    atomic_store(&turn,n);
}
bool Peterson:: getFlag(int n)
{   return flag[n];
}
int Peterson:: getTurn(){
    return turn;
}

void Peterson :: lock(int thid){
    atomic_store(&flag[thid],true);
    atomic_store(&turn,1-thid);

}
void Peterson :: unlock(int thid){

    atomic_store(&flag[thid],false);

}


