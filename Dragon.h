#ifndef DRAGON_H
#define DRAGON_H


#include "enemy.h"
class Floor;


class Dragon : public Enemy {

 public:
    Dragon(Posn posn, Floor* floor);
    ~Dragon();
    /* void move(PRNG& prng) override;
    void attack(Player* player) override;
    void beAttacked(int atk) override; */
};

#endif