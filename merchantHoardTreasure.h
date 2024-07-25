#ifndef MERCHANT_HOARDTREASURE_H
#define MERCHANT_HOARDTREASURE_H

#include "treasure.h"

class MerchantHoardTreasure : public Treasure {
 public:
    MerchantHoardTreasure(Posn posn, int gold);
    ~MerchantHoardTreasure();
    bool gainGold(Player* player) override;
};


#endif