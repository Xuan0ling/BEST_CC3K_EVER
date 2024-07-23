#include "floor.h"
#include "cell.h"
#include "player.h"
#include "enemy.h"
#include "item.h"
#include "gameMap.h"
#include <unistd.h>
#include "ConcreteEnemy.h"


Floor::Floor() : player{nullptr}, gameMap{nullptr} {
    uint32_t seed = getpid();	
    prng1.seed(seed);
}

Floor::~Floor() {}


void Floor::initFloor(Player* player, GameMap* gameMap) {
    this->player = player;
    this->gameMap = gameMap;
    this->possiblePoints = gameMap->getPossiblePoints();
    cells.clear();
    // load blank map in cells
    cells.resize(MAP_HEIGHT, std::vector<Cell>(MAP_WIDTH));
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            cells[i][j] = Cell(gameMap->getTile(i, j));
        }
    }
    enemies.clear();
    items.clear();
    // generateFloor();
}

void Floor::addEnemy(EnemyPtr enemy) {
    enemies.emplace_back(std::move(enemy));
}

void Floor::addItem(ItemPtr item) {
    items.emplace_back(std::move(item));
}

Cell& Floor::getCell(Posn posn) {
    return cells[posn.y][posn.x];
}

void Floor::clearCell(Posn posn) {
    cells[posn.y][posn.x].clearPointers();
}

void Floor::updatePlayer() {
    Posn posn = player->getPosn();
    Cell& cell = getCell(posn);
    cell.setPlayer(player);
}

void Floor::updateEnemy(Enemy* enemy) {
    Posn posn = enemy->getPosn();
    Cell& cell = getCell(posn);
    cell.setEnemy(enemy);
}

void Floor::updateItem(Item* item) {
    Posn posn = item->getPosn();
    Cell& cell = getCell(posn);
    cell.setItem(item);
}

bool Floor::isEmpty(Posn posn) {
    return getCell(posn).isEnemy();
}

std::vector<char> Floor::getDisplay() {
    std::vector<char> display;
    for (const auto& row : cells) {
        for (const auto& cell : row) {
            display.push_back(cell.getDisplaySymbol());
        }
    }
    return display;
}

void Floor::removeEnemy(Enemy* enemy) {
    Posn posn = enemy->getPosn();
    Cell& cell = getCell(posn);
    cell.setEnemy(nullptr);
    auto is_enemy = [enemy](const EnemyPtr& e) { return e.get() == enemy; };
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(), is_enemy), enemies.end());
}

void Floor::removeItem(Item* item) {
    Posn posn = item->getPosn();
    Cell& cell = getCell(posn);
    cell.setItem(nullptr);
    auto is_item = [item](const ItemPtr& i) { return i.get() == item; };
    items.erase(std::remove_if(items.begin(), items.end(), is_item), items.end());
}

void Floor::removepoint(int chambernum, Posn pair) {
    for (auto it = possiblePoints[chambernum].begin(); it != possiblePoints[chambernum].end();) {
        if((*it).x == pair.y && (*it).x == pair.y) {
            it = possiblePoints[chambernum].erase(it);
        } else {
            ++it;
        }
    }
}

void Floor::enemiesAction() {
    for (auto& enemy : enemies) {
        enemy->move(prng1);
        enemy->attack(player);
    }
}

void Floor::generateEnemies() {
    std::unique_ptr<EnemyFactory> enemyFactory = nullptr;
    
    for(int i = 0; i < 20; i++) {
        int value = 18 % prng1(1, 18);
        
        int chamber = prng1(0, 4);
        
        int posn = prng1(0, possiblePoints[chamber].size());
        
        Posn temp = possiblePoints[chamber][posn];
        

        if (value < 4) {
            enemyFactory = std::make_unique<HumanFactory>();
        } else if (value < 7) {
            enemyFactory = std::make_unique<DwarfFactory>();
        } else if (value < 12) {
            enemyFactory = std::make_unique<HalflingFactory>();
        } else if (value < 14) {
            enemyFactory = std::make_unique<ElfFactory>();
        } else if (value < 16) {
            enemyFactory = std::make_unique<OrcsFactory>();
        } else if (value < 18) {
            enemyFactory = std::make_unique<MerchantFactory>();
        }
         
        Enemy enemy = enemyFactory->createEnemy(temp, this);
        removepoint(chamber, temp);
       
        this->addEnemy(std::make_unique<Enemy>(enemy));
    }
    for (auto &enemy : enemies) {
        updateEnemy(enemy.get());
    }

}

void Floor::generateItems() {
}

void Floor::generateStair() {
}

void Floor::generatePlayer() {
}

void Floor::generateFloor() {
}

bool Floor::checkValidMove(Posn posn) {
    char symbol = getCell(posn).getSymbol();
    if (symbol == '.' || symbol == '+' || symbol == '#') {
        return true;
    }
    return false;
}


