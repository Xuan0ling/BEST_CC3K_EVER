#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include "constants.h"

class GameMap {
    std::string mapFile;
    std::vector<std::vector<char>> cells;
    std::vector<std::vector<Posn>> PossiblePoints;
public:
    GameMap(std::string mapFile);
    ~GameMap();
    char getTile(int y, int x) const;
    std::vector<std::vector<Posn>> getPossiblePoints();
};

#endif
