mylock: my-lock.cpp Peterson.cpp Peterson.h TournamentTreeLock.cpp TournamentTreeLock.h
	g++ -std=c++11 my-lock.cpp Peterson.cpp TournamentTreeLock.cpp
clean:
	rm -rf mylock Peterson.h.gch TournamentTreeLock.h.gch a.out

