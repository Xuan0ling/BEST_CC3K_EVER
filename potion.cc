#include "potion.h"
#include "player.h"

Potion::Potion(Posn posn, int value): Item{posn, 'P'}, value{value} {}

Potion::~Potion() {}

int Potion::getValue() {
    return value;
}

