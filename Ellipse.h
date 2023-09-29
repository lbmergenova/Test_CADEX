#pragma once

#include "ICurve.h"

class Ellipse : public ICurve
{
private:
    float _rx;
    float _ry;
public:
    Ellipse(float rx, float ry);
    virtual ~Ellipse();

    std::pair<float, float> GetRadius();
    
    Point Coordinat(float t);
    Point Derivative(float t);

    friend std::ostream &operator<<(std::ostream &os, const Ellipse &e);
};
