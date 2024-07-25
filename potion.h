#ifndef POTION_H
#define POTION_H

#include "item.h"
#include <string>

class Potion: public Item {
protected:
    int value;
public:
    Potion(Floor *floor, Posn posn, int value);
    ~Potion();
    int getValue();
};

#endif
