#include "ParametricWriter.h"

#include <fstream>
#include <ostream>

ParametricWriter::ParametricWriter(const std::string& fileName):
    file_(fileName),
    output_()
{}

void ParametricWriter::write()
{
    std::ofstream of(file_, std::ios::out);
    of << output_.str();
}