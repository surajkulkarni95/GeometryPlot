#pragma once

#include "IWriter.h"
#include "Point.h"

#include <string>
#include <sstream>
#include <vector>

class TextWriter: public IWriter
{
public:
    TextWriter(const std::string& fileName, const std::vector<Point>& points);

    void write() override;

private:
    std::ostringstream output_;
    std::string file_;

    const std::vector<Point>& points_;
};