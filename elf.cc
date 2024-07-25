#include "player.h"
#include "elf.h"


Elf::Elf(Floor* floor, Posn posn) : Enemy(floor, 'E', posn, 140, 30, 10) {}

Elf::~Elf() {}


   

bool Elf::attack(Player *player, PRNG& prng1) {
    int i = 2;
    if (player->getRace() == PlayerRace::DROW) {
        i = 1;
    }

    std::vector<Posn> neighbours = floor->getNeighbours(posn);
    for(int j = 0; j < i; j++) {
        for (Posn &neighbour : neighbours) {
            if (neighbour == player->getPosn()) {
                int num = prng1(0, 1);
                if(num % 2 == 0) {
                    if(j == 2) {
                        player->setAction(player->getAction() + " E attacks second time and deals " );
                    } else {
                        player->setAction(player->getAction() + " E deals " );
                    }
                    player->LoseHP(atk);
                } else {
                    if (j == 2) {
                        player->setAction(player->getAction() + " E attacks second time and misses.");
                    } else {
                        player->setAction(player->getAction() + " E attacks and misses.");
                    }
                    
                }

                return true; 
            }
        }
    }


    return false;
}

bool Elf::beAttacked(Player *player, PRNG& prng1) {
    int hplose = loseHp(player->getAtk() + player->getExAtk());

    if(hp - hplose <= 0) {
        player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to E and kills E.");
        if(player->getRace() == PlayerRace::GOBLIN) {
            player->setAction(player->getAction() + " PC stole 5 gold before killing the E.");
            player->gainGold(5);
        }
        floor->removeEnemy(this);
        player->setAction(player->getAction() + " PC gains normal gold from the dead E.");
        player->gainGold(2);
    } else {
        hp -= hplose;
        player->setAction(player->getAction() + " PC does " + player->numAsString(hplose) + " damage to E" + " (" + std::to_string(hp) + "HP).");
    }
    return true;
}
