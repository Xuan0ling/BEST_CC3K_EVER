#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include "constants.h"



class Floor {
    Player* player;
    GameMap* gameMap;
    std::vector<EnemyPtr> enemies;
    std::vector<ItemPtr> items;
    std::vector<Posn> stairPosn;
public:
    Floor(Player* player, GameMap* gameMap);
    bool checkValidMove(Posn posn);
    void addEnemy(EnemyPtr enemy);
    void addItem(ItemPtr item);
    void addStair(Posn posn);
    void removeEnemy(Enemy* enemy);
    void removeItem(Item* item);
    void removeStair(Posn posn);

    void enemiesAction();
    void generateEnemies();
    void generateItems();
    void generateStair();
    void generatePlayer();
    void generateFloor();

    std::vector<EnemyPtr>& getEnemies();
    std::vector<ItemPtr>& getItems();
    std::vector<Posn>& getStairPosn();
};






#endif
