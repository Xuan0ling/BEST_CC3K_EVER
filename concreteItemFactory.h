#ifndef CONCRETEITEMFACTORY_H
#define CONCRETEITEMFACTORY_H

#include "itemFactory.h"
#include "item.h"
#include "boostatk.h"
#include "boostdef.h"
#include "restoreHealth.h"
#include "woundAtk.h"
#include "woundDef.h"
#include "poisonHealth.h"
#include "treasure.h"
#include "posn.h"
#include "smallTreasure.h"
#include "normalTreasure.h"
#include "merchantHoardTreasure.h"
#include "dragonHoardTreasure.h"

class Woundatkfactory : public Itemfactory {
public:
    Item* createItems(Floor* floor, Posn posn) override {
        return new Woundatk(floor, posn);
    }
};

class Wounddeffactory : public Itemfactory {
public:
    Item* createItems(Floor* floor, Posn posn) override {
        return new Wounddef(floor, posn);
    }
};

class Boostatkfactory : public Itemfactory {
public:
    Item* createItems(Floor* floor, Posn posn) override {
        return new Boostatk(floor, posn);
    }
};

class Boostdeffactory : public Itemfactory {
public:
    Item* createItems(Floor* floor, Posn posn) override {
        return new Boostdef(floor, posn);
    }
};

class Restorehealthfactory : public Itemfactory {
public:
    Item* createItems(Floor* floor, Posn posn) override {
        return new Restorehealth(floor, posn);
    }
};

class Poisonhealthfactory : public Itemfactory {
public:
    Item* createItems(Floor* floor, Posn posn) override {
        return new Poisonhealth(floor, posn);
    }
};

class Smallgoldfactory : public Itemfactory {
public:
    Item* createItems(Floor* floor, Posn posn) override {
        return new SmallTreasure(floor, posn, 1);
    }
};

class Normalgoldfactory : public Itemfactory {
public:
    Item* createItems(Floor* floor, Posn posn) override {
        return new NormalTreasure(floor, posn, 2);
    }
};

class twoNormalgoldfactory : public Itemfactory {
public:
    Item* createItems(Floor* floor, Posn posn) override {
        return new NormalTreasure(floor, posn, 4);
    }
};




class Merchantgoldfactory : public Itemfactory {
public:
    Item* createItems(Floor* floor, Posn posn) override {
        return new MerchantHoardTreasure(floor, posn, 4);
    }
};

class Dragongoldfactory : public Itemfactory {
public:
    Item* createItems(Floor* floor, Posn posn) override {
        return new DragonHoardTreasure(floor, posn, 6);
    }
};

#endif
