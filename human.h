#ifndef HUMAN_H
#define HUMAN_H


#include "enemy.h"
class Floor;


class Human : public Enemy {

 public:
    Human(Floor* floor, Posn posn);
    ~Human();
    bool beAttacked(Player* player, PRNG& prng1) override;
};

#endif
