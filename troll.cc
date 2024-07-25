#include "troll.h"
#include "floor.h"
#include "cell.h"

const int TROLL_RESTORE = 5;

Troll::Troll(Floor *floor, PlayerRace race):
    Player(floor, race, 120,25,15,120) {}

Troll::~Troll() {}

void Troll::move(Posn posnChange) {
    this->gainHp(TROLL_RESTORE);
    floor->getCell(posn).clearPlayer();
    Posn newPosn = posn + posnChange;
    if (floor->checkValidMove(newPosn)) {
        changePosn(posnChange);
    }
    floor->updatePlayer();
    checkGold();
}
