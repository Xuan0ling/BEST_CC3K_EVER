#include "gameEngine.h"
#include "floor.h"
#include "player.h"



GameEngine::GameEngine(std::string mapFile, PlayerRace playerRace) {
    gameMap = std::make_unique<GameMap>(mapFile);
    floor = std::make_unique<Floor>(player.get(), gameMap.get());
    player = std::make_unique<Player>(playerRace, floor.get());
    gameInput = std::make_unique<GameInput>();
    gameOutput = std::make_unique<GameOutput>();
}

bool GameEngine::gameRun() {
    PlayerCmd input = gameInput->getInput();
    floor->generateFloor();
    while (input != PlayerCmd::QUIT) {
        handlePlayerCmd(input);
        floor->enemiesAction();
        gameOutput->printOutput();
        input = gameInput->getInput();
    }
    return player->getIsWon();
}




