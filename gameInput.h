#ifndef GAMEINPUT_H
#define GAMEINPUT_H
#include "constants.h"
#include <iostream>

class GameInput {
public:
    GameInput(bool useDLC);
    ~GameInput();

    PlayerCmd getInput();
    PlayerCmd getPlayerPosition(const std::string& input);
    std::string collectInput();
    PlayerRace getPlayerRace();

private:
    bool useDLC;
};



#endif
