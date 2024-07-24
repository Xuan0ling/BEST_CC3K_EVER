#ifndef POTION_H
#define POTION_H

#include "item.h"
#include <string>

class Potion: public Item {
public:
    Potion(Floor *floor, Posn posn);
    ~Potion(); 
};

#endif
