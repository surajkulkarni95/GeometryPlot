#include "Line.h"
#include "Circle.h"
#include "Point.h"
#include "Polygon.h"

#include <cmath>

int main(int argc, char* argv[])
{
    Point P1(1, 1);
    Point P2(0, 0);
    
    Point P3(0, 0);

    Line line(P1, P2, 100);
    line.writeParametric("LineParameter.txt");
    line.writeText("LineText.txt");

    line.rotate(M_PI/2, P3);
    line.writeText("RotatedLine.txt");

    Point O(0, 0);

    Circle circle(O, 5, 100);
    circle.writeParametric("CircleParameter.txt");
    circle.writeText("CircleText.txt");

    Polygon hexagon(O, 6, 2.5, M_PI/6);
    hexagon.writeText("HexagonText.txt");

    return 0;
}