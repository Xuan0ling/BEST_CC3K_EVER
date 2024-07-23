#ifndef GAMEOUTPUT_H
#define GAMEOUTPUT_H

#include <vector>
#include <iostream>
#include "constants.h"
#include "posn.h"


class GameOutput {
    bool useDLC = false;
public:
    GameOutput(bool useDLC);
    void printOutput(const std::vector<char>& display);
    ~GameOutput();
};



#endif
