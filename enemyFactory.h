#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <memory>
#include "enemy.h"
class Item;

class EnemyFactory {
 public:
    virtual Enemy* createEnemy(Floor* floor, Posn posn, Item* item = nullptr) = 0;
    virtual ~EnemyFactory();
};

#endif
