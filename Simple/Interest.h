#ifndef INTEREST_H
#define INTEREST_H

class Interest {
public:
    static int tests();

private:
    static double progressive(double value, double numberOfDays, double dalyInterest);
};

#endif //INTEREST_H
