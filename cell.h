#ifndef CELL_H
#define CELL_H

#include "constants.h"

class Cell {
    char symbol;
    Player* player;
    Enemy* enemy;
    Item* item;

public:
    Cell(char symbol = ' ');
    ~Cell();


    void setSymbol(char symbol);
    void setPlayer(Player* player);
    void setEnemy(Enemy* enemy);
    void setItem(Item* item);
    void setStair();


    void clearPointers();
    
    char getSymbol() const;
    Player* getPlayer() const;
    Enemy* getEnemy() const;
    Item* getItem() const;

    bool isEmpty() const;
    

    char getDisplaySymbol() const;
};



#endif
