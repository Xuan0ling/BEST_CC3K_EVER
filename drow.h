#ifndef DROW_H
#define DROW_H
#include "player.h"

class Drow: public Player {
public:
    Drow(Floor *floor, PlayerRace race);
    ~Drow();
};

#endif 
