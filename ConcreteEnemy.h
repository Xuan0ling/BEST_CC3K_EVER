#ifndef CONCRETEENEMY_H
#define CONCRETEENEMY_H

#include "EnemyFactory.h"
#include "enemy.h"
#include "Human.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Orcs.h"
#include "Merchant.h"
#include "Dragon.h"
#include "Halfling.h"

class HumanFactory : public EnemyFactory {
 public:
    Enemy createEnemy(Posn posn, Floor* floor) override {
        return Human(floor ,posn);
    }
};

class DwarfFactory : public EnemyFactory {
 public:
    Enemy createEnemy(Posn posn, Floor* floor) override {
        return Dwarf(floor, posn);
    }
};

class ElfFactory : public EnemyFactory {
 public:
    Enemy createEnemy(Posn posn, Floor* floor) override {
        return Elf(floor, posn);
    }
};

class OrcsFactory : public EnemyFactory {
 public:
    Enemy createEnemy(Posn posn, Floor* floor) override {
        return Orcs(floor, posn);
    }
};

class MerchantFactory : public EnemyFactory {
 public:
    Enemy createEnemy(Posn posn, Floor* floor) override {
        return Merchant(floor, posn);
    }
};

class DragonFactory : public EnemyFactory {
 public:
    Enemy createEnemy(Posn posn, Floor* floor) override {
        return Dragon(floor, posn);
    }
};

class HalflingFactory : public EnemyFactory {
 public:
    Enemy createEnemy(Posn posn, Floor* floor) override {
        return Halfling(floor, posn);
    }
};



#endif