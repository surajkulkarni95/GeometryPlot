#pragma once

#include <ostream>

struct Point
{
    double x;
    double y;

    Point() = default;
    Point(double X, double Y);

    Point operator+(const Point& P);
    Point operator-(const Point& P);
};

std::ostream& operator<<(std::ostream& oss, const Point& P);

Point operator*(double scalar, const Point& point);

Point operator*(const Point& point, double scalar);