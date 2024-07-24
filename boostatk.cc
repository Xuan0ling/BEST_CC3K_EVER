#include "boostatk.h"
#include "player.h"
Boostatk::Boostatk(Floor *floor, Posn posn): Potion{floor, posn} {}


Boostatk::~Boostatk() {}

void Boostatk::modifyPlayerStats(Player *player) {
    player->gainAtk(5);
}
