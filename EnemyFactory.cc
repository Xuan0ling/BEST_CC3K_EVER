#include "enemyFactory.h"
#include "enemy.h"

Enemy EnemyFactory::createEnemy(Floor *floor, Posn posn) {
    return Enemy(floor,' ',posn, 0, 0, 0);
}

Enemy EnemyFactory::createEnemy(Floor *floor, Posn posn, Item* item) {
    return Enemy(floor, ' ',posn, 0, 0, 0);
}

EnemyFactory::~EnemyFactory() {}
