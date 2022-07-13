#include "ClosedShape.h"
#include "Triangulation.h"

#include "poly2tri.h"

geom::ClosedShape::ClosedShape(const std::vector<p2t::Point*>& points):
	SimpleShape(points)
{
}

void geom::ClosedShape::tessellate()
{
	p2t::CDT cdt(points_);
	cdt.Triangulate();

	triangles_ = cdt.GetTriangles();
}

void geom::ClosedShape::writeSTL(const std::string& fileName, const std::string& solidName)
{
	p2t::CDT cdt(points_);
	cdt.Triangulate();

	triangles_ = cdt.GetTriangles();

	STLWriter_ = std::make_unique<STLWriter>(fileName, triangles_, solidName);
	STLWriter_->write();
}
