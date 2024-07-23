#ifndef HUMAN_H
#define HUMAN_H


#include "enemy.h"
class Floor;


class Human : public Enemy {

 public:
    Human(Posn posn, Floor* floor);
    ~Human();
    /* void move(PRNG& prng) override;
    void attack(Player* player) override;
    void beAttacked(int atk) override; */
};

#endif
