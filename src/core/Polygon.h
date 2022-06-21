#pragma once

#include "IShape.h"
#include "Point.h"
#include "TextWriter.h"

#include <vector>
#include <memory>

class Polygon: public IShape
{
public:
    Polygon(const std::vector<Point>& points);

    Polygon(const Point& center, int numberOfSides, double side, double angleWrtXAxis = 0.);
    
    virtual ~Polygon() = default;

    void writeParametric(const std::string& fileName);

    void writeText(const std::string& fileName);

    void scale(double scalingFactor);

    void rotate(double angleInRadians, const Point& centreOfRotation);

private:
    std::vector<Point> points_;
    Point center_;

    std::shared_ptr<TextWriter> textWriter_;

    int n_;
};

