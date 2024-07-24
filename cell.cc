#include "cell.h"
#include "player.h"
#include "enemy.h"
#include "item.h"


Cell::Cell(char symbol) : symbol{symbol}, player{nullptr}, enemy{nullptr}, item{nullptr} {}

Cell::~Cell() {
    clearPointers();
}

void Cell::clearPointers() {
    player = nullptr;
    enemy = nullptr;
    item = nullptr;
}

void Cell::clearPlayer() {
    player = nullptr;
}

void Cell::clearEnemy() {
    enemy = nullptr;
}

void Cell::clearItem() {
    item = nullptr;
}

void Cell::setSymbol(char symbol) {
    this->symbol = symbol;
}

void Cell::setPlayer(Player* player) {
    this->player = player;
}

void Cell::setEnemy(Enemy* enemy) {
    clearPointers();
    this->enemy = enemy;
}

void Cell::setItem(Item* item) {
    this->item = item;
}

void Cell::setStair() {
    symbol = SYMBOL_STAIR;
}

bool Cell::hasGold() const {
    if (item && item->getSymbol() == SYMBOL_GOLD) {
        return true;
    } else {
        return false;
    }
}

bool Cell::hasStair() const {
    if (symbol == SYMBOL_STAIR) {
        return true;
    } else {
        return false;
    }
}

bool Cell::hasPotion() const {
    if (item && item->getSymbol() == SYMBOL_POTION) {
        return true;
    } else {
        return false;
    }
}

bool Cell::hasEnemy() const {
    if (enemy) {
        return true;
    } else {
        return false;
    }
}

char Cell::getSymbol() const {
    return symbol;
}

Player* Cell::getPlayer() const {
    return player;
}

Enemy* Cell::getEnemy() const {
    return enemy;
}

Item* Cell::getItem() const {
    return item;
}

bool Cell::isEmpty() const {
    if (player || enemy || item) {
        return false;
    } else {
        return true;
    }
}

char Cell::getDisplaySymbol() const {
    if (player) {
        return player->getSymbol();
    } else if (enemy) {
        return enemy->getSymbol();
    } else if (item) {
        return item->getSymbol();
    } else {
        return symbol;
    }
}



