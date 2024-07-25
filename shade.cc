#include "shade.h"

const int DROW_HP = 125;
const int DROW_DEF = 25;
const int DROW_ATK = 25;

Shade::Shade(Floor *floor, PlayerRace race): 
    Player(floor, race, DROW_HP, DROW_ATK, DROW_DEF, 0, DROW_HP) {}

Shade::~Shade() {}

