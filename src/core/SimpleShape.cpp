#include "SimpleShape.h"
#include "poly2tri.h"

#include <cmath>


geom::SimpleShape::SimpleShape(const std::vector<p2t::Point*>& points):
    points_(points)
{    
}

geom::SimpleShape::~SimpleShape()
{
    for (int i = 0; i < points_.size(); ++i)
        delete points_[i];
}

void geom::SimpleShape::scale(double scalingFactor) {
    for(int i = 0; i < points_.size(); ++i)
    {
        *points_[i] = scalingFactor*(*points_[i]);
    }
}

void geom::SimpleShape::rotate(double angleInRadians, const p2t::Point& centreOfRotation) {
    for(int i = 0; i < points_.size(); ++i)
    {
        *points_[i] = *points_[i] - centreOfRotation;
        double x = points_[i]->x;
        double y = points_[i]->y;

        points_[i]->x = x*std::cos(angleInRadians) - y*std::sin(angleInRadians);
        points_[i]->y = x*std::sin(angleInRadians) + y*std::cos(angleInRadians);

        *points_[i] = *points_[i] + centreOfRotation;
    }
}
