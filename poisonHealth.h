#ifndef POISONHEALTH_H
#define POISONHEALTH_H
#include "potion.h"
class Poisonhealth: public Potion {
public:
    Poisonhealth(Posn posn);
    ~Poisonhealth();
    void usePotion(Player *player);
};

#endif
