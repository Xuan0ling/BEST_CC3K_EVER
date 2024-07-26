#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H
#include "player.h"

class Playerfactory {
public:
    virtual ~Playerfactory() {}
    virtual Player* createPlayer(Floor* floor) = 0;
};


#endif 
