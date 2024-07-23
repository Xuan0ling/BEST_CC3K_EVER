#ifndef DRAGON_H
#define DRAGON_H


#include "enemy.h"
#include "floor.h"


class Dragon : public Enemy {

 public:
    Dragon(Posn posn, Floor* floor);
    ~Dragon();
    void move(PRNG& prng) override;
    void attack(Player* player) override;
    void beAttacked(int atk) override;
};

#endif