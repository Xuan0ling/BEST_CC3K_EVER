#include "human.h"
#include "player.h"
#include "concreteItemFactory.h"


Human::Human(Floor* floor, Posn posn) : Enemy(floor, 'H', posn, 140, 20, 20) {}

Human::~Human() {}

bool Human::beAttacked(Player *player, PRNG& prng1) {
    int hplose = loseHp(player->getAtk() + player->getExAtk());

    if(hp - hplose <= 0) {
        player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to H and kills H.");
        if(player->getRace() == PlayerRace::GOBLIN) {
            player->setAction(player->getAction() + " PC stole 5 gold before killing the H.");
            player->gainGold(5);
        }
        player->setAction(player->getAction() + " H drops Gold.");
        std::unique_ptr<Itemfactory> itemFactory = std::make_unique<twoNormalgoldfactory>();
        std::unique_ptr<Item> twonormalgold(itemFactory->createItems(posn));
        floor->addItem(std::move(twonormalgold));
        floor->loadItems();
        floor->removeEnemy(this);
    } else {
        hp -= hplose;
        player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to D" + " (" + std::to_string(hp) + "HP).");
    }
    return true;
}
