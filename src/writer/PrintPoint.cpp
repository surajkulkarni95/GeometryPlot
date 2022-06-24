#include "PrintPoint.h"

std::ostream& operator<<(std::ostream& os, const Point& P)
{
    os << P.x << " " << P.y << " " << 0.;
    return os;
}

std::ostringstream& operator<<(std::ostringstream& oss, const Point& P)
{
    oss << P.x << " " << P.y << " " << 0.;
    return oss;
}
