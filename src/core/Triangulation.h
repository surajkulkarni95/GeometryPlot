//This file is part of Ear clipping triangulation(GNU GPL) - https://www.youtube.com/user/Muzkaw).
#pragma once

#include <iostream> 
#include <cmath>
#include <vector>

#include "Point.h"
#include "Triangle.h"
#include "shared_EXPORTS.h"

using namespace std;

namespace geom
{

typedef Point Vector2f;

SHARED_EXPORT double determinant(Vector2f u, Vector2f v);
SHARED_EXPORT double Distance(Vector2f const& v1, Vector2f const& v2);
SHARED_EXPORT bool collisionTrianglePoint(Vector2f a, Vector2f b, Vector2f c, Vector2f point);
SHARED_EXPORT vector<Triangle> triangulate(vector<Vector2f> points);

}