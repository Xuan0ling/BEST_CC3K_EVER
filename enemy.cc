#include "enemy.h"
#include "player.h"

Enemy::Enemy(Floor* floor, char symbol, Posn posn, int hp, int atk, int def) 
: floor{floor}, symbol{symbol}, posn{posn}, hp{hp}, atk{atk}, def{def} {}

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


void Enemy::beAttacked(int atk) {
}

void Enemy::move(PRNG& prng) {
    std::vector<Posn> neighbours = floor->getNeighbours(posn);
    std::vector<Posn> validNeighbours;
    for (Posn neighbour : neighbours) {
        if (floor->checkValidMoveForEnemy(neighbour)) {
            validNeighbours.push_back(neighbour);
        }
    }
    if (validNeighbours.size() == 0) {
        return;
    }
    int index = prng(0, validNeighbours.size() - 1);
    Posn newPosn = validNeighbours[index];
    floor->clearCell(posn);
    posn = newPosn;
    floor->updateEnemy(this);
}

bool Enemy::attack(Player* player) {
    std::vector<Posn> neighbours = floor->getNeighbours(posn);
    for (Posn neighbour : neighbours) {
        if (player->getPosn() == neighbour) {
            return true;
        }
    }

    return false;
}
