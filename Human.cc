#include "Human.h"

Human::Human(Posn posn, Floor* floor) : Enemy('H', posn, 140, 20, 20, floor) {}

Human::~Human() {}
