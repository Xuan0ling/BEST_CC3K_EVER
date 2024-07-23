#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <memory>
#include <string>
#include <ncurses.h>
#include "posn.h"
// define player races types
enum class PlayerCmd {
    WE, SO, NO, EA,
    ATTACK_WE, ATTACK_EA, ATTACK_NO, ATTACK_SO,
    USEPOTION_WE, USEPOTION_EA, USEPOTION_NO, USEPOTION_SO,
    ENTERNEXTFLOOR,
    RESTART, QUIT, INVALID
};

enum class PlayerRace {
    SHADE, DROW, VAMPIRE, TROLL, GOBLIN, INVALID
};


const int MAP_WIDTH = 79;
const int MAP_HEIGHT = 25;


// forward declaration
class Player;
class Floor;
class GameMap;
class GameInput;
class GameOutput;
class Enemy;
class Item;

// define unique pointers
typedef std::unique_ptr<Player> PlayerPtr;
typedef std::unique_ptr<Floor> FloorPtr;
typedef std::unique_ptr<GameInput> GameInputPtr;
typedef std::unique_ptr<GameOutput> GameOutputPtr;
typedef std::unique_ptr<GameMap> GameMapPtr;
typedef std::unique_ptr<Enemy> EnemyPtr;
typedef std::unique_ptr<Item> ItemPtr;



#endif
