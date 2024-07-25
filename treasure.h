#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"

class Treasure: public Item {
 protected:
    int Gold;
public:
    Treasure(Floor *floor, Posn posn, int gold);
    ~Treasure();
    int getGold() override;
};


#endif
