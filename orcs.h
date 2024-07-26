#ifndef ORCS_H
#define ORCS_H


#include "enemy.h"

class Floor;

class Orcs : public Enemy {

 public:
    Orcs(Floor* floor, Posn posn);
    ~Orcs();
    bool attack(Player* player, PRNG& prng1) override;
    bool beAttacked(Player* player, PRNG& prng1) override;
};

#endif
