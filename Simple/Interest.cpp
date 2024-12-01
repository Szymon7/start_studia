#include "Interest.h"
#include <iostream>

double Interest::progressive(const double value, const double numberOfDays, const double dalyInterest) {
    if (numberOfDays <= 0 || value <= 0) {
        return 0;
    }

    double interest = 0;

    for (int i = 0; i < numberOfDays; i++) {
        interest += (interest + value) * dalyInterest / 100;
    }
        std::cout << "\n\ninterest:" << interest;

    return (double)(int)(interest * 100) / 100;
}

int Interest::tests() {
    double interest;

    // Test 1
    interest = progressive( 1000, 4, 3 );
        std::cout << "\nval:" << interest;

    if (interest == 125.50) {
        std::cout << "\nTest 1: OK";
    } else {
        std::cout << "\nTest 1: FAIL";
    }

    // Test 2
    interest = progressive( 1000, 10, 3 );
        std::cout << "\nval:" << interest;
    if (interest == 343.91) {
        std::cout << "\nTest 2: OK";
    } else {
        std::cout << "\nTest 2: FAIL";
    }

    interest = progressive( 2000, 8, 4 );
    if (interest == 737.13) {
        std::cout << "\nTest 3: OK";
    } else {
        std::cout << "\nTest 3: FAIL";
    }

    interest = progressive( 300, 2, 5 );
    if (interest == 30.75) {
        std::cout << "\nTest 4: OK";
    } else {
        std::cout << "\nTest 4: FAIL";
    }

    std::cout << "\n\n=============================\n";
    return 0;
}
