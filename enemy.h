#ifndef ENEMY_H
#define ENEMY_H
#include "constants.h"

class Enemy {
    Posn posn;
    int hp;
    int atk;
    int def;
public:
    Enemy(Posn posn, int hp, int atk, int def);
    virtual ~Enemy();
    virtual void move(Posn playerPosn) = 0;
    virtual void attack(Player* player) = 0;
    virtual void beAttacked(int atk) = 0;

    virtual char getSymbol() = 0;
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
