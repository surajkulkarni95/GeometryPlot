#include "Line.h"

#include <memory>
#include <vector>
#include <cmath>


geom::Line::Line(const p2t::Point& P1, const p2t::Point& P2, int divisions):
    P1_(P1),
    P2_(P2),
    divisions_(divisions)
{
    double dX = (P2_.x - P1_.x)/divisions_;
    double dY = (P2_.y - P1_.y)/divisions_;

    for(int i = 0; i < divisions_+1; ++i)
    {
        points_.emplace_back(new p2t::Point(P1_.x + i*dX, P1_.y + i*dY));
    }
}

geom::Line::~Line()
{}

void geom::Line::writeParametric(const std::string& fileName)
{
    if(!parametricWriter_)
        parametricWriter_ = std::make_shared<ParametricWriter>(fileName);
    
    double m = slope();
    double c = intercept();

    parametricWriter_->addParameter("SLOPE", m);
    parametricWriter_->addParameter("INTERCEPT", c);
    parametricWriter_->write();
}

void geom::Line::writeText(const std::string& fileName)
{
    textWriter_ = std::make_shared<TextWriter>(fileName, points_);

    textWriter_->write();
}

double geom::Line::slope() const
{
    return (P2_.y - P1_.y)/(P2_.x - P1_.x + 1.e-15);
}

double geom::Line::intercept() const
{
    double m = slope();
    return P1_.y - m*P1_.x;
}
