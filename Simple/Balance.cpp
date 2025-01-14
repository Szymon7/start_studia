#include "Balance.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

double Balance::sum(const double values[], int size) {
    double total = 0;
    for (int i = 0; i < size; ++i) {
        total += values[i];
    }
    return total;
}

double Balance::min(const double values[], const int size) {
    double minimum = values[0];
    for (int i = 1; i < size; ++i) {
        if (values[i] < minimum) {
            minimum = values[i];
        }
    }
    return minimum;
}

double Balance::max(const double values[], int size) {
    double maximum = values[0];
    for (int i = 1; i < size; ++i) {
        if (values[i] > maximum) {
            maximum = values[i];
        }
    }
    return maximum;
}

double Balance::average(const double values[], int size) {
    return sum(values, size) / size;
}

void Balance::displayTable(const double income[], const double expenses[], int size) {
    std::cout << "\nMonthly Balance Sheet:\n";
    std::cout << std::setw(10) << "Month" << std::setw(15) << "Income" << std::setw(15) << "Expenses" << std::setw(15) << "Net" << std::setw(10) << "Status" << "\n";
    for (int i = 0; i < size; ++i) {
        double net = income[i] - expenses[i];
        std::string status = (net > 0) ? "Profit" : (net < 0) ? "Loss" : "Zero";

        std::cout << std::setw(10) << i + 1
                  << std::setw(15) << std::fixed << std::setprecision(2) << income[i]
                  << std::setw(15) << expenses[i]
                  << std::setw(15) << net
                  << std::setw(10) << status
                  << "\n";
    }
}

int Balance::run() {
    double income[12] = {0}, expenses[12] = {0};
    int choice;

    do {
        std::cout << "\n--- Annual Balance ---\n";
        std::cout << "1. Enter monthly income\n";
        std::cout << "2. Enter monthly expenses\n";
        std::cout << "3. Display summary\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter income for each month:\n";
            for (int i = 0; i < 12; ++i) {
                std::cout << "Month " << i + 1 << ": ";
                std::cin >> income[i];
            }
            break;

        case 2:
            std::cout << "Enter expenses for each month:\n";
            for (int i = 0; i < 12; ++i) {
                std::cout << "Month " << i + 1 << ": ";
                std::cin >> expenses[i];
            }
            break;

        case 3:
            displayTable(income, expenses, 12);

            std::cout << "\nSummary:\n";
            std::cout << "Total income: " << sum(income, 12) << "\n";
            std::cout << "Total expenses: " << sum(expenses, 12) << "\n";
            std::cout << "Net profit/loss: " << sum(income, 12) - sum(expenses, 12) << "\n";
            std::cout << "\nIncome statistics:\n";
            std::cout << "Minimum: " << min(income, 12) << ", Maximum: " << max(income, 12) << ", Average: " << average(income, 12) << "\n";
            std::cout << "\nExpenses statistics:\n";
            std::cout << "Minimum: " << min(expenses, 12) << ", Maximum: " << max(expenses, 12) << ", Average: " << average(expenses, 12) << "\n";
            break;
        case 4:
            return 0;
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
        }

    } while (choice != 4);

    return 0;
}
