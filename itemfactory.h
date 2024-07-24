#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include "floor.h"
#include "posn.h"
class Itemfactory {
public:
    virtual Item createItems(Floor* floor, Posn posn) = 0;
};

#endif
