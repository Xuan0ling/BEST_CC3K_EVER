#include "boostdef.h"
#include "player.h"

Boostdef::Boostdef(Floor *floor, Posn posn): Potion{floor, posn, 5} {}

Boostdef::~Boostdef() {}

void Boostdef::usePotion(Player *player) {
    if(player->getRace() == PlayerRace::DROW) {
        value = value * 1.5;
    }
    player->gainExDef(value);
    player->setAction(player->getAction() + " PC uses BD.");
}
