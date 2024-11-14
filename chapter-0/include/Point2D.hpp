#ifndef _CHAPTER_O_POINT_2D_HPP_
#define _CHAPTER_O_POINT_2D_HPP_

#include <cmath>
#include <ostream>
#include <string>

class Point2D 
{
    public:
        Point2D();
        Point2D(float x, float y);
        Point2D(const Point2D &point2D);
        ~Point2D();

        void Translate(float x, float y);
        int GetNumber();

        virtual float DistanceOrigin() const = 0; 

        virtual std::string ToString() const = 0;
        friend std::ostream& operator<<(std::ostream& os, const Point2D& point2D);

        static int allPointNumber;
    
    private:
        float _x;
        float _y;

        int pointNumber;
};

#endif // _POINT_2D_HPP_