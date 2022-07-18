#pragma once

#include "IWriter.h"
#include "Point.h"
#include "PrintPoint.h"

#include "shared_EXPORTS.h"

#include <string>
#include <sstream>

namespace geom
{

class SHARED_EXPORT ParametricWriter: public IWriter
{
public:
    ParametricWriter(const std::string& fileName);

    template<typename T>
    void addParameter(const std::string& name, const T& parameter)
    {
        output_ << name << " = " << parameter << std::endl;
    }

    void write() override;

private:
    std::ostringstream output_;
    std::string file_;
};

}
