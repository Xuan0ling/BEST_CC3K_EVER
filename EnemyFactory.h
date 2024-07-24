#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <memory>
#include "enemy.h"


class EnemyFactory {
 public:
    virtual Enemy createEnemy(Floor* floor, Posn posn) = 0;
    virtual ~EnemyFactory() {}
};

#endif
