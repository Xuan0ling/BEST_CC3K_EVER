#ifndef HALFLING_H
#define HALFLING_H


#include "Enemy.h"
#include "floor.h"


class Halfling : public Enemy {

 public:
    Halfling(Posn posn, Floor* floor);
    ~Halfling();
    void move(PRNG& prng) override;
    void attack(Player* player) override;
    void beAttacked(int atk) override;
};

#endif