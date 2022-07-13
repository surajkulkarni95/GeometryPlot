#pragma once

#include "ClosedShape.h"
#include "Point.h"
#include "TextWriter.h"

#include "shared_EXPORTS.h"

#include <vector>
#include <memory>

namespace geom
{

class SHARED_EXPORT Polygon: public ClosedShape
{
public:
    Polygon(const std::vector<p2t::Point*>& points);

    Polygon(const p2t::Point& center, int numberOfSides, double side, double angleWrtXAxis = 0.);
    
    virtual ~Polygon() = default;

    void writeParametric(const std::string& fileName) override;

    void writeText(const std::string& fileName) override;

private:
    p2t::Point center_;
    int n_;

    std::shared_ptr<TextWriter> textWriter_;
};

}

