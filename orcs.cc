#include "orcs.h"
#include "player.h"

Orcs::Orcs(Floor* floor, Posn posn) : Enemy(floor, 'O', posn, 180, 30, 25) {}

Orcs::~Orcs() {}

bool Orcs::attack(Player *player, PRNG prng1) {
    std::vector<Posn> neighbours = floor->getNeighbours(posn);
    for (Posn &neighbour : neighbours) {
        if (neighbour == player->getPosn()) {
            int num = prng1(0, 1);
            if(num % 2 == 0) {
                if(player->getRace() == PlayerRace::GOBLIN) {
                    int hpgain = ceil((100/(100 + player->getDef())) * (atk * 1.5));
                    player->gainHp(hpgain);
                    return true;
                }
                player->LoseHP(atk);
            }
            return true;     //add missed action
        }
    }
}
