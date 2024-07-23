#include "gameOutput.h"


GameOutput::GameOutput(bool useDLC) : useDLC{useDLC} {
    if (useDLC) {
        initscr(); // Initialize ncurses
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
    }
}

void GameOutput::printOutput(const std::vector<char>& display) {
    if (useDLC) {
        clear(); // Clear the ncurses window
        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                mvaddch(i, j, display[i * MAP_WIDTH + j]);
            }
        }
        refresh(); // Refresh the ncurses window to show changes
    } else {
        std::cout << "\x1B[2J\x1B[H"; // ANSI escape codes to clear the terminal
        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                std::cout << display[i * MAP_WIDTH + j];
            }
            std::cout << std::endl;
        }
    }
}

GameOutput::~GameOutput() {
    if (useDLC) {
        endwin(); // End ncurses
    }
}
