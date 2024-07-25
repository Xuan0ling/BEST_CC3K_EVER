#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"

class Vampire: public Player {
public:
    Vampire(Floor *floor, PlayerRace race);
    ~Vampire();
    void attack(Posn attackDir) override;
};

#endif 
