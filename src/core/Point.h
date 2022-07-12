#pragma once

#include "shared_EXPORTS.h"

#include "poly2tri.h"

namespace geom
{

struct SHARED_EXPORT Point
{
    double x;
    double y;

    Point();
    Point(double X, double Y);

    Point operator+(const Point& P);
    Point operator-(const Point& P);

    operator p2t::Point();

};

SHARED_EXPORT Point operator*(double scalar, const Point& point);

SHARED_EXPORT Point operator*(const Point& point, double scalar);

}