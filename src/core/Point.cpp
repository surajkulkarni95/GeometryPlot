#include "Point.h"

Point::Point()
{
}

Point::Point(double X, double Y):
    x(X), y(Y)
{}

Point Point::operator-(const Point& P)
{
    return Point(x-P.x, y-P.y);
}

Point Point::operator+(const Point& P)
{
    return Point(x+P.x, y+P.y);
}

Point operator*(double scalar, const Point& point) {
    return Point(scalar*point.x, scalar*point.y);    
}

Point operator*(const Point& point, double scalar) {
    return scalar*point;    
}
