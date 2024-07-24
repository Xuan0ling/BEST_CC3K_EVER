#ifndef CONCRETEENEMY_H
#define CONCRETEENEMY_H

#include "EnemyFactory.h"
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
    Enemy createEnemy(Floor* floor, Posn posn, Item* item) {
        return Dragon(floor, posn, item); 

    }
};

class HalflingFactory : public EnemyFactory {
 public:
    Enemy createEnemy(Floor* floor, Posn posn) override {
        return Halfling(floor, posn);
    }
};



#endif