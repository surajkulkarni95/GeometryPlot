#pragma once

#include "Point.h"
#include "shared_EXPORTS.h"

namespace geom
{

struct SHARED_EXPORT Triangle
{
	Triangle(const Point& p1, const Point& p2, const Point& p3, const Point& n = Point()) :
		V1(p1), V2(p2), V3(p3), N(n)
	{}

	bool pointInTriangle(const Point& pt);

	Point V1, V2, V3, N;

private:
	double sign(Point p1, Point p2, Point p3);
};

}
