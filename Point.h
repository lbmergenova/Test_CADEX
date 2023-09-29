#pragma once

#include <iostream>

class Point
{
public:
    float _x;
    float _y;
    float _z;
    Point(float x, float y, float z);
    ~Point();
};

std::ostream &operator<<(std::ostream &os, const Point &p);