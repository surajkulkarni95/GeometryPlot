#pragma once

#include "IShape.h"
#include "Point.h"

#include "ParametricWriter.h"
#include "TextWriter.h"

#include <memory>
#include <vector>

class Line: public IShape
{
public:
    Line(const Point& P1, const Point& P2, int divisions = 1);

    virtual ~Line();

    void writeParametric(const std::string& fileName) override;

    void writeText(const std::string& fileName) override;

    void scale(double scalingFactor) override;

    void rotate(double angleInRadians, const Point& centreOfRotation) override;

    double slope() const;

    double intercept() const;

private:
    Point P2_;
    Point P1_;

    std::shared_ptr<ParametricWriter> parametricWriter_;
    std::shared_ptr<TextWriter> textWriter_;

    int divisions_;
    std::vector<Point> points_;
};