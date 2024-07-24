
#include "wounddef.h"
#include "player.h"
Wounddef::Wounddef(Floor* floor, Posn posn): Potion(floor, posn) {}


Wounddef::~Wounddef() {}

void Wounddef::modifyPlayerStats(Player *player) {
    player->gainDef(-5);
}
