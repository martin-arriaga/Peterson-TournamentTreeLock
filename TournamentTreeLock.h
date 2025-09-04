//
// Created by Martin Arriaga on 7/17/24.
//

#ifndef MY_LOCK_TOURNAMENTTREELOCK_H
#define MY_LOCK_TOURNAMENTTREELOCK_H
#include "Peterson.h"
#include<vector>

using namespace std;


class TournamentTreeLock {
private:
    int height;
    int numOfPlocks;
    Peterson* plocks;

public:

    TournamentTreeLock(int n);
    void acquire(int n, int h);
    void release(int n, int h);
    static TournamentTreeLock* start(int n);

};



#endif //MY_LOCK_TOURNAMENTTREELOCK_H
