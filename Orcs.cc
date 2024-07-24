#include "orcs.h"


Orcs::Orcs(Floor* floor, Posn posn) : Enemy(floor, 'O', posn, 180, 30, 25) {}

Orcs::~Orcs() {}
