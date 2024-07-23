#ifndef HALFLING_H
#define HALFLING_H


#include "enemy.h"


class Floor;

class Halfling : public Enemy {

 public:
    Halfling(Posn posn, Floor* floor);
    ~Halfling();
    /* void move(PRNG& prng) override;
    void attack(Player* player) override;
    void beAttacked(int atk) override; */
};

#endif