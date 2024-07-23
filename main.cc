#include "constants.h"
#include "gameEngine.h"



int main(int argc, char* argv[]) {
    bool useDLC = false;
    // Parse command-line arguments
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-DLC") {
            useDLC = true;
        }
    }


    std::string mapFile = "emptyfloor.txt";

    GameEngine gameEngine(mapFile, PlayerRace::SHADE, useDLC);
    bool isWon = gameEngine.gameRun();
    return 0;
}


