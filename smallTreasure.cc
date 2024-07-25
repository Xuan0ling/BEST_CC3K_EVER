#include "smallTreasure.h"
#include "player.h"

SmallTreasure::SmallTreasure(Floor *floor, Posn posn, int gold) : Treasure(floor, posn, gold) {}

SmallTreasure::~SmallTreasure() {}

bool SmallTreasure::gainGold(Player *player) {
    player->setAction(player->getAction() + " PC gains Small Gold.");
    player->gainGold(Gold);
    return true;
}

