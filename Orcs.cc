#include "Orcs.h"

Orcs::Orcs(Posn posn, Floor* floor) : Enemy('O', posn, 180, 30, 25, floor) {}

Orcs::~Orcs() {}
