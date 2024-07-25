#include <ncurses.h>
#include <iostream>
#include <vector>
#include <string>
#include "gameEnd.h"

GameEnd::GameEnd(bool win, int playerScore): win{win}, playerScore{playerScore} {}

void GameEnd::printEnd() {
    std::string endMessage = win ? "Congratulations! You won!" : "Game Over!";
    std::string scoreMessage = "Your score is: " + std::to_string(playerScore);
    std::cout << endMessage << std::endl;
    std::cout << scoreMessage << std::endl;
}

GameEnd::~GameEnd() {}
