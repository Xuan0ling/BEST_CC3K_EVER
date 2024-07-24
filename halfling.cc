#include "halfling.h"


Halfling::Halfling(Floor* floor, Posn posn) : Enemy(floor, 'L', posn, 100, 15, 20) {}

Halfling::~Halfling() {}
