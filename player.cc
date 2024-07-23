#include "player.h"
#include "floor.h"



Player::Player(Floor* floor, int hp, int atk, int def, int gold, int maxHp) 
: hp{hp}, atk{atk}, def{def}, gold{gold}, maxHp{maxHp}, floor{floor} {}


void Player::setPosn(Posn newPosn) {
    posn = newPosn;
}

void Player::changePosn(Posn posnChange) {
    posn = posn + posnChange;
}

Posn Player::getPosn() {
    return posn;
}

char Player::getSymbol() {
    return '@';
}



// special ability will override those functions
//-----------------------------------------------------------------------------
void Player::move(Posn posnChange) {
    floor->clearCell(posn);
    Posn newPosn = posn + posnChange;
    if (floor->checkValidMove(newPosn)) {
        changePosn(posnChange);
    }
    floor->updatePlayer();
}

void Player::attack(Posn attackDir) {} 

void Player::usePotion(Posn usePotionDir) {}

void Player::gainGold() {}

//-----------------------------------------------------------------------------


void Player::setHp(int hp) {
    this->hp = hp;
}

void Player::setGold(int gold) {
    this->gold = gold;
}


void Player::gainHp(int hp) {
    this->hp += hp;
}

void Player::gainAtk(int atk) {
    this->atk += atk;
}

void Player::gainDef(int def) {
    this->def += def;
}

void Player::gainGold(int gold) {
    this->gold += gold;
}

void Player::gainExAtk(int exAtk) {
    this->exAtk += exAtk;
}

void Player::gainExDef(int exDef) {
    this->exDef += exDef;
}

void Player::gainCurrFloorIndex(int currFloorIndex) {
    this->currFloorIndex += currFloorIndex;
}

void Player::setMaxHp(int maxHp) {
    this->maxHp = maxHp;
}

void Player::setIsDead(bool isDead) {
    this->isDead = isDead;
}

void Player::setIsWon(bool isWon) {
    this->isWon = isWon;
}

int Player::getHp() {
    return hp;
}

int Player::getAtk() {
    return atk;
}

int Player::getDef() {
    return def;
}

int Player::getGold() {
    return gold;
}

int Player::getMaxHp() {
    return maxHp;
}

int Player::getExAtk() {
    return exAtk;
}

int Player::getExDef() {
    return exDef;
}

int Player::getCurrFloorIndex() {
    return currFloorIndex;
}

bool Player::getIsDead() {
    return isDead;
}

bool Player::getIsWon() {
    return isWon;
}

Player::~Player() {}



