#pragma once

#include <cmath>

#include "Point.h"

class ICurve
{

public:
	class CurveConstructException : public std::exception {

public:
	const char *what() const noexcept { return "bad argument"; };
};

public:
    ICurve() {};
    virtual ~ICurve() {};

    virtual Point Coordinat(float t) = 0;
    virtual Point Derivative(float t) = 0;
};
