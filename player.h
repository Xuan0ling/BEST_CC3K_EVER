#ifndef PLAYER_H
#define PLAYER_H

#include "constants.h"


class Player {
    Posn posn;
    int hp;
    int atk;
    int def;
    int gold;
    int maxHp;
    int exAtk = 0;
    int exDef = 0;
    int currFloorIndex = 1;
    bool isDead = false;
    bool isWon = false;
    Floor* floor;
public:
    Player(Floor* floor, int hp = 100, int atk = 50, int def = 50, int gold = 0, int maxHp = 100);

    void setPosn(Posn newPosn);
    void changePosn(Posn posnChange);
    Posn getPosn();

    virtual char getSymbol();
    
    virtual void move(Posn posnChange);
    virtual void attack(Posn attackDir);
    virtual void usePotion(Posn usePotionDir);
    virtual void gainGold();

    void setHp(int hp);
    void setGold(int gold);

    void gainHp(int hp);
    void gainAtk(int atk);
    void gainDef(int def);
    void gainGold(int gold);
    void gainExAtk(int exAtk);
    void gainExDef(int exDef);
    void gainCurrFloorIndex(int currFloorIndex);


    void setMaxHp(int maxHp);
    void setIsDead(bool isDead);
    void setIsWon(bool isWon);
    int getHp();
    int getAtk();
    int getDef();
    int getGold();
    int getMaxHp();
    int getExAtk();
    int getExDef();
    int getCurrFloorIndex();
    bool getIsDead();
    bool getIsWon();
    virtual ~Player();
};



#endif
