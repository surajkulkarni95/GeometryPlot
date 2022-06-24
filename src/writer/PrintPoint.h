#pragma once

#include "Point.h"
#include "shared_EXPORTS.h"

#include <ostream>
#include <sstream>

SHARED_EXPORT std::ostream& operator<<(std::ostream& os, const Point& P);

SHARED_EXPORT std::ostringstream& operator<<(std::ostringstream& oss, const Point& P);