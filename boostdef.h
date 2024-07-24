#ifndef BOOSTDEF_H
#define BOOSTDEF_H
#include "potion.h"
class Boostdef: public Potion {
public:
    Boostdef(Floor *floor, Posn posn);
    ~Boostdef();
    void modifyPlayerStats(Player *player) override;
};

#endif
