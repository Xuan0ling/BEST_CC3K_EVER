#include "restoreHealth.h"
#include "player.h"

Restorehealth::Restorehealth(Floor *floor, Posn posn): Potion(floor, posn, 10) {}

Restorehealth::~Restorehealth() {}

void Restorehealth::usePotion(Player *player) {
    if(player->getRace() == PlayerRace::DROW) {
        value = value * 1.5;
    }
    player->gainHp(value);
    player->setAction(player->getAction() + " PC uses RH.");

}
