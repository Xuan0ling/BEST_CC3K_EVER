
#include "woundatk.h"
#include "player.h"

Woundatk::Woundatk(Floor *floor, Posn posn): Potion(floor, posn) {}

Woundatk::~Woundatk() {}

void Woundatk::modifyPlayerStats(Player *player) {
    player->gainAtk(-5);
}
