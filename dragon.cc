#include "dragon.h"
#include "floor.h"
#include "item.h"
#include "player.h"
#include "posn.h"
#include "dragonHoardTreasure.h"

Dragon::Dragon (Floor* floor, Posn posn, Item* hoard) 
: Enemy{floor, SYMBOL_DRAGON, posn, 150, 20, 20}, dragonhoard{hoard} {}


Dragon::~Dragon() {}

void Dragon::move(PRNG &prng) {
}

bool Dragon::attack(Player *player, PRNG& prng1) {
    std::vector<Posn> neighbours = floor->getNeighbours(posn);
    std::vector<Posn> neighboursofhoard = floor->getNeighbours(dragonhoard->getPosn());

    for (Posn &neighbour : neighbours) {
        if (neighbour == player->getPosn()) {
            int num = prng1(0, 1);
            if(num % 2 == 0) {
                player->setAction(player->getAction() + " D deals " );
                player->LoseHP(atk);
            } else {
                player->setAction(player->getAction() + " D attacks and misses.");
            }
            return true;    
        }
    }

    for (Posn &neighbour : neighboursofhoard) {
        if (neighbour == player->getPosn()) {
            int num = prng1(0, 1);
            if(num % 2 == 0) {
                player->setAction(player->getAction() + " D deals " );
                player->LoseHP(atk);
            } else {
                player->setAction(player->getAction() + " D attacks and misses.");
            }
            return true;

           
        }
    }

    return false;
}

bool Dragon::beAttacked(Player* player, PRNG& prng1) {
    int hplose = loseHp(player->getAtk() + player->getExAtk());

    if(hp - hplose <= 0) {
        player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to D and kills D.");
        if(player->getRace() == PlayerRace::GOBLIN) {
            player->setAction(player->getAction() + " PC stole 5 gold before killing the D.");
            player->gainGold(5);
        }
        dragonhoard->setDragonDead();
        floor->removeEnemy(this);
    } else {
        player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to D.");
        hp -= hplose;
    }
    return true;
}
