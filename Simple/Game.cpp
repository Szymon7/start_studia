#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int Game::guess() {
    int input;
    int trials = 0;
    int highestNumber;

    std::cout << "Hello in guessing game!\n"
                 "Pick highest number to guess: \n";
    std::cin >> highestNumber;

    std::srand(std::time(nullptr));
    int randomNum = (rand() % highestNumber) + 1;

    while (input != randomNum) {
        std::cout << "\nWrite number: ";
        std::cin >> input;
        trials++;

        if (input > randomNum) {
            std::cout << "\nTry lower\n";
        }

        if (input < randomNum) {
            std::cout << "\nTry higher\n";
        }
    }

    std::cout << "You win!\n";
    std::cout << "Number of trials: " << trials;
    std::cout << "\n\n=============================\n";

    return 0;
}