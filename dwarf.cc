#include "dwarf.h"
#include "player.h"

Dwarf::Dwarf(Floor* floor, Posn posn) 
: Enemy(floor, 'W', posn, 100, 20, 30) {}

Dwarf::~Dwarf() {}

bool Dwarf::beAttacked(Player *player, PRNG& prng1) {
    int hplose = loseHp(player->getAtk() + player->getAtk());

    if(hp - hplose <= 0) {
        player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to W and kills W.");
        if (player->getRace() == PlayerRace::VAMPIRE) {
            player->setAction(player->getAction() + " But PC is allergic to dwarfs, so health decreased by 5.");
            player->gainHp(-5);   //because a vampire should lose 5 hp, when it attacks dwarfs.
        }
        if(player->getRace() == PlayerRace::GOBLIN) {
            player->setAction(player->getAction() + " PC stole 5 gold before killing the W.");
            player->gainGold(5);
        }
        floor->removeEnemy(this);
        player->setAction(player->getAction() + " PC gains small gold from the dead W.");
        player->gainGold(1);
    } else {
        hp -= hplose;
        player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to W" + " (" + std::to_string(hp) + "HP).");
         if (player->getRace() == PlayerRace::VAMPIRE) {
            player->setAction(player->getAction() + " But PC is allergic to W, so health decreased by 5.");
            player->gainHp(-10);   //because a vampire should lose 5 hp, when it attacks dwarfs.
        }
    }
    return true;
}
