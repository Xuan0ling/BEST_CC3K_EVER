#include "boostatk.h"
#include "player.h"

Boostatk::Boostatk(Posn posn): Potion{posn, 5} {}

Boostatk::~Boostatk() {}

void Boostatk::usePotion(Player *player) {
    if(player->getRace() == PlayerRace::DROW) {
        value = value * 1.5;
    }
    player->gainExAtk(value);
    player->setAction(player->getAction() + " PC uses BA.");

}
