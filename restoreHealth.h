#ifndef RESTOREHEALTH_H
#define RESTOREHEALTH_H
#include "potion.h"
class Restorehealth: public Potion {
public:
    Restorehealth(Floor *floor, Posn posn);
    ~Restorehealth();
    void usePotion(Player *player);
};

#endif

