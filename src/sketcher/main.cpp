#include "Line.h"
#include "Circle.h"
#include "Point.h"
#include "Polygon.h"
#include "Constants.h"
#include "poly2tri.h"
#include "Spline.h"

#include <cmath>

using p2t::Point;
using geom::Line;
using geom::Circle;
using geom::Polygon;
using geom::Spline;
using geom::SplineBoundary;

int main(int argc, char* argv[])
{
    Point P1(1, 1);
    Point P2(0, 0);
    
    Point P3(0, 0);

    Line line(P1, P2, 100);
    line.writeParametric("LineParameter.txt");
    line.writeText("LineText.txt");

    line.rotate(constants::pi/2, P3);
    line.writeText("RotatedLine.txt");

    Point O(0, 0);

    Circle circle(O, 5, 100);
    circle.writeParametric("CircleParameter.txt");
    circle.writeText("CircleText.txt");
    circle.writeSTL("circle.stl", "circle");

    Polygon hexagon(O, 12, 2.5, constants::pi/6);
    hexagon.writeText("HexagonText.txt");
    hexagon.writeSTL("hexagon.stl", "hexagon");

    std::vector<Point> pts;
    pts.push_back(Point(0, 0));
    pts.push_back(Point(0.25, 1));
    pts.push_back(Point(1, 2));

    SplineBoundary left;
    left.boundaryType = tk::spline::second_deriv;
    left.value = 1.;
    
    SplineBoundary right = left;

    Spline spline(pts, tk::spline::cspline, left, right);
    spline.writeParametric("SplineParameter.txt");
    spline.writeText("SplineText.txt");

    return 0;
}