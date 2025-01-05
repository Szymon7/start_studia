#include "FigureFields.h"
#include <iostream>
#include <limits>

double FigureFields::getValue(std::string nameOfValue) {
    double a = 0;
    bool fail;

    do {
        fail = false;
        if (a < 0)
            std::cout << std::endl << "Value must be positive." << std::endl;

        std::cout << "Provide " << nameOfValue << ": ";
        std::cin >> a;
        if (std::cin.fail()) {
            fail = true;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer.";
        }
    } while (a < 0 || fail);

    return a;
}

int FigureFields::rectangleField() {
    double a = 0;
    double b = 0;

    a = getValue("side 1 length");
    b = getValue("side 2 length");

    std::cout << "Field of rectangle is: " << a * b << "\n\n";
    return 0;
}

int FigureFields::triangleField() {
    double h = 0;
    double a = 0;

    h = getValue("height");
    a = getValue("height base");

    std::cout << "Field of triangle is: " << h * a / 2 << "\n\n";
    return 0;
}

int FigureFields::circleField() {
    double r = 0;

    r = getValue("radius");

    std::cout << "Field of circle is: " << r * r * 3.1415 << "\n\n";
    return 0;
}

int FigureFields::trapezeField() {
    double h = 0;
    double a = 0;
    double b = 0;

    h = getValue("height");
    a = getValue("base 1");
    b = getValue("base 2");

    std::cout << "Field of trapeze is: " << (a + b) * h / 2 << "\n\n";
    return 0;
}

int FigureFields::menu() {
    while (true) {
        std::cout << "What field you want calculate: \n";
        std::cout << "1. Square\n";
        std::cout << "2. Rectangle\n";
        std::cout << "3. Circle\n";
        std::cout << "4. Triangle\n";
        std::cout << "5. Trapeze\n";
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
                rectangleField();
                continue;
            case 2:
                rectangleField();
                continue;
            case 3:
                circleField();
                continue;
            case 4:
                triangleField();
                continue;
            case 5:
                trapezeField();
                continue;
            default:
                return 0;
        }

        std::cout << "\n\n=============================\n";
    }
}
