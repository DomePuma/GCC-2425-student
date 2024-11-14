#ifndef _COLOREDPOINT_HPP_
#define _COLOREDPOINT_HPP_

#include "Point2D.hpp"

class ColoredPoint : public Point2D
{
    public :
        ColoredPoint();
        ColoredPoint(float x, float y, float color = 0);
        ColoredPoint(const Point2D &point2D);
        ColoredPoint(const ColoredPoint &coloredPoint);
        ~ColoredPoint() = default;

        float DistanceOrigin() const override;
        std::string ToString() const override;
        
        void SetColor(float color);
        float GetColor();
        
    private :
        float _color;
};

#endif //_COLOREDPOINT_HPP_