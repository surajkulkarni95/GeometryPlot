#include "STLWriter.h"
#include "PrintPoint.h"

#include <fstream>

STLWriter::STLWriter(const std::string& fileName, const std::vector<Triangle>& triangles, const std::string& solidName) :
	file_(fileName),
	triangles_(triangles),
	output_(),
	solidName_(solidName)
{
}

void STLWriter::write()
{
	std::ofstream of(file_, std::ios::out);
	
	output_ << "SOLID " << solidName_ << std::endl;

	for (const auto& triangle : triangles_)
	{
		output_ << "  FACET NORMAL " << triangle.N << std::endl;
		output_ << "    OUTER LOOP" << std::endl;
		output_ << "	  VERTEX " << triangle.V1 << std::endl;
		output_ << "	  VERTEX " << triangle.V2 << std::endl;
		output_ << "	  VERTEX " << triangle.V3 << std::endl;
		output_ << "    ENDLOOP" << std::endl;
		output_ << "  ENDFACET" << std::endl;
	}
	output_ << "ENDSOLID" << std::endl;

	of << output_.str();
}
