#include "poisonhealth.h"
#include "player.h"

Poisonhealth::Poisonhealth(Floor *floor, Posn posn): Potion(floor, posn) {}

Poisonhealth::~Poisonhealth() {}

void Poisonhealth::modifyPlayerStats(Player *player) {
    player->gainHp(-10);
}

