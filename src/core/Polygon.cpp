#include "Polygon.h"
#include "Constants.h"

#include <math.h>


geom::Polygon::Polygon(const std::vector<p2t::Point*>& points):
    ClosedShape(points),
    n_(points.size())
{

}

geom::Polygon::Polygon(const p2t::Point& center, int numberOfSides, double side, double angleWrtXAxis):
    center_(center),
    n_(numberOfSides)
{
    double dTheta = (2*constants::pi)/n_;
    
    double radius = side/(2.*std::sin(dTheta/2.));

    for(int i = 0; i < n_; ++i)
    {
        points_.emplace_back(new p2t::Point(center_.x + radius*std::cos(angleWrtXAxis+i*dTheta),
            center_.y + radius*std::sin(angleWrtXAxis+i*dTheta)));
    }
}

void geom::Polygon::writeParametric(const std::string& fileName)
{
}

void geom::Polygon::writeText(const std::string& fileName)
{
    textWriter_ = std::make_shared<TextWriter>(fileName, points_);

    textWriter_->write();
}
