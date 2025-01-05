#ifndef FIGUREFIELDS_H
#define FIGUREFIELDS_H
#include <iostream>

class FigureFields {
    public:
        static int menu();

    private:
        static int rectangleField();
        static int triangleField();
        static int circleField();
        static int trapezeField();
        static double getValue(std::string nameOfValue);
};

#endif //FIGUREFIELDS_H
