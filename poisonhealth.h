#ifndef POISONHEALTH_H
#define POISONHEALTH_H
#include "potion.h"
class Poisonhealth: public Potion {
public:
    Poisonhealth(Floor *floor, Posn posn);
    ~Poisonhealth();
};

#endif
