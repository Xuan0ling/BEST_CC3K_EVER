#include "gameMenu.h"


GameMenu::GameMenu(std::string titleFile, bool useDLC) : titleFile{titleFile}, useDLC{useDLC}, input{useDLC} {
    std::ifstream file{titleFile};
    std::string line;
    while (std::getline(file, line)) {
        title.emplace_back(line);
    }
}

void GameMenu::printTitle() {
    if (useDLC) {
        // Clear the screen before printing
        clear();

        // Print each line of the title at the correct positions
        int y = 0; // Start y-coordinate
        for (const std::string &line : title) {
            mvprintw(y++, 0, "%s", line.c_str());
        }

        // Print the menu options
        mvprintw(y + 1, 0, "s - Shade");
        mvprintw(y + 2, 0, "d - Drow");
        mvprintw(y + 3, 0, "v - Vampire");
        mvprintw(y + 4, 0, "t - Troll");
        mvprintw(y + 5, 0, "g - Goblin");

        // Refresh the screen to show the changes
        refresh();
    } else {
        // Clear the terminal screen
        std::cout << "\x1B[2J\x1B[H";

        // Print each line of the title
        for (const std::string &line : title) {
            std::cout << line << std::endl;
        }
        std::cout << std::endl;

        // Print the menu options
        std::cout << "s - Shade" << " " << "d - Drow" << " " << "v - Vampire" << " " << "t - Troll" << " " << "g - Goblin" << std::endl;
    }
}

PlayerRace GameMenu::stratMenu() {
    printTitle();
    PlayerRace race = input.getPlayerRace();
    while (race == PlayerRace::INVALID) {
        printTitle();
        race = input.getPlayerRace();
    }
    return race;
}

GameMenu::~GameMenu() {
    if (useDLC) {
        endwin();
    }
}


