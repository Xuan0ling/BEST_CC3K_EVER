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

// ASCII color codes
const std::string RESET = "\033[0m";
const std::string BLUE = "\033[38;5;45m";
const std::string RED = "\033[38;5;196m";
const std::string YELLOW = "\033[38;5;226m";
const std::string GREEN = "\033[38;5;46m";

// Define color pairs
#define COLOR_PAIR_PLAYER 1
#define COLOR_PAIR_STAIRCASE 2
#define COLOR_PAIR_ENEMY 3
#define COLOR_PAIR_TREASURE 4
#define COLOR_PAIR_POTION 5

// character symbols
const char SYMBOL_PLAYER = '@';
const char SYMBOL_STAIR = '\\';
const char SYMBOL_HUMAN = 'H';
const char SYMBOL_DWARF = 'W';
const char SYMBOL_ELF = 'E';
const char SYMBOL_ORC = 'O';
const char SYMBOL_MERCHANT = 'M';
const char SYMBOL_DRAGON = 'D';
const char SYMBOL_HALFLING = 'L';
const char SYMBOL_POTION = 'P';
const char SYMBOL_GOLD = 'G';




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
