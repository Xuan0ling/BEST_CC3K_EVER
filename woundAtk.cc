#include "woundAtk.h"
#include "player.h"


Woundatk::Woundatk(Posn posn): Potion(posn, -10) {}

Woundatk::~Woundatk() {}

void Woundatk::usePotion(Player *player) {
    if(player->getRace() == PlayerRace::DROW) {
        value = value * 1.5;
    }
    player->gainExAtk(value);
    player->setAction(player->getAction() + " PC uses WA.");
}
