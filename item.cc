#include "item.h"

Item::Item(Posn posn) : posn{posn} {}

Item::~Item() {}

Posn Item::getPosn() {
    return posn;
}

void Item::setPosn(Posn posn) {
    this->posn = posn;
}

