#ifndef ITEM_H
#define ITEM_H
#include "posn.h"
#include "floor.h"

class Item {
    Posn posn;
    char symbol;
public:
    Item(Posn posn, char symbol);
    virtual ~Item() = 0;
    Posn getPosn();
    void setPosn(Posn posn);
    char getSymbol();
    virtual int getGold();
    virtual void usePotion(Player *player);
    virtual bool gainGold(Player *player);
    virtual void setDragonDead();
};

#endif