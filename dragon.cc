#include "dragon.h"
#include "floor.h"
#include "item.h"
#include "player.h"
#include "posn.h"


Dragon::Dragon (Floor* floor, Posn posn, Item* hoard) 
: Enemy{floor, SYMBOL_DRAGON, posn, 150, 20, 20}, dragonhoard{hoard} {}


Dragon::~Dragon() {}

void Dragon::move(PRNG &prng) {
}

bool Dragon::attack(Player *player, PRNG prng1) {
    std::vector<Posn> neighbours = floor->getNeighbours(posn);
    std::vector<Posn> neighboursofhoard = floor->getNeighbours(dragonhoard->getPosn());

    for (Posn &neighbour : neighbours) {
        if (neighbour == player->getPosn()) {
            int num = prng1(0, 1);
            if(num % 2 == 0) {
                player->LoseHP(atk);
            }
            return true;     //add missed action
        }
    }

    for (Posn &neighbour : neighboursofhoard) {
        if (neighbour == player->getPosn()) {
            int num = prng1(0, 1);
            if(num % 2 == 0) {
                player->LoseHP(atk);
            }
            return true;    //add missed action
        }
    }

    return false;
}

void Dragon::beAttacked(int atk) {
}
