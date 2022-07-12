#pragma once

#include "Point.h"

#include "shared_EXPORTS.h"

#include <string>

namespace geom
{

class SHARED_EXPORT IShape
{
public:
    virtual void writeParametric(const std::string& fileName) = 0;

    virtual void writeText(const std::string& fileName) = 0;

    virtual void scale(double scalingFactor) = 0;

    virtual void rotate(double angleInRadians, const Point& centreOfRotation) = 0;
};

}
