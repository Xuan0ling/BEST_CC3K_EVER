#include "dragon.h"
#include "floor.h"
#include "item.h"


Dragon::Dragon (Floor* floor, Posn posn, Item* hoard) 
: Enemy{floor, SYMBOL_DRAGON, posn, 150, 20, 20}, dragonhoard{hoard} {}


Dragon::~Dragon() {}


