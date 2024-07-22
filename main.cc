#include "constants.h"

#include "gameEngine.h"

#include <string>


int main(int argc, char* argv[]) {
    std::string mapFile = "emptyfloor.txt";

    GameEngine gameEngine(mapFile, PlayerRace::SHADE);
    gameEngine.gameRun();
    return 0;
}


