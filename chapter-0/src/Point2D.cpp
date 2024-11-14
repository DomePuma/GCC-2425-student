#include "Point2D.hpp"

int Point2D::allPointNumber = 0;

Point2D::Point2D() 
{
    this->_x = 0;
    this->_y = 0;

    this->allPointNumber++;
    this->pointNumber = allPointNumber;
}

Point2D::Point2D(float x, float y)
{
    this->_x = x;
    this->_y = y;

    this->allPointNumber++;
    this->pointNumber = allPointNumber;
}

Point2D::Point2D(const Point2D &point2D)
{
    this->_x = point2D._x;
    this->_y = point2D._y;

    this->allPointNumber++;
    this->pointNumber = allPointNumber;
}

Point2D::~Point2D() 
{
    this->allPointNumber--;
}

void Point2D::Translate(float x, float y)
{
    this->_x += x;
    this->_y += y;
}

float Point2D::DistanceOrigin() const
{
    return std::sqrt(std::pow((0 - this->_x), 2) + std::pow((0 - this -> _y), 2));
}

int Point2D::GetNumber() {
    return this->pointNumber;
}

std::string Point2D::ToString() const 
{
    return "x : " + std::to_string(this->_x) + " y : " + std::to_string(this->_y);
}

std::ostream& operator<<(std::ostream& os, const Point2D& point2D) {
    os << "x : " << point2D._x << " y : " << point2D._y;
    return os;
}