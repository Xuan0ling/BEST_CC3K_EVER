#include "vampire.h"
#include <limits>
#include "cell.h"
#include "floor.h"
#include "enemy.h"
const int VAMPIRE_HP = 50;
const int VAMPIRE_MAX_HP = INT_MAX;
const int VAMPIRE_ATK = 25;
const int VAMPIRE_DEF = 25;
const int VAMPIRE_ADD_HP = 5;

Vampire::Vampire(Floor *floor, PlayerRace race):
    Player(floor, race, VAMPIRE_HP, VAMPIRE_ATK, VAMPIRE_DEF, 0, VAMPIRE_MAX_HP) {}

Vampire::~Vampire() {}

void Vampire::attack(Posn attackDir) {
    Posn newPosn = posn + attackDir;
    auto& cell = floor->getCell(newPosn);
    if(cell.getEnemy()->beAttacked(this)) {
        if(cell.getEnemy()->getSymbol() != 'W') {
            setAction(getAction() + " PC gains 5 HP.");
            gainHp(VAMPIRE_ADD_HP);
        }
                
    } 
}

