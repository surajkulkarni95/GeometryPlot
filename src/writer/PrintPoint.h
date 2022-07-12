#pragma once

#include "Point.h"
#include "shared_EXPORTS.h"

#include <ostream>
#include <sstream>

#include "poly2tri.h"

namespace geom
{

SHARED_EXPORT std::ostream& operator<<(std::ostream& os, const Point& P);

SHARED_EXPORT std::ostringstream& operator<<(std::ostringstream& oss, const Point& P);

SHARED_EXPORT std::ostream& operator<<(std::ostream& out, const p2t::Point& point);

SHARED_EXPORT std::ostringstream& operator<<(std::ostringstream& oss, const p2t::Point& P);

}

