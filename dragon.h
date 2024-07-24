#ifndef DRAGON_H
#define DRAGON_H


#include "enemy.h"
class Floor;
class Item;

class Dragon : public Enemy {
    Item* dragonhoard;
    
 public:
    Dragon(Floor * floor, Posn posn, Item * hoard);
    ~Dragon();
    void move(PRNG& prng) override;
    bool attack(Player* player, PRNG prng1) override;
    void beAttacked(int atk) override;
};

#endif