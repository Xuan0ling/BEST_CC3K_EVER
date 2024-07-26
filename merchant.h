#ifndef MERCHANT_H
#define MERCHANT_H


#include "enemy.h"

class Floor;

class Merchant : public Enemy {

 public:
    Merchant(Floor* floor, Posn posn);
    ~Merchant();
    void move(PRNG& prng) override;
    bool attack(Player* player, PRNG& prng1) override;
    bool beAttacked(Player* player, PRNG& prng1) override;
};

#endif
