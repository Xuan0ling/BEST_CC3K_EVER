#include "poisonHealth.h"
#include "player.h"

Poisonhealth::Poisonhealth(Posn posn): Potion(posn, -10) {}

Poisonhealth::~Poisonhealth() {}

void Poisonhealth::usePotion(Player *player) {
     if(player->getRace() == PlayerRace::DROW) {
        value = value * 1.5;
    }
    player->gainHp(value);
    player->setAction(player->getAction() + " PC uses PH.");
}
