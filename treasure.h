#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"

class Treasure: public Item {
 protected:
    int Gold;
public:
    Treasure(Posn posn, int gold);
    ~Treasure() = 0;
    int getGold() override;
};


#endif
