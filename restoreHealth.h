#ifndef RESTOREHEALTH_H
#define RESTOREHEALTH_H
#include "potion.h"
class Restorehealth: public Potion {
public:
    explicit Restorehealth(Posn posn);
    ~Restorehealth();
    void usePotion(Player *player);
};

#endif

