#ifndef ENEMY_H
#define ENEMY_H

#include "floor.h"
#include "constants.h"
#include "PRNG.h"


class Enemy {
    Floor* floor;
    char symbol;
    Posn posn;
    int hp;
    int atk;
    int def;
public:
    Enemy(Floor* floor, char symbol, Posn posn, int hp, int atk, int def);
    virtual ~Enemy();
    virtual void move(PRNG& prng);
    virtual bool attack(Player* player);
    virtual void beAttacked(int atk);

    char getSymbol();
    Posn getPosn();
    int getHp();
    int getAtk();
    int getDef();
    void setPosn(Posn posn);
};


#endif
