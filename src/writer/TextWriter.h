#pragma once

#include "IWriter.h"
#include "Point.h"
#include "shared_EXPORTS.h"
#include "poly2tri.h"

#include <string>
#include <sstream>
#include <vector>

namespace geom
{

class SHARED_EXPORT TextWriter: public IWriter
{
public:
    TextWriter(const std::string& fileName, const std::vector<p2t::Point*>& points);

    void write() override;

private:
    std::ostringstream output_;
    std::string file_;

    const std::vector<p2t::Point*>& points_;
};

}