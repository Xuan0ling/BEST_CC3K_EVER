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

void Cell::setSymbol(char symbol) {
    this->symbol = symbol;
}

void Cell::setPlayer(Player* player) {
    this->player = player;
}

void Cell::setEnemy(Enemy* enemy) {
    this->enemy = enemy;
}

void Cell::setItem(Item* item) {
    this->item = item;
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

bool Cell::isEnemy() const {
    return enemy != nullptr;
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



