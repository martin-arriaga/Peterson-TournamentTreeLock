#include <iostream>
#include <thread>
#include "Peterson.h"
#include <math.h>
#include <vector>
#include <atomic>
#include "TournamentTreeLock.h"
#include "Lock.h"
using namespace std;
void enterTournament(int thid,int h,TournamentTreeLock* tt);
void CS();
void TAS();
void FAI();
void successMessage(int n, string mode);
atomic_flag TASlock = ATOMIC_FLAG_INIT;
atomic <int> token=ATOMIC_VAR_INIT(0);
atomic <int> turn= ATOMIC_VAR_INIT(0);
int counter;

void errormsg(char* msg){
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {

    int n = atoi(argv[2]);
  int mode = atoi(argv[1]);


    if(mode == 0){
        TournamentTreeLock* lock;
        lock = TournamentTreeLock :: start(n);

        int height = ceil(log2(n))  ;
        int myThId[n];
        vector<thread> th;
        for(int i = 0; i < n; i++){
            myThId[i]=i;
            th.emplace_back(enterTournament, myThId[i], height, lock);
        }

        for (auto& threads: th){
            threads.join();
        }
        delete(lock);
        successMessage(n,"Peterson Lock");
    }else if(mode == 1){
        vector<thread> th;
        for(int i = 0; i < n; i++){
            th.emplace_back(TAS);
        }
        for (auto& threads: th){
            threads.join();
        }
        successMessage(n,"TAS");
    }else if(mode == 2){
        vector<thread> th;
        for(int i = 0; i < n; i++){
            th.emplace_back(FAI);
        }
        for (auto& threads: th){
            threads.join();
        }
        successMessage(n,"FAI");

    }else{
        errormsg("**Error: Please execute the program in the following format:** ./mylock mode n.\n" "where mode is 0, 1 or 2\n" "0-> Peterson Lock\n"
                                    "1-> Test and Set lock\n""2-> Fetch and Increment lock\n""n is the amount of threads desired");
    }


    return 0;
}


void enterTournament(int thid,int h, TournamentTreeLock* tt) {
    for (int i = 0; i < 10000; i++) {
        tt->acquire(thid, h);
        CS();
        tt->release(thid, h);
    }
}

void TAS() {
    for (int i = 0; i < 10000; i++) {
        while (atomic_flag_test_and_set(&TASlock));
        CS();
        atomic_flag_clear(&TASlock);
    }
}

void FAI(){
    for(int i=0; i < 10000; i++) {
        int myTurn = atomic_fetch_add(&token, 1);
        while (myTurn != turn);
        CS();
        atomic_fetch_add(&turn, 1);
    }
}

void CS(){
    counter = counter + 1;
}
void successMessage(int n, string mode){
    fprintf(stdout,"%s lock counter: %d\n", mode.c_str(),counter);
    fprintf(stdout,"Number of threads: %d\n", n );
    fprintf(stdout,"Each thread executing the Critical Section 10,000 times, expected output: %d", n * 10000);
}

