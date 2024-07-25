#include "dragonHoardTreasure.h"
#include "player.h"

DragonHoardTreasure::DragonHoardTreasure(Posn posn, int gold) : Treasure(posn, gold)  {}

DragonHoardTreasure::~DragonHoardTreasure() {}

void DragonHoardTreasure::setDragonDead() {
    dragondead = true;
}

bool DragonHoardTreasure::getdragondead() {
    return dragondead;
}

bool DragonHoardTreasure::gainGold(Player *player) {
    if(dragondead) {
        player->setAction(player->getAction() + " PC gains Dragon Hoard.");
        player->gainGold(Gold);
        return true;
    } else {
        player->setAction(player->getAction() + " PC stepped on Dragon Hoard while Dragon is still alive.");
        return false;
    }

}
