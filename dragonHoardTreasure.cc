#include "dragonHoardTreasure.h"

DragonHoardTreasure::DragonHoardTreasure(Floor *floor, Posn posn, int gold) : Treasure(floor, posn, gold)  {}

DragonHoardTreasure::~DragonHoardTreasure() {}

bool DragonHoardTreasure::getdragondead() {
    return dragondead;
}
