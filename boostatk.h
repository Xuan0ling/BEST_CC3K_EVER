#ifndef BOOSTATK_H
#define BOOSTATK_H
#include "potion.h"
class Boostatk: public Potion {
public:
    Boostatk(Posn posn);
    ~Boostatk();
    void usePotion(Player *player) override;
};

#endif
