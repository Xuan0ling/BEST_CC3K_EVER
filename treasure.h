#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"

class Treasure: public Item {
    int Gold;
public:
    Treasure(Floor *floor, Posn posn, int gold);
    ~Treasure();
    void modifyPlayerStats(Player *player) override;
};


#endif
