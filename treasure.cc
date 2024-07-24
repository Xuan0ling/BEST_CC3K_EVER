#include "treasure.h"

Treasure::Treasure(Floor *floor, Posn posn, int gold): Item(floor, posn, 'T'), Gold(gold) {}

Treasure::~Treasure() {}

int Treasure::getGold() {
    return Gold;
}
