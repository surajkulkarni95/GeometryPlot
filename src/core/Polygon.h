#pragma once

#include "SimpleShape.h"
#include "Point.h"
#include "TextWriter.h"

#include <vector>
#include <memory>

class Polygon: public SimpleShape
{
public:
    Polygon(const std::vector<Point>& points);

    Polygon(const Point& center, int numberOfSides, double side, double angleWrtXAxis = 0.);
    
    virtual ~Polygon() = default;

    void writeParametric(const std::string& fileName);

    void writeText(const std::string& fileName);

private:
    Point center_;
    int n_;

    std::shared_ptr<TextWriter> textWriter_;
};

