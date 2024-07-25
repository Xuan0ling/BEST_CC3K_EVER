#include "vampire.h"
#include <limits>
#include "cell.h"
#include "floor.h"
#include "enemy.h"
#include "constants.h"

Vampire::Vampire(Floor *floor, PlayerRace race):
    Player(floor, race, 100, VAMPIRE_ATK, VAMPIRE_DEF, 0, VAMPIRE_MAX_HP) {}

Vampire::~Vampire() {}

void Vampire::attack(Posn attackDir) {
    std::cout << "Player attack" << std::endl;
    Posn newPosn = posn + attackDir;
    auto& cell = floor->getCell(newPosn);
    if(cell.hasEnemy()) {
        if(cell.getEnemy()->getSymbol() != 'W') {
            setAction(getAction() + " PC gains 5 HP.");
            gainHp(VAMPIRE_ADD_HP);
        }
        cell.getEnemy()->beAttacked(this, floor->getRandomGnerator());
    } 
}

