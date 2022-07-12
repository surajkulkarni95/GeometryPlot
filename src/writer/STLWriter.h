#pragma once
#include "shared_EXPORTS.h"

#include "IWriter.h"
#include "Point.h"
#include "Triangle.h"

#include <string>
#include <vector>
#include <sstream>
#include <memory>

#include "poly2tri.h"

namespace geom
{

class SHARED_EXPORT STLWriter: public IWriter
{
public:
	STLWriter(const std::string& fileName, const std::vector<p2t::Triangle*>& triangles, const std::string& solidName = "Solid1");
	void write() override;

private:
	std::ostringstream output_;
	std::string file_;
	std::string solidName_;

	const std::vector<p2t::Triangle*>& triangles_;
};

}