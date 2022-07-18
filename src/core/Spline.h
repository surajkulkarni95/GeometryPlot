#pragma once

#include "shared_EXPORTS.h"

#include "SimpleShape.h"
#include "Point.h"
#include "ParametricWriter.h"
#include "TextWriter.h"
#include "splineInternal.h"

#include <memory>

namespace geom
{

struct SHARED_EXPORT SplineBoundary
{
	tk::spline::bd_type boundaryType;
	double value;
};

class SHARED_EXPORT Spline: public SimpleShape
{
public:
	Spline(const std::vector<p2t::Point>& points, ::tk::spline::spline_type splineType,
		const SplineBoundary& leftBoundary, const SplineBoundary& rightBoundary, int divisions = 20, bool make_monotonic = false);

	void setBoundary(tk::spline::bd_type left, double left_value,
		tk::spline::bd_type right, double right_value);

	void writeParametric(const std::string& fileName) override;

	void writeText(const std::string& fileName) override;

private:
	struct Bounds
	{
		Bounds(double minVal, double maxVal) :
			min(minVal), max(maxVal)
		{
		}
		
		double min, max;
	};

	Bounds bounds();

private:
	int order_;
	int divisions_;

	std::vector<p2t::Point> initialPoints_;

	tk::spline spline_;

	std::shared_ptr<ParametricWriter> parametricWriter_;
	std::shared_ptr<TextWriter> textWriter_;
};

}
