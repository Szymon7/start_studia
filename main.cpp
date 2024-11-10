#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

#include "Simple/Calculator.h"
#include "Simple/Conversion.h"
#include "Simple/Game.h"

int findHighestInt() {
    int maxValue;
    std::string input;
    bool newSeries = true;

    while (newSeries) {
        maxValue = std::numeric_limits<int>::min();
        std::cout << "Enter integers to find the highest value (type 'done' to stop, 'reset' to start over):\n";

        bool collectingInput = true;
        while (collectingInput) {
            std::cout << "Enter an integer: ";
            std::cin >> input;

            if (input == "done") {
                if (maxValue != std::numeric_limits<int>::min()) {
                    std::cout << "The highest value entered is: " << maxValue << "\n";
                } else {
                    std::cout << "No valid integers were entered.\n";
                }
                collectingInput = false;
            } else if (input == "reset") {
                std::cout << "Starting a new series...\n";
                maxValue = std::numeric_limits<int>::min();
            } else {
                try {
                    int number = std::stoi(input);
                    if (number > maxValue) {
                        maxValue = number;
                    }
                } catch (const std::invalid_argument&) {
                    std::cout << "Invalid input. Please enter an integer, 'done' to finish, or 'reset' to start over.\n";
                } catch (const std::out_of_range&) {
                    std::cout << "Number out of range. Please enter a smaller integer.\n";
                }
            }
        }

        std::cout << "Would you like to enter a new series of integers? (yes/no): ";
        std::cin >> input;
        newSeries = (input == "yes");
    }

    std::cout << "\n\n=============================\n";
    return 0;
}

int main() {
    while (true) {
        std::cout << "MENU: \n";
        std::cout << "1. Find highest integer\n";
        std::cout << "2. Convert meters\n";
        std::cout << "3. Meters conversion to units table\n";
        std::cout << "4. Calculator\n";
        std::cout << "5. Guessing game\n";
        std::cout << "0. Exit\n";

        int selectedProgram;
        std::cout << "\nSelect program: ";

        std::cin >> selectedProgram;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer.";
            std::cout << "\n\n==========================================\n";
            continue;
        }
        std::cout << "\n\n=============================\n";

        switch (selectedProgram) {
            case 1:
                findHighestInt();
                continue;
            case 2:
                Conversion::convertMetersToUnits();
                continue;
            case 3:
                Conversion::metersConvertTable();
                continue;
            case 4:
                Calculator::basic();
                continue;
            case 5:
                Game::guess();
                continue;
            case 0:
                return 0;
            default:
                continue;
        }
    }

    return 0;
}