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

class HumanFactory : public EnemyFactory {
 public:
    Enemy createEnemy(Floor* floor, Posn posn) override {
        return Human(floor, posn);
    }
};

class DwarfFactory : public EnemyFactory {
 public:
    Enemy createEnemy(Floor* floor, Posn posn) override {
        return Dwarf(floor, posn);
    }
};

class ElfFactory : public EnemyFactory {
 public:
    Enemy createEnemy( Floor* floor, Posn posn) override {
        return Elf(floor, posn);
    }
};

class OrcsFactory : public EnemyFactory {
 public:
    Enemy createEnemy(Floor* floor, Posn posn) override {
        return Orcs(floor, posn);
    }
};

class MerchantFactory : public EnemyFactory {
 public:
    Enemy createEnemy(Floor* floor, Posn posn) override {
        return Merchant(floor, posn);
    }
};

class DragonFactory : public EnemyFactory {
 public:
    Enemy createEnemy(Floor* floor, Posn posn) override {
        return Dragon(floor, posn);
    }
};

class HalflingFactory : public EnemyFactory {
 public:
    Enemy createEnemy(Floor* floor, Posn posn) override {
        return Halfling(floor, posn);
    }
};



#endif
