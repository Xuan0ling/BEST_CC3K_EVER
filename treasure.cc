#include "treasure.h"
#include "player.h"

Treasure::Treasure(Posn posn, int gold): Item(posn, 'G'), Gold(gold) {}

Treasure::~Treasure() {}

int Treasure::getGold() {
    return Gold;
}

