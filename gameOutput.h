#ifndef GAMEOUTPUT_H
#define GAMEOUTPUT_H

#include <vector>
#include <iostream>
#include "constants.h"

class GameMenu;



class GameOutput {
    bool useDLC = false;
public:
    GameOutput(bool useDLC);
    void printOutput(const std::vector<char>& display, Player* Player);
    ~GameOutput();
};



#endif
