#include <iostream>
#include <cmath>

#include "Point2D.hpp"

void DisplayPoint2D(Point2D &point2D) {
    std::cout << point2D << std::endl;
}

int main()
{
    Point2D p1(2, 2);

    std::cout << p1.Rho() << std::endl;
    std::cout << p1.Theta() * 180 / M_PI << std::endl;

    DisplayPoint2D(p1);

    p1.Rotate(M_PI/4);

    std::cout << p1.Rho() << std::endl;
    std::cout << p1.Theta() * 180 / M_PI << std::endl;

    DisplayPoint2D(p1);

    Point2D p2(4, 3);

    std::cout << p2.allPointNumber << std::endl;
    std::cout << p1.GetNumber() << std::endl;

    return 0;
}