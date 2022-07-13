#include "TextWriter.h"
#include "PrintPoint.h"

#include <fstream>
#include <ostream>

geom::TextWriter::TextWriter(const std::string& fileName, const std::vector<p2t::Point*>& points):
    file_(fileName),
    output_(),
    points_(points)
{}

void geom::TextWriter::write()
{
    std::ofstream of(file_, std::ios::out);

    for(const auto& point: points_)
        output_ << *point << std::endl;

    of << output_.str();
}
