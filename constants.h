#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <memory>
#include <vector>
#include <string>
#include <ncurses.h>
#include <fstream>
#include "posn.h"
// define player races types
enum class PlayerCmd {
    WE, NO, SO, EA, NE, NW, SE, SW, 
    ATTACK_WE, ATTACK_NO, ATTACK_SO, ATTACK_EA,
    USEPOTION_WE, USEPOTION_NO, USEPOTION_SO, USEPOTION_EA,
    ENTERNEXTFLOOR, RESTART, QUIT, STOP, INVALID
};

enum class PlayerRace {
    SHADE, DROW, VAMPIRE, TROLL, GOBLIN, INVALID, QUIT
};


const int MAP_WIDTH = 79;
const int MAP_HEIGHT = 25;
const int NUM_FLOORS = 5;
const int NUM_CHAMBERS = 5;

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
