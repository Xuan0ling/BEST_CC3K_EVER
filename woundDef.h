#ifndef WOUNDDEF_H
#define WOUNDDEF_H
#include "potion.h"

class Wounddef: public Potion {
public: 
    Wounddef(Posn posn);
    ~Wounddef();
    void usePotion(Player *player);
};

#endif
