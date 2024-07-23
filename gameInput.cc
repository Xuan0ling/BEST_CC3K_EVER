#include "gameInput.h"

GameInput::GameInput() {}

PlayerCmd GameInput::getInput() {
    char input;
    std::cin >> input;
    switch (input) {
        case 'h':
        case 'j':
        case 'k':
        case 'l':
            return getPlayerPosition(input);
        case 'a': {
            std::cin >> input;
            PlayerCmd attackDir = getPlayerPosition(input);
            return 
                attackDir == PlayerCmd::WE ? PlayerCmd::ATTACK_WE : 
                attackDir == PlayerCmd::EA ? PlayerCmd::ATTACK_EA : 
                attackDir == PlayerCmd::NO ? PlayerCmd::ATTACK_NO : 
                attackDir == PlayerCmd::SO ? PlayerCmd::ATTACK_SO : PlayerCmd::INVALID;
        }
        case 'u': {
            std::cin >> input;
            PlayerCmd useDir = getPlayerPosition(input);
            return 
                useDir == PlayerCmd::WE ? PlayerCmd::USEPOTION_WE : 
                useDir == PlayerCmd::EA ? PlayerCmd::USEPOTION_EA : 
                useDir == PlayerCmd::NO ? PlayerCmd::USEPOTION_NO : 
                useDir == PlayerCmd::SO ? PlayerCmd::USEPOTION_SO : PlayerCmd::INVALID;
        }
        case '>':
            return PlayerCmd::ENTERNEXTFLOOR;
        case 'r':
            return PlayerCmd::RESTART;
        case 'q':
            return PlayerCmd::QUIT;
        default:
            return PlayerCmd::INVALID;
    }
}

PlayerCmd GameInput::getPlayerPosition(char input) {
    std::cout << "input: " << input << std::endl;
    switch (input) {
        case 'h':
            return PlayerCmd::WE;
        case 'j':
            return PlayerCmd::NO;
        case 'k':
            return PlayerCmd::SO;
        case 'l':
            return PlayerCmd::EA;
        default:
            return PlayerCmd::INVALID;
    }
}

PlayerRace GameInput::getPlayerRace() {
    char input;
    std::cin >> input;
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
        default:
            return PlayerRace::INVALID;
    }
}

GameInput::~GameInput() {}
