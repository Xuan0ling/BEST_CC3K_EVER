#ifndef BOOSTATK_H
#define BOOSTATK_H
#include "potion.h"
class Boostatk: public Potion {
public:
    Boostatk(Floor *floor, Posn posn);
    ~Boostatk();
    void usePotion(Player *player) override;
};

#endif
