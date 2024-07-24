#ifndef ELF_H
#define ELF_H


#include "enemy.h"


class Elf : public Enemy {

 public:
    Elf(Floor* floor, Posn posn);
    ~Elf();
    /* void move(PRNG& prng) override;
    void attack(Player* player) override;
    void beAttacked(int atk) override; */
};

#endif
