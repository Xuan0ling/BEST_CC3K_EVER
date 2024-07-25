#include "treasure.h"
#include "player.h"

Treasure::Treasure(Floor *floor, Posn posn, int gold): Item(floor, posn, 'G'), Gold(gold) {}

Treasure::~Treasure() {}

int Treasure::getGold() {
    return Gold;
}

