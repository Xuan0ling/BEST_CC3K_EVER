#ifndef DRAGON_H
#define DRAGON_H


#include "enemy.h"
class Floor;


class Dragon : public Enemy {
    
 public:
    Dragon(Floor* floor, Posn posn);
    ~Dragon();
    /* void move(PRNG& prng) override;
    void attack(Player* player) override;
    void beAttacked(int atk) override; */
};

#endif
