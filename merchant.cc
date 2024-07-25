#include "merchant.h"
#include "player.h"
#include "concreteItemFactory.h"

Merchant::Merchant(Floor* floor, Posn posn) : Enemy(floor, 'M', posn, 30, 70, 5) {}

Merchant::~Merchant() {}

bool Merchant::attack(Player *player, PRNG prng1) {
    if(player->getIsMerchantVolatile()) {
        std::vector<Posn> neighbours = floor->getNeighbours(posn);
        for (Posn &neighbour : neighbours) {
            if (neighbour == player->getPosn()) {
                int num = prng1(0, 1);
                if(num % 2 == 0) {
                    player->setAction(player->getAction() + " M deals " );
                    player->LoseHP(atk);
                } else {
                    player->setAction(player->getAction() + " M attacks and misses.");
                }
                return true;  
            }
        }
    }
    return false;
}

bool Merchant::beAttacked(Player *player) {
    if(player->getIsMerchantVolatile() == false) {
        player->setAction(player->getAction() + " PC attacked M. All M's are hostile now.");
        player->setMerchantVolatile();
    }

    int hplose = loseHp(player->getAtk() + player->getExAtk());

    if(hp - hplose <= 0) {
        player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to M and kills M.");
        if(player->getRace() == PlayerRace::GOBLIN) {
            player->setAction(player->getAction() + " PC stole 5 gold before killing the M.");
            player->gainGold(5);
        }
        floor->removeEnemy(this);
        std::unique_ptr<Itemfactory> itemFactory = std::make_unique<Merchantgoldfactory>();
        std::unique_ptr<Item> merchantgold(itemFactory->createItems(floor, posn));
        floor->addItem(std::move(merchantgold));
    } else {
        player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to M.");
        hp -= hplose;
    }
    return true;
}
