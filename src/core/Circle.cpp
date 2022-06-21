#include "Circle.h"
#include "Point.h"

#include <vector>
#include <cmath>

Circle::Circle(const Point& center, double radius, int divisions):
    center_(center),
    radius_(radius),
    divisions_(divisions)
{
    double dTheta = (2*M_PI)/divisions_;

    for(int i = 0; i < divisions_; ++i)
    {
        points_.emplace_back(Point(center_.x + radius_*std::cos(i*dTheta), center_.y + radius_*std::sin(i*dTheta)));
    }
}

void Circle::writeParametric(const std::string& fileName)
{
    if(!parametricWriter_)
        parametricWriter_ = std::make_shared<ParametricWriter>(fileName);

    parametricWriter_->addParameter("CENTER", center_);
    parametricWriter_->addParameter("RADIUS", radius_);

    parametricWriter_->write();
}

void Circle::writeText(const std::string& fileName)
{
    if(!textWriter_)
        textWriter_ = std::make_shared<TextWriter>(fileName, points_);

    textWriter_->write();
}

void Circle::scale(double scalingFactor)
{
}

void Circle::rotate(double angleInRadians, const Point& centerOfRotation)
{
}