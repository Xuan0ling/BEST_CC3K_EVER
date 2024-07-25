#ifndef NORMALTREASURE_H
#define NORMALTREASURE_H

#include "treasure.h"

class NormalTreasure : public Treasure {
 public:
    NormalTreasure(Posn posn, int gold);
    ~NormalTreasure();
    bool gainGold(Player* player) override;
};


#endif