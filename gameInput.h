#ifndef GAMEINPUT_H
#define GAMEINPUT_H
#include "constants.h"

class GameInput {
    char input;
public:
    GameInput();
    PlayerCmd getInput();
    ~GameInput();
};



#endif
