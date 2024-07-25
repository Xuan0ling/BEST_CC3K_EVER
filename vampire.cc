#include "vampire.h"
#include <limits>
const int VAMPIRE_HP = 50;
const int VAMPIRE_MAX_HP = INT_MAX;
const int VAMPIRE_ATK = 25;
const int VAMPIRE_DEF = 25;
const int VAMPIRE_ADD_HP = 5;

Vampire::Vampire(Floor *floor, PlayerRace race):
    Player(floor, race, VAMPIRE_HP, VAMPIRE_ATK, VAMPIRE_DEF, 0, VAMPIRE_MAX_HP) {}

Vampire::~Vampire() {}

void Vampire::attack(Posn attackDir) {
    return;
}

