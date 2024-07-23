#include "Dragon.h"

Dragon::Dragon(Posn posn, Floor* floor) : Enemy('D', posn, 150, 20, 20, floor) {}

Dragon::~Dragon() {}
