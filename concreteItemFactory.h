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
    Item* createItems(Posn posn) override {
        return new Woundatk(posn);
    }
};

class Wounddeffactory : public Itemfactory {
public:
    Item* createItems( Posn posn) override {
        return new Wounddef(posn);
    }
};

class Boostatkfactory : public Itemfactory {
public:
    Item* createItems(Posn posn) override {
        return new Boostatk(posn);
    }
};

class Boostdeffactory : public Itemfactory {
public:
    Item* createItems(Posn posn) override {
        return new Boostdef(posn);
    }
};

class Restorehealthfactory : public Itemfactory {
public:
    Item* createItems(Posn posn) override {
        return new Restorehealth(posn);
    }
};

class Poisonhealthfactory : public Itemfactory {
public:
    Item* createItems(Posn posn) override {
        return new Poisonhealth(posn);
    }
};

class Smallgoldfactory : public Itemfactory {
public:
    Item* createItems(Posn posn) override {
        return new SmallTreasure(posn, 1);
    }
};

class Normalgoldfactory : public Itemfactory {
public:
    Item* createItems(Posn posn) override {
        return new NormalTreasure(posn, 2);
    }
};

class twoNormalgoldfactory : public Itemfactory {
public:
    Item* createItems(Posn posn) override {
        return new NormalTreasure(posn, 4);
    }
};




class Merchantgoldfactory : public Itemfactory {
public:
    Item* createItems(Posn posn) override {
        return new MerchantHoardTreasure(posn, 4);
    }
};

class Dragongoldfactory : public Itemfactory {
public:
    Item* createItems(Posn posn) override {
        return new DragonHoardTreasure(posn, 6);
    }
};

#endif
