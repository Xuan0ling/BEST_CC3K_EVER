#ifndef BOOSTDEF_H
#define BOOSTDEF_H
#include "potion.h"

class Boostdef: public Potion {
public:
    Boostdef(Posn posn);
    ~Boostdef();
    void usePotion(Player *player);
};

#endif
