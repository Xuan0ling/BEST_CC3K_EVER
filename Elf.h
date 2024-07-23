#ifndef ELF_H
#define ELF_H


#include "enemy.h"


class Elf : public Enemy {

 public:
    Elf(Posn posn, Floor* floor);
    ~Elf();
    /* void move(PRNG& prng) override;
    void attack(Player* player) override;
    void beAttacked(int atk) override; */
};

#endif
