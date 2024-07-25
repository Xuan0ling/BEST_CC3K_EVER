#ifndef TROLL_H
#define TROLL_H
#include "player.h"

class Troll: public Player {
public:
    Troll(Floor *floor, PlayerRace race);
    ~Troll();
};

#endif 
