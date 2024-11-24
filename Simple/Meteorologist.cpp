#include "Meteorologist.h"

#include <iostream>

int Meteorologist::calculateDay() {
    std::string input;
    double numberOfTemperatures = 0;
    double highestNegativeTemperature = 0;
    double lowestNegativeTemperature = 0;
    double numberOfNegativeTemperatures = 0;
    double highestPositiveTemperature = 0;
    double lowestPositiveTemperature = 0;
    double numberOfPositiveTemperatures = 0;
    double numberOfZeroTemperatures = 0;
    double averageTemperature = 0;

    std::cout << "Hello in meteorologist program!\n";


    while (true) {
        std::cout << "Provide temperature (type 'done' to stop): \n";
        std::cin >> input;

        if (input == "done") {
            break;
        }

        try {
            double temperature = std::stod(input);
            numberOfTemperatures++;

            if (temperature < 0) {
                numberOfNegativeTemperatures++;

                if (temperature < lowestNegativeTemperature) {
                    lowestNegativeTemperature = temperature;
                } else if (temperature > highestNegativeTemperature || highestNegativeTemperature == 0) {
                    highestNegativeTemperature = temperature;
                }
            } else if (temperature > 0) {
                numberOfPositiveTemperatures++;

                if (temperature < lowestPositiveTemperature || lowestPositiveTemperature == 0) {
                    lowestPositiveTemperature = temperature;
                } else if (temperature > highestPositiveTemperature) {
                    highestPositiveTemperature = temperature;
                }
            } else if (temperature == 0) {
                numberOfZeroTemperatures++;
            }

            if (numberOfTemperatures > 1) {
                averageTemperature = (averageTemperature + temperature) / 2;
            } else {
                averageTemperature = temperature;
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter an integer, or 'done' to finish.\n";
        } catch (const std::out_of_range&) {
            std::cout << "Number out of range. Please enter a smaller integer.\n";
        }
    }

    if (numberOfNegativeTemperatures == 0) {
        std::cout << "\nHve no temperatures to calculate data. Bye bye!";
        std::cout << "\n\n=============================\n";

        return 0;
    }
    
    std::cout << "\nAverage temperature: " << averageTemperature;

    std::cout << "\n\nHighest positive temperature: " << highestPositiveTemperature;
    std::cout << "\nLowest positive temperature: " << lowestPositiveTemperature;
    std::cout << "\nNumber of positive temperature: " << numberOfPositiveTemperatures;

    std::cout << "\n\nHighest negative temperature: " << highestNegativeTemperature;
    std::cout << "\nLowest negative temperature: " << lowestNegativeTemperature;
    std::cout << "\nNumber of negative temperature: " << numberOfNegativeTemperatures;

    std::cout << "\n\nNumber of zero temperature: " << numberOfZeroTemperatures;

    std::cout << "\n\n=============================\n";

    return 0;
}