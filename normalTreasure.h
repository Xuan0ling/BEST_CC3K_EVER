#ifndef NORMALTREASURE_H
#define NORMALTREASURE_H

#include "treasure.h"

class NormalTreasure : public Treasure {
 public:
    NormalTreasure(Floor *floor, Posn posn, int gold);
    ~NormalTreasure();
};


#endif