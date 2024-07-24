#include "gameEngine.h"
#include "floor.h"
#include "gameMap.h"
#include "player.h"



GameEngine::GameEngine(std::string mapFile, PlayerRace playerRace, bool useDLC) {
    gameMap = std::make_unique<GameMap>(mapFile);
    floor = std::make_unique<Floor>();
    player = std::make_unique<Player>(floor.get(), playerRace);
    floor->initFloor(player.get(), gameMap.get());
    gameInput = std::make_unique<GameInput>(useDLC);
    gameOutput = std::make_unique<GameOutput>(useDLC);
}

bool GameEngine::gameRun() {
    floor->loadFloor();
    gameOutput->printOutput(floor->getDisplay(), player.get());

    PlayerCmd input = getAction();

    while (input != PlayerCmd::QUIT) {
        handlePlayerCmd(input);
        handleEnemiesAction();

        if (player->getIsDead() || player->getIsWon()) {
            break;
        }


        // floor->enemiesAction();
        gameOutput->printOutput(floor->getDisplay(), player.get());

        input = getAction();
    }
    return player->getIsWon();
}

PlayerCmd GameEngine::getAction() {
    PlayerCmd input = gameInput->getInput();
    while (input == PlayerCmd::INVALID) {
        player->setAction("Invalid Command");
        gameOutput->printOutput(floor->getDisplay(), player.get());
        player->setAction("");
        input = gameInput->getInput();
    }
    return input;
}

void GameEngine::handlePlayerCmd(PlayerCmd cmd) {
    switch (cmd) {
        case PlayerCmd::NO:
            player->move(Posn(-1, 0));
            break;
        case PlayerCmd::SO:
            player->move(Posn(1, 0));
            break;
        case PlayerCmd::EA:
            player->move(Posn(0, 1));
            break;
        case PlayerCmd::WE:
            player->move(Posn(0, -1));
            break;
        case PlayerCmd::ATTACK_NO:
            player->attack(Posn(-1, 0));
            break;
        case PlayerCmd::ATTACK_SO:
            player->attack(Posn(1, 0));
            break;
        case PlayerCmd::ATTACK_EA:
            player->attack(Posn(0, 1));
            break;
        case PlayerCmd::ATTACK_WE:
            player->attack(Posn(0, -1));
            break;
        case PlayerCmd::USEPOTION_NO:
            player->usePotion(Posn(-1, 0));
            break;
        case PlayerCmd::USEPOTION_SO:
            player->usePotion(Posn(1, 0));
            break;
        case PlayerCmd::USEPOTION_EA:
            player->usePotion(Posn(0, 1));
            break;
        case PlayerCmd::USEPOTION_WE:
            player->usePotion(Posn(0, -1));
            break;
        case PlayerCmd::ENTERNEXTFLOOR:
            player->gainCurrFloorIndex(1);
            floor->initFloor(player.get(), gameMap.get());
            break;
        case PlayerCmd::RESTART:
            restartGame();
            break;
        default:
            break;
    }
}

void GameEngine::handleEnemiesAction() {
    floor->enemiesAction();
}


void GameEngine::restartGame() {
    player->setIsWon(false);
    player->setIsDead(false);
    player->gainCurrFloorIndex(1);
    player->setHp(player->getMaxHp());
    player->setChamberNum(-1);
    player->setGold(0);
    floor->loadFloor();
}



GameEngine::~GameEngine() {}
