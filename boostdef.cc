#include "boostdef.h"
#include "player.h"
Boostdef::Boostdef(Floor *floor, Posn posn): Potion{floor, posn} {}

Boostdef::~Boostdef() {}

void Boostdef::modifyPlayerStats(Player *player) {
    player->gainDef(5);
}

