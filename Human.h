#ifndef HUMAN_H
#define HUMAN_H


#include "enemy.h"
#include "floor.h"


class Human : public Enemy {

 public:
    Human(Posn posn, Floor* floor);
    ~Human();
    void move(PRNG& prng) override;
    void attack(Player* player) override;
    void beAttacked(int atk) override;
};

#endif
