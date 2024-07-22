#ifndef PLAYER_H
#define PLAYER_H

#include "constants.h"


class Player {
    PlayerRace playerRace;
    int hp;
    int atk;
    int def;
    int gold;
    int maxHp;
    int exAtk;
    int exDef;
    int currFloorIndex;
    bool isDead;
    bool isWon;
    Floor* floor;
public:
    Player(PlayerRace playerRace, Floor* floor);
    bool handlePlayerCmd(PlayerCmd cmd);
    void setHp(int hp);
    void setAtk(int atk);
    void setDef(int def);
    void setGold(int gold);
    void setMaxHp(int maxHp);
    void setExAtk(int exAtk);
    void setExDef(int exDef);
    void setCurrFloorIndex(int currFloorIndex);
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
    ~Player();
};



#endif
