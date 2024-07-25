#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "constants.h"
#include "gameInput.h"

class GameMenu {
    std::string titleFile;
    bool useDLC = false;
    std::vector<std::string> title;
    GameInput input;
public:
    GameMenu(std::string titleFile, bool useDLC);
    void printTitle();
    PlayerRace stratMenu();
    ~GameMenu();
};


#endif
