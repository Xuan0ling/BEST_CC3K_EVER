#ifndef DWARF_H
#define DWARF_H


#include "enemy.h"
class Floor;



class Dwarf : public Enemy {

 public:
    Dwarf(Posn posn, Floor* floor);
    ~Dwarf();
    /* void move(PRNG& prng) override;
    void attack(Player* player) override;
    void beAttacked(int atk) override; */
};

#endif
