#include "gameMap.h"
#include <fstream>
#include <string>

GameMap::GameMap(std::string mapFile) : mapFile{mapFile} {
    std::ifstream file{mapFile};
    std::string line;
    while (std::getline(file, line)) {
        std::vector<char> row;
        for (char c : line) {
            row.emplace_back(c);
        }
        cells.emplace_back(row);
    }
}

GameMap::~GameMap() {}

char GameMap::getTile(int y, int x) const {
    return cells[y][x];
}
