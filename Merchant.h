#ifndef MERCHANT_H
#define MERCHANT_H


#include "enemy.h"

class Floor;

class Merchant : public Enemy {

 public:
    Merchant(Posn posn, Floor* floor);
    ~Merchant();
    /* void move(PRNG& prng) override;
    void attack(Player* player) override;
    void beAttacked(int atk) override; */
};

#endif
