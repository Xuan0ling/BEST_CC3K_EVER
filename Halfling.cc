#include "Halfling.h"

Halfling::Halfling(Posn posn, Floor* floor) :  Enemy('L', posn, 100, 15, 20, floor) {}

Halfling::~Halfling() {}
