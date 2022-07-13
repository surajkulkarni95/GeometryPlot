#include "Spline.h"


geom::Spline::Spline(const std::vector<p2t::Point*>& points):
	SimpleShape(points),
	order_(points.size() - 1)
{
	parameters_.reserve(order_);
}

void geom::Spline::writeParametric(const std::string& fileName)
{
}

void geom::Spline::writeText(const std::string& fileName)
{
}
