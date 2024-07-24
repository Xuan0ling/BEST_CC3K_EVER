#ifndef DRAGON_HOARDTREASURE_H
#define DRAGON_HOARDTREASURE_H

#include "treasure.h"

class DragonHoardTreasure : public Treasure {
 public:
    DragonHoardTreasure(Floor *floor, Posn posn, int gold);
    ~DragonHoardTreasure();
};

#endif