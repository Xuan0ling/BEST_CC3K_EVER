#ifndef WOUNDDEF_H
#define WOUNDDEF_H
#include "potion.h"

class Wounddef: public Potion {
public: 
    Wounddef(Floor* floor, Posn posn);
    ~Wounddef();
};

#endif
