#include "treasure.h"
#include "player.h"

Treasure::Treasure(Floor *floor, Posn posn, int gold): Item(floor, posn, 'G'), Gold(gold) {}

Treasure::~Treasure() {}

void Treasure::modifyPlayerStats(Player *player) {
    player->gainGold(Gold);
}

void Treasure::modifystats(Player *player) {
    player->gainGold(Gold);
}
