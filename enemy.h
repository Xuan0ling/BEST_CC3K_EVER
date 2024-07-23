#ifndef ENEMY_H
#define ENEMY_H

#include "floor.h"
#include "constants.h"
#include "PRNG.h"


class Enemy {
    char symbol;
    Posn posn;
    int hp;
    int atk;
    int def;
    Floor* floor;
public:
    Enemy(char symbol, Posn posn, int hp, int atk, int def, Floor* floor);
    virtual ~Enemy();
    virtual void move(PRNG& prng) = 0;
    virtual void attack(Player* player) = 0;
    virtual void beAttacked(int atk) = 0;

    char getSymbol();
    Posn getPosn();
    int getHp();
    int getAtk();
    int getDef();
    void setPosn(Posn posn);
    void gainHp(int hp);
    void gainAtk(int atk);
    void gainDef(int def);
};


#endif
