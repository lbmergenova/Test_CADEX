#pragma once

#include "ICurve.h"

class Helix : public ICurve 
{
private:
    float _r;
    float _h;
public:
    Helix(float r, float h);
    virtual ~Helix();

    float GetRadius();
    float GetStep();

    Point Coordinat(float t);
    Point Derivative(float t);

    friend std::ostream &operator<<(std::ostream &os, const Helix &h);
};

