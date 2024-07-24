#ifndef CONCRETEENEMY_H
#define CONCRETEENEMY_H

#include "enemyFactory.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include "item.h"

class HumanFactory : public EnemyFactory {
 public:
    Enemy* createEnemy(Floor* floor, Posn posn) override {
        return new Human(floor, posn);
    }
};

class DwarfFactory : public EnemyFactory {
 public:
    Enemy* createEnemy(Floor* floor, Posn posn) override {
        return new Dwarf(floor, posn);
    }
};

class ElfFactory : public EnemyFactory {
 public:
    Enemy* createEnemy( Floor* floor, Posn posn) override {
        return new Elf(floor, posn);
    }
};

class OrcsFactory : public EnemyFactory {
 public:
    Enemy* createEnemy(Floor* floor, Posn posn) override {
        return new Orcs(floor, posn);
    }
};

class MerchantFactory : public EnemyFactory {
 public:
    Enemy* createEnemy(Floor* floor, Posn posn) override {
        return new Merchant(floor, posn);
    }
};

class DragonFactory : public EnemyFactory {
 public:
    Enemy* createEnemy(Floor* floor, Posn posn, Item* item) {
        return new Dragon(floor, posn, item); 

    }
};

class HalflingFactory : public EnemyFactory {
 public:
    Enemy* createEnemy(Floor* floor, Posn posn) override {
        return new Halfling(floor, posn);
    }
};



#endif