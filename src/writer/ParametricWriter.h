#pragma once

#include "IWriter.h"

#include <string>
#include <sstream>

class ParametricWriter: public IWriter
{
public:
    ParametricWriter(const std::string& fileName);

    template<typename T>
    void addParameter(const std::string& name, const T& parameter);

    void write() override;

private:
    std::ostringstream output_;
    std::string file_;
};

template<typename T>
void ParametricWriter::addParameter(const std::string& name, const T& parameter)
{
    output_ << name << " = " << parameter << std::endl;
}