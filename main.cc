#include "constants.h"
#include "gameEngine.h"
#include "gameMenu.h"
#include "gameEnd.h"


int main(int argc, char* argv[]) {
    bool useDLC = false;
    std::string givenMapFile = "";
    // Parse command-line arguments
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-DLC") {
            useDLC = true;
        }
        if (std::string(argv[i]) == "-m") {
            if (i + 1 >= argc) {
                std::cerr << "Error: missing map file" << std::endl;
                return 1;
            }
            givenMapFile = argv[i + 1];
        }
    }
    GameMenu gameMenu("title.txt", useDLC);
    PlayerRace race = gameMenu.stratMenu();
    if (race != PlayerRace::QUIT) {
        std::unique_ptr<int> plyerScore = std::make_unique<int>(0);
        std::string mapFile = "emptyfloor.txt";
        GameEngine gameEngine(mapFile, race, useDLC, plyerScore.get());
        bool isWon = gameEngine.gameRun(givenMapFile);
        if (useDLC) {
            endwin(); // End ncurses
        }
        GameEnd gameEnd(isWon, *(plyerScore.get()));
        gameEnd.printEnd();
    }
    return 0;
}


