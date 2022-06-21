#pragma once

#include "IShape.h"
#include "Point.h"

#include "ParametricWriter.h"
#include "TextWriter.h"

#include <memory>
#include <vector>

class Circle: public IShape
{
public:
    Circle(const Point& center, double radius, int divisions = 8);

    virtual ~Circle() = default;

    void writeParametric(const std::string& fileName) override;

    void writeText(const std::string& fileName) override;

    void scale(double scalingFactor) override;

    void rotate(double angleInRadians, const Point& centreOfRotation) override;

private:
    Point center_;
    double radius_;

    int divisions_;
    std::vector<Point> points_;

    std::shared_ptr<ParametricWriter> parametricWriter_;
    std::shared_ptr<TextWriter> textWriter_;
};