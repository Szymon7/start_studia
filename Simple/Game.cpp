#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int Game::guess() {
    std::srand(std::time(nullptr));
    int randomNum = rand() % 101;
    int input;

    std::cout << "Hello in guessing game!\n"
                 "Guess number between 1 and 100\n";

    while (input != randomNum) {
        std::cout << "\nWrite number: ";
        std::cin >> input;

        if (input > randomNum) {
            std::cout << "\nTry lower\n";
        }

        if (input < randomNum) {
            std::cout << "\nTry higher\n";
        }
    }

    std::cout << "You win!\n";
    std::cout << "\n=============================\n";

    return 0;
}