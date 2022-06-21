#include "Point.h"

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

std::ostream& operator<<(std::ostream& oss, const Point& P)
{
    oss  << P.x << ", " << P.y;
    return oss;
}