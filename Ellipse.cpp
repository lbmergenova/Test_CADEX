#include "Ellipse.h"

Ellipse::Ellipse(float rx, float ry) {
        if (rx <= 0 || rx <= 0)
        {
            throw CurveConstructException();
        }
        _rx = rx;
        _ry = ry;
    }
    Ellipse::~Ellipse() {}

    std::pair<float, float> Ellipse::GetRadius() { return std::make_pair(_rx, _ry) ; }

    Point Ellipse::Coordinat(float t) {
        return Point(_rx*cos(t), _ry*sin(t),0);
    }

    Point Ellipse::Derivative(float t) {
        return Point(-_rx*sin(t)/_ry, cos(t),0);
    }
     
    std::ostream& operator<<(std::ostream &os, const Ellipse &e) {
        os << "ellipse a=" << e._rx << ", b=" << e._ry;
        return os;
    }
