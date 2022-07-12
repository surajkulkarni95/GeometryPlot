#pragma once

#include "SimpleShape.h"
#include "shared_EXPORTS.h"

#include "Triangle.h"
#include "STLWriter.h"

#include <vector>
#include <memory>

namespace geom
{

class SHARED_EXPORT ClosedShape: public SimpleShape
{
public:
	ClosedShape() = default;
	ClosedShape(const std::vector<Point>& points);

	virtual ~ClosedShape() = default;

	virtual void tessellate();

	virtual void writeSTL(const std::string& fileName, const std::string& solidName = "Solid1");

protected:
	std::vector<p2t::Triangle*> triangles_;

private:
	std::unique_ptr<STLWriter> STLWriter_;
};

}