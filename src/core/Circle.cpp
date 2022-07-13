#include "Circle.h"
#include "Point.h"
#include "Constants.h"

#include <vector>
#include <cmath>


geom::Circle::Circle(const p2t::Point& center, double radius, int divisions):
    center_(center),
    radius_(radius),
    divisions_(divisions)
{
    double dTheta = (2*constants::pi)/divisions_;

    for(int i = 0; i < divisions_; ++i)
    {
        points_.emplace_back(new p2t::Point(center_.x + radius_*std::cos(i*dTheta), center_.y + radius_*std::sin(i*dTheta)));
    }
}

void geom::Circle::writeParametric(const std::string& fileName)
{
    if(!parametricWriter_)
        parametricWriter_ = std::make_shared<ParametricWriter>(fileName);

    parametricWriter_->addParameter("CENTER", center_);
    parametricWriter_->addParameter("RADIUS", radius_);

    parametricWriter_->write();
}

void geom::Circle::writeText(const std::string& fileName)
{
    textWriter_ = std::make_shared<TextWriter>(fileName, points_);

    textWriter_->write();
}
