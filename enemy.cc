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

int Enemy::loseHp(int Atk) {
    int hplose = ceil((100.0/(100 + def)) * Atk);
    return hplose;
}

bool Enemy::beAttacked(Player* player) {
    return false;
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

bool Enemy::attack(Player *player, PRNG prng1) {
    std::vector<Posn> neighbours = floor->getNeighbours(posn);

    for (Posn &neighbour : neighbours) {
        if (neighbour == player->getPosn()) {
            int num = prng1(0, 1);
            if(num % 2 == 0) {
                if(symbol == 'W') {
                    player->setAction(player->getAction() + " W deals " );
                } else if (symbol == 'H') {
                    player->setAction(player->getAction() + " H deals " );
                } else if (symbol == 'L') {
                    player->setAction(player->getAction() + " L deals " );
                }
                player->LoseHP(atk);
            } else {
                if(symbol == 'W') {
                    player->setAction(player->getAction() + " W attacks and misses." );
                } else if (symbol == 'H') {
                    player->setAction(player->getAction() + " H attacks and misses." );
                } else if (symbol == 'L') {
                    player->setAction(player->getAction() + " L attacks and misses." );
                }
            }
            return true;     //add missed action
        }
    }
    return false;
}
