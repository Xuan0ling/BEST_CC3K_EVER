#include "gameInput.h"

GameInput::GameInput(bool useDLC) : useDLC{useDLC} {
    if (useDLC) {
        if (!initscr()) {
            std::cerr << "Error initializing ncurses." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
    }
}

std::string GameInput::collectInput() {
    std::string input;
    if (useDLC) {
        int ch = getch();
        input += ch;
        if (ch == 'n' || ch == 's' || ch == 'e' || ch == 'w') {
            ch = getch();
            input += ch;
        }
    } else {
        std::cin >> input;
    }
    return input;
}

PlayerCmd GameInput::getInput() {
    std::string input = collectInput();

    if (input == "h" || input == "j" || input == "k" || input == "l" ||
        input == "H" || input == "J" || input == "K" || input == "L" ||
        input == "no" || input == "so" || input == "ea" || input == "we" ||
        input == "ne" || input == "nw" || input == "se" || input == "sw") {
        return getPlayerPosition(input);
    } else if (input == "a") {
        std::string attackDirInput = collectInput();
        PlayerCmd attackDir = getPlayerPosition(attackDirInput);
        return 
            attackDir == PlayerCmd::WE ? PlayerCmd::ATTACK_WE : 
            attackDir == PlayerCmd::EA ? PlayerCmd::ATTACK_EA : 
            attackDir == PlayerCmd::NO ? PlayerCmd::ATTACK_NO : 
            attackDir == PlayerCmd::SO ? PlayerCmd::ATTACK_SO : 
            attackDir == PlayerCmd::NE ? PlayerCmd::ATTACK_NE : 
            attackDir == PlayerCmd::NW ? PlayerCmd::ATTACK_NW : 
            attackDir == PlayerCmd::SE ? PlayerCmd::ATTACK_SE : 
            attackDir == PlayerCmd::SW ? PlayerCmd::ATTACK_SW : PlayerCmd::INVALID;
    } else if (input == "u") {
        std::string useDirInput = collectInput();
        PlayerCmd useDir = getPlayerPosition(useDirInput);
        return 
            useDir == PlayerCmd::WE ? PlayerCmd::USEPOTION_WE : 
            useDir == PlayerCmd::EA ? PlayerCmd::USEPOTION_EA : 
            useDir == PlayerCmd::NO ? PlayerCmd::USEPOTION_NO : 
            useDir == PlayerCmd::SO ? PlayerCmd::USEPOTION_SO : 
            useDir == PlayerCmd::NE ? PlayerCmd::USEPOTION_NE : 
            useDir == PlayerCmd::NW ? PlayerCmd::USEPOTION_NW : 
            useDir == PlayerCmd::SE ? PlayerCmd::USEPOTION_SE : 
            useDir == PlayerCmd::SW ? PlayerCmd::USEPOTION_SW : PlayerCmd::INVALID;
    } else if (input == "r") {
        return PlayerCmd::RESTART;
    } else if (input == "q") {
        return PlayerCmd::QUIT;
    } else if (input == "f") {
        return PlayerCmd::STOP;
    }else {
        return PlayerCmd::INVALID;
    }
}

PlayerCmd GameInput::getPlayerPosition(const std::string& input) {
    if (input == "h" || input == "we") {
        return PlayerCmd::WE;
    } else if (input == "j" || input == "no") {
        return PlayerCmd::NO;
    } else if (input == "k" || input == "so") {
        return PlayerCmd::SO;
    } else if (input == "l" || input == "ea") {
        return PlayerCmd::EA;
    } else if (input == "K" || input == "ne") {
        return PlayerCmd::NE;
    } else if (input == "J" || input == "nw") {
        return PlayerCmd::NW;
    } else if (input == "L" || input == "se") {
        return PlayerCmd::SE;
    } else if (input == "H" || input == "sw") {
        return PlayerCmd::SW;
    }
    return PlayerCmd::INVALID;
}

PlayerRace GameInput::getPlayerRace() {
    char input;
    if (useDLC) {
        input = getch();
    } else {
        std::cin >> input;
    }
    switch (input) {
        case 's':
            return PlayerRace::SHADE;
        case 'd':
            return PlayerRace::DROW;
        case 'v':
            return PlayerRace::VAMPIRE;
        case 't':
            return PlayerRace::TROLL;
        case 'g':
            return PlayerRace::GOBLIN;
        case 'q':
            return PlayerRace::QUIT;
        default:
            return PlayerRace::INVALID;
    }
}

GameInput::~GameInput() {
}
