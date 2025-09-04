//
// Created by Martin Arriaga on 7/17/24.
//
#include <math.h>
#include <vector>
#include "TournamentTreeLock.h"
#include "Peterson.h"
#include <atomic>

using namespace std;
TournamentTreeLock :: TournamentTreeLock(int n) {

    height = ceil(log2(n)) -1;
    numOfPlocks = pow(2, (height + 1))  -1 ;
    plocks = new Peterson[numOfPlocks];

}

void TournamentTreeLock::acquire(int thid, int h) {

    int lockAssigned = floor(thid / 2);
    int newThreadId = lockAssigned;
    int side = thid % 2;
    int offset =(static_cast<int>((pow(2,(height+1)) )) -1) - (static_cast<int>((pow(2,(h)+1) ))-1)  ;

    if(h >= 0){
        h = h -1;

       plocks[lockAssigned + offset].setFlag(side,true);
       plocks[lockAssigned + offset].setTurn(1-side);

       while(plocks[lockAssigned + offset].getFlag(1-side) && side != plocks[lockAssigned + offset].getTurn())
           ;
        acquire(newThreadId , h);

    }

}
void TournamentTreeLock::release(int thid, int h){
    int lockAssigned = floor(thid / 2);
    int newThreadId = lockAssigned;
    int side = thid % 2;
    int offset =(static_cast<int>((pow(2,(height+1)) )) -1) - (static_cast<int>((pow(2,(h)+1) ))-1)  ;

    if(h >= 0){
        h--;

        release(newThreadId , h);
    }
        plocks[lockAssigned + offset ].setFlag(side,false);

}

TournamentTreeLock* TournamentTreeLock :: start(int n){

    return new TournamentTreeLock(n);

}


