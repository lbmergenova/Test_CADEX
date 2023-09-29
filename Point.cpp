#include "Point.h"

Point::Point(float x, float y, float z) : _x(x), _y(y), _z(z) {}

Point::~Point() {}

std::ostream &operator<<(std::ostream &os, const Point &p) {
	os << "{" << p._x << "," << p._y << "," << p._z << "}";
	return os;
}