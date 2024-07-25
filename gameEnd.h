#ifndef GAMEEND_H
#define GAMEEND_H

#include "constants.h"

class GameEnd {
    bool win;
    int playerScore;
public:
    GameEnd(bool win, int playerScore);
    void printEnd();
    ~GameEnd();
};


#endif
