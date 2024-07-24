#ifndef ITEM_H
#define ITEM_H
#include "posn.h"
#include "floor.h"

class Item {
    Floor *floor;
    Posn posn;
    char symbol;
public:
    Item(Floor* floor, Posn posn, char symbol);
    virtual ~Item();
    Posn getPosn();
    void setPosn(Posn posn);
    char getSymbol();
    virtual int getGold();
    virtual void usePotion(Player *player);
};

#endif