#include "orcs.h"
#include "player.h"
#include <sstream>

Orcs::Orcs(Floor* floor, Posn posn) : Enemy(floor, 'O', posn, 180, 30, 25) {}

Orcs::~Orcs() {}

bool Orcs::attack(Player *player, PRNG& prng1) {
    std::vector<Posn> neighbours = floor->getNeighbours(posn);
    for (Posn &neighbour : neighbours) {
        if (neighbour == player->getPosn()) {
            int num = prng1(0, 1);
            if(num % 2 == 0) {
                if(player->getRace() == PlayerRace::GOBLIN) {
                    int hpgain = ceil((100/(100 + player->getDef())) * (atk * 1.5));
                    std::ostringstream oss;
                    oss << hpgain;
                    player->setAction(player->getAction() + " O has advantage over Goblins and deals " + oss.str() + ", 50% more damage than usual." );
                    player->gainHp(hpgain);
                    return true;
                }
                player->setAction(player->getAction() + " O deals " );
                player->LoseHP(atk);
            } else {
                player->setAction(player->getAction() + " O attacks and misses.");
            }
            return true;  
        }
    }
    return false;
}

bool Orcs::beAttacked(Player *player, PRNG& prng1) {
    int hplose = loseHp(player->getAtk() + player->getExAtk());

    if(hp - hplose <= 0) {
        player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to O and kills O.");
        if(player->getRace() == PlayerRace::GOBLIN) {
            player->setAction(player->getAction() + " PC stole 5 gold before killing the O.");
            player->gainGold(5);
        }
        floor->removeEnemy(this);
        player->setAction(player->getAction() + " PC gains normal gold from the dead O.");
        player->gainGold(2);
    } else {
        player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to O.");
        hp -= hplose;
    }
    return true;
}
