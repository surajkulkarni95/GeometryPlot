#pragma once

#include "shared_EXPORTS.h"

#include "SimpleShape.h"
#include "Point.h"
#include "SplineMatrix.h"

#include <memory>

namespace geom
{

class SHARED_EXPORT Spline: public SimpleShape
{
public:
	Spline(const std::vector<p2t::Point>& points);

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

	Bounds bounds(const std::vector<p2t::Point>& points);

private:
	std::vector<double> parameters_;
	int order_;

	std::unique_ptr<SplineMatrix> splineMatrix_;
};

}
