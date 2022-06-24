#pragma once

#include "SimpleShape.h"
#include "Point.h"

#include "ParametricWriter.h"
#include "TextWriter.h"
#include "shared_EXPORTS.h"

#include <memory>
#include <vector>

class SHARED_EXPORT Line: public SimpleShape
{
public:
    Line(const Point& P1, const Point& P2, int divisions = 1);

    virtual ~Line();

    void writeParametric(const std::string& fileName) override;

    void writeText(const std::string& fileName) override;

    double slope() const;

    double intercept() const;

private:
    Point P2_;
    Point P1_;

    std::shared_ptr<ParametricWriter> parametricWriter_;
    std::shared_ptr<TextWriter> textWriter_;

    int divisions_;
};