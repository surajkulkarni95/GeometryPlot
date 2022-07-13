#pragma once

#include "SimpleShape.h"
#include "shared_EXPORTS.h"

#include "Triangle.h"
#include "STLWriter.h"
#include "poly2tri.h"

#include <vector>
#include <memory>

namespace geom
{

class SHARED_EXPORT ClosedShape: public SimpleShape
{
public:
	ClosedShape() = default;
	ClosedShape(const std::vector<p2t::Point*>& points);

	virtual ~ClosedShape() = default;

	virtual void writeSTL(const std::string& fileName, const std::string& solidName = "Solid1");

private:
	virtual void tessellate();

protected:
	std::vector<p2t::Triangle*> triangles_;

private:
	std::unique_ptr<STLWriter> STLWriter_;
};

}