#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include "floor.h"
#include "posn.h"
class Itemfactory {
public:
    virtual ~Itemfactory() {}
    virtual Item* createItems(Posn posn) = 0;
};

#endif
