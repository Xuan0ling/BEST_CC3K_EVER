#include "item.h"


Item::Item(Posn posn, char symbol): posn{posn}, symbol{symbol} {}


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

void Item::usePotion(Player *player) {}

bool Item::gainGold(Player *player) {
    return false;
}

void Item::setDragonDead() {}
