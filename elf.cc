#include "player.h"
#include "elf.h"


Elf::Elf(Floor* floor, Posn posn) : Enemy(floor, 'E', posn, 140, 30, 10) {}

Elf::~Elf() {}


   

bool Elf::attack(Player *player, PRNG prng1) {
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
                    player->LoseHP(atk);
                }
                return true;     //add missed action
            }
        }
    }


    return false;
}

