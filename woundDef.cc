#include "woundDef.h"
#include "player.h"


Wounddef::Wounddef(Floor* floor, Posn posn): Potion(floor, posn, -5) {}

Wounddef::~Wounddef() {}

void Wounddef::usePotion(Player *player) {
    if(player->getRace() == PlayerRace::DROW) {
        value = value * 1.5;
    }
    player->gainExDef(value);
    player->setAction(player->getAction() + " PC uses WD.");
}
