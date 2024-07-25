#ifndef GOBLIN_H
#define GOBLIN_H
#include "player.h"
class Goblin: public Player {
public:
    Goblin(Floor *floor, PlayerRace race);
    ~Goblin();

};

#endif
