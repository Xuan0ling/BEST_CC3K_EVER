#include "treasure.h"
#include "player.h"

Treasure::Treasure(Floor *floor, Posn posn, int gold): Item(floor, posn, 'T'), Gold(gold) {}

Treasure::~Treasure() {}

void Treasure::modifyPlayerStats(Player *player) {
    player->gainGold(Gold);
}
