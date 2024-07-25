#ifndef DRAGON_HOARDTREASURE_H
#define DRAGON_HOARDTREASURE_H

#include "treasure.h"

class DragonHoardTreasure : public Treasure {
    bool dragondead = false;
 public:
    DragonHoardTreasure(Posn posn, int gold);
    ~DragonHoardTreasure();
    void setDragonDead() override;
    bool getdragondead();
    bool gainGold(Player* player) override;
};

#endif