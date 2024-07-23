#ifndef GAMEINPUT_H
#define GAMEINPUT_H
#include "constants.h"
#include <iostream>

class GameInput {
    char input;
    bool useDLC;
public:
    GameInput(bool useDLC);
    PlayerCmd getInput();
    PlayerCmd getPlayerPosition(char input);
    PlayerRace getPlayerRace();
    ~GameInput();
};



#endif
