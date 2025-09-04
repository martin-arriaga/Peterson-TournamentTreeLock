//
// Created by Martin Arriaga on 7/10/24.
//

#ifndef MY_LOCK_PETERSON_H
#define MY_LOCK_PETERSON_H
#include <atomic>
using namespace std;


class Peterson {
private:
    atomic <bool> flag[2];
    atomic <int> turn;

public:
    Peterson();
    void setFlag(int m, bool n);
    void setTurn(int n);
    bool getFlag(int n);
    int getTurn();
    void lock(int t);
    void unlock(int t);



};
#endif //MY_LOCK_PETERSON_H
