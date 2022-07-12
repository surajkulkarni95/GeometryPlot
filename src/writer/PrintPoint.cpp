#include "PrintPoint.h"

std::ostream& geom::operator<<(std::ostream& os, const Point& P)
{
    os << P.x << " " << P.y << " " << 0.;
    return os;
}

std::ostringstream& geom::operator<<(std::ostringstream& oss, const Point& P)
{
    oss << P.x << " " << P.y << " " << 0.;
    return oss;
}

std::ostream& geom::operator<<(std::ostream& out, const p2t::Point& point) 
{
    return out << point.x << "," << point.y;
}

std::ostringstream& geom::operator<<(std::ostringstream& oss, const p2t::Point& P)
{
    oss << P.x << " " << P.y << " " << 0.;
    return oss;
}