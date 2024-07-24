#ifndef ORCS_H
#define ORCS_H


#include "enemy.h"

class Floor;

class Orcs : public Enemy {

 public:
    Orcs(Floor* floor, Posn posn);
    ~Orcs();
    /* void move(PRNG& prng) override;
    void attack(Player* player) override;
    void beAttacked(int atk) override; */
};

#endif
