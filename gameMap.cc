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

    std::ifstream file1{"valid.txt"};
    std::string line1;
    std::vector<Posn> chamber1;
    std::vector<Posn> chamber2;
    std::vector<Posn> chamber3;
    std::vector<Posn> chamber4;
    std::vector<Posn> chamber5;

    for (int i = 0; i <= 21; i++) {
        std::getline(file1, line1);
        for (int j = 0; j < 79; j++) {
            if (line1[j] == '1') {
                chamber1.push_back({i, j});
            } else if (line1[j] == '2') {
                chamber2.push_back({i, j});
            } else if (line1[j] == '3') {
                chamber3.push_back({i, j});
            } else if (line1[j] == '4') {
                chamber4.push_back({i, j});
            } else if (line1[j] == '5') {
                chamber5.push_back({i, j});
            } else {
                continue;
            }
        }
    }
   
    PossiblePoints.push_back(chamber1);
    PossiblePoints.push_back(chamber2);
    PossiblePoints.push_back(chamber3);
    PossiblePoints.push_back(chamber4);
    PossiblePoints.push_back(chamber5);
}

GameMap::~GameMap() {}

char GameMap::getTile(int y, int x) const {
    return cells[y][x];
}

void GameMap::removepoint(int chambernum, Posn pair) {
    for (auto it = PossiblePoints[chambernum].begin(); it != PossiblePoints[chambernum].end();) {
        if((*it).x == pair.y && (*it).x == pair.y) {
            it = PossiblePoints[chambernum].erase(it);
        } else {
            ++it;
        }
    }
}

std::vector<std::vector<Posn>> GameMap::getPossiblePoints() {
    return PossiblePoints;
}
