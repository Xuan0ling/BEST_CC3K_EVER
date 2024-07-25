#include "normalTreasure.h"
#include "player.h"


NormalTreasure::NormalTreasure(Floor *floor, Posn posn, int gold) : Treasure(floor, posn, gold) {}

NormalTreasure::~NormalTreasure() {}

bool NormalTreasure::gainGold(Player *player) {
    if(Gold == 4) {
        player->setAction(player->getAction() + " PC gains 2 Normal Gold piles.");
        player->gainGold(Gold);
        return true;
    }
    player->setAction(player->getAction() + " PC gains Normal Gold.");
    player->gainGold(Gold);
    return true;
}
