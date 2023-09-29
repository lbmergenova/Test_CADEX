#pragma once

#include "ICurve.h"

class Circle : public ICurve
{
private:
    float _r;
public:
    Circle(float r);
    virtual ~Circle();

    float GetRadius();

    Point Coordinat(float t);
    Point Derivative(float t);

    friend bool operator< (const Circle& x, const Circle& y);
    friend std::ostream& operator<<(std::ostream &os, const Circle &c);
};
