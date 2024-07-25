#ifndef WOUNDATK_H
#define WOUNDATK_H

#include "potion.h"

class Woundatk: public Potion {
public:
    Woundatk(Floor *floor, Posn posn);
    ~Woundatk();
    void usePotion(Player *player);
};

#endif
