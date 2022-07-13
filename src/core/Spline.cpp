#include "Spline.h"

#include <algorithm>
#include <tuple>

geom::Spline::Spline(const std::vector<p2t::Point>& points):
	order_(points.size() - 1)
{
	splineMatrix_ = std::make_unique<SplineMatrix>(points);
	parameters_ = splineMatrix_->solve();
	
}

void geom::Spline::writeParametric(const std::string& fileName)
{
}

void geom::Spline::writeText(const std::string& fileName)
{
}

geom::Spline::Bounds geom::Spline::bounds(const std::vector<p2t::Point>& points)
{
	std::pair<std::vector<p2t::Point>::iterator> iterPair;
	std::tie(minEl, maxEl) = std::minmax_element(begin(points), end(points),
		[](const p2t::Point& p1, const p2t::Point& p2) {
			if (p1.x < p2.x) {
				return true;
			}
			else if (p1.x == p2.x) {
				return p1.y < p2.y;
			}

			return false;
		});

	return Bounds(minEl->x, maxEl->x);
}
