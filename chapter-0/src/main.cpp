#include <iostream>
#include <vector>

#include "Point2D.hpp"
#include "WeightedPoint.hpp"
#include "ColoredPoint.hpp"

void DisplayPoint2D(const Point2D& point2D) 
{
    std::cout << point2D.ToString() << std::endl;
}

void DisplayAllPoints(const std::vector<Point2D*>& pointsList)
{
    for(int i = 0; i < (int)pointsList.size(); i++)
    {
        std::cout << pointsList[i] -> ToString() << std::endl;
    }
}

void TranslateAll(Point2D** pointList, int size, float x, float y)
{
    for(int i = 0; i < size; i++)
    {
        pointList[i] -> Translate(x, y);
    }
}

int main()
{
    ColoredPoint weightedPoint1 = ColoredPoint(2, 2, 255);
    ColoredPoint weightedPoint2 = ColoredPoint(2, 2, 255);

    //Si j'avais fait les opérateurs je les aurait mis ici mais j'ai rien compris comment faire

    return 0;
}