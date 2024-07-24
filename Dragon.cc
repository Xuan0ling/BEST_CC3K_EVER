#include "dragon.h"

Dragon::Dragon(Floor* floor, Posn posn) : Enemy(floor, 'D', posn, 150, 20, 20) {}

Dragon::~Dragon() {}
