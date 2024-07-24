#ifndef ITEM_H
#define ITEM_H
#include "posn.h"
#include "floor.h"

class Item {
    char symbol;
    Posn posn;
    Floor *floor;
public:
    Item(Floor* floor, Posn posn, char symbol);
    virtual ~Item();
    Posn getPosn();
    void setPosn(Posn posn);
    char getSymbol();
};

#endif