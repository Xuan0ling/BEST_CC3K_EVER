#ifndef HALFLING_H
#define HALFLING_H


#include "enemy.h"


class Floor;

class Halfling : public Enemy {

 public:
    Halfling(Floor* floor, Posn posn);
    ~Halfling();
    bool beAttacked(Player* player, PRNG& prng) override;
};

#endif