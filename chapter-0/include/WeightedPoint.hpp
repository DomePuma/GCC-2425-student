#ifndef _WEIGHTEDPOINT_HPP_
#define _WEIGHTEDPOINT_HPP_

#include "Point2D.hpp"

class WeightedPoint : public Point2D
{
    public :
        WeightedPoint();
        WeightedPoint(float x, float y, float weight = 0);
        WeightedPoint(const Point2D &Point2D);
        WeightedPoint(const WeightedPoint &weightedPoint);
        ~WeightedPoint() = default;

        float DistanceOrigin() const override;
        void SetWeight(float weight);
        float GetWeight();

        std::string ToString() const override;

    private :
        float _weight;
};

#endif //_WEIGHTEDPOINT_HPP_