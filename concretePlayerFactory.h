#ifndef CONCRETEPLAYER_H
#define CONCRETEPLAYER_H
#include "playerFactory.h"
#include "drow.h"
#include "goblin.h"
#include "shade.h"
#include "vampire.h"
#include "troll.h"

class Shadefactory: public Playerfactory {
public:
    Player* createPlayer(Floor *floor) override {
        return new Shade(floor, PlayerRace::SHADE);
    }
};

class Drowfactory: public Playerfactory {
public:
    Player* createPlayer(Floor *floor) override {
        return new Drow(floor, PlayerRace::DROW);
    }
};

class Vampirefactory: public Playerfactory {
public:
    Player* createPlayer(Floor *floor) override {
        return new Vampire(floor, PlayerRace::VAMPIRE);
    }
};

class Goblinfactory: public Playerfactory {
public:
    Player* createPlayer(Floor *floor) override {
        return new Goblin(floor, PlayerRace::GOBLIN);
    }
};

class Trollfactory: public Playerfactory {
public:
    Player* createPlayer(Floor *floor) override {
        return new Troll(floor, PlayerRace::TROLL);
    }
};

#endif
