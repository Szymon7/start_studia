#include "QuadraticFunction.h"
#include <iostream>
#include <cmath>

std::string QuadraticFunction::funkcjaKwadratowa(double a, double b, double c) {
    return (b * b) - (4 * a * c) < 0
        ? "The function has no zeros"
        : (b * b) - (4 * a * c) == 0
            ? "x0 = " + std::to_string(-b / (2 * a))
            : "x1 = " + std::to_string((-b + sqrt((b * b) - (4 * a * c))) / (2 * a)) + " x2 = " + std::to_string((-b - sqrt((b * b) - (4 * a * c))) / (2 * a));
}

int QuadraticFunction::run() {
    double a, b, c;
    std::cout << "Please enter a values of quadratic function\n";
    std::cout << "Please enter a: ";
    std::cin >> a;
    std::cout << "Please enter b: ";
    std::cin >> b;
    std::cout << "Please enter c: ";
    std::cin >> c;

    std::cout << funkcjaKwadratowa(a, b, c);
    std::cout << "\n\n=============================\n";
    return 0;
}
