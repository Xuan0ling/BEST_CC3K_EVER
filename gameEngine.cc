#include "gameEngine.h"
#include "floor.h"
#include "gameMap.h"
#include "player.h"
#include "concretePlayerFactory.h"


GameEngine::GameEngine(std::string mapFile, PlayerRace playerRace, bool useDLC, int* playerScore) 
: playerScore(playerScore) {
    gameMap = std::make_unique<GameMap>(mapFile);
    floor = std::make_unique<Floor>();
    playerCreate(playerRace);
    floor->initFloor(player.get(), gameMap.get());
    gameInput = std::make_unique<GameInput>(useDLC);
    gameOutput = std::make_unique<GameOutput>(useDLC);
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
    floor->loadFloor();
    gameOutput->printOutput(floor->getDisplay(), player.get());

    PlayerCmd input = getAction();

    while (input != PlayerCmd::QUIT) {
        player->setAction("");
        handlePlayerCmd(input);
        handleEnemiesAction();

        gameOutput->printOutput(floor->getDisplay(), player.get());

        if (player->getIsDead() || player->getIsWon()) {
            break;
        }

        input = getAction();
    }
    *playerScore = player->getGold();
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
        case PlayerCmd::ENTERNEXTFLOOR:
            player->playerEnterFloor();
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
}

void GameEngine::handleEnemiesAction() {
    floor->enemiesAction(stop);
}


void GameEngine::restartGame() {
    player->setIsWon(false);
    player->setIsDead(false);
    if (player->getRace() == PlayerRace::VAMPIRE) {
        player->setMaxHp(VAMPIRE_HP);
    } else {
        player->setMaxHp(player->getMaxHp());
    }
    player->setChamberNum(-1);
    player->setGold(0);
    floor->loadFloor();
}



GameEngine::~GameEngine() {}
