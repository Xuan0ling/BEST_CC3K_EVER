#include "potion.h"

Potion::Potion( Floor* floor, Posn posn, int buffatk, int buffdef, int buffhp)
    : Item{floor, posn, 'P'}, BuffHP{buffhp}, BuffATK{buffatk}, BuffDEF{buffdef} {}

Potion::~Potion() {}

int Potion::getBuffHP() {
    return BuffHP;
}

int Potion::getBuffATK() {
    return BuffATK;
}


int Potion::getBuffDEF() {
    return BuffDEF;
}


