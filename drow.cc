#include "drow.h"

const int DROW_HP = 150;
const int DROW_ATK = 25;
const int DROW_DEF = 15;

Drow::Drow(Floor *floor, PlayerRace race):
    Player(floor, race, DROW_HP, DROW_ATK, DROW_DEF, 0, DROW_HP) {}

Drow::~Drow() {}

