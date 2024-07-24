#include "item.h"

Item::Item( Floor *floor, Posn posn, char symbol): symbol{symbol}, posn{posn}, floor{floor} {}

Item::~Item() {}

Posn Item::getPosn() {
    return posn;
}

void Item::setPosn(Posn posn) {
    this->posn = posn;
}

char Item::getSymbol() {
    return symbol;
}
