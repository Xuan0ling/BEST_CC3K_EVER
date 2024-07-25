#include "merchantHoardTreasure.h"
#include "player.h"

MerchantHoardTreasure::MerchantHoardTreasure(Posn posn, int gold) : Treasure(posn, gold) {}

MerchantHoardTreasure::~MerchantHoardTreasure() {}

bool MerchantHoardTreasure::gainGold(Player *player) {
    player->setAction(player->getAction() + " PC gains Merchant Hoard.");
    player->gainGold(Gold);
    return true;
}
