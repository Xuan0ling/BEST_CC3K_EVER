#include "potion.h"
#include "player.h"

Potion::Potion( Floor* floor, Posn posn, int value)
    : Item{floor, posn, 'P'}, value{value} {}

Potion::~Potion() {}

int Potion::getValue() {
    return value;
}

