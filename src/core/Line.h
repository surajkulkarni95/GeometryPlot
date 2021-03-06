#pragma once

#include "SimpleShape.h"
#include "Point.h"

#include "ParametricWriter.h"
#include "TextWriter.h"
#include "shared_EXPORTS.h"

#include <memory>
#include <vector>

namespace geom
{

class SHARED_EXPORT Line: public SimpleShape
{
public:
    Line(const p2t::Point& P1, const p2t::Point& P2, int divisions = 1);

    virtual ~Line();

    void writeParametric(const std::string& fileName);

    void writeText(const std::string& fileName);

    double slope() const;

    double intercept() const;

private:
    p2t::Point P2_;
    p2t::Point P1_;

    std::shared_ptr<geom::ParametricWriter> parametricWriter_;
    std::shared_ptr<geom::TextWriter> textWriter_;

    int divisions_;
};

}
