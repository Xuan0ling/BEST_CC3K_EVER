#ifndef SHADE_H
#define SHADE_H

#include "player.h"

class Shade: public Player {
public:
    Shade(Floor *floor, PlayerRace race);
    ~Shade();
};


#endif 

