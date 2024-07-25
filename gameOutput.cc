#include "gameOutput.h"
#include "player.h"
#include <ncurses.h>
#include <iostream>
#include <vector>

// Constructor for GameOutput
GameOutput::GameOutput(bool useDLC) : useDLC{useDLC} {
    if (useDLC) {
        initscr(); // Initialize ncurses
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        if (has_colors()) {
            start_color();

            init_pair(COLOR_PAIR_PLAYER, COLOR_CYAN, COLOR_BLACK);
            init_pair(COLOR_PAIR_STAIRCASE, COLOR_CYAN, COLOR_BLACK);
            init_pair(COLOR_PAIR_ENEMY, COLOR_RED, COLOR_BLACK);
            init_pair(COLOR_PAIR_TREASURE, COLOR_YELLOW, COLOR_BLACK);
            init_pair(COLOR_PAIR_POTION, COLOR_GREEN, COLOR_BLACK);
        }
    }
}

// Function to check if a cell contains an enemy
bool isEnemy(char cell) {
    return cell == SYMBOL_HUMAN || cell == SYMBOL_DWARF || cell == SYMBOL_ELF ||
           cell == SYMBOL_ORC || cell == SYMBOL_MERCHANT || cell == SYMBOL_DRAGON ||
           cell == SYMBOL_HALFLING;
}

// Function to print the game output
void GameOutput::printOutput(const std::vector<char>& display, Player* player) {
    if (useDLC) {
        clear(); // Clear the ncurses window
        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                char cell = display[i * MAP_WIDTH + j];
                if (cell == SYMBOL_PLAYER) {
                    attron(COLOR_PAIR(COLOR_PAIR_PLAYER));
                    mvaddch(i, j, cell);
                    attroff(COLOR_PAIR(COLOR_PAIR_PLAYER));
                } else if (cell == SYMBOL_STAIR) {
                    attron(COLOR_PAIR(COLOR_PAIR_STAIRCASE));
                    mvaddch(i, j, cell);
                    attroff(COLOR_PAIR(COLOR_PAIR_STAIRCASE));
                } else if (isEnemy(cell)) {
                    attron(COLOR_PAIR(COLOR_PAIR_ENEMY));
                    mvaddch(i, j, cell);
                    attroff(COLOR_PAIR(COLOR_PAIR_ENEMY));
                } else if (cell == SYMBOL_GOLD) {
                    attron(COLOR_PAIR(COLOR_PAIR_TREASURE));
                    mvaddch(i, j, cell);
                    attroff(COLOR_PAIR(COLOR_PAIR_TREASURE));
                } else if (cell == SYMBOL_POTION) {
                    attron(COLOR_PAIR(COLOR_PAIR_POTION));
                    mvaddch(i, j, cell);
                    attroff(COLOR_PAIR(COLOR_PAIR_POTION));
                } else {
                    mvaddch(i, j, cell);
                }
            }
        }
        mvprintw(MAP_HEIGHT, 0, "Race: %s Gold: %d", player->getRaceStr().c_str(), player->getGold());
        mvprintw(MAP_HEIGHT + 1, 0, "HP: %d", player->getHp());
        mvprintw(MAP_HEIGHT + 2, 0, "Atk: %d", player->getAtk() + player->getExAtk());
        mvprintw(MAP_HEIGHT + 3, 0, "Def: %d", player->getDef() + player->getExDef());
        mvprintw(MAP_HEIGHT + 4, 0, "Floor: %d", player->getCurrFloorIndex());
        mvprintw(MAP_HEIGHT + 5, 0, "Action: %s", player->getAction().c_str());
        refresh(); // Refresh the ncurses window to show changes
    } else {
        std::cout << "\x1B[2J\x1B[H"; // ANSI escape codes to clear the terminal
        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                char cell = display[i * MAP_WIDTH + j];
                if (cell == SYMBOL_PLAYER) {
                    std::cout << BLUE << cell << RESET;
                } else if (cell == SYMBOL_STAIR) {
                    std::cout << BLUE << cell << RESET;
                } else if (isEnemy(cell)) {
                    std::cout << RED << cell << RESET;
                } else if (cell == SYMBOL_GOLD) {
                    std::cout << YELLOW << cell << RESET;
                } else if (cell == SYMBOL_POTION) {
                    std::cout << GREEN << cell << RESET;
                } else {
                    std::cout << cell;
                }
            }
            std::cout << std::endl;
        }
        std::cout << "Race: " << player->getRaceStr() << " Gold: " << player->getGold() << std::endl;
        std::cout << "HP: " << player->getHp() << std::endl;
        std::cout << "Atk: " << player->getAtk() + player->getExAtk() << std::endl;
        std::cout << "Def: " << player->getDef() + player->getExDef() << std::endl;
        std::cout << "Floor: " << player->getCurrFloorIndex() << std::endl;
        std::cout << "Action: " << player->getAction() << std::endl;
        std::cout << std::endl;
    }
}


// Destructor for GameOutput
GameOutput::~GameOutput() {
    if (useDLC) {
        endwin(); // End ncurses
    }
}
