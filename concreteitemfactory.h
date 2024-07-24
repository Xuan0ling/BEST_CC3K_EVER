#ifndef CONCRETEITEMFACTORY_H
#define CONCRETEITEMFACTORY_H
#include "itemfactory.h"
#include "item.h"
#include "boostatk.h"
#include "boostdef.h"
#include "restorehealth.h"
#include "woundatk.h"
#include "wounddef.h"
#include "poisonhealth.h"
#include "treasure.h"
#include "posn.h"

class Woundatkfactory: public Itemfactory {
public:
    Item createItems(Floor *floor, Posn posn) override {
        return Woundatk(floor, posn);
    }
};

class Wounddeffactory: public Itemfactory {
public:
    Item createItems(Floor * floor, Posn posn) override {
        return Wounddef(floor, posn);
    }
};

class Boostatkfactory: public Itemfactory {
public:
    Item createItems(Floor *floor, Posn posn) override {
        return Boostatk(floor, posn);
    }
};

class Boostdeffactory: public Itemfactory {
public:
    Item createItems(Floor *floor, Posn posn) override {
        return Boostdef(floor, posn);
    }
};

class Restorehealthfactory: public Itemfactory {
public:
    Item createItems(Floor *floor, Posn posn) override {
        return Restorehealth(floor, posn);
    }
};

class Poisonhealthfactory: public Itemfactory {
public:
    Item createItems(Floor *floor, Posn posn) override {
        return Poisonhealth(floor, posn);
    }
};

class Smallgoldfactory: public Itemfactory {
public:
    Item createItems(Floor *floor, Posn posn) override {
        return Treasure(floor, posn, 1);
    }
};

class Normalgoldfactory: public Itemfactory {
public:
    Item createItems(Floor *floor, Posn posn) override {
        return Treasure(floor, posn, 2);
    }
};

class Merchantgoldfactory: public Itemfactory {
public:
    Item createItems(Floor *floor, Posn posn) override {
        return Treasure(floor, posn, 4);
    }
};

class Dragongoldfactory: public Itemfactory {
public:
    Item createItems(Floor *floor, Posn posn) override {
        return Treasure(floor, posn, 6);
    }
};

#endif
