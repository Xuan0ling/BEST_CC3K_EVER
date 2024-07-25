#ifndef DWARF_H
#define DWARF_H


#include "enemy.h"
class Floor;



class Dwarf : public Enemy {

 public:
    Dwarf(Floor* floor, Posn posn);
    ~Dwarf();
    bool beAttacked(Player* player, PRNG& prng1) override;
};

#endif
