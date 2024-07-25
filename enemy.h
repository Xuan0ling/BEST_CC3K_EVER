#ifndef ENEMY_H
#define ENEMY_H

#include "floor.h"
#include "constants.h"
#include "PRNG.h"


class Enemy {
protected:
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
    virtual bool attack(Player* player, PRNG& prng1);
    virtual bool beAttacked(Player* player, PRNG& prng);

    char getSymbol();
    Posn getPosn();
    int getHp();
    int getAtk();
    int getDef();
    int loseHp(int Atk);
    void setPosn(Posn posn);
};


#endif
