#include "Calculator.h"

#include <iostream>

int Calculator::basic() {
    int numberFirst, numberSecond;
    char operation;
    std::cout << "Let's calculate something: \n";
    std::cout << "Input number: ";
    std::cin >> numberFirst;

    while (true) {
        std::cout << "Input operation character (+, -, *, /): ";
        std::cin >> operation;
        if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
            break;
        }
    }

    std::cout << "Input second number: ";
    std::cin >> numberSecond;

    std::cout << std::endl << std::endl << numberFirst << " " << operation << " " << numberSecond << " = ";
    switch (operation) {
        case '+':
            std::cout << numberFirst + numberSecond;
            break;
        case '-':
            std::cout << numberFirst - numberSecond;
            break;
        case '*':
            std::cout << numberFirst * numberSecond;
            break;
        case '/':
            std::cout << numberFirst / numberSecond;
            break;
        default:
            break;
    }

    std::cout << "\n\n=============================\n";
    return 0;
}
