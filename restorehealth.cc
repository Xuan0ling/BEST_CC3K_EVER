
#include "restorehealth.h"
#include "player.h"

Restorehealth::Restorehealth(Floor *floor, Posn posn): Potion(floor, posn) {}

Restorehealth::~Restorehealth() {}

void Restorehealth::modifyPlayerStats(Player *player) {
    player->gainHp(10);
}
