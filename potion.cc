#include "potion.h"
#include "player.h"

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

void Potion::usePotion(Player* player) {
    player->gainHp(BuffHP);
    if (player->getHp() > player->getMaxHp()) {
        player->setHp(player->getMaxHp());
    }
    player->gainExAtk(BuffATK);
    player->gainExDef(BuffDEF);
}


