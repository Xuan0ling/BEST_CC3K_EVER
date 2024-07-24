#include "item.h"

Item::Item( Floor *floor, Posn posn, char symbol): floor{floor}, posn{posn}, symbol{symbol} {}

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

int Item::getGold() {
    return 0;
}


