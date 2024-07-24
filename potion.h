#ifndef POTION_H
#define POTION_H

#include "item.h"
#include <string>

class Potion: public Item {
protected:
    int BuffHP;
    int BuffATK;
    int BuffDEF;
public:
    Potion(Floor *floor, Posn posn, int buffatk, int buffdef, int buffhp);
    ~Potion();
    int getBuffHP();
    int getBuffATK();
    int getBuffDEF();
};

#endif
