#include "halfling.h"
#include "player.h"
#include <unistd.h>

Halfling::Halfling(Floor* floor, Posn posn) : Enemy(floor, 'L', posn, 100, 15, 20) {}

Halfling::~Halfling() {}

bool Halfling::beAttacked(Player *player) {
    PRNG prng1;
    uint32_t seed = getpid();	
    prng1.seed(seed);

    int num = prng1(0, 1);

    if(num % 2 == 0) {
        int hplose = loseHp(player->getAtk() + player->getExAtk());

        if(hp - hplose <= 0) {
            player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to L and kills L.");
            if(player->getRace() == PlayerRace::GOBLIN) {
                player->setAction(player->getAction() + " PC stole 5 gold before killing the L.");
                player->gainGold(5);
            }
            floor->removeEnemy(this);
            player->setAction(player->getAction() + " PC gains small gold from the dead L.");
            player->gainGold(1);
        } else {
            player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to L.");
            hp -= hplose;
        }
        return true;
    } else {
        player->setAction(player->getAction() + " PC missed due to special ability of L.");
        return false;
    }

    
}
