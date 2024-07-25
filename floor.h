#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include <algorithm>
#include <memory>
#include "constants.h"
#include "PRNG.h"
class Cell;

class Floor {
    Player* player;
    GameMap* gameMap;
    std::vector<std::vector<Cell>> cells;
    std::vector<EnemyPtr> enemies;
    std::vector<ItemPtr> items;
    std::vector<std::vector<Posn>> possiblePoints;
    PRNG prng1;

public:
    Floor();
    ~Floor();

    void initFloor(Player* player, GameMap* gameMap);
    void loadFloor();
    void loadGivenFloor(std::string mapFile);

    void addEnemy(EnemyPtr enemy);
    void addItem(ItemPtr item);
    void loadItems();

    Cell& getCell(Posn posn);
    void clearCell(Posn posn);

    void updatePlayer();
    void updateEnemy(Enemy* enemy);
    void updateItem(Item* item);

    bool isEmpty(Posn posn);

    // for enemies attack player
    std::vector<Posn> getNeighbours(Posn posn);

    std::vector<char> getDisplay();


    void removeEnemy(Enemy* enemy);
    void removeItem(Item* item);


    void removepoint(int chambernum, Posn pair);

    void enemiesAction(int stop);
    void generateEnemies();
    void generatePotions();
    void generateGold();
    void generatePlayer();
    void generateStair();
    void generateFloor();

    Posn playerRandomPosn();

    bool checkValidMove(Posn posn);
    bool checkValidMoveForEnemy(Posn posn);

    PRNG& getRandomGnerator();
};






#endif
