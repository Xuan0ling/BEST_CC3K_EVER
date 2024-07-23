#include "enemy.h"

Enemy::Enemy(char symbol, Posn posn, int hp, int atk, int def, Floor* floor) : symbol{symbol}, posn{posn}, hp{hp}, atk{atk}, def{def}, floor{floor} {}

Enemy::~Enemy() {}

void Enemy::setPosn(Posn posn) {
    this->posn = posn;
}

char Enemy::getSymbol() {
    return symbol;
}

Posn Enemy::getPosn()
{
    return posn;
}

int Enemy::getHp() {
    return hp;
}

int Enemy::getAtk() {
    return atk;
}

int Enemy::getDef() {
    return def;
}


void Enemy::gainHp(int hp) {
    this->hp += hp;
}

void Enemy::gainAtk(int atk) {
    this->atk += atk;
}

void Enemy::gainDef(int def) {
    this->def += def;
}

void Enemy::beAttacked(int atk) {
    int damage = ceil((100.0 / (100 + def)) * atk);
    hp -= damage;
}

void Enemy::move(PRNG& prng) {
}

void Enemy::attack(Player* player) {
}
