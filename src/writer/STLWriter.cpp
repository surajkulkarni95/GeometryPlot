#include "STLWriter.h"
#include "PrintPoint.h"

#include <fstream>

#include "poly2tri.h"

using namespace p2t;

geom::STLWriter::STLWriter(const std::string& fileName, const std::vector<p2t::Triangle*>& triangles, const std::string& solidName) :
	file_(fileName),
	triangles_(triangles),
	output_(),
	solidName_(solidName)
{
}

void geom::STLWriter::write()
{
	std::ofstream of(file_, std::ios::out);
	
	output_ << "SOLID " << solidName_ << std::endl;

	for (auto* triangle : triangles_)
	{
		output_ << "FACET NORMAL " << 0. << " " << 0. << " " << 0. << std::endl;
		output_ << "  OUTER LOOP" << std::endl;
		output_ << "	VERTEX " << *(triangle->GetPoint(0)) << std::endl;
		output_ << "	VERTEX " << *(triangle->GetPoint(1)) << std::endl;
		output_ << "	VERTEX " << *(triangle->GetPoint(2)) << std::endl;
		output_ << "  ENDLOOP" << std::endl;
		output_ << "ENDFACET" << std::endl;
	}
	output_ << "ENDSOLID" << std::endl;

	of << output_.str();
}
