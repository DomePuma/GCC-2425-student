#include "ColoredPoint.hpp"

ColoredPoint::ColoredPoint()
{
    this->_color = 0;
}

ColoredPoint::ColoredPoint(float x, float y, float color) : Point2D(x, y)
{
    this->_color = color;
}

ColoredPoint::ColoredPoint(const Point2D &point2D) : Point2D(point2D)
{
    this->_color = 0;
}

ColoredPoint::ColoredPoint(const ColoredPoint &coloredPoint) : Point2D(coloredPoint)
{
    this->_color = coloredPoint._color;
}

float ColoredPoint::DistanceOrigin() const
{
    return Point2D::DistanceOrigin();
}

void ColoredPoint::SetColor(float color)
{
    this->_color = color;
}

float ColoredPoint::GetColor()
{
    return this->_color;
}

std::string ColoredPoint::ToString() const
{
    return Point2D::ToString() + " Color : " + std::to_string(this->_color);
}