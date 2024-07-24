#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"

class Treasure: public Item {
    int Gold;
    char symbol = 'G';
public:
    Treasure(Floor *floor, Posn posn, int gold);
    ~Treasure();
    int getGold();
};


#endif
