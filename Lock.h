//
// Created by Martin Arriaga on 7/17/24.
//

#ifndef MY_LOCK_LOCK_H
#define MY_LOCK_LOCK_H

#endif //MY_LOCK_LOCK_H

class Lock{

     virtual void acquire(int) = 0;
     virtual void release(int) = 0;
};
