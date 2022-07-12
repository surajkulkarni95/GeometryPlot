#include "ClosedShape.h"
#include "Triangulation.h"

#include "poly2tri.h"

geom::ClosedShape::ClosedShape(const std::vector<Point>& points):
	SimpleShape(points)
{
}

void geom::ClosedShape::tessellate()
{
	std::vector<p2t::Point*> points;
	for (int i = 0; i < points_.size(); ++i)
		points.push_back(reinterpret_cast<p2t::Point*>(&points_[i]));

	//for (int i = 0; i < points.size(); ++i)
	//	points[i]->edge_list.shrink_to_fit();
	
	p2t::CDT cdt(points);
	cdt.Triangulate();

	triangles_ = cdt.GetTriangles();
}

void geom::ClosedShape::writeSTL(const std::string& fileName, const std::string& solidName)
{
	STLWriter_ = std::make_unique<STLWriter>(fileName, triangles_, solidName);
	STLWriter_->write();
}
