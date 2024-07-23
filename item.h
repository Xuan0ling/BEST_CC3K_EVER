#ifndef ITEM_H
#define ITEM_H
#include "posn.h"

class Item {
    Posn posn;
public:
    Item(Posn posn);
    virtual ~Item();
    Posn getPosn();
    void setPosn(Posn posn);

    virtual char getSymbol() = 0;
    virtual void use() = 0;
};

#endif