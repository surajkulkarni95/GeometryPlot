#include "Polygon.h"

#include <cmath>

Polygon::Polygon(const std::vector<Point>& points):
    SimpleShape(points),
    n_(points.size())
{
}

Polygon::Polygon(const Point& center, int numberOfSides, double side, double angleWrtXAxis):
    center_(center),
    n_(numberOfSides)
{
    double dTheta = 2*M_PI/n_;
    
    double radius = side/(2.*std::sin(dTheta/2.));

    for(int i = 0; i < n_; ++i)
    {
        points_.emplace_back(Point(center_.x + radius*std::cos(angleWrtXAxis+i*dTheta),
            center_.y + radius*std::sin(angleWrtXAxis+i*dTheta)));
    }
}

void Polygon::writeParametric(const std::string& fileName)
{
}

void Polygon::writeText(const std::string& fileName)
{
    textWriter_ = std::make_shared<TextWriter>(fileName, points_);

    textWriter_->write();
}