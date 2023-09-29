#include "Circle.h"

    Circle::Circle(float r) {
        if (r <= 0)
        {
            throw CurveConstructException();
        }
        _r = r;
    }
    Circle::~Circle() {};

    float Circle::GetRadius() { return _r; }

    Point Circle::Coordinat(float t) {
        return Point(_r*cos(t), _r*sin(t), 0);
    }

    Point Circle::Derivative(float t) {
        return Point(-sin(t), cos(t),0);
    }

    bool operator< (const Circle& x, const Circle& y) {
		return x._r < y._r;
	}
    
    std::ostream &operator<<(std::ostream &os, const Circle &c) {
	    os << "circle r=" << c._r;
	    return os;
    }