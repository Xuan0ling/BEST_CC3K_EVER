#include "smallTreasure.h"
#include "player.h"

SmallTreasure::SmallTreasure(Posn posn, int gold) : Treasure(posn, gold) {}

SmallTreasure::~SmallTreasure() {}

bool SmallTreasure::gainGold(Player *player) {
    player->setAction(player->getAction() + " PC gains Small Gold.");
    player->gainGold(Gold);
    return true;
}

