#ifndef GAMEOUTPUT_H
#define GAMEOUTPUT_H

#include <vector>
#include <iostream>
#include "posn.h"


class GameOutput {
    std::vector<char> output;
public:
    GameOutput();
    void printOutput();
    void addOutput(Posn posn, char c);
    ~GameOutput();
};



#endif
