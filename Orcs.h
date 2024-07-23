#ifndef ORCS_H
#define ORCS_H


#include "enemy.h"
#include "floor.h"



class Orcs : public Enemy {

 public:
    Orcs(Posn posn, Floor* floor);
    ~Orcs();
    void move(PRNG& prng) override;
    void attack(Player* player) override;
    void beAttacked(int atk) override;
};

#endif