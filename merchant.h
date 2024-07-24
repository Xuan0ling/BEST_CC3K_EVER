#ifndef MERCHANT_H
#define MERCHANT_H


#include "enemy.h"

class Floor;

class Merchant : public Enemy {

 public:
    Merchant(Floor* floor, Posn posn);
    ~Merchant();
    bool attack(Player* player, PRNG prng1) override;
   // void beAttacked(int atk) override;
};

#endif
