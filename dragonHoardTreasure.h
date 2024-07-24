#ifndef DRAGON_HOARDTREASURE_H
#define DRAGON_HOARDTREASURE_H

#include "treasure.h"

class DragonHoardTreasure : public Treasure {
    bool dragondead = false;
 public:
    DragonHoardTreasure(Floor *floor, Posn posn, int gold);
    ~DragonHoardTreasure();
    bool getdragondead();
};

#endif