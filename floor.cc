#include "floor.h"
#include "cell.h"
#include "player.h"
#include "enemy.h"
#include "item.h"
#include "gameMap.h"
#include <unistd.h>

#include "concreteItemFactory.h"
#include "concreteEnemy.h"


Floor::Floor() : player{nullptr}, gameMap{nullptr} {
    uint32_t seed = getpid();	
    prng1.seed(seed);
}

Floor::~Floor() {}


void Floor::initFloor(Player* player, GameMap* gameMap) {
    this->player = player;
    this->gameMap = gameMap;
}

void Floor::loadFloor() {
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
    generateFloor();
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
    return getCell(posn).isEmpty();
}

std::vector<Posn> Floor::getNeighbours(Posn posn) {
    std::vector<Posn> neighbours;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            Posn neighbour = Posn{posn.y + i, posn.x + j};
            if (neighbour.y >= 0 && neighbour.y < MAP_HEIGHT && neighbour.x >= 0 && neighbour.x < MAP_WIDTH) {
                neighbours.push_back(neighbour);
            }
        }
    }
    return neighbours;
}

std::vector<Posn> Floor::getCross(Posn posn) {
    std::vector<Posn> cross;
    for (int i = -1; i <= 1; ++i) {
        if (i == 0) {
            continue;
        }
        Posn neighbour = Posn{posn.y + i, posn.x};
        if (neighbour.y >= 0 && neighbour.y < MAP_HEIGHT && neighbour.x >= 0 && neighbour.x < MAP_WIDTH) {
            cross.push_back(neighbour);
        }
    }
    for (int j = -1; j <= 1; ++j) {
        if (j == 0) {
            continue;
        }
        Posn neighbour = Posn{posn.y, posn.x + j};
        if (neighbour.y >= 0 && neighbour.y < MAP_HEIGHT && neighbour.x >= 0 && neighbour.x < MAP_WIDTH) {
            cross.push_back(neighbour);
        }
    }
    return cross;
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
    // Lambda function to check if a Posn object matches the given pair
    auto is_point = [pair](const Posn& p) { return p == pair; };

    // Remove the points that match the pair from the specified chamber
    possiblePoints[chambernum].erase(
        std::remove_if(possiblePoints[chambernum].begin(), possiblePoints[chambernum].end(), is_point),
        possiblePoints[chambernum].end()
    );
}


void Floor::enemiesAction() {
    for (auto& enemy : enemies) {
        enemy->move(prng1);
    }
}

void Floor::generateEnemies() {
    std::unique_ptr<EnemyFactory> enemyFactory = nullptr;
    
    for(int i = 0; i < 20; i++) {
        int value = prng1(0, 17);
        
        int chamber = prng1(0, 4);
        
        int posn = prng1(0, possiblePoints[chamber].size() - 1);
        
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
         
        Enemy enemy = enemyFactory->createEnemy(this, temp);
        removepoint(chamber, temp);
       
        this->addEnemy(std::make_unique<Enemy>(enemy));
    }
    for (auto &enemy : enemies) {
        updateEnemy(enemy.get());
    }

}

void Floor::generatePotions() {

    std::unique_ptr<Itemfactory> itemFactory = nullptr;

    for(int i = 0; i < 10; i++) {
        int value = prng1(0, 5);

        int chamber = prng1(0, 4);
        int posn = prng1(0, possiblePoints[chamber].size() - 1);
        
        Posn temp = possiblePoints[chamber][posn];

        if(value == 0) {
            itemFactory = std::make_unique<Restorehealthfactory>();
        } else if (value == 1) {
            itemFactory = std::make_unique<Boostatkfactory>();
        } else if (value == 2) {
            itemFactory = std::make_unique<Boostdeffactory>();
        } else if (value == 3) {
            itemFactory = std::make_unique<Poisonhealthfactory>();
        } else if (value == 4) {
            itemFactory = std::make_unique<Woundatkfactory>();
        } else if (value == 5) {
            itemFactory = std::make_unique<Wounddeffactory>();
        }

        Item potion = itemFactory->createItems(this, temp);
        removepoint(chamber, temp);
       
        this->addItem(std::make_unique<Item>(potion));
    }
    for (auto &item : items) {
        updateItem(item.get());
    }
}

void Floor::generateGold() {
}


void Floor::generatePlayer() {
    int chamber = prng1(0, NUM_CHAMBERS - 1);
    player->setChamberNum(chamber);
    int posn = prng1(0, possiblePoints[chamber].size() - 1);
    Posn temp = possiblePoints[chamber][posn];
    removepoint(chamber, temp);
    player->setPosn(temp);
    Cell& cell = getCell(temp);
    cell.setPlayer(player);
    updatePlayer();
}

void Floor::generateStair() {
    int playerchamber = player->getChamberNum();
    int which = prng1(0, NUM_CHAMBERS - 1);
    while (which == playerchamber) {
        which = prng1(0, NUM_CHAMBERS - 1);
    }

    int posn = prng1(0, possiblePoints[which].size() - 1);

    Posn temp = possiblePoints[which][posn];
    removepoint(which, temp);
    Cell& cell = getCell(temp);
    cell.setStair();
}


void Floor::generateFloor() {
    generatePlayer();
    generateEnemies();
    generatePotions();
    generateStair();
}



bool Floor::checkValidMove(Posn posn) {
    char symbol = getCell(posn).getDisplaySymbol();
    if (symbol == '.' || symbol == '+' || symbol == '#') {
        return true;
    }
    return false;
}

bool Floor::checkValidMoveForEnemy(Posn posn) {
    char symbol = getCell(posn).getDisplaySymbol();
    if (symbol == '.') {
        return true;
    }
    return false;
}

