#include "ClosedShape.h"
#include "Triangulation.h"

ClosedShape::ClosedShape(const std::vector<Point>& points):
	SimpleShape(points)
{
}

void ClosedShape::tessellate()
{
	triangles_ = triangulate(points_);
}

void ClosedShape::writeSTL(const std::string& fileName, const std::string& solidName)
{
	STLWriter_ = std::make_unique<STLWriter>(fileName, triangles_, solidName);
	STLWriter_->write();
}