#include "Line.h"
#include "Circle.h"
#include "Point.h"
#include "Polygon.h"

#include <cmath>

int main(int argc, char* argv[])
{
    Point P1(2, 1);
    Point P2(20, 33);
    
    Line line(P1, P2, 100);
    line.writeParametric("LineParameter.txt");
    line.writeText("LineText.txt");

    Point O(0, 0);

    Circle circle(O, 5, 100);
    circle.writeParametric("CircleParameter.txt");
    circle.writeText("CircleText.txt");

    Polygon hexagon(O, 6, 2.5, M_PI/6);
    hexagon.writeText("HexagonText.txt");

    return 0;
}