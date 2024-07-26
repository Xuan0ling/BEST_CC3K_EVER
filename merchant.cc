#include "merchant.h"
#include "player.h"
#include "concreteItemFactory.h"

#include "cell.h"

Merchant::Merchant(Floor* floor, Posn posn) : Enemy(floor, 'M', posn, 30, 70, 5) {}

Merchant::~Merchant() {}

bool Merchant::attack(Player *player, PRNG& prng1) {
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

void Merchant::move(PRNG& prng) {
    // check player is beside merchant, if so, set merchant dont move
    std::vector<Posn> neighbours = floor->getNeighbours(posn);
    for (Posn &neighbour : neighbours) {
        if (floor->getCell(neighbour).hasPlayer()) {
            return;
        }
    }
    // move merchant
    std::vector<Posn> validNeighbours;
    for (Posn neighbour : neighbours) {
        if (floor->checkValidMoveForEnemy(neighbour)) {
            validNeighbours.push_back(neighbour);
        }
    }
    if (validNeighbours.size() == 0) {
        return;
    }
    int index = prng(0, validNeighbours.size() - 1);
    Posn newPosn = validNeighbours[index];
    floor->clearCell(posn);
    posn = newPosn;
    floor->updateEnemy(this);
}

bool Merchant::beAttacked(Player *player, PRNG& prng1) {
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

        std::unique_ptr<Itemfactory> itemFactory = std::make_unique<Merchantgoldfactory>();
        std::unique_ptr<Item> merchantgold(itemFactory->createItems(posn));

        floor->addItem(std::move(merchantgold));
        floor->loadItems();
        floor->removeEnemy(this);
    } else {
        hp -= hplose;
        player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to M." + " (" + std::to_string(hp) + "HP)");
    }
    return true;
}
