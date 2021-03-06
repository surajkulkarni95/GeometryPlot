#pragma once

#include "ClosedShape.h"
#include "Point.h"

#include "ParametricWriter.h"
#include "TextWriter.h"

#include "shared_EXPORTS.h"

#include <memory>
#include <vector>

namespace geom
{

class SHARED_EXPORT Circle: public ClosedShape
{
public:
    Circle(const p2t::Point& center, double radius, int divisions = 8);

    virtual ~Circle() = default;

    void writeParametric(const std::string& fileName) override;

    void writeText(const std::string& fileName) override;

private:
    p2t::Point center_;
    double radius_;

    int divisions_;

    std::shared_ptr<ParametricWriter> parametricWriter_;
    std::shared_ptr<TextWriter> textWriter_;
};

}
