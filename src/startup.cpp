#include "startup.h"
#include <iostream>
#include <istream>
#include <typeinfo>

bool Startup::quitgame = false;

bool Startup::bootscreen() {
    std::cout << "Hello young player! Welcome to Pacman!" << std::endl;
    std::cout << "Not the same game as you once remember" << std::endl;
    std::cout << "but it is close enough!" << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1: Start a game" << std::endl;
    std::cout << "2: Quit" << std::endl;
    std::cout << "Please enter a number corresponding to the options above! :D : ";
    int keyevent;
    std::cin >> keyevent;

    if ((keyevent < 1) || (keyevent > 2)) {
        std::cout << "Wrong number! Please enter a valid number please!" << std::endl;
        return false;
    }
    switch (keyevent) {
    case 1:
        return true;
        break;
    case 2:
        std::cout << "Thanks for playing! Quitting the game now!" << std::endl;
        setQuitGame();
        return false;
    }
}