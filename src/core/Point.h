#pragma once

#include <ostream>
#include <sstream>

#include "shared_EXPORTS.h"

struct SHARED_EXPORT Point
{
    double x;
    double y;

    Point();
    Point(double X, double Y);

    Point operator+(const Point& P);
    Point operator-(const Point& P);
};

SHARED_EXPORT Point operator*(double scalar, const Point& point);

SHARED_EXPORT Point operator*(const Point& point, double scalar);