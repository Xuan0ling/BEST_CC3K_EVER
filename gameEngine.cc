#include "gameEngine.h"
#include "floor.h"
#include "gameMap.h"
#include "player.h"
#include "concretePlayerFactory.h"


GameEngine::GameEngine(std::string mapFile, PlayerRace playerRace, bool useDLC, int* playerScore, std::string givenMapFile) 
: playerScore(playerScore), givenMapFile(mapFile) {
    gameMap = std::make_unique<GameMap>(mapFile);
    floor = std::make_unique<Floor>();
    playerCreate(playerRace);
    floor->initFloor(player.get(), gameMap.get());
    gameInput = std::make_unique<GameInput>(useDLC);
    gameOutput = std::make_unique<GameOutput>(useDLC);
    if (givenMapFile != "") {
        haveGivenMap = true;
        try {
            givenMap = floor->readMap(givenMapFile);
        } catch (const std::runtime_error& e) {
            throw e;
        }
    }
}

void GameEngine::playerCreate(PlayerRace playerRace) {
    std::unique_ptr<Playerfactory> playerFactory;
    switch (playerRace) {
        case PlayerRace::SHADE:
            playerFactory = std::make_unique<Shadefactory>();
            break;
        case PlayerRace::DROW:
            playerFactory = std::make_unique<Drowfactory>();
            break;
        case PlayerRace::VAMPIRE:
            playerFactory = std::make_unique<Vampirefactory>();
            break;
        case PlayerRace::TROLL:
            playerFactory = std::make_unique<Trollfactory>();
            break;
        case PlayerRace::GOBLIN:
            playerFactory = std::make_unique<Goblinfactory>();
            break;
        default:
            break;
    }
    std::unique_ptr<Player> playerPtr(playerFactory->createPlayer(floor.get()));
    player = std::move(playerPtr);
}

bool GameEngine::gameRun() {
    if (haveGivenMap) {
        floor->loadGivenFloor(givenMap);
        haveGivenMap = true;
    } else {
        floor->loadFloor();
    }
    gameOutput->printOutput(floor->getDisplay(), player.get());

    PlayerCmd input = getAction();

    while (input != PlayerCmd::QUIT) {
        player->setAction("");
        handlePlayerCmd(input);

        if (hasRestart) {
            hasRestart = false;
        } else {
            handleEnemiesAction();
        }


        gameOutput->printOutput(floor->getDisplay(), player.get());

        if (player->getIsDead() || player->getIsWon()) {
            break;
        }

        input = getAction();
    }
    if (player->getRace() == PlayerRace::SHADE) {
        *playerScore = player->getGold() * 1.5;
    } else {
        *playerScore = player->getGold();
    }
    if (input == PlayerCmd::QUIT) {
        *playerScore = -1;
    }
    return player->getIsWon();
}

PlayerCmd GameEngine::getAction() {
    PlayerCmd input = gameInput->getInput();
    while (input == PlayerCmd::INVALID) {
        player->setAction(" Invalid Command");
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
        case PlayerCmd::NE:
            player->move(Posn(-1, 1));
            break;
        case PlayerCmd::NW:
            player->move(Posn(-1, -1));
            break;
        case PlayerCmd::SE:
            player->move(Posn(1, 1));
            break;
        case PlayerCmd::SW:
            player->move(Posn(1, -1));
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
        case PlayerCmd::ATTACK_NE:
            player->attack(Posn(-1, 1));
            break;
        case PlayerCmd::ATTACK_NW:
            player->attack(Posn(-1, -1));
            break;
        case PlayerCmd::ATTACK_SE:
            player->attack(Posn(1, 1));
            break;
        case PlayerCmd::ATTACK_SW:
            player->attack(Posn(1, -1));
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
        case PlayerCmd::USEPOTION_NE:
            player->usePotion(Posn(-1, 1));
            break;
        case PlayerCmd::USEPOTION_NW:
            player->usePotion(Posn(-1, -1));
            break;
        case PlayerCmd::USEPOTION_SE:
            player->usePotion(Posn(1, 1));
            break;
        case PlayerCmd::USEPOTION_SW:
            player->usePotion(Posn(1, -1));
            break;
        case PlayerCmd::TRADE_NO:
            player->trade(Posn(-1, 0));
            break;
        case PlayerCmd::TRADE_SO:
            player->trade(Posn(1, 0));
            break;
        case PlayerCmd::TRADE_EA:
            player->trade(Posn(0, 1));
            break;
        case PlayerCmd::TRADE_WE:
            player->trade(Posn(0, -1));
            break;
        case PlayerCmd::TRADE_NE:
            player->trade(Posn(-1, 1));
            break;
        case PlayerCmd::TRADE_NW:
            player->trade(Posn(-1, -1));
            break;
        case PlayerCmd::TRADE_SE:
            player->trade(Posn(1, 1));
            break;
        case PlayerCmd::TRADE_SW:
            player->trade(Posn(1, -1));
            break;
        case PlayerCmd::STOP:
            if (stop == -1) {
                player->setAction(" Stop The World !!!");
            } else {
                player->setAction(" Resume The World !!!");
            }
            stop = -stop;
            break;
        case PlayerCmd::RESTART:
            restartGame();
            break;
        default:
            break;
    }
    player->checkPlayerEnterFloor(haveGivenMap, givenMap);
}

void GameEngine::handleEnemiesAction() {
    floor->enemiesAction(stop);
    player->checkGold();
}


void GameEngine::restartGame() {
    player->setIsWon(false);
    player->setIsDead(false);
    if (player->getRace() == PlayerRace::VAMPIRE) {
        player->setHp(VAMPIRE_HP);
    } else {
        player->setHp(player->getMaxHp());
    }
    player->setChamberNum(-1);
    player->setGold(0);
    if (haveGivenMap) {
        floor->loadGivenFloor(givenMap);
    } else {
        floor->loadFloor();
    }
    hasRestart = true;
}



GameEngine::~GameEngine() {}
