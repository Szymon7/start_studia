#ifndef BALANCE_H
#define BALANCE_H



class Balance {
public:
    static int run();

private:
    static double sum(const double values[], int size);
    static double min(const double values[], int size);
    static double max(const double values[], int size);
    static double average(const double values[], int size);
    static void displayTable(const double income[], const double expenses[], int size);
};



#endif //BALANCE_H
