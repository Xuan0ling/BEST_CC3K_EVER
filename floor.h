#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include <algorithm>
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

    void addEnemy(EnemyPtr enemy);
    void addItem(ItemPtr item);

    Cell& getCell(Posn posn);
    void clearCell(Posn posn);

    void updatePlayer();
    void updateEnemy(Enemy* enemy);
    void updateItem(Item* item);

    bool isEmpty(Posn posn);

    std::vector<char> getDisplay();


    void removeEnemy(Enemy* enemy);
    void removeItem(Item* item);

    void removepoint(int chambernum, Posn pair);

    void enemiesAction();
    void generateEnemies();
    void generateItems();
    void generateStair();
    void generatePlayer();
    void generateFloor();

    bool checkValidMove(Posn posn);


};






#endif
