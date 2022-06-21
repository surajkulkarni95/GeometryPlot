#pragma once

#include "IShape.h"
#include "Point.h"

#include <vector>

class SimpleShape: public IShape
{
public:
    SimpleShape() = default;
    SimpleShape(const std::vector<Point>& points);

    virtual ~SimpleShape() = default;


    virtual void scale(double scalingFactor);

    virtual void rotate(double angleInRadians, const Point& centreOfRotation);

protected:
    std::vector<Point> points_;
};