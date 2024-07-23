#ifndef CONCRETEENEMY_H
#define CONCRETEENEMY_H

#include "EnemyFactory.h"
#include "Enemy.h"
#include "Human.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Orcs.h"
#include "Merchant.h"
#include "Dragon.h"
#include "Halfling.h"

class HumanFactory : public EnemyFactory {
 public:
    Enemy* createEnemy(Posn posn, Floor* floor) override {
        return new Human(posn, floor);
    }
};

class DwarfFactory : public EnemyFactory {
 public:
    Enemy* createEnemy(Posn posn, Floor* floor) override {
        return new Dwarf(posn, floor);
    }
};

class ElfFactory : public EnemyFactory {
 public:
    Enemy* createEnemy(Posn posn, Floor* floor) override {
        return new Elf(posn, floor);
    }
};

class OrcsFactory : public EnemyFactory {
 public:
    Enemy* createEnemy(Posn posn, Floor* floor) override {
        return new Orcs(posn, floor);
    }
};

class MerchantFactory : public EnemyFactory {
 public:
    Enemy* createEnemy(Posn posn, Floor* floor) override {
        return new Merchant(posn, floor);
    }
};

class DragonFactory : public EnemyFactory {
 public:
    Enemy* createEnemy(Posn posn, Floor* floor) override {
        return new Dragon(posn, floor);
    }
};

class HalflingFactory : public EnemyFactory {
 public:
    Enemy* createEnemy(Posn posn, Floor* floor) override {
        return new Halfling(posn, floor);
    }
};



#endif