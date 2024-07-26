#include "player.h"
#include "floor.h"
#include "cell.h"
#include "item.h"
#include "treasure.h"
#include <cmath>
#include <sstream>
#include "enemy.h"


Player::Player(Floor* floor, PlayerRace race, int hp, int atk, int def, int gold, int maxHp) 
: floor{floor}, race{race}, hp{hp}, atk{atk}, def{def}, gold{gold}, maxHp{maxHp} {}


void Player::setPosn(Posn newPosn) {
    posn = newPosn;
}

void Player::changePosn(Posn posnChange) {
    posn = posn + posnChange;
}

Posn Player::getPosn() {
    return posn;
}

char Player::getSymbol() {
    return '@';
}



// special ability will override those functions
//-----------------------------------------------------------------------------
void Player::move(Posn posnChange) {
    floor->getCell(posn).clearPlayer();
    Posn newPosn = posn + posnChange;
    if (floor->checkValidMove(newPosn)) {
        changePosn(posnChange);
        action = " PC moves " + floor->getDirStr(posnChange) + ".";
    }
    floor->updatePlayer();
    checkGold();
    seakPotion();
}

void Player::attack(Posn attackDir) {
    Posn newPosn = posn + attackDir;
    auto& cell = floor->getCell(newPosn);
    if (cell.hasEnemy()) {
        cell.getEnemy()->beAttacked(this, floor->getRandomGnerator());
    }
} 

void Player::usePotion(Posn usePotionDir) {
    auto& cell = floor->getCell(posn + usePotionDir);
    if (cell.hasPotion()) {
        Item* potion = cell.getItem();
        potion->usePotion(this);
        cell.clearItem();
        floor->removeItem(potion);
    }
}

void Player::checkGold() {
    auto& cell = floor->getCell(posn);
    if (cell.hasGold()) {
        Item* treasure = cell.getItem();
        
        if(treasure->gainGold(this)) {
            cell.clearItem();
            floor->removeItem(treasure);
        }
        
    }
}

void Player::trade(Posn tradeDir) {
    auto& cell = floor->getCell(posn + tradeDir);
    if (cell.hasMerchant() && !merchantVolatile) {
        int index = floor->getRandomGnerator()(0, GOODS.size() - 1);
        int price = floor->getRandomGnerator()(5, 10);
        float effect = 1;
        if (race == PlayerRace::DROW) {
            effect = 1.5;
        }
        if (gold >= price) {
            gold -= price;
            if (GOODS[index] == "RH") {
                hp += 10 * effect;
                if (hp > maxHp) {
                    hp = maxHp;
                }
            } else if (GOODS[index] == "BA") {
                exAtk += 5 * effect;
            } else if (GOODS[index] == "BD") {
                exDef += 5 * effect;
            } else if (GOODS[index] == "PH") {
                hp -= 10 * effect;
                if (hp <= 0) {
                    hp = 0;
                    isDead = true;
                }
            } else if (GOODS[index] == "WA") {
                exAtk -= 5 * effect;
            } else if (GOODS[index] == "WD") {
                exDef -= 5 * effect;
            } else if (GOODS[index] == "TP") {
                gainCurrFloorIndex(1);
                floor->loadFloor();
                clearEffect();
            }
            action += " PC trades " + GOODS[index] + " for " + numAsString(price) + " gold, and " + GOODS[index] + " is used.";
            if (GOODS[index] == "TP") {
                action += " PC teleport to next floor.";
            }
        } else {
            action += " PC does not have enough gold to trade.";
        }
    }
}

void Player::seakPotion() {
    std::vector<Posn> neighbours = floor->getNeighbours(posn);
    for (auto& neighbour : neighbours) {
        auto& cell = floor->getCell(neighbour);
        if (cell.hasPotion()) {
            action += " PC sees a unknown potion.";
        }
    }
}


void Player::checkPlayerEnterFloor(bool haveGivenMap, std::vector<std::vector<char>>& givenMap) {
    auto& cell = floor->getCell(posn);
    if (cell.hasStair()) {
        if (currFloorIndex == NUM_FLOORS) {
            isWon = true;
        } else if (haveGivenMap) {
            gainCurrFloorIndex(1);
            floor->loadGivenFloor(givenMap);
            clearEffect();
        } else {
            gainCurrFloorIndex(1);
            floor->loadFloor();
            clearEffect();
        }
    }
}

//-----------------------------------------------------------------------------


void Player::setHp(int hp) {
    this->hp = hp;
}

void Player::setGold(int gold) {
    this->gold = gold;
}

void Player::setChamberNum(int chamberNum) {
    this->chamberNum = chamberNum;
}

int Player::getChamberNum() {
    return chamberNum;
}


void Player::gainHp(int hp) {
    if (this->hp + hp <= 0) {
        this->hp = 0;
        this->setIsDead(true);
    } else if (race == PlayerRace::VAMPIRE){
        this->hp += hp;
    } else {
        if (this->hp + hp >= maxHp) {
            this->hp = maxHp;
        } else {
            this->hp += hp;
        }
    }
  
}

void Player::gainGold(int gold) {
    this->gold += gold;
}

void Player::gainExAtk(int exAtk) {
    if(atk + this->exAtk + exAtk < 0) {
        this->exAtk = -atk;
    } else {
        this->exAtk += exAtk;
    }
    
}

void Player::gainExDef(int exDef) {
    if(def + this->exDef + exDef < 0) {
        this->exDef= -def;
    } else {
        this->exDef += exDef;
    }
    
}

void Player::LoseHP(int atkpower) {
    int hplose = ceil((100.0/(100 + def + exDef)) * atkpower);
    setAction(getAction() + numAsString(hplose) + " damage to PC.");
    this->gainHp(-hplose);
}

void Player::gainCurrFloorIndex(int currFloorIndex) {
    this->currFloorIndex += currFloorIndex;
}

void Player::setMerchantVolatile() {
    merchantVolatile = true;
}

void Player::setMaxHp(int maxHp) {
    this->maxHp = maxHp;
}

void Player::setIsDead(bool isDead) {
    this->isDead = isDead;
}

void Player::setIsWon(bool isWon) {
    this->isWon = isWon;
}



std::string Player::getRaceStr() {
    switch(race) {
        case PlayerRace::DROW:
            return "Drow";
        case PlayerRace::VAMPIRE:
            return "Vampire";
        case PlayerRace::TROLL:
            return "Troll";
        case PlayerRace::SHADE:
            return "Shade";
        case PlayerRace::GOBLIN:
            return "Goblin";
        default:
            return "Invalid";  
    }
}

PlayerRace Player::getRace() {
    return race;
}

std::string Player::getAction() {
    return action;
}

void Player::setAction(std::string action) {
    this->action = action;
}

std::string Player::numAsString(int num) {
    std::ostringstream oss;
    oss << num;
    return oss.str();
    
}

void Player::clearEffect() {
    exAtk = 0;
    exDef = 0;
    chamberNum = -1;
}

int Player::getHp() {
    return hp;
}

int Player::getAtk() {
    return atk;
}

int Player::getDef() {
    return def;
}

int Player::getGold() {
    return gold;
}

int Player::getMaxHp() {
    return maxHp;
}

int Player::getExAtk() {
    return exAtk;
}

int Player::getExDef() {
    return exDef;
}

int Player::getCurrFloorIndex() {
    return currFloorIndex;
}

bool Player::getIsDead() {
    return isDead;
}

bool Player::getIsWon() {
    return isWon;
}

bool Player::getIsMerchantVolatile() {
    return merchantVolatile;
}

Player::~Player() {}



