#pragma once

#include "IShape.h"
#include "Point.h"

#include "shared_EXPORTS.h"

#include <vector>

namespace geom
{

class SHARED_EXPORT SimpleShape: public IShape
{
public:
    SimpleShape() = default;
    SimpleShape(const std::vector<p2t::Point*>& points);

    virtual ~SimpleShape();

    virtual void scale(double scalingFactor) override;

    virtual void rotate(double angleInRadians, const p2t::Point& centreOfRotation) override;

protected:
    std::vector<p2t::Point*> points_;
};

}
