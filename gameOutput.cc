#include "gameOutput.h"
#include "player.h"


GameOutput::GameOutput(bool useDLC) : useDLC{useDLC} {
    if (useDLC) {
        initscr(); // Initialize ncurses
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
    }
}

void GameOutput::printOutput(const std::vector<char>& display, Player* player) {
    if (useDLC) {
        clear(); // Clear the ncurses window
        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                mvaddch(i, j, display[i * MAP_WIDTH + j]);
            }
        }
        mvprintw(MAP_HEIGHT, 0, "Race: %s Gold: %d", player->getRace().c_str(), player->getGold());
        mvprintw(MAP_HEIGHT + 1, 0, "HP: %d", player->getHp());
        mvprintw(MAP_HEIGHT + 2, 0, "Atk: %d", player->getAtk() + player->getExAtk());
        mvprintw(MAP_HEIGHT + 3, 0, "Def: %d", player->getDef() +  player->getExDef());
        mvprintw(MAP_HEIGHT + 4, 0, "floor: %d", player->getCurrFloorIndex());
        mvprintw(MAP_HEIGHT + 5, 0, "Action: %s", player->getAction().c_str());
        refresh(); // Refresh the ncurses window to show changes
    } else {
        std::cout << "\x1B[2J\x1B[H"; // ANSI escape codes to clear the terminal
        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                std::cout << display[i * MAP_WIDTH + j];
            }
            std::cout << std::endl;
        }
        std::cout << "Race: " << player->getRace() << " Gold: " << player->getGold() << std::endl;
        std::cout << "HP: " << player->getHp() << std::endl;
        std::cout << "Atk: " << player->getAtk() + player->getExAtk() << std::endl;
        std::cout << "Def: " << player->getDef() + player->getExDef() << std::endl;
        std::cout << "floor: " << player->getCurrFloorIndex() << std::endl;
        std::cout << "Action: " << player->getAction() << std::endl;
        std::cout << std::endl;
    }
}

GameOutput::~GameOutput() {
    if (useDLC) {
        endwin(); // End ncurses
    }
}
