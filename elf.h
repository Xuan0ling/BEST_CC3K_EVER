#ifndef ELF_H
#define ELF_H


#include "enemy.h"


class Elf : public Enemy {

 public:
    Elf(Floor* floor, Posn posn);
    ~Elf();
    bool attack(Player* player, PRNG prng1) override;
    bool beAttacked(Player* player) override;
};

#endif
