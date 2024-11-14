#include "WeightedPoint.hpp"

WeightedPoint::WeightedPoint()
{
    this->_weight = 0;
}

WeightedPoint::WeightedPoint(float x, float y, float weight) : Point2D(x,y)
{
    this -> _weight = weight;
}

WeightedPoint::WeightedPoint(const Point2D &point2D) : Point2D(point2D)
{
    this->_weight = 0;
}

WeightedPoint::WeightedPoint(const WeightedPoint &weightedPoint) : Point2D(weightedPoint)
{
    this->_weight = weightedPoint._weight;
}

float WeightedPoint::DistanceOrigin() const
{
    return Point2D::DistanceOrigin();
}

void WeightedPoint::SetWeight(float weight)
{
    this->_weight = weight;
}

float WeightedPoint::GetWeight()
{
    return this->_weight;
}

std::string WeightedPoint::ToString() const
{
    return Point2D::ToString() + " Weight : " + std::to_string(this->_weight);
}