#ifndef MERCHANT_HOARDTREASURE_H
#define MERCHANT_HOARDTREASURE_H

#include "treasure.h"

class MerchantHoardTreasure : public Treasure {
 public:
    MerchantHoardTreasure(Floor *floor, Posn posn, int gold);
    ~MerchantHoardTreasure();
    bool gainGold(Player* player);
};


#endif