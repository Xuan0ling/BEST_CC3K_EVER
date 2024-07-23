#include "gameOutput.h"



GameOutput::GameOutput() {}

void GameOutput::printOutput(std::vector<char> display) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            std::cout << display[i * MAP_WIDTH + j];
        }
        std::cout << std::endl;
    }
}

GameOutput::~GameOutput() {}
