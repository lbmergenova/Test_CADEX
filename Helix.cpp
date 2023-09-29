#include "Helix.h"

    Helix::Helix(float r, float h) : _h(h) {
        if (r <= 0)
        {
            throw CurveConstructException();
        }
        _r = r;
    }

    Helix::~Helix() {}

    float Helix::GetRadius() { return _r; }
    float Helix::GetStep() { return _h; }

    Point Helix::Coordinat(float t) {
        return Point(_r*cos(t), _r*sin(t),_h*t);
    }
    Point Helix::Derivative(float t) {
        return Point(-_r*sin(t), _r*cos(t),_h);
    }

    std::ostream &operator<<(std::ostream &os, const Helix &h) {
        os << "helix r=" << h._r << ", h=" << h._h;
        return os;
    }

