#include "merchant.h"
#include "Merchant.h"
#include "player.h"

Merchant::Merchant(Floor* floor, Posn posn) : Enemy(floor, 'M', posn, 30, 70, 5) {}

Merchant::~Merchant() {}

bool Merchant::attack(Player *player, PRNG prng1) {
    if(player->getIsMerchantVolatile()) {
        std::vector<Posn> neighbours = floor->getNeighbours(posn);
        for (Posn &neighbour : neighbours) {
            if (neighbour == player->getPosn()) {
                int num = prng1(0, 1);
                if(num % 2 == 0) {
                    player->LoseHP(atk);
                }
                    return true;   //add missed action
            }
        }
    }
    return false;
}
