#pragma once

#include "shared_EXPORTS.h"

#include "SimpleShape.h"
#include "Point.h"

namespace geom
{

class SHARED_EXPORT Spline: public SimpleShape
{
public:
	Spline(const std::vector<p2t::Point*>& points);

	void writeParametric(const std::string& fileName) override;

	void writeText(const std::string& fileName) override;

private:
	std::vector<double> parameters_;
	int order_;
};

}
