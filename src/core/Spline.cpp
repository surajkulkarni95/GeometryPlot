#include "Spline.h"

#include <algorithm>
#include <cmath>

geom::Spline::Spline(const std::vector<p2t::Point>& points, ::tk::spline::spline_type splineType, const SplineBoundary& leftBoundary, const SplineBoundary& rightBoundary, int divisions, bool makeMonotonic):
	order_(points.size() - 1),
	divisions_(divisions),
	initialPoints_(points)
{
	std::vector<double> xVec, yVec;

	for (const auto& p : points)
	{
		xVec.push_back(p.x);
		yVec.push_back(p.y);
	}

	setBoundary(leftBoundary.boundaryType, leftBoundary.value, rightBoundary.boundaryType, rightBoundary.value);
	spline_.set_points(xVec, yVec, splineType);
	if (makeMonotonic)
		spline_.make_monotonic();

	Bounds minMax = bounds();
	double dx = (minMax.max - minMax.min) / divisions_;
	for (int i = 0; i < divisions_ + 1; ++i)
	{
		double x = minMax.min + i * dx;
		points_.emplace_back(new p2t::Point(x, spline_(x)));
	}
}

void geom::Spline::setBoundary(tk::spline::bd_type left, double leftValue, tk::spline::bd_type right, double rightValue)
{
	spline_.set_boundary(left, leftValue, right, rightValue);
}

void geom::Spline::writeParametric(const std::string& fileName)
{
	if (!parametricWriter_)
		parametricWriter_ = std::make_shared<ParametricWriter>(fileName);

	for (const auto& p : initialPoints_)
		parametricWriter_->addParameter("POINT", p);

	parametricWriter_->write();
}

void geom::Spline::writeText(const std::string& fileName)
{
	textWriter_ = std::make_shared<TextWriter>(fileName, points_);

	textWriter_->write();
}

geom::Spline::Bounds geom::Spline::bounds()
{
	auto cmp = [](const p2t::Point& p1, const p2t::Point& p2) {
		if (p1.x < p2.x) {
			return true;
		}
		else if (p1.x == p2.x) {
			return p1.y < p2.y;
		}

		return false;
	};

	auto min = min_element(initialPoints_.begin(), initialPoints_.end(), cmp);
	auto max = max_element(initialPoints_.begin(), initialPoints_.end(), cmp);

	return Bounds(min->x, max->x);
}
