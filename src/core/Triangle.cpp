#include "Triangle.h"


double Triangle::sign(Point p1, Point p2, Point p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool Triangle::pointInTriangle(const Point& pt)
{
    double d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(pt, V1, V2);
    d2 = sign(pt, V2, V3);
    d3 = sign(pt, V3, V1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}
