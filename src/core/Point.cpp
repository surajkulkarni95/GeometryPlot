#include "Point.h"

geom::Point::Point()
{
}

geom::Point::Point(double X, double Y):
    x(X), y(Y)
{}

geom::Point geom::Point::operator-(const Point& P)
{
    return Point(x-P.x, y-P.y);
}

geom::Point::operator p2t::Point()
{
    p2t::Point P;
    P.set(x, y);
    return P;
}

geom::Point geom::Point::operator+(const Point& P)
{
    return Point(x+P.x, y+P.y);
}

geom::Point geom::operator*(double scalar, const geom::Point& point) {
    return Point(scalar*point.x, scalar*point.y);    
}

geom::Point geom::operator*(const geom::Point& point, double scalar) {
    return scalar*point;    
}
