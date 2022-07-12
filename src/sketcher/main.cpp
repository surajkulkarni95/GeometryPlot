#include "Line.h"
#include "Circle.h"
#include "Point.h"
#include "Polygon.h"
#include "Constants.h"

#include <cmath>

using namespace geom;

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
    circle.tessellate();
    circle.writeSTL("circle.stl", "circle");

    Polygon hexagon(O, 12, 2.5, constants::pi/6);
    hexagon.writeText("HexagonText.txt");
    hexagon.tessellate();
    hexagon.writeSTL("hexagon.stl", "hexagon");
    return 0;
}