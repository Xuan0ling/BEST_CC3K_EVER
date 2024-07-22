#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <memory>

#include "constants.h"
#include "gameInput.h"
#include "gameOutput.h"




// GameEngine class handle the game loop and the game state
class GameEngine {
    PlayerPtr player;
    FloorPtr floor;
    GameMapPtr gameMap;
    GameInputPtr gameInput;
    GameOutputPtr gameOutput;

    int currFloorNum = 1;
public:
    GameEngine(std::string mapFile, PlayerRace playerRace);

    bool gameRun();
    void handlePlayerCmd(char cmd);


    ~GameEngine();
};






#endif
