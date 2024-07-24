#include "Human.h"


Human::Human(Floor* floor, Posn posn) : Enemy(floor, 'H', posn, 140, 20, 20) {}

Human::~Human() {}
