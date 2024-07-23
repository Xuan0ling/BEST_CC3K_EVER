#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "enemy.h"

class EnemyFactory {
 public:
    virtual Enemy* createEnemy(Posn posn, Floor* floor) = 0;
    virtual ~EnemyFactory() {}
};

#endif
