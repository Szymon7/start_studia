#include "Conversion.h"

#include <iomanip>
#include <iostream>
#include <ostream>

int Conversion::convertMetersToUnits() {
    int meters;
    std::cout << "Convert meters to other units\n";
    std::cout << "Input meters: ";
    std::cin >> meters;
    std::cout << meters << "m, to: ";

    double inches = meters * 39.3700787;
    double foot = meters * 3.2808399;
    double yard = meters * 1.0936133;
    double miles = meters * 0.000621371192;

    std::cout << std::endl << "Cale: ";
    std::cout << std::fixed << std::setprecision(4) << inches;
    std::cout << std::endl << "Stopy: ";
    std::cout << std::fixed << std::setprecision(4) << foot;
    std::cout << std::endl << "Yardy: ";
    std::cout << std::fixed << std::setprecision(4) << yard;
    std::cout << std::endl << "Mile: ";
    std::cout << std::fixed << std::setprecision(4) << miles;
    std::cout << "\n\n=============================\n";
    return 0;
}

int Conversion::metersConvertTable() {
    int meters = 5;
    std::cout << "Table with meters i other units\n";
    std::cout << "Input meters: ";
    std::cout << "\n\n";
    std::cout << "-----------------------------------------------------------------------------------\n";
    std::cout << "|     meters     |     inches     |     foots     |     yards     |     miles     |\n";
    std::cout << "-----------------------------------------------------------------------------------\n";

    while (meters <= 2600) {
        double inches = meters * 39.3700787;
        double foot = meters * 3.2808399;
        double yard = meters * 1.0936133;
        double miles = meters * 0.000621371192;

        std::cout << std::fixed << std::setprecision(4)
            << "| " << meters << " | "
            << inches << " | "
            << foot << " | "
            << yard << " | "
            << miles << " | \n";
        std::cout << "-----------------------------------------------------------------------------------\n";

        meters = meters + 5;
    }
    std::cout << "\n=============================\n";
    return 0;
}