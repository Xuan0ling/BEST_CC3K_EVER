#ifndef BOOSTATK_H
#define BOOSTATK_H
#include "potion.h"
class Player;

class Boostatk: public Potion {
public:
    Boostatk(Floor *floor, Posn posn);
    ~Boostatk();
    void modifyPlayerStats(Player *player) override;
};

#endif
