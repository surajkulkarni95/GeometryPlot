#include "TextWriter.h"

#include <fstream>
#include <ostream>

TextWriter::TextWriter(const std::string& fileName, const std::vector<Point>& points):
    file_(fileName),
    output_(),
    points_(points)
{}

void TextWriter::write()
{
    std::ofstream of(file_, std::ios::out);

    for(const auto& point: points_)
        output_ << point << std::endl;

    of << output_.str();
}