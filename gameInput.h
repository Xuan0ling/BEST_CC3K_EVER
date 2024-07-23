#ifndef GAMEINPUT_H
#define GAMEINPUT_H
#include "constants.h"
#include <iostream>

class GameInput {
    char input;
public:
    GameInput();
    PlayerCmd getInput();
    PlayerCmd getPlayerPosition(char input);
    PlayerRace getPlayerRace();
    ~GameInput();
};



#endif
