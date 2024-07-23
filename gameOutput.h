#ifndef GAMEOUTPUT_H
#define GAMEOUTPUT_H

#include <vector>
#include <iostream>
#include "constants.h"
#include "posn.h"


class GameOutput {
public:
    GameOutput();
    void printOutput(std::vector<char> display);
    ~GameOutput();
};



#endif
